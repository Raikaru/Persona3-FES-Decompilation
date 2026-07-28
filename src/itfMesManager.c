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
extern int FUN_003b0bb0();
extern int FUN_003b0c20();
extern int FUN_003b0ce0();
extern int thunk_FUN_003b0e04();
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
u64 FUN_003a4360(u64 param_1,long param_2);
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
extern u64 FUN_003a53b0_8(int param_1,int param_2,u64 param_3,int param_4,int param_5,
                          u32 param_6,int param_7,int param_8);
#pragma alias FUN_003a53b0_8f FUN_003a53b0
extern u64 FUN_003a53b0_8f(int param_1,int param_2,f32 param_3,int param_4,int param_5,
                           u32 param_6,int param_7,int param_8);
#pragma alias FUN_003a5fd0_typed FUN_003a5fd0
void FUN_003a5540(int p1,int p2,u64 p3,int p4,int p5,int p6,int p7);
#pragma alias FUN_003b0ce0_typed FUN_003b0ce0
extern void FUN_003b0ce0_typed(u64 param_1,u64 param_2);
void FUN_003a5540(int p1,int p2,u64 p3,int p4,int p5,int p6,int p7);
u64  FUN_003a5570(u32 param_1,u64 param_2,u64 param_3,u32 param_4,  u64 param_5,long param_6,u64 param_7,u32 param_8,u64 param_9  );
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
long FUN_003a6140(u32 *param_1,int param_2,u32 param_3,u64 param_4,int param_5,  u64 param_6,long param_7,u32 param_8);
#pragma alias FUN_003a6140_typed FUN_003a6140
extern u32 FUN_003a6140_typed(u32 *param_1, s32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, s32 param_7, u32 param_8);
int FUN_003a628c(int param_1);
void FUN_003a62b0(int param_1,int param_2);
#pragma alias FUN_003a62b0_typed FUN_003a62b0
extern void FUN_003a62b0_typed(u32 param_1, u32 *param_2);
int FUN_003a62e0(int param_1,int param_2);
#pragma alias FUN_003a62e0_typed FUN_003a62e0
extern s32 FUN_003a62e0_typed(u32 param_1, u32 param_2);
static void FUN_003a6380(int param_1,int param_2,int param_3,u8 param_4);
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
u32 FUN_003a7a40(int param_1);
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

