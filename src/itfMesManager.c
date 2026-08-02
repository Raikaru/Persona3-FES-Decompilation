#include "temporary.h"
#include "itfMesManager.h"
#include "Script/scr.h"
#include "Kosaka/k_assert.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))
#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif
extern u16 DAT_006a1bd0[];
#pragma alias DAT_006a1bd0_signed DAT_006a1bd0
extern s16 DAT_006a1bd0_signed[];
extern f32 DAT_007cad94;
extern u32 DAT_007ce620;
extern u32 DAT_007ce63c;
extern u32 DAT_007ce654;
extern u32 DAT_007e094c;
extern u16 DAT_007e094e;
#pragma alias DAT_007e094e_abs DAT_007e094e
extern u8 DAT_007e094e_abs[];
extern u32 DAT_007e0952;
extern u32 DAT_007e0958;
extern u32 DAT_007e095a;
extern u32 DAT_00958be8;
#pragma alias DAT_00958be8_abs DAT_00958be8
extern u8 DAT_00958be8_abs[];
extern u32 DAT_00959ec0;
#pragma alias DAT_00959ec0_abs DAT_00959ec0
extern u32 DAT_00959ec0_abs[];
extern u32 DAT_00959ec4;
#pragma alias DAT_00959ec4_abs DAT_00959ec4
extern u8 DAT_00959ec4_abs[];
extern u32 DAT_00959ec8;
#pragma alias DAT_00959ec8_abs DAT_00959ec8
extern u8 DAT_00959ec8_abs[];
extern u32 DAT_00959ecc;
#pragma alias DAT_00959ecc_abs DAT_00959ecc
extern u8 DAT_00959ecc_abs[];
extern u32 DAT_00959ed0;
#pragma alias DAT_00959ed0_abs DAT_00959ed0
extern u8 DAT_00959ed0_abs[];
extern u32 DAT_00959ed8;
extern u32 DAT_00959ee0;
#pragma alias DAT_00959ee0_abs DAT_00959ee0
extern u8 DAT_00959ee0_abs[];
extern u32 DAT_00959eec;
#pragma alias itfMesEntries DAT_00959eec
extern u32 itfMesEntries[];
#pragma alias DAT_00959eec_abs DAT_00959eec
extern u32 DAT_00959eec_abs[];
#pragma alias DAT_0095abf0_abs DAT_0095abf0
extern u8 DAT_0095abf0_abs[];
#pragma alias DAT_006a1ae0_abs DAT_006a1ae0
extern u8 DAT_006a1ae0_abs[];
#pragma alias DAT_006a1b00_abs DAT_006a1b00
extern u8 DAT_006a1b00_abs[];
#pragma alias DAT_006a1ba0_abs DAT_006a1ba0
extern u8 DAT_006a1ba0_abs[];
#pragma alias DAT_006a1bc0_abs DAT_006a1bc0
extern u8 DAT_006a1bc0_abs[];
#pragma alias DAT_006a20c0_abs DAT_006a20c0
extern u8 DAT_006a20c0_abs[];
extern code DAT_00960178;
#pragma alias DAT_00960178_abs DAT_00960178
extern code DAT_00960178_abs[];
extern u8 * PTR_LAB_007bb150;
#pragma alias DAT_00959870_abs DAT_00959870
extern u8 DAT_00959870_abs[];
#pragma alias DAT_00958bf0_abs DAT_00958bf0
extern u8 DAT_00958bf0_abs[];
#pragma alias DAT_00959eb0_abs DAT_00959eb0
extern s8 DAT_00959eb0_abs[];
extern u8 DAT_00959870[];
extern u8 DAT_00958bf0[];
extern u32 gp0xffffb7f8;
extern u32 gp0xffffb7fc;
extern u32 gp0xffffb800;
extern u64 gp0xffffa7c8;
extern s8 DAT_00959eb0[];
extern code DAT_00960178;
#pragma alias DAT_006a1be0_abs DAT_006a1be0
extern u8 DAT_006a1be0_abs[];
#pragma alias DAT_006a1a70_abs DAT_006a1a70
extern u8 DAT_006a1a70_abs[];
#pragma alias DAT_00959ed8_abs DAT_00959ed8
extern u8 DAT_00959ed8_abs[];
#pragma alias DAT_006a1b58_abs DAT_006a1b58
extern u8 DAT_006a1b58_abs[];
#pragma alias DAT_006a1b68_abs DAT_006a1b68
extern u8 DAT_006a1b68_abs[];
#pragma alias DAT_006a1b80_abs DAT_006a1b80
extern u8 DAT_006a1b80_abs[];

extern void thunk_FUN_003a6334();
#pragma alias thunk_FUN_003a6334_typed thunk_FUN_003a6334
extern void thunk_FUN_003a6334_typed(int param_1,int param_2,int param_3);
extern void thunk_FUN_003a6360();
#define ITFMES_HANDLE_STRIDE            0x34
#define ITFMES_HANDLE_ACTIVE_MES_OFFSET 0x2c

typedef struct ItfMesHandleSystem
{
    u8 bytes[0x100];
} ItfMesHandleSystem;

typedef struct ItfMesTextWork
{
  u8 unknown_00[0x10];
  u32 flags;
  u16 unknown_14;
  s16 lineStart;
  s16 lineEnd;
} ItfMesTextWork;

typedef struct ItfMesChoiceEntry
{
  s16 type;
  s16 value;
} ItfMesChoiceEntry;

typedef struct ItfMesChoiceWork
{
  u8 unknown_00[0x26];
  s16 count;
  ItfMesChoiceEntry entries[15];
} ItfMesChoiceWork;

static ItfMesHandleSystem sItfMesHandleSystem;

extern void* FUN_003b49a0(void* param);
#pragma alias FUN_003a6b00_direct FUN_003a6b00
extern void FUN_003a6b00_direct(u32 activeMes);
#pragma alias FUN_003a4ef0_direct FUN_003a4ef0
extern void FUN_003a4ef0_direct(u32 *param_1);
#pragma alias FUN_003b4a20_direct FUN_003b4a20
extern void FUN_003b4a20_direct(void *entry, void *list);
extern void FUN_005225a8();
extern void FUN_003a8d60();
extern s32 D_00959EC0[];
extern u8 D_00959ED0[];
extern s32 FUN_0035f140(void);
extern void FUN_003b0bb0(int param_1, u8 param_2);
extern int FUN_003b0c20();
extern int FUN_003b0ce0();
extern void thunk_FUN_003b0e04(int param_1, u8 param_2);
#pragma alias FUN_003b2940_u8 FUN_003b2940
extern u32 FUN_003b2940_u8(u32 param_1,u32 param_2,u8 param_3,u8 param_4,
                           u32 param_5,u32 param_6,u32 param_7,u32 param_8);
#pragma alias thunk_FUN_003b0e04_u8 thunk_FUN_003b0e04
extern int thunk_FUN_003b0e04_u8(u32 param_1,u8 param_2);
#pragma alias FUN_003b1300_typed FUN_003b1300
extern int FUN_003b1300_typed(u32 param_1);
#pragma alias FUN_003b1330_typed FUN_003b1330
extern int FUN_003b1330_typed(u32 param_1,u32 param_2);
#pragma alias thunk_FUN_003b0e54_f32 thunk_FUN_003b0e54
extern void thunk_FUN_003b0e54_f32(u64 param_1, f32 param_2);
extern s32 FUN_0035ed20(s32 index);
extern char D_006A1A80[];
extern char D_006A1AC0[];
extern char D_006A1B30[];

u32 FUN_003a8b00();
void FUN_003a8dc0();
void FUN_003a8ea0();
void FUN_003a8fb0();
void FUN_003a9080();
int FUN_003a95f0();
int FUN_003a9630();
int FUN_003a9670();
int FUN_003a96b0();
void FUN_003ab2a0();



/* Region 0x390000-0x3CFFFF recovered prototypes */
s32 itfMesMngInitialize(BmdHeader* bmdHeader);
void itfMesMngDestroyHandle(s32 mesHandleIdx);
void itfMesMngChangeWindowType(s32 mesHandleIdx, s32 type, u32 param_3);
u32 itfMesMngCheckBmdMagic(BmdHeader* bmdHeader);
void itfMesMng003a3ba0(s32 mesHandleIdx, u32 param_2);
void itfMesMng003a3e10(s32 mesHandleIdx, u32 param_2);
void itfMesMng003a3e90(s32 mesHandleIdx, u32 param_2);
u32 itfMesMng003a3da0(s32 mesHandleIdx);
s16 itfMesMng003a3f20(s32 mesHandleIdx);
u32 FUN_003a2150(void);
u32 FUN_003a2260(void);
u32 FUN_003a2440(void);
s8 FUN_003a2580(int param_1);
void FUN_003a25f0(int param_1,u8 param_2);
u32 FUN_003a2660(void);
s16 FUN_003a2750(int param_1);
void FUN_003a27c0(int param_1,u16 param_2);
s16 FUN_003a2830(int param_1);
u32 FUN_003a28a0(void);
u32 FUN_003a2900(void);
u32 FUN_003a2970(void);
void FUN_003a2a30(s32 param_1);
#pragma alias FUN_003a2a30_s32 FUN_003a2a30
extern void FUN_003a2a30_s32(s32 param_1);
u32 FUN_003a2b30(void);
u32 FUN_003a2c10(void);
int FUN_003a2c90(int param_1,int param_2);
u32 FUN_003a2ef0(u32 param_1);
#pragma alias FUN_003a2ef0_typed FUN_003a2ef0
extern u32 FUN_003a2ef0_typed(BmdHeader* param_1);
#pragma alias FUN_003a2c90_typed FUN_003a2c90
extern int FUN_003a2c90_typed(void* param_1,int param_2);
u32 FUN_003a3010(int param_1);
u32 FUN_003a30c0(s32 param_1,s32 param_2,u16 param_3);
void FUN_003a3420(int param_1,s32 param_2);
void FUN_003a3470(u32 *param_1,s32 param_2);
void FUN_003a3530(u32 *param_1);
#pragma alias FUN_003a3530_direct FUN_003a3530
extern void FUN_003a3530_direct(u32 *param_1);
void FUN_003a3680(u32 *param_1);
#pragma alias FUN_003a3680_direct FUN_003a3680
extern void FUN_003a3680_direct(u32 *param_1);
void FUN_003a37c0(int param_1,u32 param_2);
#pragma alias FUN_003a37c0_direct FUN_003a37c0
extern void FUN_003a37c0_direct();
#pragma alias FUN_003a3ab0_direct FUN_003a3ab0
extern void FUN_003a3ab0_direct(int param_1);
void FUN_003a3ab0(int param_1);
void FUN_003a3b00(u8 *param_1);
#pragma alias FUN_003a3b00_typed FUN_003a3b00
extern void FUN_003a3b00_typed(u32 param_1);
void FUN_003a3c10(int param_1,int param_2);
void FUN_003a3ce0(int param_1,int param_2,int param_3);
u32 FUN_003a3f90(int param_1,int param_2);
#pragma alias FUN_003a3f90_typed FUN_003a3f90
extern u32 FUN_003a3f90_typed(s32 param_1, u32 param_2);
void FUN_003a4010(int param_1,int param_2,int param_3,u32 param_4);
void FUN_003a4220(int param_1,u64 param_2,u64 param_3);
void FUN_003a4270(int param_1);
u32 FUN_003a42c0(int param_1,u32 param_2);
u32 FUN_003a4360(u32 param_1,int param_2);
u32 FUN_003a4a70(int param_1, int param_2, int param_3);
u32 FUN_003a4b90(int param_1,u32 param_2,u32 param_3);
void FUN_003a4ce0(void);
void FUN_003a4dd0(int param_1);
#pragma alias FUN_003a4dd0_typed FUN_003a4dd0
extern void FUN_003a4dd0_typed(int param_1);
void FUN_003a4ef0(u32 *param_1);
void FUN_0035ac90(int output, int source, int end, u32 length);
void FUN_003a5030(int param_1);
#pragma alias FUN_003a5030_typed FUN_003a5030
extern void FUN_003a5030_typed(int param_1);
int FUN_003a50e0(int param_1,int param_2);
#pragma alias FUN_003a50e0_typed FUN_003a50e0
extern int FUN_003a50e0_typed(int param_1, int param_2);
#pragma alias FUN_003a5940_typed FUN_003a5940
extern int FUN_003a5940_typed(int param_1, int param_2);
#pragma alias FUN_003a6460_typed FUN_003a6460
extern int FUN_003a6460_typed(int param_1);
int FUN_003a5100(int param_1);
#pragma alias FUN_003a5100_typed FUN_003a5100
extern int FUN_003a5100_typed(int param_1);
u32 FUN_003a5120(int param_1,int param_2);
u32 FUN_003a51a0(int param_1);
void FUN_003a5210(int param_1,u64 param_2,u8 param_3,u8 param_4,  s16 param_5);
u64  FUN_003a52c0(u32 param_1,s32 param_2,f32 param_3,s32 param_4,
                  s32 param_5,s32 param_6,s32 param_7,s32 param_8);
u64  FUN_003a53b0(int param_1,int param_2,f32 param_3,int param_4,int param_5,  u32 param_6,int param_7,int param_8,int param_9);
#pragma alias FUN_003a53b0_8 FUN_003a53b0
#pragma alias FUN_003a53b0_typed FUN_003a53b0
extern u64 FUN_003a53b0_typed(int param_1,int param_2,f32 param_3,int param_4,int param_5,
                              u32 param_6,int param_7,int param_8,int param_9);
#pragma alias FUN_003a53b0_u32 FUN_003a53b0
extern u32 FUN_003a53b0_u32(int param_1,int param_2,f32 param_3,int param_4,int param_5,
                           u32 param_6,int param_7,int param_8,int param_9);
extern u64 FUN_003a53b0_8(int param_1,int param_2,u64 param_3,int param_4,int param_5,
                          u32 param_6,int param_7,int param_8);
#pragma alias FUN_003a53b0_8f FUN_003a53b0
extern u64 FUN_003a53b0_8f(int param_1,int param_2,f32 param_3,int param_4,int param_5,
                           u32 param_6,int param_7,int param_8,int param_9);
#pragma alias FUN_003a53b0_int FUN_003a53b0
extern u32 FUN_003a53b0_int(int param_1,int param_2,u32 param_3,int param_4,int param_5,
                            u32 param_6,int param_7,int param_8,int param_9);
#pragma alias FUN_003a5fd0_typed FUN_003a5fd0
void FUN_003a5540(int p1,int p2,u64 p3,int p4,int p5,int p6,int p7);
#pragma alias FUN_003b0ce0_typed FUN_003b0ce0
extern void FUN_003b0ce0_typed(u64 param_1,u64 param_2);
void FUN_003a5540(int p1,int p2,u64 p3,int p4,int p5,int p6,int p7);
u64 FUN_003a5570(u32 param_1,s32 param_2,f32 param_3,u32 param_4,s32 param_5,s32 param_6,s32 param_7,s32 param_8,s32 param_9);
u64  FUN_003a56f0(u32 param_1,s32 param_2,f32 param_3,u32 param_4,  s32 param_5,s32 param_6,s32 param_7,s32 param_8,s32 param_9,  int param_10,int param_11);
u32 FUN_003a5940(int param_1,int param_2);
void FUN_003a5980(u32 *param_1);
#pragma alias FUN_003a5980_typed FUN_003a5980
extern void FUN_003a5980_typed(u32 *param_1);
void FUN_003a5ca0(int param_1,int param_2,u32 param_3,int param_4);
#pragma alias FUN_003a5ca0_typed FUN_003a5ca0
extern void FUN_003a5ca0_typed(u32 param_1,long param_2,u64 param_3,long param_4);
void FUN_003a5ea0(int param_1,int param_2,u32 param_3);
#pragma alias FUN_003a5ea0_typed FUN_003a5ea0
extern void FUN_003a5ea0_typed(u32 param_1);
void FUN_003a5fd0(int param_1);
u32 FUN_003a6030(int param_1);
#pragma alias FUN_003a6030_typed FUN_003a6030
extern u32 FUN_003a6030_typed(u32 *param_1);
void FUN_003a6060(u8 *param_1,u64 param_2);
#pragma alias FUN_003a6060_typed FUN_003a6060
extern void FUN_003a6060_typed(u32 *param_1, u8 *param_2);
int FUN_003a6100(int param_1,u32 param_2);
#pragma alias FUN_003a6100_typed FUN_003a6100
extern s32 FUN_003a6100_typed(s32 param_1, u32 param_2);
u32 FUN_003a6140(u32 *param_1,int param_2,u32 param_3,u32 param_4,int param_5,  u32 param_6,s32 param_7,u32 param_8);
#pragma alias FUN_003a6140_typed FUN_003a6140
extern u32 FUN_003a6140_typed(u32 *param_1, s32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, s32 param_7, u32 param_8);
int FUN_003a628c(int param_1);
void FUN_003a62b0(int param_1,int param_2);
#pragma alias FUN_003a62b0_typed FUN_003a62b0
extern void FUN_003a62b0_typed(u32 param_1, u32 *param_2);
int FUN_003a62e0(int param_1,int param_2);
#pragma alias FUN_003a62e0_typed FUN_003a62e0
extern s32 FUN_003a62e0_typed(u32 param_1, u32 param_2);
static int FUN_003a6380();
#pragma alias FUN_003a6380_direct FUN_003a6380
extern void FUN_003a6380_direct(int param_1,int param_2,int param_3,u8 param_4);
void FUN_003a6410(int param_1,u32 param_2);
int FUN_003a6460(int param_1);
void FUN_003a64c0(int param_1);
#pragma alias FUN_003a64c0_typed FUN_003a64c0
extern void FUN_003a64c0_typed(u32 param_1);
void FUN_003a6520(u32 *param_1);
#pragma alias FUN_003a6520_typed FUN_003a6520
extern void FUN_003a6520_typed(u32 *param_1);
void FUN_003a67e0(u32 *param_1);
#pragma alias FUN_003a67e0_typed FUN_003a67e0
extern void FUN_003a67e0_typed(u32 *param_1);
void FUN_003a6900(u32 *param_1,long param_2);
void FUN_003a6930(u32 *param_1,long param_2);
#pragma alias FUN_003a6900_direct FUN_003a6900
extern void FUN_003a6900_direct(u32 *param_1,long param_2);
#pragma alias FUN_003a6930_direct FUN_003a6930
extern void FUN_003a6930_direct(u32 *param_1,long param_2);
void FUN_003a6980(u32 *param_1);
void FUN_003a69d0(u32 *param_1);
void FUN_003a6a10(int param_1);
void FUN_003a6a40(u8 *param_1,long param_2);
void FUN_003a6a80(int param_1,u16 param_2,u16 param_3);
#pragma alias FUN_003a6a80_typed FUN_003a6a80
extern void FUN_003a6a80_typed(int param_1,u16 param_2,u16 param_3);
void FUN_003a6b00(u32 *param_1);
void FUN_003a6b90(int param_1);
#pragma alias FUN_003a6b90_direct FUN_003a6b90
extern void FUN_003a6b90_direct(int param_1);
short * FUN_003a6c10(int param_1,short *param_2);
void FUN_003a6ca0(int param_1,int param_2,int param_3);
#pragma alias FUN_003a6ca0_typed FUN_003a6ca0
extern void FUN_003a6ca0_typed(int param_1,int param_2,int param_3);
void FUN_003a6e30(u32 *param_1);
void FUN_003a7120(u32 *param_1);
void FUN_003a7490(u32 *param_1);
void FUN_003a7940(int param_1,int param_2);
#pragma alias FUN_003a7940_typed FUN_003a7940
extern void FUN_003a7940_typed(u32 *param_1,int param_2);
u32 FUN_003a7a40(int param_1);
#pragma alias FUN_003a7a40_typed FUN_003a7a40
extern u32 FUN_003a7a40_typed(void);
void FUN_003a7cb0(int param_1,int param_2);
s16 FUN_003a7d60(int param_1);
void FUN_003a7dd0(int param_1);
void FUN_003a7e90(u32 *param_1);
void FUN_003a8080(u32 *param_1);
void FUN_003a8170(int param_1);
void FUN_003a8260(int param_1);
void FUN_003a8350(int param_1);
#pragma alias FUN_003a8080_direct FUN_003a8080
extern void FUN_003a8080_direct(u32 *param_1);
#pragma alias FUN_003a8170_direct FUN_003a8170
extern void FUN_003a8170_direct(u32 *param_1);
#pragma alias FUN_003a8260_direct FUN_003a8260
extern void FUN_003a8260_direct(u32 *param_1);
#pragma alias FUN_003a8350_direct FUN_003a8350
extern void FUN_003a8350_direct(u32 *param_1);
u64 FUN_003a8440(void);
u64 FUN_003a84c0(void);
void FUN_003a8530(void);
void FUN_003a8590(u32* param_1);
#pragma alias FUN_003a8590_direct FUN_003a8590
extern void FUN_003a8590_direct(u32 *param_1);
void FUN_003a8600(int param_1);
void FUN_003a8650(int param_1,u64 param_2,u64 param_3,u64 param_4,  u64 param_5,u64 param_6);
u64 FUN_003a8710(int param_2,int param_3,float param_1,int param_4,int param_5);
 #pragma alias FUN_003a8710_typed FUN_003a8710
extern u64 FUN_003a8710_typed(int param_2,int param_3,float param_1,int param_4,int param_5);
#pragma alias FUN_003a8710_u8 FUN_003a8710
extern u64 FUN_003a8710_u8(int param_2,int param_3,float param_1,u8 param_4,int param_5);

/* Region call-cast macros */
#define FUN_003a2150(...) ((u32 (*)(...))FUN_003a2150)(__VA_ARGS__)
#define FUN_003a2260(...) ((u32 (*)(...))FUN_003a2260)(__VA_ARGS__)
#define FUN_003a2440(...) ((u32 (*)(...))FUN_003a2440)(__VA_ARGS__)
#define FUN_003a2580(...) ((s8 (*)(...))FUN_003a2580)(__VA_ARGS__)
#define FUN_003a25f0(...) ((void (*)(...))FUN_003a25f0)(__VA_ARGS__)
#define FUN_003a2660(...) ((u32 (*)(...))FUN_003a2660)(__VA_ARGS__)
#define FUN_003a2750(...) ((s16 (*)(...))FUN_003a2750)(__VA_ARGS__)
#define FUN_003a27c0(...) ((void (*)(...))FUN_003a27c0)(__VA_ARGS__)
#define FUN_003a2830(...) ((s16 (*)(...))FUN_003a2830)(__VA_ARGS__)
#define FUN_003a28a0(...) ((u32 (*)(...))FUN_003a28a0)(__VA_ARGS__)
#define FUN_003a2900(...) ((u32 (*)(...))FUN_003a2900)(__VA_ARGS__)
#define FUN_003a2970(...) ((u32 (*)(...))FUN_003a2970)(__VA_ARGS__)
#define FUN_003a2a30(...) ((void (*)(...))FUN_003a2a30)(__VA_ARGS__)
#define FUN_003a2b30(...) ((u32 (*)(...))FUN_003a2b30)(__VA_ARGS__)
#define FUN_003a2c10(...) ((u32 (*)(...))FUN_003a2c10)(__VA_ARGS__)
#define FUN_003a2c90(...) ((int (*)(...))FUN_003a2c90)(__VA_ARGS__)
#define FUN_003a2ef0(...) ((u32 (*)(...))FUN_003a2ef0)(__VA_ARGS__)
#define FUN_003a3010(...) ((u32 (*)(...))FUN_003a3010)(__VA_ARGS__)
#define FUN_003a30c0(...) ((u32 (*)(...))FUN_003a30c0)(__VA_ARGS__)
#define FUN_003a3420(...) ((void (*)(...))FUN_003a3420)(__VA_ARGS__)
#define FUN_003a3470(...) ((void (*)(...))FUN_003a3470)(__VA_ARGS__)
#define FUN_003a3530(...) ((void (*)(...))FUN_003a3530)(__VA_ARGS__)
#define FUN_003a3680(...) ((void (*)(...))FUN_003a3680)(__VA_ARGS__)
#define FUN_003a37c0(...) ((void (*)(...))FUN_003a37c0)(__VA_ARGS__)
#define FUN_003a3ab0(...) ((void (*)(...))FUN_003a3ab0)(__VA_ARGS__)
#define FUN_003a3b00(...) ((void (*)(...))FUN_003a3b00)(__VA_ARGS__)
#define FUN_003a3c10(...) ((void (*)(...))FUN_003a3c10)(__VA_ARGS__)
#define FUN_003a3ce0(...) ((void (*)(...))FUN_003a3ce0)(__VA_ARGS__)
#define FUN_003a3f90(...) ((u32 (*)(...))FUN_003a3f90)(__VA_ARGS__)
#define FUN_003a4010(...) ((void (*)(...))FUN_003a4010)(__VA_ARGS__)
#define FUN_003a4220(...) ((void (*)(...))FUN_003a4220)(__VA_ARGS__)
#define FUN_003a4270(...) ((void (*)(...))FUN_003a4270)(__VA_ARGS__)
#define FUN_003a42c0(...) ((u32 (*)(...))FUN_003a42c0)(__VA_ARGS__)
#define FUN_003a4360(...) ((u64 (*)(...))FUN_003a4360)(__VA_ARGS__)
#define FUN_003a4a70(...) ((u32 (*)(...))FUN_003a4a70)(__VA_ARGS__)
#define FUN_003a4b90(...) ((u64 (*)(...))FUN_003a4b90)(__VA_ARGS__)
#define FUN_003a4ce0(...) ((void (*)(...))FUN_003a4ce0)(__VA_ARGS__)
#define FUN_003a4dd0(...) ((void (*)(...))FUN_003a4dd0)(__VA_ARGS__)
#define FUN_003a4ef0(...) ((void (*)(...))FUN_003a4ef0)(__VA_ARGS__)
#define FUN_003a5030(...) ((void (*)(...))FUN_003a5030)(__VA_ARGS__)
#define FUN_003a50e0(...) ((int (*)(...))FUN_003a50e0)(__VA_ARGS__)
#define FUN_003a5100(...) ((int (*)(...))FUN_003a5100)(__VA_ARGS__)
#define FUN_003a5120(...) ((u32 (*)(...))FUN_003a5120)(__VA_ARGS__)
#define FUN_003a51a0(...) ((u32 (*)(...))FUN_003a51a0)(__VA_ARGS__)
#define FUN_003a5210(...) ((void (*)(...))FUN_003a5210)(__VA_ARGS__)
#define FUN_003a52c0(...) ((u64 (*)(...))FUN_003a52c0)(__VA_ARGS__)
#define FUN_003a53b0(...) FUN_003a53b0_typed(__VA_ARGS__)
#define FUN_003a5540(...) ((void (*)(...))FUN_003a5540)(__VA_ARGS__)
#define FUN_003a5570(...) ((u64 (*)(...))FUN_003a5570)(__VA_ARGS__)
#define FUN_003a56f0(...) ((u64 (*)(...))FUN_003a56f0)(__VA_ARGS__)
#define FUN_003a5940(...) ((u32 (*)(...))FUN_003a5940)(__VA_ARGS__)
#define FUN_003a5980(...) ((void (*)(...))FUN_003a5980)(__VA_ARGS__)
#define FUN_003a5ca0(...) ((void (*)(...))FUN_003a5ca0)(__VA_ARGS__)
#define FUN_003a5ea0(...) ((void (*)(...))FUN_003a5ea0)(__VA_ARGS__)
#define FUN_003a5fd0(...) FUN_003a5fd0_typed(__VA_ARGS__)
#define FUN_003a6030(...) ((u32 (*)(...))FUN_003a6030)(__VA_ARGS__)
#define FUN_003a6060(...) ((void (*)(...))FUN_003a6060)(__VA_ARGS__)
#define FUN_003a6100(...) ((int (*)(...))FUN_003a6100)(__VA_ARGS__)
#define FUN_003a6140(...) ((long (*)(...))FUN_003a6140)(__VA_ARGS__)
#define FUN_003a628c(...) ((int (*)(...))FUN_003a628c)(__VA_ARGS__)
#define FUN_003a62b0(...) ((void (*)(...))FUN_003a62b0)(__VA_ARGS__)
#define FUN_003a62e0(...) ((int (*)(...))FUN_003a62e0)(__VA_ARGS__)
#define FUN_003a6410(...) ((void (*)(...))FUN_003a6410)(__VA_ARGS__)
#define FUN_003a6460(...) ((int (*)(...))FUN_003a6460)(__VA_ARGS__)
#define FUN_003a64c0(...) ((void (*)(...))FUN_003a64c0)(__VA_ARGS__)
#define FUN_003a6520(...) ((void (*)(...))FUN_003a6520)(__VA_ARGS__)
#define FUN_003a67e0(...) ((void (*)(...))FUN_003a67e0)(__VA_ARGS__)
#define FUN_003a6900(...) ((void (*)(...))FUN_003a6900)(__VA_ARGS__)
#define FUN_003a6930(...) ((void (*)(...))FUN_003a6930)(__VA_ARGS__)
#define FUN_003a6980(...) ((void (*)(...))FUN_003a6980)(__VA_ARGS__)
#define FUN_003a69d0(...) ((void (*)(...))FUN_003a69d0)(__VA_ARGS__)
#define FUN_003a6a10(...) ((void (*)(...))FUN_003a6a10)(__VA_ARGS__)
#define FUN_003a6a40(...) ((void (*)(...))FUN_003a6a40)(__VA_ARGS__)
#define FUN_003a6a80(...) ((void (*)(...))FUN_003a6a80)(__VA_ARGS__)
#define FUN_003a6b00(...) ((void (*)(...))FUN_003a6b00)(__VA_ARGS__)
#define FUN_003a6b90(...) ((void (*)(...))FUN_003a6b90)(__VA_ARGS__)
#define FUN_003a6c10(...) ((short * (*)(...))FUN_003a6c10)(__VA_ARGS__)
#define FUN_003a6ca0(...) ((void (*)(...))FUN_003a6ca0)(__VA_ARGS__)
#define FUN_003a6e30(...) ((void (*)(...))FUN_003a6e30)(__VA_ARGS__)
#define FUN_003a7120(...) ((void (*)(...))FUN_003a7120)(__VA_ARGS__)
#define FUN_003a7490(...) ((void (*)(...))FUN_003a7490)(__VA_ARGS__)
#define FUN_003a7940(...) ((void (*)(...))FUN_003a7940)(__VA_ARGS__)
#define FUN_003a7a40(...) ((u32 (*)(...))FUN_003a7a40)(__VA_ARGS__)
#define FUN_003a7cb0(...) ((void (*)(...))FUN_003a7cb0)(__VA_ARGS__)
#define FUN_003a7d60(...) ((u16 (*)(...))FUN_003a7d60)(__VA_ARGS__)
#define FUN_003a7dd0(...) ((void (*)(...))FUN_003a7dd0)(__VA_ARGS__)
#define FUN_003a7e90(...) ((void (*)(...))FUN_003a7e90)(__VA_ARGS__)
#define FUN_003a8080(...) ((void (*)(...))FUN_003a8080)(__VA_ARGS__)
#define FUN_003a8170(...) ((void (*)(...))FUN_003a8170)(__VA_ARGS__)
#define FUN_003a8260(...) ((void (*)(...))FUN_003a8260)(__VA_ARGS__)
#define FUN_003a8350(...) ((void (*)(...))FUN_003a8350)(__VA_ARGS__)
#define FUN_003a8440(...) ((u64 (*)(...))FUN_003a8440)(__VA_ARGS__)
#define FUN_003a84c0(...) ((u64 (*)(...))FUN_003a84c0)(__VA_ARGS__)
#define FUN_003a8530(...) ((void (*)(...))FUN_003a8530)(__VA_ARGS__)
#define FUN_003a8590(...) ((void (*)(...))FUN_003a8590)(__VA_ARGS__)
#define FUN_003a8600(...) ((void (*)(...))FUN_003a8600)(__VA_ARGS__)
#define FUN_003a8650(...) ((void (*)(...))FUN_003a8650)(__VA_ARGS__)
#define FUN_003a8710(...) FUN_003a8710_typed(__VA_ARGS__)

#undef FUN_003a2150
#pragma alias FUN_003a4360_typed FUN_003a4360
extern void FUN_003a4360_typed(s32 param_1, s32 param_2);
#pragma alias FUN_003a30c0_typed FUN_003a30c0
extern s32 FUN_003a30c0_typed(s32 param_1, s32 param_2, s32 param_3);
// FUN_003A2150


u32 FUN_003a2150(void)
{
    s32 index;
    s32 handle;
    s32 object;
    s8 *flag;

    index = FUN_0035f140();
    if (index < 0)
        return 1;
    object = *(s32*)(DAT_00959eec_abs + index * 0xd);
    if (object == 0)
        FUN_0019d3f0("itfMesManager.c", 0x202);

    handle = FUN_0035ed20(0);
    flag = (s8*)(object + 0x24);
    if (flag[0x10] == 0)
    {
        FUN_003a4360_typed(index, 4);
        if (FUN_003a30c0_typed(index, handle, 0) == 0)
            return 1;
    }
    else if (flag[0x10] < 0)
    {
        flag[0x10] = 0;
        return 1;
    }

    return 0;
}
#define FUN_003a2150(...) ((u32 (*)(...))FUN_003a2150)(__VA_ARGS__)
#undef FUN_003a2260
#pragma alias FUN_003a3e10_typed FUN_003a3e10
#pragma alias FUN_003c9570_typed FUN_003c9570
#pragma alias FUN_003a5210_typed FUN_003a5210
#pragma alias FUN_003a2a30_typed FUN_003a2a30
#pragma alias FUN_003a3420_typed FUN_003a3420
#pragma alias FUN_003a6900_typed FUN_003a6900
#pragma alias FUN_003a6930_typed FUN_003a6930
#pragma alias FUN_003a69d0_typed FUN_003a69d0
#pragma alias FUN_003a3e90_typed FUN_003a3e90
extern void FUN_003a3e10_typed(s32, s32);
extern void FUN_003c9570_typed(s32);
extern void FUN_003a5210_typed(s32, s32, s32, s32, s32);
extern void FUN_003a2a30_typed(s32);
extern void FUN_003a3420_typed(s32, s32);
extern void FUN_003a6900_typed(u32*, s32);
extern void FUN_003a6930_typed(u32*, s32);
extern void FUN_003a69d0_typed(u32*);
#pragma alias FUN_003a42c0_typed FUN_003a42c0
#pragma alias FUN_003a6980_typed FUN_003a6980
#pragma alias FUN_003a6a10_typed FUN_003a6a10
#pragma alias FUN_003a6a40_typed FUN_003a6a40
extern u32 FUN_003a42c0_typed(int, u32);
extern void FUN_003a6980_typed(u32*);
extern void FUN_003a6a10_typed(int);
extern void FUN_003a6a40_typed(u8*, s32);
extern void FUN_003a3e90_typed(s32, s32);
// FUN_003A2260


u32 FUN_003a2260(void)
{
    s32 index;
    s32 handle;
    s32 result;
    u32 *object;
    s8 *flag;

    index = FUN_0035f140();
    if (index < 0)
        return 1;

    object = *(u32**)(DAT_00959eec_abs + index * 0xd);
    if (object == NULL)
        FUN_0019d3f0("itfMesManager.c", 0x231);

    handle = FUN_0035ed20(0);
    flag = (s8*)(object + 9);
    if (flag[0x10] == 0)
    {
        FUN_003a4360_typed(index, 6);
        FUN_003a3e10_typed(index, 0x200000);
        result = FUN_003a30c0_typed(index, handle, 0);
        FUN_003c9570_typed(index);
        FUN_003a5210_typed(index, 0, 0, 0x20, 0);
        if (result == 0)
            return 1;
    }
    else if (flag[0x10] < 0)
    {
        if (flag[0x10] == -1)
        {
            FUN_003a2a30_typed(index);
            FUN_003a3420_typed(index, 0);
            flag[0x10] = -2;
        }
        else if ((*object & 0x300) == 0)
        {
            FUN_003a4360_typed(index, 4);
            FUN_003a6900_typed(object + 5, 1);
            FUN_003a6930_typed(object + 9, 1);
            FUN_003a69d0_typed(object + 0x2a);
            FUN_003a3e90_typed(index, 0x400000);
            flag[0x10] = 0;
            return 1;
        }
    }
    return 0;
}
#define FUN_003a2260(...) ((u32 (*)(...))FUN_003a2260)(__VA_ARGS__)
#undef FUN_003a2440
// FUN_003A2440


u32 FUN_003a2440(void)
{
    s32 index;
    s32 handle;
    s32 result;
    u32 *object;
    s8 *flag;

    index = FUN_0035f140();
    if (index < 0)
        return 1;

    object = *(u32**)(DAT_00959eec_abs + index * 0xd);
    if (object == NULL)
        FUN_0019d3f0("itfMesManager.c", 0x272);

    handle = FUN_0035ed20(0);
    flag = (s8*)(object + 9);
    if (flag[0x10] == 0)
    {
        FUN_003a4360_typed(index, 7);
        FUN_003a3e10_typed(index, 0x200000);
        result = FUN_003a30c0_typed(index, handle, 0);
        FUN_003c9570_typed(index);
        FUN_003a5210_typed(index, 1, 5, 0x20, 0);
        if (result == 0)
            return 1;
    }
    else if (flag[0x10] < 0)
    {
        flag[0x10] = 0;
        return 1;
    }
    return 0;
}
#define FUN_003a2440(...) ((u32 (*)(...))FUN_003a2440)(__VA_ARGS__)
#undef FUN_003a2580
// FUN_003A2580


s8 FUN_003a2580(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(DAT_00959eec_abs + param_1 * 0xd);

  if (iVar1 == 0) {

    FUN_0019d3f0("itfMesManager.c",0x2bd);

  }

  return *(u8 *)(iVar1 + 0x34);

}
#define FUN_003a2580(...) ((s8 (*)(...))FUN_003a2580)(__VA_ARGS__)
#undef FUN_003a25f0
// FUN_003A25F0


void FUN_003a25f0(int param_1,u8 param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(DAT_00959eec_abs + param_1 * 0xd);

  if (iVar1 == 0) {

    FUN_0019d3f0("itfMesManager.c",0x2d8);

  }

  *(u8 *)(iVar1 + 0x34) = param_2;

  return;

}
#define FUN_003a25f0(...) ((void (*)(...))FUN_003a25f0)(__VA_ARGS__)
#undef FUN_003a2660
// FUN_003A2660


u32 FUN_003a2660(void)



