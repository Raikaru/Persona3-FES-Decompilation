#include "temporary.h"
#include "Event/Comu/comuFunction.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))
#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif
extern u32 DAT_007ce420;
extern u32 DAT_007ce66c;
extern u32 DAT_0095b074;
extern short *DAT_0095b070;
#pragma alias DAT_0095b070_raw_abs DAT_0095b070
extern u8 DAT_0095b070_raw_abs[];
#pragma alias DAT_0095b070_abs DAT_0095b070
#pragma alias DAT_0095b714_abs DAT_0095b714
extern u8 DAT_0095b714_abs[];
extern u8 DAT_0095b070_abs[];
extern u32 FUN_0035bb40(u32 param_1,u32 param_2,u32 param_3);
extern void FUN_0019d3f0(char* param_1,u32 param_2);
extern u32 FUN_0017e050(long param_1,long param_2,long param_3);
extern u32 FUN_0027c2b0(void);
extern u32 FUN_0027c330(void);
extern u32 FUN_0016dce0(s16 param_1);
extern void K_Assert(const char *file,s32 line);
extern char D_006A3280[];
extern s8 datGetSocialLinkLevel(s16 socialLink);
extern u32 datSocialLinkLevelIsNotZero(s16 socialLink);
extern u32 func_00172a50(s32 socialLink);
extern u32 func_00171960(s32 socialLink,s16 value);
extern s8 func_0016dd20(s16 socialLink);
extern void func_0016e410(s16 socialLink,s8 level);
extern s32 func_003c2570(s32 socialLink);
extern s32 clndGetCurrentMonth(void);
extern s32 clndGetCurrentDay(void);
extern u32 func_003c2b40(s32 *month,s32 *day);
extern u32 func_003c2c50(u8 socialLink);
extern s8 func_0016df30(s16 socialLink);
extern u32 datGetNextExp(s16 pcId);
extern u32 func_0016d280(s32 exp);
extern s16 *datGetActiveSocialLinkPtr(void);
extern u32 func_003c3e80(s32 param_1);
extern u32 adminiGetNowSeqId(void);
extern u32 adminiGetNextSeqId(void);
extern s32 FUN_00172160(long socialLink);
extern s32 FUN_001717c0(long socialLink);
extern s32 FUN_00172660(long socialLink);
#pragma alias FUN_003be1c0_typed FUN_003be1c0
extern u32 FUN_003be1c0_typed(long param_1,s32 param_2);
#pragma alias FUN_003be1c0_wide FUN_003be1c0
extern u32 FUN_003be1c0_wide(long param_1,long param_2);
#pragma alias FUN_003be2a0_typed FUN_003be2a0
extern u32 FUN_003be2a0_typed(...);
extern void adminiChangeSeq(s32 type,void *seq,s32 size,s32 arg4);
extern void FUN_0016f1f0(int param_1,int param_2);
#pragma alias FUN_0016f190_comu FUN_0016f190
extern u32 FUN_0016f190_comu(int param_1);
extern u32 DAT_0095b280;
extern u16* DAT_0095b2a0;
#pragma alias DAT_0095b2a0_abs DAT_0095b2a0
extern u8 DAT_0095b2a0_abs[];
#pragma alias DAT_0095b2a8_abs DAT_0095b2a8
extern u8 DAT_0095b2a8_abs[];
extern u32 DAT_0095b2a8;
extern u32 DAT_0095b568;
extern u32 DAT_0095b5e0[];
extern u32 DAT_0095b678;
#pragma alias DAT_0095b678_abs DAT_0095b678
extern u8 DAT_0095b678_abs[];
extern u32 DAT_0095b6a8;
#pragma alias DAT_0095b6a8_abs DAT_0095b6a8
extern u8 DAT_0095b6a8_abs[];
extern u32 DAT_0095b6ac;
extern u32 DAT_0095b6c8;
extern u32 DAT_0095b6cc;
extern u32 DAT_0095b6d8;
extern u32 DAT_0095b6dc;
extern u32 DAT_0095b6f8;
extern u32 DAT_0095b700;
extern u32 DAT_0095b704;
extern u32 DAT_0095b708;
extern u32 DAT_0095b70c;
#pragma alias DAT_0095b70c_abs DAT_0095b70c
extern u8 DAT_0095b70c_abs[];
extern u32 DAT_0095b710;
#pragma alias DAT_0095b710_abs DAT_0095b710
extern u8 DAT_0095b710_abs[];
#pragma alias DAT_0095b710_ptr_abs DAT_0095b710
extern u8 *DAT_0095b710_ptr_abs[];
extern u32 DAT_0095b714;
extern u32 DAT_0095b718;
extern u32 DAT_0095b730;
extern u32 LAB_003be5a0;