// FUN_003a3ba0
void itfMesMng003a3ba0(s32 mesHandleIdx, u32 param_2)
{
    int iVar1;

    iVar1 = *(int*)((u8*)&sItfMesHandleSystem + mesHandleIdx * ITFMES_HANDLE_STRIDE);
    K_ASSERT(iVar1 != 0, 0x956);
    *(u32*)(iVar1 + 0x50) = param_2;
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

// FUN_003a3da0
u32 itfMesMng003a3da0(s32 mesHandleIdx)
{
    u32* p;

    p = *(u32**)((u8*)&sItfMesHandleSystem + mesHandleIdx * ITFMES_HANDLE_STRIDE);
    K_ASSERT(p != NULL, 0xa54);
    return *p;
}

// FUN_003a3f20
s16 itfMesMng003a3f20(s32 mesHandleIdx)
{
    int p;

    p = *(int*)((u8*)&sItfMesHandleSystem + mesHandleIdx * ITFMES_HANDLE_STRIDE);
    K_ASSERT(p != 0, 0xaa9);
    return *(s16*)(p + 0x56);
}

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
// FUN_003A2EF0 NONMATCHING


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

    uVar2 = (*DAT_00960178)(0x1e8,0x40000);

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

      FUN_003b19a0();

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

          FUN_003a8d60();

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

        if (lVar7 < 0x69) {

          FUN_003b1c90(0x5c0,puVar2[6],puVar2[7]);

        }

        else {

          FUN_003b0d70(puVar2[7],*puVar8,puVar2[6]);

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

      FUN_005225a8(0x6a1ae0);

      FUN_003a6520_typed(puVar2);

      FUN_003a95f0(puVar2[0x2b]);

      uVar4 = *puVar2;

      *puVar2 = uVar4 & 0xfffffff8;

      *puVar2 = uVar4 & 0xfffffff8 | 2;

    }

    *(u8 *)(puVar2 + 0xd) = 1;

    *puVar2 = *puVar2 | 0x1000000;

    FUN_005225a8(0x6a1b00,*(u16 *)((int)puVar2 + 0x12));

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

    FUN_003b19a0();

  }

  uVar8 = FUN_003a6140_typed((u32 *)(iVar3 + 0x20),*(s16 *)(iVar3 + 0x1a),puVar2[0x14],puVar2[0x10],uVar8,

                             puVar2[3],iVar10,1);

  puVar2[0x13] = uVar8;

  *(short *)((int)puVar2 + 0x5a) = (short)lVar6;

  uVar8 = *puVar2;

  *puVar2 = uVar8 & 0xffffffc7;

  *puVar2 = uVar8 & 0xffffffc7 | 0x10;

  if (*(short *)((int)puVar2 + 0x12) == 4) {

    FUN_003a3680_direct(puVar2);

  }

  else if (*(short *)((int)puVar2 + 0x12) == 3) {

    FUN_003a3530_direct(puVar2);

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
// FUN_003A3C10 NONMATCHING


void FUN_003a3c10(int param_1,int param_2)



{
  int iVar1;

  int sVar2;

  int iVar3;

  u32 uVar4;

  

  iVar1 = *(int *)(DAT_00959eec_abs + param_1 * 0xd);

  if (iVar1 == 0) {

    FUN_0019d3f0("itfMesManager.c",0x96b);

  }

  sVar2 = 0;

  uVar4 = *(u32 *)(iVar1 + 0x50);

  iVar3 = 0;

  while( 1 ) {

    if ((uVar4 & 1) == 0) {

      sVar2 = sVar2 + 1;

    }

    if (param_2 <= iVar3) break;

    iVar3 = iVar3 + 1;

    uVar4 = uVar4 >> 1;

  }

  if ((uVar4 & 1) == 0) {

    sVar2 = sVar2 + -1;

  }

  else {

    sVar2 = 0;

  }

  *(short *)(iVar1 + 0x56) = sVar2;

  *(short *)(iVar1 + 0x58) = sVar2;

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
// FUN_003A4360 NONMATCHING


u64 FUN_003a4360(u64 param_1,long param_2)



{

  u32 *puVar1;

  int *piVar2;

  int iVar3;

  

  iVar3 = (int)param_1;

  if (param_2 == 7) {

    FUN_003a4990(param_1,7,0);

    piVar2 = (int *)(DAT_00959eec_abs + iVar3 * 0xd);

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

    piVar2 = (int *)(DAT_00959eec_abs + iVar3 * 0xd);

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

    piVar2 = (int *)(DAT_00959eec_abs + iVar3 * 0xd);

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

    FUN_003a6a80(param_1,0x231,0x18b);

  }

  return 0;

}
#define FUN_003a4360(...) ((u64 (*)(...))FUN_003a4360)(__VA_ARGS__)
#undef FUN_003a4a70
// FUN_003A4A70 NONMATCHING


u32 FUN_003a4a70(int param_1, int param_2, int param_3)
{
    u32 *object;
    s16 *table;
    s16 *found;
    int count;
    s32 i;

    object = *(u32**)(DAT_00959eec_abs + param_1 * 0xd);
    table = (s16*)((u8*)object + 0x40);
    found = NULL;
    if (param_2 < 0 || param_2 >= 0x10)
        return 0;

    if (param_2 == 6)
        param_2 = 5;
    if (param_2 == 6 || param_2 == 0xc || param_2 == 0xe)
        return 0;

    count = *(s16*)((u8*)table + 0x26);
    for (i = 0; i < count; i++)
    {
        s16 *entry = (s16*)((u8*)table + i * 4 + 0x28);
        if (entry[0] == param_2)
        {
            found = entry;
            break;
        }
    }
    if (found == NULL)
    {
        if (count >= 0xf)
            return 0;
        found = (s16*)((u8*)table + count * 4 + 0x28);
        *(s16*)((u8*)table + 0x26) = count + 1;
    }
    found[0] = param_2;
    found[1] = param_3;
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
// FUN_003A4CE0 NONMATCHING


void FUN_003a4ce0(void)



{

  int iVar1;

  

  DAT_00959ec0 = 0;

  DAT_00959ec8 = 0;

  DAT_00959ecc = 0;

  FUN_003b4920(0x959ed0,0x959ee0,0x40,0x34);

  for (iVar1 = DAT_00959ed8; iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {

    *(u32 *)(iVar1 + 0xc) = 0;

  }

  FUN_0035ad80(0x6a1b58,0x106f,0,0,0x3a8440,0x3a8530,0);

  FUN_00194c50(0x6a1b68,0x1cbf,0x3a84c0,0x3a8530,0);

  FUN_005225a8(0x6a1b80,0x6a1a70);

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


// FUN_003A53B0 NONMATCHING
u64

FUN_003a53b0(int param_1,int param_2,f32 param_3,int param_4,int param_5,

            u32 param_6,int param_7,int param_8,int param_9)



{

  int iVar1;

  int lVar2;

  u64 uVar3;

  

  iVar1 = *(int *)(DAT_00959eec_abs + param_7 * 0xd);

  if (iVar1 == 0) {

    FUN_0019d3f0("itfMesManager.c",0xfad);

  }

  iVar1 = param_8 * 8 + *(int *)(iVar1 + 4);

  if (iVar1 == -0x20) {

    FUN_0019d3f0("itfMesManager.c",0xfb0);

  }

  iVar1 = *(int *)(iVar1 + 0x24);

  if (iVar1 == 0) {

    FUN_0019d3f0("itfMesManager.c",0xfb3);

  }

  lVar2 = FUN_003a5940_typed(iVar1,0);

  if (lVar2 == 0) {

    FUN_0019d3f0("itfMesManager.c",0xfb6);

  }

  uVar3 = FUN_003b2940(param_1 << 4,param_2 << 3,param_4,param_5,0,0xff,lVar2,0);

  if ((param_6 & 1) != 0) {

    thunk_FUN_003b0e04(uVar3,param_5);

  }

  thunk_FUN_003b0e54_f32(uVar3,param_3);

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
// FUN_003A5570 NONMATCHING






u64

FUN_003a5570(u32 param_1,u64 param_2,u64 param_3,u32 param_4,
            u64 param_5,long param_6,u64 param_7,u32 param_8,u64 param_9

            )



{

  u64 uVar1;

  

  if (param_6 == 10) {

    param_6 = 5;

    param_4 = param_4 & 0xffffff00 | (int)(DAT_007cad94 * (float)(param_4 & 0xff));

  }

  FUN_003a5fd0(*(int *)(DAT_00959eec_abs + (int)param_8 * 0xd) + 0xd4);

  uVar1 = FUN_003a53b0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);

  FUN_003b0ce0(uVar1,param_5);

  FUN_003b1330(uVar1,1);

  FUN_003b0170(uVar1);

  return 0;

}
#define FUN_003a5570(...) ((u64 (*)(...))FUN_003a5570)(__VA_ARGS__)
#undef FUN_003a56f0
// FUN_003A56F0 NONMATCHING






u64

FUN_003a56f0(u32 param_1,s32 param_2,f32 param_3,u32 param_4,

            s32 param_5,s32 param_6,s32 param_7,s32 param_8,s32 param_9,

            int param_10,int param_11)



{

  int iVar1;

  int uVar2;

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

  uVar2 = FUN_003a53b0_typed(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);

  if (param_11 != 0) {

    if (*(int *)((int)uVar2 + 0x24) == 0) {

      uVar3 = FUN_003a53b0_8f(param_1,param_2 + 0x19,param_3,param_4,param_5,param_6,param_7,

                           param_10);

    }

    else {

      uVar3 = FUN_003a53b0_8f(param_1,param_2 + 0x32,param_3,param_4,param_5,param_6,param_7,

                           param_10);

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

  if (((*puVar9 & 0x400000) == 0) && ((DAT_00959ecc & 1) != 0)) {

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

    FUN_003a6060_typed(param_1,(u8 *)0x95abf0);

  }

  puVar9[0xc] = (u32)uVar4;

  return;

}
#define FUN_003a5980(...) ((void (*)(...))FUN_003a5980)(__VA_ARGS__)
#undef FUN_003a5ca0
// FUN_003A5CA0 NONMATCHING


void FUN_003a5ca0(int param_1,int param_2,u32 param_3,int param_4)



{

  u32 uVar1;

  int iVar2;

  u32 uVar3;

  long lVar4;

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

      uVar3 = (*DAT_00960178)(uVar1,0x40000);

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

      uVar3 = (*DAT_00960178)(uVar1,0x40000);

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
#undef FUN_003a5ea0
typedef struct ItfMesAllocationSlots {
  u32 objects[32];
  u32 allocations[32];
} ItfMesAllocationSlots;

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
// FUN_003A6140 NONMATCHING


long FUN_003a6140(u32 *param_1,int param_2,u32 param_3,u64 param_4,int param_5,

                 u64 param_6,long param_7,u32 param_8)



{

  int iVar1;

  u32 lVar2;

  int iVar3;

  

  lVar2 = 0;

  for (iVar3 = 0; iVar3 < param_2; iVar3 = iVar3 + 1) {

    if ((param_3 & 1) == 0) {

      lVar2 = FUN_003b2940(param_4,param_5,param_8,0,0,0xff,*param_1,lVar2);

      if (param_7 != 0) {

        iVar1 = (int)param_7;

      }

      else {

        iVar1 = *(short *)((int)lVar2 + 0x12) * 8;

      }

      param_5 = param_5 + iVar1;

    }

    param_3 = param_3 >> 1;

    param_1 = param_1 + 1;

  }

  if (lVar2 != 0) {

    thunk_FUN_003a6360(lVar2,param_6);

    FUN_003a6410(lVar2,0xff);

  }

  return lVar2;

}





#undef FUN_003a628c
#pragma optimization_level 3
// FUN_003A6280 thunk_FUN_003a628c
int thunk_FUN_003a628c(int param_1)
{
  return FUN_003a628c(param_1);
}
#pragma optimization_level 2
#define FUN_003a6140(...) ((long (*)(...))FUN_003a6140)(__VA_ARGS__)

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
static void FUN_003a6380(int param_1,int param_2,int param_3,u8 param_4)
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
  extern void FUN_003a8d60(u32 resource);

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

          FUN_005225a8(0x6a1ba0);

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

              FUN_003b19a0();

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

          FUN_003b0c70();

        }

      }

      *puVar4 = *puVar4 & 0xfeffffff;

    }

  }

  return;

}
#define FUN_003a7120(...) ((void (*)(...))FUN_003a7120)(__VA_ARGS__)
#undef FUN_003a7490
// FUN_003A7490 NONMATCHING


void FUN_003a7490(u32 *param_1)



{

  short sVar1;

  u32 uVar2;

  int lVar3;

  short sVar4;

  int iVar5;

  u32 uVar6;

  u32 uVar7;

  int *piVar8;

  int iVar9;

  u32 *puVar10;

  u32 *puVar11;

  

  puVar11 = (u32 *)param_1;

  uVar2 = *puVar11;

  sVar4 = (short)puVar11[0x15];

  if (sVar4 == 4) {

    if ((puVar11[0xc] == 0) || (0xb17 < (int)puVar11[10])) {

      *(u16 *)(puVar11 + 0x15) = 0xffff;

    }

    else {

      FUN_003a7940(param_1,0x40);

    }

  }

  else if (sVar4 == 3) {

    sVar4 = (short)puVar11[0x19] + -0x10;

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

  }

  else if (sVar4 == 2) {

    if (((uVar2 & 0x38) == 0x20) && (lVar3 = FUN_003a7a40(), lVar3 == 1)) {

      if (puVar11[0x13] != 0) {

        FUN_003affd0();

        puVar11[0x13] = 0;

      }

      iVar5 = *(int *)(puVar11[0x12] * 8 + puVar11[1] + 0x24);

      sVar4 = *(short *)((int)puVar11 + 0x56);

      sVar1 = *(short *)(iVar5 + 0x1a);

      puVar10 = (u32 *)(iVar5 + 0x20);

      for (lVar3 = 0; lVar3 < sVar1; lVar3 = (long)((int)lVar3 + 1)) {

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

  }

  else if (sVar4 == 1) {

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

        FUN_003a7940(param_1,-0x40);

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

        if (((DAT_007e094e & 0x4000) != 0) || ((DAT_007e0958 & 0x4000) != 0)) {

          lVar5 = 1;

        }

      }

      else {

        lVar5 = 1;

      }

    }

  }

  else if (*(short *)(param_1 + 0x56) == 0) {

    if (((DAT_007e094e & 0x1000) != 0) || ((DAT_007e0958 & 0x1000) != 0)) {

      lVar5 = -1;

    }

  }

  else {

    lVar5 = -1;

  }

  if (lVar5 == 0) {

    if ((DAT_007e094e & 0x40) == 0) {

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

      FUN_005225a8(0x6a1bc0);

      uVar4 = *(u32 *)(param_1 + 0x50);

      lVar5 = (long)*(short *)(param_1 + 0x56);

      iVar3 = 0;

      while ((iVar3 < 0x20 && (((uVar4 & 1) != 0 || (lVar5 = (long)((int)lVar5 + -1), -1 < lVar5))))

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
#undef FUN_003a7cb0
#undef FUN_003a6380
// FUN_003A7CB0 NONMATCHING


void FUN_003a7cb0(int param_1,int param_2)
{
  int next;

  FUN_003a6380(*(u32 *)(param_1 + 0xc),*(s16 *)(param_1 + 0x16),
               *(s16 *)(param_1 + 0x1a),0);
  if (param_2 < 0) {
    next = *(s16 *)(param_1 + 0x16) - 1;
    if (next < 0) {
      next = *(s16 *)(param_1 + 0x1a) - 1;
    }
  } else {
    next = *(s16 *)(param_1 + 0x16) + 1;
    if (*(s16 *)(param_1 + 0x1a) <= next) {
      next = 0;
    }
  }
  FUN_003a6380(*(u32 *)(param_1 + 0xc),next,*(s16 *)(param_1 + 0x1a),6);
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
  s16 *source;
  s16 *dest;
  int count;

  anim = (ItfMesAnim *)(object + 0x1d4);
  source = (s16 *)DAT_006a1bd0;
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
// FUN_003A8260 NONMATCHING


void FUN_003a8260(int param_1)



{

  short sVar1;

  int iVar2;

  int iVar3;

  u32 auStack_8 [2];

  

  sVar1 = *(short *)(param_1 + 0x58);

  if (sVar1 != -1) {

    FUN_005225a8(0x6a1be0,0x6a1a70);

    for (iVar3 = 0; iVar2 = FUN_003b1a90(*(u32 *)(param_1 + 0x4c)), iVar3 < iVar2;

        iVar3 = iVar3 + 1) {

      iVar2 = FUN_003b1b00(iVar3,*(u32 *)(param_1 + 0x4c));

      if (*(int *)(param_1 + 0x60) < iVar2) {

        FUN_003b1bc0(auStack_8,iVar3,*(u32 *)(param_1 + 0x4c));

        *(u32 *)(param_1 + 0x5c) = auStack_8[0];

        *(int *)(param_1 + 0x60) = iVar2;

      }

    }

    FUN_003b1bc0(auStack_8,sVar1,*(u32 *)(param_1 + 0x4c));

  }

  return;

}
#define FUN_003a8260(...) ((void (*)(...))FUN_003a8260)(__VA_ARGS__)
#undef FUN_003a8350
// FUN_003A8350 NONMATCHING


void FUN_003a8350(int param_1)
{
  u64 uStack_18;
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar1;
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

  iVar1 = (u32)fVar1 & 0xff;
  FUN_003a8710_typed(iVar2,iVar3,0.0f,iVar1,0x10);
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