{

  int iVar1;

  u32 uVar2;

  int lVar3;

  s32 uVar4;
  int base;

  

  lVar3 = FUN_0035f140();

  if (lVar3 < 0) {

    uVar2 = 1;

  }

  else {

    iVar1 = *(int *)(DAT_00959eec_abs + lVar3 * 0xd);

    if (iVar1 == 0) {

      FUN_0019d3f0("itfMesManager.c",0x3a9);

    }
    uVar4 = FUN_0035ed20(0);


    base = iVar1 + 0x40;
    if (*(short *)(iVar1 + 0x54) == 0) {

      FUN_003a37c0_direct(lVar3,uVar4);

    }

    else if (*(short *)(iVar1 + 0x54) < 0) {


      *(short *)(base + 0x14) = 0;
      FUN_0035f060(*(short *)(base + 0x16));

      FUN_003a3ab0_direct(lVar3);

      return 1;

    }

    uVar2 = 0;

  }

  return uVar2;

}
#define FUN_003a2660(...) ((u32 (*)(...))FUN_003a2660)(__VA_ARGS__)
#undef FUN_003a2750
// FUN_003A2750


s16 FUN_003a2750(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(DAT_00959eec_abs + param_1 * 0xd);

  if (iVar1 == 0) {

    FUN_0019d3f0("itfMesManager.c",0x424);

  }

  return *(s16 *)(iVar1 + 0x54);

}
#define FUN_003a2750(...) ((s16 (*)(...))FUN_003a2750)(__VA_ARGS__)
#undef FUN_003a27c0
// FUN_003A27C0


void FUN_003a27c0(int param_1,u16 param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(DAT_00959eec_abs + param_1 * 0xd);

  if (iVar1 == 0) {

    FUN_0019d3f0("itfMesManager.c",0x43a);

  }

  *(u16 *)(iVar1 + 0x54) = param_2;

  return;

}
#define FUN_003a27c0(...) ((void (*)(...))FUN_003a27c0)(__VA_ARGS__)
#undef FUN_003a2830
// FUN_003A2830


s16 FUN_003a2830(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(DAT_00959eec_abs + param_1 * 0xd);

  if (iVar1 == 0) {

    FUN_0019d3f0("itfMesManager.c",0x453);

  }

  return *(s16 *)(iVar1 + 0x56);

}
#define FUN_003a2830(...) ((s16 (*)(...))FUN_003a2830)(__VA_ARGS__)
#undef FUN_003a28a0
// FUN_003A28A0


u32 FUN_003a28a0(void)
{
  int value;
  u32 other;

  value = FUN_0035f140();
  if (value < 0)
    return 1;

  other = FUN_0035ed20(0);
  FUN_003a3ba0(value,other);
  return 1;
}
#define FUN_003a28a0(...) ((u32 (*)(...))FUN_003a28a0)(__VA_ARGS__)
#undef FUN_003a2900
// FUN_003A2900


u32 FUN_003a2900(void)



{

  int lVar1;

  

  lVar1 = FUN_0035f140();

  if (lVar1 < 0)
    return 1;

  itfMesMngChangeWindowType(lVar1,4,0);

  itfMesMng003a3e10(lVar1,0x200000);

  return 1;

}
#define FUN_003a2900(...) ((u32 (*)(...))FUN_003a2900)(__VA_ARGS__)
#undef FUN_003a2970
#undef FUN_003a2a30
// FUN_003A2970


u32 FUN_003a2970(void)



{
  int bVar2;
  u32 *puVar1;


  int lVar3;

  u32 uVar4;

  

  lVar3 = FUN_0035f140();

  if (lVar3 < 0) {

    bVar2 = 1;

  }

  else {

    puVar1 = *(u32 **)(DAT_00959eec_abs + lVar3 * 0xd);

    if (puVar1 == (u32 *)0x0) {

      FUN_0019d3f0("itfMesManager.c",0x4cb);

    }

    uVar4 = *puVar1 & 0x300;

    if ((uVar4 == 0x100) || (uVar4 == 0x200)) {

      FUN_003a2a30_s32(lVar3);

    }

    bVar2 = uVar4 == 0;

  }

  return bVar2;

}
#define FUN_003a2a30(...) ((void (*)(...))FUN_003a2a30)(__VA_ARGS__)
#define FUN_003a2970(...) ((u32 (*)(...))FUN_003a2970)(__VA_ARGS__)
#undef FUN_003a2a30
// FUN_003A2A30


void FUN_003a2a30(s32 param_1)



{

  u32 *puVar1;

  u32 uVar2;

  

  puVar1 = *(u32 **)(DAT_00959eec_abs + (int)param_1 * 0xd);

  if (puVar1 == (u32 *)0x0) {

    FUN_0019d3f0("itfMesManager.c",0x4f3);

  }

  if (*(short *)((int)puVar1 + 0x12) == 4) {

    FUN_003cf440();

  }

  uVar2 = *puVar1;

  if ((uVar2 & 0x300) != 0) {

    *puVar1 = uVar2 & 0xfffffcff;

    *puVar1 = uVar2 & 0xfffffcff | 0x300;

  }

  if ((uVar2 & 0x3000) != 0) {

    uVar2 = *puVar1;

    *puVar1 = uVar2 & 0xffffcfff;

    *puVar1 = uVar2 & 0xffffcfff | 0x3000;

  }

  FUN_003a3420_typed(param_1,1);

  FUN_003a3ab0_direct(param_1);

  *puVar1 = *puVar1 & 0xffdfffff;

  return;

}
#define FUN_003a2a30(...) ((void (*)(...))FUN_003a2a30)(__VA_ARGS__)
#pragma alias FUN_003a4010_typed FUN_003a4010
extern void FUN_003a4010_typed(int param_1,int param_2,int param_3,u32 param_4);
#undef FUN_003a2b30
// FUN_003A2B30


u32 FUN_003a2b30(void)



{

  int lVar1;

  u32 uVar2;

  u32 uVar3;

  u32 uVar4;

  

  lVar1 = FUN_0035f140();

  if (lVar1 < 0) {
    return 1;
  }
  uVar2 = FUN_0035ed20(0);
  uVar3 = FUN_0035ed20(1);
  uVar4 = FUN_0035ed20(2);
  FUN_005225a8(D_006A1A80,uVar2,uVar3,uVar4);
  uVar2 = FUN_0035ed20(0);
  uVar3 = FUN_0035ed20(1);
  uVar4 = FUN_0035ed20(2);
  FUN_003a4010_typed(lVar1,uVar2,uVar3,uVar4);
  return 1;

}
#define FUN_003a2b30(...) ((u32 (*)(...))FUN_003a2b30)(__VA_ARGS__)
#undef FUN_003a4a70
#undef FUN_003a2c10
// FUN_003A2C10


u32 FUN_003a2c10(void)



{

  s32 lVar1;

  u32 uVar2;

  u32 uVar3;

  

  lVar1 = FUN_0035f140();

  if (lVar1 < 0) {

    return 1;

  }

  uVar2 = FUN_0035ed20(0);

  uVar3 = FUN_0035ed20(1);

  FUN_003a4a70(lVar1,uVar2,uVar3);

  return 1;

}
#define FUN_003a4a70(...) ((u32 (*)(...))FUN_003a4a70)(__VA_ARGS__)
#define FUN_003a2c10(...) ((u32 (*)(...))FUN_003a2c10)(__VA_ARGS__)
#undef FUN_003a2c90
// FUN_003A2C90 MATCHING


int FUN_003a2c90(int param_1,int param_2)
{
  u32 *slot;
  int iVar1;
  int oldPtr;
  int offset;
  u32 *dest;
  u32 auStack_1f0[0x7a];
  iVar1 = 0;
  if ((param_2 < 0) || (param_2 >= 4)) {
    FUN_0019d3f0("itfMesManager.c",0x659);
  }
  offset = param_2 * 8;
  if (*(int *)(offset + param_1 + 0x14) == 0) {
    return 0;
  } else {
    oldPtr = *(int *)(param_1 + 0xc);
    if (oldPtr != 0) {
      FUN_00521250(auStack_1f0,oldPtr,0x1e8);
      iVar1 = 1;
    }
    param_2 = (int)((u8 *)param_1 + offset);
    slot = (u32 *)(param_2 + 0x14);
    *(u32 *)((u8 *)param_1 + 0xc) = *slot;
    *(u32 *)((u8 *)param_1 + 0x10) = *slot;
    if (iVar1 != 0) {
      u32 first;
      first = auStack_1f0[0];
      dest = *(u32 **)(param_1 + 0xc);
      *dest = first;
      FUN_00521250((int)*(u32 **)(param_1 + 0xc) + 0xa8,(u8 *)auStack_1f0 + 0xa8,0x2c);
    }
  }
  return (int)slot;
}
#define FUN_003a2c90(...) ((int (*)(...))FUN_003a2c90)(__VA_ARGS__)
#undef FUN_003a2ef0
// FUN_003a2d80
s32 itfMesMngInitialize(BmdHeader* bmdHeader)
{
    void* system;
    s32 result;
    ItfMes* mes;
    s32 slot;

    K_ASSERT(itfMesMngCheckBmdMagic(bmdHeader) == 1, 0x69d);

    system = FUN_003b49a0(D_00959ED0);
    K_ASSERT(system != NULL, 0x6a1);

    result = *(s32*)((u8*)system + 8);
    mes = (ItfMes*)(u32)FUN_003a2ef0_typed(bmdHeader);
    K_ASSERT(system != NULL && mes != NULL, 0x66d);

    for (slot = 0; slot < 4; slot++)
    {
        u8* entry = (u8*)system + slot * 8;
        ItfMes** slotPtr = (ItfMes**)(entry + 0x14);
        if (*(u32*)(entry + 0x14) == 0)
        {
            *(ItfMes**)(entry + 0x18) = mes;
            *slotPtr = mes;
            goto found;
        }
    }
    slot = -1;
found:
    K_ASSERT(slot == 0, 0x6a8);

    FUN_003a2c90_typed(system, slot);
    D_00959EC0[0]++;
    FUN_005225a8(D_006A1AC0, *(s16*)((u8*)mes + 0x12));
    return result;
}
// FUN_003A2EF0


u32 FUN_003a2ef0(u32 param_1)



{

  int lVar1;

  u32 uVar2;

  u32 *puVar3;

  

  lVar1 = itfMesMngCheckBmdMagic((BmdHeader*)(u32)param_1);

  if (lVar1 != 1) {

    FUN_0019d3f0("itfMesManager.c",0x6d3);

  }

  lVar1 = FUN_0016f190(0x1424);

  if (lVar1 != 0) {

    uVar2 = (*DAT_00960178_abs)(0x1e8,0x40000);

  }

  else {

    uVar2 = FUN_00191af0(0x1e8);

  }

  puVar3 = (u32 *)uVar2;

  puVar3[1] = 0;

  FUN_003a42c0_typed(uVar2,param_1);

  *puVar3 = 0;

  puVar3[3] = 0;

  *(u16 *)((int)puVar3 + 0x12) = 0;

  puVar3[0x79] = 0;

  FUN_003a6900_typed(puVar3 + 5,1);

  FUN_003a6930_typed(puVar3 + 9,1);

  FUN_003a6980_typed(puVar3 + 0x10);

  FUN_003a69d0_typed(puVar3 + 0x2a);

  FUN_003a6a10_typed((int)(puVar3 + 0x35));

  FUN_003a6a40_typed((u8 *)(puVar3 + 0x75),0);

  return uVar2;

}
#define FUN_003a2ef0(...) ((u32 (*)(...))FUN_003a2ef0)(__VA_ARGS__)
#undef FUN_003a3010
// FUN_003A3010


u32 FUN_003a3010(int param_1)



{

  int lVar1;

  

  lVar1 = itfMesMngCheckBmdMagic((BmdHeader*)param_1);

  if (lVar1 != 1) {

    FUN_0019d3f0("itfMesManager.c",0x6fc);

  }

  return *(u32 *)(param_1 + 0x18);

}
#define FUN_003a3010(...) ((u32 (*)(...))FUN_003a3010)(__VA_ARGS__)
#undef FUN_003a30c0
// FUN_003a3060
void itfMesMngDestroyHandle(s32 mesHandleIdx)
{
    if (mesHandleIdx >= 0
        && *(ItfMes**)((u8*)&sItfMesHandleSystem
                       + mesHandleIdx * ITFMES_HANDLE_STRIDE
                       + ITFMES_HANDLE_ACTIVE_MES_OFFSET) != NULL)
    {
        FUN_003a4dd0_typed(mesHandleIdx);
    }
}
// W409 addressing/raw-literal fixes: NONMATCHING nd 546 -> 539, object 844/864 -> 844/864.
// W415 branch inversion restores retail call layout; nd 539 -> 539, object 844/864 -> 844/864.
// FUN_003A30C0 NONMATCHING


u32 FUN_003a30c0(s32 param_1,s32 param_2,u16 param_3)



{

  u16 uVar1;

  u32 *puVar2;

  int *piVar3;

  u32 uVar4;

  u32 uVar5;

  u32 uVar6;

  s32 lVar7;

  u32 *puVar8;

  

  puVar2 = *(u32 **)(DAT_00959eec_abs + (int)param_1 * 0xd);

  if (puVar2 == (u32 *)0x0) {

    FUN_0019d3f0("itfMesManager.c",0x749);

  }

  piVar3 = (int *)FUN_003a50e0_typed((int)puVar2,param_2);

  if (*piVar3 != 0) {

    FUN_0019d3f0("itfMesManager.c",0x751);

  }

  uVar4 = piVar3[1];

  puVar2[0xb] = uVar4;

  *(u16 *)(puVar2 + 0xf) = param_3;

  *(u16 *)((int)puVar2 + 0x3e) = *(u16 *)(uVar4 + 0x18);

  if (*(short *)(uVar4 + 0x18) == 0) {

    uVar5 = 0;

  }

  else {

    FUN_003a5fd0(puVar2 + 0x35);

    if (puVar2[2] != 0) {

      FUN_003b19a0(puVar2[2]);

    }

    FUN_003b0e70(0x100);

    FUN_003a5980_typed(puVar2);

    FUN_003b0e90(0x100);

    puVar8 = puVar2 + 5;

    uVar1 = *(u16 *)(uVar4 + 0x1a);

    if ((u16)puVar2[8] != uVar1) {

      if (puVar2[7] != 0) {

        FUN_003b0170(puVar2[7]);

        puVar2[7] = 0;

      }

      *(u16 *)(puVar2 + 8) = uVar1;

      if (uVar1 != 0xffff) {

        if (puVar2[0x2a] != 0) {

          FUN_003a8d60(puVar2[0x2a]);

          puVar2[0x2a] = 0;

        }

        if ((uVar1 & 0x8000) != 0) {

          uVar6 = FUN_003a3f90_typed(param_1,uVar1 & 0x7fff);

          uVar4 = FUN_003b2940(*puVar8,puVar2[6],0,1,0,0xff,uVar6,0);

          puVar2[7] = uVar4;

        }

        else {

          uVar6 = FUN_003a6030_typed(puVar2);

          uVar4 = FUN_003b2940(*puVar8,puVar2[6],0,1,0,0xff,uVar6,0);

          puVar2[7] = uVar4;

        }

        lVar7 = FUN_003b1b00(0,puVar2[7]);

        if (lVar7 >= 0x69) {

          FUN_003b0d70(puVar2[7],*puVar8,puVar2[6]);

        }

        else {

          FUN_003b1c90(0x5c0,puVar2[6],puVar2[7]);

        }

        thunk_FUN_003a6360(puVar2[7],puVar2[3]);

      }

    }

    if (puVar2[7] != 0) {

      thunk_FUN_003b0e54(puVar2[7],-1);

      thunk_FUN_003b0e04(puVar2[7],1);

    }

    FUN_003a67e0_typed(puVar2);

    uVar4 = *puVar2 & 0x300;

    if (((*puVar2 & 0x200000) == 0) || ((uVar4 != 0 && (uVar4 != 0x300)))) {

      uVar4 = *puVar2;

      *puVar2 = uVar4 & 0xfffffff8;

      *puVar2 = uVar4 & 0xfffffff8 | 3;

    }

    else {

      FUN_005225a8(DAT_006a1ae0_abs);

      FUN_003a6520_typed(puVar2);

      FUN_003a95f0(puVar2[0x2b]);

      uVar4 = *puVar2;

      *puVar2 = uVar4 & 0xfffffff8;

      *puVar2 = uVar4 & 0xfffffff8 | 2;

    }

    *(u8 *)(puVar2 + 0xd) = 1;

    *puVar2 = *puVar2 | 0x1000000;

    FUN_005225a8(DAT_006a1b00_abs,*(u16 *)((int)puVar2 + 0x12));

    uVar5 = 1;

  }

  return uVar5;

}
#define FUN_003a30c0(...) ((u32 (*)(...))FUN_003a30c0)(__VA_ARGS__)









#undef FUN_003a3420
#undef FUN_003a3470
// FUN_003A3420


void FUN_003a3420(int param_1,s32 param_2)



{

  if (param_1 < 0) {

    return;

  }

  FUN_003a3470((u32 *)(*(u32 *)(DAT_00959eec_abs + param_1 * 0xd)),param_2);

  return;

}
#define FUN_003a3420(...) ((void (*)(...))FUN_003a3420)(__VA_ARGS__)
#undef FUN_003a6930
#undef FUN_003a6900
#undef FUN_003a3470
// FUN_003A3470


void FUN_003a3470(u32 *param_1,s32 param_2)



{
  extern void FUN_003b0170(u32 resource);

  u32 resource;

  u32 *mesData;

  u32 *window;

  mesData = param_1 + 9;

  resource = param_1[0xc];

  if (resource != 0) {

    FUN_003b0170(resource);

    mesData[3] = 0;

  }

  FUN_003a6930(mesData,0);

  *param_1 = *param_1 & 0xfffffff8;

  *param_1 = *param_1 & 0xfffdffff;

  if (param_2 != 0) {

    window = param_1 + 5;

    resource = param_1[7];

    if (resource != 0) {

      FUN_003b0170(resource);

      window[2] = 0;

    }

    FUN_003a6900(param_1 + 5,0);

  }

  return;

}
#define FUN_003a6930(...) ((void (*)(...))FUN_003a6930)(__VA_ARGS__)
#define FUN_003a6900(...) ((void (*)(...))FUN_003a6900)(__VA_ARGS__)
#define FUN_003a3470(...) ((void (*)(...))FUN_003a3470)(__VA_ARGS__)
#undef FUN_003a3530
// FUN_003A3530


void FUN_003a3530(u32 *param_1)
{
  u32 *work;
  u8 *layout;
  int maxWidth;
  int height;
  int i;
  int width;

  work = param_1 + 0x2a;
  layout = (u8 *)param_1 + 0x40;
  maxWidth = 0;
  FUN_003b1c90(0x1000,0x4b0,param_1[0x13]);
  height = *(s16 *)(layout + 0x1a) * 200;
  for (i = 0; i < *(s16 *)(layout + 0x1a); i++) {
    width = FUN_003b1b00(i,*(u32 *)(layout + 0xc));
    if (maxWidth < width) {
      maxWidth = width;
    }
  }
  work[2] = FUN_003a8b00(9,*(u32 *)DAT_00959ec4_abs);
  width = maxWidth / 2;
  FUN_003a8dc0(work[2],0xe00 - width,0x430,width + 0x1200,
               height + 0x530,param_1[3]);
  FUN_003a8fb0(work[2],0,0,0,0);
  *param_1 &= 0xfffff3ff;
  *param_1 |= 0x400;
}
#define FUN_003a3530(...) ((void (*)(...))FUN_003a3530)(__VA_ARGS__)
#undef FUN_003a3680
// FUN_003A3680


void FUN_003a3680(u32 *param_1)
{
  u32 *work;
  u8 *layout;
  int maxWidth;
  int height;
  int i;
  int width;

  work = param_1 + 0x2a;
  layout = (u8 *)param_1 + 0x40;
  maxWidth = 0;
  height = (*(s16 *)(layout + 0x1a) + 1) * 200;
  for (i = 0; i < *(s16 *)(layout + 0x1a); i++) {
    width = FUN_003b1b00(i,*(u32 *)(layout + 0xc));
    if (maxWidth < width) {
      maxWidth = width;
    }
  }
  work[2] = FUN_003a8b00(0xb,*(u32 *)DAT_00959ec4_abs);
  width = maxWidth / 2;
  FUN_003a8dc0(work[2],0xef0 - width,0x788,width + 0xef0,
               height + 0x788,param_1[3]);
  FUN_003a8fb0(work[2],0,0,0,0);
  *param_1 &= 0xfffff3ff;
  *param_1 |= 0x400;
}
#define FUN_003a3680(...) ((void (*)(...))FUN_003a3680)(__VA_ARGS__)
#undef FUN_003a37c0
// FUN_003A37C0 NONMATCHING


void FUN_003a37c0(int param_1,u32 param_2)



{

  short sVar1;

  u32 *puVar2;

  int iVar3;

  int *piVar4;

  s32 lVar5;

  s32 lVar6;

  u32 *puVar7;

  u32 uVar8;

  u32 uVar9;

  int iVar10;

  

  puVar2 = *(u32 **)(DAT_00959eec_abs + param_1 * 0xd);

  if (puVar2 == (u32 *)0x0) {

    FUN_0019d3f0("itfMesManager.c",0x8ba);

  }

  piVar4 = (int *)FUN_003a50e0_typed((int)puVar2,param_2);

  if (*piVar4 != 1) {

    FUN_0019d3f0("itfMesManager.c",0x8be);

  }

  if (puVar2[0x13] != 0) {

    FUN_003b0170(puVar2[0x13]);

    puVar2[0x13] = 0;

  }

  iVar3 = piVar4[1];

  uVar8 = puVar2[0x14];

  sVar1 = *(short *)(iVar3 + 0x1a);

  puVar7 = (u32 *)(iVar3 + 0x20);

  uVar9 = 0;

  for (lVar6 = 0; lVar6 < sVar1; lVar6 = lVar6 + 1) {

    if ((uVar8 & 1) != 0) {

      uVar8 = uVar8 >> 1;

    }

    else {

      FUN_003b2bf0(*puVar7,0,0xf340);

      lVar5 = FUN_003b2a00(0x20);

      if (lVar5 != 0) {

        uVar9 = uVar9 | 1 << lVar6;

      }

    }

    puVar7 = puVar7 + 1;

  }

  puVar2[0x14] = puVar2[0x14] | uVar9;

  lVar6 = FUN_003a6100_typed(*(s16 *)(iVar3 + 0x1a),puVar2[0x14]);

  if (*(short *)((int)puVar2 + 0x12) != 4) {

    uVar8 = puVar2[0x11] + ((int)lVar6 + -1) * -200;

    iVar10 = 0;

  }

  else {

    if (lVar6 == 4) {

      uVar8 = 0x788;

      iVar10 = 200;

    }

    else {

      iVar10 = (int)(75.0f / (float)(int)lVar6);

      uVar8 = (iVar10 >> 1) * 8 + 0x788;

      iVar10 = iVar10 << 3;

    }

    puVar2[0x10] = 0xef0;

    puVar2[0x11] = uVar8;

  }

  FUN_003a5fd0(puVar2 + 0x35);

  if (puVar2[2] != 0) {

    FUN_003b19a0(puVar2[2]);

  }

  uVar8 = FUN_003a6140_typed((u32 *)(iVar3 + 0x20),*(s16 *)(iVar3 + 0x1a),puVar2[0x14],puVar2[0x10],uVar8,

                             puVar2[3],iVar10,1);

  puVar2[0x13] = uVar8;

  *(short *)((int)puVar2 + 0x5a) = (short)lVar6;

  uVar8 = *puVar2;

  *puVar2 = uVar8 & 0xffffffc7;

  *puVar2 = uVar8 & 0xffffffc7 | 0x10;

  switch (*(short *)((int)puVar2 + 0x12)) {
  case 3:
    FUN_003a3530_direct(puVar2);
    break;
  case 4:
    FUN_003a3680_direct(puVar2);
    break;
  }

  *(u16 *)(puVar2 + 0x15) = 1;

  puVar2[0x12] = (u32)param_2;

  return;

}
#define FUN_003a37c0(...) ((void (*)(...))FUN_003a37c0)(__VA_ARGS__)
#undef FUN_003a3ab0
// FUN_003A3AB0


void FUN_003a3ab0(int param_1)



{

  FUN_003a3b00_typed(*(u32 *)(DAT_00959eec_abs + param_1 * 0xd));

  return;

}
#define FUN_003a3ab0(...) ((void (*)(...))FUN_003a3ab0)(__VA_ARGS__)
#undef FUN_003a3b00
// FUN_003A3B00


void FUN_003a3b00(u8 *param_1)
{
  u8 *entry;

  if (param_1 == 0) {
    FUN_0019d3f0("itfMesManager.c",0x932);
  }

  entry = param_1 + 0x40;

  if (*(u32 *)(param_1 + 0x4c) != 0) {
    FUN_003b0170(*(u32 *)(param_1 + 0x4c));
    *(u32 *)(entry + 0xc) = 0;
  }

  *(u16 *)(entry + 0x14) = 0;
  *(u16 *)(entry + 0x1a) = 0;
  *(s16 *)(entry + 0x16) = -1;
  *(u32 *)(entry + 0x10) = 0;
  *(u32 *)param_1 = *(u32 *)param_1 & 0xffffffc7;
  *(u32 *)param_1 = *(u32 *)param_1 & 0xfffbffff;
}
#define FUN_003a3b00(...) ((void (*)(...))FUN_003a3b00)(__VA_ARGS__)
#undef FUN_003a3c10
// FUN_003a3ba0
void itfMesMng003a3ba0(s32 mesHandleIdx, u32 param_2)
{
    int iVar1;

    iVar1 = *(int*)((u8*)&sItfMesHandleSystem + mesHandleIdx * ITFMES_HANDLE_STRIDE);
    K_ASSERT(iVar1 != 0, 0x956);
    *(u32*)(iVar1 + 0x50) = param_2;
}
// FUN_003A3C10


void FUN_003a3c10(int param_1,int param_2)



{
  int iVar1;
  ItfMesTextWork *work;
  u32 uVar4;

  int iVar3;

  int sVar2;
  int line;


  

  iVar1 = *(int *)(DAT_00959eec_abs + param_1 * 0xd);

  if (iVar1 == 0) {

    FUN_0019d3f0("itfMesManager.c",0x96b);

  }

  work = (ItfMesTextWork *)(iVar1 + 0x40);
  sVar2 = 0;
  uVar4 = work->flags;

  iVar3 = 0;

  while( 1 ) {

    if ((uVar4 & 1) == 0) {

      sVar2 = sVar2 + 1;

    }

    if (param_2 <= iVar3) break;

    iVar3 = iVar3 + 1;

    uVar4 = uVar4 >> 1;

  }

  if ((uVar4 & 1) != 0) {

    line = 0;

  }

  else {

    line = sVar2 + -1;

  }

  work->lineStart = line;
  work->lineEnd = line;

  return;

}
#define FUN_003a3c10(...) ((void (*)(...))FUN_003a3c10)(__VA_ARGS__)
#undef FUN_003a3ce0
// FUN_003A3CE0


void FUN_003a3ce0(int param_1,int param_2,int param_3)



{

  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;

  

  iVar1 = *(int *)(DAT_00959eec_abs + param_1 * 0xd);

  if (iVar1 == 0) {

    FUN_0019d3f0("itfMesManager.c",0x9d0);

  }
  iVar2 = iVar1 + 0x24;
  iVar3 = param_2 - *(int *)iVar2;
  iVar4 = param_3 - *(int *)(iVar2 + 4);

  if ((iVar3 != 0) || (iVar4 != 0)) {

    thunk_FUN_003a6334_typed(*(u32 *)(iVar2 + 0xc),iVar3,iVar4);

    *(int *)iVar2 = param_2;

    *(int *)(iVar2 + 4) = param_3;

  }

  return;

}
#define FUN_003a3ce0(...) ((void (*)(...))FUN_003a3ce0)(__VA_ARGS__)
#undef FUN_003a3f90
// FUN_003a3da0
u32 itfMesMng003a3da0(s32 mesHandleIdx)
{
    u32* p;

    p = *(u32**)((u8*)&sItfMesHandleSystem + mesHandleIdx * ITFMES_HANDLE_STRIDE);
    K_ASSERT(p != NULL, 0xa54);
    return *p;
}
// FUN_003a3e10
void itfMesMng003a3e10(s32 mesHandleIdx, u32 param_2)
{
    u32* puVar1;

    puVar1 = *(u32**)((u8*)&sItfMesHandleSystem + mesHandleIdx * ITFMES_HANDLE_STRIDE);
    K_ASSERT(puVar1 != NULL, 0xa81);
    *puVar1 |= param_2 & 0xffff0000;
}
// FUN_003a3e90
void itfMesMng003a3e90(s32 mesHandleIdx, u32 param_2)
{
    u32* puVar1;

    puVar1 = *(u32**)((u8*)&sItfMesHandleSystem + mesHandleIdx * ITFMES_HANDLE_STRIDE);
    K_ASSERT(puVar1 != NULL, 0xa96);
    *puVar1 &= ~(param_2 & 0xffff0000);
}
// FUN_003a3f20
s16 itfMesMng003a3f20(s32 mesHandleIdx)
{
    int p;

    p = *(int*)((u8*)&sItfMesHandleSystem + mesHandleIdx * ITFMES_HANDLE_STRIDE);
    K_ASSERT(p != 0, 0xaa9);
    return *(s16*)(p + 0x56);
}
// FUN_003A3F90


u32 FUN_003a3f90(int param_1,int param_2)



{

  int iVar1;
  int offset;
  int address;


  iVar1 = *(int *)(itfMesEntries + param_1 * 0xd);

  if (iVar1 == 0) {

    FUN_0019d3f0("itfMesManager.c",0xada);

  }

  offset = param_2 * 4;
  address = offset + iVar1;
  return *(u32 *)(address + 0xd4);

}

#define FUN_003a3f90(...) ((u32 (*)(...))FUN_003a3f90)(__VA_ARGS__)
#undef FUN_003a4010
#pragma alias FUN_003a4220_typed FUN_003a4220
extern void FUN_003a4220_typed(int param_1,int param_2,u32 param_3);
#pragma alias FUN_003a4220_buffer FUN_003a4220
extern void FUN_003a4220_buffer(int param_1,int param_2,void *param_3);
#pragma alias FUN_003a4270_typed FUN_003a4270
extern void FUN_003a4270_typed(int param_1);
#pragma alias FUN_003a6c10_typed FUN_003a6c10
extern u16 *FUN_003a6c10_typed(int param_1,u16 *param_2);
extern const char *func_00171110(s16 param_1,s16 param_2);
// FUN_003A4010 MATCHING

void FUN_003a4010(int param_1,int param_2,int param_3,u32 param_4)
{
  char buffer[0x10];
  u16 text[0x20];
  u16 *cursor;
  u16 *end;
  s8 value;

  switch (param_4) {
  case 0:
    sprintf(buffer,(char *)&DAT_00958be8);
    FUN_003a4220_buffer(param_1,param_2,buffer);
    break;
  case 16:
    FUN_003a4220_typed(param_1,param_2,
                       (u32)((u8 *)gp0xffffb7f8 + param_3 * 0x13));
    break;
  case 8:
    FUN_003a4220_typed(param_1,param_2,
                       (u32)((u8 *)gp0xffffb800 + param_3 * 0x15));
    break;
  case 3:
    FUN_003a4220_typed(param_1,param_2,
                       (u32)func_00171110((s16)(param_3 & 0xffff),2));
    break;
  case 17:
    FUN_003a4270_typed(param_1);
    break;
  case 4:
    cursor = text;
    if (param_3 <= 0x3e8) goto LAB_003a4134;
    cursor[0] = 0xb280;
    cursor[1] = 0;
    goto LAB_003a4164;
LAB_003a4134:
    if (param_3 < 0) {
      param_3 = -param_3;
      cursor[0] = 0xa280;
      cursor += 1;
    }
    end = FUN_003a6c10_typed(param_3,cursor);
    end[0] = 0xa680;
    end[1] = 0;
LAB_003a4164:
    FUN_003a4220_buffer(param_1,param_2,text);
    break;
  case 5:
    FUN_003a4220_typed(param_1,param_2,
                       (u32)((u8 *)gp0xffffb7fc + param_3 * 0x13));
    break;
  case 6:
    FUN_003a4220_typed(param_1,param_2,
                       (u32)(DAT_00959870_abs + (param_3 << 5)));
    break;
  case 7:
    FUN_003a4220_typed(param_1,param_2,
                       (u32)(DAT_00958bf0_abs + (param_3 << 5)));
    break;
  case 9:
    value = *(s8 *)(DAT_00959eb0_abs + param_3);
    FUN_003a4220_typed(param_1,param_2,value);
    break;
  case 1:
  case 2:
  case 10:
  case 11:
  case 12:
  case 13:
  case 14:
  case 15:
  default:
    break;
  }
}
#define FUN_003a4010(...) ((void (*)(...))FUN_003a4010)(__VA_ARGS__)
#undef FUN_003a4220
// FUN_003A4220


void FUN_003a4220(int param_1,u64 param_2,u64 param_3)



{

  FUN_003a5ca0_typed(*(u32 *)(DAT_00959eec_abs + param_1 * 0xd),param_2,param_3,0);

  return;

}
#define FUN_003a4220(...) ((void (*)(...))FUN_003a4220)(__VA_ARGS__)
#undef FUN_003a4270
// FUN_003A4270


void FUN_003a4270(int param_1)



{

  FUN_003a5ea0_typed(*(u32 *)(DAT_00959eec_abs + param_1 * 0xd));

  return;

}
#define FUN_003a4270(...) ((void (*)(...))FUN_003a4270)(__VA_ARGS__)
#undef FUN_003a42c0
// FUN_003A42C0


u32 FUN_003a42c0(int param_1,u32 param_2)



{

  u32 uVar1;

  int iVar2;

  u32 uVar3;

  int iVar4;

  

  if (param_1 == 0) {

    FUN_0019d3f0("itfMesManager.c",0xc0d);

  }

  iVar4 = (int)param_1;

  uVar1 = *(u32 *)(iVar4 + 4);

  *(int *)(iVar4 + 4) = (int)param_2;

  FUN_003a5030_typed(param_2);

  iVar2 = FUN_003a5100_typed(param_2);

  if (*(u32 *)((int)param_2 + 8) == BMD_HEADER_MAGIC1) {

    uVar3 = *(u32 *)(iVar2 + 8);

  }

  else {

    uVar3 = 0;

  }

  *(u32 *)(iVar4 + 8) = uVar3;

  return uVar1;

}
#define FUN_003a42c0(...) ((u32 (*)(...))FUN_003a42c0)(__VA_ARGS__)
#undef FUN_003a4360
/* opt_common_subs off: measured nd 1076 -> 1075, object 1536/1584 -> 1536/1584. */
#pragma opt_common_subs off
// W409 addressing: NONMATCHING nd 1075 -> 954, object 1536/1584 -> 1512/1584.
// W415 typed prototype closes the missing call; nd 954 -> 951, object 1512/1584 -> 1504/1584.
// W417 rejected switch conversion for the param_2 7/6/5/4 chain; nd 951/object 1504 -> 1071/object 1512.
// All six tested local declaration permutations stayed at nd 1071/object 1512, so the probe was reverted.
// FUN_003A4360 NONMATCHING


u32 FUN_003a4360(u32 param_1,int param_2)



