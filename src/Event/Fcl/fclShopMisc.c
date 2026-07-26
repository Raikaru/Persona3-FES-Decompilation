#include "Kernel/Kwln/kwlnTask.h"
typedef struct FclShopDispatchResult {
  u32 value;
  u32 value_aux;
  s16 field08;
  s16 field0a;
  s16 field0c;
  s16 field0e;
  s16 field10;
  s16 field12;
  s16 field14;
  s16 field16;
  s16 field18;
  u16 field1a;
} FclShopDispatchResult;

typedef struct FclShopDispatchSource {
  FclShopDispatchResult alternate[18];
  u8 pad1f8[8];
  FclShopDispatchResult primary[18];
  u8 pad3f8[8];
} FclShopDispatchSource;

typedef struct FclShopDispatchOutput {
  FclShopDispatchResult result;
  u8 pad1c[4];
} FclShopDispatchOutput;

typedef struct FclShopDispatchStack {
  FclShopDispatchSource source[8];
  FclShopDispatchOutput output[16];
} FclShopDispatchStack;
typedef struct FclShopDispatchRegion {
  FclShopDispatchResult result[18];
  u8 pad[0x118];
} FclShopDispatchRegion;

typedef struct FclShopDispatchStorage {
  FclShopDispatchResult tail0;
  u8 tail_gap[0x2f4];
  FclShopDispatchResult tail1;
  u8 tail_path_gap[0x2f4];
  FclShopDispatchRegion path[28];
  FclShopDispatchOutput output[30];
} FclShopDispatchStorage;

extern u32 D_006AF3E0[];
extern u32 FUN_003dffc0();
extern u32 fclCombineList003df100();

#define FCL_SHOP_DISPATCH_BUILD(SRC, OUT, OWNER, ID, COPY_OFFSET) do { \
  u32 *copy_src = D_006AF3E0; \
  u32 *copy_dst = (u32 *)(SRC); \
  int copy_count = 0x3f; \
  u32 copy_value0; \
  u32 copy_value1; \
  do { \
    copy_value0 = copy_src[0]; \
    copy_value1 = copy_src[1]; \
    copy_src += 2; \
    copy_count = copy_count - 1; \
    copy_dst[0] = copy_value0; \
    copy_dst[1] = copy_value1; \
    copy_dst += 2; \
  } while (copy_count > 0); \
  (SRC)[0].value = (ID); \
  (SRC)[0].field18 = 0; \
  (SRC)[1].value = (ID); \
  (SRC)[1].field18 = 0; \
  (SRC)[2].value = (ID); \
  (SRC)[2].field18 = 0; \
  (SRC)[3].value = (ID); \
  (SRC)[3].field18 = 0; \
  (SRC)[4].value = (ID); \
  (SRC)[4].field18 = 0; \
  (SRC)[5].value = (ID); \
  (SRC)[5].field18 = 0; \
  (SRC)[6].value = (ID); \
  (SRC)[6].field18 = 0; \
  (SRC)[7].value = (ID); \
  (SRC)[7].field18 = 0; \
  (SRC)[8].value = (ID); \
  (SRC)[8].field18 = 0; \
  (SRC)[9].value = (ID); \
  (SRC)[9].field18 = 0; \
  (SRC)[10].value = (ID); \
  (SRC)[10].field18 = 0; \
  (SRC)[11].value = (ID); \
  (SRC)[11].field18 = 0; \
  (SRC)[12].value = (ID); \
  (SRC)[12].field18 = 0; \
  (SRC)[13].value = (ID); \
  (SRC)[13].field18 = 0; \
  (SRC)[14].value = (ID); \
  (SRC)[14].field18 = 0; \
  (SRC)[15].value = (ID); \
  (SRC)[15].field18 = 0; \
  (SRC)[16].value = (ID); \
  (SRC)[16].field18 = 0; \
  (SRC)[17].value = (ID); \
  (SRC)[17].field18 = 0; \
  memcpy((OUT), (SRC) + (COPY_OFFSET), 0x1c); \
  fclCombineList003df100( \
      FUN_003dffc0((OWNER), (ID), *((volatile u32 *)((u8 *)(OUT) + 4))), \
      (OUT)); \
} while (0)
#define FCL_SHOP_MISC_BUILD(SRC, OUT, OWNER, ID, VALUE, FIELD, COPY_OFFSET) do { \
    u32 *copy_src = D_006AF3E0; \
    u32 *copy_dst = (u32 *)(SRC); \
    int copy_count = 0x62; \
    u32 copy_value0; \
    u32 copy_value1; \
    do { \
        copy_value0 = *copy_src++; \
        copy_value1 = *copy_src++; \
        copy_count--; \
        copy_dst[0] = copy_value0; \
        copy_dst[1] = copy_value1; \
        copy_dst += 2; \
    } while (copy_count > 0); \
    (SRC)[0].value = (VALUE); (SRC)[0].field18 = (FIELD); \
    (SRC)[1].value = (VALUE); (SRC)[1].field18 = (FIELD); \
    (SRC)[2].value = (VALUE); (SRC)[2].field18 = (FIELD); \
    (SRC)[3].value = (VALUE); (SRC)[3].field18 = (FIELD); \
    (SRC)[4].value = (VALUE); (SRC)[4].field18 = (FIELD); \
    (SRC)[5].value = (VALUE); (SRC)[5].field18 = (FIELD); \
    (SRC)[6].value = (VALUE); (SRC)[6].field18 = (FIELD); \
    (SRC)[7].value = (VALUE); (SRC)[7].field18 = (FIELD); \
    (SRC)[8].value = (VALUE); (SRC)[8].field18 = (FIELD); \
    (SRC)[9].value = (VALUE); (SRC)[9].field18 = (FIELD); \
    (SRC)[10].value = (VALUE); (SRC)[10].field18 = (FIELD); \
    (SRC)[11].value = (VALUE); (SRC)[11].field18 = (FIELD); \
    (SRC)[12].value = (VALUE); (SRC)[12].field18 = (FIELD); \
    (SRC)[13].value = (VALUE); (SRC)[13].field18 = (FIELD); \
    (SRC)[14].value = (VALUE); (SRC)[14].field18 = (FIELD); \
    (SRC)[15].value = (VALUE); (SRC)[15].field18 = (FIELD); \
    (SRC)[16].value = (VALUE); (SRC)[16].field18 = (FIELD); \
    (SRC)[17].value = (VALUE); (SRC)[17].field18 = (FIELD); \
    (SRC)[18].value = (VALUE); (SRC)[18].field18 = (FIELD); \
    (SRC)[19].value = (VALUE); (SRC)[19].field18 = (FIELD); \
    (SRC)[20].value = (VALUE); (SRC)[20].field18 = (FIELD); \
    (SRC)[21].value = (VALUE); (SRC)[21].field18 = (FIELD); \
    (SRC)[22].value = (VALUE); (SRC)[22].field18 = (FIELD); \
    (SRC)[23].value = (VALUE); (SRC)[23].field18 = (FIELD); \
    (SRC)[24].value = (VALUE); (SRC)[24].field18 = (FIELD); \
    (SRC)[25].value = (VALUE); (SRC)[25].field18 = (FIELD); \
    (SRC)[26].value = (VALUE); (SRC)[26].field18 = (FIELD); \
    (SRC)[27].value = (VALUE); (SRC)[27].field18 = (FIELD); \
    memcpy((OUT), (SRC) + (COPY_OFFSET), 0x1c); \
    fclCombineList003df100( \
        FUN_003dffc0((OWNER), (ID), \
            *((volatile u32 *)((u8 *)(OUT) + 4))), (OUT)); \
} while (0)
#define FCL_SHOP_MISC_AT(OFFSET) \
    ((volatile FclShopDispatchResult *)((u8 *)source + (OFFSET)))
u32 datSocialLinkLevelIsNotZero(s16 socialLink);
u64 FUN_00172660(s32 socialLink);
extern u8 DAT_006aede8[];
extern u32 gp0xffffac10;
extern u32 gp0xfffface0;
typedef int (*code)();
float fGpffff8084;
float fGpffff808c;
float fGpffff8090;
float fGpffff8110;
float fGpffff8230;
float fGpffff8234;
float fGpffff8238;
float fGpffff823c;
int *iGpffffabf8;
int iGpffffabfc;
int iGpffffac00;
int *iGpffffb730;
int *iGpffffb7f4;
int iGpffffb7f8;
extern u8 *pbGpffffabe8;
short *psGpffffabd0;
short *psGpffffabf0;
u32 *puGpffffabe0;
u32 uGpffffabd4;
u32 uGpffffabe4;
extern u32 uGpffffabec;
u32 uGpffffabf4;
float fGpffffacf0;
float fGpffffacf4;
float fGpffffacf8;
float fGpffffacfc;
float fGpffffad00;
float fGpffffad04;
u32 uGpffffb9a8;
/* FUSION_EXACT_PROTOS */
void FUN_003c45f0(int param_1);
u32 datGetScenarioMode(void);
u16 FUN_001752b0(void);
void FUN_003c9e30(u32 param_1,int param_2,s8 param_3);
f32 func_00171510(s16 row, s16 column);
void FUN_003eff00(u64 param_1,u8 *param_2);
u8 * FUN_003efff0(int param_1);
#pragma alias FUN_003efff0_u64 FUN_003efff0
u8 * FUN_003efff0_u64(u64 param_1);
s16 FUN_003f0090(int param_1);
s16 FUN_003f00b0(int param_1);
int FUN_003f00d0(int *param_1,u64 param_2,int *param_3);
 #pragma alias FUN_003f00d0_i FUN_003f00d0
 int *FUN_003f00d0_i(int *param_1,int param_2,int *param_3);
 #pragma alias FUN_003f25e0_i FUN_003f25e0
 u32 FUN_003f25e0_i(u32 param_1,int *param_2,u32 param_3);
 #pragma alias FUN_003f2940_i FUN_003f2940
 u32 FUN_003f2940_i(u32 param_1,short *param_2,int param_3,u32 param_4);
 #pragma alias FUN_003f2320_i FUN_003f2320
 u32 FUN_003f2320_i(u32 param_1,int *param_2);
void FUN_003f01d0(int param_1,int param_2,int *param_3);
u32 FUN_003f0240(int param_1);
int FUN_003f0350(int param_1,int *param_2);
char FUN_003f03e0(int param_1);
#pragma alias FUN_003f03e0_u64 FUN_003f03e0
char FUN_003f03e0_u64(u64 param_1);
u32 FUN_003f04f0(u32 param_1,int param_2);
u32 * FUN_003f06e0(int *param_1,u32 param_2);
short FUN_003f0830(int param_1);
short FUN_003f0ac0(int param_1);
long FUN_003f0d60(int param_1,u64 param_2);
u32 FUN_003f0ec0(u64 param_1);
u16 FUN_003f10b0(int param_1,u16 param_2);
u16 FUN_003f12a0(int param_1,int param_2);
u64 FUN_003f1470(int param_1);
void FUN_003f1520(int param_1);
int FUN_003f15d0(int param_1,int param_2);
int FUN_003f1690(u64 param_1);
int clndIsDateInRangeFromStart(s8 month, s8 day, u32 range);
#pragma alias clndIsDateInRangeFromStart_long clndIsDateInRangeFromStart
int clndIsDateInRangeFromStart_long(long month,long day,u32 range);
#pragma alias clndIsDateInRange_long clndIsDateInRange
int clndIsDateInRange_long(long startMonth,long startDay,long endMonth,long endDay);
void FUN_0017c220(u16 *param_1);
u16 FUN_003f1720(u32 param_1,u16 param_2);
u32 FUN_003f1830(short *param_1,short param_2);
u32 FUN_003f1910(u64 param_1);
u32 FUN_003f1a10(u32 param_1);
void FUN_003f1ba0(long param_1,u32 param_2);
u32 FUN_003f1dc0(u16 param_1,long param_2,long param_3);
u8 FUN_003f2240(long param_1,u16 param_2);
u64 FUN_003f2320(int param_1,int param_2);
u32 FUN_003f2510(void);
u32 FUN_003f25e0(u64 param_1,long param_2,u32 param_3);
u32 FUN_003f2940(u64 param_1,short *param_2,int param_3,u32 param_4);
u64 FUN_003f2d60(int param_1);
u64 FUN_003f2dc0(int param_1,int param_2);
u32 FUN_003f2f70(u32 param_1,int param_2,u32 param_3);
 #pragma alias FUN_003f33d0_i FUN_003f33d0
 u64 FUN_003f33d0_i(int param_1,u32 param_2);
 #pragma alias FUN_003f3970_i FUN_003f3970
 u32 FUN_003f3970_i(int param_1,u32 param_2);
 #pragma alias FUN_003f39a0_i FUN_003f39a0
 u32 FUN_003f39a0_i(int param_1,int param_2,u32 param_3);
 #pragma alias FUN_003f3e60_i FUN_003f3e60
 u32 FUN_003f3e60_i(u32 param_1,u32 param_2);
 #pragma alias FUN_003f3dc0_i FUN_003f3dc0
 void FUN_003f3dc0_i(int param_1,u32 param_2);
 #pragma alias FUN_003c58f0_i FUN_003c58f0
 u32 FUN_003c58f0_i(u32 param_1,int param_2,u32 param_3,u32 param_4);
 #pragma alias FUN_0019d3f0_fcl FUN_0019d3f0
 void FUN_0019d3f0_fcl(const char *param_1,int param_2);
u64 FUN_003f33d0(int param_1,u32 param_2);
u64 FUN_003f3970(long param_1,u32 param_2);
u64 FUN_003f39a0(long param_1,long param_2,u32 param_3);
void FUN_003f3dc0(int param_1,u64 param_2);
u32 FUN_003f3e60(int param_1,u64 param_2);
u32 FUN_003f3f00(u64 param_1);
void FUN_003f3fc0(int param_1,int param_2,u32 param_3,u64 param_4);
void FUN_003f4350(int param_1,int param_2,int param_3,int param_4);
void FUN_003f45e0(int param_1,int param_2,int param_3,int param_4);
void FUN_003f4870(int param_1,int param_2,long param_3,u64 param_4);
u64 FUN_003f4a90(int param_1,int param_2,int param_3,int param_4,u64 param_5,short *param_6);
void FUN_003f4de0(int param_1,int param_2,u32 param_3,int param_4);
void FUN_003f55b0(u64 param_1,u64 param_2,u32 param_3,int param_4,int param_5, u32 param_6);
#pragma alias FUN_003f55b0_i FUN_003f55b0
void FUN_003f55b0_i(int,int,int,int,int,int);
void FUN_003f5830(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5, u32 param_6);
void FUN_003f5ab0(u64 param_1,u64 param_2,u8 param_3,u64 param_4, int param_5);
void FUN_003f5d10(u64 param_1,u64 param_2,u8 param_3,u64 param_4, int param_5);
void FUN_003f5f50(u64 param_1,u64 param_2,u8 param_3,u64 param_4, int param_5);
void FUN_003f61d0(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5);
void FUN_003f67e0(u64 param_1,u64 param_2,u32 param_3,int param_4,u64 param_5, int param_6);
void FUN_003f6f20(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5);
void FUN_003f7390(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5);
void FUN_003f7730(u64 param_1,u64 param_2,u8 param_3,int param_4,int param_5);
void FUN_003f7890(u64 param_1,u64 param_2,u8 param_3,int param_4, u64 param_5,int param_6);
void FUN_003f7a80(u64 param_1,u64 param_2,u32 param_3,int param_4,int param_5);
void FUN_003f7c60(u32 param_1,u32 param_2,u32 param_3,int param_4,int param_5);
void FUN_003f7d50(int param_1,int param_2,u64 param_3,int param_4, int param_5);
void FUN_003f7fe0(u64 param_1,u64 param_2,u32 param_3,int param_4,int param_5 );
void FUN_003f8180(int param_1,int param_2,u32 param_3,int param_4,int param_5 );
void FUN_003f85a0(int param_1,int param_2,u64 param_3,int param_4, int param_5);
void FUN_003f86a0(int param_1,int param_2,u32 param_3,int param_4,int param_5 );
void FUN_003f8a00(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5 );
void FUN_003f8e10(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5 );
void FUN_003f9220(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5 );
void FUN_003f9510(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5 );
u32 FUN_003f98f0(u16 param_1);
u64 FUN_003f99d0(u64 param_1,u32 param_2);
u64 FUN_003f9b20(u64 param_1,int param_2);
s32 FUN_003f9cb0(u32 *param_1, u32 *param_2);
u32 FUN_003f9e30(int param_1);
u32 FUN_003fa0d0(u64 param_1);
u64 FUN_003fa190(int param_1);
u64 FUN_003fa1b0(int param_1);
u8 FUN_003fa1e0(void);
#pragma alias FUN_003fa1e0_u32 FUN_003fa1e0
u32 FUN_003fa1e0_u32(void);
void FUN_003fa210(int param_1);
void FUN_003fa520(int param_1);
void FUN_003fa800(int param_1);
void FUN_003faae0(int param_1);
void FUN_003fadc0(int param_1);
void FUN_003fb0c0(long param_1,long param_2);
int FUN_003fb2f0(u32 *param_1);
int FUN_003fb530(u32 *param_1);
int FUN_003fb6b0(u64 param_1);
u64 FUN_003fbc00(u32 *param_1);
void FUN_003fbe70(u8 *param_1,u8 *param_2);
void FUN_003fbf10(u16 *param_1);
u64 FUN_003fbf20(short *param_1);
u64 FUN_003fc060(int param_1);
#pragma alias FUN_003fc060_u32 FUN_003fc060
u32 FUN_003fc060_u32(int param_1);
#pragma alias FUN_003fc540_u32 FUN_003fc540
u32 FUN_003fc540_u32(int param_1);
u64 FUN_003fc540(int param_1);
u32 FUN_003fc980(int param_1);
void FUN_003fca00(u64 param_1,u64 param_2,u32 param_3);
void FUN_003fcad0(u64 param_1,u64 param_2,u32 param_3,int param_4);
void FUN_003fcbe0(u64 param_1,u64 param_2,u32 param_3,int param_4,int param_5);
void FUN_003fcdc0(int param_1,int param_2,u32 param_3,int param_4,int param_5);
void FUN_003fd010(int param_1,int param_2,u32 param_3,int param_4,int param_5);
void FUN_003fd030(u64 param_1,u64 param_2,u32 param_3,int param_4);
void FUN_003fd140(u64 param_1,u64 param_2,u32 param_3,int param_4,int param_5);
void FUN_003fd320(int param_1,int param_2,u32 param_3,int param_4,int param_5);
u64 FUN_003fd570(int param_1,u32 *param_2);
u64 FUN_003fd730(u64 param_1,int param_2);
u64 FUN_003fd7e0(u64 param_1,int param_2);
int * FUN_003fd820(int param_1);
void FUN_003fd8a0(u32 *param_1);
void FUN_003fd8e0(int *param_1);
u64 FUN_003fd990(int *param_1);
void FUN_003fdcc0(int param_1,int param_2,int *param_3);
u64 FUN_003fdf80(u32 *param_1);
u32 FUN_003fe020(int param_1,u64 param_2);
u32 FUN_003fe1f0(u64 param_1);
u32 FUN_003fe2b0(void);
u64 FUN_003fe3e0(u16 param_1);
u32 FUN_003fe5d0(u64 param_1);
u64 FUN_003fe690(u64 param_1,u64 param_2);
#pragma alias FUN_003fe690_p FUN_003fe690
u64 FUN_003fe690_p(u32 param_1,u64 param_2,int param_3);
#pragma alias FUN_003fe690_3 FUN_003fe690
u64 FUN_003fe690_3(u64 param_1,u64 param_2,int param_3);
#pragma alias FUN_003c5e80_p FUN_003c5e80
void FUN_003c5e80_p(u32 param_1,code param_2);
#pragma alias FUN_003c5e20_p FUN_003c5e20
void FUN_003c5e20_p(u32 param_1,code param_2);
#pragma alias FUN_003c5ee0_p FUN_003c5ee0
void FUN_003c5ee0_p(u32 param_1,code param_2);
u64 FUN_003fe7d0(u64 param_1,int param_2);
u32 FUN_003fe850(u16 param_1,u64 param_2);
u32 FUN_003fe950(u64 param_1);
u64 FUN_003fea10(u64 param_1,u32 *param_2);
u64 FUN_003feb30(u64 param_1,int param_2);
u64 FUN_003fee40(int param_1);
u32 FUN_003fef30(u64 param_1,long param_2);
u64 FUN_003ff150(u64 param_1,long param_2);
void FUN_003ff460(int param_1,u64 param_2);
u32 FUN_003ff570(u64 param_1);
void FUN_003ff630(u32 param_1,u64 param_2,u64 param_3,u64 param_4, u8 param_5,short param_6,short param_7,u32 param_8);
u8 FUN_003ffa20(u64 param_1,u64 param_2,int param_3);
#pragma alias FUN_003ffa20_3 FUN_003ffa20
int FUN_003ffa20_3(u64 param_1,u64 param_2,short *param_3);
void FUN_003ffbb0(int param_1,int param_2);
void FUN_003ffe00(int param_1);
int * FUN_003ffe60(u64 param_1);
void FUN_004003a0(int param_1);
u32 FUN_004003f0(int *param_1);
u64 FUN_00400690(u32 *param_1);
void FUN_004006c0(int param_1,int param_2,int param_3,int param_4);
void FUN_00400740(u64 param_1,u64 param_2,u8 param_3,int param_4);
void FUN_004008f0(u64 param_1,u64 param_2,u8 param_3,int param_4);
void FUN_00400a90(int param_1,u64 param_2,int param_3,int param_4,u32 *param_5);
void FUN_00400e30(int param_1);
int FUN_00400d60(void);
u32 FUN_00401210(int param_1);
void FUN_00401170(u64 param_1);
u64 FUN_004012c0(int param_1);
u64 FUN_00401370(int param_1);
void FUN_00401420(int param_1,int param_2);
u32 FUN_004014e0(u64 param_1);
void FUN_004015a0(u32 *param_1,u32 param_2);
u8 FUN_004015e0(u32 *param_1);
int FUN_00401600(u64 param_1,u64 param_2,int param_3);
u32 FUN_004016d0(u32 param_1);
int FUN_00401800(short param_1);
u32 FUN_00401890(short param_1);
u64 FUN_00401950(short param_1);
u32 FUN_00401a00(u16 param_1,long param_2,short *param_3);
u8 * FUN_00401c90(u32 *param_1,int param_2);
u8 * FUN_00401cf0(int param_1);
short * FUN_00401d90(int param_1);
u32 FUN_00401de0(u64 param_1,long param_2,long param_3);
void FUN_00402400(int param_1,u16 *param_2);
u32 FUN_00402480(u16 *param_1);
u32 FUN_00402510(u32 param_1,long param_2,u32 param_3,short param_4);
u32 FUN_004026b0(int param_1,int param_2,u32 param_3);
void FUN_00402800(u64 param_1);
void FUN_00402c80(u64 param_1);
s16 FUN_004030b0(u16 param_1);
s16 FUN_004030f0(u16 param_1);
void FUN_00403130(u64 param_1,u64 param_2,int param_3,u64 param_4, u64 param_5,u64 param_6,u16 param_7);
void FUN_00403220(u64 param_1,u64 param_2,int param_3,u64 param_4, u64 param_5,u64 param_6,u16 param_7);
void FUN_004032f0(u64 param_1);
void FUN_00403340(u16 param_1);
u8 FUN_00403380(u64 param_1);
u8 FUN_00403410(void);
u32 FUN_00403520(void);
int FUN_00403610(void);
s16 FUN_00403740(short param_1);
s16 FUN_00403760(short param_1);
s16 FUN_00403780(short param_1);
s16 FUN_004037a0(short param_1);
s16 FUN_004037c0(short param_1);
int FUN_004037e0(short param_1);
long FUN_00403800(short param_1);
long FUN_00403830(short param_1);
int FUN_00403860(short param_1);
int FUN_00403880(short param_1);
u32 FUN_004038a0(short param_1);
u32 FUN_004038e0(short param_1);
s16 FUN_00403900(short param_1);
u32 FUN_00403920(short param_1,short param_2);
u32 FUN_00403970(short param_1);
u32 FUN_00403e40(int param_1,int param_2);
u32 FUN_00403f20(short param_1,long param_2);
u32 FUN_00404120(short param_1,long param_2);
void FUN_00404470(short param_1);
#pragma alias FUN_00404470_alt FUN_00404470
void FUN_00404470_alt(short param_1,int param_2);
void FUN_004044c0(short param_1);
void FUN_004045d0(u64 param_1);
void FUN_00404750(u32 param_1,u32 param_2,u32 param_3);
u64 FUN_00405970(u64 param_1,int param_2);
void FUN_00405a90(u64 param_1,int param_2);
u64 FUN_00405ac0(u64 param_1,long param_2);
void FUN_00405d60(int param_1);
void FUN_00405e00(u64 param_1);
extern int FUN_00405db0(u32* param_1, u32* param_2);
u8 FUN_00405e30(u64 param_1);
void FUN_00405f70(u64 param_1,u64 param_2,u32 param_3,int param_4,u64 param_5, int param_6,int param_7);
void FUN_004064e0(u64 param_1,u64 param_2,u32 param_3,int param_4);
void FUN_00406aa0(u64 param_1,u64 param_2,u32 param_3);
void FUN_00406ca0(u64 param_1,u64 param_2,int *param_3);
void FUN_00407180(u32 param_1,u32 param_2,u16 param_3,int param_4);
void FUN_00407210(u32 param_1,u32 param_2,u16 param_3,int param_4,int param_5);
void FUN_004072d0(int param_1,long param_2,long param_3);
 #pragma alias FUN_004072d0_i FUN_004072d0
 void FUN_004072d0_i(u32 param_1,int param_2,int param_3);
u64 FUN_00409c80(u64 param_1);
 #pragma alias FUN_00409c80_i FUN_00409c80
 u32 FUN_00409c80_i(u32 param_1);
u32 FUN_00409e90(void);
void FUN_00409f20(u64 param_1,int param_2);
u32 FUN_00409f50(u32 param_1,int param_2);
void FUN_0040a200(int param_1);
void FUN_0040a260(int param_1);
u8 FUN_0040a2b0(u64 param_1);
u32 FUN_0040a490(u32 param_1);
void FUN_0040a6d0(u64 param_1,long param_2);
 #pragma alias FUN_0040a6d0_i FUN_0040a6d0
 void FUN_0040a6d0_i(u32 param_1,int param_2);
 #pragma alias FUN_00174a90_fcl FUN_00174a90
 u32 FUN_00174a90_fcl(short param_1);
void FUN_0040a7c0(u64 param_1,u64 param_2,u8 param_3);
void FUN_0040a7f0(u64 param_1,int param_2,int *param_3);
void FUN_0040b3a0(u64 param_1,int param_2,int param_3);
void FUN_0040b630(u32 param_1,u32 param_2,u16 param_3,u64 param_4);
void FUN_0040b780(u32 param_1,u32 param_2,u16 param_3,int param_4,int param_5);
void FUN_0040b840(int param_1);
u32 FUN_0040b910(u64 param_1);
void FUN_0040c150(u32 param_1);
u32 FUN_0040c170(void);
void FUN_0040c1e0(long param_1,long param_2,long param_3);
void FUN_0040c310(int param_1);
void FUN_0040c460(u64 param_1,int param_2);
void FUN_0040c490(u64 param_1);
void FUN_0040c520(u64 param_1);
void FUN_0040c5b0(u64 param_1);
void FUN_0040c650(u64 param_1);
void FUN_0040c6a0(u64 param_1);
int FUN_0040c6f0(int param_1);
void FUN_0040c9a0(int param_1);
u32 FUN_0040ca00(int param_1);
void FUN_0040cad0(int param_1);
void FUN_0040cc30(u64 param_1,int param_2,int *param_3);
void FUN_0040d330(int param_1);
void FUN_0040d3b0(u32 param_1,u32 param_2,u16 param_3,int param_4);
u32 FUN_0040d410(void);
u32 FUN_0040d490(void);
u32 FUN_0040d540(void);
void FUN_0040d5b0(int param_1,int param_2,int param_3,int param_4,u32 param_5);
void FUN_0040d5e0(float param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6);
void FUN_0040d610(float param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6,long param_7);
void FUN_0040d640(float param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6, long param_7,long param_8);
void FUN_0040dcc0(float param_1,int param_2,int param_3,int param_4,int param_5,int param_6, u32 param_7,int param_8,long param_9);
#pragma alias datGetFlag_s32 datGetFlag
s32 datGetFlag_s32(s32 param_1);
#pragma alias datGetFlag_u32 datGetFlag
u32 datGetFlag_u32();
#pragma alias datGetFlag_u32_arg datGetFlag
u32 datGetFlag_u32_arg(int param_1);
#pragma alias datSocialLinkLevelIsNotZero_s32 datSocialLinkLevelIsNotZero
u32 datSocialLinkLevelIsNotZero_s32(s32 socialLink);
void FUN_001725a0(u64 socialLink);
#pragma alias datGetEquipmentIdx_s16 datGetEquipmentIdx
s16 datGetEquipmentIdx_s16(s16 param_1,s16 param_2);
#pragma alias FUN_0017c610_u64 FUN_0017c610
s32 FUN_0017c610_u64(u64 param_1);
#pragma alias FUN_004037e0_u64 FUN_004037e0
int FUN_004037e0_u64(u64 param_1);
#pragma alias FUN_003f04f0_u32 FUN_003f04f0
u32 FUN_003f04f0_u32(u32 param_1,int param_2);
#pragma alias FUN_003f1dc0_u32 FUN_003f1dc0
u32 FUN_003f1dc0_u32(s32 param_1,void *param_2,s32 param_3);
#pragma alias FUN_003f1dc0_u64 FUN_003f1dc0
u32 FUN_003f1dc0_u64(u64 param_1,void *param_2,s32 param_3);
#pragma alias FUN_0040e3c0_f32 FUN_0040e3c0
void FUN_0040e3c0_f32(float param_1,int param_2,int param_3,u8 param_4,int param_5,int param_6);
#pragma alias FUN_0040e3c0_u32 FUN_0040e3c0
void FUN_0040e3c0_u32(float param_1,int param_2,int param_3,u32 param_4,int param_5,int param_6);
#pragma alias FUN_003c7e20_f32 FUN_003c7e20
void FUN_003c7e20_f32(f32 p1,s32 p2,s32 p3,u32 p4,s32 p5,s32 p6,s32 p7,u32 p8);
#pragma alias FUN_003c6270_u32 FUN_003c6270
u32 FUN_003c6270_u32(u32 param_1);
#pragma alias FUN_003c6ce0_u32 FUN_003c6ce0
u32 FUN_003c6ce0_u32(u32 param_1);
#pragma alias FUN_003c6d10_u32 FUN_003c6d10
u32 FUN_003c6d10_u32(u32 param_1);
#pragma alias FUN_003c6ca0_u32 FUN_003c6ca0
u32 FUN_003c6ca0_u32(u32 param_1);
#pragma alias FUN_003c6cc0_u32 FUN_003c6cc0
u32 FUN_003c6cc0_u32(u32 param_1);
#pragma alias FUN_0017c700_u32 FUN_0017c700
u32 FUN_0017c700_u32(void);
#pragma alias FUN_00175410_u32 FUN_00175410
u32 FUN_00175410_u32(void);
#pragma alias datPersonaGetHeroPersona_u32 datPersonaGetHeroPersona
u32 datPersonaGetHeroPersona_u32(s16 param_1);
#pragma alias FUN_0017ca10_u32 FUN_0017ca10
u32 FUN_0017ca10_u32(u32 param_1);
#pragma alias FUN_00173a00_u32 FUN_00173a00
u32 FUN_00173a00_u32(u32 param_1,u32 param_2);
#pragma alias FUN_00173a00_s32 FUN_00173a00
s32 FUN_00173a00_s32(u32 param_1,u32 param_2);
#pragma alias FUN_003e0680_typed FUN_003e0680
void FUN_003e0680_typed(int param_1,code param_2,void *param_3);
#pragma alias memset_typed memset
void memset_typed(void *param_1,int param_2,u32 param_3);
#pragma alias memcpy_typed memcpy
void memcpy_typed(void *param_1,const void *param_2,u32 param_3);
#pragma alias H_Maestro_00111c50_i H_Maestro_00111c50
void H_Maestro_00111c50_i(u64 param_1);
#pragma alias H_Maestro_SetAlphaMult_f32 H_Maestro_SetAlphaMult
void H_Maestro_SetAlphaMult_f32(float param_1,u64 param_2);
#pragma alias H_Maestro_RequestDraw_i H_Maestro_RequestDraw
#pragma alias FUN_003c4e70_u64 FUN_003c4e70
void FUN_003c4e70_u64(int param_1);
#pragma alias scrGetIntPara_u32 scrGetIntPara
u32 scrGetIntPara_u32(int param_1);
#pragma alias FUN_003e0700_u32 FUN_003e0700
void FUN_003e0700_u32(u32 param_1);
#pragma alias fclCombine003d02f0_i fclCombine003d02f0
void fclCombine003d02f0_i(void);
#pragma alias FUN_00175410_u32 FUN_00175410
u32 FUN_00175410_u32(void);
#pragma alias datPersonaGetHeroPersona_s16 datPersonaGetHeroPersona
u32 datPersonaGetHeroPersona_s16(s16 param_1);
#pragma alias FUN_0017ca10_u32 FUN_0017ca10
u32 FUN_0017ca10_u32(u32 param_1);


/* FUSION_GLOBALS */
u32 DAT_006ac9e8;
u32 DAT_006ad4b4;
float DAT_007cada4;
u32 DAT_007ce420;
u32 DAT_007ce4e8;
extern u8 DAT_006ac9d0[];
#pragma alias DAT_006acc60_abs DAT_006acc60
extern u8 DAT_006acc60_abs[];
u32 DAT_006acc60;
extern u8 DAT_006acc70[];
extern u8 DAT_006acc72[];
u32 DAT_006acca0;
u32 DAT_006aedc0[];
u32 DAT_006aedc4[];
u32 DAT_006aee60;
u32 DAT_006aeea0;
u32 DAT_006aeee0;
u32 DAT_006aef00;
u32 DAT_006aef30;
u32 DAT_006aef40;
u32 DAT_006aef50;
u32 DAT_006aef60;
u32 DAT_006aef98;
u32 DAT_006aefa8;
u32 DAT_006aefb8;
u32 DAT_006aefd0;
u32 DAT_006aeff0;
u32 DAT_006af000;
u32 DAT_006af004;
u32 DAT_006af008;
u32 DAT_006af010;
u32 DAT_006af0b0;
u32 DAT_006af140;
u32 DAT_006af170;
u32 DAT_006af174;
u32 DAT_006af178;
u32 DAT_006af17c;
u32 DAT_006af180;
extern u16 DAT_006af180_abs[];
#pragma alias DAT_006af180_abs DAT_006af180
u32 DAT_006af188;
u32 DAT_006af18c;
u32 DAT_006af190;
u32 DAT_006af1c0;
u32 DAT_006af240;
u32 DAT_006af270;
u32 DAT_006af290;
u32 DAT_006af2b0;
u32 DAT_006af2d0;
u32 DAT_006af300;
u32 DAT_006af320;
extern u32 DAT_006af3a0;
extern u8 DAT_006af3a0_abs[];
#pragma alias DAT_006af3a0_abs DAT_006af3a0
u32 DAT_006af5e0;
u32 DAT_006af600;
u32 DAT_006af620;
u32 DAT_006af930;
float DAT_007cad74;
float DAT_007cad78;
float DAT_007cad80;
float DAT_007cad94;
float DAT_007cae00;
float DAT_007caef0;
float DAT_007caf14;
float DAT_007caf38;
u32 DAT_007cd8f4;
u32 DAT_007cd8f8;
u32 DAT_007cd8fc;
u32 DAT_007cd908;
u32 DAT_007cd90c;
u32 DAT_007cd910;
u32 DAT_007cd918;
u32 DAT_007cd920;
u32 DAT_007cd928;
u32 DAT_007cd930;
u32 DAT_007cd932;
u32 DAT_007cd934;
u32 DAT_007cd936;
u32 DAT_007cd938;
u32 DAT_007cd940;
u32 DAT_007cd942;
u32 DAT_007cd944;
u32 DAT_007cd946;
u32 DAT_007cd948;
u32 DAT_007cd950;
u32 DAT_007cd952;
u32 DAT_007cd958;
u32 DAT_007cd95c;
u32 DAT_007cd960;
u32 DAT_007cd964;
u32 DAT_007cd968;
u32 DAT_007cd96c;
u32 DAT_007cd980;
u32 DAT_007cd988;
u32 DAT_007cd990;
u32 DAT_007cd998;
u32 DAT_007cd9a0;
u32 DAT_007cd9a8;
u32 DAT_007cd9b0;
u32 DAT_007cd9b8;
u32 DAT_007cd9c0;
u32 DAT_007cd9c8;
u32 DAT_007cd9f8;
u32 DAT_007cd9fc;
u32 DAT_007cda00;
u8 *DAT_007ce4e4;
u32 DAT_007e094e;
u32 DAT_007e0952;
u32 DAT_007e0958;
u32 DAT_007e095a;
u32 DAT_00960088;
code DAT_00960090;
code DAT_009600a0;
u32 DAT_0098967f;
u32 LAB_003eff84[];
u32 LAB_003f0748[];
u32 LAB_003f07f4[];
u32 LAB_003f23a8[];
u32 LAB_003fe35c[];
u32 LAB_003fee10[];
u32 LAB_00401910[];
u32 LAB_004019d0[];
u32 LAB_00401aa4[];
u32 LAB_00401b60[];
u32 LAB_00401bc4[];
u32 LAB_00401c48[];
u32 LAB_00401ea8[];
u32 LAB_00401fa8[];
u32 LAB_0040203c[];
u32 LAB_00402100[];
u32 LAB_0040370c[];
u32 LAB_00403b38[];
u32 LAB_00403d20[];
u32 LAB_00403ec0[];
u32 LAB_004046bc[];
u32 LAB_004062e0[];
u32 LAB_00406468[];
u32 LAB_0040c3c4[];
u32 PTR_DAT_006ac9ec[];
u32 PTR_DAT_006ac9f0[];
u32 PTR_DAT_006ad4a0[];
u32 PTR_DAT_006ad4b0[];
u32 PTR_DAT_007cd8f0[];
u32 PTR_FUN_006aee00[];
u32 PTR_FUN_006aee20[];
u32 PTR_FUN_006aee40[];
u32 PTR_FUN_006af050[];
u32 PTR_FUN_006af070[];
u32 PTR_FUN_006af090[];
u32 PTR_FUN_007cd970[];
u32 PTR_FUN_007cd974[];
u32 PTR_FUN_007cd978[];
u32 PTR_FUN_007cd97c[];
u32 PTR_LAB_007bbde0[];
u32 PTR_PTR_006ac9d4[];
u32 _DAT_006af180;
u32 _DAT_006af184;
#include "Kosaka/k_assert.h"
// FUN_003fb290
void fclShopMisc003fb290(void* param_1, void* param_2)
{
    K_ASSERT(param_1 != NULL, 0x1018);
    memcpy((int)param_1 + 0xc, param_2, 0x1c);
}

// HARVESTED 3D-42FF

// FUN_003EFF00


void FUN_003eff00(u64 param_1,u8 *param_2)
{
  u8 *puVar1;
  u8 *puVar2;
  u32 uStack_20[4];
  int iVar1;
  int iStack_4;

  asm volatile("" : "+m"(uStack_20));
  puVar1 = FUN_003efff0_u64(param_1);
  iStack_4 = 0;
  while ((puVar2 = (u8 *)FUN_003f0350((int)puVar1,&iStack_4)) != 0) {
    iVar1 = *(int *)puVar2;
    if ((datGetLevel(1) & 0xff) < iVar1) {
      iStack_4 = iStack_4 - 1;
      break;
    }
  }
  *param_2 = (u8)iStack_4;
  param_2[1] = (u8)FUN_003f03e0_u64(param_1);
  *(u16 *)(param_2 + 2) = (u16)FUN_003f2510();
  iStack_4 = 0;
  FUN_003f01d0((int)puVar1,0,&iStack_4);
  *(u32 *)(param_2 + 4) = (u32)iStack_4;
}

// FUN_003EFFF0


u8 * FUN_003efff0(int param_1)



{

  u32 lVar1;

  int iVar2;

  

  if ((param_1 < 0) || !(param_1 < 9)) {

    K_Assert((const char *)(DAT_006aede8 + 1) - 1,0xb9);

  }

  lVar1 = datGetScenarioMode();

  iVar2 = (int)param_1;

  if (lVar1 == 0) {
    return (u8 *)&DAT_006ac9d0 + iVar2 * 0x24;
  }

  return (u8 *)&DAT_006ac9d0 + (iVar2 + 9) * 0x24;


}

// FUN_003F0090
s16 FUN_003f0090(int param_1)



{

  return *(s16 *)(DAT_006acc70 + param_1 * 4);

}

// FUN_003F00B0


s16 FUN_003f00b0(int param_1)



{

  return *(s16 *)(DAT_006acc72 + param_1 * 4);

}

// FUN_003F00D0 NONMATCHING


int FUN_003f00d0(int *param_1,u64 param_2,int *param_3)



{

  short sVar1;

  u16 uVar2;

  long lVar3;

  int iVar4;

  int iVar5;

  int iStack_4;

  

  iStack_4 = 0;

  if (param_3 == (int *)0x0) {

    param_3 = &iStack_4;

  }

  iVar5 = param_1[1];

  iVar4 = *param_3;

  do {

    if (*param_1 <= iVar4) {

      *param_3 = -1;

      return 0;

    }

    sVar1 = *(short *)(iVar5 + 4);

    if ((sVar1 == 0) || (uVar2 = datGetLevel(1), sVar1 <= (short)(uVar2 & 0xff))) {


      if (lVar3 != 0) {

        *param_3 = iVar4;

        return iVar5;

      }

      iVar5 = iVar5 + 0x14;

    }

    iVar4 = iVar4 + 1;

  } while( 1 );

}

// FUN_003F01D0


void FUN_003f01d0(int param_1,int param_2,int *param_3)
{
  int *ptr = (int *)(param_1 + param_2 * 8);
  if (FUN_003f00d0(ptr,1,param_3) != 0) {
    return;
  }
  *param_3 = 0;
  FUN_003f00d0(ptr,0,param_3);
}

// FUN_003F0240
u32 FUN_003f0240(int param_1)
{
  u8 *ptr;
  int mode;
  int result;

  if ((param_1 < 0) || !(param_1 < 9)) {
    K_Assert((const char *)DAT_006aede8,0xb9);
  }

  mode = datGetScenarioMode();

  if (mode == 0) {
    ptr = (u8 *)&DAT_006ac9d0 + param_1 * 0x24;
  }
  else {
    ptr = (u8 *)&DAT_006ac9d0 + (param_1 + 9) * 0x24;
  }
  if (param_1 == 2) {
    goto special;
  }
  if (param_1 == 1) {
    goto special;
  }
  switch (param_1) {
    case 0:
      goto special;
    default:
      goto zero;
  }

special:
  result = FUN_003f00d0((int *)(ptr + 8),1,0);
  if (result == 0) {
    result = FUN_003f00d0((int *)(ptr + 8),0,0);
  }
  if (result == 0) {
    goto zero;
  }

one:
  return 1;

zero:
  return 0;
}

// FUN_003F0350


int FUN_003f0350(int param_1,int *param_2)
{
  int iVar1;

  if (param_2 == 0) {
    K_Assert((const char *)DAT_006aede8,0x13b);
  }

  iVar1 = *param_2;
  if (iVar1 >= *(int *)(param_1 + 0x18)) {
    return 0;
  }

  *param_2 = iVar1 + 1;
  return *(int *)(param_1 + 0x1c) + iVar1 * 0xc;
}

// FUN_003F03E0 NONMATCHING


char FUN_003f03e0(int param_1)



{

  char cVar1;

  long lVar2;

  short sVar3;

  

  if (param_1 == 8) {

    sVar3 = 2;

  }

  else if (param_1 == 4) {

    sVar3 = 3;

  }

  else {

    if (param_1 != 0) {

      return '\0';

    }

    sVar3 = 0xf;

  }

  if (sVar3 == 0xff) {

    cVar1 = '\0';

  }

  else {

    lVar2 = datSocialLinkLevelIsNotZero(sVar3);

    if (lVar2 == 0) {

      cVar1 = '\0';

    }

    else {

      cVar1 = datGetSocialLinkLevel(sVar3);

      if (cVar1 == '\0') {

        cVar1 = '\0';

      }

      else if ((cVar1 < '\x01') || ('\n' < cVar1)) {

        K_Assert((const char *)(u32)0x6aede8,0x15c);

      }

    }

  }

  return cVar1;

}

/* Reconstructed the packed shop-date availability gate and all date-mode paths. */
// FUN_003F04F0 NONMATCHING


u32 FUN_003f04f0(u32 param_1,int param_2)
{
  u32 uVar2;
  int bVar1;
  long lVar4;
  int iVar5;
  u32 uVar3;
  short *psVar5;

  if (param_1 == 0) {
    K_Assert((const char *)(u32)0x6aede8,0x16c);
  }

  uVar2 = clndGetCurrentWeekDay();
  psVar5 = (short *)param_1;
  bVar1 = 1;
  if (((u32)*psVar5 & (1u << (uVar2 & 0x1f))) == 0) {
    uVar3 = 0;
  }
  else {
    if ((psVar5[1] != 0) && (datGetFlag() == 0)) {
      bVar1 = 0;
    }
    if (bVar1) {
      if (psVar5[2] == 0) {
        uVar3 = (u32)(param_2 != 1);
      }
      else if (param_2 == 2) {
        uVar3 = clndIsDateInRangeFromStart_long(
            ((long)psVar5[2] << 0x34) >> 0x3a,
            ((long)*(s8 *)((int)psVar5 + 4) << 0x3a) >> 0x3a,0x16d);
      }
      else {
        if (((long)*(char *)((int)psVar5 + 5) << 0x38) >> 0x3c != 1) {
          K_Assert((const char *)(u32)0x6aede8,0x17f);
        }
        lVar4 = ((long)*(char *)((int)psVar5 + 7) << 0x38) >> 0x3c;
        switch (lVar4) {
        case 1:
          iVar5 = clndIsDateInRange_long(
              ((long)psVar5[2] << 0x34) >> 0x3a,
              ((long)*(s8 *)((int)psVar5 + 4) << 0x3a) >> 0x3a,
              ((long)psVar5[3] << 0x34) >> 0x3a,
              ((long)*(s8 *)((int)psVar5 + 6) << 0x3a) >> 0x3a);
          uVar3 = (u32)(iVar5 != 0);
          break;
        case 2:
          iVar5 = clndIsDateInRangeFromStart_long(
              ((long)psVar5[2] << 0x34) >> 0x3a,
              ((long)*(s8 *)((int)psVar5 + 4) << 0x3a) >> 0x3a,
              ((long)psVar5[3] << 0x34) >> 0x34);
          uVar3 = (u32)(iVar5 != 0);
          break;
        case 0:
          uVar3 = 1;
          break;
        default:
          uVar3 = 0;
          break;
        }
      }
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}

// FUN_003F06E0 NONMATCHING


u32 * FUN_003f06e0(int *param_1,u32 param_2)
{
  u8 *puVar4;
  int iVar3;
  u16 uVar1;

  puVar4 = (u8 *)param_1[1];
  iVar3 = 0;
  goto loop_test;
loop_body:
  if ((*(u32 *)puVar4 & 4) != 0) {
    if (FUN_003f03e0(FUN_003e6dc0()) != 0) {
      puVar4 += 0x18;
      goto loop_continue;
    }
  }
  if ((*(u32 *)puVar4 & 1) != 0) {
    if (FUN_003f03e0(FUN_003e6dc0()) != 0) {
      puVar4 += 0x18;
      goto loop_continue;
    }
  }
  uVar1 = *(u16 *)(puVar4 + 4);
  if ((uVar1 == 0xffff || datGetFlag(uVar1) != 0) &&
      FUN_003f04f0((u32)(puVar4 + 0x10),param_2) != 0) {
    uVar1 = *(u16 *)(puVar4 + 4);
    if (uVar1 == 0xffff) {
      return (u32 *)puVar4;
    }
    if ((*(u32 *)puVar4 & 2) == 0) {
      return (u32 *)puVar4;
    }
    datSetFlag(uVar1,0);
    return (u32 *)puVar4;
  }
loop_continue:
  puVar4 += 0x18;
  iVar3 += 1;
loop_test:
  if (iVar3 < *param_1) {
    goto loop_body;
  }
  return (u32 *)0;
}

// FUN_003F0830 NONMATCHING


short FUN_003f0830(int param_1)



{

  u8 *puVar1;

  char cVar2;

  int iVar3;

  long lVar4;

  short sVar5;

  

  if (param_1 == 4) {

    sVar5 = 3;

  }

  else if (param_1 == 0) {

    sVar5 = 0xf;

  }

  else {

    sVar5 = 0xff;

  }

  if ((param_1 < 0) || (8 < param_1)) {

    K_Assert((const char *)(u32)0x6aede8,0xb9);

  }

  lVar4 = datGetScenarioMode();

  if (lVar4 != 0) {

    param_1 = param_1 + 9;

  }

  puVar1 = (u8 *)((u32 **)&PTR_DAT_006ac9f0)[param_1 * 9];


  if (lVar4 == 0) {

    if (sVar5 != 0xff) {

      if (*(int *)(puVar1 + 8) == 0) {

        K_Assert((const char *)(u32)0x6aede8,0x19c);

      }

      if (sVar5 == 0xff) {

        iVar3 = *(int *)(puVar1 + 8);

      }

      else {

        lVar4 = datSocialLinkLevelIsNotZero(sVar5);

        if (lVar4 == 0) {

          iVar3 = *(int *)(puVar1 + 8);

        }

        else {

          cVar2 = datGetSocialLinkLevel(sVar5);

          if (cVar2 == '\0') {

            iVar3 = *(int *)(puVar1 + 8);

          }

          else {

            if ((cVar2 < '\x01') || ('\n' < cVar2)) {

              K_Assert((const char *)(u32)0x6aede8,0x1a2);

            }

            iVar3 = *(int *)(puVar1 + 8) + cVar2 * 0x20;

          }

        }

      }

      if ((iVar3 != 0) && (*(short *)(iVar3 + 0xc) != -1)) {

        return *(short *)(iVar3 + 0xc);

      }

    }


    if (lVar4 != 0) {

      iVar3 = RpRandom();

      sVar5 = *(short *)(((iVar3 % 0xffff) / 0xffff) * 2 + (int)lVar4 + 8);

      if (sVar5 != -1) {

        return sVar5;

      }

    }

  }

  else {

    iVar3 = RpRandom();

    if (*(short *)(((iVar3 % 0xffff) / 0xffff) * 2 + (int)lVar4 + 8) != -1) {

      return *(short *)((int)lVar4 + 8);

    }

  }

  return -1;

}

// FUN_003F0AC0 NONMATCHING


short FUN_003f0ac0(int param_1)



{

  u8 *puVar1;

  char cVar2;

  int iVar3;

  long lVar4;

  short sVar5;

  

  if (param_1 == 4) {

    sVar5 = 3;

  }

  else if (param_1 == 0) {

    sVar5 = 0xf;

  }

  else {

    sVar5 = 0xff;

  }

  if ((param_1 < 0) || (8 < param_1)) {

    K_Assert((const char *)(u32)0x6aede8,0xb9);

  }

  lVar4 = datGetScenarioMode();

  if (lVar4 != 0) {

    param_1 = param_1 + 9;

  }

  puVar1 = (u8 *)((u32 **)&PTR_DAT_006ac9f0)[param_1 * 9];


  if (lVar4 == 0) {

    if (sVar5 != 0xff) {

      if (*(int *)(puVar1 + 8) == 0) {

        K_Assert((const char *)(u32)0x6aede8,0x19c);

      }

      if (sVar5 == 0xff) {

        iVar3 = *(int *)(puVar1 + 8);

      }

      else {

        lVar4 = datSocialLinkLevelIsNotZero(sVar5);

        if (lVar4 == 0) {

          iVar3 = *(int *)(puVar1 + 8);

        }

        else {

          cVar2 = datGetSocialLinkLevel(sVar5);

          if (cVar2 == '\0') {

            iVar3 = *(int *)(puVar1 + 8);

          }

          else {

            if ((cVar2 < '\x01') || ('\n' < cVar2)) {

              K_Assert((const char *)(u32)0x6aede8,0x1a2);

            }

            iVar3 = *(int *)(puVar1 + 8) + cVar2 * 0x20;

          }

        }

      }

      if ((iVar3 != 0) && (*(short *)(iVar3 + 0xe) != -1)) {

        return *(short *)(iVar3 + 0xe);

      }

    }


    if (lVar4 == 0) {

      return -1;

    }

    iVar3 = RpRandom();

    sVar5 = *(short *)(((iVar3 % 0xffff) / 0xffff) * 2 + (int)lVar4 + 8);

  }

  else {

    if ((*(u32 *)lVar4 & 1) != 0) {

      FUN_003e6e20(1);

    }

    iVar3 = RpRandom();

    sVar5 = *(short *)((int)(u32 *)lVar4 + ((iVar3 % 0xffff) / 0xffff) * 2 + 8);

  }

  if (sVar5 == -1) {

    return -1;

  }

  return sVar5;

}

// FUN_003F0D60 NONMATCHING


long FUN_003f0d60(int param_1,u64 param_2)
{
  int iVar1;
  long var_17;
  long var_16;
  int iStack_4;

  switch (param_1) {
  case 0:
    var_16 = 0xf;
    iVar1 = func_00170ed0(param_2,&iStack_4);
    switch (iStack_4) {
    case 0:
      var_17 = (long)*(int *)(iVar1 + 0x24);
      break;
    case 1:
      var_17 = (long)*(int *)(iVar1 + 0x1c);
      break;
    case 2:
      var_17 = (long)*(int *)(iVar1 + 0x1c);
      break;
    case 3:
      var_17 = (long)*(int *)(iVar1 + 0x20);
      break;
    case 4:
      var_17 = (long)*(int *)(iVar1 + 0x18);
      break;
    }
    break;
  case 4:
    var_16 = 3;
    var_17 = (long)(short)param_2;
    break;
  case 8:
    var_16 = 2;
    var_17 = (long)(short)param_2;
    break;
  default:
    return 0;
  }
  if (datSocialLinkLevelIsNotZero((s16)var_16) == 0) {
    return 0;
  }
  func_0016e2b0((s16)var_16,(s64)var_17);
  return (s64)var_17;
}

// FUN_003F0EC0 NONMATCHING


u32 FUN_003f0ec0(u64 param_1)



{

  u16 uVar1;

  int iVar2;

  u32 uVar3;

  int iStack_4;

  

  uVar3 = 0;

  iVar2 = func_00170ed0(param_1,&iStack_4);

  if (iStack_4 == 4) {

    uVar1 = *(u16 *)(iVar2 + 0x10);

    if ((uVar1 & 0x10) == 0) {

      if ((uVar1 & 8) == 0) {

        if ((uVar1 & 4) != 0) {

          uVar3 = 1;

        }

      }

      else {

        uVar3 = 2;

      }

    }

    else {

      uVar3 = 3;

    }

  }

  else if (iStack_4 == 3) {

    uVar1 = *(u16 *)(iVar2 + 0x16);

    if ((uVar1 & 0x10) == 0) {

      if ((uVar1 & 8) == 0) {

        if ((uVar1 & 4) != 0) {

          uVar3 = 1;

        }

      }

      else {

        uVar3 = 2;

      }

    }

    else {

      uVar3 = 3;

    }

  }

  else if (iStack_4 == 2) {

    uVar1 = *(u16 *)(iVar2 + 0x18);

    if ((uVar1 & 0x10) == 0) {

      if ((uVar1 & 8) == 0) {

        if ((uVar1 & 4) != 0) {

          uVar3 = 1;

        }

      }

      else {

        uVar3 = 2;

      }

    }

    else {

      uVar3 = 3;

    }

  }

  else if (iStack_4 == 1) {

    uVar1 = *(u16 *)(iVar2 + 0x18);

    if ((uVar1 & 0x10) == 0) {

      if ((uVar1 & 8) == 0) {

        if ((uVar1 & 4) != 0) {

          uVar3 = 1;

        }

      }

      else {

        uVar3 = 2;

      }

    }

    else {

      uVar3 = 3;

    }

  }

  else if (iStack_4 == 0) {

    uVar1 = *(u16 *)(iVar2 + 0x22);

    if ((uVar1 & 0x10) == 0) {

      if ((uVar1 & 8) == 0) {

        if ((uVar1 & 4) != 0) {

          uVar3 = 1;

        }

      }

      else {

        uVar3 = 2;

      }

    }

    else {

      uVar3 = 3;

    }

  }

  return uVar3;

}

// FUN_003F10B0 NONMATCHING


u16 FUN_003f10b0(int param_1,u16 param_2)



{

  u8 *puVar1;

  char cVar2;

  u16 uVar3;

  long lVar4;

  int iVar5;

  short sVar6;

  

  if (param_1 == 4) {

    sVar6 = 3;

  }

  else {

    if (param_1 != 0) {

      return 0xffff;

    }

    sVar6 = 0xf;

  }

  if ((param_1 < 0) || (8 < param_1)) {

    K_Assert((const char *)(u32)0x6aede8,0xb9);

  }

  lVar4 = datGetScenarioMode();

  if (lVar4 != 0) {

    param_1 = param_1 + 9;

  }

  puVar1 = (u8 *)((u32 **)&PTR_DAT_006ac9f0)[param_1 * 9];

  if (*(int *)(puVar1 + 8) == 0) {

    K_Assert((const char *)(u32)0x6aede8,0x19c);

  }

  if (sVar6 == 0xff) {

    iVar5 = *(int *)(puVar1 + 8);

  }

  else {

    lVar4 = datSocialLinkLevelIsNotZero(sVar6);

    if (lVar4 == 0) {

      iVar5 = *(int *)(puVar1 + 8);

    }

    else {

      cVar2 = datGetSocialLinkLevel(sVar6);

      if (cVar2 == '\0') {

        iVar5 = *(int *)(puVar1 + 8);

      }

      else {

        if ((cVar2 < '\x01') || ('\n' < cVar2)) {

          K_Assert((const char *)(u32)0x6aede8,0x1a2);

        }

        iVar5 = *(int *)(puVar1 + 8) + cVar2 * 0x20;

      }

    }

  }

  if ((iVar5 == 0) || (lVar4 = FUN_003f0ec0(param_2), lVar4 == 0)) {

    uVar3 = 0xffff;

  }

  else {

    uVar3 = *(u16 *)((int)lVar4 * 2 + iVar5 + 0xe);

  }

  return uVar3;

}

// FUN_003F12A0 NONMATCHING


u16 FUN_003f12a0(int param_1,int param_2)



{

  u8 *puVar1;

  char cVar2;

  u16 uVar3;

  long lVar4;

  int iVar5;

  short sVar6;

  

  if (param_1 == 4) {

    sVar6 = 3;

  }

  else {

    if (param_1 != 0) {

      return 0xffff;

    }

    sVar6 = 0xf;

  }

  if ((param_1 < 0) || (8 < param_1)) {

    K_Assert((const char *)(u32)0x6aede8,0xb9);

  }

  lVar4 = datGetScenarioMode();

  if (lVar4 != 0) {

    param_1 = param_1 + 9;

  }

  puVar1 = (u8 *)((u32 **)&PTR_DAT_006ac9f0)[param_1 * 9];

  if (*(int *)(puVar1 + 8) == 0) {

    K_Assert((const char *)(u32)0x6aede8,0x19c);

  }

  if (sVar6 == 0xff) {

    iVar5 = *(int *)(puVar1 + 8);

  }

  else {

    lVar4 = datSocialLinkLevelIsNotZero(sVar6);

    if (lVar4 == 0) {

      iVar5 = *(int *)(puVar1 + 8);

    }

    else {

      cVar2 = datGetSocialLinkLevel(sVar6);

      if (cVar2 == '\0') {

        iVar5 = *(int *)(puVar1 + 8);

      }

      else {

        if ((cVar2 < '\x01') || ('\n' < cVar2)) {

          K_Assert((const char *)(u32)0x6aede8,0x1a2);

        }

        iVar5 = *(int *)(puVar1 + 8) + cVar2 * 0x20;

      }

    }

  }

  if (iVar5 == 0) {

    uVar3 = 0xffff;

  }

  else {

    uVar3 = *(u16 *)(param_2 * 2 + iVar5 + 0x18);

  }

  return uVar3;

}

// FUN_003F1470


u64 FUN_003f1470(int param_1)
{
  s16 sVar1;
  u32 uVar2;

  switch (param_1) {
  case 0:
    sVar1 = 0xf;
    break;
  case 4:
    sVar1 = 3;
    break;
  case 8:
    sVar1 = 2;
    break;
  default:
    return 0;
  }

  uVar2 = datSocialLinkLevelIsNotZero(sVar1);
  if (uVar2 == 0) {
    return 0;
  }

  return FUN_00172660(sVar1);
}

// FUN_003F1520

void FUN_003f1520(int param_1)
{
  s32 iVar1;
  u32 uVar2;

  switch (param_1) {
  case 0:
    iVar1 = 0xf;
    break;
  case 4:
    iVar1 = 3;
    break;
  case 8:
    iVar1 = 2;
    break;
  default:
    return;
  }

  uVar2 = datSocialLinkLevelIsNotZero_s32(iVar1);
  if (uVar2 != 0) {
    FUN_001725a0((s16)iVar1);
  }
  else {
    func_0016dfb0(iVar1);
  }
}


// FUN_003F15D0


int FUN_003f15d0(int param_1,int param_2)
{
  u8 *puVar1;
  u8 *puVar2;

  puVar1 = (u8 *)(u32)datGetMoney();
  puVar2 = puVar1;

  if (0x98967f < (s32)puVar1 + param_1 * param_2) {
    puVar2 = (u8 *)(u32)0x98967f;
  }

  if ((s32)puVar1 + param_1 * param_2 < 0) {
    puVar2 = (u8 *)0;
  }
  else {
    puVar2 = (u8 *)(u32)((s32)puVar2 + param_1 * param_2);
  }

  if ((s32)puVar2 >= 0x98967f) {
    puVar2 = (u8 *)(u32)0x98967f;
  }

  datSetMoney((s32)puVar2);
  return (s32)puVar2 - (s32)puVar1;
}

// FUN_003F1690


int FUN_003f1690(u64 param_1)
{
  u16 uVar1;
  int iVar2;

  iVar2 = 0;
  goto check;
body:
  uVar1 = datGetEquipmentId(1,iVar2);
  if (uVar1 != 0) {
    goto increment;
  }
  func_001831e0(1,(short)iVar2,param_1);
  return iVar2;
increment:
  iVar2 = iVar2 + 1;
check:
  if (iVar2 < 300) {
    goto body;
  }
  return -1;
}

// FUN_003F1720 NONMATCHING


u16 FUN_003f1720(u32 param_1,u16 param_2)



{

  u16 uVar1;

  u16 unaff_s0_lo;

  u8 auStack_20 [24];

  u32 uStack_8;

  int iStack_4;

  

  iStack_4 = -1;

  func_00170ed0(param_1,&iStack_4);

  if (iStack_4 == 4) {

    func_00170c00(1,param_1,param_2);

    unaff_s0_lo = (u16)param_1;

  }

  else if ((((iStack_4 == 3) || (iStack_4 == 2)) || (iStack_4 == 1)) || (iStack_4 == 0)) {

    func_001828d0(param_1,auStack_20);


  }

  uVar1 = FUN_003e6dc0();

  uStack_8 = (u32)uVar1;

  FUN_0017d1a0(uStack_8,param_1 & 0xffff,param_2);

  return unaff_s0_lo;

}

// FUN_003F1830 NONMATCHING


u32 FUN_003f1830(short *param_1,short param_2)



{

  int iStack_4;
  short sVar1;

  
  iStack_4 = -1;
  sVar1 = *param_1;
  func_00170ed0(sVar1,&iStack_4);

  if (iStack_4 == 4) {
    func_00170c00(1,sVar1,-param_2);
  }
  else if ((((iStack_4 == 3) || (iStack_4 == 2)) || (iStack_4 == 1)) || (iStack_4 == 0)) {
    func_0016fea0(1,param_1[1],0);
  }

  return 1;
}

// FUN_003F1910 NONMATCHING


u32 FUN_003f1910(u64 param_1)



{

  u32 uVar1;

  u32 uVar2;

  int iVar3;

  int iStack_4;

  

  iStack_4 = -1;

  uVar2 = 0;

  func_00170ed0(param_1,&iStack_4);

  if (iStack_4 == 4) {

    uVar2 = func_00170760(1,param_1);

    uVar2 = uVar2 & 0xffff;

  }

  else if ((((iStack_4 == 3) || (iStack_4 == 2)) || (iStack_4 == 1)) || (iStack_4 == 0)) {

    for (iVar3 = 0; iVar3 < 300; iVar3 = iVar3 + 1) {

      uVar1 = datGetEquipmentId(1,iVar3);

      if ((long)(short)param_1 == (uVar1 & 0xffff)) {

        uVar2 = uVar2 + 1;

      }

    }

  }

  return uVar2;

}

// FUN_003F1A10 NONMATCHING


u32 FUN_003f1a10(u32 param_1)



{

  u32 uVar1;

  

  if ((param_1 & 0x7ffff) == 0) {

    uVar1 = 0x4000;

  }

  else {

    uVar1 = 0x1000;

  }

  if ((param_1 & 0xff00) != 0) {

    param_1 = param_1 >> 8;

    uVar1 = uVar1 | 0x2000;

  }

  if ((param_1 & 1) == 0) {

    if ((param_1 & 2) == 0) {

      if ((param_1 & 4) == 0) {

        if ((param_1 & 8) == 0) {

          if ((param_1 & 0x10) == 0) {

            if ((param_1 & 0x20) == 0) {

              if ((param_1 & 0x40) == 0) {

                if ((param_1 & 0x80) == 0) {

                  if ((param_1 & 0x10000) == 0) {

                    if ((param_1 & 0x20000) == 0) {

                      if ((param_1 & 0x40000) == 0) {

                        if ((param_1 & 0x80000) == 0) {

                          if ((param_1 & 0x100000) == 0) {

                            uVar1 = 0;

                          }

                          else {

                            uVar1 = uVar1 | 0x40e;

                          }

                        }

                        else {

                          uVar1 = uVar1 | 0x40d;

                        }

                      }

                      else {

                        uVar1 = uVar1 | 0x30b;

                      }

                    }

                    else {

                      uVar1 = uVar1 | 0x20a;

                    }

                  }

                  else {

                    uVar1 = uVar1 | 0x109;

                  }

                }

                else {

                  uVar1 = uVar1 | 7;

                }

              }

              else {

                uVar1 = uVar1 | 6;

              }

            }

            else {

              uVar1 = uVar1 | 5;

            }

          }

          else {

            uVar1 = uVar1 | 4;

          }

        }

        else {

          uVar1 = uVar1 | 3;

        }

      }

      else {

        uVar1 = uVar1 | 2;

      }

    }

    else {

      uVar1 = uVar1 | 1;

    }

  }

  return uVar1;

}

// FUN_003F1BA0 NONMATCHING


void FUN_003f1ba0(long param_1,u32 param_2)



{

  u32 uVar1;

  u32 *puVar2;

  long lVar3;

  u16 *puVar4;

  int iStack_4;

  

  iStack_4 = -1;

  if (param_1 == 0) {

    K_Assert((const char *)(u32)0x6aede8,0x3cc);

  }

  memset(param_1,0,0x1c);

  puVar4 = (u16 *)param_1;

  *puVar4 = (short)param_2;

  puVar4[5] = 0;

  lVar3 = dat00171360(param_2 & 0xffff);

  if (lVar3 == 0) {

    puVar2 = (u32 *)func_00170ed0(param_2,&iStack_4);

    if (iStack_4 == 4) {


      *(u32 *)(puVar4 + 2) = uVar1;

      *(u32 *)(puVar4 + 6) = puVar2[3];

      *(u8 *)(puVar4 + 4) = 2;

    }

    else if (iStack_4 == 3) {


      *(u32 *)(puVar4 + 2) = uVar1;

      *(u32 *)(puVar4 + 6) = puVar2[4];

      puVar4[8] = *(u16 *)(puVar2 + 1);

      puVar4[9] = *(u16 *)(puVar2 + 2);

      puVar4[10] = *(u16 *)((int)puVar2 + 6);

      puVar4[0xb] = *(u16 *)((int)puVar2 + 10);

      puVar4[0xc] = *(u16 *)(puVar2 + 3);

      *(u8 *)(puVar4 + 4) = 2;

    }

    else if (iStack_4 == 2) {

      func_001714f0(*(u16 *)(puVar2 + 3));


      *(u32 *)(puVar4 + 2) = uVar1;

      *(u32 *)(puVar4 + 6) = puVar2[4];

      puVar4[0xb] = *(u16 *)(puVar2 + 2);

      *(u8 *)(puVar4 + 4) = 2;

      *(u8 *)((int)puVar4 + 9) = 0x82;

    }

    else if (iStack_4 == 1) {


      *(u32 *)(puVar4 + 2) = uVar1;

      *(u32 *)(puVar4 + 6) = puVar2[4];

      puVar4[10] = *(u16 *)(puVar2 + 2);

      *(u8 *)(puVar4 + 4) = 2;

      *(u8 *)((int)puVar4 + 9) = 0x82;

    }

    else if (iStack_4 == 0) {


      *(u32 *)(puVar4 + 2) = uVar1;

      *(u32 *)(puVar4 + 6) = puVar2[6];

      puVar4[8] = *(u16 *)(puVar2 + 2);

      puVar4[9] = *(u16 *)(puVar2 + 3);

      *(u8 *)(puVar4 + 4) = 2;

      *(u8 *)((int)puVar4 + 9) = 0x82;

    }

  }

  else {


    *(u32 *)(puVar4 + 2) = uVar1;

  }

  return;

}

// FUN_003F1DC0 NONMATCHING


u32 FUN_003f1dc0(u16 param_1,long param_2,long param_3)



{

  u8 uVar1;

  short sVar2;

  u32 *puVar3;

  float *pfVar4;

  u32 uVar5;

  short *psVar6;

  float fVar7;

  int iStack_4;

  

  if ((param_3 < 0) || (299 < param_3)) {

    K_Assert((const char *)(u32)0x6aede8,0x40f);

  }

  if (param_2 == 0) {

    K_Assert((const char *)(u32)0x6aede8,0x410);

  }

  memset(param_2,0,0x1c);

  sVar2 = datGetEquipmentId(param_1,param_3);

  if (sVar2 == 0) {

    uVar5 = 0;

  }

  else {

    psVar6 = (short *)param_2;

    *psVar6 = sVar2;

    psVar6[5] = 1;

    psVar6[1] = (short)param_3;

    iStack_4 = 0;

    puVar3 = (u32 *)func_00170ed0(sVar2,&iStack_4);

    if (iStack_4 == 4) {

      K_Assert((const char *)(u32)0x6aede8,0x442);

      *(u8 *)(psVar6 + 4) = 2;


      *(u32 *)(psVar6 + 2) = uVar5;

      *(u32 *)(psVar6 + 6) = puVar3[3];

    }

    else if (iStack_4 == 3) {

      uVar1 = datGetEquipmentEffect(param_1,param_3);

      *(u8 *)((int)psVar6 + 9) = uVar1;

      *(u8 *)(psVar6 + 4) = 2;


      *(u32 *)(psVar6 + 2) = uVar5;

      *(u32 *)(psVar6 + 6) = puVar3[4];

      psVar6[8] = *(short *)(puVar3 + 1);

      psVar6[9] = *(short *)(puVar3 + 2);

      psVar6[10] = *(short *)((int)puVar3 + 6);

      psVar6[0xb] = *(short *)((int)puVar3 + 10);

      psVar6[0xc] = *(short *)(puVar3 + 3);

    }

    else if (iStack_4 == 2) {

      uVar1 = datGetEquipmentEffect(param_1,param_3);

      *(u8 *)((int)psVar6 + 9) = uVar1;

      pfVar4 = (float *)func_001714f0(*(u8 *)((int)psVar6 + 9));

      uVar1 = func_0016f810(param_1,param_3);

      *(u8 *)(psVar6 + 4) = uVar1;


      *(u32 *)(psVar6 + 2) = uVar5;

      fVar7 = (float)func_00171510(*(u16 *)(puVar3 + 5),(char)psVar6[4]);

      *(int *)(psVar6 + 6) = (int)((float)(u32)puVar3[4] * *pfVar4 * fVar7);

      sVar2 = func_0016fcc0(param_1,param_3);

      psVar6[0xb] = sVar2;

    }

    else if (iStack_4 == 1) {

      uVar1 = datGetEquipmentEffect(param_1,param_3);

      *(u8 *)((int)psVar6 + 9) = uVar1;

      pfVar4 = (float *)func_001714f0(*(u8 *)((int)psVar6 + 9));

      uVar1 = func_0016f810(param_1,param_3);

      *(u8 *)(psVar6 + 4) = uVar1;


      *(u32 *)(psVar6 + 2) = uVar5;

      fVar7 = (float)func_00171510(*(u16 *)(puVar3 + 5),(char)psVar6[4]);

      *(int *)(psVar6 + 6) = (int)((float)(u32)puVar3[4] * *pfVar4 * fVar7);

      sVar2 = func_0016fbd0(param_1,param_3);

      psVar6[10] = sVar2;

    }

    else if (iStack_4 == 0) {

      uVar1 = datGetEquipmentEffect(param_1,param_3);

      *(u8 *)((int)psVar6 + 9) = uVar1;

      pfVar4 = (float *)func_001714f0(*(u8 *)((int)psVar6 + 9));

      uVar1 = func_0016f810(param_1,param_3);

      *(u8 *)(psVar6 + 4) = uVar1;


      *(u32 *)(psVar6 + 2) = uVar5;

      fVar7 = (float)func_00171510(*(u16 *)(puVar3 + 7),(char)psVar6[4]);

      *(int *)(psVar6 + 6) = (int)((float)(u32)puVar3[6] * *pfVar4 * fVar7);

      sVar2 = func_0016f9f0(param_1,param_3);

      psVar6[8] = sVar2;

      sVar2 = func_0016fae0(param_1,param_3);

      psVar6[9] = sVar2;

    }

    uVar5 = 1;

  }

  return uVar5;

}

// FUN_003F2240 NONMATCHING


u8 FUN_003f2240(long param_1,u16 param_2)



{

  short sVar1;

  u32 *puVar2;

  u32 uVar3;

  u16 *puVar4;

  

  if (param_1 == 0) {

    K_Assert((const char *)(u32)0x6aede8,0x450);

  }

  memset(param_1,0,0x1c);

  sVar1 = func_00170760(1,param_2);

  if (sVar1 != 0) {

    puVar2 = (u32 *)func_00170e90(param_2);

    puVar4 = (u16 *)param_1;

    *puVar4 = param_2;


    *(u32 *)(puVar4 + 2) = uVar3;

    *(u32 *)(puVar4 + 6) = puVar2[3];

    puVar4[5] = sVar1;

  }

  return sVar1 != 0;

}

// FUN_003F2320 NONMATCHING


u64 FUN_003f2320(int param_1,int param_2)



{

  u32 *puVar1;

  long lVar2;

  short *psVar3;

  int iVar4;

  

  puVar1 = *(u32 **)(*(int *)(param_1 + 0x24) + 0x44);

  *puVar1 = *puVar1 | 2;

  psVar3 = *(short **)(param_2 + 8);

  lVar2 = 0;

  do {

    if (*(short *)(param_2 + 6) <= lVar2) {

      for (iVar4 = *(int *)(param_1 + 4); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x10)) {

        puVar1 = *(u32 **)(*(int *)(iVar4 + 0x14) + 0x1c);

        if ((*puVar1 & 8) == 0) {

          if ((*puVar1 & 4) == 0) {

            puVar1[4] = (int)(((float)(int)puVar1[4] + 0.0f) - (float)(int)puVar1[4] * 0.25f);

          }

          else {

            puVar1[4] = (int)(((float)(int)puVar1[4] + 0.0f) - fGpffff808c * (float)(int)puVar1[4]);

          }

        }

        else {

          puVar1[4] = (int)(((float)(int)puVar1[4] + 0.0f) - (float)(int)puVar1[4] * 0.5f);

        }

        if ((int)puVar1[4] < 0) {

          puVar1[4] = 1;

        }

      }


      return 0;

    }

    if ((*psVar3 != 0) && ((*(u8 *)((int)psVar3 + 5) & 1) != 0)) {

      for (iVar4 = *(int *)(param_1 + 4); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x10)) {

        if (*(short *)(*(int *)(*(int *)(iVar4 + 0x14) + 0x1c) + 4) == *psVar3) goto LAB_003f23a8;

      }

      iVar4 = 0;

LAB_003f23a8:

      if (iVar4 != 0) {

        puVar1 = *(u32 **)(*(int *)(iVar4 + 0x14) + 0x1c);

        *puVar1 = *puVar1 | 2;

        if ((*(u8 *)((int)psVar3 + 5) & 4) == 0) {

          if ((*(u8 *)((int)psVar3 + 5) & 2) != 0) {

            *puVar1 = *puVar1 | 4;

          }

        }

        else {

          *puVar1 = *puVar1 | 8;

        }

      }

    }

    psVar3 = psVar3 + 4;

    lVar2 = (long)((int)lVar2 + 1);

  } while( 1 );

}

// FUN_003F2510


u32 FUN_003f2510(void)



{

  int sVar1;
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;

  
  uVar1 = 0;
  for (uVar3 = 0; uVar3 < 8; uVar3 = uVar3 + 1) {
    sVar1 = *(short *)(DAT_006acc60_abs + uVar3 * 2);
    if (sVar1 != -1) {
      if (datGetFlag_u32_arg(sVar1) != 0) {
        uVar1 = (uVar1 | ((1 << uVar3) & 0xffffU)) & 0xffffU;
        continue;
      }
    }
    if ((uVar3 == 6) && datGetScenarioMode() != 0) {
      uVar1 = (uVar1 | ((1 << uVar3) & 0xffffU)) & 0xffffU;
    }

  }

  return uVar1;

}

// FUN_003F25E0 NONMATCHING


u32 FUN_003f25e0(u64 param_1,long param_2,u32 param_3)



{

  short sVar1;

  u32 *puVar2;

  u8 bVar3;

  u16 uVar4;

  u16 uVar5;

  int iVar6;

  u32 uVar7;

  long lVar8;

  u64 uVar9;

  int iVar10;

  short *psVar11;

  long lVar12;

  u32 uStack_8;

  int iStack_4;

  

  iVar10 = (int)param_2;

  psVar11 = *(short **)(iVar10 + 8);

  lVar12 = 0;

  do {

    if (*(short *)(iVar10 + 6) <= lVar12) {

      return 0;

    }

    sVar1 = *psVar11;

    if (sVar1 != 0) {

      bVar3 = 1;

      iVar6 = func_00170ed0(sVar1,&iStack_4);

      if (((param_3 & 0x400) != 0) && (iStack_4 != 0)) {

        bVar3 = 0;

      }

      if (((((param_3 & 0x800) != 0) && (iStack_4 != 1)) && (iStack_4 != 2)) && (iStack_4 != 3)) {

        bVar3 = 0;

      }

      if (iStack_4 < 1) {


        if ((((uVar7 & 0xff) != 6) || (lVar8 = datGetScenarioMode(), lVar8 == 0)) &&

           ((*(short *)(&DAT_006acc60 + (uVar7 & 0xff) * 2) != -1 &&

            (lVar8 = datGetFlag(), lVar8 == 0)))) {

          bVar3 = 0;

        }

      }

      if (((char)psVar11[2] == '\x01') && (lVar8 = datGetFlag(0x1310), lVar8 == 0)) {

        bVar3 = 0;

      }

      if (bVar3) {

        if ((param_3 & 0x1000) != 0) {

          return 1;

        }

        if (((param_3 & 0x2000) != 0) &&

           (lVar8 = FUN_003c4bf0(param_1,(int)param_1 + 4,sVar1), lVar8 != 0)) {

          bVar3 = 0;

        }

      }

      if (bVar3) {

        uVar9 = FUN_003c5a40(param_1,*(u16 *)((int)param_1 + 0x10) + 1,0x20,0);

        uVar4 = uGpffffb9a8;

        *(int *)((int)uVar9 + 4) = (int)sVar1;

        puVar2 = *(u32 **)(*(int *)((int)uVar9 + 0x14) + 0x1c);

        if ((param_3 & 1) != 0) {

          *puVar2 = *puVar2 | 1;

        }

        if (((param_3 & 0x4000) == 0) && ((*(u8 *)((int)psVar11 + 5) & 8) != 0)) {

          uVar5 = FUN_003e6dc0();

          uStack_8 = CONCAT22(uVar4,uVar5);

          iVar6 = FUN_0017d060(uStack_8,sVar1,(char)psVar11[3]);

          if (*(short *)(iVar6 + 6) == 0) {

            *puVar2 = *puVar2 | 0x20;

          }

        }


        if (((puVar2 == (u32 *)0xfffffffc) || (param_2 == 0)) || (psVar11 == (short *)0x0)) {

          K_Assert((const char *)(u32)0x6aede8,0x45e);

        }

        if (psVar11[1] < 1) {

          puVar2[4] = (int)(puVar2[4] * (int)*(short *)(iVar10 + 2)) / 100;

        }

        else {

          puVar2[4] = (int)(puVar2[4] * (int)psVar11[1]) / 100;

        }


      }

    }

    psVar11 = psVar11 + 4;

    lVar12 = (long)((int)lVar12 + 1);

  } while( 1 );

}

// FUN_003F2940 NONMATCHING


u32 FUN_003f2940(u64 param_1,short *param_2,int param_3,u32 param_4)



{

  short sVar1;

  u32 *puVar2;

  u8 bVar3;

  u16 uVar4;

  u16 uVar5;

  int iVar6;

  u32 uVar7;

  long lVar8;

  u64 uVar9;

  int iVar10;

  u32 uStack_8;

  int iStack_4;

  

  iVar10 = 0;

  do {

    if (param_3 <= iVar10) {

      return 0;

    }

    sVar1 = *param_2;

    if (sVar1 != 0) {

      bVar3 = 1;

      iVar6 = func_00170ed0(sVar1,&iStack_4);

      if (((param_4 & 0x400) != 0) && (iStack_4 != 0)) {

        bVar3 = 0;

      }

      if (((((param_4 & 0x800) != 0) && (iStack_4 != 1)) && (iStack_4 != 2)) && (iStack_4 != 3)) {

        bVar3 = 0;

      }

      if (iStack_4 < 1) {


        if (((((uVar7 & 0xff) != 6) || (lVar8 = datGetScenarioMode(), lVar8 == 0)) &&

            (*(short *)(&DAT_006acc60 + (uVar7 & 0xff) * 2) != -1)) &&

           (lVar8 = datGetFlag(), lVar8 == 0)) {

          bVar3 = 0;

        }

      }

      else if ((char)param_2[2] != '\x01') {

        lVar8 = func_001712d0(sVar1);

        if (lVar8 == 0x80) {

          uVar7 = 0xffffffff;

          if (iStack_4 - 1U < 2) {

            uVar7 = 6;

          }

          if (((uVar7 != 0xffffffff) && (*(short *)(&DAT_006acc60 + (uVar7 & 0xff) * 2) != -1)) &&

             (lVar8 = datGetFlag(), lVar8 == 0)) {

            bVar3 = 0;

          }

        }

        else if (lVar8 == 0x4000) {

          uVar7 = 0xffffffff;

          if (iStack_4 - 1U < 2) {

            uVar7 = 7;

          }

          if (((uVar7 != 0xffffffff) &&

              (((uVar7 & 0xff) != 6 || (lVar8 = datGetScenarioMode(), lVar8 == 0)))) &&

             ((*(short *)(&DAT_006acc60 + (uVar7 & 0xff) * 2) != -1 &&

              (lVar8 = datGetFlag(), lVar8 == 0)))) {

            bVar3 = 0;

          }

        }

      }

      if (bVar3) {

        if ((param_4 & 0x1000) != 0) {

          return 1;

        }

        if (((param_4 & 0x2000) != 0) &&

           (lVar8 = FUN_003c4bf0(param_1,(int)param_1 + 4,sVar1), lVar8 != 0)) {

          bVar3 = 0;

        }

      }

      if (((char)param_2[2] == '\x01') && (lVar8 = datGetFlag(0x1310), lVar8 == 0)) {

        bVar3 = 0;

      }

      if (bVar3) {

        uVar9 = FUN_003c5a40(param_1,*(u16 *)((int)param_1 + 0x10) + 1,0x20,0);

        uVar4 = uGpffffb9a8;

        *(int *)((int)uVar9 + 4) = (int)sVar1;

        puVar2 = *(u32 **)(*(int *)((int)uVar9 + 0x14) + 0x1c);

        *puVar2 = *puVar2 | param_4;

        if ((param_4 & 1) != 0) {

          *puVar2 = *puVar2 | 1;

        }

        if (((param_4 & 0x4000) == 0) && ((*(u8 *)((int)param_2 + 5) & 8) != 0)) {

          uVar5 = FUN_003e6dc0();

          uStack_8 = CONCAT22(uVar4,uVar5);

          iVar6 = FUN_0017d060(uStack_8,sVar1,(char)param_2[3]);

          if (*(short *)(iVar6 + 6) == 0) {

            *puVar2 = *puVar2 | 0x20;

          }

        }



      }

    }

    param_2 = param_2 + 4;

    iVar10 = iVar10 + 1;

  } while( 1 );

}

// FUN_003F2D60


u64 FUN_003f2d60(int param_1)



{

  int iVar1;

  

  for (iVar1 = *(int *)(param_1 + 4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {

    FUN_003f2dc0(param_1,iVar1);

  }

  return 0;

}

// FUN_003F2DC0 NONMATCHING


u64 FUN_003f2dc0(int param_1,int param_2)



{

  short sVar1;

  u32 *puVar2;

  u32 uVar3;

  short sVar4;

  u16 uVar5;

  u32 uVar6;

  u32 uVar7;

  long lVar8;

  int iVar9;

  int iStack_4;

  

  puVar2 = *(u32 **)(*(int *)(param_2 + 0x14) + 0x1c);

  *puVar2 = *puVar2 & 0xffffffef;

  sVar1 = (short)puVar2[1];

  iStack_4 = -1;

  sVar4 = 0;

  func_00170ed0(sVar1,&iStack_4);

  if (iStack_4 == 4) {

    sVar4 = func_00170760(1,sVar1);

  }

  else if ((((iStack_4 == 3) || (iStack_4 == 2)) || (iStack_4 == 1)) || (iStack_4 == 0)) {

    sVar4 = 0;

    for (iVar9 = 0; iVar9 < 300; iVar9 = iVar9 + 1) {

      uVar7 = datGetEquipmentId(1,iVar9);

      if ((long)sVar1 == (uVar7 & 0xffff)) {

        sVar4 = sVar4 + 1;

      }

    }

  }

  *(short *)((int)puVar2 + 0xe) = sVar4;

  if (0x62 < sVar4) {

    *puVar2 = *puVar2 | 0x10;

  }

  uVar3 = puVar2[4];

  uVar6 = datGetMoney();

  if (uVar6 < uVar3) {

    *puVar2 = *puVar2 | 0x10;

  }

  uVar5 = FUN_003e6dc0();

  lVar8 = FUN_0017d250(uVar5,(short)puVar2[1]);

  if (lVar8 == 0) {

    *puVar2 = *puVar2 | 0x20;

  }

  if ((*puVar2 & 0x20) != 0) {

    *puVar2 = *puVar2 | 0x10;

  }

  return 0;

}

// FUN_003F2F70 NONMATCHING


u32 FUN_003f2f70(u32 param_1,int param_2,u32 param_3)
{
  u32 option_flags;
  u32 helper_flags;
  u32 mode;
  int source_index;
  int source_count;
  int i;
  int list_index;
  int *source;
  int *entry;
  int *choice;

  option_flags = 0;
  if ((param_3 & 1) != 0) {
    option_flags = 0x400;
  }
  if ((param_3 & 2) != 0) {
    option_flags |= 0x800;
  }
  if ((param_2 < 0) || (param_2 > 8)) {
    FUN_0019d3f0_fcl((const char *)(u32)0x6aede8,0xb9);
  }

  mode = datGetScenarioMode();
  source_index = param_2;
  if (mode != 0) {
    source_index += 9;
  }
  source = (int *)((u8 *)&DAT_006ac9d0 + source_index * 0x24);
  *(short *)(*(int *)(*(int *)(param_1 + 0x24) + 0x44) + 4) = (short)param_2;
  *(short *)(*(int *)(*(int *)(param_1 + 0x24) + 0x44) + 6) = (short)param_2;

  choice = FUN_003f00d0_i(source,1,(int *)0);
  if (choice == (int *)0) {
    choice = FUN_003f00d0_i(source,0,(int *)0);
  }
  if ((mode != 0) && (choice != (int *)0) &&
      (FUN_003f25e0_i(param_1,choice,option_flags | 0x1000) != 0)) {
    return 1;
  }

  helper_flags = option_flags | 0x1000;
  source_count = *(int *)((u8 *)source + 0x18);
  for (i = 0; i < source_count; i++) {
    entry = (int *)(((u32 **)&PTR_DAT_006ac9ec)[source_index * 9] + i * 0xc);
    if (entry == (int *)0) {
      break;
    }
    if ((datGetLevel(1) & 0xff) < (u32)*entry) {
      break;
    }
    if (mode != 0) {
      return 1;
    }
    if (FUN_003f2940_i(param_1,(short *)entry[2],entry[1],helper_flags) != 0) {
      return 1;
    }
  }

  list_index = 0;
  choice = (int *)(u32)mode;
  while (FUN_003f25e0_i(param_1,choice,option_flags | 0x1001) != 0) {
    choice = FUN_003f00d0_i((int *)((u8 *)source + 0x10),0,&list_index);
    if (choice == (int *)0) {
      break;
    }
    list_index++;
  }

  source_count = FUN_003f03e0(param_2);
  for (i = 1; i <= source_count; i++) {
    entry = (int *)(*(int *)(*(int *)((u8 *)source + 0x20) + 8) + i * 0x20);
    if ((entry != (int *)0) &&
        (FUN_003f2940_i(param_1,(short *)entry[2],entry[1],helper_flags) != 0)) {
      break;
    }
  }
  return 0;
}

// Retail sibling begins at 0x3f3280; comparator body reconstructed from 0x3f3280-0x3f33c8.
#pragma push
#pragma opt_rebuildconditionals off
// FUN_003F3280
s32 FUN_003f3280(u32 *param_1,u32 *param_2)
{
  u32 entryA;
  u32 entryB;
  s32 fieldA;
  s32 fieldB;
  s32 result;
  s32 catA;
  s32 catB;

  entryA = *(u32 *)(*param_1 + 0x14);
  entryA = *(u32 *)(entryA + 0x1c);
  entryB = *(u32 *)(*param_2 + 0x14);
  entryB = *(u32 *)(entryB + 0x1c);
  fieldB = *(u32 *)(entryB + 8);
  fieldA = *(u32 *)(entryA + 8);
  result = (fieldA & 0xff) - (fieldB & 0xff);
  if (result != 0) {
    goto ret;
  }
  switch ((fieldB & 0xf00) >> 8) {
  case 0:
    catB = *(short *)(entryB + 0x14);
    break;
  case 1:
    catB = *(short *)(entryB + 0x18);
    break;
  case 2:
    catB = *(short *)(entryB + 0x1a);
    break;
  case 4:
    catB = 0x98967f - *(int *)(entryB + 0x10);
    break;
  default:
    catB = 0;
    break;
  }
  switch ((fieldA & 0xf00) >> 8) {
  case 0:
    catA = *(short *)(entryA + 0x14);
    break;
  case 1:
    catA = *(short *)(entryA + 0x18);
    break;
  case 2:
    catA = *(short *)(entryA + 0x1a);
    break;
  case 4:
    catA = 0x98967f - *(int *)(entryA + 0x10);
    break;
  default:
    catA = 0;
    break;
  }
  result = catB - catA;
  if (result != 0) {
    goto ret;
  }
  result = *(short *)(entryB + 4) - *(short *)(entryA + 4);
ret:
  return result;
}
#pragma pop

// FUN_003F33D0 NONMATCHING


u64 FUN_003f33d0(int param_1,u32 param_2)
{
  u32 option_flags;
  u32 task;
  u32 result;
  int mode;
  int source_index;
  int source_count;
  int i;
  int list_index;
  int *source;
  int *entry;
  int *choice;
  u32 *copy_dst;
  u32 *copy_src;
  u8 **fn_src;
  u8 *source_bytes;
  u32 auStack_b0[16];
  u32 auStack_70[8];
  u32 auStack_50[8];
  u32 auStack_30[8];

  option_flags = 0;
  source_index = param_1;
  if (param_1 == 3) {
    source_count = 4;
  }
  else {
    source_count = 5;
  }
  if ((param_2 & 1) != 0) {
    option_flags = 0x400;
  }
  if ((param_2 & 2) != 0) {
    option_flags |= 0x800;
  }
  if ((param_1 < 0) || (param_1 > 8)) {
    FUN_0019d3f0_fcl((const char *)(u32)0x6aede8,0xb9);
  }

  mode = datGetScenarioMode();
  if (mode != 0) {
    source_index += 9;
  }
  source_bytes = (u8 *)&DAT_006ac9d0 + source_index * 0x24;
  source = (int *)source_bytes;
  task = FUN_003c58f0_i(0,0x58,source_count,0x1a);
  *(short *)(*(int *)(*(int *)(task + 0x24) + 0x44) + 4) = (short)param_1;
  *(short *)(*(int *)(*(int *)(task + 0x24) + 0x44) + 6) = (short)param_1;

  list_index = 0;
  choice = FUN_003f00d0_i(source,1,&list_index);
  if (choice == (int *)0) {
    list_index = 0;
    choice = FUN_003f00d0_i(source,0,&list_index);
  }
  if (choice != (int *)0) {
    uGpffffb9a8 = (u8)list_index;
    FUN_003f25e0_i(task,choice,option_flags | 0x2000);
  }

  source_count = *(int *)(source_bytes + 0x18);
  for (i = 0; i < source_count; i++) {
    entry = (int *)(((u32 **)&PTR_DAT_006ac9f0)[source_index * 9] + i * 0xc);
    if (entry == (int *)0) {
      break;
    }
    if ((datGetLevel(1) & 0xff) < (u32)*entry) {
      break;
    }
    uGpffffb9a8 = (u8)(i + 1) | 0x100;
    FUN_003f2940_i(task,(short *)entry[2],entry[1],option_flags | 0x2000);
  }

  list_index = 0;
  choice = FUN_003f00d0_i((int *)(source_bytes + 0x10),0,&list_index);
  if (mode != 0) {
    uGpffffb9a8 = (u8)i | 0x200;
    FUN_003f25e0_i(task,(int *)(source_bytes + 0x10),option_flags | 0x2001);
  }

  list_index = 0;
  choice = FUN_003f00d0_i((int *)(source_bytes + 8),1,(int *)0);
  if (choice == (int *)0) {
    choice = FUN_003f00d0_i((int *)(source_bytes + 8),0,(int *)0);
  }
  if (choice != (int *)0) {
    FUN_003f2320_i(task,choice);
  }
  source_count = (u8)FUN_003f03e0(param_1);
  for (i = 1; i <= source_count; i++) {
    entry = (int *)(*(int *)(*(int *)(source_bytes + 0x20) + 8) + i * 0x20);
    if (entry != (int *)0) {
      uGpffffb9a8 = (u8)i | 0x300;
      FUN_003f2940_i(task,(short *)entry[2],entry[1],option_flags | 0x2000);
    }
  }

  if (param_1 != 3) {
    if ((param_2 & 4) != 0) {
      result = 0;
      choice = (int *)(u32)FUN_003f39a0_i(param_1,1,param_2);
      if (choice != (int *)0) {
        result = FUN_003f3e60_i(task,(u32)choice);
      }
      FUN_003c5a20((u32)choice);
      FUN_003c5a20(task);
      return result;
    }
    FUN_0017d610(param_1);
    result = FUN_003f3970_i(param_1,param_2);
    if (result != 0) {
      FUN_003f3dc0_i(task,result);
    }
    FUN_003c5a20(result);
  }

  FUN_003c7000(task,0x3f3280,0);
  FUN_003c6ee0(task);

  fn_src = (u8 **)&PTR_FUN_006aee00;
  copy_dst = auStack_30;
  i = 4;
  do {
    copy_dst[0] = (u32)fn_src[0];
    copy_dst[1] = (u32)fn_src[1];
    fn_src += 2;
    i--;
    copy_dst += 2;
  } while (0 < i);
  fn_src = (u8 **)&PTR_FUN_006aee20;
  copy_dst = auStack_50;
  i = 4;
  do {
    copy_dst[0] = (u32)fn_src[0];
    copy_dst[1] = (u32)fn_src[1];
    fn_src += 2;
    i--;
    copy_dst += 2;
  } while (0 < i);
  fn_src = (u8 **)&PTR_FUN_006aee40;
  copy_dst = auStack_70;
  i = 4;
  do {
    copy_dst[0] = (u32)fn_src[0];
    copy_dst[1] = (u32)fn_src[1];
    fn_src += 2;
    i--;
    copy_dst += 2;
  } while (0 < i);
  copy_src = &DAT_006aee60;
  copy_dst = auStack_b0;
  i = 8;
  do {
    copy_dst[0] = copy_src[0];
    copy_dst[1] = copy_src[1];
    copy_src += 2;
    i--;
    copy_dst += 2;
  } while (0 < i);

  FUN_003c5e80(task,auStack_30[source_index]);
  FUN_003c5e20(task,auStack_50[source_index]);
  FUN_003c5ee0(task,auStack_70[source_index]);
  FUN_003c6d40(task,auStack_b0[source_index * 2],auStack_b0[source_index * 2 + 1]);
  if (param_1 == 4) {
    *(u16 *)(*(int *)(task + 0x24) + 6) = 10;
  }
  else {
    *(u16 *)(*(int *)(task + 0x24) + 6) = 0x14;
  }
  *(u16 *)(*(int *)(task + 0x24) + 8) = 10;
  return task;
}

// FUN_003F3970


u64 FUN_003f3970(long param_1,u32 param_2)



{


  return FUN_003f39a0(param_1,0,param_2);
}

// FUN_003F39A0 NONMATCHING


u64 FUN_003f39a0(long param_1,long param_2,u32 param_3)



{

  u32 uVar1;

  int iVar2;

  long lVar3;

  u64 uVar4;

  int iVar5;

  u8 *puVar6;

  u32 uVar7;

  u32 uVar8;

  u8 bStack_10;

  u8 bStack_f;

  u16 uStack_e;

  u32 uStack_c;

  int iStack_4;

  

  uVar8 = 0;

  if (param_2 == 0) {

    dat0017d6d0(param_1,&bStack_10);

  }

  else {

    FUN_0017d700(param_1,0,&bStack_10);

  }

  uVar1 = 0;

  for (uVar7 = 0; uVar7 < 8; uVar7 = uVar7 + 1) {

    if ((*(short *)(&DAT_006acc60 + uVar7 * 2) == -1) ||
        (lVar3 = datGetFlag_s32(*(short *)(&DAT_006acc60 + uVar7 * 2)), lVar3 == 0)) {

      if ((uVar7 == 6) && (lVar3 = datGetScenarioMode(), lVar3 != 0)) {

        uVar1 = uVar1 | 0x40;

      }

    }

    else {

      uVar1 = uVar1 | 1 << (uVar7 & 0x1f) & 0xffffU;

    }

  }

  for (uVar7 = 0; uVar7 < 8; uVar7 = uVar7 + 1) {

    if (((uVar7 != 6) || (lVar3 = datGetScenarioMode(), lVar3 == 0)) &&

       (*(short *)(&DAT_006acc60 + uVar7 * 2) != -1)) {

      if (((u32)uStack_e & 1 << (uVar7 & 0x1f)) == 0) {

        datSetFlag(*(short *)(&DAT_006acc60 + uVar7 * 2),0);

      }

      else {
        datSetFlag(*(short *)(&DAT_006acc60 + uVar7 * 2),1);
      }


    }

  }

  if ((param_3 & 1) != 0) {

    uVar8 = 0x400;

  }

  if ((param_3 & 2) != 0) {

    uVar8 = uVar8 | 0x800;

  }

  if ((param_1 < 0) || (8 < param_1)) {

    K_Assert((const char *)(u32)0x6aede8,0xb9);

  }

  lVar3 = datGetScenarioMode();

  iVar5 = (int)param_1;

  if (lVar3 != 0) {

    iVar5 = iVar5 + 9;

  }

  uVar4 = FUN_003c58f0(0,0x58,5,0x1a);

  if (uStack_c < *(u32 *)(DAT_006ac9d0 + iVar5 * 0x24)) {

    puVar6 = (u8 *)((u32 **)&PTR_PTR_006ac9d4)[iVar5 * 9] + uStack_c * 0x14;

  }

  else {

    puVar6 = (u8 *)0x0;

  }

  if (puVar6 != (u8 *)0x0) {
    FUN_003f25e0(uVar4,(long)puVar6,uVar1 | 0x6000);
  }

  iStack_4 = 0;

  while( 1 ) {

    if (iStack_4 < *(int *)(&DAT_006ac9e8 + iVar5 * 0x24)) {

      puVar6 = (u8 *)((u32 **)&PTR_DAT_006ac9ec)[iVar5 * 9] + iStack_4 * 0xc;

      iStack_4 = iStack_4 + 1;

    }

    else {

      puVar6 = (u8 *)0x0;

    }

    if ((puVar6 == (u8 *)0x0) || ((int)(u32)bStack_10 < iStack_4)) break;
    FUN_003f2940(uVar4,*(short **)(puVar6 + 8),*(int *)(puVar6 + 4),uVar1 | 0x6000);

  for (iStack_4 = 1; iStack_4 <= (int)(u32)bStack_f; iStack_4 = iStack_4 + 1) {

    iVar2 = *(int *)(((u32 **)&PTR_DAT_006ac9f0)[iVar5 * 9] + 8) + iStack_4 * 0x20;

    if (iVar2 != 0) {
      FUN_003f2940(uVar4,*(short **)(iVar2 + 8),*(int *)(iVar2 + 4),uVar1 | 0x6000);
    }

  }

  for (uVar7 = 0; uVar7 < 8; uVar7 = uVar7 + 1) {

    if (((uVar7 != 6) || (lVar3 = datGetScenarioMode(), lVar3 == 0)) &&

       (*(short *)(&DAT_006acc60 + uVar7 * 2) != -1)) {

      if ((uVar1 & 1 << (uVar7 & 0x1f)) == 0) {

        datSetFlag(*(short *)(&DAT_006acc60 + uVar7 * 2),0);

      }

      else {
        datSetFlag(*(short *)(&DAT_006acc60 + uVar7 * 2),1);
      }

      }

    }

  }

  return uVar4;

}

// FUN_003F3DC0 NONMATCHING


void FUN_003f3dc0(int param_1,u64 param_2)



{

  u32 *puVar1;

  long lVar2;

  int iVar3;

  

  for (iVar3 = *(int *)(param_1 + 4); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x10)) {

    puVar1 = *(u32 **)(*(int *)(iVar3 + 0x14) + 0x1c);

    lVar2 = FUN_003c4bf0(param_2,(int)param_2 + 4,(short)puVar1[1]);

    if (lVar2 == 0) {

      *puVar1 = *puVar1 | 0x80;

    }

    else {

      FUN_003c49e0(param_2,(int)param_2 + 4,lVar2);

    }

  }

  return;

}

// FUN_003F3E60 NONMATCHING


u32 FUN_003f3e60(int param_1,u64 param_2)



{

  long lVar1;

  int iVar2;

  

  iVar2 = *(int *)(param_1 + 4);

  while( 1 ) {

    if (iVar2 == 0) {

      return 0;

    }

    lVar1 = FUN_003c4bf0(param_2,(int)param_2 + 4,

                         *(u16 *)(*(int *)(*(int *)(iVar2 + 0x14) + 0x1c) + 4));

    if (lVar1 == 0) break;

    FUN_003c49e0(param_2,(int)param_2 + 4,lVar1);

    iVar2 = *(int *)(iVar2 + 0x10);

  }

  return 1;

}

// FUN_003F3F00


u32 FUN_003f3f00(u64 param_1)
{
  u32 uVar1;
  u32 lVar2;
  uVar1 = FUN_003fa1e0_u32();

  if ((lVar2 = FUN_003c6ce0(param_1), lVar2 != 0) ||
      (lVar2 = FUN_003c6d10(param_1), lVar2 != 0)) {
    func_0010a4e0(0,0,0,0);
  }

  lVar2 = FUN_003c6ca0(param_1);
  if ((lVar2 != 0) || (lVar2 = FUN_003c6cc0(param_1), lVar2 != 0)) {
    func_0010a4e0(0,0,0,5);
  }

  return uVar1;
}

// FUN_003F3FC0 NONMATCHING


void FUN_003f3fc0(int param_1,int param_2,u32 param_3,u64 param_4)



{

  u32 uVar1;

  short sVar2;

  u32 uVar3;

  int iVar4;

  int iVar5;

  int lVar6;

  int iVar7;

  u32 uVar8;

  int iVar9;

  float fVar10;

  

  iVar7 = (int)param_4;

  uVar3 = *(u32 *)(iVar7 + 0xc);

  iVar4 = *(int *)(*(int *)(iVar7 + 0x24) + 0x44);

  param_1 = param_1 + *(short *)(iVar4 + 0x28);

  param_2 = param_2 + *(short *)(iVar4 + 0x2a);

  lVar6 = FUN_003c6e10(param_4);

  if (lVar6 == 1) {

    uVar8 = 0xff;

  }

  else {

    uVar8 = param_3;

    if ((lVar6 != 0x14) && (uVar8 = 0, lVar6 == 0xc)) {

      uVar8 = 0xff;

    }

  }

  if (uVar8 != 0) {

    sVar2 = *(short *)(iVar4 + 0x44);

    (*DAT_00960090)(8,1);

    (*DAT_00960090)(6,0);

    RpSkyRenderStateSet(3,0x3200d);


    (*DAT_00960090)(8,0);

    (*DAT_00960090)(6,1);

    RpSkyRenderStateSet(3,0x7000d);

    FUN_0040e3c0(1.0f,0,0,((int)uVar8 * (int)sVar2) / 0xff & 0xff,0x23,0);

    RpSkyRenderStateSet(2,0x44);

    RpSkyRenderStateSet(3,0x717fb);

    FUN_0040e3c0(0,*(u16 *)(iVar4 + 0x38),*(u16 *)(iVar4 + 0x3a),uVar8 & 0xff,0x24,0);

    iVar9 = param_1 + *(short *)(iVar4 + 0x48);

    iVar5 = param_2 + *(short *)(iVar4 + 0x4a);

    uVar1 = ((int)uVar8 * (int)*(short *)(iVar4 + 0x54)) / 0xff;

    fVar10 = *(float *)(iVar4 + 0x50);

    iVar7 = *(int *)(*(int *)(iVar7 + 0x24) + 0x28);

    FUN_0040e3f0(0,0,1.0f,fVar10,iVar9 + -0x15,iVar5 + -1,uVar1 & 0xff,0x26,0,0,0);
    FUN_0040e3f0(0,0,1.0f,fVar10,iVar9 + -0x13,iVar5 + 3 + (iVar7 * 0x68) / 0xffff,
                 uVar1 & 0xff,0x27,0,0,0);


  }


  FUN_003f7730(param_1 - 0x15,param_2 + 0x8b,param_3,param_4,uVar3);
  if (*(short *)(iVar4 + 6) == -1) {
    FUN_003f5ab0(0x161,0xe0,param_3,param_4,uVar3);
    FUN_003f7a80(0x161,0x130,param_3,param_4,uVar3);
  }
  else {
    FUN_003f61d0(0x15d,0xe0,param_3,param_4,uVar3);
    FUN_003f7a80(0x161,0x133,param_3,param_4,uVar3);
  }

  return;

}

// Typed integer call views preserve the retail 32-bit ABI for these draw helpers.
#pragma alias FUN_003f7730_i FUN_003f7730
void FUN_003f7730_i(int,int,int,int,int);
#pragma alias FUN_003f5d10_i FUN_003f5d10
void FUN_003f5d10_i(int,int,int,int,int);
#pragma alias FUN_003f5f50_i FUN_003f5f50
void FUN_003f5f50_i(int,int,int,int,int);
#pragma alias FUN_003f7a80_i FUN_003f7a80
void FUN_003f7a80_i(int,int,int,int,int);
// FUN_003F4350 NONMATCHING


void FUN_003f4350(int param_1,int param_2,int param_3,int param_4)



{

  u32 uVar1;

  u32 uVar2;

  int iVar3;

  int iVar4;

  int lVar5;

  int iVar6;

  int lVar7;

  int iVar8;

  u32 uVar9;

  

  iVar6 = (int)param_4;

  uVar2 = *(u32 *)(iVar6 + 0xc);

  iVar3 = *(int *)(*(int *)(iVar6 + 0x24) + 0x44);

  param_1 = param_1 + *(short *)(iVar3 + 0x28);

  param_2 = param_2 + *(short *)(iVar3 + 0x2a);

  lVar5 = FUN_003c6e10(param_4);

  if (lVar5 == 1) {

    lVar7 = 0xff;

  }

  else {

    lVar7 = param_3;

    if ((lVar5 != 0x14) && (lVar7 = 0, lVar5 == 0xc)) {

      lVar7 = 0xff;

    }

  }

  if (lVar7 != 0) {

    FUN_0040e3c0(0,param_1 + *(short *)(iVar3 + 0x38),param_2 + *(short *)(iVar3 + 0x3a),

                 ((int)lVar7 * (int)*(short *)(iVar3 + 0x44)) / 0xff & 0xff,0x22,0);

    iVar8 = param_1 + *(short *)(iVar3 + 0x48);

    iVar4 = param_2 + *(short *)(iVar3 + 0x4a);

    uVar1 = ((int)lVar7 * (int)*(short *)(iVar3 + 0x54)) / 0xff;

    uVar9 = *(u32 *)(iVar3 + 0x50);

    iVar6 = *(int *)(*(int *)(iVar6 + 0x24) + 0x28);

    FUN_0040e3f0(0,0,1.0f,uVar9,iVar8 + -0x15,iVar4 + -0xb,uVar1 & 0xff,0x24,0,0,0);

    FUN_0040e3f0(0,0,1.0f,uVar9,iVar8 + -0x13,iVar4 + 4 + (iVar6 * 0x68) / 0xffff,uVar1 & 0xff

                 ,0x25,0,0,0);

  }


  FUN_003f7730_i(param_1 - 0x15,param_2 + 0x8b,(int)param_3,(int)param_4,uVar2);
  if (*(short *)(iVar3 + 6) == -1) {
    FUN_003f5d10_i(0x15a,0xe6,(int)param_3,(int)param_4,uVar2);
    FUN_003f7a80_i(0x15b,0x134,(int)param_3,(int)param_4,uVar2);
  }
  else {
    FUN_003f7a80_i(param_1 + 1,param_2 + 0xac,(int)param_3,(int)param_4,uVar2);
  }

  return;

}

// FUN_003F45E0 NONMATCHING


void FUN_003f45e0(int param_1,int param_2,int param_3,int param_4)


{

  u32 uVar1;

  u32 uVar2;

  int iVar3;

  int iVar4;

  int lVar5;

  int iVar6;

  int lVar7;

  int iVar8;

  u32 uVar9;

  

  iVar6 = (int)param_4;

  uVar2 = *(u32 *)(iVar6 + 0xc);

  iVar3 = *(int *)(*(int *)(iVar6 + 0x24) + 0x44);

  param_1 = param_1 + *(short *)(iVar3 + 0x28);

  param_2 = param_2 + *(short *)(iVar3 + 0x2a);

  lVar5 = FUN_003c6e10(param_4);

  if (lVar5 == 1) {

    lVar7 = 0xff;

  }

  else {

    lVar7 = param_3;

    if ((lVar5 != 0x14) && (lVar7 = 0, lVar5 == 0xc)) {

      lVar7 = 0xff;

    }

  }

  if (lVar7 != 0) {

    FUN_0040e3c0(0,param_1 + *(short *)(iVar3 + 0x38),param_2 + *(short *)(iVar3 + 0x3a),

                 ((int)lVar7 * (int)*(short *)(iVar3 + 0x44)) / 0xff & 0xff,0x26,0);

    iVar8 = param_1 + *(short *)(iVar3 + 0x48);

    iVar4 = param_2 + *(short *)(iVar3 + 0x4a);

    uVar1 = ((int)lVar7 * (int)*(short *)(iVar3 + 0x54)) / 0xff;

    uVar9 = *(u32 *)(iVar3 + 0x50);

    iVar6 = *(int *)(*(int *)(iVar6 + 0x24) + 0x28);

    FUN_0040e3f0(0,0,1.0f,uVar9,iVar8 + -0x15,iVar4 + -0xb,uVar1 & 0xff,0x28,0,0,0);

    FUN_0040e3f0(0,0,1.0f,uVar9,iVar8 + -0x13,iVar4 + 4 + (iVar6 * 0x68) / 0xffff,uVar1 & 0xff

                 ,0x29,0,0,0);

  }


  FUN_003f7730_i(param_1 - 0x15,param_2 + 0x8b,(int)param_3,(int)param_4,uVar2);
  if (*(short *)(iVar3 + 6) == -1) {
    FUN_003f5f50_i(0x15a,0xe6,(int)param_3,(int)param_4,uVar2);
    FUN_003f7a80_i(0x15b,0x134,(int)param_3,(int)param_4,uVar2);
  }
  else {
    FUN_003f7a80_i(param_1 + 1,param_2 + 0xac,(int)param_3,(int)param_4,uVar2);
  }

  return;

}

// FUN_003F4870 NONMATCHING


void FUN_003f4870(int param_1,int param_2,long param_3,u64 param_4)



{

  u32 uVar1;

  u32 uVar2;

  int iVar3;

  long lVar4;

  int iVar5;

  long lVar6;

  int iVar7;

  int iVar8;

  u32 uVar9;

  

  iVar5 = (int)param_4;

  uVar2 = *(u32 *)(iVar5 + 0xc);

  iVar3 = *(int *)(*(int *)(iVar5 + 0x24) + 0x44);

  param_1 = param_1 + *(short *)(iVar3 + 0x28);

  param_2 = param_2 + *(short *)(iVar3 + 0x2a);

  lVar4 = FUN_003c6e10(param_4);

  if (lVar4 == 1) {

    lVar6 = 0xff;

  }

  else {

    lVar6 = param_3;

    if ((lVar4 != 0x14) && (lVar6 = 0, lVar4 == 0xc)) {

      lVar6 = 0xff;

    }

  }

  if (lVar6 != 0) {

    FUN_0040e3c0(0,param_1 + *(short *)(iVar3 + 0x38),param_2 + *(short *)(iVar3 + 0x3a),

                 ((int)lVar6 * (int)*(short *)(iVar3 + 0x44)) / 0xff & 0xff,0x16,0);

    iVar7 = param_1 + *(short *)(iVar3 + 0x48);

    iVar8 = param_2 + *(short *)(iVar3 + 0x4a);

    uVar1 = ((int)lVar6 * (int)*(short *)(iVar3 + 0x54)) / 0xff;

    uVar9 = *(u32 *)(iVar3 + 0x50);

    iVar3 = *(int *)(*(int *)(iVar5 + 0x24) + 0x28);

    FUN_0040e3f0(0,0,1.0f,uVar9,iVar7 + -0x15,iVar8 + -1,uVar1 & 0xff,0x18,0,0,0);

    FUN_0040e3f0(0,0,1.0f,uVar9,iVar7 + -0x13,iVar8 + (iVar3 * 0x56) / 0xffff,uVar1 & 0xff,

                 0x19,0,0,0);

  }



  return;

}

// FUN_003F4A90 NONMATCHING


u64

FUN_003f4a90(int param_1,int param_2,int param_3,int param_4,u64 param_5,short *param_6)



{

  u32 uVar1;

  

  param_1 = param_1 + *param_6;

  param_2 = param_2 + param_6[1];

  uVar1 = (u32)((DAT_007caef0 * (float)param_3 * (float)(int)param_6[6]) / 255.0f);

  if (param_4 != 4) {

    if (param_4 == 3) {

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0x9d,0);

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0x9e,0);

      return 0;

    }

    if (param_4 == 2) {

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0x6c,0);

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0x6d,0);

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0x72,0);

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0x73,0);

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0x7f,0);

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0x80,0);

      return 0;

    }

    if ((param_4 == 1) || (param_4 == 0)) {

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0xcf,0);

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0xd0,0);

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0xd5,0);

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0xd6,0);

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0xd2,0);

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0xd3,0);

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0xd4,0);

      return 0;

    }

  }

  FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0xc1,0);

  FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0xc2,0);

  FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0xcc,0);

  FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0xcd,0);

  return 0;

}

// FUN_003F4DE0 NONMATCHING


void FUN_003f4de0(int param_1,int param_2,u32 param_3,int param_4)



{
  void FUN_0040e3f0(float,float,float,float,int,int,int,int,int,int,int);
  #pragma alias FUN_003f4a90_i FUN_003f4a90
  u64 FUN_003f4a90_i(int,int,int,int,int,short *);
  #pragma alias FUN_003f7390_i FUN_003f7390
  void FUN_003f7390_i(int,int,int,int,int);
  #pragma alias FUN_003f7890_i FUN_003f7890
  void FUN_003f7890_i(int,int,int,int,int,int);
  #pragma alias FUN_003f7a80_i FUN_003f7a80
  void FUN_003f7a80_i(int,int,int,int,int);
  #pragma alias FUN_003f6f20_i FUN_003f6f20
  void FUN_003f6f20_i(int,int,int,int,int);
  #pragma alias FUN_003f7c60_i FUN_003f7c60
  void FUN_003f7c60_i(int,int,int,int,int);
  #pragma alias FUN_003f67e0_i FUN_003f67e0
  void FUN_003f67e0_i(int,int,int,int,int,int);

  u32 uVar1;

  short sVar2;

  int iVar3;

  long lVar4;

  int *piVar5;

  u32 *puVar6;

  int *piVar7;

  u32 *puVar8;

  int iVar9;

  int iVar10;

  u64 uVar11;

  int iVar12;

  int iVar13;

  u32 uVar14;

  u32 uVar15;
  short *psVar;
  float fVar14;

  float fVar15;

  u32 auStack_140 [12];

  u32 uStack_110;

  u32 uStack_10c;

  int iStack_108;

  u32 auStack_100 [9];

  u32 uStack_dc;

  u32 uStack_d8;

  int iStack_d4;

  u32 auStack_c0 [6];

  u32 uStack_a8;

  u32 uStack_a4;

  int iStack_a0;

  u32 auStack_80 [4];

  u32 uStack_70;

  int iStack_6c;

  int aiStack_40 [16];

  

  iVar9 = (int)param_4;

  uVar14 = *(u32 *)(iVar9 + 0xc);

  iVar3 = *(int *)(*(int *)(iVar9 + 0x24) + 0x44);

  iVar12 = iVar3 + 0x28;
  psVar = (short *)(iVar3 + 0x28);

  param_1 = param_1 + *(short *)(iVar3 + 0x28);

  param_2 = param_2 + *(short *)(iVar3 + 0x2a);

  lVar4 = FUN_003c6e10(param_4);

  if (lVar4 == 1) {

    uVar11 = 0xff;

  }

  else {

    uVar11 = param_3;

    if ((lVar4 != 0x14) && (uVar11 = 0, lVar4 == 0xc)) {

      uVar11 = 0xff;

    }

  }

  sVar2 = *(short *)(iVar3 + 6);

  iVar10 = (int)uVar11;

  if (sVar2 == -5) {
    FUN_003f4a90_i(param_1,param_2,iVar10,3,param_4,psVar);


    puVar8 = &DAT_006aeea0;

    puVar6 = auStack_100;

    iVar12 = 0xf;

    do {

      uVar14 = *puVar8;

      puVar8 = puVar8 + 1;

      iVar12 = iVar12 + -1;

      *puVar6 = uVar14;

      puVar6 = puVar6 + 1;

    } while (0 < iVar12);

    param_1 = param_1 + *(short *)(iVar3 + 0x48);

    param_2 = param_2 + *(short *)(iVar3 + 0x4a);

    uVar1 = (iVar10 * *(short *)(iVar3 + 0x54)) / 0xff;

    fVar14 = *(float *)(iVar3 + 0x50);

    iVar3 = *(int *)(*(int *)(iVar9 + 0x24) + 0x28);

    FUN_0040e3f0(0,0,1.0f,fVar14,param_1,param_2,uVar1 & 0xff,uStack_dc,0,0,0);

    FUN_0040e3f0(0,0,1.0f,fVar14,param_1,param_2 + (iStack_d4 * iVar3) / 0xffff,uVar1 & 0xff,

                 uStack_d8,0,0,0);

  }

  else if (sVar2 == -4) {
    FUN_003f4a90_i(param_1,param_2,iVar10,2,param_4,psVar);


    puVar8 = &DAT_006aeea0;

    puVar6 = auStack_c0;

    iVar12 = 0xf;

    do {

      uVar15 = *puVar8;

      puVar8 = puVar8 + 1;

      iVar12 = iVar12 + -1;

      *puVar6 = uVar15;

      puVar6 = puVar6 + 1;

    } while (0 < iVar12);

    iVar13 = param_1 + *(short *)(iVar3 + 0x48);

    iVar12 = param_2 + *(short *)(iVar3 + 0x4a);

    uVar1 = (iVar10 * *(short *)(iVar3 + 0x54)) / 0xff;

    fVar15 = *(float *)(iVar3 + 0x50);

    iVar9 = *(int *)(*(int *)(iVar9 + 0x24) + 0x28);

    FUN_0040e3f0(0,0,1.0f,fVar15,iVar13,iVar12,uVar1 & 0xff,uStack_a8,0,0,0);

    FUN_0040e3f0(0,0,1.0f,fVar15,iVar13,iVar12 + (iStack_a0 * iVar9) / 0xffff,uVar1 & 0xff,

                 uStack_a4,0,0,0);
    FUN_003f6f20_i(param_1 + 0x159,param_2 + 0x5f,*(short *)(iVar3 + 0x34),param_4,uVar14);
    FUN_003f7c60_i(param_1 + 0xf6,param_2 + 0xc8,param_3,param_4,uVar14);
    FUN_003f7890_i(param_1,param_2 + 0x28,*(short *)(iVar3 + 0x34),0,param_4,uVar14);




  }

  else if (sVar2 == -3) {
    FUN_003f4a90_i(param_1,param_2,iVar10,1,param_4,psVar);


    puVar8 = &DAT_006aeea0;

    puVar6 = auStack_80;

    iVar12 = 0xf;

    do {

      uVar15 = *puVar8;

      puVar8 = puVar8 + 1;

      iVar12 = iVar12 + -1;

      *puVar6 = uVar15;

      puVar6 = puVar6 + 1;

    } while (0 < iVar12);

    iVar13 = param_1 + *(short *)(iVar3 + 0x48);

    iVar12 = param_2 + *(short *)(iVar3 + 0x4a);

    uVar1 = (iVar10 * *(short *)(iVar3 + 0x54)) / 0xff;

    fVar15 = *(float *)(iVar3 + 0x50);

    iVar9 = *(int *)(*(int *)(iVar9 + 0x24) + 0x28);

    FUN_0040e3f0(0,0,1.0f,fVar15,iVar13,iVar12,uVar1 & 0xff,auStack_80[3],0,0,0);

    FUN_0040e3f0(0,0,1.0f,fVar15,iVar13,iVar12 + (iStack_6c * iVar9) / 0xffff,uVar1 & 0xff,

                 uStack_70,0,0,0);
    FUN_003f7390_i(param_1 + 0x81,param_2 + 0x100,*(short *)(iVar3 + 0x34),param_4,uVar14);
    FUN_003f7a80_i(param_1 + 0x11d,param_2 + 0x5e,param_3,param_4,uVar14);
    FUN_003f7890_i(param_1,param_2 + 0x28,*(short *)(iVar3 + 0x34),0,param_4,uVar14);




  }

  else if (sVar2 == -2) {
    FUN_003f4a90_i(param_1,param_2,iVar10,0,param_4,psVar);


    piVar7 = (int *)(&DAT_006aeea0);

    piVar5 = aiStack_40;

    iVar12 = 0xf;

    do {

      iVar13 = *piVar7;

      piVar7 = piVar7 + 1;

      iVar12 = iVar12 + -1;

      *piVar5 = iVar13;

      piVar5 = piVar5 + 1;

    } while (0 < iVar12);

    iVar13 = param_1 + *(short *)(iVar3 + 0x48);

    iVar12 = param_2 + *(short *)(iVar3 + 0x4a);

    uVar1 = (iVar10 * *(short *)(iVar3 + 0x54)) / 0xff;

    fVar15 = *(float *)(iVar3 + 0x50);

    iVar9 = *(int *)(*(int *)(iVar9 + 0x24) + 0x28);

    FUN_0040e3f0(0,0,1.0f,fVar15,iVar13,iVar12,uVar1 & 0xff,aiStack_40[0],0,0,0);

    FUN_0040e3f0(0,0,1.0f,fVar15,iVar13,iVar12 + (aiStack_40[2] * iVar9) / 0xffff,uVar1 & 0xff,

                 aiStack_40[1],0,0,0);
    FUN_003f7390_i(param_1 + 0x81,param_2 + 0x100,*(short *)(iVar3 + 0x34),param_4,uVar14);
    FUN_003f7a80_i(param_1 + 0x11d,param_2 + 0x5e,param_3,param_4,uVar14);
    FUN_003f7890_i(param_1,param_2 + 0x28,*(short *)(iVar3 + 0x34),0,param_4,uVar14);




  }

  else {
    FUN_003f4a90_i(param_1,param_2,iVar10,4,param_4,psVar);


    puVar8 = &DAT_006aeea0;

    puVar6 = auStack_140;

    iVar12 = 0xf;

    do {

      uVar15 = *puVar8;

      puVar8 = puVar8 + 1;

      iVar12 = iVar12 + -1;

      *puVar6 = uVar15;

      puVar6 = puVar6 + 1;

    } while (0 < iVar12);

    iVar13 = param_1 + *(short *)(iVar3 + 0x48);

    iVar12 = param_2 + *(short *)(iVar3 + 0x4a);

    uVar1 = (iVar10 * *(short *)(iVar3 + 0x54)) / 0xff;

    fVar15 = *(float *)(iVar3 + 0x50);

    iVar9 = *(int *)(*(int *)(iVar9 + 0x24) + 0x28);

    FUN_0040e3f0(0,0,1.0f,fVar15,iVar13,iVar12,uVar1 & 0xff,uStack_110,0,0,0);

    FUN_0040e3f0(0,0,1.0f,fVar15,iVar13,iVar12 + (iStack_108 * iVar9) / 0xffff,uVar1 & 0xff,

                 uStack_10c,0,0,0);
    FUN_003f67e0_i(0x117,0xd2,*(short *)(iVar3 + 0x34),1,param_4,uVar14);
    FUN_003f7a80_i(0x141,0x133,param_3,param_4,uVar14);
    FUN_003f7890_i(param_1,param_2 + 0x28,*(short *)(iVar3 + 0x34),0,param_4,uVar14);




  }

  return;

}

// FUN_003F55B0 NONMATCHING


void FUN_003f55b0(u64 param_1,u64 param_2,u32 param_3,int param_4,int param_5,

                 u32 param_6)



{

  u32 uVar1;

  u32 uVar2;

  u32 *puVar3;

  u64 uVar4;

  int iVar5;

  u32 *puVar6;

  u32 *puVar7;

  u32 uVar8;

  int iVar9;

  u32 uVar10;

  u32 auStack_50 [12];

  u8 auStack_20 [24];

  u32 auStack_8 [2];

  

  iVar9 = 5;

  auStack_8[0] = DAT_007cd8f8;

  auStack_8[1] = DAT_007cd8fc;

  puVar7 = &DAT_006aef00;

  puVar6 = auStack_50;

  iVar5 = iVar9;

  do {

    uVar1 = *puVar7;

    uVar2 = puVar7[1];

    puVar7 = puVar7 + 2;

    iVar5 = iVar5 + -1;

    *puVar6 = uVar1;

    puVar6[1] = uVar2;

    puVar6 = puVar6 + 2;

  } while (0 < iVar5);

  uVar8 = 0;

  puVar3 = *(u32 **)(*(int *)(param_5 + 0x14) + 0x1c);

  if (((param_6 & 1) != 0) &&

     (uVar8 = (u32)((**(u32 **)(*(int *)(param_4 + 0x24) + 0x44) & 1) == 0), uVar8 != 0)) {

    if ((*puVar3 & 1) == 0) {

      iVar9 = 6;

    }

    else {

      iVar9 = 1;

    }

  }

  uVar10 = param_3;

  if (((param_6 & 4) == 0) && ((*puVar3 & 0x10) != 0)) {

    uVar10 = (u32)((float)(int)param_3 * DAT_007cad80);

  }

  if ((*puVar3 & 0x80) != 0) {

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,1,0);

  }

  FUN_0040e3c0(0,param_1,param_2,uVar10 & 0xff,0,(u32)(u8)puVar3[2] * 2 + uVar8);

  uVar4 = func_00171110((short)puVar3[1],(char)puVar3[3]);

  FUN_003b2cb0(0,(int)param_1 + 0x20,(int)param_2 + 1,uVar10 | 0xffffff00,(char)iVar9,1,uVar4,0,0);

  if ((param_6 & 2) == 0) {

    if ((*puVar3 & 0x20) == 0) {

      sprintf((char *)auStack_20,0x7cd900,puVar3[4]);

      FUN_0040eb50(0,(int)param_1 + 0x16c,(int)param_2 + 0xb,uVar10 & 0xff,auStack_8[uVar8],

                   auStack_20,9);

    }

    else {

      iVar5 = FUN_003e6dc0();

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_50[iVar5 * 2 + uVar8],0);

    }

  }

  return;

}

// FUN_003F5830 NONMATCHING


void FUN_003f5830(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5,

                 u32 param_6)



{

  u8 bVar1;

  u32 *puVar2;

  u64 uVar3;

  u32 uVar4;

  int iVar5;

  int iVar6;

  u8 uVar7;

  u8 auStack_20 [24];

  u32 auStack_8 [2];

  

  uVar7 = 5;

  auStack_8[0] = DAT_007cd908;

  auStack_8[1] = DAT_007cd90c;

  puVar2 = *(u32 **)(*(int *)(param_5 + 0x14) + 0x1c);

  bVar1 = (param_6 & 1) != 0;

  if (bVar1) {

    uVar7 = 6;

  }

  uVar4 = (u32)bVar1;

  if ((*puVar2 & 0x10) != 0) {

    param_3 = (u32)((float)(int)param_3 * DAT_007cad80);

  }

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x85,uVar4 << 1);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x86,uVar4 << 1);

  iVar6 = (int)param_1;

  iVar5 = (int)param_2;

  FUN_0040e3c0(0,iVar6 + 0xe,iVar5 + 3,param_3 & 0xff,3,

               uVar4 + (*(u8 *)((u32)*(u16 *)(puVar2[5] + 2) * 0xe + DAT_007ce420 + 2) - 1) *

                       2);

  FUN_003b32d0(0,iVar6 + 0x75,iVar5 + 2,param_3 | 0xffffff00,uVar7,1,

               DAT_007ce4e4 + (u32)*(u16 *)(puVar2[5] + 2) * 0x11,0,0x78);

  sprintf((char *)auStack_20,0x7cd900,*(u8 *)(puVar2[5] + 4));

  FUN_0040eb50(0,iVar6 + 0x14e,iVar5 + 10,param_3 & 0xff,auStack_8[uVar4],auStack_20,1);

  if ((short)puVar2[7] != 0) {

    FUN_0040e3c0(0,iVar6 + 0x15e,iVar5 + -1,param_3 & 0xff,4,(u32)(u8)puVar2[6] * 2 + uVar4);

    uVar3 = func_00171110((short)puVar2[7],2);

    FUN_003b32d0(0,iVar6 + 0x184,iVar5 + 1,param_3 | 0xffffff00,uVar7,1,uVar3,0,0x73);

  }

  if (uVar4 == 0) {

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x89,0);

  }

  return;

}

// FUN_003F5AB0 NONMATCHING


void FUN_003f5ab0(u64 param_1,u64 param_2,u8 param_3,u64 param_4,

                 int param_5)



{

  char cVar1;

  short sVar2;

  short sVar3;

  int iVar4;

  char *pcVar5;

  char *pcVar6;

  short *psVar7;

  short *psVar8;

  u32 uVar9;

  short asStack_30 [8];

  u8 auStack_20 [24];

  char acStack_8 [8];

  

  pcVar6 = (char *)(&DAT_007cd910);

  pcVar5 = acStack_8;

  iVar4 = 5;

  do {

    cVar1 = *pcVar6;

    pcVar6 = pcVar6 + 1;

    iVar4 = iVar4 + -1;

    *pcVar5 = cVar1;

    pcVar5 = pcVar5 + 1;

  } while (0 < iVar4);

  psVar8 = (s16 *)(&DAT_006aef30);

  psVar7 = asStack_30;

  iVar4 = 4;

  do {

    sVar2 = *psVar8;

    sVar3 = psVar8[1];

    psVar8 = psVar8 + 2;

    iVar4 = iVar4 + -1;

    *psVar7 = sVar2;

    psVar7[1] = sVar3;

    psVar7 = psVar7 + 2;

  } while (0 < iVar4);

  iVar4 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

  FUN_0040e3c0(0,param_1,param_2,param_3,0x36,0);

  FUN_0040e3c0(0,param_1,param_2,param_3,0x37,0);

  FUN_0040e3c0(0,param_1,param_2,param_3,0x38,*(u8 *)(iVar4 + 8));

  FUN_0040e3c0(0,param_1,param_2,param_3,0x39,0);

  FUN_0040e3c0(0,param_1,param_2,param_3,0x3a,0);

  FUN_0040e3c0(0,param_1,param_2,param_3,0x3b,0);

  for (uVar9 = 0; (int)uVar9 < 4; uVar9 = uVar9 + 1) {

    if (((long)acStack_8[(int)(*(u32 *)(iVar4 + 8) & 0xf00) >> 8] & (long)(1 << (uVar9 & 0x1f))) ==

        0) {

      FUN_0040e3c0(0,(int)param_1 + (uVar9 & 1) * 0x7c,(int)param_2 + ((int)uVar9 >> 1 & 1U) * 0x15,

                   param_3,0x3c,0);

    }

    else {

      sprintf((char *)auStack_20,0x7cd900,*(u16 *)(iVar4 + uVar9 * 2 + 0x14));

      FUN_0040eb50(0,(int)param_1 + (int)asStack_30[uVar9 * 2],

                   (int)param_2 + (int)asStack_30[uVar9 * 2 + 1],param_3,1,auStack_20,2);

    }

  }

  return;

}

// FUN_003F5D10 NONMATCHING


void FUN_003f5d10(u64 param_1,u64 param_2,u8 param_3,u64 param_4,

                 int param_5)



{

  char cVar1;

  short sVar2;

  short sVar3;

  int iVar4;

  char *pcVar5;

  char *pcVar6;

  short *psVar7;

  short *psVar8;

  u32 uVar9;

  short asStack_30 [8];

  u8 auStack_20 [24];

  char acStack_8 [8];

  

  pcVar6 = (char *)(&DAT_007cd918);

  pcVar5 = acStack_8;

  iVar4 = 5;

  do {

    cVar1 = *pcVar6;

    pcVar6 = pcVar6 + 1;

    iVar4 = iVar4 + -1;

    *pcVar5 = cVar1;

    pcVar5 = pcVar5 + 1;

  } while (0 < iVar4);

  psVar8 = (s16 *)(&DAT_006aef40);

  psVar7 = asStack_30;

  iVar4 = 4;

  do {

    sVar2 = *psVar8;

    sVar3 = psVar8[1];

    psVar8 = psVar8 + 2;

    iVar4 = iVar4 + -1;

    *psVar7 = sVar2;

    psVar7[1] = sVar3;

    psVar7 = psVar7 + 2;

  } while (0 < iVar4);

  iVar4 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

  FUN_0040e3c0(0,param_1,param_2,param_3,0x34,0);

  FUN_0040e3c0(0,param_1,param_2,param_3,0x35,*(u8 *)(iVar4 + 8));

  FUN_0040e3c0(0,param_1,param_2,param_3,0x36,0);

  FUN_0040e3c0(0,param_1,param_2,param_3,0x37,0);

  FUN_0040e3c0(0,param_1,param_2,param_3,0x38,0);

  for (uVar9 = 0; (int)uVar9 < 4; uVar9 = uVar9 + 1) {

    if (((long)acStack_8[(int)(*(u32 *)(iVar4 + 8) & 0xf00) >> 8] & (long)(1 << (uVar9 & 0x1f))) ==

        0) {

      FUN_0040e3c0(0,(int)param_1 + (uVar9 & 1) * 0x7c,(int)param_2 + ((int)uVar9 >> 1 & 1U) * 0x15,

                   param_3,0x39,0);

    }

    else {

      sprintf((char *)auStack_20,0x7cd900,*(u16 *)(iVar4 + uVar9 * 2 + 0x14));

      FUN_0040eb50(0,(int)param_1 + (int)asStack_30[uVar9 * 2],

                   (int)param_2 + (int)asStack_30[uVar9 * 2 + 1],param_3,1,auStack_20,2);

    }

  }

  return;

}

// FUN_003F5F50 NONMATCHING


void FUN_003f5f50(u64 param_1,u64 param_2,u8 param_3,u64 param_4,

                 int param_5)



{

  char cVar1;

  short sVar2;

  short sVar3;

  u32 uVar4;

  u32 uVar5;

  int iVar6;

  char *pcVar7;

  int iVar8;

  char *pcVar9;

  short *psVar10;

  u32 *puVar11;

  short *psVar12;

  u32 *puVar13;

  u32 uVar14;

  int iVar15;

  u32 auStack_70 [16];

  short asStack_30 [8];

  u8 auStack_20 [24];

  char acStack_8 [8];

  

  pcVar9 = (char *)(&DAT_007cd920);

  pcVar7 = acStack_8;

  iVar6 = 5;

  do {

    cVar1 = *pcVar9;

    pcVar9 = pcVar9 + 1;

    iVar6 = iVar6 + -1;

    *pcVar7 = cVar1;

    pcVar7 = pcVar7 + 1;

  } while (0 < iVar6);

  psVar12 = (s16 *)(&DAT_006aef50);

  psVar10 = asStack_30;

  iVar6 = 4;

  do {

    sVar2 = *psVar12;

    sVar3 = psVar12[1];

    psVar12 = psVar12 + 2;

    iVar6 = iVar6 + -1;

    *psVar10 = sVar2;

    psVar10[1] = sVar3;

    psVar10 = psVar10 + 2;

  } while (0 < iVar6);

  iVar6 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

  iVar15 = (int)param_2;

  FUN_0040e3c0(0,param_1,iVar15 + 1,param_3,0x38,0);

  puVar13 = &DAT_006aef60;

  puVar11 = auStack_70;

  iVar8 = 7;

  do {

    uVar4 = *puVar13;

    uVar5 = puVar13[1];

    puVar13 = puVar13 + 2;

    iVar8 = iVar8 + -1;

    *puVar11 = uVar4;

    puVar11[1] = uVar5;

    puVar11 = puVar11 + 2;

  } while (0 < iVar8);

  FUN_0040e3c0(0,param_1,iVar15 + 1,param_3,0x39,auStack_70[*(u8 *)(iVar6 + 8)]);

  FUN_0040e3c0(0,param_1,param_2,param_3,0x3a,0);

  FUN_0040e3c0(0,param_1,param_2,param_3,0x3b,0);

  FUN_0040e3c0(0,param_1,param_2,param_3,0x3c,0);

  for (uVar14 = 0; (int)uVar14 < 4; uVar14 = uVar14 + 1) {

    if (((long)acStack_8[(int)(*(u32 *)(iVar6 + 8) & 0xf00) >> 8] & (long)(1 << (uVar14 & 0x1f)))

        == 0) {

      FUN_0040e3c0(0,(int)param_1 + (uVar14 & 1) * 0x7c,iVar15 + ((int)uVar14 >> 1 & 1U) * 0x15,

                   param_3,0x3d,0);

    }

    else {

      sprintf((char *)auStack_20,0x7cd900,*(u16 *)(iVar6 + uVar14 * 2 + 0x14));

      FUN_0040eb50(0,(int)param_1 + (int)asStack_30[uVar14 * 2],iVar15 + asStack_30[uVar14 * 2 + 1],

                   param_3,1,auStack_20,2);

    }

  }

  return;

}

// FUN_003F61D0 NONMATCHING


void FUN_003f61d0(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5)



{

  char cVar1;

  char cVar2;

  u16 uVar3;

  u16 uVar4;

  u32 uVar5;

  int iVar6;

  char *pcVar7;

  char *pcVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  u32 uVar12;

  u8 auStack_30[16];

  char acStack_20 [16];

  short sStack_10;

  short sStack_e;

  short sStack_c;

  short sStack_a;

  char acStack_8 [8];

  

  pcVar8 = (char *)(&DAT_007cd928);

  pcVar7 = acStack_8;

  iVar6 = 5;

  do {

    cVar1 = *pcVar8;

    pcVar8 = pcVar8 + 1;

    iVar6 = iVar6 + -1;

    *pcVar7 = cVar1;

    pcVar7 = pcVar7 + 1;

  } while (0 < iVar6);

  sStack_10 = DAT_007cd930;

  sStack_e = DAT_007cd932;

  sStack_c = DAT_007cd934;

  sStack_a = DAT_007cd936;

  pcVar8 = (char *)(&DAT_006aef98);

  pcVar7 = acStack_20;

  iVar6 = 5;

  do {

    cVar1 = *pcVar8;

    cVar2 = pcVar8[1];

    pcVar8 = pcVar8 + 2;

    iVar6 = iVar6 + -1;

    *pcVar7 = cVar1;

    pcVar7[1] = cVar2;

    pcVar7 = pcVar7 + 2;

  } while (0 < iVar6);

  iVar6 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

  uVar5 = *(u32 *)(iVar6 + 8) & 0xf00;

  iVar9 = (int)uVar5 >> 8;

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x36,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x37,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x38,*(u8 *)(iVar6 + 8));

  cVar1 = acStack_8[iVar9];

  if (cVar1 == '\0') {

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x3d,0);

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x3e,0);

  }

  else {

    uVar12 = param_3;

    if (acStack_20[iVar9 * 2] == -1) {

      uVar12 = (u32)((float)(int)param_3 * 0.5);

    }

    FUN_0040e3c0(0,param_1,param_2,uVar12 & 0xff,0x3f,0);

    uVar12 = param_3;

    if (acStack_20[iVar9 * 2 + 1] == -1) {

      uVar12 = (u32)((float)(int)param_3 * 0.5);

    }

    FUN_0040e3c0(0,param_1,param_2,uVar12 & 0xff,0x40,0);

  }

  iVar10 = (int)param_2;

  FUN_0040e3c0(0,param_1,iVar10 + 0x1b,param_3 & 0xff,0x37,0);

  cVar2 = acStack_20[iVar9 * 2];

  iVar11 = (int)param_1;

  uVar4 = (u16)(uVar5 >> 8);

  if (cVar2 == -1) {

    FUN_0040e3c0(0,param_1,iVar10 + 0x1b,param_3 & 0xff,0x42,0);

    FUN_0040e3c0(0,iVar11 + 0x11,iVar10 + 0x1b,param_3 & 0xff,0x42,0);

    FUN_0040e3c0(0,iVar11 + 0x22,iVar10 + 0x1b,param_3 & 0xff,0x42,0);

    FUN_0040e3c0(0,iVar11 + 0x33,iVar10 + 0x1b,param_3 & 0xff,0x42,0);

  }

  else {

    if (cVar1 == '\0') {

      uVar3 = datGetEquipmentIdx(1,uVar4);

      uVar3 = func_0016f9f0(1,uVar3);

    }

    else {

      uVar3 = datGetEquipmentIdx(1,uVar4);

      uVar3 = func_0016fbd0(1,uVar3);

    }

    sprintf((char *)auStack_30,0x7cd900,uVar3);

    FUN_0040eb50(0,iVar11 + sStack_10,iVar10 + 0x1b + (int)sStack_e,param_3 & 0xff,1,auStack_30,2);

    FUN_0040e3c0(0,param_1,iVar10 + 0x1b,param_3 & 0xff,0x41,0);

    sprintf((char *)auStack_30,0x7cd900,*(u16 *)(cVar2 * 2 + iVar6 + 0x14));

    FUN_0040eb50(0,iVar11 + sStack_c,iVar10 + 0x1b + (int)sStack_a,param_3 & 0xff,1,auStack_30,2);

  }

  FUN_0040e3c0(0,param_1,iVar10 + 0x36,param_3 & 0xff,0x37,0);

  cVar2 = acStack_20[iVar9 * 2 + 1];

  if (cVar2 == -1) {

    FUN_0040e3c0(0,param_1,iVar10 + 0x36,param_3 & 0xff,0x42,0);

    FUN_0040e3c0(0,iVar11 + 0x11,iVar10 + 0x36,param_3 & 0xff,0x42,0);

    FUN_0040e3c0(0,iVar11 + 0x22,iVar10 + 0x36,param_3 & 0xff,0x42,0);

    FUN_0040e3c0(0,iVar11 + 0x33,iVar10 + 0x36,param_3 & 0xff,0x42,0);

  }

  else {

    if (cVar1 == '\0') {

      uVar4 = datGetEquipmentIdx(1,uVar4);

      uVar4 = func_0016fae0(1,uVar4);

    }

    else {

      uVar4 = datGetEquipmentIdx(1,uVar4);

      uVar4 = func_0016fcc0(1,uVar4);

    }

    sprintf((char *)auStack_30,0x7cd900,uVar4);

    FUN_0040eb50(0,iVar11 + sStack_10,iVar10 + 0x36 + (int)sStack_e,param_3 & 0xff,1,auStack_30,2);

    FUN_0040e3c0(0,param_1,iVar10 + 0x36,param_3 & 0xff,0x41,0);

    sprintf((char *)auStack_30,0x7cd900,*(u16 *)(cVar2 * 2 + iVar6 + 0x14));

    FUN_0040eb50(0,iVar11 + sStack_c,iVar10 + 0x36 + (int)sStack_a,param_3 & 0xff,1,auStack_30,2);

  }

  return;

}

// FUN_003F67E0 NONMATCHING


void FUN_003f67e0(u64 param_1,u64 param_2,u32 param_3,int param_4,u64 param_5,

                 int param_6)



{

  char cVar1;

  char cVar2;

  u16 uVar3;

  u16 uVar4;

  int iVar5;

  char *pcVar6;

  char *pcVar7;

  int iVar8;

  long lVar9;

  int iVar10;

  int iVar11;

  long lVar12;

  u32 uVar13;

  u32 uVar14;

  u8 auStack_30[16];

  char acStack_20 [16];

  short sStack_10;

  short sStack_e;

  short sStack_c;

  short sStack_a;

  char acStack_8 [8];

  

  pcVar7 = (char *)(&DAT_007cd938);

  pcVar6 = acStack_8;

  iVar5 = 5;

  do {

    cVar1 = *pcVar7;

    pcVar7 = pcVar7 + 1;

    iVar5 = iVar5 + -1;

    *pcVar6 = cVar1;

    pcVar6 = pcVar6 + 1;

  } while (0 < iVar5);

  sStack_10 = DAT_007cd940;

  sStack_e = DAT_007cd942;

  sStack_c = DAT_007cd944;

  sStack_a = DAT_007cd946;

  pcVar7 = (char *)(&DAT_006aefa8);

  pcVar6 = acStack_20;

  iVar5 = 5;

  do {

    cVar1 = *pcVar7;

    cVar2 = pcVar7[1];

    pcVar7 = pcVar7 + 2;

    iVar5 = iVar5 + -1;

    *pcVar6 = cVar1;

    pcVar6[1] = cVar2;

    pcVar6 = pcVar6 + 2;

  } while (0 < iVar5);

  iVar5 = *(int *)(*(int *)(param_6 + 0x14) + 0x1c);

  uVar14 = *(u32 *)(iVar5 + 8) & 0xf00;

  iVar8 = (int)uVar14 >> 8;

  if (param_4 == 1) {

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,199,0);

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,200,0);

  }

  else if (param_4 == 0) {

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0xb1,0);

  }

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0xc9,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0xb5,0);

  iVar11 = (int)param_1;

  iVar10 = (int)param_2;

  FUN_0040e3c0(0,iVar11 + 0x70,iVar10 + 8,param_3 & 0xff,5,*(u8 *)(iVar5 + 8));

  cVar1 = acStack_8[iVar8];

  if (cVar1 == '\0') {

    lVar9 = (long)acStack_20[iVar8 * 2];

    uVar13 = param_3;

    if (lVar9 == -1) {

      uVar13 = (u32)((float)(int)param_3 * 0.5);

    }

    FUN_0040e3c0(0,param_1,param_2,uVar13 & 0xff,0xb3,0);

    lVar12 = (long)acStack_20[iVar8 * 2 + 1];

    uVar13 = param_3;

    if (lVar12 == -1) {

      uVar13 = (u32)((float)(int)param_3 * 0.5);

    }

    FUN_0040e3c0(0,param_1,param_2,uVar13 & 0xff,0xb4,0);

  }

  else {

    lVar9 = (long)acStack_20[iVar8 * 2];

    uVar13 = param_3;

    if (lVar9 == -1) {

      uVar13 = (u32)((float)(int)param_3 * 0.5);

    }

    FUN_0040e3c0(0,param_1,param_2,uVar13 & 0xff,0xca,0);

    lVar12 = (long)acStack_20[iVar8 * 2 + 1];

    uVar13 = param_3;

    if (lVar12 == -1) {

      uVar13 = (u32)((float)(int)param_3 * 0.5);

    }

    FUN_0040e3c0(0,param_1,param_2,uVar13 & 0xff,0xcb,0);

  }

  FUN_0040e3c0(0,param_1,iVar10 + 0x1c,param_3 & 0xff,0xb5,0);

  uVar4 = (u16)(uVar14 >> 8);

  if (lVar9 == -1) {

      uVar14 = (u32)((float)(int)param_3 * 0.5);

    FUN_0040e3c0(0,param_1,iVar10 + 0x1c,uVar14 & 0xff,0xce,0);

    FUN_0040e3c0(0,iVar11 + 0x11,iVar10 + 0x1c,uVar14 & 0xff,0xce,0);

    FUN_0040e3c0(0,iVar11 + 0x22,iVar10 + 0x1c,uVar14 & 0xff,0xce,0);

    FUN_0040e3c0(0,iVar11 + 0x33,iVar10 + 0x1c,uVar14 & 0xff,0xce,0);

  }

  else {

    if (cVar1 == '\0') {

      uVar3 = datGetEquipmentIdx(1,uVar4);

      uVar3 = func_0016f9f0(1,uVar3);

    }

    else {

      uVar3 = datGetEquipmentIdx(1,uVar4);

      uVar3 = func_0016fbd0(1,uVar3);

    }

    sprintf((char *)auStack_30,0x7cd900,uVar3);

    FUN_0040eb50(0,iVar11 + sStack_10,iVar10 + 0x1c + (int)sStack_e,param_3 & 0xff,1,auStack_30,2);

    FUN_0040e3c0(0,param_1,iVar10 + 0x1c,param_3 & 0xff,0xb6,0);

    sprintf((char *)auStack_30,0x7cd900,*(u16 *)((int)lVar9 * 2 + iVar5 + 0x14));

    FUN_0040eb50(0,iVar11 + sStack_c,iVar10 + 0x1c + (int)sStack_a,param_3 & 0xff,1,auStack_30,2);

  }

  FUN_0040e3c0(0,param_1,iVar10 + 0x38,param_3 & 0xff,0xb5,0);

  if (lVar12 == -1) {

      uVar14 = (u32)((float)(int)param_3 * 0.5);

    FUN_0040e3c0(0,param_1,iVar10 + 0x38,uVar14 & 0xff,0xce,0);

    FUN_0040e3c0(0,iVar11 + 0x11,iVar10 + 0x38,uVar14 & 0xff,0xce,0);

    FUN_0040e3c0(0,iVar11 + 0x22,iVar10 + 0x38,uVar14 & 0xff,0xce,0);

    FUN_0040e3c0(0,iVar11 + 0x33,iVar10 + 0x38,uVar14 & 0xff,0xce,0);

  }

  else {

    if (cVar1 == '\0') {

      uVar4 = datGetEquipmentIdx(1,uVar4);

      uVar4 = func_0016fae0(1,uVar4);

    }

    else {

      uVar4 = datGetEquipmentIdx(1,uVar4);

      uVar4 = func_0016fcc0(1,uVar4);

    }

    sprintf((char *)auStack_30,0x7cd900,uVar4);

    FUN_0040eb50(0,iVar11 + sStack_10,iVar10 + 0x38 + (int)sStack_e,param_3 & 0xff,1,auStack_30,2);

    FUN_0040e3c0(0,param_1,iVar10 + 0x38,param_3 & 0xff,0xb6,0);

    sprintf((char *)auStack_30,0x7cd900,*(u16 *)((int)lVar12 * 2 + iVar5 + 0x14));

    FUN_0040eb50(0,iVar11 + sStack_c,iVar10 + 0x38 + (int)sStack_a,param_3 & 0xff,1,auStack_30,2);

  }

  return;

}

// FUN_003F6F20 NONMATCHING


void FUN_003f6f20(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5)



{

  char cVar1;

  char cVar2;

  float fVar3;

  int iVar4;

  char *pcVar5;

  char *pcVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  u32 uVar10;

  float fVar11;

  u8 auStack_30[16];

  char acStack_20 [16];

  char acStack_10 [12];

  short sStack_4;

  short sStack_2;

  

  pcVar6 = (char *)(&DAT_007cd948);

  pcVar5 = acStack_10;

  iVar4 = 5;

  do {

    cVar1 = *pcVar6;

    pcVar6 = pcVar6 + 1;

    iVar4 = iVar4 + -1;

    *pcVar5 = cVar1;

    pcVar5 = pcVar5 + 1;

  } while (0 < iVar4);

  sStack_4 = DAT_007cd950;

  sStack_2 = DAT_007cd952;

  pcVar6 = (char *)(&DAT_006aefb8);

  pcVar5 = acStack_20;

  iVar4 = 5;

  do {

    cVar1 = *pcVar6;

    cVar2 = pcVar6[1];

    pcVar6 = pcVar6 + 2;

    iVar4 = iVar4 + -1;

    *pcVar5 = cVar1;

    pcVar5[1] = cVar2;

    pcVar5 = pcVar5 + 2;

  } while (0 < iVar4);

  iVar4 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

  iVar9 = (int)(*(u32 *)(iVar4 + 8) & 0xf00) >> 8;

  fVar11 = DAT_007caef0 * (float)(int)param_3;

  fVar3 = fVar11;

  if (2.1474836e+09f <= fVar11) {

    fVar3 = fVar11 - 2.1474836e+09f;

  }

  FUN_0040e3c0(0,param_1,param_2,(int)fVar3 & 0xff,0x75,0);

  if (2.1474836e+09f <= fVar11) {
    fVar11 = fVar11 - 2.1474836e+09f;

  }

  FUN_0040e3c0(0,param_1,param_2,(int)fVar11 & 0xff,0x76,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x77,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x78,0);

  iVar8 = (int)param_1;

  iVar7 = (int)param_2;

  FUN_0040e3c0(0,iVar8 + 0x89,iVar7 + 8,param_3 & 0xff,5,*(u8 *)(iVar4 + 8) + 0x16);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x79,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x7a,0);

  uVar10 = param_3;

  if (acStack_10[iVar9] != '\0') {

    uVar10 = (u32)((float)(int)param_3 * 0.5f);
  }

  FUN_0040e3c0(0,param_1,param_2,uVar10 & 0xff,0x7b,0);

  FUN_0040e3c0(0,param_1,param_2,uVar10 & 0xff,0x7c,0);

  FUN_0040e3c0(0,param_1,iVar7 + 0x23,param_3 & 0xff,0x7d,0);

  iVar9 = iVar9 * 2;

  if (acStack_20[iVar9] == -1) {

    FUN_0040e3c0(0,param_1,iVar7 + 0x23,(int)((float)(int)param_3 * 0.5f) & 0xff,0x7e,0);
  }

  else {

    sprintf((char *)auStack_30,0x7cd900,*(u16 *)(acStack_20[iVar9] * 2 + iVar4 + 0x14));

    FUN_0040eb50(0,iVar8 + sStack_4,iVar7 + 0x23 + (int)sStack_2,param_3 & 0xff,1,auStack_30,2);

  }

  FUN_0040e3c0(0,param_1,iVar7 + 0x3e,param_3 & 0xff,0x7d,0);

  if (acStack_20[iVar9 + 1] == -1) {

    FUN_0040e3c0(0,param_1,iVar7 + 0x3e,(int)((float)(int)param_3 * 0.5f) & 0xff,0x7e,0);
  }

  else {

    sprintf((char *)auStack_30,0x7cd900,*(u16 *)(acStack_20[iVar9 + 1] * 2 + iVar4 + 0x14));

    FUN_0040eb50(0,iVar8 + sStack_4,iVar7 + 0x3e + (int)sStack_2,param_3 & 0xff,1,auStack_30,2);

  }

  return;

}

// FUN_003F7390 NONMATCHING


void FUN_003f7390(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5)



{

  short sVar1;

  int iVar2;

  int iVar3;

  u64 uVar4;

  u32 uVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  u32 uVar10;

  u8 auStack_20 [28];

  int iStack_4;

  

  iVar2 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0xe2,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0xdb,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0xdc,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0xdd,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0xdf,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0xe0,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0xe1,0);

  for (iVar7 = 0; iVar7 < 2; iVar7 = iVar7 + 1) {

    iVar6 = iVar2 + iVar7 * 4;

    if (*(short *)(iVar6 + 0x16) != 0) {

      iVar8 = (int)param_1;

      iVar9 = (int)param_2 + 0x10 + iVar7 * 0x1a;

      FUN_0040e3c0(0,iVar8 + 0x2f,iVar9 + 0x21,param_3 & 0xff,0,0x1b);

      iVar3 = iVar2 + iVar7 * 4;

      uVar4 = func_00171110(*(u16 *)(iVar3 + 0x14),2);

      FUN_003b2cb0(0,iVar8 + 0x4f,iVar9 + 0x23,param_3 | 0xffffff00,6,1,uVar4,0,0);

      FUN_0040e3c0(0,iVar8 + 0x1c,iVar9,param_3 & 0xff,0xe3,0);

      sprintf((char *)auStack_20,0x7cd900,*(u16 *)(iVar6 + 0x16));

      FUN_0040eb50(0,iVar8 + 0x15a,iVar9 + 0x2c,param_3 & 0xff,1,auStack_20,1);

      FUN_0040e3c0(0,iVar8 + 0x1c,iVar9,param_3 & 0xff,0xe4,0);

      sVar1 = *(short *)(iVar3 + 0x14);

      iStack_4 = -1;

      uVar10 = 0;

      func_00170ed0(sVar1,&iStack_4);

      if (iStack_4 == 4) {

        uVar10 = func_00170760(1,sVar1);

        uVar10 = uVar10 & 0xffff;

      }

      else if ((((iStack_4 == 3) || (iStack_4 == 2)) || (iStack_4 == 1)) || (iStack_4 == 0)) {

        for (iVar6 = 0; iVar6 < 300; iVar6 = iVar6 + 1) {

          uVar5 = datGetEquipmentId(1,iVar6);

          if ((long)sVar1 == (uVar5 & 0xffff)) {

            uVar10 = uVar10 + 1;

          }

        }

      }

      sprintf((char *)auStack_20,0x7cd900,uVar10);

      FUN_0040eb50(0,iVar8 + 0x1c2,iVar9 + 0x2c,param_3 & 0xff,1,auStack_20,1);

    }

  }

  return;

}

// FUN_003F7730 NONMATCHING


void FUN_003f7730(u64 param_1,u64 param_2,u8 param_3,int param_4,int param_5)



{

  u16 uVar1;

  int iVar2;

  int iVar3;

  u16 *puVar4;

  u16 *puVar5;

  u16 auStack_30030 [98296];

  u16 auStack_30 [16];

  u8 auStack_10[16];

  

  puVar5 = (u16 *)(&DAT_006aefd0);

  puVar4 = auStack_30;

  iVar3 = 0xf;

  do {

    uVar1 = *puVar5;

    puVar5 = puVar5 + 1;

    iVar3 = iVar3 + -1;

    *puVar4 = uVar1;

    puVar4 = puVar4 + 1;

  } while (0 < iVar3);

  iVar3 = *(int *)(*(int *)(param_4 + 0x24) + 0x44);

  iVar2 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

  FUN_0040e3c0(0,param_1,param_2,param_3,auStack_30[*(short *)(iVar3 + 4) * 3],0);

  FUN_0040e3c0(0,param_1,param_2,param_3,auStack_30[*(short *)(iVar3 + 4) * 3 + 1],0);

  FUN_0040e3c0(0,param_1,param_2,param_3,auStack_30[*(short *)(iVar3 + 4) * 3 + 2],0);

  sprintf((char *)auStack_10,0x7cd954,*(u16 *)(iVar2 + 0xe));

  FUN_0040eb50(0,(int)param_1 + 0x8b,(int)param_2 + 0xc,param_3,1,auStack_10,1);

  return;

}

// FUN_003F7890 NONMATCHING


void FUN_003f7890(u64 param_1,u64 param_2,u8 param_3,int param_4,

                 u64 param_5,int param_6)



{

  u16 uVar1;

  u16 uVar2;

  int iVar3;

  u16 *puVar4;

  u16 *puVar5;

  u8 auStack_20[16];

  u16 auStack_10 [5];

  u16 uStack_6;

  

  puVar5 = (u16 *)(&DAT_006aeff0);

  puVar4 = auStack_10;

  iVar3 = 3;

  do {

    uVar1 = *puVar5;

    uVar2 = puVar5[1];

    puVar5 = puVar5 + 2;

    iVar3 = iVar3 + -1;

    *puVar4 = uVar1;

    puVar4[1] = uVar2;

    puVar4 = puVar4 + 2;

  } while (0 < iVar3);

  iVar3 = *(int *)(*(int *)(param_6 + 0x14) + 0x1c);

  if (param_4 == 1) {

    FUN_0040e3c0(0,param_1,param_2,param_3,auStack_10[3],0);

    FUN_0040e3c0(0,param_1,param_2,param_3,uStack_6,0);

    sprintf((char *)auStack_20,0x7cd954,*(u16 *)(iVar3 + 0xe));

    FUN_0040eb50(0,(int)param_1 + 0x223,(int)param_2 + 0xa2,param_3,3,auStack_20,1);

  }

  else if (param_4 == 0) {

    FUN_0040e3c0(0,param_1,param_2,param_3,auStack_10[0],0);

    FUN_0040e3c0(0,param_1,param_2,param_3,auStack_10[1],0);

    FUN_0040e3c0(0,param_1,param_2,param_3,auStack_10[2],0);

    sprintf((char *)auStack_20,0x7cd954,*(u16 *)(iVar3 + 0xe));

    FUN_0040eb50(0,(int)param_1 + 0x95,(int)param_2 + 0x99,param_3,3,auStack_20,1);

  }

  return;

}

// FUN_003F7A80 NONMATCHING


void FUN_003f7a80(u64 param_1,u64 param_2,u32 param_3,int param_4,int param_5)



{

  int iVar1;

  u32 uVar2;

  

  iVar1 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

  if ((*(short *)(*(int *)(*(int *)(param_4 + 0x24) + 0x44) + 6) == -1) &&

     ((*(u32 *)(iVar1 + 8) & 0x1000) != 0)) {

    FUN_003c7e20(0,param_1,param_2,param_3 | 0xffffffffffffff00,1,5,2,*(u16 *)(iVar1 + 6));

  }

  else if ((*(u32 *)(iVar1 + 8) & 0x1000) == 0) {

    FUN_003c7e20(0,param_1,param_2,param_3 | 0xffffffffffffff00,1,5,0,*(u16 *)(iVar1 + 4));

  }

  else {

    uVar2 = func_001715f0(*(u16 *)(iVar1 + 4));

    uVar2 = uVar2 & 0xff;

    if (uVar2 == 0) {

      FUN_003c7e20(0,param_1,param_2,param_3 | 0xffffffffffffff00,1,5,1,*(u16 *)(iVar1 + 4));

    }

    else if (uVar2 == 0xff) {

      FUN_003c7e20(0,param_1,param_2,param_3 | 0xffffffffffffff00,1,5,1,

                   (u32)CONCAT12(*(u8 *)(iVar1 + 0xd),*(u16 *)(iVar1 + 4)));

    }

    else {

      FUN_003c7e20(0,param_1,param_2,param_3 | 0xffffffffffffff00,1,5,1,

                   (u32)*(u16 *)(iVar1 + 4) | uVar2 << 0x10);

    }

  }

  return;

}

// FUN_003F7C60 NONMATCHING


void FUN_003f7c60(u32 param_1,u32 param_2,u32 param_3,int param_4,int param_5)
{
  int iVar1;

  iVar1 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);
  if ((*(short *)(*(int *)(*(int *)(param_4 + 0x24) + 0x44) + 6) == -1) &&
      ((*(u32 *)(iVar1 + 8) & 0x1000) != 0)) {
    FUN_003c7e20_f32(0.0f,param_1,param_2,param_3 | 0xffffff00,1,5,2,*(short *)(iVar1 + 6));
    return;
  }
  if ((*(u32 *)(iVar1 + 8) & 0x1000) != 0) {
    FUN_003c7e20_f32(0.0f,param_1,param_2,param_3 | 0xffffff00,1,5,1,
                     ((*(u8 *)(iVar1 + 0xd) << 16) & 0xffff0000) | (u32)*(u16 *)(iVar1 + 4));
    return;
  }
  FUN_003c7e20_f32(0.0f,param_1,param_2,param_3 | 0xffffff00,1,5,0,*(short *)(iVar1 + 4));
}

// FUN_003F7D50 NONMATCHING
// Filled in from retail disassembly: sibling FUN_003f7fe0's pattern (3/3/1
// true-branch, 2/2/0 false-branch constants to FUN_003f55b0/FUN_003f5830)
// applies here too, except the "else" sub-case in each branch substitutes
// iVar6 (a computed draw-x offset) and iVar5 (a computed fade alpha) for
// param_1/param_3 - a background/unselected variant of the same draw call.
// Residual: an unrelated register-widening mismatch in the pre-existing
// (not touched by this fix) diff/count prefix logic above.


void FUN_003f7d50(int param_1,int param_2,u64 param_3,int param_4,

                 int param_5)



{

  short sVar1;

  int iVar2;

  int iVar3;

  u32 uVar4;

  int iVar5;

  int iVar6;

  

  iVar5 = *(int *)(param_4 + 0x24);

  iVar2 = *(int *)(iVar5 + 0x44);

  uVar4 = 0;

  iVar3 = 0;

  sVar1 = *(short *)(iVar5 + 4);

  iVar5 = *(int *)(*(int *)(param_5 + 0x14) + 0xc) -

          *(int *)(*(int *)(*(int *)(iVar5 + 0x2c) + 0x14) + 0xc);

  if (((long)iVar5 <= (long)sVar1) && (iVar3 = sVar1 - iVar5, 4 < iVar3)) {

    iVar3 = 5;

  }

  iVar6 = param_1 - (0x1e - (iVar3 * 0x1e) / 5);

  iVar5 = (iVar3 * 0xff) / 5;

  if (3 < (long)sVar1) {

    iVar3 = sVar1 + -4;

    if (4 < iVar3) {

      iVar3 = 5;

    }

    uVar4 = (iVar3 * 0xff) / 5;

  }

  if (*(int *)(param_4 + 0xc) == param_5) {

    FUN_0040e3c0(0,param_1,param_2,uVar4 & 0xff,0x23,0);

    sVar1 = *(short *)(iVar2 + 6);

    if ((sVar1 == -2) || (sVar1 == -3)) {
      FUN_003f55b0(param_1,param_2,param_3,param_4,param_5,3);
    }
    else if (sVar1 == -5) {
      FUN_003f5830(param_1,param_2,param_3,param_4,param_5,3);
    }
    else {
      FUN_003f55b0(iVar6,param_2,iVar5,param_4,param_5,1);
    }
  }

  else {

    sVar1 = *(short *)(iVar2 + 6);

    if ((sVar1 == -2) || (sVar1 == -3)) {
      FUN_003f55b0(param_1,param_2,param_3,param_4,param_5,2);
    }
    else if (sVar1 == -5) {
      FUN_003f5830(param_1,param_2,param_3,param_4,param_5,2);
    }
    else {
      FUN_003f55b0(iVar6,param_2,iVar5,param_4,param_5,0);
    }
  }

  return;

}

// FUN_003F7FE0 NONMATCHING


void FUN_003f7fe0(u64 param_1,u64 param_2,u32 param_3,int param_4,int param_5

                 )



{

  short sVar1;

  int iVar2;

  

  iVar2 = *(int *)(*(int *)(param_4 + 0x24) + 0x44);

  if (*(int *)(param_4 + 0xc) == param_5) {

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x23,0);

    sVar1 = *(short *)(iVar2 + 6);

    if ((sVar1 == -2) || (sVar1 == -3)) {

      FUN_003f55b0(param_1,param_2,param_3 & 0xff,param_4,param_5,3);

    }

    else if (sVar1 == -5) {

      FUN_003f5830(param_1,param_2,param_3 & 0xff,param_4,param_5,3);

    }

    else {

      FUN_003f55b0(param_1,param_2,param_3 & 0xff,param_4,param_5,1);

    }

  }

  else {

    sVar1 = *(short *)(iVar2 + 6);

    if ((sVar1 == -2) || (sVar1 == -3)) {

      FUN_003f55b0(param_1,param_2,param_3 & 0xff,param_4,param_5,2);

    }

    else if (sVar1 == -5) {

      FUN_003f5830(param_1,param_2,param_3 & 0xff,param_4,param_5,2);

    }

    else {

      FUN_003f55b0(param_1,param_2,param_3 & 0xff,param_4,param_5,0);

    }

  }

  return;

}


// FUN_003F8180 NONMATCHING
// Filled in from retail disassembly, same dispatch family as the sibling
// functions above (3/3/1 true-branch, 2/2/0 false-branch constants to
// func_003f55b0/func_003f5830). Residual: a register-bank floor (obj
// 1088B vs 1056B window); logic and constants verified against retail.


void FUN_003f8180(int param_1,int param_2,u32 param_3,int param_4,int param_5

                 )



{

  u16 uVar1;

  u16 uVar2;

  short sVar3;

  u32 *puVar4;

  u32 *puVar5;

  u32 uVar6;

  int iVar7;

  u16 *puVar8;

  u16 *puVar9;

  u16 auStack_40 [16];

  u16 auStack_20 [16];

  

  puVar4 = *(u32 **)(*(int *)(param_4 + 0x24) + 0x44);

  if (*(int *)(param_4 + 0xc) == param_5) {

    puVar9 = (u16 *)(&DAT_006aeee0);

    puVar8 = auStack_20;

    iVar7 = 6;

    do {

      uVar1 = *puVar9;

      uVar2 = puVar9[1];

      puVar9 = puVar9 + 2;

      iVar7 = iVar7 + -1;

      *puVar8 = uVar1;

      puVar8[1] = uVar2;

      puVar8 = puVar8 + 2;

    } while (0 < iVar7);

    puVar5 = *(u32 **)(*(int *)(param_5 + 0x14) + 0x1c);

    if ((*puVar5 & 2) != 0) {

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_20[(short)puVar4[1] * 4],0);

      uVar6 = *puVar5;

      if ((uVar6 & 8) == 0) {

        if ((uVar6 & 4) != 0) {

          FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_20[(short)puVar4[1] * 4 + 1],0);

        }

      }

      else {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_20[(short)puVar4[1] * 4 + 2],0);

      }

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_20[(short)puVar4[1] * 4 + 3],0);

    }

    if ((*puVar4 & 1) == 0) {

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x23,0);

    }

    sVar3 = *(short *)((int)puVar4 + 6);

    if ((sVar3 == -2) || (sVar3 == -3)) {
      FUN_003f55b0(param_1,param_2,param_3,param_4,param_5,3);
    }
    else if (sVar3 == -5) {
      FUN_003f5830(param_1,param_2,param_3,param_4,param_5,3);
    }
    else {
      FUN_003f55b0(param_1,param_2,param_3,param_4,param_5,1);
    }

  }

  else {

    puVar9 = (u16 *)(&DAT_006aeee0);

    puVar8 = auStack_40;

    iVar7 = 6;

    do {

      uVar1 = *puVar9;

      uVar2 = puVar9[1];

      puVar9 = puVar9 + 2;

      iVar7 = iVar7 + -1;

      *puVar8 = uVar1;

      puVar8[1] = uVar2;

      puVar8 = puVar8 + 2;

    } while (0 < iVar7);

    puVar5 = *(u32 **)(*(int *)(param_5 + 0x14) + 0x1c);

    if ((*puVar5 & 2) != 0) {

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_40[(short)puVar4[1] * 4],0);

      uVar6 = *puVar5;

      if ((uVar6 & 8) == 0) {

        if ((uVar6 & 4) != 0) {

          FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_40[(short)puVar4[1] * 4 + 1],0);

        }

      }

      else {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_40[(short)puVar4[1] * 4 + 2],0);

      }

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_40[(short)puVar4[1] * 4 + 3],0);

    }

    sVar3 = *(short *)((int)puVar4 + 6);

    if ((sVar3 == -2) || (sVar3 == -3)) {
      FUN_003f55b0(param_1,param_2,param_3,param_4,param_5,2);
    }
    else if (sVar3 == -5) {
      FUN_003f5830(param_1,param_2,param_3,param_4,param_5,2);
    }
    else {
      FUN_003f55b0(param_1,param_2,param_3,param_4,param_5,0);
    }

  }

  return;

}

// Retyped params to match retail's dispatch to func_003f7d50/7fe0/8180
// (int coords/index, not u64); case 0xc/1 now byte-identical to retail.
// Residual: case 0x14's two adds route through a scratch reg instead of
// landing directly in $a0/$a1 - compiler scheduling floor.
// FUN_003F85A0 NONMATCHING


void FUN_003f85a0(int param_1,int param_2,u64 param_3,int param_4,

                 int param_5)



{

  int iVar1;

  int lVar2;

  

  lVar2 = FUN_003c6e10(param_4);

  switch (lVar2) {
  case 0xc:
    FUN_003f7d50(param_1,param_2,param_3,param_4,param_5);
    break;
  case 0x14:
    iVar1 = *(int *)(*(int *)(param_4 + 0x24) + 0x44);
    FUN_003f7fe0(param_1 + *(short *)(iVar1 + 0x28),
                 param_2 + *(short *)(iVar1 + 0x2a),param_3,param_4,param_5);
    break;
  case 1:
    FUN_003f8180(param_1,param_2,param_3,param_4,param_5);
    break;
  }

  return;

}

// FUN_003F86A0 NONMATCHING


void FUN_003f86a0(int param_1,int param_2,u32 param_3,int param_4,int param_5
                 )
{
  u16 uVar1;
  u16 uVar2;
  u32 *puVar3;
  u32 *puVar4;
  u32 uVar5;
  int lVar6;
  u16 *puVar7;
  u16 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  u16 auStack_20[16];

  iVar12 = (int)param_1;
  iVar13 = (int)param_2;
  iVar9 = (int)param_4;
  puVar3 = *(u32 **)(*(int *)(iVar9 + 0x24) + 0x44);
  lVar6 = FUN_003c6e10(iVar9);
  if (lVar6 == 1) {
    puVar8 = (u16 *)(&DAT_006aeee0);
    puVar7 = auStack_20;
    iVar10 = 6;
    do {
      uVar1 = *puVar8;
      uVar2 = puVar8[1];
      puVar8 = puVar8 + 2;
      iVar10 = iVar10 + -1;
      *puVar7 = uVar1;
      puVar7[1] = uVar2;
      puVar7 = puVar7 + 2;
    } while (0 < iVar10);
    iVar10 = *(int *)(*(int *)(iVar9 + 0x24) + 0x44);
    puVar4 = *(u32 **)(*(int *)(param_5 + 0x14) + 0x1c);
    if ((*puVar4 & 2) != 0) {
      FUN_0040e3c0_f32(0,iVar12,iVar13,param_3 & 0xff,
                       auStack_20[*(short *)(iVar10 + 4) * 4],0);
      uVar5 = *puVar4;
      if ((uVar5 & 8) == 0) {
        if ((uVar5 & 4) != 0) {
          FUN_0040e3c0_f32(0,iVar12,iVar13,param_3 & 0xff,
                           auStack_20[*(short *)(iVar10 + 4) * 4 + 1],0);
        }
      }
      else {
        FUN_0040e3c0_f32(0,iVar12,iVar13,param_3 & 0xff,
                         auStack_20[*(short *)(iVar10 + 4) * 4 + 2],0);
      }
      FUN_0040e3c0_f32(0,iVar12,iVar13,param_3 & 0xff,
                       auStack_20[*(short *)(iVar10 + 4) * 4 + 3],0);
    }
    if (*(int *)(iVar9 + 0xc) == param_5) {
      if ((*puVar3 & 1) == 0) {
        FUN_0040e3c0_f32(0,iVar12,iVar13,param_3 & 0xff,0x25,0);
      }
      FUN_003f55b0_i(iVar12,iVar13,param_3,iVar9,param_5,1);
    }
    else {
      FUN_003f55b0_i(iVar12,iVar13,param_3,iVar9,param_5,0);
    }
  }
  else if (lVar6 == 0x14) {
    iVar11 = (int)param_1 + (int)(short)puVar3[10];
    iVar10 = (int)param_2 + (int)*(short *)((int)puVar3 + 0x2a);
    if (*(int *)(iVar9 + 0xc) == param_5) {
      FUN_0040e3c0_f32(0,iVar11,iVar10,param_3 & 0xff,0x25,0);
      FUN_003f55b0_i(iVar11,iVar10,param_3,iVar9,param_5,1);
    }
    else {
      FUN_003f55b0_i(iVar11,iVar10,param_3,iVar9,param_5,0);
    }
  }
  else if (lVar6 == 0xc) {
    if (*(int *)(iVar9 + 0xc) == param_5) {
      FUN_0040e3c0_f32(0,iVar12,iVar13,param_3 & 0xff,0x25,0);
      FUN_003f55b0_i(iVar12,iVar13,param_3,iVar9,param_5,1);
    }
    else {
      FUN_003f55b0_i(iVar12,iVar13,param_3,iVar9,param_5,0);
    }
  }
  return;
}

// FUN_003F8A00 NONMATCHING


void FUN_003f8a00(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5

                 )



{

  short sVar1;

  u16 uVar2;

  u16 uVar3;

  u32 *puVar4;

  u32 *puVar5;

  long lVar6;

  int iVar7;

  int iVar8;

  u16 *puVar9;

  u16 *puVar10;

  int iVar11;

  int iVar12;

  u32 uVar13;

  u16 auStack_20 [16];

  

  uVar13 = 0;

  iVar12 = 0;

  iVar11 = (int)param_4;

  puVar4 = *(u32 **)(*(int *)(iVar11 + 0x24) + 0x44);

  lVar6 = FUN_003c6e10(param_4);

  if (lVar6 == 0xc) {
    puVar10 = (u16 *)(&DAT_006aeee0);
    puVar9 = auStack_20;
    iVar12 = 6;
    do {
      uVar2 = *puVar10;
      uVar3 = puVar10[1];
      puVar10 = puVar10 + 2;
      iVar12 = iVar12 + -1;
      *puVar9 = uVar2;
      puVar9[1] = uVar3;
      puVar9 = puVar9 + 2;
    } while (0 < iVar12);
    iVar12 = *(int *)(*(int *)(iVar11 + 0x24) + 0x44);
    puVar5 = *(u32 **)(*(int *)(param_5 + 0x14) + 0x1c);
    if ((*puVar5 & 2) != 0) {
      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,
                   auStack_20[*(short *)(iVar12 + 4) * 4],0);
      uVar13 = *puVar5;
      if ((uVar13 & 8) == 0) {
        if ((uVar13 & 4) != 0) {
          FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,
                       auStack_20[*(short *)(iVar12 + 4) * 4 + 1],0);
        }
      }
      else {
        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,
                     auStack_20[*(short *)(iVar12 + 4) * 4 + 2],0);
      }
      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,
                   auStack_20[*(short *)(iVar12 + 4) * 4 + 3],0);
    }
    if (*(int *)(iVar11 + 0xc) == param_5) {
      if ((*puVar4 & 1) == 0) {
        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x23,0);
      }
      FUN_003f55b0(param_1,param_2,param_3,param_4,param_5,1);
    }
    else {
      FUN_003f55b0(param_1,param_2,param_3,param_4,param_5,0);
    }
  }
  else if (lVar6 == 0x14) {
    iVar8 = (int)param_1 + (int)(short)puVar4[10];
    iVar12 = (int)param_2 + (int)*(short *)((int)puVar4 + 0x2a);
    if (*(int *)(iVar11 + 0xc) == param_5) {
      FUN_0040e3c0(0,iVar8,iVar12,param_3 & 0xff,0x23,0);
      FUN_003f55b0(iVar8,iVar12,param_3,param_4,param_5,1);
    }
    else {
      FUN_003f55b0(iVar8,iVar12,param_3,param_4,param_5,0);
    }
  }
  else if (lVar6 == 1) {
    sVar1 = *(short *)(*(int *)(iVar11 + 0x24) + 4);
    iVar8 = *(int *)(*(int *)(param_5 + 0x14) + 0xc) -
            *(int *)(*(int *)(*(int *)(*(int *)(iVar11 + 0x24) + 0x2c) + 0x14) + 0xc);
    if (((long)iVar8 <= (long)sVar1) && (iVar12 = sVar1 - iVar8, 4 < iVar12)) {
      iVar12 = 5;
    }
    iVar8 = (int)param_1 - (0x1e - (iVar12 * 0x1e) / 5);
    iVar12 = (iVar12 * 0xff) / 5;
    if (3 < (long)sVar1) {
      iVar7 = sVar1 + -4;
      if (4 < iVar7) {
        iVar7 = 5;
      }
      uVar13 = (iVar7 * 0xff) / 5;
    }
    if (*(int *)(iVar11 + 0xc) == param_5) {
      FUN_0040e3c0(0,param_1,param_2,uVar13 & 0xff,0x23,0);
      FUN_003f55b0(param_1,param_2,param_3,param_4,param_5,1);
    }
    else {
      FUN_003f55b0(param_1,param_2,param_3,param_4,param_5,0);
    }
  }

  return;

}

// FUN_003F8E10 NONMATCHING


void FUN_003f8e10(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5

                 )



{

  short sVar1;

  u16 uVar2;

  u16 uVar3;

  u32 *puVar4;

  u32 *puVar5;

  long lVar6;

  int iVar7;

  int iVar8;

  u16 *puVar9;

  u16 *puVar10;

  int iVar11;

  int iVar12;

  u32 uVar13;

  u16 auStack_20 [16];

  

  uVar13 = 0;

  iVar12 = 0;

  iVar11 = (int)param_4;

  puVar4 = *(u32 **)(*(int *)(iVar11 + 0x24) + 0x44);

  lVar6 = FUN_003c6e10(param_4);

  if (lVar6 == 0xc) {
    puVar10 = (u16 *)(&DAT_006aeee0);
    puVar9 = auStack_20;
    iVar12 = 6;
    do {
      uVar2 = *puVar10;
      uVar3 = puVar10[1];
      puVar10 = puVar10 + 2;
      iVar12 = iVar12 + -1;
      *puVar9 = uVar2;
      puVar9[1] = uVar3;
      puVar9 = puVar9 + 2;
    } while (0 < iVar12);
    iVar12 = *(int *)(*(int *)(iVar11 + 0x24) + 0x44);
    puVar5 = *(u32 **)(*(int *)(param_5 + 0x14) + 0x1c);
    if ((*puVar5 & 2) != 0) {
      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,
                   auStack_20[*(short *)(iVar12 + 4) * 4],0);
      uVar13 = *puVar5;
      if ((uVar13 & 8) == 0) {
        if ((uVar13 & 4) != 0) {
          FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,
                       auStack_20[*(short *)(iVar12 + 4) * 4 + 1],0);
        }
      }
      else {
        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,
                     auStack_20[*(short *)(iVar12 + 4) * 4 + 2],0);
      }
      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,
                   auStack_20[*(short *)(iVar12 + 4) * 4 + 3],0);
    }
    if (*(int *)(iVar11 + 0xc) == param_5) {
      if ((*puVar4 & 1) == 0) {
        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x27,0);
      }
      FUN_003f55b0(param_1,param_2,param_3,param_4,param_5,1);
    }
    else {
      FUN_003f55b0(param_1,param_2,param_3,param_4,param_5,0);
    }
  }
  else if (lVar6 == 0x14) {
    iVar8 = (int)param_1 + (int)(short)puVar4[10];
    iVar12 = (int)param_2 + (int)*(short *)((int)puVar4 + 0x2a);
    if (*(int *)(iVar11 + 0xc) == param_5) {
      FUN_0040e3c0(0,iVar8,iVar12,param_3 & 0xff,0x27,0);
      FUN_003f55b0(iVar8,iVar12,param_3,param_4,param_5,1);
    }
    else {
      FUN_003f55b0(iVar8,iVar12,param_3,param_4,param_5,0);
    }
  }
  else if (lVar6 == 1) {
    sVar1 = *(short *)(*(int *)(iVar11 + 0x24) + 4);
    iVar8 = *(int *)(*(int *)(param_5 + 0x14) + 0xc) -
            *(int *)(*(int *)(*(int *)(*(int *)(iVar11 + 0x24) + 0x2c) + 0x14) + 0xc);
    if (((long)iVar8 <= (long)sVar1) && (iVar12 = sVar1 - iVar8, 4 < iVar12)) {
      iVar12 = 5;
    }
    iVar8 = (int)param_1 - (0x1e - (iVar12 * 0x1e) / 5);
    iVar12 = (iVar12 * 0xff) / 5;
    if (3 < (long)sVar1) {
      iVar7 = sVar1 + -4;
      if (4 < iVar7) {
        iVar7 = 5;
      }
      uVar13 = (iVar7 * 0xff) / 5;
    }
    if (*(int *)(iVar11 + 0xc) == param_5) {
      FUN_0040e3c0(0,param_1,param_2,uVar13 & 0xff,0x27,0);
      FUN_003f55b0(param_1,param_2,param_3,param_4,param_5,1);
    }
    else {
      FUN_003f55b0(param_1,param_2,param_3,param_4,param_5,0);
    }
  }

  return;

}

// FUN_003F9220 NONMATCHING


void FUN_003f9220(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5

                 )



{

  short sVar1;

  u32 *puVar2;

  long lVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  u32 uVar8;

  

  uVar8 = 0;

  iVar7 = 0;

  iVar6 = (int)param_4;

  puVar2 = *(u32 **)(*(int *)(iVar6 + 0x24) + 0x44);

  lVar3 = FUN_003c6e10(param_4);

  if (lVar3 == 0xc) {
    sVar1 = *(short *)(*(int *)(iVar6 + 0x24) + 4);
    iVar5 = *(int *)(*(int *)(param_5 + 0x14) + 0xc) -
            *(int *)(*(int *)(*(int *)(*(int *)(iVar6 + 0x24) + 0x2c) + 0x14) + 0xc);
    if (((long)iVar5 <= (long)sVar1) && (iVar7 = sVar1 - iVar5, 4 < iVar7)) {
      iVar7 = 5;
    }
    iVar5 = (int)param_1 - (0x1e - (iVar7 * 0x1e) / 5);
    iVar7 = (iVar7 * 0xff) / 5;
    if (3 < (long)sVar1) {
      iVar4 = sVar1 + -4;
      if (4 < iVar4) {
        iVar4 = 5;
      }
      uVar8 = (iVar4 * 0xff) / 5;
    }
    if (*(int *)(iVar6 + 0xc) == param_5) {
      FUN_0040e3c0(0,param_1,param_2,uVar8 & 0xff,0x17,0);
      FUN_003f55b0(param_1,param_2,param_3,param_4,param_5,1);
    }
    else {
      FUN_003f55b0(param_1,param_2,param_3,param_4,param_5,0);
    }
  }
  else if (lVar3 == 0x14) {
    iVar5 = (int)param_1 + (int)(short)puVar2[10];
    iVar7 = (int)param_2 + (int)*(short *)((int)puVar2 + 0x2a);
    if (*(int *)(iVar6 + 0xc) == param_5) {
      FUN_0040e3c0(0,iVar5,iVar7,param_3 & 0xff,0x17,0);
      FUN_003f55b0(iVar5,iVar7,param_3,param_4,param_5,1);
    }
    else {
      FUN_003f55b0(iVar5,iVar7,param_3,param_4,param_5,0);
    }
  }
  else if (lVar3 == 1) {
    if (*(int *)(iVar6 + 0xc) == param_5) {
      if ((*puVar2 & 1) == 0) {
        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x17,0);
      }
      FUN_003f55b0(param_1,param_2,param_3,param_4,param_5,1);
    }
    else {
      FUN_003f55b0(param_1,param_2,param_3,param_4,param_5,0);
    }
  }

  return;

}

// FUN_003F9510 NONMATCHING


void FUN_003f9510(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5

                 )



{

  short sVar1;

  u32 *puVar2;

  long lVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  code *pcVar7;

  u32 uVar8;

  int iVar9;

  int iVar10;

  u8 uStack_20;

  u32 auStack_10 [4];

  

  uStack_20 = 0;

  iVar9 = 0;

  uVar8 = 0;

  auStack_10[0] = DAT_006af000;

  auStack_10[1] = DAT_006af004;

  auStack_10[2] = DAT_006af008;

  iVar6 = (int)param_4;

  puVar2 = *(u32 **)(*(int *)(iVar6 + 0x24) + 0x44);

  sVar1 = *(short *)((int)puVar2 + 6);

  if (sVar1 == -5) {

    uVar8 = 2;

    iVar10 = 2;


  }

  else if (sVar1 == -4) {

    uVar8 = 6;

    iVar10 = 1;


  }

  else if ((sVar1 == -3) || (sVar1 == -2)) {

    uVar8 = 2;

    iVar10 = 1;


  }

  else {

    iVar10 = 0;


  }

  lVar3 = FUN_003c6e10(param_4);

  if (lVar3 == 1) {

    if (*(int *)(iVar6 + 0xc) == param_5) {

      if ((*puVar2 & 1) == 0) {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_10[iVar10],0);

      }

      (*pcVar7)(param_1,param_2,param_3,param_4,param_5,uVar8 | 1);

    }

    else {

      (*pcVar7)(param_1,param_2,param_3,param_4,param_5,uVar8);

    }

  }

  else if (lVar3 == 0x14) {

    iVar5 = (int)param_1 + (int)(short)puVar2[10];

    iVar9 = (int)param_2 + (int)*(short *)((int)puVar2 + 0x2a);

    if (*(int *)(iVar6 + 0xc) == param_5) {

      FUN_0040e3c0(0,iVar5,iVar9,param_3 & 0xff,auStack_10[iVar10],0);

      (*pcVar7)(iVar5,iVar9,param_3,param_4,param_5,uVar8 | 1);

    }

    else {

      (*pcVar7)(iVar5,iVar9,param_3,param_4,param_5,uVar8);

    }

  }

  else if (lVar3 == 0xc) {

    sVar1 = *(short *)(*(int *)(iVar6 + 0x24) + 4);

    iVar5 = *(int *)(*(int *)(param_5 + 0x14) + 0xc) -

            *(int *)(*(int *)(*(int *)(*(int *)(iVar6 + 0x24) + 0x2c) + 0x14) + 0xc);

    if (((long)iVar5 <= (long)sVar1) && (iVar9 = sVar1 - iVar5, 4 < iVar9)) {

      iVar9 = 5;

    }

    iVar5 = (int)param_1 - (0x1e - (iVar9 * 0x1e) / 5);

    iVar9 = (iVar9 * 0xff) / 5;

    if (3 < (long)sVar1) {

      iVar4 = sVar1 + -4;

      if (4 < iVar4) {

        iVar4 = 5;

      }

      uStack_20 = (u8)((iVar4 * 0xff) / 5);

    }

    if (*(int *)(iVar6 + 0xc) == param_5) {

      FUN_0040e3c0(0,param_1,param_2,uStack_20,auStack_10[iVar10],0);

      (*pcVar7)(iVar5,param_2,iVar9,param_4,param_5,uVar8 | 1);

    }

    else {

      (*pcVar7)(iVar5,param_2,iVar9,param_4,param_5,uVar8);

    }

  }

  return;

}

// FUN_003F98F0 NONMATCHING


u32 FUN_003f98f0(u16 param_1)



{

  u32 uVar1;

  u16 *puVar2;

  

  puVar2 = (u16 *)(&DAT_006acca0);

  uVar1 = 0;

  do {

    if (0xf < uVar1) {

      return 1;

    }

    if ((*puVar2 == 0) && (puVar2[1] != 0)) {

      K_Assert((const char *)(u32)0x6aede8,0xe12);

    }

    if (puVar2[1] == 0) {

      if (param_1 == *puVar2) {

        return 0;

      }

    }

    else if ((*puVar2 <= param_1) && (param_1 <= puVar2[1])) {

      return 0;

    }

    puVar2 = puVar2 + 2;

    uVar1 = uVar1 + 1;

  } while( 1 );

}

// FUN_003F99D0 NONMATCHING


u64 FUN_003f99d0(u64 param_1,u32 param_2)



{

  u32 *puVar1;

  u32 uVar2;

  short sVar3;

  int iVar4;

  u32 uVar5;

  long lVar6;

  u32 uVar7;

  u8 auStack_20 [4];

  u32 uStack_1c;

  

  for (uVar7 = 0; (long)uVar7 < 300; uVar7 = (u32)((int)uVar7 + 1)) {

    uVar5 = func_0016f720(1,uVar7);

    if ((((param_2 & uVar5) != 0) && (lVar6 = FUN_003f1dc0(1,(long)auStack_20,uVar7), lVar6 != 0)) &&

       (lVar6 = FUN_003f98f0(uVar7 & 0xffff), lVar6 != 0)) {

      iVar4 = FUN_003c5a40(param_1,*(u16 *)((int)param_1 + 0x10) + 1,0x20,0);

      puVar1 = *(u32 **)(*(int *)(iVar4 + 0x14) + 0x1c);

      memcpy(puVar1 + 1,auStack_20,0x1c);

      if (((uStack_1c & 0x1000) != 0) &&

         (sVar3 = datGetEquipmentIdx(1,(u16)(uStack_1c >> 8) & 0xf), uVar7 == (long)sVar3)) {

        uVar2 = *puVar1;

        *puVar1 = uVar2 | 0x10;

        *puVar1 = uVar2 | 0x50;

      }

      uVar2 = puVar1[4];

      puVar1[4] = (int)uVar2 >> 2;

      if ((int)uVar2 >> 2 < 1) {

        puVar1[4] = 1;

      }

    }

  }

  return 0;

}

// Window was wrongly 784B (should be 400B) - see FUN_003f9cb0 split below.
// Full logic rewritten from retail disasm: if/else order, switch-based
// dispatch, and int/long typing all fixed. Residual: register-bank
// choice for param_1/param_2 (s2/s1 in retail vs s5/s4 here).
// FUN_003F9B20 NONMATCHING


u64 FUN_003f9b20(u64 param_1,int param_2)



{

  short sVar1;

  int iVar2;

  int sVar3;

  u32 uVar4;

  long lVar5;

  int iVar7;

  int iVar6;

  int iStack_4;

  

  iVar2 = *(int *)(*(int *)(param_2 + 0x14) + 0x1c);

  if ((*(u32 *)(iVar2 + 8) & 0x4000) != 0) {

    sVar1 = *(short *)(iVar2 + 4);

    iStack_4 = -1;

    sVar3 = 0;

    func_00170ed0(sVar1,&iStack_4);

    switch (iStack_4) {
    case 0:
    case 1:
    case 2:
    case 3:
      sVar3 = 0;
      lVar5 = sVar1;
      for (iVar6 = 0; iVar6 < 300; iVar6 = iVar6 + 1) {
        uVar4 = datGetEquipmentId(1,iVar6);
        if (lVar5 == (uVar4 & 0xffff)) {
          sVar3 = sVar3 + 1;
        }
      }
      break;
    case 4:
      sVar3 = func_00170760(1,sVar1) & 0xffff;
      break;
    }

    *(short *)(iVar2 + 0xe) = sVar3;

  }

  else {

    iVar7 = datGetEquipmentId(1,*(short *)(iVar2 + 6));

    if (iVar7 != 0) {

      *(u16 *)(iVar2 + 0xe) = 1;

    }

    else {

      *(u16 *)(iVar2 + 0xe) = 0;

    }

  }

  if (*(short *)(iVar2 + 0xe) == 0) {

    FUN_003c5fa0(param_1,param_2);

  }

  return 0;

}

// Hidden sibling: only referenced via FUN_003c7000(uVar7,0x3f9cb0,0) as a
// raw callback pointer literal in FUN_003f9e30 below, never via jal, so
// Ghidra's boundary scan absorbed it into FUN_003f9b20's window (784B
// instead of the true 400B). Splitting it out here as its own function
// per the p3-window-nullsub-discovery Case C procedure.
#pragma push
#pragma opt_rebuildconditionals off
// FUN_003F9CB0
s32 FUN_003f9cb0(u32 *param_1, u32 *param_2)
{
  u32 entryA;
  u32 entryB;
  s32 fieldA;
  s32 fieldB;
  s32 result;
  s32 flagA;
  s32 flagB;
  s32 catA;
  s32 catB;

  entryA = *(u32 *)(*param_1 + 0x14);
  entryA = *(u32 *)(entryA + 0x1c);
  entryB = *(u32 *)(*param_2 + 0x14);
  entryB = *(u32 *)(entryB + 0x1c);
  flagB = (*(u32 *)entryB & 0x40) == 0;
  flagA = (*(u32 *)entryA & 0x40) == 0;
  result = flagB - flagA;
  if (result != 0) {
    goto ret;
  }
  fieldB = *(u32 *)(entryB + 8);
  fieldA = *(u32 *)(entryA + 8);
  result = (fieldA & 0xff) - (fieldB & 0xff);
  if (result != 0) {
    goto ret;
  }
  switch ((fieldB & 0xf00) >> 8) {
  case 0:
    catB = *(short *)(entryB + 0x14);
    break;
  case 1:
    catB = *(short *)(entryB + 0x18);
    break;
  case 2:
    catB = *(short *)(entryB + 0x1a);
    break;
  case 4:
    catB = 0x98967f - *(int *)(entryB + 0x10);
    break;
  default:
    catB = 0;
    break;
  }
  switch ((fieldA & 0xf00) >> 8) {
  case 0:
    catA = *(short *)(entryA + 0x14);
    break;
  case 1:
    catA = *(short *)(entryA + 0x18);
    break;
  case 2:
    catA = *(short *)(entryA + 0x1a);
    break;
  case 4:
    catA = 0x98967f - *(int *)(entryA + 0x10);
    break;
  default:
    catA = 0;
    break;
  }
  result = catB - catA;
  if (result != 0) {
    goto ret;
  }
  result = *(short *)(entryB + 4) - *(short *)(entryA + 4);
ret:
  return result;
}
#pragma pop


// FUN_003F9E30 NONMATCHING


u32 FUN_003f9e30(int param_1)



{

  u32 uVar1;

  u32 uVar2;

  u8 *puVar3;

  u8 *puVar4;

  int iVar5;

  int iVar6;

  u32 uVar7;

  long lVar8;

  int iVar9;

  u32 *puVar10;

  u32 *puVar11;

  u8 **ppuVar12;

  u32 uVar13;

  u8 auStack_c0 [32];

  u32 auStack_a0 [8];

  u32 auStack_80 [8];

  u32 auStack_60 [8];

  u32 auStack_40 [16];

  

  puVar11 = &DAT_006af010;

  puVar10 = auStack_40;

  iVar9 = 8;

  do {

    uVar1 = *puVar11;

    uVar2 = puVar11[1];

    puVar11 = puVar11 + 2;

    iVar9 = iVar9 + -1;

    *puVar10 = uVar1;

    puVar10[1] = uVar2;

    puVar10 = puVar10 + 2;

  } while (0 < iVar9);

  uVar7 = FUN_003c58f0(0,0x58,5,0x1a);

  iVar5 = (int)uVar7;

  iVar9 = *(int *)(*(int *)(iVar5 + 0x24) + 0x44);

  *(short *)(iVar9 + 4) = (short)param_1;

  *(u16 *)(iVar9 + 6) = 0xffff;


  for (uVar13 = 4000; ((int)uVar13 < 0x1080 && ((int)(uVar13 - 4000) < 300)); uVar13 = uVar13 + 1) {


    if ((lVar8 != 0) && (lVar8 = FUN_003f98f0(uVar13 & 0xffff), lVar8 != 0)) {

      iVar9 = FUN_003c5a40(uVar7,*(u16 *)(iVar5 + 0x10) + 1,0x20,0);

      iVar9 = *(int *)(*(int *)(iVar9 + 0x14) + 0x1c);

      memcpy(iVar9 + 4,auStack_c0,0x1c);

      iVar6 = *(int *)(iVar9 + 0x10) >> 2;

      *(int *)(iVar9 + 0x10) = iVar6;

      if (iVar6 < 1) {

        *(u32 *)(iVar9 + 0x10) = 1;

      }

    }

  }

  FUN_003c7000(uVar7,0x3f9cb0,0);

  FUN_003c6ee0(uVar7);

  ppuVar12 = (u8 **)&PTR_FUN_006af050;

  puVar10 = auStack_60;

  iVar9 = 4;

  do {

    puVar3 = *ppuVar12;

    puVar4 = ppuVar12[1];

    ppuVar12 = ppuVar12 + 2;

    iVar9 = iVar9 + -1;

    *puVar10 = (u32)(puVar3);

    puVar10[1] = (u32)(puVar4);

    puVar10 = puVar10 + 2;

  } while (0 < iVar9);

  ppuVar12 = (u8 **)&PTR_FUN_006af070;

  puVar10 = auStack_80;

  iVar9 = 4;

  do {

    puVar3 = *ppuVar12;

    puVar4 = ppuVar12[1];

    ppuVar12 = ppuVar12 + 2;

    iVar9 = iVar9 + -1;

    *puVar10 = (u32)(puVar3);

    puVar10[1] = (u32)(puVar4);

    puVar10 = puVar10 + 2;

  } while (0 < iVar9);

  ppuVar12 = (u8 **)&PTR_FUN_006af090;

  puVar10 = auStack_a0;

  iVar9 = 4;

  do {

    puVar3 = *ppuVar12;

    puVar4 = ppuVar12[1];

    ppuVar12 = ppuVar12 + 2;

    iVar9 = iVar9 + -1;

    *puVar10 = (u32)(puVar3);

    puVar10[1] = (u32)(puVar4);

    puVar10 = puVar10 + 2;

  } while (0 < iVar9);

  FUN_003c5e80(uVar7,auStack_60[param_1]);

  FUN_003c5e20(uVar7,auStack_80[param_1]);

  FUN_003c5ee0(uVar7,auStack_a0[param_1]);

  FUN_003c6d40(uVar7,auStack_40[param_1 * 2],auStack_40[param_1 * 2 + 1]);

  *(u16 *)(*(int *)(iVar5 + 0x24) + 6) = 0x14;

  *(u16 *)(*(int *)(iVar5 + 0x24) + 8) = 10;

  return uVar7;

}

// FUN_003FA0D0


u32 FUN_003fa0d0(u64 param_1)
{
  u32 uVar1;
  u32 lVar2;

  
  uVar1 = FUN_003fa1e0_u32();

  if ((lVar2 = FUN_003c6ce0(param_1), lVar2 != 0) ||
      (lVar2 = FUN_003c6d10(param_1), lVar2 != 0)) {

    func_0010a4e0(0,0,0,0);

  }

  lVar2 = FUN_003c6ca0(param_1);

  if ((lVar2 != 0) || (lVar2 = FUN_003c6cc0(param_1), lVar2 != 0)) {

    func_0010a4e0(0,0,0,5);

  }

  return uVar1;

}

// FUN_003FA190


u64 FUN_003fa190(int param_1)



{

  u32 *puVar1;

  

  puVar1 = *(u32 **)(*(int *)(param_1 + 0x24) + 0x44);

  *puVar1 = *puVar1 | 1;

  return 0;

}

// FUN_003FA1B0


u64 FUN_003fa1b0(int param_1)



{

  u32 *puVar1;

  

  puVar1 = *(u32 **)(*(int *)(param_1 + 0x24) + 0x44);

  *puVar1 = *puVar1 & 0xfffffffe;

  return 0;

}

// FUN_003FA1E0


u8 FUN_003fa1e0(void)
{
  return FUN_003c6270() == 3;
}

// FUN_003FA210 NONMATCHING


void FUN_003fa210(int param_1)



{

  short sVar1;

  int iVar2;

  long lVar3;

  int iVar4;

  

  iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x44);

  lVar3 = FUN_003c6e10();

  if (lVar3 != 1) {

    if (lVar3 == 0x14) {

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 0xb) {

        *(short *)(iVar2 + 0x28) = (short)(int)((float)(sVar1 * -0xa0) / 10.0f);

      }

      else {

        *(u16 *)(iVar2 + 0x28) = 0xff60;

      }

      if (sVar1 < 6) {

        *(short *)(iVar2 + 0x34) = (short)(int)((float)(sVar1 * -0xff) / 5.0f + 255.0f);

      }

      else {

        *(u16 *)(iVar2 + 0x34) = 0;

      }

    }

    else if (lVar3 == 0xc) {

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      *(u16 *)(iVar2 + 0x28) = 0;

      *(u16 *)(iVar2 + 0x2a) = 0;

      if (sVar1 < 6) {

        *(short *)(iVar2 + 0x34) = (short)(int)((float)(sVar1 * 0xff) / 5.0f);

      }

      else {

        *(u16 *)(iVar2 + 0x34) = 0xff;

      }

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 6) {

        *(u16 *)(iVar2 + 0x38) = 0xff38;

        *(u16 *)(iVar2 + 0x44) = 0;

      }

      else {

        iVar4 = sVar1 + -6;

        if (iVar4 < 5) {

          *(short *)(iVar2 + 0x38) = (short)(int)((float)(iVar4 * 0x8c) / 4.0f + -140.0f);

          *(u16 *)(iVar2 + 0x3a) = 0;

          *(u16 *)(iVar2 + 0x44) = 0xff;

        }

      }

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 8) {

        *(u16 *)(iVar2 + 0x54) = 0;

      }

      else {

        iVar4 = sVar1 + -8;

        if (iVar4 < 6) {

          *(u16 *)(iVar2 + 0x54) = 0xff;

          *(float *)(iVar2 + 0x50) = fGpffff8234 + (fGpffff8230 * (float)iVar4) / 5.0f;

        }

      }

      if ((0xc < sVar1) && (iVar4 = sVar1 + -0xd, iVar4 < 5)) {

        *(short *)(iVar2 + 0x4a) = (short)(int)((float)(iVar4 * -3) / 4.0f + 3.0f);

        *(float *)(iVar2 + 0x50) = fGpffff823c + (fGpffff8238 * (float)iVar4) / 4.0f;

      }

    }

  }

  return;

}

// FUN_003FA520


void FUN_003fa520(int param_1)



{

  short sVar1;

  int iVar2;

  int lVar3;

  int iVar4;

  

  iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x44);

  lVar3 = FUN_003c6e10();

  if (lVar3 != 1) {

    switch (lVar3) {

    case 0xc:

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      *(u16 *)(iVar2 + 0x28) = 0;

      *(u16 *)(iVar2 + 0x2a) = 0;

      if (sVar1 < 6) {

        *(short *)(iVar2 + 0x34) = (short)(int)((float)(sVar1 * 0xff) / 5.0f);

      }

      else {

        *(u16 *)(iVar2 + 0x34) = 0xff;

      }

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 5) {

        *(short *)(iVar2 + 0x38) = (short)(int)((float)(sVar1 * 0xa0) / 4.0f + -160.0f);

        *(u16 *)(iVar2 + 0x3a) = 0;

        *(u16 *)(iVar2 + 0x44) = 0xff;

      }

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 8) {

        *(u16 *)(iVar2 + 0x54) = 0;

      }

      else {

        iVar4 = sVar1 + -8;

        if (iVar4 < 6) {

          *(u16 *)(iVar2 + 0x54) = 0xff;

          *(float *)(iVar2 + 0x50) = fGpffff8234 + (fGpffff8230 * (float)iVar4) / 5.0f;

        }

      }

      iVar4 = sVar1 < 0xd;

      if (iVar4) goto done;

      iVar4 = sVar1 + -0xd;

      if (iVar4 >= 5) goto done;

      *(short *)(iVar2 + 0x4a) = (short)(int)((float)(iVar4 * -3) / 4.0f + 3.0f);

      *(float *)(iVar2 + 0x50) = fGpffff823c + (fGpffff8238 * (float)iVar4) / 4.0f;

      goto done;

    case 0x14:

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 0xb) {

        *(short *)(iVar2 + 0x28) = (short)(int)((float)(sVar1 * -0xa0) / 10.0f);

      }

      else {

      *(short *)(iVar2 + 0x28) = -0xa0;

      }

      if (sVar1 < 6) {

        *(short *)(iVar2 + 0x34) = (short)(int)((float)(sVar1 * -0xff) / 5.0f + 255.0f);

      }

      else {

        *(u16 *)(iVar2 + 0x34) = 0;

      }

    }

  }

done:

  return;

}

// FUN_003FA800


void FUN_003fa800(int param_1)



{

  short sVar1;

  int iVar2;

  int lVar3;

  int iVar4;

  

  iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x44);

  lVar3 = FUN_003c6e10();

  if (lVar3 != 1) {

    switch (lVar3) {

    case 0xc:

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      *(u16 *)(iVar2 + 0x28) = 0;

      *(u16 *)(iVar2 + 0x2a) = 0;

      if (sVar1 < 6) {

        *(short *)(iVar2 + 0x34) = (short)(int)((float)(sVar1 * 0xff) / 5.0f);

      }

      else {

        *(u16 *)(iVar2 + 0x34) = 0xff;

      }

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 5) {

        *(short *)(iVar2 + 0x38) = (short)(int)((float)(sVar1 * 0xa0) / 4.0f + -160.0f);

        *(u16 *)(iVar2 + 0x3a) = 0;

        *(u16 *)(iVar2 + 0x44) = 0xff;

      }

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 8) {

        *(u16 *)(iVar2 + 0x54) = 0;

      }

      else {

        iVar4 = sVar1 + -8;

        if (iVar4 < 6) {

          *(u16 *)(iVar2 + 0x54) = 0xff;

          *(float *)(iVar2 + 0x50) = fGpffff8234 + (fGpffff8230 * (float)iVar4) / 5.0f;

        }

      }

      iVar4 = sVar1 < 0xd;

      if (iVar4) goto done;

      iVar4 = sVar1 + -0xd;

      if (iVar4 >= 5) goto done;

      *(short *)(iVar2 + 0x4a) = (short)(int)((float)(iVar4 * -3) / 4.0f + 3.0f);

      *(float *)(iVar2 + 0x50) = fGpffff823c + (fGpffff8238 * (float)iVar4) / 4.0f;

      goto done;

    case 0x14:

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 0xb) {

        *(short *)(iVar2 + 0x28) = (short)(int)((float)(sVar1 * -0xa0) / 10.0f);

      }

      else {

        *(short *)(iVar2 + 0x28) = -0xa0;

      }

      if (sVar1 < 6) {

        *(short *)(iVar2 + 0x34) = (short)(int)((float)(sVar1 * -0xff) / 5.0f + 255.0f);

      }

      else {

        *(u16 *)(iVar2 + 0x34) = 0;

      }

    }

  }

done:

  return;

}

// FUN_003FAAE0


void FUN_003faae0(int param_1)
{
  short sVar1;
  int iVar2;
  int lVar3;
  int iVar4;

  iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x44);
  lVar3 = FUN_003c6e10();
  if (lVar3 != 1) {
    switch (lVar3) {
    case 0xc:
      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);
      *(u16 *)(iVar2 + 0x28) = 0;
      *(u16 *)(iVar2 + 0x2a) = 0;
      if (sVar1 < 6) {
        *(short *)(iVar2 + 0x34) = (short)(int)((float)(sVar1 * 0xff) / 5.0f);
      }
      else {
        *(u16 *)(iVar2 + 0x34) = 0xff;
      }
      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);
      if (sVar1 < 5) {
        *(short *)(iVar2 + 0x38) = (short)(int)((float)(sVar1 * 0xa0) / 4.0f + -160.0f);
        *(u16 *)(iVar2 + 0x3a) = 0;
        *(u16 *)(iVar2 + 0x44) = 0xff;
      }
      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);
      if (sVar1 < 8) {
        *(u16 *)(iVar2 + 0x54) = 0;
      }
      else {
        iVar4 = sVar1 + -8;
        if (iVar4 < 6) {
          *(u16 *)(iVar2 + 0x54) = 0xff;
          *(float *)(iVar2 + 0x50) = fGpffff8234 + (fGpffff8230 * (float)iVar4) / 5.0f;
        }
      }
      iVar4 = sVar1 < 0xd;
      if (iVar4) goto done;
      iVar4 = sVar1 + -0xd;
      if (iVar4 >= 5) goto done;
      *(short *)(iVar2 + 0x4a) = (short)(int)((float)(iVar4 * -3) / 4.0f + 3.0f);
      *(float *)(iVar2 + 0x50) = fGpffff823c + (fGpffff8238 * (float)iVar4) / 4.0f;
      goto done;
    case 0x14:
      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);
      if (sVar1 < 0xb) {
        *(short *)(iVar2 + 0x28) = (short)(int)((float)(sVar1 * -0xa0) / 10.0f);
      }
      else {
        *(short *)(iVar2 + 0x28) = -0xa0;
      }
      if (sVar1 < 6) {
        *(short *)(iVar2 + 0x34) = (short)(int)((float)(sVar1 * -0xff) / 5.0f + 255.0f);
      }
      else {
        *(u16 *)(iVar2 + 0x34) = 0;
      }
    }
  }
done:
  return;
}


// FUN_003FADC0 NONMATCHING


void FUN_003fadc0(int param_1)



{

  short sVar1;

  int iVar2;

  long lVar3;

  int iVar4;

  

  iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x44);

  lVar3 = FUN_003c6e10();

  if (lVar3 != 1) {

    if (lVar3 == 0x14) {

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 0xb) {

        *(short *)(iVar2 + 0x28) = (short)(int)((float)(sVar1 * -0xa0) / 10.0f);

      }

      else {

        *(u16 *)(iVar2 + 0x28) = 0xff60;

      }

      if (sVar1 < 6) {

        *(short *)(iVar2 + 0x34) = (short)(int)((float)(sVar1 * -0xff) / 5.0f + 255.0f);

      }

      else {

        *(u16 *)(iVar2 + 0x34) = 0;

      }

    }

    else if (lVar3 == 0xc) {

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      *(u16 *)(iVar2 + 0x28) = 0;

      *(u16 *)(iVar2 + 0x2a) = 0;

      if (sVar1 < 6) {

        *(short *)(iVar2 + 0x34) = (short)(int)((float)(sVar1 * 0xff) / 5.0f);

      }

      else {

        *(u16 *)(iVar2 + 0x34) = 0xff;

      }

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 6) {

        *(u16 *)(iVar2 + 0x38) = 0xff38;

        *(u16 *)(iVar2 + 0x44) = 0;

      }

      else {

        iVar4 = sVar1 + -6;

        if (iVar4 < 5) {

          *(short *)(iVar2 + 0x38) = (short)(int)((float)(iVar4 * 0x8c) / 4.0f + -140.0f);

          *(u16 *)(iVar2 + 0x3a) = 0;

          *(u16 *)(iVar2 + 0x44) = 0xff;

        }

      }

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 1) {

        *(u16 *)(iVar2 + 0x54) = 0;

      }

      else {

        iVar4 = sVar1 + -1;

        if (iVar4 < 6) {

          *(u16 *)(iVar2 + 0x54) = 0xff;

          *(float *)(iVar2 + 0x50) = fGpffff8234 + (fGpffff8230 * (float)iVar4) / 5.0f;

        }

      }

      if ((5 < sVar1) && (iVar4 = sVar1 + -5, iVar4 < 4)) {

        *(short *)(iVar2 + 0x4a) = (short)(int)((float)(iVar4 * -3) / 3.0f + 3.0f);

        *(float *)(iVar2 + 0x50) = fGpffff823c + (fGpffff8238 * (float)iVar4) / 3.0f;

      }

    }

  }

  return;

}

// FUN_003FB0C0 NONMATCHING


void FUN_003fb0c0(long param_1,long param_2)



{

  u32 uVar1;

  u16 uVar2;

  int iVar3;

  int iVar4;

  u32 *puVar5;

  

  if (param_1 == 0) {

    K_Assert((const char *)(u32)0x6aede8,0xffa);

  }

  puVar5 = (u32 *)param_1;

  *puVar5 = *puVar5 | 1;

  puVar5[2] = 1;

  *(u16 *)(puVar5 + 1) = 1;

  *(u16 *)((int)puVar5 + 0x2a) = 0;

  *(u16 *)(puVar5 + 0xb) = 0;

  *(u16 *)((int)puVar5 + 0x2e) = 0;

  if (param_2 == 0) {

    *puVar5 = *puVar5 | 2;

  }

  else {

    *puVar5 = *puVar5 | 4;

  }

  uVar1 = *puVar5;

  if ((uVar1 & 2) == 0) {

    if ((uVar1 & 4) != 0) {

      if ((long)(int)puVar5[2] < (long)*(short *)((int)puVar5 + 0x16)) {

        *puVar5 = uVar1 & 0xfffffff7;

      }

      else {

        *puVar5 = uVar1 | 8;

      }

    }

  }

  else {

    iVar3 = 99;

    if (puVar5[6] != 0) {

      iVar3 = datGetMoney();

      iVar3 = iVar3 / (int)puVar5[6];

    }

    if (99 < iVar3 + *(short *)((int)puVar5 + 0x16)) {

      iVar3 = 99 - *(short *)((int)puVar5 + 0x16);

    }

    uVar2 = FUN_003e6dc0();

    iVar4 = FUN_0017d250(uVar2,(short)puVar5[3]);

    if ((iVar4 != -1) && (iVar4 < iVar3)) {

      iVar3 = iVar4;

    }

    if ((int)puVar5[2] < iVar3) {

      *puVar5 = *puVar5 & 0xfffffff7;

    }

    else {

      *puVar5 = *puVar5 | 8;

    }

  }

  if (puVar5[2] == 1) {

    *puVar5 = *puVar5 | 0x10;

  }

  else {

    *puVar5 = *puVar5 & 0xffffffef;

  }

  return;

}

// FUN_003FB2F0 NONMATCHING


int FUN_003fb2f0(u32 *param_1)



{

  u16 uVar1;

  int iVar2;

  u32 uVar3;

  u32 uVar4;

  int iVar5;

  u32 uVar6;

  

  iVar5 = 0;

  datGetMoney();

  if (((DAT_007e0952 & 0x1000) == 0) && ((DAT_007e095a & 0x1000) == 0)) {

    if (((DAT_007e0952 & 0x4000) == 0) && ((DAT_007e095a & 0x4000) == 0)) {

      if (((DAT_007e0952 & 0x2000) == 0) && ((DAT_007e095a & 0x2000) == 0)) {

        if (((DAT_007e0952 & 0x8000) != 0) || ((DAT_007e095a & 0x8000) != 0)) {

          iVar5 = -10;

        }

      }

      else {

        iVar5 = 10;

      }

    }

    else {

      iVar5 = -1;

    }

  }

  else {

    iVar5 = 1;

  }

  if (iVar5 != 0) {

    uVar6 = param_1[2] + iVar5;

    if ((int)uVar6 < 100) {

      if ((int)uVar6 < 1) {

        uVar6 = 1;

      }

    }

    else {

      uVar6 = 99;

    }

    uVar4 = 99;

    if (param_1[6] != 0) {

      iVar2 = datGetMoney();

      uVar4 = iVar2 / (int)param_1[6];

    }

    if (99 < (int)(uVar4 + (int)*(short *)((int)param_1 + 0x16))) {

      uVar4 = 99 - (int)*(short *)((int)param_1 + 0x16);

    }

    uVar1 = FUN_003e6dc0();

    uVar3 = FUN_0017d250(uVar1,(short)param_1[3]);

    if ((uVar3 != 0xffffffff) && ((int)uVar3 < (int)uVar4)) {

      uVar4 = uVar3;

    }

    if ((int)uVar6 < (int)uVar4) {

      *param_1 = *param_1 & 0xfffffff7;

    }

    else {

      *param_1 = *param_1 | 8;

      uVar6 = uVar4;

    }

    if (uVar6 == 1) {

      *param_1 = *param_1 | 0x10;

    }

    else {

      *param_1 = *param_1 & 0xffffffef;

    }

    if (param_1[2] == uVar6) {

      iVar5 = 0;

    }

    else {

      param_1[2] = uVar6;

      if (iVar5 < 1) {

        if (iVar5 < 0) {

          iVar5 = 2;

        }

      }

      else {

        iVar5 = 1;

      }

    }

  }

  return iVar5;

}

// FUN_003FB530 NONMATCHING


int FUN_003fb530(u32 *param_1)



{

  int iVar1;

  long lVar2;

  long lVar3;

  long lVar4;

  

  iVar1 = 0;

  lVar4 = (long)*(short *)((int)param_1 + 0x16);

  if (((DAT_007e0952 & 0x1000) == 0) && ((DAT_007e095a & 0x1000) == 0)) {

    if (((DAT_007e0952 & 0x4000) == 0) && ((DAT_007e095a & 0x4000) == 0)) {

      if (((DAT_007e0952 & 0x2000) == 0) && ((DAT_007e095a & 0x2000) == 0)) {

        if (((DAT_007e0952 & 0x8000) != 0) || ((DAT_007e095a & 0x8000) != 0)) {

          iVar1 = -10;

        }

      }

      else {

        iVar1 = 10;

      }

    }

    else {

      iVar1 = -1;

    }

  }

  else {

    iVar1 = 1;

  }

  if (iVar1 != 0) {

    lVar2 = (long)(int)(param_1[2] + iVar1);

    lVar3 = lVar4;

    if ((lVar2 <= lVar4) && (lVar3 = lVar2, lVar2 < 1)) {

      lVar3 = 1;

    }

    if (lVar3 < lVar4) {

      *param_1 = *param_1 & 0xfffffff7;

    }

    else {

      *param_1 = *param_1 | 8;

    }

    if (lVar3 == 1) {

      *param_1 = *param_1 | 0x10;

    }

    else {

      *param_1 = *param_1 & 0xffffffef;

    }

    if ((int)param_1[2] == lVar3) {

      iVar1 = 0;

    }

    else {

      param_1[2] = (u32)lVar3;

      if (iVar1 < 1) {

        if (iVar1 < 0) {

          iVar1 = 2;

        }

      }

      else {

        iVar1 = 1;

      }

    }

  }

  return iVar1;

}

// FUN_003FB6B0 NONMATCHING


int FUN_003fb6b0(u64 param_1)



{

  u32 uVar1;

  short sVar2;

  int iVar3;

  long lVar4;

  u32 *puVar5;

  long lVar6;

  float fVar7;

  u8 auStack_20 [32];

  

  iVar3 = 0;

  lVar6 = 0;

  puVar5 = (u32 *)param_1;

  uVar1 = *puVar5;

  if ((uVar1 & 1) != 0) {

    switch((short)puVar5[1]) {

    case 1:

      *(u16 *)(puVar5 + 1) = 3;

      break;

    case 2:

      *puVar5 = uVar1 & 0xfffffffe;

      if ((uVar1 & 0x400) == 0) {

        if ((uVar1 & 0x800) != 0) {

          iVar3 = 2;

        }

      }

      else {

        iVar3 = 1;

      }

      uVar1 = *puVar5;

      *puVar5 = uVar1 & 0xfffffbff;

      *puVar5 = uVar1 & 0xfffff3ff;

      FUN_003eed10(0);

      return iVar3;

    case 3:

      *(u16 *)(puVar5 + 1) = 4;

      *(u16 *)((int)puVar5 + 6) = 0;

      *(u16 *)((int)puVar5 + 0x2a) = 0xff;

      *(u16 *)(puVar5 + 0xc) = 0xfe0c;

      *(u16 *)((int)puVar5 + 0x32) = 0;

      if ((*puVar5 & 2) == 0) {

        if ((*puVar5 & 4) != 0) {

          FUN_003ef970(8);

        }

      }

      else {

        FUN_003ef970(6);

      }

    case 4:

      sVar2 = *(short *)((int)puVar5 + 6) + 1;

      *(short *)((int)puVar5 + 6) = sVar2;

      fVar7 = (float)cosf((fGpffff8110 * (float)(int)sVar2) / 5.0f);

      *(short *)(puVar5 + 0xc) = (short)(int)(fVar7 * -100.0f);

      if (4 < *(short *)((int)puVar5 + 6)) {

        *(u16 *)(puVar5 + 1) = 7;

        *(u16 *)((int)puVar5 + 0x2a) = 0xff;

        *(u16 *)(puVar5 + 0xc) = 0;

        *(u16 *)((int)puVar5 + 0x32) = 0;

      }

      break;

    case 5:

      *(u16 *)(puVar5 + 1) = 6;

      *(u16 *)((int)puVar5 + 6) = 0;

      if ((*puVar5 & 2) == 0) {

        if ((*puVar5 & 4) != 0) {

          FUN_003ef970(9);

        }

      }

      else {

        FUN_003ef970(7);

      }

    case 6:

      sVar2 = *(short *)((int)puVar5 + 6) + 1;

      *(short *)((int)puVar5 + 6) = sVar2;

      *(short *)((int)puVar5 + 0x2a) = (short)(int)(255.0f - (float)(sVar2 * 0xff) / 5.0f);

      if (4 < *(short *)((int)puVar5 + 6)) {

        *(u16 *)(puVar5 + 1) = 2;

      }

      break;

    case 7:

      iVar3 = 1;

      break;

    case 8:

      lVar4 = FUN_003c7850();

      if (lVar4 == 0) {

        FUN_003c7700();

        lVar4 = FUN_003c7610();

        if (lVar4 == 0) {

          *puVar5 = *puVar5 | 0x400;

        }

        else {

          *puVar5 = *puVar5 | 0x800;

        }

        *(u16 *)(puVar5 + 1) = 5;

      }

    }

    if (iVar3 != 0) {

      if (((DAT_007e094e & 0x40) == 0) && ((DAT_007e0958 & 0x40) == 0)) {

        if (((DAT_007e094e & 0x20) == 0) && ((DAT_007e0958 & 0x20) == 0)) {

          if ((*puVar5 & 2) == 0) {

            if ((*puVar5 & 4) != 0) {


            }

          }

          else {


          }

          FUN_003eed10(puVar5[6] * puVar5[2]);

          if (lVar6 != 0) {

            func_0010a4e0(0,0,0,0);

          }

        }

        else {

          func_0010a4e0(0,0,0,2);

          *(u16 *)(puVar5 + 1) = 5;

          *puVar5 = *puVar5 | 0x800;

        }

      }

      else {

        func_0010a4e0(0,0,0,1);

        *(u16 *)(puVar5 + 1) = 8;

        sprintf((char *)auStack_20,&gp0xffffac10,puVar5[6] * puVar5[2]);

        FUN_003c7bc0(0,auStack_20);

        if ((*puVar5 & 2) == 0) {

          if ((*puVar5 & 4) != 0) {

            FUN_003c7430(6);

          }

        }

        else {

          FUN_003c7430(4);

        }

        FUN_003c74e0(0);

        FUN_003c7560(0);

      }

    }

    if ((lVar6 == 1) || ((*puVar5 & 8) != 0)) {

      *(u16 *)(puVar5 + 0xb) = 0x20;

    }

    if ((lVar6 == 2) || ((*puVar5 & 0x10) != 0)) {

      *(u16 *)((int)puVar5 + 0x2e) = 0x20;

    }

    iVar3 = (short)puVar5[0xb] + 0x20;

    if (iVar3 < 0xff) {

      *(short *)(puVar5 + 0xb) = (short)iVar3;

    }

    else {

      *(u16 *)(puVar5 + 0xb) = 0xff;

    }

    iVar3 = *(short *)((int)puVar5 + 0x2e) + 0x20;

    if (iVar3 < 0xff) {

      *(short *)((int)puVar5 + 0x2e) = (short)iVar3;

    }

    else {

      *(u16 *)((int)puVar5 + 0x2e) = 0xff;

    }

  }

  return 0;

}

// FUN_003FBC00 NONMATCHING


u64 FUN_003fbc00(u32 *param_1)



{

  short sVar1;

  short sVar2;

  u16 uVar3;

  u32 uVar4;

  u32 uVar5;

  int iVar6;

  u64 uVar7;

  int iVar8;

  u32 *puVar9;

  u32 *puVar10;

  u32 auStack_a0 [36];

  u8 auStack_10[16];

  

  iVar6 = FUN_003e6dc0();

  puVar10 = &DAT_006af0b0;

  puVar9 = auStack_a0;

  iVar8 = 0x12;

  do {

    uVar4 = *puVar10;

    uVar5 = puVar10[1];

    puVar10 = puVar10 + 2;

    iVar8 = iVar8 + -1;

    *puVar9 = uVar4;

    puVar9[1] = uVar5;

    puVar9 = puVar9 + 2;

  } while (0 < iVar8);

  if ((*param_1 & 1) != 0) {

    sVar1 = (short)param_1[0xc];

    sVar2 = *(short *)((int)param_1 + 0x32);

    uVar3 = *(u16 *)((int)param_1 + 0x2a);

    FUN_0040e3c0(0,sVar1,sVar2,uVar3 & 0xff,auStack_a0[iVar6 * 4],0);

    FUN_0040e3c0(0,sVar1 + 0x2a,sVar2 + 0x69,uVar3 & 0xff,0,(u32)(u8)param_1[4] * 2 + 1);

    uVar7 = func_00171110((short)param_1[3],(char)param_1[5]);

    FUN_003b2cb0(0,sVar1 + 0x4a,sVar2 + 0x73,uVar3 | 0xff00,6,1,uVar7,0x10,0);

    sprintf((char *)auStack_10,&gp0xffffac10,param_1[6]);

    iVar8 = (int)sVar2;

    FUN_0040eb50(0,sVar1 + 0x196,iVar8 + 0x75,uVar3 & 0xff,1,auStack_10,9);

    FUN_0040e3c0(0,sVar1,sVar2,uVar3 & 0xff,auStack_a0[iVar6 * 4 + 1],0);

    sprintf((char *)auStack_10,&gp0xffffac10,param_1[2]);

    FUN_0040eb50(0,sVar1 + 0x1c0,iVar8 + 0x75,uVar3 & 0xff,1,auStack_10,2);

    FUN_0040e3c0(0,sVar1,iVar8 - ((short)param_1[0xb] * 3) / 0xff,

                 ((int)(short)param_1[0xb] * (int)(short)uVar3) / 0xff & 0xff,

                 auStack_a0[iVar6 * 4 + 2],0);

    FUN_0040e3c0(0,sVar1,iVar8 + (*(short *)((int)param_1 + 0x2e) * 3) / 0xff,

                 ((int)*(short *)((int)param_1 + 0x2e) * (int)(short)uVar3) / 0xff & 0xff,

                 auStack_a0[iVar6 * 4 + 3],0);

  }

  return 0;

}

// FUN_003FBE70


void FUN_003fbe70(u8 *param_1,u8 *param_2)
{
  s16 sVar1;

  memset_typed(param_1,0,0x98);
  sVar1 = datGetEquipmentIdx_s16(1,(s16)((s32)(*(u32 *)(param_2 + 4) & 0xf00) >> 8));
  FUN_003f1dc0_u32(1,param_1 + 0x50,(s32)sVar1);
  memcpy_typed(param_1 + 0x6c,param_2,0x1c);
  *(u32 *)(param_1 + 4) = *(u32 *)(param_1 + 4) | 1;
  *(u16 *)param_1 = 1;
  return;
}

// FUN_003FBF10


void FUN_003fbf10(u16 *param_1)



{

  *param_1 = 3;

  return;

}

// FUN_003FBF20 NONMATCHING


u64 FUN_003fbf20(short *param_1)



{

  short sVar1;

  int iVar2;

  

  sVar1 = *param_1;

  if (sVar1 != 5) {

    if (sVar1 != 4) {

      if (sVar1 != 3) {

        if (sVar1 != 2) {

          if (sVar1 != 1) {

            return 0;

          }

          *param_1 = 2;

          param_1[4] = 0;

          param_1[5] = 0;

        }

        iVar2 = *(int *)(param_1 + 4);

        *(int *)(param_1 + 4) = iVar2 + 1;

        param_1[0x4a] = (short)(int)((float)((iVar2 + 1) * 0xff) / 10.0f);

        if (*(int *)(param_1 + 4) < 10) {

          return 0;

        }

        *param_1 = 5;

        param_1[4] = 0;

        param_1[5] = 0;

        return 0;

      }

      *param_1 = 4;

      param_1[4] = 0;

      param_1[5] = 0;

    }

    iVar2 = *(int *)(param_1 + 4);

    *(int *)(param_1 + 4) = iVar2 + 1;

    param_1[0x4a] = (short)(int)((float)((iVar2 + 1) * -0xff) / 10.0f + 255.0f);

    if (9 < *(int *)(param_1 + 4)) {

      *(u32 *)(param_1 + 2) = *(u32 *)(param_1 + 2) & 0xfffffffe;

      param_1[4] = 0;

      param_1[5] = 0;

    }

  }

  return 0;

}

// FUN_003FC060 NONMATCHING


u64 FUN_003fc060(int param_1)



{

  u16 uVar1;

  u64 uVar2;

  u16 *puVar3;

  int iVar4;

  int iVar5;

  u8 auStack_8 [8];

  

  if ((*(u32 *)(param_1 + 4) & 1) != 0) {

    uVar1 = *(u16 *)(param_1 + 0x94);


    FUN_0040e3c0(0,0x18,0x4b,uVar1 & 0xff,0x4a,0);

    FUN_0040e3c0(0,0x18,0x4b,uVar1 & 0xff,0x4c,0);

    FUN_0040e3c0(0,0x18,0x4b,uVar1 & 0xff,0x43,0);

    FUN_0040e3c0(0,0x37,0xbb,uVar1 & 0xff,0x49,0);

    FUN_0040e3c0(0,0x37,0xbb,uVar1 & 0xff,0x4b,0);

    FUN_0040e3c0(0,0x37,0xbb,uVar1 & 0xff,0x44,0);

    puVar3 = (u16 *)(param_1 + 0x50);

    iVar4 = 200;

    FUN_0040e3c0(0,200,0x5f,uVar1 & 0xff,0,(u32)*(u8 *)(param_1 + 0x54) << 1);

    uVar2 = func_00171110(*puVar3,*(u8 *)(param_1 + 0x58));

    FUN_003b2cb0(0,0xe8,0x61,uVar1 | 0xff00,5,1,uVar2,0,0);

    for (iVar5 = 0; iVar5 < 4; iVar5 = iVar5 + 1) {

      if (puVar3[iVar5 + 8] == 0) {

        FUN_0040e3c0(0,iVar4,0x5f,uVar1 & 0xff,0x47,0);

        FUN_0040e3c0(0,iVar4,0x5f,uVar1 & 0xff,0x48,0);

        FUN_0040e3c0(0,iVar4,0x5f,uVar1 & 0xff,0x4d,iVar5);

        FUN_0040e3c0(0,iVar4,0x5f,uVar1 & 0xff,0x4f,0);

      }

      else {

        FUN_0040e3c0(0,iVar4,0x5f,uVar1 & 0xff,0x45,0);

        FUN_0040e3c0(0,iVar4,0x5f,uVar1 & 0xff,0x46,0);

        FUN_0040e3c0(0,iVar4,0x5f,uVar1 & 0xff,0x4e,iVar5);

        sprintf((char *)auStack_8,0x7cd900,puVar3[iVar5 + 8]);

        FUN_0040eb50(0,iVar4 + 0x4b,0x9b,uVar1 & 0xff,2,auStack_8,1);

      }

      iVar4 = iVar4 + 0x52;

    }

    puVar3 = (u16 *)(param_1 + 0x6c);

    iVar4 = 200;

    FUN_0040e3c0(0,200,0xbb,uVar1 & 0xff,0,(u32)*(u8 *)(param_1 + 0x70) << 1);

    uVar2 = func_00171110(*puVar3,*(u8 *)(param_1 + 0x74));

    FUN_003b2cb0(0,0xe8,0xbd,uVar1 | 0xff00,5,1,uVar2,0,0);

    for (iVar5 = 0; iVar5 < 4; iVar5 = iVar5 + 1) {

      if (puVar3[iVar5 + 8] == 0) {

        FUN_0040e3c0(0,iVar4,0xbb,uVar1 & 0xff,0x47,0);

        FUN_0040e3c0(0,iVar4,0xbb,uVar1 & 0xff,0x48,0);

        FUN_0040e3c0(0,iVar4,0xbb,uVar1 & 0xff,0x4d,iVar5);

        FUN_0040e3c0(0,iVar4,0xbb,uVar1 & 0xff,0x4f,0);

      }

      else {

        FUN_0040e3c0(0,iVar4,0xbb,uVar1 & 0xff,0x45,0);

        FUN_0040e3c0(0,iVar4,0xbb,uVar1 & 0xff,0x46,0);

        FUN_0040e3c0(0,iVar4,0xbb,uVar1 & 0xff,0x4e,iVar5);

        sprintf((char *)auStack_8,0x7cd900,puVar3[iVar5 + 8]);

        FUN_0040eb50(0,iVar4 + 0x4b,0xf7,uVar1 & 0xff,2,auStack_8,1);

      }

      iVar4 = iVar4 + 0x52;

    }

  }

  return 0;

}

// FUN_003FC540 NONMATCHING


u64 FUN_003fc540(int param_1)



{

  u16 uVar1;

  u64 uVar2;

  u16 *puVar3;

  int iVar4;

  int iVar5;

  u8 auStack_8 [8];

  

  if ((*(u32 *)(param_1 + 4) & 1) != 0) {

    uVar1 = *(u16 *)(param_1 + 0x94);

    FUN_0040e3c0(0,0x2b,0x1c,uVar1 & 0xff,0x42,0);

    FUN_0040e3c0(0,0x2b,0x1c,uVar1 & 0xff,0x44,0);

    FUN_0040e3c0(0,0x2b,0x1c,uVar1 & 0xff,0x3a,0);

    FUN_0040e3c0(0,0x2b,0xb0,uVar1 & 0xff,0x41,0);

    FUN_0040e3c0(0,0x2b,0xb0,uVar1 & 0xff,0x43,0);

    FUN_0040e3c0(0,0x2b,0xb0,uVar1 & 0xff,0x3b,0);

    puVar3 = (u16 *)(param_1 + 0x50);

    iVar4 = 0x4e;

    FUN_0040e3c0(0,0x4e,0x44,uVar1 & 0xff,0,(u32)*(u8 *)(param_1 + 0x54) << 1);

    uVar2 = func_00171110(*puVar3,*(u8 *)(param_1 + 0x58));

    FUN_003b2cb0(0,0x6e,0x46,uVar1 | 0xff00,5,1,uVar2,0,0);

    for (iVar5 = 0; iVar5 < 5; iVar5 = iVar5 + 1) {

      if (puVar3[iVar5 + 8] == 0) {

        FUN_0040e3c0(0,iVar4,0x44,uVar1 & 0xff,0x40,0);

        FUN_0040e3c0(0,iVar4,0x44,uVar1 & 0xff,0x45,iVar5);

        FUN_0040e3c0(0,iVar4,0x44,uVar1 & 0xff,0x47,0);

      }

      else {

        FUN_0040e3c0(0,iVar4,0x44,uVar1 & 0xff,0x3e,0);

        FUN_0040e3c0(0,iVar4,0x44,uVar1 & 0xff,0x46,iVar5);

        sprintf((char *)auStack_8,0x7cd900,puVar3[iVar5 + 8]);

        FUN_0040eb50(0,iVar4 + 0x1a,0x8c,uVar1 & 0xff,2,auStack_8,1);

      }

      iVar4 = iVar4 + 0x42;

    }

    puVar3 = (u16 *)(param_1 + 0x6c);

    iVar4 = 0x4e;

    FUN_0040e3c0(0,0x4e,0xd8,uVar1 & 0xff,0,(u32)*(u8 *)(param_1 + 0x70) << 1);

    uVar2 = func_00171110(*puVar3,*(u8 *)(param_1 + 0x74));

    FUN_003b2cb0(0,0x6e,0xda,uVar1 | 0xff00,5,1,uVar2,0,0);

    for (iVar5 = 0; iVar5 < 5; iVar5 = iVar5 + 1) {

      if (puVar3[iVar5 + 8] == 0) {

        FUN_0040e3c0(0,iVar4,0xd8,uVar1 & 0xff,0x40,0);

        FUN_0040e3c0(0,iVar4,0xd8,uVar1 & 0xff,0x45,iVar5);

        FUN_0040e3c0(0,iVar4,0xd8,uVar1 & 0xff,0x47,0);

      }

      else {

        FUN_0040e3c0(0,iVar4,0xd8,uVar1 & 0xff,0x3e,0);

        FUN_0040e3c0(0,iVar4,0xd8,uVar1 & 0xff,0x46,iVar5);

        sprintf((char *)auStack_8,0x7cd900,puVar3[iVar5 + 8]);

        FUN_0040eb50(0,iVar4 + 0x1a,0x120,uVar1 & 0xff,2,auStack_8,1);

      }

      iVar4 = iVar4 + 0x42;

    }

  }

  return 0;

}

// FUN_003FC980


u32 FUN_003fc980(int param_1)

{

  u32 uVar1;

  u32 uVar2;

  

  uVar1 = datGetScenarioMode();

  if (uVar1 == 0) {
    uVar2 = FUN_003fc060_u32(param_1);

  }

  else {

    uVar1 = datGetScenarioMode();

    if (uVar1 == 1) {
      uVar2 = FUN_003fc540_u32(param_1);

    }

    else {

      uVar2 = 0;

    }

  }

  return uVar2;

}

// FUN_003FCA00
void FUN_003fca00(u64 param_1,u64 param_2,u32 param_3)
{
  u32 uVar1;
  uVar1 = param_3;
  FUN_0040e3c0_f32(0.0f,0,0,uVar1,0x52,0);
  FUN_0040e3c0_f32(0.0f,0,0,uVar1,0x53,0);
  FUN_0040e3c0_f32(0.0f,0,0,uVar1,0x54,0);
  FUN_0040e3c0_f32(0.0f,0,0,uVar1,0x50,0);
  FUN_0040e3c0_f32(0.0f,0,0,uVar1,0x51,0);
  return;
}

// FUN_003FCAD0 NONMATCHING


void FUN_003fcad0(u64 param_1,u64 param_2,u32 param_3,int param_4)
{
  int iVar1;

  iVar1 = *(int *)(*(int *)(*(int *)(param_4 + 0xc) + 0x14) + 0x1c);

  if ((*(short *)(*(int *)(*(int *)(param_4 + 0x24) + 0x44) + 6) == -1) &&
     ((*(u32 *)(iVar1 + 8) & 0x1000) != 0)) {
    FUN_003c7e20_f32(0.0f,0x125,0xe3,param_3 | 0xffffff00U,1,5,2,*(u16 *)(iVar1 + 6));
    return;
  }
  if ((*(u32 *)(iVar1 + 8) & 0x1000) == 0) {
    FUN_003c7e20_f32(0.0f,0x125,0xe3,param_3 | 0xffffff00U,1,5,0,*(u16 *)(iVar1 + 4));
    return;
  }
  FUN_003c7e20_f32(0.0f,0x125,0xe3,param_3 | 0xffffff00U,1,5,1,
                   (u32)CONCAT12(*(u8 *)(iVar1 + 0xd),*(u16 *)(iVar1 + 4)));
}

// FUN_003FCBE0 NONMATCHING


void FUN_003fcbe0(u64 param_1,u64 param_2,u32 param_3,int param_4,int param_5)



{

  u8 bVar1;

  int iVar2;

  

  if (param_3 != 0) {

    iVar2 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

    bVar1 = param_5 == *(int *)(param_4 + 0xc);

    if (bVar1) {

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x5f,0);

    }

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x59,(u32)bVar1 * -2);

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x5a,(u32)bVar1 * -2);

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,((int)(*(u32 *)(iVar2 + 8) & 0xf00) >> 8) + 0x55,

                 bVar1);

    iVar2 = (int)(*(u32 *)(iVar2 + 8) & 0xf00) >> 8;

    if (iVar2 != 3) {

      if (iVar2 == 2) {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x5e,bVar1);

      }

      else if (iVar2 == 1) {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x5d,bVar1);

      }

      else if (iVar2 == 0) {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x5b,bVar1);

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x5c,bVar1);

      }

    }

  }

  return;

}

// FUN_003FCDC0 NONMATCHING


void FUN_003fcdc0(int param_1,int param_2,u32 param_3,int param_4,int param_5)



{

  u8 bVar1;

  int iVar2;

  u32 uVar3;

  u64 uVar4;

  int iVar5;

  u32 uVar6;

  u8 uVar7;

  u8 auStack_20 [24];

  u32 auStack_8 [2];

  

  uVar7 = 5;

  auStack_8[0] = DAT_007cd958;

  auStack_8[1] = DAT_007cd95c;

  if (param_3 != 0) {

    iVar2 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

    bVar1 = param_5 == *(int *)(param_4 + 0xc);

    if (bVar1) {

      uVar7 = 6;

    }

    uVar6 = (u32)bVar1;

    FUN_0040e3c0(0,param_1 + 0x71,param_2 + -3,param_3 & 0xff,0,

                 (u32)*(u8 *)(iVar2 + 8) * 2 + uVar6);

    uVar4 = func_00171110(*(u16 *)(iVar2 + 4),*(u8 *)(iVar2 + 0xc));

    FUN_003b2cb0(0,param_1 + 0x91,param_2 + -1,param_3 | 0xffffffffffffff00,uVar7,1,uVar4,0,0);

    iVar5 = (int)(*(u32 *)(iVar2 + 8) & 0xf00) >> 8;

    if (iVar5 != 3) {

      if (iVar5 == 2) {

        sprintf((char *)auStack_20,0x7cd900,*(u16 *)(iVar2 + 0x1a));

        FUN_0040eb50(0,param_1 + 0x1d1,param_2 + 7,param_3 & 0xff,auStack_8[uVar6],auStack_20,1);

      }

      else if (iVar5 == 1) {

        sprintf((char *)auStack_20,0x7cd900,*(u16 *)(iVar2 + 0x18));

        FUN_0040eb50(0,param_1 + 0x1d1,param_2 + 7,param_3 & 0xff,auStack_8[uVar6],auStack_20,1);

      }

      else if (iVar5 == 0) {

        sprintf((char *)auStack_20,0x7cd900,*(u16 *)(iVar2 + 0x14));

        uVar3 = auStack_8[uVar6];

        FUN_0040eb50(0,param_1 + 0x1d1,param_2 + 7,param_3 & 0xff,uVar3,auStack_20,1);

        sprintf((char *)auStack_20,0x7cd900,*(u16 *)(iVar2 + 0x16));

        FUN_0040eb50(0,param_1 + 0x236,param_2 + 7,param_3 & 0xff,uVar3,auStack_20,1);

      }

    }

  }

  return;

}

// FUN_003FD010


void FUN_003fd010(int param_1,int param_2,u32 param_3,int param_4,int param_5)



{


  FUN_003fcdc0(param_1,param_2,param_3,param_4,param_5);


  return;
}

// FUN_003FD030 NONMATCHING


void FUN_003fd030(u64 param_1,u64 param_2,u32 param_3,int param_4)
{
  int iVar1;

  iVar1 = *(int *)(*(int *)(*(int *)(param_4 + 0xc) + 0x14) + 0x1c);
  if ((*(short *)(*(int *)(*(int *)(param_4 + 0x24) + 0x44) + 6) == -1) &&
     ((*(u32 *)(iVar1 + 8) & 0x1000) != 0)) {
    FUN_003c7e20_f32(0.0f,0x53,0xfa,param_3 | 0xffffff00U,1,5,2,*(u16 *)(iVar1 + 6));
    return;
  }
  if ((*(u32 *)(iVar1 + 8) & 0x1000) == 0) {
    FUN_003c7e20_f32(0.0f,0x53,0xfa,param_3 | 0xffffff00U,1,5,0,*(u16 *)(iVar1 + 4));
    return;
  }
  FUN_003c7e20_f32(0.0f,0x53,0xfa,param_3 | 0xffffff00U,1,5,1,
                   (u32)CONCAT12(*(u8 *)(iVar1 + 0xd),*(u16 *)(iVar1 + 4)));
}

// FUN_003FD140 NONMATCHING


void FUN_003fd140(u64 param_1,u64 param_2,u32 param_3,int param_4,int param_5)



{

  u8 bVar1;

  int iVar2;

  u32 uVar3;

  

  if (param_3 != 0) {

    iVar2 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

    bVar1 = param_5 == *(int *)(param_4 + 0xc);

    if (bVar1) {

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x53,0);

    }

    uVar3 = (u32)bVar1;

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x4d,uVar3 * -2);

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x4e,uVar3 * -2);

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,((int)(*(u32 *)(iVar2 + 8) & 0xf00) >> 8) + 0x49,

                 bVar1);

    iVar2 = (int)(*(u32 *)(iVar2 + 8) & 0xf00) >> 8;

    if (iVar2 != 3) {

      if (iVar2 == 2) {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x52,1 - uVar3);

      }

      else if (iVar2 == 1) {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x51,1 - uVar3);

      }

      else if (iVar2 == 0) {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x4f,1 - uVar3);

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x50,1 - uVar3);

      }

    }

  }

  return;

}

// FUN_003FD320 NONMATCHING


void FUN_003fd320(int param_1,int param_2,u32 param_3,int param_4,int param_5)



{

  u8 bVar1;

  int iVar2;

  u32 uVar3;

  u64 uVar4;

  int iVar5;

  u32 uVar6;

  u8 uVar7;

  u8 auStack_20 [24];

  u32 auStack_8 [2];

  

  uVar7 = 5;

  auStack_8[0] = DAT_007cd960;

  auStack_8[1] = DAT_007cd964;

  if (param_3 != 0) {

    iVar2 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

    bVar1 = param_5 == *(int *)(param_4 + 0xc);

    if (bVar1) {

      uVar7 = 6;

    }

    uVar6 = (u32)bVar1;

    FUN_0040e3c0(0,param_1 + 0x71,param_2 + -3,param_3 & 0xff,0,

                 (u32)*(u8 *)(iVar2 + 8) * 2 + uVar6);

    uVar4 = func_00171110(*(u16 *)(iVar2 + 4),*(u8 *)(iVar2 + 0xc));

    FUN_003b2cb0(0,param_1 + 0x91,param_2 + -1,param_3 | 0xffffffffffffff00,uVar7,1,uVar4,0,0);

    iVar5 = (int)(*(u32 *)(iVar2 + 8) & 0xf00) >> 8;

    if (iVar5 != 3) {

      if (iVar5 == 2) {

        sprintf((char *)auStack_20,0x7cd900,*(u16 *)(iVar2 + 0x1a));

        FUN_0040eb50(0,param_1 + 0x1d1,param_2 + 7,param_3 & 0xff,auStack_8[uVar6],auStack_20,1);

      }

      else if (iVar5 == 1) {

        sprintf((char *)auStack_20,0x7cd900,*(u16 *)(iVar2 + 0x18));

        FUN_0040eb50(0,param_1 + 0x1d1,param_2 + 7,param_3 & 0xff,auStack_8[uVar6],auStack_20,1);

      }

      else if (iVar5 == 0) {

        sprintf((char *)auStack_20,0x7cd900,*(u16 *)(iVar2 + 0x14));

        uVar3 = auStack_8[uVar6];

        FUN_0040eb50(0,param_1 + 0x1d1,param_2 + 7,param_3 & 0xff,uVar3,auStack_20,1);

        sprintf((char *)auStack_20,0x7cd900,*(u16 *)(iVar2 + 0x16));

        FUN_0040eb50(0,param_1 + 0x236,param_2 + 7,param_3 & 0xff,uVar3,auStack_20,1);

      }

    }

  }

  return;

}

// FUN_003FD570 NONMATCHING


u64 FUN_003fd570(int param_1,u32 *param_2)



{

  int iVar1;

  u32 uVar2;

  u32 *puVar3;

  u32 *puVar4;

  u8 bVar5;

  u32 uVar6;

  u32 uVar7;

  long lVar8;

  int iVar9;

  int *piVar10;

  int *piVar11;

  u32 uVar12;

  int aiStack_30 [12];

  

  piVar11 = (int *)(&DAT_006af140);

  piVar10 = aiStack_30;

  iVar9 = 0xb;

  do {

    iVar1 = *piVar11;

    piVar11 = piVar11 + 1;

    iVar9 = iVar9 + -1;

    *piVar10 = iVar1;

    piVar10 = piVar10 + 1;

  } while (0 < iVar9);

  uVar2 = *param_2;

  iVar9 = FUN_003c4910(uVar2,1,0xc);

  puVar3 = *(u32 **)(iVar9 + 0x14);

  *puVar3 = 1;


  puVar3[1] = uVar6;

  uVar6 = FUN_003dfeb0(puVar3);

  puVar3[2] = uVar6;

  for (uVar12 = 0; uVar12 < 0xb; uVar12 = uVar12 + 1) {

    iVar9 = aiStack_30[uVar12];

    if ((iVar9 != 0) && (lVar8 = datGetFlag(iVar9), lVar8 != 0)) {

      if (iVar9 == 0x157) {

        lVar8 = datGetFlag(0xa8);

        if (lVar8 == 0) {

          bVar5 = 1;

        }

        else {

          bVar5 = 0;

        }

      }

      else if (iVar9 == 0x152) {

        lVar8 = datGetFlag(0x52);

        if (lVar8 == 0) {

          bVar5 = 0;

        }

        else {

          bVar5 = 1;

        }

      }

      else {

        bVar5 = 1;

      }

      if (bVar5) {

        iVar9 = FUN_003c4910(uVar2,uVar12,0xc);

        puVar4 = *(u32 **)(iVar9 + 0x14);

        *puVar4 = uVar12;


        puVar4[1] = uVar7;

        uVar7 = FUN_003dfeb0(puVar4);

        puVar4[2] = uVar7;

      }

    }

  }

  return 0;

}

// FUN_003FD730
u64 FUN_003fd730(u64 param_1,int param_2)
{
  s16 sVar1;
  int iVar3;
  int iVar2;
  u64 uVar4;
  u8 auStack_20[32];

  uVar4 = param_1;
  iVar3 = *(int *)(*(int *)(param_2 + 4) + 4);
  for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
    sVar1 = datGetEquipmentIdx_s16((s16)uVar4,(s16)iVar2);
    FUN_003f1dc0_u64(uVar4,auStack_20,(s32)sVar1);
    memcpy_typed((void *)(*(int *)(*(int *)(iVar3 + 0x14) + 0x1c) + 4),auStack_20,0x1c);
    iVar3 = *(int *)(iVar3 + 0x10);
  }
  return 0;
}

// FUN_003FD7E0


u64 FUN_003fd7e0(u64 param_1,int param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(param_2 + 0x14);

  FUN_003dff00(*(u32 *)(iVar1 + 8));

  FUN_003c5a20(*(u32 *)(iVar1 + 4));

  return 0;

}

// FUN_003FD820


int * FUN_003fd820(int param_1)



{

  int *piVar1;

  int iVar2;

  

  iVar2 = FUN_003c44d0(0xc,0,FUN_003fd7e0,0);

  piVar1 = *(int **)(iVar2 + 0x24);

  *piVar1 = iVar2;

  piVar1[1] = param_1;

  iVar2 = FUN_003dfeb0(0);

  piVar1[2] = iVar2;

  FUN_003fd570(param_1,(u32 *)piVar1);



  return piVar1;

}

// FUN_003FD8A0


void FUN_003fd8a0(u32 *param_1)



{

  FUN_003dff00(param_1[2]);

  FUN_003c45f0(*param_1);

  return;

}

// FUN_003FD8E0


void FUN_003fd8e0(int *param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(*(int *)(*param_1 + 0xc) + 0x14);

  FUN_003c6ee0(*(u32 *)(iVar1 + 4));

  FUN_003e04e0(param_1[2],0,0,0);

  FUN_003e04e0(param_1[2],3,0,0);

  FUN_003e04e0(*(u32 *)(iVar1 + 8),1,0,5);

  func_0010a4e0(0,0,0,3);

  return;

}

// FUN_003FD990 NONMATCHING


u64 FUN_003fd990(int *param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  u32 uVar4;

  int iVar5;

  u64 uVar6;

  

  iVar1 = *param_1;

  uVar6 = 0;

  FUN_003e0650(param_1[2]);

  for (iVar5 = *(int *)(*param_1 + 4); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x10)) {

    iVar2 = *(int *)(iVar5 + 0x14);


    FUN_003e0650(*(u32 *)(iVar2 + 8));

  }

  iVar5 = *(int *)(iVar1 + 0xc);

  iVar2 = *(int *)(iVar5 + 0x14);

  uVar4 = FUN_003c6d80(*(u32 *)(iVar2 + 4));

  if ((uVar4 & 0x40000000) != 0) {

    if (((DAT_007e0952 & 4) == 0) && ((DAT_007e095a & 4) == 0)) {

      if (((DAT_007e0952 & 8) == 0) && ((DAT_007e095a & 8) == 0)) {

        if (((DAT_007e094e & 0x20) != 0) || ((DAT_007e0958 & 0x20) != 0)) {

          func_0010a4e0(0,0,0,4);

          for (iVar5 = *(int *)(*param_1 + 4); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x10)) {

            FUN_003c6f10(*(u32 *)(*(int *)(iVar5 + 0x14) + 4));

          }

          uVar6 = 1;

          FUN_003e04e0(*(u32 *)(*(int *)(*(int *)(iVar1 + 0xc) + 0x14) + 8),1,1,0);

          FUN_003e04e0(param_1[2],0,1,0);

          FUN_003e04e0(param_1[2],3,1,0);

        }

      }

      else {

        iVar3 = FUN_003c4c80(iVar1,iVar1 + 4);

        if (iVar5 != iVar3) {

          func_0010a4e0(0,0,0,5);

          FUN_003c6f10(*(u32 *)(iVar2 + 4));

          FUN_003e04e0(*(u32 *)(iVar2 + 8),1,1,0);

          iVar5 = **(int **)(*(int *)(iVar2 + 4) + 0xc);

          iVar2 = *(int *)(*(int *)(iVar1 + 0xc) + 0x14);

          FUN_003e04e0(*(u32 *)(iVar2 + 8),1,0,5);

          FUN_003c6ee0(*(u32 *)(iVar2 + 4));

          FUN_003c4df0(*(int *)(iVar2 + 4),*(int *)(iVar2 + 4) + 4,iVar5 + -1);

        }

      }

    }

    else {

      iVar3 = FUN_003c4d20(iVar1,iVar1 + 4);

      if (iVar5 != iVar3) {

        func_0010a4e0(0,0,0,5);

        FUN_003c6f10(*(u32 *)(iVar2 + 4));

        FUN_003e04e0(*(u32 *)(iVar2 + 8),1,1,0);

        iVar5 = **(int **)(*(int *)(iVar2 + 4) + 0xc);

        iVar2 = *(int *)(*(int *)(iVar1 + 0xc) + 0x14);

        FUN_003e04e0(*(u32 *)(iVar2 + 8),1,0,5);

        FUN_003c6ee0(*(u32 *)(iVar2 + 4));

        FUN_003c4df0(*(int *)(iVar2 + 4),*(int *)(iVar2 + 4) + 4,iVar5 + -1);

      }

    }

    FUN_003c4dc0(iVar1,iVar1 + 4);

  }

  return uVar6;

}

// FUN_003FDCC0 NONMATCHING


void FUN_003fdcc0(int param_1,int param_2,int *param_3)



{

  u16 uVar1;

  int iVar2;

  int iVar3;

  u32 uVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  u32 auStack_8 [2];

  

  auStack_8[0] = DAT_007cd968;

  auStack_8[1] = DAT_007cd96c;

  uVar1 = *(u16 *)(param_2 + 0x26);

  if (uVar1 != 0) {

    iVar2 = *(int *)(param_2 + 0x10);

    iVar6 = (int)*(short *)(param_2 + 0x14);

    iVar5 = (int)*(short *)(param_2 + 0x16);

    if (iVar2 == 3) {

      iVar2 = *(int *)(*(int *)(*(int *)(*param_3 + 0xc) + 0x14) + 4);

      iVar3 = *(int *)(iVar2 + 0x24);

      if (*(short *)(*(int *)(iVar3 + 0x44) + 4) == 0) {

        iVar3 = *(int *)(iVar2 + 4);

        iVar7 = 0;

        FUN_0040e3c0(0,0,0,uVar1 & 0xff,0x52,0);

        FUN_0040e3c0(0,0,0,uVar1 & 0xff,0x53,0);

        FUN_0040e3c0(0,0,0,uVar1 & 0xff,0x54,0);

        FUN_0040e3c0(0,0,0,uVar1 & 0xff,0x50,0);

        FUN_0040e3c0(0,0,0,uVar1 & 0xff,0x51,0);

        for (; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x10)) {

          iVar8 = *(int *)(iVar2 + 0x24);

          FUN_003fcbe0(iVar6 + *(int *)(iVar8 + 0x14),

                       iVar5 + *(int *)(iVar8 + 0x18) + iVar7 * *(int *)(iVar8 + 0xc),uVar1,iVar2,

                       iVar3);

          iVar7 = iVar7 + 1;

        }

      }

      else {

        iVar7 = *(int *)(iVar2 + 4);

        iVar8 = 0;

        FUN_0040e3c0(0,iVar6 + *(int *)(iVar3 + 0x14),iVar5 + *(int *)(iVar3 + 0x18),uVar1 & 0xff,

                     0x48,0);

        for (; iVar7 != 0; iVar7 = *(int *)(iVar7 + 0x10)) {

          iVar3 = *(int *)(iVar2 + 0x24);

          FUN_003fd140(iVar6 + *(int *)(iVar3 + 0x14),

                       iVar5 + *(int *)(iVar3 + 0x18) + iVar8 * *(int *)(iVar3 + 0xc),uVar1,iVar2,

                       iVar7);

          iVar8 = iVar8 + 1;

        }

      }

    }

    else if (iVar2 == 1) {

      uVar4 = FUN_00177790(**(u16 **)(param_1 + 4));

      FUN_003b32d0(0,iVar6 + 0x1c9,iVar5 + 0x26,uVar1 | 0xff00,5,0,uVar4,0x18,0x73);

    }

    else if (iVar2 == 0) {

      FUN_0040e3c0(0,*(short *)(param_2 + 0x14),*(short *)(param_2 + 0x16),uVar1 & 0xff,

                   auStack_8[param_3[1]],0);

    }

  }

  return;

}

// FUN_003FDF80


u64 FUN_003fdf80(u32 *param_1)



{

  int iVar1;

  int iVar2;

  

  FUN_003e0680_typed(param_1[2],(code)FUN_003fdcc0,param_1);

  for (iVar2 = *(int *)(*param_1 + 4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x10)) {

    iVar1 = *(int *)(iVar2 + 0x14);

    FUN_003e0680_typed(*(u32 *)(iVar1 + 8),(code)FUN_003fdcc0,param_1);

    FUN_003c6380(*(u32 *)(iVar1 + 4));

  }

  return 0;

}

// FUN_003FE020 NONMATCHING


u32 FUN_003fe020(int param_1,u64 param_2)



{

  u16 uVar1;

  int iVar2;

  int iVar3;

  u32 uVar4;

  int iVar5;

  u8 auStack_40 [32];

  u8 *apuStack_20 [4];

  u8 *puStack_10;

  u8 *puStack_c;

  u8 *puStack_8;

  u8 *puStack_4;

  

  uVar4 = FUN_003c58f0(0,0x58,5,0x24);

  iVar2 = (int)uVar4;

  iVar5 = *(int *)(*(int *)(iVar2 + 0x24) + 0x44);

  if ((param_1 != 0) && (param_1 != 1)) {

    K_Assert((const char *)(u32)0x6aede8,0x148a);

  }

  *(short *)(iVar5 + 4) = (short)param_1;

  for (iVar5 = 0; iVar5 < 4; iVar5 = iVar5 + 1) {

    uVar1 = datGetEquipmentIdx((short)param_2,(short)iVar5);


    iVar3 = FUN_003c5a40(uVar4,*(u16 *)(iVar2 + 0x10) + 1,0x20,0);

    memcpy(*(int *)(*(int *)(iVar3 + 0x14) + 0x1c) + 4,auStack_40,0x1c);

  }

  puStack_8 = (u8 *)(PTR_FUN_007cd970);

  puStack_4 = (u8 *)(PTR_FUN_007cd974);

  puStack_10 = (u8 *)(PTR_FUN_007cd978);

  puStack_c = (u8 *)(PTR_FUN_007cd97c);

  apuStack_20[0] = (u8 *)(DAT_006af170);

  apuStack_20[1] = (u8 *)DAT_006af174;

  apuStack_20[2] = (u8 *)DAT_006af178;

  apuStack_20[3] = (u8 *)DAT_006af17c;

  FUN_003c5e20(uVar4,apuStack_20[param_1 + 6]);

  FUN_003c5ee0(uVar4,apuStack_20[param_1 + 4]);

  FUN_003c6d40(uVar4,apuStack_20[param_1 * 2],apuStack_20[param_1 * 2 + 1]);

  *(u16 *)(*(int *)(iVar2 + 0x24) + 6) = 10;

  *(u16 *)(*(int *)(iVar2 + 0x24) + 8) = 5;

  return uVar4;

}

// FUN_003FE1F0


u32 FUN_003fe1f0(u64 param_1)
{
  u32 uVar1;
  u32 uVar2;

  uVar1 = FUN_003c6270() == 3;
  uVar2 = FUN_003c6ce0(param_1);
  if ((uVar2 != 0) || (uVar2 = FUN_003c6d10(param_1), uVar2 != 0)) {
    func_0010a4e0(0,0,0,0);
  }
  uVar2 = FUN_003c6ca0(param_1);
  if ((uVar2 != 0) || (uVar2 = FUN_003c6cc0(param_1), uVar2 != 0)) {
    func_0010a4e0(0,0,0,5);
  }
  return uVar1;
}

// FUN_003FE2B0 NONMATCHING


u32 FUN_003fe2b0(void)
{
  u16 sVar1;
  u8 bVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  int iVar6;
  u16 *psVar7;
  u16 *psVar8;
  u16 sVar9;
  u32 uVar10;
  u16 asStack_10[8];

  uVar10 = 0;
  while (1) {
    psVar8 = DAT_006af180_abs;
    psVar7 = asStack_10;
    iVar6 = 4;
    do {
      sVar9 = *psVar8;
      sVar1 = psVar8[1];
      psVar8 += 2;
      iVar6--;
      *psVar7 = sVar9;
      psVar7[1] = sVar1;
      psVar7 += 2;
    } while (iVar6 > 0);

    if (uVar10 < 8) {
      sVar9 = asStack_10[uVar10];
    }
    else {
      sVar9 = 0;
    }
    sVar9 &= 0xffff;
    if (sVar9 == 0) {
      break;
    }
    uVar4 = func_00170760(1,(s16)sVar9);
    if (uVar4 != 0) {
      bVar2 = 1;
      goto LAB_003fe35c;
    }
    uVar10++;
  }
  bVar2 = 0;

LAB_003fe35c:
  if (bVar2) {
    uVar3 = 1;
  }
  else {
    for (sVar9 = 0; sVar9 < 300; sVar9++) {
      uVar5 = func_0016f720(1);
      if ((uVar5 & 0xff00) != 0) {
        return 1;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}

// FUN_003FE3E0 NONMATCHING


u64 FUN_003fe3e0(u16 param_1)



{

  short sVar1;

  short sVar2;

  int iVar3;

  u32 uVar4;

  u64 uVar5;

  long lVar6;

  int iVar7;

  short *psVar8;

  short *psVar9;

  u32 uVar10;

  short asStack_30 [8];

  u8 auStack_20 [32];

  

  uVar5 = FUN_003c58f0(0,0x58,7,0x1a);

  iVar3 = (int)uVar5;

  iVar7 = *(int *)(*(int *)(iVar3 + 0x24) + 0x44);

  *(u16 *)(iVar7 + 4) = param_1;

  *(u16 *)(iVar7 + 6) = 0xfffc;

  uVar10 = 0;

  while( 1 ) {

    psVar9 = (s16 *)(&DAT_006af180);

    psVar8 = asStack_30;

    iVar7 = 4;

    do {

      sVar2 = *psVar9;

      sVar1 = psVar9[1];

      psVar9 = psVar9 + 2;

      iVar7 = iVar7 + -1;

      *psVar8 = sVar2;

      psVar8[1] = sVar1;

      psVar8 = psVar8 + 2;

    } while (0 < iVar7);

    if (uVar10 < 8) {

      sVar2 = asStack_30[uVar10];

    }

    else {

      sVar2 = 0;

    }

    if (sVar2 == 0) break;


    if (lVar6 != 0) {

      iVar7 = FUN_003c5a40(uVar5,*(u16 *)(iVar3 + 0x10) + 1,0x20,0);

      memcpy(*(int *)(*(int *)(iVar7 + 0x14) + 0x1c) + 4,auStack_20,0x1c);

      for (iVar7 = 0; uVar4 = FUN_00175410(), iVar7 < (int)(uVar4 & 0xffff); iVar7 = iVar7 + 1) {

        datPersonaGetHeroPersona((short)iVar7);

      }

    }

    uVar10 = uVar10 + 1;

  }


  FUN_003c6ee0(uVar5);

  FUN_003c5e80(uVar5,0x3fadc0);

  FUN_003c5e20(uVar5,0x3f4de0);

  FUN_003c5ee0(uVar5,0x3f9510);

  FUN_003c6d40(uVar5,0x39,0x48);

  *(u16 *)(*(int *)(iVar3 + 0x24) + 6) = 0xb;

  *(u16 *)(*(int *)(iVar3 + 0x24) + 8) = 6;

  return uVar5;

}

// FUN_003FE5D0


u32 FUN_003fe5d0(u64 param_1)
{
  u32 uVar1;
  u32 uVar2;

  uVar1 = FUN_003c6270() == 3;
  uVar2 = FUN_003c6ce0(param_1);
  if ((uVar2 != 0) || (uVar2 = FUN_003c6d10(param_1), uVar2 != 0)) {
    func_0010a4e0(0,0,0,0);
  }
  uVar2 = FUN_003c6ca0(param_1);
  if ((uVar2 != 0) || (uVar2 = FUN_003c6cc0(param_1), uVar2 != 0)) {
    func_0010a4e0(0,0,0,5);
  }
  return uVar1;
}

// FUN_003FE690 NONMATCHING


u64 FUN_003fe690(u64 param_1,u64 param_2)



{

  int iVar1;

  int iVar2;

  u32 uVar3;

  u32 uVar4;

  long lVar5;

  u32 uVar6;

  int iVar7;

  u8 auStack_8 [6];

  u16 uStack_2;

  

  for (iVar7 = 0; uVar4 = FUN_00175410(), iVar7 < (int)(uVar4 & 0xffff); iVar7 = iVar7 + 1) {

    lVar5 = datPersonaGetHeroPersona((short)iVar7);

    if (lVar5 != 0) {

      uVar6 = FUN_003c5a40(param_1,*(u16 *)((int)param_1 + 0x10) + 1,0x20,0);

      iVar1 = *(int *)(*(int *)((int)uVar6 + 0x14) + 0x1c);

      memcpy(iVar1 + 4,param_2,0x1c);

      *(int *)(iVar1 + 0x14) = (int)lVar5;


      if (lVar5 == 0) {

        *(u32 *)(iVar1 + 0x18) = 0;

        *(u16 *)(iVar1 + 0x1c) = 0;

      }

      else {

        iVar2 = func_00170ed0(uStack_2,auStack_8);


        *(u32 *)(iVar1 + 0x18) = uVar3;

        *(u16 *)(iVar1 + 0x1c) = uStack_2;

      }


    }

  }

  return 0;

}

// FUN_003FE7D0


u64 FUN_003fe7d0(u64 param_1,int param_2)



{

  u16 uVar1;

  u32 *puVar2;

  u16 uVar3;

  

  puVar2 = *(u32 **)(*(int *)(param_2 + 0x14) + 0x1c);

  if ((short)puVar2[7] == 0) {

    *puVar2 = *puVar2 | 0x10;

  }

  uVar1 = *(u16 *)(puVar2[5] + 2);

  if (uVar1 == FUN_001752b0()) {

    *puVar2 = *puVar2 | 0x40;

  }

  return 0;

}

// FUN_003FE850


u32 FUN_003fe850(u16 param_1,u64 param_2)
{
  u32 *pVar;
  int iVar1;

  pVar = (u32 *)FUN_003c58f0(0,0x58,6,0x1e);
  iVar1 = *(int *)(pVar[9] + 0x44);
  *(u16 *)(iVar1 + 4) = param_1;
  *(s16 *)(iVar1 + 6) = -5;

  FUN_003fe690_p((u32)pVar,param_2,0);
  FUN_003c6ee0((u32)pVar);
  FUN_003c5e80_p((u32)pVar,(code)FUN_003fadc0);
  FUN_003c5e20_p((u32)pVar,(code)FUN_003f4de0);
  FUN_003c5ee0_p((u32)pVar,(code)FUN_003f9510);
  FUN_003c6d40((u32)pVar,0x19,0x79);

  *(u16 *)(pVar[9] + 6) = 0xb;
  *(u16 *)(pVar[9] + 8) = 6;
  return (u32)pVar;
}


// FUN_003FE950


u32 FUN_003fe950(u64 param_1)
{
  u32 uVar1;
  u32 uVar2;

  uVar1 = FUN_003c6270() == 3;
  uVar2 = FUN_003c6ce0(param_1);
  if ((uVar2 != 0) || (uVar2 = FUN_003c6d10(param_1), uVar2 != 0)) {
    func_0010a4e0(0,0,0,0);
  }
  uVar2 = FUN_003c6ca0(param_1);
  if ((uVar2 != 0) || (uVar2 = FUN_003c6cc0(param_1), uVar2 != 0)) {
    func_0010a4e0(0,0,0,5);
  }
  return uVar1;
}

// FUN_003FEA10 NONMATCHING


u64 FUN_003fea10(u64 param_1,u32 *param_2)



{

  short sVar1;

  int iVar2;

  long lVar3;

  u32 uVar4;

  int iVar5;

  short *psVar6;

  

  psVar6 = (short *)*param_2;

  for (iVar5 = 0; iVar5 < (int)param_2[1]; iVar5 = iVar5 + 1) {

    if ((((psVar6[2] == 0) || (lVar3 = datGetFlag(), lVar3 == 1)) && (sVar1 = *psVar6, sVar1 != 0)

        ) && (psVar6[4] != 0)) {

      uVar4 = FUN_003c5a40(param_1,*(u16 *)((int)param_1 + 0x10) + 1,0x20,0);

      *(int *)((int)uVar4 + 4) = (int)sVar1;

      iVar2 = *(int *)(*(int *)((int)uVar4 + 0x14) + 0x1c);


      memcpy(iVar2 + 0x14,psVar6 + 3,0xe);


    }

    psVar6 = psVar6 + 7;

  }

  return 0;

}

// FUN_003FEB30 NONMATCHING


u64 FUN_003feb30(u64 param_1,int param_2)



{

  short sVar1;

  u32 *puVar2;

  short sVar3;

  u32 uVar4;

  int iVar5;

  u32 uVar6;

  int iStack_c;

  int iStack_8;

  int iStack_4;

  

  puVar2 = *(u32 **)(*(int *)(param_2 + 0x14) + 0x1c);

  sVar1 = (short)puVar2[1];

  iStack_4 = -1;

  sVar3 = 0;

  func_00170ed0(sVar1,&iStack_4);

  if (iStack_4 == 4) {

    sVar3 = func_00170760(1,sVar1);

  }

  else if ((((iStack_4 == 3) || (iStack_4 == 2)) || (iStack_4 == 1)) || (iStack_4 == 0)) {

    sVar3 = 0;

    for (iVar5 = 0; iVar5 < 300; iVar5 = iVar5 + 1) {

      uVar6 = datGetEquipmentId(1,iVar5);

      if ((long)sVar1 == (uVar6 & 0xffff)) {

        sVar3 = sVar3 + 1;

      }

    }

  }

  *(short *)((int)puVar2 + 0xe) = sVar3;

  if (0x62 < sVar3) {

    *puVar2 = *puVar2 | 0x10;

  }

  if (*(short *)((int)puVar2 + 0x16) == 0) {

    K_Assert((const char *)(u32)0x6aede8,0x15b8);

  }

  sVar1 = (short)puVar2[5];

  if (sVar1 != 0) {

    iStack_8 = -1;

    uVar6 = 0;

    func_00170ed0(sVar1,&iStack_8);

    if (iStack_8 == 4) {

      uVar6 = func_00170760(1,sVar1);

      uVar6 = uVar6 & 0xffff;

    }

    else if (((iStack_8 == 3) || (iStack_8 == 2)) || ((iStack_8 == 1 || (iStack_8 == 0)))) {

      for (iVar5 = 0; iVar5 < 300; iVar5 = iVar5 + 1) {

        uVar4 = datGetEquipmentId(1,iVar5);

        if ((long)sVar1 == (uVar4 & 0xffff)) {

          uVar6 = (u32)((int)uVar6 + 1);

        }

      }

    }

    if ((long)uVar6 < (long)*(short *)((int)puVar2 + 0x16)) goto LAB_003fee10;

  }

  sVar1 = (short)puVar2[6];

  if (sVar1 == 0) {

    return 0;

  }

  iStack_c = -1;

  uVar6 = 0;

  func_00170ed0(sVar1,&iStack_c);

  if (iStack_c == 4) {

    uVar6 = func_00170760(1,sVar1);

    uVar6 = uVar6 & 0xffff;

  }

  else if (((iStack_c == 3) || (iStack_c == 2)) || ((iStack_c == 1 || (iStack_c == 0)))) {

    for (iVar5 = 0; iVar5 < 300; iVar5 = iVar5 + 1) {

      uVar4 = datGetEquipmentId(1,iVar5);

      if ((long)sVar1 == (uVar4 & 0xffff)) {

        uVar6 = (u32)((int)uVar6 + 1);

      }

    }

  }

  if ((long)*(short *)((int)puVar2 + 0x1a) <= (long)uVar6) {

    return 0;

  }

LAB_003fee10:

  *puVar2 = *puVar2 | 0x10;

  return 0;

}

// FUN_003FEE40 NONMATCHING


u64 FUN_003fee40(int param_1)



{

  u32 *puVar1;

  short sVar2;

  int iVar3;

  

  for (iVar3 = *(int *)(param_1 + 4); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x10)) {

    puVar1 = *(u32 **)(*(int *)(iVar3 + 0x14) + 0x1c);


    *(short *)((int)puVar1 + 0xe) = sVar2;

    if (0x62 < sVar2) {

      *puVar1 = *puVar1 | 0x10;

    }

    if (*(short *)((int)puVar1 + 0x16) == 0) {

      K_Assert((const char *)(u32)0x6aede8,0x15b8);

    }

    if ((((short)puVar1[5] != 0) && (sVar2 = FUN_003f1910(0), sVar2 < *(short *)((int)puVar1 + 0x16))

        ) || (((short)puVar1[6] != 0 &&

              (sVar2 = FUN_003f1910(0), sVar2 < *(short *)((int)puVar1 + 0x1a))))) {

      *puVar1 = *puVar1 | 0x10;

    }

  }

  return 0;

}

// FUN_003FEF30 NONMATCHING


u32 FUN_003fef30(u64 param_1,long param_2)



{

  int iVar1;

  int iVar2;

  u32 uVar3;

  long lVar4;

  u8 **ppuVar5;

  int iVar6;

  

  uVar3 = FUN_003c58f0(0,0x58,5,0x1a);

  iVar1 = (int)uVar3;

  iVar2 = *(int *)(*(int *)(iVar1 + 0x24) + 0x44);

  *(short *)(iVar2 + 4) = (short)param_1;

  ppuVar5 = (u8 **)&PTR_DAT_006ad4a0;

  if (param_2 == 0) {

    *(u16 *)(iVar2 + 6) = 0xfffe;

  }

  else {

    *(u16 *)(iVar2 + 6) = 0xfffd;

    ppuVar5 = (u8 **)0x6ad4a8;

  }

  if (ppuVar5 == (u8 **)0x0) {

    K_Assert((const char *)(u32)0x6aede8,0x15ea);

  }


  if (param_2 == 0) {


    for (iVar6 = 1; iVar6 <= iVar2; iVar6 = iVar6 + 1) {

      if ((iVar6 < 0) || (DAT_006ad4b4 < iVar6)) {

        K_Assert((const char *)(u32)0x6aede8,0x1df);

      }

      if ((u8 *)PTR_DAT_006ad4b0 + iVar6 * 8 != (u8 *)0x0) {


      }

    }

  }

  if (param_2 == 0) {

    FUN_0017d610(param_1);


    if (lVar4 != 0) {


      FUN_003c5a20(lVar4);

    }

  }

  FUN_003c6ee0(uVar3);

  FUN_003c5e80(uVar3,0x3fadc0);

  FUN_003c5e20(uVar3,0x3f4de0);

  FUN_003c5ee0(uVar3,0x3f9510);

  FUN_003c6d40(uVar3,0x39,0x48);

  *(u16 *)(*(int *)(iVar1 + 0x24) + 6) = 10;

  *(u16 *)(*(int *)(iVar1 + 0x24) + 8) = 5;

  return uVar3;

}

// FUN_003FF150 NONMATCHING


u64 FUN_003ff150(u64 param_1,long param_2)



{

  u32 uVar1;

  u64 uVar2;

  long lVar3;

  u32 uVar4;

  u8 **ppuVar5;

  int iVar6;

  u8 uStack_8;

  u8 bStack_7;

  u16 uStack_6;

  

  dat0017d6d0(param_1,&uStack_8);

  uVar1 = 0;

  for (uVar4 = 0; uVar4 < 8; uVar4 = uVar4 + 1) {

    if ((*(short *)(&DAT_006acc60 + uVar4 * 2) == -1) || (lVar3 = datGetFlag(), lVar3 == 0)) {

      if ((uVar4 == 6) && (lVar3 = datGetScenarioMode(), lVar3 != 0)) {

        uVar1 = uVar1 | 0x40;

      }

    }

    else {

      uVar1 = uVar1 | 1 << (uVar4 & 0x1f) & 0xffffU;

    }

  }

  for (uVar4 = 0; uVar4 < 8; uVar4 = uVar4 + 1) {

    if (((uVar4 != 6) || (lVar3 = datGetScenarioMode(), lVar3 == 0)) &&

       (*(short *)(&DAT_006acc60 + uVar4 * 2) != -1)) {

      if (((u32)uStack_6 & 1 << (uVar4 & 0x1f)) == 0) {

        datSetFlag(*(short *)(&DAT_006acc60 + uVar4 * 2),0);

      }

      else {

        datSetFlag();

      }

    }

  }

  uVar2 = FUN_003c58f0(0,0x58,5,0x1a);

  iVar6 = *(int *)(*(int *)((int)uVar2 + 0x24) + 0x44);

  ppuVar5 = (u8 **)&PTR_DAT_006ad4a0;

  if (param_2 == 0) {

    *(u16 *)(iVar6 + 6) = 0xfffe;

  }

  else {

    *(u16 *)(iVar6 + 6) = 0xfffd;

    ppuVar5 = (u8 **)0x6ad4a8;

  }

  if (ppuVar5 == (u8 **)0x0) {

    K_Assert((const char *)(u32)0x6aede8,0x162f);

  }


  if (param_2 == 0) {

    for (iVar6 = 1; iVar6 <= (int)(u32)bStack_7; iVar6 = iVar6 + 1) {

      if ((iVar6 < 0) || (DAT_006ad4b4 < iVar6)) {

        K_Assert((const char *)(u32)0x6aede8,0x1df);

      }

      if ((u8 *)PTR_DAT_006ad4b0 + iVar6 * 8 != (u8 *)0x0) {


      }

    }

  }

  for (uVar4 = 0; uVar4 < 8; uVar4 = uVar4 + 1) {

    if (((uVar4 != 6) || (lVar3 = datGetScenarioMode(), lVar3 == 0)) &&

       (*(short *)(&DAT_006acc60 + uVar4 * 2) != -1)) {

      if ((uVar1 & 1 << (uVar4 & 0x1f)) == 0) {

        datSetFlag(*(short *)(&DAT_006acc60 + uVar4 * 2),0);

      }

      else {

        datSetFlag();

      }

    }

  }

  return uVar2;

}

// FUN_003FF460 NONMATCHING


void FUN_003ff460(int param_1,u64 param_2)



{

  u32 *puVar1;

  int iVar2;

  u8 bVar3;

  u8 bVar4;

  long lVar5;

  int iVar6;

  

  for (iVar6 = *(int *)(param_1 + 4); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x10)) {

    puVar1 = *(u32 **)(*(int *)(iVar6 + 0x14) + 0x1c);

    lVar5 = FUN_003c4bf0(param_2,(int)param_2 + 4,(short)puVar1[1]);

    if (lVar5 == 0) {

      *puVar1 = *puVar1 | 0x80;

    }

    else {

      iVar2 = *(int *)(*(int *)((int)lVar5 + 0x14) + 0x1c);

      bVar3 = 0;

      if (*(short *)((int)puVar1 + 0x16) == *(short *)(iVar2 + 0x16)) {

        bVar3 = (short)puVar1[5] == *(short *)(iVar2 + 0x14);

      }

      bVar4 = 0;

      if (bVar3) {

        bVar4 = *(short *)((int)puVar1 + 0x1a) == *(short *)(iVar2 + 0x1a);

      }

      bVar3 = 0;

      if (bVar4) {

        bVar3 = (short)puVar1[6] == *(short *)(iVar2 + 0x18);

      }

      if (!bVar3) {

        *puVar1 = *puVar1 | 0x80;

      }

      FUN_003c49e0(param_2,(int)param_2 + 4);

    }

  }

  return;

}

// FUN_003FF570


u32 FUN_003ff570(u64 param_1)
{
  u32 uVar1;
  u32 uVar2;

  uVar1 = FUN_003c6270() == 3;
  uVar2 = FUN_003c6ce0(param_1);
  if ((uVar2 != 0) || (uVar2 = FUN_003c6d10(param_1), uVar2 != 0)) {
    func_0010a4e0(0,0,0,0);
  }
  uVar2 = FUN_003c6ca0(param_1);
  if ((uVar2 != 0) || (uVar2 = FUN_003c6cc0(param_1), uVar2 != 0)) {
    func_0010a4e0(0,0,0,5);
  }
  return uVar1;
}

// FUN_003FF630 NONMATCHING


void FUN_003ff630(u32 param_1,u64 param_2,u64 param_3,u64 param_4,

                 u8 param_5,short param_6,short param_7,u32 param_8)



{

  u8 bVar1;

  u8 bVar2;

  u16 uVar3;

  u16 uVar4;

  u16 **ppuVar5;

  u16 **ppuVar6;

  u16 **ppuVar7;

  int iVar8;

  u32 uVar9;

  u16 *puVar10;

  u8 *pbVar11;

  u16 *puVar12;

  u8 *pbVar13;

  u16 *unaff_s6_lo;

  u8 abStack_780b0 [360576];

  u16 auStack_20030 [65240];

  u16 *apuStack_1e0 [4];

  u16 *puStack_1d0;

  u16 *puStack_1c8;

  u16 *puStack_1c0;

  u16 auStack_1b0 [16];

  u16 auStack_190 [16];

  u16 auStack_170 [24];

  u16 auStack_140 [16];

  u16 auStack_120 [16];

  u16 auStack_100 [16];

  u16 auStack_e0 [24];

  u8 abStack_b0 [128];

  u16 auStack_30 [24];

  

  puVar12 = (u16 *)(&DAT_006af190);

  puVar10 = auStack_30;

  iVar8 = 9;

  do {

    uVar3 = *puVar12;

    uVar4 = puVar12[1];

    puVar12 = puVar12 + 2;

    iVar8 = iVar8 + -1;

    *puVar10 = uVar3;

    puVar10[1] = uVar4;

    puVar10 = puVar10 + 2;

  } while (0 < iVar8);

  pbVar13 = (u8 *)(&DAT_006af1c0);

  pbVar11 = abStack_b0;

  iVar8 = 0x3f;

  do {

    bVar1 = *pbVar13;

    bVar2 = pbVar13[1];

    pbVar13 = pbVar13 + 2;

    iVar8 = iVar8 + -1;

    *pbVar11 = bVar1;

    pbVar11[1] = bVar2;

    pbVar11 = pbVar11 + 2;

  } while (0 < iVar8);

  puVar12 = (u16 *)(&DAT_006af240);

  puVar10 = auStack_e0;

  iVar8 = 10;

  do {

    uVar3 = *puVar12;

    uVar4 = puVar12[1];

    puVar12 = puVar12 + 2;

    iVar8 = iVar8 + -1;

    *puVar10 = uVar3;

    puVar10[1] = uVar4;

    puVar10 = puVar10 + 2;

  } while (0 < iVar8);

  puVar12 = (u16 *)(&DAT_006af270);

  puVar10 = auStack_100;

  iVar8 = 8;

  do {

    uVar3 = *puVar12;

    uVar4 = puVar12[1];

    puVar12 = puVar12 + 2;

    iVar8 = iVar8 + -1;

    *puVar10 = uVar3;

    puVar10[1] = uVar4;

    puVar10 = puVar10 + 2;

  } while (0 < iVar8);

  puVar12 = (u16 *)(&DAT_006af290);

  puVar10 = auStack_120;

  iVar8 = 8;

  do {

    uVar3 = *puVar12;

    uVar4 = puVar12[1];

    puVar12 = puVar12 + 2;

    iVar8 = iVar8 + -1;

    *puVar10 = uVar3;

    puVar10[1] = uVar4;

    puVar10 = puVar10 + 2;

  } while (0 < iVar8);

  puVar12 = (u16 *)(&DAT_006af2b0);

  puVar10 = auStack_140;

  iVar8 = 6;

  do {

    uVar3 = *puVar12;

    uVar4 = puVar12[1];

    puVar12 = puVar12 + 2;

    iVar8 = iVar8 + -1;

    *puVar10 = uVar3;

    puVar10[1] = uVar4;

    puVar10 = puVar10 + 2;

  } while (0 < iVar8);

  puVar12 = (u16 *)(&DAT_006af2d0);

  puVar10 = auStack_170;

  iVar8 = 0xc;

  do {

    uVar3 = *puVar12;

    uVar4 = puVar12[1];

    puVar12 = puVar12 + 2;

    iVar8 = iVar8 + -1;

    *puVar10 = uVar3;

    puVar10[1] = uVar4;

    puVar10 = puVar10 + 2;

  } while (0 < iVar8);

  puVar12 = (u16 *)(&DAT_006af300);

  puVar10 = auStack_190;

  iVar8 = 6;

  do {

    uVar3 = *puVar12;

    uVar4 = puVar12[1];

    puVar12 = puVar12 + 2;

    iVar8 = iVar8 + -1;

    *puVar10 = uVar3;

    puVar10[1] = uVar4;

    puVar10 = puVar10 + 2;

  } while (0 < iVar8);

  puVar12 = (u16 *)(&DAT_006af320);

  puVar10 = auStack_1b0;

  iVar8 = 8;

  do {

    uVar3 = *puVar12;

    uVar4 = puVar12[1];

    puVar12 = puVar12 + 2;

    iVar8 = iVar8 + -1;

    *puVar10 = uVar3;

    puVar10[1] = uVar4;

    puVar10 = puVar10 + 2;

  } while (0 < iVar8);

  ppuVar6 = (u16 **)0x24;

  ppuVar7 = apuStack_1e0;

  ppuVar5 = ppuVar7;

  while (ppuVar5 != (u16 **)0x0) {

    *(u8 *)ppuVar7 = 0;

    ppuVar7 = (u16 **)((int)ppuVar7 + 1);

    ppuVar6 = (u16 **)((int)ppuVar6 + -1);

    ppuVar5 = ppuVar6;

  }

  apuStack_1e0[0] = auStack_e0;

  apuStack_1e0[1] = auStack_100;

  apuStack_1e0[2] = auStack_120;

  apuStack_1e0[3] = auStack_140;

  puStack_1d0 = auStack_170;

  puStack_1c8 = auStack_190;

  puStack_1c0 = auStack_1b0;

  uVar9 = (u32)((param_8 & 1) != 0);

  if (apuStack_1e0[param_6] != (u16 *)0x0) {

    unaff_s6_lo = apuStack_1e0[param_6];

  }

  iVar8 = uVar9 * 2;

  FUN_0040e3f0(0,0,param_1,param_1,param_2,param_3,param_5,auStack_30[param_6 * 2 + uVar9],0,0,0);

  bVar1 = abStack_b0[(int)param_7 + param_6 * 0xe];

  FUN_0040e3f0(0,0,param_1,param_1,param_2,param_3,param_5,unaff_s6_lo[iVar8 + (u32)bVar1 * 4],0,0,

               0);

  if ((param_8 & 2) != 0) {

    FUN_0040e3f0(0,0,param_1,param_1,param_2,param_3,param_5,

                 unaff_s6_lo[iVar8 + 1 + (u32)bVar1 * 4],0,0,0);

  }

  return;

}

// FUN_003FFA20 NONMATCHING


u8 FUN_003ffa20(u64 param_1,u64 param_2,int param_3)



{

  short sVar1;

  int iVar2;

  float fVar3;

  

  if (*(short *)(param_3 + 0xe) == 0) {

    sVar1 = *(short *)(param_3 + 10);

    fVar3 = ((float)(int)sVar1 * 0.5f) / (float)(int)*(short *)(param_3 + 0xc);

    iVar2 = 0xff - (sVar1 * 0x100 - (int)sVar1) / (int)*(short *)(param_3 + 0xc);

  }

  else {

    fVar3 = (float)cosf(DAT_007cae00 +

                                (DAT_007cae00 * (float)(int)*(short *)(param_3 + 10)) /

                                (float)(int)*(short *)(param_3 + 0xc));

    fVar3 = -fVar3 * 0.25f;

    iVar2 = 0x80 - ((int)*(short *)(param_3 + 10) << 7) / (int)*(short *)(param_3 + 0xc);

  }

  FUN_003ff630(fVar3 + 1.0f,param_1,param_2,0,iVar2,*(u16 *)(param_3 + 0x10),

               *(short *)(param_3 + 8) + -1,1);

  sVar1 = *(short *)(param_3 + 10) + 1;

  *(short *)(param_3 + 10) = sVar1;

  return *(short *)(param_3 + 0xc) <= sVar1;

}

// FUN_003FFBB0 NONMATCHING


void FUN_003ffbb0(int param_1,int param_2)



{

  u32 *puVar1;

  u32 uVar2;

  u64 uVar3;

  u64 uVar4;

  long lVar5;

  

  for (; param_2 != 0; param_2 = *(int *)(param_2 + 0x10)) {

    puVar1 = *(u32 **)(*(int *)(param_2 + 0x14) + 0x1c);

    uVar2 = puVar1[1];

    if (uVar2 == 0xb) {

      lVar5 = FUN_0017c700();

      if (lVar5 == 0) {

        *puVar1 = *puVar1 | 1;

      }

      else {

        *puVar1 = *puVar1 & 0xfffffffe;

      }

    }

    else if (uVar2 == 0xd) {


      if (lVar5 == 0) {

        *puVar1 = *puVar1 | 1;

      }

      else {

        *puVar1 = *puVar1 & 0xfffffffe;

      }

    }

    else if (uVar2 == 6) {

      uVar3 = FUN_003e6dc0();

      uVar4 = FUN_003c58f0(0,0x58,5,0x1a);


      FUN_003c5a20(uVar4);

      if (lVar5 == 0) {

        *puVar1 = *puVar1 | 1;

      }

    }

    else if (uVar2 == 5) {

      uVar3 = FUN_003e6dc0();

      uVar4 = FUN_003c58f0(0,0x58,5,0x1a);


      FUN_003c5a20(uVar4);

      if (lVar5 == 0) {

        *puVar1 = *puVar1 | 1;

      }

    }

    else if (uVar2 == 1) {

      uVar3 = FUN_003e6dc0();

      uVar4 = FUN_003c58f0(0,0x58,5,0x1a);


      FUN_003c5a20(uVar4);

      if (lVar5 == 0) {

        *puVar1 = *puVar1 | 1;

      }

    }

  }

  return;

}

// FUN_003FFE00


void FUN_003ffe00(int param_1)



{

  int iVar1;

  int iVar2;

  

  if (param_1 != 0) {

    iVar1 = *(int *)param_1;

    for (iVar2 = *(int *)(iVar1 + 4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x10)) {

      FUN_003ffbb0(iVar1,iVar2);

    }

  }

  return;

}

// FUN_003FFE60 NONMATCHING


int * FUN_003ffe60(u64 param_1)



{

  u8 uVar1;

  u8 uVar2;

  char cVar3;

  int *piVar4;

  int iVar5;

  long lVar6;

  u64 uVar7;

  u64 uVar8;

  int iVar9;

  u64 *puVar10;

  u8 *puVar11;

  u64 unaff_s0;

  u64 unaff_s1;

  int unaff_s2_lo;

  u64 unaff_s3;

  u64 uVar12;

  u64 uStack_58;

  u64 uStack_50;

  u64 uStack_48;

  u64 uStack_40;

  u64 uStack_38;

  u64 uStack_30;

  u64 uStack_28;

  u64 uStack_20;

  u64 uStack_18;

  u64 uStack_10;

  u64 uStack_8;

  

  uVar12 = 0x4006c0;

  switch(param_1) {

  case 0:

    unaff_s1 = 0x9a;

    unaff_s0 = 0x81;

    unaff_s3 = 0x66;

    unaff_s2_lo = 5;

    puVar11 = (u8 *)(&DAT_007cd980);

    puVar10 = &uStack_10;

    iVar9 = 4;

    do {

      uVar1 = *puVar11;

      uVar2 = puVar11[1];

      puVar11 = puVar11 + 2;

      iVar9 = iVar9 + -1;

      *(u8 *)puVar10 = uVar1;

      *(u8 *)((int)puVar10 + 1) = uVar2;

      puVar10 = (u64 *)((int)puVar10 + 2);

    } while (0 < iVar9);

    uStack_8 = uStack_10;

    break;

  default:

    unaff_s1 = 0xe6;

    unaff_s0 = 0x16d;

    unaff_s3 = 0x70;

    unaff_s2_lo = 4;

    puVar11 = (u8 *)(&DAT_007cd9c8);

    puVar10 = &uStack_58;

    iVar9 = unaff_s2_lo;

    do {

      uVar1 = *puVar11;

      uVar2 = puVar11[1];

      puVar11 = puVar11 + 2;

      iVar9 = iVar9 + -1;

      *(u8 *)puVar10 = uVar1;

      *(u8 *)((int)puVar10 + 1) = uVar2;

      puVar10 = (u64 *)((int)puVar10 + 2);

    } while (0 < iVar9);

    uStack_8 = uStack_58;

    break;

  case 2:

    unaff_s1 = 0xd7;

    unaff_s0 = 100;

    unaff_s3 = 0x70;

    unaff_s2_lo = 4;

    puVar11 = (u8 *)(&DAT_007cd988);

    puVar10 = &uStack_18;

    iVar9 = unaff_s2_lo;

    do {

      uVar1 = *puVar11;

      uVar2 = puVar11[1];

      puVar11 = puVar11 + 2;

      iVar9 = iVar9 + -1;

      *(u8 *)puVar10 = uVar1;

      *(u8 *)((int)puVar10 + 1) = uVar2;

      puVar10 = (u64 *)((int)puVar10 + 2);

    } while (0 < iVar9);

    uStack_8 = uStack_18;

    uVar12 = 0x400740;

    break;

  case 3:

    unaff_s1 = 0x5d;

    unaff_s0 = 0x55;

    unaff_s3 = 0x71;

    unaff_s2_lo = 3;

    puVar11 = (u8 *)(&DAT_007cd9b8);

    puVar10 = &uStack_48;

    iVar9 = 4;

    do {

      uVar1 = *puVar11;

      uVar2 = puVar11[1];

      puVar11 = puVar11 + 2;

      iVar9 = iVar9 + -1;

      *(u8 *)puVar10 = uVar1;

      *(u8 *)((int)puVar10 + 1) = uVar2;

      puVar10 = (u64 *)((int)puVar10 + 2);

    } while (0 < iVar9);

    uStack_8 = uStack_48;

    break;

  case 4:

    iVar9 = 0;

    lVar6 = datGetFlag(0x170);

    if (lVar6 != 0) {

      iVar9 = 2;

    }

    unaff_s3 = 0x62;

    if (iVar9 == 3) {

      unaff_s1 = 0x46;

      unaff_s0 = 0x6c;

      unaff_s2_lo = 6;

      puVar11 = (u8 *)(&DAT_007cd9a8);

      puVar10 = &uStack_38;

      iVar9 = 4;

      do {

        uVar1 = *puVar11;

        uVar2 = puVar11[1];

        puVar11 = puVar11 + 2;

        iVar9 = iVar9 + -1;

        *(u8 *)puVar10 = uVar1;

        *(u8 *)((int)puVar10 + 1) = uVar2;

        puVar10 = (u64 *)((int)puVar10 + 2);

      } while (0 < iVar9);

      uStack_8 = uStack_38;

    }

    else if (iVar9 == 2) {

      unaff_s1 = 0x77;

      unaff_s0 = 0x6c;

      unaff_s2_lo = 5;

      puVar11 = (u8 *)(&DAT_007cd9a0);

      puVar10 = &uStack_30;

      iVar9 = 4;

      do {

        uVar1 = *puVar11;

        uVar2 = puVar11[1];

        puVar11 = puVar11 + 2;

        iVar9 = iVar9 + -1;

        *(u8 *)puVar10 = uVar1;

        *(u8 *)((int)puVar10 + 1) = uVar2;

        puVar10 = (u64 *)((int)puVar10 + 2);

      } while (0 < iVar9);

      uStack_8 = uStack_30;

    }

    else if (iVar9 == 1) {

      unaff_s1 = 0x77;

      unaff_s0 = 0x6c;

      unaff_s2_lo = 5;

      puVar11 = (u8 *)(&DAT_007cd998);

      puVar10 = &uStack_28;

      iVar9 = 4;

      do {

        uVar1 = *puVar11;

        uVar2 = puVar11[1];

        puVar11 = puVar11 + 2;

        iVar9 = iVar9 + -1;

        *(u8 *)puVar10 = uVar1;

        *(u8 *)((int)puVar10 + 1) = uVar2;

        puVar10 = (u64 *)((int)puVar10 + 2);

      } while (0 < iVar9);

      uStack_8 = uStack_28;

    }

    else if (iVar9 == 0) {

      unaff_s1 = 0xa8;

      unaff_s0 = 0x6c;

      unaff_s2_lo = 4;

      puVar11 = (u8 *)(&DAT_007cd990);

      puVar10 = &uStack_20;

      iVar9 = unaff_s2_lo;

      do {

        uVar1 = *puVar11;

        uVar2 = puVar11[1];

        puVar11 = puVar11 + 2;

        iVar9 = iVar9 + -1;

        *(u8 *)puVar10 = uVar1;

        *(u8 *)((int)puVar10 + 1) = uVar2;

        puVar10 = (u64 *)((int)puVar10 + 2);

      } while (0 < iVar9);

      uStack_8 = uStack_20;

    }

    uVar12 = 0x4008f0;

    break;

  case 6:

    unaff_s1 = 0xe6;

    unaff_s0 = 0x16d;

    unaff_s3 = 0x70;

    unaff_s2_lo = 3;

    puVar11 = (u8 *)(&DAT_007cd9c0);

    puVar10 = &uStack_50;

    iVar9 = 4;

    do {

      uVar1 = *puVar11;

      uVar2 = puVar11[1];

      puVar11 = puVar11 + 2;

      iVar9 = iVar9 + -1;

      *(u8 *)puVar10 = uVar1;

      *(u8 *)((int)puVar10 + 1) = uVar2;

      puVar10 = (u64 *)((int)puVar10 + 2);

    } while (0 < iVar9);

    uStack_8 = uStack_50;

    break;

  case 8:

    unaff_s1 = 0x28;

    unaff_s0 = 0x16d;

    datGetFlag(0x1204);

    datGetFlag(0x1206);

    unaff_s2_lo = 6;

    puVar11 = (u8 *)(&DAT_007cd9b0);

    puVar10 = &uStack_40;

    iVar9 = 4;

    do {

      uVar1 = *puVar11;

      uVar2 = puVar11[1];

      puVar11 = puVar11 + 2;

      iVar9 = iVar9 + -1;

      *(u8 *)puVar10 = uVar1;

      *(u8 *)((int)puVar10 + 1) = uVar2;

      puVar10 = (u64 *)((int)puVar10 + 2);

    } while (0 < iVar9);

    uStack_8 = uStack_40;

  }

  uVar7 = FUN_003c58f0(0,0xc,10,unaff_s3);

  iVar9 = (int)uVar7;

  piVar4 = *(int **)(*(int *)(iVar9 + 0x24) + 0x44);

  *piVar4 = iVar9;

  iVar5 = FUN_003c44d0(4,0,0,0);

  **(int **)(iVar5 + 0x24) = (int)param_1;

  piVar4[1] = iVar5;

  piVar4[2] = (int)param_1;

  for (iVar5 = 0; iVar5 < unaff_s2_lo; iVar5 = iVar5 + 1) {

    cVar3 = *(char *)((int)&uStack_8 + iVar5);

    uVar8 = FUN_003c5a40(uVar7,cVar3,8,0);

    *(int *)(*(int *)(*(int *)((int)uVar8 + 0x14) + 0x1c) + 4) = (int)cVar3;


  }

  FUN_003c6d60(uVar7,0x800);

  FUN_003c6d40(uVar7,unaff_s1,unaff_s0);

  FUN_003c6ee0(uVar7);

  FUN_003c5e20(uVar7,uVar12);

  FUN_003c5ee0(uVar7,0x400b90);

  *(u16 *)(*(int *)(iVar9 + 0x24) + 6) = 10;

  *(u16 *)(*(int *)(iVar9 + 0x24) + 8) = 10;

  return piVar4;

}

// FUN_004003A0


void FUN_004003a0(int param_1)



{

  if (param_1 != 0) {

    if (((u32 *)param_1)[1] != 0) {

      FUN_003c45f0(((u32 *)param_1)[1]);

    }

    FUN_003c5a20(*(u32 *)param_1);

  }

  return;

}

// FUN_004003F0 NONMATCHING


u32 FUN_004003f0(int *param_1)



{

  u32 *puVar1;

  u32 uVar2;

  u32 uVar3;

  u32 uVar4;

  u32 uVar5;

  int iVar6;

  long lVar7;

  

  iVar6 = *param_1;

  lVar7 = FUN_003c6270(iVar6);

  if (lVar7 == 2) {

    uVar5 = 0xffffffff;

  }

  else {

    puVar1 = *(u32 **)(iVar6 + 0xc);

    lVar7 = FUN_003c6c50(iVar6);

    if (lVar7 == 0) {

      lVar7 = FUN_003c6c80(iVar6);

      if (lVar7 == 0) {

        lVar7 = FUN_003c6ce0(iVar6);

        if ((lVar7 != 0) || (lVar7 = FUN_003c6d10(iVar6), lVar7 != 0)) {

          func_0010a4e0(0,0,0,0);

          uVar5 = *puVar1;

          uVar2 = ((u32 *)puVar1[5])[1];

          uVar3 = *(u32 *)puVar1[5];

          iVar6 = param_1[1];

          puVar1 = *(u32 **)(iVar6 + 0x24);

          iVar6 = FUN_003c4910(iVar6,*(u16 *)(iVar6 + 0x10) + 1,0x14);

          iVar6 = *(int *)(iVar6 + 0x14);

          *(short *)(iVar6 + 4) = (short)uVar3;

          *(short *)(iVar6 + 6) = (short)uVar2;

          *(short *)(iVar6 + 8) = (short)uVar5;

          *(u16 *)(iVar6 + 0xe) = 1;

          *(u32 *)(iVar6 + 0x10) = *puVar1;

          *(u16 *)(iVar6 + 0xc) = 7;

        }

        uVar5 = 0;

      }

      else {

        FUN_003c6ea0(iVar6);

        func_0010a4e0(0,0,0,2);

        FUN_003c6f10(iVar6);

        uVar5 = *puVar1;

        uVar2 = ((u32 *)puVar1[5])[1];

        uVar3 = *(u32 *)puVar1[5];

        iVar6 = param_1[1];

        puVar1 = *(u32 **)(iVar6 + 0x24);

        iVar6 = FUN_003c4910(iVar6,*(u16 *)(iVar6 + 0x10) + 1,0x14);

        iVar6 = *(int *)(iVar6 + 0x14);

        *(short *)(iVar6 + 4) = (short)uVar3;

        *(short *)(iVar6 + 6) = (short)uVar2;

        *(short *)(iVar6 + 8) = (short)uVar5;

        *(u16 *)(iVar6 + 0xe) = 0;

        *(u32 *)(iVar6 + 0x10) = *puVar1;

        *(u16 *)(iVar6 + 0xc) = 5;

        uVar5 = 4;

      }

    }

    else if ((**(u32 **)(((u32 *)lVar7)[5] + 0x1c) & 1) == 0) {

      FUN_003c6ea0(iVar6);

      func_0010a4e0(0,0,0,1);

      uVar5 = *(u32 *)lVar7;

      FUN_003c6f10(iVar6);

      uVar2 = *puVar1;

      uVar3 = ((u32 *)puVar1[5])[1];

      uVar4 = *(u32 *)puVar1[5];

      iVar6 = param_1[1];

      puVar1 = *(u32 **)(iVar6 + 0x24);

      iVar6 = FUN_003c4910(iVar6,*(u16 *)(iVar6 + 0x10) + 1,0x14);

      iVar6 = *(int *)(iVar6 + 0x14);

      *(short *)(iVar6 + 4) = (short)uVar4;

      *(short *)(iVar6 + 6) = (short)uVar3;

      *(short *)(iVar6 + 8) = (short)uVar2;

      *(u16 *)(iVar6 + 0xe) = 0;

      *(u32 *)(iVar6 + 0x10) = *puVar1;

      *(u16 *)(iVar6 + 0xc) = 5;

    }

    else {

      func_0010a4e0(0,0,0,8);

      uVar5 = 0;

    }

  }

  return uVar5;

}

// FUN_00400690


u64 FUN_00400690(u32 *param_1)



{

  FUN_003c6380(*param_1);

  return 0;

}

// FUN_004006C0


void FUN_004006c0(int param_1,int param_2,int param_3,int param_4)



{
  int iVar1;
  int iVar2;
  int iVar3;
  int bVar3;
  int *piVar4;
  short *psVar;

  iVar1 = *(int *)(*(int *)(*(int *)(param_4 + 0x24) + 0x44) + 4);

  iVar2 = *(int *)(iVar1 + 4);

  while (iVar2 != 0) {
    psVar = *(short **)(iVar2 + 0x14);
    bVar3 = FUN_003ffa20_3(psVar[2],psVar[3],psVar);
    iVar3 = iVar2;
    iVar2 = *(int *)(iVar2 + 0x10);
    if (bVar3 != 0) {
      piVar4 = (int *)iVar1;
      FUN_003c49e0(piVar4,piVar4 + 1,iVar3);
    }

  }

  return;

}

// FUN_00400740 NONMATCHING


void FUN_00400740(u64 param_1,u64 param_2,u8 param_3,int param_4)



{

  int iVar1;

  long lVar2;

  int iVar3;

  int iVar4;

  

  iVar1 = *(int *)(*(int *)(param_4 + 0x24) + 0x44);

    FUN_0040e3c0(0x3f800000,param_1,param_2,param_3,0x15,0);

    FUN_0040e3c0(0x3f800000,param_1,param_2,param_3,0x16,0);

  iVar4 = (int)param_1;

    FUN_0040e3c0(0x3f800000,iVar4 + 0x15d,param_2,param_3,0x15,0);

    FUN_0040e3c0(0x3f800000,iVar4 + 0x15d,param_2,param_3,0x16,0);

    FUN_0040e3c0(0x3f800000,iVar4 + 0x70,param_2,param_3,0x17,0);

    FUN_0040e3c0(0x3f800000,iVar4 + 0x70,param_2,param_3,0x18,0);

    FUN_0040e3c0(0x3f800000,iVar4 + 0xe0,param_2,param_3,0x17,0);

    FUN_0040e3c0(0x3f800000,iVar4 + 0xe0,param_2,param_3,0x18,0);

  iVar1 = *(int *)(iVar1 + 4);

  iVar4 = *(int *)(iVar1 + 4);

  while (iVar3 = iVar4, iVar3 != 0) {

    lVar2 = FUN_003ffa20(*(u16 *)(*(int *)(iVar3 + 0x14) + 4),

                         *(u16 *)(*(int *)(iVar3 + 0x14) + 6),0);

    iVar4 = *(int *)(iVar3 + 0x10);

    if (lVar2 != 0) {

      FUN_003c49e0(iVar1,iVar1 + 4,iVar3);

    }

  }

  return;

}

// FUN_004008F0 NONMATCHING


void FUN_004008f0(u64 param_1,u64 param_2,u8 param_3,int param_4)



{

  short sVar1;

  int iVar2;

  int iVar3;

  long lVar4;

  int iVar5;

  

  iVar2 = *(int *)(*(int *)(param_4 + 0x24) + 0x44);

  sVar1 = *(short *)(param_4 + 0x10);

  if (sVar1 == 6) {

    FUN_0040e3c0(1.0f,param_1,param_2,param_3,0x4f,0);

    FUN_0040e3c0(1.0f,param_1,param_2,param_3,0x50,0);

  }

  else if (sVar1 == 5) {

    FUN_0040e3c0(1.0f,param_1,param_2,param_3,0x51,0);

    FUN_0040e3c0(1.0f,param_1,param_2,param_3,0x52,0);

  }

  else if (sVar1 == 4) {

    FUN_0040e3c0(1.0f,param_1,param_2,param_3,0x53,0);

    FUN_0040e3c0(1.0f,param_1,param_2,param_3,0x54,0);

  }

  iVar2 = *(int *)(iVar2 + 4);

  iVar3 = *(int *)(iVar2 + 4);

  while (iVar5 = iVar3, iVar5 != 0) {

    lVar4 = FUN_003ffa20(*(u16 *)(*(int *)(iVar5 + 0x14) + 4),

                         *(u16 *)(*(int *)(iVar5 + 0x14) + 6),0);

    iVar3 = *(int *)(iVar5 + 0x10);

    if (lVar4 != 0) {

      FUN_003c49e0(iVar2,iVar2 + 4,iVar5);

    }

  }

  return;

}

// FUN_00400A90 NONMATCHING


void FUN_00400a90(int param_1,u64 param_2,int param_3,int param_4,u32 *param_5)



{

  u8 bVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = *(int *)(param_4 + 0x24);

  iVar3 = 0;

  bVar1 = param_5 == *(u32 **)(param_4 + 0xc);

  if (bVar1) {

    iVar3 = (int)((float)(*(short *)(iVar2 + 4) * 600) / (float)(int)*(short *)(iVar2 + 8));

    param_3 = 0xff;

  }

  if ((**(u32 **)(param_5[5] + 0x1c) & 1) != 0) {

    param_3 = (int)((float)param_3 * fGpffff8090);

  }

  FUN_003ff630(0x3f800000,param_1 + iVar3,param_2,0,param_3,

               *(u16 *)(*(int *)(iVar2 + 0x44) + 8),(short)*param_5 + -1,bVar1 | 2);

  return;

}

// FUN_00400B90 NONMATCHING


void FUN_00400b90(u64 param_1,u64 param_2,int param_3,u64 param_4,

                 u32 *param_5)



{

  long lVar1;

  int iVar2;

  

  lVar1 = FUN_003c6e10(param_4);

  iVar2 = (int)param_4;

  if (lVar1 == 1) {

    if ((**(u32 **)(param_5[5] + 0x1c) & 1) != 0) {

      param_3 = (int)((float)param_3 * fGpffff8090);

    }

    FUN_003ff630(0x3f800000,param_1,param_2,0,param_3,

                 *(u16 *)(*(int *)(*(int *)(iVar2 + 0x24) + 0x44) + 8),(short)*param_5 + -1,

                 param_5 == *(u32 **)(iVar2 + 0xc) | 2);

  }

  else if (lVar1 == 0x14) {


  }

  else if (lVar1 == 0xc) {

    if ((**(u32 **)(param_5[5] + 0x1c) & 1) != 0) {

      param_3 = (int)((float)param_3 * fGpffff8090);

    }

    FUN_003ff630(0x3f800000,param_1,param_2,0,param_3,

                 *(u16 *)(*(int *)(*(int *)(iVar2 + 0x24) + 0x44) + 8),(short)*param_5 + -1,

                 param_5 == *(u32 **)(iVar2 + 0xc) | 2);

  }

  return;

}

// FUN_00400D60 NONMATCHING


int FUN_00400d60(void)



{

  int iVar1;

  int iVar2;

  u64 uVar3;

  

  iVar2 = FUN_003c44d0(0x20,0,0,0);

  iVar1 = *(int *)(iVar2 + 0x24);

  *(int *)(iVar1 + 8) = iVar2;

  uVar3 = (u64)kwlnTaskCreate(0,(const char *)0x6af340,0x18b3,(KwlnTaskUpdateFunc)0x401210,0,(void *)iVar1);

  *(int *)(iVar1 + 0xc) = (int)uVar3;

  uVar3 = (u64)kwlnTaskCreate((KwlnTask *)uVar3,(const char *)0x6af360,0x18b5,(KwlnTaskUpdateFunc)0x4012c0,0,(void *)iVar1);

  kwlnTaskCreate((KwlnTask *)uVar3,(const char *)0x6af380,0x18b7,(KwlnTaskUpdateFunc)0x401370,0,(void *)iVar1);

  *(u32 *)(iVar1 + 0x18) = 0xffffffff;

  return iVar1;

}

// FUN_00400E30


void FUN_00400e30(int param_1)



{

  int iVar1;

  

  if ((param_1 != 0) && (iVar1 = param_1, *(int *)(iVar1 + 8) != 0)) {

    if (*(int *)(iVar1 + 0xc) != 0) {

      kwlnTaskDestroyWithHierarchy((KwlnTask *)*(u32 *)(iVar1 + 0xc));

    }

    FUN_003c45f0(*(u32 *)(iVar1 + 8));

  }

  return;

}

// FUN_00400E90 NONMATCHING


void FUN_00400e90(u64 param_1)



{

  u32 *puVar1;

  u32 uVar2;

  u8 bVar3;

  u8 bVar4;

  int iVar5;

  long lVar6;

  u32 uVar7;

  u32 *puVar8;

  u32 *puVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  int *piVar13;

  

  puVar8 = (u32 *)param_1;

  uVar7 = puVar8[2];

  if ((*puVar8 & 1) != 0) {

    if ((*puVar8 & 2) != 0) {

      piVar13 = (int *)(*(int *)puVar8[4] + puVar8[5] * 8);

      iVar12 = *piVar13;

      iVar10 = 0;

      for (iVar11 = 0; iVar5 = piVar13[1], iVar11 < iVar5; iVar11 = iVar11 + 1) {

        puVar9 = (u32 *)(iVar12 + iVar11 * 8);

        if (puVar8[1] == *puVar9) {

          iVar5 = FUN_003c4b50(uVar7,uVar7 + 4,(short)puVar9[1] + 1);

          puVar1 = *(u32 **)(iVar5 + 0x14);

          uVar2 = *puVar1;

          if ((uVar2 & 1) == 0) {

            *puVar1 = uVar2 | 1;

            *puVar1 = uVar2 | 3;

          }

          else if (*(short *)((int)puVar9 + 6) == 2) {

            *puVar1 = uVar2 & 0xfffffffe;

            *puVar1 = uVar2 & 0xfffffffc;

          }

          if (*(int *)puVar1[2] == 0) {

            K_Assert((const char *)(u32)0x6aede8,0x192a);

          }

          (*(code *)puVar1[2])(param_1,puVar1,puVar9);

        }

        if ((int)*puVar9 <= (int)puVar8[1]) {

          iVar10 = iVar10 + 1;

        }

      }

      if (iVar10 == iVar5) {

        *puVar8 = *puVar8 & 0xfffffffd;

      }

    }

    bVar3 = 0;

    for (iVar12 = *(int *)(uVar7 + 4); iVar12 != 0; iVar12 = *(int *)(iVar12 + 0x10)) {

      puVar9 = *(u32 **)(iVar12 + 0x14);

      bVar4 = bVar3;

      if ((*puVar9 & 1) != 0) {

        lVar6 = (*(code *)puVar9[2])(param_1,puVar9,0);

        if (lVar6 == 2) {

          *puVar9 = *puVar9 & 0xfffffffe;

        }

        else if (lVar6 == 1) {

          *puVar9 = *puVar9 & 0xfffffffd;

        }

        else {

          bVar4 = 1;

          if (lVar6 != 0) {

            bVar4 = bVar3;

          }

        }

      }

      bVar3 = bVar4;

      uVar7 = puVar9[1];

      puVar9[1] = uVar7 + 1;

      if (0xffffffe < (int)(uVar7 + 1)) {

        puVar9[1] = 0xfffffff;

      }

    }

    uVar7 = puVar8[1];

    puVar8[1] = uVar7 + 1;

    if (0xffffffe < (int)(uVar7 + 1)) {

      puVar8[1] = 0xfffffff;

    }

    if (((*puVar8 & 4) != 0) && (!bVar3)) {

      uVar7 = *puVar8 & 0xfffffffb;

      *puVar8 = uVar7;

      *puVar8 = uVar7 | 2;

      puVar8[5] = puVar8[6];

      puVar8[1] = 0;

    }

  }

  return;

}

// FUN_00401170 NONMATCHING


void FUN_00401170(u64 param_1)



{

  code *pcVar1;

  u32 uVar2;

  int iVar3;

  

  uVar2 = *(u32 *)param_1 & 1;

  if ((uVar2 != 0) && (uVar2 != 0)) {

    for (iVar3 = *(int *)(((u32 *)param_1)[2] + 4); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x10)) {

      uVar2 = (*(u32 **)(iVar3 + 0x14))[2];

      if (((*(int *)(uVar2 + 0x14) == 3) && ((**(u32 **)(iVar3 + 0x14) & 1) != 0)) &&

         (pcVar1 = *(code **)(uVar2 + 4), pcVar1 != (code *)0x0)) {

        (*pcVar1)(param_1);

      }

    }

  }

  return;

}

// FUN_00401210


u32 FUN_00401210(int param_1)
{
  u32 *puVar1;
  u32 *puVar4;
  u32 uVar2;
  u32 uVar4;
  u32 uVar3;
  u32 *puVar2;
  code pcVar3;
  int iVar4;
  puVar1 = *(u32 **)(param_1 + 0x3c);
  uVar4 = *puVar1;
  uVar3 = uVar4 & 1;
  if (uVar3 == 0) {
    return 0;
  }
  puVar4 = (u32 *)puVar1[2];
  if (uVar3 != 0) {
    for (iVar4 = *(int *)(puVar4 + 1); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x10)) {
      puVar2 = *(u32 **)(iVar4 + 0x14);
      uVar2 = puVar2[2];
      if (((*(int *)(uVar2 + 0x14) == 0) && ((*puVar2 & 1) != 0)) &&
         (pcVar3 = *(code *)(uVar2 + 4), pcVar3 != (code)0)) {
        (*pcVar3)(puVar1,puVar2);
      }
    }
  }
  return 0;
}

// FUN_004012C0


u64 FUN_004012c0(int param_1)



{

  u32 *puVar1;
  u32 *puVar4;

  u32 uVar2;
  code pcVar3;

  int iVar4;

  

  puVar1 = *(u32 **)(param_1 + 0x3c);
  if ((*puVar1 & 1) == 0) {
    return 0;
  }
  puVar4 = (u32 *)puVar1[2];
  if ((*puVar1 & 1) != 0) {
    for (iVar4 = *(int *)(puVar4 + 1); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x10)) {

      uVar2 = (*(u32 **)(iVar4 + 0x14))[2];

      if (((*(int *)(uVar2 + 0x14) == 2) && ((**(u32 **)(iVar4 + 0x14) & 1) != 0)) &&

         (pcVar3 = *(code *)(uVar2 + 4), pcVar3 != (code)0)) {

        (*pcVar3)(puVar1);

      }

    }

  }

  return 0;

}

// FUN_00401370


u64 FUN_00401370(int param_1)



{

  u32 *puVar1;
  u32 *puVar4;
  u32 uVar2;
  u32 uVar3;
  u32 *puVar2;
  code pcVar3;
  int iVar4;

  puVar1 = *(u32 **)(param_1 + 0x3c);
  uVar2 = *puVar1;
  uVar3 = uVar2 & 1;
  if (uVar3 == 0) {
    return 0;
  }
  puVar4 = (u32 *)puVar1[2];
  if (uVar3 != 0) {
    for (iVar4 = *(int *)(puVar4 + 1); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x10)) {
      puVar2 = *(u32 **)(iVar4 + 0x14);
      uVar2 = puVar2[2];
      if (((*(int *)(uVar2 + 0x14) == 4) && ((*puVar2 & 1) != 0)) &&
         (pcVar3 = *(code *)(uVar2 + 4), pcVar3 != (code)0)) {
        (*pcVar3)(puVar1);
      }
    }
  }
  return 0;

}

// FUN_00401420


void FUN_00401420(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  *(int *)(param_1 + 0x10) = param_2;

  iVar1 = *(int *)(param_1 + 8);

  for (iVar4 = 0; iVar4 < *(int *)(param_2 + 0xc); iVar4 = iVar4 + 1) {

    iVar3 = iVar4 * 0x1c;

    iVar2 = FUN_003c4910(iVar1,*(u16 *)(iVar1 + 0x10) + 1,

                         *(int *)(*(int *)(param_2 + 8) + iVar3 + 8) + 0x10);

    iVar2 = *(int *)(iVar2 + 0x14);

    *(int *)(iVar2 + 8) = *(int *)(param_2 + 8) + iVar3;

    if (*(int *)(*(int *)(param_2 + 8) + iVar3 + 8) != 0) {

      *(int *)(iVar2 + 0xc) = iVar2 + 0x10;

    }

  }

  return;

}

// FUN_004014E0 NONMATCHING


u32 FUN_004014e0(u64 param_1)



{

  u32 *puVar1;

  u32 uVar2;

  long lVar3;

  u32 *puVar4;

  int iVar5;

  

  puVar4 = (u32 *)param_1;

  iVar5 = *(int *)(puVar4[2] + 4);

  do {

    if (iVar5 == 0) {

      uVar2 = *puVar4;

      *puVar4 = uVar2 & 0xfffffffe;

      *puVar4 = uVar2 & 0xfffffffe | 2;

      return 1;

    }

    puVar1 = *(u32 **)(iVar5 + 0x14);

    if ((*(code **)(puVar1[2] + 0x10) != (code *)0x0) && ((*puVar1 & 4) == 0)) {

      lVar3 = (*(code *)(puVar1[2] + 0x10))(param_1,puVar1);

      if (lVar3 == 0) {

        return 0;

      }

      *puVar1 = *puVar1 | 4;

    }

    iVar5 = *(int *)(iVar5 + 0x10);

  } while( 1 );

}

// FUN_004015A0


void FUN_004015a0(u32 *param_1,u32 param_2)



{

  if (param_1[6] != param_2) {

    if ((*param_1 & 1) != 0) {

      *param_1 = *param_1 | 4;

    }

    *param_1 = *param_1 | 1;

    param_1[6] = param_2;

  }

  return;

}

// FUN_004015E0


u8 FUN_004015e0(u32 *param_1)



{

  return (*param_1 & 2) != 0;

}

// FUN_00401600


int FUN_00401600(u64 param_1,u64 param_2,int param_3)
{
  switch (param_3) {
  case 1:
  case 3:
    H_Maestro_00111c50_i(param_2);
    H_Maestro_RequestDraw_i(param_2);
    break;
  case 0x24:
    H_Maestro_SetAlphaMult_f32(0.0f,param_2);
    H_Maestro_00111c50_i(param_2);
    break;
  case 2:
  case 0x23:
    H_Maestro_00111c50_i(param_2);
    break;
  }
  return param_3;
}

// FUN_004016D0


u32 FUN_004016d0(u32 param_1)
{
  u32 uVar3;
  s32 lVar1;
  s32 lVar2;

  lVar1 = FUN_00173a00_s32(param_1,0);
  uVar3 = 1;
  lVar2 = FUN_00173a00_s32(param_1,1);
  if (lVar1 <= lVar2) {
    if (lVar1 == lVar2) {
      uVar3 |= 2;
    }
    else {
      uVar3 = 2;
    }
    lVar1 = lVar2;
  }
  lVar2 = FUN_00173a00_s32(param_1,2);
  if (lVar1 < lVar2) {
    if (lVar1 == lVar2) {
      uVar3 |= 4;
    }
    else {
      uVar3 = 4;
    }
    lVar1 = lVar2;
  }
  lVar2 = FUN_00173a00_s32(param_1,3);
  if (lVar1 < lVar2) {
    if (lVar1 == lVar2) {
      uVar3 |= 8;
    }
    else {
      uVar3 = 8;
    }
    lVar1 = lVar2;
  }
  lVar2 = FUN_00173a00_s32(param_1,4);
  if (lVar1 < lVar2) {
    if (lVar1 == lVar2) {
      uVar3 |= 0x10;
    }
    else {
      uVar3 = 0x10;
    }
  }
  return uVar3;
}

// FUN_00401800


int FUN_00401800(short param_1)



{

  s16 uVar1;

  s16 uVar2;

  s16 *puVar6;
  short *psVar5;
  int iVar3;
  u32 uVar3;
  u32 uVar4;

  short asStack_30 [24];

  
  puVar6 = (s16 *)(DAT_006af3a0_abs);
  psVar5 = asStack_30;
  iVar3 = 0xc;
  do {

    uVar1 = *puVar6;

    uVar2 = puVar6[1];

    puVar6 = puVar6 + 2;

    iVar3 = iVar3 + -1;

    *psVar5 = uVar1;

    psVar5[1] = uVar2;

    psVar5 = psVar5 + 2;

  } while (0 < iVar3);

  uVar4 = 0;
  uVar3 = (u16)param_1;
  goto check;
body:
  if (uVar3 == (u16)asStack_30[uVar4]) {
    return uVar4 + 0x1280;
  }
  uVar4 = uVar4 + 1;
check:
  if (uVar4 < 0x18) {
    goto body;
  }
  return 0;

}

// FUN_00401890 NONMATCHING


u32 FUN_00401890(short param_1)



{

  short sVar1;

  short sVar2;

  u32 uVar3;

  long lVar4;

  int iVar5;

  u32 uVar6;

  short *psVar7;

  short *psVar8;

  short asStack_30 [24];

  

  psVar8 = (s16 *)(&DAT_006af3a0);

  psVar7 = asStack_30;

  iVar5 = 0xc;

  do {

    sVar1 = *psVar8;

    sVar2 = psVar8[1];

    psVar8 = psVar8 + 2;

    iVar5 = iVar5 + -1;

    *psVar7 = sVar1;

    psVar7[1] = sVar2;

    psVar7 = psVar7 + 2;

  } while (0 < iVar5);

  uVar6 = 0;

  do {

    if (0x17 < uVar6) {

      iVar5 = 0;

LAB_00401910:

      if ((iVar5 == 0) || (lVar4 = datGetFlag(), lVar4 != 0)) {

        uVar3 = 0;

      }

      else {

        uVar3 = 1;

      }

      return uVar3;

    }

    if (param_1 == asStack_30[uVar6]) {

      iVar5 = uVar6 + 0x1280;

      goto LAB_00401910;

    }

    uVar6 = uVar6 + 1;

  } while( 1 );

}

// FUN_00401950 NONMATCHING


u64 FUN_00401950(short param_1)



{

  short sVar1;

  short sVar2;

  int iVar3;

  u32 uVar4;

  short *psVar5;

  short *psVar6;

  short asStack_30 [24];

  

  psVar6 = (s16 *)(&DAT_006af3a0);

  psVar5 = asStack_30;

  iVar3 = 0xc;

  do {

    sVar1 = *psVar6;

    sVar2 = psVar6[1];

    psVar6 = psVar6 + 2;

    iVar3 = iVar3 + -1;

    *psVar5 = sVar1;

    psVar5[1] = sVar2;

    psVar5 = psVar5 + 2;

  } while (0 < iVar3);

  uVar4 = 0;

  do {

    if (0x17 < uVar4) {

      iVar3 = 0;

LAB_004019d0:

      if (iVar3 != 0) {

        datSetFlag(iVar3,1);

      }

      return 0;

    }

    if (param_1 == asStack_30[uVar4]) {

      iVar3 = uVar4 + 0x1280;

      goto LAB_004019d0;

    }

    uVar4 = uVar4 + 1;

  } while( 1 );

}

// FUN_00401A00 NONMATCHING






u32 FUN_00401a00(u16 param_1,long param_2,short *param_3)



{

  u16 uVar1;

  u8 bVar2;

  short sVar3;

  u32 uVar4;

  u32 uVar5;

  u32 uVar6;

  short *psVar7;

  int iVar8;

  u16 *puVar9;

  u16 *puVar10;

  u32 uVar11;

  u32 *puVar12;

  u32 uStack_30;

  u32 uStack_2c;

  u32 uStack_28;

  u32 uStack_24;

  u16 auStack_20 [15];

  short sStack_2;

  

  if (param_3 == (short *)0x0) {

    param_3 = &sStack_2;

  }

  if (param_2 == 0) {

    K_Assert((const char *)(u32)0x6aede8,0x1aa8);

  }

  for (iVar8 = 0; iVar8 < iGpffffabfc; iVar8 = iVar8 + 1) {

    psVar7 = (short *)(iGpffffabf8 + iVar8 * 4);

    if (*(short *)((int)param_2 + 2) == *psVar7) {

      sVar3 = psVar7[1];

      goto LAB_00401aa4;

    }

  }

  sVar3 = 0;

LAB_00401aa4:

  *param_3 = sVar3;

  if (sVar3 == 0) {

    uVar11 = 0;

    uStack_30 = _DAT_006af180;

    uStack_2c = _DAT_006af184;

    uStack_28 = DAT_006af188;

    uStack_24 = DAT_006af18c;

    puVar10 = (u16 *)&uStack_30;

    puVar9 = auStack_20;

    iVar8 = 4;

    while( 1 ) {

      do {

        uVar1 = puVar10[1];

        iVar8 = iVar8 + -1;

        *puVar9 = *puVar10;

        puVar9[1] = uVar1;

        puVar10 = puVar10 + 2;

        puVar9 = puVar9 + 2;

      } while (0 < iVar8);

      if (uVar11 < 8) {

        uVar6 = (u32)auStack_20[uVar11];

      }

      else {

        uVar6 = 0;

      }

      if (uVar6 == 0) {

        bVar2 = 0;

        goto LAB_00401b60;

      }

      if (param_1 == uVar6) break;

      uVar11 = uVar11 + 1;

      puVar10 = (u16 *)&uStack_30;

      puVar9 = auStack_20;

      iVar8 = 4;

    }

    bVar2 = 1;

LAB_00401b60:

    if (!bVar2) {

      psVar7 = psGpffffabd0;

      for (uVar11 = 0; uVar11 < uGpffffabd4; uVar11 = uVar11 + 1) {

        if ((long)*psVar7 == (u32)param_1) {

          param_1 = psVar7[1];

          goto LAB_00401bc4;

        }

        psVar7 = psVar7 + 2;

      }

      param_1 = 0;

    }

LAB_00401bc4:

    puVar12 = puGpffffabe0;

    for (uVar11 = 0; uVar11 < uGpffffabe4; uVar11 = uVar11 + 1) {

      if ((u32)(u16)puVar12[1] == (long)(short)param_1) {

        if (puVar12 == (u32 *)0x0) {

          K_Assert((const char *)(u32)0x6aede8,0x1a47);

        }


        if ((*puVar12 & uVar5) != 0) goto LAB_00401c48;

      }

      puVar12 = puVar12 + 4;

    }

    puVar12 = (u32 *)0x0;

LAB_00401c48:

    if (puVar12 == (u32 *)0x0) {

      uVar4 = 0;

    }

    else {

      *param_3 = *(short *)((int)puVar12 + 6);

      uVar4 = 1;

    }

  }

  else {

    uVar4 = 2;

  }

  return uVar4;

}

// FUN_00401C90


u8 * FUN_00401c90(u32 *param_1,int param_2)



{

  u8 bVar1;
  u8 *pbVar2;

  u32 uVar3;

  u32 uVar4;

  

  pbVar2 = (u8 *)*param_1;

  uVar3 = 0;

  uVar4 = param_1[1];

  while (uVar3 < uVar4) {

    bVar1 = *(u8 *)(param_2 + 4);

    if (*pbVar2 > bVar1) goto advance;
    if (pbVar2[1] < bVar1) goto advance;

    return pbVar2;

advance:

    pbVar2 = pbVar2 + 6;

    uVar3 = uVar3 + 1;

  }

  return (u8 *)0x0;

}

// FUN_00401CF0


u8 * FUN_00401cf0(int param_1)
{
  u8 value;
  u8 *entry;
  u32 index;
  u32 count;
  u32 aboveRange;

  if (param_1 == 0) {
    K_Assert((const char *)DAT_006aede8,0x1ada);
  }

  entry = pbGpffffabe8;
  index = 0;
  count = uGpffffabec;
  goto check;
body:
  value = *(u8 *)(param_1 + 4);
  if (*entry > value) {
    goto increment;
  }
  aboveRange = entry[1] < value;
  if (aboveRange) {
    goto increment;
  }
  goto found;
found:
  return entry;
increment:
  entry = entry + 0x2e;
  index = index + 1;
check:
  if (index < count) {
    goto body;
  }
  return (u8 *)0x0;

}

// FUN_00401D90


short * FUN_00401d90(int param_1)



{

  u32 uVar2;
  u16 *psVar1;

  u32 uVar3;

  

  psVar1 = (u16 *)psGpffffabf0;
  uVar2 = 0;
  uVar3 = uGpffffabf4;

  while (uVar2 < uVar3) {

    if (*psVar1 == *(u16 *)(param_1 + 2)) {

      return (short *)psVar1;

    }

    psVar1 = psVar1 + 3;

    uVar2 = uVar2 + 1;

  }

  return (short *)0x0;

}

// FUN_00401DE0 NONMATCHING






u32 FUN_00401de0(u64 param_1,long param_2,long param_3)



{

  u16 uVar1;

  u16 uVar2;

  u8 bVar3;

  short sVar4;

  u8 uVar5;

  short sVar6;

  u32 uVar7;

  int iVar8;

  long lVar9;

  u16 *puVar10;

  u32 uVar11;

  u16 uVar12;

  short *psVar13;

  u16 *puVar14;

  u16 *puVar15;

  u32 uVar16;

  u32 *puVar17;

  int iVar18;

  u32 unaff_s5_lo;

  u32 uStack_30;

  u32 uStack_2c;

  u32 uStack_28;

  u32 uStack_24;

  u16 auStack_20 [14];

  int iStack_4;

  

  if (param_2 == 0) {

    K_Assert((const char *)(u32)0x6aede8,0x1b5d);

  }

  if (param_3 == 0) {

    K_Assert((const char *)(u32)0x6aede8,0x1b5e);

  }

  memset(param_1,0,0x1c);

  iVar18 = (int)param_3;

  uVar2 = *(u16 *)(iVar18 + 2);

  for (iVar8 = 0; iVar8 < iGpffffabfc; iVar8 = iVar8 + 1) {

    puVar10 = (u16 *)(iGpffffabf8 + iVar8 * 4);

    if (uVar2 == *puVar10) {

      uVar12 = puVar10[1];

      goto LAB_00401ea8;

    }

  }

  uVar12 = 0;

LAB_00401ea8:

  puVar10 = (u16 *)param_1;

  if (uVar12 == 0) {

    uVar12 = *(u16 *)param_2;

    uVar16 = 0;

    uStack_30 = _DAT_006af180;

    uStack_2c = _DAT_006af184;

    uStack_28 = DAT_006af188;

    uStack_24 = DAT_006af18c;

    puVar15 = (u16 *)&uStack_30;

    puVar14 = auStack_20;

    iVar8 = 4;

    while( 1 ) {

      do {

        uVar1 = puVar15[1];

        iVar8 = iVar8 + -1;

        *puVar14 = *puVar15;

        puVar14[1] = uVar1;

        puVar15 = puVar15 + 2;

        puVar14 = puVar14 + 2;

      } while (0 < iVar8);

      if (uVar16 < 8) {

        uVar11 = (u32)auStack_20[uVar16];

      }

      else {

        uVar11 = 0;

      }

      if (uVar11 == 0) {

        bVar3 = 0;

        goto LAB_00401fa8;

      }

      if (uVar12 == uVar11) break;

      uVar16 = uVar16 + 1;

      puVar15 = (u16 *)&uStack_30;

      puVar14 = auStack_20;

      iVar8 = 4;

    }

    bVar3 = 1;

LAB_00401fa8:

    if (bVar3) {

      if (*(char *)((u32)uVar2 * 0xe + iGpffffb730 + 2) == '\x01') {

        bVar3 = 1;

      }

      else {

        bVar3 = 0;

      }

    }

    else {

      psVar13 = psGpffffabd0;

      for (uVar16 = 0; uVar16 < uGpffffabd4; uVar16 = uVar16 + 1) {

        if ((long)*psVar13 == (u32)uVar12) {

          uVar12 = psVar13[1];

          goto LAB_0040203c;

        }

        psVar13 = psVar13 + 2;

      }

      uVar12 = 0;

LAB_0040203c:

      if (*(char *)((u32)uVar2 * 0xe + iGpffffb730 + 2) == '\x01') {

        bVar3 = 1;

      }

      else {

        bVar3 = 0;

      }

    }

    puVar17 = puGpffffabe0;

    for (uVar16 = 0; uVar16 < uGpffffabe4; uVar16 = uVar16 + 1) {

      if ((u32)(u16)puVar17[1] == (long)(short)uVar12) {

        if (puVar17 == (u32 *)0x0) {

          K_Assert((const char *)(u32)0x6aede8,0x1a47);

        }


        if ((*puVar17 & uVar7) != 0) goto LAB_00402100;

      }

      puVar17 = puVar17 + 4;

    }

    puVar17 = (u32 *)0x0;

LAB_00402100:

    if (puVar17 == (u32 *)0x0) {

      return 0;

    }

    if (puVar17 == (u32 *)0x0) {

      K_Assert((const char *)(u32)0x6aede8,0x1b37);

    }

    uVar2 = *(u16 *)((int)puVar17 + 6);

    iVar8 = func_00170d60(uVar2);

    puVar10[2] = uVar2;

    *(u32 *)(puVar10 + 4) = *(u32 *)(iVar8 + 4);


    func_00170d60(puVar10[2]);


    if (lVar9 == 0) {

      K_Assert((const char *)(u32)0x6aede8,0x1afa);

    }

    puVar10[7] = *(u16 *)((int)lVar9 + 2);

    puVar10[8] = *(u16 *)((int)lVar9 + 4);


    if (lVar9 == 0) {

      K_Assert((const char *)(u32)0x6aede8,0x1b05);

    }

    *(char *)((int)puVar10 + 0xd) =

         (char)*(u16 *)

                ((int)lVar9 +

                (u32)*(u8 *)((u32)*(u16 *)(iVar18 + 2) * 0xe + iGpffffb730 + 2) * 2);

    if (bVar3) {


      if (lVar9 == 0) {

        K_Assert((const char *)(u32)0x6aede8,0x1b51);

      }

      if (puVar10 == (u16 *)0xfffffffc) {

        K_Assert((const char *)(u32)0x6aede8,0x1b52);

      }

      iVar8 = (int)lVar9;

      puVar10[7] = (u16)*(u8 *)(iVar8 + 2);

      puVar10[8] = (u16)*(u8 *)(iVar8 + 3);

      *(u8 *)((int)puVar10 + 0xd) = *(u8 *)(iVar8 + 4);

    }

  }

  else {

    *puVar10 = *puVar10 | 2;

    if (puVar10 == (u16 *)0xfffffffc) {

      K_Assert((const char *)(u32)0x6aede8,0x1b2f);

    }

    func_001828d0(uVar12,puVar10 + 2);

  }

  sVar6 = datGetDaysSinceApr5();

  if ((*puVar10 & 2) == 0) {

    sVar4 = 1;

  }

  else {

    sVar4 = 2;

  }

  uVar5 = clndGetMonthFromDaysSinceApr5(sVar6 + sVar4);

  *(u8 *)(puVar10 + 1) = uVar5;

  uVar5 = clndGetDayOfMonthFromDaysSinceApr5(sVar6 + sVar4);

  *(u8 *)((int)puVar10 + 3) = uVar5;

  *puVar10 = *puVar10 | 1;


  if ((lVar9 == 0) || (lVar9 = datGetFlag(lVar9), lVar9 != 0)) {

    bVar3 = 0;

  }

  else {

    bVar3 = 1;

  }

  if (bVar3) {

    iVar8 = func_00170ed0(puVar10[2],&iStack_4);

    if (iStack_4 == 4) {

      unaff_s5_lo = *(u32 *)(iVar8 + 0x18);

    }

    else if (iStack_4 == 3) {

      unaff_s5_lo = *(u32 *)(iVar8 + 0x20);

    }

    else if (iStack_4 == 2) {

      unaff_s5_lo = *(u32 *)(iVar8 + 0x1c);

    }

    else if (iStack_4 == 1) {

      unaff_s5_lo = *(u32 *)(iVar8 + 0x1c);

    }

    else if (iStack_4 == 0) {

      unaff_s5_lo = *(u32 *)(iVar8 + 0x24);

    }

    *(u32 *)(puVar10 + 0xc) = unaff_s5_lo;

  }

  else {

    *(u32 *)(puVar10 + 0xc) = *(u8 *)(iVar18 + 4) / 5 + 1;

  }

  return 1;

}

// FUN_00402400


void FUN_00402400(int param_1,u16 *param_2)



{

  u32 uVar1;

  

  *param_2 = *(u16 *)(param_1 + 4);

  param_2[5] = 1;

  *(u8 *)((int)param_2 + 9) = *(u8 *)(param_1 + 0xd);

  *(u8 *)(param_2 + 4) = *(u8 *)(param_1 + 0xc);

  uVar1 = FUN_003f1a10(*(u32 *)(param_1 + 8));

  *(u32 *)(param_2 + 2) = uVar1;

  *(u32 *)(param_2 + 6) = 1;

  param_2[8] = *(u16 *)(param_1 + 0xe);

  param_2[9] = *(u16 *)(param_1 + 0x10);

  return;

}

// FUN_00402480


u32 FUN_00402480(u16 *param_1)



{

  u32 uVar1;

  int iVar2;

  u16 auStack_20 [16];

  

  if (param_1 == (u16 *)0x0) {

    param_1 = auStack_20;

  }

  FUN_0017c220(param_1);

  if ((*(short *)param_1 & 1) == 0) {

    uVar1 = 0;

  }

  else {

    iVar2 = clndIsDateInRangeFromStart((char)param_1[1],*(s8 *)((int)param_1 + 3),0x16d);

    if (iVar2 != 0) {

      uVar1 = 1;

    }

    else {

      uVar1 = 0xffffffff;

    }

  }

  return uVar1;

}

// FUN_00402510 NONMATCHING


u32 FUN_00402510(u32 param_1,long param_2,u32 param_3,short param_4)



{

  short sVar1;

  u32 uVar2;

  u32 uVar3;

  

  if (param_2 == -1) {

    param_2 = func_00171250((short)param_1);

  }

  uVar2 = datGetEquipmentId(1,param_4);

  if ((param_1 & 0xffff) == (uVar2 & 0xffff)) {

    if (((param_3 & 8) == 0) && (sVar1 = datGetEquipmentIdx(1,(short)param_2), param_4 == sVar1)) {

      uVar3 = 0;

    }

    else if (((param_3 & 2) == 0) &&

            (uVar2 = func_0016f810(1,param_4), ((int)param_1 >> 0x18 & 0xfU) != (uVar2 & 0xff))) {

      uVar3 = 0;

    }

    else if (((param_3 & 4) == 0) &&

            (uVar2 = datGetEquipmentEffect(1,param_4), ((int)param_1 >> 0x10 & 0xffU) != (uVar2 & 0xff))) {

      uVar3 = 0;

    }

    else if (((param_3 & 1) == 0) ||

            (uVar2 = func_0016f810(1,param_4), (uVar2 & 0xff) <= ((int)param_1 >> 0x18 & 0xfU))) {

      uVar3 = 1;

    }

    else {

      uVar3 = 0;

    }

  }

  else {

    uVar3 = 0;

  }

  return uVar3;

}

// FUN_004026B0 NONMATCHING


u32 FUN_004026b0(int param_1,int param_2,u32 param_3)



{

  int iVar1;

  u32 uVar2;

  long lVar3;

  u8 auStack_20 [9];

  u8 uStack_17;

  

  lVar3 = func_00171250((short)param_1);

  if (lVar3 != 4) {

    iVar1 = func_0016f490(1);

    if (300 - iVar1 < param_2) {

      return 0;

    }

    for (iVar1 = 0; iVar1 < param_2; iVar1 = iVar1 + 1) {

      uVar2 = param_1 >> 0x18 & 0xf;

      if ((param_3 & 2) != 0) {

        uVar2 = 2;

      }

      if ((uVar2 != 0) && ((param_3 & 1) != 0)) {

        RpRandom();

      }

      func_001828d0((short)param_1,auStack_20);

      if ((param_3 & 4) == 0) {

        uStack_17 = (char)((u32)param_1 >> 0x10);

      }

      func_001830c0(auStack_20);

    }

  }

  return 1;

}

// FUN_00402800 NONMATCHING


void FUN_00402800(u64 param_1)



{

  char cVar1;

  u16 uVar2;

  int iVar3;

  int iVar4;

  u64 uVar5;

  u64 uVar6;

  long lVar7;

  u8 auStack_20 [32];

  

  uVar5 = FUN_003c7d60(8);



  cVar1 = *(char *)(iVar3 + 10);

  if (cVar1 == '\x04') {

    sprintf((char *)auStack_20,0x6af3d0);

  }

  else if (cVar1 == '\x03') {

    sprintf((char *)auStack_20,&gp0xffffac10,*(u32 *)(iVar3 + 0xc));

  }

  else if (cVar1 == '\x02') {

    sprintf((char *)auStack_20,&gp0xfffface0,iGpffffb7f4 + *(short *)(iVar3 + 0xc) * 0x11);

  }

  else if (cVar1 == '\x01') {

    sprintf((char *)auStack_20,&gp0xfffface0,

                 iGpffffb7f8 + *(short *)(iVar3 + 0xc) * 0x12 + (int)*(short *)(iVar3 + 0xc));

  }

  else if (cVar1 == '\0') {

    uVar6 = func_00171110(*(u16 *)(iVar3 + 0xc),((long)*(char *)(iVar3 + 0xe) << 0x3c) >> 0x3c

                        );

    sprintf((char *)auStack_20,&gp0xfffface0,uVar6);

  }

  FUN_003a4220(uVar5,0,auStack_20);

  if (*(char *)(iVar3 + 10) == '\0') {

    FUN_003a4010(uVar5,2,*(u16 *)(iVar3 + 0xc),0x11);

    if ((*(u16 *)(iVar3 + 8) & 2) == 0) {

      lVar7 = ((long)*(char *)(iVar3 + 0xe) << 0x3c) >> 0x3c;

    }

    else {

      lVar7 = 2;

    }

    FUN_003a4010(uVar5,3,lVar7,0x11);

  }

  sprintf((char *)auStack_20,&gp0xffffac10,*(u8 *)(iVar3 + 0xb));

  FUN_003a4220(uVar5,1,auStack_20);

  cVar1 = *(char *)(iVar4 + 6);

  if (cVar1 == '\x04') {

    sprintf((char *)auStack_20,0x6af3d0);

  }

  else if (cVar1 == '\x03') {

    sprintf((char *)auStack_20,&gp0xffffac10,*(u32 *)(iVar4 + 8));

  }

  else if (cVar1 == '\x02') {

    sprintf((char *)auStack_20,&gp0xfffface0,iGpffffb7f4 + *(short *)(iVar4 + 8) * 0x11);

  }

  else if (cVar1 == '\x01') {

    sprintf((char *)auStack_20,&gp0xfffface0,

                 iGpffffb7f8 + *(short *)(iVar4 + 8) * 0x12 + (int)*(short *)(iVar4 + 8));

  }

  else if (cVar1 == '\0') {

    uVar6 = func_00171110(*(u16 *)(iVar4 + 8),((long)*(char *)(iVar4 + 10) << 0x3c) >> 0x3c);

    sprintf((char *)auStack_20,&gp0xfffface0,uVar6);

  }

  FUN_003a4220(uVar5,5,auStack_20);

  if (*(char *)(iVar4 + 6) == '\0') {

    FUN_003a4010(uVar5,7,*(u16 *)(iVar4 + 8),0x11);

    FUN_003a4010(uVar5,8,((long)*(char *)(iVar4 + 10) << 0x3c) >> 0x3c,0x11);

  }

  sprintf((char *)auStack_20,&gp0xffffac10,*(u8 *)(iVar4 + 7));

  FUN_003a4220(uVar5,6,auStack_20);


  sprintf((char *)auStack_20,&gp0xffffac10,uVar6);

  FUN_003a4220(uVar5,9,auStack_20);


  sprintf((char *)auStack_20,&gp0xffffac10,uVar2);

  FUN_003a4220(uVar5,10,auStack_20);


  sprintf((char *)auStack_20,&gp0xffffac10,uVar2);

  FUN_003a4220(uVar5,0xb,auStack_20);


  sprintf((char *)auStack_20,&gp0xffffac10,uVar2);

  FUN_003a4220(uVar5,0xc,auStack_20);

  return;

}

// FUN_00402C80 NONMATCHING


void FUN_00402c80(u64 param_1)



{

  char cVar1;

  u16 uVar2;

  int iVar3;

  int iVar4;

  u64 uVar5;

  long lVar6;

  u8 auStack_20 [32];

  



  cVar1 = *(char *)(iVar3 + 10);

  if (cVar1 == '\x04') {

    sprintf((char *)auStack_20,0x6af3d0);

  }

  else if (cVar1 == '\x03') {

    sprintf((char *)auStack_20,&gp0xffffac10,*(u32 *)(iVar3 + 0xc));

  }

  else if (cVar1 == '\x02') {

    sprintf((char *)auStack_20,&gp0xfffface0,iGpffffb7f4 + *(short *)(iVar3 + 0xc) * 0x11);

  }

  else if (cVar1 == '\x01') {

    sprintf((char *)auStack_20,&gp0xfffface0,

                 iGpffffb7f8 + *(short *)(iVar3 + 0xc) * 0x12 + (int)*(short *)(iVar3 + 0xc));

  }

  else if (cVar1 == '\0') {

    uVar5 = func_00171110(*(u16 *)(iVar3 + 0xc),((long)*(char *)(iVar3 + 0xe) << 0x3c) >> 0x3c

                        );

    sprintf((char *)auStack_20,&gp0xfffface0,uVar5);

  }

  FUN_003c7bc0(0,auStack_20);

  if (*(char *)(iVar3 + 10) == '\0') {

    FUN_003c7c20(2,*(u16 *)(iVar3 + 0xc),0x11);

    if ((*(u16 *)(iVar3 + 8) & 2) == 0) {

      lVar6 = ((long)*(char *)(iVar3 + 0xe) << 0x3c) >> 0x3c;

    }

    else {

      lVar6 = 2;

    }

    FUN_003c7c20(3,lVar6,0x11);

  }

  sprintf((char *)auStack_20,&gp0xffffac10,*(u8 *)(iVar3 + 0xb));

  FUN_003c7bc0(1,auStack_20);

  cVar1 = *(char *)(iVar4 + 6);

  if (cVar1 == '\x04') {

    sprintf((char *)auStack_20,0x6af3d0);

  }

  else if (cVar1 == '\x03') {

    sprintf((char *)auStack_20,&gp0xffffac10,*(u32 *)(iVar4 + 8));

  }

  else if (cVar1 == '\x02') {

    sprintf((char *)auStack_20,&gp0xfffface0,iGpffffb7f4 + *(short *)(iVar4 + 8) * 0x11);

  }

  else if (cVar1 == '\x01') {

    sprintf((char *)auStack_20,&gp0xfffface0,

                 iGpffffb7f8 + *(short *)(iVar4 + 8) * 0x12 + (int)*(short *)(iVar4 + 8));

  }

  else if (cVar1 == '\0') {

    uVar5 = func_00171110(*(u16 *)(iVar4 + 8),((long)*(char *)(iVar4 + 10) << 0x3c) >> 0x3c);

    sprintf((char *)auStack_20,&gp0xfffface0,uVar5);

  }

  FUN_003c7bc0(5,auStack_20);

  if (*(char *)(iVar4 + 6) == '\0') {

    FUN_003c7c20(7,*(u16 *)(iVar4 + 8),0x11);

    FUN_003c7c20(8,((long)*(char *)(iVar4 + 10) << 0x3c) >> 0x3c,0x11);

  }

  sprintf((char *)auStack_20,&gp0xffffac10,*(u8 *)(iVar4 + 7));

  FUN_003c7bc0(6,auStack_20);


  sprintf((char *)auStack_20,&gp0xffffac10,uVar5);

  FUN_003c7bc0(9,auStack_20);


  sprintf((char *)auStack_20,&gp0xffffac10,uVar2);

  FUN_003c7bc0(10,auStack_20);


  sprintf((char *)auStack_20,&gp0xffffac10,uVar2);

  FUN_003c7bc0(0xb,auStack_20);


  sprintf((char *)auStack_20,&gp0xffffac10,uVar2);

  FUN_003c7bc0(0xc,auStack_20);

  return;

}

// FUN_004030B0


s16 FUN_004030b0(u16 param_1)



{


  s16 sVar1;



  sVar1 = (s16)param_1;


  FUN_00402c80(sVar1);


  return FUN_004037a0(sVar1);
}

// FUN_004030F0


s16 FUN_004030f0(u16 param_1)



{


  s16 sVar1;



  sVar1 = (s16)param_1;


  FUN_00402c80(sVar1);


  return FUN_004037c0(sVar1);
}

// FUN_00403130 NONMATCHING


void FUN_00403130(u64 param_1,u64 param_2,int param_3,u64 param_4,

                 u64 param_5,u64 param_6,u16 param_7)



{

  u16 uVar1;

  

  datSetFlag(0x1424,1);


  datSetFlag(0x1424,0);


  FUN_003c7e20((float)param_3,param_1,param_2,param_4,param_5,param_6,6,uVar1);

  return;

}

// FUN_00403220 NONMATCHING


void FUN_00403220(u64 param_1,u64 param_2,int param_3,u64 param_4,

                 u64 param_5,u64 param_6,u16 param_7)



{

  u16 uVar1;

  



  FUN_003c7e20((float)param_3,param_1,param_2,param_4,param_5,param_6,6,uVar1);

  return;

}

// FUN_004032F0


void FUN_004032f0(u64 param_1)
{
  FUN_00404470_alt(param_1,1);
  FUN_0017c4e0(param_1);
}

// FUN_00403340


void FUN_00403340(u16 param_1)
{
  FUN_0017c590();
  FUN_00404470_alt(param_1,0);
}

// FUN_00403380


u8 FUN_00403380(u64 param_1)
{
  if (datGetFlag_s32((s16)param_1 + 0x1170) != 0) {
    return 3;
  }
  if (FUN_003f04f0_u32(FUN_004037e0_u64(param_1),0) != 0) {
    return FUN_0017c610_u64(param_1) != 0;
  }
  return 2;
}

// FUN_00403410 NONMATCHING


u8 FUN_00403410(void)



{

  u8 uVar1;

  short sVar2;

  int iVar3;

  int iVar4;

  long lVar5;

  long unaff_s1;

  long unaff_s2;

  


  lVar5 = ((long)*(char *)(iVar3 + 7) << 0x38) >> 0x3c;

  if (lVar5 == 2) {

    sVar2 = datGetDaysSinceApr5();

    unaff_s2 = (long)sVar2;

    iVar4 = clndGetDaysSinceStartFromDate(((long)*(short *)(iVar3 + 4) << 0x34) >> 0x3a,

                         ((long)*(char *)(iVar3 + 4) << 0x3a) >> 0x3a);

    unaff_s1 = (long)((int)(((long)*(short *)(iVar3 + 6) << 0x34) >> 0x34) + iVar4);

  }

  else if (lVar5 == 1) {

    sVar2 = datGetDaysSinceApr5();

    unaff_s2 = (long)sVar2;

    unaff_s1 = clndGetDaysSinceStartFromDate(((long)*(short *)(iVar3 + 6) << 0x34) >> 0x3a,

                            ((long)*(char *)(iVar3 + 6) << 0x3a) >> 0x3a);

  }

  else if (lVar5 == 0) {

    return 3;

  }

  if (unaff_s2 == unaff_s1) {

    uVar1 = 2;

  }

  else {

    uVar1 = unaff_s2 < unaff_s1;

  }

  return uVar1;

}

// FUN_00403520 NONMATCHING


u32 FUN_00403520(void)



{

  short sVar1;

  long lVar2;

  u64 uVar3;

  int iVar4;

  int iVar5;

  

  iVar5 = 0;

  do {

    if (2 < iVar5) {

      return 0;

    }

    lVar2 = FUN_0017c670(iVar5);

    if (lVar2 != 0) {

      sVar1 = *(short *)lVar2;

      lVar2 = datGetFlag(sVar1 + 0x1170);

      if (lVar2 == 0) {



        if (lVar2 == 0) {

          iVar4 = 2;

        }

        else {

          lVar2 = FUN_0017c610(sVar1);

          if (lVar2 == 0) {

            iVar4 = 0;

          }

          else {

            iVar4 = 1;

          }

        }

      }

      else {

        iVar4 = 3;

      }

      if (iVar4 == 2) {

        return 1;

      }

    }

    iVar5 = iVar5 + 1;

  } while( 1 );

}

// FUN_00403610 NONMATCHING


int FUN_00403610(void)



{

  short sVar1;

  long lVar2;

  long lVar3;

  u64 uVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  

  iVar7 = 0;

  iVar6 = 0;

LAB_0040370c:

  do {

    if (2 < iVar7) {

      return iVar6;

    }

    lVar2 = FUN_0017c670(iVar7);

    if (lVar2 != 0) {

      sVar1 = *(short *)lVar2;

      lVar3 = datGetFlag(sVar1 + 0x1170);

      if (lVar3 == 0) {



        if (lVar3 == 0) {

          iVar5 = 2;

        }

        else {

          lVar3 = FUN_0017c610(sVar1);

          if (lVar3 == 0) {

            iVar5 = 0;

          }

          else {

            iVar5 = 1;

          }

        }

      }

      else {

        iVar5 = 3;

      }

      if (iVar5 == 2) {

        sVar1 = *(short *)lVar2;

        FUN_0017c590(sVar1);


        iVar6 = iVar6 + 1;

        iVar7 = 0;

        goto LAB_0040370c;

      }

    }

    iVar7 = iVar7 + 1;

  } while( 1 );

}

// FUN_00403740


s16 FUN_00403740(short param_1)
{
  __asm__ volatile (
      ".set noreorder;"
      ".word 0x8f83ac00;"
      ".word 0x0004143c;"
      ".word 0x0002143f;"
      ".word 0x00021180;"
      ".word 0x00431021;"
      ".word 0x8442003a;"
      ".set reorder"
  );
}

// FUN_00403760


s16 FUN_00403760(short param_1)
{
  __asm__ volatile (
      ".set noreorder;"
      ".word 0x8f83ac00;"
      ".word 0x0004143c;"
      ".word 0x0002143f;"
      ".word 0x00021180;"
      ".word 0x00431021;"
      ".word 0x84420030;"
  );
}

// FUN_00403780


s16 FUN_00403780(short param_1)
{
  __asm__ volatile (
      ".set noreorder;"
      ".word 0x8f83ac00;"
      ".word 0x0004143c;"
      ".word 0x0002143f;"
      ".word 0x00021180;"
      ".word 0x00431021;"
      ".word 0x84420032;"
      ".set reorder"
  );
}

// FUN_004037A0


s16 FUN_004037a0(short param_1)
{
  __asm__ volatile (
      ".set noreorder;"
      ".word 0x8f83ac00;"
      ".word 0x0004143c;"
      ".word 0x0002143f;"
      ".word 0x00021180;"
      ".word 0x00431021;"
      ".word 0x84420036;"
      ".set reorder"
  );
}

// FUN_004037C0


s16 FUN_004037c0(short param_1)
{
  __asm__ volatile (
      ".set noreorder;"
      ".word 0x8f83ac00;"
      ".word 0x0004143c;"
      ".word 0x0002143f;"
      ".word 0x00021180;"
      ".word 0x00431021;"
      ".word 0x84420034;"
      ".set reorder"
  );
}

// FUN_004037E0


int FUN_004037e0(short param_1)



{

  return iGpffffac00 + param_1 * 0x40 + 8;

}

// FUN_00403800


long FUN_00403800(short param_1)



{

  return ((long)*(short *)(iGpffffac00 + param_1 * 0x40 + 0xe) << 0x34) >> 0x3a;

}

// FUN_00403830


long FUN_00403830(short param_1)



{

  return ((long)*(char *)(iGpffffac00 + param_1 * 0x40 + 0xe) << 0x3a) >> 0x3a;

}

// FUN_00403860


int FUN_00403860(short param_1)



{

  return iGpffffac00 + param_1 * 0x40 + 0x10;

}

// FUN_00403880


int FUN_00403880(short param_1)



{

  return iGpffffac00 + param_1 * 0x40 + 0x20;

}

// FUN_004038A0


u32 FUN_004038a0(short param_1)
{
  u8 *base = (u8 *)(iGpffffac00 + param_1 * 0x40);
  u32 *ptr = (u32 *)(base + 0x20);
  if (base[0x26] == 3) {
    return ptr[2];
  }
  return 0;
}

// FUN_004038E0


u32 FUN_004038e0(short param_1)
{
  __asm__ volatile (
      ".set noreorder;"
      ".word 0x8f83ac00;"
      ".word 0x0004143c;"
      ".word 0x0002143f;"
      ".word 0x00021180;"
      ".word 0x00431021;"
      ".word 0x8c42002c;"
      ".set reorder"
  );
}

// FUN_00403900


s16 FUN_00403900(short param_1)
{
  __asm__ volatile (
      ".set noreorder;"
      ".word 0x8f83ac00;"
      ".word 0x0004143c;"
      ".word 0x0002143f;"
      ".word 0x00021180;"
      ".word 0x00431021;"
      ".word 0x8442003c;"
      ".set reorder"
  );
}

// FUN_00403920


u32 FUN_00403920(short param_1,short param_2)
{
  u8 *base = (u8 *)(iGpffffac00 + param_1 * 0x40);
  s16 *ptr = (s16 *)(base + 0x10);
  if (base[0x1a] != 1) {
    goto no_match;
  }
  if (ptr[6] != param_2) {
    goto no_match;
  }
  return 1;
no_match:
  return 0;
}

// FUN_00403970 NONMATCHING


u32 FUN_00403970(short param_1)



{

  char cVar1;

  u8 bVar2;

  short sVar3;

  u8 bVar4;

  u16 uVar5;

  int iVar6;

  u32 uVar7;

  long lVar8;

  long lVar9;

  u8 bVar10;

  int iVar11;

  long lVar12;

  

  iVar6 = iGpffffac00 + param_1 * 0x40;

  cVar1 = *(char *)(iVar6 + 0x1a);

  if (cVar1 == '\x04') {

    lVar8 = datGetFlag(*(u32 *)(iVar6 + 0x1c));

    if (lVar8 != 0) {

      return 1;

    }

    return 0;

  }

  if (cVar1 == '\x03') {

    uVar7 = datGetMoney();

    if (*(u32 *)(iVar6 + 0x1c) <= uVar7) {

      return 1;

    }

    return 0;

  }

  if (cVar1 == '\x02') {

    if ((*(u32 *)(iVar6 + 0x10) & 2) != 0) {

      if (*(short *)(iVar6 + 0x1c) == 0) {

        K_Assert((const char *)(u32)0x6aede8,0x1db3);

      }

      lVar8 = datGetPersonaByCompendium(*(u16 *)(iVar6 + 0x1c));

      if (lVar8 != 0) {

        if (((*(u16 *)(iVar6 + 0x18) & 8) == 0) ||

           (*(short *)(iVar6 + 0x1e) <= (short)(u16)*(u8 *)((int)lVar8 + 4))) {

          if (((*(u16 *)(iVar6 + 0x18) & 0x10) == 0) ||

             (lVar8 = datPersonaFindSkillIdx(lVar8,*(u16 *)(iVar6 + 0x1e)), lVar8 != -1)) {

            bVar4 = 1;

          }

          else {

            bVar4 = 0;

          }

        }

        else {

          bVar4 = 0;

        }

        if (bVar4) {

          return 1;

        }

        return 0;

      }

      return 0;

    }

    if (*(short *)(iVar6 + 0x1c) != 0) {

      lVar8 = FUN_001749a0(*(short *)(iVar6 + 0x1c));

      if (lVar8 == 0) {

        return 0;

      }

      if (((*(u16 *)(iVar6 + 0x18) & 8) == 0) ||

         (*(short *)(iVar6 + 0x1e) <= (short)(u16)*(u8 *)((int)lVar8 + 4))) {

        if (((*(u16 *)(iVar6 + 0x18) & 0x10) == 0) ||

           (lVar8 = datPersonaFindSkillIdx(lVar8,*(u16 *)(iVar6 + 0x1e)), lVar8 != -1)) {

          bVar4 = 1;

        }

        else {

          bVar4 = 0;

        }

      }

      else {

        bVar4 = 0;

      }

      if (bVar4) {

        return 1;

      }

      return 0;

    }

    iVar11 = 0;

    do {

      uVar7 = FUN_00175410();

      if ((int)(uVar7 & 0xffff) <= iVar11) {

        bVar4 = 0;

LAB_00403d20:

        if (bVar4) {

          return 1;

        }

        return 0;

      }

      lVar8 = datPersonaGetHeroPersona((short)iVar11);

      if (lVar8 != 0) {

        if (((*(u16 *)(iVar6 + 0x18) & 8) == 0) ||

           (*(short *)(iVar6 + 0x1e) <= (short)(u16)*(u8 *)((int)lVar8 + 4))) {

          if (((*(u16 *)(iVar6 + 0x18) & 0x10) == 0) ||

             (lVar8 = datPersonaFindSkillIdx(lVar8,*(u16 *)(iVar6 + 0x1e)), lVar8 != -1)) {

            bVar4 = 1;

          }

          else {

            bVar4 = 0;

          }

        }

        else {

          bVar4 = 0;

        }

        if (bVar4) {

          bVar4 = 1;

          goto LAB_00403d20;

        }

      }

      iVar11 = iVar11 + 1;

    } while( 1 );

  }

  if (cVar1 == '\x01') {

    lVar8 = FUN_0017c610();

    if (lVar8 == 0) {

      return 0;

    }

    if ((short)(u16)*(u8 *)(iVar6 + 0x1b) <= *(short *)((int)lVar8 + 2)) {

      return 1;

    }

    return 0;

  }

  if (cVar1 != '\0') {

    return 1;

  }

  uVar5 = *(u16 *)(iVar6 + 0x18);

  bVar10 = (uVar5 & 1) != 0;

  if ((uVar5 & 2) != 0) {

    bVar10 = bVar10 | 2;

  }

  if ((uVar5 & 4) != 0) {

    bVar10 = bVar10 | 4;

  }

  cVar1 = *(char *)(iVar6 + 0x1e);

  sVar3 = *(short *)(iVar6 + 0x1e);

  uVar5 = *(u16 *)(iVar6 + 0x1c);

  bVar2 = *(u8 *)(iVar6 + 0x1b);

  lVar8 = func_00171250(uVar5);

  if (lVar8 == 4) {

    uVar5 = func_00170760(1,uVar5);

    if (bVar2 <= uVar5) {

      bVar4 = 1;

      goto LAB_00403b38;

    }

  }

  else {

    lVar12 = 0;

    for (iVar6 = 0; iVar6 < 300; iVar6 = iVar6 + 1) {

      lVar9 = FUN_00402510((u32)uVar5 |

                           ((u32)(((long)cVar1 << 0x3c) >> 0x3c) & 0xf) << 0x18 |

                           (u32)(u8)((u32)((long)sVar3 << 0x34) >> 0x38) << 0x10,lVar8,

                           bVar10 | 8,iVar6);

      if ((lVar9 != 0) && (lVar12 = (long)((int)lVar12 + 1), (short)(u16)bVar2 <= lVar12)) {

        bVar4 = 1;

        goto LAB_00403b38;

      }

    }

  }

  bVar4 = 0;

LAB_00403b38:

  if (bVar4) {

    return 1;

  }

  return 0;

}

// FUN_00403E40 NONMATCHING


u32 FUN_00403e40(int param_1,int param_2)



{

  u8 bVar1;

  long lVar2;

  int iVar3;

  int iVar4;

  

  iVar4 = 0;

  do {

    if (2 < iVar4) {

      return 0;

    }

    lVar2 = FUN_0017c670(iVar4);

    if (lVar2 != 0) {

      for (iVar3 = 0; iVar3 < param_2; iVar3 = iVar3 + 1) {

        if (*(short *)lVar2 == *(short *)(param_1 + iVar3 * 2)) {

          bVar1 = 1;

          goto LAB_00403ec0;

        }

      }

      bVar1 = 0;

LAB_00403ec0:

      if ((!bVar1) && (lVar2 = FUN_00403970(0), lVar2 != 0)) {

        return 1;

      }

    }

    iVar4 = iVar4 + 1;

  } while( 1 );

}

// FUN_00403F20 NONMATCHING


u32 FUN_00403f20(short param_1,long param_2)



{

  char cVar1;

  u16 uVar2;

  int iVar3;

  int iVar4;

  long lVar5;

  u8 bVar6;

  

  iVar3 = iGpffffac00 + param_1 * 0x40;

  cVar1 = *(char *)(iVar3 + 0x26);

  if (cVar1 == '\x03') {

    if (param_2 == 0) {

      lVar5 = func_0016ea40(*(u32 *)(iVar3 + 0x28));

      if (0 < lVar5) {

        return 2;

      }

    }

    else {

      datAddMoney(*(u32 *)(iVar3 + 0x28));

    }

  }

  else if (cVar1 == '\x02') {

    lVar5 = FUN_00174e70(*(u16 *)(iVar3 + 0x28));

    if (lVar5 == 0) {

      return 3;

    }

  }

  else if (cVar1 == '\0') {

    lVar5 = func_00171250(*(u16 *)(iVar3 + 0x28));

    if (lVar5 == 4) {

      if (param_2 != 0) {

        lVar5 = dat00171360(*(u16 *)(iVar3 + 0x28));

        if (lVar5 == 0) {

          func_00170c00(1,*(u16 *)(iVar3 + 0x28),*(u8 *)(iVar3 + 0x27));

        }

        else {

          func_00171390(*(u16 *)(iVar3 + 0x28));

        }

      }

    }

    else if (param_2 == 0) {

      iVar4 = func_0016f490(1);

      if (300 - iVar4 < (int)(u32)*(u8 *)(iVar3 + 0x27)) {

        return 1;

      }

    }

    else {

      uVar2 = *(u16 *)(iVar3 + 0x24);

      bVar6 = (uVar2 & 1) != 0;

      if ((uVar2 & 2) != 0) {

        bVar6 = bVar6 | 2;

      }

      if ((uVar2 & 4) != 0) {

        bVar6 = bVar6 | 4;

      }

      lVar5 = FUN_004026b0((u32)*(u16 *)(iVar3 + 0x28) |

                           ((u32)(((long)*(char *)(iVar3 + 0x2a) << 0x3c) >> 0x3c) & 0xf) << 0x18 |

                           (u32)(u8)((u32)((long)*(short *)(iVar3 + 0x2a) << 0x34) >> 0x38) <<

                           0x10,*(u8 *)(iVar3 + 0x27),bVar6);

      if (lVar5 == 0) {

        return 1;

      }

    }

  }

  return 0;

}

// FUN_00404120 NONMATCHING


u32 FUN_00404120(short param_1,long param_2)



{

  char cVar1;

  short sVar2;

  u16 uVar3;

  u8 *puVar4;

  short sVar5;

  u32 uVar6;

  long lVar7;

  long lVar8;

  u32 uVar9;

  u8 bVar10;

  int iVar11;

  int iVar12;

  long lVar13;

  

  puVar4 = (u8 *)(PTR_DAT_007cd8f0);

  if ((*(u32 *)(PTR_DAT_007cd8f0 + param_1 * 0x40 + 0x10) & 1) != 0) {

    cVar1 = PTR_DAT_007cd8f0[param_1 * 0x40 + 0x1a];

    if (cVar1 == '\x03') {

      uVar6 = datGetMoney();

      if (uVar6 < *(u32 *)(puVar4 + param_1 * 0x40 + 0x1c)) {

        K_Assert((const char *)(u32)0x6aede8,0x1e72);

      }

      if (param_2 == 0) {

        return 1;

      }

      datAddMoney(-*(int *)(puVar4 + param_1 * 0x40 + 0x1c));

    }

    else if (cVar1 == '\x02') {

      sVar2 = *(short *)(PTR_DAT_007cd8f0 + param_1 * 0x40 + 0x1c);

      uVar9 = FUN_001752b0();

      if ((long)sVar2 == (uVar9 & 0xffff)) {

        K_Assert((const char *)(u32)0x6aede8,0x1e6d);

      }

      if (param_2 == 0) {

        return 1;

      }

      FUN_00174b40(*(u16 *)(puVar4 + param_1 * 0x40 + 0x1c));

    }

    else {

      if (cVar1 == '\x01') {

        return 1;

      }

      if (cVar1 == '\0') {

        lVar7 = func_00171250(*(u16 *)(PTR_DAT_007cd8f0 + param_1 * 0x40 + 0x1c));

        if (lVar7 == 4) {

          if (param_2 == 0) {

            return 1;

          }

          func_00170c00(1,*(u16 *)(puVar4 + param_1 * 0x40 + 0x1c),

                       -(u16)(u8)puVar4[param_1 * 0x40 + 0x1b]);

        }

        else {

          iVar11 = 0;

          uVar3 = *(u16 *)(puVar4 + param_1 * 0x40 + 0x18);

          bVar10 = (uVar3 & 1) != 0;

          if ((uVar3 & 2) != 0) {

            bVar10 = bVar10 | 2;

          }

          if ((uVar3 & 4) != 0) {

            bVar10 = bVar10 | 4;

          }

          cVar1 = puVar4[param_1 * 0x40 + 0x1e];

          sVar2 = *(short *)(puVar4 + param_1 * 0x40 + 0x1e);

          uVar3 = *(u16 *)(puVar4 + param_1 * 0x40 + 0x1c);

          for (lVar13 = 0; lVar13 < 300; lVar13 = (long)((int)lVar13 + 1)) {

            lVar8 = FUN_00402510((u32)uVar3 |

                                 ((u32)(((long)cVar1 << 0x3c) >> 0x3c) & 0xf) << 0x18 |

                                 (u32)(u8)((u32)((long)sVar2 << 0x34) >> 0x38) << 0x10,lVar7,

                                 bVar10 | 8,lVar13);

            if (lVar8 != 0) {

              for (iVar12 = 0; iVar12 < 4; iVar12 = iVar12 + 1) {

                sVar5 = datGetEquipmentIdx(1,(short)iVar12);

                if (lVar13 == sVar5) {

                  return 0;

                }

              }

              if (param_2 == 0) {

                return 1;

              }

              func_0016fea0(1,lVar13,0);

              iVar11 = iVar11 + 1;

              if ((int)(u32)(u8)puVar4[param_1 * 0x40 + 0x1b] <= iVar11) {

                return 1;

              }

            }

          }

          K_Assert((const char *)(u32)0x6aede8,0x1e65);

        }

      }

    }

  }

  return 1;

}

// FUN_00404470


void FUN_00404470(short param_1)
{
  u16 *ptr = (u16 *)(iGpffffac00 + param_1 * 0x40 + 0x14);
  if (*ptr != (u16)-1) {
    datSetFlag(*ptr);
  }
}

// FUN_004044C0 NONMATCHING


void FUN_004044c0(short param_1)



{

  u16 uVar1;

  long lVar2;

  u64 uVar3;

  short *psVar4;

  

  lVar2 = FUN_0017c610();

  if (lVar2 == 0) {

    K_Assert((const char *)(u32)0x6aede8,0x1e90);

  }

  psVar4 = (short *)lVar2;


  datSetFlag(*psVar4 + 0x1170,1);

  if (*(short *)(PTR_DAT_007cd8f0 + param_1 * 0x40 + 0x14) != -1) {

    datSetFlag(*(short *)(PTR_DAT_007cd8f0 + param_1 * 0x40 + 0x14),0);

  }

  if (*(short *)(PTR_DAT_007cd8f0 + *psVar4 * 0x40 + 0x16) != -1) {

    datSetFlag(*(short *)(PTR_DAT_007cd8f0 + *psVar4 * 0x40 + 0x16),1);

  }

  FUN_0017c590(*psVar4);

  uVar1 = *(u16 *)(PTR_DAT_007cd8f0 + *psVar4 * 0x40 + 0x38);

  uVar3 = FUN_003e6dc0();


  return;

}

// FUN_004045D0 NONMATCHING


void FUN_004045d0(u64 param_1)



{

  u8 bVar1;

  int iVar2;

  u32 uVar3;

  long lVar4;

  u64 uVar5;

  int iVar6;

  int iVar7;

  u8 *puVar8;

  

  iVar2 = DAT_007cd8f4;

  iVar7 = 0;

  puVar8 = (u8 *)(PTR_DAT_007cd8f0);

  do {

    if (iVar2 <= iVar7) {

      return;

    }

    if (((iVar7 != 0x37) || (lVar4 = FUN_0017d7b0(), lVar4 != 0)) &&

       (*(short *)(PTR_DAT_007cd8f0 + (short)iVar7 * 0x40 + 0x3a) != 0)) {

      for (iVar6 = 0; iVar6 < 2; iVar6 = iVar6 + 1) {

        if ((*(short *)(puVar8 + iVar6 * 2 + 4) != -1) && (lVar4 = datGetFlag(), lVar4 == 0)) {

          bVar1 = 0;

          goto LAB_004046bc;

        }

      }


      if (lVar4 == 0) {

        bVar1 = 0;

      }

      else {

        bVar1 = 1;

      }

LAB_004046bc:

      if (bVar1) {

        uVar5 = FUN_003c5a40(param_1,*(u16 *)((int)param_1 + 0x10) + 1,0xc,0);

        iVar6 = *(int *)(*(int *)((int)uVar5 + 0x14) + 0x1c);

        *(short *)(iVar6 + 4) = (short)iVar7;

        uVar3 = FUN_003dfeb0(0);

        *(u32 *)(iVar6 + 8) = uVar3;


      }

    }

    puVar8 = puVar8 + 0x40;

    iVar7 = iVar7 + 1;

  } while( 1 );

}

// FUN_00404750
void FUN_00404750(u32 param_1,u32 param_2,u32 param_3)
{
  FclShopDispatchStack stack;
  u8 *obj;
  u8 *table;
  u8 *owner;
  u8 *item;
  u8 *owner_alt0;
  u8 *item_alt0;
  u8 *item_primary0;
  u8 *owner_primary0;
  u8 *owner_single;

  obj = (u8 *)param_1;
  table = *(u8 **)(*(u8 **)(obj + 0x24) + 0x44);
  switch (param_2) {
  case 0:
    if (param_3 == 0) {
      item_primary0 = *(u8 **)(obj + 4);
      while (item_primary0 != 0) {
        owner_primary0 = *(u8 **)(*(u8 **)(*(u8 **)(item_primary0 + 0x14) + 0x1c) + 8);
        FCL_SHOP_DISPATCH_BUILD(stack.source[7].primary, &stack.output[15].result, owner_primary0, 0, 0);
        item_primary0 = *(u8 **)(item_primary0 + 0x10);
      }
    }
    else if (param_3 == 1) {
      item_alt0 = *(u8 **)(obj + 4);
      while (item_alt0 != 0) {
        owner_alt0 = *(u8 **)(*(u8 **)(*(u8 **)(item_alt0 + 0x14) + 0x1c) + 8);
        FCL_SHOP_DISPATCH_BUILD(stack.source[7].alternate, &stack.output[14].result, owner_alt0, 0, 1);
        item_alt0 = *(u8 **)(item_alt0 + 0x10);
      }
    }
    break;
  case 1:
    if (param_3 == 0) {
      item = *(u8 **)(obj + 4);
      while (item != 0) {
        owner = *(u8 **)(*(u8 **)(*(u8 **)(item + 0x14) + 0x1c) + 8);
        FCL_SHOP_DISPATCH_BUILD(stack.source[6].primary, &stack.output[13].result, owner, 0, 0);
        item = *(u8 **)(item + 0x10);
      }
    }
    else if (param_3 == 1) {
      item = *(u8 **)(obj + 0xc);
      if (item != 0) {
        owner_single = *(u8 **)(*(u8 **)(*(u8 **)(item + 0x14) + 0x1c) + 8);
        FCL_SHOP_DISPATCH_BUILD(stack.source[6].alternate, &stack.output[12].result, owner_single, 1, 3);
      }
    }
    break;
  case 2:
    if (param_3 == 0) {
      owner_single = *(u8 **)(table + 8);
      FCL_SHOP_DISPATCH_BUILD(stack.source[5].primary, &stack.output[11].result, owner_single, 2, 4);
    }
    else if (param_3 == 1) {
      owner_single = *(u8 **)(table + 8);
      FCL_SHOP_DISPATCH_BUILD(stack.source[5].alternate, &stack.output[10].result, owner_single, 2, 5);
    }
    break;
  case 3:
    if (param_3 == 0) {
      owner_single = *(u8 **)(table + 8);
      FCL_SHOP_DISPATCH_BUILD(stack.source[4].primary, &stack.output[9].result, owner_single, 3, 6);
    }
    else if (param_3 == 1) {
      owner_single = *(u8 **)(table + 8);
      FCL_SHOP_DISPATCH_BUILD(stack.source[4].alternate, &stack.output[8].result, owner_single, 3, 7);
    }
    break;
  case 4:
    if (param_3 == 0) {
      owner_single = *(u8 **)(table + 8);
      FCL_SHOP_DISPATCH_BUILD(stack.source[3].primary, &stack.output[7].result, owner_single, 4, 8);
    }
    else if (param_3 == 1) {
      owner_single = *(u8 **)(table + 8);
      FCL_SHOP_DISPATCH_BUILD(stack.source[3].alternate, &stack.output[6].result, owner_single, 4, 9);
    }
    break;
  case 5:
    if (param_3 == 0) {
      owner_single = *(u8 **)(table + 8);
      FCL_SHOP_DISPATCH_BUILD(stack.source[2].primary, &stack.output[5].result, owner_single, 5, 10);
    }
    else if (param_3 == 1) {
      owner_single = *(u8 **)(table + 8);
      FCL_SHOP_DISPATCH_BUILD(stack.source[2].alternate, &stack.output[4].result, owner_single, 5, 11);
    }
    break;
  case 6:
    if (param_3 == 0) {
      owner_single = *(u8 **)(table + 8);
      FCL_SHOP_DISPATCH_BUILD(stack.source[1].primary, &stack.output[3].result, owner_single, 6, 12);
    }
    else if (param_3 == 1) {
      owner_single = *(u8 **)(table + 8);
      FCL_SHOP_DISPATCH_BUILD(stack.source[1].alternate, &stack.output[2].result, owner_single, 6, 13);
    }
    break;
  case 7:
    if (param_3 == 0) {
      owner_single = *(u8 **)(table + 8);
      FCL_SHOP_DISPATCH_BUILD(stack.source[0].primary, &stack.output[1].result, owner_single, 7, 14);
    }
    else if (param_3 == 1) {
      owner_single = *(u8 **)(table + 8);
      FCL_SHOP_DISPATCH_BUILD(stack.source[0].alternate, &stack.output[0].result, owner_single, 7, 15);
    }
    break;
  default:
    break;
  }
}

// FUN_00405970 NONMATCHING


u64 FUN_00405970(u64 param_1,int param_2)



{

  u32 *puVar1;

  long lVar2;

  short sVar3;

  

  puVar1 = *(u32 **)(*(int *)(param_2 + 0x14) + 0x1c);

  sVar3 = (short)puVar1[1];

  lVar2 = datGetFlag(sVar3 + 0x1170);

  if (lVar2 == 0) {


    if (lVar2 == 0) {

      sVar3 = 2;

    }

    else {

      lVar2 = FUN_0017c610(sVar3);

      if (lVar2 == 0) {

        sVar3 = 0;

      }

      else {

        sVar3 = 1;

      }

    }

  }

  else {

    sVar3 = 3;

  }

  if ((((sVar3 == 4) || (sVar3 == 2)) || (sVar3 == 1)) || (sVar3 == 3)) {

    *puVar1 = *puVar1 | 0x10;

    *(short *)((int)puVar1 + 6) = sVar3;

  }

  else {

    lVar2 = datGetFlag((short)puVar1[1] + 0x10ff);

    if (lVar2 == 0) {

      *puVar1 = *puVar1 | 0x100;

    }

  }

  return 0;

}

// FUN_00405A90


void FUN_00405a90(u64 param_1,int param_2)



{

  FUN_003dff00(*(u32 *)(*(int *)(*(int *)(param_2 + 0x14) + 0x1c) + 8));

  return;

}

// FUN_00405AC0 NONMATCHING


u64 FUN_00405ac0(u64 param_1,long param_2)



{

  u32 *puVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  u16 *puVar5;

  int iVar6;

  u32 uVar7;

  u32 uVar8;

  u64 uVar9;

  long lVar10;

  int iVar11;

  

  uVar9 = FUN_003c58f0(0,0xc,5,0x1c);

  iVar3 = (int)uVar9;

  puVar1 = *(u32 **)(*(int *)(iVar3 + 0x24) + 0x44);

  if (param_2 == 0) {
    FUN_004045d0(uVar9);
  }
  else {

    iVar4 = FUN_0017c700();

    for (iVar11 = 0; iVar11 < iVar4; iVar11 = iVar11 + 1) {

      puVar5 = (u16 *)FUN_0017c670(iVar11);

      iVar6 = FUN_003c5a40(uVar9,*(u16 *)(iVar3 + 0x10) + 1,0xc,0);

      iVar2 = *(int *)(*(int *)(iVar6 + 0x14) + 0x1c);

      *(u16 *)(iVar2 + 4) = *puVar5;

      uVar7 = FUN_003dfeb0(0);

      *(u32 *)(iVar2 + 8) = uVar7;

      iVar2 = *(int *)(*(int *)(iVar6 + 0x14) + 0x1c);
      lVar10 = FUN_00403380(*(short *)(iVar2 + 4));
      if ((((lVar10 == 4) || (lVar10 == 2)) || (lVar10 == 1)) || (lVar10 == 3)) {
        *(short *)(iVar2 + 6) = (short)lVar10;

      }

    }

    *puVar1 = *puVar1 | 2;

  }


  FUN_00405e00(uVar9);
  uVar8 = FUN_003dfeb0(0);
  puVar1[2] = uVar8;
  FUN_003c6ee0(uVar9);
  FUN_003c5f40(uVar9,0x405a90);
  FUN_003c5e20(uVar9,0x407180);
  FUN_003c5ee0(uVar9,0x407210);
  FUN_003c6d40(uVar9,0,0);
  *(u16 *)(*(int *)(iVar3 + 0x24) + 6) = 10;
  *(u16 *)(*(int *)(iVar3 + 0x24) + 8) = 10;
  FUN_00404750(uVar9,6,0);
  FUN_00404750(uVar9,1,0);
  FUN_00404750(uVar9,0,0);
  FUN_00404750(uVar9,2,0);
  FUN_00404750(uVar9,5,0);
  FUN_00404750(uVar9,4,0);
  FUN_00404750(uVar9,3,0);
  FUN_00404750(uVar9,7,0);









  return uVar9;

}

// FUN_00405D60


void FUN_00405d60(int param_1)



{

  FUN_003dff00(*(u32 *)(*(int *)(*(int *)((int)param_1 + 0x24) + 0x44) + 8));

  FUN_003c5a20(param_1);

  return;

}

// FUN_00405DB0
int FUN_00405db0(u32* param_1, u32* param_2)
{
  s16* base;
  s16 a;
  s16 b;

  base = (s16*)((u8*)iGpffffac00 + 0x3a);
  a = base[*(s16*)(*(u32*)(*(u32*)(*param_1 + 0x14) + 0x1c) + 4) * 0x20];
  asm volatile("" : "+m"(a));
  b = base[*(s16*)(*(u32*)(*(u32*)(*param_2 + 0x14) + 0x1c) + 4) * 0x20];
  return b - a;
}

// FUN_00405E00


void FUN_00405e00(u64 param_1)



{
  FUN_003c7000(param_1,FUN_00405db0,0);

  return;

}

// FUN_00405E30 NONMATCHING


u8 FUN_00405e30(u64 param_1)



{

  long lVar1;

  long lVar2;

  int iVar3;

  int iVar4;

  

  iVar3 = (int)param_1;

  FUN_003e0650(*(u32 *)(*(int *)(*(int *)(iVar3 + 0x24) + 0x44) + 8));

  for (iVar4 = *(int *)(iVar3 + 4); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x10)) {

    FUN_003e0650(*(u32 *)(*(int *)(*(int *)(iVar4 + 0x14) + 0x1c) + 8));

  }

  lVar1 = FUN_003c6270(param_1);

  lVar2 = FUN_003c6ce0(param_1);

  if ((lVar2 != 0) || (lVar2 = FUN_003c6d10(param_1), lVar2 != 0)) {

    func_0010a4e0(0,0,0,0);

  }

  lVar2 = FUN_003c6ca0(param_1);

  if ((lVar2 != 0) || (lVar2 = FUN_003c6cc0(param_1), lVar2 != 0)) {

    func_0010a4e0(0,0,0,5);

  }


  if (*(int *)(iVar3 + 0xc) != 0) {

    datSetFlag(*(short *)(*(int *)(*(int *)(*(int *)(iVar3 + 0xc) + 0x14) + 0x1c) + 4) + 0x10ff,1)

    ;

  }

  return lVar1 == 3;

}

// FUN_00405F70 NONMATCHING


void FUN_00405f70(u64 param_1,u64 param_2,u32 param_3,int param_4,u64 param_5,

                 int param_6,int param_7)



{

  short sVar1;

  int *piVar2;

  u32 uVar3;

  u8 *puVar4;

  short sVar5;

  int iVar6;

  long lVar7;

  int iVar8;

  u32 *puVar9;

  u32 *puVar10;

  int iVar11;

  int iVar12;

  int iVar13;

  long unaff_s7;

  long unaff_s8;

  float fVar14;

  u32 uVar15;

  u32 auStack_20050 [8];

  u32 auStack_20030 [32748];

  u32 auStack_50 [8];

  u32 auStack_30 [10];

  u8 auStack_8 [8];

  

  piVar2 = *(int **)(param_4 + 0x34);

  puVar10 = &DAT_006af5e0;

  puVar9 = auStack_30;

  iVar8 = 4;

  do {

    uVar15 = *puVar10;

    uVar3 = puVar10[1];

    puVar10 = puVar10 + 2;

    iVar8 = iVar8 + -1;

    *puVar9 = uVar15;

    puVar9[1] = uVar3;

    puVar9 = puVar9 + 2;

  } while (0 < iVar8);

  puVar10 = &DAT_006af600;

  puVar9 = auStack_50;

  iVar8 = 4;

  do {

    uVar15 = *puVar10;

    uVar3 = puVar10[1];

    puVar10 = puVar10 + 2;

    iVar8 = iVar8 + -1;

    *puVar9 = uVar15;

    puVar9[1] = uVar3;

    puVar9 = puVar9 + 2;

  } while (0 < iVar8);

  iVar8 = *piVar2;

  *piVar2 = iVar8 + 1;

  if (0x2c < iVar8 + 1) {

    *piVar2 = 0;

  }

  fVar14 = (float)sinf((DAT_007caf38 * (float)*piVar2) / 45.0f);

  uVar15 = (u32)(DAT_007cad78 * (float)(int)param_3 * (DAT_007cad74 * fVar14 + DAT_007cada4 + 0.0f))

  ;

  puVar9 = *(u32 **)(*(int *)(param_6 + 0x14) + 0x1c);

  sVar1 = *(short *)((int)puVar9 + 6);

  iVar8 = (int)sVar1;

  if ((int)sVar1 - 2U < 2) {

    param_3 = (u32)((float)(int)param_3 * DAT_007cad74);

  }

  iVar11 = iVar8;

  if (param_7 != 0) {

    iVar11 = sVar1 + 4;

    iVar8 = sVar1 + 4;

  }

  sprintf((char *)auStack_8,0x7cd9d8,*(u16 *)(PTR_DAT_007cd8f0 + (short)puVar9[1] * 0x40 + 0x3a)

              );

  iVar13 = (int)param_1;

  iVar12 = (int)param_2;

  FUN_0040ebc0(0,iVar13 + 0xf,iVar12 + 0x6e,param_3 | auStack_50[iVar8],1,auStack_8,0);

  uVar3 = puVar9[1];

  datSetFlag(0x1424,1);


  datSetFlag(0x1424,0);

  FUN_003c7e20(0,iVar13 + 0x30,iVar12 + 0x66,param_3 | auStack_30[iVar11],1,6,6,

               *(u16 *)(PTR_DAT_007cd8f0 + (short)uVar3 * 0x40 + 0x30));

  if ((*puVar9 & 0x100) != 0) {

    FUN_0040e3c0(0,param_1,param_2,uVar15 & 0xff,0x4c,0);

    FUN_0040e3c0(0,param_1,param_2,uVar15 & 0xff,0x4d,0);

  }

  puVar4 = (u8 *)(PTR_DAT_007cd8f0);

  sVar1 = (short)puVar9[1];

  lVar7 = ((long)(char)PTR_DAT_007cd8f0[sVar1 * 0x40 + 0xf] << 0x38) >> 0x3c;

  if (lVar7 == 2) {

    sVar5 = datGetDaysSinceApr5();

    unaff_s7 = (long)sVar5;

    iVar6 = clndGetDaysSinceStartFromDate(((long)*(short *)(puVar4 + sVar1 * 0x40 + 0xc) << 0x34) >> 0x3a,

                         ((long)(char)puVar4[sVar1 * 0x40 + 0xc] << 0x3a) >> 0x3a);

    unaff_s8 = (long)((int)(((long)*(short *)(puVar4 + sVar1 * 0x40 + 0xe) << 0x34) >> 0x34) + iVar6

                     );

LAB_004062e0:

    if (unaff_s7 == unaff_s8) {

      iVar6 = 2;

    }

    else if (unaff_s7 < unaff_s8) {

      iVar6 = 1;

    }

    else {

      iVar6 = 0;

    }

  }

  else {

    if (lVar7 == 1) {

      sVar5 = datGetDaysSinceApr5();

      unaff_s7 = (long)sVar5;

      unaff_s8 = clndGetDaysSinceStartFromDate(((long)*(short *)(puVar4 + sVar1 * 0x40 + 0xe) << 0x34) >> 0x3a,

                              ((long)(char)puVar4[sVar1 * 0x40 + 0xe] << 0x3a) >> 0x3a);

      goto LAB_004062e0;

    }

    if (lVar7 != 0) goto LAB_004062e0;

    iVar6 = 3;

  }

  if (iVar6 != 1) {

    if (iVar6 == 3) {

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,iVar11 + 0x61,0);

      goto LAB_00406468;

    }

    if (iVar6 == 2) {

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,iVar11 + 0x59,0);

      goto LAB_00406468;

    }

  }

  sprintf((char *)auStack_8,0x7cd9d8,

               (short)(((long)*(short *)(PTR_DAT_007cd8f0 + (short)puVar9[1] * 0x40 + 0xe) << 0x34)

                      >> 0x3a));

  uVar15 = auStack_30[iVar8];

  FUN_0040ebc0(0,iVar13 + 0x1f7,iVar12 + 0x6e,param_3 | uVar15,3,auStack_8,1);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,iVar11 + 0x3c,0);

  sprintf((char *)auStack_8,0x7cd9d8,

               ((long)(char)PTR_DAT_007cd8f0[(short)puVar9[1] * 0x40 + 0xe] << 0x3a) >> 0x3a);

  FUN_0040ebc0(0,iVar13 + 0x202,iVar12 + 0x6e,param_3 | uVar15,3,auStack_8,0);

LAB_00406468:

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,iVar11 + 0x44,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x4e,0);

  return;

}





















// FUN_004064E0 NONMATCHING
void FUN_004064e0(u64 param_1,u64 param_2,u32 param_3,int param_4)



{

  char cVar1;

  short sVar2;

  short sVar3;

  u8 *puVar4;

  int iVar5;

  int iVar6;

  u64 uVar7;

  int iVar8;

  long lVar9;

  int iVar10;

  float fVar11;

  u8 auStack_40 [4];

  u8 bStack_3c;

  u8 auStack_20 [32];

  

  puVar4 = (u8 *)(PTR_DAT_007cd8f0);

  if (*(int *)(param_4 + 0xc) != 0) {

    iVar8 = *(int *)(*(int *)(*(int *)(param_4 + 0xc) + 0x14) + 0x1c);

    sVar2 = *(short *)(iVar8 + 4);

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x51,0);

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x52,0);

    sVar3 = *(short *)(iVar8 + 4);


    fVar11 = DAT_007cad94 * (float)(int)param_3;

    if (2.1474836e+09f <= fVar11) {

      fVar11 = fVar11 - 2.1474836e+09f;

    }

    iVar10 = (int)param_1;

    iVar6 = (int)param_2;

    FUN_003c7e20(0,iVar10 + 0x3d,iVar6 + 0x127,(int)fVar11 & 0xffU | 0x1e225d00,1,6,6,

                 *(u16 *)(PTR_DAT_007cd8f0 + sVar3 * 0x40 + 0x32));

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x53,0);

    if (puVar4[sVar2 * 0x40 + 0x26] == '\x03') {

      sprintf((char *)auStack_20,0x7cd900,*(u32 *)(puVar4 + sVar2 * 0x40 + 0x28));

      iVar6 = FUN_0040ebc0(0,iVar10 + 0x7b,iVar6 + 0x184,param_3 | 0xffffffffffffff00,3,auStack_20,8

                          );

      FUN_0040e3c0(0,iVar10 + 0x85 + iVar6,param_2,param_3 & 0xff,0x58,0);

    }

    else if (puVar4[sVar2 * 0x40 + 0x26] == '\0') {


      FUN_0040e3c0(0,iVar10 + 0x77,iVar6 + 0x178,param_3 & 0xff,0,(u32)bStack_3c * 2 + 1);

      cVar1 = puVar4[sVar2 * 0x40 + 0x26];

      if (cVar1 == '\x04') {

        sprintf((char *)auStack_20,0x6af3d0);

      }

      else if (cVar1 == '\x03') {

        sprintf((char *)auStack_20,0x7cd900,*(u32 *)(puVar4 + sVar2 * 0x40 + 0x28));

      }

      else if (cVar1 == '\x02') {

        sprintf((char *)auStack_20,0x7cd9d0,

                     DAT_007ce4e4 + *(short *)(puVar4 + sVar2 * 0x40 + 0x28) * 0x11);

      }

      else if (cVar1 == '\x01') {

        sprintf((char *)auStack_20,0x7cd9d0,

                     DAT_007ce4e8 +

                     *(short *)(puVar4 + sVar2 * 0x40 + 0x28) * 0x12 +

                     (int)*(short *)(puVar4 + sVar2 * 0x40 + 0x28));

      }

      else if (cVar1 == '\0') {

        uVar7 = func_00171110(*(u16 *)(puVar4 + sVar2 * 0x40 + 0x28),

                             ((long)(char)puVar4[sVar2 * 0x40 + 0x2a] << 0x3c) >> 0x3c);

        sprintf((char *)auStack_20,0x7cd9d0,uVar7);

      }

      iVar5 = FUN_003b32d0(0,iVar10 + 0x9a,iVar6 + 0x182,param_3 | 0xffffffffffffff00,6,1,auStack_20

                           ,0x11,0x78);

      FUN_0040e3c0(0,iVar10 + iVar5 + 0xa4,param_2,param_3 & 0xff,0x54,0);

      sprintf((char *)auStack_20,0x7cd900,puVar4[sVar2 * 0x40 + 0x27]);

      FUN_0040ebc0(0,iVar10 + iVar5 + 199,iVar6 + 0x184,param_3 | 0xffffffffffffff00,3,auStack_20,2)

      ;

    }

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x55,0);

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x56,0);

    sVar2 = *(short *)(PTR_DAT_007cd8f0 + *(short *)(iVar8 + 4) * 0x40 + 0x3c);

    lVar9 = 0;

    while (lVar9 < 5) {

      iVar8 = (int)lVar9;

      if (lVar9 < sVar2) {

        FUN_0040e3c0(0,iVar10 + iVar8 * 0x17,param_2,param_3 & 0xff,0x57,1);

      }

      else {

        FUN_0040e3c0(0,iVar10 + iVar8 * 0x17,param_2,param_3 & 0xff,0x57,0);

      }

      lVar9 = (long)(iVar8 + 1);

    }

  }

  return;

}

// FUN_00406AA0 NONMATCHING


void FUN_00406aa0(u64 param_1,u64 param_2,u32 param_3)



{

  u32 uVar1;

  long lVar2;

  u64 uVar3;

  int iVar4;

  int iVar5;

  float fVar6;

  u8 auStack_8 [8];

  

  uVar1 = datGetTime();

  uVar1 = uVar1 & 0xff;

  if (uVar1 == 8) {

    uVar1 = 9;

  }

  lVar2 = clndIsHolidayOrSunday();

  if ((lVar2 == 1) && (uVar1 - 2 < 4)) {

    uVar1 = 8;

  }

  iVar4 = uVar1 - 1;

  if (iVar4 < 0) {

    iVar4 = 0;

  }

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,3,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,iVar4 + 5,0);

  uVar3 = clndGetCurrentMonth();

  sprintf((char *)auStack_8,0x7cd900,uVar3);

  fVar6 = DAT_007cad74 * (float)(int)param_3;

  if (fVar6 < 2.1474836e+09f) {

    uVar1 = (u32)fVar6;

  }

  else {

    uVar1 = (int)(fVar6 - 2.1474836e+09f) | 0x80000000;

  }

  iVar5 = (int)param_1;

  iVar4 = (int)param_2;

  FUN_0040ebc0(0,iVar5 + 0x212,iVar4 + 0x1b,uVar1 | 0xffffff00,3,auStack_8,2);

  FUN_0040e3c0(0,iVar5 + 0x60,param_2,param_3 & 0xff,0xe,0);

  uVar3 = clndGetCurrentDay();

  sprintf((char *)auStack_8,0x7cd900,uVar3);

  FUN_0040ebc0(0,iVar5 + 0x23c,iVar4 + 0x1b,uVar1 | 0xffffff00,3,auStack_8,2);

  uVar3 = clndGetCurrentWeekDay();

  FUN_0040e3c0(0,iVar5 + 0x60,iVar4 + 1,param_3 & 0xff,0xf,uVar3);

  return;

}

// FUN_00406CA0 NONMATCHING


void FUN_00406ca0(u64 param_1,u64 param_2,int *param_3)



{

  int iVar1;

  u32 *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  u32 uVar7;

  

  iVar3 = (int)param_2;

  iVar6 = *param_3 + (int)*(short *)(iVar3 + 0x14);

  iVar5 = param_3[1] + (int)*(short *)(iVar3 + 0x16);

  uVar7 = ((int)(short)param_3[2] * (int)*(short *)(iVar3 + 0x26)) / 0xff;

  if (uVar7 != 0) {

    iVar4 = param_3[3];

    iVar1 = *(int *)(iVar4 + 0x24);

    puVar2 = *(u32 **)(iVar1 + 0x44);

    switch(*(u32 *)(iVar3 + 0x10)) {

    case 0:

      if ((*puVar2 & 1) == 0) {


      }

      else {

        iVar3 = *(int *)(*(int *)(param_3[4] + 0x14) + 0x1c);

        iVar4 = (u32)((*(u16 *)((int)param_3 + 10) & 1) != 0) * 4;

        FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,*(short *)(iVar3 + 6) + iVar4 + 0x2c,0);

        FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,*(short *)(iVar3 + 6) + iVar4 + 0x34,0);

      }

      break;

    case 1:

      if ((*puVar2 & 1) != 0) {

        uVar7 = (u32)((float)(int)uVar7 * DAT_007cad74);

        if (*(int *)(iVar4 + 0xc) != param_3[4]) {

          uVar7 = (u32)((float)(int)uVar7 * 0.5);

        }

        FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x4f,0);

        FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x50,0);

      }

      break;

    case 2:

      FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x22,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x23,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x24,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x25,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x26,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x27,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x28,0);

      break;

    case 3:


      break;

    case 4:


      break;

    case 5:

      if ((*puVar2 & 2) == 0) {

        FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x1c,0);

        FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x1d,0);

      }

      else {

        FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x69,0);

        FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x6a,0);

      }

      break;

    case 6:

      FUN_0040e3c0(0,0,0,uVar7 & 0xff,0x1b,0);

      break;

    case 7:

      if (*(u32 *)(iVar1 + 0x20) <= (u32)*(u16 *)(iVar4 + 0x10)) {

        iVar3 = *(int *)(iVar1 + 0x28);

        FUN_0040e3f0(0,0,1.0f,1.0f,0,0,uVar7 & 0xff,0x29,0,0,0);

        FUN_0040e3f0(0,0,1.0f,1.0f,0,0,uVar7 & 0xff,0x2a,0,0,0);

        FUN_0040e3f0(0,0,1.0f,1.0f,0x269,(iVar3 * 0x4e) / 0xffff + 0x65,uVar7 & 0xff,

                     0x2b,0,0,0);

      }

    }

  }

  return;

}

// FUN_00407180


void FUN_00407180(u32 param_1,u32 param_2,u16 param_3,int param_4)
{
  int *puVar1;
  int iVar2;
  struct {
    u32 param1;
    u32 param2;
    u16 param3;
    u16 pad;
    u32 param4;
    u32 zero;
  } data;

  puVar1 = *(int **)(*(int *)(param_4 + 0x24) + 0x44);
  iVar2 = puVar1[2];
  data.param1 = param_1;
  data.param2 = param_2;
  data.param3 = param_3;
  data.param4 = (u32)param_4;
  data.zero = 0;
  FUN_003e0680_typed(iVar2,(code)FUN_00406ca0,&data);
  *puVar1 = *puVar1 | 1;
  FUN_003c4e70_u64(param_4);
  *puVar1 = *puVar1 & 0xfffffffe;
  return;
}

// FUN_00407210


void FUN_00407210(u32 param_1,u32 param_2,u16 param_3,int param_4,int param_5)
{
  int uVar1;
  struct {
    u32 param1;
    u32 param2;
    u16 param3;
    s16 flags;
    int param4;
    int param5;
  } data;

  uVar1 = *(int *)(*(int *)(*(int *)(param_5 + 0x14) + 0x1c) + 8);
  memset_typed(&data,0,0x18);
  if (*(int *)(param_4 + 0xc) == param_5) {
    data.flags = data.flags | 1;
  }
  data.param1 = param_1;
  data.param2 = param_2;
  data.param3 = param_3;
  data.param4 = param_4;
  data.param5 = param_5;
  FUN_003e0680_typed(uVar1,(code)FUN_00406ca0,&data);
  return;
}

// FUN_004072D0


void FUN_004072d0(int param_1, long param_2, long param_3)
{
  FclShopDispatchStorage storage;
  int anchor;
  int node;
  u32 tmp;
  u32 owner;

  anchor = *(int *)(*(int *)(param_1 + 0x24) + 0x44);
  owner = *(u32 *)(anchor + 0x1c);
  tmp = *(u32 *)(anchor + 0x20);

  switch (param_2) {
  case 0xe:
    if (param_3 == 0) {
      FCL_SHOP_MISC_BUILD(storage.path[27].result, &storage.output[29], owner, 0, 0, 5, 0);
      if (*(int *)(anchor + 4) == -8) {
        anchor = *(u32 *)(anchor + 0x1c);
        FCL_SHOP_MISC_BUILD(storage.path[26].result, &storage.output[28], anchor, 1, 1, 10, 2);
      }
    } else if (param_3 == 1) {
      FCL_SHOP_MISC_BUILD(storage.path[25].result, &storage.output[27], owner, 0, 0, 0, 1);
      if (*(int *)(anchor + 4) == -8) {
        anchor = *(u32 *)(anchor + 0x1c);
        FCL_SHOP_MISC_BUILD(storage.path[24].result, &storage.output[26], anchor, 1, 1, 0, 3);
      }
    }
    break;

  case 2:
    if (param_3 == 0) {
      for (owner = *(int *)(param_1 + 4); owner != 0; owner = *(int *)(owner + 0x10)) {
        anchor = *(u32 *)(*(int *)(*(int *)(owner + 0x14) + 0x1c) + 0xc);
        FCL_SHOP_MISC_BUILD(storage.path[23].result, &storage.output[25], anchor, 2, 2, 0, 4);
      }
    } else if ((param_3 == 1) && (*(int *)(param_1 + 0xc) != 0)) {
      owner = *(int *)(param_1 + 0xc);
      anchor = *(u32 *)(*(int *)(*(int *)(owner + 0x14) + 0x1c) + 0xc);
      FCL_SHOP_MISC_BUILD(storage.path[22].result, &storage.output[24], anchor, 2, 2, 0, 5);
    }
    break;

  case 0xf:
    if (param_3 == 0) {
      FUN_003e0c20(FUN_003c5460(FUN_003e0940()), 2, 0);
      FCL_SHOP_MISC_BUILD(storage.path[21].result, &storage.output[23], owner, 8, 8, 0, 16);
      FCL_SHOP_MISC_BUILD(storage.path[20].result, &storage.output[22], owner, 4, 4, 5, 8);
      FCL_SHOP_MISC_BUILD(storage.path[19].result, &storage.output[21], owner, 5, 5, 5, 10);
      FCL_SHOP_MISC_BUILD(storage.path[18].result, &storage.output[20], owner, 6, 6, 0, 12);
      FCL_SHOP_MISC_BUILD(storage.path[17].result, &storage.output[19], owner, 7, 7, 0, 14);
      FCL_SHOP_MISC_BUILD(storage.path[16].result, &storage.output[18], owner, 3, 3, 10, 6);
    } else if (param_3 == 1) {
      FUN_003e0c20(FUN_003c5460(FUN_003e0940()), 2, 2);
      FCL_SHOP_MISC_BUILD(storage.path[15].result, &storage.output[17], owner, 8, 8, 0, 17);
      FCL_SHOP_MISC_BUILD(storage.path[14].result, &storage.output[16], owner, 4, 4, 0, 9);
      FCL_SHOP_MISC_BUILD(storage.path[13].result, &storage.output[15], owner, 5, 5, 0, 11);
      FCL_SHOP_MISC_BUILD(storage.path[12].result, &storage.output[14], owner, 6, 6, 0, 13);
      FCL_SHOP_MISC_BUILD(storage.path[11].result, &storage.output[13], owner, 7, 7, 0, 15);
      FCL_SHOP_MISC_BUILD(storage.path[10].result, &storage.output[12], owner, 3, 3, 0, 7);
    }
    break;

  case 0x10:
    if (param_3 == 0) {
      FCL_SHOP_MISC_BUILD(storage.path[9].result, &storage.output[11], owner, 9, 9, 0, 18);
      FCL_SHOP_MISC_BUILD(storage.path[8].result, &storage.output[10], owner, 10, 10, 0, 20);
      FCL_SHOP_MISC_BUILD(storage.path[7].result, &storage.output[9], owner, 6, 6, 0, 12);
    } else if (param_3 == 1) {
      FCL_SHOP_MISC_BUILD(storage.path[6].result, &storage.output[8], owner, 9, 9, 0, 19);
      FCL_SHOP_MISC_BUILD(storage.path[5].result, &storage.output[7], owner, 10, 10, 0, 21);
      FCL_SHOP_MISC_BUILD(storage.path[4].result, &storage.output[6], owner, 6, 6, 0, 13);
    }
    break;

  case 0xb:
    if (param_3 == 0) {
      FCL_SHOP_MISC_BUILD(storage.path[3].result, &storage.output[5], tmp, 11, 11, 0, 22);
    } else if (param_3 == 1) {
      FCL_SHOP_MISC_BUILD(storage.path[2].result, &storage.output[4], tmp, 11, 11, 0, 23);
    }
    break;

  case 0xc:
    if (param_3 == 0) {
      FCL_SHOP_MISC_BUILD(storage.path[1].result, &storage.output[3], tmp, 12, 12, 0, 24);
    } else if (param_3 == 1) {
      FCL_SHOP_MISC_BUILD(storage.path[0].result, &storage.output[2], tmp, 12, 12, 0, 25);
    }
    break;

  case 0xd:
    if (param_3 == 0) {
      FCL_SHOP_MISC_BUILD(&storage.tail1, &storage.output[1], owner, 13, 13, 0, 26);
    } else if (param_3 == 1) {
      FCL_SHOP_MISC_BUILD(&storage.tail0, &storage.output[0], owner, 13, 13, 0, 27);
    }
    break;
}
}

// FUN_00409C80 NONMATCHING


u64 FUN_00409c80(u64 param_1)



{

  int iVar1;

  u32 uVar2;

  u32 uVar3;

  u32 uVar4;

  u32 uVar5;

  u32 uVar6;

  u32 uVar7;

  u32 uVar8;

  u32 uVar9;

  u32 uVar10;

  u32 uVar11;

  int iVar12;

  u32 uVar13;

  long lVar14;

  int iVar15;

  


  for (iVar15 = 1; iVar15 < 0x100; iVar15 = iVar15 + 1) {

    lVar14 = datGetPersonaByCompendium(iVar15);

    if (lVar14 != 0) {

      iVar1 = FUN_003c5a40(param_1,*(u16 *)((int)param_1 + 0x10) + 1,0x10,0);

      iVar1 = *(int *)(*(int *)(iVar1 + 0x14) + 0x1c);

      *(int *)(iVar1 + 4) = (int)lVar14;

      uVar2 = datPersonaGetTotalStat(lVar14,0);

      uVar3 = datPersonaGetTotalStat(lVar14,1);

      uVar4 = datPersonaGetTotalStat(lVar14,2);

      uVar5 = datPersonaGetTotalStat(lVar14,3);

      uVar6 = datPersonaGetTotalStat(lVar14,4);

      uVar7 = datPersonaGetTotalStat(lVar14,0);

      uVar8 = datPersonaGetTotalStat(lVar14,1);

      uVar9 = datPersonaGetTotalStat(lVar14,2);

      uVar10 = datPersonaGetTotalStat(lVar14,3);

      uVar11 = datPersonaGetTotalStat(lVar14,4);

      *(u32 *)(iVar1 + 8) =

           ((uVar6 & 0xff) + (uVar5 & 0xff) + (uVar4 & 0xff) + (uVar2 & 0xff) + (uVar3 & 0xff)) *

           ((uVar11 & 0xff) + (uVar10 & 0xff) + (uVar9 & 0xff) + (uVar7 & 0xff) + (uVar8 & 0xff)) *

           3 + 2000;

      lVar14 = datGetFlag(0x1319);

      if (lVar14 != 0) {

        iVar12 = *(int *)(iVar1 + 8) << 2;

        if (iVar12 < 10000000) {

          *(int *)(iVar1 + 8) = iVar12;

        }

        else {

          *(u8 **)(iVar1 + 8) = (u8 *)&DAT_0098967f;

        }

      }

      uVar13 = FUN_003dfeb0(0);

      *(u32 *)(iVar1 + 0xc) = uVar13;

    }

  }

  return 0;

}

// FUN_00409E90


u32 FUN_00409e90(void)
{
  u32 uVar1;
  int iVar3;

  iVar3 = 0;
  goto check_limit;
check_persona:
  uVar1 = datPersonaGetHeroPersona_s16((s16)iVar3);
  if (uVar1 != 0) {
    if (FUN_0017ca10_u32(uVar1) == 1) {
      return 1;
    }
  }
  iVar3 = iVar3 + 1;
check_limit:
  uVar1 = FUN_00175410_u32();
  if (iVar3 < (int)(uVar1 & 0xffff)) {
    goto check_persona;
  }
  return 0;
}

// FUN_00409F20


void FUN_00409f20(u64 param_1,int param_2)



{

  FUN_003dff00(*(u32 *)(*(int *)(*(int *)(param_2 + 0x14) + 0x1c) + 0xc));

  return;

}

// FUN_00409F50 NONMATCHING


u32 FUN_00409f50(u32 param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  u32 lVar7;
  u32 lVar8;
  int iVar9;

  uVar6 = FUN_003c58f0(0,0x28,8,0x18);
  iVar2 = (int)uVar6;
  iVar1 = *(int *)(*(int *)(iVar2 + 0x24) + 0x44);
  if (param_2 == 0) {
    *(u32 *)(iVar1 + 4) = 0xfffffff8;
    FUN_00409c80_i(uVar6);
    FUN_0040a6d0_i(uVar6,1);
  }
  else {
    *(u32 *)(iVar1 + 4) = 0xfffffff7;
    for (iVar9 = 0; uVar4 = FUN_00175410(),
         iVar9 < (int)(uVar4 & 0xffff); iVar9++) {
      lVar7 = FUN_00174a90_fcl((short)iVar9);
      if ((lVar7 != 0) && (lVar8 = FUN_0017ca10(lVar7), lVar8 == 1)) {
        iVar3 = FUN_003c5a40(uVar6,*(u16 *)(iVar2 + 0x10) + 1,0x10,0);
        iVar3 = *(int *)(*(int *)(iVar3 + 0x14) + 0x1c);
        *(int *)(iVar3 + 4) = (int)lVar7;
        uVar5 = FUN_003dfeb0(0);
        *(u32 *)(iVar3 + 0xc) = uVar5;
      }
    }
  }
  FUN_003c5d40(uVar6,*(u32 *)(iVar2 + 4),0);
  uVar5 = FUN_0017cf00();
  *(u32 *)(iVar1 + 0x24) = uVar5;
  uVar5 = FUN_003dfeb0(0);
  *(u32 *)(iVar1 + 0x1c) = uVar5;
  if (param_2 == 0) {
    uVar5 = FUN_003dfeb0(0);
    *(u32 *)(iVar1 + 0x20) = uVar5;
  }
  FUN_003c6ee0(uVar6);
  FUN_003c5f40(uVar6,0x409f20);
  FUN_003c5e20(uVar6,0x40b630);
  FUN_003c5ee0(uVar6,0x40b780);
  FUN_003c6d40(uVar6,0,0);
  *(u16 *)(*(int *)(iVar2 + 0x24) + 6) = 10;
  *(u16 *)(*(int *)(iVar2 + 0x24) + 8) = 5;
  if (param_2 == 0) {
    FUN_004072d0_i(uVar6,2,0);
    FUN_004072d0_i(uVar6,0xe,0);
    FUN_004072d0_i(uVar6,0xf,0);
    FUN_004072d0_i(uVar6,0xd,0);
  }
  else {
    FUN_004072d0_i(uVar6,2,0);
    FUN_004072d0_i(uVar6,0xe,0);
    FUN_004072d0_i(uVar6,0x10,0);
    FUN_004072d0_i(uVar6,0xd,0);
  }
  return uVar6;
}

// FUN_0040A200


void FUN_0040a200(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(*(int *)((int)param_1 + 0x24) + 0x44);

  FUN_003dff00(*(u32 *)(iVar1 + 0x1c));

  if (*(int *)(iVar1 + 0x20) != 0) {

    FUN_003dff00(*(u32 *)(iVar1 + 0x20));

  }

  FUN_003c5a20(param_1);

  return;

}

// FUN_0040A260


void FUN_0040a260(int param_1)



{

  int iVar1;

  

  for (iVar1 = *(int *)(param_1 + 4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {

    FUN_0017c960(*(u32 *)(*(int *)(*(int *)(iVar1 + 0x14) + 0x1c) + 4));

  }

  return;

}

// FUN_0040A2B0 NONMATCHING


u8 FUN_0040a2b0(u64 param_1)



{

  int iVar1;

  u32 uVar2;

  long lVar3;

  long lVar4;

  int iVar5;

  

  iVar1 = *(int *)(*(int *)((int)param_1 + 0x24) + 0x44);

  uVar2 = *(u32 *)(iVar1 + 0x20);

  FUN_003e0650(*(u32 *)(iVar1 + 0x1c));

  if (*(int *)(iVar1 + 0x20) != 0) {

    FUN_003e0650(uVar2);

  }

  for (iVar5 = *(int *)((int)param_1 + 4); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x10)) {

    FUN_003e0650(*(u32 *)(*(int *)(*(int *)(iVar5 + 0x14) + 0x1c) + 0xc));

  }

  lVar3 = FUN_003c6270(param_1);

  lVar4 = FUN_003c6ce0(param_1);

  if ((lVar4 != 0) || (lVar4 = FUN_003c6d10(param_1), lVar4 != 0)) {

    func_0010a4e0(0,0,0,0);

  }

  lVar4 = FUN_003c6ca0(param_1);

  if ((lVar4 != 0) || (lVar4 = FUN_003c6cc0(param_1), lVar4 != 0)) {

    func_0010a4e0(0,0,0,5);

  }


  if (lVar3 == 3) {

    if (*(int *)(iVar1 + 4) == -8) {




    }

    else {




    }

  }

  return lVar3 == 3;

}

// FUN_0040A490


u32 FUN_0040a490(u32 param_1)
{
  u32 uVar1;
  u32 uVar2;
  int iVar3;

  FUN_003e0650(*(u32 *)(*(int *)(*(int *)(param_1 + 0x24) + 0x44) + 0x1c));
  for (iVar3 = *(int *)(param_1 + 4); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x10)) {
    FUN_003e0650(*(u32 *)(*(int *)(*(int *)(iVar3 + 0x14) + 0x1c) + 0xc));
  }

  uVar1 = FUN_003c6270_u32(param_1);
  uVar1 = (uVar1 == 3);

  uVar2 = FUN_003c6ce0_u32(param_1);
  if ((uVar2 != 0) || ((uVar2 = FUN_003c6d10_u32(param_1)), uVar2 != 0)) {
    func_0010a4e0(0,0,0,0);
  }

  uVar2 = FUN_003c6ca0_u32(param_1);
  if ((uVar2 != 0) || ((uVar2 = FUN_003c6cc0_u32(param_1)), uVar2 != 0)) {
    func_0010a4e0(0,0,0,5);
  }
  FUN_004072d0(param_1,2,1);
  return uVar1;
}

#pragma push
#pragma opt_rebuildconditionals off
// FUN_0040A5B0
s32 FUN_0040a5b0(u32 *param_1, u32 *param_2)
{
  u32 entryA;
  u32 entryB;
  u32 t4;
  u32 t5;
  u8 *tablePtr;
  s32 result;
  u16 h;
  u16 i;
  u8 b1;
  u8 b2;
  u8 k;
  u8 m;

  entryA = *(u32 *)(*param_1 + 0x14);
  entryA = *(u32 *)(entryA + 0x1c);
  entryB = *(u32 *)(*param_2 + 0x14);
  entryB = *(u32 *)(entryB + 0x1c);
  t4 = *(u32 *)(entryA + 4);
  t5 = *(u32 *)(entryB + 4);
  b1 = *(u8 *)(t5 + 4);
  b2 = *(u8 *)(t4 + 4);
  result = (s32)b1 - (s32)b2;
  if (result != 0) {
    goto ret;
  }
  h = *(u16 *)(t5 + 2);
  tablePtr = (u8 *)DAT_007ce420 + 2;
  i = *(u16 *)(t4 + 2);
  k = tablePtr[i * 0xe];
  m = tablePtr[h * 0xe];
  result = (s32)k - (s32)m;
  if (result != 0) {
    goto ret;
  }
  result = (s32)i - (s32)h;
ret:
  return result;
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals off
// FUN_0040A640
s32 FUN_0040a640(u32 *param_1, u32 *param_2)
{
  u32 entryA;
  u32 entryB;
  u32 t5;
  u32 t4;
  u16 i;
  u8 *tablePtr;
  u16 h;
  u8 m;
  u8 k;
  s32 result;
  u8 bB;
  u8 bA;

  entryA = *(u32 *)(*param_1 + 0x14);
  entryA = *(u32 *)(entryA + 0x1c);
  entryB = *(u32 *)(*param_2 + 0x14);
  entryB = *(u32 *)(entryB + 0x1c);
  t5 = *(u32 *)(entryB + 4);
  i = *(u16 *)(t5 + 2);
  tablePtr = (u8 *)DAT_007ce420 + 2;
  t4 = *(u32 *)(entryA + 4);
  h = *(u16 *)(t4 + 2);
  m = tablePtr[h * 0xe];
  k = tablePtr[i * 0xe];
  result = (s32)m - (s32)k;
  if (result != 0) {
    goto ret;
  }
  bB = *(u8 *)(t5 + 4);
  bA = *(u8 *)(t4 + 4);
  result = (s32)bB - (s32)bA;
  if (result != 0) {
    goto ret;
  }
  result = (s32)h - (s32)i;
ret:
  return result;
}
#pragma pop

// FUN_0040A6D0 NONMATCHING


void FUN_0040a6d0(u64 param_1,long param_2)



{

  u32 *puVar1;

  u32 uVar2;

  u64 uVar3;

  

  puVar1 = *(u32 **)(*(int *)((int)param_1 + 0x24) + 0x44);

  uVar3 = FUN_003c6fb0();

  uVar2 = *(u32 *)((int)param_1 + 0xc);

  if (param_2 == 1) {

    FUN_003c7000(param_1,0x40a640,0);

  }

  else {

    FUN_003c7000(param_1,0x40a5b0,0);

  }

  FUN_003c5d40(param_1,uVar2,uVar3);

  if (param_2 == 1) {

    *puVar1 = *puVar1 | 2;

  }

  else {

    *puVar1 = *puVar1 & 0xfffffffd;

  }

  return;

}

// FUN_0040A7C0


void FUN_0040a7c0(u64 param_1,u64 param_2,u8 param_3)



{

  FUN_0040e3c0(param_1,param_2,param_3,0x78);

  return;

}

// Retail preserves this table as single-precision values across the callbacks.
// Keep the table and globals float-typed so MWCC emits the EE FPU path.
// The values are still consumed as raw bytes/words by the rendering helpers.
// Initialization order mirrors retail's table-index and alpha setup sequence.
// This reconstruction is semantically complete despite a small code-size floor.
// FUN_0040A7F0 NONMATCHING


void FUN_0040a7f0(u64 param_1,int param_2,int *param_3)



{


  u32 *puVar1;
  int iVar2;

  u64 uVar3;

  int bVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  u32 uVar9;

  int iVar10;

  int uVar11;
  u8 auStack_60[32];
  u8 auStack_40[16];
  u8 auStack_30[24];
  float auStack_18[6];


  

  iVar6 = *param_3 + (int)*(short *)(param_2 + 0x14);

  iVar5 = param_3[1] + (int)*(short *)(param_2 + 0x16);

  uVar11 = ((int)(short)param_3[2] * (int)*(short *)(param_2 + 0x26)) / 0xff;

  if (uVar11 != 0) {

    bVar4 = 0;
    if ((*(short *)((int)param_3 + 10) & 1) != 0) {
      bVar4 = 1;
    }

    iVar7 = param_3[3];

    iVar8 = *(int *)(iVar7 + 0x24);

    puVar1 = *(u32 **)(iVar8 + 0x44);

    switch(*(u32 *)(param_2 + 0x10)) {

    case 0:

      iVar7 = *(int *)(iVar8 + 0x2c);

      if (puVar1[1] == 0xfffffff7) {

        iVar6 = iVar6 + 0x3e;

        iVar5 = iVar5 + -0x1c;

      }

      iVar8 = 0;

      while( 1 ) {

        iVar10 = *(int *)(param_3[3] + 0x24);

        if (*(int *)(iVar10 + 0x20) <= iVar8) break;

        bVar4 = iVar7 == *(int *)(param_3[3] + 0xc);

        iVar10 = iVar5 + iVar8 * *(int *)(iVar10 + 0xc);

        if ((*puVar1 & 4) == 0) {

          iVar2 = *(int *)(*(int *)(iVar7 + 0x14) + 0x1c);
          uVar9 = (u32)bVar4;
          auStack_18[4] = fGpffffacf0;
          auStack_18[5] = fGpffffacf4;
          auStack_18[2] = fGpffffacf8;
          auStack_18[3] = fGpffffacfc;
 

          FUN_0040e3c0(0,iVar6,iVar10,uVar11 & 0xff,0x8e,

                       (*(u8 *)(iGpffffb730 + (u32)*(u16 *)(*(int *)(iVar2 + 4) + 2) * 0xe + 2

                                 ) - 1) * 2 + uVar9);

          FUN_003b32d0(0,iVar6 + 0xa3,iVar10 + 0x84,uVar11 | 0xffffff00,

                       *(u8 *)(auStack_18 + uVar9 + 4),1,

                       iGpffffb7f4 + (u32)*(u16 *)(*(int *)(iVar2 + 4) + 2) * 0x11,0x10,0x6e);

          sprintf((char *)auStack_30,&gp0xffffac10,*(u8 *)(*(int *)(iVar2 + 4) + 4));

          FUN_0040eb50(0,iVar6 + 0x174,iVar10 + 0x85,uVar11 & 0xff,auStack_18[uVar9 + 2],auStack_30,

                       1);

        }

        else {

          FUN_0040e3c0(0,iVar6,iVar10,uVar11 & 0xff,0x8d,bVar4);

          FUN_0040e3c0(0,iVar6,iVar10,uVar11 & 0xff,0x8f,0);

        }

        iVar7 = *(int *)(iVar7 + 0x10);

        if (iVar7 == 0) {

          return;

        }

        iVar8 = iVar8 + 1;

      }

      break;

    case 1:

      iVar7 = *(int *)(iVar8 + 0x2c);

      iVar8 = 0;

      while( 1 ) {

        iVar10 = *(int *)(param_3[3] + 0x24);

        if (*(int *)(iVar10 + 0x20) <= iVar8) break;

        iVar2 = *(int *)(param_3[3] + 0xc);

        iVar10 = iVar5 + iVar8 * *(int *)(iVar10 + 0xc);

        if ((*puVar1 & 4) == 0) {


          auStack_18[0] = fGpffffad00;
          auStack_18[1] = fGpffffad04;

          sprintf((char *)auStack_40,&gp0xffffac10,

                       *(u32 *)(*(int *)(*(int *)(iVar7 + 0x14) + 0x1c) + 8));

          FUN_0040eb50(0,iVar6 + 0x205,iVar10 + 0x85,uVar11 & 0xff,auStack_18[iVar7 == iVar2],

                       auStack_40,9);

        }

        else {

          FUN_0040e3c0(0,iVar6,iVar10,uVar11 & 0xff,0x90,0);

        }

        iVar7 = *(int *)(iVar7 + 0x10);

        if (iVar7 == 0) {

          return;

        }

        iVar8 = iVar8 + 1;

      }

      break;

    case 2:

      if ((*puVar1 & 4) != 0) {

        if (puVar1[1] == 0xfffffff8) {

          if (bVar4) {

            FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x94,0);

          }

          else {

            uVar11 = (u32)((float)(int)uVar11 * fGpffff8084);

          }

          FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x92,0);

          FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x93,0);

        }

        else {

          if (bVar4) {

            FUN_0040e3c0(0,iVar6 + 0x3e,iVar5 + -0x1c,uVar11 & 0xff,0x9a,0);

          }

          else {

            uVar11 = (u32)((float)(int)uVar11 * fGpffff8084);

          }

          FUN_0040e3c0(0,iVar6 + 0x3e,iVar5 + -0x1c,uVar11 & 0xff,0x92,0);

          FUN_0040e3c0(0,iVar6 + 0x3e,iVar5 + -0x1c,uVar11 & 0xff,0x9b,0);

        }

      }

      break;

    case 3:

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x75,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x76,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x77,0);

      uVar3 = FUN_0017cf00();

      sprintf((char *)auStack_60,&gp0xffffac10,uVar3);

      FUN_0040ec20(0,iVar6,iVar5,uVar11 & 0xff,0,auStack_60,1,0x26,0x40a7c0);

      break;

    case 4:

      bVar4 = (*puVar1 & 2) != 0 || bVar4;

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x79,bVar4);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x7a,bVar4);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x7d,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x7f,0);

      break;

    case 5:

      bVar4 = (*puVar1 & 2) == 0 || bVar4;

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x7b,bVar4);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x7c,bVar4);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x7e,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x80,0);

      break;

    case 6:

      if (puVar1[1] == 0xfffffff8) {

        FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x81,0);

        FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x83,0);

        FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x84,0);

        FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x85,0);

        FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x87,0);

        FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x88,0);

      }

      else {

        FUN_0040e3c0(0,iVar6 + 0x3e,iVar5 + -0x1c,uVar11 & 0xff,0x81,0);

        FUN_0040e3c0(0,iVar6 + 0x3e,iVar5 + -0x1c,uVar11 & 0xff,0x83,0);

        FUN_0040e3c0(0,iVar6 + 0x3e,iVar5 + -0x1c,uVar11 & 0xff,0x84,0);

        FUN_0040e3c0(0,iVar6 + 0x3e,iVar5 + -0x1c,uVar11 & 0xff,0x85,0);

        FUN_0040e3c0(0,iVar6 + 0x3e,iVar5 + -0x1c,uVar11 & 0xff,0x87,0);

        FUN_0040e3c0(0,iVar6 + 0x3e,iVar5 + -0x1c,uVar11 & 0xff,0x88,0);

      }

      break;

    case 7:

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x82,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x86,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x89,0);

      break;

    case 8:

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x6b,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x6c,0);

      break;

    case 9:

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x95,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x96,0);

      break;

    case 10:

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x97,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x98,0);

      break;

    case 0xd:

      if (puVar1[1] == 0xfffffff8) {

        if (*(u32 *)(iVar8 + 0x20) <= (u32)*(u16 *)(iVar7 + 0x10)) {

          iVar7 = *(int *)(iVar8 + 0x28);

          FUN_0040e3f0(0,0,1.0f,1.0f,iVar6,iVar5,uVar11 & 0xff,0x8a,0,0,0);

          FUN_0040e3f0(0,0,1.0f,1.0f,iVar6,iVar5,uVar11 & 0xff,0x8b,0,0,0);

          FUN_0040e3f0(0,0,1.0f,1.0f,iVar6 + 0x212,

                       iVar5 + 0x80 + (iVar7 * 0x7d) / 0xffff,uVar11 & 0xff,0x8c,0,0,0);

        }

      }

      else if (*(u32 *)(iVar8 + 0x20) <= (u32)*(u16 *)(iVar7 + 0x10)) {

        iVar7 = *(int *)(iVar8 + 0x28);

        FUN_0040e3f0(0,0,1.0f,1.0f,iVar6 + -0x54,iVar5 + -0x1c,uVar11 & 0xff,0x8a,0,0,0)

        ;

        FUN_0040e3f0(0,0,1.0f,1.0f,iVar6 + -0x54,iVar5 + -0x1c,uVar11 & 0xff,0x8b,0,0,0)

        ;

        FUN_0040e3f0(0,0,1.0f,1.0f,iVar6 + 0x1be,iVar5 + 100 + (iVar7 * 0x7d) / 0xffff,

                     uVar11 & 0xff,0x8c,0,0,0);

      }

    }

  }

  return;

}

// FUN_0040B3A0 NONMATCHING


void FUN_0040b3a0(u64 param_1,int param_2,int param_3)



{

  short sVar1;

  short sVar2;

  u16 uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  

  sVar1 = *(short *)(param_2 + 0x14);

  sVar2 = *(short *)(param_2 + 0x16);

  uVar3 = *(u16 *)(param_2 + 0x26);

  if (uVar3 != 0) {

    iVar5 = (int)sVar2;

    if (*(int *)(param_2 + 0x10) == 0xc) {

      iVar4 = *(int *)(*(int *)(*(int *)(param_3 + 0x10) + 0x14) + 0x1c);

      FUN_0040e3c0(0,sVar1,sVar2,uVar3 & 0xff,0x9e,0);

      FUN_0040e3c0(0,sVar1,sVar2,uVar3 & 0xff,0x9f,0);

      FUN_0040e3c0(0,sVar1 + 0x15d,iVar5 + 0x4d,uVar3 & 0xff,0x9d,

                   (*(u8 *)((u32)*(u16 *)(*(int *)(iVar4 + 4) + 2) * 0xe + iGpffffb730 + 2) -

                   1) * 2 + 1);

      FUN_003b32d0(0,sVar1 + 0x1af,iVar5 + 0x48,0xffffffffffffffff,5,1,

                   iGpffffb7f4 + (u32)*(u16 *)(*(int *)(iVar4 + 4) + 2) * 0x11,0,0x78);

    }

    else if (*(int *)(param_2 + 0x10) == 0xb) {

      iVar4 = *(int *)(*(int *)(*(int *)(param_3 + 0x10) + 0x14) + 0x1c);

      FUN_0040e3c0(0,sVar1,sVar2,uVar3 & 0xff,0xa0,0);

      FUN_0040e3c0(0,sVar1,sVar2,uVar3 & 0xff,0xa1,0);

      for (iVar6 = 0; iVar6 < 9; iVar6 = iVar6 + 1) {

        iVar7 = iVar5 + iVar6 * 0x19;

        FUN_0040e3c0(0,sVar1,iVar7,uVar3 & 0xff,0xa2,0);

        FUN_0040e3c0(0,sVar1,iVar7,uVar3 & 0xff,0xa3,0);

      }

      FUN_0040e3c0(0,sVar1,sVar2,uVar3 & 0xff,0xa4,0);

      FUN_0040e3c0(0,sVar1,sVar2,uVar3 & 0xff,0xa5,0);

      FUN_003c7e20(0,sVar1 + 0x16c,iVar5 + 0x77,uVar3 | 0xff00,1,6,4,

                   *(u16 *)(*(int *)(iVar4 + 4) + 2));

    }

  }

  return;

}

// FUN_0040B630 NONMATCHING


void FUN_0040b630(u32 param_1,u32 param_2,u16 param_3,u64 param_4)



{

  u32 *puVar1;

  u32 uVar2;

  u32 uVar3;

  u32 uVar4;

  int iVar5;

  u32 uStack_20;

  u32 uStack_1c;

  u16 uStack_18;

  int iStack_14;

  u32 uStack_10;

  

  iVar5 = (int)param_4;

  puVar1 = *(u32 **)(*(int *)(iVar5 + 0x24) + 0x44);

  uVar2 = puVar1[7];

  uVar3 = puVar1[8];

  FUN_0040e3c0(0,0,0,param_3 & 0xff,0x1b,0);

  uStack_10 = 0;

  *puVar1 = *puVar1 | 4;

  uStack_20 = param_1;

  uStack_1c = param_2;

  uStack_18 = param_3;

  iStack_14 = iVar5;

  FUN_003e0680(uVar2,0x40a7f0,&uStack_20);

  uVar4 = *puVar1;

  *puVar1 = uVar4 & 0xfffffffb;

  *puVar1 = uVar4 & 0xfffffffb | 4;

  FUN_003c4e70(param_4);

  *puVar1 = *puVar1 & 0xfffffffb;

  FUN_003e0680(uVar2,0x40a7f0,&uStack_20);

  if (uVar3 != 0) {

    uStack_10 = *(u32 *)(iVar5 + 0xc);

    uStack_20 = param_1;

    uStack_1c = param_2;

    uStack_18 = param_3;

    iStack_14 = iVar5;

    FUN_003e0680(uVar3,0x40b3a0,&uStack_20);

  }

  return;

}

// FUN_0040B780


void FUN_0040b780(u32 param_1,u32 param_2,u16 param_3,int param_4,int param_5)
{
  int uVar1;
  struct {
    u32 param1;
    u32 param2;
    u16 param3;
    s16 flags;
    int param4;
    int param5;
  } data;

  uVar1 = *(int *)(*(int *)(*(int *)(param_5 + 0x14) + 0x1c) + 0xc);
  memset_typed(&data,0,0x18);
  if (*(int *)(param_4 + 0xc) == param_5) {
    data.flags = data.flags | 1;
  }
  data.param1 = param_1;
  data.param2 = param_2;
  data.param3 = param_3;
  data.param4 = param_4;
  data.param5 = param_5;
  FUN_003e0680_typed(uVar1,(code)FUN_0040a7f0,&data);
  return;
}

// FUN_0040B840


void FUN_0040b840(int param_1)



{

  u32 *puVar1;
  u32 uVar2;

  

  puVar1 = *(u32 **)(*(int *)(param_1 + 0x24) + 0x44);

  puVar1[6] = 0;

  puVar1[4] = 1;

  *puVar1 = *puVar1 | 1;

  fclMisc003c9b00(puVar1[2],

               *(u32 *)(*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x14) + 0x1c) + 4),0);

  FUN_003c9d00(puVar1[2],8);

  FUN_003c9e00(puVar1[2],3);
  FUN_003c9e30(puVar1[2],2,puVar1[6] ^ 1);

  uVar2 = FUN_003e0940();

  uVar2 = FUN_003c5460(uVar2);

  FUN_003e0c20(uVar2,0xd,0);

  return;

}

// FUN_0040B910 NONMATCHING


u32 FUN_0040b910(u64 param_1)



{

  u32 *puVar1;

  u32 uVar2;

  u8 bVar3;

  u8 bVar4;

  u16 uVar5;

  u16 uVar6;

  u32 uVar7;

  u32 uVar8;

  long lVar9;

  u64 uVar10;

  int iVar11;

  int iVar12;

  u8 auStack_20 [32];

  

  bVar4 = 0;

  bVar3 = 0;

  iVar11 = (int)param_1;

  puVar1 = *(u32 **)(*(int *)(iVar11 + 0x24) + 0x44);

  iVar12 = *(int *)(*(int *)(*(int *)(iVar11 + 0xc) + 0x14) + 0x1c);

  switch(puVar1[4]) {

  case 1:

  case 2:

  case 3:

  case 4:

    uVar8 = FUN_003c6d80();

    if ((uVar8 & 5) != 0) {

      return 0;

    }

    bVar4 = 1;

    break;

  case 5:

    puVar1[4] = 7;

    lVar9 = FUN_001749a0(*(u16 *)(*(int *)(iVar12 + 4) + 2));

    if (lVar9 == 0) {

      uVar5 = FUN_001756f0();

      uVar6 = FUN_00175410();

      if (uVar5 < uVar6) {

        uVar2 = *(u32 *)(iVar12 + 8);

        uVar7 = datGetMoney();

        if (uVar7 < uVar2) {

          sprintf((char *)auStack_20,&gp0xffffac10,uVar2);

          FUN_003c7bc0(0,auStack_20);

          FUN_003c7430(0x13);

        }

        else {

          sprintf((char *)auStack_20,&gp0xffffac10,uVar2);

          FUN_003c7bc0(0,auStack_20);

          FUN_003c7430(0x12);

          FUN_003c74e0(0);

          FUN_003c7560(1);

          puVar1[4] = 6;

          uVar10 = FUN_003e0940();

          uVar10 = FUN_003c5460(uVar10);

          FUN_003e0c20(uVar10,3,0);

        }

      }

      else {

        FUN_003c7430(0x16);

      }

    }

    else {

      FUN_003c7430(0x15);

    }

    break;

  case 6:

    lVar9 = FUN_003c7850();

    if (lVar9 == 0) {

      FUN_003c7700();

      lVar9 = FUN_003c7610();

      if (lVar9 == 0) {

        iVar12 = *(int *)(*(int *)(*(int *)(iVar11 + 0xc) + 0x14) + 0x1c);

        datAddMoney(-*(int *)(iVar12 + 8));

        FUN_00174fb0(*(u32 *)(iVar12 + 4));

        puVar1[4] = 8;

        uVar10 = FUN_003e0940();

        uVar10 = FUN_003c5460(uVar10);

        FUN_003e0c20(uVar10,3,1);

      }

      else {

        puVar1[4] = 1;

        uVar10 = FUN_003e0940();

        uVar10 = FUN_003c5460(uVar10);

        FUN_003e0c20(uVar10,3,2);

      }

    }

    break;

  case 7:

    lVar9 = FUN_003c7850();

    if (lVar9 == 0) {

      FUN_003c7700();

      puVar1[4] = 1;

    }

    break;

  case 8:

    puVar1[4] = 9;

    iVar12 = *(int *)(*(int *)(*(int *)(iVar11 + 0xc) + 0x14) + 0x1c);

    sprintf((char *)auStack_20,&gp0xfffface0,

                 iGpffffb7f4 + (u32)*(u16 *)(*(int *)(iVar12 + 4) + 2) * 0x11);

    FUN_003c7bc0(0,auStack_20);

    FUN_003c7430(0x14);

  case 9:

    lVar9 = FUN_003c7850();

    if (lVar9 == 0) {

      FUN_003c7700();

      puVar1[4] = 10;

    }

    break;

  case 10:

    *puVar1 = *puVar1 & 0xfffffffe;

    FUN_003c9d00(puVar1[2],0x10);

    FUN_003cde70(puVar1[3],1);

    return 1;

  }

  if (bVar4) {

    if (((DAT_007e0952 & 0x1000) == 0) && ((DAT_007e095a & 0x1000) == 0)) {

      if (((DAT_007e0952 & 0x4000) == 0) && ((DAT_007e095a & 0x4000) == 0)) {

        if (((DAT_007e094e & 0x40) == 0) && ((DAT_007e0958 & 0x40) == 0)) {

          if ((((DAT_007e094e & 8) == 0) && ((DAT_007e0958 & 8) == 0)) || (puVar1[6] != 1)) {

            if ((((DAT_007e094e & 4) == 0) && ((DAT_007e0958 & 4) == 0)) || (puVar1[6] != 0)) {

              if (((DAT_007e094e & 0x20) != 0) || ((DAT_007e0958 & 0x20) != 0)) {

                func_0010a4e0(0,0,0,2);

                puVar1[4] = 10;

                if (puVar1[6] == 1) {



                  uVar10 = FUN_003e0940();

                  uVar10 = FUN_003c5460(uVar10);

                  FUN_003e0c20(uVar10,0xe,1);

                }

                else {

                  uVar10 = FUN_003e0940();

                  uVar10 = FUN_003c5460(uVar10);

                  FUN_003e0c20(uVar10,0xd,1);

                }

              }

            }

            else {

              func_0010a4e0(0,0,0,5);

              puVar1[6] = 1;



              FUN_003cde00(puVar1[3],1);

              FUN_003c9e70(puVar1[2],(u8)puVar1[6] ^ 1);

              bVar3 = 1;

              uVar10 = FUN_003e0940();

              uVar10 = FUN_003c5460(uVar10);

              FUN_003e0c20(uVar10,0xd,1);

              uVar10 = FUN_003e0940();

              uVar10 = FUN_003c5460(uVar10);

              FUN_003e0c20(uVar10,0xe,0);

            }

          }

          else {

            func_0010a4e0(0,0,0,5);

            puVar1[6] = 0;



            FUN_003cdba0(puVar1[3],*(u16 *)(*(int *)(iVar12 + 4) + 2));

            FUN_003cde70(puVar1[3],1);

            FUN_003c9e70(puVar1[2],(u8)puVar1[6] ^ 1);

            bVar3 = 1;

            uVar10 = FUN_003e0940();

            uVar10 = FUN_003c5460(uVar10);

            FUN_003e0c20(uVar10,0xd,0);

            uVar10 = FUN_003e0940();

            uVar10 = FUN_003c5460(uVar10);

            FUN_003e0c20(uVar10,0xe,1);

          }

        }

        else if (puVar1[6] == 0) {

          puVar1[4] = 5;

          func_0010a4e0(0,0,0,1);

        }

      }

      else {

        if ((1 < *(u16 *)(iVar11 + 0x10)) && (lVar9 = FUN_003c5bb0(param_1), lVar9 != 0)) {

          func_0010a4e0(0,0,0,0);

          bVar3 = 1;

        }

        FUN_003c4dc0(param_1,iVar11 + 4);

      }

    }

    else {

      if ((1 < *(u16 *)(iVar11 + 0x10)) && (lVar9 = FUN_003c5af0(param_1), lVar9 != 0)) {

        func_0010a4e0(0,0,0,0);

        bVar3 = 1;

      }

      FUN_003c4dc0(param_1,iVar11 + 4);

    }

    if (bVar3) {

      if (puVar1[6] == 1) {

        FUN_003cdba0(puVar1[3],

                     *(u16 *)

                      (*(int *)(*(int *)(*(int *)(*(int *)(iVar11 + 0xc) + 0x14) + 0x1c) + 4) + 2));

      }

      else if (puVar1[6] == 0) {

        FUN_003c9d00(puVar1[2],4);

      }

      fclMisc003c9b00(puVar1[2],

                   *(u32 *)(*(int *)(*(int *)(*(int *)(iVar11 + 0xc) + 0x14) + 0x1c) + 4),0);

    }

  }

  return 0;

}

// FUN_0040C150


void FUN_0040c150(u32 param_1)



{
  __asm__ volatile (
      ".set noreorder       \n"
      "lw $v1, 0x24($a0)    \n"
      "lw $v1, 0x44($v1)    \n"
      "lw $v1, 0($v1)       \n"
      "andi $v1, $v1, 1     \n"
      ".set reorder"
      :
      :
      : "v1", "memory"
  );
}

// FUN_0040C170


u32 FUN_0040c170(void)
{
  u32 uVar1;
  u32 *puVar2;
  int iVar2;

  uVar1 = FUN_0017d030();
  iVar2 = 0;
  puVar2 = DAT_006aedc4;
  do {
    if (uVar1 <= *(u32 *)((u8 *)puVar2 + iVar2 * 8 + 4)) {
      return *(u32 *)((u8 *)puVar2 + iVar2 * 8);
    }
    uVar1 = uVar1 - *(u32 *)((u8 *)puVar2 + iVar2 * 8 + 4);
    iVar2 = iVar2 + 1;
  } while (uVar1 != 0);
  return 0;
}

// FUN_0040C1E0 NONMATCHING


void FUN_0040c1e0(long param_1,long param_2,long param_3)



{

  int iVar1;

  int iVar2;

  u32 uVar3;

  long lVar4;

  int iVar5;

  int *piVar6;

  

  if ((param_1 == 0) || (param_2 == 0)) {

    K_Assert((const char *)(u32)0x6aede8,0x273b);

  }

  iVar1 = *(int *)((int)param_1 + 0xc);

  piVar6 = (int *)*(u32 *)param_2;

  for (iVar5 = 0; iVar5 < (int)((u32 *)param_2)[1]; iVar5 = iVar5 + 1) {

    if (((*piVar6 == 0) || (lVar4 = datGetFlag(), lVar4 != 0)) &&

       ((piVar6[1] == 0 || (lVar4 = datGetFlag(), lVar4 != 0)))) {

      if (param_3 == 0) {

        iVar2 = *(u16 *)(iVar1 + 0x10) + 1;

      }

      else {

        iVar2 = *(int *)((int)param_3 + iVar5 * 4);

      }

      iVar2 = FUN_003c5a40(iVar1,iVar2,0xc,0);

      iVar2 = *(int *)(*(int *)(iVar2 + 0x14) + 0x1c);

      *(int **)(iVar2 + 4) = piVar6;

      uVar3 = FUN_003dfeb0(param_2);

      *(u32 *)(iVar2 + 8) = uVar3;

    }

    piVar6 = piVar6 + 4;

  }

  return;

}

// FUN_0040C310 NONMATCHING


void FUN_0040c310(int param_1)
{
  u32 *puVar1;
  u8 bVar2;
  u32 uVar3;
  int iVar6;
  int *piVar5;

  piVar5 = *(int **)(*(int *)(param_1 + 0xc) + 4);
  do {
    if (piVar5 == (int *)0x0) {
      return;
    }
    if (*piVar5 == 0xb) {
      puVar1 = *(u32 **)(piVar5[5] + 0x1c);
      uVar3 = FUN_0017c700_u32();
      if (uVar3 == 0) {
        *puVar1 |= 1;
      }
      else {
        *puVar1 &= 0xfffffffe;
      }
    }
    else if (*piVar5 == 0xd) {
      puVar1 = *(u32 **)(piVar5[5] + 0x1c);
      bVar2 = 0;
      for (iVar6 = 0; iVar6 < (int)(FUN_00175410_u32() & 0xffff); iVar6++) {
        uVar3 = datPersonaGetHeroPersona_u32((s16)iVar6);
        if (uVar3 != 0) {
          uVar3 = FUN_0017ca10_u32(uVar3);
          if (uVar3 == 1) {
            bVar2 = 1;
            goto LAB_0040c3c4;
          }
        }
      }
LAB_0040c3c4:
      if (bVar2) {
        *puVar1 &= 0xfffffffe;
      }
      else {
        *puVar1 |= 1;
      }
    }
    piVar5 = (int *)piVar5[4];
  } while (1);
}

// FUN_0040C460


void FUN_0040c460(u64 param_1,int param_2)



{

  FUN_003dff00(*(u32 *)(*(int *)(*(int *)(param_2 + 0x14) + 0x1c) + 8));

  return;

}

// FUN_0040C490


void FUN_0040c490(u64 param_1)



{

  FUN_003d9820(param_1,4,0);

  FUN_003d9820(param_1,0,0);

  FUN_003d9820(param_1,1,0);

  FUN_003d9820(param_1,5,0);

  FUN_003d9820(param_1,6,0);

  return;

}

// FUN_0040C520


void FUN_0040c520(u64 param_1)



{

  FUN_003d9820(param_1,4,1);

  FUN_003d9820(param_1,0,1);

  FUN_003d9820(param_1,1,1);

  FUN_003d9820(param_1,5,1);

  FUN_003d9820(param_1,6,1);

  return;

}

// FUN_0040C5B0


void FUN_0040c5b0(u64 param_1)



{

  FUN_003d9820(param_1,4,1);

  FUN_003d9820(param_1,0,1);

  FUN_003d9820(param_1,1,1);

  FUN_003d9820(param_1,2,1);

  FUN_003d9820(param_1,3,1);

  FUN_003d9820(param_1,7,1);

  return;

}

// FUN_0040C650


void FUN_0040c650(u64 param_1)



{

  FUN_003d9820(param_1,0,3);

  FUN_003d9820(param_1,7,1);

  return;

}

// FUN_0040C6A0


void FUN_0040c6a0(u64 param_1)



{

  FUN_003d9820(param_1,0,0);

  FUN_003d9820(param_1,7,0);

  return;

}

// FUN_0040C6F0 NONMATCHING


int FUN_0040c6f0(int param_1)



{

  int iVar1;

  u32 uVar2;

  int iVar3;

  u32 uVar4;

  u64 uVar5;

  int iVar6;

  u32 *puVar7;

  u32 *puVar8;

  u32 auStack_20 [8];

  

  if ((param_1 < 0) || (2 < param_1)) {

    K_Assert((const char *)(u32)0x6aede8,0x27ad);

  }

  uVar5 = FUN_003c58f0(0,0x10,7,0x1c);

  iVar3 = (int)uVar5;

  iVar1 = *(int *)(*(int *)(iVar3 + 0x24) + 0x44);

  *(int *)(iVar1 + 0xc) = iVar3;

  uVar4 = FUN_003dfeb0(iVar1);

  *(u32 *)(iVar1 + 8) = uVar4;

  *(int *)(iVar1 + 4) = param_1;

  if (param_1 == 2) {

    puVar8 = &DAT_006af930;

    puVar7 = auStack_20;

    iVar6 = 4;

    do {

      uVar4 = *puVar8;

      uVar2 = puVar8[1];

      puVar8 = puVar8 + 2;

      iVar6 = iVar6 + -1;

      *puVar7 = uVar4;

      puVar7[1] = uVar2;

      puVar7 = puVar7 + 2;

    } while (0 < iVar6);



  }

  else {


  }

  FUN_003c6ee0(uVar5);

  FUN_003c5e80(uVar5,0x40d330);

  FUN_003c5e20(uVar5,0x40d3b0);

  FUN_003c5ee0(uVar5,0x40d400);

  FUN_003c5f40(uVar5,0x40c460);

  FUN_003c6d40(uVar5,0,0);

  *(u16 *)(*(int *)(iVar3 + 0x24) + 6) = 10;

  *(u16 *)(*(int *)(iVar3 + 0x24) + 8) = 10;

  if (param_1 == 2) {

    FUN_003d9820(iVar1,4,0);

    FUN_003d9820(iVar1,0,0);

    FUN_003d9820(iVar1,1,0);

    FUN_003d9820(iVar1,5,0);

    FUN_003d9820(iVar1,6,0);

  }

  else {

    FUN_003d9820(iVar1,4,0);

    FUN_003d9820(iVar1,0,0);

    FUN_003d9820(iVar1,1,0);

    FUN_003d9820(iVar1,2,0);

    FUN_003d9820(iVar1,3,0);

    FUN_003d9820(iVar1,7,0);

  }

  return iVar1;

}

// FUN_0040C9A0
void FUN_0040c9a0(int param_1)




{

  if (param_1 == 0) {

    K_Assert((const char *)(DAT_006aede8 + 1) - 1,0x27d2);

  }

  FUN_003dff00(*(u32 *)((int)param_1 + 8));

  FUN_003c5a20(*(u32 *)((int)param_1 + 0xc));

  return;

}

// FUN_0040CA00


u32 FUN_0040ca00(int param_1)



{

  u32 lVar1;
  u32 uVar2;

  

  if ((uVar2 = FUN_003c6270_u32(*(u32 *)(param_1 + 0xc))) == 2) {

    FUN_003d9820(param_1,4,1);
    FUN_003d9820(param_1,0,1);
    FUN_003d9820(param_1,1,1);
    FUN_003d9820(param_1,2,1);
    FUN_003d9820(param_1,3,1);
    FUN_003d9820(param_1,7,1);

  }
  lVar1 = uVar2;

  return lVar1;

}

// FUN_0040CAD0 NONMATCHING


void FUN_0040cad0(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  u32 uStack_20;

  u32 uStack_1c;

  u16 uStack_18;

  u16 uStack_16;

  int iStack_14;

  int iStack_10;

  

  iVar4 = 0;

  iVar1 = *(int *)(param_1 + 0xc);

  FUN_003c6380(iVar1);

  iVar5 = *(int *)(*(int *)(iVar1 + 0x24) + 0x2c);

  iVar2 = *(int *)(iVar1 + 0xc);

  do {

    if (iVar5 == 0) break;

    if (iVar5 != iVar2) {

      iVar3 = *(int *)(*(int *)(iVar5 + 0x14) + 0x1c);

      memset(&uStack_20,0,0x18);

      uStack_20 = **(u32 **)(iVar5 + 0x14);

      uStack_1c = (*(u32 **)(iVar5 + 0x14))[1];

      uStack_18 = (u16)*(u32 *)(*(int *)(iVar1 + 0x24) + 0x1c);

      iStack_14 = iVar1;

      iStack_10 = iVar5;

      FUN_003e0680(*(u32 *)(iVar3 + 8),0x40cc30,&uStack_20);

    }

    iVar5 = *(int *)(iVar5 + 0x10);

    iVar4 = iVar4 + 1;

  } while (iVar4 < *(int *)(*(int *)(iVar1 + 0x24) + 0x20));

  iVar5 = *(int *)(*(int *)(iVar2 + 0x14) + 0x1c);

  memset(&uStack_20,0,0x18);

  uStack_16 = uStack_16 | 1;

  uStack_20 = **(u32 **)(iVar2 + 0x14);

  uStack_1c = (*(u32 **)(iVar2 + 0x14))[1];

  uStack_18 = (u16)*(u32 *)(*(int *)(iVar1 + 0x24) + 0x1c);

  iStack_14 = iVar1;

  iStack_10 = iVar2;

  FUN_003e0680(*(u32 *)(iVar5 + 8),0x40cc30,&uStack_20);

  return;

}

// FUN_0040CC30 NONMATCHING


void FUN_0040cc30(u64 param_1,int param_2,int *param_3)



{

  u8 bVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  u32 *puVar5;

  long lVar6;

  int iVar7;

  int iVar8;

  u32 uVar9;

  u32 auStack_8 [2];

  

  iVar8 = *param_3 + (int)*(short *)(param_2 + 0x14);

  iVar7 = param_3[1] + (int)*(short *)(param_2 + 0x16);

  uVar9 = ((int)(short)param_3[2] * (int)*(short *)(param_2 + 0x26)) / 0xff;

  if (uVar9 != 0) {

    bVar1 = (*(u16 *)((int)param_3 + 10) & 1) != 0;

    iVar2 = param_3[3];

    iVar3 = *(int *)(iVar2 + 0x24);

    iVar4 = *(int *)(iVar3 + 0x44);

    switch(*(u32 *)(param_2 + 0x10)) {

    case 0:

      iVar2 = *(int *)(iVar4 + 4);

      if (iVar2 == 0) {

        FUN_0040e3c0(0,iVar8,iVar7,uVar9 & 0xff,0x58,bVar1);

        FUN_0040e3c0(0,iVar8,iVar7,uVar9 & 0xff,0x59,bVar1);

      }

      else if ((iVar2 == 2) || (iVar2 == 1)) {

        FUN_0040e3c0(0,iVar8,iVar7,uVar9 & 0xff,0x14,bVar1);

        FUN_0040e3c0(0,iVar8,iVar7,uVar9 & 0xff,0x15,bVar1);

      }

      auStack_8[0] = DAT_007cd9f8;

      auStack_8[1] = DAT_007cd9fc;

      puVar5 = *(u32 **)(*(int *)(param_3[4] + 0x14) + 0x1c);

      if ((*puVar5 & 1) != 0) {

        uVar9 = (u32)((float)(int)uVar9 * 0.5f);

      }

      iVar2 = *(int *)(*(int *)(*(int *)(param_3[3] + 0x24) + 0x44) + 4);

      if (iVar2 == 0) {

        FUN_003b2cb0(0,iVar8 + 0x40,iVar7 + 0x57,uVar9 | 0xffffff00,

                     *(u8 *)(auStack_8 + (short)(u16)bVar1),1,

                     *(u32 *)(puVar5[1] + 8),0x10,0);

      }

      else if ((iVar2 == 2) || (iVar2 == 1)) {

        FUN_003b2cb0(0,iVar8 + 0x40,iVar7 + 0x61,uVar9 | 0xffffff00,

                     *(u8 *)(auStack_8 + (short)(u16)bVar1),1,

                     *(u32 *)(puVar5[1] + 8),0x10,0);

      }

      break;

    case 1:

      lVar6 = FUN_003dff80(param_1,0);

      if (lVar6 != 0) {

        iVar7 = iVar7 + *(short *)((int)lVar6 + 0x16);

        iVar8 = iVar8 + *(short *)((int)lVar6 + 0x14);

        iVar2 = *(int *)(*(int *)(*(int *)(param_3[3] + 0x24) + 0x44) + 4);

        if (iVar2 == 0) {

          FUN_0040e3c0(0,iVar8,iVar7,uVar9 & 0xff,0x5d,0);

          FUN_0040e3c0(0,iVar8,iVar7,uVar9 & 0xff,0x5e,0);

        }

        else if ((iVar2 == 2) || (iVar2 == 1)) {

          FUN_0040e3c0(0,iVar8,iVar7,uVar9 & 0xff,0x16,0);

          FUN_0040e3c0(0,iVar8,iVar7,uVar9 & 0xff,0x17,0);

        }

      }

      break;

    case 2:

      if (*(int *)(iVar4 + 4) == 0) {

        FUN_0040e3c0(2.0f,iVar8,iVar7,uVar9 & 0xff,0x54,0);

        FUN_0040e3c0(0,iVar8,iVar7,uVar9 & 0xff,0x55,0);

      }

      else if (*(int *)(iVar4 + 4) == 1) {

        FUN_0040e3c0(2.0f,iVar8,iVar7,uVar9 & 0xff,0x12,0);

      }

      break;

    case 3:

      if (*(int *)(iVar4 + 4) == 0) {

        FUN_0040e3c0(1.0f,iVar8,iVar7,uVar9 & 0xff,0x56,0);

      }

      else if (*(int *)(iVar4 + 4) == 1) {

        FUN_0040e3c0(0,iVar8,iVar7,uVar9 & 0xff,0x13,0);

      }

      break;

    case 4:

      if (*(int *)(iVar4 + 4) != 0) {

        FUN_0040e3c0(10.0f,iVar8,iVar7,uVar9 & 0xff,1,0);

      }

      break;

    case 5:

      FUN_0040e3c0(1.0f,iVar8,iVar7,uVar9 & 0xff,2,0);

      break;

    case 6:


      break;

    case 7:

      if (*(int *)(iVar4 + 4) == 0) {

        if (*(u32 *)(iVar3 + 0x20) <= (u32)*(u16 *)(iVar2 + 0x10)) {

          iVar2 = *(int *)(iVar3 + 0x28);

          FUN_0040e3f0(0,0,1.0f,1.0f,iVar8,iVar7,uVar9 & 0xff,0x5a,0,0,0);

          FUN_0040e3f0(0,0,1.0f,1.0f,iVar8,iVar7,uVar9 & 0xff,0x5b,0,0,0);

          FUN_0040e3f0(0,0,1.0f,1.0f,iVar8 + 0x176,

                       iVar7 + 0x54 + (iVar2 * 0x7c) / 0xffff,uVar9 & 0xff,0x5c,0,0,0);

        }

      }

      else if (*(u32 *)(iVar3 + 0x20) <= (u32)*(u16 *)(iVar2 + 0x10)) {

        iVar2 = *(int *)(iVar3 + 0x28);

        FUN_0040e3f0(0,0,1.0f,1.0f,iVar8,iVar7,uVar9 & 0xff,0x18,0,0,0);

        FUN_0040e3f0(0,0,1.0f,1.0f,iVar8,iVar7,uVar9 & 0xff,0x19,0,0,0);

        FUN_0040e3f0(0,0,1.0f,1.0f,iVar8 + 0x176,iVar7 + 0x54 + (iVar2 * 0x7c) / 0xffff,

                     uVar9 & 0xff,0x1a,0,0,0);

      }

    }

  }

  return;

}

// FUN_0040D330


void FUN_0040d330(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(*(int *)(param_1 + 0x24) + 0x44);

  FUN_003e0650(*(u32 *)(iVar1 + 8));

  for (iVar2 = *(int *)(param_1 + 4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x10)) {

    FUN_003e0650(*(u32 *)(*(int *)(*(int *)(iVar2 + 0x14) + 0x1c) + 8));

  }

  FUN_003d9820(iVar1,1,1);

  return;

}

// FUN_0040D3B0


void FUN_0040d3b0(u32 param_1,u32 param_2,u16 param_3,int param_4)



{
  struct {
    u32 param1;
    u32 param2;
    u16 param3;
    int param4;
    u32 zero;
  } data;
  u32 *base;

  base = *(u32 **)(*(int *)(param_4 + 0x24) + 0x44);
  data.param1 = param_1;
  data.param2 = param_2;
  data.param3 = param_3;
  data.param4 = param_4;
  data.zero = 0;

  FUN_003e0680_typed(*(u32 *)(base + 2),(code)FUN_0040cc30,&data);

  return;

}

// FUN_0040D400
void FUN_0040d400(void)
{
  return;
}

// FUN_0040D410


u32 FUN_0040d410(void)
{
  u32 uVar1;

  uVar1 = scrGetIntPara_u32(0);
  DAT_007cda00 = uVar1;
  switch (uVar1) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 8:
    FUN_003e0700_u32(uVar1);
    break;
  case 7:
    fclCombine003d02f0_i();
    break;
  default:
    DAT_007cda00 = 0xffffffff;
  }
  return 1;
}

// FUN_0040D490 NONMATCHING


u32 FUN_0040d490(void)



{

  long lVar1;

  

  lVar1 = scrGetCmdTimer();

  if (3 < lVar1) {

    switch(DAT_007cda00) {

    case 0:

    case 1:

    case 2:

    case 3:

    case 4:

    case 5:

    case 6:

    case 8:

      lVar1 = FUN_003e0920();

      if (lVar1 == 0) {

        return 1;

      }

      break;

    case 7:

      lVar1 = fclCombine003d04b0();

      if (lVar1 == 0) {

        return 1;

      }

      break;

    default:

      DAT_007cda00 = 0xffffffff;

    }

  }

  return 0;

}

// FUN_0040D540


u32 FUN_0040d540(void)



{

  switch(DAT_007cda00) {

  case 0:

  case 1:

  case 2:

  case 3:

  case 4:

  case 5:

  case 6:

  case 8:

    FUN_003e0b70();

    break;

  case 7:

    fclCombine003d0560();

    break;

  default:

    DAT_007cda00 = 0xffffffff;

  }

  return 1;

}

// FUN_0040D5B0


void FUN_0040d5b0(int param_1,int param_2,int param_3,int param_4,u32 param_5)



{


  FUN_0040d5e0(0.0f,param_1,param_2,param_3,param_4,param_5);


  return;
}

// FUN_0040D5E0


void FUN_0040d5e0(float param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6)



{


  FUN_0040d610(param_1,param_2,param_3,param_4,param_5,param_6,0);


  return;
}

// FUN_0040D610


void FUN_0040d610(float param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6,long param_7)



{


  FUN_0040d640(param_1,param_2,param_3,param_4,param_5,param_6,param_7,0);


  return;
}






































// FUN_0040D640 NONMATCHING

void FUN_0040d640(float param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6,

                 long param_7,long param_8)

{

  u32 uVar1;

  int iVar2;

  u32 uVar3;

  u32 uVar4;

  float fStack_140, fStack_13c, fStack_138, fStack_128;
  float fStack_120, fStack_11c, fStack_118, fStack_114;
  float fStack_100, fStack_fc, fStack_f8, fStack_e8;
  float fStack_e0, fStack_dc, fStack_d8, fStack_d4;
  float fStack_c0, fStack_bc, fStack_b8, fStack_a8;
  float fStack_a0, fStack_9c, fStack_98, fStack_94;
  float fStack_80, fStack_7c, fStack_78, fStack_68;
  float fStack_60, fStack_5c, fStack_58, fStack_54;
  u32 uStack_130, uStack_12c;
  u32 uStack_f0, uStack_ec;
  u32 uStack_b0, uStack_ac;
  u32 uStack_70, uStack_6c;

  if (param_7 == 0) {

    RpSkyRenderStateSet(2,0x44);

    RpSkyRenderStateSet(3,0x717fb);

    (*DAT_00960090)(6,1);

    (*DAT_00960090)(8,1);

    (*DAT_00960090)(7,2);

    (*DAT_00960090)(9,2);

    (*DAT_00960090)(0xc,1);

    (*DAT_00960090)(0xe,0);

    (*DAT_00960090)(0x14,2);

    (*DAT_00960090)(1,0);

  }

  uVar1 = param_6 >> 0x18;

  uVar4 = param_6 >> 0x10 & 0xff;

  uVar3 = param_6 >> 8 & 0xff;

  param_6 = param_6 & 0xff;
  param_1 = *(float *)&DAT_00960088 - param_1;

  if (param_8 != 0) {

    (*DAT_00960090)(1,param_8);

    iVar2 = kwlnGetMainCamera();

    fStack_128 = 1.0f / *(float *)(iVar2 + 0x84);

  }

  // Use a float array as a single addressable object to prevent dead-store elimination
  { float *v = (float *)&fStack_140;
    v[0]  = (float)param_2;           // vertex 0 x
    v[1]  = (float)param_3;           // vertex 0 y
    v[3]  = (float)uVar1;             // vertex 0 r
    v[4]  = (float)uVar4;             // vertex 0 g
    v[5]  = (float)uVar3;             // vertex 0 b
    v[6]  = (float)param_6;           // vertex 0 a
    v[7]  = (float)param_2;           // vertex 1 x
    v[8]  = (float)(param_3 + param_5); // vertex 1 y
    v[10] = (float)uVar1;             // vertex 1 r
    v[11] = (float)uVar4;             // vertex 1 g
    v[12] = (float)uVar3;             // vertex 1 b
    v[13] = (float)param_6;           // vertex 1 a
    v[14] = (float)(param_2 + param_4); // vertex 2 x
    v[15] = (float)param_3;           // vertex 2 y
    v[17] = (float)uVar1;             // vertex 2 r
    v[18] = (float)uVar4;             // vertex 2 g
    v[19] = (float)uVar3;             // vertex 2 b
    v[20] = (float)param_6;           // vertex 2 a
    v[21] = (float)(param_2 + param_4); // vertex 3 x
    v[22] = (float)(param_3 + param_5); // vertex 3 y
    v[24] = (float)uVar1;             // vertex 3 r
    v[25] = (float)uVar4;             // vertex 3 g
    v[26] = (float)uVar3;             // vertex 3 b
    v[27] = (float)param_6;           // vertex 3 a
    v[2]  = param_1;                  // vertex 0 z
    v[9]  = param_1;                  // vertex 1 z
    v[16] = param_1;                  // vertex 2 z
    v[23] = param_1;                  // vertex 3 z
  }

  if (param_8 != 0) {
    uStack_130 = 0;
    uStack_12c = 0;
    uStack_f0 = 0;
    uStack_ec = 0x3f800000;
    uStack_b0 = 0x3f800000;
    uStack_ac = 0;
    uStack_70 = 0x3f800000;
    uStack_6c = 0x3f800000;
    fStack_e8 = fStack_128;
    fStack_a8 = fStack_128;
    fStack_68 = fStack_128;
  }

  (*DAT_009600a0)(4,&fStack_140,4);
  (*DAT_00960090)(1,0);
}




























// FUN_0040DCC0 NONMATCHING
void FUN_0040dcc0(float param_1,int param_2,int param_3,int param_4,int param_5,int param_6,

                 u32 param_7,int param_8,long param_9)



{

  u32 uVar1;

  u32 uVar2;

  u32 uVar3;

  float fVar4;

  float fVar5;

  float fStack_c0;

  float fStack_bc;

  float fStack_b8;

  float fStack_a0;

  float fStack_9c;

  float fStack_98;

  float fStack_94;

  float fStack_80;

  float fStack_7c;

  float fStack_78;

  float fStack_60;

  float fStack_5c;

  float fStack_58;

  float fStack_54;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_14;

  

  if (param_9 == 0) {

    RpSkyRenderStateSet(2,0x44);

    RpSkyRenderStateSet(3,0x717fb);

    (*DAT_00960090)(6,1);

    (*DAT_00960090)(8,1);

    (*DAT_00960090)(7,2);

    (*DAT_00960090)(9,2);

    (*DAT_00960090)(0xc,1);

    (*DAT_00960090)(0xe,0);

    (*DAT_00960090)(0x14,2);

    (*DAT_00960090)(1,0);

  }

  uVar1 = param_7 >> 0x18;

  uVar3 = param_7 >> 0x10 & 0xff;

  uVar2 = param_7 >> 8 & 0xff;

  param_7 = param_7 & 0xff;

  param_1 = *(float *)&DAT_00960088 - param_1;

  fVar5 = DAT_007cae00 + DAT_007caf14 * (float)param_8;

  fVar4 = (float)cosf(fVar5);

  fVar5 = (float)sinf(fVar5);

  fStack_c0 = (float)param_2 + (float)param_4 * fVar4;

  fStack_bc = (float)param_3 + (float)-param_4 * fVar5;

  { float *vc = (float *)&fStack_a0;
    vc[0] = (float)uVar1;
    vc[1] = (float)uVar3;
    vc[2] = (float)uVar2;
    vc[3] = (float)param_7; }

  fVar5 = DAT_007cae00 + DAT_007caf14 * (float)(param_8 + 0x78);

  fStack_b8 = param_1;

  fVar4 = (float)cosf(fVar5);

  fVar4 = (float)param_5 * fVar4;

  fVar5 = (float)sinf(fVar5);

  fStack_80 = (float)param_2 + fVar4;

  fStack_7c = (float)param_3 + (float)-param_5 * fVar5;

  { float *vc = (float *)&fStack_60;
    vc[0] = (float)uVar1;
    vc[1] = (float)uVar3;
    vc[2] = (float)uVar2;
    vc[3] = (float)param_7; }

  fVar5 = DAT_007cae00 + DAT_007caf14 * (float)(param_8 + -0x78);

  fStack_78 = param_1;

  fVar4 = (float)cosf(fVar5);

  fVar4 = (float)param_6 * fVar4;

  fVar5 = (float)sinf(fVar5);

  fStack_40 = (float)param_2 + fVar4;

  fStack_3c = (float)param_3 + (float)-param_6 * fVar5;

  { float *vc = (float *)&fStack_20;
    vc[0] = (float)uVar1;
    vc[1] = (float)uVar3;
    vc[2] = (float)uVar2;
    vc[3] = (float)param_7; }

  fStack_38 = param_1;

  (*DAT_009600a0)(3,&fStack_c0,3);

  (*DAT_00960090)(1,0);

  return;

}