static SiteibiEventTable sSiteibiEvtTable; // 0095b658

SiteibiEventTable* Comu_GetSiteibiEvtTable()
{
    return &sSiteibiEvtTable;
}



/* Region 0x390000-0x3CFFFF recovered prototypes */
void FUN_003bdbd0(int param_1);
u32 * FUN_003bdd40(void);
u32 * FUN_003bdd50(void);
void FUN_003bdd60(u32 param_1,u32 param_2);
u32 FUN_003bdd90(int param_1);
u32 FUN_003bddd0(void);
void FUN_003bdde0(void);
u32 FUN_003bded0(u64 param_1);
u8 FUN_003bdfc0(int param_1);
u32 FUN_003be020(int param_1,int param_2,u32 param_3);
u32 FUN_003be2a0(int param_1,int *param_2,u32 param_3,u32 param_4,u8 *param_5);
u32 FUN_003be1c0(u32 param_1,s32 param_2);
u32 FUN_003be8e0(long param_1,u64 param_2);
u8 FUN_003bea20(int param_1,int param_2);
u32 FUN_003beab0(u32 param_1,u32 param_2,int *param_3);
int FUN_003beb10(int param_1);
void FUN_003beb70(int param_1);
u8 FUN_003bebd0(int param_1);
void FUN_003bec50(void);
int FUN_003beca0(int param_1);
u8 * FUN_003bee80(u16 param_1,int *param_2);
u32 FUN_003bf130(void);
void FUN_003bf180(u32 param_1,u32 param_2,u32 param_3);
u32 FUN_003bf200(long param_1,long param_2,long param_3,long param_4);
u32  FUN_003bf270(long param_1,long param_2,long param_3,long param_4,long param_5,long param_6);
u32 FUN_003bf370(void);
u32 FUN_003bf510(void);
u32 FUN_003bf610(void);

/* Region call-cast macros */
#define FUN_003bdbd0(...) ((void (*)(...))FUN_003bdbd0)(__VA_ARGS__)
#define FUN_003bdd40(...) ((u32 * (*)(...))FUN_003bdd40)(__VA_ARGS__)
#define FUN_003bdd50(...) ((u32 * (*)(...))FUN_003bdd50)(__VA_ARGS__)
#define FUN_003bdd60(...) ((void (*)(...))FUN_003bdd60)(__VA_ARGS__)
#define FUN_003bdd90(...) ((u32 (*)(...))FUN_003bdd90)(__VA_ARGS__)
#define FUN_003bddd0(...) ((u32 (*)(...))FUN_003bddd0)(__VA_ARGS__)
#define FUN_003bdde0(...) ((void (*)(...))FUN_003bdde0)(__VA_ARGS__)
#define FUN_003bded0(...) ((u32 (*)(...))FUN_003bded0)(__VA_ARGS__)
#define FUN_003bdfc0(...) ((u8 (*)(...))FUN_003bdfc0)(__VA_ARGS__)
#define FUN_003be020(...) ((u32 (*)(...))FUN_003be020)(__VA_ARGS__)
#define FUN_003be1a0(...) ((u8 (*)(...))FUN_003be1a0)(__VA_ARGS__)
#define FUN_003be1c0(...) ((u32 (*)(...))FUN_003be1c0)(__VA_ARGS__)
#define FUN_003be2a0(...) ((u32 (*)(...))FUN_003be2a0)(__VA_ARGS__)
#define FUN_003be8e0(...) ((u32 (*)(...))FUN_003be8e0)(__VA_ARGS__)
#define FUN_003bea20(...) ((u8 (*)(...))FUN_003bea20)(__VA_ARGS__)
#define FUN_003beab0(...) ((u32 (*)(...))FUN_003beab0)(__VA_ARGS__)
#define FUN_003beb10(...) ((int (*)(...))FUN_003beb10)(__VA_ARGS__)
#define FUN_003beb70(...) ((void (*)(...))FUN_003beb70)(__VA_ARGS__)
#define FUN_003bebd0(...) ((u8 (*)(...))FUN_003bebd0)(__VA_ARGS__)
#define FUN_003bec50(...) ((void (*)(...))FUN_003bec50)(__VA_ARGS__)
#define FUN_003beca0(...) ((int (*)(...))FUN_003beca0)(__VA_ARGS__)
#define FUN_003bee80(...) ((u8 * (*)(...))FUN_003bee80)(__VA_ARGS__)
#define FUN_003bf130(...) ((u32 (*)(...))FUN_003bf130)(__VA_ARGS__)
#define FUN_003bf180(...) ((void (*)(...))FUN_003bf180)(__VA_ARGS__)
#define FUN_003bf200(...) ((u32 (*)(...))FUN_003bf200)(__VA_ARGS__)
#define FUN_003bf270(...) ((u32 (*)(...))FUN_003bf270)(__VA_ARGS__)
#define FUN_003bf370(...) ((u32 (*)(...))FUN_003bf370)(__VA_ARGS__)
#define FUN_003bf510(...) ((u32 (*)(...))FUN_003bf510)(__VA_ARGS__)
#define FUN_003bf610(...) ((u32 (*)(...))FUN_003bf610)(__VA_ARGS__)