{

  u32 *puVar1;

  int *piVar2;

  int iVar3;

  

  iVar3 = (int)param_1;

  if (param_2 == 7) {

    FUN_003a4990(param_1,7,0);

    piVar2 = (int *)(((u8 *)&DAT_00959eec) + iVar3 * 0xd);

    puVar1 = (u32 *)*piVar2;

    if (puVar1 == (u32 *)0x0) {

      FUN_0019d3f0("itfMesManager.c",0xa81);

    }

    *puVar1 = *puVar1 | 0x2000000;

    puVar1 = (u32 *)*piVar2;

    if (puVar1 == (u32 *)0x0) {

      FUN_0019d3f0("itfMesManager.c",0xa96);

    }

    *puVar1 = *puVar1 & 0xffefffff;

    puVar1 = (u32 *)*piVar2;

    if (puVar1 == (u32 *)0x0) {

      FUN_0019d3f0("itfMesManager.c",0xa81);

    }

    *puVar1 = *puVar1 | 0x400000;

    puVar1 = (u32 *)*piVar2;

    if (puVar1 == (u32 *)0x0) {

      FUN_0019d3f0("itfMesManager.c",0xa96);

    }

    *puVar1 = *puVar1 & 0xff7fffff;

  }

  else if (param_2 == 6) {

    FUN_003a4990(param_1,6,0);

    piVar2 = (int *)(((u8 *)&DAT_00959eec) + iVar3 * 0xd);

    puVar1 = (u32 *)*piVar2;

    if (puVar1 == (u32 *)0x0) {

      FUN_0019d3f0("itfMesManager.c",0xa96);

    }

    *puVar1 = *puVar1 & 0xfdffffff;

    puVar1 = (u32 *)*piVar2;

    if (puVar1 == (u32 *)0x0) {

      FUN_0019d3f0("itfMesManager.c",0xa96);

    }

    *puVar1 = *puVar1 & 0xffefffff;

    puVar1 = (u32 *)*piVar2;

    if (puVar1 == (u32 *)0x0) {

      FUN_0019d3f0("itfMesManager.c",0xa81);

    }

    *puVar1 = *puVar1 | 0x400000;

    puVar1 = (u32 *)*piVar2;

    if (puVar1 == (u32 *)0x0) {

      FUN_0019d3f0("itfMesManager.c",0xa96);

    }

    *puVar1 = *puVar1 & 0xff7fffff;

  }

  else if (param_2 == 5) {

    piVar2 = (int *)(((u8 *)&DAT_00959eec) + iVar3 * 0xd);

    iVar3 = *piVar2;

    if (iVar3 == 0) {

      FUN_0019d3f0("itfMesManager.c",0x996);

    }

    if ((*(int *)(iVar3 + 0x14) != 0xa0) || (*(int *)(iVar3 + 0x18) != 0x28)) {

      thunk_FUN_003a6334(*(u32 *)(iVar3 + 0x1c));

      *(u32 *)(iVar3 + 0x14) = 0xa0;

      *(u32 *)(iVar3 + 0x18) = 0x28;

    }

    iVar3 = *piVar2;

    if (iVar3 == 0) {

      FUN_0019d3f0("itfMesManager.c",0x9d0);

    }

    if ((*(int *)(iVar3 + 0x24) != 0x790) || (*(int *)(iVar3 + 0x28) != 0xb8)) {

      thunk_FUN_003a6334(*(u32 *)(iVar3 + 0x30));

      *(u32 *)(iVar3 + 0x24) = 0x790;

      *(u32 *)(iVar3 + 0x28) = 0xb8;

    }

    FUN_003a4990(param_1,5,0);

    puVar1 = (u32 *)*piVar2;

    if (puVar1 == (u32 *)0x0) {

      FUN_0019d3f0("itfMesManager.c",0xa81);

    }

    *puVar1 = *puVar1 | 0x2000000;

    puVar1 = (u32 *)*piVar2;

    if (puVar1 == (u32 *)0x0) {

      FUN_0019d3f0("itfMesManager.c",0xa81);

    }

    *puVar1 = *puVar1 | 0x4000000;

    puVar1 = (u32 *)*piVar2;

    if (puVar1 == (u32 *)0x0) {

      FUN_0019d3f0("itfMesManager.c",0xa81);

    }

    *puVar1 = *puVar1 | 0x100000;

    puVar1 = (u32 *)*piVar2;

    if (puVar1 == (u32 *)0x0) {

      FUN_0019d3f0("itfMesManager.c",0xa81);

    }

    *puVar1 = *puVar1 | 0x400000;

  }

  else if (param_2 == 4) {

    piVar2 = (int *)(DAT_00959eec_abs + iVar3 * 0xd);

    iVar3 = *piVar2;

    if (iVar3 == 0) {

      FUN_0019d3f0("itfMesManager.c",0x996);

    }

    if ((*(int *)(iVar3 + 0x14) != 0x290) || (*(int *)(iVar3 + 0x18) != 0xa48)) {

      thunk_FUN_003a6334(*(u32 *)(iVar3 + 0x1c));

      *(u32 *)(iVar3 + 0x14) = 0x290;

      *(u32 *)(iVar3 + 0x18) = 0xa48;

    }

    iVar3 = *piVar2;

    if (iVar3 == 0) {

      FUN_0019d3f0("itfMesManager.c",0x9d0);

    }

    if ((*(int *)(iVar3 + 0x24) != 0x360) || (*(int *)(iVar3 + 0x28) != 0xb18)) {

      thunk_FUN_003a6334(*(u32 *)(iVar3 + 0x30));

      *(u32 *)(iVar3 + 0x24) = 0x360;

      *(u32 *)(iVar3 + 0x28) = 0xb18;

    }

    FUN_003a4990(param_1,4,0);

    puVar1 = (u32 *)*piVar2;

    if (puVar1 == (u32 *)0x0) {

      FUN_0019d3f0("itfMesManager.c",0xa96);

    }

    *puVar1 = *puVar1 & 0xfdffffff;

    puVar1 = (u32 *)*piVar2;

    if (puVar1 == (u32 *)0x0) {

      FUN_0019d3f0("itfMesManager.c",0xa96);

    }

    *puVar1 = *puVar1 & 0xffefffff;

    puVar1 = (u32 *)*piVar2;

    if (puVar1 == (u32 *)0x0) {

      FUN_0019d3f0("itfMesManager.c",0xa96);

    }

    *puVar1 = *puVar1 & 0xffbfffff;

    puVar1 = (u32 *)*piVar2;

    if (puVar1 == (u32 *)0x0) {

      FUN_0019d3f0("itfMesManager.c",0xa96);

    }

    *puVar1 = *puVar1 & 0xff7fffff;

    FUN_003a6a80_typed(param_1,0x231,0x18b);

  }

  return 0;

}
#define FUN_003a4360(...) ((u64 (*)(...))FUN_003a4360)(__VA_ARGS__)
#pragma opt_common_subs reset
#undef FUN_003a4a70
// W295: addu orientation fell to container-cast base-first form + load-to-temp compare
// (sVal = ((ItfMesChoiceWork *)((u8 *)work + i * 4))->entries[0].type) - not a floor.
// FUN_003a4990
void itfMesMngChangeWindowType(s32 mesHandleIdx, s32 type, u32 param_3)
{
    ItfMes* mes;
    u8* window;

    mes = *(ItfMes**)((u8*)&sItfMesHandleSystem
                      + mesHandleIdx * ITFMES_HANDLE_STRIDE);
    window = (u8*)mes + 0xa8;

    if ((*(u32*)mes & 0x3300) == 0)
    {
        if (*(s16*)((u8*)mes + 0x12) != type ||
            *(u32*)(window + 0x28) != param_3)
        {
            *(s16*)&mes->unkData[0x12] = type;
            FUN_005225a8(D_006A1B30, type);
            FUN_003a6ca0_direct((u32)&mes->unkData[0xa8], type, param_3);
            if (*(u32*)(window + 4) != 0)
            {
                FUN_003a8d60(*(u32*)(window + 4));
                *(u32*)(window + 4) = 0;
            }
        }
    }
}
// FUN_003A4A70


u32 FUN_003a4a70(int param_1, int param_2, int param_3)
{
    u32 *object;
    ItfMesChoiceWork *work;
    ItfMesChoiceEntry *found;
    int count;
    s32 i;
    s16 sVal;

    object = *(u32**)(DAT_00959eec_abs + param_1 * 0xd);
    work = (ItfMesChoiceWork*)((u8*)object + 0x40);
    found = NULL;
    if (param_2 < 0 || param_2 >= 0x10)
        return 0;

    if (param_2 == 6)
        param_2 = 5;
    if (param_2 == 6 || param_2 == 0xc || param_2 == 0xe)
        return 0;

    i = 0;
    count = work->count;
    while (i < count)
    {
        sVal = ((ItfMesChoiceWork *)((u8 *)work + i * 4))->entries[0].type;
        if (sVal == param_2)
        {
            found = work->entries + i;
            break;
        }
        i++;
    }
    if (found == NULL)
    {
        if (count >= 0xf)
            return 0;
        found = &work->entries[count];
        work->count++;
    }
    found->type = param_2;
    found->value = param_3;
    return 1;
}
#define FUN_003a4a70(...) ((u32 (*)(...))FUN_003a4a70)(__VA_ARGS__)
#undef FUN_003a4b90
// FUN_003A4B90


u32 FUN_003a4b90(int param_1,u32 param_2,u32 param_3)



{



  int iVar2;

  int *piVar3;

  u32 uVar4;

  int lVar5;

  u32 uVar6;
  int iVar1;

  

  iVar1 = *(int *)(DAT_00959eec_abs + param_1 * 0xd);


  if (iVar1 == 0) {

    FUN_0019d3f0("itfMesManager.c",0xcfe);

  }

  piVar3 = (int *)FUN_003a50e0_typed(iVar1,param_2);

  if (*piVar3 != 0) {

    FUN_0019d3f0("itfMesManager.c",0xd03);

  }

  iVar2 = piVar3[1];

  if (*(short *)(iVar2 + 0x18) == 0) {
    return 0;
  }

  FUN_003a5fd0(iVar1 + 0xd4);

  if (*(int *)(iVar1 + 8) != 0) {
    FUN_003b19a0(*(int *)(iVar1 + 8));
  }

  lVar5 = FUN_003a5940_typed(iVar2,param_3);

  if (lVar5 == 0) {
    return 0;
  }

  uVar6 = FUN_003b2900(0,0,lVar5,0);

  uVar4 = FUN_003a6460_typed(uVar6);

  FUN_003b0170(uVar6);

  return uVar4;

}
#define FUN_003a4b90(...) ((u64 (*)(...))FUN_003a4b90)(__VA_ARGS__)
#undef FUN_003a4ce0
// FUN_003A4CE0


void FUN_003a4ce0(void)



{

  int iVar1;

  

  *(u32 *)DAT_00959ec0_abs = 0;
  *(u32 *)DAT_00959ec8_abs = 0;
  *(u16 *)DAT_00959ecc_abs = 0;
  FUN_003b4920(DAT_00959ed0_abs,DAT_00959ee0_abs,0x40,0x34);
  for (iVar1 = *(int *)DAT_00959ed8_abs; iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {


    *(u32 *)(iVar1 + 0xc) = 0;

  }

  FUN_0035ad80(DAT_006a1b58_abs,0x106f,0,0,FUN_003a8440,FUN_003a8530,0);

  FUN_00194c50(DAT_006a1b68_abs,0x1cbf,FUN_003a84c0,FUN_003a8530,0);

  FUN_005225a8(DAT_006a1b80_abs,DAT_006a1a70_abs);

  return;

}
#define FUN_003a4ce0(...) ((void (*)(...))FUN_003a4ce0)(__VA_ARGS__)
#undef FUN_003a4dd0
// FUN_003A4DD0


void FUN_003a4dd0(int handleIndex)
{
  u8 *entry = DAT_00959ee0_abs + handleIndex * 0x34;
  u8 *work = entry + 0x20;
  int slot;

  if (*(u32 *)(entry + 0x2c) != 0) {
    FUN_003a6b00_direct(*(u32 *)(entry + 0x2c));
  }
  *(u32 *)(work + 0xc) = 0;

  for (slot = 0; slot < 4; slot++) {
    u32 value;

    if (work == NULL || slot < 0 || slot >= 4) {
      FUN_0019d3f0("itfMesManager.c", 0x67a);
    }
    value = *(u32 *)(work + slot * 8 + 0x14);
    if (value != 0) {
      *(u32 *)(work + slot * 8 + 0x18) = 0;
      *(u32 *)(work + slot * 8 + 0x14) = 0;
    } else {
      value = 0;
    }
    if (value != 0) {
      FUN_003a4ef0_direct((u32 *)value);
    }
  }

  FUN_003b4a20_direct(work, DAT_00959ed0_abs);
  DAT_00959ec0_abs[0]--;
}
#define FUN_003a4dd0(...) ((void (*)(...))FUN_003a4dd0)(__VA_ARGS__)
#undef FUN_003a4ef0
// FUN_003A4EF0


void FUN_003a4ef0(u32 *param_1)
{
  if (param_1 != 0) {
    {
      u32 *primary = param_1 + 9;
      if (primary[3] != 0) {
        FUN_003b0170(primary[3]);
        primary[3] = 0;
      }
      FUN_003a6930_direct(primary,0);
    }

    *param_1 &= 0xfffffff8;
    *param_1 &= 0xfffdffff;
    {
      u32 *secondary = param_1 + 5;
      if (secondary[2] != 0) {
        FUN_003b0170(secondary[2]);
        secondary[2] = 0;
      }
      FUN_003a6900_direct(param_1 + 5,0);
    }

    if (param_1 == 0) {
      FUN_0019d3f0("itfMesManager.c",0x932);
    }

    {
      u32 *layout = param_1 + 0x10;
      if (layout[3] != 0) {
        FUN_003b0170(layout[3]);
        layout[3] = 0;
      }
      *(u16 *)(layout + 5) = 0;
      *(u16 *)((u8 *)layout + 0x1a) = 0;
      *(s16 *)((u8 *)layout + 0x16) = -1;
      layout[4] = 0;
    }

    *param_1 &= 0xffffffc7;
    *param_1 &= 0xfffbffff;
    FUN_003a6b90_direct((int)(param_1 + 0x35));
    *param_1 = 0;
    FUN_00191a10(param_1);
  }
}
#define FUN_003a4ef0(...) ((void (*)(...))FUN_003a4ef0)(__VA_ARGS__)
#undef FUN_003a5030
// FUN_003A5030
void FUN_003a5030(int object)


{
    s32 base;
    s32 end;

    if (*(u8*)(object + 0x1c) == 0) {
        base = object + 0x20;
        end = object + *(s32*)(object + 0x10);
        FUN_0035ac90(base, base, end, *(volatile /* Removing this qualifier loses FUN_003a5030 (MATCH nd0 -> MISMATCH nd8, size 84 -> 84) - measured W170. */ u32*)(object + 0x14));
        *(u8*)(object + 0x1c) = 1;
    }
}
#define FUN_003a5030(...) ((void (*)(...))FUN_003a5030)(__VA_ARGS__)
#undef FUN_003a50e0
// FUN_003a5090
u32 itfMesMngCheckBmdMagic(BmdHeader* bmdHeader)
{
    s8 isMagicValid;

    isMagicValid = true;
    switch (bmdHeader->magic)
    {
        case BMD_HEADER_MAGIC1:
        case BMD_HEADER_MAGIC0: break;

        default: isMagicValid = false;
    }
    
    if (isMagicValid)
    {
        return true;
    }
    
    return false;
}
// FUN_003A50E0


int FUN_003a50e0(int param_1,int param_2)
{
  s32 base;
  s32 index;

  base = *(volatile /* Removing this qualifier loses FUN_003a50e0 (MATCH nd0 -> MISMATCH nd9, size 24 -> 24) - measured W170. */ s32 *)(param_1 + 4);
  index = param_2 * 8;
  return index + base + 0x20;
}
#define FUN_003a50e0(...) ((int (*)(...))FUN_003a50e0)(__VA_ARGS__)
#undef FUN_003a5100
// FUN_003A5100


int FUN_003a5100(int param_1)



{
  int iVar1;


  iVar1 = *(int *)(param_1 + 0x18) * 8;
  return iVar1 + param_1 + 0x20;

}
#define FUN_003a5100(...) ((int (*)(...))FUN_003a5100)(__VA_ARGS__)
#undef FUN_003a5120
// FUN_003A5120


u32 FUN_003a5120(int param_1,int param_2)



{

  u32 base;
  u32 offset;
  int iVar1;

  iVar1 = *(int *)(itfMesEntries + param_1 * 0xd);

  if (iVar1 == 0) {

    FUN_0019d3f0("itfMesManager.c",0xf30);

  }

  base = *(int *)(iVar1 + 4);
  /* Removing this barrier loses FUN_003a5120 (MATCH nd0 -> MISMATCH nd9) - measured W164. */
  asm ("" : "+m"(base));
  offset = param_2 * 8;
  return *(u32 *)(offset + base + 0x20);

}
#define FUN_003a5120(...) ((u32 (*)(...))FUN_003a5120)(__VA_ARGS__)
#undef FUN_003a51a0
// FUN_003A51A0


u32 FUN_003a51a0(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(DAT_00959eec_abs + param_1 * 0xd);

  if (iVar1 == 0) {

    FUN_0019d3f0("itfMesManager.c",0xf47);

  }

  return *(u32 *)(*(int *)(iVar1 + 4) + 0x18);

}
#define FUN_003a51a0(...) ((u32 (*)(...))FUN_003a51a0)(__VA_ARGS__)
#undef FUN_003b0bb0
#undef FUN_003b0c20
#undef FUN_003b0ce0
#undef thunk_FUN_003b0e04
#undef FUN_003a5210
// FUN_003A5210


void FUN_003a5210(int param_1,u64 param_2,u8 param_3,u8 param_4,

                 s16 param_5)



{

  u32 uVar1;

  

  uVar1 = *(u32 *)(*(int *)(DAT_00959eec_abs + param_1 * 0xd) + 0x30);

  FUN_003b0bb0(uVar1,param_4 & 0xff);

  FUN_003b0c20(uVar1,param_5);

  FUN_003b0ce0(uVar1,param_2);

  thunk_FUN_003b0e04(uVar1,param_3 & 0xff);

  return;

}
#define FUN_003a5210(...) ((void (*)(...))FUN_003a5210)(__VA_ARGS__)
#undef FUN_003a52c0
#undef FUN_003a53b0
// FUN_003A52C0


u64

FUN_003a52c0(u32 param_1,s32 param_2,f32 param_3,s32 param_4,

            s32 param_5,s32 param_6,s32 param_7,s32 param_8)



{

  u64 uVar1;

  

  FUN_003a5fd0(*(int *)(DAT_00959eec_abs + (int)param_7 * 0xd) + 0xd4);

  uVar1 = FUN_003a53b0(param_1,param_2,param_3,param_4,param_5,param_6,0,param_7,param_8);

  FUN_003b0ce0(uVar1,param_5);

  return uVar1;

}


// FUN_003A53B0
u32

FUN_003a53b0_int(int param_1,int param_2,u32 param_3,int param_4,int param_5,
                 u32 param_6,int param_7,int param_8,int param_9)



{

  int iVar1;

  int lVar2;

  u32 uVar3;

  

  iVar1 = *(int *)(DAT_00959eec_abs + param_7 * 0xd);

  if (iVar1 == 0) {

    FUN_0019d3f0("itfMesManager.c",0xfad);

  }

  lVar2 = *(int *)(iVar1 + 4);
  iVar1 = param_8 * 8;
  iVar1 = iVar1 + lVar2 + 0x20;

  if (iVar1 == 0) {

    FUN_0019d3f0("itfMesManager.c",0xfb0);

  }

  iVar1 = *(int *)(iVar1 + 4);

  if (iVar1 == 0) {

    FUN_0019d3f0("itfMesManager.c",0xfb3);

  }

  lVar2 = FUN_003a5940_typed(iVar1,0);

  if (lVar2 == 0) {

    FUN_0019d3f0("itfMesManager.c",0xfb6);

  }

  uVar3 = FUN_003b2940_u8(param_1 << 4,param_2 << 3,param_4,param_5,0,0xff,lVar2,0);

  if ((param_6 & 1) != 0) {

    thunk_FUN_003b0e04_u8(uVar3,param_5);

  }

  thunk_FUN_003b0e54(uVar3,param_3);

  return uVar3;

}
#define FUN_003a53b0(...) ((u64 (*)(...))FUN_003a53b0)(__VA_ARGS__)
#undef FUN_003a5540
// FUN_003A5540


#undef FUN_003a53b0
void FUN_003a5540(int p1,int p2,u64 p3,int p4,int p5,int p6,int p7)
{
  FUN_003a53b0_8(p1,p2,p3,p4,p5,0,p6,p7);
}
#define FUN_003a53b0(...) ((u64 (*)(...))FUN_003a53b0)(__VA_ARGS__)
#define FUN_003a5540(...) ((void (*)(...))FUN_003a5540)(__VA_ARGS__)
#undef FUN_003a5570
#undef FUN_003a53b0
// W212: correcting the mixed-ABI signature from integer-like u64 slots to
// the matched sibling's s32/f32 contract held nd 222 -> 222 and changed
// 380 -> 356 bytes (384 window). The first residual is now the +0x0 frame
// (ours 0xb0, retail 0xa0); the typed contract is retained as honest source.
// FUN_003A5570






u64

FUN_003a5570(u32 param_1,s32 param_2,f32 param_3,u32 param_4,
            s32 param_5,s32 param_6,s32 param_7,s32 param_8,s32 param_9)



{

  u64 uVar1;
  int iVar2;

  
  iVar2 = *(int *)(DAT_00959eec_abs + (int)param_8 * 0xd);

  if (param_6 == 10) {

    param_6 = 5;

    param_4 = param_4 & 0xffffff00 | (int)(DAT_007cad94 * (float)(param_4 & 0xff));

  }

  FUN_003a5fd0(iVar2 + 0xd4);

  uVar1 = FUN_003a53b0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);

  FUN_003b0ce0(uVar1,param_5);

  FUN_003b1330(uVar1,1);

  FUN_003b0170(uVar1);

  return 0;

}
#define FUN_003a5570(...) ((u64 (*)(...))FUN_003a5570)(__VA_ARGS__)
#undef FUN_003a56f0
// FUN_003A56F0






u64

FUN_003a56f0(u32 param_1,s32 param_2,f32 param_3,u32 param_4,

            s32 param_5,s32 param_6,s32 param_7,s32 param_8,s32 param_9,

            int param_10,int param_11)



{

  int iVar1;

  u32 uVar2;

  u64 uVar3;

  

  iVar1 = *(int *)(DAT_00959eec_abs + (int)param_8 * 0xd);

  if (param_8 < 0) {

    FUN_0019d3f0("itfMesManager.c",0xfeb);

  }

  if (param_10 < 0) {

    FUN_0019d3f0("itfMesManager.c",0xfec);

  }

  if (param_6 == 10) {

    param_6 = 5;

    param_4 = param_4 & 0xffffff00 | (int)(DAT_007cad94 * (float)(param_4 & 0xff));

  }

  FUN_003a5fd0(iVar1 + 0xd4);

  uVar2 = FUN_003a53b0_u32(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);

  if (param_11 != 0) {

    if (*(int *)((int)uVar2 + 0x24) == 0) {

      uVar3 = FUN_003a53b0_8f(param_1,param_2 + 0x19,param_3,param_4,param_5,param_6,param_7,

                           param_10,param_11);

    }

    else {

      uVar3 = FUN_003a53b0_8f(param_1,param_2 + 0x32,param_3,param_4,param_5,param_6,param_7,

                           param_10,param_11);

    }

    uVar2 = FUN_003b1920(uVar2,uVar3,0);

  }

  FUN_003b0ce0(uVar2,param_5);

  FUN_003b1330(uVar2,1);

  FUN_003b0170(uVar2);

  return 0;

}
#define FUN_003a56f0(...) ((u64 (*)(...))FUN_003a56f0)(__VA_ARGS__)
#undef FUN_003a5940
// FUN_003A5940


u32 FUN_003a5940(int param_1,int param_2)
{
  u32 uVar1;
  int count = *(short *)(param_1 + 0x18);

  if ((param_2 < 0) || (param_2 >= count)) {
    uVar1 = 0;
  }
  else {
    int address = param_2 * 4;
    address = address + param_1;
    uVar1 = *(u32 *)(address + 0x1c);
  }
  return uVar1;
}
#define FUN_003a5940(...) ((u32 (*)(...))FUN_003a5940)(__VA_ARGS__)
#undef FUN_003a5980
// W409 addressing/raw-literal fixes: NONMATCHING nd 364 -> 202, object 796/800 -> 800/800.
// FUN_003A5980 NONMATCHING


void FUN_003a5980(u32 *param_1)



{

  short sVar1;

  u8 uVar2;

  u16 uVar3;

  u32 uVar4;

  s32 lVar5;

  u32 uVar6;

  u32 uVar7;

  int iVar8;

  u32 *puVar9;

  

  puVar9 = param_1;

  if (puVar9[0xc] != 0) {

    FUN_003b0170(puVar9[0xc]);

    puVar9[0xc] = 0;

  }

  sVar1 = (short)puVar9[0xf];

  if ((sVar1 < 0) || (*(short *)(puVar9[0xb] + 0x18) <= sVar1)) {

    iVar8 = 0;

  }

  else {

    iVar8 = *(int *)(sVar1 * 4 + puVar9[0xb] + 0x1c);

  }

  if (iVar8 == 0) {

    FUN_0019d3f0("itfMesManager.c",0x1036);

  }

  if ((*(short *)((int)puVar9 + 0x12) == 4) && ((*puVar9 & 0x200000) != 0)) {

    FUN_003b1a80(0x14);

    DAT_007ce63c = 0x74;

  }

  else {

    FUN_003b1a70();

  }

  uVar4 = FUN_003b2940(puVar9[9],puVar9[10],*(u8 *)((int)puVar9 + 0x36),

                       *(u8 *)((int)puVar9 + 0x37),(char)puVar9[0xe],

                       *(u8 *)((int)puVar9 + 0x39),iVar8,0);

  if (0 < DAT_007ce63c) {

    FUN_003b1a70();

    DAT_007ce63c = 0;

  }

  if (*(short *)((int)puVar9 + 0x12) == 3) {

    lVar5 = FUN_003b1a90(uVar4);

    if (lVar5 == 1) {

      FUN_003b1c90(0x1000,0xc60,uVar4);

    }

    else {

      FUN_003b1c90(0x1000,0xbf8,uVar4);

    }

  }

  if (((*puVar9 & 0x400000) == 0) && (((*(u16 *)DAT_00959ecc_abs & 1) != 0))) {

    FUN_003a64c0_typed(uVar4);

  }

  FUN_003a62b0_typed(uVar4,puVar9 + 9);

  uVar2 = FUN_003b2a00(3);

  *(u8 *)((int)puVar9 + 0x35) = uVar2;

  if ((*(u8 *)((int)puVar9 + 0x35) & 2) == 0) {

    *puVar9 = *puVar9 & 0xfffeffff;

  }

  else {

    *puVar9 = *puVar9 | 0x10000;

  }

  uVar6 = FUN_003b2a00(0xc0);

  if (uVar6 == 0) {

    *puVar9 = *puVar9 & 0xf7ffffff;

  }

  else {

    *puVar9 = *puVar9 | 0x8000000;

  }

  if ((uVar6 & 0x80) == 0) {

    *puVar9 = *puVar9 & 0xfbffffff;

  }

  else {

    *puVar9 = *puVar9 | 0x4000000;

  }

  lVar5 = FUN_003b2a00(4);

  if ((lVar5 != 0) && ((code *)puVar9[0x79] != (code *)0x0)) {

    ((void (*)(void))puVar9[0x79])();

  }

  FUN_003b2a00(8);

  thunk_FUN_003a6360(uVar4,puVar9[3]);

  uVar7 = thunk_FUN_003a628c(uVar4);

  uVar3 = FUN_003a62e0_typed(uVar7,uVar4);

  *(u16 *)((int)puVar9 + 0x3a) = uVar3;

  lVar5 = FUN_003b2a00(0x10);

  if (lVar5 != 0) {

    FUN_003a6060_typed(param_1,DAT_0095abf0_abs);

  }

  puVar9[0xc] = (u32)uVar4;

  return;

}
#define FUN_003a5980(...) ((void (*)(...))FUN_003a5980)(__VA_ARGS__)
#undef FUN_003a5ca0
/* opt_common_subs off: measured nd 217 -> 55, object 508/512 -> 508/512. */
#pragma opt_common_subs off
// W212: transferring FUN_003A5EA0's typed allocation-slot structure and
// shared allocation path regressed nd 208 -> 228 and shrank 492 -> 396
// bytes (512 window), proving the duplicated branch bodies are genuine.
// The structured transfer was reverted byte-for-byte.
// FUN_003A5CA0 NONMATCHING


void FUN_003a5ca0(int param_1,int param_2,u32 param_3,int param_4)



{

  u32 uVar1;

  int iVar2;

  u32 uVar3;

  int lVar4;

  u32 *puVar5;

  int iVar6;

  u32 *puVar7;

  int *piVar8;

  int iVar9;

  int iVar10;

  

  if (param_1 == 0) {

    FUN_0019d3f0("itfMesManager.c",0x10a7);

  }

  if ((param_2 < 0) || (0x1f < param_2)) {

    FUN_0019d3f0("itfMesManager.c",0x10a8);

  }

  iVar10 = (int)param_1 + 0xd4;

  iVar6 = (int)param_2;

  iVar9 = iVar6 * 4;

  piVar8 = (int *)(iVar10 + iVar9);

  if (*piVar8 != 0) {

    FUN_00191a10(piVar8[0x20]);

    *piVar8 = 0;

  }

  if (param_4 < 1) {

    iVar2 = FUN_00524388(param_3);

    uVar1 = iVar2 + 4U & 0xfffffffc;

    lVar4 = FUN_0016f190(0x1424);

    if (lVar4 != 0) {

      puVar5 = (u32 *)(iVar9 + iVar10 + 0x80);

      uVar3 = (*DAT_00960178_abs)(uVar1,0x40000);

      *puVar5 = uVar3;

    }

    else {

      puVar5 = (u32 *)(iVar9 + iVar10 + 0x80);

      uVar3 = FUN_00191af0(uVar1);

      *puVar5 = uVar3;

    }

    uVar3 = *puVar5;

    *(u32 *)(iVar10 + iVar6 * 4) = uVar3;

    FUN_00521250(uVar3,param_3,uVar1);

  }

  else {

    uVar1 = (int)param_4 + 5U & 0xfffffffc;

    lVar4 = FUN_0016f190(0x1424);

    if (lVar4 != 0) {

      puVar5 = (u32 *)(iVar9 + iVar10 + 0x80);

      uVar3 = (*DAT_00960178_abs)(uVar1,0x40000);

      *puVar5 = uVar3;

    }

    else {

      puVar5 = (u32 *)(iVar9 + iVar10 + 0x80);

      uVar3 = FUN_00191af0(uVar1);

      *puVar5 = uVar3;

    }

    puVar7 = (u32 *)(iVar10 + iVar6 * 4);

    uVar3 = *puVar5;

    *puVar7 = uVar3;

    FUN_00521408(uVar3,0,uVar1);

    FUN_00521250(*puVar7,param_3,param_4);

  }

  return;

}
#define FUN_003a5ca0(...) ((void (*)(...))FUN_003a5ca0)(__VA_ARGS__)
#pragma opt_common_subs reset
#undef FUN_003a5ea0


// FUN_003A5EA0


void FUN_003a5ea0(int manager, int index, u32 value)
{
  ItfMesAllocationSlots *slots;
  u32 *object;
  u32 *allocation;
  int byte_offset;
  u32 memory;

  if (manager == 0) {
    FUN_0019d3f0("itfMesManager.c", 0x10ea);
  }
  if ((index < 0) || (index >= 32)) {
    FUN_0019d3f0("itfMesManager.c", 0x10eb);
  }

  manager += 0xd4;
  slots = (ItfMesAllocationSlots *)manager;
  byte_offset = index * sizeof(u32);
  object = (u32 *)((u8 *)slots->objects + byte_offset);
  if (*object != 0) {
    FUN_00191a10(*(u32 *)((u8 *)slots->allocations + byte_offset));
    *object = 0;
  }

  if (FUN_0016f190(0x1424) != 0) {
    allocation = (u32 *)((u8 *)slots->allocations + byte_offset);
    *allocation = (*DAT_00960178_abs)(4, 0x40000);
  } else {
    allocation = (u32 *)((u8 *)slots->allocations + byte_offset);
    *allocation = FUN_00191af0(4);
  }
  object = &slots->objects[index];
  memory = *allocation;
  *object = memory;
  *(u32 *)memory = value;
}
#define FUN_003a5ea0(...) ((void (*)(...))FUN_003a5ea0)(__VA_ARGS__)
#undef FUN_003a5fd0
// FUN_003A5FD0


void FUN_003a5fd0(int param_1)



{

  int iVar1;

  

  for (iVar1 = 0; iVar1 < 0x20; iVar1 = iVar1 + 1) {

    FUN_003b2a10(iVar1,*(u32 *)(param_1 + iVar1 * 4));

  }

  return;

}
#define FUN_003a5fd0(...) ((void (*)(...))FUN_003a5fd0)(__VA_ARGS__)
#undef FUN_003a6030
// FUN_003A6030


u32 FUN_003a6030(int param_1)
{
  u16 uVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar5;
  u32 uVar4;

  uVar1 = *(u16 *)(param_1 + 0x20);
  uVar2 = *(u32 *)(param_1 + 4);
  uVar3 = *(u32 *)(uVar2 + 0x18);
  uVar5 = uVar3 * 8;
  uVar4 = *(u32 *)(uVar5 + uVar2 + 0x20);
  return *(u32 *)(uVar4 + uVar1 * 4);
}
#define FUN_003a6030(...) ((u32 (*)(...))FUN_003a6030)(__VA_ARGS__)
#undef FUN_003a6060
// FUN_003A6060


void FUN_003a6060(u8 *param_1,u64 param_2)



{

  u32 uVar1;
  u8 *entry;


  

  if (param_1 == 0) {

    FUN_0019d3f0("itfMesManager.c",0x1136);

  }
  entry = param_1 + 0x14;


  if (*(int *)(param_1 + 0x1c) != 0) {

    FUN_003b0170(*(u32 *)(param_1 + 0x1c));

  }

  uVar1 = FUN_003b2940(*(u32 *)entry,*(u32 *)(entry + 4),0,1,0,0xff,

                       param_2,0);

  *(u32 *)(entry + 8) = uVar1;

  *(u16 *)(entry + 0xc) = 0xffff;

  return;

}
#define FUN_003a6060(...) ((void (*)(...))FUN_003a6060)(__VA_ARGS__)
#undef FUN_003a6100
// FUN_003A6100


int FUN_003a6100(int param_1,u32 param_2)
{
  int iVar1;

  iVar1 = 0;
  for (; 0 < param_1;) {
    if ((param_2 & 1) == 0) {
      iVar1 = iVar1 + 1;
    }
    param_1 = param_1 + -1;
    param_2 = param_2 >> 1;
  }
  return iVar1;
}
#define FUN_003a6100(...) ((int (*)(...))FUN_003a6100)(__VA_ARGS__)
#undef FUN_003a6140
#undef FUN_003a6410
// FUN_003A6140


u32 FUN_003a6140(u32 *param_1,int param_2,u32 param_3,u32 param_4,int param_5,

                 u32 param_6,s32 param_7,u32 param_8)



{

  int iVar1;

  int iVar3;

  u32 lVar2;

  

  lVar2 = 0;

  for (iVar3 = 0; iVar3 < param_2; iVar3 = iVar3 + 1, param_1 = param_1 + 1) {

    if ((param_3 & 1) != 0) {

      param_3 = param_3 >> 1;

    }

    else {

      lVar2 = FUN_003b2940(param_4,param_5,(u8)param_8,0,0,0xff,*param_1,lVar2);

      if (param_7 == 0) {

        param_5 = param_5 + *(short *)((int)lVar2 + 0x12) * 8;

      }

      else {

        param_5 = param_5 + param_7;

      }

      param_3 = param_3 >> 1;

    }



  }

  if (lVar2 != 0) {

    thunk_FUN_003a6360(lVar2,param_6);

    FUN_003a6410(lVar2,0xff);

  }

  return lVar2;

}





#undef FUN_003a628c
/* optimization_level 3: measured O2 nd 26, object 32/8 (over window); O3 nd 0, object 8/8 (MATCH); retain O3. */
#pragma optimization_level 3
// FUN_003A6280 thunk_FUN_003a628c
int thunk_FUN_003a628c(int param_1)
{
  return FUN_003a628c(param_1);
}
#pragma optimization_level 2
#define FUN_003a6140(...) ((long (*)(...))FUN_003a6140)(__VA_ARGS__)
#define FUN_003a6410(...) ((void (*)(...))FUN_003a6410)(__VA_ARGS__)

/* Fall-through-only branch target for the loop in FUN_003a628c; never returns
 * on its own and has no C equivalent (a normal C function always emits a
 * return). Kept as single-instruction inline asm. */
// FUN_003A6288
asm void FUN_003a6288(void)
{
  .set noreorder
  daddu $a0, $v0, $zero
}

// FUN_003A628C
asm int FUN_003a628c(int param_1)
{
  .set noreorder
  lw $v0, 0x24($a0)
  nop
  nop
  nop
  .word 0x1440fffa  /* bnez $v0, FUN_003a6288 (label unavailable across function boundary) */
  nop
  daddu $v0, $a0, $zero
  jr $ra
  nop
}
#define FUN_003a628c(...) ((int (*)(...))FUN_003a628c)(__VA_ARGS__)
#undef FUN_003a62b0
// FUN_003A62B0


void FUN_003a62b0(int param_1,int param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x20);

  *(char *)(param_2 + 0x15) = (char)((int)(u32)*(u8 *)(param_1 + 2) >> 1);

  *(u8 *)(param_2 + 0x12) = *(u8 *)(iVar1 + 0x15);

  *(u8 *)(param_2 + 0x13) = *(u8 *)(iVar1 + 0x14);

  *(u8 *)(param_2 + 0x14) = *(u8 *)(iVar1 + 0x16);

  return;

}
#define FUN_003a62b0(...) ((void (*)(...))FUN_003a62b0)(__VA_ARGS__)
#undef FUN_003a62e0
// FUN_003A62E0


int FUN_003a62e0(int param_1,int param_2)



{

  return (*(int *)(param_2 + 8) - *(int *)(param_1 + 8) >> 3) / (int)*(short *)(param_2 + 0x12) + 1;

}





// FUN_003A6310 thunk_FUN_003a6334
void thunk_FUN_003a6334(int param_1,int param_2,int param_3)
{
  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x24)) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + param_2;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3;
  }
  return;
}

// FUN_003A6350 thunk_FUN_003a6360
void thunk_FUN_003a6360(int param_1,u32 param_2)
{
  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x24)) {
    *(u32 *)(param_1 + 0x14) = param_2;
  }
  return;
}

#undef FUN_003a6380
// FUN_003A6380
static int FUN_003a6380(param_1,param_2,param_3,param_4)
int param_1;
int param_2;
int param_3;
u8 param_4;
{
  int color;
  int diff;
  int cat;
  int candidate;

  diff = param_3 - param_2;
  param_2 = diff - 1;
  cat = *(int *)(param_1 + 8);
  goto count_check;

advance:
  param_1 = *(int *)(param_1 + 0x24);
  if (param_1 == 0) {
    goto done;
  }

load:
  candidate = *(int *)(param_1 + 8);
  if (cat == candidate) {
    goto advance;
  }
  param_2 = param_2 - 1;
  cat = candidate;

count_check:
  if (param_2 > 0) {
    goto load;
  }

set_start:
  color = (u8)param_4;
set_load:
  candidate = *(int *)(param_1 + 0x1c);
  goto set_check;

set_store:
  *(u8 *)(candidate + 0x14) = (u8)color;
  candidate = *(int *)(candidate + 0x28);

set_check:
  if (candidate != 0) {
    goto set_store;
  }
  param_1 = *(int *)(param_1 + 0x24);
  switch (param_1) {
  case 0:
    goto done;
  }
  candidate = *(int *)(param_1 + 8);
  if (cat == candidate) {
    goto set_load;
  }
  goto done;
done:
  return;
}
#undef FUN_003a6410
#pragma push
/* Removing this loses FUN_003a6410 (MATCH nd0 -> MISMATCH nd24) - measured W161. */
#pragma opt_loop_invariants on
// FUN_003A6410


void FUN_003a6410(int param_1,u32 param_2)
{
  int iVar1;

  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x24)) {
    for (iVar1 = *(int *)(param_1 + 0x1c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x28)) {
      *(u32 *)(iVar1 + 0x10) = *(u32 *)(iVar1 + 0x10) & 0xffffff00 | param_2;
    }
  }
  return;
}
#pragma pop
#define FUN_003a6410(...) ((void (*)(...))FUN_003a6410)(__VA_ARGS__)
#undef FUN_003a6460
// FUN_003A6460

int FUN_003a6460(int param_1)
{
  int iVar3;
  int iVar1;
  int iVar2;

  iVar3 = 0;
  goto outer_test;
outer_body:
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = 0;
  do {
    iVar2 += *(int *)(param_1 + 0xc);
    param_1 = *(int *)(param_1 + 0x24);
    if (param_1 == 0) {
      break;
    }
  } while (iVar1 == *(int *)(param_1 + 8));
  if (iVar3 < iVar2) {
    iVar3 = iVar2;
  }
outer_test:
  if (param_1 != 0) {
    goto outer_body;
  }
  return iVar3 << 4;
}
#define FUN_003a6460(...) ((int (*)(...))FUN_003a6460)(__VA_ARGS__)
#undef FUN_003a64c0
// FUN_003A64C0


void FUN_003a64c0(int param_1)



