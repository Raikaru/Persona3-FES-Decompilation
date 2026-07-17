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
extern u64 func_00100ec0();
extern u64 func_001016b0();
extern u64 func_00102100();
extern u64 func_001021c0();
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
extern u64 func_00198590();
extern u64 func_0019d3f0();
extern u64 func_001fdd60();
extern u64 func_001fdda0();
extern u64 func_001fddf0();
extern u64 func_001fdec0();
extern u64 func_001fdf10();
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
extern u64 func_0021cca0();
extern u64 func_0021cce0();
extern u64 func_0027e310();
extern u32 func_0027ec10();
extern u64 func_0027ed20();
extern u64 func_0027f650();
extern u64 func_0027f7c0();
extern u64 func_0027ffb0();
extern u64 func_00280870();
extern u64 func_00288f80();
extern u64 func_00289030();
extern u64 func_0028a780();
extern u64 func_0029a1d0();
extern u64 func_0029a210();
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
extern u64 func_002ffcc0();
extern u16 func_002ffd70(u32 unit);
extern u16 func_002ffd80(u32 unit);
extern u16 func_002ffdf0(u32 unit);
extern u16 func_00300100(u32 unit);
extern u64 func_00300530();
extern u64 func_00300550();
extern u64 func_00300580();
#pragma alias func_00300580_u32 func_00300580
extern u32 func_00300580_u32(u32 param_1,u32 param_2);
extern u64 func_003005e0();
extern u64 func_00301540();
extern u64 func_00301750();
extern u64 func_00301870();
extern u64 func_00301ca0();
extern u64 func_00303130();
extern u32 func_00306e80();
extern u64 func_003080c0();
extern u64 func_003082f0();
extern u64 func_003086f0();
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
#pragma alias func_0030b5a0_u32 func_0030b5a0
extern u32 func_0030b5a0_u32(u32,u32);
extern u64 func_0030b5a0();
extern u64 func_0030bc20();
extern u64 func_003174e0();
extern u64 func_003176c0();
extern u64 func_00317730();
extern u64 func_00317a20();
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
extern u64 func_00325e40();
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
extern u64 func_0045a430();
extern u64 func_0045af40();
extern u64 func_0045af70();
extern u64 func_004bdde0();
extern u64 func_004be1e0();
extern u64 func_004c69f0();
extern u64 func_004c6b20();
extern u64 func_0051e0e0();
extern u64 func_00521250();
extern u64 func_00521408();
extern u64 func_00523ac8();
extern u32 func_00524270();
extern u32 func_00524388();
extern u64 func_0052ea18();
extern u8 DAT_00696440;
extern u8 DAT_00696460;
extern u8 DAT_00696d70;
#pragma alias DAT_00696d70_abs DAT_00696d70
extern u8 DAT_00696d70_abs[];
extern u8 DAT_00696e10;
extern u32 DAT_00696e30;
extern u32 DAT_00696e34;
extern u8 DAT_00696fb0;
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
extern u16 DAT_007e094e_abs[];
extern u16 DAT_007e0952_abs[];
extern u16 DAT_007e0958_abs[];
extern u16 DAT_007e095a_abs[];
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
extern u64 (*DAT_00960090)();
extern u64 (*DAT_009600a4)();
extern u64 (*DAT_00960178)();
#pragma alias DAT_00960178_u32_abs DAT_00960178
extern u32 (*DAT_00960178_u32_abs[])(...);
#pragma alias DAT_00960178_abs DAT_00960178
extern code DAT_00960178_abs[];
extern void (*DAT_0096017c[])(...);
extern u32* PTR_DAT_00696f30;
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
extern void LAB_002bd060(void);
extern void LAB_002bd210(void);
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
extern u32 func_002b9370(int param_1,u16 param_2);
extern u32 func_002b93c0(int param_1,u16 param_2);
extern u32 func_002b93e0(u32 param_1,u16 param_2,u32 param_3,u32 param_4,u32 param_5);
extern void func_002b94f0(BtlFormationWork *param_1);
extern float func_002b9590(int param_1);
extern void func_002b9600(u32 *param_1);
extern u32 func_002b9640(int param_1);
extern void func_002b96e0(int param_1,u32 param_2);
extern void func_002b96f0(float param_1,float param_2,float *param_3,u32 *param_4,int param_5,u64 param_6);
extern void func_002b99d0(int param_1,int param_2,u64 param_3,u64 param_4);
extern void func_002b9b00(int param_1,u64 param_2,int param_3,float *param_4);
extern void func_002b9c00(int param_1,u64 param_2,int param_3,float *param_4);
extern void func_002b9d40(int param_1,u64 param_2,int param_3,float *param_4);
extern void func_002b9e80(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
extern void func_002b9f30(u64 param_1,int param_2,u64 param_3,u64 param_4);
extern void func_002ba000(u64 param_1,int param_2,u64 param_3,u64 param_4);
extern void func_002ba0f0(int param_1,int param_2,char *param_3,u8 (*param_4) [16]);
extern void func_002ba3a0(u64 param_1);
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
extern u64 func_002bb7d0(void);
extern void func_002bb8f0(u32 param_1);
extern u16 * func_002bb9c0(int param_1);
extern u32 func_002bbac0(int param_1,u16 *param_2);
extern void func_002bbbc0(int param_1);
extern u64 func_002bbc00(u32 param_1);
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
extern void func_002bc9c0(float param_1,float param_2,float param_3,float param_4,float param_5, float param_6,u32 param_7,long param_8);
extern void func_002bccd0(u32 param_1, u32 param_2);
extern void func_002bcde0(u64 param_1,u32 *param_2);
extern void func_002bce10(float param_1,float param_2,int param_3,int param_4,float *param_5);
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
extern u32 func_002bde10(int param_1,u16 *param_2);
extern u32 func_002bdfb0(int param_1);
extern u32 func_002be2f0(int param_1);
extern void func_002be390(short *param_1,short param_2,short param_3);
extern u32 func_002be580(u64 param_1,int param_2);
extern u32 func_002BE5D0(u64 param_1,int param_2);
extern u32 func_002BE5F0(u64 param_1,int param_2);
extern void func_002BE610(int param_1);
extern u64 func_002be620(u64 param_1,u64 param_2);
extern void func_002be720(short *param_1,short param_2,short param_3,u64 param_4);
extern u64 func_002be9e0(int param_1,int param_2);
extern void func_002bea80(short *param_1,short param_2,short param_3);
extern u16 func_002becc0(void);
extern void func_002bed10(void);
extern void func_002bedd0(int param_1);
extern u64 func_002bef20(u64 param_1);
extern u32 func_002bf2b0(u32 param_1);
extern void func_002bf370(u64 param_1);
extern u32 func_002bf3f0(u64 param_1);
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
extern void func_002bfcb0(int param_1,u64 param_2,u32 param_3,u32 param_4,long param_5);
#pragma alias func_002bfcb0_ptr func_002bfcb0
extern void func_002bfcb0_ptr(int param_1,void *param_2,u32 param_3,u32 param_4,long param_5);
extern u8 func_002bff60(u64 param_1,long param_2,u32 param_3,long param_4);
// Typed alias for callers that consume the helper's full 16-bit result.
#pragma alias func_002bff60_u16 func_002bff60
extern u16 func_002bff60_u16(u32 param_1,u32 param_2,u16 param_3,u32 param_4);
extern void func_002c0070(int param_1,u64 param_2);
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
extern bool func_002c2ed0(u64 param_1,u16 param_2,long param_3);
extern void func_002c30f0(u64 param_1,u16 param_2);
extern void func_002c3120(u64 param_1,u16 param_2);
extern void func_002c3150(int param_1,u32 param_2);
extern void func_002c31b0(int param_1,u32 param_2);
extern void func_002c3210(int param_1,u32 param_2);
extern bool func_002c3270(int param_1);
extern u32 func_002c32c0(int param_1);
extern u32 func_002c32e0(int param_1);
extern u32 func_002c3300(int param_1,u32 param_2);
extern bool func_002c3400(int param_1);
extern u64 func_002c3430(u64 param_1,u64 param_2,u32 param_3,u16 param_4,int param_5, code *param_6);
extern u32 func_002c3770(u64 param_1,u64 param_2);
#pragma alias func_002c3770_u32 func_002c3770
extern u32 func_002c3770_u32(u32 param_1,u32 param_2);
extern u32 func_002c3be0(u64 param_1);
extern u32 func_002c3ce0(u64 param_1);
extern u64 func_002c3e10(void);
extern void func_002c3e20(u64 param_1,u64 param_2);
extern void func_002c3e60(u64 param_1,u64 param_2);
extern void func_002c3ea0(u64 param_1,u64 param_2);
extern u32 func_002c3ee0(int param_1);
extern void func_002c3f00(int param_1);
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
extern u32 func_002c48a0(int param_1,int param_2,u16 *param_3,u32 param_4,short param_5);
extern u32 func_002c4a90(int param_1,int param_2,u16 *param_3,u32 param_4,short param_5);
extern u32 func_002c4c80(int param_1,int param_2,u16 *param_3,u32 param_4,short param_5);
extern u32 func_002c4e50(int param_1,int param_2,u16 *param_3,u32 param_4,short param_5);
extern long func_002c5030(u64 param_1,u64 param_2,long param_3,int param_4);
extern u32 func_002c5380(int param_1,int param_2,u16 *param_3,long param_4);
extern u32 func_002c59d0(u64 param_1,u64 param_2,u64 param_3,long param_4);
extern long func_002c5fc0(u64 param_1,u64 param_2,short param_3,int param_4);
extern long func_002c6300(u64 param_1,u64 param_2,u16 param_3,long param_4);
#pragma alias func_002c6300_s32 func_002c6300
extern long func_002c6300_s32(u32 context, u32 actor, s16 value, s32 mode);
extern u32 func_002c65d0(int param_1);
extern void func_002c6a00(int param_1,int param_2,u16 param_3);
extern char func_002c6ba0(u64 param_1);
extern undefined * func_002c6e30(int param_1,u32 param_2);
extern u32 func_002c6f50(u64 param_1,int param_2,u64 param_3,u64 param_4);
extern void func_002c70d0(u64 param_1,u64 param_2);
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
extern void func_002d0a30(void);
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

// FUN_002b90d0 NONMATCHING

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

  func_00521250(destination, source, 0x630);
  for (outer = 0; outer < 2; outer++) {
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
  }
  *(u16 *)(destination + 0x630) |= 2;
}

// FUN_002b9220 NONMATCHING

void func_002b9220(int state)
{
  u16 outer;
  int count;
  u16 index;
  u8 *entry;
  int block;

  for (outer = 0; outer < 2; outer++) {
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
  
  __asm__ volatile (
      ".set noreorder          \n"
      "lui %0, 0x95             \n"
      "addiu %0, %0, 0x7100     \n"
      ".set reorder"
      : "=r" (puVar4)
  );
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
                   u64 param_6)
{
  u8 bVar1 = *(u8 *)(param_5 + 2);
  float fVar3 = 0.0f;
  float origin[3] = {0.0f, 0.0f, 0.0f};
  float originX;
  float originY;
  float originZ;
  float targetX;
  float targetY;
  float targetZ;
  float dx;
  float dy;
  float dz;
  float distance = 0.0f;
  float scale = 0.0f;
  u32 uStack_20 = 0;
  u32 uStack_1c = 0;
  u32 uStack_18 = 0;
  u32 uStack_14 = 0;
  float fStack_10 = 0.0f;
  float fStack_c = 0.0f;
  float fStack_8 = 0.0f;
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
    func_003297a0(origin);
    originX = origin[0];
    originY = origin[1];
    originZ = origin[2];
    if (param_2 <= param_1) {
      param_2 = param_1;
    }

    targetX = *param_3;
    targetZ = param_3[2];
    if (bVar1 == 9) {
      targetY = param_3[1];
    }
    else {
      targetY = fVar3;
    }

    dx = targetX - originX;
    dy = targetY - originY;
    dz = targetZ - originZ;
    if (bVar1 == 10) {
      dy = 0.0f;
    }

    distance = sqrtf(dx * dx + dy * dy + dz * dz);
    if (distance > 0.0f) {
      scale = -param_2 / distance;
      targetX += dx * scale;
      targetY += dy * scale;
      targetZ += dz * scale;
    }
    *(float *)(out) = targetX;
    *(float *)(out + 4) = targetY;
    *(float *)(out + 8) = targetZ;
  }
  else if (bVar1 == 8) {
    *(float *)out = *param_3;
    *(float *)(out + 4) = fVar3;
    *(float *)(out + 8) = param_3[2];
  }
  else {
    uStack_20 = *param_4;
    uStack_1c = param_4[1];
    uStack_18 = param_4[2];
    uStack_14 = param_4[3];
    func_004bdde0(*(u32 *)(&DAT_00696460 + (u32)bVar1 * 4),&uStack_20,0x697880,2);
    func_004be1e0(&fStack_10,0x697890,1,&uStack_20);
    *(float *)out = *param_3 + fStack_10 * param_1;
    *(float *)(out + 4) = fVar3 + fStack_c * param_1;
    *(float *)(out + 8) = param_3[2] + fStack_8 * param_1;
  }
  *(u32 *)(out + 0xc) = 0;
}

// FUN_002b99d0 NONMATCHING

void func_002b99d0(int param_1,int param_2,u64 param_3,u64 param_4)

{
  u16 uVar1 = 0;
  float fVar2 = 0;
  float fVar3 = 0;
  float fStack_30 = 0;
  float fStack_2c = 0;
  float fStack_28 = 0;
  float fStack_20 = 0;
  float fStack_1c = 0;
  float fStack_18 = 0;
  float fStack_10 = 0;
  float fStack_c = 0;
  float fStack_8 = 0;
  
  uVar1 = *(u16 *)((int)param_3 + 4);
  if (uVar1 == 0) {
    fVar3 = *(float *)(param_1 + 0x30) * *(float *)(param_2 + 0x2c);
  }
  else {
    fVar3 = (float)uVar1;
  }
  fVar2 = *(float *)(param_1 + 0x2c) * *(float *)(param_2 + 0x2c) * 0.5;
  fStack_18 = *(float *)(param_1 + 0x50);
  fStack_20 = *(float *)(param_1 + 0x20) * fStack_18;
  fStack_1c = *(float *)(param_1 + 0x24) * fStack_18;
  fStack_18 = *(float *)(param_1 + 0x28) * fStack_18;
  func_004be1e0(&fStack_30,&fStack_20,1,param_1 + 0x40);
  fStack_10 = fStack_30 + *(float *)(param_1 + 0x34);
  fStack_c = fStack_2c + *(float *)(param_1 + 0x38);
  fStack_8 = fStack_28 + *(float *)(param_1 + 0x3c);
  func_002b96f0(fVar3,fVar2,&fStack_10,(u32 *)(param_1 + 0x40),param_3,param_4);
  return;
}

// FUN_002b9b00 NONMATCHING

void func_002b9b00(int param_1,u64 param_2,int param_3,float *param_4)

{
  long lVar1 = 0;
  float fStack_30 = 0;
  float fStack_2c = 0;
  float fStack_28 = 0;
  float fStack_20 = 0;
  float fStack_1c = 0;
  float fStack_18 = 0;
  float fStack_10 = 0;
  float fStack_c = 0;
  float fStack_8 = 0;
  
  if ((*(u32 *)((int)param_2 + 0x98) & 2) == 0) {
    func_0027ffb0(param_2,&fStack_10);
  }
  else {
    lVar1 = func_00318ed0(*(u32 *)((int)param_2 + 0x9f4),*(u16 *)(param_3 + 4),
                         &fStack_10);
    if (lVar1 == 0) {
      fStack_18 = *(float *)(param_1 + 0x50);
      fStack_20 = *(float *)(param_1 + 0x20) * fStack_18;
      fStack_1c = *(float *)(param_1 + 0x24) * fStack_18;
      fStack_18 = *(float *)(param_1 + 0x28) * fStack_18;
      func_004be1e0(&fStack_30,&fStack_20,1,param_1 + 0x40);
      fStack_10 = fStack_30 + *(float *)(param_1 + 0x34);
      fStack_c = fStack_2c + *(float *)(param_1 + 0x38);
      fStack_8 = fStack_28 + *(float *)(param_1 + 0x3c);
    }
  }
  *param_4 = fStack_10;
  param_4[1] = fStack_c;
  param_4[2] = fStack_8;
  return;
}

// FUN_002b9c00 NONMATCHING

void func_002b9c00(int param_1,u64 param_2,int param_3,float *param_4)

{
  int iVar1 = 0;
  long lVar2 = 0;
  int iVar3 = 0;
  float fStack_30 = 0;
  float fStack_2c = 0;
  float fStack_28 = 0;
  float fStack_20 = 0;
  float fStack_1c = 0;
  float fStack_18 = 0;
  float fStack_10 = 0;
  float fStack_c = 0;
  float fStack_8 = 0;
  
  if ((*(u32 *)((int)param_2 + 0x98) & 2) == 0) {
    func_0027ffb0(param_2,&fStack_10);
  }
  else {
    iVar1 = *(int *)((int)param_2 + 0x9f4);
    iVar3 = *(int *)(iVar1 + 0x3c4);
    if (iVar3 == 0) {
      iVar3 = iVar1;
    }
    func_003176c0(iVar3);
    func_00318b90(iVar3);
    lVar2 = func_00318ed0(iVar3,*(u16 *)(param_3 + 4),&fStack_10);
    if (lVar2 == 0) {
      fStack_18 = *(float *)(param_1 + 0x50);
      fStack_20 = *(float *)(param_1 + 0x20) * fStack_18;
      fStack_1c = *(float *)(param_1 + 0x24) * fStack_18;
      fStack_18 = *(float *)(param_1 + 0x28) * fStack_18;
      func_004be1e0(&fStack_30,&fStack_20,1,param_1 + 0x40);
      fStack_10 = fStack_30 + *(float *)(param_1 + 0x34);
      fStack_c = fStack_2c + *(float *)(param_1 + 0x38);
      fStack_8 = fStack_28 + *(float *)(param_1 + 0x3c);
    }
  }
  *param_4 = fStack_10;
  param_4[1] = fStack_c;
  param_4[2] = fStack_8;
  return;
}

// FUN_002b9d40 NONMATCHING

void func_002b9d40(int param_1,u64 param_2,int param_3,float *param_4)

{
  int iVar1 = 0;
  long lVar2 = 0;
  int iVar3 = 0;
  float fStack_30 = 0;
  float fStack_2c = 0;
  float fStack_28 = 0;
  float fStack_20 = 0;
  float fStack_1c = 0;
  float fStack_18 = 0;
  float fStack_10 = 0;
  float fStack_c = 0;
  float fStack_8 = 0;
  
  if ((*(u32 *)((int)param_2 + 0x98) & 2) == 0) {
    func_0027ffb0(param_2,&fStack_10);
  }
  else {
    iVar1 = *(int *)((int)param_2 + 0x9f4);
    iVar3 = *(int *)(iVar1 + 0x3b8);
    if (iVar3 == 0) {
      iVar3 = iVar1;
    }
    func_003176c0(iVar3);
    func_00318b90(iVar3);
    lVar2 = func_00318ed0(iVar3,*(u16 *)(param_3 + 4),&fStack_10);
    if (lVar2 == 0) {
      fStack_18 = *(float *)(param_1 + 0x50);
      fStack_20 = *(float *)(param_1 + 0x20) * fStack_18;
      fStack_1c = *(float *)(param_1 + 0x24) * fStack_18;
      fStack_18 = *(float *)(param_1 + 0x28) * fStack_18;
      func_004be1e0(&fStack_30,&fStack_20,1,param_1 + 0x40);
      fStack_10 = fStack_30 + *(float *)(param_1 + 0x34);
      fStack_c = fStack_2c + *(float *)(param_1 + 0x38);
      fStack_8 = fStack_28 + *(float *)(param_1 + 0x3c);
    }
  }
  *param_4 = fStack_10;
  param_4[1] = fStack_c;
  param_4[2] = fStack_8;
  return;
}

// FUN_002b9e80 NONMATCHING

void func_002b9e80(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  u16 uVar1 = 0;
  float fVar2 = 0;
  u32 uStack_20 = 0;
  u32 uStack_1c = 0;
  u32 uStack_18 = 0;
  u32 uStack_14 = 0;
  float auStack_10[3] = {0.0f, 0.0f, 0.0f};
  float fStack_4 = 0;
  
  fVar2 = (float)func_00280870(3,0,auStack_10,&fStack_4,0,0);
  uVar1 = *(u16 *)((int)param_3 + 4);
  if (uVar1 != 0) {
    fVar2 = (float)uVar1;
  }
  uStack_14 = 0x3f800000;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  func_002b96f0(fVar2,fStack_4 * 0.5,auStack_10,&uStack_20,param_3,param_4);
  return;
}

// FUN_002b9f30 NONMATCHING

void func_002b9f30(u64 param_1,int param_2,u64 param_3,u64 param_4)

{
  u16 uVar1 = 0;
  u32 uVar2 = 0;
  float fVar3 = 0;
  u32 uStack_20 = 0;
  u32 uStack_1c = 0;
  u32 uStack_18 = 0;
  u32 uStack_14 = 0;
  float auStack_10[3] = {0.0f, 0.0f, 0.0f};
  float fStack_4 = 0;
  
  if (*(char *)(param_2 + 0xa2) == '\0') {
    uVar2 = 1;
  }
  else {
    uVar2 = 2;
  }
  fVar3 = (float)func_00280870(uVar2,0,auStack_10,&fStack_4,0,0);
  uVar1 = *(u16 *)((int)param_3 + 4);
  if (uVar1 != 0) {
    fVar3 = (float)uVar1;
  }
  uStack_14 = 0x3f800000;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  func_002b96f0(fVar3,fStack_4 * 0.5,auStack_10,&uStack_20,param_3,param_4);
  return;
}

// FUN_002ba000 NONMATCHING

void func_002ba000(u64 param_1,int param_2,u64 param_3,u64 param_4)

{
  u16 uVar1 = 0;
  u32 uVar2 = 0;
  float fVar3 = 0;
  u32 uStack_20 = 0;
  u32 uStack_1c = 0;
  u32 uStack_18 = 0;
  u32 uStack_14 = 0;
  float auStack_10[3] = {0.0f, 0.0f, 0.0f};
  float fStack_4 = 0;
  
  if (*(char *)(param_2 + 0xa2) == '\0') {
    uVar2 = 2;
  }
  else {
    uVar2 = 1;
  }
  fVar3 = (float)func_00280870(uVar2,0,auStack_10,&fStack_4,0,0);
  uVar1 = *(u16 *)((int)param_3 + 4);
  if (uVar1 != 0) {
    fVar3 = (float)uVar1;
  }
  uStack_14 = 0x3f800000;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  func_002b96f0(fVar3,fStack_4 * 0.5,auStack_10,&uStack_20,param_3,param_4);
  return;
}

// FUN_002ba0f0 NONMATCHING

void func_002ba0f0(int param_1,int param_2,char *param_3,u8 (*param_4) [16])

{
  int iVar1 = 0;
  u8 auVar2 [16] = {0};
  long lVar3 = 0;
  u32 uVar4 = 0;
  u32 uStack_90 = 0;
  u32 uStack_8c = 0;
  u32 uStack_88 = 0;
  u32 uStack_80 = 0;
  u32 uStack_7c = 0;
  u32 uStack_78 = 0;
  u32 uStack_70 = 0;
  u32 uStack_6c = 0;
  u32 uStack_68 = 0;
  u32 uStack_60 = 0;
  u32 uStack_5c = 0;
  u32 uStack_58 = 0;
  u32 uStack_50 = 0;
  u32 uStack_4c = 0;
  u32 uStack_48 = 0;
  u32 uStack_44 = 0;
  u32 uStack_40 = 0;
  u32 uStack_3c = 0;
  u32 uStack_38 = 0;
  u32 uStack_34 = 0;
  u32 uStack_30 = 0;
  u32 uStack_2c = 0;
  u32 uStack_28 = 0;
  u32 uStack_24 = 0;
  u32 uStack_20 = 0;
  u32 uStack_1c = 0;
  u32 uStack_18 = 0;
  u32 uStack_14 = 0;
  float afStack_10 [2] = {0};
  float fStack_8 = 0;
  
  switch(*param_3) {
  case '\0':
    func_004be1e0(afStack_10,0x697890,1,param_1 + 0x40);
    if ((afStack_10[0] == 0.0) && (fStack_8 == 0.0)) {
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
      uVar4 = func_0052ea18(afStack_10[0],fStack_8);
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
      lVar3 = func_00318d10(*(u32 *)(param_2 + 0x9f4),*(u16 *)(param_3 + 4),&uStack_90)
      ;
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
        uStack_50 = uStack_90;
        uStack_4c = uStack_8c;
        uStack_48 = uStack_88;
        uStack_44 = 0;
        uStack_40 = uStack_80;
        uStack_3c = uStack_7c;
        uStack_38 = uStack_78;
        uStack_34 = 0;
        uStack_30 = uStack_70;
        uStack_2c = uStack_6c;
        uStack_28 = uStack_68;
        uStack_24 = 0;
        uStack_20 = uStack_60;
        uStack_1c = uStack_5c;
        uStack_18 = uStack_58;
        uStack_14 = 0;
        func_00329ed0(&uStack_50);
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
        lVar3 = func_00318d10(iVar1,*(u16 *)(param_3 + 4),&uStack_90);
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
          uStack_50 = uStack_90;
          uStack_4c = uStack_8c;
          uStack_48 = uStack_88;
          uStack_44 = 0;
          uStack_40 = uStack_80;
          uStack_3c = uStack_7c;
          uStack_38 = uStack_78;
          uStack_34 = 0;
          uStack_30 = uStack_70;
          uStack_2c = uStack_6c;
          uStack_28 = uStack_68;
          uStack_24 = 0;
          uStack_20 = uStack_60;
          uStack_1c = uStack_5c;
          uStack_18 = uStack_58;
          uStack_14 = 0;
          func_00329ed0(&uStack_50);
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

// FUN_002ba3a0 NONMATCHING

void func_002ba3a0(u64 param_1)

{
  char cVar1 = 0;
  u16 uVar2 = 0;
  int iVar3 = 0;
  u32 uVar4 = 0;
  u32 uVar5 = 0;
  u32 uVar6 = 0;
  bool bVar7 = 0;
  short *psVar8;
  long lVar9 = 0;
  int *piVar10;
  char *pcVar11;
  int *piVar12;
  u16 uVar13 = 0;
  int iVar14 = 0;
  int iVar15 = 0;
  int iVar16 = 0;
  float fVar17 = 0;
  float fVar18 = 0;
  u8 auStack_40 [16] = {0};
  u8 auStack_30 [16] = {0};
  u8 auStack_20 [16] = {0};
  u8 auStack_10 [16] = {0};
  
  piVar10 = (int *)param_1;
  iVar3 = piVar10[6];
  uVar4 = piVar10[4];
  uVar5 = piVar10[2];
  if (((uVar5 & 0x800) == 0) && ((uVar4 & 0xff000000) != 0)) {
    uVar6 = piVar10[3];
    if ((uVar6 == 0) ||
       ((((uVar5 & 0x1000) != 0 && (uVar6 == *(u32 *)(*piVar10 + 800))) || ((uVar5 & 0x100) != 0)))
       ) {
      lVar9 = (long)(uintptr_t)func_002fc520(
          (BtlUnit*)(uintptr_t)iVar3);
      if (lVar9 == 0) {
        iVar14 = *(int *)(iVar3 + 0x84);
        iVar15 = *(int *)(iVar3 + 0x88);
        piVar10[8] = *(int *)(iVar3 + 0x80);
        piVar10[9] = iVar14;
        piVar10[10] = iVar15;
        piVar10[0xb] = *(int *)(iVar3 + 0x8c);
        piVar10[0xc] = *(int *)(iVar3 + 0x90);
      }
      else {
        psVar8 = (short *)lVar9;
        piVar10[8] = (int)(float)(int)*psVar8;
        piVar10[9] = (int)(float)(int)psVar8[1];
        piVar10[10] = (int)(float)(int)psVar8[2];
        piVar10[0xb] = (int)(float)(u16)psVar8[3];
        piVar10[0xc] = (int)(float)(u16)psVar8[4];
      }
      iVar14 = *(int *)(iVar3 + 8);
      iVar15 = *(int *)(iVar3 + 0xc);
      piVar10[0xd] = *(int *)(iVar3 + 4);
      piVar10[0xe] = iVar14;
      piVar10[0xf] = iVar15;
      if (iVar3 == piVar10[7]) {
        iVar16 = *(int *)(iVar3 + 0x20);
        iVar14 = *(int *)(iVar3 + 0x24);
        iVar15 = *(int *)(iVar3 + 0x28);
        piVar10[0x10] = *(int *)(iVar3 + 0x1c);
        piVar10[0x11] = iVar16;
        piVar10[0x12] = iVar14;
        piVar10[0x13] = iVar15;
      }
      else if ((*(char *)(iVar3 + 0xa2) == *(char *)(piVar10[7] + 0xa2)) &&
              (*(char *)(iVar3 + 0xa2) == '\x01')) {
        iVar16 = *(int *)(iVar3 + 0x20);
        iVar14 = *(int *)(iVar3 + 0x24);
        iVar15 = *(int *)(iVar3 + 0x28);
        piVar10[0x10] = *(int *)(iVar3 + 0x1c);
        piVar10[0x11] = iVar16;
        piVar10[0x12] = iVar14;
        piVar10[0x13] = iVar15;
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
            iVar14 = func_00325920(*(u32 *)(pcVar11 + 4));
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
                       *(float *)(iVar3 + 0x8c) * *(float *)(iVar3 + 0x2c) * 0.5) * 0.5;
              if (2.5 < fVar17) {
                fVar18 = 2.5;
              }
              else if (fGpffff839c <= fVar17) {
                fVar18 = fVar17;
              }
            }
            else {
              iVar14 = piVar10[7];
              fVar17 = fGpffff8398 *
                       (*(float *)(iVar14 + 0x90) * *(float *)(iVar14 + 0x2c) +
                       *(float *)(iVar14 + 0x8c) * *(float *)(iVar14 + 0x2c) * 0.5) * 0.5;
              if (2.5 < fVar17) {
                fVar18 = 2.5;
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
          func_002ba0f0(param_1,iVar3,pcVar11 + 8,&auStack_40);
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

// FUN_002ba900 NONMATCHING

void func_002ba900(int param_1)
{
  extern u16 func_00321130(void);
  u16 index;
  u16 count;
  int *entries;
  u32 savedState;
  u32 limit;

  if ((*(u32 *)(param_1 + 8) & 0x400) == 0) {
    entries = *(int **)(param_1 + 0x58);
    count = *(u16 *)(param_1 + 0x54);
    if ((*(u32 *)(param_1 + 8) & 0x8000) == 0) {
      index = 0;
      limit = count;
      while (index < limit) {
        if (*entries != 0) func_00325500(*entries);
        index++;
        entries++;
      }
    } else {
      savedState = func_00321130();
      func_00321320(DAT_00957100_abs);
      func_00321120(4);
      index = 0;
      while (index < count) {
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

// FUN_002baad0 NONMATCHING

u32 func_002baad0(int *param_1)

{
  int iVar1 = 0;
  int iVar2 = 0;
  u32 uVar3 = 0;
  long lVar4 = 0;
  u64 uVar5 = 0;
  u8 auStack_4 [4] = {0};
  
  iVar1 = *param_1;
  if (param_1[1] == 0) {
    iVar2 = func_00100d80(param_1[2],0);
    param_1[1] = iVar2;
  }
  lVar4 = func_001016b0(param_1[1]);
  if (lVar4 == 0) {
    uVar3 = 0;
  }
  else {
    uVar5 = func_001021c0(param_1[2],auStack_4);
    func_002b90d0(iVar1,uVar5);
    func_00100ec0(param_1[1]);
    *(u16 *)(iVar1 + 0x630) = *(u16 *)(iVar1 + 0x630) & 0xfffe;
    *(u16 *)(iVar1 + 0x630) = *(u16 *)(iVar1 + 0x630) | 2;
    *(short *)(iVar1 + 0x632) = *(short *)(iVar1 + 0x632) + -1;
    if (((*(u16 *)(iVar1 + 0x630) & 8) != 0) && (*(short *)(iVar1 + 0x632) == 1)) {
      func_002b9220(iVar1);
    }
    if (*(short *)(iVar1 + 0x632) == 0) {
      if ((*(u16 *)(iVar1 + 0x630) & 2) != 0) {
        func_002b9220(iVar1);
      }
      (*DAT_0096017c)(iVar1);
    }
    uVar3 = 1;
  }
  return uVar3;
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
  short sVar1 = 0;
  u16 *puVar2;
  int iVar3 = 0;
  u32 uVar4 = 0;
  long lVar5 = 0;
  u32 unaff_s1_lo = 0;
  u32 unaff_s2_lo = 0;
  
  lVar5 = func_002b9350(*param_1);
  if (lVar5 == 0) {
    uVar4 = 0;
  }
  else {
    puVar2 = (u16 *)param_1[4];
    if ((*(u32 *)(puVar2 + 2) & 0xff000000) == 0) {
      uVar4 = 1;
    }
    else {
      iVar3 = func_002b9370(*param_1,*(u16 *)(param_1 + 3));
      if ((*puVar2 & 0x40) == 0) {
        if (iVar3 * 2 + -0xd <= (int)param_1[6]) {
          *puVar2 = *puVar2 | 0x100;
          return 0;
        }
        if ((param_1[6] == 0) && ((param_1[7] & 0xc00) != 0xc00)) {
          sVar1 = *(short *)(param_1 + 3);
          if (sVar1 == 1) {
            unaff_s2_lo = param_1[2];
            unaff_s1_lo = param_1[1];
          }
          else if (sVar1 == 0) {
            unaff_s2_lo = param_1[1];
            unaff_s1_lo = param_1[2];
          }
          uVar4 = func_002b93e0(*param_1,sVar1,unaff_s2_lo,unaff_s1_lo,0);
          *(u32 *)(puVar2 + 8) = uVar4;
          *puVar2 = *puVar2 | 0x30;
        }
        param_1[6] = param_1[6] + 2;
      }
      uVar4 = 0;
    }
  }
  return uVar4;
}

// FUN_002baec0

bool func_002baec0(u32 *param_1)
{
  int iVar2;
  u16 index;
  u32 value;
  volatile u16 *index_ptr;
  volatile u32 *value_ptr;
  
  if (!func_002b9350(*param_1)) {
    return false;
  }
  index_ptr = (volatile u16 *)(param_1 + 3);
  value_ptr = (volatile u32 *)param_1;
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
  
  lVar4 = func_002b9350(*param_1);
  if (lVar4 == 0) {
    uVar3 = 0;
  }
  else {
    puVar1 = (u16 *)param_1[6];
    if ((*(u32 *)(puVar1 + 2) & 0xff000000) == 0) {
      uVar3 = 1;
    }
    else {
      if ((*puVar1 & 0x40) == 0) {
        if ((*(u16 *)(param_1 + 8) & 0x4000) == 0) {
          iVar2 = func_002b9370(*param_1,0);
          iVar2 = iVar2 << 1;
        }
        else {
          iVar2 = param_1[7] + 1;
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

// FUN_002bb3a0 NONMATCHING

void func_002bb3a0(void)

{
  u16 uVar1 = 0;
  u32 uVar2 = 0;
  u32 uVar3 = 0;
  u16 *puVar4;
  u32 uStack_4 = 0;
  
  for (puVar4 = *(u16 **)(iGpffffb6fc + 400); puVar4 != (u16 *)0x0;
      puVar4 = *(u16 **)(puVar4 + 0x10)) {
    uVar3 = *(u32 *)(puVar4 + 2);
    uVar1 = *puVar4;
    if ((uVar1 & 0x40) == 0) {
      if ((uVar1 & 0x100) == 0) {
        if ((uVar1 & 0x80) != 0) {
          uVar2 = (u32)(u8)puVar4[4] * 0x1000000;
          if (uVar2 < -(uVar3 & 0xff000000) - 0x1000000) {
            uVar3 = uVar3 + uVar2;
          }
          else {
            uVar3 = uVar3 & 0xffffff | 0xff000000;
            *puVar4 = uVar1 & 0xfe7f;
          }
        }
      }
      else if ((u32)(u8)puVar4[4] * 0x1000000 < (uVar3 & 0xff000000)) {
        uVar3 = uVar3 + (u32)(u8)puVar4[4] * -0x1000000;
      }
      else {
        uVar3 = uVar3 & 0xffffff;
        *puVar4 = uVar1 & 0xfe7f;
      }
      if ((*puVar4 & 0x220) == 0x220) {
        if (*(int *)(puVar4 + 0xc) != 0) {
          func_00317730();
        }
        if (*(int *)(puVar4 + 10) != 0) {
          func_003252a0();
        }
        if (*(int *)(puVar4 + 8) != 0) {
          func_002ba3a0(0);
        }
      }
    }
    if (((*puVar4 & 0x210) == 0x210) && ((uVar3 & 0xff000000) != 0)) {
      if (*(int *)(puVar4 + 0xc) != 0) {
        uStack_4 = uVar3;
        func_00318ad0(*(u32 *)(puVar4 + 0xc),&uStack_4);
        func_00317a20(*(u32 *)(puVar4 + 0xc));
      }
      if (*(int *)(puVar4 + 10) != 0) {
        func_00326030(*(int *)(puVar4 + 10),uVar3);
        func_00325500(*(u32 *)(puVar4 + 10));
      }
      if (*(int *)(puVar4 + 8) != 0) {
        *(u32 *)(*(int *)(puVar4 + 8) + 0x10) = uVar3;
        func_002ba900(*(u32 *)(puVar4 + 8));
      }
    }
    *(u32 *)(puVar4 + 2) = uVar3;
    *(int *)(puVar4 + 6) = *(int *)(puVar4 + 6) + 1;
  }
  return;
}

// FUN_002bb580

void func_002bb580(u16 *param_1)

{
  if (*(int *)(param_1 + 8) != 0) {
    func_002b94f0((BtlFormationWork *)*(int *)(param_1 + 8));
    *(u32 *)(param_1 + 8) = 0;
  }
  if (*(int *)(param_1 + 10) != 0) {
    func_003257e0(*(int *)(param_1 + 10));
    *(u32 *)(param_1 + 10) = 0;
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    func_003174e0(*(int *)(param_1 + 0xc));
    *(u32 *)(param_1 + 0xc) = 0;
  }
  *(u32 *)(param_1 + 2) = 0xffffffff;
  *(u8 *)(param_1 + 4) = 0x14;
  *(u32 *)(param_1 + 6) = 0;
  *param_1 = 0x200;
  return;
}

// FUN_002bb610

void func_002bb610(u32 param_1)

{
  u16 *puVar1;
  
  puVar1 = (u16 *)param_1;
  if (*(int *)(puVar1 + 8) != 0) {
    func_002b94f0((BtlFormationWork *)*(int *)(puVar1 + 8));
    *(u32 *)(puVar1 + 8) = 0;
  }
  if (*(int *)(puVar1 + 10) != 0) {
    func_003257e0(*(int *)(puVar1 + 10));
    *(u32 *)(puVar1 + 10) = 0;
  }
  if (*(int *)(puVar1 + 0xc) != 0) {
    func_003174e0(*(int *)(puVar1 + 0xc));
    *(u32 *)(puVar1 + 0xc) = 0;
  }
  *(u32 *)(puVar1 + 2) = 0xffffffff;
  *(u8 *)(puVar1 + 4) = 0x14;
  *(u32 *)(puVar1 + 6) = 0;
  *puVar1 = 0x200;
  if (*(int *)(puVar1 + 0x10) != 0) {
    *(u32 *)(*(int *)(puVar1 + 0x10) + 0x1c) = *(u32 *)(puVar1 + 0xe);
  }
  if (*(int *)(puVar1 + 0xe) != 0) {
    *(u32 *)(*(int *)(puVar1 + 0xe) + 0x20) = *(u32 *)(puVar1 + 0x10);
  }
  else {
    *(u32 *)(iGpffffb6fc + 400) = *(u32 *)(puVar1 + 0x10);
  }
  (*DAT_0096017c)(param_1);
  return;
}

// FUN_002bb6f0

void func_002bb6f0(u16 param_1,u64 param_2)

{
  if ((*(u32 *)(iGpffffb6fc + 0x14) & 1) != 0) {
    func_00523ac8(param_2,D_006964D0);
  }
  else {
    func_00523ac8(param_2,D_006964E8,&gp0xffff99f8,param_1);
  }
  return;
}

// FUN_002bb760

void func_002bb760(void)

{
  return;
}

// FUN_002bb770

void func_002bb770(void)

{
  int *piVar1 = 0;
  
  piVar1 = *(int **)(iGpffffb6fc + 400);
  while (piVar1 != 0) {
    int *piVar2 = *(int **)((int)piVar1 + 0x20);
    func_002bb610((u32)piVar1);
    piVar1 = piVar2;
  }
  func_002bc2f0();
  return;
}

// FUN_002bb7d0 NONMATCHING

u64 func_002bb7d0(void)

{
  u64 uVar1 = 0;
  u64 uVar2 = 0;
  u16 *puVar3;
  u32 uVar4 = 0;
  
  uVar1 = (*DAT_00960178)(200,0x40000);
  func_00521408(uVar1,0,200);
  for (uVar4 = 0; uVar4 < 0x30; uVar4 = uVar4 + 1) {
    uVar2 = (*DAT_00960178)(0x24,0x40000);
    func_00521408(uVar2,0,0x24);
    puVar3 = (u16 *)uVar2;
    *(u32 *)(puVar3 + 2) = 0xffffffff;
    *(u8 *)(puVar3 + 4) = 0x14;
    *(u32 *)(puVar3 + 6) = 0;
    *puVar3 = 0x200;
    *(u32 *)(puVar3 + 0xe) = 0;
    if (*(int *)(iGpffffb6fc + 400) == 0) {
      *(u32 *)(puVar3 + 0x10) = 0;
    }
    else {
      *(u16 **)(*(int *)(iGpffffb6fc + 400) + 0x1c) = puVar3;
      *(u32 *)(puVar3 + 0x10) = *(u32 *)(iGpffffb6fc + 400);
    }
    *(u16 **)(iGpffffb6fc + 400) = puVar3;
    *(u16 **)((int)uVar1 + uVar4 * 4) = puVar3;
  }
  return uVar1;
}

// FUN_002bb8f0 MATCHING

void func_002bb8f0(u32 param_1)

{
  u32 index;
  int node;
  
  for (index = 0; index < 0x30; index = index + 1) {
    node = *(int *)(param_1 + index * 4);
    func_002bb580((u16 *)node);
    if (*(int *)(node + 0x20) != 0) {
      *(u32 *)(*(int *)(node + 0x20) + 0x1c) = *(u32 *)(node + 0x1c);
    }
    if (*(int *)(node + 0x1c) != 0) {
      *(u32 *)(*(int *)(node + 0x1c) + 0x20) = *(u32 *)(node + 0x20);
    }
    else {
      *(u32 *)(iGpffffb6fc + 400) = *(u32 *)(node + 0x20);
    }
    (*DAT_0096017c)(node);
  }
  (*DAT_0096017c)(param_1);
}

// FUN_002bb9c0

u16 *func_002bb9c0(int param_1)
{
  u16 *entry;
  u32 index;
  u32 mask;

  mask = 1;
  index = 0;
  while (index < 0x30) {
    if ((*(u32 *)(param_1 + 0xc0) & mask) == 0) {
      entry = *(u16 **)(param_1 + index * 4);
      if (*(int *)(entry + 8) != 0) {
        func_002b94f0((BtlFormationWork *)*(int *)(entry + 8));
        *(u32 *)(entry + 8) = 0;
      }
      if (*(int *)(entry + 10) != 0) {
        func_003257e0(*(int *)(entry + 10));
        *(u32 *)(entry + 10) = 0;
      }
      if (*(int *)(entry + 0xc) != 0) {
        func_003174e0(*(int *)(entry + 0xc));
        *(u32 *)(entry + 0xc) = 0;
      }
      *(u32 *)(entry + 2) = 0xffffffff;
      *(u8 *)(entry + 4) = 0x14;
      *(u32 *)(entry + 6) = 0;
      *entry = 0x200;
      *(u32 *)(param_1 + 0xc0) |= mask;
      return entry;
    }
    mask <<= 1;
    index++;
  }
  return NULL;
}

// FUN_002bbac0

u32 func_002bbac0(int param_1, u16 *entry)
{
  u32 index;
  u32 mask;

  mask = 1;
  index = 0;
  while (index < 0x30) {
    if (*(u16 **)(param_1 + index * 4) == entry) {
      if (*(int *)(entry + 8) != 0) {
        func_002b94f0((BtlFormationWork *)*(int *)(entry + 8));
        *(u32 *)(entry + 8) = 0;
      }
      if (*(int *)(entry + 10) != 0) {
        func_003257e0(*(int *)(entry + 10));
        *(u32 *)(entry + 10) = 0;
      }
      if (*(int *)(entry + 0xc) != 0) {
        func_003174e0(*(int *)(entry + 0xc));
        *(u32 *)(entry + 0xc) = 0;
      }
      *(u32 *)(entry + 2) = 0xffffffff;
      *(u8 *)(entry + 4) = 0x14;
      *(u32 *)(entry + 6) = 0;
      *entry = 0x200;
      *(u32 *)(param_1 + 0xc0) &= ~mask;
      return 1;
    }
    mask <<= 1;
    index++;
  }
  return 0;
}

// FUN_002bbbc0

void func_002bbbc0(int param_1)

{
  u16 *puVar1;
  u32 uVar2 = 0;
  
  for (uVar2 = 0; uVar2 < 0x30; uVar2 = uVar2 + 1) {
    puVar1 = *(u16 **)(param_1 + uVar2 * 4);
    *puVar1 = *puVar1 & 0xfdff;
  }
  return;
}

// FUN_002bbc00 NONMATCHING

u64 func_002bbc00(u32 param_1)

{
  u8 *puVar1;
  u64 uVar2 = 0;
  u64 uVar3 = 0;
  u16 *puVar4;
  
  uVar2 = (*DAT_00960178)(0x18,0x40000);
  puVar1 = (u8 *)uVar2;
  *(u32 *)(puVar1 + 4) = param_1;
  *(u16 *)(puVar1 + 0x10) = 0xffff;
  *puVar1 = 0;
  *(u32 *)(puVar1 + 0x14) = 0xffffffff;
  *(u32 *)(puVar1 + 0xc) = 0;
  uVar3 = (*DAT_00960178)(0x24,0x40000);
  func_00521408(uVar3,0,0x24);
  puVar4 = (u16 *)uVar3;
  *(u32 *)(puVar4 + 2) = 0xffffffff;
  *(u8 *)(puVar4 + 4) = 0x14;
  *(u32 *)(puVar4 + 6) = 0;
  *puVar4 = 0x200;
  *(u32 *)(puVar4 + 0xe) = 0;
  if (*(int *)(iGpffffb6fc + 400) == 0) {
    *(u32 *)(puVar4 + 0x10) = 0;
  }
  else {
    *(u16 **)(*(int *)(iGpffffb6fc + 400) + 0x1c) = puVar4;
    *(u32 *)(puVar4 + 0x10) = *(u32 *)(iGpffffb6fc + 400);
  }
  *(u16 **)(iGpffffb6fc + 400) = puVar4;
  *(u16 **)(puVar1 + 8) = puVar4;
  return uVar2;
}

// FUN_002bbd00 MATCHING

void func_002bbd00(u32 param_1)

{
  int node;
  void (**release)(u32);
  
  node = *(int *)(param_1 + 8);
  func_002bb580((u16 *)node);
  if (*(int *)(node + 0x20) != 0) {
    *(u32 *)(*(int *)(node + 0x20) + 0x1c) = *(u32 *)(node + 0x1c);
  }
  if (*(int *)(node + 0x1c) != 0) {
    *(u32 *)(*(int *)(node + 0x1c) + 0x20) = *(u32 *)(node + 0x20);
  }
  else {
    *(u32 *)(iGpffffb6fc + 400) = *(u32 *)(node + 0x20);
  }
  release = (void (**)(u32))DAT_0096017c;
  (*release)(node);
  if (*(int *)(param_1 + 0xc) != 0) {
    func_002b9030(*(u32 *)(param_1 + 0xc));
    *(u32 *)(param_1 + 0xc) = 0;
  }
  (*release)(param_1);
}

// FUN_002bbdc0

void func_002bbdc0(u8 *param_1,short param_2)

{
  if (*(short *)(param_1 + 0x10) != param_2) {
    *param_1 = *param_1 | 1;
    *(short *)(param_1 + 0x10) = param_2;
  }
  return;
}

// FUN_002bbdf0

short func_002bbdf0(int param_1)

{
  return *(short *)(param_1 + 0x10);
}

// FUN_002bbe00

void func_002bbe00(u8 *param_1)

{
  u16 *puVar1;
  u32 uVar2 = 0;
  
  if ((*(u32 *)(iGpffffb6fc + 0xc) & 0x40000) != 0) {
    if ((*param_1 & 1) != 0) {
      puVar1 = *(u16 **)(param_1 + 8);
      if (*(int *)(puVar1 + 8) != 0) {
        func_002b94f0((BtlFormationWork *)*(int *)(puVar1 + 8));
        *(u32 *)(puVar1 + 8) = 0;
      }
      if (*(int *)(puVar1 + 10) != 0) {
        func_003257e0(*(int *)(puVar1 + 10));
        *(u32 *)(puVar1 + 10) = 0;
      }
      if (*(int *)(puVar1 + 0xc) != 0) {
        func_003174e0(*(int *)(puVar1 + 0xc));
        *(u32 *)(puVar1 + 0xc) = 0;
      }
      *(u32 *)(puVar1 + 2) = 0xffffffff;
      *(u8 *)(puVar1 + 4) = 0x14;
      *(u32 *)(puVar1 + 6) = 0;
      *puVar1 = 0x200;
      if (*(int *)(param_1 + 0xc) != 0) {
        func_002b9030(*(u32 *)(param_1 + 0xc));
        *(u32 *)(param_1 + 0xc) = 0;
      }
      if (*(short *)(param_1 + 0x10) != -1) {
        *(u32 *)(param_1 + 0xc) =
             ((u32 *)(iGpffffb6fc + 0xc24))[*(short *)(param_1 + 0x10)];
        func_002b9300(*(int *)(param_1 + 0xc));
        uVar2 = func_002b93e0(*(u32 *)(param_1 + 0xc),1,*(u32 *)(param_1 + 4),
                             *(u32 *)(param_1 + 4),0);
        *(u32 *)(*(int *)(param_1 + 8) + 0x10) = uVar2;
      }
      *param_1 = *param_1 & 0xfe;
    }
    if (*(short *)(param_1 + 0x10) != -1) {
      **(u16 **)(param_1 + 8) = **(u16 **)(param_1 + 8) | 0x30;
      *(u32 *)(*(int *)(param_1 + 8) + 4) = *(u32 *)(param_1 + 0x14);
    }
    else {
      **(u16 **)(param_1 + 8) = **(u16 **)(param_1 + 8) & 0xffcf;
    }
  }
  return;
}

// FUN_002bbf80

void func_002bbf80(int param_1,u32 param_2)

{
  *(u32 *)(param_1 + 0x14) = param_2 & 0xff000000 | 0xffffff;
  return;
}

// FUN_002bbfa0

u32 func_002bbfa0(int param_1)
{
  if (param_1 == 0) {
    return 0xffffffff;
  }

  switch (param_1) {
  case 1:
    return 0x27;
  case 2:
    return 0x28;
  case 4:
    return 0x29;
  case 8:
    return 0x2a;
  case 0x10:
    return 0x2b;
  case 0x20:
    return 0x24;
  case 0x40:
    return 0x25;
  case 0x80:
    return 0x26;
  case 0x100:
    return 0x2d;
  case 0x200:
    return 0x2c;
  case 0x400:
  case 0x80000:
  case 0x100000:
  default:
    return 0xffffffff;
  }
}

// FUN_002bc0e0 MATCHING

void func_002bc0e0(int param_1, u8 *param_2)
{
  param_2[3] = 0xff;

  switch (param_1) {
  case 1:
    param_2[0] = 0xff;
    param_2[1] = 0x94;
    param_2[2] = 0xbc;
    return;
  case 2:
    param_2[0] = 0xb2;
    param_2[1] = 0x9e;
    param_2[2] = 0xff;
    return;
  case 4:
    param_2[0] = 0xcd;
    param_2[1] = 0xb2;
    param_2[2] = 0xcd;
    return;
  case 8:
    param_2[0] = 0xa8;
    param_2[1] = 0xa8;
    param_2[2] = 0xff;
    return;
  case 0x10:
    param_2[0] = 0xff;
    param_2[1] = 0xb2;
    param_2[2] = 0x9e;
    return;
  case 0x20:
    param_2[0] = 0x8a;
    param_2[1] = 0xc6;
    param_2[2] = 0xff;
    return;
  case 0x40:
    param_2[0] = 0xf5;
    param_2[1] = 0xda;
    param_2[2] = 0x80;
    return;
  case 0x80:
    param_2[0] = 0xff;
    param_2[1] = 0x6c;
    param_2[2] = 0xe4;
    return;
  case 0x200:
    param_2[0] = 0xff;
    param_2[1] = 0x3a;
    param_2[2] = 0x44;
    return;
  case 0x100: {
    *(RwRGBA*)param_2 = *(const RwRGBA*)&DAT_007cc970;
    return;
  }
  case 0x400:
    param_2[0] = 0xff;
    param_2[1] = 0x40;
    param_2[2] = 0x12;
    return;
  case 0x100000:
  case 0x80000:
  default: {
    *(RwRGBA*)param_2 = *(const RwRGBA*)&DAT_007cc970;
    return;
  }
  }
}

// FUN_002bc2f0 NONMATCHING

void func_002bc2f0(void)

{
  int iVar1 = 0;
  u32 firstIndex = 0;
  u32 uVar2 = 0;
  int iVar3 = 0;
  u8 *state;
  
  if ((*(u32 *)(DAT_007ce3ec + 0x14) & 0x4000000) == 0) {
    for (firstIndex = 0; firstIndex < 0x3c; firstIndex = firstIndex + 1) {
      state = DAT_007ce3ec;
      if (*(int *)(state + firstIndex * 4 + 0xc24) != 0) {
        func_002b9030(*(u32 *)(state + firstIndex * 4 + 0xc24));
        *(u32 *)(DAT_007ce3ec + firstIndex * 4 + 0xc24) = 0;
      }
    }
    if (*(int *)(DAT_007ce3ec + 0xd14) != 0) {
      func_00100ec0(*(u32 *)(DAT_007ce3ec + 0xd14));
      *(u32 *)(DAT_007ce3ec + 0xd14) = 0;
    }
  }
  else {
    for (uVar2 = 0; uVar2 < 0x3c; uVar2 = uVar2 + 1) {
      state = DAT_007ce3ec;
      iVar3 = uVar2 * 4;
      iVar1 = *(int *)(state + iVar3 + 0xc24);
      if (iVar1 != 0) {
        (*DAT_0096017c)(*(u32 *)(iVar1 + 0x634));
        func_002b9030(*(u32 *)(DAT_007ce3ec + iVar3 + 0xc24));
        *(u32 *)(DAT_007ce3ec + iVar3 + 0xc24) = 0;
      }
    }
  }
  *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xfffbffff;
  return;
}

// FUN_002bc420

void func_002bc420(void)
{
  int iVar1 = 0;
  if ((*(u32 *)(DAT_007ce3ec + 0x14) & 0x4000000) == 0) {
    if (*(int *)(DAT_007ce3ec + 0xd14) != 0) {
      func_00100ec0(*(int *)(DAT_007ce3ec + 0xd14));
    }
    *(u32 *)(DAT_007ce3ec + 0xd14) = 0;
  }
  else {
    *(u32 *)(DAT_007ce3ec + 0xd14) = 0;
  }
  return;
}

// FUN_002bc480 NONMATCHING

u32 func_002bc480(void)

{
  extern u32 func_00100d80(void *,u32);
  extern u32 func_001016b0(u32);
  extern u32 func_00102100(u32,u32,u8 *);
  extern void func_00521250(u32,u32,u32);
  u32 uVar1 = 0;
  u32 lVar2 = 0;
  u32 firstIndex = 0;
  u32 resource = 0;
  u32 secondIndex = 0;
  u32 allocated = 0;
  u32 firstValue = 0;
  u32 firstOffset = 0;
  u8 auStack_4[4];
  
  if ((*(u32 *)(DAT_007ce3ec + 0x14) & 0x4000000) == 0) {
    if (*(int *)(DAT_007ce3ec + 0xd14) == 0) {
      uVar1 = func_00100d80(DAT_00696d70_abs,1);
      *(u32 *)(DAT_007ce3ec + 0xd14) = uVar1;
    }
    else {
      lVar2 = func_001016b0(*(u32 *)(DAT_007ce3ec + 0xd14));
      if (lVar2 != 0) {
        for (firstIndex = 0; firstIndex < 0x3c; firstIndex = firstIndex + 1) {
          firstValue = func_00102100(*(u32 *)(DAT_007ce3ec + 0xd14),firstIndex,auStack_4);
          firstOffset = firstIndex * 4;
          uVar1 = func_002b8f90(2);
          *(u32 *)(DAT_007ce3ec + firstOffset + 0xc24) = uVar1;
          func_002b96e0(*(u32 *)(DAT_007ce3ec + firstOffset + 0xc24),firstValue);
        }
        *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x40000;
        return 1;
      }
    }
    uVar1 = 0;
  }
  else {
    for (secondIndex = 0; secondIndex < 0x3c; secondIndex = secondIndex + 1) {
      resource = func_00100d80(PTR_s_battle_effect_ATC_D_BED_abs[secondIndex],0);
      func_001023a0(resource);
      uVar1 = func_002b8f90(2);
      *(u32 *)(DAT_007ce3ec + secondIndex * 4 + 0xc24) = uVar1;
      allocated = (*DAT_00960178_u32_abs)(*(u32 *)(resource + 0x118),0x40000);
      func_00521250(allocated,*(u32 *)(resource + 0x110),*(u32 *)(resource + 0x118));
      func_002b96e0(*(u32 *)(DAT_007ce3ec + secondIndex * 4 + 0xc24),allocated);
      func_00100ec0(resource);
    }
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x40000;
    uVar1 = 1;
  }
  return uVar1;
}

// FUN_002bc680

void func_002bc680(void)

{
  int iVar1 = 0;
  
  iVar1 = func_0027ec10(0x306,0);
  *(u8 *)(iVar1 + 0x47) = *(u8 *)(iVar1 + 0x47) & 0xfe;
  *(code *)(iVar1 + 0x68) = (code)func_002bc420;
  *(code *)(iVar1 + 0x6c) = (code)func_002bc480;
  return;
}

// FUN_002bc6d0 NONMATCHING

void func_002bc6d0(void)

{
  extern u32 func_00100d80(void *,u32);
  extern void func_00521250(u32,u32,u32);
  u32 index = 0;
  u32 offset = 0;
  u32 resource = 0;
  u32 allocated = 0;

  while (index == 0) {
    offset = index * 4;
    resource = func_00100d80(*(char **)((u8 *)&PTR_s_battle_effect_SHADOW_S_BED_007cc6f0 + offset),0);
    func_001023a0(resource);
    *(u32 *)((u8 *)&_DAT_007ce4f4 + offset) = func_002b8f90(2);
    allocated = (*DAT_00960178_u32_abs)(*(u32 *)(resource + 0x118),0x40000);
    func_00521250(allocated,*(u32 *)(resource + 0x110),*(u32 *)(resource + 0x118));
    func_002b96e0(*(u32 *)((u8 *)&_DAT_007ce4f4 + offset),allocated);
    func_00100ec0(resource);
    index++;
  }
  return;
}

// FUN_002bc7b0

u32 func_002bc7b0(u16 *param_1)

{
  func_00351bb0(*param_1);
  return 1;
}

// FUN_002bc7e0

void func_002bc7e0(u16 param_1)

{
  int iVar1 = 0;
  
  iVar1 = func_0027ec10(0x308,2);
  *(code *)(iVar1 + 0x6c) = (code)func_002bc7b0;
  **(u16 **)(iVar1 + 0x78) = param_1;
  return;
}

// FUN_002bc830

u32 func_002bc830(u8 *param_1)

{
  func_00108570();
  func_00108670(8);
  func_00108680(*param_1,param_1[1],param_1[2]);
  func_001086a0(*(short *)(param_1 + 4));
  return 1;
}

// FUN_002bc890

void func_002bc890(u8 *param_1,u16 param_2)

{
  typedef struct BtlMessageArgs {
    u8 values[4];
  } BtlMessageArgs;
  u8 *work;
  int packet = 0;
  
  packet = func_0027ec10(0x30a,6);
  *(code *)(packet + 0x6c) = (code)func_002bc830;
  work = *(u8 **)(packet + 0x78);
  *(BtlMessageArgs *)work = *(BtlMessageArgs *)param_1;
  *(u16 *)(work + 4) = param_2;
  return;
}

// FUN_002bc910

u32 func_002bc910(u32 *param_1)

{
  func_00352c50(*param_1,param_1[1],param_1[2]);
  return 1;
}

// FUN_002bc950

void func_002bc950(u32 param_1,u32 param_2,u32 param_3)

{
  u32 *puVar1;
  int iVar2 = 0;
  
  iVar2 = func_0027ec10(0x309,0xc);
  *(code *)(iVar2 + 0x6c) = (code)func_002bc910;
  puVar1 = *(u32 **)(iVar2 + 0x78);
  *puVar1 = param_1;
  puVar1[1] = param_2;
  puVar1[2] = param_3;
  return;
}

// FUN_002bc9c0 NONMATCHING

void func_002bc9c0(float param_1,float param_2,float param_3,float param_4,float param_5,
                 float param_6,u32 param_7,long param_8)

{
  int iVar1 = 0;
  u32 uVar2 = 0;
  float fVar3 = 0;
  float fStack_100 = 0;
  float fStack_fc = 0;
  float afStack_f8 [62] = {0};
  
  iVar1 = func_00198590();
  fVar3 = *(float *)(iVar1 + 0x80);
  for (uVar2 = 0; uVar2 < 4; uVar2 = uVar2 + 1) {
    afStack_f8[uVar2 * 0x10 + 4] = 1.0 / fVar3;
    afStack_f8[uVar2 * 0x10 + 6] = (float)(param_7 >> 0x18);
    afStack_f8[uVar2 * 0x10 + 7] = (float)(param_7 >> 0x10 & 0xff);
    afStack_f8[uVar2 * 0x10 + 8] = (float)(param_7 >> 8 & 0xff);
    afStack_f8[uVar2 * 0x10 + 9] = (float)(param_7 & 0xff);
    afStack_f8[uVar2 * 0x10] = DAT_00960088;
  }
  if (param_8 != 0) {
    afStack_f8[0x22] = (float)*(int *)((int)param_8 + 0xc);
    afStack_f8[0x13] = (float)*(int *)((int)param_8 + 0x10);
    afStack_f8[2] = param_5 / afStack_f8[0x22];
    afStack_f8[3] = param_6 / afStack_f8[0x13];
    afStack_f8[0x13] = (param_6 + param_4) / afStack_f8[0x13];
    afStack_f8[0x22] = (param_5 + param_3) / afStack_f8[0x22];
    afStack_f8[0x12] = afStack_f8[2];
    afStack_f8[0x23] = afStack_f8[0x13];
    afStack_f8[0x32] = afStack_f8[0x22];
    afStack_f8[0x33] = afStack_f8[3];
  }
  (*DAT_00960090)(6,0);
  (*DAT_00960090)(7,2);
  (*DAT_00960090)(8,0);
  (*DAT_00960090)(10,5);
  (*DAT_00960090)(0xb,6);
  (*DAT_00960090)(9,2);
  (*DAT_00960090)(0xc,1);
  (*DAT_00960090)(1,param_8);
  afStack_f8[0xf] = param_2 + param_4;
  afStack_f8[0x1e] = param_1 + param_3;
  fStack_100 = param_1;
  fStack_fc = param_2;
  afStack_f8[0xe] = param_1;
  afStack_f8[0x1f] = afStack_f8[0xf];
  afStack_f8[0x2e] = afStack_f8[0x1e];
  afStack_f8[0x2f] = param_2;
  (*DAT_009600a4)(3,&fStack_100,4,0x696da8,6);
  return;
}

// FUN_002bccd0 NONMATCHING

void func_002bccd0(u32 param_1,u32 param_2)

{
  char cVar1 = 0;
  u16 uVar2 = 0;
  int in_v0_lo = 0;
  
  if (param_1 != 0) {
    uVar2 = *(u16 *)((int)param_1 + 0xa4);
    cVar1 = *(char *)((int)param_1 + 0xa2);
    if (cVar1 == '\x02') {
      in_v0_lo = func_00173220(uVar2);
    }
    else if (cVar1 == '\x01') {
      in_v0_lo = (int)(DAT_007ce4e8 + (u32)uVar2 * 0x12 + (u32)uVar2);
    }
    else if (cVar1 == '\0') {
      in_v0_lo = func_001778b0(uVar2);
    }
    func_003a4220(*(u32 *)(DAT_007ce3ec + 0xba0),0,in_v0_lo);
  }
  if (param_2 < 0x1000) {
    func_001fea10(*(u32 *)(DAT_007ce3ec + 0xba0),param_2);
  }
  else {
    func_001fe9b0(DAT_007ce4ec + ((int)param_2 - 0x1000U & 0xffff) * 0x13);
  }
  return;
}

// FUN_002bcde0

void func_002bcde0(u64 param_1,u32 *param_2)

{
  *param_2 = 0xbf800000;
  param_2[1] = 0x3f800000;
  *(short *)(param_2 + 4) = -1;
  param_2[5] = 0xbf800000;
  param_2[6] = 0x3f800000;
  *(short *)(param_2 + 9) = -1;
  return;
}

// FUN_002bce10 NONMATCHING

void func_002bce10(float param_1,float param_2,int param_3,int param_4,float *param_5)

{
  short sVar1 = 0;
  long lVar2 = 0;
  u64 uVar3 = 0;
  u64 uVar4 = 0;
  int iVar5 = 0;
  float fVar6 = 0;
  float fVar7 = 0;
  float fStack_8 = 0;
  float fStack_4 = 0;
  
  if (0.0 <= *param_5) {
    param_5[3] = *param_5;
    param_5[2] = param_5[1];
    *param_5 = -1.0;
    *(u16 *)(param_5 + 4) = 0;
  }
  sVar1 = *(short *)(param_5 + 4);
  if ((-1 < sVar1) && (sVar1 < 0x1c)) {
    if (sVar1 < 0x10) {
      param_5[1] = ((float)(int)sVar1 / 16.0) * (param_5[3] - param_5[2]) + param_5[2] + 0.0;
    }
    else {
      param_5[1] = param_5[3];
    }
    lVar2 = func_001fef10(*(u32 *)(param_3 + 0xa8),&fStack_8);
    if ((lVar2 != 0) && (param_4 != '\0')) {
      fVar6 = param_5[1];
      param_2 = fStack_4 + param_2;
      uVar3 = func_0021c3f0(1);
      uVar3 = func_0021cca0(uVar3,1);
      uVar4 = func_0021cce0(uVar3);
      iVar5 = (int)uVar3;
      fVar7 = (fStack_8 + param_1) - (float)(*(int *)(iVar5 + 0xc) >> 1);
      func_002bc9c0(fVar7,param_2,(float)*(int *)(iVar5 + 0xc),(float)*(int *)(iVar5 + 0x10),
                   (float)*(int *)(iVar5 + 0x14),(float)*(int *)(iVar5 + 0x18),0xffffffffffffffff,
                   uVar4);
      uVar3 = func_0021c3f0(5);
      uVar3 = func_0021cca0(uVar3,4);
      uVar4 = func_0021cce0(uVar3);
      iVar5 = (int)uVar3;
      func_002bc9c0(fVar7 + 8.0,param_2 + 4.0,(float)(int)((float)*(int *)(iVar5 + 0xc) * fVar6),
                   (float)*(int *)(iVar5 + 0x10),(float)(int)((float)*(int *)(iVar5 + 0x14) * fVar6)
                   ,(float)*(int *)(iVar5 + 0x18),0xffffffffffffffff,uVar4);
    }
    *(short *)(param_5 + 4) = *(short *)(param_5 + 4) + 1;
  }
  return;
}


// FUN_002bd080 NONMATCHING

u32 func_002bd080(int *work)

{
  int unit;
  s16 current;
  s16 maximum;
  long value;
  long adjusted;

  unit = *work;
  switch (*(u8 *)((int)work + 4)) {
  case 0:
    current = func_002ffd70(*(u32 *)(unit + 0xa2c));
    maximum = func_002ffdf0(*(u32 *)(unit + 0xa2c));
    value = (long)current;
    if (*(s16 *)((int)work + 6) != 0) {
      adjusted = (long)(s16)(current + *(s16 *)((int)work + 6));
      value = (long)maximum;
      if (adjusted <= value) {
        value = adjusted;
        if (adjusted < 0) {
          value = 0;
        }
      }
    }
    *(float *)(unit + 0xa04) = (float)(int)value / (float)(int)maximum;
    break;
  case 1:
    current = func_002ffd80(*(u32 *)(unit + 0xa2c));
    maximum = func_00300100(*(u32 *)(unit + 0xa2c));
    value = (long)current;
    if (*(s16 *)((int)work + 6) != 0) {
      adjusted = (long)(s16)(current + *(s16 *)((int)work + 6));
      value = (long)maximum;
      if (adjusted <= value) {
        value = adjusted;
        if (adjusted < 0) {
          value = 0;
        }
      }
    }
    *(float *)(unit + 0xa18) = (float)(int)value / (float)(int)maximum;
    break;
  }
  return 1;
}


// FUN_002bd230

void func_002bd230(u32 param_1,u8 param_2,u16 param_3)

{
  u32 *puVar1;
  int iVar2 = 0;
  
  iVar2 = func_0027ec10(0x500,8);
  *(u8 *)(iVar2 + 0x47) = *(u8 *)(iVar2 + 0x47) & 0xef;
  *(code *)(iVar2 + 0x68) = (code)LAB_002bd060;
  *(code *)(iVar2 + 0x6c) = (code)func_002bd080;
  *(code *)(iVar2 + 0x70) = (code)LAB_002bd210;
  puVar1 = *(u32 **)(iVar2 + 0x78);
  *puVar1 = param_1;
  *(u8 *)(puVar1 + 1) = param_2;
  *(u16 *)((int)puVar1 + 6) = param_3;
  return;
}

// FUN_002bd2c0
void btlFormationInit0501Packet(void* work)
{
    BtlUnit* unit;

    unit = *(BtlUnit**)work;
    unit->packetCount++;
}

// FUN_002bd2e0

u32 func_002bd2e0(int *param_1)

{
  int unit;

  unit = *param_1;
  *(float *)(unit + 0xa08) =
      (float)func_002ffd70(*(u32 *)(unit + 0xa2c)) /
      (float)func_002ffdf0(*(u32 *)(unit + 0xa2c));
  *(float *)(unit + 0xa04) = -1.0f;
  *(s16 *)(unit + 0xa14) = -1;
  *(float *)(unit + 0xa1c) =
      (float)func_002ffd80(*(u32 *)(unit + 0xa2c)) /
      (float)func_00300100(*(u32 *)(unit + 0xa2c));
  *(float *)(unit + 0xa04) = -1.0f;
  *(s16 *)(unit + 0xa28) = -1;
  return 1;
}

// FUN_002bd460
void btlFormationDestroy0501Packet(void* work)
{
    BtlUnit* unit;

    unit = *(BtlUnit**)work;
    unit->packetCount--;
}


// FUN_002bd480

void func_002bd480(u32 param_1)

{
  int iVar1 = 0;
  
  iVar1 = func_0027ec10(0x501,4);
  *(u8 *)(iVar1 + 0x47) = *(u8 *)(iVar1 + 0x47) & 0xef;
  *(code *)(iVar1 + 0x68) = (code)btlFormationInit0501Packet;
  *(code *)(iVar1 + 0x6c) = (code)func_002bd2e0;
  *(code *)(iVar1 + 0x70) = (code)btlFormationDestroy0501Packet;
  **(u32 **)(iVar1 + 0x78) = param_1;
  return;
}


// FUN_002bd4f0
u32 func_002bd4f0(int param_1)
{
  u32 uVar1;
  u32 uVar2;

  if ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x200) == 0) {
    uVar1 = 1;
  }
  else {
    if (*(int *)(param_1 + 8) == 0) {
      func_001fe9b0(DAT_007ce4ec + (u32)*(u16 *)(param_1 + 4) * 0x13);
    }
    uVar2 = *(int *)(param_1 + 8) + 1;
    *(u32 *)(param_1 + 8) = uVar2;
    if (uVar2 >= 0x2d) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

// FUN_002bd590

void func_002bd590(u32 param_1,u16 param_2)

{
  u32 *puVar1;
  int iVar2 = 0;
  
  iVar2 = func_0027ec10(0x504,0xc);
  *(code *)(iVar2 + 0x6c) = (code)func_002bd4f0;
  puVar1 = *(u32 **)(iVar2 + 0x78);
  *puVar1 = param_1;
  *(u16 *)(puVar1 + 1) = param_2;
  puVar1[2] = 0;
  return;
}


// FUN_002bd5f0
u32 func_002bd5f0(int param_1)
{
  u32 uVar1;
  u32 uVar2;
  const char* text;

  if ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x200) == 0) {
    uVar1 = 1;
  }
  else {
    if (*(int *)(param_1 + 8) == 0) {
      text = func_00171110(*(s16 *)(param_1 + 4), 0);
      func_001fe9b0(text);
    }
    uVar2 = *(int *)(param_1 + 8) + 1;
    *(u32 *)(param_1 + 8) = uVar2;
    if (uVar2 >= 0x2d) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

// FUN_002bd690

void func_002bd690(u32 param_1,u16 param_2)

{
  u32 *puVar1;
  int iVar2 = 0;
  
  iVar2 = func_0027ec10(0x505,0xc);
  *(code *)(iVar2 + 0x6c) = (code)func_002bd5f0;
  puVar1 = *(u32 **)(iVar2 + 0x78);
  *puVar1 = param_1;
  *(u16 *)(puVar1 + 1) = param_2;
  puVar1[2] = 0;
  return;
}

// FUN_002bd6f0

u32 func_002bd6f0(int param_1)
{
  u32 result;
  u32 frame;

  if (*(int *)(param_1 + 8) == 0) {
    if (*(u16 *)(param_1 + 4) == 0) {
      result = 1;
      goto done;
    }
    func_001fe9b0(PTR_s_N_00646555_0x12_00696dcc[*(u16 *)(param_1 + 4)]);
  }
  frame = *(int *)(param_1 + 8) + 1;
  *(u32 *)(param_1 + 8) = frame;
  if (frame >= 0x2d) {
    result = 1;
  }
  else {
    result = 0;
  }

done:
  return result;
}

// FUN_002bd780

void func_002bd780(u32 param_1,u16 param_2)

{
  u32 *puVar1;
  int iVar2 = 0;
  
  iVar2 = func_0027ec10(0x507,0xc);
  *(code *)(iVar2 + 0x6c) = (code)func_002bd6f0;
  puVar1 = *(u32 **)(iVar2 + 0x78);
  *puVar1 = param_1;
  *(u16 *)(puVar1 + 1) = param_2;
  puVar1[2] = 0;
  return;
}

// FUN_002bd7e0

bool func_002bd7e0(u32 *param_1)

{
  u32 frame;

  if (param_1[2] == 0) {
    func_002bccd0(*param_1,param_1[1]);
  }
  frame = param_1[2] + 1;
  param_1[2] = frame;
  if (0x2d < frame) {
    return true;
  }
  return false;
}

// FUN_002bd850

void func_002bd850(u32 param_1,u32 param_2)

{
  u32 *puVar1;
  int iVar2 = 0;
  
  iVar2 = func_0027ec10(0x506,0xc);
  *(code *)(iVar2 + 0x6c) = (code)func_002bd7e0;
  puVar1 = *(u32 **)(iVar2 + 0x78);
  *puVar1 = param_1;
  puVar1[1] = param_2;
  puVar1[2] = 0;
  return;
}

// FUN_002bd8b0
void btlFormationInit050aPacket(void* work)
{
    BtlUnit** units;

    units = (BtlUnit**)work;
    units[0]->packetCount++;
    units[1]->packetCount++;
}

// FUN_002bd8e0 NONMATCHING

u32 func_002bd8e0(int *param_1)

{
  char cVar1 = 0;
  bool bVar2 = 0;
  u16 uVar3 = 0;
  u32 uVar4 = 0;
  long lVar5 = 0;
  int iVar6 = 0;
  u32 uVar7 = 0;
  int iVar8 = 0;
  int iVar9 = 0;
  int iStack_20 = 0;
  int iStack_1c = 0;
  u32 uStack_18 = 0;
  u32 uStack_14 = 0;
  u32 uStack_10 = 0;
  u32 uStack_c = 0;
  u32 uStack_8 = 0;
  
  if (param_1[0xc] == 0) {
    lVar5 = func_001feb50(*(u32 *)(param_1[1] + 0xa8));
    if ((lVar5 == 0) || ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x800) == 0)) {
      return 1;
    }
  }
  else {
    uVar7 = 0;
    if (((*(u16 *)(param_1 + 10) & 4) == 0) &&
       ((((param_1[2] != 0 || (param_1[3] != 0)) || (param_1[4] != 0)) ||
        ((param_1[5] != 0 || (param_1[6] != 0)))))) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    iVar9 = param_1[2];
    if (iVar9 == 0) {
      iVar9 = 0;
    }
    else {
      uVar7 = 0x10;
    }
    iVar8 = param_1[3];
    if (iVar8 == 0) {
      iVar8 = 0;
    }
    else {
      uVar7 = uVar7 | 0x20;
    }
    if ((u32)*(u16 *)((int)param_1 + 0x2e) == *(u16 *)(param_1 + 0xb) + 1) {
      if (((*(u16 *)((int)param_1 + 0x2a) & 2) != 0) && (!bVar2)) {
        uVar7 = uVar7 | 1;
      }
      if (((*(u16 *)((int)param_1 + 0x2a) & 4) != 0) && (!bVar2)) {
        uVar7 = uVar7 | 2;
      }
      if ((*(u16 *)(param_1 + 10) & 0x100) == 0) {
        if (bVar2) {
          uVar7 = uVar7 | 4;
        }
      }
      else {
        if ((param_1[9] == 0xffffffff) || (*(int *)(*param_1 + 0xa2c) == 0)) {
          uVar4 = 0;
        }
        else {
          uVar3 = func_003082f0(*(int *)(*param_1 + 0xa2c),param_1[9] & 0xffff);
          uVar4 = func_003080c0(uVar3);
        }
        if ((uVar4 & 0x1f800) == 0) {
          uVar7 = uVar7 | 8;
        }
        else {
          uVar7 = uVar7 | 4;
        }
      }
      if ((param_1[4] & 0x100000U) != 0) {
        uVar7 = uVar7 | 0x40;
      }
    }
    if (-1 < param_1[9]) {
      iVar6 = param_1[9] * 0x2c;
      cVar1 = *(char *)(iVar6 + DAT_007ce3f8 + 8);
      if ((cVar1 == '\x02') || (cVar1 == '\x01')) {
        uVar7 = uVar7 | 0x80;
      }
      if ((*(u8 *)(DAT_007ce3f8 + iVar6) & 0x20) != 0) {
        uVar7 = uVar7 & 0xfffffffb;
      }
    }
    uStack_14 = *(u32 *)(*param_1 + 0xa8);
    uStack_10 = *(u32 *)(param_1[1] + 0xa8);
    uStack_8 = (u32)*(u16 *)(param_1 + 0xb);
    uStack_c = (u32)*(u16 *)((int)param_1 + 0x2e);
    iStack_20 = iVar9;
    iStack_1c = iVar8;
    uStack_18 = uVar7;
    func_001fe650(&iStack_20);
    param_1[0xc] = 0;
  }
  return 0;
}

// FUN_002bdba0
void btlFormationDestroy050aPacket(void* work)
{
    BtlUnit** units;

    units = (BtlUnit**)work;
    units[0]->packetCount--;
    units[1]->packetCount--;
}

// FUN_002bdbd0

int func_002bdbd0(u32 param_1,u32 param_2,u32 param_3,u16 param_4,
                u16 param_5,u16 param_6,u16 param_7,u64 param_8)

{
  u32 *puVar1;
  int iVar2 = 0;
  
  iVar2 = func_0027ec10(0x50a,0x34);
  *(code *)(iVar2 + 0x68) = (code)btlFormationInit050aPacket;
  *(code *)(iVar2 + 0x6c) = (code)func_002bd8e0;
  *(code *)(iVar2 + 0x70) = (code)btlFormationDestroy050aPacket;
  puVar1 = *(u32 **)(iVar2 + 0x78);
  func_00521250(puVar1 + 2,param_8,0x1c);
  *puVar1 = param_1;
  puVar1[1] = param_2;
  puVar1[9] = param_3;
  *(u16 *)(puVar1 + 10) = param_4;
  *(u16 *)((int)puVar1 + 0x2a) = param_5;
  *(u16 *)(puVar1 + 0xb) = param_6;
  *(u16 *)((int)puVar1 + 0x2e) = param_7;
  puVar1[0xc] = 1;
  return iVar2;
}

// FUN_002bdcd0 MATCHING

u32 func_002bdcd0(u16* state)
{
  u64 result;

  switch (*state) {
  case 0:
    result = func_001fea90();
    if (result == 0) {
      return 1;
    }
    result = func_002d1a70();
    if (result == 1) {
      *(u32 *)(DAT_007ce3ec + 0xc) &= ~0x4000;
      func_002d1a10();
      func_001ff350();
    }
    func_001feab0();
    *state = 1;
    goto return_zero;
  case 1:
    result = func_001feb30();
    if (result != 0) {
      goto return_zero;
    }
    result = func_002d1a70();
    if (result == 1) {
      *(u32 *)(DAT_007ce3ec + 0xc) |= 0x4000;
      func_001ff370();
    }
    return 1;
  default:
    goto return_zero;
  }
return_zero:
  return 0;
}

// FUN_002bddd0

void func_002bddd0(void)

{
  int iVar1 = 0;
  
  iVar1 = func_0027ec10(0x50b,2);
  *(code *)(iVar1 + 0x6c) = (code)func_002bdcd0;
  **(u16 **)(iVar1 + 0x78) = 0;
  return;
}

// FUN_002bde10 NONMATCHING

u32 func_002bde10(int unit, u16* output)
{
  u16 skill;
  u16 nextSkill;
  u16 count;
  u16 index;
  u16* unitSkills;
  u16 lastIndex;
  bool swapped;

  count = 0;
  unitSkills = (u16*)func_00308bb0_u32(*(u32 *)(*(int *)(unit + 0x30) + 0xa2c));
  for (index = 0; index < 8; index++) {
    skill = unitSkills[index];
    if (skill != 0 && skill < 0x1d0 &&
        (*(u8 *)(DAT_007ce3f8 + (u32)skill * 0x2c + 1) & 2) != 0) {
      if (output != 0) {
        output[count] = skill;
      }
      count++;
    }
  }
  if (output != 0) {
    for (index = count; index < 8; index++) {
      output[index] = 0;
    }
    if (count > 1) {
      lastIndex = count - 1;
      do {
        swapped = false;
        for (index = 0; index < lastIndex; index++) {
          skill = output[index];
          nextSkill = output[index + 1];
          if (nextSkill < skill) {
            output[index] = nextSkill;
            output[index + 1] = skill;
            swapped = true;
          }
        }
      } while (swapped);
    }
  }
  return count;
}

// FUN_002bdfb0 NONMATCHING

u32 func_002bdfb0(int state)
{
  FormationMenuState* menu;
  s16 steps;
  s16 index;
  s16 firstEntry;
  s16 selectedEntry;
  long selected;
  u32 result;

  menu = (FormationMenuState*)state;
  if (menu->selectedEntry >= menu->entryCount) {
    menu->selectedEntry = menu->entryCount - 1;
    menu->firstEntry = menu->entryCount - menu->visibleEntries;
    if (menu->firstEntry < 0) {
      menu->firstEntry = 0;
    }
  }

  if ((DAT_007e094e_abs[0] & 0x40) != 0 || (DAT_007e0958_abs[0] & 0x40) != 0) {
    result = 2;
  } else if ((DAT_007e094e_abs[0] & 0x20) != 0 || (DAT_007e0958_abs[0] & 0x20) != 0) {
    result = 1;
  } else {
    if ((DAT_007e0952_abs[0] & 0x1000) != 0 || (DAT_007e095a_abs[0] & 0x1000) != 0 ||
        (DAT_007e0952_abs[0] & 0x8000) != 0 || (DAT_007e095a_abs[0] & 0x8000) != 0) {
      if ((DAT_007e0952_abs[0] & 0x1000) == 0 && (DAT_007e095a_abs[0] & 0x1000) == 0) {
        steps = menu->visibleEntries;
      } else {
        steps = 1;
      }
      for (index = 0; index < steps; index++) {
        firstEntry = menu->firstEntry;
        selectedEntry = menu->selectedEntry;
        if ((long)(firstEntry + 1) < (long)selectedEntry) {
          menu->selectedEntry = selectedEntry - 1;
        } else if (firstEntry < 1) {
          if ((long)selectedEntry == 1) {
            menu->selectedEntry = 0;
          } else {
            menu->firstEntry = menu->entryCount - menu->visibleEntries;
            if (menu->firstEntry < 0) {
              menu->firstEntry = 0;
            }
            menu->selectedEntry = menu->entryCount - 1;
          }
        } else {
          menu->firstEntry = firstEntry - 1;
          menu->selectedEntry--;
        }
      }
      result = 3;
    } else if ((DAT_007e0952_abs[0] & 0x4000) != 0 || (DAT_007e095a_abs[0] & 0x4000) != 0 ||
               (DAT_007e0952_abs[0] & 0x2000) != 0 || (DAT_007e095a_abs[0] & 0x2000) != 0) {
      if ((DAT_007e0952_abs[0] & 0x4000) == 0 && (DAT_007e095a_abs[0] & 0x4000) == 0) {
        steps = menu->visibleEntries;
      } else {
        steps = 1;
      }
      for (index = 0; index < steps; index++) {
        selected = (long)menu->selectedEntry;
        if (selected < (int)menu->firstEntry + (int)menu->visibleEntries - 2 &&
            selected < menu->entryCount - 2) {
          menu->selectedEntry++;
        } else if ((long)menu->firstEntry < (long)(menu->entryCount - menu->visibleEntries)) {
          menu->firstEntry++;
          menu->selectedEntry++;
        } else if (selected < menu->entryCount - 1) {
          menu->selectedEntry++;
        } else {
          menu->firstEntry = 0;
          menu->selectedEntry = 0;
        }
      }
      result = 4;
    } else {
      result = 0;
    }
  }

  return result;
}

// FUN_002be2f0 NONMATCHING

u32 func_002be2f0(int param_1)
{
  u16 state;
  void *entry;

  state = func_002bdfb0(param_1);
  if (state == 2) {
    entry = (&PTR_DAT_00696f30)[*(short *)(param_1 + 6)];
    *(void **)(param_1 + 0x24) = entry;
    *(int *)((u8 *)entry + 0x20) = param_1;
    if (*(void (**)(void *))((u8 *)entry + 0x10) != 0) {
      (*(void (**)(void *))((u8 *)entry + 0x10))(entry);
    }
    return 2;
  }
  if (state == 1) {
    *(u16 *)(param_1 + 4) = 0;
    *(u16 *)(param_1 + 6) = 0;
  }
  return 0;
}

// FUN_002be390 NONMATCHING

void func_002be390(short *param_1,short param_2,short param_3)

{
  short sVar1 = 0;
  short sVar2 = 0;
  int iVar3 = 0;
  int iVar4 = 0;
  short sVar5 = 0;
  short sVar6 = 0;
  
  func_002bc9c0((float)((int)param_2 + (int)*param_1 + -2),
               (float)((int)param_3 + (int)param_1[1] + -2),
               (float)(param_1[4] * 0x12 + (int)param_1[4] + 4),(float)(param_1[5] * 0x12 + 4),0,0,
               0xffffffffc0c0c0c0,0);
  sVar1 = *param_1;
  iVar3 = (int)param_1[1] + (int)param_3 + -8;
  sVar2 = param_1[2];
  iVar4 = sVar2 * 4 + 0x696d90;
  for (sVar6 = 0; sVar5 = (short)iVar3, sVar6 < param_1[5]; sVar6 = sVar6 + 1) {
    iVar3 = (int)sVar6;
    if ((long)param_1[3] == (long)(sVar2 + iVar3)) {
      func_003b2cb0(0,sVar1 + param_2,sVar5,0xffffffffffffffff,1,2,*(u32 *)(iVar4 + iVar3 * 4)
                   ,0,0);
    }
    else {
      func_003b2cb0(0,sVar1 + param_2,sVar5,0xffffffffffffffff,0,2,*(u32 *)(iVar4 + iVar3 * 4)
                   ,0,0);
    }
    iVar3 = sVar5 + 0x12;
  }
  return;
}

// FUN_002be580

u32 func_002be580(u64 param_1,int param_2)

{
  u16 uVar1 = 0;
  
  *(u16 *)(param_2 + 0x6c) = 1;
  uVar1 = func_00308930(*(u32 *)(*(int *)(param_2 + 0x30) + 0xa2c));
  *(u16 *)(param_2 + 0x6e) = uVar1;
  return 4;
}

// FUN_002BE5D0

u32 func_002BE5D0(u64 param_1,int param_2)
{
  *(u16 *)(param_2 + 0x6c) = 6;
  *(u16 *)(param_2 + 0x6e) = 0;
  return 6;
}

// FUN_002BE5F0

u32 func_002BE5F0(u64 param_1,int param_2)
{
  *(u16 *)(param_2 + 0x6c) = 7;
  *(u16 *)(param_2 + 0x6e) = 0;
  return 6;
}

// FUN_002BE610

void func_002BE610(int param_1)
{
  *(u16 *)(param_1 + 0xc) = 0x26f;
}

// FUN_002be620 NONMATCHING

u64 func_002be620(u64 param_1,u64 param_2)

{
  u16 uVar1 = 0;
  short sVar2 = 0;
  u64 uVar3 = 0;
  int iVar4 = 0;
  int iVar5 = 0;
  u16 auStack_20 [16] = {0};
  
  iVar5 = (int)param_1;
  if ((*(u32 *)(DAT_007ce3ec + 0x14) & 0x2000000) == 0) {
    uVar1 = func_002bde10(param_2,(u16*)auStack_20);
    *(u16 *)(iVar5 + 0xc) = uVar1;
  }
  else {
    *(u16 *)(iVar5 + 0xc) = 0x26f;
  }
  sVar2 = func_002bdfb0(param_1);
  if (sVar2 == 2) {
    iVar4 = (int)param_2;
    *(u16 *)(iVar4 + 0x6c) = 2;
    if ((*(u32 *)(DAT_007ce3ec + 0x14) & 0x2000000) == 0) {
      *(u16 *)(iVar4 + 0x6e) = auStack_20[*(short *)(iVar5 + 6)];
    }
    else {
      *(short *)(iVar4 + 0x6e) = *(short *)(iVar5 + 6) + 1;
    }
    uVar3 = 3;
  }
  else {
    uVar3 = 1;
    if (sVar2 != 1) {
      uVar3 = 0;
    }
  }
  return uVar3;
}

// FUN_002be720 NONMATCHING

void func_002be720(short *param_1,short param_2,short param_3,u64 param_4)

{
  short sVar1 = 0;
  short sVar2 = 0;
  u32 uVar3 = 0;
  int iVar4 = 0;
  u32 uVar5 = 0;
  short sVar6 = 0;
  short sVar7 = 0;
  u16 auStack_20020 [65528] = {0};
  u16 auStack_20 [16] = {0};
  
  func_002bc9c0((float)((int)param_2 + (int)*param_1 + -2),
               (float)((int)param_3 + (int)param_1[1] + -2),
               (float)(param_1[4] * 0x12 + (int)param_1[4] + 4),(float)(param_1[5] * 0x12 + 4),0,0,
               0xffffffffc0c0c0c0,0);
  if ((*(u32 *)(DAT_007ce3ec + 0x14) & 0x2000000) == 0) {
    sVar2 = func_002bde10(param_4,(u16*)auStack_20);
    param_1[6] = sVar2;
  }
  else {
    param_1[6] = 0x26f;
  }
  uVar5 = (u32)param_1[6];
  if ((long)param_1[5] <= (long)uVar5) {
    uVar5 = (long)param_1[5];
  }
  sVar2 = *param_1;
  iVar4 = (int)param_1[1] + (int)param_3 + -8;
  sVar1 = param_1[2];
  for (sVar7 = 0; sVar6 = (short)iVar4, (long)sVar7 < (long)(uVar5 & 0xffff); sVar7 = sVar7 + 1) {
    iVar4 = (int)sVar7;
    if ((*(u32 *)(DAT_007ce3ec + 0x14) & 0x2000000) == 0) {
      uVar3 = (u32)auStack_20[sVar1 + iVar4];
    }
    else {
      uVar3 = sVar1 + iVar4 + 1U & 0xffff;
    }
    if ((long)param_1[3] == (long)(sVar1 + iVar4)) {
      func_003b2cb0(0,sVar2 + param_2,sVar6,0xffffffffffffffff,1,2,DAT_007ce4ec + uVar3 * 0x13,0,0);
    }
    else {
      func_003b2cb0(0,sVar2 + param_2,sVar6,0xffffffffffffffff,0,2,DAT_007ce4ec + uVar3 * 0x13,0,0);
    }
    iVar4 = sVar6 + 0x12;
  }
  return;
}

// FUN_002be9e0 NONMATCHING

u64 func_002be9e0(int param_1,int param_2)

{
  short sVar1 = 0;
  u16 uVar2 = 0;
  u64 uVar3 = 0;
  int extraout_a0_lo = 0;
  
  *(u16 *)(param_1 + 0xc) = 0xdf;
  sVar1 = func_002bdfb0(0);
  if (sVar1 == 2) {
    *(u16 *)(param_2 + 0x6c) = 3;
    *(short *)(param_2 + 0x70) = *(short *)(extraout_a0_lo + 6) + 0xfa1;
    uVar2 = func_0030bc20(*(u16 *)(param_2 + 0x70));
    *(u16 *)(param_2 + 0x6e) = uVar2;
    uVar3 = 3;
  }
  else {
    uVar3 = 1;
    if (sVar1 != 1) {
      uVar3 = 0;
    }
  }
  return uVar3;
}

// FUN_002bea80 NONMATCHING

void func_002bea80(short *param_1,short param_2,short param_3)

{
  short sVar1 = 0;
  short sVar2 = 0;
  const char* uVar3 = NULL;
  int iVar4 = 0;
  short sVar5 = 0;
  u32 uVar6 = 0;
  short sVar7 = 0;
  short sVar8 = 0;
  
  func_002bc9c0((float)((int)param_2 + (int)*param_1 + -2),
               (float)((int)param_3 + (int)param_1[1] + -2),
               (float)(param_1[4] * 0x12 + (int)param_1[4] + 4),(float)(param_1[5] * 0x12 + 4),0,0,
               0xffffffffc0c0c0c0,0);
  uVar6 = 0xdf;
  param_1[6] = 0xdf;
  if ((long)param_1[5] < 0xe0) {
    uVar6 = (long)param_1[5];
  }
  sVar1 = *param_1;
  iVar4 = (int)param_1[1] + (int)param_3 + -8;
  sVar2 = param_1[2];
  for (sVar8 = 0; sVar7 = (short)iVar4, (long)sVar8 < (long)(uVar6 & 0xffff); sVar8 = sVar8 + 1) {
    sVar5 = sVar2 + 0xfa1 + sVar8;
    if ((long)param_1[3] == (long)((int)sVar2 + (int)sVar8)) {
      uVar3 = func_00171110(sVar5,0);
      func_003b2cb0(0,sVar1 + param_2,sVar7,0xffffffffffffffff,1,2,uVar3,0,0);
    }
    else {
      uVar3 = func_00171110(sVar5,0);
      func_003b2cb0(0,sVar1 + param_2,sVar7,0xffffffffffffffff,0,2,uVar3,0,0);
    }
    iVar4 = sVar7 + 0x12;
  }
  return;
}

// FUN_002becc0

u16 func_002becc0(void)
{
    u32 handle;
    u16* data;

    handle = func_00195340_u32(D_00696f50);
    if (handle == 0)
    {
        return 5;
    }

    data = (u16*)func_00195540_u32(handle);
    return *data;
}

// FUN_002bed10

void func_002bed10(void)
{
  u32 handle;
  u16 *state;

  if ((handle = func_00195340_u32(D_00696f50)) == 0) {
    return;
  }
  state = (u16 *)func_00195540_u32(handle);
  if ((*(u32 *)(DAT_007ce3ec + 0x14) & 0x2000000) != 0) {
    if (*state == 3) {
      *state = 6;
    }
  }
  else {
    switch (*(u16 *)(*(u32 *)(state + 2) + 0x6c)) {
    case 4:
      func_001fe430();
      break;
    default:
      func_001fdec0();
      break;
    }
    *state = 2;
  }
}

// FUN_002bedd0

void func_002bedd0(int param_1)
{
  u32 handle;
  u16 *state;

  if ((*(u32 *)(DAT_007ce3ec + 0x14) & 0x2000000) != 0) {
    if ((handle = func_00195340_u32(D_00696f50)) != 0) {
      state = (u16 *)func_00195540_u32(handle);
      if ((*(u32 *)(DAT_007ce3ec + 0x14) & 0x2000000) != 0) {
        if (*state == 3) {
          *state = 6;
        }
      }
      else {
        switch (*(u16 *)(*(u32 *)(state + 2) + 0x6c)) {
        case 4:
          func_001fe430();
          break;
        default:
          func_001fdec0();
          break;
        }
        *state = 2;
      }
    }
  }
  else {
    if ((handle = func_00195340_u32(D_00696f50)) != 0) {
      state = (u16 *)func_00195540_u32(handle);
      switch (*(u16 *)(*(u32 *)(state + 2) + 0x6c)) {
      case 4:
        func_001fe3b0(*(u32 *)(*(u32 *)(param_1 + 0x30) + 0xa8));
        break;
      default:
        break;
      }
      *state = 2;
    }
  }
}

// FUN_002bef20 NONMATCHING

u64 func_002bef20(u64 param_1)

{
  short sVar1 = 0;
  int iVar2 = 0;
  u16 uVar3 = 0;
  short *psVar4;
  long lVar5 = 0;
  u32 uStack_20 = 0;
  int iStack_1c = 0;
  u16 uStack_18 = 0;
  u16 uStack_16 = 0;
  u16 uStack_14 = 0;
  u32 uStack_10 = 0;
  
  lVar5 = btlFadeSuppressesFormationUpdates();
  if ((lVar5 == 0) && ((*(u32 *)(DAT_007ce3ec + 0x14) & 4) == 0)) {
    psVar4 = (short *)func_00195540(param_1);
    sVar1 = *psVar4;
    if ((sVar1 != 8) && (((sVar1 != 7 && (sVar1 != 5)) && (sVar1 != 3)))) {
      if ((*(u32 *)(DAT_007ce3ec + 0x14) & 0x2000000) == 0) {
        func_0016f1f0(0x140c,0);
        func_0016f1f0(0x1409,0);
        iVar2 = *(int *)(psVar4 + 2);
        lVar5 = func_001fddf0();
        if (lVar5 != 0) {
          func_001fdf10(&uStack_20);
          *(short *)(iVar2 + 0x6c) = (short)iStack_1c;
          if (iStack_1c == 0xd) {
            *psVar4 = 8;
          }
          else if ((iStack_1c == 7) || (iStack_1c == 6)) {
            *psVar4 = 5;
          }
          else if (iStack_1c == 10) {
            func_002db650(uStack_10);
            *psVar4 = 7;
          }
          else if (iStack_1c == 5) {
            *(u16 *)(iVar2 + 0x74) = uStack_14;
            *psVar4 = 5;
          }
          else if (iStack_1c == 4) {
            if (((uStack_20 & 1) == 0) && ((uStack_20 & 2) == 0)) {
              *psVar4 = 5;
            }
            else {
              *(u16 *)(iVar2 + 0x6e) = uStack_16;
              *psVar4 = 3;
            }
          }
          else if (iStack_1c == 3) {
            *(u16 *)(iVar2 + 0x70) = uStack_18;
            uVar3 = func_0030bc20(uStack_18);
            *(u16 *)(iVar2 + 0x6e) = uVar3;
            *psVar4 = 3;
          }
          else if (iStack_1c == 2) {
            *(u16 *)(iVar2 + 0x6e) = uStack_16;
            *psVar4 = 3;
          }
          else if (iStack_1c == 1) {
            uVar3 = func_00308930(*(u32 *)(*(int *)(iVar2 + 0x30) + 0xa2c));
            *(u16 *)(iVar2 + 0x6e) = uVar3;
            *psVar4 = 3;
          }
        }
      }
      else {
        func_0016f1f0(0x140c,1);
        func_0016f1f0(0x1409,1);
        if (*psVar4 == 6) {
          *psVar4 = 2;
          return 0;
        }
        iVar2 = *(int *)(psVar4 + 6);
        if ((iVar2 != 0) && (*(code **)(iVar2 + 0x14) != (code *)0x0)) {
          uVar3 = (**(code **)(iVar2 + 0x14))(iVar2,*(u32 *)(psVar4 + 2));
          switch(uVar3) {
          case 1:
            iVar2 = *(int *)(iVar2 + 0x20);
            if (iVar2 != 0) {
              *(int *)(psVar4 + 6) = iVar2;
              *(u32 *)(iVar2 + 0x24) = 0;
            }
            break;
          case 2:
            if (*(int *)(iVar2 + 0x24) != 0) {
              *(int *)(psVar4 + 6) = *(int *)(iVar2 + 0x24);
            }
            break;
          case 4:
            iVar2 = *(int *)(iVar2 + 0x20);
            if (iVar2 != 0) {
              *(int *)(psVar4 + 6) = iVar2;
              *(u32 *)(iVar2 + 0x24) = 0;
            }
          case 3:
            *psVar4 = 3;
            break;
          case 6:
            *psVar4 = 5;
          }
        }
      }
    }
  }
  return 0;
}

// FUN_002bf2b0

u32 func_002bf2b0(u32 param_1)

{
  u32 state;
  u32 entry;
  void (*callback)(u32,u32,u32,u32);

  if (btlFadeSuppressesFormationUpdates() != 0) {
    return 0;
  }
  if ((*(u32 *)(DAT_007ce3ec + 0x14) & 4) != 0) {
    return 0;
  }
  if ((*(u32 *)(DAT_007ce3ec + 0x14) & 0x2000000) != 0) {
    state = func_00195540_u32(param_1);
    entry = *(u32 *)(state + 8);
    do {
      callback = *(void (**)(u32,u32,u32,u32))(entry + 0x18);
      if (callback != 0) {
        callback(entry,0x10,300,*(u32 *)(state + 4));
      }
      entry = *(u32 *)(entry + 0x24);
    } while (entry != 0);
  }
  return 0;
}


void func_002bf370(u64 param_1)

{
  long lVar1 = 0;
  u64 uVar2 = 0;
  
  func_001fdda0();
  lVar1 = func_002d1a70();
  if (lVar1 == 1) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x4000;
    func_001ff370();
  }
  uVar2 = func_00195540(param_1);
  (*DAT_0096017c)(uVar2);
  *(u32 *)(DAT_007ce3ec + 0xd1c) = 0;
  return;
}

// FUN_002bf3f0 NONMATCHING

u32 func_002bf3f0(u64 param_1)

{
  u32 uVar1 = 0;
  long lVar2 = 0;
  u64 uVar3 = 0;
  u64 uVar4 = 0;
  u32 uVar5 = 0;
  u16 *puVar6;
  int iVar7 = 0;
  
  lVar2 = func_002d1a70();
  if (lVar2 == 1) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) & 0xffffbfff;
  }
  lVar2 = func_00195340(0x696f50);
  if (lVar2 == 0) {
    uVar3 = (*DAT_00960178)(0x14,0x40000);
    func_00521408(uVar3,0,0x14);
    uVar4 = func_00194b20(*(u32 *)(DAT_007ce3ec + 0xd18),0x696f50,10,0x2bef20,0x2bf370,uVar3);
    puVar6 = (u16 *)uVar3;
    *(int *)(puVar6 + 8) = (int)uVar4;
    func_00194b20(uVar4,0x696f70,0x106f,0x2bf2b0,0,uVar3);
    *(u32 *)(DAT_007ce3ec + 0xd1c) = *(u32 *)(puVar6 + 8);
    DAT_00696e30 = 0;
    DAT_00696e34 = 0;
    *(undefined **)(puVar6 + 4) = &DAT_00696e10;
    *(undefined **)(puVar6 + 6) = &DAT_00696e10;
    iVar7 = (int)param_1;
    *(int *)(puVar6 + 2) = iVar7;
    *puVar6 = 2;
    uVar5 = func_00300550(*(u32 *)(*(int *)(iVar7 + 0x30) + 0xa2c));
    if ((uVar5 & 0x80060) == 0) {
      func_001fed00();
    }
    else {
      func_001fece0();
    }
    lVar2 = func_002c1ce0(param_1,0);
    if (lVar2 == 0) {
      func_001fede0();
    }
    else {
      func_001fee00();
    }
    if ((uVar5 & 0x80274) == 0) {
      func_001fed40();
    }
    else {
      func_001fed20();
    }
    if ((uVar5 & 0x80060) == 0) {
      func_001fed80();
    }
    else {
      func_001fed60();
    }
    if ((*(u16 *)(iVar7 + 0x18) & 0x400) == 0) {
      func_001feda0();
    }
    else {
      func_001fedc0();
    }
    func_001fee80();
    func_001fee40();
    func_002fd820();
    func_001fdd60();
    uVar1 = *(u32 *)(puVar6 + 8);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

// FUN_002bf650

void func_002bf650(void)
{
  long handle;
  
  if ((handle = func_00195340(D_00696f50)) == 0) {
    return;
  }
  func_00195020(handle);
  return;
}

// FUN_002bf690 NONMATCHING

void func_002bf690(short param_1)

{
  int iVar1 = 0;
  u32 uVar2 = 0;
  long lVar3 = 0;
  long lVar4 = 0;
  
  iVar1 = func_00195540(*(u32 *)(DAT_007ce3ec + 0xd1c));
  iVar1 = *(int *)(iVar1 + 4);
  uVar2 = func_00300550(*(u32 *)(*(int *)(iVar1 + 0x30) + 0xa2c));
  lVar4 = 0;
  if ((param_1 == 0xc) || (param_1 == 6)) {
    lVar3 = func_002c1ce0(iVar1,0);
    if (lVar3 == 0) {
      lVar4 = 0xd7;
    }
  }
  else if (param_1 == 5) {
    lVar4 = 0xd6;
  }
  else if (param_1 == 3) {
    if ((uVar2 & 0x20) == 0) {
      if ((uVar2 & 0x40) == 0) {
        lVar3 = func_002d5550();
        if (lVar3 == 0x1ad) {
          lVar4 = 0xd1;
        }
      }
      else {
        lVar4 = 0xce;
      }
    }
    else {
      lVar4 = 0xcd;
    }
  }
  else if (param_1 == 2) {
    if ((uVar2 & 0x20) == 0) {
      if ((uVar2 & 0x40) == 0) {
        if ((uVar2 & 4) != 0) {
          lVar4 = 0xd0;
        }
      }
      else {
        lVar4 = 0xce;
      }
    }
    else {
      lVar4 = 0xcd;
    }
  }
  else if (param_1 == 1) {
    if ((uVar2 & 0x20) == 0) {
      if ((uVar2 & 0x40) != 0) {
        lVar4 = 0xce;
      }
    }
    else {
      lVar4 = 0xcd;
    }
  }
  if (lVar4 != 0) {
    func_001fea10(*(u32 *)(DAT_007ce3ec + 0xba0),lVar4);
  }
  return;
}

// FUN_002bf850

void func_002bf850(void)

{
  func_002bf690(1);
  return;
}

// FUN_002bf880

void func_002bf880(void)

{
  func_002bf690(6);
  return;
}

// FUN_002bf8b0

void func_002bf8b0(void)

{
  func_002bf690(2);
  return;
}

// FUN_002bf8e0

void func_002bf8e0(void)

{
  func_002bf690(3);
  return;
}

// FUN_002bf910

void func_002bf910(void)

{
  func_002bf690(5);
  return;
}

// FUN_002bf940

void func_002bf940(void)

{
  func_002bf690(7);
  return;
}

// FUN_002bf970

void func_002bf970(void)

{
  return;
}

// FUN_002bf980

void func_002bf980(void)

{
  return;
}

// FUN_002bf990

void func_002bf990(void)

{
  return;
}

// FUN_002bf9a0

void func_002bf9a0(void)

{
  return;
}

// FUN_002bf9b0 NONMATCHING

void func_002bf9b0(void)

{
  int iVar1 = 0;
  long lVar2 = 0;
  u32 uVar3 = 0;
  u32 uVar4 = 0;
  
  if ((((*(int *)(DAT_007ce3ec + 0x2b4) != 0x12) && (lVar2 = btlFadeSuppressesFormationUpdates(), lVar2 == 0)) &&
      ((*(u32 *)(DAT_007ce3ec + 0x14) & 4) == 0)) && ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x800) != 0)
     ) {
    for (uVar4 = 0; uVar4 < 4; uVar4 = uVar4 + 1) {
      for (iVar1 = *(int *)(DAT_007ce3ec + uVar4 * 8 + 0x150); iVar1 != 0;
          iVar1 = *(int *)(iVar1 + 0xa34)) {
        if (*(int *)(iVar1 + 0xa2c) != 0) {
          if (*(u8 *)(iVar1 + 0x37) != 0) {
            uVar3 = 0xff;
          }
          else {
            uVar3 = 0;
          }
          func_002bce10(0.0f, 0.0f, iVar1, uVar3 | 0xb4736400, (float *)(iVar1 + 0xa04));
        }
      }
    }
  }
  return;
}

// FUN_002bfab0

u32 func_002bfab0(void)

{
  func_001ff3b0();
  return 1;
}

// FUN_002bfae0

void func_002bfae0(void)

{
  int iVar1 = 0;
  
  iVar1 = func_0027ec10(0x50c,0);
  *(u32 *)(iVar1 + 0x6c) = (u32)func_002bfab0;
}

// FUN_002bfb20

u32 func_002bfb20(void)

{
  func_001ff390();
  return 1;
}

// FUN_002bfb50

void func_002bfb50(void)

{
  int iVar1 = 0;
  
  iVar1 = func_0027ec10(0x50d,0);
  *(u32 *)(iVar1 + 0x6c) = (u32)func_002bfb20;
}

// FUN_002bfb90

u32 func_002bfb90(int *param_1)

{
  long lVar1 = 0;
  
  if (*param_1 == 0) {
    func_001fe5f0();
    *param_1 = 1;
  }
  else {
    lVar1 = func_001fe630();
    if (lVar1 == 0) {
      return 1;
    }
  }
  return 0;
}

// FUN_002bfc00

void func_002bfc00(void)

{
  int iVar1 = 0;
  
  iVar1 = func_0027ec10(0x508,4);
  *(u8 *)(iVar1 + 0x47) = *(u8 *)(iVar1 + 0x47) & 0xfe;
  *(code *)(iVar1 + 0x6c) = (code)func_002bfb90;
  **(u32 **)(iVar1 + 0x78) = 0;
  return;
}

// FUN_002bfc50

void func_002bfc50(void)

{
  func_0045a430();
  return;
}

// FUN_002bfc70

void func_002bfc70(void)

{
  func_0045af70();
  return;
}

// FUN_002bfc90

void func_002bfc90(void)

{
  func_0045af40();
  return;
}

// FUN_002bfcb0 NONMATCHING

void func_002bfcb0(int param_1,u64 param_2,u32 param_3,u32 param_4,long param_5)

{
  char cVar1 = 0;
  int iVar2 = 0;
  long lVar3 = 0;
  u32 uVar4 = 0;
  u32 unaff_s0_lo = 0;
  u32 unaff_s1_lo = 0;
  int *piVar5;
  int iVar6 = 0;
  
  func_00521408(param_2,0,0x30);
  piVar5 = (int *)param_2;
  *(u16 *)(piVar5 + 0xe) = 0;
  *(u16 *)((int)piVar5 + 0x3a) = 0;
  *(u8 *)(piVar5 + 0xf) = 0;
  *(u8 *)(piVar5 + 0xf) = *(u8 *)(piVar5 + 0xf) | 1;
  if (param_1 == 0) {
    unaff_s1_lo = 1;
    unaff_s0_lo = 2;
  }
  else {
    cVar1 = *(char *)(*(int *)(param_1 + 0x30) + 0xa2);
    if (cVar1 == '\x01') {
      unaff_s1_lo = 2;
      unaff_s0_lo = 1;
    }
    else if (cVar1 == '\0') {
      unaff_s0_lo = 2;
      unaff_s1_lo = 1;
    }
  }
  uVar4 = 0;
  if ((param_3 & 1) != 0) {
    uVar4 = unaff_s1_lo & 0xffff;
  }
  if ((param_3 & 2) != 0) {
    uVar4 = uVar4 | unaff_s0_lo & 0xffff;
  }
  if ((param_3 & 4) != 0) {
    uVar4 = uVar4 | 4;
  }
  if ((param_4 & 1) == 0) {
    for (iVar6 = *(int *)(DAT_007ce3ec + 0x14c); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x4a8)) {
      if (((param_1 == 0) || ((*(u16 *)(iVar6 + 0x1a) & 8) != 0)) &&
         ((*(u16 *)(iVar6 + 0x1a) & 1) != 0)) {
        iVar2 = *(int *)(iVar6 + 0x30);
        if (((*(u8 *)(iVar2 + 0xa2) == 2) || ((*(u32 *)(iVar2 + 0x9c) & 8) != 0)) &&
           ((uVar4 & 1 << (*(u8 *)(iVar2 + 0xa2) & 0x1f)) != 0)) {
          if ((uVar4 & 4) != 0) goto LAB_002bfefc;
          if ((((param_4 & 2) == 0) || (param_1 != iVar6)) &&
             (((param_4 & 4) != 0 ||
              (lVar3 = func_0030b5a0(*(u32 *)(iVar2 + 0xa2c),0), lVar3 == 0)))) {
            if ((param_4 & 8) == 0) {
              if ((param_5 == 0) ||
                 (((*(u32 *)(*(int *)(iVar2 + 0xa2c) + 0xc) & 0xffefffff) != 0 &&
                  (lVar3 = func_00300580(*(int *)(iVar2 + 0xa2c),param_5), lVar3 == 0))))
              goto LAB_002bfefc;
            }
            else {
              lVar3 = func_00300580(*(u32 *)(iVar2 + 0xa2c),0x100000);
              if (lVar3 != 0) {
LAB_002bfefc:
                piVar5[*(u16 *)(piVar5 + 0xe)] = iVar6;
                *(short *)(piVar5 + 0xe) = (short)piVar5[0xe] + 1;
              }
            }
          }
        }
      }
    }
  }
  else {
    *piVar5 = param_1;
    *(u16 *)(piVar5 + 0xe) = 1;
  }
  return;
}

// FUN_002bff60 NONMATCHING

u8 func_002bff60(u64 param_1,long param_2,u32 param_3,long param_4)

{
  int iVar1 = 0;
  u8 bVar2 = 0;
  int iVar3 = 0;
  u8 bVar4 = 0;
  
  if (param_2 != 0) {
    iVar3 = (param_3 & 0xffff) * 0x2c;
    iVar1 = (int)(iVar3 + DAT_007ce3f8);
    bVar2 = *(u8 *)(iVar1 + 9);
    bVar4 = *(u8 *)(iVar1 + 10);
    if (param_4 != 0) {
      if (((bVar2 & 1) == 0) || ((bVar2 & 2) != 0)) {
        if (((bVar2 & 2) != 0) && ((bVar2 & 1) == 0)) {
          bVar2 = bVar2 & 0xfd | 1;
        }
      }
      else {
        bVar2 = bVar2 & 0xfe | 2;
      }
      if ((bVar4 & 1) != 0) {
        bVar4 = bVar4 & 0xfe | 2;
      }
    }
    func_002bfcb0(param_1,param_2,bVar2,bVar4,*(u16 *)(iVar3 + DAT_007ce3f8 + 0xc));
  }
  return *(u8 *)((param_3 & 0xffff) * 0x2c + DAT_007ce3f8 + 8);
}

// FUN_002c0070 NONMATCHING

void func_002c0070(int param_1,u64 param_2)

{
  u16 uVar1 = 0;
  int iVar2 = 0;
  bool bVar3 = 0;
  u16 uVar4 = 0;
  float fVar5 = 0;
  int iVar6 = 0;
  int iVar7 = 0;
  u32 uVar8 = 0;
  u16 uVar9 = 0;
  bool bVar10 = 0;
  u16 unaff_s3_lo = 0;
  u32 uVar11 = 0;
  float fVar12 = 0;
  u16 auStack_e8 [4] = {0};
  float fStack_e0 = 0;
  u16 auStack_dc [2] = {0};
  float afStack_d8 [2] = {0};
  float afStack_d0 [32] = {0};
  float fStack_50 = 0;
  float fStack_4c = 0;
  float fStack_48 = 0;
  float fStack_44 = 0;
  float afStack_40 [2] = {0};
  float fStack_38 = 0;
  float afStack_30 [2] = {0};
  float fStack_28 = 0;
  float fStack_20 = 0;
  float fStack_1c = 0;
  float fStack_18 = 0;
  float fStack_14 = 0;
  float fStack_10 = 0;
  float fStack_c = 0;
  float fStack_8 = 0;
  float fStack_4 = 0;
  
  iVar7 = (int)param_2;
  uVar1 = *(u16 *)(iVar7 + 0x38);
  if (1 < uVar1) {
    if (((DAT_007e0952 & 0x2000) == 0) && ((DAT_007e095a & 0x2000) == 0)) {
      if (((DAT_007e0952 & 0x8000) == 0) && ((DAT_007e095a & 0x8000) == 0)) {
        if (((DAT_007e0952 & 0x1000) == 0) && ((DAT_007e095a & 0x1000) == 0)) {
          if (((DAT_007e0952 & 0x4000) == 0) && ((DAT_007e095a & 0x4000) == 0)) {
            return;
          }
          iVar6 = 3;
          bVar3 = (DAT_007e094e & 0x4000) != 0 || (DAT_007e0958 & 0x4000) != 0;
        }
        else {
          iVar6 = 2;
          bVar3 = (DAT_007e094e & 0x1000) != 0 || (DAT_007e0958 & 0x1000) != 0;
        }
      }
      else {
        iVar6 = 0;
        bVar3 = (DAT_007e094e & 0x8000) != 0 || (DAT_007e0958 & 0x8000) != 0;
      }
    }
    else {
      iVar6 = 1;
      bVar3 = (DAT_007e094e & 0x2000) != 0 || (DAT_007e0958 & 0x2000) != 0;
    }
    if ((iVar6 == 3) || (iVar6 == 2)) {
      uVar8 = 0;
      for (uVar11 = 0; uVar11 < uVar1; uVar11 = uVar11 + 1 & 0xffff) {
        fVar5 = *(float *)(iVar7 + uVar11 * 4);
        if (((*(u16 *)((int)fVar5 + 0x1a) & 1) != 0) &&
           (*(char *)(*(int *)((int)fVar5 + 0x30) + 0xa2) == '\0')) {
          uVar9 = 0;
          for (iVar2 = *(int *)(DAT_007ce3ec + 0x154);
              (iVar2 != 0 && (iVar2 != *(int *)((int)fVar5 + 0x30)));
              iVar2 = *(int *)(iVar2 + 0xa30)) {
            uVar9 = uVar9 + 1;
          }
          (&fStack_e0)[uVar8 * 3] = fVar5;
          auStack_dc[uVar8 * 6] = (u16)uVar11;
          auStack_dc[uVar8 * 6 + 1] = uVar9;
          uVar8 = uVar8 + 1 & 0xffff;
        }
      }
      if (uVar8 == 0) {
        return;
      }
      if (1 < uVar8) {
        do {
          bVar10 = false;
          for (uVar11 = 0; (int)uVar11 < (int)(uVar8 - 1); uVar11 = uVar11 + 1 & 0xffff) {
            uVar1 = auStack_dc[uVar11 * 6 + 1];
            if (uVar1 < *(u16 *)((int)afStack_d0 + (uVar11 * 6 + 1) * 2)) {
              fVar5 = (&fStack_e0)[uVar11 * 3];
              unaff_s3_lo = auStack_dc[uVar11 * 6];
              (&fStack_e0)[uVar11 * 3] = afStack_d8[uVar11 * 3 + 1];
              auStack_dc[uVar11 * 6] = *(u16 *)(afStack_d0 + uVar11 * 3);
              auStack_dc[uVar11 * 6 + 1] = *(u16 *)((int)afStack_d0 + (uVar11 * 6 + 1) * 2);
              afStack_d8[uVar11 * 3 + 1] = fVar5;
              *(u16 *)(afStack_d0 + uVar11 * 3) = unaff_s3_lo;
              *(u16 *)((int)afStack_d0 + (uVar11 * 6 + 1) * 2) = uVar1;
              bVar10 = true;
            }
          }
        } while (bVar10);
      }
      fVar5 = (float)func_002c0880(param_2);
      for (uVar11 = 0; (uVar11 < uVar8 && ((&fStack_e0)[uVar11 * 3] != fVar5));
          uVar11 = uVar11 + 1 & 0xffff) {
      }
      if (uVar11 != uVar8) {
        if (iVar6 == 2) {
          if (uVar11 + 1 == uVar8) {
            unaff_s3_lo = auStack_dc[0];
            if (!bVar3) {
              unaff_s3_lo = *(u16 *)(iVar7 + 0x3a);
            }
          }
          else {
            unaff_s3_lo = auStack_dc[(uVar11 + 1 & 0xffff) * 6];
          }
        }
        else if (uVar11 == 0) {
          if (bVar3) {
            unaff_s3_lo = auStack_e8[uVar8 * 6];
          }
          else {
            unaff_s3_lo = *(u16 *)(iVar7 + 0x3a);
          }
        }
        else {
          unaff_s3_lo = auStack_dc[(uVar11 - 1 & 0xffff) * 6];
        }
      }
    }
    else if ((iVar6 == 0) || (iVar6 == 1)) {
      func_0027ffb0(*(u32 *)(param_1 + 0x30),afStack_30);
      uVar4 = func_002c09f0(param_2);
      func_00280870(uVar4,0,afStack_40,0,0,1);
      fStack_50 = afStack_30[0];
      fStack_4c = fStack_28;
      fStack_48 = afStack_40[0];
      fStack_44 = fStack_38;
      fStack_18 = afStack_30[0] - afStack_40[0];
      fStack_20 = fStack_28 - fStack_38;
      fStack_1c = -fStack_18;
      fStack_14 = fStack_20;
      func_004c6b20(&fStack_20,&fStack_20);
      uVar11 = 0;
      for (uVar8 = 0; uVar8 < *(u16 *)(iVar7 + 0x38); uVar8 = uVar8 + 1 & 0xffff) {
        fVar5 = *(float *)(iVar7 + uVar8 * 4);
        func_0027ffb0(*(u32 *)((int)fVar5 + 0x30),afStack_30);
        fStack_8 = afStack_30[0];
        fStack_4 = fStack_28;
        fVar12 = (float)func_002d1fd0(&fStack_50,&fStack_48,&fStack_8,&fStack_10);
        fStack_18 = fStack_8 - fStack_10;
        fStack_14 = fStack_4 - fStack_c;
        func_004c6b20(&fStack_18,&fStack_18);
        if (fStack_18 * fStack_20 + fStack_14 * fStack_1c <= 0.0) {
          afStack_d8[uVar11 * 3] = fVar12;
        }
        else {
          afStack_d8[uVar11 * 3] = -fVar12;
        }
        (&fStack_e0)[uVar11 * 3] = fVar5;
        auStack_dc[uVar11 * 6] = (u16)uVar8;
        uVar11 = uVar11 + 1 & 0xffff;
      }
      do {
        bVar10 = false;
        for (uVar8 = 0; (int)uVar8 < (int)(uVar11 - 1); uVar8 = uVar8 + 1 & 0xffff) {
          fVar5 = afStack_d8[uVar8 * 3];
          if (fVar5 < afStack_d0[uVar8 * 3 + 1]) {
            fVar12 = (&fStack_e0)[uVar8 * 3];
            uVar1 = auStack_dc[uVar8 * 6];
            (&fStack_e0)[uVar8 * 3] = afStack_d8[uVar8 * 3 + 1];
            auStack_dc[uVar8 * 6] = *(u16 *)(afStack_d0 + uVar8 * 3);
            afStack_d8[uVar8 * 3] = afStack_d0[uVar8 * 3 + 1];
            afStack_d8[uVar8 * 3 + 1] = fVar12;
            *(u16 *)(afStack_d0 + uVar8 * 3) = uVar1;
            afStack_d0[uVar8 * 3 + 1] = fVar5;
            bVar10 = true;
          }
        }
      } while (bVar10);
      fVar5 = (float)func_002c0880(param_2);
      for (uVar8 = 0; (uVar8 < uVar11 && ((&fStack_e0)[uVar8 * 3] != fVar5));
          uVar8 = uVar8 + 1 & 0xffff) {
      }
      if (iVar6 == 1) {
        if (uVar8 + 1 == uVar11) {
          unaff_s3_lo = auStack_dc[0];
          if (!bVar3) {
            unaff_s3_lo = *(u16 *)(iVar7 + 0x3a);
          }
        }
        else {
          unaff_s3_lo = auStack_dc[(uVar8 + 1 & 0xffff) * 6];
        }
      }
      else if (uVar8 == 0) {
        if (bVar3) {
          unaff_s3_lo = auStack_e8[uVar11 * 6];
        }
        else {
          unaff_s3_lo = *(u16 *)(iVar7 + 0x3a);
        }
      }
      else {
        unaff_s3_lo = auStack_dc[(uVar8 - 1 & 0xffff) * 6];
      }
    }
    if (*(u16 *)(iVar7 + 0x3a) != unaff_s3_lo) {
      *(u16 *)(iVar7 + 0x3a) = unaff_s3_lo;
      *(u8 *)(iVar7 + 0x3c) = *(u8 *)(iVar7 + 0x3c) | 1;
    }
  }
  return;
}

// FUN_002c0880

u32 func_002c0880(int param_1)

{
  return *(u32 *)(param_1 + (u32)*(u16 *)(param_1 + 0x3a) * 4);
}

// FUN_002c08a0

void func_002c08a0(int param_1,u64 *param_2)

{
  *(u64 *)(param_1 + 0x30) = *param_2;
  return;
}

// FUN_002c08b0

void func_002c08b0(int param_1,int param_2)

{
  *(u64 *)(param_1 + 0x30) = *(u64 *)(param_2 + 0x30);
  return;
}

// FUN_002c08c0 MATCHING

long *func_002c08c0(int param_1)
{
  long *entry;
  int unit;
  
  for (entry = *(long **)(iGpffffb6fc + 0x14c); entry != 0;
       entry = *(long **)(entry + 0x95)) {
    if ((*(u16 *)((int)entry + 0x1a) & 1) == 0) {
      continue;
    }
    if ((*(u16 *)((int)entry + 0x1a) & 8) == 0) {
      continue;
    }
    unit = *(int *)((int)entry[6] + 0xa2c);
    if (unit != 0 && func_0030b5a0_u32(unit, 0) != 0) {
      continue;
    }
    if (*entry != *(long *)(param_1 + 0x30)) {
      continue;
    }
    return entry;
  }
  return 0;
}

// FUN_002c0970 NONMATCHING
#pragma opt_loop_invariants on

u32 func_002c0970(int param_1)

{
  s32 count;
  s32 index;
  u64 target;

  *(u16 *)(param_1 + 0x3a) = 0;
  target = *(u64 *)(param_1 + 0x30);
  if (target == 0) {
    return 0;
  }
  index = 0;
  count = *(u16 *)(param_1 + 0x38);
  for (; (index & 0xffff) < count; index = (u16)(index + 1)) {
    if (target == **(u64 **)(param_1 + (u16)index * 4)) {
      *(u16 *)(param_1 + 0x3a) = index;
      return 1;
    }
  }
  return 0;
}

// FUN_002c09f0 NONMATCHING

u32 func_002c09f0(int param_1)
{
  u32 result;
  u16 index;
  s32 count;
  u32 bit;

  result = 0;
  index = 0;
  count = *(u16 *)(param_1 + 0x38);
  bit = 1;
  for (; index < count; index = (u16)(index + 1)) {
    u8 genus = *(u8 *)(*(int *)(*(int *)(param_1 + index * 4) + 0x30) + 0xa2);
    result = (result | ((bit << genus) & 0xffff)) & 0xffff;
  }
  return result;
}
#pragma opt_loop_invariants off

// FUN_002c0a50

void func_002c0a50(u32 param_1,u16 param_2)
{
  extern void *func_0029a1d0(u32);
  extern void *func_00289030(u32);
  char *destination;
  char *source;

  destination = (char *)func_0029a1d0(param_1);
  param_1 = (u32)func_00289030(param_2);
  if (param_1 == 0) {
    return;
  }
  source = (char *)func_0029a1d0(param_1);
  if (source == 0) {
    return;
  }
  *(u64 *)(destination + 0xb8) = *(u64 *)source;
}

// FUN_002c0ac0 NONMATCHING

void func_002c0ac0(int param_1,int param_2)

{
  char cVar1 = 0;
  int iVar2 = 0;
  u16 uVar3 = 0;
  long lVar4 = 0;
  short sVar5 = 0;
  int iVar6 = 0;
  u32 uVar7 = 0;
  u16 uVar8 = 0;
  
  if ((1 < *(u16 *)(param_2 + 0x38)) &&
     (((sVar5 = *(short *)(param_1 + 0x6c), sVar5 == 2 || (sVar5 == 3)) || (sVar5 == 1)))) {
    iVar6 = ((u32)*(u16 *)(param_1 + 0x6e) * 10 + (u32)*(u16 *)(param_1 + 0x6e)) * 4;
    if (*(char *)(iVar6 + iGpffffb708 + 8) == '\0') {
      if ((*(char *)(iVar6 + iGpffffb708 + 0x18) == '\x02') &&
         (iVar2 = *(int *)(iGpffffb708 + 0x1c + iVar6), iVar2 != 0)) {
        for (uVar7 = 0; uVar7 < *(u16 *)(param_2 + 0x38); uVar7 = uVar7 + 1 & 0xffff) {
          lVar4 = func_00300580(*(u32 *)
                                (*(int *)(*(int *)(param_2 + uVar7 * 4) + 0x30) + 0xa2c),iVar2);
          if (lVar4 != 0) {
            *(short *)(param_2 + 0x3a) = (short)uVar7;
            return;
          }
        }
      }
      iVar2 = *(int *)(iGpffffb708 + 0x20 + iVar6);
      if (iVar2 != 0) {
        for (uVar7 = 0; uVar7 < *(u16 *)(param_2 + 0x38); uVar7 = uVar7 + 1 & 0xffff) {
          lVar4 = func_00301ca0(*(u32 *)
                                (*(int *)(*(int *)(param_2 + uVar7 * 4) + 0x30) + 0xa2c),iVar2);
          if (lVar4 == 0) {
            *(short *)(param_2 + 0x3a) = (short)uVar7;
            return;
          }
        }
      }
      cVar1 = *(char *)(iVar6 + iGpffffb708 + 0x11);
      if (((cVar1 == '\x0f') || (cVar1 == '\v')) ||
         ((cVar1 == '\t' || ((cVar1 == '\x05' || (cVar1 == '\x02')))))) {
        uVar8 = 0xffff;
        sVar5 = -1;
        for (uVar7 = 0; uVar7 < *(u16 *)(param_2 + 0x38); uVar7 = uVar7 + 1 & 0xffff) {
          uVar3 = func_002ffd70(*(u32 *)
                                (*(int *)(*(int *)(param_2 + uVar7 * 4) + 0x30) + 0xa2c));
          if (uVar3 < uVar8) {
            sVar5 = (short)uVar7;
            uVar8 = uVar3;
          }
        }
        if (sVar5 != -1) {
          *(short *)(param_2 + 0x3a) = sVar5;
          return;
        }
      }
      cVar1 = *(char *)(iVar6 + iGpffffb708 + 0x14);
      if ((((cVar1 == '\x0f') || (cVar1 == '\v')) || (cVar1 == '\t')) ||
         ((cVar1 == '\x05' || (cVar1 == '\x02')))) {
        uVar8 = 0xffff;
        sVar5 = -1;
        for (uVar7 = 0; uVar7 < *(u16 *)(param_2 + 0x38); uVar7 = uVar7 + 1 & 0xffff) {
          uVar3 = func_002ffd80(*(u32 *)
                                (*(int *)(*(int *)(param_2 + uVar7 * 4) + 0x30) + 0xa2c));
          if (uVar3 < uVar8) {
            sVar5 = (short)uVar7;
            uVar8 = uVar3;
          }
        }
        if (sVar5 != -1) {
          *(short *)(param_2 + 0x3a) = sVar5;
        }
      }
    }
  }
  return;
}

// FUN_002c0e30 NONMATCHING

int func_002c0e30(short param_1,u32 param_2,u32 param_3)

{
  int iVar1 = 0;
  int iVar2 = 0;
  long lVar3 = 0;
  
  iVar1 = *(int *)(iGpffffb6fc + 0x14c);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (((((*(u16 *)(iVar1 + 0x1a) & 1) != 0) && ((*(u16 *)(iVar1 + 0x1a) & 8) != 0)) &&
        (iVar2 = *(int *)(iVar1 + 0x30),
        (param_2 & 0xffff & 1 << (*(u8 *)(iVar2 + 0xa2) & 0x1f)) != 0)) &&
       ((((param_3 & 0x80000) == 0 ||
         (lVar3 = func_0030b5a0(*(u32 *)(iVar2 + 0xa2c),0), lVar3 == 0)) &&
        ((lVar3 = func_00300580(*(u32 *)(iVar2 + 0xa2c),param_3), lVar3 == 0 &&
         (*(short *)(iVar2 + 0xa4) == param_1)))))) break;
    iVar1 = *(int *)(iVar1 + 0x4a8);
  }
  return iVar1;
}

// FUN_002c0f40

u16 func_002c0f40(int param_1,u32 param_2,u32 param_3,u32 param_4,
                 u32 param_5,FormationPredicate param_6,int *param_7)
{
  struct {
    int entries[14];
    u16 count;
    u16 selected;
  } candidates;
  int unit;
  u16 index;
  u16 result;

  func_002bfcb0_ptr(param_1,&candidates,param_4,0,0);
  result = 0;
  index = 0;
  while (index < candidates.count) {
    unit = candidates.entries[index];
    if (((*(u16 *)(unit + 0x1a) & 1) != 0) &&
        ((*(u16 *)(unit + 0x1a) & 8) != 0) &&
        (func_00300580(*(u32 *)(*(int *)(unit + 0x30) + 0xa2c),param_3) == 0) &&
        ((*param_6)(unit,param_2) != param_5)) {
      if (param_7 != 0) {
        param_7[result] = unit;
      }
      result++;
    }
    index++;
  }
  return result;
}

// FUN_002c1080 NONMATCHING

u32
func_002c1080(int param_1,u32 param_2,u32 param_3,u32 param_4,u16 param_5,
            code *param_6)

{
  int iVar1 = 0;
  int iVar2 = 0;
  char cVar3 = 0;
  long lVar4 = 0;
  u32 uVar5 = 0;
  
  iVar1 = *(int *)(iGpffffb6fc + 0x14c);
  do {
    if (iVar1 == 0) {
      return 0;
    }
    if ((((*(u16 *)(iVar1 + 0x1a) & 1) != 0) && ((*(u16 *)(iVar1 + 0x1a) & 8) != 0)) &&
       (iVar2 = *(int *)(iVar1 + 0x30),
       (param_3 & 0xffff & 1 << (*(u8 *)(iVar2 + 0xa2) & 0x1f)) != 0)) {
      if (param_5 == 0) {
LAB_002c123c:
        if (((((param_4 & 0x80000) == 0) ||
             (lVar4 = func_0030b5a0(*(u32 *)(iVar2 + 0xa2c),0), lVar4 == 0)) &&
            (lVar4 = func_00300580(*(u32 *)(iVar2 + 0xa2c),param_4), lVar4 == 0)) &&
           (lVar4 = (*param_6)(iVar1,param_2), lVar4 != 0)) {
          return 1;
        }
      }
      else if (((param_5 & 1) == 0) ||
              (lVar4 = func_00300580(*(u32 *)(iVar2 + 0xa2c),0x100000), lVar4 != 0)) {
        if (((param_5 & 2) != 0) && (uVar5 = func_003080c0((short)param_2), (uVar5 & 0xe0001) == 0))
        {
          if ((uVar5 & 0xe) == 0) {
            if ((uVar5 & 0x100) != 0) goto LAB_002c11dc;
            cVar3 = func_00301750(*(u32 *)(iVar2 + 0xa2c),0x12);
          }
          else {
            cVar3 = func_00301750(*(u32 *)(iVar2 + 0xa2c),0x11);
          }
          if ('\0' < cVar3) goto LAB_002c12a0;
        }
LAB_002c11dc:
        if ((((param_5 & 0xc) == 0) || (*(char *)(iVar2 + 0xa2) != '\x01')) ||
           ((lVar4 = func_002e3350(iVar1,(short)param_2), lVar4 != 0 ||
            (lVar4 = func_0017b260(*(u16 *)(iVar2 + 0xa4)), lVar4 != 0)))) goto LAB_002c123c;
        if ((param_5 & 4) == 0) {
          return 1;
        }
      }
    }
LAB_002c12a0:
    iVar1 = *(int *)(iVar1 + 0x4a8);
  } while( true );
}

// FUN_002c12f0

bool func_002c12f0(int param_1,int param_2)

{
  u32 uVar2 = 0;
  u32 uVar1 = 0;
  
  uVar1 = *(u16 *)(*(int *)(*(int *)(param_1 + 0x30) + 0xa2c) + 8);
  uVar2 = func_002ffdf0(*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c));
  return (u32)uVar1 * 100 <= (uVar2 & 0xffff) * param_2;
}

// FUN_002c1360

u32 func_002c1360(int param_1,int param_2)

{
  u32 uVar2 = 0;
  u32 uVar1 = 0;
  
  uVar1 = *(u16 *)(*(int *)(*(int *)(param_1 + 0x30) + 0xa2c) + 8);
  uVar2 = func_002ffdf0(*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c));
  return !((u32)uVar1 * 100 < (uVar2 & 0xffff) * param_2);
}

// FUN_002c13d0

bool func_002c13d0(int param_1,int param_2)

{
  u32 uVar2 = 0;
  u32 uVar1 = 0;
  
  uVar1 = *(u16 *)(*(int *)(*(int *)(param_1 + 0x30) + 0xa2c) + 10);
  uVar2 = func_00300100(*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c));
  return (u32)uVar1 * 100 <= (uVar2 & 0xffff) * param_2;
}

// FUN_002c1440

void func_002c1440(int param_1,u32 param_2)

{
  func_002c1080(param_1,param_2,1 << *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) & 0xffff,
               0x80000,0,(code *)&func_002c12f0);
  return;
}

// FUN_002c1490 NONMATCHING
void func_002c1490(int param_1, u32 param_2)
{
    u32 shift;
    switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2))
    {
    default:
        shift = 1;
        break;
    case 0:
        shift = 0;
        break;
    }
    func_002c1080(param_1, param_2, 1 << (shift & 0xffff) & 0xffff, 0x80000, 0, (code*)&func_002c12f0);
    return;
}

// FUN_002c14f0 NONMATCHING

void func_002c14f0(int param_1, u32 param_2)
{
    u32 shift;
    switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2))
    {
    default:
        shift = 1;
        break;
    case 0:
        shift = 0;
        break;
    }
    func_002c1080(param_1, param_2, 1 << (shift & 0xffff) & 0xffff, 0x80000, 0, (code*)&func_002c1360);
    return;
}

// FUN_002c1550

bool func_002c1550(int param_1,u32 param_2)
{
  extern u8 func_002ffcc0(u32);
  u8 level;

  level = func_002ffcc0(*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c));
  return param_2 <= level;
}

// FUN_002c1590

bool func_002c1590(int param_1,u32 param_2)

{
  u32 uVar1 = 0;
  
  uVar1 = func_002d4cf0(1 << *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) & 0xffff,0x80000);
  return param_2 <= (uVar1 & 0xffff);
}

// FUN_002c15e0 NONMATCHING

bool func_002c15e0(int param_1,u32 param_2)

{
  u32 uVar1 = 0;
  u16 genus;
  switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2)) {
  default:
    genus = 0;
    break;
  case 0:
    genus = 1;
    break;
  }
  uVar1 = func_002d4cf0(1 << genus & 0xffff,0x80000);
  return param_2 <= (uVar1 & 0xffff);
}


// FUN_002c1650

bool func_002c1650(int param_1,u32 param_2)

{
  u32 uVar1 = 0;
  
  uVar1 = func_002d4e10(1 << *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) & 0xffff,0x80000);
  return (uVar1 & 0xffff) <= param_2;
}

// FUN_002c16a0 NONMATCHING

bool func_002c16a0(int param_1,u32 param_2)

{
  u32 uVar1 = 0;
  u16 genus;
  switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2)) {
  default:
    genus = 0;
    break;
  case 0:
    genus = 1;
    break;
  }
  uVar1 = func_002d4e10(1 << genus & 0xffff,0x80000);
  return (uVar1 & 0xffff) <= param_2;
}


// FUN_002c1710

void func_002c1710(int param_1)

{
  func_00300580(*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c));
  return;
}

// FUN_002c1740

void func_002c1740(int param_1,u32 param_2)

{
  u32 uVar1 = 0;
  
  uVar1 = 1 << *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) & 0xffff;
  if ((param_2 & 0x80000) != 0) {
    func_002c1080(param_1,param_2,uVar1,0,0,(code *)&func_002c1710);
  }
  else {
    func_002c1080(param_1,param_2,uVar1,0x80000,0,(code *)&func_002c1710);
  }
  return;
}

// FUN_002c17b0 NONMATCHING

void func_002c17b0(int param_1,u32 param_2)

{
  u32 genus;
  u16 shift;

  switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2)) {
  default:
    genus = 0;
    break;
  case 0:
    genus = 1;
    break;
  }
  shift = genus;
  if ((param_2 & 0x80000) != 0) {
    func_002c1080(param_1,param_2,1 << shift & 0xffff,0,0,(code *)&func_002c1710);
  }
  else {
    func_002c1080(param_1,param_2,1 << shift & 0xffff,0x80000,0,(code *)&func_002c1710);
  }
  return;
}

// FUN_002c1850 NONMATCHING

bool func_002c1850(int param_1,u64 param_2)
{
  u32 genus;
  u16 shift;
  u32 sideMask;
  int entry;
  int unit;

  switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2)) {
  default:
    genus = 0;
    break;
  case 0:
    genus = 1;
    break;
  }
  shift = genus;
  sideMask = 1 << shift & 0xffff;
  for (entry = *(int *)(iGpffffb6fc + 0x14c); entry != 0; entry = *(int *)(entry + 0x4a8)) {
    if ((*(u16 *)(entry + 0x1a) & 1) == 0) continue;
    if ((*(u16 *)(entry + 0x1a) & 8) == 0) continue;
    unit = *(int *)(entry + 0x30);
    if ((sideMask & 1 << *(u8 *)(unit + 0xa2)) == 0) continue;
    if (func_0030b5a0(*(u32 *)(unit + 0xa2c),0) != 0) continue;
    if (func_00300580(*(u32 *)(unit + 0xa2c),param_2) == 0) break;
  }
  if (entry == 0) return true;
  return false;
}

// FUN_002c1960

u32 func_002c1960(int param_1,u32 param_2)

{
  int entry;
  int unit;

  for (entry = *(int *)(iGpffffb6fc + 0x14c); entry != 0; entry = *(int *)(entry + 0x4a8)) {
    if (param_1 == entry) {
      continue;
    }
    if ((*(u16 *)(entry + 0x1a) & 1) == 0) {
      continue;
    }
    if ((*(u16 *)(entry + 0x1a) & 8) == 0) {
      continue;
    }
    unit = *(int *)(entry + 0x30);
    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != *(u8 *)(unit + 0xa2)) {
      continue;
    }
    if (func_00300580(*(u32 *)(unit + 0xa2c),0x80000) != 0) {
      continue;
    }
    if (*(u16 *)(unit + 0xa4) != param_2) {
      continue;
    }
    return 1;
  }
  return 0;
}

// FUN_002c1a30 NONMATCHING

u32 func_002c1a30(int param_1,u32 param_2)

{
  u32 selectedSide;
  u32 side;
  int entry;
  int unit;

  switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2)) {
  default:
    selectedSide = 0;
    break;
  case 0:
    selectedSide = 1;
    break;
  }
  side = selectedSide & 0xffff;
  for (entry = *(int *)(iGpffffb6fc + 0x14c); entry != 0; entry = *(int *)(entry + 0x4a8)) {
    if ((*(u16 *)(entry + 0x1a) & 1) == 0) {
      continue;
    }
    if ((*(u16 *)(entry + 0x1a) & 8) == 0) {
      continue;
    }
    unit = *(int *)(entry + 0x30);
    if (*(u8 *)(unit + 0xa2) != side) {
      continue;
    }
    if (func_00300580(*(u32 *)(unit + 0xa2c),0x80000) != 0) {
      continue;
    }
    if (*(u16 *)(unit + 0xa4) != param_2) {
      continue;
    }
    return 1;
  }
  return 0;
}

// FUN_002c1b10

u32 func_002c1b10(int param_1,u32 param_2)

{
  int entry;
  int unit;

  for (entry = *(int *)(iGpffffb6fc + 0x14c); entry != 0; entry = *(int *)(entry + 0x4a8)) {
    if (param_1 == entry) {
      continue;
    }
    if ((*(u16 *)(entry + 0x1a) & 1) == 0) {
      continue;
    }
    if ((*(u16 *)(entry + 0x1a) & 8) == 0) {
      continue;
    }
    unit = *(int *)(entry + 0x30);
    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != *(u8 *)(unit + 0xa2)) {
      continue;
    }
    if (func_00300580(*(u32 *)(unit + 0xa2c),0x80000) != 0) {
      continue;
    }
    if (func_00301ca0(*(u32 *)(unit + 0xa2c),param_2) == 0) {
      continue;
    }
    return 1;
  }
  return 0;
}

// FUN_002c1bf0 NONMATCHING

u32 func_002c1bf0(int param_1,u32 param_2)

{
  u32 selectedSide;
  u32 side;
  int entry;
  int unit;

  switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2)) {
  default:
    selectedSide = 0;
    break;
  case 0:
    selectedSide = 1;
    break;
  }
  side = selectedSide & 0xffff;
  for (entry = *(int *)(iGpffffb6fc + 0x14c); entry != 0; entry = *(int *)(entry + 0x4a8)) {
    if ((*(u16 *)(entry + 0x1a) & 1) == 0) {
      continue;
    }
    if ((*(u16 *)(entry + 0x1a) & 8) == 0) {
      continue;
    }
    unit = *(int *)(entry + 0x30);
    if (*(u8 *)(unit + 0xa2) != side) {
      continue;
    }
    if (func_00300580(*(u32 *)(unit + 0xa2c),0x80000) != 0) {
      continue;
    }
    if (func_00301ca0(*(u32 *)(unit + 0xa2c),param_2) == 0) {
      continue;
    }
    return 1;
  }
  return 0;
}

// FUN_002c1ce0

bool func_002c1ce0(int param_1,int param_2)

{
  if (func_00300580(*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c),0x80271) != 0) {
    return false;
  }
  if ((*(u16 *)(param_1 + 0x18) & 0x80) != 0) {
    return false;
  }
  return (*(u32 *)(iGpffffb7b8 +
                   (u32)*(u16 *)(*(int *)(iGpffffb6fc + 0xbbc) + 8) * 0x1c) & 1) != 0;
}

// FUN_002c1d80

u64 func_002c1d80(void)

{
  return 0;
}

// FUN_002c1d90

bool func_002c1d90(int param_1)
{
    bool result;
    u8 genus;

    if (*(int *)(param_1 + 0x20) > 0)
        return false;

    genus = *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2);
    switch (genus) {
    case 0:
        result = *(u16 *)(iGpffffb6fc + 0x1a) == 1;
        break;
    case 1:
        result = *(u16 *)(iGpffffb6fc + 0x1a) == 2;
        break;
    default:
        result = false;
        break;
    }
    return result;
}

// FUN_002c1e10

bool func_002c1e10(int param_1,short param_2)

{
  u32 uVar1 = 0;
  
  uVar1 = func_00306e80(*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c),param_2);
  return (uVar1 & 0x2000000) != 0;
}

// FUN_002c1e50

bool func_002c1e50(int param_1,short param_2)

{
  u32 uVar1 = 0;
  
  uVar1 = func_00306e80(*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c),param_2);
  return (uVar1 & 0x4000000) != 0;
}

// FUN_002c1e90

bool func_002c1e90(int param_1,short param_2)

{
  u32 uVar1 = 0;
  
  uVar1 = func_00306e80(*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c),param_2);
  return (uVar1 & 0x1000000) != 0;
}

// FUN_002c1ed0

bool func_002c1ed0(int param_1,short param_2)

{
  u32 uVar1 = 0;
  
  uVar1 = func_00306e80(*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c),param_2);
  return (uVar1 & 0x8000000) != 0;
}

// FUN_002c1f10

void func_002c1f10(int param_1,u32 param_2)
{
  func_002c1080(param_1,param_2,1 << *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) & 0xffff,
               0x80000,0,(code *)&func_002c1e10);
  return;
}

// FUN_002c1f60 NONMATCHING

void func_002c1f60(int param_1, u32 param_2)
{
    u32 shift;
    switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2))
    {
    default:
        shift = 1;
        break;
    case 0:
        shift = 0;
        break;
    }
    func_002c1080(param_1, param_2, 1 << (shift & 0xffff) & 0xffff, 0x80000, 0, (code*)&func_002c1e10);
    return;
}

// FUN_002c1fc0

void func_002c1fc0(int param_1,u32 param_2)
{
  func_002c1080(param_1,param_2,1 << *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) & 0xffff,
               0x80000,0,(code *)&func_002c1e50);
  return;
}

// FUN_002c2010 NONMATCHING

void func_002c2010(int param_1, u32 param_2)
{
    u32 shift;
    switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2))
    {
    default:
        shift = 1;
        break;
    case 0:
        shift = 0;
        break;
    }
    func_002c1080(param_1, param_2, 1 << (shift & 0xffff) & 0xffff, 0x80000, 0, (code*)&func_002c1e50);
    return;
}

// FUN_002c2070

void func_002c2070(int param_1,u32 param_2)
{
  func_002c1080(param_1,param_2,1 << *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) & 0xffff,
               0x80000,0,(code *)&func_002c1e90);
  return;
}

// FUN_002c20c0 NONMATCHING

void func_002c20c0(int param_1, u32 param_2)
{
    u32 shift;
    switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2))
    {
    default:
        shift = 1;
        break;
    case 0:
        shift = 0;
        break;
    }
    func_002c1080(param_1, param_2, 1 << (shift & 0xffff) & 0xffff, 0x80000, 0, (code*)&func_002c1e90);
    return;
}

// FUN_002c2120

void func_002c2120(int param_1,u32 param_2)
{
  func_002c1080(param_1,param_2,1 << *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) & 0xffff,
               0x80000,0,(code *)&func_002c1ed0);
  return;
}

// FUN_002c2170 NONMATCHING

void func_002c2170(int param_1, u32 param_2)
{
    u32 shift;
    switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2))
    {
    default:
        shift = 1;
        break;
    case 0:
        shift = 0;
        break;
    }
    func_002c1080(param_1, param_2, 1 << (shift & 0xffff) & 0xffff, 0x80000, 0, (code*)&func_002c1ed0);
    return;
}

// FUN_002c21d0

bool func_002c21d0(int param_1,int param_2)

{
  extern s16 func_003082f0(u32,u16);
  s16 sVar1 = 0;
  u32 id = 0;
  
  id = *(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c);
  sVar1 = func_003082f0(id,*(u16 *)(param_1 + 0x7e));
  return sVar1 == param_2;
}

// FUN_002c2220

void func_002c2220(int param_1,u32 param_2)
{
  func_002c1080(param_1,param_2,1 << *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) & 0xffff,
               0x80000,0,(code *)&func_002c21d0);
  return;
}

// FUN_002c2270 NONMATCHING

void func_002c2270(int param_1, u32 param_2)
{
    u32 shift;
    switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2))
    {
    default:
        shift = 1;
        break;
    case 0:
        shift = 0;
        break;
    }
    func_002c1080(param_1, param_2, 1 << (shift & 0xffff) & 0xffff, 0x80000, 0, (code*)&func_002c21d0);
    return;
}

// FUN_002c22d0 MATCHING
bool func_002c22d0(int param_1, int param_2)
{
    bool result;

    switch (*(u16*)(param_1 + 0x7c))
    {
    default:
        result = false;
        break;
    case 1:
    case 2:
        result = *(u16*)(param_1 + 0x7e) == param_2;
        break;
    }
    return result;
}

// FUN_002c2310

void func_002c2310(int param_1,u32 param_2)
{
  func_002c1080(param_1,param_2,1 << *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) & 0xffff,
               0x80000,0,(code *)&func_002c22d0);
  return;
}

// FUN_002c2360 NONMATCHING

void func_002c2360(int param_1, u32 param_2)
{
    u32 shift;
    switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2))
    {
    default:
        shift = 1;
        break;
    case 0:
        shift = 0;
        break;
    }
    func_002c1080(param_1, param_2, 1 << (shift & 0xffff) & 0xffff, 0x80000, 0, (code*)&func_002c22d0);
    return;
}

// FUN_002c23c0

u32 func_002c23c0(int param_1)
{
  u16 result;

  result = func_002bff60_u16(param_1,0,*(u16 *)(param_1 + 0x7e),0);
  switch (result) {
  case 1:
  case 2:
    return 1;
  default:
    return 0;
  }
}

// FUN_002c2420

void func_002c2420(int param_1,u32 param_2)
{
  func_002c1080(param_1,param_2,1 << *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) & 0xffff,
               0x80000,0,(code *)&func_002c23c0);
  return;
}

// FUN_002c2470 NONMATCHING

void func_002c2470(int param_1, u32 param_2)
{
    u32 shift;
    switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2))
    {
    default:
        shift = 1;
        break;
    case 0:
        shift = 0;
        break;
    }
    func_002c1080(param_1, param_2, 1 << (shift & 0xffff) & 0xffff, 0x80000, 0, (code*)&func_002c23c0);
    return;
}

// FUN_002c24d0 MATCHING
bool func_002c24d0(int param_1, u32 param_2)
{
    return param_2 >= *(u32*)(param_1 + 0x20);
}

// FUN_002c24f0 MATCHING
bool func_002c24f0(int param_1, u32 param_2)
{
    return param_2 <= *(u32*)(param_1 + 0x20);
}

// FUN_002c2510

u32 func_002c2510(int param_1)
{
    int data;
    s32 count;
    u16 *skills;
    u16 index;

    data = *(int *)(param_1 + 0x30);
    count = (u16)func_00308ba0_u32(*(u32 *)(data + 0xa2c));
    skills = (u16 *)func_00308bb0_u32(*(u32 *)(data + 0xa2c));
    index = 0;
    count = (u16)count;
    while (index < count) {
        u16 skillId = skills[index];

        if (skillId != 0 && skillId < 0x1d0 && func_00308860(skillId) != 0)
            return 1;
        index++;
    }
    return 0;
}

// FUN_002c25d0

bool func_002c25d0(int param_1)

{
  return *(u8 *)(param_1 + 0x28) > 0;
}

// FUN_002c25e0

void func_002c25e0(int param_1,u32 param_2)
{
  func_002c1080(param_1,param_2,1 << *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) & 0xffff,
               0x180000,0,(code *)&func_002c1e10);
  return;
}

// FUN_002c2630 NONMATCHING

void func_002c2630(int param_1, u32 param_2)
{
    u32 shift;
    switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2))
    {
    default:
        shift = 1;
        break;
    case 0:
        shift = 0;
        break;
    }
    func_002c1080(param_1, param_2, 1 << (shift & 0xffff) & 0xffff, 0x180000, 0, (code*)&func_002c1e10);
    return;
}

// FUN_002c2690

void func_002c2690(int param_1,u32 param_2)
{
  func_002c1080(param_1,param_2,1 << *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) & 0xffff,
               0x180000,0,(code *)&func_002c1e50);
  return;
}

// FUN_002c26e0 NONMATCHING

void func_002c26e0(int param_1, u32 param_2)
{
    u32 shift;
    switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2))
    {
    default:
        shift = 1;
        break;
    case 0:
        shift = 0;
        break;
    }
    func_002c1080(param_1, param_2, 1 << (shift & 0xffff) & 0xffff, 0x180000, 0, (code*)&func_002c1e50);
    return;
}

// FUN_002c2740

void func_002c2740(int param_1,u32 param_2)
{
  func_002c1080(param_1,param_2,1 << *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) & 0xffff,
               0x180000,0,(code *)&func_002c1e90);
  return;
}

// FUN_002c2790 NONMATCHING

void func_002c2790(int param_1, u32 param_2)
{
    u32 shift;
    switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2))
    {
    default:
        shift = 1;
        break;
    case 0:
        shift = 0;
        break;
    }
    func_002c1080(param_1, param_2, 1 << (shift & 0xffff) & 0xffff, 0x180000, 0, (code*)&func_002c1e90);
    return;
}

// FUN_002c27f0

void func_002c27f0(int param_1,u32 param_2)
{
  func_002c1080(param_1,param_2,1 << *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) & 0xffff,
               0x180000,0,(code *)&func_002c1ed0);
  return;
}

// FUN_002c2840 NONMATCHING

void func_002c2840(int param_1, u32 param_2)
{
    u32 shift;
    switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2))
    {
    default:
        shift = 1;
        break;
    case 0:
        shift = 0;
        break;
    }
    func_002c1080(param_1, param_2, 1 << (shift & 0xffff) & 0xffff, 0x180000, 0, (code*)&func_002c1ed0);
    return;
}

// FUN_002c28a0 MATCHING
bool func_002c28a0(int param_1, int param_2)
{
    return *(u16*)(*(s32*)(param_1 + 0x30) + 0xa4) == param_2;
}

// FUN_002c28c0 NONMATCHING

bool func_002c28c0(int param_1,int param_2)

{
  u8 bVar1 = 0;
  int iVar2 = 0;
  u32 uVar3 = 0;
  long lVar4 = 0;
  int iVar5 = 0;
  int iVar6 = 0;
  int iVar7 = 0;
  
  bVar1 = *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2);
  iVar6 = 0;
  iVar5 = 0;
  for (iVar7 = *(int *)(iGpffffb6fc + 0x14c); iVar7 != 0; iVar7 = *(int *)(iVar7 + 0x4a8)) {
    if (((((*(u16 *)(iVar7 + 0x1a) & 1) != 0) && ((*(u16 *)(iVar7 + 0x1a) & 8) != 0)) &&
        (iVar2 = *(int *)(iVar7 + 0x30),
        (1 << (bVar1 & 0x1f) & 0xffffU & 1 << (*(u8 *)(iVar2 + 0xa2) & 0x1f)) != 0)) &&
       (lVar4 = func_0030b5a0(*(u32 *)(iVar2 + 0xa2c),0), lVar4 == 0)) {
      uVar3 = func_002ffd70(*(u32 *)(iVar2 + 0xa2c));
      iVar6 = iVar6 + (uVar3 & 0xffff);
      uVar3 = func_002ffdf0(*(u32 *)(iVar2 + 0xa2c));
      iVar5 = iVar5 + (uVar3 & 0xffff);
    }
  }
  return (u32)(iVar6 * 100) <= (u32)(iVar5 * param_2);
}

// FUN_002c29e0 NONMATCHING

bool func_002c29e0(int param_1,int param_2)

{
  char cVar1 = 0;
  int iVar2 = 0;
  u32 uVar3 = 0;
  long lVar4 = 0;
  int iVar5 = 0;
  int iVar6 = 0;
  int iVar7 = 0;
  
  cVar1 = *(char *)(*(int *)(param_1 + 0x30) + 0xa2);
  iVar6 = 0;
  iVar5 = 0;
  for (iVar7 = *(int *)(iGpffffb6fc + 0x14c); iVar7 != 0; iVar7 = *(int *)(iVar7 + 0x4a8)) {
    if (((((*(u16 *)(iVar7 + 0x1a) & 1) != 0) && ((*(u16 *)(iVar7 + 0x1a) & 8) != 0)) &&
        (iVar2 = *(int *)(iVar7 + 0x30),
        (1 << (u32)(cVar1 == '\0') & 0xffffU & 1 << (*(u8 *)(iVar2 + 0xa2) & 0x1f)) != 0)) &&
       (lVar4 = func_0030b5a0(*(u32 *)(iVar2 + 0xa2c),0), lVar4 == 0)) {
      uVar3 = func_002ffd70(*(u32 *)(iVar2 + 0xa2c));
      iVar6 = iVar6 + (uVar3 & 0xffff);
      uVar3 = func_002ffdf0(*(u32 *)(iVar2 + 0xa2c));
      iVar5 = iVar5 + (uVar3 & 0xffff);
    }
  }
  return (u32)(iVar6 * 100) <= (u32)(iVar5 * param_2);
}

// FUN_002c2b20

bool func_002c2b20(int param_1,u16 param_2)
{
  int iVar1;
  
  if (param_2 >= 0x270) {
    func_0019d3f0(D_00696f50 + 0x38,0x468);
  }
  iVar1 = *(int *)(param_1 + 0x30);
  if (func_00300580(*(u32 *)(iVar1 + 0xa2c),0x80274) != 0) {
    return false;
  }
  if (func_003005e0(*(u32 *)(iVar1 + 0xa2c),param_2) == 0) {
    return false;
  }
  return func_003086f0(*(u32 *)(iVar1 + 0xa2c),param_2) == 0;
}
// FUN_002c2be0 NONMATCHING
void func_002c2be0(int param_1,u32 param_2)
{
  u32 shift;

  switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2)) {
  default:
    shift = 1;
    break;
  case 0:
    shift = 0;
    break;
  }
  func_002c1080(param_1,param_2,1 << (shift & 0xffff) & 0xffff,0x80000,6,
                 (code *)&func_002c1ed0);
  return;
}

// FUN_002c2c40 NONMATCHING

void func_002c2c40(int param_1,u32 param_2)
{
  u32 shift;

  switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2)) {
  default:
    shift = 1;
    break;
  case 0:
    shift = 0;
    break;
  }
  func_002c1080(param_1,param_2,1 << (shift & 0xffff) & 0xffff,0x180000,6,
                 (code *)&func_002c1ed0);
  return;
}

// FUN_002c2ca0 NONMATCHING

void func_002c2ca0(int param_1,u32 param_2)
{
  u32 shift;

  switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2)) {
  default:
    shift = 1;
    break;
  case 0:
    shift = 0;
    break;
  }
  func_002c1080(param_1,param_2,1 << (shift & 0xffff) & 0xffff,0x80000,7,
                 (code *)&func_002c1ed0);
  return;
}

// FUN_002c2d00 NONMATCHING

u32 func_002c2d00(int param_1,u32 param_2)

{
  u16 uVar1 = 0;
  int iVar2 = 0;
  int iVar3 = 0;
  bool bVar4 = 0;
  short sVar5 = 0;
  u32 uVar6 = 0;
  u32 uVar7 = 0;
  int iVar8 = 0;
  long lVar9 = 0;
  u16 *puVar10;
  u32 uVar11 = 0;
  
  iVar2 = *(int *)(param_1 + 0x30);
  sVar5 = func_003082f0(*(u32 *)(iVar2 + 0xa2c),0);
  if (sVar5 == param_2) {
    uVar6 = 1;
  }
  else {
    uVar7 = func_00308ba0(*(u32 *)(iVar2 + 0xa2c));
    iVar8 = func_00308bb0(*(u32 *)(iVar2 + 0xa2c));
    for (uVar11 = 0; uVar11 < (uVar7 & 0xffff); uVar11 = uVar11 + 1 & 0xffff) {
      puVar10 = (u16 *)(iVar8 + uVar11 * 2);
      uVar1 = *puVar10;
      if (((uVar1 != 0) && (uVar1 < 0x1d0)) &&
         (sVar5 = func_003082f0(*(u32 *)(iVar2 + 0xa2c),uVar1), sVar5 == param_2)) {
        uVar1 = *puVar10;
        if (0x26f < uVar1) {
          func_0019d3f0(0x696f88,0x468);
        }
        iVar3 = *(int *)(param_1 + 0x30);
        lVar9 = func_00300580(*(u32 *)(iVar3 + 0xa2c),0x80274);
        if (lVar9 == 0) {
          lVar9 = func_003005e0(*(u32 *)(iVar3 + 0xa2c),uVar1);
          if (lVar9 == 0) {
            bVar4 = false;
          }
          else {
            lVar9 = func_003086f0(*(u32 *)(iVar3 + 0xa2c),uVar1);
            if (lVar9 == 0) {
              bVar4 = true;
            }
            else {
              bVar4 = false;
            }
          }
        }
        else {
          bVar4 = false;
        }
        if (bVar4) {
          return 1;
        }
      }
    }
    uVar6 = 0;
  }
  return uVar6;
}

// FUN_002c2ed0 NONMATCHING

bool func_002c2ed0(u64 param_1,u16 param_2,long param_3)

{
  short sVar1 = 0;
  int iVar2 = 0;
  char cVar3 = 0;
  u32 uVar4 = 0;
  int iVar5 = 0;
  long lVar6 = 0;
  u32 uVar7 = 0;
  u32 uVar8 = 0;
  
  iVar2 = *(int *)((int)param_1 + 0x30);
  if (((*(char *)(iVar2 + 0xa2) == '\x01') && (lVar6 = func_002e3350(param_1,param_2), lVar6 == 0))
     && (lVar6 = func_0017b260(*(u16 *)(iVar2 + 0xa4)), lVar6 == 0)) {
    return true;
  }
  uVar7 = func_003080c0(param_2);
  if ((param_3 == 1) && ((uVar7 & 0xe0001) == 0)) {
    if ((uVar7 & 0xe) == 0) {
      if (((uVar7 & 0x100) == 0) &&
         (cVar3 = func_00301750(*(u32 *)(iVar2 + 0xa2c),0x12), '\0' < cVar3)) {
        return false;
      }
    }
    else {
      cVar3 = func_00301750(*(u32 *)(iVar2 + 0xa2c),0x11);
      if ('\0' < cVar3) {
        return false;
      }
    }
  }
  if ((uVar7 & 0xe) != 0) {
    if (*(char *)(iVar2 + 0xa2) == '\x01') {
      if ((**(u16 **)(iVar2 + 0xa2c) & 0x200) != 0) {
        return false;
      }
    }
    else {
      uVar4 = func_00308ba0(*(u32 *)(iVar2 + 0xa2c));
      iVar5 = func_00308bb0(*(u32 *)(iVar2 + 0xa2c));
      for (uVar8 = 0; uVar8 < (uVar4 & 0xffff); uVar8 = uVar8 + 1 & 0xffff) {
        sVar1 = *(short *)(iVar5 + uVar8 * 2);
        if (((sVar1 == 0x222) || (sVar1 == 0x221)) || (sVar1 == 0x220)) {
          return false;
        }
      }
    }
  }
  uVar7 = func_0030b4b0(*(u32 *)(iVar2 + 0xa2c),param_2);
  return (uVar7 & 0x7000000) == 0;
}

// FUN_002c30f0

void func_002c30f0(u64 param_1,u16 param_2)

{
  func_002c2ed0(param_1,param_2,1);
  return;
}

// FUN_002c3120

void func_002c3120(u64 param_1,u16 param_2)

{
  func_002c2ed0(param_1,param_2,0);
  return;
}

// FUN_002c3150 NONMATCHING

void func_002c3150(int param_1,u32 param_2)
{
  u32 shift;

  switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2)) {
  default:
    shift = 1;
    break;
  case 0:
    shift = 0;
    break;
  }
  func_002c1080(param_1,param_2,1 << (shift & 0xffff) & 0xffff,0x80000,10,
                 (code *)&func_002c30f0);
  return;
}

// FUN_002c31b0 NONMATCHING

void func_002c31b0(int param_1,u32 param_2)
{
  u32 shift;

  switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2)) {
  default:
    shift = 1;
    break;
  case 0:
    shift = 0;
    break;
  }
  func_002c1080(param_1,param_2,1 << (shift & 0xffff) & 0xffff,0x180000,10,
                 (code *)&func_002c30f0);
  return;
}

// FUN_002c3210 NONMATCHING

void func_002c3210(int param_1,u32 param_2)
{
  u32 shift;

  switch (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2)) {
  default:
    shift = 1;
    break;
  case 0:
    shift = 0;
    break;
  }
  func_002c1080(param_1,param_2,1 << (shift & 0xffff) & 0xffff,0x80000,0xb,
                 (code *)&func_002c30f0);
  return;
}

// FUN_002c3270

bool func_002c3270(int param_1)
{
  long lVar2 = 0;
  if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 1) {
    return false;
  }
  lVar2 = func_0017b260(*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4));
  return lVar2 != 0;
}

// FUN_002c32c0

u32 func_002c32c0(int param_1)

{
  return !((**(u16 **)(*(int *)(param_1 + 0x30) + 0xa2c) & 0x10));
}

// FUN_002c32e0

u32 func_002c32e0(int param_1)

{
  return !((**(u16 **)(*(int *)(param_1 + 0x30) + 0xa2c) & 0x20));
}

// FUN_002c3300 NONMATCHING

u32 func_002c3300(int param_1,u32 param_2)

{
  char cVar1 = 0;
  u32 uVar2 = 0;
  u32 uVar3 = 0;
  int iVar4 = 0;
  
  cVar1 = *(char *)(*(int *)(param_1 + 0x30) + 0xa2);
  uVar2 = func_002ffcc0(*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c));
  iVar4 = *(int *)(iGpffffb6fc + 0x14c);
  do {
    if (iVar4 == 0) {
      return 0;
    }
    if ((((*(u16 *)(iVar4 + 0x1a) & 1) != 0) && ((*(u16 *)(iVar4 + 0x1a) & 8) != 0)) &&
       ((bool)*(char *)(*(int *)(iVar4 + 0x30) + 0xa2) == (cVar1 == '\0'))) {
      uVar3 = func_002ffcc0(*(u32 *)(*(int *)(iVar4 + 0x30) + 0xa2c));
      if (((uVar2 & 0xff) <= (uVar3 & 0xff)) && (param_2 <= (uVar3 & 0xff) - (uVar2 & 0xff))) {
        return 1;
      }
    }
    iVar4 = *(int *)(iVar4 + 0x4a8);
  } while( true );
}

// FUN_002c3400

bool func_002c3400(int param_1)

{
  long lVar1 = 0;
  
  lVar1 = func_00301ca0(*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c));
  return lVar1 != 0;
}

// FUN_002c3430 NONMATCHING

u64
func_002c3430(u64 param_1,u64 param_2,u32 param_3,u16 param_4,int param_5,
            code *param_6)

{
  short sVar1 = 0;
  int iVar2 = 0;
  u32 uVar3 = 0;
  long lVar4 = 0;
  u64 uVar5 = 0;
  int iVar6 = 0;
  u32 uVar7 = 0;
  int iVar8 = 0;
  int aiStack_30 [12] = {0};
  
  iVar8 = (int)param_1;
  if ((param_4 & 0x20) == 0) {
    sVar1 = func_002bff60(param_1,iVar8 + 0x88,*(u16 *)(iVar8 + 0x6e),0);
    if (sVar1 != 0) {
      for (uVar7 = 0; uVar7 < *(u16 *)(iVar8 + 0xc0); uVar7 = uVar7 + 1 & 0xffff) {
        iVar6 = iVar8 + uVar7 * 4;
        *(u32 *)(iVar6 + 0x38) = *(u32 *)(iVar6 + 0x88);
      }
      *(u16 *)(iVar8 + 0x6a) = *(u16 *)(iVar8 + 0xc0);
      return 1;
    }
  }
  else {
    func_002bfcb0(param_1,iVar8 + 0x88,2,0,0);
  }
  uVar7 = 0;
  for (uVar3 = 0; uVar3 < *(u16 *)(iVar8 + 0xc0); uVar3 = uVar3 + 1 & 0xffff) {
    iVar6 = *(int *)(iVar8 + uVar3 * 4 + 0x88);
    if ((((*(u16 *)(iVar6 + 0x1a) & 1) != 0) &&
        (((iVar2 = *(int *)(iVar6 + 0x30), param_4 == 0 ||
          (((((param_4 & 1) == 0 ||
             (lVar4 = func_00300580(*(u32 *)(iVar2 + 0xa2c),0x100000), lVar4 != 0)) &&
            (((param_4 & 2) == 0 ||
             (((*(char *)(iVar2 + 0xa2) != '\x01' ||
               (lVar4 = func_002e3350(iVar6,(short)param_2), lVar4 != 0)) ||
              (lVar4 = func_0017b260(*(u16 *)(iVar2 + 0xa4)), lVar4 != 0)))))) &&
           (((param_4 & 0x10) == 0 || (lVar4 = func_002c5030(param_1,iVar6,0,0), -1 < lVar4)))))) &&
         (lVar4 = func_00300580(*(u32 *)(iVar2 + 0xa2c),param_3), lVar4 == 0)))) &&
       (iVar2 = (*param_6)(iVar6,param_2), param_5 != iVar2)) {
      aiStack_30[uVar7] = iVar6;
      uVar7 = uVar7 + 1 & 0xffff;
    }
  }
  if (uVar7 == 0) {
    if ((param_4 & 8) == 0) {
      uVar5 = func_002c3770(param_1,param_2);
    }
    else {
      uVar5 = 0;
    }
  }
  else {
    if ((param_4 & 4) == 0) {
      uVar3 = 0;
      if (1 < uVar7) {
        uVar3 = func_002ffbc0();
        uVar3 = uVar3 & 0xffff;
      }
      *(int *)(iVar8 + 0x38) = aiStack_30[uVar3];
      *(u16 *)(iVar8 + 0x6a) = 1;
    }
    else {
      for (uVar3 = 0; uVar3 < uVar7; uVar3 = uVar3 + 1 & 0xffff) {
        *(int *)(iVar8 + uVar3 * 4 + 0x38) = aiStack_30[uVar3];
      }
      *(short *)(iVar8 + 0x6a) = (short)uVar7;
    }
    uVar5 = 1;
  }
  return uVar5;
}

// FUN_002c3770 NONMATCHING

u32 func_002c3770(u64 param_1,u64 param_2)

{
  char cVar1 = 0;
  u16 uVar2 = 0;
  float fVar3 = 0;
  short sVar4 = 0;
  u16 uVar5 = 0;
  u16 uVar6 = 0;
  int iVar7 = 0;
  int iVar8 = 0;
  u32 uVar9 = 0;
  bool bVar10 = 0;
  int iVar11 = 0;
  u32 uVar12 = 0;
  float fVar13 = 0;
  float afStack_60 [24] = {0};
  
  iVar11 = (int)param_1;
  sVar4 = func_002bff60(param_1,iVar11 + 0x88,*(u16 *)(iVar11 + 0x6e),0);
  if (sVar4 == 0) {
    uVar2 = *(u16 *)(iVar11 + 0xc0);
    uVar12 = (u32)uVar2;
    bVar10 = true;
    if (uVar12 == 1) {
      *(u32 *)(iVar11 + 0x38) = *(u32 *)(iVar11 + 0x88);
      *(u16 *)(iVar11 + 0x6a) = 1;
    }
    else {
      if (*(char *)(*(int *)(iVar11 + 0x30) + 0xa2) == '\x01') {
        uVar9 = 0;
        while ((uVar9 < uVar12 &&
               (*(char *)(*(int *)(*(int *)(iVar11 + uVar9 * 4 + 0x88) + 0x30) + 0xa2) == '\0'))) {
          uVar9 = uVar9 + 1 & 0xffff;
        }
        if (uVar9 == uVar12) {
          bVar10 = false;
        }
      }
      cVar1 = *(char *)(((u32)*(u16 *)(iVar11 + 0x6e) * 10 + (u32)*(u16 *)(iVar11 + 0x6e)) *
                        4 + iGpffffb708 + 0x11);
      if ((((((cVar1 != '\x10') && (cVar1 != '\x0e')) && (cVar1 != '\r')) &&
           ((cVar1 != '\f' && (cVar1 != '\n')))) &&
          ((cVar1 != '\b' && ((cVar1 != '\x04' && (cVar1 != '\x03')))))) && (cVar1 != '\x01')) {
        bVar10 = true;
      }
      if ((bVar10) || (4 < uVar12)) {
        uVar12 = func_002ffbc0(uVar12);
        *(u32 *)(iVar11 + 0x38) = *(u32 *)((uVar12 & 0xffff) * 4 + iVar11 + 0x88);
        *(u16 *)(iVar11 + 0x6a) = 1;
      }
      else {
        for (uVar9 = 0; uVar9 < uVar12; uVar9 = uVar9 + 1 & 0xffff) {
          iVar7 = iVar11 + uVar9 * 4;
          iVar8 = *(int *)(iVar7 + 0x88);
          uVar6 = func_002ffdf0(*(u32 *)(*(int *)(iVar8 + 0x30) + 0xa2c));
          uVar5 = func_002ffd70(*(u32 *)(*(int *)(iVar8 + 0x30) + 0xa2c));
          afStack_60[uVar9 * 2] = *(float *)(iVar7 + 0x88);
          afStack_60[uVar9 * 2 + 1] = (float)uVar5 / (float)uVar6;
        }
        do {
          bVar10 = false;
          for (uVar9 = 0; (int)uVar9 < (int)(uVar2 - 1); uVar9 = uVar9 + 1 & 0xffff) {
            fVar13 = afStack_60[uVar9 * 2 + 1];
            if (fVar13 < afStack_60[uVar9 * 2 + 3]) {
              fVar3 = afStack_60[uVar9 * 2];
              afStack_60[uVar9 * 2] = afStack_60[uVar9 * 2 + 2];
              afStack_60[uVar9 * 2 + 1] = afStack_60[uVar9 * 2 + 3];
              afStack_60[uVar9 * 2 + 2] = fVar3;
              afStack_60[uVar9 * 2 + 3] = fVar13;
              bVar10 = true;
            }
          }
        } while (bVar10);
        uVar6 = func_002ffbc0(100);
        uVar5 = 0;
        for (uVar9 = 0; uVar9 < uVar12; uVar9 = uVar9 + 1 & 0xffff) {
          uVar5 = uVar5 + *(u8 *)((u32)uVar2 * 4 + uVar9 + 0x696f9c);
          if (uVar6 <= uVar5) break;
        }
        if (uVar12 == uVar9) {
          iVar8 = func_002ffbc0(uVar12);
          *(float *)(iVar11 + 0x38) = afStack_60[iVar8 * 2];
          *(u16 *)(iVar11 + 0x6a) = 1;
        }
        else {
          *(float *)(iVar11 + 0x38) = afStack_60[uVar9 * 2];
          *(u16 *)(iVar11 + 0x6a) = 1;
        }
      }
    }
  }
  else {
    for (uVar12 = 0; uVar12 < *(u16 *)(iVar11 + 0xc0); uVar12 = uVar12 + 1 & 0xffff) {
      iVar8 = iVar11 + uVar12 * 4;
      *(u32 *)(iVar8 + 0x38) = *(u32 *)(iVar8 + 0x88);
    }
    *(u16 *)(iVar11 + 0x6a) = *(u16 *)(iVar11 + 0xc0);
  }
  return 1;
}

// FUN_002c3be0 NONMATCHING

u32 func_002c3be0(u64 param_1)

{
  int iVar1 = 0;
  short sVar2 = 0;
  u32 uVar3 = 0;
  int iVar4 = 0;
  u32 uVar5 = 0;
  u32 uVar6 = 0;
  int iVar7 = 0;
  
  iVar7 = (int)param_1;
  sVar2 = func_002bff60(param_1,iVar7 + 0x88,*(u16 *)(iVar7 + 0x6e),0);
  if (sVar2 == 0) {
    iVar4 = 0;
    uVar5 = 0xfffffff;
    for (uVar6 = 0; uVar6 < *(u16 *)(iVar7 + 0xc0); uVar6 = uVar6 + 1) {
      iVar1 = *(int *)(iVar7 + uVar6 * 4 + 0x88);
      uVar3 = (u32)*(u16 *)(*(int *)(*(int *)(iVar1 + 0x30) + 0xa2c) + 8);
      if (uVar3 < uVar5) {
        uVar5 = uVar3;
        iVar4 = iVar1;
      }
    }
    *(int *)(iVar7 + 0x38) = iVar4;
    *(u16 *)(iVar7 + 0x6a) = 1;
  }
  else {
    for (uVar5 = 0; uVar5 < *(u16 *)(iVar7 + 0xc0); uVar5 = uVar5 + 1 & 0xffff) {
      iVar4 = iVar7 + uVar5 * 4;
      *(u32 *)(iVar4 + 0x38) = *(u32 *)(iVar4 + 0x88);
    }
    *(u16 *)(iVar7 + 0x6a) = *(u16 *)(iVar7 + 0xc0);
  }
  return 1;
}

// FUN_002c3ce0 NONMATCHING

u32 func_002c3ce0(u64 param_1)

{
  int iVar1 = 0;
  short sVar2 = 0;
  u32 uVar3 = 0;
  int iVar4 = 0;
  u32 uVar5 = 0;
  u32 uVar6 = 0;
  int iVar7 = 0;
  
  iVar7 = (int)param_1;
  sVar2 = func_002bff60(param_1,iVar7 + 0x88,*(u16 *)(iVar7 + 0x6e),0);
  if (sVar2 == 0) {
    iVar4 = 0;
    uVar6 = 0xffff;
    for (uVar5 = 0; uVar5 < *(u16 *)(iVar7 + 0xc0); uVar5 = uVar5 + 1 & 0xffff) {
      iVar1 = *(int *)(iVar7 + uVar5 * 4 + 0x88);
      uVar3 = func_002ffcc0(*(u32 *)(*(int *)(iVar1 + 0x30) + 0xa2c));
      if ((uVar3 & 0xff) < uVar6) {
        uVar6 = uVar3 & 0xff;
        iVar4 = iVar1;
      }
    }
    *(int *)(iVar7 + 0x38) = iVar4;
    *(u16 *)(iVar7 + 0x6a) = 1;
  }
  else {
    for (uVar5 = 0; uVar5 < *(u16 *)(iVar7 + 0xc0); uVar5 = uVar5 + 1 & 0xffff) {
      iVar4 = iVar7 + uVar5 * 4;
      *(u32 *)(iVar4 + 0x38) = *(u32 *)(iVar4 + 0x88);
    }
    *(u16 *)(iVar7 + 0x6a) = *(u16 *)(iVar7 + 0xc0);
  }
  return 1;
}

// FUN_002c3e10

u64 func_002c3e10(void)

{
  return 0;
}

// FUN_002c3e20

void func_002c3e20(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0,0,0,(code *)&func_002c1710);
  return;
}

// FUN_002c3e60

void func_002c3e60(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0,0,1,(code *)&func_002c1710);
  return;
}

// FUN_002c3ea0

void func_002c3ea0(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0,0,0,(code *)&func_002c28a0);
  return;
}

// FUN_002c3ee0

u32 func_002c3ee0(int param_1)

{
  *(int *)(param_1 + 0x38) = param_1;
  *(u16 *)(param_1 + 0x6a) = 1;
  return 1;
}

// FUN_002c3f00 NONMATCHING

void func_002c3f00(int param_1)

{
  int iVar1 = 0;
  long lVar2 = 0;
  u32 uVar3 = 0;
  int aiStack_30 [12] = {0};
  
  uVar3 = 0;
  for (iVar1 = *(int *)(iGpffffb6fc + 0x14c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x4a8)) {
    if ((((param_1 != iVar1) && ((*(u16 *)(iVar1 + 0x1a) & 1) != 0)) &&
        ((*(u16 *)(iVar1 + 0x1a) & 8) != 0)) &&
       ((*(char *)(*(int *)(param_1 + 0x30) + 0xa2) == *(char *)(*(int *)(iVar1 + 0x30) + 0xa2) &&
        (lVar2 = func_00300580(*(u32 *)(*(int *)(iVar1 + 0x30) + 0xa2c),0x80000), lVar2 == 0))
       )) {
      aiStack_30[uVar3] = iVar1;
      uVar3 = uVar3 + 1 & 0xffff;
    }
  }
  if (uVar3 == 0) {
    *(int *)(param_1 + 0x38) = param_1;
    *(u16 *)(param_1 + 0x6a) = 1;
  }
  else {
    iVar1 = func_002ffbc0();
    *(int *)(param_1 + 0x38) = aiStack_30[iVar1];
    *(u16 *)(param_1 + 0x6a) = 1;
  }
  return;
}

// FUN_002c4000

void func_002c4000(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0,0,0,(code *)&func_002c1e10);
  return;
}

// FUN_002c4040

void func_002c4040(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0,0,0,(code *)&func_002c1e50);
  return;
}

// FUN_002c4080

void func_002c4080(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0,0,0,(code *)&func_002c1e90);
  return;
}

// FUN_002c40c0

void func_002c40c0(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0,0,0,(code *)&func_002c1ed0);
  return;
}

// FUN_002c4100

void func_002c4100(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0,0,1,(code *)&func_002c1e10);
  return;
}

// FUN_002c4140

void func_002c4140(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0,0,1,(code *)&func_002c1e50);
  return;
}

// FUN_002c4180

void func_002c4180(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0,0,1,(code *)&func_002c1e90);
  return;
}

// FUN_002c41c0

void func_002c41c0(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0,0,1,(code *)&func_002c1ed0);
  return;
}

// FUN_002c4200

u32 func_002c4200(u32 param_1)

{
  u16 result;
  u16 index;
  u32 address;

  result = func_002bff60_u16(param_1,param_1 + 0x88,*(u16 *)(param_1 + 0x6e),1);
  if (result != 0) {
    for (index = 0; index < *(u16 *)(param_1 + 0xc0); index++) {
      *(u32 *)(param_1 + index * 4 + 0x38) = *(u32 *)(param_1 + index * 4 + 0x88);
    }
    *(u16 *)(param_1 + 0x6a) = *(u16 *)(param_1 + 0xc0);
    return 1;
  }
  index = func_002ffbc0_u16(*(u16 *)(param_1 + 0xc0));
  address = (index & 0xffff) * 4;
  *(u32 *)(param_1 + 0x38) = *(u32 *)(address + param_1 + 0x88);
  *(u16 *)(param_1 + 0x6a) = 1;
  return 1;
}

// FUN_002c42c0

u32 func_002c42c0(u32 param_1,u32 param_2)

{
  u16 result;
  u16 index;

  result = func_002bff60_u16(param_1,param_1 + 0x88,*(u16 *)(param_1 + 0x6e),0);
  if (result != 0) {
    for (index = 0; index < *(u16 *)(param_1 + 0xc0); index++) {
      *(u32 *)(param_1 + index * 4 + 0x38) = *(u32 *)(param_1 + index * 4 + 0x88);
    }
    *(u16 *)(param_1 + 0x6a) = *(u16 *)(param_1 + 0xc0);
    return 1;
  }
  if (func_002c0970(param_1 + 0x88) == 0) {
    return func_002c3770_u32(param_1,param_2);
  }
  *(u32 *)(param_1 + 0x38) = func_002c0880((int)&((u8 *)param_1)[0x88]);
  *(u16 *)(param_1 + 0x6a) = 1;
  return 1;
}

// FUN_002c43a0

void func_002c43a0(u64 param_1)

{
  func_002c3430(param_1,0x100000,0,0,0,(code *)&func_002c1710);
  return;
}

// FUN_002c43e0

void func_002c43e0(u64 param_1)

{
  func_002c3430(param_1,0x100000,0,0,1,(code *)&func_002c1710);
  return;
}

// FUN_002c4420

void func_002c4420(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0x100000,0,0,(code *)&func_002c1e10);
  return;
}

// FUN_002c4460

void func_002c4460(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0x100000,0,0,(code *)&func_002c1e50);
  return;
}

// FUN_002c44a0

void func_002c44a0(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0x100000,0,0,(code *)&func_002c1e90);
  return;
}

// FUN_002c44e0

void func_002c44e0(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0x100000,0,0,(code *)&func_002c1ed0);
  return;
}

// FUN_002c4520

void func_002c4520(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0x100000,0,1,(code *)&func_002c1e10);
  return;
}

// FUN_002c4560

void func_002c4560(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0x100000,0,1,(code *)&func_002c1e50);
  return;
}

// FUN_002c45a0

void func_002c45a0(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0x100000,0,1,(code *)&func_002c1e90);
  return;
}

// FUN_002c45e0

void func_002c45e0(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0x100000,0,1,(code *)&func_002c1ed0);
  return;
}

// FUN_002c4620

void func_002c4620(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0,1,0,(code *)&func_002c1e10);
  return;
}

// FUN_002c4660

void func_002c4660(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0,1,0,(code *)&func_002c1e50);
  return;
}

// FUN_002c46a0

void func_002c46a0(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0,1,0,(code *)&func_002c1e90);
  return;
}

// FUN_002c46e0

void func_002c46e0(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0,1,0,(code *)&func_002c1ed0);
  return;
}

// FUN_002c4720

void func_002c4720(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0,0,1,(code *)&func_002c28a0);
  return;
}

// FUN_002c4760

u32 func_002c4760(u32 param_1)

{
  u16 result;
  u16 index;
  u32 address;

  result = func_002bff60_u16(param_1,param_1 + 0x88,*(u16 *)(param_1 + 0x6e),0);
  if (result != 0) {
    for (index = 0; index < *(u16 *)(param_1 + 0xc0); index++) {
      *(u32 *)(param_1 + index * 4 + 0x38) = *(u32 *)(param_1 + index * 4 + 0x88);
    }
    *(u16 *)(param_1 + 0x6a) = *(u16 *)(param_1 + 0xc0);
    return 1;
  }
  index = func_002ffbc0_u16(*(u16 *)(param_1 + 0xc0));
  address = (index & 0xffff) * 4;
  *(u32 *)(param_1 + 0x38) = *(u32 *)(address + param_1 + 0x88);
  *(u16 *)(param_1 + 0x6a) = 1;
  return 1;
}

// FUN_002c4820

void func_002c4820(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0,0,0,(code *)&func_002c3400);
  return;
}

// FUN_002c4860

void func_002c4860(u64 param_1,u64 param_2)

{
  func_002c3430(param_1,param_2,0,0,1,(code *)&func_002c3400);
  return;
}

// FUN_002c48a0 NONMATCHING

u32 func_002c48a0(int param_1,int param_2,u16 *param_3,u32 param_4,short param_5)

{
  u16 uVar1 = 0;
  char cVar2 = 0;
  u32 uVar3 = 0;
  int iVar4 = 0;
  u16 *puVar5;
  u32 uVar6 = 0;
  u32 uVar7 = 0;
  int iVar8 = 0;
  
  uVar3 = func_002ffd70(*(u32 *)(*(int *)(param_2 + 0x30) + 0xa2c));
  uVar7 = 0xffffffff;
  iVar8 = 0xffffff;
  for (uVar6 = 0; uVar6 < (param_4 & 0xffff); uVar6 = uVar6 + 1 & 0xffff) {
    puVar5 = (u16 *)(param_3 + uVar6 * 2);
    uVar1 = *puVar5;
    if (uVar1 == 0) {
      cVar2 = '\0';
    }
    else {
      cVar2 = *(char *)(DAT_007ce3f8 + ((u32)uVar1 * 10 + (u32)uVar1) * 4 + 8);
    }
    if (((param_5 != 0) || (cVar2 == '\x01')) && ((param_5 != 1 || (cVar2 == '\0')))) {
      iVar4 = func_00303130(uVar1,*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c),
                           *(u32 *)(*(int *)(param_2 + 0x30) + 0xa2c),1,1,1,0,1);
      iVar4 = (uVar3 & 0xffff) + iVar4;
      if ((iVar4 < 1) || (iVar8 < 1)) {
        if ((iVar4 < 1) && ((0 < iVar8 || (iVar8 < iVar4)))) {
          uVar7 = (u32)*puVar5;
          iVar8 = iVar4;
        }
      }
      else if (iVar4 < iVar8) {
        uVar7 = (u32)*puVar5;
        iVar8 = iVar4;
      }
    }
  }
  func_00301870(*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c));
  func_00301870(*(u32 *)(*(int *)(param_2 + 0x30) + 0xa2c));
  return uVar7;
}

// FUN_002c4a90 NONMATCHING

u32 func_002c4a90(int param_1,int param_2,u16 *param_3,u32 param_4,short param_5)

{
  char cVar1 = 0;
  u32 uVar2 = 0;
  u16 uVar3 = 0;
  int iVar4 = 0;
  u16 *puVar5;
  u32 uVar6 = 0;
  u32 uVar7 = 0;
  int iVar8 = 0;
  
  uVar2 = func_002ffd70(*(u32 *)(*(int *)(param_2 + 0x30) + 0xa2c));
  uVar7 = 0xffffffff;
  iVar8 = 0xffffff;
  for (uVar6 = 0; uVar6 < (param_4 & 0xffff); uVar6 = uVar6 + 1 & 0xffff) {
    puVar5 = param_3 + uVar6;
    uVar3 = func_0030bc20(*puVar5);
    if ((((uVar3 != 0) && (uVar3 < 0x1d0)) &&
        ((cVar1 = *(char *)(DAT_007ce3f8 + uVar3 * 0x2c + 8), param_5 != 0 || (cVar1 == '\x01'))))
       && ((param_5 != 1 || (cVar1 == '\0')))) {
      iVar4 = func_00303130(uVar3,*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c),
                           *(u32 *)(*(int *)(param_2 + 0x30) + 0xa2c),1,1,1,1,1);
      iVar4 = (uVar2 & 0xffff) + iVar4;
      if ((iVar4 < 1) || (iVar8 < 1)) {
        if ((iVar4 < 1) && ((0 < iVar8 || (iVar8 < iVar4)))) {
          uVar7 = (u32)*puVar5;
          iVar8 = iVar4;
        }
      }
      else if (iVar4 < iVar8) {
        uVar7 = (u32)*puVar5;
        iVar8 = iVar4;
      }
    }
  }
  func_00301870(*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c));
  func_00301870(*(u32 *)(*(int *)(param_2 + 0x30) + 0xa2c));
  return uVar7;
}

// FUN_002c4c80 NONMATCHING

u32 func_002c4c80(int param_1,int param_2,u16 *param_3,u32 param_4,short param_5)

{
  char cVar1 = 0;
  u16 uVar2 = 0;
  u32 uVar3 = 0;
  u32 uVar4 = 0;
  int iVar5 = 0;
  long lVar6 = 0;
  u32 uVar7 = 0;
  u32 uVar8 = 0;
  long lVar9 = 0;
  u16 *puVar10;
  
  uVar3 = func_002ffd70(*(u32 *)(*(int *)(param_2 + 0x30) + 0xa2c));
  uVar4 = func_002ffdf0(*(u32 *)(*(int *)(param_2 + 0x30) + 0xa2c));
  uVar8 = 0xffffffff;
  lVar9 = 0xffffff;
  for (uVar7 = 0; uVar7 < (param_4 & 0xffff); uVar7 = uVar7 + 1 & 0xffff) {
    puVar10 = (u16 *)(param_3 + uVar7 * 2);
    uVar2 = *puVar10;
    if ((((uVar2 != 0) && (uVar2 < 0x1d0)) &&
        ((cVar1 = *(char *)(DAT_007ce3f8 + ((u32)uVar2 * 10 + (u32)uVar2) * 4 + 8), param_5 != 0
         || (cVar1 == '\x01')))) && ((param_5 != 1 || (cVar1 == '\0')))) {
      iVar5 = func_00303130(uVar2,*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c),
                           *(u32 *)(*(int *)(param_2 + 0x30) + 0xa2c),1,1,1,0,1);
      lVar6 = func_0051e0e0((uVar4 & 0xffff) - ((uVar3 & 0xffff) + iVar5));
      if (lVar6 < lVar9) {
        uVar8 = (u32)*puVar10;
        lVar9 = lVar6;
      }
    }
  }
  func_00301870(*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c));
  func_00301870(*(u32 *)(*(int *)(param_2 + 0x30) + 0xa2c));
  return uVar8;
}

// FUN_002c4e50 NONMATCHING

u32 func_002c4e50(int param_1,int param_2,u16 *param_3,u32 param_4,short param_5)

{
  char cVar1 = 0;
  u32 uVar2 = 0;
  u32 uVar3 = 0;
  u32 uVar4 = 0;
  int iVar5 = 0;
  long lVar6 = 0;
  u32 uVar7 = 0;
  u32 uVar8 = 0;
  long lVar9 = 0;
  u16 *puVar10;
  
  uVar2 = func_002ffd70(*(u32 *)(*(int *)(param_2 + 0x30) + 0xa2c));
  uVar3 = func_002ffdf0(*(u32 *)(*(int *)(param_2 + 0x30) + 0xa2c));
  uVar8 = 0xffffffff;
  lVar9 = 0xffffff;
  for (uVar7 = 0; uVar7 < (param_4 & 0xffff); uVar7 = uVar7 + 1 & 0xffff) {
    puVar10 = (u16 *)(param_3 + uVar7 * 2);
    uVar4 = func_0030bc20(*puVar10);
    uVar4 = uVar4 & 0xffff;
    if ((((uVar4 != 0) && (uVar4 < 0x1d0)) &&
        ((cVar1 = *(char *)(DAT_007ce3f8 + uVar4 * 0x2c + 8), param_5 != 0 || (cVar1 == '\x01'))))
       && ((param_5 != 1 || (cVar1 == '\0')))) {
      iVar5 = func_00303130(uVar4,*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c),
                           *(u32 *)(*(int *)(param_2 + 0x30) + 0xa2c),1,1,1,1,1);
      lVar6 = func_0051e0e0((uVar3 & 0xffff) - ((uVar2 & 0xffff) + iVar5));
      if (lVar6 < lVar9) {
        uVar8 = (u32)*puVar10;
        lVar9 = lVar6;
      }
    }
  }
  func_00301870(*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c));
  func_00301870(*(u32 *)(*(int *)(param_2 + 0x30) + 0xa2c));
  return uVar8;
}

// FUN_002c5030 NONMATCHING

long func_002c5030(u64 param_1,u64 param_2,long param_3,int param_4)

{
  u16 uVar1 = 0;
  int iVar2 = 0;
  int iVar3 = 0;
  bool bVar4 = 0;
  u16 uVar5 = 0;
  u32 uVar6 = 0;
  int iVar7 = 0;
  long lVar8 = 0;
  u32 uVar9 = 0;
  u32 uVar10 = 0;
  u32 uVar11 = 0;
  u16 *puVar12;
  u16 auStack_10 [8] = {0};
  
  iVar2 = *(int *)((int)param_1 + 0x30);
  uVar5 = func_003082f0(*(u32 *)(iVar2 + 0xa2c),0);
  lVar8 = func_002c2ed0(param_2,uVar5,1);
  if (lVar8 != 0) {
    auStack_10[0] = 0;
  }
  uVar10 = (u32)(lVar8 != 0);
  uVar6 = func_00308ba0(*(u32 *)(iVar2 + 0xa2c));
  iVar7 = func_00308bb0(*(u32 *)(iVar2 + 0xa2c));
  uVar11 = 0;
  do {
    if ((uVar6 & 0xffff) <= uVar11) {
      if (uVar10 == 0) {
        lVar8 = -1;
      }
      else if (param_3 == 1) {
        lVar8 = func_002c48a0(param_1,param_2,auStack_10,uVar10,0);
        if (lVar8 < 0) {
          lVar8 = func_002c48a0(param_1,param_2,auStack_10,uVar10,0);
        }
      }
      else if (param_3 == 0) {
        lVar8 = func_002c48a0(param_1,param_2,auStack_10,uVar10,0);
        if (lVar8 < 0) {
          lVar8 = func_002c48a0(param_1,param_2,auStack_10,uVar10,1);
        }
      }
      else {
        lVar8 = func_002c48a0(param_1,param_2,auStack_10,uVar10,0xffff);
      }
      return lVar8;
    }
    puVar12 = (u16 *)(iVar7 + uVar11 * 2);
    if ((*puVar12 != 0) && (*puVar12 < 0x1d0)) {
      uVar5 = func_003082f0(*(u32 *)(iVar2 + 0xa2c));
      uVar9 = func_003080c0(uVar5);
      if (param_4 == 0) {
        if ((uVar9 & 0x1fe) != 0) {
LAB_002c5168:
          uVar1 = *puVar12;
          if (0x26f < uVar1) {
            func_0019d3f0(0x696f88,0x468);
          }
          iVar3 = *(int *)((int)param_1 + 0x30);
          lVar8 = func_00300580(*(u32 *)(iVar3 + 0xa2c),0x80274);
          if (lVar8 == 0) {
            lVar8 = func_003005e0(*(u32 *)(iVar3 + 0xa2c),uVar1);
            if (lVar8 == 0) {
              bVar4 = false;
            }
            else {
              lVar8 = func_003086f0(*(u32 *)(iVar3 + 0xa2c),uVar1);
              if (lVar8 == 0) {
                bVar4 = true;
              }
              else {
                bVar4 = false;
              }
            }
          }
          else {
            bVar4 = false;
          }
          if ((bVar4) && (lVar8 = func_002c2ed0(param_2,uVar5,1), lVar8 != 0)) {
            auStack_10[uVar10] = *puVar12;
            uVar10 = uVar10 + 1 & 0xffff;
          }
        }
      }
      else if (((uVar9 & 0x1fe) != 0) && ((uVar9 & 0xe) == 0)) goto LAB_002c5168;
    }
    uVar11 = uVar11 + 1 & 0xffff;
  } while( true );
}

// FUN_002c5380 NONMATCHING

u32 func_002c5380(int param_1,int param_2,u16 *param_3,long param_4)
{
  bool bVar1 = 0;
  u16 uVar2 = 0;
  u16 uVar3 = 0;
  u32 uVar4 = 0;
  int iVar5 = 0;
  u32 uVar6 = 0;
  long lVar7 = 0;
  u32 uVar8 = 0;
  short sVar10 = 0;
  u32 uVar11 = 0;
  u32 uVar12 = 0;
  int iVar13 = 0;
  u16 *puVar14;
  u16 auStack_10 [8] = {0};
  
  sVar10 = -1;
  uVar12 = 0;
  iVar5 = *(int *)(param_1 + 0x30);
  uVar4 = func_00308ba0(*(u32 *)(iVar5 + 0xa2c));
  uVar4 = uVar4 & 0xffff;
  iVar5 = func_00308bb0(*(u32 *)(iVar5 + 0xa2c));
  iVar13 = (int)param_2;
  lVar7 = func_0030b5a0(*(u32 *)(*(int *)(iVar13 + 0x30) + 0xa2c),0);
  if (lVar7 == 0) {
    uVar2 = *(u16 *)(*(int *)(*(int *)(iVar13 + 0x30) + 0xa2c) + 8);
    uVar6 = func_002ffdf0(*(u32 *)(*(int *)(iVar13 + 0x30) + 0xa2c));
    if ((uVar6 & 0xffff) * 0x3c < (u32)uVar2 * 100) {
      lVar7 = func_00300580(*(u32 *)(*(int *)(iVar13 + 0x30) + 0xa2c),0xe);
      if (lVar7 == 0) {
        uVar2 = func_002ffd70(*(u32 *)(*(int *)(iVar13 + 0x30) + 0xa2c));
        uVar3 = func_002ffdf0(*(u32 *)(*(int *)(iVar13 + 0x30) + 0xa2c));
        if (uVar2 < uVar3) {
          sVar10 = 1;
        }
      }
      else {
        sVar10 = 2;
      }
    }
    else {
      sVar10 = 1;
    }
  }
  else {
    sVar10 = 0;
  }
  if (sVar10 == 2) {
    for (uVar6 = 0; uVar6 < uVar4; uVar6 = uVar6 + 1 & 0xffff) {
      puVar14 = (u16 *)(iVar5 + uVar6 * 2);
      uVar2 = *puVar14;
      if (((uVar2 != 0) && (uVar2 < 0x1d0)) && ((uVar2 == 200 || (uVar2 == 199)))) {
        if (0x26f < uVar2) {
          func_0019d3f0(0x696f88,0x468);
        }
        iVar13 = *(int *)(param_1 + 0x30);
        lVar7 = func_00300580(*(u32 *)(iVar13 + 0xa2c),0x80274);
        if (lVar7 == 0) {
          lVar7 = func_003005e0(*(u32 *)(iVar13 + 0xa2c),uVar2);
          if (lVar7 == 0) {
            bVar1 = false;
          }
          else {
            lVar7 = func_003086f0(*(u32 *)(iVar13 + 0xa2c),uVar2);
            if (lVar7 == 0) {
              bVar1 = true;
            }
            else {
              bVar1 = false;
            }
          }
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          auStack_10[uVar12] = *puVar14;
          uVar12 = uVar12 + 1 & 0xffff;
        }
      }
    }
  }
  else if (sVar10 == 1) {
    uVar6 = uVar12;
    for (uVar11 = 0; uVar11 < uVar4; uVar11 = uVar11 + 1 & 0xffff) {
      puVar14 = (u16 *)(iVar5 + uVar11 * 2);
      uVar2 = *puVar14;
      if ((uVar2 != 0) && (uVar2 < 0x1d0)) {
        switch(uVar2) {
        case 0xc0:
        case 0xc1:
        case 0xc2:
        case 0xc3:
        case 0xc4:
        case 0xc5:
        case 0xc6:
          if (0x26f < uVar2) {
            func_0019d3f0(0x696f88,0x468);
          }
          iVar13 = *(int *)(param_1 + 0x30);
          lVar7 = func_00300580(*(u32 *)(iVar13 + 0xa2c),0x80274);
          if (lVar7 == 0) {
            lVar7 = func_003005e0(*(u32 *)(iVar13 + 0xa2c),uVar2);
            if (lVar7 == 0) {
              bVar1 = false;
            }
            else {
              lVar7 = func_003086f0(*(u32 *)(iVar13 + 0xa2c),uVar2);
              if (lVar7 == 0) {
                bVar1 = true;
              }
              else {
                bVar1 = false;
              }
            }
          }
          else {
            bVar1 = false;
          }
          if (bVar1) {
            auStack_10[uVar6] = *puVar14;
            uVar6 = uVar6 + 1 & 0xffff;
          }
        }
      }
    }
    uVar12 = 0;
    if (uVar6 != 0) {
      if (param_4 == 1) {
        uVar8 = func_002c4c80(param_1,param_2,auStack_10,uVar6,0);
        if (-1 < (long)uVar8) {
          return uVar8;
        }
        uVar8 = func_002c4c80(param_1,param_2,auStack_10,uVar6,0);
        return uVar8;
      }
      if (param_4 != 0) {
        uVar8 = func_002c4c80(param_1,param_2,auStack_10,uVar6,0xffff);
        return uVar8;
      }
      uVar8 = func_002c4c80(param_1,param_2,auStack_10,uVar6,0);
      if (-1 < (long)uVar8) {
        return uVar8;
      }
      uVar8 = func_002c4c80(param_1,param_2,auStack_10,uVar6,1);
      return uVar8;
    }
  }
  else if (sVar10 == 0) {
    for (uVar6 = 0; uVar6 < uVar4; uVar6 = uVar6 + 1 & 0xffff) {
      puVar14 = (u16 *)(iVar5 + uVar6 * 2);
      uVar2 = *puVar14;
      if (((uVar2 != 0) && (uVar2 < 0x1d0)) && ((uVar2 == 0xcd || (uVar2 == 0xcc)))) {
        if (0x26f < uVar2) {
          func_0019d3f0(0x696f88,0x468);
        }
        iVar13 = *(int *)(param_1 + 0x30);
        lVar7 = func_00300580(*(u32 *)(iVar13 + 0xa2c),0x80274);
        if (lVar7 == 0) {
          lVar7 = func_003005e0(*(u32 *)(iVar13 + 0xa2c),uVar2);
          if (lVar7 == 0) {
            bVar1 = false;
          }
          else {
            lVar7 = func_003086f0(*(u32 *)(iVar13 + 0xa2c),uVar2);
            if (lVar7 == 0) {
              bVar1 = true;
            }
            else {
              bVar1 = false;
            }
          }
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          auStack_10[uVar12] = *puVar14;
          uVar12 = uVar12 + 1 & 0xffff;
        }
      }
    }
  }
  if (uVar12 == 0) {
    uVar8 = 0xffffffffffffffff;
  }
  else {
    iVar5 = func_002ffbc0();
    uVar8 = (u32)auStack_10[iVar5];
  }
  return uVar8;
}

// FUN_002c59d0 NONMATCHING

u32 func_002c59d0(u64 param_1,u64 param_2,u64 param_3,long param_4)

{
  u16 uVar1 = 0;
  u16 uVar2 = 0;
  u16 uVar3 = 0;
  u32 uVar4 = 0;
  int iVar5 = 0;
  long lVar6 = 0;
  short sVar7 = 0;
  u32 uVar8 = 0;
  u32 uVar9 = 0;
  u16 auStack_20 [16] = {0};
  
  uVar8 = 0xffffffffffffffff;
  uVar9 = 0;
  iVar5 = *(int *)((int)param_1 + 0x30);
  if (*(char *)(iVar5 + 0xa2) == '\0') {
    uVar1 = *(u16 *)(*(int *)(iVar5 + 0xa2c) + 2);
    if ((uVar1 == 1) || (10 < uVar1)) {
      uVar8 = 0xffffffffffffffff;
    }
    else {
      iVar5 = (int)param_2;
      lVar6 = func_0030b5a0(*(u32 *)(*(int *)(iVar5 + 0x30) + 0xa2c),0);
      if (lVar6 == 0) {
        uVar2 = *(u16 *)(*(int *)(*(int *)(iVar5 + 0x30) + 0xa2c) + 8);
        uVar4 = func_002ffdf0(*(u32 *)(*(int *)(iVar5 + 0x30) + 0xa2c));
        if ((uVar4 & 0xffff) * 0x3c < (u32)uVar2 * 100) {
          lVar6 = func_00300580(*(u32 *)(*(int *)(iVar5 + 0x30) + 0xa2c),0xfffff);
          if (lVar6 == 0) {
            uVar2 = func_002ffd70(*(u32 *)(*(int *)(iVar5 + 0x30) + 0xa2c));
            uVar3 = func_002ffdf0(*(u32 *)(*(int *)(iVar5 + 0x30) + 0xa2c));
            if (uVar2 < uVar3) {
              uVar8 = 1;
            }
          }
          else {
            uVar8 = 2;
          }
        }
        else {
          uVar8 = 1;
        }
      }
      else {
        uVar8 = 0;
      }
      sVar7 = (short)uVar8;
      if (sVar7 == 2) {
        for (uVar2 = 0; uVar2 < 0xc; uVar2 = uVar2 + 1) {
          uVar3 = func_00170670(uVar1,uVar2);
          if (((4000 < uVar3) && (uVar3 < 0x1080)) && (sVar7 = func_001706c0(uVar1,uVar2), 0 < sVar7)
             ) {
            if (uVar3 == 0xfab) {
              lVar6 = func_00300580(*(u32 *)(*(int *)(iVar5 + 0x30) + 0xa2c),0xe);
              if (lVar6 != 0) {
                auStack_20[uVar9] = 0xfab;
                uVar9 = uVar9 + 1 & 0xffff;
              }
            }
            else if (uVar3 == 0xfb4) {
              lVar6 = func_00300580(*(u32 *)(*(int *)(iVar5 + 0x30) + 0xa2c),1);
              if (lVar6 != 0) {
                auStack_20[uVar9] = 0xfb4;
                uVar9 = uVar9 + 1 & 0xffff;
              }
            }
            else if (uVar3 == 0xfb3) {
              lVar6 = func_00300580(*(u32 *)(*(int *)(iVar5 + 0x30) + 0xa2c),0x10);
              if (lVar6 != 0) {
                auStack_20[uVar9] = 0xfb3;
                uVar9 = uVar9 + 1 & 0xffff;
              }
            }
            else if ((uVar3 == 0xfa8) &&
                    (lVar6 = func_00300580(*(u32 *)(*(int *)(iVar5 + 0x30) + 0xa2c),0x80),
                    lVar6 != 0)) {
              auStack_20[uVar9] = 0xfa8;
              uVar9 = uVar9 + 1 & 0xffff;
            }
          }
        }
      }
      else if (sVar7 == 1) {
        uVar4 = uVar9;
        for (uVar2 = 0; uVar2 < 0xc; uVar2 = uVar2 + 1) {
          uVar3 = func_00170670(uVar1,uVar2);
          if ((((4000 < uVar3) && (uVar3 < 0x1080)) &&
              ((uVar3 == 0xfa3 || ((uVar3 == 0xfa2 || (uVar3 == 0xfa1)))))) &&
             (sVar7 = func_001706c0(uVar1,uVar2), 0 < sVar7)) {
            auStack_20[uVar4] = uVar3;
            uVar4 = uVar4 + 1 & 0xffff;
          }
        }
        uVar9 = 0;
        if (uVar4 != 0) {
          if (param_4 == 1) {
            uVar8 = func_002c4e50(param_1,param_2,auStack_20,uVar4,0);
            if (-1 < (long)uVar8) {
              return uVar8;
            }
            uVar8 = func_002c4e50(param_1,param_2,auStack_20,uVar4,0);
            return uVar8;
          }
          if (param_4 != 0) {
            uVar8 = func_002c4e50(param_1,param_2,auStack_20,uVar4,0xffff);
            return uVar8;
          }
          uVar8 = func_002c4e50(param_1,param_2,auStack_20,uVar4,0);
          if (-1 < (long)uVar8) {
            return uVar8;
          }
          uVar8 = func_002c4e50(param_1,param_2,auStack_20,uVar4,1);
          return uVar8;
        }
      }
      else if (sVar7 == 0) {
        for (uVar2 = 0; uVar2 < 0xc; uVar2 = uVar2 + 1) {
          uVar3 = func_00170670(uVar1,uVar2);
          if (((4000 < uVar3) && (uVar3 < 0x1080)) &&
             (((uVar3 == 0xfaa || (uVar3 == 0xfa9)) &&
              (sVar7 = func_001706c0(uVar1,uVar2), 0 < sVar7)))) {
            auStack_20[uVar9] = uVar3;
            uVar9 = uVar9 + 1 & 0xffff;
          }
        }
      }
      if (uVar9 == 0) {
        uVar8 = 0xffffffffffffffff;
      }
      else {
        iVar5 = func_002ffbc0();
        uVar8 = (u32)auStack_20[iVar5];
      }
    }
  }
  return uVar8;
}

// FUN_002c5fc0 NONMATCHING

long func_002c5fc0(u64 param_1,u64 param_2,short param_3,int param_4)

{
  u16 uVar1 = 0;
  int iVar2 = 0;
  int iVar3 = 0;
  bool bVar4 = 0;
  short sVar5 = 0;
  u32 uVar6 = 0;
  int iVar7 = 0;
  long lVar8 = 0;
  u32 uVar9 = 0;
  u32 uVar10 = 0;
  u16 *puVar11;
  u16 auStack_10 [8] = {0};
  
  if (param_3 == 0x10) {
    lVar8 = func_002c5380(0,0,0,0);
  }
  else {
    uVar9 = 0;
    iVar2 = *(int *)((int)param_1 + 0x30);
    sVar5 = func_003082f0(*(u32 *)(iVar2 + 0xa2c),0);
    if ((sVar5 == param_3) && (lVar8 = func_002c2ed0(param_2,sVar5,1), lVar8 != 0)) {
      auStack_10[0] = 0;
      uVar9 = 1;
    }
    uVar6 = func_00308ba0(*(u32 *)(iVar2 + 0xa2c));
    iVar7 = func_00308bb0(*(u32 *)(iVar2 + 0xa2c));
    for (uVar10 = 0; uVar10 < (uVar6 & 0xffff); uVar10 = uVar10 + 1 & 0xffff) {
      puVar11 = (u16 *)(iVar7 + uVar10 * 2);
      if ((*puVar11 != 0) && (*puVar11 < 0x1d0)) {
        sVar5 = func_003082f0(*(u32 *)(iVar2 + 0xa2c));
        if (sVar5 == param_3) {
          uVar1 = *puVar11;
          if (0x26f < uVar1) {
            func_0019d3f0(0x696f88,0x468);
          }
          iVar3 = *(int *)((int)param_1 + 0x30);
          lVar8 = func_00300580(*(u32 *)(iVar3 + 0xa2c),0x80274);
          if (lVar8 == 0) {
            lVar8 = func_003005e0(*(u32 *)(iVar3 + 0xa2c),uVar1);
            if (lVar8 == 0) {
              bVar4 = false;
            }
            else {
              lVar8 = func_003086f0(*(u32 *)(iVar3 + 0xa2c),uVar1);
              if (lVar8 == 0) {
                bVar4 = true;
              }
              else {
                bVar4 = false;
              }
            }
          }
          else {
            bVar4 = false;
          }
          if ((bVar4) && (lVar8 = func_002c2ed0(param_2,sVar5,1), lVar8 != 0)) {
            auStack_10[uVar9] = *puVar11;
            uVar9 = uVar9 + 1 & 0xffff;
          }
        }
      }
    }
    if (uVar9 == 0) {
      lVar8 = -1;
    }
    else if (param_4 == 1) {
      lVar8 = func_002c48a0(param_1,param_2,auStack_10,uVar9,0);
      if (lVar8 < 0) {
        lVar8 = func_002c48a0(param_1,param_2,auStack_10,uVar9,0);
      }
    }
    else if (param_4 == 0) {
      lVar8 = func_002c48a0(param_1,param_2,auStack_10,uVar9,0);
      if (lVar8 < 0) {
        lVar8 = func_002c48a0(param_1,param_2,auStack_10,uVar9,1);
      }
    }
    else {
      lVar8 = func_002c48a0(param_1,param_2,auStack_10,uVar9,0xffff);
    }
  }
  return lVar8;
}

// FUN_002c6300 NONMATCHING

long func_002c6300(u64 param_1,u64 param_2,u16 param_3,long param_4)

{
  u16 uVar1 = 0;
  int iVar2 = 0;
  u16 uVar3 = 0;
  u16 uVar4 = 0;
  short sVar5 = 0;
  short sVar6 = 0;
  long lVar7 = 0;
  u32 uVar8 = 0;
  u16 uVar9 = 0;
  u16 auStack_20 [16] = {0};
  
  if ((long)((u32)param_3 << 0x30) >> 0x30 == 0x10) {
    lVar7 = func_002c59d0(0,0,0,0);
  }
  else {
    uVar8 = 0;
    iVar2 = *(int *)((int)param_1 + 0x30);
    if (*(char *)(iVar2 + 0xa2) == '\0') {
      uVar1 = *(u16 *)(*(int *)(iVar2 + 0xa2c) + 2);
      if ((uVar1 == 1) || (10 < uVar1)) {
        lVar7 = -1;
      }
      else {
        for (uVar9 = 0; uVar9 < 0xc; uVar9 = uVar9 + 1) {
          uVar3 = func_00170670(uVar1,uVar9);
          if ((4000 < uVar3) && (uVar3 < 0x1080)) {
            uVar4 = func_0030bc20(uVar3);
            if ((uVar4 != 0) && (uVar4 < 0x1d0)) {
              sVar5 = func_003082f0(*(u32 *)(iVar2 + 0xa2c));
              if (((long)sVar5 ==
                   CONCAT44((int)((long)((u32)param_3 << 0x30) >> 0x3f),(int)(short)param_3)) &&
                 (sVar6 = func_001706c0(uVar1,uVar9), 0 < sVar6)) {
                lVar7 = func_002c2ed0(param_2,sVar5,1);
                if (lVar7 != 0) {
                  auStack_20[uVar8] = uVar3;
                  uVar8 = uVar8 + 1 & 0xffff;
                }
              }
            }
          }
        }
        if (uVar8 == 0) {
          lVar7 = -1;
        }
        else if (param_4 == 1) {
          lVar7 = func_002c4a90(param_1,param_2,auStack_20,uVar8,0);
          if (lVar7 < 0) {
            lVar7 = func_002c4a90(param_1,param_2,auStack_20,uVar8,0);
          }
        }
        else if (param_4 == 0) {
          lVar7 = func_002c4a90(param_1,param_2,auStack_20,uVar8,0);
          if (lVar7 < 0) {
            lVar7 = func_002c4a90(param_1,param_2,auStack_20,uVar8,1);
          }
        }
        else {
          lVar7 = func_002c4a90(param_1,param_2,auStack_20,uVar8,0xffff);
        }
      }
    }
    else {
      lVar7 = -1;
    }
  }
  return lVar7;
}

// FUN_002c65d0 NONMATCHING

u32 func_002c65d0(int param_1)

{
  short sVar1 = 0;
  short sVar2 = 0;
  bool bVar3 = 0;
  u16 uVar4 = 0;
  u16 uVar5 = 0;
  u32 uVar6 = 0;
  u32 uVar7 = 0;
  long lVar8 = 0;
  int iVar9 = 0;
  u32 uVar10 = 0;
  u32 uVar11 = 0;
  short *psVar12;
  int iVar13 = 0;
  short asStack_20 [16] = {0};
  
  if (*(short *)(param_1 + 0xc0) == 1) {
    uVar7 = *(u32 *)(param_1 + 0x88);
  }
  else {
    iVar13 = 0;
    for (uVar6 = 0; uVar6 < *(u16 *)(param_1 + 0xc0); uVar6 = uVar6 + 1) {
      iVar13 = iVar13 + *(int *)(&DAT_00696fb0 + uVar6 * 4);
      iVar9 = *(int *)(param_1 + uVar6 * 4 + 0x88);
      psVar12 = asStack_20 + uVar6;
      *psVar12 = 0;
      uVar4 = func_002ffdf0(*(u32 *)(*(int *)(iVar9 + 0x30) + 0xa2c));
      uVar5 = func_002ffd70(*(u32 *)(*(int *)(iVar9 + 0x30) + 0xa2c));
      *psVar12 = *psVar12 + (short)(int)(100.0 - ((float)uVar5 / (float)uVar4) * 100.0);
      lVar8 = func_00300530(*(u32 *)(*(int *)(iVar9 + 0x30) + 0xa2c));
      if (lVar8 == 0x40) {
        *psVar12 = (short)(int)((float)(int)*psVar12 + 20.0);
      }
      else if (lVar8 == 0x20) {
        *psVar12 = (short)(int)((float)(int)*psVar12 + 20.0);
      }
      else if (lVar8 == 0x10) {
        *psVar12 = (short)(int)((float)(int)*psVar12 + 30.0);
      }
      else if (lVar8 == 8) {
        *psVar12 = (short)(int)((float)(int)*psVar12 + 50.0);
      }
      else if (lVar8 == 4) {
        *psVar12 = (short)(int)((float)(int)*psVar12 + 30.0);
      }
      else if (lVar8 == 2) {
        *psVar12 = (short)(int)((float)(int)*psVar12 + 20.0);
      }
    }
    do {
      bVar3 = false;
      for (uVar6 = 0; uVar6 < *(u16 *)(param_1 + 0xc0) - 1; uVar6 = uVar6 + 1) {
        sVar1 = asStack_20[uVar6 + 1];
        sVar2 = asStack_20[uVar6];
        if (sVar2 < sVar1) {
          iVar9 = param_1 + uVar6 * 4;
          uVar7 = *(u32 *)(iVar9 + 0x88);
          *(u32 *)(iVar9 + 0x88) = *(u32 *)(iVar9 + 0x8c);
          *(u32 *)(iVar9 + 0x8c) = uVar7;
          asStack_20[uVar6] = sVar1;
          asStack_20[uVar6 + 1] = sVar2;
          bVar3 = true;
        }
      }
    } while (bVar3);
    uVar11 = 0;
    uVar6 = func_002ffbc0(iVar13);
    for (uVar10 = 0; uVar10 < *(u16 *)(param_1 + 0xc0); uVar10 = uVar10 + 1) {
      uVar11 = uVar11 + *(int *)(&DAT_00696fb0 + uVar10 * 4);
      if (uVar6 < uVar11) {
        return *(u32 *)(uVar10 * 4 + param_1 + 0x88);
      }
    }
    uVar7 = 0;
  }
  return uVar7;
}

// FUN_002c6a00 NONMATCHING

void func_002c6a00(int param_1,int param_2,u16 param_3)

{
  u16 uVar1 = 0;
  u16 uVar2 = 0;
  
  uVar2 = param_3 & 0xf000;
  if (uVar2 == 0x8000) {
    uVar2 = param_3;
  }
  if (uVar2 == 0x8004) {
    param_3 = func_00308a80(*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c));
LAB_002c6b78:
    *(u16 *)(param_2 + 0x34) = 2;
    *(u16 *)(param_2 + 0x36) = param_3;
  }
  else {
    if (uVar2 == 0x8008) {
      *(u16 *)(param_2 + 0x34) = 0xc;
      return;
    }
    if (uVar2 == 0x8001) {
      *(u16 *)(param_2 + 0x34) = 6;
      return;
    }
    if (uVar2 == 0x8006) {
      *(u16 *)(param_2 + 0x34) = 0xb;
      return;
    }
    if (uVar2 == 0x8005) {
      return;
    }
    if (uVar2 == 0x8007) {
      *(u16 *)(param_2 + 0x34) = 8;
      return;
    }
    if (uVar2 != 0x8002) {
      if (uVar2 != 0x2000) {
        if (uVar2 == 0x1000) {
          *(u16 *)(param_2 + 0x34) = 9;
          *(u16 *)(param_2 + 0x36) = 0x155;
          *(u16 *)(param_2 + 0x3e) = param_3 & 0xfff;
          return;
        }
        if (uVar2 == 0x8000) {
          *(u16 *)(param_2 + 0x34) = 1;
          uVar1 = func_00308930(*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c));
          *(u16 *)(param_2 + 0x36) = uVar1;
          return;
        }
        goto LAB_002c6b78;
      }
      *(u16 *)(param_1 + 0xdc) = param_3 & 0xfff;
    }
    *(u16 *)(param_2 + 0x34) = 7;
  }
  return;
}

// FUN_002c6ba0 NONMATCHING

char func_002c6ba0(u64 param_1)

{
  u16 uVar1 = 0;
  u32 uVar2 = 0;
  int iVar3 = 0;
  int iVar4 = 0;
  u32 uVar5 = 0;
  int iVar6 = 0;
  u32 uVar7 = 0;
  u32 uVar8 = 0;
  int aiStack_10 [4] = {0};
  
  uVar1 = *(u16 *)(*(int *)((int)param_1 + 0x30) + 0xa4);
  iVar6 = (int)(DAT_007ce41c + ((u32)uVar1 * 0x28 + (u32)uVar1) * 4);
  uVar8 = 0;
  while( true ) {
    if (1 < uVar8) {
      return '\0';
    }
    iVar3 = iVar6 + uVar8 * 0x14;
    for (uVar7 = 0; uVar7 < 3; uVar7 = uVar7 + 1 & 0xffff) {
      uVar2 = *(u32 *)(iVar3 + 4 + uVar7 * 4);
      uVar5 = uVar2 >> 0x18;
      if (uVar5 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = (**(code **)(&DAT_006971b0 + uVar5 * 0xc))(param_1,uVar2 & 0xffffff);
      }
      aiStack_10[uVar7] = iVar4;
    }
    if ((((aiStack_10[0] != 0) && (aiStack_10[1] != 0)) && (aiStack_10[2] != 0)) &&
       (*(char *)(iVar3 + 0x10) != '\b')) {
      return *(char *)(iVar3 + 0x10);
    }
    if (((aiStack_10[0] != 0) && (aiStack_10[1] != 0)) && (*(char *)(iVar3 + 0x11) != '\b')) {
      return *(char *)(iVar3 + 0x11);
    }
    if (((aiStack_10[0] != 0) && (aiStack_10[2] != 0)) && (*(char *)(iVar3 + 0x12) != '\b')) break;
    if (((aiStack_10[1] != 0) && (aiStack_10[2] != 0)) && (*(char *)(iVar3 + 0x13) != '\b')) {
      return *(char *)(iVar3 + 0x13);
    }
    if ((aiStack_10[0] != 0) && (*(char *)(iVar3 + 0x14) != '\b')) {
      return *(char *)(iVar3 + 0x14);
    }
    if ((aiStack_10[1] != 0) && (*(char *)(iVar3 + 0x15) != '\b')) {
      return *(char *)(iVar3 + 0x15);
    }
    if ((aiStack_10[2] != 0) && (*(char *)(iVar3 + 0x16) != '\b')) {
      return *(char *)(iVar3 + 0x16);
    }
    if (*(char *)(iVar3 + 0x17) != '\b') {
      return *(char *)(iVar3 + 0x17);
    }
    uVar8 = uVar8 + 1 & 0xffff;
  }
  return *(char *)(iVar3 + 0x12);
}

// FUN_002c6e30 NONMATCHING

undefined * func_002c6e30(int param_1,u32 param_2)

{
  u8 bVar1 = 0;
  short sVar2 = 0;
  u16 uVar3 = 0;
  undefined *puVar4;
  int iVar5 = 0;
  u32 uVar6 = 0;
  u16 uVar7 = 0;
  int iVar8 = 0;
  
  uVar3 = *(u16 *)(*(int *)(param_1 + 0x30) + 0xa4);
  sVar2 = 0;
  iVar8 = (int)(DAT_007ce41c + ((u32)uVar3 * 0x28 + (u32)uVar3) * 4 + (param_2 & 0xffff) * 0x28);
  for (uVar6 = 0; uVar6 < 5; uVar6 = uVar6 + 1 & 0xffff) {
    sVar2 = sVar2 + (u16)*(u8 *)(iVar8 + uVar6 * 8 + 0x2c);
  }
  if (sVar2 == 0) {
    puVar4 = &DAT_007cc740;
  }
  else {
    uVar3 = func_002ffbc0();
    uVar7 = 0;
    for (uVar6 = 0; uVar6 < 5; uVar6 = uVar6 + 1 & 0xffff) {
      iVar5 = iVar8 + uVar6 * 8;
      bVar1 = *(u8 *)(iVar5 + 0x2c);
      uVar7 = uVar7 + bVar1;
      if ((uVar3 <= uVar7) && (bVar1 != 0)) {
        return (undefined *)(iVar5 + 0x2c);
      }
    }
    puVar4 = (undefined *)0x0;
  }
  return puVar4;
}

// FUN_002c6f50 NONMATCHING

u32 func_002c6f50(u64 param_1,int param_2,u64 param_3,u64 param_4)

{
  int iVar1 = 0;
  int iVar2 = 0;
  u64 uVar3 = 0;
  int unaff_s3_lo = 0;
  u8 auStack_20 [32] = {0};
  
  iVar2 = *(int *)((int)param_1 + 0x30);
  if (*(char *)(iVar2 + 0xa2) == '\0') {
    func_00523ac8(auStack_20,0x697710,param_4,*(u8 *)(*(int *)(iVar2 + 0xa2c) + 0x10));
    param_4 = func_0035c090(param_3,auStack_20);
  }
  uVar3 = func_0035bb40(*(int *)(*(int *)(DAT_007ce3ec + 0xd18) + 0x20) + -1,param_3,param_4);
  func_0035c1a0(uVar3,param_1);
  iVar2 = func_0035ae10(uVar3);
  if (-1 < *(int *)(iVar2 + 0xcc)) {
    iVar1 = *(int *)((int)param_1 + 0x30);
    if (*(char *)(iVar1 + 0xa2) == '\x01') {
      unaff_s3_lo = (int)(DAT_007ce4e8) +
                    (u32)*(u16 *)(iVar1 + 0xa4) * 0x12 + (u32)*(u16 *)(iVar1 + 0xa4);
    }
    else if (*(char *)(iVar1 + 0xa2) == '\0') {
      unaff_s3_lo = func_001778b0(*(u16 *)(iVar1 + 0xa4));
    }
    func_003a4220(*(u32 *)(iVar2 + 0xcc),0,unaff_s3_lo);
  }
  func_00195550(*(u32 *)(DAT_007ce3ec + 0xd18),uVar3);
  *(int *)(param_2 + 0x4c) = (int)uVar3;
  return 1;
}

// FUN_002c70d0 NONMATCHING

void func_002c70d0(u64 param_1,u64 param_2)

{
  char cVar1 = 0;
  u16 uVar2 = 0;
  int iVar3 = 0;
  long lVar4 = 0;
  u32 unaff_s1_lo = 0;
  u32 uVar5 = 0;
  u16 unaff_s2_lo = 0;
  u16 uVar6 = 0;
  
  uVar6 = *(u16 *)(*(int *)((int)param_1 + 0x30) + 0xa4);
  func_002d15a0(param_2);
  cVar1 = *(char *)(*(int *)((int)param_1 + 0x30) + 0xa2);
  if (cVar1 == '\x01') {
    uVar6 = *(u16 *)(((u32)uVar6 * 0x28 + (u32)uVar6) * 4 + DAT_007ce41c + 2);
    uVar5 = (u32)DAT_007ce4d0;
  }
  else {
    uVar5 = (u32)DAT_007ce4cc;
    if (cVar1 != '\0') {
      uVar5 = unaff_s1_lo;
      uVar6 = unaff_s2_lo;
    }
  }
  if (uVar6 == 0) {
    uVar2 = func_002c6ba0(param_1);
    iVar3 = (int)func_002c6e30(param_1,uVar2);
    func_002c6a00(param_1,param_2,*(u16 *)(iVar3 + 2));
    lVar4 = (*(PTR_FUN_006975e0)[(*(u32 *)(iVar3 + 4) >> 0x18) * 2])
                      (param_1,*(u32 *)(iVar3 + 4) & 0xffffff);
    if (lVar4 == 0) {
      (*(code *)PTR_FUN_006975e0)(param_1,0);
    }
  }
  else {
    func_002c6f50(param_1,param_2,uVar5,0);
    *(u8 *)((int)param_2 + 0x30) = 1;
  }
  return;
}

// FUN_002c7250

bool func_002c7250(int param_1)

{
  if (*(u8 *)(param_1 + 0x30) != 0) {
    return true;
  }
  return *(int *)(param_1 + 0x4c) != 0;
}

// FUN_002c7280

u32 func_002c7280(int param_1)

{
  u32 uVar1 = 0;
  long lVar2 = 0;
  
  if (*(u8 *)(param_1 + 0x30) == 0) {
    uVar1 = 1;
  }
  else if (*(int *)(param_1 + 0x4c) == 0) {
    uVar1 = 1;
  }
  else {
    lVar2 = func_00195460(*(int *)(param_1 + 0x4c));
    if (lVar2 == 0) {
      *(u8 *)(param_1 + 0x30) = 0;
      *(u32 *)(param_1 + 0x4c) = 0;
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

// FUN_002c7300

u32 func_002c7300(void)

{
  extern u32 func_0035f160(void);
  extern void func_002c6a00(void *,void *,u16);
  char *pVar1 = (char *)func_0035f160();

  func_002c6a00(pVar1,pVar1 + 0x38,0x8000);
  return 1;
}

// FUN_002c7340

u32 func_002c7340(void)

{
  extern void *func_0035f160(void);
  extern s32 func_0035ed20(u32);
  extern void func_002c6a00(void *,void *,u16);
  char *state;
  s32 selection;

  state = (char *)func_0035f160();
  selection = func_0035ed20(0);
  if (selection == 0) {
    func_002c6a00(state,state + 0x38,0x8000);
  }
  else if (selection > 0) {
    func_002c6a00(state,state + 0x38,(u16)selection);
  }
  else {
    func_002c6a00(state,state + 0x38,0x8002);
  }
  return 1;
}

// FUN_002c73e0

u32 func_002c73e0(void)

{
  extern void *func_0035f160(void);
  extern s32 func_0035ed20(u32);
  extern void func_002c6a00(void *,void *,u16);
  char *state;
  s32 selection;
  u16 selectedIndex;

  state = (char *)func_0035f160();
  selection = func_0035ed20(0);
  if (selection >= 0) {
    *(u16 *)(state + 0x6c) = 3;
    *(s16 *)(state + 0x70) = (selectedIndex = (u16)selection, selection);
    *(u16 *)(state + 0x6e) = func_0030bc20(selectedIndex);
  }
  else {
    func_002c6a00(state,state + 0x38,0x8002);
  }
  return 1;
}

// FUN_002c7460

u32 func_002c7460(void)

{
  extern u32 func_0035f160(void);
  extern void func_002c6a00(void *,void *,u16);
  char *pVar1 = 0;
  
  pVar1 = (char *)func_0035f160();
  func_002c6a00(pVar1,pVar1 + 0x38,0x8001);
  return 1;
}

// FUN_002c74a0

u32 func_002c74a0(void)

{
  extern u32 func_0035f160(void);
  extern void func_002c6a00(void *,void *,u16);
  char *pVar1 = 0;
  
  pVar1 = (char *)func_0035f160();
  func_002c6a00(pVar1,pVar1 + 0x38,0x8002);
  return 1;
}

// FUN_002c74e0

u32 func_002c74e0(void)

{
  extern u32 func_0035f160(void);
  extern void func_002c6a00(void *,void *,u16);
  char *pVar1 = (char *)func_0035f160();
  u16 uVar1 = func_0035ed20(0);

  *(u16 *)(pVar1 + 0xdc) = uVar1;
  func_002c6a00(pVar1,pVar1 + 0x38,0x8002);
  return 1;
}

// FUN_002c7540

u32 func_002c7540(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  char *unit;
  s32 result;

  unit = (char *)func_0035f160();
  *(u16 *)(unit + 0x6c) = 9;
  *(u16 *)(unit + 0x6e) = 0x155;
  *(u16 *)(unit + 0x76) = func_0035ed20(0);
  result = (*(s32 (**)(void *,u32))PTR_FUN_00697620)(unit,0);
  if (result == 0) {
    (*(s32 (**)(void *,u32))PTR_FUN_006975e0)(unit,0);
  }
  return 1;
}

// FUN_002c75d0

u32 func_002c75d0(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  char *unit;
  s32 result;

  unit = (char *)func_0035f160();
  *(u16 *)(unit + 0x6c) = 9;
  *(u16 *)(unit + 0x6e) = 0x155;
  *(u16 *)(unit + 0x76) = func_0035ed20(0);
  *(u16 *)(unit + 0x78) = func_0035ed20(1);
  result = (*(s32 (**)(void *,u32))PTR_FUN_00697620)(unit,0);
  if (result == 0) {
    (*(s32 (**)(void *,u32))PTR_FUN_006975e0)(unit,0);
  }
  return 1;
}

// FUN_002c7670

u32 func_002c7670(void)

{
  extern u32 func_0035f160(void);
  extern void func_002c6a00(void *,void *,u16);
  char *pVar1 = 0;
  
  pVar1 = (char *)func_0035f160();
  func_002c6a00(pVar1,pVar1 + 0x38,0x8007);
  return 1;
}

// FUN_002c76b0

u32 func_002c76b0(void)
{
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x1000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c7760

u32 func_002c7760(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x2000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c7810

u32 func_002c7810(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x03000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c78c0

u32 func_002c78c0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x04000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c7970

u32 func_002c7970(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x05000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c7a20

u32 func_002c7a20(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x06000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c7ad0

u32 func_002c7ad0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x07000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c7b80

u32 func_002c7b80(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x08000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c7c30

u32 func_002c7c30(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x09000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c7ce0

u32 func_002c7ce0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x0a000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c7d90

u32 func_002c7d90(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x0b000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c7e40

u32 func_002c7e40(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x0c000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c7ef0

u32 func_002c7ef0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x0d000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c7fa0

u32 func_002c7fa0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x0e000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c8050

u32 func_002c8050(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x0f000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c8100

u32 func_002c8100(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x10000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c81b0

u32 func_002c81b0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x11000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c8260

u32 func_002c8260(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x12000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c8310

u32 func_002c8310(void)

{
  u64 uVar1 = 0;
  u32 lVar2 = 0;
  
  uVar1 = func_0035f160();
  lVar2 = (*(code *)PTR_FUN_00697294)(uVar1,0);
  func_0035f060(lVar2 != 0);
  return 1;
}

// FUN_002c8360

u32 func_002c8360(void)

{
  u64 uVar1 = 0;
  u32 lVar2 = 0;
  
  uVar1 = func_0035f160();
  lVar2 = (*(code *)PTR_FUN_006972a0)(uVar1,0);
  func_0035f060(lVar2 != 0);
  return 1;
}

// FUN_002c83b0

u32 func_002c83b0(void)

{
  u64 uVar1 = 0;
  u32 lVar2 = 0;
  
  uVar1 = func_0035f160();
  lVar2 = (*(code *)PTR_FUN_006972ac)(uVar1,0);
  func_0035f060(lVar2 != 0);
  return 1;
}

// FUN_002c8400

u32 func_002c8400(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x16000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c84b0

u32 func_002c84b0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x17000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c8560

u32 func_002c8560(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x18000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c8610

u32 func_002c8610(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x19000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c86c0

u32 func_002c86c0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x1a000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c8770

u32 func_002c8770(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x1b000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c8820

u32 func_002c8820(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x1c000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c88d0

u32 func_002c88d0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x1d000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c8980

u32 func_002c8980(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x1e000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c8a30

u32 func_002c8a30(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x1f000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c8ae0

u32 func_002c8ae0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x20000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c8b90

u32 func_002c8b90(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x21000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c8c40

u32 func_002c8c40(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x22000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c8cf0

u32 func_002c8cf0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x23000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c8da0

u32 func_002c8da0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x24000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c8e50

u32 func_002c8e50(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x25000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c8f00

u32 func_002c8f00(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x26000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c8fb0

u32 func_002c8fb0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x27000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c9060

u32 func_002c9060(void)

{
  u64 uVar1 = 0;
  u32 lVar2 = 0;
  
  uVar1 = func_0035f160();
  lVar2 = (*(code *)PTR_FUN_00697390)(uVar1,0);
  func_0035f060(lVar2 != 0);
  return 1;
}

// FUN_002c90b0

u32 func_002c90b0(void)

{
  u64 uVar1 = 0;
  u32 lVar2 = 0;
  
  uVar1 = func_0035f160();
  lVar2 = (*(code *)PTR_FUN_0069739c)(uVar1,0);
  func_0035f060(lVar2 != 0);
  return 1;
}

// FUN_002c9100

u32 func_002c9100(void)

{
  u64 uVar1 = 0;
  u32 lVar2 = 0;
  
  uVar1 = func_0035f160();
  lVar2 = (*(code *)PTR_FUN_006973a8)(uVar1,0);
  func_0035f060(lVar2 != 0);
  return 1;
}

// FUN_002c9150

u32 func_002c9150(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x2b000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c9200

u32 func_002c9200(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x2c000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c92b0

u32 func_002c92b0(void)

{
  u64 uVar1 = 0;
  u32 lVar2 = 0;
  
  uVar1 = func_0035f160();
  lVar2 = (*(code *)PTR_FUN_006973cc)(uVar1,0);
  func_0035f060(lVar2 != 0);
  return 1;
}

// FUN_002c9300

u32 func_002c9300(void)

{
  u64 uVar1 = 0;
  u32 lVar2 = 0;
  
  uVar1 = func_0035f160();
  lVar2 = (*(code *)PTR_FUN_006973d8)(uVar1,0);
  func_0035f060(lVar2 != 0);
  return 1;
}

// FUN_002c9350

u32 func_002c9350(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x2f000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c9400

u32 func_002c9400(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x30000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c94b0

u32 func_002c94b0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x31000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c9560

u32 func_002c9560(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x32000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c9610

u32 func_002c9610(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x33000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c96c0

u32 func_002c96c0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x34000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c9770

u32 func_002c9770(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x35000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c9820

u32 func_002c9820(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x36000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c98d0

u32 func_002c98d0(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern int func_002c0e30(u16,u32,u32);
  u32 unit;
  u16 id;
  int context;
  u32 selector;
  u32 dispatchType;
  u32 payload;
  int result;
  int dispatchResult;

  unit = func_0035f160();
  id = func_0035ed20(0);
  context = func_002c0e30(id,
      1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff,
      0x80000);
  if (context != 0) {
    selector = (func_0035ed20(1) & 0xffffff) | 0x01000000;
    dispatchType = (selector & 0xff000000) >> 24;
    payload = selector & 0xffffff;
    if (dispatchType == 0) {
      dispatchResult = 0;
    }
    else {
      dispatchResult = gFormationDispatchTable[dispatchType * 3](context,payload);
    }
    result = dispatchResult;
  }
  else {
    result = 0;
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c99c0

u32 func_002c99c0(void) {
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern int func_002c0e30(u16,u32,u32);
  u32 unit;
  u16 id;
  int context;
  u32 selector;
  u32 dispatchType;
  u32 payload;
  int result;
  int dispatchResult;

  unit = func_0035f160();
  id = func_0035ed20(0);
  context = func_002c0e30(id,
      1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff,
      0x80000);
  if (context != 0) {
    selector = (func_0035ed20(1) & 0xffffff) | 0x02000000;
    dispatchType = (selector & 0xff000000) >> 24;
    payload = selector & 0xffffff;
    if (dispatchType == 0) {
      dispatchResult = 0;
    }
    else {
      dispatchResult = gFormationDispatchTable[dispatchType * 3](context,payload);
    }
    result = dispatchResult;
  }
  else {
    result = 0;
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c9ab0

u32 func_002c9ab0(void) {
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern int func_002c0e30(u16,u32,u32);
  u32 unit;
  u16 id;
  int context;
  u32 selector;
  u32 dispatchType;
  u32 payload;
  int result;
  int dispatchResult;

  unit = func_0035f160();
  id = func_0035ed20(0);
  context = func_002c0e30(id,
      1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff,
      0x80000);
  if (context != 0) {
    selector = (func_0035ed20(1) & 0xffffff) | 0x06000000;
    dispatchType = (selector & 0xff000000) >> 24;
    payload = selector & 0xffffff;
    if (dispatchType == 0) {
      dispatchResult = 0;
    }
    else {
      dispatchResult = gFormationDispatchTable[dispatchType * 3](context,payload);
    }
    result = dispatchResult;
  }
  else {
    result = 0;
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c9ba0 MATCHING

u32 func_002c9ba0(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern int func_002c0e30(u16,u32,u32);
  extern void func_0035f060(u32);
  u16 id;
  u32 unit;
  u32 argument;
  u32 sideMask;
  int context;
  u32 dispatchType;
  u32 payload;
  int result;
  int dispatchResult;
  
  argument = func_0035ed20(1);
  unit = func_0035f160();
  sideMask = 1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff;
  if ((argument & 0x80000) != 0) {
    id = func_0035ed20(0);
    context = func_002c0e30(id, sideMask, 0);
  }
  else {
    id = func_0035ed20(0);
    context = func_002c0e30(id, sideMask, 0x80000);
  }
  if (context != 0) {
    dispatchType = (((argument & 0xffffff) | 0x0b000000) & 0xff000000) >> 24;
    payload = (argument | 0x0b000000) & 0xffffff;
    if (dispatchType == 0) {
      dispatchResult = 0;
    }
    else {
      dispatchResult = gFormationDispatchTable[dispatchType * 3](context, payload);
    }
    result = dispatchResult;
  }
  else {
    result = 0;
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c9ce0 MATCHING

u32 func_002c9ce0(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern int func_002c0e30(u16,u32,u32);
  extern int func_00301ca0(u32,u32);
  extern void func_0035f060(u32);
  u32 unit;
  u16 id;
  int context;
  u32 argument;
  int result;
  
  unit = func_0035f160();
  id = func_0035ed20(0);
  context = func_002c0e30(id,
      1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff,
      0x80000);
  if (context != 0) {
    argument = func_0035ed20(1);
    result = func_00301ca0(*(u32 *)(*(int *)(context + 0x30) + 0xa2c), argument);
    if (result != 0) {
      result = 1;
    }
    else {
      result = 0;
    }
  }
  else {
    result = 0;
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c9da0

u32 func_002c9da0(void) {
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern int func_002c0e30(u16,u32,u32);
  u32 unit;
  u16 id;
  int context;
  u32 selector;
  u32 dispatchType;
  u32 payload;
  int result;
  int dispatchResult;

  unit = func_0035f160();
  id = func_0035ed20(0);
  context = func_002c0e30(id,
      1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff,
      0x80000);
  if (context != 0) {
    selector = (func_0035ed20(1) & 0xffffff) | 0x16000000;
    dispatchType = (selector & 0xff000000) >> 24;
    payload = selector & 0xffffff;
    if (dispatchType == 0) {
      dispatchResult = 0;
    }
    else {
      dispatchResult = gFormationDispatchTable[dispatchType * 3](context,payload);
    }
    result = dispatchResult;
  }
  else {
    result = 0;
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c9e90

u32 func_002c9e90(void) {
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern int func_002c0e30(u16,u32,u32);
  u32 unit;
  u16 id;
  int context;
  u32 selector;
  u32 dispatchType;
  u32 payload;
  int result;
  int dispatchResult;

  unit = func_0035f160();
  id = func_0035ed20(0);
  context = func_002c0e30(id,
      1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff,
      0x80000);
  if (context != 0) {
    selector = (func_0035ed20(1) & 0xffffff) | 0x17000000;
    dispatchType = (selector & 0xff000000) >> 24;
    payload = selector & 0xffffff;
    if (dispatchType == 0) {
      dispatchResult = 0;
    }
    else {
      dispatchResult = gFormationDispatchTable[dispatchType * 3](context,payload);
    }
    result = dispatchResult;
  }
  else {
    result = 0;
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002c9f80

u32 func_002c9f80(void) {
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern int func_002c0e30(u16,u32,u32);
  u32 unit;
  u16 id;
  int context;
  u32 selector;
  u32 dispatchType;
  u32 payload;
  int result;
  int dispatchResult;

  unit = func_0035f160();
  id = func_0035ed20(0);
  context = func_002c0e30(id,
      1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff,
      0x80000);
  if (context != 0) {
    selector = (func_0035ed20(1) & 0xffffff) | 0x18000000;
    dispatchType = (selector & 0xff000000) >> 24;
    payload = selector & 0xffffff;
    if (dispatchType == 0) {
      dispatchResult = 0;
    }
    else {
      dispatchResult = gFormationDispatchTable[dispatchType * 3](context,payload);
    }
    result = dispatchResult;
  }
  else {
    result = 0;
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002ca070

u32 func_002ca070(void) {
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern int func_002c0e30(u16,u32,u32);
  u32 unit;
  u16 id;
  int context;
  u32 selector;
  u32 dispatchType;
  u32 payload;
  int result;
  int dispatchResult;

  unit = func_0035f160();
  id = func_0035ed20(0);
  context = func_002c0e30(id,
      1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff,
      0x80000);
  if (context != 0) {
    selector = (func_0035ed20(1) & 0xffffff) | 0x19000000;
    dispatchType = (selector & 0xff000000) >> 24;
    payload = selector & 0xffffff;
    if (dispatchType == 0) {
      dispatchResult = 0;
    }
    else {
      dispatchResult = gFormationDispatchTable[dispatchType * 3](context,payload);
    }
    result = dispatchResult;
  }
  else {
    result = 0;
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002ca160

u32 func_002ca160(void) {
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern int func_002c0e30(u16,u32,u32);
  u32 unit;
  u16 id;
  int context;
  u32 selector;
  u32 dispatchType;
  u32 payload;
  int result;
  int dispatchResult;

  unit = func_0035f160();
  id = func_0035ed20(0);
  context = func_002c0e30(id,
      1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff,
      0x80000);
  if (context != 0) {
    selector = (func_0035ed20(1) & 0xffffff) | 0x22000000;
    dispatchType = (selector & 0xff000000) >> 24;
    payload = selector & 0xffffff;
    if (dispatchType == 0) {
      dispatchResult = 0;
    }
    else {
      dispatchResult = gFormationDispatchTable[dispatchType * 3](context,payload);
    }
    result = dispatchResult;
  }
  else {
    result = 0;
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002ca250

u32 func_002ca250(void) {
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern int func_002c0e30(u16,u32,u32);
  u32 unit;
  u16 id;
  int context;
  u32 selector;
  u32 dispatchType;
  u32 payload;
  int result;
  int dispatchResult;

  unit = func_0035f160();
  id = func_0035ed20(0);
  context = func_002c0e30(id,
      1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff,
      0x80000);
  if (context != 0) {
    selector = (func_0035ed20(1) & 0xffffff) | 0x25000000;
    dispatchType = (selector & 0xff000000) >> 24;
    payload = selector & 0xffffff;
    if (dispatchType == 0) {
      dispatchResult = 0;
    }
    else {
      dispatchResult = gFormationDispatchTable[dispatchType * 3](context,payload);
    }
    result = dispatchResult;
  }
  else {
    result = 0;
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002ca340

u32 func_002ca340(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern int func_002c0e30(u16,u32,u32);
  u32 unit;
  u16 id;
  int context;
  int result;

  unit = func_0035f160();
  id = func_0035ed20(0);
  context = func_002c0e30(id,
      1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff,
      0x80000);
  if (context != 0) {
    result = (*(int (**)(int,u32))PTR_FUN_00697390)(context,0);
  }
  else {
    result = 0;
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002ca3e0

u32 func_002ca3e0(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern int func_002c0e30(u16,u32,u32);
  u32 unit;
  u16 id;
  int context;
  int result;

  unit = func_0035f160();
  id = func_0035ed20(0);
  context = func_002c0e30(id,
      1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff,
      0x80000);
  if (context != 0) {
    result = (*(int (**)(int,u32))PTR_FUN_006973cc)(context,0);
  }
  else {
    result = 0;
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002ca480 NONMATCHING

u32 func_002ca480(void)

{
  char cVar1 = 0;
  u16 uVar2 = 0;
  int iVar3 = 0;
  long lVar4 = 0;
  u32 uVar5 = 0;
  
  iVar3 = func_0035f160();
  cVar1 = *(char *)(*(int *)(iVar3 + 0x30) + 0xa2);
  uVar2 = func_0035ed20(0);
  lVar4 = func_002c0e30(uVar2,1 << (u32)(cVar1 == '\0') & 0xffff,0x80000);
  if (lVar4 == 0) {
    lVar4 = 0;
  }
  else {
    uVar5 = func_0035ed20(1);
    lVar4 = (*pcRam006971bc)(lVar4,uVar5 & 0xffffff);
  }
  func_0035f060(lVar4 != 0);
  return 1;
}

// FUN_002ca590 NONMATCHING

u32 func_002ca590(void)

{
  char cVar1 = 0;
  u16 uVar2 = 0;
  int iVar3 = 0;
  long lVar4 = 0;
  u32 uVar5 = 0;
  
  iVar3 = func_0035f160();
  cVar1 = *(char *)(*(int *)(iVar3 + 0x30) + 0xa2);
  uVar2 = func_0035ed20(0);
  lVar4 = func_002c0e30(uVar2,1 << (u32)(cVar1 == '\0') & 0xffff,0x80000);
  if (lVar4 == 0) {
    lVar4 = 0;
  }
  else {
    uVar5 = func_0035ed20(1);
    lVar4 = (*pcRam006971c8)(lVar4,uVar5 & 0xffffff);
  }
  func_0035f060(lVar4 != 0);
  return 1;
}

// FUN_002ca6a0 NONMATCHING

u32 func_002ca6a0(void)

{
  char cVar1 = 0;
  u16 uVar2 = 0;
  int iVar3 = 0;
  long lVar4 = 0;
  u32 uVar5 = 0;
  
  iVar3 = func_0035f160();
  cVar1 = *(char *)(*(int *)(iVar3 + 0x30) + 0xa2);
  uVar2 = func_0035ed20(0);
  lVar4 = func_002c0e30(uVar2,1 << (u32)(cVar1 == '\0') & 0xffff,0x80000);
  if (lVar4 == 0) {
    lVar4 = 0;
  }
  else {
    uVar5 = func_0035ed20(1);
    lVar4 = (*pcRam006971f8)(lVar4,uVar5 & 0xffffff);
  }
  func_0035f060(lVar4 != 0);
  return 1;
}

// FUN_002ca7b0 NONMATCHING

u32 func_002ca7b0(void)

{
  u16 uVar1 = 0;
  int iVar2 = 0;
  u32 uVar3 = 0;
  long lVar4 = 0;
  u32 uVar5 = 0;
  
  uVar3 = func_0035ed20(1);
  iVar2 = func_0035f160();
  uVar5 = 1 << (u32)(*(char *)(*(int *)(iVar2 + 0x30) + 0xa2) == '\0') & 0xffff;
  if ((uVar3 & 0x80000) == 0) {
    uVar1 = func_0035ed20(0);
    lVar4 = func_002c0e30(uVar1,uVar5,0x80000);
  }
  else {
    uVar1 = func_0035ed20(0);
    lVar4 = func_002c0e30(uVar1,uVar5,0);
  }
  if (lVar4 == 0) {
    lVar4 = 0;
  }
  else {
    lVar4 = (*pcRam00697234)(lVar4,uVar3 & 0xffffff);
  }
  func_0035f060(lVar4 != 0);
  return 1;
}

// FUN_002ca900 NONMATCHING

u32 func_002ca900(void)

{
  char cVar1 = 0;
  u8 uVar2 = 0;
  u16 uVar3 = 0;
  int iVar4 = 0;
  long lVar5 = 0;
  u64 uVar6 = 0;
  
  iVar4 = func_0035f160();
  cVar1 = *(char *)(*(int *)(iVar4 + 0x30) + 0xa2);
  uVar3 = func_0035ed20(0);
  lVar5 = func_002c0e30(uVar3,1 << (u32)(cVar1 == '\0') & 0xffff,0x80000);
  if (lVar5 == 0) {
    uVar2 = 0;
  }
  else {
    uVar6 = func_0035ed20(1);
    lVar5 = func_00301ca0(*(u32 *)(*(int *)((int)lVar5 + 0x30) + 0xa2c),uVar6);
    if (lVar5 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  func_0035f060(uVar2);
  return 1;
}

// FUN_002ca9d0 NONMATCHING

u32 func_002ca9d0(void)

{
  char cVar1 = 0;
  u16 uVar2 = 0;
  int iVar3 = 0;
  long lVar4 = 0;
  u32 uVar5 = 0;
  
  iVar3 = func_0035f160();
  cVar1 = *(char *)(*(int *)(iVar3 + 0x30) + 0xa2);
  uVar2 = func_0035ed20(0);
  lVar4 = func_002c0e30(uVar2,1 << (u32)(cVar1 == '\0') & 0xffff,0x80000);
  if (lVar4 == 0) {
    lVar4 = 0;
  }
  else {
    uVar5 = func_0035ed20(1);
    lVar4 = (*pcRam006972b8)(lVar4,uVar5 & 0xffffff);
  }
  func_0035f060(lVar4 != 0);
  return 1;
}

// FUN_002caae0 NONMATCHING

u32 func_002caae0(void)

{
  char cVar1 = 0;
  u16 uVar2 = 0;
  int iVar3 = 0;
  long lVar4 = 0;
  u32 uVar5 = 0;
  
  iVar3 = func_0035f160();
  cVar1 = *(char *)(*(int *)(iVar3 + 0x30) + 0xa2);
  uVar2 = func_0035ed20(0);
  lVar4 = func_002c0e30(uVar2,1 << (u32)(cVar1 == '\0') & 0xffff,0x80000);
  if (lVar4 == 0) {
    lVar4 = 0;
  }
  else {
    uVar5 = func_0035ed20(1);
    lVar4 = (*pcRam006972c4)(lVar4,uVar5 & 0xffffff);
  }
  func_0035f060(lVar4 != 0);
  return 1;
}

// FUN_002cabf0 NONMATCHING

u32 func_002cabf0(void)

{
  char cVar1 = 0;
  u16 uVar2 = 0;
  int iVar3 = 0;
  long lVar4 = 0;
  u32 uVar5 = 0;
  
  iVar3 = func_0035f160();
  cVar1 = *(char *)(*(int *)(iVar3 + 0x30) + 0xa2);
  uVar2 = func_0035ed20(0);
  lVar4 = func_002c0e30(uVar2,1 << (u32)(cVar1 == '\0') & 0xffff,0x80000);
  if (lVar4 == 0) {
    lVar4 = 0;
  }
  else {
    uVar5 = func_0035ed20(1);
    lVar4 = (*pcRam006972d0)(lVar4,uVar5 & 0xffffff);
  }
  func_0035f060(lVar4 != 0);
  return 1;
}

// FUN_002cad00 NONMATCHING

u32 func_002cad00(void)

{
  char cVar1 = 0;
  u16 uVar2 = 0;
  int iVar3 = 0;
  long lVar4 = 0;
  u32 uVar5 = 0;
  
  iVar3 = func_0035f160();
  cVar1 = *(char *)(*(int *)(iVar3 + 0x30) + 0xa2);
  uVar2 = func_0035ed20(0);
  lVar4 = func_002c0e30(uVar2,1 << (u32)(cVar1 == '\0') & 0xffff,0x80000);
  if (lVar4 == 0) {
    lVar4 = 0;
  }
  else {
    uVar5 = func_0035ed20(1);
    lVar4 = (*pcRam006972dc)(lVar4,uVar5 & 0xffffff);
  }
  func_0035f060(lVar4 != 0);
  return 1;
}

// FUN_002cae10 NONMATCHING

u32 func_002cae10(void)

{
  char cVar1 = 0;
  u16 uVar2 = 0;
  int iVar3 = 0;
  long lVar4 = 0;
  u32 uVar5 = 0;
  
  iVar3 = func_0035f160();
  cVar1 = *(char *)(*(int *)(iVar3 + 0x30) + 0xa2);
  uVar2 = func_0035ed20(0);
  lVar4 = func_002c0e30(uVar2,1 << (u32)(cVar1 == '\0') & 0xffff,0x80000);
  if (lVar4 == 0) {
    lVar4 = 0;
  }
  else {
    uVar5 = func_0035ed20(1);
    lVar4 = (*pcRam00697348)(lVar4,uVar5 & 0xffffff);
  }
  func_0035f060(lVar4 != 0);
  return 1;
}

// FUN_002caf20 NONMATCHING

u32 func_002caf20(void)

{
  char cVar1 = 0;
  u16 uVar2 = 0;
  int iVar3 = 0;
  long lVar4 = 0;
  u32 uVar5 = 0;
  
  iVar3 = func_0035f160();
  cVar1 = *(char *)(*(int *)(iVar3 + 0x30) + 0xa2);
  uVar2 = func_0035ed20(0);
  lVar4 = func_002c0e30(uVar2,1 << (u32)(cVar1 == '\0') & 0xffff,0x80000);
  if (lVar4 == 0) {
    lVar4 = 0;
  }
  else {
    uVar5 = func_0035ed20(1);
    lVar4 = (*pcRam0069736c)(lVar4,uVar5 & 0xffffff);
  }
  func_0035f060(lVar4 != 0);
  return 1;
}

// FUN_002cb030 NONMATCHING

u32 func_002cb030(void)

{
  char cVar1 = 0;
  u16 uVar2 = 0;
  int iVar3 = 0;
  long lVar4 = 0;
  
  iVar3 = func_0035f160();
  cVar1 = *(char *)(*(int *)(iVar3 + 0x30) + 0xa2);
  uVar2 = func_0035ed20(0);
  lVar4 = func_002c0e30(uVar2,1 << (u32)(cVar1 == '\0') & 0xffff,0x80000);
  if (lVar4 == 0) {
    lVar4 = 0;
  }
  else {
    lVar4 = (*(code *)PTR_FUN_00697390)(lVar4,0);
  }
  func_0035f060(lVar4 != 0);
  return 1;
}

// FUN_002cb0e0 NONMATCHING

u32 func_002cb0e0(void)

{
  char cVar1 = 0;
  u16 uVar2 = 0;
  int iVar3 = 0;
  long lVar4 = 0;
  
  iVar3 = func_0035f160();
  cVar1 = *(char *)(*(int *)(iVar3 + 0x30) + 0xa2);
  uVar2 = func_0035ed20(0);
  lVar4 = func_002c0e30(uVar2,1 << (u32)(cVar1 == '\0') & 0xffff,0x80000);
  if (lVar4 == 0) {
    lVar4 = 0;
  }
  else {
    lVar4 = (*(code *)PTR_FUN_006973cc)(lVar4,0);
  }
  func_0035f060(lVar4 != 0);
  return 1;
}

// FUN_002cb190

u32 func_002cb190(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  u32 unit;
  u16 side;
  u16 id;
  int result;

  unit = func_0035f160();
  side = func_0035ed20(0);
  id = func_0035ed20(1);
  result = 1;
  switch (side) {
  case 0:
    if (*(u8 *)(*(int *)(unit + 0x30) + 0xa2) != 0) {
      result = 0;
    }
    break;
  case 1:
    if (*(u8 *)(*(int *)(unit + 0x30) + 0xa2) != 1) {
      result = 0;
    }
    break;
  }
  if (result == 1) {
    if (*(u16 *)(*(int *)(unit + 0x30) + 0xa4) != id) {
      result = 0;
    }
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002cb270

u32 func_002cb270(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x38000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002cb320

u32 func_002cb320(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x39000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002cb3d0

u32 func_002cb3d0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x3a000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002cb480

u32 func_002cb480(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x3b000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002cb530

u32 func_002cb530(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x3c000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002cb5e0

u32 func_002cb5e0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x3d000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002cb690

u32 func_002cb690(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x3e000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002cb740

u32 func_002cb740(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x3f000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002cb7f0

u32 func_002cb7f0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x40000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002cb8a0

u32 func_002cb8a0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x41000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002cb950

u32 func_002cb950(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x42000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002cba00

u32 func_002cba00(void)

{
  u64 uVar1 = 0;
  u32 lVar2 = 0;
  
  uVar1 = func_0035f160();
  lVar2 = (*(code *)PTR_FUN_006974d4)(uVar1,0);
  func_0035f060(lVar2 != 0);
  return 1;
}

// FUN_002cba50

u32 func_002cba50(void)

{
  u64 uVar1 = 0;
  u32 lVar2 = 0;
  
  uVar1 = func_0035f160();
  lVar2 = (*(code *)PTR_FUN_006974e0)(uVar1,0);
  func_0035f060(lVar2 != 0);
  return 1;
}

// FUN_002cbaa0

u32 func_002cbaa0(void)

{
  u64 uVar1 = 0;
  u32 lVar2 = 0;
  
  uVar1 = func_0035f160();
  lVar2 = (*(code *)PTR_FUN_006974ec)(uVar1,0);
  func_0035f060(lVar2 != 0);
  return 1;
}

// FUN_002cbaf0

u32 func_002cbaf0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x46000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002cbba0

u32 func_002cbba0(void)
{
  extern u32 func_0035ed20(u32);
  extern int func_002c0e30(u16,u32,u32);
  int context;
  u16 side;
  u16 id;
  u32 selector;
  u32 dispatchType;
  u32 payload;
  int result;
  int dispatchResult;

  side = func_0035ed20(0);
  id = func_0035ed20(1);
  context = 0;
  switch (side) {
  case 0:
    context = func_002c0e30(id,1,0x80000);
    break;
  case 1:
    context = func_002c0e30(id,2,0x80000);
    break;
  }
  if (context != 0) {
    selector = (func_0035ed20(2) & 0xffffff) | 0x19000000;
    dispatchType = (selector & 0xff000000) >> 24;
    payload = selector & 0xffffff;
    if (dispatchType == 0) {
      dispatchResult = 0;
    }
    else {
      dispatchResult = gFormationDispatchTable[dispatchType * 3](context,payload);
    }
    result = dispatchResult;
  }
  else {
    result = 0;
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002cbcd0

u32 func_002cbcd0(void)
{
  extern u32 func_0035ed20(u32);
  extern int func_002c0e30(u16,u32,u32);
  u16 side;
  u16 id;
  int context;
  int result;

  side = func_0035ed20(0);
  id = func_0035ed20(1);
  context = 0;
  switch (side) {
  case 0:
    context = func_002c0e30(id,1,0x80000);
    break;
  case 1:
    context = func_002c0e30(id,2,0x80000);
    break;
  }
  if (context != 0) {
    result = (*(u16 *)(context + 0x18) & 0x1800) != 0;
  }
  else {
    result = 0;
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002cbd90

u32 func_002cbd90(void)
{
  extern u32 func_0035ed20(u32);
  extern int func_002c0e30(u16,u32,u32);
  u16 side;
  u16 id;
  int context;
  int result;

  side = func_0035ed20(0);
  id = func_0035ed20(1);
  context = 0;
  switch (side) {
  case 0:
    context = func_002c0e30(id,1,0x80000);
    break;
  case 1:
    context = func_002c0e30(id,2,0x80000);
    break;
  }
  if (context != 0) {
    result = (*(u16 *)(context + 0x18) & 0x1000) != 0;
  }
  else {
    result = 0;
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002cbe50

u32 func_002cbe50(void)
{
  extern u32 func_0035ed20(u32);
  extern int func_002c0e30(u16,u32,u32);
  u16 side;
  u16 id;
  int context;
  int result;

  side = func_0035ed20(0);
  id = func_0035ed20(1);
  context = 0;
  switch (side) {
  case 0:
    context = func_002c0e30(id,1,0x80000);
    break;
  case 1:
    context = func_002c0e30(id,2,0x80000);
    break;
  }
  if (context != 0) {
    result = (*(u16 *)(context + 0x18) & 0x800) != 0;
  }
  else {
    result = 0;
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002cbf10

u32 func_002cbf10(void)
{
  extern u32 func_0035ed20(u32);
  extern int func_002c0e30(u16,u32,u32);
  u16 side;
  u16 id;
  int context;
  int result;

  side = func_0035ed20(0);
  id = func_0035ed20(1);
  context = 0;
  switch (side) {
  case 0:
    context = func_002c0e30(id,1,0x80000);
    break;
  case 1:
    context = func_002c0e30(id,2,0x80000);
    break;
  }
  if (context != 0) {
    result = (*(u16 *)(context + 0x18) & 0x2000) != 0;
  }
  else {
    result = 0;
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002cbfd0

u32 func_002cbfd0(void)
{
  extern u32 func_0035ed20(u32);
  extern int func_002c0e30(u16,u32,u32);
  u16 side;
  u16 id;
  int context;
  int result;

  side = func_0035ed20(0);
  id = func_0035ed20(1);
  context = 0;
  switch (side) {
  case 0:
    context = func_002c0e30(id,1,0x80000);
    break;
  case 1:
    context = func_002c0e30(id,2,0x80000);
    break;
  }
  if (context != 0) {
    result = gFormationDispatchTable[67 * 3](context,0);
  }
  else {
    result = 0;
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002cc0a0

u32 func_002cc0a0(void) {
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern int func_002c0e30(u16,u32,u32);
  u32 unit;
  u16 id;
  int context;
  u32 selector;
  u32 dispatchType;
  u32 payload;
  int result;
  int dispatchResult;

  unit = func_0035f160();
  id = func_0035ed20(0);
  context = func_002c0e30(id,
      1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff,
      0x80000);
  if (context != 0) {
    selector = (func_0035ed20(1) & 0xffffff) | 0x3a000000;
    dispatchType = (selector & 0xff000000) >> 24;
    payload = selector & 0xffffff;
    if (dispatchType == 0) {
      dispatchResult = 0;
    }
    else {
      dispatchResult = gFormationDispatchTable[dispatchType * 3](context,payload);
    }
    result = dispatchResult;
  }
  else {
    result = 0;
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002cc190

u32 func_002cc190(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 dispatchType;
  u32 payload;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x47000000;
  actor = func_0035f160();
  dispatchType = (selector & 0xff000000) >> 24;
  payload = selector & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002cc240

u32 func_002cc240(void) {
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern int func_002c0e30(u16,u32,u32);
  u32 unit;
  u16 id;
  int context;
  u32 selector;
  u32 dispatchType;
  u32 payload;
  int result;
  int dispatchResult;

  unit = func_0035f160();
  id = func_0035ed20(0);
  context = func_002c0e30(id,
      1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff,
      0x80000);
  if (context != 0) {
    selector = (func_0035ed20(1) & 0xffffff) | 0x3e000000;
    dispatchType = (selector & 0xff000000) >> 24;
    payload = selector & 0xffffff;
    if (dispatchType == 0) {
      dispatchResult = 0;
    }
    else {
      dispatchResult = gFormationDispatchTable[dispatchType * 3](context,payload);
    }
    result = dispatchResult;
  }
  else {
    result = 0;
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002cc330

u32 func_002cc330(void)
{
  u32 current;
  u32 found;
  u16 id;
  s32 value;

  current = func_0035f160_u32();
  found = 0;
  id = 1;
  while (id < 12) {
    value = func_0029ad60_u32(id);
    if (value == 0 || value == *(s32 *)(DAT_007ce3ec + 0x148)) {
      break;
    }
    if (value == current) {
      found = 1;
      break;
    }
    id++;
  }
  func_0035f060_u32(found != 0);
  return 1;
}

// FUN_002cc3e0

u32 func_002cc3e0(void)

{
  extern u32 func_0035f160(void);
  u32 uVar1 = 0;
  s32 lVar2 = 0;
  
  uVar1 = func_0035f160();
  lVar2 = (*(code *)PTR_FUN_006975e0)(uVar1,0);
  if (lVar2 == 0) {
    (*(code *)PTR_FUN_006975e0)(uVar1,0);
  }
  return 1;
}

// FUN_002cc450

u32 func_002cc450(void)

{
  u64 uVar1 = 0;
  s32 lVar2 = 0;
  
  uVar1 = func_0035f160();
  lVar2 = (*(code *)PTR_FUN_006975e8)(uVar1,0);
  if (lVar2 == 0) {
    (*(code *)PTR_FUN_006975e0)(uVar1,0);
  }
  return 1;
}

// FUN_002cc4c0

u32 func_002cc4c0(void)

{
  u64 uVar1 = 0;
  s32 lVar2 = 0;
  
  uVar1 = func_0035f160();
  lVar2 = (*(code *)PTR_FUN_006975f0)(uVar1,0);
  if (lVar2 == 0) {
    (*(code *)PTR_FUN_006975e0)(uVar1,0);
  }
  return 1;
}

// FUN_002cc530

u32 func_002cc530(void)

{
  u64 uVar1 = 0;
  s32 lVar2 = 0;
  
  uVar1 = func_0035f160();
  lVar2 = (*(code *)PTR_FUN_006975f8)(uVar1,0);
  if (lVar2 == 0) {
    (*(code *)PTR_FUN_006975e0)(uVar1,0);
  }
  return 1;
}

// FUN_002cc5a0

u32 func_002cc5a0(void)
{
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 payload;
  u32 dispatchType;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x04000000;
  actor = func_0035f160();
  payload = selector & 0xffffff;
  dispatchType = (selector & 0xff000000) >> 24;
  result = gFormationActionTable[dispatchType * 2](actor,payload);
  if (result == 0) {
    gFormationActionTable[0](actor,0);
  }
  return 1;
}

// FUN_002cc650

u32 func_002cc650(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 payload;
  u32 dispatchType;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x05000000;
  actor = func_0035f160();
  payload = selector & 0xffffff;
  dispatchType = (selector & 0xff000000) >> 24;
  result = gFormationActionTable[dispatchType * 2](actor,payload);
  if (result == 0) {
    gFormationActionTable[0](actor,0);
  }
  return 1;
}

// FUN_002cc700

u32 func_002cc700(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 payload;
  u32 dispatchType;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x06000000;
  actor = func_0035f160();
  payload = selector & 0xffffff;
  dispatchType = (selector & 0xff000000) >> 24;
  result = gFormationActionTable[dispatchType * 2](actor,payload);
  if (result == 0) {
    gFormationActionTable[0](actor,0);
  }
  return 1;
}

// FUN_002cc7b0

u32 func_002cc7b0(void)

{
  u64 uVar1 = 0;
  s32 lVar2 = 0;
  
  uVar1 = func_0035f160();
  lVar2 = (*(code *)PTR_FUN_00697618)(uVar1,0);
  if (lVar2 == 0) {
    (*(code *)PTR_FUN_006975e0)(uVar1,0);
  }
  return 1;
}

// FUN_002cc820

u32 func_002cc820(void)

{
  u64 uVar1 = 0;
  s32 lVar2 = 0;
  
  uVar1 = func_0035f160();
  lVar2 = (*(code *)PTR_FUN_00697620)(uVar1,0);
  if (lVar2 == 0) {
    (*(code *)PTR_FUN_006975e0)(uVar1,0);
  }
  return 1;
}

// FUN_002cc890

u32 func_002cc890(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 payload;
  u32 dispatchType;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x09000000;
  actor = func_0035f160();
  payload = selector & 0xffffff;
  dispatchType = (selector & 0xff000000) >> 24;
  result = gFormationActionTable[dispatchType * 2](actor,payload);
  if (result == 0) {
    gFormationActionTable[0](actor,0);
  }
  return 1;
}

// FUN_002cc940

u32 func_002cc940(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 payload;
  u32 dispatchType;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x0a000000;
  actor = func_0035f160();
  payload = selector & 0xffffff;
  dispatchType = (selector & 0xff000000) >> 24;
  result = gFormationActionTable[dispatchType * 2](actor,payload);
  if (result == 0) {
    gFormationActionTable[0](actor,0);
  }
  return 1;
}

// FUN_002cc9f0

u32 func_002cc9f0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 payload;
  u32 dispatchType;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x0b000000;
  actor = func_0035f160();
  payload = selector & 0xffffff;
  dispatchType = (selector & 0xff000000) >> 24;
  result = gFormationActionTable[dispatchType * 2](actor,payload);
  if (result == 0) {
    gFormationActionTable[0](actor,0);
  }
  return 1;
}

// FUN_002ccaa0

u32 func_002ccaa0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 payload;
  u32 dispatchType;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x0c000000;
  actor = func_0035f160();
  payload = selector & 0xffffff;
  dispatchType = (selector & 0xff000000) >> 24;
  result = gFormationActionTable[dispatchType * 2](actor,payload);
  if (result == 0) {
    gFormationActionTable[0](actor,0);
  }
  return 1;
}

// FUN_002ccb50

u32 func_002ccb50(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 payload;
  u32 dispatchType;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x0d000000;
  actor = func_0035f160();
  payload = selector & 0xffffff;
  dispatchType = (selector & 0xff000000) >> 24;
  result = gFormationActionTable[dispatchType * 2](actor,payload);
  if (result == 0) {
    gFormationActionTable[0](actor,0);
  }
  return 1;
}

// FUN_002ccc00

u32 func_002ccc00(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 payload;
  u32 dispatchType;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x0e000000;
  actor = func_0035f160();
  payload = selector & 0xffffff;
  dispatchType = (selector & 0xff000000) >> 24;
  result = gFormationActionTable[dispatchType * 2](actor,payload);
  if (result == 0) {
    gFormationActionTable[0](actor,0);
  }
  return 1;
}

// FUN_002cccb0

u32 func_002cccb0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 payload;
  u32 dispatchType;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x0f000000;
  actor = func_0035f160();
  payload = selector & 0xffffff;
  dispatchType = (selector & 0xff000000) >> 24;
  result = gFormationActionTable[dispatchType * 2](actor,payload);
  if (result == 0) {
    gFormationActionTable[0](actor,0);
  }
  return 1;
}

// FUN_002ccd60

u32 func_002ccd60(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 payload;
  u32 dispatchType;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x10000000;
  actor = func_0035f160();
  payload = selector & 0xffffff;
  dispatchType = (selector & 0xff000000) >> 24;
  result = gFormationActionTable[dispatchType * 2](actor,payload);
  if (result == 0) {
    gFormationActionTable[0](actor,0);
  }
  return 1;
}

// FUN_002cce10

u32 func_002cce10(void)

{
  u64 uVar1 = 0;
  s32 lVar2 = 0;
  
  uVar1 = func_0035f160();
  lVar2 = (*(code *)PTR_FUN_00697670)(uVar1,0);
  if (lVar2 == 0) {
    (*(code *)PTR_FUN_006975e0)(uVar1,0);
  }
  return 1;
}

// FUN_002cce80

u32 func_002cce80(void)

{
  u64 uVar1 = 0;
  s32 lVar2 = 0;
  
  uVar1 = func_0035f160();
  lVar2 = (*(code *)PTR_FUN_00697678)(uVar1,0);
  if (lVar2 == 0) {
    (*(code *)PTR_FUN_006975e0)(uVar1,0);
  }
  return 1;
}

// FUN_002ccef0

u32 func_002ccef0(void)

{
  u64 uVar1 = 0;
  s32 lVar2 = 0;
  
  uVar1 = func_0035f160();
  lVar2 = (*(code *)PTR_FUN_00697680)(uVar1,0);
  if (lVar2 == 0) {
    (*(code *)PTR_FUN_006975e0)(uVar1,0);
  }
  return 1;
}

// FUN_002ccf60

u32 func_002ccf60(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 payload;
  u32 dispatchType;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x15000000;
  actor = func_0035f160();
  payload = selector & 0xffffff;
  dispatchType = (selector & 0xff000000) >> 24;
  result = gFormationActionTable[dispatchType * 2](actor,payload);
  if (result == 0) {
    gFormationActionTable[0](actor,0);
  }
  return 1;
}

// FUN_002cd010

u32 func_002cd010(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 payload;
  u32 dispatchType;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x16000000;
  actor = func_0035f160();
  payload = selector & 0xffffff;
  dispatchType = (selector & 0xff000000) >> 24;
  result = gFormationActionTable[dispatchType * 2](actor,payload);
  if (result == 0) {
    gFormationActionTable[0](actor,0);
  }
  return 1;
}

// FUN_002cd0c0

u32 func_002cd0c0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 payload;
  u32 dispatchType;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x17000000;
  actor = func_0035f160();
  payload = selector & 0xffffff;
  dispatchType = (selector & 0xff000000) >> 24;
  result = gFormationActionTable[dispatchType * 2](actor,payload);
  if (result == 0) {
    gFormationActionTable[0](actor,0);
  }
  return 1;
}

// FUN_002cd170

u32 func_002cd170(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 payload;
  u32 dispatchType;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x18000000;
  actor = func_0035f160();
  payload = selector & 0xffffff;
  dispatchType = (selector & 0xff000000) >> 24;
  result = gFormationActionTable[dispatchType * 2](actor,payload);
  if (result == 0) {
    gFormationActionTable[0](actor,0);
  }
  return 1;
}

// FUN_002cd220

u32 func_002cd220(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 payload;
  u32 dispatchType;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x19000000;
  actor = func_0035f160();
  payload = selector & 0xffffff;
  dispatchType = (selector & 0xff000000) >> 24;
  result = gFormationActionTable[dispatchType * 2](actor,payload);
  if (result == 0) {
    gFormationActionTable[0](actor,0);
  }
  return 1;
}

// FUN_002cd2d0

u32 func_002cd2d0(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 payload;
  u32 dispatchType;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x1a000000;
  actor = func_0035f160();
  payload = selector & 0xffffff;
  dispatchType = (selector & 0xff000000) >> 24;
  result = gFormationActionTable[dispatchType * 2](actor,payload);
  if (result == 0) {
    gFormationActionTable[0](actor,0);
  }
  return 1;
}

// FUN_002cd380

u32 func_002cd380(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 payload;
  u32 dispatchType;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x1b000000;
  actor = func_0035f160();
  payload = selector & 0xffffff;
  dispatchType = (selector & 0xff000000) >> 24;
  result = gFormationActionTable[dispatchType * 2](actor,payload);
  if (result == 0) {
    gFormationActionTable[0](actor,0);
  }
  return 1;
}

// FUN_002cd430

u32 func_002cd430(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 payload;
  u32 dispatchType;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x1c000000;
  actor = func_0035f160();
  payload = selector & 0xffffff;
  dispatchType = (selector & 0xff000000) >> 24;
  result = gFormationActionTable[dispatchType * 2](actor,payload);
  if (result == 0) {
    gFormationActionTable[0](actor,0);
  }
  return 1;
}

// FUN_002cd4e0

u32 func_002cd4e0(void)
{
  extern u32 func_0035f160(void);
  u32 actor;
  int result;

  actor = func_0035f160();
  if (*(int *)(DAT_007ce3ec + 0x148) != 0) {
    func_002c08b0(actor + 0x88,*(int *)(DAT_007ce3ec + 0x148) + 0x88);
    result = gFormationActionTable[18 * 2](actor,0);
    if (result == 0) {
      gFormationActionTable[0](actor,0);
    }
  }
  return 1;
}

// FUN_002cd570

u32 func_002cd570(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 payload;
  u32 dispatchType;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x21000000;
  actor = func_0035f160();
  payload = selector & 0xffffff;
  dispatchType = (selector & 0xff000000) >> 24;
  result = gFormationActionTable[dispatchType * 2](actor,payload);
  if (result == 0) {
    gFormationActionTable[0](actor,0);
  }
  return 1;
}

// FUN_002cd620

u32 func_002cd620(void)

{
  u64 uVar1 = 0;
  s32 lVar2 = 0;
  
  uVar1 = func_0035f160();
  lVar2 = (*(code *)PTR_FUN_006976f0)(uVar1,0);
  if (lVar2 == 0) {
    (*(code *)PTR_FUN_006975e0)(uVar1,0);
  }
  return 1;
}

// FUN_002cd690

u32 func_002cd690(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 payload;
  u32 dispatchType;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x23000000;
  actor = func_0035f160();
  payload = selector & 0xffffff;
  dispatchType = (selector & 0xff000000) >> 24;
  result = gFormationActionTable[dispatchType * 2](actor,payload);
  if (result == 0) {
    gFormationActionTable[0](actor,0);
  }
  return 1;
}

// FUN_002cd740

u32 func_002cd740(void) {
  extern u32 func_0035ed20(u32);
  extern u32 func_0035f160(void);
  u32 selector;
  u32 payload;
  u32 dispatchType;
  u32 actor;
  int result;

  selector = (func_0035ed20(0) & 0xffffff) | 0x24000000;
  actor = func_0035f160();
  payload = selector & 0xffffff;
  dispatchType = (selector & 0xff000000) >> 24;
  result = gFormationActionTable[dispatchType * 2](actor,payload);
  if (result == 0) {
    gFormationActionTable[0](actor,0);
  }
  return 1;
}

// FUN_002cd7f0

u32 func_002cd7f0(void)

{
  extern u32 func_0035f160(void);
  u16 uVar1 = 0;
  int iVar2 = 0;
  
  iVar2 = func_0035f160();
  uVar1 = func_0035ed20(0);
  if (*(u16 *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8) != 0x1b4) {
    func_0017b220(*(u16 *)(*(int *)(iVar2 + 0x30) + 0xa4));
  }
  func_00301540(*(u32 *)(*(int *)(iVar2 + 0x30) + 0xa2c),0xd);
  func_00301540(*(u32 *)(*(int *)(iVar2 + 0x30) + 0xa2c),0xe);
  func_00301540(*(u32 *)(*(int *)(iVar2 + 0x30) + 0xa2c),0xf);
  func_00301540(*(u32 *)(*(int *)(iVar2 + 0x30) + 0xa2c),0x10);
  *(u16 *)(*(int *)(*(int *)(iVar2 + 0x30) + 0xa2c) + 4) = uVar1;
  return 1;
}

// FUN_002cd8c0

u32 func_002cd8c0(void)

{
  extern u32 func_0035f160(void);
  u16 *puVar1;
  u16 uVar2 = 0;
  int iVar3 = 0;
  
  iVar3 = func_0035f160();
  uVar2 = func_0035ed20(0);
  if (uVar2 == 0) {
    puVar1 = *(u16 **)(*(int *)(iVar3 + 0x30) + 0xa2c);
    *puVar1 = *puVar1 | 0x10;
  }
  else {
    puVar1 = *(u16 **)(*(int *)(iVar3 + 0x30) + 0xa2c);
    *puVar1 = *puVar1 & 0xffef;
  }
  return 1;
}

// FUN_002cd940

u32 func_002cd940(void)

{
  extern u32 func_0035f160(void);
  u16 *puVar1;
  u16 uVar2 = 0;
  int iVar3 = 0;
  
  iVar3 = func_0035f160();
  uVar2 = func_0035ed20(0);
  if (uVar2 == 0) {
    puVar1 = *(u16 **)(*(int *)(iVar3 + 0x30) + 0xa2c);
    *puVar1 = *puVar1 | 0x20;
  }
  else {
    puVar1 = *(u16 **)(*(int *)(iVar3 + 0x30) + 0xa2c);
    *puVar1 = *puVar1 & 0xffdf;
  }
  return 1;
}

// FUN_002cd9c0

u32 func_002cd9c0(void)

{
  extern u32 func_0035f160(void);
  u8 uVar1 = 0;
  u16 uVar2 = 0;
  int iVar3 = 0;
  
  iVar3 = func_0035f160();
  uVar2 = func_0035ed20(0);
  *(u16 *)(iVar3 + 0x80) = uVar2;
  uVar1 = func_0035ed20(1);
  *(u8 *)(iVar3 + 0x82) = uVar1;
  return 1;
}

// FUN_002cda10

u32 func_002cda10(void)

{
  extern u32 func_0035f160(void);
  int iVar1 = 0;
  
  iVar1 = func_0035f160();
  func_0035f060(*(u16 *)(*(int *)(*(int *)(iVar1 + 0x30) + 0xa2c) + 4));
  return 1;
}

// FUN_002cda50

u32 func_002cda50(void)

{
  extern u32 func_0035f160(void);
  extern int func_002c0e30(u16,u32,u32);
  u16 uVar1 = 0;
  int iVar2 = 0;
  int lVar3 = 0;
  u32 uVar4 = 0;
  
  iVar2 = func_0035f160();
  uVar1 = func_0035ed20(0);
  lVar3 = func_002c0e30(uVar1,1 << *(u8 *)(*(int *)(iVar2 + 0x30) + 0xa2) & 0xffff,
                        0x80000);
  if (lVar3 != 0) {
    uVar4 = *(u32 *)(lVar3 + 0x20);
  }
  else {
    uVar4 = 0;
  }
  func_0035f060(uVar4);
  return 1;
}

// FUN_002cdad0 NONMATCHING

u32 func_002cdad0(void)
{
  extern u32 func_0035f160(void);
  extern int func_002c0e30(u16,u32,u32);
  u32 actor;
  u32 side;
  u16 id;
  int context;
  u32 result;

  actor = func_0035f160();
  switch (*(u8 *)(*(int *)(actor + 0x30) + 0xa2)) {
  default:
    side = 1;
    break;
  case 0:
    side = 0;
    break;
  }
  id = func_0035ed20(0);
  context = func_002c0e30(id,1 << side & 0xffff,0x80000);
  if (context != 0) {
    result = *(u32 *)(context + 0x20);
  }
  else {
    result = 0;
  }
  func_0035f060(result);
  return 1;
}

// FUN_002cdb70

u32 func_002cdb70(void)

{
  u16 uVar1 = 0;
  u64 uVar2 = 0;
  u64 uVar3 = 0;
  
  uVar2 = func_0035f160();
  uVar3 = func_0035ed20(0);
  uVar1 = func_002c0f40_call(uVar2,uVar3,0x80000,1,0,(code *)&func_002c3400,0);
  func_0035f060(uVar1);
  return 1;
}

// FUN_002cdbe0

u32 func_002cdbe0(void)

{
  u16 uVar1 = 0;
  u64 uVar2 = 0;
  u64 uVar3 = 0;
  
  uVar2 = func_0035f160();
  uVar3 = func_0035ed20(0);
  uVar1 = func_002c0f40_call(uVar2,uVar3,0x80000,1,1,(code *)&func_002c3400,0);
  func_0035f060(uVar1);
  return 1;
}

// FUN_002cdc50

u32 func_002cdc50(void)

{
  u16 uVar1 = 0;
  u64 uVar2 = 0;
  u64 uVar3 = 0;
  
  uVar2 = func_0035f160();
  uVar3 = func_0035ed20(0);
  uVar1 = func_002c0f40_call(uVar2,uVar3,0x80000,1,0,(code *)&func_002c1710,0);
  func_0035f060(uVar1);
  return 1;
}

// FUN_002cdcc0

u32 func_002cdcc0(void)

{
  u16 uVar1 = 0;
  u64 uVar2 = 0;
  u64 uVar3 = 0;
  
  uVar2 = func_0035f160();
  uVar3 = func_0035ed20(0);
  uVar1 = func_002c0f40_call(uVar2,uVar3,0x80000,2,0,(code *)&func_002c3400,0);
  func_0035f060(uVar1);
  return 1;
}

// FUN_002cdd30

u32 func_002cdd30(void)

{
  u16 uVar1 = 0;
  u64 uVar2 = 0;
  u64 uVar3 = 0;
  
  uVar2 = func_0035f160();
  uVar3 = func_0035ed20(0);
  uVar1 = func_002c0f40_call(uVar2,uVar3,0x80000,2,1,(code *)&func_002c3400,0);
  func_0035f060(uVar1);
  return 1;
}

// FUN_002cdda0

u32 func_002cdda0(void)

{
  u16 uVar1 = 0;
  u64 uVar2 = 0;
  u64 uVar3 = 0;
  
  uVar2 = func_0035f160();
  uVar3 = func_0035ed20(0);
  uVar1 = func_002c0f40_call(uVar2,uVar3,0x80000,1,0,(code *)&func_002c12f0,0);
  func_0035f060(uVar1);
  return 1;
}

// FUN_002cde10

u32 func_002cde10(void)

{
  extern u32 func_0035f160(void);
  u16 uVar1 = 0;
  int iVar2 = 0;
  
  iVar2 = func_0035f160();
  uVar1 = func_002d4cf0(1 << *(u8 *)(*(int *)(iVar2 + 0x30) + 0xa2) & 0xffff,0x80000);
  func_0035f060(uVar1);
  return 0xffffffff;
}

// FUN_002cde60 NONMATCHING

u32 func_002cde60(void)

{
  extern u32 func_0035f160(void);
  u16 uVar1 = 0;
  int iVar2 = 0;
  u16 genus;
  
  iVar2 = func_0035f160();
  switch (*(u8 *)(*(int *)(iVar2 + 0x30) + 0xa2)) {
  default:
    genus = 0;
    break;
  case 0:
    genus = 1;
    break;
  }
  uVar1 = func_002d4cf0(1 << genus & 0xffff,0x80000);
  func_0035f060(uVar1);
  return 0xffffffff;
}

// FUN_002cded0

u32 func_002cded0(void)

{
  extern u32 func_0035f160(void);
  extern s16 func_003082f0(u32,u16);
  s16 id = 0;
  s16 result = 0;
  u32 unit = 0;
  
  unit = func_0035f160();
  id = func_0035ed20(0);
  result = func_003082f0(*(u32 *)(*(int *)(unit + 0x30) + 0xa2c),id);
  func_0035f060(result);
  return 0xffffffff;
}

// FUN_002cdf40

u32 func_002cdf40(void)
{
  extern u32 func_0035ed20(u32);
  extern u32 func_0029a210(u32);
  u32 actorId;
  u32 rawPayload;
  u32 actor;
  u32 selector;
  u32 dispatchType;
  u32 payload;
  int result;

  actorId = func_0035ed20(0);
  rawPayload = func_0035ed20(1);
  actor = func_0029a210(actorId & 0xfffffff);
  selector = rawPayload & 0xffffff;
  selector |= 0x01000000;
  dispatchType = (selector & 0xff000000) >> 24;
  payload = (rawPayload | 0x01000000) & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002ce010

u32 func_002ce010(void)

{
  extern u32 func_0035ed20(u32);
  extern u32 func_0029a210(u32);
  u32 actor = 0;
  u32 actorId = 0;
  u32 statusId = 0;
  u32 active = 0;
  
  actorId = func_0035ed20(0);
  statusId = func_0035ed20(1);
  actor = func_0029a210(actorId & 0xfffffff);
  active = func_00301ca0(*(u32 *)(*(int *)(actor + 0x30) + 0xa2c),statusId) != 0;
  func_0035f060(active != 0);
  return 1;
}

// FUN_002ce090

u32 func_002ce090(void)

{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern u32 func_0029a210(u32);
  extern s32 func_00303130(s32,u32,u32,s32,s32,s32,s32,s32);
  u32 unit = 0;
  u32 actor = 0;
  s32 relation = 0;
  u32 status = 0;
  u32 actorId = 0;
  
  unit = func_0035f160();
  actorId = func_0035ed20(0);
  actor = func_0029a210(actorId & 0xfffffff);
  relation = func_00303130(0,*(u32 *)(*(int *)(unit + 0x30) + 0xa2c),
                          *(u32 *)(*(int *)(actor + 0x30) + 0xa2c),1,1,1,0,1);
  func_00301870(*(u32 *)(*(int *)(unit + 0x30) + 0xa2c));
  func_00301870(*(u32 *)(*(int *)(actor + 0x30) + 0xa2c));
  status = func_002ffd70(*(u32 *)(*(int *)(actor + 0x30) + 0xa2c));
  func_0035f060((s32)((status & 0xffff) + relation) <= 0);
  return 1;
}

// FUN_002ce170

u32 func_002ce170(void)

{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern u32 func_0029a210(u32);
  extern s32 func_002c5fc0(u32,u32,s16,s32);
  u32 unit = 0;
  u32 actorId = 0;
  u32 actionId = 0;
  u32 target = 0;
  s32 result = 0;
  
  unit = func_0035f160();
  actorId = func_0035ed20(0);
  actionId = func_0035ed20(1);
  target = func_0029a210(actorId & 0xfffffff);
  result = func_002c5fc0(unit,target,(s16)actionId,0);
  func_0035f060(result != -1);
  return 1;
}

// FUN_002ce210

u32 func_002ce210(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern u32 func_0029a210(u32);
  u32 context;
  u32 actorId;
  u32 value;
  u32 actor;
  long result;

  context = func_0035f160();
  actorId = func_0035ed20(0);
  value = func_0035ed20(1);
  actor = func_0029a210(actorId & 0xfffffff);
  result = func_002c6300_s32(context, actor, value, 0);
  func_0035f060(result != -1);
  return 1;
}

// FUN_002ce2b0

u32 func_002ce2b0(void)
{
  extern u32 func_0035ed20(u32);
  extern u32 func_0029a210(u32);
  u32 actorId;
  u32 rawPayload;
  u32 actor;
  u32 selector;
  u32 dispatchType;
  u32 payload;
  int result;

  actorId = func_0035ed20(0);
  rawPayload = func_0035ed20(1);
  actor = func_0029a210(actorId & 0xfffffff);
  selector = rawPayload & 0xffffff;
  selector |= 0x3f000000;
  dispatchType = (selector & 0xff000000) >> 24;
  payload = (rawPayload | 0x3f000000) & 0xffffff;
  if (dispatchType == 0) {
    result = 0;
  }
  else {
    result = gFormationDispatchTable[dispatchType * 3](actor,payload);
  }
  func_0035f060(result != 0);
  return 1;
}

// FUN_002ce380 NONMATCHING

u32 func_002ce380(void)

{
  short sVar1 = 0;
  int iVar2 = 0;
  u32 uVar3 = 0;
  u64 uVar4 = 0;
  u32 uVar5 = 0;
  long lVar6 = 0;
  
  uVar4 = func_0035f160();
  iVar2 = (int)uVar4;
  sVar1 = func_002bff60(uVar4,0,*(u16 *)(iVar2 + 0x6e),0);
  if (sVar1 == 0) {
    uVar5 = func_0035ed20(0);
    uVar3 = func_0029a210(uVar5 & 0xfffffff);
    *(u32 *)(iVar2 + 0x38) = uVar3;
    *(u16 *)(iVar2 + 0x6a) = 1;
  }
  else {
    lVar6 = (*(code *)PTR_FUN_006975e0)(uVar4,0);
    if (lVar6 == 0) {
      (*(code *)PTR_FUN_006975e0)(uVar4,0);
    }
  }
  return 1;
}

// FUN_002ce440

u32 func_002ce440(void)

{
  extern u32 func_0035ed20(u32);
  extern int func_002c0e30(u16,u32,u32);
  u16 side = 0;
  u16 id = 0;
  int context = 0;
  
  side = func_0035ed20(0);
  id = func_0035ed20(1);
  context = 0;
  switch (side) {
  case 0:
    context = func_002c0e30(id,1,0x80000);
    break;
  case 1:
    context = func_002c0e30(id,2,0x80000);
    break;
  }
  func_0035f060(*(u32 *)(context + 8) | 0x80000000);
  return 1;
}

// FUN_002ce4e0

u32 func_002ce4e0(void)

{
  int unit = 0;
  long excluded = 0;
  u16 stat = 0;
  int selectedUnit = 0;
  u32 lowestStat = 0;

  selectedUnit = 0;
  lowestStat = 0xfffffff;
  for (unit = *(int *)(DAT_007ce3ec + 0x14c); unit != 0; unit = *(int *)(unit + 0x4a8)) {
    if (((((*(u16 *)(unit + 0x1a) & 1) != 0) && ((*(u16 *)(unit + 0x1a) & 8) != 0)) &&
        (*(u8 *)(*(int *)(unit + 0x30) + 0xa2) == 1)) &&
       (excluded = func_0030b5a0(*(u32 *)(*(int *)(unit + 0x30) + 0xa2c),0), excluded == 0)) {
      stat = func_002ffd70(*(u32 *)(*(int *)(unit + 0x30) + 0xa2c));
      if (stat < lowestStat) {
        selectedUnit = unit;
        lowestStat = stat;
      }
    }
  }
  func_0035f060(*(u32 *)(selectedUnit + 8) | 0x80000000);
  return 1;
}

// FUN_002ce5c0 NONMATCHING

u32 func_002ce5c0(void)

{
  int iVar1 = 0;
  int iVar2 = 0;
  u64 uVar3 = 0;
  u32 uVar4 = 0;
  long lVar5 = 0;
  
  uVar3 = func_0035f160();
  uVar4 = func_0035ed20(0);
  lVar5 = func_002c3430(uVar3,uVar4,0,0x2e,0,(code *)&func_002c1ed0);
  if (lVar5 == 1) {
    iVar1 = (int)uVar3;
    if (*(short *)(iVar1 + 0x6a) == 1) {
      func_0035f060(*(u32 *)(*(int *)(iVar1 + 0x38) + 8) | 0x80000000);
    }
    else {
      if ((uVar4 & 0xe) == 0) {
        iVar2 = func_002ffbc0();
        iVar1 = *(int *)(iVar2 * 4 + iVar1 + 0x38);
      }
      else {
        iVar1 = func_002c65d0(uVar3);
      }
      func_0035f060(*(u32 *)(iVar1 + 8) | 0x80000000);
    }
  }
  else {
    func_0035f060(0xffffffffffffffff);
  }
  return 1;
}

// FUN_002ce6c0

u32 func_002ce6c0(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern u32 func_002c3430(u32,u32,u32,u16,int,code *);
  extern u32 func_002ffbc0(u32);
  u32 unit;
  u32 selector;
  u32 offset;

  unit = func_0035f160();
  selector = func_0035ed20(0);
  if (func_002c3430(unit,selector,0x100000,0x2e,0,(code *)&func_002c1ed0) == 1) {
    if (*(u16 *)(unit + 0x6a) == 1) {
      func_0035f060(*(u32 *)(*(int *)(unit + 0x38) + 8) | 0x80000000);
    }
    else {
      offset = func_002ffbc0(*(u16 *)(unit + 0x6a)) * 4;
      func_0035f060(*(u32 *)(*(int *)(offset + unit + 0x38) + 8) | 0x80000000);
    }
  }
  else {
    func_0035f060(0xffffffff);
  }
  return 1;
}

// FUN_002ce7a0

u32 func_002ce7a0(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern u32 func_002c3430(u32,u32,u32,u16,int,code *);
  extern u32 func_002ffbc0(u32);
  u32 unit;
  u32 selector;
  u32 offset;

  unit = func_0035f160();
  selector = func_0035ed20(0);
  if (func_002c3430(unit,selector,0,0x2f,0,(code *)&func_002c1ed0) == 1) {
    if (*(u16 *)(unit + 0x6a) == 1) {
      func_0035f060(*(u32 *)(*(int *)(unit + 0x38) + 8) | 0x80000000);
    }
    else {
      offset = func_002ffbc0(*(u16 *)(unit + 0x6a)) * 4;
      func_0035f060(*(u32 *)(*(int *)(offset + unit + 0x38) + 8) | 0x80000000);
    }
  }
  else {
    func_0035f060(0xffffffff);
  }
  return 1;
}

// FUN_002ce880

u32 func_002ce880(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern u32 func_002c3430(u32,u32,u32,u16,int,code *);
  extern u32 func_002ffbc0(u32);
  u32 unit;
  u32 selector;
  u32 offset;

  unit = func_0035f160();
  selector = func_0035ed20(0);
  if (func_002c3430(unit,selector,0,0x2c,0,(code *)&func_002c30f0) == 1) {
    if (*(u16 *)(unit + 0x6a) == 1) {
      func_0035f060(*(u32 *)(*(int *)(unit + 0x38) + 8) | 0x80000000);
    }
    else {
      offset = func_002ffbc0(*(u16 *)(unit + 0x6a)) * 4;
      func_0035f060(*(u32 *)(*(int *)(offset + unit + 0x38) + 8) | 0x80000000);
    }
  }
  else {
    func_0035f060(0xffffffff);
  }
  return 1;
}

// FUN_002ce960

u32 func_002ce960(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern u32 func_002c3430(u32,u32,u32,u16,int,code *);
  extern u32 func_002ffbc0(u32);
  u32 unit;
  u32 selector;
  u32 offset;

  unit = func_0035f160();
  selector = func_0035ed20(0);
  if (func_002c3430(unit,selector,0x100000,0x2c,0,(code *)&func_002c30f0) == 1) {
    if (*(u16 *)(unit + 0x6a) == 1) {
      func_0035f060(*(u32 *)(*(int *)(unit + 0x38) + 8) | 0x80000000);
    }
    else {
      offset = func_002ffbc0(*(u16 *)(unit + 0x6a)) * 4;
      func_0035f060(*(u32 *)(*(int *)(offset + unit + 0x38) + 8) | 0x80000000);
    }
  }
  else {
    func_0035f060(0xffffffff);
  }
  return 1;
}

// FUN_002cea40

u32 func_002cea40(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern u32 func_002c3430(u32,u32,u32,u16,int,code *);
  extern u32 func_002ffbc0(u32);
  u32 unit;
  u32 selector;
  u32 offset;

  unit = func_0035f160();
  selector = func_0035ed20(0);
  if (func_002c3430(unit,selector,0,0x2d,0,(code *)&func_002c30f0) == 1) {
    if (*(u16 *)(unit + 0x6a) == 1) {
      func_0035f060(*(u32 *)(*(int *)(unit + 0x38) + 8) | 0x80000000);
    }
    else {
      offset = func_002ffbc0(*(u16 *)(unit + 0x6a)) * 4;
      func_0035f060(*(u32 *)(*(int *)(offset + unit + 0x38) + 8) | 0x80000000);
    }
  }
  else {
    func_0035f060(0xffffffff);
  }
  return 1;
}

// FUN_002ceb20 NONMATCHING

u32 func_002ceb20(void)

{
  u32 uVar1 = 0;
  int iVar2 = 0;
  u64 uVar3 = 0;
  u64 uVar4 = 0;
  u32 uVar5 = 0;
  int aiStack_30 [12] = {0};
  
  uVar3 = func_0035f160();
  uVar4 = func_0035ed20(0);
  uVar1 = func_002c0f40_call(uVar3,uVar4,0x80000,1,1,(code *)&func_002c3400,(long)(int)aiStack_30);
  uVar1 = uVar1 & 0xffff;
  if (uVar1 == 0) {
    func_0035f060(0xffffffffffffffff);
  }
  else {
    for (uVar5 = 0; (uVar5 < uVar1 && (*(int *)(DAT_007ce3ec + 0x148) != aiStack_30[uVar5]));
        uVar5 = uVar5 + 1 & 0xffff) {
    }
    if (uVar5 == uVar1) {
      iVar2 = func_002ffbc0(uVar1);
      iVar2 = aiStack_30[iVar2];
    }
    else {
      iVar2 = *(int *)(DAT_007ce3ec + 0x148);
    }
    func_0035f060(*(u32 *)(iVar2 + 8) | 0x80000000);
  }
  return 1;
}

// FUN_002cec30 NONMATCHING

u32 func_002cec30(void)

{
  char cVar1 = 0;
  u32 uVar2 = 0;
  int iVar3 = 0;
  u64 uVar4 = 0;
  u64 uVar5 = 0;
  u32 uVar6 = 0;
  int aiStack_30 [12] = {0};
  
  uVar4 = func_0035f160();
  uVar5 = func_0035ed20(0);
  uVar2 = func_002c0f40_call(uVar4,uVar5,0x80000,2,1,(code *)&func_002c3400,(long)(int)aiStack_30);
  uVar2 = uVar2 & 0xffff;
  if (uVar2 == 0) {
    func_0035f060(0xffffffffffffffff);
  }
  else {
    iVar3 = 0;
    for (uVar6 = 0; uVar6 < uVar2; uVar6 = uVar6 + 1 & 0xffff) {
      cVar1 = func_002ffcc0(*(u32 *)(*(int *)(aiStack_30[uVar6] + 0x30) + 0xa2c));
      if (cVar1 != '\0') {
        iVar3 = aiStack_30[uVar6];
      }
    }
    if (iVar3 == 0) {
      iVar3 = func_002ffbc0(uVar2);
      iVar3 = aiStack_30[iVar3];
    }
    func_0035f060(*(u32 *)(iVar3 + 8) | 0x80000000);
  }
  return 1;
}

// FUN_002ced60 NONMATCHING

u32 func_002ced60(void)

{
  char cVar1 = 0;
  u8 bVar2 = 0;
  int iVar3 = 0;
  u64 uVar4 = 0;
  long lVar5 = 0;
  u32 uVar6 = 0;
  u32 uVar7 = 0;
  u8 bVar8 = 0;
  int aiStack_70 [12] = {0};
  int aiStack_40 [14] = {0};
  u16 uStack_8 = 0;
  
  uVar4 = func_0035f160();
  cVar1 = *(char *)(*(int *)((int)uVar4 + 0x30) + 0xa2);
  func_002bfcb0(uVar4,(u64)(u32)aiStack_40,2,0,0);
  bVar8 = 0;
  uVar6 = 0;
  for (uVar7 = 0; uVar7 < uStack_8; uVar7 = uVar7 + 1 & 0xffff) {
    iVar3 = aiStack_40[uVar7];
    if (((((*(u16 *)(iVar3 + 0x1a) & 1) != 0) && ((*(u16 *)(iVar3 + 0x1a) & 8) != 0)) &&
        ((bool)*(char *)(*(int *)(iVar3 + 0x30) + 0xa2) == (cVar1 == '\0'))) &&
       (lVar5 = func_0030b5a0(*(u32 *)(*(int *)(iVar3 + 0x30) + 0xa2c),0), lVar5 == 0)) {
      bVar2 = func_002ffcc0(*(u32 *)(*(int *)(iVar3 + 0x30) + 0xa2c));
      if (bVar2 == bVar8) {
        aiStack_70[uVar6] = iVar3;
        uVar6 = uVar6 + 1 & 0xffff;
      }
      else if (bVar8 < bVar2) {
        uVar6 = 1;
        aiStack_70[0] = iVar3;
        bVar8 = bVar2;
      }
    }
  }
  if (uVar6 == 0) {
    func_0035f060(0xffffffffffffffff);
  }
  else {
    iVar3 = func_002ffbc0();
    func_0035f060(*(u32 *)(aiStack_70[iVar3] + 8) | 0x80000000);
  }
  return 1;
}

// FUN_002cef10 NONMATCHING

u32 func_002cef10(void)

{
  int iVar1 = 0;
  u8 bVar2 = 0;
  u16 uVar3 = 0;
  u64 uVar4 = 0;
  u64 uVar5 = 0;
  long lVar6 = 0;
  u16 uVar7 = 0;
  u32 uVar8 = 0;
  int iVar9 = 0;
  int iVar10 = 0;
  u8 bVar11 = 0;
  
  uVar4 = func_0035f160();
  uVar5 = func_0035ed20(0);
  lVar6 = func_002c3430(uVar4,uVar5,0,0x2c,0,(code *)&func_002c30f0);
  if (lVar6 == 1) {
    iVar10 = (int)uVar4;
    if (*(short *)(iVar10 + 0x6a) == 1) {
      iVar9 = *(int *)(iVar10 + 0x38);
    }
    else {
      iVar9 = 0;
      bVar11 = 0;
      uVar7 = 0;
      for (uVar8 = 0; uVar8 < *(u16 *)(iVar10 + 0x6a); uVar8 = uVar8 + 1) {
        iVar1 = *(int *)(iVar10 + uVar8 * 4 + 0x38);
        bVar2 = func_002ffcc0(*(u32 *)(*(int *)(iVar1 + 0x30) + 0xa2c));
        if (bVar11 <= bVar2) {
          uVar3 = func_002ffd70(*(u32 *)(*(int *)(iVar1 + 0x30) + 0xa2c));
          bVar11 = bVar2;
          if (uVar7 < uVar3) {
            iVar9 = iVar1;
            uVar7 = uVar3;
          }
        }
      }
    }
    func_0035f060(*(u32 *)(iVar9 + 8) | 0x80000000);
  }
  else {
    func_0035f060(0xffffffffffffffff);
  }
  return 0xffffffff;
}

// FUN_002cf070 NONMATCHING

u32 func_002cf070(void)

{
  int iVar1 = 0;
  u64 uVar2 = 0;
  u64 uVar3 = 0;
  long lVar4 = 0;
  u32 uVar5 = 0;
  u32 uVar6 = 0;
  u32 uVar7 = 0;
  int aiStack_30 [12] = {0};
  
  uVar2 = func_0035f160();
  uVar3 = func_0035ed20(0);
  lVar4 = func_002c3430(uVar2,uVar3,0,0x2c,0,(code *)&func_002c30f0);
  if (lVar4 == 1) {
    uVar6 = 0;
    for (uVar7 = 0; uVar7 < *(u16 *)((int)uVar2 + 0x6a); uVar7 = uVar7 + 1 & 0xffff) {
      iVar1 = *(int *)((int)uVar2 + uVar7 * 4 + 0x38);
      uVar5 = func_00300530(*(u32 *)(*(int *)(iVar1 + 0x30) + 0xa2c));
      if ((uVar5 & 0xffffffffffefffff) == 0) {
        aiStack_30[uVar6] = iVar1;
        uVar6 = uVar6 + 1 & 0xffff;
      }
    }
    if (uVar6 == 0) {
      func_0035f060(0xffffffffffffffff);
    }
    else {
      iVar1 = func_002ffbc0();
      func_0035f060(*(u32 *)(aiStack_30[iVar1] + 8) | 0x80000000);
    }
  }
  else {
    func_0035f060(0xffffffffffffffff);
  }
  return 0xffffffff;
}

// FUN_002cf1d0 NONMATCHING

u32 func_002cf1d0(void)

{
  int iVar1 = 0;
  u8 bVar2 = 0;
  int iVar3 = 0;
  u64 uVar4 = 0;
  u64 uVar5 = 0;
  long lVar6 = 0;
  u32 uVar7 = 0;
  u8 bVar8 = 0;
  u32 uVar9 = 0;
  int aiStack_30 [12] = {0};
  
  uVar4 = func_0035f160();
  uVar5 = func_0035ed20(0);
  lVar6 = func_002c3430(uVar4,uVar5,0,0x2c,1,(code *)&func_002c3120);
  if (lVar6 == 1) {
    iVar3 = (int)uVar4;
    if (*(short *)(iVar3 + 0x6a) == 1) {
      iVar3 = *(int *)(iVar3 + 0x38);
    }
    else {
      uVar7 = 0;
      bVar8 = 0;
      for (uVar9 = 0; uVar9 < *(u16 *)(iVar3 + 0x6a); uVar9 = uVar9 + 1) {
        iVar1 = *(int *)(iVar3 + uVar9 * 4 + 0x38);
        bVar2 = func_002ffcc0(*(u32 *)(*(int *)(iVar1 + 0x30) + 0xa2c));
        if (bVar8 <= bVar2) {
          if (bVar2 == bVar8) {
            aiStack_30[uVar7] = iVar1;
            uVar7 = uVar7 + 1 & 0xffff;
          }
          else {
            uVar7 = 1;
            aiStack_30[0] = iVar1;
            bVar8 = bVar2;
          }
        }
      }
      iVar3 = func_002ffbc0(uVar7);
      iVar3 = aiStack_30[iVar3];
    }
    func_0035f060(*(u32 *)(iVar3 + 8) | 0x80000000);
  }
  else {
    func_0035f060(0xffffffffffffffff);
  }
  return 0xffffffff;
}

// FUN_002cf340 NONMATCHING

u32 func_002cf340(void)

{
  short sVar1 = 0;
  u64 uVar2 = 0;
  u64 uVar3 = 0;
  long lVar4 = 0;
  u32 uVar5 = 0;
  u32 uVar6 = 0;
  
  uVar2 = func_0035f160();
  uVar3 = func_0035ed20(0);
  lVar4 = func_002c3430(uVar2,uVar3,0,0x2c,0,(code *)&func_002c30f0);
  if (lVar4 == 1) {
    sVar1 = 0;
    for (uVar6 = 0; uVar6 < *(u16 *)((int)uVar2 + 0x6a); uVar6 = uVar6 + 1 & 0xffff) {
      uVar5 = func_00300530(*(u32 *)
                            (*(int *)(*(int *)((int)uVar2 + uVar6 * 4 + 0x38) + 0x30) + 0xa2c));
      if ((uVar5 & 0xffffffffffefffff) == 0) {
        sVar1 = sVar1 + 1;
      }
    }
    func_0035f060(sVar1);
  }
  else {
    func_0035f060(0);
  }
  return 0xffffffff;
}

// FUN_002cf450

u32 func_002cf450(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern u32 func_002c3430(u32,u32,u32,u16,int,code *);
  u32 unit;
  u32 selector;
  int selectedUnit;
  int candidate;
  u32 index;
  u32 lowestStat;
  u16 stat;

  unit = func_0035f160();
  selector = func_0035ed20(0);
  if (func_002c3430(unit,selector,0,0x2e,0,(code *)&func_002c1ed0) == 1) {
    if (*(u16 *)(unit + 0x6a) == 1) {
      selectedUnit = *(int *)(unit + 0x38);
    }
    else {
      selectedUnit = 0;
      lowestStat = 0xfffffff;
      for (index = 0; index < *(u16 *)(unit + 0x6a); index++) {
        candidate = *(int *)(unit + index * 4 + 0x38);
        stat = func_002ffd70(*(u32 *)(*(int *)(candidate + 0x30) + 0xa2c));
        if (stat < lowestStat) {
          selectedUnit = candidate;
          lowestStat = stat;
        }
      }
    }
    func_0035f060(*(u32 *)(selectedUnit + 8) | 0x80000000);
  }
  else {
    func_0035f060(0xffffffff);
  }
  return 1;
}

// FUN_002cf580

u32 func_002cf580(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern u32 func_002c3430(u32,u32,u32,u16,int,code *);
  u32 unit;
  u32 selector;
  int selectedUnit;
  int candidate;
  u32 index;
  u32 lowestStat;
  u16 stat;

  unit = func_0035f160();
  selector = func_0035ed20(0);
  if (func_002c3430(unit,selector,0x100000,0x2e,0,(code *)&func_002c1ed0) == 1) {
    if (*(u16 *)(unit + 0x6a) == 1) {
      selectedUnit = *(int *)(unit + 0x38);
    }
    else {
      selectedUnit = 0;
      lowestStat = 0xfffffff;
      for (index = 0; index < *(u16 *)(unit + 0x6a); index++) {
        candidate = *(int *)(unit + index * 4 + 0x38);
        stat = func_002ffd70(*(u32 *)(*(int *)(candidate + 0x30) + 0xa2c));
        if (stat < lowestStat) {
          selectedUnit = candidate;
          lowestStat = stat;
        }
      }
    }
    func_0035f060(*(u32 *)(selectedUnit + 8) | 0x80000000);
  }
  else {
    func_0035f060(0xffffffff);
  }
  return 1;
}

// FUN_002cf6b0

u32 func_002cf6b0(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern u32 func_002c3430(u32,u32,u32,u16,int,code *);
  u32 unit;
  u32 selector;
  int selectedUnit;
  int candidate;
  u32 index;
  u32 lowestStat;
  u16 stat;

  unit = func_0035f160();
  selector = func_0035ed20(0);
  if (func_002c3430(unit,selector,0,0x2f,0,(code *)&func_002c1ed0) == 1) {
    if (*(u16 *)(unit + 0x6a) == 1) {
      selectedUnit = *(int *)(unit + 0x38);
    }
    else {
      selectedUnit = 0;
      lowestStat = 0xfffffff;
      for (index = 0; index < *(u16 *)(unit + 0x6a); index++) {
        candidate = *(int *)(unit + index * 4 + 0x38);
        stat = func_002ffd70(*(u32 *)(*(int *)(candidate + 0x30) + 0xa2c));
        if (stat < lowestStat) {
          selectedUnit = candidate;
          lowestStat = stat;
        }
      }
    }
    func_0035f060(*(u32 *)(selectedUnit + 8) | 0x80000000);
  }
  else {
    func_0035f060(0xffffffff);
  }
  return 1;
}

// FUN_002cf7e0

u32 func_002cf7e0(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern u32 func_0029a210(u32);
  extern s32 func_002c5fc0(u32,u32,s16,s32);
  u32 unit;
  u32 selector;
  u32 actionId;
  u32 mode;
  u32 target;
  s32 result;

  unit = func_0035f160();
  selector = func_0035ed20(0);
  actionId = func_0035ed20(1);
  mode = func_0035ed20(2);
  target = func_0029a210(selector & 0xfffffff);
  result = func_002c5fc0(unit,target,(s16)actionId,mode);
  func_0035f060(result);
  return 1;
}

// FUN_002cf890

u32 func_002cf890(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern u32 func_0029a210(u32);
  extern s32 func_002c6300(u32,u32,s16,s32);
  u32 unit;
  u32 selector;
  u32 actionId;
  u32 mode;
  u32 target;
  s32 result;

  unit = func_0035f160();
  selector = func_0035ed20(0);
  actionId = func_0035ed20(1);
  mode = func_0035ed20(2);
  target = func_0029a210(selector & 0xfffffff);
  result = func_002c6300(unit,target,(s16)actionId,mode);
  func_0035f060(result);
  return 1;
}

// FUN_002cf940

u32 func_002cf940(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern u32 func_0029a210(u32);
  extern s32 func_002c5030(u32,u32,u32,u32);
  u32 unit;
  u32 selector;
  u32 actionId;
  u32 mode;
  u32 target;
  s32 result;

  unit = func_0035f160();
  selector = func_0035ed20(0);
  actionId = func_0035ed20(1);
  mode = func_0035ed20(2);
  target = func_0029a210(selector & 0xfffffff);
  result = func_002c5030(unit,target,actionId,mode);
  func_0035f060(result);
  return 1;
}

// FUN_002cf9f0

u32 func_002cf9f0(void)
{
  extern u32 func_0035f160(void);
  extern s16 func_003082f0(u32,u16);
  u32 unit;
  s16 result;

  unit = func_0035f160();
  result = func_003082f0(*(u32 *)(*(int *)(unit + 0x30) + 0xa2c),0);
  func_0035f060(result);
  return 1;
}

// FUN_002cfa40

u32 func_002cfa40(void)

{
  int unit = 0;
  long excluded = 0;
  u16 stat = 0;
  int selectedUnit = 0;
  u32 lowestStat = 0;

  selectedUnit = 0;
  lowestStat = 0xfffffff;
  for (unit = *(int *)(DAT_007ce3ec + 0x14c); unit != 0; unit = *(int *)(unit + 0x4a8)) {
    if (((((*(u16 *)(unit + 0x1a) & 1) != 0) && ((*(u16 *)(unit + 0x1a) & 8) != 0)) &&
        (*(u8 *)(*(int *)(unit + 0x30) + 0xa2) == 0)) &&
       (excluded = func_0030b5a0(*(u32 *)(*(int *)(unit + 0x30) + 0xa2c),0), excluded == 0)) {
      stat = func_002ffd70(*(u32 *)(*(int *)(unit + 0x30) + 0xa2c));
      if (stat < lowestStat) {
        selectedUnit = unit;
        lowestStat = stat;
      }
    }
  }
  func_0035f060(*(u32 *)(selectedUnit + 8) | 0x80000000);
  return 1;
}

// FUN_002cfb20

u32 func_002cfb20(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern u32 func_002c3430(u32,u32,u32,u16,int,code *);
  u32 unit;
  u32 selector;
  int selectedUnit;
  int candidate;
  u32 index;
  u32 lowestStat;
  u16 stat;

  unit = func_0035f160();
  selector = func_0035ed20(0);
  if (func_002c3430(unit,selector,0,0x2c,0,(code *)&func_002c30f0) == 1) {
    if (*(u16 *)(unit + 0x6a) == 1) {
      selectedUnit = *(int *)(unit + 0x38);
    }
    else {
      selectedUnit = 0;
      lowestStat = 0xfffffff;
      for (index = 0; index < *(u16 *)(unit + 0x6a); index++) {
        candidate = *(int *)(unit + index * 4 + 0x38);
        stat = func_002ffd70(*(u32 *)(*(int *)(candidate + 0x30) + 0xa2c));
        if (stat < lowestStat) {
          selectedUnit = candidate;
          lowestStat = stat;
        }
      }
    }
    func_0035f060(*(u32 *)(selectedUnit + 8) | 0x80000000);
  }
  else {
    func_0035f060(0xffffffff);
  }
  return 1;
}

// FUN_002cfc50

u32 func_002cfc50(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern u32 func_002c3430(u32,u32,u32,u16,int,code *);
  u32 unit;
  u32 selector;
  int selectedUnit;
  int candidate;
  u32 index;
  u32 lowestStat;
  u16 stat;

  unit = func_0035f160();
  selector = func_0035ed20(0);
  if (func_002c3430(unit,selector,0x100000,0x2c,0,(code *)&func_002c30f0) == 1) {
    if (*(u16 *)(unit + 0x6a) == 1) {
      selectedUnit = *(int *)(unit + 0x38);
    }
    else {
      selectedUnit = 0;
      lowestStat = 0xfffffff;
      for (index = 0; index < *(u16 *)(unit + 0x6a); index++) {
        candidate = *(int *)(unit + index * 4 + 0x38);
        stat = func_002ffd70(*(u32 *)(*(int *)(candidate + 0x30) + 0xa2c));
        if (stat < lowestStat) {
          selectedUnit = candidate;
          lowestStat = stat;
        }
      }
    }
    func_0035f060(*(u32 *)(selectedUnit + 8) | 0x80000000);
  }
  else {
    func_0035f060(0xffffffff);
  }
  return 1;
}

// FUN_002cfd80

u32 func_002cfd80(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern u32 func_002c3430(u32,u32,u32,u16,int,code *);
  u32 unit;
  u32 selector;
  int selectedUnit;
  int candidate;
  u32 index;
  u32 lowestStat;
  u16 stat;

  unit = func_0035f160();
  selector = func_0035ed20(0);
  if (func_002c3430(unit,selector,0,0x2d,0,(code *)&func_002c30f0) == 1) {
    if (*(u16 *)(unit + 0x6a) == 1) {
      selectedUnit = *(int *)(unit + 0x38);
    }
    else {
      selectedUnit = 0;
      lowestStat = 0xfffffff;
      for (index = 0; index < *(u16 *)(unit + 0x6a); index++) {
        candidate = *(int *)(unit + index * 4 + 0x38);
        stat = func_002ffd70(*(u32 *)(*(int *)(candidate + 0x30) + 0xa2c));
        if (stat < lowestStat) {
          selectedUnit = candidate;
          lowestStat = stat;
        }
      }
    }
    func_0035f060(*(u32 *)(selectedUnit + 8) | 0x80000000);
  }
  else {
    func_0035f060(0xffffffff);
  }
  return 1;
}

// FUN_002cfeb0 NONMATCHING

u32 func_002cfeb0(void)

{
  int iVar1 = 0;
  int iVar2 = 0;
  long lVar3 = 0;
  u32 uVar4 = 0;
  int aiStack_30 [12] = {0};
  
  iVar2 = func_0035f160();
  iVar2 = (int)func_002c08c0(iVar2 + 0x88);
  if ((iVar2 == 0) || (*(char *)(*(int *)(iVar2 + 0x30) + 0xa2) != '\x01')) {
    uVar4 = 0;
    for (iVar2 = *(int *)(DAT_007ce3ec + 0x14c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x4a8)) {
      if (((((*(u16 *)(iVar2 + 0x1a) & 1) != 0) && ((*(u16 *)(iVar2 + 0x1a) & 8) != 0)) &&
          (*(char *)(*(int *)(iVar2 + 0x30) + 0xa2) == '\x01')) &&
         ((iVar1 = *(int *)(*(int *)(iVar2 + 0x30) + 0xa2c), iVar1 == 0 ||
          (lVar3 = func_0030b5a0(iVar1,0), lVar3 == 0)))) {
        aiStack_30[uVar4] = iVar2;
        uVar4 = uVar4 + 1 & 0xffff;
      }
    }
    iVar2 = func_002ffbc0(uVar4);
    iVar2 = aiStack_30[iVar2];
  }
  func_0035f060(*(u32 *)(iVar2 + 8) | 0x80000000);
  return 1;
}

// FUN_002cffc0 NONMATCHING

u32 func_002cffc0(void)

{
  u16 uVar1 = 0;
  u16 uVar2 = 0;
  int iVar3 = 0;
  int iVar4 = 0;
  u32 uVar5 = 0;
  int iVar6 = 0;
  u32 uVar7 = 0;
  u32 uVar8 = 0;
  
  iVar3 = func_0035f160();
  uVar7 = func_0035ed20(0);
  iVar4 = func_0029a210(uVar7 & 0xfffffff);
  iVar3 = *(int *)(iVar3 + 0x30);
  uVar2 = func_003082f0(*(u32 *)(iVar3 + 0xa2c),0);
  uVar7 = func_0030b4b0(*(u32 *)(*(int *)(iVar4 + 0x30) + 0xa2c),uVar2);
  if ((uVar7 & 0x8000000) == 0) {
    uVar5 = func_00308ba0(*(u32 *)(iVar3 + 0xa2c));
    iVar6 = func_00308bb0(*(u32 *)(iVar3 + 0xa2c));
    for (uVar8 = 0; uVar8 < (uVar5 & 0xffff); uVar8 = uVar8 + 1) {
      uVar1 = *(u16 *)(iVar6 + uVar8 * 2);
      if ((uVar1 != 0) && (uVar1 < 0x1d0)) {
        uVar2 = func_003082f0(*(u32 *)(iVar3 + 0xa2c));
        uVar7 = func_0030b4b0(*(u32 *)(*(int *)(iVar4 + 0x30) + 0xa2c),uVar2);
        if ((uVar7 & 0x8000000) != 0) {
          func_0035f060(uVar2);
          return 1;
        }
      }
    }
    func_0035f060(0xffffffffffffffff);
  }
  else {
    func_0035f060(uVar2);
  }
  return 1;
}

// FUN_002d0150 NONMATCHING

u32 func_002d0150(void)

{
  int iVar1 = 0;
  int iVar2 = 0;
  long lVar3 = 0;
  u32 uVar4 = 0;
  int aiStack_30 [12] = {0};
  
  func_0035f160();
  iVar2 = (int)func_002c08c0(*(int *)(DAT_007ce3ec + 0x148) + 0x88);
  if ((iVar2 == 0) || (*(char *)(*(int *)(iVar2 + 0x30) + 0xa2) != '\x01')) {
    uVar4 = 0;
    for (iVar2 = *(int *)(DAT_007ce3ec + 0x14c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x4a8)) {
      if (((((*(u16 *)(iVar2 + 0x1a) & 1) != 0) && ((*(u16 *)(iVar2 + 0x1a) & 8) != 0)) &&
          (*(char *)(*(int *)(iVar2 + 0x30) + 0xa2) == '\x01')) &&
         ((iVar1 = *(int *)(*(int *)(iVar2 + 0x30) + 0xa2c), iVar1 == 0 ||
          (lVar3 = func_0030b5a0(iVar1,0), lVar3 == 0)))) {
        aiStack_30[uVar4] = iVar2;
        uVar4 = uVar4 + 1 & 0xffff;
      }
    }
    iVar2 = func_002ffbc0(uVar4);
    iVar2 = aiStack_30[iVar2];
  }
  func_0035f060(*(u32 *)(iVar2 + 8) | 0x80000000);
  return 1;
}

// FUN_002d0270 NONMATCHING

u32 func_002d0270(void)

{
  int iVar1 = 0;
  int iVar2 = 0;
  u64 uVar3 = 0;
  long lVar4 = 0;
  u32 uVar5 = 0;
  u32 uVar6 = 0;
  u32 uVar7 = 0;
  int iVar8 = 0;
  int iVar9 = 0;
  
  uVar3 = func_0035f160();
  iVar9 = 0;
  uVar6 = 0xfffffff;
  iVar8 = 0;
  uVar7 = uVar6;
  for (iVar1 = *(int *)(DAT_007ce3ec + 0x14c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x4a8)) {
    if (((((*(u16 *)(iVar1 + 0x1a) & 1) != 0) && ((*(u16 *)(iVar1 + 0x1a) & 8) != 0)) &&
        (iVar2 = *(int *)(iVar1 + 0x30), *(char *)(iVar2 + 0xa2) == '\x01')) &&
       (lVar4 = func_0030b5a0(*(u32 *)(iVar2 + 0xa2c),0), lVar4 == 0)) {
      uVar5 = func_002ffd70(*(u32 *)(iVar2 + 0xa2c));
      uVar5 = uVar5 & 0xffff;
      if ((uVar5 < uVar6) && (lVar4 = func_002c5030(uVar3,iVar1,0,0), -1 < lVar4)) {
        uVar6 = uVar5;
        iVar8 = iVar1;
      }
      if (uVar5 < uVar7) {
        uVar7 = uVar5;
        iVar9 = iVar1;
      }
    }
  }
  if (iVar8 == 0) {
    func_0035f060(*(u32 *)(iVar9 + 8) | 0x80000000);
  }
  else {
    func_0035f060(*(u32 *)(iVar8 + 8) | 0x80000000);
  }
  return 1;
}

// FUN_002d03e0 NONMATCHING

u32 func_002d03e0(void)

{
  u16 uVar1 = 0;
  int iVar2 = 0;
  int iVar3 = 0;
  u32 uVar4 = 0;
  u32 uVar5 = 0;
  u32 uVar6 = 0;
  long lVar7 = 0;
  u32 uVar8 = 0;
  u32 uVar9 = 0;
  int iVar10 = 0;
  
  uVar5 = func_0035ed20(0);
  iVar3 = func_0035ed20(1);
  uVar6 = func_0035ed20(2);
  iVar10 = 0;
  uVar9 = 0xfffffff;
  for (iVar2 = *(int *)(DAT_007ce3ec + 0x14c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x4a8)) {
    if (((((*(u16 *)(iVar2 + 0x1a) & 1) != 0) && ((*(u16 *)(iVar2 + 0x1a) & 8) != 0)) &&
        (*(char *)(*(int *)(iVar2 + 0x30) + 0xa2) == '\0')) &&
       (((uVar6 & 0x80000) != 0 ||
        (lVar7 = func_0030b5a0(*(u32 *)(*(int *)(iVar2 + 0x30) + 0xa2c),0), lVar7 == 0)))) {
      uVar8 = func_002ffd70(*(u32 *)(*(int *)(iVar2 + 0x30) + 0xa2c));
      uVar8 = uVar8 & 0xffff;
      if (((uVar5 <= uVar8) &&
          (uVar1 = *(u16 *)(*(int *)(*(int *)(iVar2 + 0x30) + 0xa2c) + 8),
           uVar4 = func_002ffdf0(*(u32 *)(*(int *)(iVar2 + 0x30) + 0xa2c)),
           (u32)uVar1 * 100 <= (uVar4 & 0xffff) * iVar3)) &&
         (((uVar6 == 0 ||
           (lVar7 = func_00300580(*(u32 *)(*(int *)(iVar2 + 0x30) + 0xa2c),uVar6), lVar7 != 0)
           ) && (uVar8 < uVar9)))) {
        uVar9 = uVar8;
        iVar10 = iVar2;
      }
    }
  }
  if (iVar10 == 0) {
    func_0035f060(0xffffffffffffffff);
  }
  else {
    func_0035f060(*(u32 *)(iVar10 + 8) | 0x80000000);
  }
  return 1;
}

// FUN_002d05c0

u32 func_002d05c0(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern void func_002efc90(void *);
  extern void func_002efcd0(void *);
  char *unit;
  u16 encounterId;
  s32 result;

  unit = (char *)func_0035f160();
  *(u16 *)(unit + 0x6e) = func_0035ed20(0);
  encounterId = *(u16 *)(unit + 0x6e);
  switch (encounterId) {
  case 0x132:
  case 0x68:
    *(u16 *)(unit + 0x6c) = 8;
    func_002efc90(unit);
    break;
  case 0x133:
    *(u16 *)(unit + 0x6c) = 8;
    func_002efcd0(unit);
    break;
  default:
    *(u16 *)(unit + 0x6c) = 9;
    break;
  }
  *(u16 *)(unit + 0x76) = func_0035ed20(1);
  *(u16 *)(unit + 0x78) = func_0035ed20(2);
  *(u16 *)(unit + 0x7a) = func_0035ed20(3);
  result = (*(s32 (**)(void *,u32))PTR_FUN_00697620)(unit,0);
  if (result == 0) {
    (*(s32 (**)(void *,u32))PTR_FUN_006975e0)(unit,0);
  }
  return 1;
}

// FUN_002d06e0

u32 func_002d06e0(void)

{
  extern u32 func_0035f160(void);
  u32 uVar1 = 0;

  func_002eab70();
  uVar1 = func_0035f160();
  *(u16 *)(uVar1 + 0x6c) = 8;
  return 1;
}

// FUN_002d0720

u32 func_002d0720(void)

{
  extern u32 func_0035f160(void);
  u32 uVar1 = 0;

  func_002eabb0();
  uVar1 = func_0035f160();
  *(u16 *)(uVar1 + 0x6c) = 8;
  return 1;
}

// FUN_002d0760

u32 func_002d0760(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern void func_002c6a00(void *,void *,u16);
  char *unit;
  u32 selector;
  u16 encounterId;
  s32 result;

  unit = (char *)func_0035f160();
  selector = func_0035ed20(0);
  encounterId = *(u16 *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8);
  switch (encounterId) {
  case 0x1a5:
    func_002c6a00(unit,unit + 0x38,0x16b);
    func_002ec560(selector);
    break;
  case 0x1b4:
    func_002c6a00(unit,unit + 0x38,0x126);
    func_002f6bf0(selector);
    break;
  }
  result = (*(s32 (**)(void *,u32))PTR_FUN_00697620)(unit,0);
  if (result == 0) {
    (*(s32 (**)(void *,u32))PTR_FUN_006975e0)(unit,0);
  }
  return 1;
}

// FUN_002d0860

u32 func_002d0860(void)
{
    u16 encounterId;

    encounterId = *(u16*)(*(u8**)(iGpffffb6fc + 0xbbc) + 8);
    switch (encounterId)
    {
    case 0x1a5:
        func_0035f060(func_002ec590() != 0);
        break;
    case 0x1b4:
        func_0035f060(func_002f6c20() != 0);
        break;
    }
    return 1;
}

// FUN_002d08e0

u32 func_002d08e0(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern void func_00288f80(u32,u32);
  extern void func_002c6a00(void *,void *,u16);
  char *unit;
  u32 selector;
  u32 actionId;

  unit = (char *)func_0035f160();
  selector = func_0035ed20(0);
  actionId = func_0035ed20(1);
  func_00288f80(*(u32 *)(unit + 0x30),selector);
  func_002c6a00(unit,unit + 0x38,(u16)actionId);
  return 1;
}


u32 func_002d0970(void)

{
  u64 uVar1 = 0;
  
  if (*(u16 *)(*(int *)(iGpffffb6fc + 0xbbc) + 8) == 0x1b0) {
    uVar1 = func_002f5320();
    func_0035f060(uVar1);
  }
  else {
    func_0035f060(7);
  }
  return 1;
}

// FUN_002d09d0

u32 func_002d09d0(void)

{
  extern u32 func_0035f160(void);
  u32 uVar1 = 0;

  uVar1 = func_0035f160();
  if (*(u16 *)(*(int *)(iGpffffb6fc + 0xbbc) + 8) == 0x1b0) {
    func_002f5030(uVar1);
  }
  *(u16 *)((int)uVar1 + 0x6c) = 5;
  return 1;
}

// FUN_002d0a30 NONMATCHING

void func_002d0a30(void)
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
  return;
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
  base = (u32)*(u8* volatile *)&iGpffffb6fc;
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
  base = (u32)*(u8* volatile *)&iGpffffb6fc;
  iVar1 <<= 2;
  *(u32 *)(iVar1 + base + 0xd30) = uVar2;
  return 1;
}

// FUN_002d1560
u32 func_002d1560(void)
{
  return 1;
}

/* ---- Straggler recovery: 0x2BD4F0-0x2D0970 ---- */


// FUN_002BF370 MATCHING
void FUN_002bf370(u32 param_1)

{
  int result;
  
  FUN_001fdda0();
  result = FUN_002d1a70();
  if (result == 1) {
    *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x4000;
    FUN_001ff370();
  }
  result = FUN_00195540(param_1);
  (*DAT_0096017c)(result);
  *(u32 *)(DAT_007ce3ec + 0xd1c) = 0;
}

// FUN_002D0970
u32 FUN_002d0970(void)

{
  extern u32 FUN_002f5320(void);
  extern void FUN_0035f060(u32);
  u32 uVar1;
  
  if (*(u16 *)(*(int *)(iGpffffb6fc + 0xbbc) + 8) == 0x1b0) {
    uVar1 = FUN_002f5320();
    FUN_0035f060(uVar1);
  }
  else {
    FUN_0035f060(7);
  }
  return 1;
}