#undef FUN_003bdbd0
#define FUN_003bdbd0(...) ((void (*)(...))FUN_003bdbd0)(__VA_ARGS__)
#undef FUN_003bdd40
#define FUN_003bdd40(...) ((u32 * (*)(...))FUN_003bdd40)(__VA_ARGS__)
#undef FUN_003bdd50
#define FUN_003bdd50(...) ((u32 * (*)(...))FUN_003bdd50)(__VA_ARGS__)
#undef FUN_003bdd60
#define FUN_003bdd60(...) ((void (*)(...))FUN_003bdd60)(__VA_ARGS__)
#undef FUN_003bdd90
#define FUN_003bdd90(...) ((u32 (*)(...))FUN_003bdd90)(__VA_ARGS__)
#undef FUN_003bddd0
#define FUN_003bddd0(...) ((u32 (*)(...))FUN_003bddd0)(__VA_ARGS__)
#undef FUN_003bdde0
#define FUN_003bdde0(...) ((void (*)(...))FUN_003bdde0)(__VA_ARGS__)
#undef FUN_003bded0
#define FUN_003bded0(...) ((u32 (*)(...))FUN_003bded0)(__VA_ARGS__)
#undef FUN_003bdfc0
#define FUN_003bdfc0(...) ((u8 (*)(...))FUN_003bdfc0)(__VA_ARGS__)
#undef FUN_003be020
#define FUN_003be020(...) ((u32 (*)(...))FUN_003be020)(__VA_ARGS__)
#undef FUN_003be1a0
#define FUN_003be1a0(...) ((u8 (*)(...))FUN_003be1a0)(__VA_ARGS__)
#undef FUN_003be1c0
#define FUN_003be1c0(...) ((u32 (*)(...))FUN_003be1c0)(__VA_ARGS__)
#undef FUN_003be2a0
#define FUN_003be2a0(...) ((u32 (*)(...))FUN_003be2a0)(__VA_ARGS__)
#undef FUN_003be8e0
#define FUN_003be8e0(...) ((u32 (*)(...))FUN_003be8e0)(__VA_ARGS__)
#undef FUN_003bea20
#define FUN_003bea20(...) ((u8 (*)(...))FUN_003bea20)(__VA_ARGS__)
#undef FUN_003beab0

#define FUN_003beab0(...) ((u32 (*)(...))FUN_003beab0)(__VA_ARGS__)
#undef FUN_003beb10
#define FUN_003beb10(...) ((int (*)(...))FUN_003beb10)(__VA_ARGS__)
#undef FUN_003beb70
#define FUN_003beb70(...) ((void (*)(...))FUN_003beb70)(__VA_ARGS__)
#undef FUN_003bebd0
#define FUN_003bebd0(...) ((u8 (*)(...))FUN_003bebd0)(__VA_ARGS__)
#undef FUN_003bec50
#define FUN_003bec50(...) ((void (*)(...))FUN_003bec50)(__VA_ARGS__)
#undef FUN_003beca0
#define FUN_003beca0(...) ((int (*)(...))FUN_003beca0)(__VA_ARGS__)
#undef FUN_003bee80
#define FUN_003bee80(...) ((u8 * (*)(...))FUN_003bee80)(__VA_ARGS__)
#undef FUN_003bf130
#define FUN_003bf130(...) ((u32 (*)(...))FUN_003bf130)(__VA_ARGS__)
#undef FUN_003bf180
#define FUN_003bf180(...) ((void (*)(...))FUN_003bf180)(__VA_ARGS__)
#undef FUN_003bf200
#define FUN_003bf200(...) ((u32 (*)(...))FUN_003bf200)(__VA_ARGS__)
#undef FUN_003bf270
#define FUN_003bf270(...) ((u32 (*)(...))FUN_003bf270)(__VA_ARGS__)
#undef FUN_003bf370
#define FUN_003bf370(...) ((u32 (*)(...))FUN_003bf370)(__VA_ARGS__)
#undef FUN_003bf510
#define FUN_003bf510(...) ((u32 (*)(...))FUN_003bf510)(__VA_ARGS__)
#undef FUN_003bf610
#define FUN_003bf610(...) ((u32 (*)(...))FUN_003bf610)(__VA_ARGS__)