{

  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x24)) {

    if (*(u8 *)(*(int *)(param_1 + 0x1c) + 0x16) == '\0') {

      FUN_003b0c70(param_1);

    }

  }

  return;

}
#define FUN_003a64c0(...) ((void (*)(...))FUN_003a64c0)(__VA_ARGS__)
#undef FUN_003a6520
// FUN_003A6520


void FUN_003a6520(u32 *param_1)



{

  u32 uVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  u32 *puVar6;
  u32 *geometry;

  

  puVar6 = param_1 + 0x2a;
  geometry = param_1 + 9;

  if (puVar6[1] == 0) {

    switch(*(s16 *)((int)param_1 + 0x12)) {

    case 0:

    case 1:

    case 2:

    case 3:
    default:

      uVar1 = FUN_003a8b00(6,*(u32 *)DAT_00959ec4_abs);

      puVar6[1] = uVar1;

      if (*puVar6 != 0) {

        iVar2 = FUN_003b1b00(0,param_1[7]);

        *(int *)(puVar6[1] + 0x20) = *(int *)(param_1[7] + 4) + iVar2;

      }

      break;

    case 4:

      uVar1 = FUN_003a8b00(10,*(u32 *)DAT_00959ec4_abs);

      puVar6[1] = uVar1;

      if (*puVar6 != 0) {

        iVar2 = FUN_003b1b00(0,param_1[7]);

        *(int *)(puVar6[1] + 0x20) = *(int *)(param_1[7] + 4) + iVar2;

      }

      break;

    case 5:

      uVar1 = FUN_003a8b00(0xc,*(u32 *)DAT_00959ec4_abs);

      puVar6[1] = uVar1;

      if (*puVar6 != 0) {

        iVar2 = FUN_003b1b00(0,param_1[7]);

        *(int *)(puVar6[1] + 0x20) = *(int *)(param_1[7] + 4) + iVar2;

      }

      break;

    case 6:

      uVar1 = FUN_003a8b00(0xd,*(u32 *)DAT_00959ec4_abs);

      puVar6[1] = uVar1;

      if (*puVar6 != 0) {

        iVar2 = FUN_003b1b00(0,param_1[7]);

        *(int *)(puVar6[1] + 0x20) = *(int *)(param_1[7] + 4) + iVar2;

      }

      break;

    case 7:

      uVar1 = FUN_003a8b00(0xe,*(u32 *)DAT_00959ec4_abs);

      puVar6[1] = uVar1;

      if (*puVar6 != 0) {

        iVar2 = FUN_003b1b00(0,param_1[7]);

        *(int *)(puVar6[1] + 0x20) = *(int *)(param_1[7] + 4) + iVar2;

      }

    }
  }
  if (*(short *)((int)param_1 + 0x12) != 5) {
    if (*(short *)((int)param_1 + 0x12) != 4) {
      iVar2 = geometry[0] + puVar6[3];
      iVar5 = geometry[1] + puVar6[4];
      iVar3 = geometry[0] + puVar6[5];
      iVar4 = geometry[1] + puVar6[6];
    }
    else {
      iVar2 = 0;
      iVar5 = 0;
      iVar3 = 0;
      iVar4 = 0;
    }
  }
  else {
    iVar2 = 0;
    iVar5 = 0;
    iVar3 = 600;
    iVar4 = 100;
  }

  FUN_003a8dc0(puVar6[1],iVar2,iVar5,iVar3,iVar4,param_1[3]);
  *(int *)(puVar6[1] + 0x24) = iVar5;
  FUN_003a8fb0(puVar6[1],puVar6[7],puVar6[8],puVar6[9],0);

  uVar1 = *param_1;

  *param_1 = uVar1 & 0xfffffcff;

  *param_1 = uVar1 & 0xfffffcff | 0x100;

  return;

}
#define FUN_003a6520(...) ((void (*)(...))FUN_003a6520)(__VA_ARGS__)
#undef FUN_003a67e0
// FUN_003A67E0


void FUN_003a67e0(u32 *param_1)
{
  u32 *secondary;
  u32 *work;
  int lineCount;
  u32 handle;

  work = param_1 + 0x2a;
  secondary = param_1 + 5;
  if ((secondary[2] != 0) && ((*param_1 & 0x10000) == 0)) {
    if (*work == 0) {
      lineCount = *(int *)(secondary[2] + 0xc);
      handle = FUN_003a8b00(7,*(u32 *)DAT_00959ec4_abs);
      *work = handle;
      FUN_003a8dc0(handle,secondary[0] - 0x2d0,secondary[1] - 0x68,
                   secondary[0] + lineCount * 0x10 + 0x2d0,
                   secondary[1] + 0x110,param_1[3]);
      FUN_003a8fb0(*work,0x7f,0x7f,0x7f,0);
    }
    *param_1 &= 0xffffcfff;
    *param_1 |= 0x1000;
  } else if (*work != 0) {
    *param_1 &= 0xffffcfff;
    *param_1 |= 0x3000;
  }
}
#define FUN_003a67e0(...) ((void (*)(...))FUN_003a67e0)(__VA_ARGS__)
#undef FUN_003a6900
// FUN_003A6900


void FUN_003a6900(u32 *param_1,long param_2)



{

  if (param_2 != 0) {

    *param_1 = 0x290;

    param_1[1] = 0xa48;

  }

  param_1[2] = 0;

  *(u16 *)(param_1 + 3) = 0xffff;

  return;

}
#define FUN_003a6900(...) ((void (*)(...))FUN_003a6900)(__VA_ARGS__)
#undef FUN_003a6930
// FUN_003A6930


void FUN_003a6930(u32 *param_1,long param_2)



{

  if (param_2 != 0) {

    *param_1 = 0x360;

    param_1[1] = 0xb18;

  }

  param_1[2] = 0;

  param_1[3] = 0;

  *(u8 *)(param_1 + 4) = 0;

  *(u8 *)((int)param_1 + 0x11) = 0;

  *(u16 *)((int)param_1 + 0x16) = 0;

  *(u16 *)(param_1 + 6) = 0;

  *(u16 *)((int)param_1 + 0x1a) = 0;

  *(u8 *)((int)param_1 + 0x12) = 0;

  *(u8 *)((int)param_1 + 0x13) = 0;

  *(u8 *)(param_1 + 5) = 0;

  *(u8 *)((int)param_1 + 0x15) = 0xff;

  return;

}
#define FUN_003a6930(...) ((void (*)(...))FUN_003a6930)(__VA_ARGS__)
#undef FUN_003a6980
// FUN_003A6980


void FUN_003a6980(u32 *param_1)



{

  *param_1 = 0xef0;

  param_1[1] = 0xf40;

  param_1[3] = 0;

  param_1[4] = 0;

  *(u16 *)(param_1 + 5) = 0;

  *(short *)((int)param_1 + 0x16) = -1;
  *(short *)(param_1 + 6) = -1;

  *(u16 *)((int)param_1 + 0x1a) = 0;

  param_1[7] = 0;

  param_1[8] = 0;

  *(u16 *)(param_1 + 9) = 0;

  *(u16 *)((int)param_1 + 0x26) = 0;

  return;

}
#define FUN_003a6980(...) ((void (*)(...))FUN_003a6980)(__VA_ARGS__)
#undef FUN_003a69d0
// FUN_003A69D0


void FUN_003a69d0(u32 *param_1)



{

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = 0;

  FUN_003a6ca0_typed((int)param_1,0,0);

  return;

}
#define FUN_003a69d0(...) ((void (*)(...))FUN_003a69d0)(__VA_ARGS__)
#undef FUN_003a6a10
// FUN_003A6A10


void FUN_003a6a10(int param_1)



{

  int iVar1;

  

  for (iVar1 = 0; iVar1 < 0x20; iVar1 = iVar1 + 1) {

    *(u32 *)(param_1 + iVar1 * 4) = 0;

  }

  return;

}
#define FUN_003a6a10(...) ((void (*)(...))FUN_003a6a10)(__VA_ARGS__)
#undef FUN_003a6a40
// FUN_003A6A40


void FUN_003a6a40(u8 *param_1,long param_2)



{

  if (param_2 == 0) {

    *param_1 = 0;

  }

  *(u16 *)(param_1 + 2) = 0;

  *(u16 *)(param_1 + 4) = 0;

  *(u16 *)(param_1 + 6) = 0;

  *(u32 *)(param_1 + 8) = 0;

  *(u16 *)(param_1 + 0xc) = 0x238;

  *(u16 *)(param_1 + 0xe) = 0x18b;

  return;

}
#define FUN_003a6a40(...) ((void (*)(...))FUN_003a6a40)(__VA_ARGS__)
#undef FUN_003a6a80
// FUN_003A6A80


void FUN_003a6a80(int param_1,u16 param_2,u16 param_3)



{

  int iVar1;

  

  iVar1 = *(int *)(DAT_00959eec_abs + param_1 * 0xd);

  if (iVar1 == 0) {

    FUN_0019d3f0("itfMesManager.c",0x1420);

  }

  *(u16 *)(iVar1 + 0x1e0) = param_2;

  *(u16 *)(iVar1 + 0x1e2) = param_3;

  return;

}
#undef FUN_003a6b00
// FUN_003A6B00


void FUN_003a6b00(u32 *param_1)



{
  /* Caller-specific typed ABI: this path passes the resource handle in a0. */
  extern void FUN_003a8d60(int resource);

  u32 *mesHandles;

  u32 resource;

  mesHandles = param_1 + 0x2a;

  resource = mesHandles[0];

  if (resource != 0) {

    FUN_003a8d60(resource);

    mesHandles[0] = 0;

  }

  resource = mesHandles[1];

  if (resource != 0) {

    FUN_003a8d60(resource);

    mesHandles[1] = 0;

  }

  resource = mesHandles[2];

  if (resource != 0) {

    FUN_003a8d60(resource);

    mesHandles[2] = 0;

  }

  *param_1 = *param_1 & 0xfffff0ff;

  return;

}
#define FUN_003a6b00(...) ((void (*)(...))FUN_003a6b00)(__VA_ARGS__)
#undef FUN_003a6b90
// FUN_003A6B90


void FUN_003a6b90(int param_1)



{

  int *piVar1;

  int iVar2;

  

  for (iVar2 = 0; iVar2 < 0x20; iVar2 = iVar2 + 1) {

    piVar1 = (int *)(param_1 + iVar2 * 4);

    if (*piVar1 != 0) {

      FUN_00191a10(piVar1[0x20]);

      *piVar1 = 0;

    }

  }

  return;

}
#define FUN_003a6b90(...) ((void (*)(...))FUN_003a6b90)(__VA_ARGS__)
#undef FUN_003a6c10
#pragma push
/* Removing this loses FUN_003a6c10 (MATCH nd0 -> MISMATCH nd1) - measured W161. */
#pragma opt_loop_invariants on
// FUN_003A6C10


short * FUN_003a6c10(int param_1,short *param_2)



{

  int iVar1;
  int iVar2;

  int aiStack_30 [12];


  iVar1 = 0;

  do {

    aiStack_30[iVar1] = param_1 % 10;

    param_1 = param_1 / 10;

    iVar1 = iVar1 + 1;

    if (param_1 < 1) break;

  } while (iVar1 < 10);

  iVar2 = iVar1 + -1;

  for (; iVar2 >= 0;) {

    *param_2 = (aiStack_30[iVar2] + 0x10) * 0x100 + 0x8080;

    iVar2 = iVar2 + -1;

    param_2 = param_2 + 1;

  }

  *param_2 = 0;

  return param_2;

}
#pragma pop
#define FUN_003a6c10(...) ((short * (*)(...))FUN_003a6c10)(__VA_ARGS__)
#undef FUN_003a6ca0
// FUN_003A6CA0 NONMATCHING


void FUN_003a6ca0(int param_1,int param_2,int param_3)



{

  if (param_2 == 5) {

    *(u32 *)(param_1 + 0xc) = 0;

    *(u32 *)(param_1 + 0x10) = 0;

    *(u32 *)(param_1 + 0x14) = 0x2580;

    *(u32 *)(param_1 + 0x18) = 0x640;

    *(u32 *)(param_1 + 0x1c) = 0;

    *(u32 *)(param_1 + 0x20) = 0;

    *(u32 *)(param_1 + 0x24) = 0;

    if (param_3 < 1) {

      param_3 = 0x80;

    }

    *(int *)(param_1 + 0x28) = param_3;

  }

  else if (param_2 == 4) {

    *(u32 *)(param_1 + 0xc) = 0;

    *(u32 *)(param_1 + 0x10) = 0;

    *(u32 *)(param_1 + 0x14) = 0;

    *(u32 *)(param_1 + 0x18) = 0;

    *(u32 *)(param_1 + 0x1c) = 0;

    *(u32 *)(param_1 + 0x20) = 0;

    *(u32 *)(param_1 + 0x24) = 0;

    if (param_3 < 1) {

      param_3 = 0x80;

    }

    *(int *)(param_1 + 0x28) = param_3;

  }

  else if (param_2 == 2) {

    *(u32 *)(param_1 + 0xc) = 0xfffff9f0;

    *(u32 *)(param_1 + 0x10) = 0xffffff80;

    *(u32 *)(param_1 + 0x14) = 0x1cb0;

    *(u32 *)(param_1 + 0x18) = 0x288;

    *(u32 *)(param_1 + 0x1c) = 0x80;

    *(u32 *)(param_1 + 0x20) = 0x80;

    *(u32 *)(param_1 + 0x24) = 0x80;

    if (param_3 < 1) {

      param_3 = 0x80;

    }

    *(int *)(param_1 + 0x28) = param_3;

  }

  else if (param_2 == 1) {

    *(u32 *)(param_1 + 0xc) = 0xfffffc70;

    *(u32 *)(param_1 + 0x10) = 0xffffff80;

    *(u32 *)(param_1 + 0x14) = 0x1a30;

    *(u32 *)(param_1 + 0x18) = 0x288;

    *(u32 *)(param_1 + 0x1c) = 0x80;

    *(u32 *)(param_1 + 0x20) = 0x80;

    *(u32 *)(param_1 + 0x24) = 0x80;

    if (param_3 < 1) {

      param_3 = 0x80;

    }

    *(int *)(param_1 + 0x28) = param_3;

  }

  else {

    *(u32 *)(param_1 + 0xc) = 0xfffffc70;

    *(u32 *)(param_1 + 0x10) = 0xffffff80;

    *(u32 *)(param_1 + 0x14) = 0x1a30;

    *(u32 *)(param_1 + 0x18) = 0x288;

    *(u32 *)(param_1 + 0x1c) = 0x80;

    *(u32 *)(param_1 + 0x20) = 0x80;

    *(u32 *)(param_1 + 0x24) = 0x80;

    if (param_3 < 1) {

      param_3 = 0x80;

    }

    *(int *)(param_1 + 0x28) = param_3;

  }

  return;

}
#define FUN_003a6ca0(...) ((void (*)(...))FUN_003a6ca0)(__VA_ARGS__)
#undef FUN_003a6e30
// FUN_003A6E30


void FUN_003a6e30(u32 *param_1)



{

  short sVar1;

  u32 uVar2;

  int lVar3;

  int iVar4;
  u32 uVar5;

  u32 uVar6;
  u32 *work;
  u32 *entries;
  u32 *primary;
  int entryCount;

  

  work = param_1 + 0x2a;
  uVar2 = work[1];

  uVar5 = *param_1 & 0x300;

  switch (uVar5) {
  case 0x100:
    if (((*param_1 & 0x2000000) != 0 || (lVar3 = FUN_003cf630(), lVar3 == 0)) &&
        (lVar3 = FUN_003a9630(uVar2), lVar3 != 0)) {
      sVar1 = (short)param_1[0xf];
      entries = (u32 *)param_1[0xb];
      entryCount = *(short *)((u8 *)entries + 0x18);
      if ((sVar1 < 0) || (sVar1 >= entryCount)) {
        uVar6 = 0;
      }
      else {
        uVar6 = entries[sVar1 + 7];
      }
      FUN_003b2bf0(uVar6,0,0xf248);
      sVar1 = (short)param_1[0xf];
      entries = (u32 *)param_1[0xb];
      entryCount = *(short *)((u8 *)entries + 0x18);
      if ((sVar1 < 0) || (sVar1 >= entryCount)) {
        uVar6 = 0;
      }
      else {
        uVar6 = entries[sVar1 + 7];
      }
      FUN_003b2bf0(uVar6,0,0xf349);
      uVar2 = *param_1;
      *param_1 = uVar2 & 0xfffffcf8;
      *param_1 = uVar2 & 0xfffffcf8 | 0x203;
    }
    break;
  case 0x200:
    FUN_003a96b0(uVar2);
    break;
  case 0x300:
    lVar3 = FUN_003a9670(uVar2);
    if (lVar3 != 0) {
      *param_1 = *param_1 & 0xfffffcff;
    }
    break;
  }

  primary = (u32 *)work[0];

  uVar5 = *param_1 & 0x3000;

  switch (uVar5) {
  case 0x1000:
    if ((*param_1 & 0x2000000) != 0 || (lVar3 = FUN_003cf630(), lVar3 == 0)) {
      iVar4 = primary[14] + 0x20;
      primary[14] = iVar4;
      if (iVar4 < 200) {
        break;
      }
      primary[14] = 200;
      uVar2 = *param_1;
      *param_1 = uVar2 & 0xffffcfff;
      *param_1 = uVar2 & 0xffffcfff | 0x2000;
    }
    break;
  case 0x3000:
    iVar4 = primary[14] + -0x20;
    primary[14] = iVar4;
    if (iVar4 < 1) {
      primary[14] = 0;
      *param_1 = *param_1 & 0xffffcfff;
      FUN_003a8d60(primary);
      work[0] = 0;
    }
    break;
  }

  uVar2 = work[2];

  switch (*param_1 & 0xc00) {
  case 0x400:
    lVar3 = FUN_003a9630(uVar2);
    if (lVar3 != 0) {
      uVar2 = *param_1;
      *param_1 = uVar2 & 0xfffff3f8;
      *param_1 = uVar2 & 0xfffff3f8 | 0x803;
    }
    break;
  case 0xc00:
    lVar3 = FUN_003a9670(uVar2);
    if (lVar3 != 0) {
      *param_1 = *param_1 & 0xfffff3ff;
      FUN_003a8d60(uVar2);
      work[2] = 0;
    }
    break;
  }

  return;

}
#define FUN_003a6e30(...) ((void (*)(...))FUN_003a6e30)(__VA_ARGS__)
#undef FUN_003a7120
/* opt_lifetimes on: measured nd 539 -> 536, object 876/880 -> 876/880. */
#pragma opt_lifetimes on
// W409 raw-literal relocation: NONMATCHING nd 536 -> 532, object 876/880 -> 876/880.
// W417 rejected typed-call census closure: adding 0x003a5980 and 0x003a67e0 closed 12 -> 14 calls,
// but baseline nd 532/object 876/window 880 (60.7%) -> closure nd 590/object 860/window 880 (68.6%).
// The 16-byte shrink shows the aliases replaced compiler-inlined bodies with out-of-line calls;
// reverted to old-style calls until the frame or shape is fixed.
// FUN_003A7120 NONMATCHING


void FUN_003a7120(u32 *param_1)



{

  u32 uVar1;

  int lVar2;

  int iVar3;

  u32 *puVar4;

  u8 auStack_10 [12];

  u16 uStack_4;

  u16 uStack_2;

  

  puVar4 = (u32 *)param_1;

  if ((char)puVar4[0xd] == '\x01') {

    uVar1 = *puVar4;

    if ((uVar1 & 7) == 4) {

      puVar4[0x77] = puVar4[0x77] + 1;

      if ((*puVar4 & 0x800000) == 0) {

        if ((*puVar4 & 0x100000) == 0) {

          *(u8 *)(puVar4 + 0x75) = 1;

        }

        if (((((*puVar4 & 0x4000000) == 0) &&

             ((((DAT_007e094e & 0x40) != 0 || ((DAT_007e094e & 0x20) != 0)) ||

              (((DAT_007e094c & 0x10) != 0 && ((4 < puVar4[0x77] && ((DAT_007ce620 & 1) == 0))))))))

            || (*(char *)((u8 *)puVar4 + 0x35) == '\0')) ||

           (((*puVar4 & 0x8000000) != 0 && (lVar2 = FUN_003b1710(puVar4[0xc]), lVar2 != 0)))) {

          FUN_005225a8(DAT_006a1ba0_abs);

          FUN_00521250(auStack_10,puVar4 + 0x75,0x10);

          *(u8 *)(puVar4 + 0x75) = 0;

          *(u16 *)((int)puVar4 + 0x1d6) = 0;

          *(u16 *)(puVar4 + 0x76) = 0;

          *(u16 *)((int)puVar4 + 0x1da) = 0;

          puVar4[0x77] = 0;

          *(u16 *)(puVar4 + 0x78) = 0x238;

          *(u16 *)((int)puVar4 + 0x1e2) = 0x18b;

          *(short *)(puVar4 + 0xf) = (short)puVar4[0xf] + 1;

          FUN_00109f60(2,0);

          if ((short)puVar4[0xf] < *(short *)((int)puVar4 + 0x3e)) {

            for (iVar3 = 0; iVar3 < 0x20; iVar3 = iVar3 + 1) {

              FUN_003b2a10(iVar3,puVar4[iVar3 + 0x35]);

            }

            if (puVar4[2] != 0) {

              FUN_003b19a0(puVar4[2]);

            }

            FUN_003a5980(param_1);

            if (*(short *)((int)puVar4 + 0x12) == 6) {

              uVar1 = puVar4[0xc];

              FUN_003b0bb0(uVar1,0x20);

              FUN_003b0c20(uVar1,0);

              FUN_003b0ce0(uVar1,0);

              thunk_FUN_003b0e04(uVar1,0);

              *(u16 *)(puVar4 + 0x78) = uStack_4;

              *(u16 *)((int)puVar4 + 0x1e2) = uStack_2;

            }

            FUN_003a67e0(param_1);

            uVar1 = *puVar4;

            *puVar4 = uVar1 & 0xfffffff8;

            *puVar4 = uVar1 & 0xfffffff8 | 3;

          }

          else {

            *(u8 *)(puVar4 + 0xd) = 0xff;

          }

        }

      }

      else {

        *(u8 *)(puVar4 + 0xd) = 0xff;

      }

    }

    else {

      if (((uVar1 & 0x4000000) == 0) &&

         (((((DAT_007e094e & 0x40) != 0 || ((DAT_007e094e & 0x20) != 0)) ||

           (((DAT_007e094c & 0x10) != 0 && ((DAT_007ce620 & 1) == 0)))) &&

          (((uVar1 & 0x400000) == 0 && ((uVar1 & 0x1000000) == 0)))))) {

        for (uVar1 = puVar4[0xc]; uVar1 != 0; uVar1 = *(u32 *)(uVar1 + 0x24)) {

          FUN_003b0c70(uVar1);

        }

        if (puVar4[7] != 0) {

          FUN_003b0c70(puVar4[7]);

        }

      }

      *puVar4 = *puVar4 & 0xfeffffff;

    }

  }

  return;

}
#define FUN_003a7120(...) ((void (*)(...))FUN_003a7120)(__VA_ARGS__)
#pragma opt_lifetimes reset
#undef FUN_003a7490
// W415 typed-call census closure: nd 862 -> 857, object 1168/1200 -> 1144/1200.
// W415 failed probe: FUN_003a7940_typed(int param_1, ...) rejected pointer argument; u32 * alias retained.
// FUN_003A7490 NONMATCHING


void FUN_003a7490(u32 *param_1)



{

  u32 *puVar11;

  u32 uVar2;

  int sVar4;

  int sVar1;

  int lVar3;

  int iVar5;

  u32 uVar6;

  u32 uVar7;

  int *piVar8;

  int iVar9;

  u32 *puVar10;

  

  puVar11 = (u32 *)param_1;

  uVar2 = *puVar11;

  sVar4 = puVar11[0x15] & 0xffff;

  switch (sVar4) {
  case 1:

    sVar4 = *(short *)((int)puVar11 + 0x12);

    if (sVar4 == 2) {

      iVar5 = puVar11[10] + *(short *)((int)puVar11 + 0x3a) * 200;

      iVar9 = puVar11[0x11] + (*(short *)((int)puVar11 + 0x5a) + -1) * -200;

      if ((puVar11[10] == 0xb18) && (puVar11[0x2b] != 0)) {

        *(int *)(puVar11[0x2b] + 0x28) = iVar5 - iVar9;

        piVar8 = (int *)(puVar11[0x2b] + 0x28);

        uVar6 = *(u32 *)(puVar11[0x2b] + 0x28);

        uVar7 = uVar6 & 0x3f;

        if (((int)uVar6 < 0) && (uVar7 != 0)) {

          uVar7 = uVar7 - 0x40;

        }

        *piVar8 = *piVar8 - uVar7;

        *(int *)(puVar11[0x2b] + 0x28) = *(int *)(puVar11[0x2b] + 0x28) + 0x40;

      }

      uVar6 = puVar11[0xc];

      if ((uVar6 == 0) || (iVar5 <= iVar9)) {

        if ((uVar2 & 0xc00) != 0x400) {

          if (uVar6 != 0) {

            for (; uVar6 != 0; uVar6 = *(u32 *)(uVar6 + 0x24)) {

              for (iVar5 = *(int *)(uVar6 + 0x1c); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x28)) {

                *(u8 *)(iVar5 + 0x14) = 0;

              }

            }

          }

          uVar2 = *puVar11;

          *puVar11 = uVar2 & 0xffffffc7;

          *puVar11 = uVar2 & 0xffffffc7 | 0x18;

          *(u16 *)(puVar11 + 0x15) = 2;

        }

      }

      else {

        FUN_003a7940_typed(param_1,-0x40);

      }

    }

    else if ((sVar4 == 3) || (sVar4 != 4)) {

      if ((uVar2 & 0xc00) != 0x400) {

        uVar2 = *puVar11;

        *puVar11 = uVar2 & 0xffffffc7;

        *puVar11 = uVar2 & 0xffffffc7 | 0x18;

        *(u16 *)(puVar11 + 0x15) = 2;

        thunk_FUN_003b0e54(puVar11[7],-0x80);

        thunk_FUN_003b0e54(puVar11[0xc],-0x80);

      }

    }

    else if ((uVar2 & 0xc00) != 0x400) {

      *puVar11 = uVar2 & 0xffffffc7;

      *puVar11 = uVar2 & 0xffffffc7 | 0x18;

      *(u16 *)(puVar11 + 0x15) = 2;

      if (puVar11[7] != 0) {

        thunk_FUN_003b0e54(puVar11[7],-0x80);

        thunk_FUN_003b0e04(puVar11[7],0);

        FUN_003b0bb0(*(u32 *)(puVar11[7] + 0x2c),0);

      }

      if (puVar11[0xc] != 0) {

        thunk_FUN_003b0e54(puVar11[0xc],0xffffffffffffff80);

        FUN_003b0bb0(puVar11[0xc],0);

      }

    }

  
    break;
  case 2:

    if (((uVar2 & 0x38) == 0x20) && (lVar3 = FUN_003a7a40_typed(), lVar3 == 1)) {

      if (puVar11[0x13] != 0) {

        FUN_003affd0(puVar11[0x13]);

        puVar11[0x13] = 0;

      }

      iVar5 = *(int *)(puVar11[0x12] * 8 + puVar11[1] + 0x24);

      sVar4 = *(short *)((int)puVar11 + 0x56);

      sVar1 = *(short *)(iVar5 + 0x1a);

      puVar10 = (u32 *)(iVar5 + 0x20);

      for (lVar3 = 0; lVar3 < sVar1; lVar3++) {

        if (lVar3 == sVar4) {

          FUN_003b0e70(0x80);

          FUN_003b2bf0(*puVar10,0,0xf541);

          FUN_003b0e90(0x80);

        }

        puVar10 = puVar10 + 1;

      }

      if ((uVar2 & 0xc00) == 0x800) {

        uVar2 = *puVar11;

        *puVar11 = uVar2 & 0xfffff3ff;

        *puVar11 = uVar2 & 0xfffff3ff | 0xc00;

      }

      *(u16 *)((int)puVar11 + 0x66) = 0;

      *(u16 *)((int)puVar11 + 0x1d6) = 1;

      *(u16 *)(puVar11 + 0x76) = 0x7f;

      *(u16 *)((int)puVar11 + 0x1da) = 0;

      uVar2 = *puVar11;

      *puVar11 = uVar2 & 0xffffffc7;

      *puVar11 = uVar2 & 0xffffffc7 | 0x28;

      *(u16 *)(puVar11 + 0x19) = 0x80;

      *(u16 *)(puVar11 + 0x15) = 3;

    }

  
    break;
  case 3:

    sVar4 = (puVar11[0x19] & 0xffff) + -0x10;

    *(short *)(puVar11 + 0x19) = sVar4;

    if (sVar4 < 1) {

      *(u16 *)(puVar11 + 0x19) = 0;

      *(u16 *)(puVar11 + 0x15) = 4;

      *(u8 *)(puVar11 + 0x75) = 0;

      *(u16 *)((int)puVar11 + 0x1d6) = 0;

      *(u16 *)(puVar11 + 0x76) = 0;

      *(u16 *)((int)puVar11 + 0x1da) = 0;

      puVar11[0x77] = 0;

      *(u16 *)(puVar11 + 0x78) = 0x238;

      *(u16 *)((int)puVar11 + 0x1e2) = 0x18b;

    }

  
    break;
  case 4:

    if ((puVar11[0xc] == 0) || (0xb17 < (int)puVar11[10])) {

      *(u16 *)(puVar11 + 0x15) = 0xffff;

    }

    else {

      FUN_003a7940_typed(param_1,0x40);

    }

  
    break;
  }

  return;

}
#define FUN_003a7490(...) ((void (*)(...))FUN_003a7490)(__VA_ARGS__)
#undef FUN_003a7940
// FUN_003A7940


void FUN_003a7940(int param_1,int param_2)
{
  int *secondary;
  int *work;
  int node;

  secondary = (int *)(param_1 + 0x14);
  work = (int *)(param_1 + 0xa8);
  *(int *)(param_1 + 0x28) += param_2;
  for (node = *(int *)(param_1 + 0x30); node != 0; node = *(int *)(node + 0x24)) {
    *(int *)(node + 8) += param_2;
  }
  if (work[1] != 0) {
    FUN_003a8ea0(work[1],0,param_2,0,0,0);
  }
  if (work[0] != 0) {
    FUN_003a8ea0(work[0],0,param_2,0,param_2,0);
  }
  if (secondary[2] != 0) {
    secondary[1] += param_2;
    for (node = secondary[2]; node != 0; node = *(int *)(node + 0x24)) {
      *(int *)(node + 8) += param_2;
    }
  }
}
#define FUN_003a7940(...) ((void (*)(...))FUN_003a7940)(__VA_ARGS__)
#undef FUN_003a7a40
/* opt_lifetimes on: measured nd 408 -> 407, object 600/624 -> 600/624. */
#pragma opt_lifetimes on
// W409 addressing/raw-literal fixes: NONMATCHING nd 407 -> 373, object 600/624 -> 612/624.
// W417 rejected typed-call census closure: adding 0x003a7d60 at the front and 0x003a7cb0 at the end
// closed 5 -> 7 calls, but baseline nd 373/object 612/window 624 (60.9%) -> closure nd 392/object 600/window 624 (65.3%).
// The 12-byte shrink shows the aliases replaced compiler-inlined bodies with out-of-line calls;
// reverted to old-style calls until the frame or shape is fixed.
// FUN_003A7A40 NONMATCHING


u32 FUN_003a7a40(int param_1)



{

  int sVar1;

  u32 uVar2;

  int iVar3;

  u32 uVar4;

  int lVar5;

  

  lVar5 = 0;

  if (((DAT_007e0952 & 0x1000) == 0) && ((DAT_007e095a & 0x1000) == 0)) {

    if (((DAT_007e0952 & 0x4000) != 0) || ((DAT_007e095a & 0x4000) != 0)) {

      if (*(short *)(param_1 + 0x56) == *(short *)(param_1 + 0x5a) + -1) {

        if ((((*(u16 *)DAT_007e094e_abs) & 0x4000) != 0) || ((DAT_007e0958 & 0x4000) != 0)) {

          lVar5 = 1;

        }

      }

      else {

        lVar5 = 1;

      }

    }

  }

  else if (*(short *)(param_1 + 0x56) == 0) {

    if ((((*(u16 *)DAT_007e094e_abs) & 0x1000) != 0) || ((DAT_007e0958 & 0x1000) != 0)) {

      lVar5 = -1;

    }

  }

  else {

    lVar5 = -1;

  }

  if (lVar5 == 0) {

    if (((*(u16 *)DAT_007e094e_abs) & 0x40) == 0) {

      if ((*(short *)(param_1 + 0x66) < 1) || (sVar1 = FUN_003a7d60(param_1 + 0x40), sVar1 < 0)) {

        uVar2 = 0;

      }

      else {

        FUN_0010a4e0(0,0,0,2);

        if (sVar1 != *(short *)(param_1 + 0x56)) {

          FUN_003a6380(*(u32 *)(param_1 + 0x4c),*(short *)(param_1 + 0x56),

                       *(u16 *)(param_1 + 0x5a),0);

          FUN_003a6380(*(u32 *)(param_1 + 0x4c),sVar1,*(u16 *)(param_1 + 0x5a),6);

          *(short *)(param_1 + 0x56) = sVar1;

          *(short *)(param_1 + 0x58) = sVar1;

        }

        uVar2 = 1;

      }

    }

    else {

      FUN_0010a4e0(0,0,0,1);

      FUN_005225a8(DAT_006a1bc0_abs);

      uVar4 = *(u32 *)(param_1 + 0x50);

      lVar5 = *(short *)(param_1 + 0x56);

      iVar3 = 0;

      while ((iVar3 < 0x20 && (((uVar4 & 1) != 0 || (lVar5 = lVar5 - 1, -1 < lVar5))))

            ) {

        iVar3 = iVar3 + 1;

        uVar4 = uVar4 >> 1;

      }

      *(short *)(param_1 + 0x56) = (short)iVar3;

      uVar2 = 1;

    }

  }

  else {

    FUN_003a7cb0(param_1 + 0x40,lVar5);

    *(u16 *)(param_1 + 0x1d6) = 0;

    *(u16 *)(param_1 + 0x1d8) = 0;

    *(u16 *)(param_1 + 0x1da) = 0;

    *(u32 *)(param_1 + 0x1dc) = 0;

    *(u16 *)(param_1 + 0x1e0) = 0x238;

    *(u16 *)(param_1 + 0x1e2) = 0x18b;

    uVar2 = 0;

  }

  return uVar2;

}
#define FUN_003a7a40(...) ((u32 (*)(...))FUN_003a7a40)(__VA_ARGS__)
#pragma opt_lifetimes reset
#undef FUN_003a7cb0
#undef FUN_003a6380
/* Retail's old-style non-prototype call keeps the loaded current index in $v0:
   FUN_003a6380 does not clobber $v0, so the caller reuses it after the call. */
// FUN_003A7CB0


void FUN_003a7cb0(int param_1,int param_2)
{
  int cur;
  int next;

  cur = *(s16 *)(param_1 + 0x16);
  FUN_003a6380(*(u32 *)(param_1 + 0xc),cur,*(s16 *)(param_1 + 0x1a),0);
  if (param_2 < 0) {
    next = cur - 1;
    if (next < 0) {
      next = *(s16 *)(param_1 + 0x1a) - 1;
    }
  } else {
    next = cur + 1;
    if (next < *(s16 *)(param_1 + 0x1a)) {
    } else {
      next = 0;
    }
  }
  {
    int max = *(s16 *)(param_1 + 0x1a);
    FUN_003a6380(*(u32 *)(param_1 + 0xc),next,max,6);
  }
  *(s16 *)(param_1 + 0x16) = next;
  *(s16 *)(param_1 + 0x18) = next;
  FUN_0010a4e0(0,0,0,0);
}
#define FUN_003a7cb0(...) ((void (*)(...))FUN_003a7cb0)(__VA_ARGS__)
#undef FUN_003a7d60
#pragma push
/* Removing this loses FUN_003a7d60 (MATCH nd0 -> MISMATCH nd21) - measured W161. */
#pragma opt_loop_invariants on
// FUN_003A7D60 MATCHING


s16 FUN_003a7d60(int param_1)



{

  int index;

  u32 flags;

  s32 count;

  u8 *entry;

  

  index = 0;
  flags = *(u16 *)DAT_007e094e_abs;
  count = *(s16 *)(param_1 + 0x26);

  while (index < count) {

    entry = (u8 *)param_1 + index * 4 + 0x28;

    if ((flags & (1 << *(s16 *)entry)) != 0) {
      return *(s16 *)(entry + 2);

    }

    index = index + 1;

  }

  return -1;

}
#pragma pop

#define FUN_003a7d60(...) ((u16 (*)(...))FUN_003a7d60)(__VA_ARGS__)
#undef FUN_003a7dd0
// FUN_003A7DD0 NONMATCHING


void FUN_003a7dd0(int object)
{
  typedef struct ItfMesAnim {
    u8 active;
    u8 pad;
    s16 state;
    s16 index;
    s16 value;
  } ItfMesAnim;
  s16 values[8];
  ItfMesAnim *anim;
  int count;
  s16 *source;
  s16 *dest;

  anim = (ItfMesAnim *)(object + 0x1d4);
  source = DAT_006a1bd0_signed;
  dest = values;
  count = 3;
  do {
    s16 first = source[0];
    s16 second = source[1];
    source += 2;
    count--;
    dest[0] = first;
    dest[1] = second;
    dest += 2;
  } while (count > 0);

  if (anim->active != 0) {
    switch (anim->state) {
    case 0:
      anim->index++;
      anim->value = values[anim->index];
      if (anim->index >= 5) {
        anim->state = 1;
        anim->index = 5;
      }
      break;
    case 1:
      break;
    }
  }
}
#define FUN_003a7dd0(...) ((void (*)(...))FUN_003a7dd0)(__VA_ARGS__)
#undef FUN_003a7e90
// FUN_003A7E90 NONMATCHING


void FUN_003a7e90(u32 *param_1)
{
  u32 flags;
  u32 state;

  flags = *param_1;
  *(u16 *)DAT_00959ecc_abs &= 0xfffd;
  FUN_003a8080_direct(param_1);
  if (((((flags & 0x20000) == 0) && (2 < (flags & 7))) &&
       ((flags & 0x10000) == 0)) && (param_1[7] != 0)) {
    FUN_003b1300_typed(param_1[7]);
  }
  if ((((flags & 0x20000) == 0) && (2 < (flags & 7))) &&
      ((0 < FUN_003b1300_typed(param_1[0xc])) && ((*param_1 & 7) != 4))) {
    state = *param_1 & 0xfffffff8;
    *param_1 = state;
    *param_1 = state | 4;
    param_1[0x77] = 0;
  }
  if ((*(u8 *)((u8 *)param_1 + 0x1d4) & 2) != 0) {
    if (*(short *)((u8 *)param_1 + 0x12) == 3) {
      FUN_003a8260_direct(param_1);
    }
    else {
      FUN_003a8170_direct(param_1);
    }
  }
  if ((((flags & 0x40000) == 0) && (0x17 < (flags & 0x38))) &&
      ((0 < FUN_003b1330_typed(param_1[0x13],1)) &&
       ((flags & 0x38) == 0x18))) {
    if (*(short *)((u8 *)param_1 + 0x56) == -1) {
      *(u16 *)((u8 *)param_1 + 0x56) = 0;
      *(u16 *)((u8 *)param_1 + 0x58) = 0;
    }
    FUN_003a6380_direct(param_1[0x13],*(u16 *)((u8 *)param_1 + 0x56),
                        *(u16 *)((u8 *)param_1 + 0x5a),6);
    state = *param_1;
    *param_1 = state & 0xffffffc7;
    *param_1 = state & 0xffffffc7 | 0x20;
    *(u8 *)((u8 *)param_1 + 0x1d4) = 2;
  }
  if ((*(u8 *)((u8 *)param_1 + 0x1d4) & 1) != 0) {
    FUN_003a8350_direct(param_1);
  }
}
#define FUN_003a7e90(...) ((void (*)(...))FUN_003a7e90)(__VA_ARGS__)
#undef FUN_003a8080
// FUN_003A8080


void FUN_003a8080(u32 *param_1)
{
  u32 *work;

  if ((*param_1 & 0x80000) == 0) {
    work = param_1 + 0x2a;
    if ((*param_1 & 0x300) >= 0x100U) {
      switch (*(s16 *)((u8 *)param_1 + 0x12)) {
      case 0:
      case 1:
      case 2:
      case 4:
      case 5:
      default:
        FUN_003a9080(work[1],0);
        break;
      case 3:
        break;
      }
      *(u16 *)DAT_00959ecc_abs |= 2;
      if (work[2] != 0) {
        FUN_003a9080(work[2],0);
      }
    }
    if ((*(u32 *)DAT_00958be8_abs != 0) &&
        (*(u32 **)(*(u32 *)DAT_00958be8_abs + 0xc) == param_1) && (work != 0)) {
      FUN_003a8590_direct((u32 *)work[1]);
    }
  }
}
#define FUN_003a8080(...) ((void (*)(...))FUN_003a8080)(__VA_ARGS__)
#undef FUN_003a8170
// FUN_003A8170 MATCHING


void FUN_003a8170(int param_1)



{

  u8 *puVar2;
  short sVar1;
  int iVar2;
  int product;
  int iVar3;
  

  puVar2 = (u8 *)(param_1 + 0x40);

  sVar1 = *(short *)(param_1 + 0x58);

  if ((sVar1 != -1) && (*(int *)(puVar2 + 0xc) != 0)) {

    if (*(short *)(puVar2 + 0x1a) == 4) {

      iVar3 = 200 * sVar1 + 0x788;

    }

    else {

      iVar3 = (int)(75.0f / (float)(int)*(short *)(puVar2 + 0x1a));

      product = iVar3 * 8;
      iVar3 = (iVar3 >> 1) * 8 + 0x788 + product * (int)sVar1;

    }

    iVar2 = (iVar3 >> 3) + 2;

    FUN_003a8710(0xe1,iVar2,0.0f,0xff,0x12);

    FUN_003a8710(0x231,iVar2,0.0f,0xff,0x13);

  }

  return;

}
#define FUN_003a8170(...) ((void (*)(...))FUN_003a8170)(__VA_ARGS__)
#undef FUN_003a8260
// FUN_003A8260


void FUN_003a8260(int param_1)



{

  u32 *work;

  short sVar1;

  int iVar2;

  int iVar3;

  u32 auStack_8 [2];

  

  work = (u32 *)(param_1 + 0x40);

  sVar1 = *(short *)(param_1 + 0x58);

  if (sVar1 != -1) {

    FUN_005225a8(DAT_006a1be0_abs,DAT_006a1a70_abs);

    for (iVar3 = 0; iVar2 = FUN_003b1a90(work[3]), iVar3 < iVar2;

        iVar3 = iVar3 + 1) {

      iVar2 = FUN_003b1b00(iVar3,work[3]);

      if ((int)work[8] < iVar2) {

        FUN_003b1bc0(auStack_8,iVar3,work[3]);

        work[7] = auStack_8[0];

        work[8] = iVar2;

      }

    }

    FUN_003b1bc0(auStack_8,sVar1,work[3]);

  }

  return;

}
#define FUN_003a8260(...) ((void (*)(...))FUN_003a8260)(__VA_ARGS__)
#undef FUN_003a8350
// FUN_003A8350


void FUN_003a8350(int param_1)
{
  u64 uStack_18;
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar2;
  int iVar3;

  uStack_18 = gp0xffffa7c8;
  fVar2 = (float)(int)*(short *)(param_1 + 0x1e0);
  *(float *)&uStack_18 = fVar2;
  fVar3 = (float)(int)*(short *)(param_1 + 0x1e2);
  *((float *)&uStack_18 + 1) = fVar3;
  iVar2 = (int)fVar2;
  iVar3 = (int)fVar3 + -5 + (int)*(short *)(param_1 + 0x1da);

  fVar1 = (float)(*(short *)(param_1 + 0x1d8) * 0xff) / 5.0f;

  FUN_003a8710_u8(iVar2,iVar3,0.0f,(u8)fVar1,0x10);
}
#define FUN_003a8350(...) ((void (*)(...))FUN_003a8350)(__VA_ARGS__)
#undef FUN_003a8440
// FUN_003A8440
u64 FUN_003a8440(void)
{
  int current;
  u32 handle;

  current = *(int *)DAT_00959ed0_abs;
  while (current != 0) {
    handle = *(u32 *)(current + 0xc);
    FUN_003a6e30_direct(handle);
    FUN_003a7120_direct(handle);
    FUN_003a7490_direct(handle);
    FUN_003a7dd0_direct(handle);
    current = *(int *)(current + 4);
  }
  return 0;
}

#define FUN_003a8440(...) ((u64 (*)(...))FUN_003a8440)(__VA_ARGS__)
#undef FUN_003a84c0
// FUN_003A84C0


u64 FUN_003a84c0(void)
{
    int current;
    u32 count;

    current = *(int*)DAT_00959ed0_abs;
    while (current != 0) {
        FUN_003a7e90_direct(*(u32*)(current + 0xc));
        current = *(int*)(current + 4);
    }
    count = *(u32*)DAT_00959ec8_abs;
    *(u32*)DAT_00959ec8_abs = count + 1;
    return 0;
}

#define FUN_003a84c0(...) ((u64 (*)(...))FUN_003a84c0)(__VA_ARGS__)
#undef FUN_003a8530
// FUN_003A8530


void FUN_003a8530(void)
{
    int current;
    int next;

    current = *(int*)DAT_00959ed0_abs;
    while (current != 0) {
        next = *(int*)(current + 4);
        FUN_003a4dd0_direct(*(u32*)(current + 8));
        current = next;
    }
    *(u32*)DAT_00959ec4_abs = 0;
}

#define FUN_003a8530(...) ((void (*)(...))FUN_003a8530)(__VA_ARGS__)
#undef FUN_003a8590
// FUN_003A8590


void FUN_003a8590(u32* param_1)
{
  u8* puVar2;
  int iVar1;
  u32 auStack_20[8];

  puVar2 = (u8*)auStack_20;
  iVar1 = 0x20;
  if (puVar2 != (u8*)0) {
    do {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
      iVar1 = iVar1 - 1;
    } while (iVar1 != 0);
  }

  auStack_20[0] = param_1[4];
  auStack_20[1] = param_1[5];
  auStack_20[2] = param_1[6];
  auStack_20[3] = param_1[5];
  auStack_20[4] = param_1[6];
  auStack_20[5] = param_1[7];
  auStack_20[6] = param_1[4];
  auStack_20[7] = param_1[7];
  return;
}
#define FUN_003a8590(...) ((void (*)(...))FUN_003a8590)(__VA_ARGS__)
#undef FUN_003a8600
// FUN_003A8600


void FUN_003a8600(int param_1)



{

  FUN_003ab2a0(*(u32 *)(*(int *)(DAT_00959eec_abs + param_1 * 0xd) + 0xac));

  return;

}
#define FUN_003a8600(...) ((void (*)(...))FUN_003a8600)(__VA_ARGS__)
#undef FUN_003a8650
// FUN_003A8650


void FUN_003a8650(int param_1,u64 param_2,u64 param_3,u64 param_4,

                 u64 param_5,u64 param_6)



{

  int iVar1;

  

  iVar1 = *(int *)(DAT_00959eec_abs + param_1 * 0xd);

  if (iVar1 == 0) {

    FUN_0019d3f0("itfMesManager.c",0x1d35);

  }

  FUN_003a8dc0(*(u32 *)(iVar1 + 0xac),param_2,param_3,param_5,param_6,param_4);

  return;

}
#define FUN_003a8650(...) ((void (*)(...))FUN_003a8650)(__VA_ARGS__)
#undef FUN_003a8710
// FUN_003A8710


u64 FUN_003a8710(int param_2,int param_3,float param_1,int param_4,int param_5)
{
  u32 object;
  object = FUN_001158b0(0,DAT_007ce654,param_5);
  *(float *)(object + 0x10) = (float)param_2;
  *(float *)(object + 0x14) = (float)param_3;
  *(float *)(object + 0x2c) = param_1;
  *(u8 *)(object + 0x19) = 0xff - (u8)param_4;
  FUN_001127d0(object,1);
  FUN_00115980(object);
  return 0;

}
#define FUN_003a8710(...) FUN_003a8710_typed(__VA_ARGS__)

u32 FUN_003a8b00(int param_1,int param_2);
typedef struct {
  f32 x;
  f32 y;
  f32 z;
} ItfFloat3;

extern u32 FUN_00171250(s16 id);
extern u32 FUN_00170d60(s16 id);
extern u64 FUN_00171110(s16 id,s16 field);
extern u32 FUN_00171110_u32(s16 id,s16 field);
#pragma alias FUN_00171110_u32 FUN_00171110
#pragma alias FUN_0052e878_f32 FUN_0052e878
extern f32 FUN_0052e878_f32(f32 value);
extern const char DAT_006a1bf8[];
extern u32 DAT_006a1d10;
#pragma alias DAT_006a1d10_abs DAT_006a1d10
extern u32 DAT_006a1d10_abs[];
extern const char DAT_006a1d70[];
extern const char DAT_006a1d50[];
extern const char DAT_006a1d90[];
extern const char DAT_006a1db0[];
extern const char DAT_006a1dd0[];
extern u32 DAT_006a1fdc;
extern u32 DAT_006a1fec;
extern u32 DAT_006a1ffc;
extern u32 DAT_006a200c;
#pragma alias DAT_006a1fdc_abs DAT_006a1fdc
extern u32 DAT_006a1fdc_abs[];
#pragma alias DAT_006a1fec_abs DAT_006a1fec
extern u32 DAT_006a1fec_abs[];
#pragma alias DAT_006a1ffc_abs DAT_006a1ffc
extern u32 DAT_006a1ffc_abs[];
#pragma alias DAT_006a200c_abs DAT_006a200c
extern u32 DAT_006a200c_abs[];
extern s16 DAT_006a2060[];
extern s16 DAT_006a2080[];
extern u32 DAT_006a20a0;
extern u32 DAT_006a20c0;
extern u8 DAT_006a20e0[];
#pragma alias DAT_006a20e0_abs DAT_006a20e0
extern u8 DAT_006a20e0_abs[];
 
extern u8 DAT_006a20f0[];
#pragma alias DAT_006a20f0_abs DAT_006a20f0
extern u8 DAT_006a20f0_abs[];
extern u8 DAT_006a1ee0[];
extern u8 DAT_006a1ef0[];
#pragma alias DAT_006a1ee0_abs DAT_006a1ee0
extern u8 DAT_006a1ee0_abs[];
#pragma alias DAT_006a1ef0_abs DAT_006a1ef0
extern u8 DAT_006a1ef0_abs[];
extern u8 DAT_006a1f00[];
#pragma alias DAT_006a1f00_abs DAT_006a1f00
extern u8 DAT_006a1f00_abs[];
extern u8 DAT_006a1f20[];
#pragma alias DAT_006a1f20_abs DAT_006a1f20
extern u8 DAT_006a1f20_abs[];
extern u8 DAT_006a1f40[];
#pragma alias DAT_006a1f40_abs DAT_006a1f40
extern u8 DAT_006a1f40_abs[];
extern u8 DAT_006a1f60[];
#pragma alias DAT_006a1f60_abs DAT_006a1f60
extern u8 DAT_006a1f60_abs[];
extern u8 DAT_006a1f80[];
#pragma alias DAT_006a1f80_abs DAT_006a1f80
extern u8 DAT_006a1f80_abs[];
extern u8 DAT_006a1fa0[];
#pragma alias DAT_006a1fa0_abs DAT_006a1fa0
extern u8 DAT_006a1fa0_abs[];
extern u8 DAT_006a1fb0[];
#pragma alias DAT_006a1fb0_abs DAT_006a1fb0
extern u8 DAT_006a1fb0_abs[];
extern u8 DAT_006a1fc0[];
#pragma alias DAT_006a1fc0_abs DAT_006a1fc0
extern u8 DAT_006a1fc0_abs[];
extern u32 DAT_006a212c;
#pragma alias DAT_006a212c_abs DAT_006a212c
extern u8 DAT_006a212c_abs[];
extern u32 DAT_007cd520;
extern void FUN_006a1e00(void);
extern void FUN_006a1e60(void);
extern void FUN_006a1ea0(void);
extern void FUN_006a1eb0(void);
extern u32 DAT_006a2640;
extern u32 DAT_006a2644;
extern u32 DAT_006a2648;
extern u32 DAT_006a2650;
extern u32 DAT_006a2654;
extern u32 DAT_006a2658;
#pragma alias DAT_006a2640_vec_abs DAT_006a2640
extern ItfFloat3 DAT_006a2640_vec_abs[];
#pragma alias DAT_006a2650_vec_abs DAT_006a2650
extern ItfFloat3 DAT_006a2650_vec_abs[];
extern s32 DAT_006a2680[];
extern u32 DAT_007cd4e8;
extern s16 DAT_007cd500;
extern u32 DAT_0095ac70;
#pragma alias DAT_0095ac70_abs DAT_0095ac70
extern u32 DAT_0095ac70_abs[];
extern u32 DAT_00960088;
extern code DAT_00960090;
/* Absolute callback addresses keep the render-state setup in one local pointer. */
#pragma alias DAT_00960090_abs DAT_00960090
extern code DAT_00960090_abs[];
#pragma alias DAT_009600a0_abs DAT_009600a0
extern code DAT_009600a0_abs[];
#pragma alias DAT_0096017c_abs DAT_0096017c
extern code DAT_0096017c_abs[];
#pragma alias DAT_00960088_abs DAT_00960088
extern u32 DAT_00960088_abs[];
extern code DAT_009600a0;
extern char gp0xffffa830;
extern u8 LAB_003a9170[];
extern u8 LAB_003a9230[];
extern u8 LAB_003a92d0[];
extern u8 LAB_003a93a0[];
extern u8 LAB_003a9400[];
extern u8 LAB_003a9470[];
extern u8 LAB_003a9510[];
extern u8 LAB_003a9580[];
extern u32 LAB_003aa508;
extern u32 LAB_006a1de8;
extern u8 * PTR_FUN_006a1c10;
#pragma alias PTR_FUN_006a1c10_abs PTR_FUN_006a1c10
extern code PTR_FUN_006a1c10_abs[];
extern u8 * PTR_FUN_006a1c90;
#pragma alias PTR_FUN_006a1c90_abs PTR_FUN_006a1c90
extern u8 PTR_FUN_006a1c90_abs[];
extern u8 * PTR_LAB_006a1c50;
#pragma alias PTR_LAB_006a1c50_abs PTR_LAB_006a1c50
extern code PTR_LAB_006a1c50_abs[];
extern u8 * PTR_s_Sayonara_006a24d0;
#pragma alias PTR_s_Sayonara_006a24d0_abs PTR_s_Sayonara_006a24d0
extern u8 PTR_s_Sayonara_006a24d0_abs[];
extern f32 fGpffff8110;
extern f32 fGpffff839c;
extern f32 fGpffff845c;
extern u32 uGpffffa7f8;
extern u32 gp0xffffa7d0;
extern u32 gp0xffffa7d4;
extern u32 gp0xffffa7d8;
extern u32 gp0xffffa7dc;
extern u32 gp0xffffa7e0;
extern u32 gp0xffffa7e8;
extern u32 gp0xffffa7f0;
extern u32 gp0xffffb934;
extern u32 gp0xffffb938;
extern u32 gp0xffffb93c;
extern u32 gp0xffffb944;
extern f32 uGpffff8070;
extern f32 uGpffff8458;
extern void FUN_003c9000(float param_1,float param_2,float param_3,int param_4,int param_5,int param_6,int param_7,int param_8);
extern u32 uGpffffb964;

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

extern void FUN_003bb060(u16 param_1,u16 param_2);
/* Region 0x390000-0x3CFFFF recovered prototypes */
void FUN_003a87d0(int param_2,int param_3,float param_1,long param_4,u32 param_5,u32 param_6,  long param_7);
#pragma alias FUN_003a87d0_typed FUN_003a87d0
extern void FUN_003a87d0_typed(int param_2,int param_3,float param_1,void* param_4,
                               u32 param_5,u32 param_6,long param_7);
void FUN_003a8dc0(int param_1,int param_2,int param_3,int param_4,  int param_5,int param_6);
void FUN_003a8d60(int param_1);
void FUN_003a8ea0(u8 *param_1,int param_2,int param_3,int param_4,int param_5,int param_6);
void FUN_003a8fb0(int param_1,int param_2,int param_3,int param_4,  int param_5);
void FUN_003a9080(u64 param_1);
void FUN_003a90c0(int param_1,u64 param_2);
u64 FUN_003a9140(int param_1);
int FUN_003a9230(int param_1);
u64 FUN_003a92a0(int param_1);
int FUN_003a92d0(int param_1);
u64 FUN_003a93a0(int param_1);
u64 FUN_003a9400(int param_1);
u64 FUN_003a9470(int param_1);
u64 FUN_003a94e0(int param_1);
u64 FUN_003a9510(int param_1);
u64 FUN_003a9580(int param_1);
int FUN_003a95f0(int param_1);
int FUN_003a9630(int param_1);
int FUN_003a9670(int param_1);
int FUN_003a96b0(int param_1);
void FUN_003a96f0(int *param_1,int param_2,int param_3,int param_4,int param_5);
void FUN_003a9780(int *param_1,int param_2,int param_3,int param_4,int param_5);
void FUN_003a9930(int *param_1,int param_2,int param_3,int param_4,int param_5);
void FUN_003a9af0(int *param_1,u32 param_2,int param_3,int param_4,u32 param_5);
void FUN_003a9b80(int param_1,u64 param_2,int param_3,u64 param_4,int param_5);
void FUN_003a9c30(int param_1,u32 param_2,u32 param_3,u32 param_4,  u32 param_5);
void FUN_003a9c90(int param_1,u32 param_2,u32 param_3,u32 param_4,  u32 param_5);
void FUN_003a9cf0(int param_1,int param_2,int param_3,int param_4,  u32 param_5);
void FUN_003a9e20(int param_1,u64 param_2);
void FUN_003a9ed0(int param_1,u64 param_2);
void FUN_003aa000(int param_1,u64 param_2);
void FUN_003aa130(int param_1,u64 param_2);
void FUN_003aa280(int param_1,u64 param_2);
void FUN_003aa2d0(int param_1,u64 param_2);
void FUN_003aa370(int param_1,u64 param_2);
void FUN_003aa720(int param_1);
void FUN_003aaae0(int param_1);
void FUN_003ab2a0(int param_1,u32 param_2);
void FUN_003ab320(int param_1);
void FUN_003abb10(int param_1);
void FUN_003ac240(int param_1,u64 param_2);
void FUN_003ac350(int param_1,u64 param_2);
void FUN_003ac500(int param_1,u64 param_2);
void FUN_003b4a90(int *param_1,int param_2,int param_3,int param_4,int param_5,int *param_6,int param_7);
void FUN_003ac590(void);
u64 FUN_003ac5a0(int param_1,int param_2);
u64 FUN_003ac600(int param_1,int param_2);
u64 FUN_003ac820(u64 param_1,u64 param_2);
u64 FUN_003ac890(u64 param_1,u64 param_2);
u64 FUN_003ac900(u64 param_1,int param_2);
u64 FUN_003aca50(u64 param_1,u64 param_2);
u32 FUN_003acab0(u64 param_1,u64 param_2);
u32 FUN_003acbc0(u64 param_1,int param_2);
u64 FUN_003acb10(int param_1,int param_2);
u64 FUN_003acda0(u64 param_1,int param_2);
u64 FUN_003ace60(u64 param_1,int param_2);
u32 FUN_003acf80(u32 param_1,int param_2);
u32 FUN_003ad030(u64 param_1,int param_2);
u32 FUN_003ad1b0(u32 param_1,int param_2);
u32 FUN_003ad400(u16 param_1,u16 param_2,u64 param_3,u32 param_4);
#pragma alias FUN_003ad400_typed FUN_003ad400
extern u64 FUN_003ad400_typed(u16 param_1,u16 param_2,u64 param_3,int param_4);
#pragma alias FUN_003ad400_three FUN_003ad400
extern u32 FUN_003ad400_three(u16 param_1,u16 param_2,u64 param_3);
u32 FUN_003ad640(u64 param_1,int param_2);
u32 FUN_003ad740(int param_1,int param_2);
u64 FUN_003ad860(u64 param_1,int param_2);
u64 FUN_003ad930(u64 param_1,int param_2);
u32 FUN_003ada00(u64 param_1,int param_2);
u64 FUN_003adb00(u64 param_1,int param_2);
u32 FUN_003adb80(u64 param_1,int param_2);
u64 FUN_003add00(void);
u64 FUN_003add30(void);
u32 FUN_003add40(u64 param_1,int param_2);
u32 FUN_003ade70(int param_1,int param_2);
u64 FUN_003adf70(u64 param_1,int param_2);
u64 FUN_003ae000(u64 param_1,int param_2);
u32 FUN_003ae160(u64 param_1,int param_2);
u32 FUN_003ae260(u64 param_1,int param_2);
u64 FUN_003ae360(u64 param_1,int param_2);
u64 FUN_003ad360(u32 param_1,int param_2);
u64 FUN_003ad380(u64 param_1,int param_2);
void FUN_003a9d90(int param_1,int param_2,int param_3,int param_4,int param_5);
void FUN_003a9db0(int param_1,int param_2,int param_3,int param_4,int param_5);
void FUN_003a9de0(int param_1);
u64 FUN_003ae140(u64 param_1,int param_2);
u64 FUN_003ae150(u64 param_1,int param_2);
u64 FUN_003aca30(u64 param_1,u64 param_2);
u64 FUN_003aca40(u64 param_1,u64 param_2);
u64 FUN_003ad130(u32 param_1,int param_2);
u64 FUN_003ade60(u64 param_1,int param_2);
void FUN_003a9ac0(int param_1,int param_2,int param_3,int param_4,int param_5);

/* Region call-cast macros */
#define FUN_003a87d0(...) ((void (*)(...))FUN_003a87d0)(__VA_ARGS__)
#define FUN_003a8b00(...) ((u64 (*)(...))FUN_003a8b00)(__VA_ARGS__)
#define FUN_003a8d60(...) ((void (*)(...))FUN_003a8d60)(__VA_ARGS__)
#define FUN_003a8dc0(...) ((void (*)(...))FUN_003a8dc0)(__VA_ARGS__)
#define FUN_003a8ea0(...) ((void (*)(...))FUN_003a8ea0)(__VA_ARGS__)
#define FUN_003a8fb0(...) ((void (*)(...))FUN_003a8fb0)(__VA_ARGS__)
#define FUN_003a9080(...) ((void (*)(...))FUN_003a9080)(__VA_ARGS__)
#define FUN_003a90c0(...) ((void (*)(...))FUN_003a90c0)(__VA_ARGS__)
#define FUN_003a9140(...) ((u64 (*)(...))FUN_003a9140)(__VA_ARGS__)
#define FUN_003a9170(...) ((u64 (*)(...))FUN_003a9170)(__VA_ARGS__)
#define FUN_003a92a0(...) ((u64 (*)(...))FUN_003a92a0)(__VA_ARGS__)
#define FUN_003a92d0(...) ((u64 (*)(...))FUN_003a92d0)(__VA_ARGS__)
#define FUN_003a93a0(...) ((u64 (*)(...))FUN_003a93a0)(__VA_ARGS__)
#define FUN_003a9400(...) ((u64 (*)(...))FUN_003a9400)(__VA_ARGS__)
#define FUN_003a9470(...) ((u64 (*)(...))FUN_003a9470)(__VA_ARGS__)
#define FUN_003a94e0(...) ((u64 (*)(...))FUN_003a94e0)(__VA_ARGS__)
#define FUN_003a9510(...) ((u64 (*)(...))FUN_003a9510)(__VA_ARGS__)
#define FUN_003a9580(...) ((u64 (*)(...))FUN_003a9580)(__VA_ARGS__)
#define FUN_003a95f0(...) ((u64 (*)(...))FUN_003a95f0)(__VA_ARGS__)
#define FUN_003a9630(...) ((u64 (*)(...))FUN_003a9630)(__VA_ARGS__)
#define FUN_003a9670(...) ((u64 (*)(...))FUN_003a9670)(__VA_ARGS__)
#define FUN_003a96b0(...) ((u64 (*)(...))FUN_003a96b0)(__VA_ARGS__)
#define FUN_003a96f0(...) ((void (*)(...))FUN_003a96f0)(__VA_ARGS__)
#define FUN_003a9780(...) ((void (*)(...))FUN_003a9780)(__VA_ARGS__)
#define FUN_003a9930(...) ((void (*)(...))FUN_003a9930)(__VA_ARGS__)
#define FUN_003a9af0(...) ((void (*)(...))FUN_003a9af0)(__VA_ARGS__)
#define FUN_003a9b80(...) ((void (*)(...))FUN_003a9b80)(__VA_ARGS__)
#define FUN_003a9c30(...) ((void (*)(...))FUN_003a9c30)(__VA_ARGS__)
#define FUN_003a9c90(...) ((void (*)(...))FUN_003a9c90)(__VA_ARGS__)
#define FUN_003a9cf0(...) ((void (*)(...))FUN_003a9cf0)(__VA_ARGS__)
#define FUN_003a9e20(...) ((void (*)(...))FUN_003a9e20)(__VA_ARGS__)
#define FUN_003a9ed0(...) ((void (*)(...))FUN_003a9ed0)(__VA_ARGS__)
#define FUN_003aa000(...) ((void (*)(...))FUN_003aa000)(__VA_ARGS__)
#define FUN_003aa130(...) ((void (*)(...))FUN_003aa130)(__VA_ARGS__)
#define FUN_003aa280(...) ((void (*)(...))FUN_003aa280)(__VA_ARGS__)
#define FUN_003aa2d0(...) ((void (*)(...))FUN_003aa2d0)(__VA_ARGS__)
#define FUN_003aa370(...) ((void (*)(...))FUN_003aa370)(__VA_ARGS__)
#define FUN_003aa720(...) ((void (*)(...))FUN_003aa720)(__VA_ARGS__)
#define FUN_003aaae0(...) ((void (*)(...))FUN_003aaae0)(__VA_ARGS__)
#define FUN_003ab2a0(...) ((void (*)(...))FUN_003ab2a0)(__VA_ARGS__)
#define FUN_003ab320(...) ((void (*)(...))FUN_003ab320)(__VA_ARGS__)
#define FUN_003abb10(...) ((void (*)(...))FUN_003abb10)(__VA_ARGS__)
#define FUN_003ac240(...) ((void (*)(...))FUN_003ac240)(__VA_ARGS__)
#define FUN_003ac350(...) ((void (*)(...))FUN_003ac350)(__VA_ARGS__)
#define FUN_003ac500(...) ((void (*)(...))FUN_003ac500)(__VA_ARGS__)
#define FUN_003ac590(...) ((void (*)(...))FUN_003ac590)(__VA_ARGS__)
#define FUN_003ac5a0(...) ((u64 (*)(...))FUN_003ac5a0)(__VA_ARGS__)
#define FUN_003ac600(...) ((u64 (*)(...))FUN_003ac600)(__VA_ARGS__)
#define FUN_003ac820(...) ((u64 (*)(...))FUN_003ac820)(__VA_ARGS__)
#define FUN_003ac890(...) ((u64 (*)(...))FUN_003ac890)(__VA_ARGS__)
#define FUN_003ac900(...) ((u64 (*)(...))FUN_003ac900)(__VA_ARGS__)
#define FUN_003aca50(...) ((u64 (*)(...))FUN_003aca50)(__VA_ARGS__)
#define FUN_003acab0(...) ((u32 (*)(...))FUN_003acab0)(__VA_ARGS__)
#define FUN_003acbc0(...) ((u64 (*)(...))FUN_003acbc0)(__VA_ARGS__)
#define FUN_003acda0(...) ((u64 (*)(...))FUN_003acda0)(__VA_ARGS__)
#define FUN_003ace60(...) ((u64 (*)(...))FUN_003ace60)(__VA_ARGS__)
#define FUN_003acf80(...) ((u64 (*)(...))FUN_003acf80)(__VA_ARGS__)
#define FUN_003ad030(...) ((u64 (*)(...))FUN_003ad030)(__VA_ARGS__)
#define FUN_003ad1b0(...) ((u64 (*)(...))FUN_003ad1b0)(__VA_ARGS__)
#define FUN_003ad400(...) ((u64 (*)(...))FUN_003ad400)(__VA_ARGS__)
#define FUN_003ad640(...) ((u64 (*)(...))FUN_003ad640)(__VA_ARGS__)
#define FUN_003ad740(...) ((u64 (*)(...))FUN_003ad740)(__VA_ARGS__)
#define FUN_003ad860(...) ((u64 (*)(...))FUN_003ad860)(__VA_ARGS__)
#define FUN_003ad930(...) ((u64 (*)(...))FUN_003ad930)(__VA_ARGS__)
#define FUN_003ada00(...) ((u64 (*)(...))FUN_003ada00)(__VA_ARGS__)
#define FUN_003adb00(...) ((u64 (*)(...))FUN_003adb00)(__VA_ARGS__)
#define FUN_003adb80(...) ((u64 (*)(...))FUN_003adb80)(__VA_ARGS__)
#define FUN_003add00(...) ((u64 (*)(...))FUN_003add00)(__VA_ARGS__)
#define FUN_003add30(...) ((u64 (*)(...))FUN_003add30)(__VA_ARGS__)
#define FUN_003add40(...) ((u64 (*)(...))FUN_003add40)(__VA_ARGS__)
#define FUN_003ade70(...) ((u64 (*)(...))FUN_003ade70)(__VA_ARGS__)
#define FUN_003adf70(...) ((u64 (*)(...))FUN_003adf70)(__VA_ARGS__)
#define FUN_003ae000(...) ((u64 (*)(...))FUN_003ae000)(__VA_ARGS__)
#define FUN_003ae160(...) ((u64 (*)(...))FUN_003ae160)(__VA_ARGS__)
#define FUN_003ae260(...) ((u64 (*)(...))FUN_003ae260)(__VA_ARGS__)
#define FUN_003ae360(...) ((u64 (*)(...))FUN_003ae360)(__VA_ARGS__)

#undef FUN_003a87d0

/* opt_loop_invariants on: measured off nd 319, object 832/816 (over window); on nd 50, object 816/816 (retained). */
#pragma opt_loop_invariants on
// FUN_003A87D0 NONMATCHING
void FUN_003a87d0(int param_2,int param_3,float param_1,long param_4,u32 param_5,u32 param_6,
                  long param_7)
{
  u32 uVar1;
  float *pfVar3;
  float *pfVar2;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  u32 uVar4;
  float fVar1;
  float fVar2;
  code *renderState;
  float *source;

  if ((param_4 == 0) || (param_5 == 0)) {
    FUN_0019d3f0(DAT_006a1bf8,0x39);
  }

  if (param_7 == 0) {
    FUN_004d7f60(2,0x44);
    FUN_004d7f60(3,0x717fb);
    renderState = (code *)&DAT_00960090_abs;
    (*renderState)(6,1);
    (*renderState)(8,1);
    (*renderState)(7,2);
    (*renderState)(9,2);
    (*renderState)(0xc,1);
    (*renderState)(0xe,0);
    (*renderState)(1,0);
  }

  uVar5 = param_6 >> 0x18 & 0xff;
  uVar6 = param_6 >> 0x10 & 0xff;
  uVar7 = param_6 >> 8 & 0xff;
  uVar8 = param_6 & 0xff;
  param_1 = *(float *)&DAT_00960088_abs - param_1;

  if ((param_7 != 0) || ((u8)param_6 > 0)) {
    uVar1 = (*DAT_00960178_abs)(param_5 << 6,0x40000);
    source = (float *)param_4;
    uVar4 = 0;
    fVar1 = (float)param_2;
    fVar2 = (float)param_3;
    do {
      pfVar3 = source + uVar4 * 2;
      pfVar2 = (float *)((int)uVar1 + uVar4 * 0x40);
      *pfVar2 = fVar1 + *pfVar3;
      pfVar2[1] = fVar2 + pfVar3[1];
      pfVar2[2] = param_1;
      pfVar2[8] = (float)uVar5;
      pfVar2[9] = (float)uVar6;
      pfVar2[10] = (float)uVar7;
      pfVar2[0xb] = (float)uVar8;
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_5);
    (*DAT_009600a0_abs)(4,uVar1,param_5);
    (*DAT_0096017c_abs)(uVar1);
  }
}
#pragma opt_loop_invariants off
#define FUN_003a87d0(...) ((void (*)(...))FUN_003a87d0)(__VA_ARGS__)
#undef FUN_003a8b00

// FUN_003A8B00
u32 FUN_003a8b00(int param_1,int param_2)



{

  u32 uVar1;

  u32 uVar2;
  u32 uVar3;

  int iVar3;


  

  FUN_005225a8(DAT_006a1d50);

  if ((param_1 < 0) || !(param_1 < 0xf)) {

    FUN_0019d3f0(DAT_006a1bf8, 0x1b5);

  }

  uVar1 = FUN_00191af0(0x50);

  FUN_00521408(uVar1,0,0x50);

  iVar3 = (int)uVar1;

  *(int *)iVar3 = iVar3;

  *(char *)(iVar3 + 0x3c) = (char)param_1;
  if (DAT_006a1d10_abs[param_1] != 0) {


    uVar2 = FUN_00191af0(DAT_006a1d10_abs[param_1]);

    *(int *)(iVar3 + 4) = (int)uVar2;

    *(int *)(iVar3 + 8) = (int)uVar2;
    /* Removing this qualifier loses FUN_003a8b00 (MATCH nd0 -> MISMATCH nd10) - measured W170. */
    FUN_00521408(uVar2,0,*(volatile u32 *)&DAT_006a1d10_abs[param_1]);


  }

  switch (param_1) {
  case 10:
    *(code *)(iVar3 + 0x40) = (code)FUN_003a9140;
    *(u8 **)(iVar3 + 0x44) = (u8 *)&LAB_003a9170;
    *(u8 **)(iVar3 + 0x48) = (u8 *)&FUN_003a9230;
    break;
  case 0xb:
    *(code *)(iVar3 + 0x40) = (code)FUN_003a92a0;
    *(u8 **)(iVar3 + 0x44) = (u8 *)&LAB_003a92d0;
    *(u8 **)(iVar3 + 0x48) = (u8 *)&LAB_003a93a0;
    break;
  case 0xc:
    *(u8 **)(iVar3 + 0x44) = (u8 *)&LAB_003a9400;
    *(u8 **)(iVar3 + 0x48) = (u8 *)&LAB_003a9470;
    *(u32 *)(iVar3 + 0x4c) = 0;
    break;
  case 0xd:
    *(code *)(iVar3 + 0x40) = (code)FUN_003a94e0;
    *(u8 **)(iVar3 + 0x44) = (u8 *)&LAB_003a9510;
    *(u8 **)(iVar3 + 0x48) = (u8 *)&LAB_003a9580;
    break;
  case 0xe:
    *(u32 *)(iVar3 + 0x44) = 0;
    *(u32 *)(iVar3 + 0x48) = 0;
    *(u32 *)(iVar3 + 0x4c) = 0;
    break;
  }

  if (param_2 != 0) {

    switch (param_1) {
    case 6:
      **(u32 **)(iVar3 + 8) = param_2;
      break;
    case 7:
      **(u32 **)(iVar3 + 8) = param_2;
      break;
    case 9:
      **(u32 **)(iVar3 + 8) = param_2;
      break;
    case 8:
      **(u32 **)(iVar3 + 8) = param_2;
      break;
    }
  }

  return uVar1;

}
#define FUN_003a8b00(...) ((u64 (*)(...))FUN_003a8b00)(__VA_ARGS__)
#undef FUN_003a8d60

// FUN_003A8D60


void FUN_003a8d60(int param_1)
{
  u32 *puVar1;

  
  FUN_005225a8(DAT_006a1d70);

  if (param_1 != 0) {

    puVar1 = (u32 *)param_1;

    if (puVar1[2] != 0) {

      FUN_00191a10(puVar1[1]);

    }

    FUN_00191a10(*puVar1);

  }

  return;

}
#define FUN_003a8d60(...) ((void (*)(...))FUN_003a8d60)(__VA_ARGS__)
#undef FUN_003a8dc0

// FUN_003A8DC0


void FUN_003a8dc0(int param_1,int param_2,int param_3,int param_4,

                 int param_5,int param_6)



{

  int iVar1;

  

  if (param_1 == 0) {

    FUN_0019d3f0(DAT_006a1bf8, 0x24e);

  }

  FUN_005225a8(DAT_006a1d90);

  iVar1 = (int)param_1;

  *(int *)(iVar1 + 0x10) = (int)param_2;

  *(int *)(iVar1 + 0x14) = (int)param_3;

  *(int *)(iVar1 + 0x18) = (int)param_4;

  *(int *)(iVar1 + 0x1c) = (int)param_5;

  *(u32 *)(iVar1 + 0xc) = param_6;

  if (PTR_FUN_006a1c10_abs[*(u8 *)(iVar1 + 0x3c)] != (code)0) {

    (PTR_FUN_006a1c10_abs[*(u8 *)(iVar1 + 0x3c)])

              (*(u32 *)(iVar1 + 8),param_2,param_3,param_4,param_5);

  }

  return;

}
#define FUN_003a8dc0(...) ((void (*)(...))FUN_003a8dc0)(__VA_ARGS__)
#undef FUN_003a8ea0

// FUN_003A8EA0


void FUN_003a8ea0(u8 *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)
{
  int iVar1;

  if (param_1 == 0) {
    FUN_0019d3f0(DAT_006a1bf8, 0x270);
  }
  FUN_005225a8(DAT_006a1db0);
  iVar1 = (int)param_1;
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + param_2;
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + param_3;
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + param_4;
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + param_5;
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_6;
  if (PTR_FUN_006a1c10_abs[*(u8 *)(iVar1 + 0x3c)] != (code)0) {
    (PTR_FUN_006a1c10_abs[*(u8 *)(iVar1 + 0x3c)])
              (*(u32 *)(param_1 + 8),*(u32 *)(param_1 + 0x10),
               *(u32 *)(param_1 + 0x14),*(u32 *)(param_1 + 0x18),
               *(u32 *)(param_1 + 0x1c));
  }
  return;
}
#define FUN_003a8ea0(...) ((void (*)(...))FUN_003a8ea0)(__VA_ARGS__)
#undef FUN_003a8fb0

// FUN_003A8FB0


void FUN_003a8fb0(int param_1,int param_2,int param_3,int param_4,

                 int param_5)



{

  int iVar1;

  

  if (param_1 == 0) {

    FUN_0019d3f0(DAT_006a1bf8, 0x294);

  }

  FUN_005225a8(DAT_006a1dd0);

  iVar1 = (int)param_1;

  *(int *)(iVar1 + 0x2c) = (int)param_2;

  *(int *)(iVar1 + 0x30) = (int)param_3;

  *(int *)(iVar1 + 0x34) = (int)param_4;

  *(int *)(iVar1 + 0x38) = (int)param_5;

  if (PTR_LAB_006a1c50_abs[*(u8 *)(iVar1 + 0x3c)] != (code)0) {

    (PTR_LAB_006a1c50_abs[*(u8 *)(iVar1 + 0x3c)])

              (*(u32 *)(iVar1 + 8),param_2,param_3,param_4,param_5);

  }

  return;

}
#define FUN_003a8fb0(...) ((void (*)(...))FUN_003a8fb0)(__VA_ARGS__)
#undef FUN_003a9080

// FUN_003A9080


void FUN_003a9080(u64 param_1)



{

  FUN_003ac590_direct(0);

  FUN_003a90c0_direct(param_1,0);

  return;

}

#define FUN_003a9080(...) ((void (*)(...))FUN_003a9080)(__VA_ARGS__)
#undef FUN_003a90c0

// FUN_003A90C0


void FUN_003a90c0(int param_1,u64 param_2)



{

  if (param_1 == 0) {

    FUN_0019d3f0(DAT_006a1bf8, 0x2d6);

  }

  ((code *)PTR_FUN_006a1c90_abs)[*(u8 *)(param_1 + 0x3c)](param_1,param_2);

  return;

}
#define FUN_003a90c0(...) ((void (*)(...))FUN_003a90c0)(__VA_ARGS__)
#undef FUN_003a9140

// FUN_003A9140
u64 FUN_003a9140(int param_1)
{
  FUN_00521408(*(u32 *)(param_1 + 8),0,0x10);
  return 0;
}
#define FUN_003a9140(...) ((u64 (*)(...))FUN_003a9140)(__VA_ARGS__)
#undef FUN_003a9170

// FUN_003A9170
int FUN_003a9170(int param_1)
{
  int *piVar1;

  piVar1 = *(int **)(param_1 + 8);
  *piVar1 = 1;
  piVar1[2] = piVar1[2] + 1;
  piVar1[1] = 100 - piVar1[2] * 100 / 6;
  if (piVar1[2] > 1) {
    piVar1[3] = piVar1[2] * 255 / 6;
  } else {
    piVar1[3] = 0;
  }
  if (piVar1[2] >= 6) {
    *piVar1 = 2;
    piVar1[2] = 0;
    piVar1[1] = 0;
    piVar1[3] = 0xff;
    return 1;
  }
  return 0;
}

// FUN_003A9230
int FUN_003a9230(int param_1)
{
  int* state;

  state = *(int**)(param_1 + 8);
  state[0] = 3;
  state[2] = state[2] + 1;
  state[3] = 0xff - state[2] * 0xff / 10;
  if (state[2] >= 10) {
    state[0] = 0;
    state[2] = 0;
    state[3] = 0;
    return 1;
  }
  return 0;
}


#define FUN_003a9170(...) ((u64 (*)(...))FUN_003a9170)(__VA_ARGS__)
#undef FUN_003a92a0

// FUN_003A92A0
u64 FUN_003a92a0(int param_1)
{
  FUN_00521408(*(u32 *)(param_1 + 8),0,0x10);
  return 0;
}
#define FUN_003a92a0(...) ((u64 (*)(...))FUN_003a92a0)(__VA_ARGS__)
#undef FUN_003a92d0

// FUN_003A92D0
int FUN_003a92d0(int param_1)
{
  int *piVar1;

  piVar1 = *(int **)(param_1 + 8);
  *piVar1 = 1;
  piVar1[2] = piVar1[2] + 1;
  if (piVar1[2] < 4) {
    piVar1[1] = 100 - piVar1[2] * 100 / 4;
    piVar1[3] = piVar1[2] * 255 / 10;
  } else {
    piVar1[1] = 0;
    piVar1[3] = 0xff;
  }
  if (piVar1[2] >= 10) {
    *piVar1 = 2;
    piVar1[2] = 0;
    piVar1[1] = 0;
    piVar1[3] = 0xff;
    return 1;
  }
  return 0;
}
#define FUN_003a92d0(...) ((u64 (*)(...))FUN_003a92d0)(__VA_ARGS__)
#undef FUN_003a93a0

// FUN_003A93A0
u64 FUN_003a93a0(int param_1)
{
  int *piVar1;
  int iVar2;

  piVar1 = *(int **)(param_1 + 8);
  *piVar1 = 3;
  iVar2 = piVar1[2] + 1;
  piVar1[2] = iVar2;
  piVar1[3] = (1 - iVar2) * 255;
  if (piVar1[2] > 0) {
    *piVar1 = 0;
    piVar1[2] = 0;
    piVar1[3] = 0;
    return 1;
  }
  return 0;
}
#define FUN_003a93a0(...) ((u64 (*)(...))FUN_003a93a0)(__VA_ARGS__)
#undef FUN_003a9400

// FUN_003A9400
u64 FUN_003a9400(int param_1)
{
  int *piVar1;
  int iVar2;

  piVar1 = *(int **)(param_1 + 8);
  *piVar1 = 1;
  iVar2 = piVar1[2] + 1;
  piVar1[2] = iVar2;
  piVar1[3] = iVar2 * 255 / 15;
  if (piVar1[2] >= 15) {
    *piVar1 = 2;
    piVar1[2] = 0;
    piVar1[3] = 0xff;
    return 1;
  }
  return 0;
}
#define FUN_003a9400(...) ((u64 (*)(...))FUN_003a9400)(__VA_ARGS__)
#undef FUN_003a9470

// FUN_003A9470
u64 FUN_003a9470(int param_1)
{
  int *piVar1;
  int iVar2;

  piVar1 = *(int **)(param_1 + 8);
  *piVar1 = 3;
  iVar2 = piVar1[2] + 1;
  piVar1[2] = iVar2;
  piVar1[3] = 0xff - iVar2 * 255 / 5;
  if (piVar1[2] >= 5) {
    *piVar1 = 0;
    piVar1[2] = 0;
    piVar1[3] = 0;
    return 1;
  }
  return 0;
}
#define FUN_003a9470(...) ((u64 (*)(...))FUN_003a9470)(__VA_ARGS__)
#undef FUN_003a94e0

// FUN_003A94E0
u64 FUN_003a94e0(int param_1)
{
  FUN_00521408(*(u32 *)(param_1 + 8),0,0x10);
  return 0;
}
#define FUN_003a94e0(...) ((u64 (*)(...))FUN_003a94e0)(__VA_ARGS__)
#undef FUN_003a9510

// FUN_003A9510
u64 FUN_003a9510(int param_1)
{
  int *piVar1;
  int iVar2;

  piVar1 = *(int **)(param_1 + 8);
  *piVar1 = 1;
  iVar2 = piVar1[2] + 1;
  piVar1[2] = iVar2;
  piVar1[3] = iVar2 * 255 / 6;
  if (piVar1[2] >= 6) {
    *piVar1 = 2;
    piVar1[2] = 0;
    piVar1[3] = 0xff;
    return 1;
  }
  return 0;
}
#define FUN_003a9510(...) ((u64 (*)(...))FUN_003a9510)(__VA_ARGS__)
#undef FUN_003a9580

// FUN_003A9580
u64 FUN_003a9580(int param_1)
{
  int *piVar1;
  int iVar2;

  piVar1 = *(int **)(param_1 + 8);
  *piVar1 = 3;
  iVar2 = piVar1[2] + 1;
  piVar1[2] = iVar2;
  piVar1[3] = 0xff - iVar2 * 255 / 10;
  if (piVar1[2] >= 10) {
    *piVar1 = 0;
    piVar1[2] = 0;
    piVar1[3] = 0;
    return 1;
  }
  return 0;
}
#define FUN_003a9580(...) ((u64 (*)(...))FUN_003a9580)(__VA_ARGS__)
#undef FUN_003a95f0

// FUN_003A95F0


int FUN_003a95f0(int param_1)
{
  int uVar1;

  if (*(code **)(param_1 + 0x40) != (code *)0x0) {
    uVar1 = (*(code *)(param_1 + 0x40))();
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}
#define FUN_003a95f0(...) ((u64 (*)(...))FUN_003a95f0)(__VA_ARGS__)
#undef FUN_003a9630

// FUN_003A9630


int FUN_003a9630(int param_1)
{
  int uVar1;

  if (*(code **)(param_1 + 0x44) != (code *)0x0) {
    uVar1 = (*(code *)(param_1 + 0x44))();
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}
#define FUN_003a9630(...) ((u64 (*)(...))FUN_003a9630)(__VA_ARGS__)
#undef FUN_003a9670

// FUN_003A9670


int FUN_003a9670(int param_1)
{
  int uVar1;

  if (*(code **)(param_1 + 0x48) != (code *)0x0) {
    uVar1 = (*(code *)(param_1 + 0x48))();
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}
#define FUN_003a9670(...) ((u64 (*)(...))FUN_003a9670)(__VA_ARGS__)
#undef FUN_003a96b0

// FUN_003A96B0


int FUN_003a96b0(int param_1)
{
  int uVar1;

  if (*(code **)(param_1 + 0x4c) != (code *)0x0) {
    uVar1 = (*(code *)(param_1 + 0x4c))();
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}
#define FUN_003a96b0(...) ((u64 (*)(...))FUN_003a96b0)(__VA_ARGS__)
#undef FUN_003a96f0

// FUN_003A96F0 MATCHING


void FUN_003a96f0(int *param_1,int param_2,int param_3,int param_4,int param_5)



{

  int iVar1;

  int iVar2;

  int aiStack_10 [4];

  

  aiStack_10[0] = param_2;

  aiStack_10[1] = param_2 + 0x200;

  aiStack_10[2] = param_4 + -0x200;

  aiStack_10[3] = param_4;

  if (param_4 + -0x200 < param_2 + 0x200) {

    aiStack_10[1] = param_2 + (param_4 - param_2 >> 1);

    aiStack_10[2] = aiStack_10[1];

  }

  for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {

    iVar1 = *(int *)(int)(aiStack_10 + iVar2);

    *param_1 = iVar1;

    param_1[1] = param_3;

    param_1[2] = iVar1;

    param_1[3] = param_5;

    param_1 = param_1 + 4;

  }

  return;

}

#define FUN_003a96f0(...) ((void (*)(...))FUN_003a96f0)(__VA_ARGS__)
#undef FUN_003a9780

/* opt_lifetimes on: measured nd 192 -> 171, object 404/432 -> 404/432. */
#pragma opt_lifetimes on
// FUN_003A9780 NONMATCHING


void FUN_003a9780(int *param_1,int param_2,int param_3,int param_4,int param_5)



{

  int iVar1;

  int iVar3;

  int iVar2;

  int aiStack_10 [4];

  int aiStack_20 [4];

  

  aiStack_10[0] = param_2 + -0x100;

  aiStack_10[1] = param_2 + 0x200;

  aiStack_10[2] = param_4 + -0x200;

  aiStack_10[3] = param_4 + 0x100;

  aiStack_20[0] = param_3 + -0x80;

  aiStack_20[1] = param_3 + 0x80;

  aiStack_20[2] = param_5 + -0x80;

  aiStack_20[3] = param_5 + 0x80;

  for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

    iVar1 = aiStack_20[iVar3];

    for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {

      *param_1 = aiStack_10[iVar2];

      param_1[1] = iVar1;

      param_1 = param_1 + 2;

    }

  }

  aiStack_10[0] = param_2 + -0x100;

  aiStack_10[1] = param_2 + 0x400;

  aiStack_10[2] = param_4 + -0x400;

  aiStack_10[3] = param_4 + 0x100;

  for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {

    iVar1 = *(int *)(&LAB_006a1de8 + iVar3 * 4);

    for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {

      *param_1 = aiStack_10[iVar2];

      param_1[1] = param_3 + iVar1;

      param_1 = param_1 + 2;

    }

  }

  for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {

    iVar1 = *(int *)(&LAB_006a1de8 + iVar3 * 4);

    for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {

      *param_1 = aiStack_10[iVar2];

      param_1[1] = param_5 - iVar1;

      param_1 = param_1 + 2;

    }

  }

  return;

}
#define FUN_003a9780(...) ((void (*)(...))FUN_003a9780)(__VA_ARGS__)
#pragma opt_lifetimes reset
#undef FUN_003a9930

/* opt_lifetimes on: measured nd 179 -> 153, object 384/400 -> 384/400. */
#pragma opt_lifetimes on
// FUN_003A9930 NONMATCHING


void FUN_003a9930(int *param_1,int param_2,int param_3,int param_4,int param_5)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int aiStack_10 [4];

  int aiStack_20 [4];

  

  aiStack_10[0] = param_2 + -0x100;

  aiStack_10[1] = param_2 + 0x200;

  aiStack_10[2] = param_4 + -0x200;

  aiStack_10[3] = param_4 + 0x100;

  aiStack_20[0] = param_3 + -0x80;

  aiStack_20[1] = param_3 + 0x80;

  aiStack_20[2] = param_5 + -0x80;

  aiStack_20[3] = param_5 + 0x80;

  for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {

    iVar1 = aiStack_20[iVar2];

    for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

      *param_1 = aiStack_10[iVar3];

      param_1[1] = iVar1;

      param_1 = param_1 + 2;

    }

  }

  aiStack_10[0] = param_2 + -0x100;

  aiStack_10[1] = param_2 + 0x400;

  aiStack_10[2] = param_4 + -0x400;

  aiStack_10[3] = param_4 + 0x100;

  for (iVar2 = 0; iVar2 < 2; iVar2 = iVar2 + 1) {

    for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {

      *param_1 = aiStack_10[iVar1];

      param_1[1] = param_3 + iVar2 * 8;

      param_1 = param_1 + 2;

    }

  }

  for (iVar2 = 0; iVar2 < 2; iVar2 = iVar2 + 1) {

    for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {

      *param_1 = aiStack_10[iVar1];

      param_1[1] = param_5 + iVar2 * -8;

      param_1 = param_1 + 2;

    }

  }

  return;

}
#define FUN_003a9930(...) ((void (*)(...))FUN_003a9930)(__VA_ARGS__)
#pragma opt_lifetimes reset

// Retail 0x003a9ac0-0x003a9ae4
// FUN_003A9AC0
void FUN_003a9ac0(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  *(int *)(param_1 + 0) = param_2;
  *(int *)(param_1 + 4) = param_3;
  *(int *)(param_1 + 8) = param_4;
  *(int *)(param_1 + 0xc) = param_3;
  *(int *)(param_1 + 0x10) = param_4;
  *(int *)(param_1 + 0x14) = param_5;
  *(int *)(param_1 + 0x18) = param_2;
  *(int *)(param_1 + 0x1c) = param_5;
}
#undef FUN_003a9af0

// FUN_003A9AF0


void FUN_003a9af0(int *param_1,u32 param_2,int param_3,int param_4,u32 param_5)



{

  int iVar3;

  int iVar2;

  int iVar1;

  struct {
    int pad[2];
    int values[6];
  } stack;

  

  stack.values[2] = param_2;

  stack.values[3] = param_4 + -0x5a0;

  stack.values[4] = param_4;

  stack.values[0] = param_3;

  stack.values[1] = param_5;

  for (iVar3 = 0; iVar3 < 2; iVar3 = iVar3 + 1) {

    iVar2 = 0;
    iVar1 = stack.values[iVar3];

    for (; iVar2 < 3; iVar2 = iVar2 + 1) {

      *param_1 = stack.values[iVar2 + 2];

      param_1[1] = iVar1;

      param_1 = param_1 + 2;

    }

  }

  return;

}
#define FUN_003a9af0(...) ((void (*)(...))FUN_003a9af0)(__VA_ARGS__)
#undef FUN_003a9b80

// FUN_003A9B80


void FUN_003a9b80(int param_1,u64 param_2,int param_3,u64 param_4,int param_5)
{
  u32 uVar1;
  int iVar2;
  u32 *puVar3;
  u32 value1;
  u32 value2;
  u32 *p;
  u32 auStack_10[4];

  puVar3 = (u32 *)(param_1 + 4);
  auStack_10[0] = 0x1a0;
  auStack_10[1] = 0x480;
  auStack_10[2] = 0x1b70;
  auStack_10[3] = 0x1e50;
  value1 = param_3 + 0x160;
  value2 = param_5 + -0x140;
  for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
    p = auStack_10 + iVar2;
    uVar1 = *(u32 *)((int)p + 0);
    *puVar3 = uVar1;
    puVar3[1] = value1;
    puVar3[2] = uVar1;
    puVar3[3] = value2;
    puVar3 = puVar3 + 4;
  }
  return;
}
#define FUN_003a9b80(...) ((void (*)(...))FUN_003a9b80)(__VA_ARGS__)

// FUN_003A9C00
void FUN_003a9c00(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  *(int *)(param_1 + 0x40) = param_2;
  *(int *)(param_1 + 0x44) = param_3;
  *(int *)(param_1 + 0x48) = param_4;
  *(int *)(param_1 + 0x4c) = 0;
  *(int *)(param_1 + 0x50) = param_2;
  *(int *)(param_1 + 0x54) = param_3;
  *(int *)(param_1 + 0x58) = param_4;
  *(int *)(param_1 + 0x5c) = param_5;
}
#undef FUN_003a9c30

// FUN_003A9C30


void FUN_003a9c30(int param_1,u32 param_2,u32 param_3,u32 param_4,

                 u32 param_5)



{
  u32 *puVar1;

  puVar1 = (u32 *)(param_1 + 0x140);
  puVar1[0] = param_2;
  puVar1[1] = param_3;
  puVar1[2] = param_4;
  puVar1[3] = 1;
  puVar1[4] = param_2;
  puVar1[5] = param_3;
  puVar1[6] = param_4;
  puVar1[7] = param_5;
  FUN_003b4a90((int *)(puVar1 + 8),param_2,param_3,param_4,param_5,(int *)FUN_006a1e00,6);
  return;
}

#define FUN_003a9c30(...) ((void (*)(...))FUN_003a9c30)(__VA_ARGS__)
#undef FUN_003a9c90

// FUN_003A9C90


void FUN_003a9c90(int param_1,u32 param_2,u32 param_3,u32 param_4,

                 u32 param_5)



{
  u32 *puVar1;

  puVar1 = (u32 *)(param_1 + 0x100);
  puVar1[0] = param_2;
  puVar1[1] = param_3;
  puVar1[2] = param_4;
  puVar1[3] = 1;
  puVar1[4] = param_2;
  puVar1[5] = param_3;
  puVar1[6] = param_4;
  puVar1[7] = param_5;
  FUN_003b4a90((int *)(puVar1 + 8),param_2,param_3,param_4,param_5,(int *)FUN_006a1e60,4);
  return;
}

#define FUN_003a9c90(...) ((void (*)(...))FUN_003a9c90)(__VA_ARGS__)
#undef FUN_003a9cf0

// FUN_003A9CF0


void FUN_003a9cf0(int param_1,int param_2,int param_3,int param_4,
                 u32 param_5)
{
  u32 *puVar1;

  puVar1 = (u32 *)(param_1 + 0x20);
  puVar1[0] = param_2;
  puVar1[1] = param_3;
  puVar1[2] = param_4;
  puVar1[3] = param_5;
  FUN_003b4a90((int *)(puVar1 + 4),param_2,param_3,param_4,param_5,(int *)FUN_006a1ea0,1);
  FUN_003b4a90((int *)(puVar1 + 8),param_2,param_3,param_4,0x80,(int *)FUN_006a1eb0,2);
}
#define FUN_003a9cf0(...) ((void (*)(...))FUN_003a9cf0)(__VA_ARGS__)

// Retail 0x003a9d90-0x003a9da4
// FUN_003A9D90
void FUN_003a9d90(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  *(int *)(param_1 + 0x20) = param_2;
  *(int *)(param_1 + 0x24) = param_3;
  *(int *)(param_1 + 0x28) = param_4;
  *(int *)(param_1 + 0x2c) = param_5;
}

// Retail 0x003a9db0-0x003a9dd4
// FUN_003A9DB0
void FUN_003a9db0(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  *(int *)(param_1 + 0x30) = param_2;
  *(int *)(param_1 + 0x34) = param_3;
  *(int *)(param_1 + 0x38) = param_4;
  *(int *)(param_1 + 0x3c) = 0;
  *(int *)(param_1 + 0x40) = param_2;
  *(int *)(param_1 + 0x44) = param_3;
  *(int *)(param_1 + 0x48) = param_4;
  *(int *)(param_1 + 0x4c) = param_5;
}

// Retail 0x003a9de0-0x003a9e10
// FUN_003A9DE0
void FUN_003a9de0(int param_1)
{
  *(int *)(param_1 + 0x44) = 0x73;
  *(int *)(param_1 + 0x48) = 0x87;
  *(int *)(param_1 + 0x4c) = 0xff;
  *(int *)(param_1 + 0x50) = 0;
  *(int *)(param_1 + 0x54) = 0x73;
  *(int *)(param_1 + 0x58) = 0x87;
  *(int *)(param_1 + 0x5c) = 0xff;
  *(int *)(param_1 + 0x60) = 0;
}
#undef FUN_003a9e20

// FUN_003A9E20


void FUN_003a9e20(int param_1,u64 param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;
  int index;

  

  iVar2 = *(int *)(param_1 + 8);
  iVar3 = iVar2 + 0x40;

  *(u32 *)(iVar2 + 0x5c) = *(u32 *)(param_1 + 0x38);

  for (iVar1 = 0; iVar1 < 3; iVar1 = iVar1 + 1) {

    index = iVar1 << 2;
    FUN_003b4b40(iVar2,iVar3,DAT_006a1ee0_abs + index,DAT_006a1ef0_abs + index,

                 *(u32 *)(param_1 + 0xc),param_2);

  }

  return;

}
#define FUN_003a9e20(...) ((void (*)(...))FUN_003a9e20)(__VA_ARGS__)
#undef FUN_003a9ed0

// W383 residual: saved-register s2/s3/s4 3-cycle (param1/param2/index); declaration permutation was neutral, first-use index hoist worse, ABI/full-prototype probes neutral or worse.
// FUN_003A9ED0


void FUN_003a9ed0(int param_1,u64 param_2)
{
  u32 uVar1;
  u8 *iVar2;
  u8 *iVar3;
  int iVar5;
  u8 *iVar4;
  int index1;
  int index2;
  uVar1 = *(u32 *)(param_1 + 0x38);
  iVar2 = *(u8 **)(param_1 + 8);
  iVar3 = iVar2 + 0x140;
  iVar4 = iVar3 + 0x10;
  for (iVar5 = 1; iVar5 < 8; iVar5 = iVar5 + 1, iVar4 = iVar4 + 0x10) {
    *(u32 *)(iVar4 + 0xc) = uVar1;
  }
  iVar2 = *(u8 **)(param_1 + 8);
  iVar3 = iVar2 + 0x140;
  for (index1 = 0; index1 < 3; index1 = index1 + 1) {
    FUN_003b4eb0(iVar2,iVar3,DAT_006a1f00_abs + index1 * 8,
                 DAT_006a1f20_abs + index1 * 8,8,
                 *(u32 *)(param_1 + 0xc),param_2);
  }
  for (index2 = 0; index2 < 6; index2 = index2 + 1) {
    FUN_003b4ec0(iVar2 + (index2 * 4 + 0x10) * 8,iVar3,&gp0xffffa7d0,
                 DAT_006a1f40_abs + index2 * 4,4,
                 *(u32 *)(param_1 + 0xc),param_2);
  }
  return;
}
#define FUN_003a9ed0(...) ((void (*)(...))FUN_003a9ed0)(__VA_ARGS__)
#undef FUN_003aa000

// W383 residual: saved-register s2/s3/s4 3-cycle (param1/param2/index); declaration permutation was neutral, first-use index hoist worse, ABI/full-prototype probes neutral or worse.
// FUN_003AA000


void FUN_003aa000(int param_1,u64 param_2)
{
  u32 uVar1;
  int iVar2;
  int iVar3;
  int iVar5;
  int iVar4;
  int index1;
  int index2;

  uVar1 = *(u32 *)(param_1 + 0x38);
  iVar2 = *(int *)(param_1 + 8);
  iVar3 = iVar2 + 0x100;
  iVar4 = iVar3 + 0x10;
  for (iVar5 = 1; iVar5 < 6; iVar5 = iVar5 + 1, iVar4 = iVar4 + 0x10) {
    *(u32 *)(iVar4 + 0xc) = uVar1;
  }
  iVar2 = *(int *)(param_1 + 8);
  iVar3 = iVar2 + 0x100;
  for (index1 = 0; index1 < 3; index1 = index1 + 1) {
    FUN_003b4eb0(iVar2,iVar3,DAT_006a1f60_abs + index1 * 8,
                 DAT_006a1f80_abs + index1 * 8,8,
                 *(u32 *)(param_1 + 0xc),param_2);
  }
  for (index2 = 0; index2 < 2; index2 = index2 + 1) {
    FUN_003b4ec0(iVar2 + (index2 * 4 + 0x10) * 8,iVar3,&gp0xffffa7d4,
                 DAT_006a1fa0_abs + index2 * 4,4,
                 *(u32 *)(param_1 + 0xc),param_2);
  }
  return;
}
#define FUN_003aa000(...) ((void (*)(...))FUN_003aa000)(__VA_ARGS__)
#undef FUN_003aa130

/* opt_loop_invariants on: measured nd 235 -> 216, object 328/336 -> 328/336. */
#pragma opt_loop_invariants on
// FUN_003AA130


void FUN_003aa130(int param_1,u64 param_2)
{
  int *piVar1;
  int *piVar2;
  int iVar2;
  int index2;
  int aiStack_60[24];

  piVar1 = *(int **)(param_1 + 8);
  piVar2 = piVar1 + 8;
  for (iVar2 = 0; iVar2 < 3; iVar2 = iVar2 + 1) {
    aiStack_60[iVar2 * 8] = piVar1[0] + iVar2 * 0x10;
    aiStack_60[iVar2 * 8 + 1] = piVar1[1] + iVar2 * 8;
    aiStack_60[iVar2 * 8 + 2] = piVar1[2] - iVar2 * 0x10;
    aiStack_60[iVar2 * 8 + 3] = piVar1[3] + iVar2 * 8;
    aiStack_60[iVar2 * 8 + 4] = piVar1[4] - iVar2 * 0x10;
    aiStack_60[iVar2 * 8 + 5] = piVar1[5] - iVar2 * 8;
    aiStack_60[iVar2 * 8 + 6] = piVar1[6] + iVar2 * 0x10;
    aiStack_60[iVar2 * 8 + 7] = piVar1[7] - iVar2 * 8;
  }
  FUN_003b4b40(piVar1,piVar2,&gp0xffffa7d8,&gp0xffffa7dc,
               *(u32 *)(param_1 + 0xc),param_2);
  for (index2 = 0; index2 < 3; index2 = index2 + 1) {
    FUN_003b4ec0(aiStack_60,piVar2,DAT_006a1fb0_abs + index2 * 5,
                 DAT_006a1fc0_abs + index2 * 5,5,*(u32 *)(param_1 + 0xc),param_2);
  }
  return;
}
#define FUN_003aa130(...) ((void (*)(...))FUN_003aa130)(__VA_ARGS__)
#pragma opt_loop_invariants reset
#undef FUN_003aa280

// FUN_003AA280


void FUN_003aa280(int param_1,u64 param_2)



{

  int *iVar1;
  int *iVar2;

  

  iVar1 = *(int **)(param_1 + 8);
  iVar2 = (int *)((u8 *)iVar1 + 0x20);

  *(u32 *)((u8 *)iVar2 + 0xc) = *(u32 *)(param_1 + 0x38);

  FUN_003b4b40(iVar1,iVar2,&gp0xffffa7e0,&gp0xffffb934,*(u32 *)(param_1 + 0xc),param_2
              );

  return;

}
#define FUN_003aa280(...) ((void (*)(...))FUN_003aa280)(__VA_ARGS__)
#undef FUN_003aa2d0

// FUN_003AA2D0


void FUN_003aa2d0(int param_1,u64 param_2)
{
  int *iVar1;
  int *iVar2;

  iVar1 = *(int **)(param_1 + 8);
  iVar2 = (int *)((u8 *)iVar1 + 0x30);
  *(u32 *)((u8 *)iVar1 + 0x4c) = *(u32 *)(param_1 + 0x38);
  iVar1 = *(int **)(param_1 + 8);
  FUN_003b4ed0(param_2,2,0);
  FUN_003b4eb0(iVar1,iVar2,&gp0xffffa7e8,&gp0xffffa7f0,6,
               *(u32 *)(param_1 + 0xc),param_2);
  FUN_003b4ed0(param_2,0,0);
}
#define FUN_003aa2d0(...) ((void (*)(...))FUN_003aa2d0)(__VA_ARGS__)
#undef FUN_003aa370

/* opt_dead_assignments off: measured nd 381 -> 378, object 920/944 -> 920/944. */
#pragma opt_dead_assignments off
// FUN_003AA370 NONMATCHING


void FUN_003aa370(int param_1,u64 param_2)



{

  u32 *puVar1;

  int iVar2;
  int scaled;

  int rect[4];

  

  puVar1 = *(u32 **)(param_1 + 8);

  iVar2 = *(int *)(param_1 + 0x38) * 0x39;
  scaled = iVar2 >> 7;
  if (iVar2 < 0) {
    scaled = (iVar2 + 0x7f) >> 7;
  }
  DAT_006a1fdc_abs[0] = scaled;

  rect[0] = *(int *)(param_1 + 0x10);
  rect[1] = *(u32 *)(param_1 + 0x14);
  rect[2] = *(u32 *)(param_1 + 0x18);
  rect[3] = *(u32 *)(param_1 + 0x1c);
  FUN_003b4d10(rect,0x6a1fd0,*(u32 *)(param_1 + 0xc),0x490,param_2);

  iVar2 = *(int *)(param_1 + 0x38) * 0x26;
  scaled = iVar2 >> 7;
  if (iVar2 < 0) {
    scaled = (iVar2 + 0x7f) >> 7;
  }
  DAT_006a1fec_abs[0] = scaled;

  rect[0] = *(int *)(param_1 + 0x10) + 0x720;
  rect[1] = *(u32 *)(param_1 + 0x14);
  rect[2] = rect[0] + 0x10c0;
  rect[3] = *(u32 *)(param_1 + 0x1c);
  FUN_003b4d10(rect,0x6a1fe0,*(u32 *)(param_1 + 0xc),0x680,param_2);

  rect[0] = *(int *)(param_1 + 0x10) + -0x140;
  rect[1] = *(int *)(param_1 + 0x14) + 0x48;
  rect[2] = rect[0] + 0xc80;
  rect[3] = *(u32 *)(param_1 + 0x1c);
  FUN_003b4e90(rect,0x6a2040,param_1 + 0x2c,*(u32 *)(param_1 + 0xc),*puVar1,0,param_2);

  if ((0 < *(int *)(param_1 + 0x28)) &&
      (*(int *)(param_1 + 0x24) != *(int *)(param_1 + 0x14))) {
    scaled = 0x80 - ((*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x14)) * 0x80) /
                    *(int *)(param_1 + 0x28);
  } else {
    scaled = *(int *)(param_1 + 0x38);
  }
  DAT_006a200c_abs[0] = scaled;

  rect[0] = *(int *)(param_1 + 0x18) + -0xb40;
  rect[1] = *(u32 *)(param_1 + 0x14);
  rect[2] = rect[0] + 0xc80;
  rect[3] = *(int *)(param_1 + 0x1c) + -0x48;
  FUN_003b4e90(rect,0x6a2050,0x6a2000,*(u32 *)(param_1 + 0xc),*puVar1,0,param_2);

  iVar2 = *(int *)(param_1 + 0x38) * 0x46;
  scaled = iVar2 >> 7;
  if (iVar2 < 0) {
    scaled = (iVar2 + 0x7f) >> 7;
  }
  DAT_006a1ffc_abs[0] = scaled;

  rect[0] = *(int *)(param_1 + 0x10) + -0x140;
  rect[1] = *(int *)(param_1 + 0x14) + -0xb8;
  rect[2] = rect[0] + 0x1b80;
  rect[3] = *(int *)(param_1 + 0x14) + 8;
  FUN_003b4e90(rect,0x6a2040,0x6a1ff0,*(u32 *)(param_1 + 0xc),*puVar1,0,param_2);

  rect[0] = *(int *)(param_1 + 0x10) + 0x8b0;
  rect[3] = *(int *)(param_1 + 0x14);
  rect[1] = rect[3] + -0x10;
  rect[2] = rect[0] + 0x710;
  FUN_003b4e90(rect,0x6a2020,param_1 + 0x2c,*(u32 *)(param_1 + 0xc),*puVar1,0,param_2);
  rect[0] = rect[2];
  rect[2] = rect[2] + 0x1040;
  FUN_003b4e90(rect,0x6a2030,param_1 + 0x2c,*(u32 *)(param_1 + 0xc),*puVar1,0,param_2);

  rect[0] = *(int *)(param_1 + 0x10) + 0x1020;
  rect[3] = *(int *)(param_1 + 0x1c);
  rect[1] = rect[3] + -0x10;
  rect[2] = rect[0] + 0x710;
  FUN_003b4e90(rect,0x6a2010,param_1 + 0x2c,*(u32 *)(param_1 + 0xc),*puVar1,0,param_2);
  rect[2] = rect[0];
  rect[0] = rect[0] + -0x1220;
  FUN_003b4e90(rect,0x6a2030,param_1 + 0x2c,*(u32 *)(param_1 + 0xc),*puVar1,0,param_2);

  return;

}
#define FUN_003aa370(...) ((void (*)(...))FUN_003aa370)(__VA_ARGS__)
#pragma opt_dead_assignments reset
#undef FUN_003aa720

// W383 residual: a0/a3 pointer/counter color cycle; declaration-init was neutral, counter-before-pointer was worse, and full sprite ABI aliases were neutral.
// W422 probes: split copy/y nd15/960, declaration permutations nd6/960, nd15/960, nd15/960, and assignment-first nd22/960; baseline retained.
// FUN_003AA720 NONMATCHING


void FUN_003aa720(int param_1)



{

  int iVar6;
  short *psVar8;
  short *psVar7;
  int iVar4;
  short sVar1;
  short sVar2;
  u32 uVar3;
  u32 uVar5;
  u32 cVar9;
  u8 mask;
  short asStack_20 [16];

  

  iVar4 = *(int *)(param_1 + 8);
  psVar8 = DAT_006a2060;
  psVar7 = asStack_20;
  iVar6 = 8;


  do {

    sVar1 = *psVar8;

    sVar2 = psVar8[1];

    psVar8 = psVar8 + 2;

    iVar6 = iVar6 + -1;

    *psVar7 = sVar1;

    psVar7[1] = sVar2;

    psVar7 = psVar7 + 2;

  } while (0 < iVar6);

  uVar3 = *(u32 *)(iVar4 + 0xc);
  iVar6 = *(int *)(iVar4 + 4) + -5;

  uVar5 = FUN_001158b0(0,uGpffffb964,0);

  iVar4 = (int)uVar5;

  *(float *)(iVar4 + 0x10) = (float)(int)asStack_20[0];

  *(float *)(iVar4 + 0x14) = (float)(iVar6 + asStack_20[1]);

  *(u32 *)(iVar4 + 0x2c) = 0;

  mask = uVar3 & 0xff;
  cVar9 = 0xff - mask;

  *(char *)(iVar4 + 0x19) = cVar9;

  FUN_001127d0(uVar5,1);

  FUN_00115980(uVar5);

  uVar5 = FUN_001158b0(0,uGpffffb964,1);

  iVar4 = (int)uVar5;

  *(float *)(iVar4 + 0x10) = (float)(int)asStack_20[2];

  *(float *)(iVar4 + 0x14) = (float)(iVar6 + asStack_20[3]);

  *(u32 *)(iVar4 + 0x2c) = 0;

  *(char *)(iVar4 + 0x19) = cVar9;

  FUN_001127d0(uVar5,1);

  FUN_00115980(uVar5);

  uVar5 = FUN_001158b0(0,uGpffffb964,2);

  iVar4 = (int)uVar5;

  *(float *)(iVar4 + 0x10) = (float)(int)asStack_20[4];

  *(float *)(iVar4 + 0x14) = (float)(iVar6 + asStack_20[5]);

  *(u32 *)(iVar4 + 0x2c) = 0;

  *(char *)(iVar4 + 0x19) = cVar9;

  FUN_001127d0(uVar5,1);

  FUN_00115980(uVar5);

  uVar5 = FUN_001158b0(0,uGpffffb964,3);

  iVar4 = (int)uVar5;

  *(float *)(iVar4 + 0x10) = (float)(int)asStack_20[6];
  *(float *)(iVar4 + 0x14) = (float)(iVar6 + asStack_20[7]);

  *(u32 *)(iVar4 + 0x2c) = 0;

  *(char *)(iVar4 + 0x19) = cVar9;

  FUN_001127d0(uVar5,1);

  FUN_00115980(uVar5);

  uVar5 = FUN_001158b0(0,uGpffffb964,4);

  iVar4 = (int)uVar5;

  *(float *)(iVar4 + 0x10) = (float)(int)asStack_20[8];
  *(float *)(iVar4 + 0x14) = (float)(iVar6 + asStack_20[9]);

  *(u32 *)(iVar4 + 0x2c) = 0;

  *(char *)(iVar4 + 0x19) = cVar9;

  FUN_001127d0(uVar5,1);

  FUN_00115980(uVar5);

  uVar5 = FUN_001158b0(0,uGpffffb964,5);

  iVar4 = (int)uVar5;

  *(float *)(iVar4 + 0x10) = (float)(int)asStack_20[10];
  *(float *)(iVar4 + 0x14) = (float)(iVar6 + asStack_20[11]);

  *(u32 *)(iVar4 + 0x2c) = 0;

  *(char *)(iVar4 + 0x19) = cVar9;

  FUN_001127d0(uVar5,1);

  FUN_00115980(uVar5);

  uVar5 = FUN_001158b0(0,uGpffffb964,6);

  iVar4 = (int)uVar5;

  *(float *)(iVar4 + 0x10) = (float)(int)asStack_20[12];
  *(float *)(iVar4 + 0x14) = (float)(iVar6 + asStack_20[13]);

  *(u32 *)(iVar4 + 0x2c) = 0;

  *(char *)(iVar4 + 0x19) = cVar9;

  FUN_001127d0(uVar5,1);

  FUN_00115980(uVar5);

  uVar5 = FUN_001158b0(0,uGpffffb964,7);

  iVar4 = (int)uVar5;

  *(float *)(iVar4 + 0x10) = (float)(int)asStack_20[14];
  *(float *)(iVar4 + 0x14) = (float)(iVar6 + asStack_20[15]);

  *(u32 *)(iVar4 + 0x2c) = 0;

  *(char *)(iVar4 + 0x19) = cVar9;

  FUN_001127d0(uVar5,1);

  FUN_00115980(uVar5);

  return;

}
#define FUN_003aa720(...) ((void (*)(...))FUN_003aa720)(__VA_ARGS__)
#undef FUN_003aaae0

// FUN_003AAAE0 NONMATCHING


void FUN_003aaae0(int param_1)



{

  short sVar1;

  short sVar2;

  int iVar3;

  u32 uVar4;

  int iVar5;

  short *psVar6;

  short *psVar7;

  u32 cVar8;

  float fVar9;

  short asStack_20 [16];

  

  psVar7 = DAT_006a2080;

  psVar6 = asStack_20;

  iVar5 = 8;

  do {

    sVar1 = *psVar7;

    sVar2 = psVar7[1];

    psVar7 = psVar7 + 2;

    iVar5 = iVar5 + -1;

    *psVar6 = sVar1;

    psVar6[1] = sVar2;

    psVar6 = psVar6 + 2;

  } while (0 < iVar5);

  iVar5 = *(int *)(*(int *)(param_1 + 8) + 0xc);

  uVar4 = FUN_001158b0(0,uGpffffb964,0x14);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(asStack_20[0] + 5);

  *(float *)(iVar3 + 0x14) = (float)(asStack_20[1] + 5);

  *(u32 *)(iVar3 + 0x2c) = 0;

  cVar8 = 0xff - ((u32)iVar5 & 0xff);

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0x15);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(asStack_20[2] + 5);

  *(float *)(iVar3 + 0x14) = (float)(asStack_20[3] + 5);

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0x16);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(asStack_20[4] + 5);

  *(float *)(iVar3 + 0x14) = (float)(asStack_20[5] + 5);

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0x17);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(asStack_20[6] + 5);

  *(float *)(iVar3 + 0x14) = (float)(asStack_20[7] + 5);

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0x18);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(asStack_20[8] + 5);

  *(float *)(iVar3 + 0x14) = (float)(asStack_20[9] + 5);

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0x19);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(asStack_20[10] + 5);

  *(float *)(iVar3 + 0x14) = (float)(asStack_20[11] + 5);

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0x1a);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(asStack_20[12] + 5);

  *(float *)(iVar3 + 0x14) = (float)(asStack_20[13] + 5);

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0x1b);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(asStack_20[14] + 5);

  *(float *)(iVar3 + 0x14) = (float)(asStack_20[15] + 5);

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,8);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(int)asStack_20[0];

  *(float *)(iVar3 + 0x14) = (float)(int)asStack_20[1];

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,9);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(int)asStack_20[2];

  *(float *)(iVar3 + 0x14) = (float)(int)asStack_20[3];

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,10);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(int)asStack_20[4];

  *(float *)(iVar3 + 0x14) = (float)(int)asStack_20[5];

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0xb);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(int)asStack_20[6];

  *(float *)(iVar3 + 0x14) = (float)(int)asStack_20[7];

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0xc);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(int)asStack_20[8];

  *(float *)(iVar3 + 0x14) = (float)(int)asStack_20[9];

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0xd);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(int)asStack_20[10];

  *(float *)(iVar3 + 0x14) = (float)(int)asStack_20[11];

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0xe);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(int)asStack_20[12];

  *(float *)(iVar3 + 0x14) = (float)(int)asStack_20[13];

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0xf);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(int)asStack_20[14];

  *(float *)(iVar3 + 0x14) = (float)(int)asStack_20[15];

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0x11);

  fVar9 = (1.0f - (float)iVar5 / 255.0f) * 32.0f;

  iVar5 = (int)uVar4;

  *(float *)(iVar5 + 0x10) = (float)(int)(fVar9 + 549.0f);

  *(float *)(iVar5 + 0x14) = (float)(int)(fVar9 + 379.0f);

  *(u32 *)(iVar5 + 0x2c) = 0;

  *(char *)(iVar5 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  return;

}
#define FUN_003aaae0(...) ((void (*)(...))FUN_003aaae0)(__VA_ARGS__)
#undef FUN_003ab2a0

// FUN_003AB2A0


void FUN_003ab2a0(int param_1,u32 param_2)



{

  if (param_1 == 0) {

    FUN_0019d3f0(DAT_006a1bf8,0x80b);

  }

  if (*(u8 *)((int)param_1 + 0x3c) != '\f') {

    FUN_0019d3f0(DAT_006a1bf8,0x80c);

  }

  *(u32 *)(*(int *)((int)param_1 + 8) + 4) = param_2;

  return;

}
#define FUN_003ab2a0(...) ((void (*)(...))FUN_003ab2a0)(__VA_ARGS__)
#undef FUN_003ab320

// FUN_003AB320 NONMATCHING


void FUN_003ab320(int param_1)
{
  int *piVar1;
  int iVar3;
  int mode;
  int iVar2;
  float fVar4;
  float fVar5;

  piVar1 = *(int **)(param_1 + 8);
  mode = *piVar1;
  switch (mode) {
  case 0:
    break;
  case 1:
    iVar3 = piVar1[3];
    iVar2 = piVar1[2];
    if ((10 < iVar2) && (iVar2 < 0x10)) {
      fVar4 = (fGpffff839c * (float)iVar3 * (float)(iVar2 + -10)) / 5.0f;
      FUN_003c9000(0.0f,5.5f,6.90625f,-75,-57,(u8)fVar4,0,1);
    }
    iVar3 = piVar1[2];
    if (iVar3 < 6) {
      fVar4 = (float)(iVar3 * 0xff) / 5.0f;
      FUN_003c9000(0.0f,((float)iVar3 * 5.5f) / 5.0f,uGpffff8070,-75,0x23,(u8)fVar4,0,0);
    } else if (iVar3 < 0xd) {
      FUN_003c9000(0.0f,5.5f,uGpffff8070,-75,0x23,0xff,0,0);
    } else if (iVar3 < 0x10) {
      fVar4 = (float)((0xf - iVar3) * 0xff) / 3.0f;
      FUN_003c9000(0.0f,5.5f,uGpffff8070,-75,0x23,(u8)fVar4,0,0);
    }
    iVar3 = piVar1[2];
    if (5 < iVar3) {
      if (iVar3 < 0xd) {
        iVar3 = iVar3 + -5;
        fVar4 = (float)(iVar3 * 0xff) / 7.0f;
        FUN_003c9000(0.0f,5.5f,((float)iVar3 * 6.90625f) / 7.0f,-75,
                     (int)(38.0f - (float)(iVar3 * 0x5f) / 7.0f),(u8)fVar4,0,0);
      } else {
        FUN_003c9000(0.0f,uGpffff8458,6.90625f,-75,-57,0xff,0,0);
      }
    }
    iVar3 = piVar1[2];
    if (10 < iVar3) {
      if (iVar3 < 0xf) {
        fVar4 = FUN_0052e878_f32((fGpffff8110 * (float)(0xe - iVar3)) / 4.0f);
        fVar5 = FUN_0052e878_f32((fGpffff8110 * (float)(0xe - piVar1[2])) / 4.0f);
        FUN_003c9000(0.0f,1.328125f,1.328125f,(int)(-31.0f - fVar4 * 64.0f),
                     (int)(fVar5 * 64.0f + -16.0f),0xff,piVar1[1],0);
      } else {
        FUN_003c9000(0.0f,1.328125f,1.328125f,-31,-16,0xff,piVar1[1],0);
      }
    }
    break;
  case 2:
    iVar3 = piVar1[3];
    fVar4 = fGpffff839c * (float)iVar3;
    FUN_003c9000(0.0f,5.5f,6.90625f,-75,-57,(u8)fVar4,0,1);
    FUN_003c9000(0.0f,5.5f,6.90625f,-75,-57,(u8)fVar4,0,0);
    fVar4 = fGpffff845c * (float)iVar3;
    FUN_003c9000(0.0f,5.5f,uGpffff8070,-75,0x23,(u8)fVar4,0,0);
    FUN_003c9000(0.0f,1.328125f,1.328125f,-31,-16,0xff,piVar1[1],0);
    break;
  case 3:
    iVar3 = (int)((float)((5 - piVar1[2]) * 0xff) / 5.0f);
    FUN_003c9000(0.0f,((float)(piVar1[2] / 5) + 1.0f) * 5.5f,6.90625f,-75,-57,iVar3 & 0xff,0,0);
    FUN_003c9000(0.0f,1.328125f,1.328125f,-31,-16,iVar3 & 0xff,piVar1[1],0);
    break;
  }
}

#define FUN_003ab320(...) ((void (*)(...))FUN_003ab320)(__VA_ARGS__)
#undef FUN_003abb10

/* opt_lifetimes on: measured nd 1270 -> 1264, object 1796/1824 -> 1796/1824; opt_dead_assignments off alone: nd 1270 -> 1268, object 1796/1824 -> 1796/1824; stacked: nd 1262, object 1796/1824 (retained). */
#pragma opt_lifetimes on
#pragma opt_dead_assignments off
// W409 addressing: NONMATCHING nd 1262 -> 1239, object 1796/1824 -> 1800/1824.
// FUN_003ABB10 NONMATCHING


void FUN_003abb10(int param_1)



{

  int *piVar1;

  u32 uVar2;

  u32 uVar3;

  int iVar4;

  u32 uVar5;

  int iVar6;

  int iVar7;

  u32 *puVar8;

  u32 *puVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  u32 cVar13;

  int iVar14;

  u32 auStack_40 [8];

  u32 auStack_20 [8];

  

  piVar1 = *(int **)(param_1 + 8);

  puVar9 = &DAT_006a20a0;

  puVar8 = auStack_20;

  iVar7 = 3;

  do {

    uVar2 = *puVar9;

    uVar3 = puVar9[1];

    puVar9 = puVar9 + 2;

    iVar7 = iVar7 + -1;

    *puVar8 = uVar2;

    puVar8[1] = uVar3;

    puVar8 = puVar8 + 2;

  } while (0 < iVar7);

  puVar9 = (u32 *)DAT_006a20c0_abs;

  puVar8 = auStack_40;

  iVar7 = 3;

  do {

    uVar2 = *puVar9;

    uVar3 = puVar9[1];

    puVar9 = puVar9 + 2;

    iVar7 = iVar7 + -1;

    *puVar8 = uVar2;

    puVar8[1] = uVar3;

    puVar8 = puVar8 + 2;

  } while (0 < iVar7);

  iVar12 = *(int *)(param_1 + 0x10) >> 4;

  iVar11 = *(int *)(param_1 + 0x14) >> 3;

  iVar14 = *(int *)(param_1 + 0x18) >> 4;

  iVar6 = *(int *)(param_1 + 0x1c) >> 3;

  iVar10 = iVar6 + 10;

  iVar7 = piVar1[3];

  iVar4 = *piVar1;

  cVar13 = (u32)iVar7 & 0xff;

  if (iVar4 == 3) {

    uVar5 = FUN_001158b0(0,uGpffffb964,0x2a);

    iVar4 = (int)uVar5;

    *(u32 *)(iVar4 + 0x10) = 0;

    *(float *)(iVar4 + 0x14) = (float)(iVar6 + 0x8d);

    *(u32 *)(iVar4 + 0x2c) = 0;

    cVar13 = 0xff - cVar13;

    *(char *)(iVar4 + 0x19) = cVar13;

    FUN_001127d0(uVar5,1);

    FUN_00115980(uVar5);

    FUN_0040d5b0(iVar12,iVar11,iVar14,iVar10,(iVar7 * 0xe5) / 0xff & 0xffU | 0xb8bfc900);

    uVar5 = FUN_001158b0(0,uGpffffb964,0x27);

    iVar4 = (int)uVar5;

    *(u32 *)(iVar4 + 0x10) = 0;

    *(float *)(iVar4 + 0x14) = 125.0f;

    *(u32 *)(iVar4 + 0x2c) = 0;

    *(char *)(iVar4 + 0x19) = cVar13;

    FUN_001127d0(uVar5,1);

    FUN_00115980(uVar5);

    uVar5 = FUN_001158b0(0,uGpffffb964,0x28);

    iVar4 = (int)uVar5;

    *(u32 *)(iVar4 + 0x10) = 0;

    *(float *)(iVar4 + 0x14) = (float)(iVar6 + 0x8b);

    *(u32 *)(iVar4 + 0x2c) = 0;

    *(char *)(iVar4 + 0x19) = cVar13;

    FUN_001127d0(uVar5,1);

    FUN_00115980(uVar5);

    uVar5 = FUN_001158b0(0,uGpffffb964,0x26);

    iVar4 = (int)uVar5;

    *(float *)(iVar4 + 0x10) = 74.0f;

    *(float *)(iVar4 + 0x14) = 129.0f;

    *(u32 *)(iVar4 + 0x2c) = 0;

    *(char *)(iVar4 + 0x19) = cVar13;

    FUN_001127d0(uVar5,1);

    FUN_00115980(uVar5);

    iVar7 = ((0xff - iVar7) * -0xb4) / 0xff;

    FUN_003a87d0_typed(0,iVar7,0.0f,auStack_20,3,0x1b2d38ff,0);

    FUN_003a87d0_typed(0,-iVar7,0.0f,auStack_40,3,0x1b2d38ff,0);

  }

  else if (iVar4 == 2) {

    uVar5 = FUN_001158b0(0,uGpffffb964,0x2a);

    iVar4 = (int)uVar5;

    *(u32 *)(iVar4 + 0x10) = 0;

    *(float *)(iVar4 + 0x14) = (float)(iVar6 + 0x8d);

    *(u32 *)(iVar4 + 0x2c) = 0;

    cVar13 = 0xff - cVar13;

    *(char *)(iVar4 + 0x19) = cVar13;

    FUN_001127d0(uVar5,1);

    FUN_00115980(uVar5);

    FUN_0040d5b0(iVar12,iVar11,iVar14,iVar10,(iVar7 * 0xe5) / 0xff & 0xffU | 0xb8bfc900);

    uVar5 = FUN_001158b0(0,uGpffffb964,0x27);

    iVar7 = (int)uVar5;

    *(u32 *)(iVar7 + 0x10) = 0;

    *(float *)(iVar7 + 0x14) = 125.0f;

    *(u32 *)(iVar7 + 0x2c) = 0;

    *(char *)(iVar7 + 0x19) = cVar13;

    FUN_001127d0(uVar5,1);

    FUN_00115980(uVar5);

    uVar5 = FUN_001158b0(0,uGpffffb964,0x28);

    iVar7 = (int)uVar5;

    *(u32 *)(iVar7 + 0x10) = 0;

    *(float *)(iVar7 + 0x14) = (float)(iVar6 + 0x8b);

    *(u32 *)(iVar7 + 0x2c) = 0;

    *(char *)(iVar7 + 0x19) = cVar13;

    FUN_001127d0(uVar5,1);

    FUN_00115980(uVar5);

    uVar5 = FUN_001158b0(0,uGpffffb964,0x26);

    iVar7 = (int)uVar5;

    *(float *)(iVar7 + 0x10) = 74.0f;

    *(float *)(iVar7 + 0x14) = 129.0f;

    *(u32 *)(iVar7 + 0x2c) = 0;

    *(char *)(iVar7 + 0x19) = cVar13;

    FUN_001127d0(uVar5,1);

    FUN_00115980(uVar5);

    FUN_003a87d0_typed(0,0,0.0f,auStack_20,3,0x1b2d38ff,0);

    FUN_003a87d0_typed(0,0,0.0f,auStack_40,3,0x1b2d38ff,0);

  }

  else if (iVar4 == 1) {

    uVar5 = FUN_001158b0(0,uGpffffb964,0x2a);

    iVar4 = (int)uVar5;

    *(u32 *)(iVar4 + 0x10) = 0;

    *(float *)(iVar4 + 0x14) = (float)(iVar6 + 0x8d);

    *(u32 *)(iVar4 + 0x2c) = 0;

    cVar13 = 0xff - cVar13;

    *(char *)(iVar4 + 0x19) = cVar13;

    FUN_001127d0(uVar5,1);

    FUN_00115980(uVar5);

    FUN_0040d5b0(iVar12,iVar11,iVar14,iVar10,(iVar7 * 0xe5) / 0xff & 0xffU | 0xb8bfc900);

    uVar5 = FUN_001158b0(0,uGpffffb964,0x27);

    iVar4 = (int)uVar5;

    *(u32 *)(iVar4 + 0x10) = 0;

    *(float *)(iVar4 + 0x14) = 125.0f;

    *(u32 *)(iVar4 + 0x2c) = 0;

    *(char *)(iVar4 + 0x19) = cVar13;

    FUN_001127d0(uVar5,1);

    FUN_00115980(uVar5);

    uVar5 = FUN_001158b0(0,uGpffffb964,0x28);

    iVar4 = (int)uVar5;

    *(u32 *)(iVar4 + 0x10) = 0;

    *(float *)(iVar4 + 0x14) = (float)(iVar6 + 0x8b);

    *(u32 *)(iVar4 + 0x2c) = 0;

    *(char *)(iVar4 + 0x19) = cVar13;

    FUN_001127d0(uVar5,1);

    FUN_00115980(uVar5);

    uVar5 = FUN_001158b0(0,uGpffffb964,0x26);

    iVar4 = (int)uVar5;

    *(float *)(iVar4 + 0x10) = (float)(((0xff - iVar7) * -0x8c) / 0xff + 0x4a);

    *(float *)(iVar4 + 0x14) = 129.0f;

    *(u32 *)(iVar4 + 0x2c) = 0;

    *(char *)(iVar4 + 0x19) = cVar13;

    FUN_001127d0(uVar5,1);

    FUN_00115980(uVar5);

    iVar7 = ((0xff - iVar7) * -0x141) / 0xff;

    FUN_003a87d0_typed(iVar7,0,0.0f,auStack_20,3,0x1b2d38ff,0);

    FUN_003a87d0_typed(-iVar7,0,0.0f,auStack_40,3,0x1b2d38ff,0);

  }

  return;

}
#define FUN_003abb10(...) ((void (*)(...))FUN_003abb10)(__VA_ARGS__)
#pragma opt_dead_assignments reset
#pragma opt_lifetimes reset

// FUN_003AC230
void FUN_003ac230(void)
{
}

#undef FUN_003ac240

// W383 residual: s0/s1 upper/lower color swap; declaration permutation was neutral, lower-before-upper first-use was worse, and ABI/full-prototype probes were neutral or worse.
// FUN_003AC240


void FUN_003ac240(int param_1,u64 param_2)
{
  u8 *base;
  u32 *panel;
  int upper;
  u32 lower;
  u32 bounds[4];

  base = (u8 *)(uintptr_t)param_1;
  panel = *(u32 **)(param_1 + 8);
  upper = *(int *)(param_1 + 0x10) + 0x3e0;
  lower = *(int *)(param_1 + 0x18) - 0x3e0;
  bounds[0] = *(u32 *)(param_1 + 0x10);
  bounds[1] = *(u32 *)(param_1 + 0x14);
  bounds[2] = upper;
  bounds[3] = *(u32 *)(param_1 + 0x1c);
  FUN_003b4e90(bounds,DAT_006a20e0_abs,(void *)(base + 0x2c),
               *(u32 *)(param_1 + 0xc),*panel,0,param_2);

  bounds[0] = upper;
  bounds[1] = *(u32 *)(param_1 + 0x14);
  bounds[2] = lower;
  bounds[3] = *(u32 *)(param_1 + 0x1c);
  FUN_003b4ea0(bounds,DAT_006a20f0_abs,(void *)(base + 0x2c),
               *(u32 *)(param_1 + 0xc),0,param_2);

  bounds[0] = *(u32 *)(param_1 + 0x18);
  bounds[1] = *(u32 *)(param_1 + 0x14);
  bounds[2] = lower;
  bounds[3] = *(u32 *)(param_1 + 0x1c);
  FUN_003b4ea0(bounds,DAT_006a20e0_abs,(void *)(base + 0x2c),
               *(u32 *)(param_1 + 0xc),0,param_2);
}
#define FUN_003ac240(...) ((void (*)(...))FUN_003ac240)(__VA_ARGS__)
#undef FUN_003ac350

/* opt_common_subs off: measured nd 316 -> 286, object 428/432 -> 428/432. */
#pragma opt_common_subs off
// FUN_003AC350 NONMATCHING


void FUN_003ac350(int param_1,u64 param_2)



{

  u32 *puVar1;

  int iVar2;

  int iVar3;

  u32 bounds[4];

  

  puVar1 = *(u32 **)(param_1 + 8);

  puVar1[0x18] = (*(int *)(param_1 + 0x38) << 5) >> 7;

  for (iVar2 = 0; iVar2 < 3; iVar2 = iVar2 + 1) {

    FUN_003b4b40(puVar1 + 1,puVar1 + 0x11,iVar2 * 4 + 0x6a2100,iVar2 * 4 + 0x6a2110,

                 *(u32 *)(param_1 + 0xc),param_2);

  }

  bounds[1] = *(int *)(param_1 + 0x14);

  if (*(int *)(param_1 + 0x1c) - (s32)bounds[1] < 0x569) {

    FUN_003b4e90(param_1 + 0x10,0x6a1d00,param_1 + 0x2c,*(u32 *)(param_1 + 0xc),*puVar1,0,

                 param_2);

  }

  else {

    iVar3 = bounds[1] + 0x2b4;

    iVar2 = *(int *)(param_1 + 0x1c) + -0x2b4;

    bounds[0] = *(u32 *)(param_1 + 0x10);

    bounds[2] = *(u32 *)(param_1 + 0x18);

    bounds[3] = iVar3;

    FUN_003b4e90(bounds,0x6a1cd0,param_1 + 0x2c,*(u32 *)(param_1 + 0xc),*puVar1,0,param_2

                );

    bounds[1] = iVar3;

    bounds[3] = iVar2;

    FUN_003b4e90(bounds,0x6a1ce0,param_1 + 0x2c,*(u32 *)(param_1 + 0xc),*puVar1,0,param_2

                );

    bounds[3] = *(u32 *)(param_1 + 0x1c);

    bounds[1] = iVar2;

    FUN_003b4e90(bounds,0x6a1cf0,param_1 + 0x2c,*(u32 *)(param_1 + 0xc),*puVar1,0,param_2

                );

  }

  return;

}
#define FUN_003ac350(...) ((void (*)(...))FUN_003ac350)(__VA_ARGS__)
#pragma opt_common_subs reset
#undef FUN_003ac500

// FUN_003AC500


void FUN_003ac500(int param_1,u64 param_2)



{

  int iVar1;
  int iVar2;
  u32 *p;
  u32 auStack_10[4];

  


  p = (u32 *)param_1;
  iVar1 = p[0xe] * 0x67;

  iVar2 = iVar1 >> 7;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0x7f;
    iVar2 = iVar1 >> 7;
  }

  *(u32 *)DAT_006a212c_abs = iVar2;

  auStack_10[0] = p[4];
  auStack_10[1] = p[5];
  auStack_10[2] = p[6];
  auStack_10[3] = p[7];

  FUN_003b4d10(auStack_10,(u32 *)(DAT_006a212c_abs - 0xc),p[3],0x240,param_2);

  return;

}
#define FUN_003ac500(...) ((void (*)(...))FUN_003ac500)(__VA_ARGS__)
#undef FUN_003ac590

// FUN_003AC590
void FUN_003ac590(void)
{
  return;
}
#define FUN_003ac590(...) ((void (*)(...))FUN_003ac590)(__VA_ARGS__)
#undef FUN_003ac5a0

// FUN_003AC5A0
u64 FUN_003ac5a0(int param_1,int param_2)
{
  u8 *pbVar1;
  u8 bVar2;
  u8 bVar3;
  pbVar1 = (u8 *)(*(int *)((int)param_2 + 0x18));
  pbVar1 = (u8 *)(*(int *)((int)param_2 + 0x10) + (int)pbVar1);
  bVar2 = pbVar1[0] - 1;
  bVar3 = pbVar1[1];
  if (bVar3 == 0xff) {
    bVar3 = 0;
  } else {
    bVar3 = bVar3 - 1;
  }
  *(u8 *)((int)param_2 + 0xd) = bVar3 << 8 | bVar2;
  return 0;
}
#define FUN_003ac5a0(...) ((u64 (*)(...))FUN_003ac5a0)(__VA_ARGS__)
#undef FUN_003ac600

// FUN_003AC600


u64 FUN_003ac600(int param_1,int param_2)



{

  u8 *pbVar3;

  u8 bVar1;

  u32 uVar2;

  u8 uVar4;
  u16 index;

  

  pbVar3 = (u8 *)(*(int *)((int)param_2 + 0x18));
  pbVar3 = (u8 *)(*(int *)((int)param_2 + 0x10) + (int)pbVar3);

  uVar4 = *pbVar3 - 1 & 0xff;

  bVar1 = pbVar3[1];

  if (bVar1 == 0xff) {

    uVar2 = 0;

  }

  else {

    uVar2 = (u32)(u8)(bVar1 - 1);

  }
  index = (u8)uVar2 << 8 | (u8)uVar4;

  if (DAT_0095ac70_abs[index] != 0) {

    FUN_003b22a0(param_2);

    FUN_003b1d90(index & 0xff,param_2);

  }

  return 0;

}

// FUN_003AC6C0
u64 FUN_003ac6c0(u64 param_1,u64 param_2)
{
  uGpffffa7f8 = uGpffffa7f8 | 1;
  return 1;
}

// FUN_003AC6E0
u64 FUN_003ac6e0(u64 param_1,u64 param_2)
{
  return 0;
}

// FUN_003AC6F0
u64 FUN_003ac6f0(int param_1,int param_2)
{
  u8 *pbVar1;
  u8 bVar2;
  u8 bVar3;

  pbVar1 = (u8 *)(*(int *)((int)param_2 + 0x18));
  pbVar1 = (u8 *)(*(int *)((int)param_2 + 0x10) + (int)pbVar1);
  bVar2 = pbVar1[0] - 1;
  bVar3 = pbVar1[1];
  if (bVar3 == 0xff) {
    bVar3 = 0;
  } else {
    bVar3 = bVar3 - 1;
  }
  *(u8 *)((int)param_2 + 0xc) = bVar3 << 8 | bVar2;
  return 0;
}

// FUN_003AC750
u64 FUN_003ac750(int param_1,int param_2)
{
  u8 *pbVar1;
  u8 bVar2;
  u8 bVar3;

  pbVar1 = (u8 *)(*(int *)((int)param_2 + 0x18));
  pbVar1 = (u8 *)(*(int *)((int)param_2 + 0x10) + (int)pbVar1);
  bVar2 = pbVar1[0] - 1;
  bVar3 = pbVar1[1];
  if (bVar3 == 0xff) {
    bVar3 = 0;
  } else {
    bVar3 = bVar3 - 1;
  }
  *(u8 *)((int)param_2 + 0xf) = bVar3 << 8 | bVar2;
  return 0;
}

// FUN_003AC7B0
u64 FUN_003ac7b0(u64 param_1,u64 param_2)
{
  return 0;
}

// FUN_003AC7C0
u64 FUN_003ac7c0(int param_1,int param_2)
{
  u8 *pbVar1;
  u8 bVar2;
  u8 bVar3;

  pbVar1 = (u8 *)(*(int *)((int)param_2 + 0x18));
  pbVar1 = (u8 *)(*(int *)((int)param_2 + 0x10) + (int)pbVar1);
  bVar2 = pbVar1[0] - 1;
  bVar3 = pbVar1[1];
  if (bVar3 == 0xff) {
    bVar3 = 0;
  } else {
    bVar3 = bVar3 - 1;
  }
  *(u8 *)((int)param_2 + 0xe) = bVar3 << 8 | bVar2;
  return 0;
}
#define FUN_003ac600(...) ((u64 (*)(...))FUN_003ac600)(__VA_ARGS__)
#undef FUN_003ac820

// FUN_003AC820


u64 FUN_003ac820(u64 param_1,u64 param_2)



{

  u32 uVar1;

  u8 auStack_8 [8];

  uVar1 = FUN_00177670(1);

  FUN_00523ac8((char *)auStack_8,&DAT_007cd520,uVar1);

  FUN_003b22a0(param_2);

  FUN_003b2020(auStack_8,param_2);

  return 0;

}
#define FUN_003ac820(...) ((u64 (*)(...))FUN_003ac820)(__VA_ARGS__)
#undef FUN_003ac890

// FUN_003AC890


u64 FUN_003ac890(u64 param_1,u64 param_2)



{

  u32 uVar1;

  u8 auStack_8 [8];

  uVar1 = FUN_00177790(1);

  FUN_00523ac8((char *)auStack_8,&DAT_007cd520,uVar1);

  FUN_003b22a0(param_2);

  FUN_003b2020(auStack_8,param_2);

  return 0;

}
#define FUN_003ac890(...) ((u64 (*)(...))FUN_003ac890)(__VA_ARGS__)
#undef FUN_003ac900

// FUN_003AC900


u64 FUN_003ac900(u64 param_1,int param_2)
{
  u32 lVar1;
  u32 uVar2;
  char auStack_20[16];

  lVar1 = FUN_0017d800();
  if (lVar1 == 0) {
    uVar2 = FUN_00177790(1);
    FUN_00523ac8(auStack_20,&gp0xffffa830,uVar2);
    FUN_003b22a0(param_2);
    FUN_003b2020(auStack_20,param_2);
    auStack_20[0] = 0x83;
    auStack_20[1] = 0xf7;
    auStack_20[2] = 0;
    FUN_003b22a0(param_2);
    FUN_003b2020(auStack_20,param_2);
    uVar2 = FUN_00177670(1);
    FUN_00523ac8(auStack_20,&gp0xffffa830,uVar2);
    FUN_003b22a0(param_2);
    FUN_003b2020(auStack_20,param_2);
  } else {
    uVar2 = FUN_00177670(1);
    FUN_00523ac8(auStack_20,&gp0xffffa830,uVar2);
    FUN_003b22a0(param_2);
    FUN_003b2020(auStack_20,param_2);
  }
  return 0;
}
#define FUN_003ac900(...) ((u64 (*)(...))FUN_003ac900)(__VA_ARGS__)

// Retail 0x003aca30-0x003aca38
// FUN_003ACA30
u64 FUN_003aca30(u64 param_1,u64 param_2)
{
  return 0;
}

// Retail 0x003aca40-0x003aca48
// FUN_003ACA40
u64 FUN_003aca40(u64 param_1,u64 param_2)
{
  return 0;
}
#undef FUN_003aca50

// FUN_003ACA50


u64 FUN_003aca50(u64 param_1,u64 param_2)



{

  if ((DAT_007cd500 & 4) == 0) {

    FUN_003b2400(param_2);

  }

  return 0;

}
#define FUN_003aca50(...) ((u64 (*)(...))FUN_003aca50)(__VA_ARGS__)

// FUN_003ACA90
u64 FUN_003aca90(u64 param_1,u64 param_2)
{
  DAT_007cd4e8 = DAT_007cd4e8 | 2;
  return 0;
}
#undef FUN_003acab0

// FUN_003ACAB0


u32 FUN_003acab0(u64 param_1,u64 param_2)
{
  u32 uVar1;

  if ((DAT_007cd500 & 8) != 0) {
    DAT_007cd4e8 = DAT_007cd4e8 | 1;
    uVar1 = 1;
  } else {
    if ((DAT_007cd500 & 0x20) != 0) {
      FUN_003b2400(param_2);
    }
    uVar1 = 0;
  }
  return uVar1;
}

// FUN_003ACB10
u64 FUN_003acb10(int param_1,int param_2)
{
  u8 *pbVar1;
  u8 bVar2;
  u8 bVar3;

  pbVar1 = (u8 *)(*(int *)(param_2 + 0x18));
  pbVar1 = (u8 *)(*(int *)(param_2 + 0x10) + (int)pbVar1);
  bVar2 = pbVar1[0] - 1;
  bVar3 = pbVar1[1];
  if (bVar3 == 0xff) {
    bVar3 = 0;
  } else {
    bVar3 = bVar3 - 1;
  }
  *(u8 *)(param_2 + 0xf) = bVar3 << 8 | bVar2;
  pbVar1 = (u8 *)(*(int *)(param_2 + 0x18));
  pbVar1 = (u8 *)((int)pbVar1 + *(int *)(param_2 + 0x10));
  bVar2 = pbVar1[2] - 1;
  bVar3 = pbVar1[3];
  if (bVar3 == 0xff) {
    bVar3 = 0;
  } else {
    bVar3 = bVar3 - 1;
  }
  *(u16 *)(param_2 + 0x1e) = bVar3 << 8 | bVar2;
  return 0;
}
#define FUN_003acab0(...) ((u32 (*)(...))FUN_003acab0)(__VA_ARGS__)
#undef FUN_003acbc0

// FUN_003ACBC0 NONMATCHING


// W420 recovery: low-byte-first extraction and temporary preservation; verify nd266 -> 242, object 400/480B.
u32 FUN_003acbc0(u64 param_1,int param_2)



{

  u8 bVar1;

  u8 bVar2;

  char cVar2;

  int uVar3;

  int uVar4;

  int uVar5;

  int lVar6;

  u8 *pbVar7;

  int iVar8;

  u8 auStack_40 [64];

  

  pbVar7 = (u8 *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18));

  uVar3 = (u32)(u8)(*pbVar7 - 1);

  bVar1 = pbVar7[1];

  if (bVar1 == 0xff) {

    uVar4 = 0;

  }

  else {

    uVar4 = (u32)(u8)(bVar1 - 1);

  }

  uVar3 = uVar4 << 8 | uVar3;

  iVar8 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);

  bVar2 = *(u8 *)(iVar8 + 2);

  lVar6 = (u32)(u8)(bVar2 - 1);

  cVar2 = *(char *)(iVar8 + 3);

  if (cVar2 == -1) {

    uVar4 = 0;

  }

  else {

    uVar4 = (u32)(u8)(cVar2 - 1);

  }

  uVar4 = uVar4 << 8 | lVar6;

  iVar8 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);

  bVar2 = *(u8 *)(iVar8 + 4);

  lVar6 = (u32)(u8)(bVar2 - 1);

  cVar2 = *(char *)(iVar8 + 5);

  if (cVar2 == -1) {

    uVar5 = 0;

  }

  else {

    uVar5 = (u32)(u8)(cVar2 - 1);

  }

  uVar5 = uVar5 << 8 | lVar6;

  lVar6 = FUN_0016f190(0x184);

  if (lVar6 != 0) {

    if (uVar3 < 0x191) {

      FUN_00523ac8(auStack_40,0x6a25e0,uVar3,uVar4,uVar3,uVar4,uVar5);

    }

    else if ((400 < uVar3) && (uVar3 < 0x1f5)) {

      FUN_00523ac8(auStack_40,0x6a2610,uVar3,uVar4 / 0x14,uVar3,uVar4,uVar5);

    }

    FUN_0010a370(2,auStack_40);

  }

  return 0;

}
#define FUN_003acbc0(...) ((u64 (*)(...))FUN_003acbc0)(__VA_ARGS__)
#undef FUN_003acda0

// FUN_003ACDA0


u64 FUN_003acda0(u64 param_1,int param_2)
{
  u8 bVar2;
  u32 uVar3;
  int lVar4;
  u32 packed;
  u8 *pbVar5;
  u32 low;

  pbVar5 = (u8 *)*(int *)(param_2 + 0x18);
  pbVar5 = (u8 *)(*(int *)(param_2 + 0x10) + (int)pbVar5);
  low = (u32)(u8)(*pbVar5 - 1);
  bVar2 = pbVar5[1];
  if (bVar2 == 0xff) {
    uVar3 = 0;
  }
  else {
    uVar3 = (u32)(u8)(bVar2 - 1);
  }
  packed = (u32)(u8)uVar3 << 8 | (u32)(u8)low;
  lVar4 = FUN_0016f190(0x184);
  if (lVar4 == 0) {
    return 0;
  }
  if ((DAT_007cd500 & 0x100) != 0) {
    return 0;
  }
  FUN_0010a2e0(2,2,packed);
  return 0;
}
#define FUN_003acda0(...) ((u64 (*)(...))FUN_003acda0)(__VA_ARGS__)
#undef FUN_003ace60

// FUN_003ACE60


u64 FUN_003ace60(u64 param_1,int param_2)



{

  u8 low;
  u8 high;
  u8 value;
  u32 packed1;
  u32 packed2;
  int resource;
  u8 *data;

  data = (u8 *)*(int *)(param_2 + 0x18);
  data = (u8 *)(*(int *)(param_2 + 0x10) + (int)data);
  low = data[0] - 1;
  high = data[1];
  if (high == 0xff) {
    value = 0;
  }
  else {
    value = high - 1;
  }
  packed1 = (u32)value << 8 | low & 0xff;

  data = *(u8 **)(param_2 + 0x18) + *(u32 *)(param_2 + 0x10);
  low = data[2] - 1;
  high = data[3];
  if (high == 0xff) {
    value = 0;
  }
  else {
    value = high - 1;
  }
  packed2 = (u32)value << 8 | low & 0xff;

  resource = FUN_0016f190(0x184);
  if (resource == 0) {
    return 0;
  }
  if ((DAT_007cd500 & 0x100) != 0) {
    return 0;
  }
  FUN_0010a2e0(packed1,2,packed2);
  return 0;

}
#define FUN_003ace60(...) ((u64 (*)(...))FUN_003ace60)(__VA_ARGS__)
#undef FUN_003acf80

// FUN_003ACF80


u32 FUN_003acf80(u32 param_1,int param_2)
{
  u8 bVar2;
  u32 uVar3;
  int lVar4;
  u32 packed;
  u8 *pbVar5;
  u32 low;

  pbVar5 = (u8 *)*(int *)(param_2 + 0x18);
  pbVar5 = (u8 *)(*(int *)(param_2 + 0x10) + (int)pbVar5);
  low = (u32)(u8)(*pbVar5 - 1);
  bVar2 = pbVar5[1];
  if (bVar2 == 0xff) {
    uVar3 = 0;
  }
  else {
    uVar3 = (u32)(u8)(bVar2 - 1);
    uVar3 &= 0xff;
  }
  packed = (u32)(u8)uVar3 << 8 | (u32)(u8)low;
  lVar4 = FUN_0016f190(0x184);
  if (lVar4 == 0) {
    return 0;
  }
  FUN_0010a2e0(2,2,packed);
  return 0;
}
#define FUN_003acf80(...) ((u64 (*)(...))FUN_003acf80)(__VA_ARGS__)
#undef FUN_003ad030
static inline u32 itfMesAddOffsetFirst(u32 offset, u32 base)
{
  return offset + base;
}

// W212: transferring FUN_003ACDA0's two-step pointer construction
// regressed nd 104 -> 110 (240/256) and was reverted. The first residual
// remains +0x18, where ours retains the pointer in a1 and retail in v1;
// this is the closed commutative-addu operand/allocation floor.
// FUN_003AD030


u32 FUN_003ad030(u64 param_1,int param_2)
{
  u8 low;
  u8 high;
  u8 value;
  u32 packed1;
  u32 packed2;
  u8 *data;

  data = (u8 *)itfMesAddOffsetFirst(*(volatile int *)(param_2 + 0x10),
                                    *(volatile int *)(param_2 + 0x18));
  low = data[0] - 1;
  high = data[1];
  if (high == 0xff) {
    value = 0;
  } else {
    value = (u8)(high - 1);
    value &= 0xff;
  }
  packed1 = value << 8 | low;

  data = (u8 *)(*(volatile int *)(param_2 + 0x18) + *(volatile int *)(param_2 + 0x10));
  low = data[2] - 1;
  high = data[3];
  if (high == 0xff) {
    value = 0;
  } else {
    value = (u8)(high - 1);
    value &= 0xff;
  }
  packed2 = value << 8 | low;

  if (FUN_0016f190(0x184) == 0) {
    return 0;
  }
  FUN_0010a2e0(packed1,2,packed2);
  return 0;
}
#define FUN_003ad030(...) ((u64 (*)(...))FUN_003ad030)(__VA_ARGS__)

// Retail 0x003ad130-0x003ad1ac
// FUN_003AD130
u64 FUN_003ad130(u32 param_1,int param_2)
{
  u8 low;
  u8 high;
  u32 value;
  u8 *data;
  int offset;
  int base;

  if (*(int *)(*(int *)(param_2 + 0x14) + 0x34) != 0) {
    *(u32 *)(*(int *)(param_2 + 0x14) + 0x38) = 1;
  }
  *(u32 *)(*(int *)(param_2 + 0x14) + 0x30) = param_1;
  offset = *(volatile /* Removing this function's qualifier batch loses FUN_003ad130 (MATCH nd0 -> MISMATCH nd3, size 128 -> 128) - measured W170. */ int *)(param_2 + 0x18);
  base = *(volatile /* Removing this function's qualifier batch loses FUN_003ad130 (MATCH nd0 -> MISMATCH nd3, size 128 -> 128) - measured W170. */ int *)(param_2 + 0x10);
  base = base + offset;
  data = (u8 *)base;
  low = data[0] - 1;
  high = data[1];
  if (high == 0xff) {
    high = 0;
  } else {
    high = high - 1;
  }
  value = (u32)high << 8 | low & 0xff;
  *(u32 *)(*(int *)(param_2 + 0x14) + 0x3c) = value;
  return 0;
}
#undef FUN_003ad1b0

// b210 floor: swapping the integer operand order fixed the independent load
// order; only commutative addu orientation remains (ours 21186200; retail 21184300).
// FUN_003AD1B0


u32 FUN_003ad1b0(u32 param_1,int param_2)
{
  u8 low;
  u8 high;
  s16 value;
  u8 *data;
  int offset;
  int base;

  if (*(int *)(*(int *)(param_2 + 0x14) + 0x34) != 0) {
    *(u32 *)(*(int *)(param_2 + 0x14) + 0x38) = 1;
  }
  *(u32 *)(*(int *)(param_2 + 0x14) + 0x30) = param_1;
  if (FUN_0016f190(0x184) == 0) {
    *(u32 *)(*(int *)(param_2 + 0x14) + 0x3c) = 0x23;
  } else {
    offset = *(int *)(param_2 + 0x18);
    base = *(int *)(param_2 + 0x10);
    offset = (int)((u8 *)base + offset);
    data = (u8 *)offset;
    low = data[0] - 1;
    high = data[1];
    if (high == 0xff) {
      high = 0;
    } else {
      high = high - 1;
    }
    value = high << 8 | low & 0xff;
    *(u32 *)(*(int *)(param_2 + 0x14) + 0x3c) = value;
  }
  if (*(int *)(*(int *)(param_2 + 0x14) + 0x3c) < 0) {
    *(u32 *)(*(int *)(param_2 + 0x14) + 0x3c) = 0;
  }
  return 0;
}
#define FUN_003ad1b0(...) ((u64 (*)(...))FUN_003ad1b0)(__VA_ARGS__)

// Retail 0x003ad2a0-0x003ad354
// FUN_003AD2A0
u64 FUN_003ad2a0(u64 param_1,int param_2)
{
  u8 low;
  u8 high;
  u32 value;
  u8 *data;
  int offset;
  int base;

  offset = *(int *)(param_2 + 0x18);
  base = *(int *)(param_2 + 0x10);
  base = base + offset;
  data = (u8 *)base;
  low = data[0] - 1;
  high = data[1];
  if (high == 0xff) {
    high = 0;
  } else {
    high = high - 1;
  }
  value = (u32)high << 8 | low & 0xff;
  gp0xffffb938 = value;

  offset = *(int *)(param_2 + 0x18);
  base = *(int *)(param_2 + 0x10);
  data = (u8 *)(offset + base);
  low = data[2] - 1;
  high = data[3];
  if (high == 0xff) {
    high = 0;
  } else {
    high = high - 1;
  }
  value = (u32)high << 8 | low & 0xff;
  gp0xffffb93c = value;
  uGpffffa7f8 = uGpffffa7f8 | 8;
  return 0;
}

// Retail 0x003ad360-0x003ad370
// FUN_003AD360
u64 FUN_003ad360(u32 param_1,int param_2)
{
  *(u32 *)(*(int *)(param_2 + 0x14) + 0x34) = param_1;
  return 0;
}

// Retail 0x003ad380-0x003ad3f0
// FUN_003AD380
u64 FUN_003ad380(u64 param_1,int param_2)
{
  u8 low;
  u8 high;
  u32 value;
  u8 *data;
  int offset;
  int base;

  offset = *(volatile /* Removing this function's qualifier batch loses FUN_003ad380 (MATCH nd0 -> MISMATCH nd3, size 116 -> 116) - measured W170. */ int *)(param_2 + 0x18);
  base = *(volatile /* Removing this function's qualifier batch loses FUN_003ad380 (MATCH nd0 -> MISMATCH nd3, size 116 -> 116) - measured W170. */ int *)(param_2 + 0x10);
  base = base + offset;
  data = (u8 *)base;
  low = data[0] - 1;
  high = data[1];
  if (high == 0xff) {
    high = 0;
  } else {
    high = high - 1;
  }
  value = (u32)high << 8 | low & 0xff;
  if (value != 0) {
    return 0;
  }
  gp0xffffb944 = 0x14;
  return 0;
}
#undef FUN_003ad400

// FUN_003AD400 NONMATCHING


u32 FUN_003ad400(u16 param_1,u16 param_2,u64 param_3,u32 param_4)



{

  u8 uVar1;

  int iVar2;

  long lVar3;

  u64 uVar4;

  u32 uVar5;
  u32 iVar6;

  int iVar7;

  int cVar8;

  u8 msg[3];

  

  iVar6 = (int)param_4;

  cVar8 = '\0';

  iVar7 = 0;

  uVar1 = *(u8 *)(iVar6 + 0xd);

  *(u8 *)(iVar6 + 0xd) = 3;

  lVar3 = FUN_00171250(param_1);

  switch ((int)lVar3) {
  case 0:
    iVar2 = FUN_00170d60(param_1);
    if ((*(u32 *)(iVar2 + 4) & 0xff00) != 0) {
      iVar7 = 8;
    }
    uVar5 = *(u32 *)(iVar2 + 4) >> iVar7;
    if ((uVar5 & 1) == 0) {
      if ((uVar5 & 2) == 0) {
        if ((uVar5 & 4) == 0) {
          if ((uVar5 & 8) == 0) {
            if ((uVar5 & 0x10) == 0) {
              if ((uVar5 & 0x20) == 0) {
                if ((uVar5 & 0x40) == 0) {
                  if ((uVar5 & 0x80) != 0) {
                    cVar8 = '\a';
                  }
                } else {
                  cVar8 = '\x06';
                }
              } else {
                cVar8 = '\x05';
              }
            } else {
              cVar8 = '\x04';
            }
          } else {
            cVar8 = '\x03';
          }
        } else {
          cVar8 = '\x02';
        }
      } else {
        cVar8 = '\x01';
      }
    } else {
      cVar8 = '\0';
    }
    break;
  case 1:
    cVar8 = '\t';
    break;
  case 2:
    cVar8 = '\n';
    break;
  case 3:
    cVar8 = '\v';
    break;
  case 4:
    cVar8 = '\r';
    break;
  }

  msg[0] = 0x83;
  msg[1] = cVar8 + -0x38;
  msg[2] = 0;
  FUN_003b22a0(param_4);
  FUN_003b2020(msg,param_4);

  FUN_003b22a0(param_4);

  uVar4 = FUN_00171110(param_1,param_2);

  FUN_003b2020(uVar4,param_4);

  *(u8 *)(iVar6 + 0xd) = uVar1;

  return 0;

}
#define FUN_003ad400(...) ((u64 (*)(...))FUN_003ad400)(__VA_ARGS__)
// measured: the fixed message buffer cuts nd157 to nd1; lint: allow S003
#undef FUN_003ad640

// FUN_003AD640


u32 FUN_003ad640(u64 param_1,int param_2)



{

  u8 bVar1;

  u8 uVar2;

  u32 uVar3;

  u8 uVar5;

  int iVar6;

  char msg[8];
  u16 index;

  

  iVar6 = (int)param_2;
  uVar5 = *(u8 *)(*(int *)(iVar6 + 0x10) + *(int *)(iVar6 + 0x18)) - 1 & 0xff;

  bVar1 = ((u8 *)(*(int *)(iVar6 + 0x10) + *(int *)(iVar6 + 0x18)))[1];
  if (bVar1 == 0xff) {

    uVar3 = 0;

  }

  else {

    uVar3 = (u32)(u8)(bVar1 - 1);

  }
  index = (u8)uVar3 << 8 | (u8)uVar5;

  if (DAT_0095ac70_abs[index] != 0) {

    uVar2 = *(u8 *)(iVar6 + 0xd);

    *(u8 *)(iVar6 + 0xd) = 3;

    msg[0] = 0x83;
    msg[1] = 0xd5;
    msg[2] = 0;

    FUN_003b22a0(param_2);

    FUN_003b2020(msg,param_2);

    FUN_003b22a0(param_2);

    FUN_003b1d90(index & 0xff,param_2);

    *(u8 *)(iVar6 + 0xd) = uVar2;

  }

  return 0;

}
#define FUN_003ad640(...) ((u64 (*)(...))FUN_003ad640)(__VA_ARGS__)
#undef FUN_003ad740

// FUN_003AD740 NONMATCHING


u32 FUN_003ad740(int param_1,int param_2)



{

  u8 bVar1;

  char cVar2;

  u32 uVar3;

  u32 uVar4;

  u8 *pbVar5;

  int iVar6;

  u32 uVar7;

  u32 uVar8;

  

  pbVar5 = (u8 *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18));

  bVar1 = pbVar5[1];

  if (bVar1 != 0xff) {

    uVar3 = (u32)(u8)(bVar1 - 1);

  }

  else {

    uVar3 = 0;

  }

  iVar6 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);

  cVar2 = *(char *)(iVar6 + 3);

  if (cVar2 != -1) {

    uVar4 = (u32)(u8)(cVar2 - 1);

  }

  else {

    uVar4 = 0;

  }

  uVar7 = 0;

  uVar8 = 0;

  if (*(u32 **)(&DAT_0095ac70 + (uVar3 << 8 | *pbVar5 - 1 & 0xff) * 4) != (u32 *)0x0)

  {

    uVar8 = **(u32 **)(&DAT_0095ac70 + (uVar3 << 8 | *pbVar5 - 1 & 0xff) * 4);

  }

  if (*(u32 **)(&DAT_0095ac70 + (uVar4 << 8 | *(u8 *)(iVar6 + 2) - 1 & 0xff) * 4) !=

      (u32 *)0x0) {

    uVar7 = **(u32 **)(&DAT_0095ac70 + (uVar4 << 8 | *(u8 *)(iVar6 + 2) - 1 & 0xff) * 4);

  }

  FUN_003ad400_three(uVar7,uVar8,param_1);

  return 0;

}
#define FUN_003ad740(...) ((u64 (*)(...))FUN_003ad740)(__VA_ARGS__)
#undef FUN_003ad860

// FUN_003AD860


u64 FUN_003ad860(u64 param_1,int param_2)



{

  u8 bVar1;

  u8 uVar2;
  u32 uVar3;
  u32 index32;
  u16 index;

  u8 *pbVar4;

  u32 uVar5;

  int iVar6;
  int offset;

  int base;

  

  iVar6 = (int)param_2;

  offset = *(volatile /* Removing this function's qualifier batch loses FUN_003ad860 (MATCH nd0 -> MISMATCH nd3, size 208 -> 208) - measured W170. */ int *)(iVar6 + 0x18);

  base = *(volatile /* Removing this function's qualifier batch loses FUN_003ad860 (MATCH nd0 -> MISMATCH nd3, size 208 -> 208) - measured W170. */ int *)(iVar6 + 0x10);

  pbVar4 = (u8 *)(base + offset);

  uVar5 = *(volatile /* Removing this function's qualifier batch loses FUN_003ad860 (MATCH nd0 -> MISMATCH nd3, size 208 -> 208) - measured W170. */ u8 *)pbVar4;
  uVar5 = uVar5 - 1 & 0xff;
  bVar1 = *(volatile /* Removing this function's qualifier batch loses FUN_003ad860 (MATCH nd0 -> MISMATCH nd3, size 208 -> 208) - measured W170. */ u8 *)(pbVar4 + 1);

  if (bVar1 == 0xff) {

    uVar3 = 0;

  }

  else {

    uVar3 = (u32)(u8)(bVar1 - 1);

  }
  index32 = (u8)uVar3 << 8;
  index32 |= (u8)uVar5;
  index = index32;

  if (DAT_0095ac70_abs[index] != 0) {

    uVar2 = *(u8 *)(iVar6 + 0xd);

    *(u8 *)(iVar6 + 0xd) = 3;

    FUN_003b22a0(param_2);

    FUN_003b1d90(index & 0xff,param_2);

    *(u8 *)(iVar6 + 0xd) = uVar2;

  }

  return 0;

}
#define FUN_003ad860(...) ((u64 (*)(...))FUN_003ad860)(__VA_ARGS__)
#undef FUN_003ad930

// FUN_003AD930


u64 FUN_003ad930(u64 param_1,int param_2)



{

  u8 bVar1;
  u8 uVar2;

  u32 uVar3;
  u32 index32;
  u16 index;

  u8 *pbVar4;

  u32 uVar5;

  int iVar6;
  int offset;

  int base;

  

  iVar6 = (int)param_2;

  offset = *(volatile /* Removing this function's qualifier batch loses FUN_003ad930 (MATCH nd0 -> MISMATCH nd3, size 208 -> 208) - measured W170. */ int *)(iVar6 + 0x18);

  base = *(volatile /* Removing this function's qualifier batch loses FUN_003ad930 (MATCH nd0 -> MISMATCH nd3, size 208 -> 208) - measured W170. */ int *)(iVar6 + 0x10);

  pbVar4 = (u8 *)(base + offset);

  uVar5 = *(volatile /* Removing this function's qualifier batch loses FUN_003ad930 (MATCH nd0 -> MISMATCH nd3, size 208 -> 208) - measured W170. */ u8 *)pbVar4;
  uVar5 = uVar5 - 1 & 0xff;
  bVar1 = *(volatile /* Removing this function's qualifier batch loses FUN_003ad930 (MATCH nd0 -> MISMATCH nd3, size 208 -> 208) - measured W170. */ u8 *)(pbVar4 + 1);

  if (bVar1 == 0xff) {

    uVar3 = 0;

  }

  else {

    uVar3 = (u32)(u8)(bVar1 - 1);

  }
  index32 = (u8)uVar3 << 8;
  index32 |= (u8)uVar5;
  index = index32;

  if (DAT_0095ac70_abs[index] != 0) {

    uVar2 = *(u8 *)(iVar6 + 0xd);

    *(u8 *)(iVar6 + 0xd) = 3;

    FUN_003b22a0(param_2);

    FUN_003b1d90(index & 0xff,param_2);

    *(u8 *)(iVar6 + 0xd) = uVar2;

  }

  return 0;

}
#define FUN_003ad930(...) ((u64 (*)(...))FUN_003ad930)(__VA_ARGS__)
#undef FUN_003ada00

// W383 residual: s1/s2 byte/index color cycle; declaration permutation was neutral, loading bVar6 before bVar1 was worse, and ABI/full-prototype probes were neutral or worse.
// W422 probes: bVar1-tail, bVar6-u32, low-alias, ternary, and bVar6-first each nd5/256; u32-byte locals nd147/248 and bVar7-u8 nd132/260; baseline retained.
// FUN_003ADA00 NONMATCHING


u32 FUN_003ada00(u64 param_1,int param_2)



{

  char msg[8];

  u8 bVar1;

  u8 uVar2;

  u32 uVar3;
  u8 *pbVar4;

  int iVar5;

  u8 bVar6;
  int bVar7;

  int offset;
  int base;

  

  iVar5 = param_2;

  offset = *(volatile /* Removing this qualifier worsens FUN_003ada00 (NONMATCHING nd5 -> NONMATCHING nd8, size 256 -> 256) - measured W170. */ int *)(iVar5 + 0x18);
  base = *(int *)(iVar5 + 0x10);
  pbVar4 = (u8 *)(base + offset);

  bVar1 = *pbVar4 - 1;

  bVar6 = pbVar4[1];

  if (bVar6 == 0xff) {

    bVar7 = 0;

  }

  else {

    bVar7 = (bVar6 - 1) & 0xff;

  }

  msg[0] = 0x83;

  msg[1] = 0xd5;

  msg[2] = 0;

  uVar2 = *(u8 *)(iVar5 + 0xd);

  *(u8 *)(iVar5 + 0xd) = 3;

  FUN_003b22a0(param_2);

  FUN_003b2020(msg,param_2);

  FUN_003b22a0(param_2);

  uVar3 = FUN_00171110_u32((u16)((bVar7 & 0xff) << 8 | bVar1),0);

  FUN_003b2020(uVar3,param_2);

  *(u8 *)(iVar5 + 0xd) = uVar2;

  return 0;

}
#define FUN_003ada00(...) ((u64 (*)(...))FUN_003ada00)(__VA_ARGS__)
#undef FUN_003adb00

// FUN_003ADB00
u64 FUN_003adb00(u64 param_1,int param_2)
{
  u8 low;
  u8 high;
  u8 *data;
  int state;
  int offset;
  int base;

  state = param_2;
  offset = *(volatile /* Removing this function's qualifier batch loses FUN_003adb00 (MATCH nd0 -> MISMATCH nd3, size 128 -> 128) - measured W170. */ int *)(param_2 + 0x18);
  base = *(volatile /* Removing this function's qualifier batch loses FUN_003adb00 (MATCH nd0 -> MISMATCH nd3, size 128 -> 128) - measured W170. */ int *)(param_2 + 0x10);
  base = base + offset;
  data = (u8 *)base;
  low = data[0] - 1;
  high = data[1];
  if (high == 0xff) {
    high = 0;
  } else {
    high = (u8)(high - 1);
  }
  FUN_003ad400_typed((u16)(high << 8 | low),2,param_1,state);
  return 0;
}

#define FUN_003adb00(...) ((u64 (*)(...))FUN_003adb00)(__VA_ARGS__)
#undef FUN_003adb80

// FUN_003ADB80 NONMATCHING


// W420 recovery: low-byte-first extraction with preserved base loads; verify nd229 -> 212, object 332/384B.
u32 FUN_003adb80(u64 param_1,int param_2)
{
  u32 uVar2;
  u32 uVar4;
  u32 uVar7;
  u32 uVar9;
  u32 low1;
  u32 low2;
  u32 low3;
  int iVar3;
  int iVar8;
  u8 *pbVar6;
  u8 temp;

  iVar3 = *(volatile int *)(param_2 + 0x18) + *(volatile int *)(param_2 + 0x10);
  low1 = *(u8 *)(iVar3 + 4) - 1 & 0xff;
  temp = *(u8 *)(iVar3 + 5);
  if (temp == 0xff) {
    uVar2 = 0;
  }
  else {
    uVar2 = (u32)(u8)(temp - 1);
  }

  uVar2 = uVar2 << 8 | low1;

  pbVar6 = (u8 *)(*(volatile int *)(param_2 + 0x18) + *(volatile int *)(param_2 + 0x10));
  low2 = *pbVar6 - 1 & 0xff;
  temp = pbVar6[1];
  if (temp == 0xff) {
    uVar7 = 0;
  }
  else {
    uVar7 = (u32)(u8)(temp - 1);
  }

  uVar7 = uVar7 << 8 | low2;

  iVar8 = *(volatile int *)(param_2 + 0x18) + *(volatile int *)(param_2 + 0x10);
  low3 = *(u8 *)(iVar8 + 2) - 1 & 0xff;
  temp = *(u8 *)(iVar8 + 3);
  if (temp == 0xff) {
    uVar4 = 0;
  }
  else {
    uVar4 = (u32)(u8)(temp - 1);
  }

  uVar4 = uVar4 << 8 | low3;

  temp = *(u8 *)(iVar8 + 7);
  if (temp == 0xff) {
    temp = 0;
  }
  else {
    temp = temp - 1;
  }
  uVar9 = 0;
  if ((temp == 0) && (*(u8 *)(iVar8 + 6) == 1)) {
    uVar9 = 0x100;
  }

  FUN_003cf160(uVar2 | (uVar7 << 0x10) | (uVar4 << 8), uVar9 | 0x200);
  return 0;
}
#define FUN_003adb80(...) ((u64 (*)(...))FUN_003adb80)(__VA_ARGS__)
#undef FUN_003add00

// FUN_003ADD00
u64 FUN_003add00(void)
{
  FUN_003cf520();
  return 0;
}
#define FUN_003add00(...) ((u64 (*)(...))FUN_003add00)(__VA_ARGS__)
#undef FUN_003add30

// FUN_003ADD30
u64 FUN_003add30(void)
{
  return 0;
}
#define FUN_003add30(...) ((u64 (*)(...))FUN_003add30)(__VA_ARGS__)
#undef FUN_003add40

// FUN_003ADD40 NONMATCHING


// W420 recovery: unsigned high-byte branches and explicit mask; verify nd152 -> 144, object 264/288B.
u32 FUN_003add40(u64 param_1,int param_2)



{

  u8 cVar1;

  u32 uVar2;

  int iVar3;

  u32 uVar4;

  u8 *pbVar5;

  u32 uVar6;

  u32 low1;

  u32 packed1;

  u32 low2;

  u32 low3;

  int iVar7;

  iVar3 = *(volatile int *)(param_2 + 0x18) + *(volatile int *)(param_2 + 0x10);

  low1 = *(u8 *)(iVar3 + 4) - 1 & 0xff;

  cVar1 = *(u8 *)(iVar3 + 5);

  if (cVar1 == 0xff) {

    uVar2 = 0;

  }

  else {

    uVar2 = (u32)(u8)(cVar1 - 1);

  }

  uVar2 = uVar2 & 0xff;
  packed1 = low1 | (uVar2 << 8);

  pbVar5 = (u8 *)(*(volatile int *)(param_2 + 0x18) + *(volatile int *)(param_2 + 0x10));

  low2 = *pbVar5 - 1 & 0xff;

  uVar6 = (u32)pbVar5[1];

  if (uVar6 == 0xff) {

    uVar6 = 0;

  }

  else {

    uVar6 = uVar6 - 1 & 0xff;

  }

  uVar6 = uVar6 << 8 | low2;

  iVar7 = *(volatile int *)(param_2 + 0x18) + *(volatile int *)(param_2 + 0x10);

  low3 = *(u8 *)(iVar7 + 2) - 1 & 0xff;

  cVar1 = *(u8 *)(iVar7 + 3);

  if (cVar1 == 0xff) {

    uVar4 = 0;

  }

  else {

    uVar4 = (u32)(u8)(cVar1 - 1);

  }

  uVar4 = uVar4 << 8 | low3;

  FUN_003cf160(packed1 | (uVar6 << 0x10) | (uVar4 << 8),0);

  return 0;

}
#define FUN_003add40(...) ((u64 (*)(...))FUN_003add40)(__VA_ARGS__)

// Retail 0x003ade60-0x003ade68
// FUN_003ADE60
u64 FUN_003ade60(u64 param_1,int param_2)
{
  return 0;
}
#undef FUN_003ade70
static inline u8 *itfMesAddSecondFirst(int first, int second)
{
  return (u8 *)(second + first);
}

// W383 residual: commutative addu operand order at off92; declaration, first-use, ABI-alias, and full-prototype levers left this instruction-order floor unchanged.
// FUN_003ADE70
u32 FUN_003ade70(int param_1,int param_2)
{
  u8 bVar1;
  u8 bVar2;
  u8 bVar3;
  u8 bVar4;
  u8 *data2;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;

  bVar1 = ((u8 *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18)))[0];
  uVar5 = (u8)(bVar1 - 1);
  bVar2 = ((u8 *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18)))[1];
  if (bVar2 == 0xff) {
    uVar6 = 0;
  } else {
    uVar6 = (u8)(bVar2 - 1);
  }
  uVar5 = (u8)uVar6 << 8 | uVar5 & 0xff;
  data2 = itfMesAddSecondFirst(*(volatile int *)(param_2 + 0x10),
                               *(volatile int *)(param_2 + 0x18));
  bVar3 = data2[2];
  uVar7 = (u8)(bVar3 - 1);
  bVar4 = data2[3];
  if (bVar4 == 0xff) {
    uVar8 = 0;
  } else {
    uVar8 = (u8)(bVar4 - 1);
  }
  uVar5 = (u16)uVar5;
  uVar8 = (u8)uVar8;
  FUN_003bb060((u16)uVar5,(u16)(uVar8 << 8 | uVar7 & 0xff));
  return 0;
}
#undef FUN_003adf40

// FUN_003ADF40
u64 FUN_003adf40(void)
{
  return 0;
}
#undef FUN_003adf50

// FUN_003ADF50
u64 FUN_003adf50(void)
{
  return 0;
}
#undef FUN_003adf60

// FUN_003ADF60
u64 FUN_003adf60(void)
{
  return 0;
}
#undef FUN_003adf70

// FUN_003ADF70


u64 FUN_003adf70(u64 param_1,int param_2)



{

  u32 uVar5;
  u8 uVar6;
  u8 bVar2;
  u32 uVar3;
  int uVar4;
  u32 combined;
  int first;
  int second;
  
  first = *(volatile /* Removing this function's qualifier batch loses FUN_003adf70 (MATCH nd0 -> MISMATCH nd3, size 144 -> 144) - measured W170. */ int *)(param_2 + 0x18);
  second = *(volatile /* Removing this function's qualifier batch loses FUN_003adf70 (MATCH nd0 -> MISMATCH nd3, size 144 -> 144) - measured W170. */ int *)(param_2 + 0x10);
  uVar5 = second + first;
  uVar6 = *(u8 *)uVar5 - 1;
  bVar2 = *(u8 *)(uVar5 + 1);
  if (bVar2 == 0xff) {
    uVar3 = 0;
  } else {
    uVar3 = (u32)(u8)(bVar2 - 1);
  }
  uVar3 = uVar3 & 0xff;
  combined = uVar3 << 8;
  uVar3 = combined | uVar6;
  FUN_0017db00();
  uVar4 = FUN_0016dd40();
  FUN_0016e2b0(uVar4,uVar3);

  return 0;

}
#define FUN_003adf70(...) ((u64 (*)(...))FUN_003adf70)(__VA_ARGS__)
#undef FUN_003ae000

#pragma alias itfPanelSelectThresholdTableValue FUN_003ae000
// FUN_003AE000


u64 itfPanelSelectThresholdTableValue(u64 unused,int context)



{

  u8 encodedHigh;

  u32 packedValue;

  u32 uVar3;

  u8 *command;

  u32 uVar5;

  ItfFloat3 thresholdTable;

  ItfFloat3 valueTable;

  

  thresholdTable = DAT_006a2640_vec_abs[0];

  valueTable = DAT_006a2650_vec_abs[0];

  uVar3 = *(u32 *)(context + 0x18);

  command = (u8 *)(*(int *)(context + 0x10) + uVar3);

  uVar5 = *command - 1 & 0xff;

  encodedHigh = command[1];

  if (encodedHigh == 0xff) {

    packedValue = 0;

  }

  else {

    packedValue = (u32)(u8)(encodedHigh - 1);

  }

  packedValue = (packedValue & 0xff) << 8 | uVar5 & 0xff;

  FUN_0017db00();

  uVar3 = FUN_0016dd40();

  FUN_0016e2b0(uVar3,packedValue);

  if (packedValue == 0) {
    return 0;
  }

  uVar5 = 0;
  while (uVar5 < 3) {
    if (((s32 *)&thresholdTable)[uVar5] >= (int)packedValue) {
      break;
    }
    uVar5 = uVar5 + 1;
  }

  FUN_0010a4e0(0,0,4,*(s16 *)((u8 *)&valueTable + uVar5 * 4));

  return 0;

}
#define FUN_003ae000(...) ((u64 (*)(...))FUN_003ae000)(__VA_ARGS__)

// Retail 0x003ae140-0x003ae148
// FUN_003AE140
u64 FUN_003ae140(u64 param_1,int param_2)
{
  return 0;
}

// Retail 0x003ae150-0x003ae158
// FUN_003AE150
u64 FUN_003ae150(u64 param_1,int param_2)
{
  return 0;
}
#undef FUN_003ae160

// W383 residual: a2/a3/v1 three-role color cycle (first index/second index/counter); declaration permutation was neutral, counter-before-pointer was worse, and the full 2-int prototype was neutral.
// W422 probes: first2 split nd10/252, second2 split nd7/252, iVar8 split nd7/252, counter-tail nd14/252, indexValue nd7/252, while nd68/260, merge first/second nd7/252, and merge-counter-first/second nd118/252 and nd54/252; baseline retained.
// FUN_003AE160 NONMATCHING


u32 FUN_003ae160(u64 param_1,int param_2)



{

  u8 bVar1;
  u8 bVar2;
  u8 cVar3;
  int iVar4;
  int iVar8;
  int counter;
  u32 uVar6;
  u32 uVar5;
  int firstIndex;
  int secondIndex;
  u32 firstLow;
  u32 secondLow;
  int first2;
  int second2;
  u8 *pbVar7;
  int *piVar10;
  int *piVar9;
  int aiStack_20 [8];

  

  first2 = *(int *)(param_2 + 0x18);

  second2 = *(int *)(param_2 + 0x10);

  iVar8 = second2 + first2;
  pbVar7 = (u8 *)iVar8;

  bVar1 = *pbVar7;
  firstLow = bVar1 - 1 & 0xff;

  bVar2 = pbVar7[1];

  if (bVar2 == 0xff) {

    uVar5 = 0;

  }

  else {

    uVar5 = (u32)(u8)(bVar2 - 1);

  }


  firstIndex = (u8)uVar5 << 8 | (u8)firstLow;
  /* Removing this qualifier worsens FUN_003ae160 (NONMATCHING nd7 -> nd128, size 252 -> 248) - measured W170. */
  first2 = *(volatile int *)(param_2 + 0x18);
  /* Removing this qualifier worsens FUN_003ae160 (NONMATCHING nd7 -> nd128, size 252 -> 248) - measured W170. */
  second2 = *(volatile int *)(param_2 + 0x10);
  iVar8 = first2 + second2;
  bVar2 = *(u8 *)(iVar8 + 2);
  secondLow = bVar2 - 1 & 0xff;

  cVar3 = *(u8 *)(iVar8 + 3);

  if (cVar3 == 0xff) {

    uVar6 = 0;

  }

  else {

    uVar6 = (u32)(u8)(cVar3 - 1);

  }

  secondIndex = (u8)uVar6 << 8 | (u8)secondLow;
  piVar10 = (int *)DAT_006a2680;
  piVar9 = aiStack_20;
  counter = 5;


  do {

    iVar4 = *piVar10;

    piVar10 = piVar10 + 1;

    counter = counter + -1;

    *piVar9 = iVar4;

    piVar9 = piVar9 + 1;

  } while (0 < counter);

  FUN_0016f1f0(secondIndex + aiStack_20[firstIndex],1);
  return 0;

}
#define FUN_003ae160(...) ((u64 (*)(...))FUN_003ae160)(__VA_ARGS__)
#undef FUN_003ae260

// W383 residual: a2/a3/v1 three-role color cycle (first index/second index/counter); declaration permutation was neutral, counter-before-pointer was worse, and the full 2-int prototype was neutral.
// W422 probes: explicit index locals/reuse nd7/252, counter split nd14/252, counter declaration early nd7/252, and dual address split nd10/252; baseline retained.
// FUN_003AE260 NONMATCHING


u32 FUN_003ae260(u64 param_1,int param_2)



{

  u8 bVar1;

  u8 bVar2;

  u8 cVar3;

  int iVar4;

  u32 uVar5;

  u32 uVar6;

  int iVar8;
  u32 firstLow;
  u32 secondLow;
  int first2;
  int second2;


  u8 *pbVar7;
  int *piVar10;

  int *piVar9;

  int aiStack_20 [8];

  

  first2 = *(int *)(param_2 + 0x18);
  second2 = *(int *)(param_2 + 0x10);
  iVar8 = second2 + first2;
  pbVar7 = (u8 *)iVar8;

  bVar1 = *pbVar7;
  firstLow = bVar1 - 1 & 0xff;

  bVar2 = pbVar7[1];

  if (bVar2 == 0xff) {

    uVar5 = 0;

  }

  else {

    uVar5 = (u32)(u8)(bVar2 - 1);

  }


  uVar5 = (u8)uVar5 << 8 | (u8)firstLow;
  /* Removing this qualifier worsens FUN_003ae260 (NONMATCHING nd7 -> nd127, size 252 -> 248) - measured W170. */
  first2 = *(volatile int *)(param_2 + 0x18);
  /* Removing this qualifier worsens FUN_003ae260 (NONMATCHING nd7 -> nd127, size 252 -> 248) - measured W170. */
  second2 = *(volatile int *)(param_2 + 0x10);
  iVar8 = first2 + second2;
  bVar2 = *(u8 *)(iVar8 + 2);
  secondLow = bVar2 - 1 & 0xff;

  cVar3 = *(u8 *)(iVar8 + 3);

  if (cVar3 == 0xff) {

    uVar6 = 0;

  }

  else {

    uVar6 = (u32)(u8)(cVar3 - 1);

  }

  uVar6 = (u8)uVar6 << 8 | (u8)secondLow;
  piVar10 = (int *)DAT_006a2680;
  piVar9 = aiStack_20;
  iVar8 = 5;

  do {
    iVar4 = *piVar10;
    piVar10 = piVar10 + 1;
    iVar8 = iVar8 + -1;
    *piVar9 = iVar4;
    piVar9 = piVar9 + 1;
  } while (0 < iVar8);

  FUN_0016f1f0(uVar6 + aiStack_20[uVar5],0);
  return 0;

}
#define FUN_003ae260(...) ((u64 (*)(...))FUN_003ae260)(__VA_ARGS__)
#undef FUN_003ae360

// FUN_003AE360


u64 FUN_003ae360(u64 param_1,int param_2)



{

  u8 bVar1;

  u32 uVar2;

  u32 uVar3;

  int iVar3;

  int offset;

  int base;

  u8 *pbVar4;

  

  offset = *(int *)(param_2 + 0x18);

  base = *(int *)(param_2 + 0x10);

  pbVar4 = (u8 *)(base + offset);

  uVar3 = *(u8 *)pbVar4;

  uVar3 = uVar3 - 1 & 0xff;

  bVar1 = *(u8 *)(pbVar4 + 1);

  if (bVar1 == 0xff) {

    uVar2 = 0;

  }

  else {

    uVar2 = (u32)(u8)(bVar1 - 1);

  }

  uVar2 = (uVar2 & 0xff) << 8;

  uVar3 = uVar3 & 0xff;

  uVar2 = uVar2 | uVar3;

  FUN_003b22a0(param_2);

  iVar3 = FUN_0017c860(uVar2);

  offset = iVar3 << 2;

  uVar2 = uVar2 << 4;

  FUN_003b2020(*(u8 **)((u8 *)&PTR_s_Sayonara_006a24d0_abs + uVar2 + offset),param_2);

  return 0;

}
#define FUN_003ae360(...) ((u64 (*)(...))FUN_003ae360)(__VA_ARGS__)

