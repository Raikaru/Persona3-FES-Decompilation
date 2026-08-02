/* W390 TU convergence: the 28 functions below moved here from y_runtime.c,
 * which is now deleted -- upstream splat.yaml places 0x0045A430..0x0045E7B0 in
 * Yajima/y_timeLimit and the rest of y_runtime in Yajima/y_misc.
 *
 * Measured trade, recorded so it is not mistaken for a regression to chase:
 * every function is byte-identical in SOURCE to its y_runtime original (verified
 * by diffing each block), and 265 of 378 Yajima markers still MATCH with none
 * lost and nothing over window.  Three functions moved on normalized_diff --
 * FUN_0045CE90 2022->2071, FUN_0045D990 900->947, FUN_0045E3E0 392->516 -- purely
 * because a smaller translation unit assigns $gp/small-data slots differently.
 * Adding y_timeLimit.h to the old y_runtime.c does NOT reproduce it, so it is the
 * TU boundary itself, not an include or a lost pragma.  These numbers should
 * settle once the remaining translation units converge on retail as well. */
#include "Yajima/y_timeLimit.h"

#pragma alias iGpffffba08_y2 iGpffffba08



/*
 * The task framework stores the time-limit state pointer at work+0x3C.
 * Keep the explicit padding so these fields remain at their retail offsets.
 */
typedef struct YTimeLimitInner
{
    u8 reserved00[4];
    u8 lifecycleState;
    u8 reserved05[0x3f];
    s16 transitionFrame;
} YTimeLimitInner;

typedef struct YTimeLimitWork
{
    u8 reserved00[0x3c];
    YTimeLimitInner* timeLimit;
} YTimeLimitWork;

extern YTimeLimitWork* iGpffffba08_y2;

enum
{
    /* State 6 makes FUN_0045A020 finish the time-limit task immediately. */
    Y_TIME_LIMIT_STATE_FINISHED = 6,
};

// FUN_0045a400
void Y_TimeLimit_Stop(void)
{
    YTimeLimitInner* timeLimit;

    if (iGpffffba08_y2 != NULL)
    {
        timeLimit = iGpffffba08_y2->timeLimit;
        timeLimit->transitionFrame = 0;
        timeLimit->lifecycleState = Y_TIME_LIMIT_STATE_FINISHED;
    }
}


#include "temporary.h"
#include "Yajima/y_runtime.h"

#pragma alias FUN_00108f70_y2 FUN_00108f70
#pragma alias FUN_001023a0_y2 FUN_001023a0
#pragma alias FUN_00108570_y2 FUN_00108570
#pragma alias FUN_001085c0_y2 FUN_001085c0
#pragma alias FUN_00108710_y2 FUN_00108710
#pragma alias FUN_0010c1a0_y2 FUN_0010c1a0
#pragma alias FUN_0010c3a0_y2 FUN_0010c3a0
#pragma alias FUN_0016c4f0_y2 FUN_0016c4f0
#pragma alias FUN_00173300_y2 FUN_00173300
#pragma alias FUN_0017be10_y2 FUN_0017be10
#pragma alias FUN_001a0250_y2 FUN_001a0250
#pragma alias FUN_001a02c0_y2 FUN_001a02c0
#pragma alias FUN_001ad910_y2 FUN_001ad910
#pragma alias FUN_001ad920_y2 FUN_001ad920
#pragma alias FUN_001ad940_y2 FUN_001ad940
#pragma alias FUN_001b00c0_y2 FUN_001b00c0
#pragma alias FUN_001b0220_y2 FUN_001b0220
#pragma alias FUN_001b0240_y2 FUN_001b0240
#pragma alias FUN_001b0260_y2 FUN_001b0260
#pragma alias FUN_001bf220_y2 FUN_001bf220
#pragma alias FUN_001c7130_y2 FUN_001c7130
#pragma alias FUN_001cd670_y2 FUN_001cd670
#pragma alias FUN_001d3810_y2 FUN_001d3810
#pragma alias FUN_001e1360_y2 FUN_001e1360
#pragma alias FUN_003182d0_y2 FUN_003182d0
#pragma alias FUN_00318b60_y2 FUN_00318b60
#pragma alias FUN_004221a0_y2 FUN_004221a0
#pragma alias FUN_004229d0_y2 FUN_004229d0
#pragma alias FUN_00422c10_y2 FUN_00422c10
#pragma alias FUN_00422c30_y2 FUN_00422c30
#pragma alias FUN_00422c90_y2 FUN_00422c90
#pragma alias FUN_00427e50_y2 FUN_00427e50
#pragma alias FUN_00488f30_y2 FUN_00488f30
#pragma alias FUN_004c69f0_y2 FUN_004c69f0
#pragma alias FUN_0045e8c0_y2 FUN_0045e8c0
#pragma alias FUN_004312b0_y2 FUN_004312b0
#pragma alias FUN_0043c690_y2 FUN_0043c690
#pragma alias FUN_004579b0_y2 FUN_004579b0
#pragma alias FUN_00195290_y2 FUN_00195290
#pragma alias DAT_007caf94_y2 DAT_007caf94
#pragma alias DAT_007cafa8_y2 DAT_007cafa8
#pragma alias DAT_007cafc0_y2 DAT_007cafc0
#pragma alias DAT_007cb134_y2 DAT_007cb134
#pragma alias DAT_007cb138_y2 DAT_007cb138
#pragma alias DAT_007ce704_y2 DAT_007ce704
#pragma alias DAT_00960088_y2 DAT_00960088
#pragma alias FUN_001124b0_y2 FUN_001124b0
#pragma alias FUN_0016f1f0_y2 FUN_0016f1f0
#pragma alias FUN_00521408_y2 FUN_00521408
#pragma alias fGpffff8110_y2 fGpffff8110
#pragma alias fGpffff8248_y2 fGpffff8248
#pragma alias fGpffff82d8_y2 fGpffff82d8
#pragma alias uGpffff82b8_y2 uGpffff82b8
#pragma alias uGpffff82d0_y2 uGpffff82d0
#pragma alias uGpffff82d4_y2 uGpffff82d4
#pragma alias FUN_00100d80_y2 FUN_00100d80
#pragma alias FUN_0010a4e0_y2 FUN_0010a4e0
#pragma alias FUN_001127d0_y2 FUN_001127d0
#pragma alias FUN_001140d0_y2 FUN_001140d0
#pragma alias FUN_001158b0_y2 FUN_001158b0
#pragma alias FUN_00115980_y2 FUN_00115980
#pragma alias FUN_0016c470_y2 FUN_0016c470
#pragma alias FUN_0016c970_y2 FUN_0016c970
#pragma alias FUN_0017b5b0_y2 FUN_0017b5b0
#pragma alias FUN_00195460_y2 FUN_00195460
#pragma alias FUN_001c6450_y2 FUN_001c6450
#pragma alias FUN_001c6720_y2 FUN_001c6720
#pragma alias FUN_001c7160_y2 FUN_001c7160
#pragma alias FUN_001d8d80_y2 FUN_001d8d80
#pragma alias FUN_00421fe0_y2 FUN_00421fe0
#pragma alias FUN_004d1260_y2 FUN_004d1260
#pragma alias FUN_00524828_y2 FUN_00524828
#pragma alias FUN_0045b4e0_y2 FUN_0045b4e0
#pragma alias FUN_0044f120_y2 FUN_0044f120
#pragma alias FUN_0044f170_y2 FUN_0044f170
#pragma alias FUN_0043c180_y2 FUN_0043c180
#pragma alias FUN_0043c340_y2 FUN_0043c340
#pragma alias FUN_00453460_y2 FUN_00453460
#pragma alias FUN_00431aa0_y2 FUN_00431aa0
#pragma alias FUN_00432050_y2 FUN_00432050
#pragma alias FUN_00432600_y2 FUN_00432600
#pragma alias FUN_00432bb0_y2 FUN_00432bb0
#pragma alias FUN_00434770_y2 FUN_00434770
#pragma alias FUN_0043ca30_y2 FUN_0043ca30
#pragma alias FUN_0045a280_y2 FUN_0045a280
#pragma alias FUN_0045afd0_y2 FUN_0045afd0
#pragma alias FUN_0045b190_y2 FUN_0045b190
#pragma alias FUN_0045b420_y2 FUN_0045b420
#pragma alias FUN_0045e3e0_y2 FUN_0045e3e0
#pragma alias FUN_00430180_y2 FUN_00430180
#pragma alias FUN_00430bb0_y2 FUN_00430bb0
#pragma alias FUN_00431110_y2 FUN_00431110
#pragma alias FUN_00431670_y2 FUN_00431670
#pragma alias FUN_00439f60_y2 FUN_00439f60
#pragma alias FUN_00447e70_y2 FUN_00447e70
#pragma alias FUN_0044aaf0_y2 FUN_0044aaf0
#pragma alias FUN_0044ad20_y2 FUN_0044ad20
#pragma alias FUN_0044e560_y2 FUN_0044e560
#pragma alias FUN_004542c0_y2 FUN_004542c0
#pragma alias FUN_00455e00_y2 FUN_00455e00
#pragma alias FUN_004560d0_y2 FUN_004560d0
#pragma alias FUN_00458630_y2 FUN_00458630
#pragma alias FUN_00459f60_y2 FUN_00459f60
#pragma alias FUN_00435260_y2 FUN_00435260
#pragma alias FUN_004353f0_y2 FUN_004353f0
#pragma alias FUN_004359f0_y2 FUN_004359f0
#pragma alias FUN_0043c7f0_y2 FUN_0043c7f0
#pragma alias FUN_00449c90_y2 FUN_00449c90
#pragma alias FUN_0044a420_y2 FUN_0044a420
#pragma alias FUN_0044f060_y2 FUN_0044f060
#pragma alias FUN_0044f1c0_y2 FUN_0044f1c0
#pragma alias FUN_00453480_y2 FUN_00453480
#pragma alias FUN_00454400_y2 FUN_00454400
#pragma alias FUN_00454520_y2 FUN_00454520
#pragma alias FUN_00454a70_y2 FUN_00454a70
#pragma alias FUN_00454d00_y2 FUN_00454d00
#pragma alias FUN_00457390_y2 FUN_00457390
#pragma alias FUN_004573d0_y2 FUN_004573d0
#pragma alias FUN_0045a3b0_y2 FUN_0045a3b0
#pragma alias FUN_0045af90_y2 FUN_0045af90
#pragma alias FUN_0045b480_y2 FUN_0045b480
#pragma alias FUN_0045b4b0_y2 FUN_0045b4b0
#pragma alias FUN_00430270_y2 FUN_00430270
#pragma alias FUN_004311f0_y2 FUN_004311f0
#pragma alias FUN_004344f0_y2 FUN_004344f0
#pragma alias FUN_00435c00_y2 FUN_00435c00
#pragma alias FUN_00438010_y2 FUN_00438010
#pragma alias FUN_00439520_y2 FUN_00439520
#pragma alias FUN_00448060_y2 FUN_00448060
#pragma alias FUN_00448cf0_y2 FUN_00448cf0
#pragma alias FUN_00449d60_y2 FUN_00449d60
#pragma alias FUN_0044a240_y2 FUN_0044a240
#pragma alias FUN_0044a330_y2 FUN_0044a330
#pragma alias FUN_0044af60_y2 FUN_0044af60
#pragma alias FUN_0044beb0_y2 FUN_0044beb0
#pragma alias FUN_0044dfc0_y2 FUN_0044dfc0
#pragma alias FUN_004561d0_y2 FUN_004561d0
#pragma alias FUN_004563d0_y2 FUN_004563d0
#pragma alias FUN_00456a90_y2 FUN_00456a90
#pragma alias FUN_0045b620_y2 FUN_0045b620
#pragma alias FUN_0045bcb0_y2 FUN_0045bcb0
#pragma alias FUN_0045cdd0_y2 FUN_0045cdd0
#pragma alias FUN_0045ce90_y2 FUN_0045ce90
#pragma alias FUN_0045d990_y2 FUN_0045d990


typedef int (*code)(...);
typedef struct YajimaVec2 {
  f32 x;
  f32 y;
} YajimaVec2;
typedef u8 bool;

typedef union Vec128 { struct { u32 _0_4_; u32 _4_4_; u32 _8_4_; u32 _12_4_; }; struct { u64 _0_8_; u64 _8_8_; }; u8 _bytes[16]; } Vec128;
static inline Vec128 rwVecZero(void) { Vec128 v; v._0_8_=0; v._8_8_=0; return v; }
static inline int yTimeLess(int lhs, int rhs) { return lhs < rhs; }
static Vec128 rwVecKeep(Vec128 v) { return v; }
#define _lqc2(x) rwVecZero()
#define _sqc2(x) rwVecKeep(x)
#define _qmtc2(x) rwVecZero()
#define _qmfc2(x) rwVecZero()
#define _vwaitq() ((u32)0)
#define _ctc2(x) ((void)0)
#define _vnop() ((void)0)
#define DI() ((void)0)
#define EI() ((void)0)
#define SYNC(x) ((void)0)
#define FlushCache(x) ((void)0)
#define _pcpyld(...) rwVecZero()
#define _pexew(...) rwVecZero()
#define _ppacw(...) rwVecZero()
#define _vabs(...) rwVecZero()
#define _vadd(...) rwVecZero()
#define _vaddabc(...) rwVecZero()
#define _vaddi(...) rwVecZero()
#define _vmadd(...) rwVecZero()
#define _vmadda(...) rwVecZero()
#define _vmaddabc(...) rwVecZero()
#define _vmaddbc(...) rwVecZero()
#define _vmax(...) rwVecZero()
#define _vmini(...) rwVecZero()
#define _vmsubbc(...) rwVecZero()
#define _vmul(...) rwVecZero()
#define _vmula(...) rwVecZero()
#define _vmulabc(...) rwVecZero()
#define _vmulbc(...) rwVecZero()
#define _vmuli(...) rwVecZero()
#define _vsub(...) rwVecZero()
#ifndef SQRT
#define SQRT(x) sqrtf(x)
#endif
extern f32 sqrtf(f32 value);
extern u32 DAT_006b4608;
extern u32 DAT_006b4610;
extern u32 DAT_006b4618;
extern u32 DAT_006b4620;
extern u8 DAT_006b4630[];
extern u8 DAT_006b45e0[];
extern u8 DAT_006b4510[];
extern u8 DAT_006b4bc0[];
extern u8 DAT_006b4a60[];
extern u8 DAT_006b45f8[];
extern u8 DAT_006b4a00[];
extern u8 DAT_006b4a18[];
extern u8 DAT_006b4a30[];
extern u8 DAT_006b4be0[];
extern u8 DAT_006b4b50[];
extern u8 DAT_006b4b30[];
extern u8 DAT_006b4b68[];
extern u32 DAT_006b4650;
extern u8 DAT_006b44f0[];
extern u32 DAT_006b4652;
extern u32 DAT_006b46d0;
extern u32 DAT_006b46d2;
extern u32 DAT_006b46d4;
extern u32 DAT_006b46d6;
extern u32 DAT_006b46d8;
extern u32 DAT_006b46da;
extern u32 DAT_006b46dc;
extern u32 DAT_006b46de;
extern u32 DAT_006b46e0;
extern u32 DAT_006b46e2;
extern u32 DAT_006b46e4;
extern u32 DAT_006b46e6;
extern u32 DAT_006b4712;
extern u32 DAT_006b4714;
extern u32 DAT_006b4716;
extern u32 DAT_006b4718;
extern u32 DAT_006b471a;
extern u32 DAT_006b471c;
extern u32 DAT_006b471e;
extern u32 DAT_006b477a;
extern u32 DAT_006b477c;
extern u32 DAT_006b477e;
extern u32 DAT_006b4780;
extern u32 DAT_006b4782;
extern u32 DAT_006b4784;
extern u32 DAT_006b4786;
extern u32 DAT_006b4788;
extern u32 DAT_006b478a;
#pragma alias DAT_006b46d0_abs DAT_006b46d0
#pragma alias DAT_006b477e_abs DAT_006b477e
#pragma alias DAT_006b4784_abs DAT_006b4784
#pragma alias DAT_006b478a_abs DAT_006b478a
extern s8 DAT_006b46d0_abs[];
extern s8 DAT_006b477e_abs[];
extern s8 DAT_006b4784_abs[];
extern s8 DAT_006b478a_abs[];
extern u32 DAT_006b478c;
extern u32 DAT_006b478e;
extern u32 DAT_006b4790;
extern u32 DAT_006b4792;
extern u32 DAT_006b4794;
extern u32 DAT_006b4796;
extern u32 DAT_006b4798;
extern u32 DAT_006b479a;
extern u32 DAT_006b479c;
extern u32 DAT_006b479e;
extern u32 DAT_006b47a0;
extern u32 DAT_006b47a2;
extern u32 DAT_006b47a4;
extern u32 DAT_006b47a6;
extern u32 DAT_006b47ae;
extern u32 DAT_006b481a;
extern u32 DAT_006b4a48;
extern u32 DAT_006b4a50;
extern u32 DAT_006b4a78;
extern u32 DAT_006b4a80;
extern u32 DAT_006b4a90;
#pragma alias DAT_006b4a78_abs DAT_006b4a78
extern u8 DAT_006b4a78_abs[];
#pragma alias DAT_006b4a90_abs DAT_006b4a90
extern u8 DAT_006b4a90_abs[];
extern u32 DAT_006b4ab0;
extern u32 DAT_006b4ab4;
extern u32 DAT_006b4ab8;
#pragma alias DAT_006b4ab0_abs DAT_006b4ab0
extern u8 DAT_006b4ab0_abs[];
extern u32 DAT_006b4abc;
extern u32 DAT_006b4ac0;
extern u32 DAT_006b4ac2;
extern u32 DAT_006b4ac4;
extern u32 DAT_006b4ac6;
extern u32 DAT_006b4ac8;
extern u32 DAT_006b4b20;
extern u32 DAT_006b4b28;
extern u32 DAT_006b4b80;
extern u32 DAT_006b4b82;
extern u32 DAT_006b4b84;
extern u32 DAT_006b4e00;
extern u32 DAT_007bc460;
extern int DAT_007bc610[];
extern u32 DAT_007bc6b0;
extern u32 DAT_007bc730;
extern float DAT_007caf94;
extern float DAT_007cafa8;
extern float DAT_007cafc0;
extern float DAT_007cb134;
extern float DAT_007cb138;
extern u32 DAT_007cdb10;
extern u32 DAT_007ce290;
extern u32 DAT_007ce6ac;
extern u32 DAT_007ce6bc;
extern u32 DAT_007ce6c0;
extern u32 DAT_007ce6c4;
extern u32 DAT_007ce6c8;
extern u32 DAT_007ce6cc;
extern u32 DAT_007ce6d0;
extern u32 DAT_007ce6d4;
extern u32 DAT_007ce6e0;
extern u32 DAT_007ce6e4;
extern s8 DAT_007ce6e7;
extern u32 DAT_007ce6e8;
extern u32 DAT_007ce6ec;
extern u32 DAT_007ce6f0;
extern u32 DAT_007ce6f4;
extern u32 DAT_007ce700;
extern s32 DAT_007ce704;
extern u32 DAT_007ce70c;
extern u32 DAT_007ce710;
extern u32 DAT_007ce714;
extern u32 DAT_007ce718;
extern u32 DAT_007e094e;
extern u32 DAT_007e0952;
extern u32 DAT_007e0958;
extern u32 DAT_007e095a;
extern u32 DAT_0086be00;
#pragma alias DAT_0086be00_abs DAT_0086be00
extern u8 DAT_0086be00_abs[];
extern u32 DAT_0086e6e8;
extern u8 DAT_0086e6a0[];
extern u32 DAT_0086e6f0;
extern u32 DAT_0086e6f4;
extern u32 DAT_0086e808;
extern u32 DAT_0086e80c;
extern u32 DAT_0086e810;
extern u32 DAT_0086e848;
extern u32 DAT_0086e9cc;
extern u32 DAT_0086eb8c;
extern u32 DAT_0086ed4c;
extern u32 DAT_0086eda0;
extern u32 DAT_0086ede8;
extern u32 DAT_0086edf4;
extern u32 DAT_0086ef08;
extern u32 DAT_0086ef0c;
extern u32 DAT_0086ef10;
extern u32 DAT_0086ef2c;
extern u32 DAT_0086ef38;
extern u32 DAT_0086ef39;
extern u32 DAT_0086ef3a;
extern u32 DAT_0086ef3b;
extern u32 DAT_0086ef3c;
extern u32 DAT_008717a0;
extern u32 DAT_008717e8;
#pragma alias DAT_008717e8_rows DAT_008717e8
#pragma alias DAT_008717a0_bytes DAT_008717a0
extern u8 DAT_008717a0_bytes[];
#pragma alias DAT_008717a0_rows_abs DAT_008717a0
extern u8 DAT_008717a0_rows_abs[][0x1c0];
#pragma alias DAT_008717a0_rows_check DAT_008717a0
extern u8 DAT_008717a0_rows_check[][0x1c0];
#pragma alias DAT_008717a0_unit_rows DAT_008717a0
extern YRuntimeUnitRow DAT_008717a0_unit_rows[];
#pragma alias DAT_0086eda0_bytes DAT_0086eda0
extern u8 DAT_0086eda0_bytes[];
#pragma alias DAT_006b4650_bytes DAT_006b4650
extern u8 DAT_006b4650_bytes[];
#pragma alias DAT_006b4652_bytes DAT_006b4652
extern u8 DAT_006b4652_bytes[];
#pragma alias DAT_006b4608_abs DAT_006b4608
extern u8 DAT_006b4608_abs[];
#pragma alias DAT_006b4610_abs DAT_006b4610
extern u8 DAT_006b4610_abs[];
#pragma alias DAT_006b4618_abs DAT_006b4618
extern u8 DAT_006b4618_abs[];
#pragma alias DAT_006b4620_abs DAT_006b4620
extern u8 DAT_006b4620_abs[];
#pragma alias FUN_001b9120_u32 FUN_001b9120
#pragma alias FUN_0035bc00_u32 FUN_0035bc00
extern u32 FUN_0035bc00_u32(int param_1,u32 param_2,u32 param_3,int param_4);
extern int FUN_001b9120_u32(void);
#pragma alias FUN_001a91b0_call FUN_001a91b0
#pragma alias fGpffff82d0 uGpffff82d0
extern float fGpffff82d0;
extern void FUN_001a91b0_call(u32 param_1, void *param_2);
#pragma alias FUN_001a91b0_ret FUN_001a91b0
extern u64 FUN_001a91b0_ret(u32 param_1, void *param_2);
extern void FUN_00195020_y2(void);
#pragma alias yRuntimeQueueTween FUN_0045afd0
extern u32 yRuntimeQueueTween(float duration, int stateAddress, int startX, int startY, int endX,
                              int endY, u8 delay, u8 hold, short frameCount);
#pragma alias FUN_0045afd0_call FUN_0045afd0
extern u32 FUN_0045afd0_call(float param_1,int param_2,int param_3,int param_4,int param_5,
                              int param_6,u8 param_7,u8 param_8,short param_9);
#pragma alias FUN_0045afd0_call2 FUN_0045afd0
extern u32 FUN_0045afd0_call2(int param_2,int param_3,int param_4,int param_5,int param_6,
                               u8 param_7,u8 param_8,short param_9,float param_1);
#pragma alias FUN_0045afd0_call3 FUN_0045afd0
extern u32 FUN_0045afd0_call3(int param_2,int param_3,int param_4,int param_5,int param_6,
                               float param_1,u8 param_7,u8 param_8,short param_9);
#pragma alias FUN_0045b620_call FUN_0045b620
extern void FUN_0045b620_call(float param_1,float param_2,float param_3,float param_4,
                              u32 param_5,u8 param_6,int param_7);
#pragma alias FUN_0045b190_arg FUN_0045b190
extern u32 FUN_0045b190_arg(int param_1);
#pragma alias FUN_00439520_arg FUN_00439520
extern void FUN_00439520_arg(int param_1);
#pragma alias FUN_0045bd90_arg FUN_0045bd90
extern void FUN_0045bd90_arg(int param_1);
extern u32 DAT_008717e8_rows[];
#pragma alias DAT_008717f4_rows DAT_008717f4
extern u32 DAT_008717f4_rows[];
#pragma alias DAT_0087190c_rows DAT_0087190c
extern u32 DAT_0087190c_rows[];
extern u32 DAT_008717f0;
#pragma alias DAT_008717f0_abs DAT_008717f0
extern u8 DAT_008717f0_abs[];
extern u32 DAT_008717f4;
extern u32 DAT_0087190c;
extern u32 DAT_0087193a;
extern u32 DAT_0087193b;
extern u32 DAT_0087193c;
extern u32 DAT_00871948;
extern u32 DAT_0087194a;
extern u32 DAT_0087194c;
extern u32 DAT_00871954;
extern u32 DAT_00871958;
extern u32 DAT_008719b0;
extern u32 DAT_0095c0e0;
#pragma alias DAT_0095c0e0_abs DAT_0095c0e0
extern u8 DAT_0095c0e0_abs[];
#pragma alias DAT_0095c0e4_abs DAT_0095c0e4
extern u8 DAT_0095c0e4_abs[];
#pragma alias DAT_0095c0e8_abs DAT_0095c0e8
extern u8 DAT_0095c0e8_abs[];
#pragma alias DAT_0095c0ec_abs DAT_0095c0ec
extern u8 DAT_0095c0ec_abs[];
#pragma alias DAT_0095c0f0_abs DAT_0095c0f0
extern u8 DAT_0095c0f0_abs[];
#pragma alias DAT_0095c0f4_abs DAT_0095c0f4
extern u8 DAT_0095c0f4_abs[];
#pragma alias DAT_0095c0f8_abs DAT_0095c0f8
extern u8 DAT_0095c0f8_abs[];
#pragma alias DAT_0095c0fc_abs DAT_0095c0fc
extern u8 DAT_0095c0fc_abs[];
#pragma alias DAT_0095c100_abs DAT_0095c100
extern u8 DAT_0095c100_abs[];
extern u32 DAT_0095c0e4;
extern u32 DAT_0095c0e8;
extern u32 DAT_0095c0ec;
extern u32 DAT_0095c0f0;
extern u32 DAT_0095c0f4;
extern u32 DAT_0095c0f8;
extern u32 DAT_0095c0fc;
extern u32 DAT_0095c100;
extern u32 DAT_0095c110;
#pragma alias DAT_0095c110_abs DAT_0095c110
extern u8 DAT_0095c110_abs[];
extern u32 DAT_0095c210;
extern u32 DAT_0095c21e;
extern u32 DAT_0095c21f;
extern u32 DAT_0095c220;
extern u32 DAT_0095c221;
extern u32 DAT_0095c23e;
extern u32 DAT_0095c23f;
extern u32 DAT_0095c240;
extern u32 DAT_0095c241;
extern u32 DAT_0095c258;
extern u32 DAT_0095c25c;
extern u32 DAT_0095c260;
extern f32 DAT_00960088;
#pragma alias DAT_00960088_abs DAT_00960088
extern u8 DAT_00960088_abs[];
extern code DAT_00960090;
#pragma alias DAT_00960090_abs DAT_00960090
extern u8 DAT_00960090_abs[];
extern code DAT_009600a0;
extern code DAT_0096017c;
#pragma alias DAT_0087190c_abs DAT_0087190c
#pragma alias DAT_007e094e_abs DAT_007e094e
#pragma alias DAT_007e0952_abs DAT_007e0952
#pragma alias DAT_007e0958_abs DAT_007e0958
#pragma alias DAT_007e095a_abs DAT_007e095a
#pragma alias DAT_007bc730_abs DAT_007bc730
extern u8 DAT_007e094e_abs[];
extern u8 DAT_007e0952_abs[];
extern u8 DAT_007e0958_abs[];
extern u8 DAT_007e095a_abs[];
extern u8 DAT_007bc730_abs[];
#pragma alias DAT_0086e80c_abs DAT_0086e80c
extern u8 DAT_0086e80c_abs[];
#pragma alias DAT_0086e9cc_abs DAT_0086e9cc
extern u8 DAT_0086e9cc_abs[];
#pragma alias DAT_0086eb8c_abs DAT_0086eb8c
extern u8 DAT_0086eb8c_abs[];
#pragma alias DAT_0086ed4c_abs DAT_0086ed4c
extern u8 DAT_0086ed4c_abs[];
#pragma alias DAT_0086e6e8_abs DAT_0086e6e8
extern u8 DAT_0086e6e8_abs[];
#pragma alias DAT_0086e6f4_abs DAT_0086e6f4
extern u8 DAT_0086e6f4_abs[];
#pragma alias FUN_00195020_call FUN_00195020
extern void FUN_00195020_call(u32 param_1);
extern u8 DAT_0087190c_abs[];
#pragma alias DAT_008717e8_abs DAT_008717e8
extern u8 DAT_008717e8_abs[];
#pragma alias DAT_008717f4_abs DAT_008717f4
extern u8 DAT_008717f4_abs[];
#pragma alias DAT_0086ede8_abs DAT_0086ede8
extern u8 DAT_0086ede8_abs[];
#pragma alias DAT_0086edf4_abs DAT_0086edf4
extern u8 DAT_0086edf4_abs[];
#pragma alias DAT_0086ef0c_abs DAT_0086ef0c
#pragma alias DAT_0086ef10_abs DAT_0086ef10
extern u8 DAT_0086ef10_abs[];
#pragma alias DAT_0086ef08_abs DAT_0086ef08
extern u8 DAT_0086ef08_abs[];
extern u8 DAT_0086ef0c_abs[];
typedef struct YVec3f { f32 x, y, z; } YVec3f;
typedef struct YPositionWork {
  u8 pad_000[4];
  u32 resource;
  u8 pad_008[0xe6];
  s16 counter0;
  u8 pad_0f0[4];
  s16 counter1;
} YPositionWork;
#pragma alias DAT_0086ef2c_abs DAT_0086ef2c
extern u8 DAT_0086ef2c_abs[];
#pragma alias DAT_0086ef38_abs DAT_0086ef38
extern u8 DAT_0086ef38_abs[];
#pragma alias DAT_0086ef39_abs DAT_0086ef39
extern u8 DAT_0086ef39_abs[];
#pragma alias DAT_0086ef3a_abs DAT_0086ef3a
extern u8 DAT_0086ef3a_abs[];
#pragma alias DAT_0086ef3c_abs DAT_0086ef3c
extern u8 DAT_0086ef3c_abs[];
#pragma alias DAT_00871948_abs DAT_00871948
extern u8 DAT_00871948_abs[];
#pragma alias FUN_00456410_noarg FUN_00456410
#pragma alias FUN_004c6ac0_vec FUN_004c6ac0
extern float FUN_004c6ac0_vec(const RwV3d *param_1);
#pragma alias FUN_001124b0_u32 FUN_001124b0
extern void FUN_001124b0_u32(u32 param_1);
#pragma alias iGpffffb9fc_ptr iGpffffb9fc
extern u8 *iGpffffb9fc_ptr;
#pragma alias DAT_0096017c_task DAT_0096017c
extern void (*DAT_0096017c_task[])(u32);
#pragma alias FUN_00100ec0_arg FUN_00100ec0
extern void FUN_00100ec0_arg(u32 param_1);
#pragma alias FUN_004d0f00_arg FUN_004d0f00
#pragma alias DAT_0086e6a0_rows DAT_0086e6a0
extern u8 DAT_0086e6a0_rows[][0x1c0];
#pragma alias DAT_0086e6a0_unit_rows DAT_0086e6a0
extern YRuntimeUnitRow DAT_0086e6a0_unit_rows[];
#pragma alias DAT_006b4b20_abs DAT_006b4b20
extern u8 DAT_006b4b20_abs[];
#pragma alias DAT_006b4796_abs DAT_006b4796
extern u8 DAT_006b4796_abs[];
extern void FUN_004d0f00_arg(u32 param_1);
#pragma alias FUN_004d0f00_ptr FUN_004d0f00
extern void FUN_004d0f00_ptr(void *param_1);
#pragma alias FUN_001124b0_ptr FUN_001124b0
extern void FUN_001124b0_ptr(void *param_1);
#pragma alias FUN_00115980_ptr FUN_00115980
extern void FUN_00115980_ptr(void *param_1);
extern void FUN_00456410_noarg(void);
#pragma alias DAT_0096017c_abs DAT_0096017c
extern code DAT_0096017c_abs[];
extern code DAT_00960184;
#pragma alias DAT_00960184_abs DAT_00960184
extern code DAT_00960184_abs[];
#pragma alias FUN_00194b80_u32 FUN_00194b80
extern u32 FUN_00194b80_u32(u64, u32, u8 *, u32 (*)(int), void (*)(int), u32);
#pragma alias FUN_00194b80_u32arg FUN_00194b80
extern u32 FUN_00194b80_u32arg(u32, u32, u8 *, u32 (*)(int), void (*)(int), u32);
extern u32 PTR_DAT_006b46f0;
extern u32 PTR_DAT_006b4720;
extern u32 PTR_DAT_006b4de0;
extern u32 PTR_FUN_006b4e60;
#pragma alias PTR_FUN_006b4e60_abs PTR_FUN_006b4e60
extern code PTR_FUN_006b4e60_abs[];
extern u8 cGpffffb9cc;
extern f32 fGpffff8110;
extern f32 fGpffff8248;
extern f32 fGpffff82d8;
extern u32 gp0xffffae24;
extern u32 gp0xffffb9f7;
extern u32 iGpffffb418;
extern u32 iGpffffb5a0;
extern u32 iGpffffb9fc;
extern u32 iGpffffba08;
extern u32 iGpffffba20;
extern u32 iGpffffba24;
extern float uGpffff82b8;
extern float uGpffff82d0;
extern float uGpffff82d4;
extern u32 uGpffffae20;
extern u32 uGpffffb418;
extern u32 uGpffffb9cc;
extern u32 uGpffffb9dc;
extern u32 uGpffffb9e0;
extern u32 uGpffffb9e4;
extern u32 uGpffffba00;
extern u32 uGpffffba04;
extern u32 uGpffffba08;
extern u32 uGpffffba28;
extern char getCopCondition(int,int);

extern u32 FUN_00100d80(u32 param_1, int param_2);
#pragma alias FUN_00100d80_ptr FUN_00100d80
extern u32 FUN_00100d80_ptr(const char *param_1, int param_2);
extern code FUN_00100ec0;
extern code FUN_001016b0;
#pragma alias FUN_001016b0_typed FUN_001016b0
extern s32 FUN_001016b0_typed(void *cdvd);
extern code FUN_00102100;
#pragma alias FUN_00102100_typed FUN_00102100
extern void *FUN_00102100_typed(void *cdvd, s32 fileIdx, u32 *fileSize);
extern void FUN_001023a0_y2(u32 param_1);
extern int FUN_00108570_y2(void);
extern int FUN_001085c0_y2(void);
extern code FUN_00108670;
#pragma alias FUN_00108670_typed FUN_00108670
extern void FUN_00108670_typed(s16 type);
extern int FUN_00108710_y2(void);
extern code FUN_00108fd0;
#pragma alias FUN_00108fd0_va FUN_00108fd0
extern void FUN_00108fd0_va(u32 value, ...);
extern void FUN_0010a4e0(int param_1, int param_2, int param_3, int param_4);
extern u32 FUN_0010c1a0_y2(int param_1, u32 param_2, int param_3, int param_4,
                        int param_5, int param_6, int param_7, int param_8,
                        int param_9, int param_10, u32 param_11, u32 param_12);
extern u32 FUN_0010c3a0_y2(u32 param_1, int *param_2, int param_3);
extern code FUN_00111f30;
#pragma alias FUN_00111f30_typed FUN_00111f30
extern s32 FUN_00111f30_typed(void *maestroBlob);
#pragma alias FUN_00111f30_long FUN_00111f30
extern s32 FUN_00111f30_long(void *maestroBlob);
extern code FUN_001120c0;
#pragma alias FUN_001120c0_typed FUN_001120c0
extern void FUN_001120c0_typed(void);
extern code FUN_00112370;
#pragma alias FUN_00112370_typed FUN_00112370
extern u32 FUN_00112370_typed(const char *path);
extern code FUN_00112420;
#pragma alias FUN_00112420_typed FUN_00112420
extern void *FUN_00112420_typed(void *source);
extern code FUN_001124b0;
extern code FUN_001126b0;
extern code FUN_00112740;
extern void FUN_001127d0(u32 param_1, u32 param_2);
extern code FUN_00113a30;
#pragma alias FUN_00113a30_va FUN_00113a30
extern void FUN_00113a30_va(f32 first, ...);
extern void FUN_001140d0(u32 param_1, u32 param_2, u32 param_3, u64 param_4, u32 param_5, u32 param_6, u32 param_7);
#pragma alias FUN_001140d0_f3 FUN_001140d0
extern void FUN_001140d0_f3(float param_1, float param_2, float param_3, u32 param_4,
                            u32 param_5, u32 param_6, u32 param_7);
extern u32 FUN_001158b0(int param_1, u32 param_2, u32 param_3);
#pragma alias FUN_00115980_arg FUN_00115980
extern void FUN_00115980(u32 param_1);
extern void FUN_00115980_arg(u32 param_1);
#pragma alias FUN_001159f0_va FUN_001159f0
extern void FUN_001159f0_va(f32 first, ...);
#pragma alias FUN_001159f0_3f FUN_001159f0
extern void FUN_001159f0_3f(f32 x, f32 y, f32 depth);
#pragma alias FUN_001159f0_3fv FUN_001159f0
extern void FUN_001159f0_3fv(f32 x, f32 y, f32 depth, ...);
#pragma alias FUN_00115bc0_3fv FUN_00115bc0
extern void FUN_00115bc0_3fv(f32 x, f32 y, f32 depth, ...);
#pragma alias FUN_00115bc0_3f FUN_00115bc0
extern void FUN_00115bc0_3f(f32 x, f32 y, f32 depth);
extern code FUN_001159f0;
extern code FUN_00115bc0;
#pragma alias FUN_00115bc0_va FUN_00115bc0
extern void FUN_00115bc0_va(f32 first, ...);
extern u8 FUN_0016c470(s16 id);
extern short FUN_0016c4f0_y2(u16 param_1);
extern code FUN_0016c570;
extern code FUN_0016c5f0;
#pragma alias FUN_0016c5f0_typed FUN_0016c5f0
extern u16 FUN_0016c5f0_typed(s16 pcId);
#pragma alias FUN_0016c5f0_u32 FUN_0016c5f0
extern u32 FUN_0016c5f0_u32(s16 pcId);
extern code FUN_0016c920;
#pragma alias FUN_0016c920_typed FUN_0016c920
extern s16 FUN_0016c920_typed(u16 id);
extern u32 FUN_0016c970(u16 param_1);
#pragma alias FUN_0016c970_s32 FUN_0016c970
extern u32 FUN_0016c970_s32(s32 param_1);
extern code FUN_0016cf40;
#pragma alias FUN_0016cf40_typed FUN_0016cf40
extern void FUN_0016cf40_typed(s16 pcId, s16 hp);
extern code FUN_0016cf90;
#pragma alias FUN_0016cf90_typed FUN_0016cf90
extern void FUN_0016cf90_typed(s16 pcId, s16 sp);
extern code FUN_0016f190;
#pragma alias FUN_0016f190_typed FUN_0016f190
extern s32 FUN_0016f190_typed(s32 flag);
extern code FUN_0016f1f0;
#pragma alias FUN_0016f1f0_typed FUN_0016f1f0
extern void FUN_0016f1f0_typed(s32 flag, int enabled);
extern code FUN_0016f490;
#pragma alias FUN_0016f490_typed FUN_0016f490
extern s32 FUN_0016f490_typed(s16 pcId);
extern code FUN_00170a40;
#pragma alias FUN_00170a40_typed FUN_00170a40
extern u16 FUN_00170a40_typed(s16 pcId, s16 index);
extern code FUN_00170ab0;
#pragma alias FUN_00170ab0_typed FUN_00170ab0
extern s16 FUN_00170ab0_typed(s16 pcId, s16 index);
extern code FUN_00170b20;
#pragma alias FUN_00170b20_typed FUN_00170b20
extern void FUN_00170b20_typed(s16 pcId, s16 index, u16 value);
extern code FUN_00170b90;
#pragma alias FUN_00170b90_typed FUN_00170b90
extern void FUN_00170b90_typed(s16 pcId, s16 index, u16 value);
extern int FUN_00173300_y2(void);
extern code FUN_00173380;
#pragma alias FUN_00173380_typed FUN_00173380
extern u16 *FUN_00173380_typed(u16 param_1);
extern code FUN_00177410;
#pragma alias FUN_00177410_typed FUN_00177410
extern void FUN_00177410_typed(u8 *param_1, u8 *param_2);
extern code FUN_0017b500;
#pragma alias FUN_0017b500_ret FUN_0017b500
extern short FUN_0017b500_ret(s16 player, u64 value);
extern s32 FUN_0017b5b0(u32 param_1, u32 param_2);
extern code FUN_0017b660;
#pragma alias FUN_0017b660_2arg FUN_0017b660
extern long FUN_0017b660_2arg(u16 param_1, u16 param_2);
#pragma alias FUN_0017b660_1arg FUN_0017b660
extern long FUN_0017b660_1arg(u16 param_1);
#pragma alias FUN_0017b660_s16 FUN_0017b660
extern s32 FUN_0017b660_s16(s16 param_1);
#pragma alias FUN_0016c570_s16 FUN_0016c570
extern u32 FUN_0016c570_s16(s16 param_1);
extern code FUN_0017b860;
#pragma alias FUN_0017b860_typed FUN_0017b860
extern s32 FUN_0017b860_typed(s16 player, s16 sourcePlayer, u64 id, u64 value);
extern void FUN_0017be10_y2(int param_1, int param_2, u16 param_3, int param_4, void *param_5, void *param_6, void *param_7);
extern code FUN_001831e0;
#pragma alias FUN_001831e0_typed FUN_001831e0
extern void FUN_001831e0_typed(s16 param_1, u32 param_2, int param_3);
extern code FUN_0018bee0;
#pragma alias FUN_0018bee0_typed FUN_0018bee0
extern void FUN_0018bee0_typed(u32 param_1, u16 param_2, int param_3);
extern code FUN_0018c0c0;
#pragma alias FUN_0018c0c0_typed FUN_0018c0c0
extern void FUN_0018c0c0_typed(u32 object, s32 enabled);
extern code FUN_0018eb30;
#pragma alias FUN_0018eb30_typed FUN_0018eb30
extern void FUN_0018eb30_typed(u32 object, s32 enabled);
extern code FUN_00194b20;
#pragma alias FUN_00194b20_u32 FUN_00194b20
extern u32 FUN_00194b20_u32(u64, u8 *, u32, u32 (*)(int), void (*)(int), u32);
extern code FUN_00194b80;
extern code FUN_00195020;
extern long FUN_00195460(u32 param_1);
#pragma alias FUN_00195460_int FUN_00195460
extern int FUN_00195460_int(u32 param_1);
extern code FUN_00198590;
#pragma alias FUN_00198590_typed FUN_00198590
extern int FUN_00198590_typed(void);
extern code FUN_001a0040;
#pragma alias FUN_001a0040_typed FUN_001a0040
extern void FUN_001a0040_typed(u32 visible, u32 updateField);
extern int FUN_001a0250_y2(void);
extern int FUN_001a02c0_y2(void);
extern code FUN_001a0dc0;
#pragma alias FUN_001a0dc0_typed FUN_001a0dc0
extern void FUN_001a0dc0_typed(u16 resTypeId, u32 visible);
extern code FUN_001a5320;
#pragma alias FUN_001a5320_typed FUN_001a5320
extern u32 FUN_001a5320_typed(u32 param_1);
extern code FUN_001a56b0;
#pragma alias FUN_001a56b0_typed FUN_001a56b0
extern void FUN_001a56b0_typed(u32 param_1, int param_2);
extern code FUN_001a56c0;
#pragma alias FUN_001a56c0_typed FUN_001a56c0
extern void FUN_001a56c0_typed(u32 param_1, u32 param_2);
extern code FUN_001a56d0;
#pragma alias FUN_001a56d0_typed FUN_001a56d0
extern void FUN_001a56d0_typed(u32 param_1, void *param_2);
extern code FUN_001a5700;
#pragma alias FUN_001a5700_typed FUN_001a5700
extern void FUN_001a5700_typed(u32 param_1, void *param_2);
extern code FUN_001a57a0;
#pragma alias FUN_001a57a0_typed FUN_001a57a0
extern void FUN_001a57a0_typed(u32 param_1, u32 param_2, u32 param_3);
#pragma alias FUN_001a57a0_f32 FUN_001a57a0
extern void FUN_001a57a0_f32(u32 param_1,float param_2,float param_3);
extern code FUN_001a5aa0;
#pragma alias FUN_001a5aa0_typed FUN_001a5aa0
extern f32 FUN_001a5aa0_typed(const void *matrix);
extern code FUN_001a91b0;
extern code FUN_001a9390;
#pragma alias FUN_001a9390_typed FUN_001a9390
extern void FUN_001a9390_typed(void *task, s32 index, u16 value);
extern code FUN_001a9760;
#pragma alias FUN_001a9760_typed FUN_001a9760
extern void FUN_001a9760_typed(void *task, u32 value, void *position, u32 sound, u32 flags);
extern code FUN_001aaa20;
#pragma alias FUN_001aaa20_typed FUN_001aaa20
extern void *FUN_001aaa20_typed(void *parent, u32 value);
extern code FUN_001aaac0;
#pragma alias FUN_001aaac0_typed FUN_001aaac0
extern void FUN_001aaac0_typed(void *task, u32 value);
extern code FUN_001acc30;
#pragma alias FUN_001acc30_typed FUN_001acc30
extern u32 FUN_001acc30_typed(void *param_1, void *param_2);
extern code FUN_001ad870;
#pragma alias FUN_001ad870_typed FUN_001ad870
extern void FUN_001ad870_typed(void *collisCtlTask, u32 flags);
extern int FUN_001ad910_y2(u32 param_1);
extern int FUN_001ad920_y2(u32 param_1);
extern void FUN_001ad940_y2(void *param_1, u32 param_2);
extern code FUN_001adc20;
#pragma alias FUN_001adc20_typed FUN_001adc20
extern void FUN_001adc20_typed(void *collisCtlTask, const void *position);
extern code FUN_001adff0;
#pragma alias FUN_001adff0_typed FUN_001adff0
extern void FUN_001adff0_typed(void *collisCtlTask, const void *axis, f32 angle);
extern code FUN_001af930;
#pragma alias FUN_001af930_typed FUN_001af930
extern void *FUN_001af930_typed(void *parent, void *resource);
extern code FUN_001afa20;
#pragma alias FUN_001afa20_typed FUN_001afa20
extern u32 FUN_001afa20_typed(f32 duration, void *task, void *position);
extern code FUN_001aff70;
#pragma alias FUN_001aff70_typed FUN_001aff70
extern u32 FUN_001aff70_typed(void *task, s32 duration);
extern code FUN_001b0020;
#pragma alias FUN_001b0020_typed FUN_001b0020
extern void FUN_001b0020_typed(u32 param_1, void *param_2, s32 param_3);
extern void FUN_001b00c0_y2(u32 param_1);
extern code FUN_001b01b0;
#pragma alias FUN_001b01b0_typed FUN_001b01b0
extern u32 *FUN_001b01b0_typed(void *task, s32 index);
extern code FUN_001b01d0;
#pragma alias FUN_001b01d0_typed FUN_001b01d0
extern void FUN_001b01d0_typed(void *task, s32 index, const void *point);
extern long FUN_001b0220_y2(u32 param_1);
extern code FUN_001b0230;
#pragma alias FUN_001b0230_typed FUN_001b0230
extern void FUN_001b0230_typed(void *task, s32 pointCount);
extern void FUN_001b0240_y2(u32 param_1, int param_2);
extern code FUN_001b0250;
#pragma alias FUN_001b0250_typed FUN_001b0250
extern void FUN_001b0250_typed(u32 param_1, int param_2);
extern void FUN_001b0260_y2(u32 param_1, int param_2);
extern code FUN_001b9120;
extern void FUN_001bf220_y2(void *param_1, u16 param_2, u16 param_3);
extern long FUN_001c6450(u32 param_1, u32 param_2, u32 param_3, void *param_4);
 #pragma alias FUN_001c6450_typed FUN_001c6450
 extern u32 FUN_001c6450_typed(u32 param_1,void *param_2,float param_3,float param_4);
 #pragma alias FUN_001c6450_f32 FUN_001c6450
 extern u32 FUN_001c6450_f32(u32 param_1,void *param_2,float param_3,float param_4);
extern code FUN_001c65e0;
#pragma alias FUN_001c65e0_typed FUN_001c65e0
 #pragma alias FUN_001c6720_u32 FUN_001c6720
 extern u32 FUN_001c6720_u32(u32 param_1,u32 param_2);
#pragma alias FUN_001c6720_f32 FUN_001c6720
extern u32 FUN_001c6720_f32(u32 param_1,float param_2);
#pragma alias FUN_001c6720_f32first FUN_001c6720
extern u32 FUN_001c6720_f32first(float param_1,u32 param_2);
extern u32 FUN_001c65e0_typed(void *param_1);
extern long FUN_001c6720(u32 param_1, u32 param_2);
extern code FUN_001c6d70;
extern code FUN_001c6dd0;
#pragma alias FUN_001c6d70_typed FUN_001c6d70
extern long FUN_001c6d70_typed(u32 param_1, void *param_2);
#pragma alias FUN_001c6dd0_typed FUN_001c6dd0
extern long FUN_001c6dd0_typed(u32 param_1, void *param_2);
extern long FUN_001c7130_y2(u32 param_1, u32 param_2);
#pragma alias FUN_001c7160_f32 FUN_001c7160
extern long FUN_001c7160_f32(f32 param_1, void *param_2, void *param_3);
#pragma alias FUN_001c7160_f32_u32 FUN_001c7160
extern u32 FUN_001c7160_f32_u32(f32 param_1, void *param_2, void *param_3);
extern long FUN_001c7160(u32 param_1, void *param_2, void *param_3);
#pragma alias FUN_001c7160_i32 FUN_001c7160
extern int FUN_001c7160_i32(u32 param_1, void *param_2, void *param_3);
#pragma alias FUN_001c7270_typed FUN_001c7270
extern void *FUN_001c7270_typed(void *param_1, f32 param_2);
extern code FUN_001c7b10;
#pragma alias FUN_001c7b10_typed FUN_001c7b10
extern u32 FUN_001c7b10_typed(const void *fldUnit);
extern void FUN_001cd670_y2(u32 param_1, int param_2);
extern code FUN_001d0110;
#pragma alias FUN_001d0110_typed FUN_001d0110
extern void FUN_001d0110_typed(void *unit);
extern code FUN_001d22a0;
#pragma alias FUN_001d22a0_typed FUN_001d22a0
extern void FUN_001d22a0_typed(void *work);
extern void FUN_001d3810_y2(u32 param_1, int param_2);
extern code FUN_001d8b00;
#pragma alias FUN_001d8b00_typed FUN_001d8b00
extern void *FUN_001d8b00_typed(void *parent, void *pc, void *ec);
extern code FUN_001d8c60;
#pragma alias FUN_001d8c60_typed FUN_001d8c60
extern void FUN_001d8c60_typed(u32 paused);
extern long FUN_001d8d80(u32 param_1);
#pragma alias FUN_001d8d80_int FUN_001d8d80
extern int FUN_001d8d80_int(u32 param_1);
extern code FUN_001d8e60;
#pragma alias FUN_001d8e60_typed FUN_001d8e60
extern u32 FUN_001d8e60_typed(void *owner, void *pc, void *ec);
extern code FUN_001dde00;
#pragma alias FUN_001dde00_typed FUN_001dde00
extern u32 FUN_001dde00_typed(s32 mode);
extern code FUN_001ded40;
#pragma alias FUN_001ded40_typed FUN_001ded40
extern s32 FUN_001ded40_typed(s32 charId);
extern void FUN_001e1360_y2(u32 param_1, int param_2);
extern code FUN_001e13c0;
#pragma alias FUN_001e13c0_typed FUN_001e13c0
extern f32 FUN_001e13c0_typed(void);
extern code FUN_00269690;
#pragma alias FUN_00269690_typed FUN_00269690
extern u32 FUN_00269690_typed(s32 mode, s32 index, u32 flags);
extern code FUN_002699a0;
#pragma alias FUN_002699a0_typed FUN_002699a0
extern void FUN_002699a0_typed(u32 param_1);
extern code FUN_002699d0;
#pragma alias FUN_002699d0_typed FUN_002699d0
extern void FUN_002699d0_typed(u32 param_1);
extern code FUN_00269a10;
#pragma alias FUN_00269a10_typed FUN_00269a10
extern void FUN_00269a10_typed(u32 param_1, void *param_2);
extern code FUN_00269c80;
extern code FUN_00269ca0;
extern code FUN_002ff340;
#pragma alias FUN_002ff340_typed FUN_002ff340
extern void *FUN_002ff340_typed(u16 pcId);
extern code FUN_002ff760;
extern code FUN_002ff790;
#pragma alias FUN_002ff790_typed FUN_002ff790
extern u32 FUN_002ff790_typed(void *genusBase);
extern code FUN_00316e00;
#pragma alias FUN_00316e00_typed FUN_00316e00
extern u32 FUN_00316e00_typed(u16 type, u16 id, u32 readMode);
extern code FUN_00316f70;
#pragma alias FUN_00316f70_typed FUN_00316f70
extern s32 FUN_00316f70_typed(s32 param_1);
extern code FUN_003174e0;
extern u64 FUN_003182d0_y2(u32 param_1, u32 param_2, u64 param_3, u64 param_4, u64 param_5);
extern code FUN_00318540;
#pragma alias FUN_00318540_typed FUN_00318540
extern s16 FUN_00318540_typed(void *mdl, u16 slotIdx);
extern int FUN_00318b60_y2(u32 param_1);
extern code FUN_00318ed0;
#pragma alias FUN_00318ed0_typed FUN_00318ed0
extern s32 FUN_00318ed0_typed(u32 param_1, int param_2, float *param_3);
extern code FUN_0031c1d0;
#pragma alias FUN_0031c1d0_typed FUN_0031c1d0
extern void FUN_0031c1d0_typed(u32 model);
extern code FUN_0035bb40;
#pragma alias FUN_0035bb40_typed FUN_0035bb40
extern u32 FUN_0035bb40_typed(s32 type, u32 list, s32 index);
extern code FUN_0035bc00;
extern code FUN_0035c1a0;
#pragma alias FUN_0035c1a0_typed FUN_0035c1a0
extern void FUN_0035c1a0_typed(u32 task, s32 value);
extern code FUN_003952d0;
#pragma alias FUN_003952d0_typed FUN_003952d0
extern u64 FUN_003952d0_typed(u64 param_1, int param_2, s16 param_3);
extern code FUN_003b2cb0;
#pragma alias FUN_003b2cb0_va FUN_003b2cb0
extern void FUN_003b2cb0_va(f32 first, ...);
extern code FUN_003b5d10;
#pragma alias FUN_003b5d10_eb90 FUN_003b5d10
extern u32 FUN_003b5d10_eb90(u32 param_1);
extern code FUN_003b5d50;
#pragma alias FUN_003b5d50_typed FUN_003b5d50
extern void *FUN_003b5d50_typed(u32 resType);
extern code FUN_003b6030;
#pragma alias FUN_003b6030_typed FUN_003b6030
extern u16 FUN_003b6030_typed(u16 resId, s32 param_2, void *mdl);
extern code FUN_003b7090;
extern code FUN_003bb010;
#pragma alias FUN_003bb010_typed FUN_003bb010
extern u32 FUN_003bb010_typed(u64 param_1, u32 param_2);
extern code FUN_003c72d0;
extern code FUN_003c7430;
extern code FUN_003c74e0;
extern code FUN_003c7560;
extern code FUN_003c75b0;
extern code FUN_003c77a0;
extern code FUN_003c7850;
extern code FUN_003c78d0;
extern code FUN_003c7b90;
extern float FUN_00421fe0(int param_1, int param_2, int param_3, u16 param_4, int param_5);
#pragma alias FUN_00421fe0_s16 FUN_00421fe0
extern float FUN_00421fe0_s16(int param_1, int param_2, int param_3, s16 param_4, int param_5);
extern float FUN_004221a0_y2(float param_1, float param_2, float param_3, float param_4, int param_5);
extern code FUN_004222d0;
#pragma alias FUN_004222d0_typed FUN_004222d0
extern void FUN_004222d0_typed(float *param_1,char param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,short param_8);
#pragma alias FUN_004222d0_s16_counter FUN_004222d0
extern void FUN_004222d0_s16_counter(float *param_1, char param_2, int param_3, int param_4,
                 int param_5, int param_6, s16 param_7, short param_8);
extern u32 FUN_004229d0_y2(int param_1, u64 param_2, int param_3);
extern void FUN_00422c10_y2(u32 param_1, int param_2);
extern void FUN_00422c30_y2(u32 param_1, u64 param_2, void *param_3);
extern void FUN_00422c90_y2(u32 param_1, int param_2, int param_3, int param_4, int param_5);
extern code FUN_00423fe0;
#pragma alias FUN_00423fe0_typed FUN_00423fe0
extern void FUN_00423fe0_typed(float *param_1, char param_2, short param_3, short param_4, short param_5, short param_6);
extern code FUN_00427830;
#pragma alias FUN_00427830_typed FUN_00427830
extern u32 FUN_00427830_typed(float param_1,int param_2,u32 param_3,u64 param_4,u32 param_5,
                               char *param_6,char *param_7,int param_8);
extern code FUN_00427a10;
#pragma alias FUN_00427a10_typed FUN_00427a10
extern u32 FUN_00427a10_typed(float param_1,int param_2,u32 param_3,u64 param_4,u32 param_5,
                               char *param_6,char *param_7,int param_8);
extern code FUN_00427db0;
#pragma alias FUN_00427db0_typed FUN_00427db0
extern void FUN_00427db0_typed(int object, u64 value);
extern code FUN_00427de0;
#pragma alias FUN_00427de0_typed FUN_00427de0
extern void FUN_00427de0_typed(int param_1,u8 param_2,u8 param_3,u8 param_4, u8 param_5);
extern code FUN_00427e20;
#pragma alias FUN_00427e20_typed FUN_00427e20
extern void FUN_00427e20_typed(float param_1,float param_2,u32 param_3);
extern void FUN_00427e50_y2(u32 param_1, int param_2);
extern code FUN_00427e60;
#pragma alias FUN_00427e60_typed FUN_00427e60
extern void FUN_00427e60_typed(int param_1, u8 param_2);
extern code FUN_00427e70;
#pragma alias FUN_00427e70_typed FUN_00427e70
extern void FUN_00427e70_typed(float param_1,u32 param_4,float param_2,float param_3,int param_5,
                               int param_6,u32 param_7);
extern code FUN_00429e80;
#pragma alias FUN_00429e80_typed FUN_00429e80
extern void FUN_00429e80_typed(int param_1, u8 param_2);
extern int FUN_00488f30_y2(void);
extern code FUN_004c31b0;
#pragma alias FUN_004c31b0_ym FUN_004c31b0
extern void FUN_004c31b0_ym(f32 angle, void *matrix, const void *axis, u32 mode);
extern code FUN_004c3880;
#pragma alias FUN_004c3880_typed FUN_004c3880
extern void FUN_004c3880_typed(u32 param_1);
extern code FUN_004c38c0;
#pragma alias FUN_004c38c0_typed FUN_004c38c0
extern u32 FUN_004c38c0_typed(void);
extern float FUN_004c69f0_y2(float *param_1, float *param_2);
extern code FUN_004c6ac0;
extern code FUN_004c6be0;
#pragma alias FUN_004c6be0_typed FUN_004c6be0
extern void FUN_004c6be0_typed(float *out, const float *basis, void *source);
extern code FUN_004d0f00;
extern u32 FUN_004d1260(u32 param_1, int param_2);
#pragma alias FUN_004d1260_ptr FUN_004d1260
extern u32 FUN_004d1260_ptr(const char *param_1, int param_2);
extern code FUN_004d7f60;
#pragma alias FUN_004d7f60_typed FUN_004d7f60
extern void FUN_004d7f60_typed(u32 param_1, u32 param_2);
extern code FUN_00521250;
#pragma alias FUN_00521250_typed FUN_00521250
extern void FUN_00521250_typed(void *destination, const void *source, u32 size);
extern code FUN_00521408;
extern code FUN_00523e68;
extern code FUN_00524388;
#pragma alias FUN_00524388_str FUN_00524388
extern u32 FUN_00524388_str(const char *param_1);
extern code FUN_00524670;
#pragma alias FUN_00524670_typed FUN_00524670
extern int FUN_00524670_typed(u64 param_1, u8 (*param_2)[16], u32 param_3);
extern void FUN_00524828(void *param_1, void *param_2, int param_3);
#pragma alias FUN_00524828_u64 FUN_00524828
extern void FUN_00524828_u64(void *param_1,u64 param_2,int param_3);
extern code FUN_0052e878;
extern code FUN_0052ea18;
#pragma alias FUN_00269c80_f32 FUN_00269c80
extern f32 FUN_00269c80_f32(f32 value);
#pragma alias FUN_00269ca0_f32 FUN_00269ca0
extern f32 FUN_00269ca0_f32(f32 value);
#pragma alias FUN_0052ea18_f32 FUN_0052ea18
extern f32 FUN_0052ea18_f32(f32 x, f32 y);

char FUN_00435440(char param_1);
char FUN_0043bc20(char param_1);
float FUN_0045b4e0(int param_1);
float FUN_004693a0(int param_1);
float FUN_0047cfd0(u32 *param_1,u8 (*param_2) [12],u8 (*param_3) [12], int param_4,int param_5);
float FUN_004a9560(float param_1,int param_2,u8 *param_3);
float FUN_004aa2c0(void);
int * FUN_00496cd0(u32 param_1,u32 *param_2,u64 param_3,u16 *param_4);
int * FUN_004ac120(int *param_1,u64 param_2);
int * FUN_004ac240(int *param_1);
int FUN_0044f120(RwV3d param_1);
int FUN_0044f170(RwV3d param_1);
int FUN_00457410(void);
int FUN_0045edd0(u32 *param_1);
int FUN_0045f540(int param_1,int param_2);
int FUN_00465b40(int param_1);
int FUN_00468350(int param_1);
int FUN_0046ad20(int *param_1,int param_2);
int FUN_0046b060(int param_1,u32 *param_2,int param_3);
int FUN_004753d0(int param_1,u32 param_2);
int FUN_00475540(int param_1,u64 param_2,u64 param_3,u32 param_4);
int FUN_00489320(int *param_1);
int FUN_00489ae0(int param_1);
int FUN_0048a7a0(int param_1);
int FUN_0048d200(int param_1);
int FUN_0048e4f0(long param_1);
int FUN_0048e890(int *param_1,long param_2,u64 param_3,int param_4);
int FUN_0048ed20(int param_1,int param_2);
int FUN_0048ede0(int param_1);
int FUN_0048ee30(int param_1,int param_2);
int FUN_004912b0(int param_1);
int FUN_00491cc0(int param_1);
int FUN_00492f80(int param_1,int param_2);
int FUN_00493cb0(u64 param_1);
int FUN_00495340(int *param_1,int param_2);
int FUN_004964f0(int param_1,char *param_2);
int FUN_00499400(int param_1,u64 param_2,int param_3,int param_4);
int FUN_0049c560(int param_1);
int FUN_0049c5c0(int param_1);
int FUN_0049c620(int param_1);
int FUN_0049d4d0(int param_1,int param_2,int *param_3,int *param_4,int *param_5,int *param_6);
int FUN_0049ecd0(int param_1);
int FUN_0049f340(int param_1);
int FUN_004a0ce0(int param_1,int *param_2,int param_3,u32 param_4);
int FUN_004a26d0(int param_1,int *param_2,int param_3,u32 param_4);
int FUN_004a5200(void);
int FUN_004a5290(void);
int FUN_004a5320(void);
int FUN_004a6630(int param_1,float *param_2,int param_3,int *param_4,int *param_5);
int FUN_004ab0e0(u64 param_1);
int FUN_004ace80(int param_1,float *param_2,u64 param_3,u32 *param_4,int *param_5);
long FUN_0045ec40(u16 param_1,u16 param_2,u32 *param_3,u32 param_4);
long FUN_0045efe0(u64 param_1);
long FUN_0045f140(u64 param_1,u16 param_2,u16 param_3,u64 param_4, u32 *param_5);
long FUN_00464280(u32 param_1);
long FUN_00464540(u64 param_1);
long FUN_00467c20(long param_1,u64 param_2,int param_3);
long FUN_0046bab0(long param_1,u64 param_2);
long FUN_0046bd00(long param_1,u64 param_2);
long FUN_0046bfb0(float param_1,long param_2,u8 *param_3,float *param_4,u32 param_5);
long FUN_00474260(u32 param_1,u32 param_2,u64 param_3,u64 param_4);
long FUN_00475d60(u64 param_1,u64 param_2,u64 param_3,u32 param_4, u32 param_5);
long FUN_0047ab70(void);
long FUN_0047b1a0(void);
long FUN_0047bb40(int param_1,int param_2,u32 param_3);
long FUN_0048a9a0(long param_1,u64 param_2);
long FUN_0048af80(u32 param_1);
long FUN_0048dab0(int param_1,long param_2,u64 param_3);
long FUN_00490050(u64 param_1);
long FUN_00490dc0(u64 param_1,int *param_2,int *param_3);
long FUN_00491880(void);
long FUN_00491b40(u64 param_1);
long FUN_00491de0(void);
long FUN_004920a0(u64 param_1);
long FUN_00494580(u64 param_1);
long FUN_004947c0(u8 param_1);
long FUN_00494be0(void);
long FUN_00494e30(u64 param_1);
long FUN_004954c0(u64 param_1,long param_2);
long FUN_00495b10(long param_1);
long FUN_00496230(u64 param_1,char *param_2,u32 param_3);
long FUN_00497130(u64 param_1,long param_2,u64 param_3,u64 param_4,long param_5);
long FUN_00498e70(int param_1);
long FUN_00499140(long param_1,u32 param_2);
long FUN_0049a080(long param_1);
long FUN_0049a400(u32 *param_1);
long FUN_0049c810(void);
long FUN_0049fe40(long param_1,int param_2,long param_3);
long FUN_0049fec0(long param_1,u32 param_2);
long FUN_004a35c0(long param_1,long param_2,u32 param_3);
long FUN_004a38f0(long param_1,long param_2,long param_3,long param_4);
long FUN_004a3a80(long param_1,long param_2,long param_3,long param_4);
long FUN_004a3c10(long param_1,long param_2,long param_3);
long FUN_004a3d70(long param_1,u32 param_2);
long FUN_004a3db0(long param_1,long param_2,long param_3);
long FUN_004a3e30(long param_1,int param_2,long param_3);
long FUN_004a5470(void);
long FUN_004a6ce0(u32 param_1,long param_2,u8 *param_3,u32 *param_4, u64 param_5);
long FUN_004a6eb0(float param_1,long param_2,u8 *param_3,float *param_4,float *param_5);
long FUN_004a7820(long param_1,u64 param_2,u32 param_3,u32 param_4);
long FUN_004a9490(long param_1);
long FUN_004a98a0(u64 param_1);
long FUN_004ac570(void);
long FUN_004ac5f0(long param_1);
long FUN_004ac710(long param_1);
long FUN_004acb90(u64 param_1);
long FUN_004aeea0(u64 param_1);
long FUN_004af210(int *param_1,int *param_2,u32 param_3,u64 param_4);
short * FUN_00496e80(int param_1,short param_2,short param_3);
short FUN_0043b980(char param_1,u64 param_2);
short FUN_0043bda0(char param_1,char param_2);
u16 FUN_00435660(char param_1);
short FUN_0043c180(char param_1);
short FUN_0043c340(char param_1);
short FUN_00453460(void);
u32 * FUN_0048f580(u64 param_1,int *param_2,int param_3,u32 param_4);
u32 * FUN_0048fbd0(u64 param_1,u64 param_2,u64 param_3,u32 param_4);
u32 * FUN_004a7e40(u32 *param_1,u32 param_2,u32 param_3,char *param_4);
u32 * FUN_004a8980(u32 *param_1,u64 param_2,u32 param_3,u64 param_4);
u32 * FUN_004a90f0(void);
u32 * FUN_004a9a80(u64 param_1);
u32 * FUN_004ab8c0(void);
u32 FUN_00431880(int param_1);
u32 FUN_00431aa0(int param_1);
u32 FUN_00432050(int param_1);
u32 FUN_00432600(int param_1);
u32 FUN_00432bb0(int param_1);
u32 FUN_00433160(int param_1);
u32 FUN_00433810(char param_1,char param_2);
u32 FUN_004339d0(int param_1);
u32 FUN_00433de0(int param_1);
u32 FUN_00434770(float param_1,float param_2,int param_3,float *param_4);
u32 FUN_00434920(float param_1,float param_2,int param_3,float *param_4);
u32 FUN_004352e0(void);
u32 FUN_00437e20(char param_1);
u32 FUN_0043a230(char param_1);
u32 FUN_0043a9d0(u64 param_1,u64 param_2,char param_3);
u32 FUN_0043c500(int param_1);
u32 FUN_0043c910(char param_1);
u32 FUN_0043ca30(int param_1);
u32 FUN_00449fe0(float param_1,float param_2,float param_3,float param_4,int param_5,short param_6);
u32 FUN_0044a110(float param_1,float param_2,float param_3,float param_4,int param_5,short param_6);
u32 FUN_0044f300(char param_1);
u32 FUN_0044ffb0(int param_1);
u32 FUN_004514a0(char param_1);
u32 FUN_004523c0(u64 param_1,char param_2);
u32 FUN_00452a70(char param_1,char param_2);
u32 FUN_004534b0(char param_1);
u32 FUN_00453ed0(char param_1,char param_2,char param_3,u32 *param_4,char param_5,char param_6);
u32 FUN_004541f0(int param_1);
u32 FUN_00457470(int param_1);
u32 FUN_004575e0(int param_1);
u32 FUN_004589e0(void);
u32 FUN_00458a80(char param_1,char param_2);
u32 FUN_00458cb0(u64 param_1,char param_2,char param_3);
u32 FUN_00459790(u64 param_1,char param_2);
u32 FUN_00459e00(char param_1);
u32 FUN_00459e80(int param_1);
u32 FUN_0045a020(int param_1);
u32 FUN_0045a280(u32 param_1,u32 param_2);
u32 FUN_0045af40(void);
u32 FUN_0045afd0(float param_1,int param_2,int param_3,int param_4,int param_5,int param_6, u8 param_7,u8 param_8,short param_9);
u32 FUN_0045b190(int param_1);
u32 FUN_0045b420(int param_1,float *param_2);
u32 FUN_0045df00(int param_1);
u32 FUN_0045e3e0(int param_1);
u32 FUN_0045e8c0_y2(u64 param_1);
u32 FUN_0045eaf0(void);
u32 FUN_0045eba0(void);
u32 FUN_00465590(int param_1,u64 param_2);
u32 FUN_00466710(int param_1);
u32 FUN_00466720(int param_1);
u32 FUN_00466730(u32 *param_1);
u32 FUN_00469030(int param_1);
u32 FUN_00469340(int param_1);
u32 FUN_004695f0(int param_1);
u32 FUN_00469650(int param_1);
u32 FUN_004696b0(int param_1);
u32 FUN_00469710(int param_1);
u32 FUN_004698e0(int param_1);
u32 FUN_00469a90(void);
u32 FUN_00469ce0(void);
u32 FUN_00469cf0(void);
u32 FUN_0046a6c0(int param_1,u64 param_2,u64 param_3,u64 param_4);
u32 FUN_0046a6f0(int param_1,u64 param_2,u64 param_3,u64 param_4);
u32 FUN_0046a720(int param_1,u64 param_2,u64 param_3,u64 param_4);
u32 FUN_0046a750(u64 param_1);
u32 FUN_0046a890(u64 param_1);
u32 FUN_0046eb10(int param_1,u32 *param_2);
u32 FUN_00473600(int *param_1,u32 param_2);
u32 FUN_00473b10(int *param_1,u32 param_2);
u32 FUN_00473fb0(u32 param_1);
u32 FUN_00474640(int param_1,int *param_2,u32 param_3,u32 param_4);
u32 FUN_00474a80(int param_1);
u32 FUN_00478440(int param_1,u32 *param_2);
u32 FUN_00478e80(u64 param_1,u32 param_2);
u32 FUN_00479840(int param_1,u32 *param_2);
u32 FUN_0047a210(u64 param_1,int param_2);
u32 FUN_0047a510(u64 param_1,u64 param_2,u64 param_3,u32 param_4);
u32 FUN_0047abf0(int param_1,u32 *param_2);
u32 FUN_0047bd20(u64 param_1);
u32 FUN_0047de30(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5);
u32 FUN_0047e9e0(u32 *param_1,float *param_2,float *param_3,int param_4,int param_5);
u32 FUN_0047fb10(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5);
u32 FUN_00480c30(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5);
u32 FUN_00481860(u32 *param_1,float *param_2,float *param_3,int param_4,int param_5);
u32 FUN_00482a50(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5);
u32 FUN_00483170(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5);
u32 FUN_004861b0(u64 param_1,u64 param_2,u32 param_3,u32 param_4);
u32 FUN_00486340(u32 param_1,int param_2,u32 param_3);
u32 FUN_00489020(int param_1);
u32 FUN_00489550(int *param_1,int param_2,long param_3,int param_4,long param_5,long param_6, long param_7,long param_8);
u32 FUN_004899f0(u64 param_1);
u32 FUN_00489a80(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
u32 FUN_0048a1a0(void);
u32 FUN_0048a2c0(int param_1);
u32 FUN_0048a3d0(u32 *param_1);
u32 FUN_0048a3e0(int param_1);
u32 FUN_0048a480(int param_1);
u32 FUN_0048abf0(void);
u32 FUN_0048ac00(void);
u32 FUN_0048da30(u64 param_1);
u32 FUN_0048ef30(int param_1);
f32 FUN_0048ef60(int param_1, int param_2);
u32 FUN_0048ef80(int param_1,int param_2);
int FUN_0048efe0(int param_1);
u32 FUN_00491a80(u64 param_1);
u32 FUN_00491ea0(u64 param_1);
u32 FUN_00492d50(u64 param_1);
u32 FUN_00493b60(u64 param_1);
u32 FUN_00494760(u64 param_1);
u32 FUN_00494cc0(u64 param_1);
u32 FUN_00495320(int *param_1,int param_2);
u32 FUN_00495c20(u64 param_1);
u32 FUN_00495c80(int *param_1);
u32 FUN_00497600(int param_1,u32 param_2,int *param_3,int param_4);
u32 FUN_004982b0(int *param_1,long param_2);
u32 FUN_00498e40(long param_1,long param_2);
u32 FUN_00499c20(code *param_1,u64 param_2);
u32 FUN_0049a170(u32 param_1);
u32 FUN_0049a290(int param_1);
u32 FUN_0049aeb0(u64 param_1);
u32 FUN_0049af20(int *param_1);
u32 FUN_0049c230(int param_1);
u32 FUN_0049c790(void);
u32 FUN_0049c7a0(u64 param_1,u32 *param_2);
u32 FUN_0049c8c0(void);
u32 FUN_0049cc70(int param_1);
u32 FUN_0049e6c0(int param_1);
u32 FUN_0049e780(int param_1);
u32 FUN_0049f5d0(int param_1,u32 *param_2);
u32 FUN_004a09d0(u64 param_1,u32 *param_2);
u32 FUN_004a1430(int param_1);
u32 FUN_004a2bb0(int param_1);
u32 FUN_004a4060(int param_1,int *param_2);
u32 FUN_004a42f0(int param_1);
u32 FUN_004a4f90(int param_1);
u32 FUN_004a5080(int param_1);
u32 FUN_004a5210(void);
u32 FUN_004a52a0(void);
u32 FUN_004a5330(void);
u32 FUN_004a5400(void);
u32 FUN_004a5540(u64 param_1);
u32 FUN_004a9330(void);
u32 FUN_004a9550(u32 param_1);
u32 FUN_004a96b0(int param_1);
u32 FUN_004a9bf0(void);
u32 FUN_004a9d80(float *param_1,float *param_2,float *param_3);
u32 FUN_004a9f20(float param_1,float param_2,float param_3,float param_4);
u32 FUN_004aa410(int param_1);
u32 FUN_004aa540(void);
u32 FUN_004aa6c0(void);
u32 FUN_004aada0(u32 param_1,u32 param_2);
u32 FUN_004aae00(u32 param_1,u32 param_2);
u32 FUN_004ab0c0(void);
u32 FUN_004ac870(void);
u32 FUN_004adb80(void);
u32 FUN_004ae010(int param_1);
u32 FUN_004ae8f0(int param_1);
u32 FUN_004ae900(int param_1);
u32 FUN_004af130(u64 param_1);
u32 FUN_00430180(u64 param_1);
u64 FUN_00430060(int param_1);
u64 FUN_00430bb0(int param_1);
u32 FUN_00431110(u64 param_1,YajimaVec2 param_2,char param_3,u8 param_4);
u64 FUN_004312b0_y2(int param_1);
u32 FUN_00431670(int param_1,char param_2,u32 param_3);
u64 FUN_00439f60(int param_1,char param_2);
u64 FUN_0043a0b0(u64 param_1,char param_2);
u32 FUN_0043c690_y2(u32 param_1);
u32 FUN_00447e70(u64 param_1,u8 param_2,u8 param_3);
u64 FUN_0044aaf0(int param_1);
u32 FUN_0044ad20(u64 param_1,char param_2);
u32 FUN_0044e560(int param_1);
u32 FUN_004542c0(char param_1);
u64 FUN_00454620(char param_1);
u32 FUN_00455e00(u32 param_1);
u32 FUN_004560d0(u64 param_1,float param_2,float param_3,u32 param_5,u32 param_6,float param_4);
u32 FUN_004579b0_y2(u64 param_1);
u64 FUN_00457a40(u64 param_1);
u32 FUN_00458630(u64 param_1,char param_2,u8 param_3);
u32 FUN_00459f60(u64 param_1,u16 param_2,char param_3);
u64 FUN_0045ee00(u64 param_1,u64 param_2);
u64 FUN_0045f4e0(u64 param_1,int param_2);
u64 FUN_0045f580(u64 param_1,u64 param_2,int param_3,int param_4);
u64 FUN_0045f600(u64 param_1,u64 param_2,char *param_3,int param_4);
u64 FUN_00464020(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
u64 FUN_00464120(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
u64 FUN_004643b0(u64 param_1,int param_2,u32 param_3);
u64 FUN_004654a0(u64 param_1,u64 param_2);
u64 FUN_00465930(u64 param_1,u64 param_2);
u64 FUN_00465a00(u64 param_1);
u64 FUN_00465ae0(u64 param_1);
u64 FUN_00465bf0(u64 param_1,int param_2);
u64 FUN_00465cf0(u64 param_1,u64 param_2,int param_3);
u64 FUN_00465eb0(u64 param_1,u64 param_2,u32 param_3);
u64 FUN_00466260(u32 param_1,u32 *param_2,u32 *param_3,u32 param_4,u64 param_5);
u64 FUN_004663d0(u64 param_1);
u64 FUN_00466480(u32 param_1,int param_2,u32 param_3,u64 param_4);
u64 FUN_00466640(u64 param_1);
u64 FUN_00466ef0(u32 *param_1);
u64 FUN_00467590(u64 param_1);
u64 FUN_00467600(u64 param_1);
u64 FUN_004676c0(u64 param_1);
u64 FUN_004677f0(u64 param_1);
u64 FUN_00467860(u64 param_1,u64 param_2);
u64 FUN_00467b40(u64 param_1,int *param_2);
u64 FUN_00467fd0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00468560(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00468690(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_004687e0(long param_1,int *param_2);
u64 FUN_00468dc0(u64 param_1);
u64 FUN_00468e30(u64 param_1);
u64 FUN_00468ea0(u64 param_1,int param_2);
u64 FUN_00469060(u64 param_1,long param_2);
u64 FUN_00469280(u64 param_1,u32 param_2);
u64 FUN_004692e0(float param_1,u64 param_2);
u64 FUN_00469400(u64 param_1,int param_2);
u64 FUN_004694b0(u64 param_1,u32 param_2);
u64 FUN_00469510(u64 param_1,u32 param_2);
u64 FUN_00469590(u32 param_1,u64 param_2);
u64 FUN_00469770(u64 param_1,int param_2);
u64 FUN_00469840(u64 param_1,u32 param_2,u32 param_3);
u64 FUN_00469940(u64 param_1,u32 *param_2,u32 *param_3);
u64 FUN_004699b0(u64 param_1,u32 param_2,u32 param_3);
u64 FUN_00469a10(u64 param_1,long param_2,long param_3);
u64 FUN_00469d00(u64 param_1);
u64 FUN_00469d60(u64 param_1);
u64 FUN_00469e30(u64 param_1,int param_2);
u64 FUN_00469fe0(u64 param_1);
u64 FUN_0046a040(u64 param_1,int param_2);
u64 FUN_0046a0f0(u64 param_1,u64 param_2,int param_3);
u64 FUN_0046a230(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_0046a470(u64 param_1,int param_2);
u64 FUN_0046a600(u64 param_1);
u64 FUN_0046a660(u64 param_1);
u64 FUN_0046a830(u64 param_1);
u64 FUN_0046a970(u64 param_1,int param_2);
u64 FUN_0046aa80(u64 param_1,u32 *param_2);
u64 FUN_0046ac30(u64 param_1);
u64 FUN_0046ad80(u32 *param_1);
u64 FUN_0046afa0(u32 *param_1);
u64 FUN_0046b8e0(int param_1);
u64 FUN_0046c330(u64 param_1,u32 param_2);
u64 FUN_0046c5b0(int param_1);
u64 FUN_0046cd90(int param_1);
u64 FUN_0046d6f0(int param_1);
u64 FUN_0046e170(int param_1);
u64 FUN_0046eb90(int param_1,u32 *param_2);
u64 FUN_0046f400(u32 *param_1,u32 *param_2);
u64 FUN_0046fdd0(int param_1);
u64 FUN_00470200(float *param_1,float *param_2);
u64 FUN_004709e0(int param_1);
u64 FUN_00470e10(u32 *param_1,u32 *param_2);
u64 FUN_00471470(int param_1);
u64 FUN_004718a0(int param_1,u32 *param_2);
u64 FUN_00472270(int param_1);
u64 FUN_00472970(int param_1);
u64 FUN_004733c0(int param_1,int param_2);
u64 FUN_004734d0(u64 param_1);
u64 FUN_00474160(u64 param_1);
u64 FUN_004747f0(u64 param_1);
u64 FUN_00474820(int param_1,long param_2,u32 param_3);
u64 FUN_004748c0(int param_1,long param_2);
u64 FUN_004749a0(int param_1,long param_2);
u64 FUN_00474bb0(u64 param_1);
u64 FUN_00474c60(u64 param_1);
u64 FUN_00478520(int param_1);
u64 FUN_00478a70(void);
u64 FUN_00479900(int param_1);
u64 FUN_00479e50(void);
u64 FUN_0047a710(u64 param_1,int *param_2);
u64 FUN_0047b280(u64 param_1,float *param_2,u32 param_3,u8 *param_4);
u64 FUN_0047b750(u64 param_1,float *param_2,u32 param_3,float *param_4);
u64 FUN_0047be10(int param_1,int param_2,u64 param_3);
u64 FUN_00488cd0(u64 param_1);
u64 FUN_00488d40(u64 param_1);
u64 FUN_00489080(u64 param_1,int *param_2);
u64 FUN_00489160(u64 param_1,long param_2);
u64 FUN_00489730(u64 param_1);
u64 FUN_00489840(u64 param_1);
u64 FUN_004898e0(u64 param_1);
u64 FUN_00489960(u64 param_1);
u64 FUN_00489b70(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00489cd0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00489f20(u64 param_1,u64 param_2,int param_3,u64 param_4,u64 param_5);
u64 FUN_0048a2a0(u64 param_1,u32 param_2);
u64 FUN_0048a2e0(u64 param_1,int param_2);
u64 FUN_0048a370(u64 param_1);
u64 FUN_0048a4b0(u64 param_1);
u64 FUN_0048a790(u64 param_1);
u64 FUN_0048a800(u64 param_1,int param_2);
u64 FUN_0048ac10(u64 param_1,long param_2);
u64 FUN_0048b910(u64 param_1,float *param_2);
u64 FUN_0048cf00(u64 param_1);
u64 FUN_0048cfa0(u64 param_1);
u64 FUN_0048d0e0(u64 param_1);
u64 FUN_0048d270(int param_1,int param_2,u64 param_3);
u64 FUN_0048d370(u64 param_1,int param_2,u32 *param_3);
u64 FUN_0048d480(float param_1,int param_2,long param_3,u64 param_4,long param_5);
u64 FUN_0048d960(u64 param_1);
u64 FUN_0048e020(int *param_1,u64 param_2);
u64 FUN_0048e2d0(int *param_1,u64 param_2);
u64 FUN_0048e750(long param_1,u64 param_2);
u64 FUN_0048eab0(u64 param_1,int param_2);
u64 FUN_0048eb50(u64 param_1,int param_2,int param_3);
u64 FUN_0048ec20(u64 param_1,u64 param_2,int param_3,int param_4);
u64 FUN_0048ecf0(u64 param_1,u64 param_2,int param_3,int param_4);
u64 FUN_0048f340(u64 param_1,int param_2);
u64 FUN_0048f3c0(u64 param_1,u64 param_2,int param_3);
u64 FUN_0048f460(u64 param_1,int param_2);
u64 FUN_0048f4e0(u64 param_1,u64 param_2,int param_3);
u64 FUN_00490770(u64 param_1,u64 param_2,int param_3);
u64 FUN_00490810(u64 param_1);
u64 FUN_00490860(u64 param_1);
u64 FUN_004908d0(u64 param_1,int param_2);
u64 FUN_00490980(u64 param_1,u64 param_2);
u64 FUN_00490d00(u64 param_1);
u64 FUN_00490d40(u64 param_1);
u64 FUN_00490d90(u64 param_1);
u64 FUN_00491410(u64 param_1);
u64 FUN_004914d0(u64 param_1,int param_2);
u64 FUN_00491630(u64 param_1);
u64 FUN_004916d0(u64 param_1,code *param_2,u64 param_3);
u64 FUN_00491760(u64 param_1,code *param_2,u64 param_3);
u64 FUN_004917f0(u64 param_1,code *param_2,u64 param_3);
u64 FUN_004919b0(u64 param_1,int param_2,u32 param_3);
u64 FUN_00491ff0(u64 param_1,int param_2);
u64 FUN_00492020(u64 param_1,int param_2);
u64 FUN_00492060(u64 param_1,int param_2);
u64 FUN_00492d10(u64 param_1);
u64 FUN_00492e20(u64 param_1,float *param_2);
u64 FUN_00493210(u64 param_1,u16 *param_2,u16 param_3,u16 param_4, u16 param_5);
u64 FUN_00493230(u64 param_1,int param_2,long param_3);
u64 FUN_004932c0(u64 param_1,code *param_2,u64 param_3);
u64 FUN_00493370(u64 param_1,u16 param_2);
u64 FUN_004933d0(u64 param_1);
u64 FUN_00493b40(u64 param_1);
u64 FUN_004944b0(u64 param_1,u32 *param_2);
u64 FUN_004948b0(u64 param_1);
u64 FUN_00494930(u64 param_1,int param_2);
u64 FUN_004949c0(u64 param_1,int param_2);
u64 FUN_00494a40(u64 param_1,u64 param_2,int param_3);
u64 FUN_00494ae0(u64 param_1,int param_2);
u64 FUN_00494b70(u64 param_1);
u64 FUN_00494d50(u64 param_1,long param_2);
u64 FUN_00495260(u64 param_1);
u64 FUN_00495300(u64 param_1);
u64 FUN_00495a30(u64 param_1,int param_2);
u64 FUN_00495cf0(u64 param_1,u32 param_2,u16 param_3,u16 param_4, u16 param_5,u16 param_6,u16 param_7,u16 param_8, u16 param_9);
u64 FUN_00495f10(u64 param_1,code *param_2,u64 param_3);
u64 FUN_00495fb0(u32 *param_1,char *param_2,u64 param_3,u64 param_4);
u64 FUN_004967a0(u64 param_1);
u64 FUN_00496be0(u32 param_1,u32 *param_2,int param_3,u32 *param_4);
u64 FUN_00498720(int param_1,u64 param_2,u32 param_3);
u64 FUN_00499320(u64 param_1);
u64 FUN_00499a80(u64 param_1);
u64 FUN_00499af0(u64 param_1,int param_2);
u64 FUN_00499b90(u64 param_1);
u64 FUN_00499ca0(u64 param_1,code *param_2,u64 param_3);
u64 FUN_00499d30(u64 param_1);
u64 FUN_00499fd0(u64 param_1);
u64 FUN_0049a250(u64 param_1);
u64 FUN_0049a3d0(u64 param_1,code *param_2);
u64 FUN_0049a7c0(u64 param_1,code *param_2,u64 param_3);
u64 FUN_0049a870(u64 param_1,code *param_2,u64 param_3);
u64 FUN_0049aaf0(u64 param_1,int param_2);
u64 FUN_0049abf0(u64 param_1);
u64 FUN_0049ade0(u64 param_1,int param_2);
u64 FUN_0049ae30(u64 param_1);
u64 FUN_0049b180(u64 param_1);
u64 FUN_0049b2e0(u64 param_1);
u64 FUN_0049b3f0(u64 param_1,int param_2);
u64 FUN_0049b440(u64 param_1);
u64 FUN_0049b760(u64 param_1,int param_2);
u64 FUN_0049b7a0(u64 param_1);
u64 FUN_0049b850(u64 param_1,int param_2);
u64 FUN_0049bbc0(u64 param_1,u64 param_2);
u64 FUN_0049bbf0(u64 param_1,u64 param_2);
u64 FUN_0049bc20(u64 param_1,u64 param_2);
u64 FUN_0049bdc0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_0049c160(u64 param_1,int param_2);
u64 FUN_0049c1b0(u64 param_1,int param_2);
u64 FUN_0049c1e0(u64 param_1,int param_2);
u64 FUN_0049c240(u64 param_1,u64 param_2);
u64 FUN_0049c330(u64 param_1,code *param_2,u64 param_3);
u64 FUN_0049c3d0(u64 param_1,int param_2);
u64 FUN_0049c480(u64 param_1,int param_2);
u64 FUN_0049dc70(int param_1);
u64 FUN_0049e5a0(u64 param_1,int param_2);
u64 FUN_0049e830(u64 param_1,u64 param_2);
u64 FUN_0049e9f0(u64 param_1,u64 param_2);
u64 FUN_0049ee70(u64 param_1,u64 param_2);
u64 FUN_0049f040(u64 param_1,u64 param_2);
u64 FUN_0049faa0(u64 param_1);
u64 FUN_004a0430(u64 param_1,int param_2);
u64 FUN_004a0e00(int param_1);
u64 FUN_004a30d0(int param_1);
u64 FUN_004a3f20(u64 param_1);
u64 FUN_004a4d60(u64 param_1,int param_2);
u64 FUN_004a4da0(u64 param_1);
u64 FUN_004a4e40(u64 param_1);
u64 FUN_004a4ef0(u64 param_1);
u64 FUN_004a55b0(u64 param_1,float *param_2,float *param_3,float *param_4,float *param_5, float *param_6,float *param_7);
u64 FUN_004a5dd0(u64 param_1,u8 *param_2,u8 *param_3,u8 *param_4,u64 param_5);
u64 FUN_004a6200(u64 param_1,float *param_2,float *param_3,float *param_4,float *param_5);
u64 FUN_004a62e0(u64 param_1,long param_2);
u64 FUN_004a6360(u64 param_1,int param_2,u64 param_3);
u64 FUN_004a6530(u64 param_1,u64 param_2);
u64 FUN_004a6600(u64 param_1);
u64 FUN_004a7620(u64 param_1);
u64 FUN_004ab1b0(u64 param_1);
u64 FUN_004ab200(u32 param_1,u32 param_2,u64 param_3);
u64 FUN_004ab2c0(float param_1,float param_2,u64 param_3);
u64 FUN_004ab410(float param_1,float param_2,float param_3,float param_4,float param_5,float param_6, u64 param_7);
u64 FUN_004ab6a0(u64 param_1);
u64 FUN_004abd50(u64 param_1,u32 *param_2);
u64 FUN_004ac020(int *param_1,u64 param_2);
u64 FUN_004ac920(u64 param_1,int param_2,u64 param_3);
u64 FUN_004acb10(u64 param_1,u64 param_2);
u64 FUN_004ad480(u64 param_1,char *param_2);
u64 FUN_004ad5b0(u64 param_1,long param_2,u64 param_3);
u64 FUN_004ad6a0(int param_1);
u64 FUN_004ad700(u64 param_1,u64 param_2);
u64 FUN_004ad750(u64 param_1);
u64 FUN_004ad940(u64 param_1,u64 param_2);
u64 FUN_004adbd0(int *param_1);
u64 FUN_004adcc0(u64 param_1,u32 param_2);
u64 FUN_004addb0(u64 param_1,u64 param_2);
u64 FUN_004ade90(u64 param_1);
u64 FUN_004adf30(u64 param_1);
u64 FUN_004adfd0(u64 param_1,int param_2);
u64 FUN_004ae020(u64 param_1,u32 *param_2);
u64 FUN_004ae070(u32 param_1,u32 param_2,u64 param_3);
u64 FUN_004ae0c0(u32 param_1,u32 param_2,u64 param_3);
u64 FUN_004ae110(u64 param_1,u64 param_2);
u64 FUN_004ae150(u64 param_1,u64 param_2);
u32 FUN_004ae1d0(u32 param_1,u32 param_2);
u64 FUN_004ae1f0(int param_1,u32 *param_2);
u64 FUN_004ae270(u64 param_1,u64 param_2);
u64 FUN_004ae2f0(u64 param_1);
u64 FUN_004ae3b0(u64 param_1,u64 param_2);
u64 FUN_004ae690(u64 param_1);
u64 FUN_004ae790(u64 param_1);
u64 FUN_004ae960(u64 param_1,float *param_2,float *param_3);
u64 FUN_004aeb60(u64 param_1,code *param_2,u64 param_3);
u64 FUN_004aebf0(u64 param_1,u64 param_2,long param_3);
u32 FUN_004aef50(u32 param_1);
u64 FUN_004aef60(u64 param_1);
u64 FUN_004af340(u32 *param_1);
u64 FUN_004af760(u64 param_1);
u64 FUN_004af9d0(u64 param_1,float *param_2,float *param_3);
u64 FUN_004affe0(u64 param_1,u64 param_2,long param_3);
u8 * FUN_00493710(int param_1,int param_2,u32 param_3);
u8 * FUN_004aae60(void);
u8 ** FUN_0049ff00(void);
u8 ** FUN_004a3f10(void);
u32 FUN_00435260(char param_1);
s8 FUN_004353f0(int param_1);
u8 FUN_00435810(void);
u8 FUN_004359f0(int param_1,u8 param_2,u8 param_3,u32 *param_4, u8 param_5,u8 param_6);
u8 FUN_0043c730(char param_1);
char FUN_0043c7f0(char param_1);
char FUN_00449c90(u64 param_1,char param_2);
char FUN_0044a420(int param_1,int param_2,int param_3);
u32 FUN_0044f060(float param_1,int param_2,float *param_3);
u32 FUN_0044f1c0(float param_1,float *param_2,float *param_3);
u8 FUN_0044fab0(int param_1);
char FUN_00453480(void);
u32 FUN_00454400(f32 *param_1,char param_2);
u32 FUN_00454520(float *param_1,char param_2);
u8 FUN_00454a70(char param_1,RwV3d param_2);
u8 FUN_00454d00(RwV3d param_1);
char FUN_00457390(char param_1);
char FUN_004573d0(char param_1);
int FUN_0045a3b0(void);
u8 FUN_0045af90(int param_1);
int FUN_0045b480(int param_1);
int FUN_0045b4b0(int param_1);
u8 FUN_0045e010(int param_1);
u8 FUN_0045e0c0(int param_1);
u8 FUN_0045e170(int param_1);
u8 FUN_0045ec00(void);
u8 FUN_0045ec20(void);
u8 FUN_0045f7d0(void);
u8 FUN_004661b0(void);
u8 FUN_00468c50(void);
u8 FUN_0046a530(void);
u8 FUN_00473590(void);
u8 FUN_00477050(int param_1);
u8 FUN_00479030(int param_1);
u8 FUN_0047a3d0(int param_1);
u8 FUN_00488fe0(void);
u8 FUN_0048ad20(void);
u8 FUN_0048dcf0(void);
u8 FUN_0048f030(void);
u8 FUN_004915c0(void);
u8 FUN_0049a980(void);
u8 FUN_0049be50(void);
u8 FUN_0049c6c0(void);
u8 FUN_004a5100(void);
u8 FUN_004a9bd0(int param_1);
u8 FUN_004aa390(float param_1);
u8 FUN_004aa3d0(float param_1);
u8 FUN_004aaa60(void);
u8 FUN_004aab40(long param_1);
u8 FUN_004aac70(u32 *param_1);
u8 FUN_004ac390(long param_1);
u8 FUN_004accc0(float *param_1,int *param_2);
u8 FUN_004ae1e0(int param_1);
u8 FUN_004ae4e0(int param_1);
u8 FUN_004ae5a0(long param_1);
void FUN_00430150(int param_1);
void FUN_00430220(int param_1,u64 param_2);
void FUN_00430270(RwV4d* output, int object);
void FUN_004302a0(int param_1);
void FUN_004302b0(void);
void FUN_00430630(int param_1);
void FUN_00430780(u64 param_1,int param_2,int param_3,int param_4);
void FUN_00430a40(char param_1);
void FUN_004310e0(int param_1);
void FUN_004311f0(void *param_1,u32 param_2,u32 param_3);
void FUN_00431630(int param_1);
void FUN_004332f0(int param_1);
void FUN_004333d0(int param_1);
void FUN_004334d0(int param_1);
void FUN_004343d0(int param_1);
void FUN_004344f0(float *param_2,float param_1,int param_3,float *param_4,float *param_5);
void FUN_00434c90(char param_1);
void FUN_00434d30(void);
void FUN_00434e60(void);
void FUN_00434f60(u8 param_1);
void FUN_00434f70(void);
void FUN_00435060(u8 param_1);
void FUN_004350e0(char param_1,char param_2);
void FUN_00435370(u8 param_1);
void FUN_00435c00(int param_1);
void FUN_00437e00(void);
void FUN_00437e80(u32 *param_1,char param_2);
void FUN_00438010(int param_1);
void FUN_00439400(char param_1);
void FUN_00439520(int param_1);
void FUN_0043a1a0(char param_1,u8 param_2);
void FUN_0043a2f0(int param_1);
void FUN_0043a960(int param_1);
void FUN_0043bf50(u64 param_1);
void FUN_0043c660(int param_1);
void FUN_0043c7a0(char param_1,u8 param_2);
void FUN_00447ad0(int param_1);
void FUN_00447f90(float *param_1,int param_2,char param_3);
void FUN_00448060(int param_1,u8 param_2,u64 param_3,char param_4,short param_5, char param_6);
void FUN_00448cf0(int param_1,u8 param_2,u64 param_3,char param_4,short param_5, char param_6,int param_7);
void FUN_00449d10(int param_1);
void FUN_00449d60(int param_1);
void FUN_00449ed0(void);
void FUN_00449fa0(void);
void FUN_0044a240(float param_1,float param_2,float param_3,float param_4,int param_5 ,char param_6);
void FUN_0044a330(float param_1,float param_2,float param_3,float param_4,int param_5 ,char param_6);
void FUN_0044a630(int param_1);
void FUN_0044a790(u32 *param_1);
void FUN_0044a990(int param_1,u32 *param_2);
void FUN_0044acf0(int param_1);
void FUN_0044af60(u32 param_1);
void FUN_0044b7d0(int param_1);
void FUN_0044beb0(int param_1);
void FUN_0044d600(int param_1);
void FUN_0044dfc0(int param_1);
void FUN_0044e530(int param_1,u8 param_2);
void FUN_0044f270(float *param_1,float *param_2);
#pragma alias FUN_0044f270_ret FUN_0044f270
extern u32 FUN_0044f270_ret(float *param_1, float *param_2);
void FUN_004501b0(char param_1);
void FUN_00450b30(char param_1);
void FUN_00451d70(int param_1);
void FUN_00452010(float *param_1);
void FUN_00452f70(u32 *param_1,int param_2);
void FUN_004532d0(char param_1);
void FUN_004533e0(u8 param_1);
void FUN_00453470(u16 param_1);
void FUN_00453490(int param_1);
void FUN_00453d90(char param_1);
void FUN_00454110(int param_1);
void FUN_00454290(int param_1);
void FUN_004543c0(char param_1,u8 param_2);
void FUN_00454f50(char param_1,char param_2);
void FUN_00455b50(void);
void FUN_00455cf0(void);
void FUN_00456050(int param_1);
void FUN_004561d0(float param_1,float param_2,int param_3);
void FUN_004561f0(float param_1,int param_2);
void FUN_004563b0(f32 param_1, int param_2);
void FUN_004563c0(int param_1,u8 param_2);
void FUN_004563d0(int object, RwV2d value);
void FUN_00456400(int param_1,u8 param_2);
void FUN_00456410(char param_1);
void FUN_00456450(char param_1);
void FUN_00456490(char param_1);
void FUN_004564e0(char param_1);
void FUN_00456530(char param_1);
void FUN_00456580(char param_1);
void FUN_004565d0(char param_1);
void FUN_00456620(char param_1);
void FUN_00456670(u64 param_1,u64 param_2);
void FUN_00456a90(u32 param_1,char param_2,char param_3);
void FUN_00456ea0(u64 param_1,u64 param_2,u64 param_3);
void FUN_00457340(char param_1,u8 param_2,char param_3);
void FUN_00457980(int param_1);
void FUN_00458600(int param_1);
void FUN_00458850(int param_1);
void FUN_00458870(int param_1);
void FUN_00458890(void);
void FUN_00458920(int param_1);
void FUN_00458930(void);
void FUN_004589d0(int param_1,u8 param_2);
void FUN_00458b00(void);
void FUN_00458b60(void);
void FUN_00458bb0(void);
void FUN_00459d60(void);
void FUN_00459f30(int param_1);
void FUN_0045a220(int param_1);
void FUN_0045a3e0(void);
void FUN_0045a430(char param_1);
void FUN_0045a490(void);
void FUN_0045ace0(void);
void FUN_0045af70(u8 param_1);
void FUN_0045b620(u32 param_5,float param_1,float param_2,float param_3,float param_4,u8 param_6,int param_7);
void FUN_0045b830(int param_1,long param_2);
void FUN_0045b8f0(int param_1);
void FUN_0045bcb0(int param_1,u64 param_2);
void FUN_0045bd90(int param_1);
void FUN_0045c530(int param_1);
void FUN_0045c8c0(int param_1,int param_2);
void FUN_0045cdd0(int param_1,long param_2);
void FUN_0045ce90(int param_1);
void FUN_0045d990(int param_1,long param_2);
void FUN_0045e7b0(int param_1);
void FUN_0045e7e0(void);
void FUN_0045ea80(int param_1);
void FUN_0045edc0(void);
void FUN_0045f930(int param_1,float *param_2,code *param_3,u32 param_4);
void FUN_004606b0(int param_1,u64 param_2,code *param_3,u32 param_4);
void FUN_00460ec0(int param_1,u64 param_2,u32 param_3,code *param_4,u32 param_5);
void FUN_00461900(int param_1,float *param_2,u64 param_3,code *param_4,u32 param_5);
void FUN_00461d00(int param_1,u64 param_2,u32 param_3,code *param_4,u32 param_5);
void FUN_00461ea0(int param_1,float *param_2,u32 param_3,code *param_4,u32 param_5);
void FUN_00462bb0(int param_1,u64 param_2,u32 param_3,code *param_4,u32 param_5);
void FUN_00463490(int param_1,int param_2,float *param_3,u32 param_4,code *param_5, u32 param_6);
void FUN_00463b20(int param_1,int param_2,int param_3,u32 param_4,code *param_5, u32 param_6);
void FUN_00463f20(int param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00464850(float param_1,int param_2,int param_3,int param_4);
void FUN_00464e80(float param_1,int param_2,int param_3,int param_4);
void FUN_00465670(int param_1,int param_2);
void FUN_00468530(u64 param_1,u64 param_2,int param_3);
void FUN_00468660(u64 param_1,u64 param_2,int param_3);
void FUN_00468720(char *param_1,long param_2,int param_3);
void FUN_00469aa0(int param_1);
void FUN_00469b50(int param_1);
void FUN_00469bc0(int param_1);
void FUN_0046a8d0(int *param_1,int *param_2);
void FUN_0046a9e0(int *param_1);
void FUN_0046b1b0(u32 *param_1,int param_2,u32 *param_3);
void FUN_0046ea80(u64 param_1);
void FUN_00472130(u64 param_1);
void FUN_00472170(u64 param_1);
void FUN_004721b0(u64 param_1);
void FUN_004721f0(u64 param_1);
void FUN_00472230(u64 param_1);
void FUN_00473340(u64 param_1);
void FUN_00473380(u64 param_1);
void FUN_00474210(u64 param_1,u64 param_2,u64 param_3);
void FUN_00474d30(int param_1,int param_2);
void FUN_00474f20(int param_1,u32 param_2);
void FUN_00475c20(int param_1);
void FUN_00475cb0(int param_1);
void FUN_00476140(u32 *param_1,long param_2,u32 param_3);
void FUN_00476490(u64 *param_1,long param_2,u64 *param_3);
void FUN_00476720(int param_1,long param_2,u64 *param_3);
void FUN_00476980(int param_1,long param_2,u64 *param_3);
void FUN_00476c20(int param_1,int param_2,long param_3);
void FUN_00477150(int *param_1,int param_2,u64 param_3,u64 param_4,u32 param_5);
void FUN_00477470(int *param_1,u64 param_2,u64 param_3,u64 param_4, u32 param_5);
void FUN_00477610(int *param_1,u64 param_2,u64 param_3,int param_4,int param_5);
void FUN_00477810(u32 *param_1,int param_2,int param_3);
void FUN_00477a20(u32 *param_1,int param_2,int param_3);
void FUN_00477c90(int *param_1,int param_2,int param_3);
void FUN_00477eb0(int *param_1,int param_2,int param_3);
void FUN_00478100(int *param_1,int param_2,int param_3);
void FUN_00478280(int *param_1,int param_2,int param_3);
void FUN_00478cc0(int param_1,u32 *param_2);
void FUN_00479170(int *param_1,int param_2,u64 param_3,u64 param_4,u32 param_5);
void FUN_00479590(int *param_1,u64 param_2,u64 param_3,u64 param_4, u32 param_5);
void FUN_0047a050(int param_1,u32 *param_2);
void FUN_0047bf80(int param_1);
void FUN_0047c240(u32 *param_1,float *param_2,float *param_3,int param_4,int param_5);
void FUN_0047c8c0(u32 *param_1,float *param_2,float *param_3,int param_4,int param_5);
void FUN_004838e0(u32 *param_1,int param_2,int param_3);
void FUN_00485070(u32 *param_1,int param_2,int param_3);
void FUN_00485110(u32 *param_1,int param_2,int param_3);
void FUN_00485440(u32 *param_1,int param_2,int param_3);
void FUN_00485750(int *param_1,int param_2,int param_3);
void FUN_00485e20(int *param_1,int param_2,int param_3);
void FUN_00485ef0(int *param_1,int param_2,int param_3);
void FUN_00485ff0(int *param_1,int param_2,int param_3);
void FUN_004866c0(int param_1);
void FUN_00486c80(int *param_1,float *param_2,float *param_3,int param_4,int param_5);
void FUN_00487030(int *param_1,float *param_2,float *param_3,int param_4,int param_5);
void FUN_00487280(int *param_1,float *param_2,float *param_3,int param_4,int param_5);
void FUN_004876f0(int *param_1,float *param_2,float *param_3,long param_4,int param_5);
void FUN_00487bf0(u32 *param_1,int param_2,int param_3);
void FUN_00488550(int *param_1,int param_2,int param_3,int param_4,u32 param_5);
void FUN_00489350(u64 param_1,long param_2);
void FUN_004893e0(int param_1,int param_2,u32 param_3);
void FUN_00489460(int param_1,u32 *param_2,int *param_3,int param_4,u32 *param_5,u32 param_6);
void FUN_0048a3f0(u64 param_1,long param_2);
void FUN_0048dd70(int *param_1);
void FUN_0048de50(int *param_1,int *param_2);
void FUN_0048e610(int *param_1);
void FUN_0048efa0(int param_1,int param_2,u32 param_3);
void FUN_0048efc0(int param_1, int param_2, f32 param_3);
void FUN_00491100(int param_1);
void FUN_00492c30(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00492c60(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00492c90(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00492cc0(u64 param_1,u64 param_2);
void FUN_00492ce0(u64 param_1,u64 param_2);
void FUN_00492d00(u64 param_1);
void FUN_00493c50(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00493c80(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00494520(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00494550(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00494db0(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00494de0(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00494e10(u64 param_1,u64 param_2);
void FUN_00495480(int *param_1,int param_2);
void FUN_004959c0(u64 param_1);
void FUN_00496580(void);
void FUN_00496ad0(u64 param_1,int *param_2,short param_3,short param_4,int param_5, int param_6);
void FUN_00496f60(int param_1,int param_2,long param_3);
void FUN_00498e30(u64 param_1);
void FUN_00499230(void);
void FUN_00499250(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00499280(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_004992b0(u64 param_1,u64 param_2);
void FUN_004992d0(u64 param_1,u64 param_2);
void FUN_00499720(u64 param_1);
void FUN_00499850(int *param_1);
void FUN_00499e90(u32 param_1,u32 param_2);
void FUN_00499f40(int param_1);
void FUN_0049a920(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_0049a950(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_0049afa0(int param_1,u64 param_2);
void FUN_0049be20(int param_1);
void FUN_0049c680(void);
void FUN_0049c9b0(void);
void FUN_0049ca50(long param_1);
void FUN_0049cab0(float param_1,u8 *param_2);
void FUN_0049cbd0(int param_1,float *param_2);
void FUN_0049cc30(int param_1);
void FUN_0049e4f0(u64 param_1);
void FUN_0049ff10(u32 param_1,u32 param_2,int param_3,long param_4);
void FUN_004a0480(int param_1,int param_2);
void FUN_004a05d0(int param_1,int param_2);
void FUN_004a06c0(int param_1);
void FUN_004a08f0(int param_1,int *param_2,int param_3,u32 param_4);
void FUN_004a0dc0(int param_1);
void FUN_004a24a0(int param_1,int param_2);
void FUN_004a2560(u64 param_1,int *param_2);
void FUN_004a3540(int param_1);
void FUN_004a3f70(int param_1,u32 *param_2);
void FUN_004a53b0(void);
void FUN_004a91f0(void);
void FUN_004a97c0(u64 param_1,u64 param_2);
void FUN_004a9a70(int param_1);
void FUN_004aa550(u64 param_1);
void FUN_004aa5c0(void);
void FUN_004aa620(void);
void FUN_004aad50(void);
void FUN_004ab170(u32 *param_1);
void FUN_004ab910(float *param_1,float *param_2,float *param_3);
void FUN_004aba20(u64 param_1,u64 param_2,int param_3);
void FUN_004ac410(int *param_1);
void FUN_004ac7f0(void);
void FUN_004ac860(u32 param_1,u32 param_2);
void FUN_004adb50(void);
void FUN_004adc70(u64 param_1);
void FUN_004adc90(u64 param_1,u64 param_2);
void FUN_004adca0(void);
void FUN_004ae060(int param_1);
void FUN_004ae940(u64 param_1);

extern u32 DAT_006b4608;
extern u32 DAT_006b4610;
extern u32 DAT_006b4618;
extern u32 DAT_006b4620;
extern u32 DAT_006b4650;
extern u32 DAT_006b4652;
extern u32 DAT_006b46d0;
extern u32 DAT_006b46d2;
extern u32 DAT_006b46d4;
extern u32 DAT_006b46d6;
extern u32 DAT_006b46d8;
extern u32 DAT_006b46da;
extern u32 DAT_006b46dc;
extern u32 DAT_006b46de;
extern u32 DAT_006b46e0;
extern u32 DAT_006b46e2;
extern u32 DAT_006b46e4;
extern u32 DAT_006b46e6;
extern u32 DAT_006b4712;
extern u32 DAT_006b4714;
extern u32 DAT_006b4716;
extern u32 DAT_006b4718;
extern u32 DAT_006b471a;
extern u32 DAT_006b471c;
extern u32 DAT_006b471e;
extern u32 DAT_006b477a;
extern u32 DAT_006b477c;
extern u32 DAT_006b477e;
extern u32 DAT_006b4780;
extern u32 DAT_006b4782;
extern u32 DAT_006b4784;
extern u32 DAT_006b4786;
extern u32 DAT_006b4788;
extern u32 DAT_006b478a;
extern u32 DAT_006b478c;
extern u32 DAT_006b478e;
extern u32 DAT_006b4790;
extern u32 DAT_006b4792;
extern u32 DAT_006b4794;
extern u32 DAT_006b4796;
extern u32 DAT_006b4798;
extern u32 DAT_006b479a;
extern u32 DAT_006b479c;
extern u32 DAT_006b479e;
extern u32 DAT_006b47a0;
extern u32 DAT_006b47a2;
extern u32 DAT_006b47a4;
extern u32 DAT_006b47a6;
extern u32 DAT_006b47ae;
extern u32 DAT_006b481a;
extern u32 DAT_006b4a48;
extern u32 DAT_006b4a50;
extern u32 DAT_006b4a78;
extern u32 DAT_006b4a80;
extern u32 DAT_006b4a90;
extern u32 DAT_006b4ab0;
extern u32 DAT_006b4ab4;
extern u32 DAT_006b4ab8;
extern u32 DAT_006b4abc;
extern u32 DAT_006b4ac0;
extern u32 DAT_006b4ac2;
extern u32 DAT_006b4ac4;
extern u32 DAT_006b4ac6;
extern u32 DAT_006b4ac8;
extern u32 DAT_006b4b20;
extern u32 DAT_006b4b28;
extern u32 DAT_006b4b80;
extern u32 DAT_006b4b82;
extern u32 DAT_006b4b84;
extern u32 DAT_006b4e00;
extern u32 DAT_007bc460;
extern u32 DAT_007bc6b0;
extern u32 DAT_007bc730;
extern float DAT_007caf94;
extern float DAT_007cafa8;
extern float DAT_007cafc0;
extern float DAT_007cb134;
extern float DAT_007cb138;
extern u32 DAT_007cdb10;
extern u32 DAT_007ce290;
extern u32 DAT_007ce6ac;
extern u32 DAT_007ce6bc;
extern u32 DAT_007ce6c0;
extern u32 DAT_007ce6c4;
extern u32 DAT_007ce6c8;
extern u32 DAT_007ce6cc;
extern u32 DAT_007ce6d0;
extern u32 DAT_007ce6d4;
extern u32 DAT_007ce6e0;
extern u32 DAT_007ce6e4;
extern u32 DAT_007ce6e8;
extern u32 DAT_007ce6ec;
extern u32 DAT_007ce6f0;
extern u32 DAT_007ce6f4;
extern u32 DAT_007ce700;
extern s32 DAT_007ce704;
extern u32 DAT_007ce710;
extern u32 DAT_007ce718;
extern u32 DAT_007e094e;
extern u32 DAT_007e0952;
extern u32 DAT_007e0958;
extern u32 DAT_007e095a;
extern u32 DAT_0086be00;
extern u32 DAT_0086e6e8;
extern u8 DAT_0086e6a0[];
extern u32 DAT_0086e6f0;
extern u32 DAT_0086e6f4;
extern u32 DAT_0086e808;
extern u32 DAT_0086e80c;
extern u32 DAT_0086e810;
extern u32 DAT_0086e848;
extern u32 DAT_0086e9cc;
extern u32 DAT_0086eb8c;
extern u32 DAT_0086ed4c;
extern u32 DAT_0086eda0;
extern u32 DAT_0086ede8;
extern u32 DAT_0086edf4;
extern u32 DAT_0086ef08;
extern u32 DAT_0086ef0c;
extern u32 DAT_0086ef10;
extern u32 DAT_0086ef2c;
extern u32 DAT_0086ef38;
extern u32 DAT_0086ef39;
extern u32 DAT_0086ef3a;
extern u32 DAT_0086ef3b;
extern u32 DAT_0086ef3c;
extern u32 DAT_008717a0;
extern u32 DAT_008717e8;
extern u32 DAT_008717f0;
extern u32 DAT_008717f4;
extern u32 DAT_0087190c;
extern u32 DAT_0087193a;
extern u32 DAT_0087193b;
extern u32 DAT_0087193c;
extern u32 DAT_00871948;
extern u32 DAT_0087194a;
extern u32 DAT_0087194c;
extern u32 DAT_00871954;
extern u32 DAT_00871958;
extern u32 DAT_008719b0;
extern u32 DAT_0095c0e0;
extern u32 DAT_0095c0e4;
extern u32 DAT_0095c0e8;
extern u32 DAT_0095c0ec;
extern u32 DAT_0095c0f0;
extern u32 DAT_0095c0f4;
extern u32 DAT_0095c0f8;
extern u32 DAT_0095c0fc;
extern u32 DAT_0095c100;
extern u32 DAT_0095c110;
extern u32 DAT_0095c210;
extern u32 DAT_0095c21e;
extern u32 DAT_0095c21f;
extern u32 DAT_0095c220;
#pragma alias DAT_0095c220_abs DAT_0095c220
extern u8 DAT_0095c220_abs[];
extern u32 DAT_0095c221;
extern u32 DAT_0095c23e;
extern u32 DAT_0095c23f;
extern u32 DAT_0095c240;
#pragma alias DAT_0095c240_abs DAT_0095c240
extern u8 DAT_0095c240_abs[];
extern u32 DAT_0095c241;
extern f32 DAT_00960088;
extern code DAT_00960090;
extern code DAT_009600a0;
extern code DAT_0096017c;
extern code DAT_00960184;
extern u32 PTR_DAT_006b46f0;
extern u32 PTR_DAT_006b4720;
extern u32 PTR_DAT_006b4de0;
extern u32 PTR_FUN_006b4e60;
extern u8 cGpffffb9cc;
extern f32 fGpffff8110;
extern f32 fGpffff8248;
extern f32 fGpffff82d8;
extern u32 gp0xffffae24;
extern u32 gp0xffffb9f7;
extern u32 iGpffffb418;
extern u32 iGpffffb5a0;
extern u32 iGpffffb9fc;
extern u32 iGpffffba08;
extern u32 iGpffffba20;
extern u32 iGpffffba24;
extern float uGpffff82b8;
extern float uGpffff82d0;
extern float uGpffff82d4;
extern u32 uGpffffae20;
extern u32 uGpffffb418;
extern u32 uGpffffb9cc;
extern u32 uGpffffb9dc;
extern u32 uGpffffb9e0;
extern u32 uGpffffb9e4;
extern u32 uGpffffba00;
extern u32 uGpffffba04;
extern u32 uGpffffba08;
extern u32 uGpffffba28;
extern char getCopCondition(int,int);

extern code FUN_00100ec0;
extern code FUN_001016b0;
extern code FUN_00102100;


extern code FUN_00108670;

extern code FUN_00108f70_y2;
extern code FUN_00108fd0;
extern code FUN_00109040;
extern code FUN_00111f30;
extern code FUN_001120c0;
#pragma alias FUN_001126b0_typed FUN_001126b0
extern f32 FUN_001126b0_typed(void *particle);
#pragma alias FUN_00112740_typed FUN_00112740
extern f32 FUN_00112740_typed(void *particle);
#pragma alias FUN_0016c570_typed FUN_0016c570
extern u32 FUN_0016c570_typed(u16 id);
#pragma alias FUN_0052e878_typed FUN_0052e878
extern f32 FUN_0052e878_typed(f32 angle);
extern code FUN_00112370;
extern code FUN_00112420;
extern code FUN_001124b0;
extern code FUN_001126b0;
extern code FUN_00112740;
extern code FUN_00113a30;

extern code FUN_001159f0;
extern code FUN_00115bc0;
extern u8 FUN_0016c470(s16 id);
extern code FUN_0016c570;
extern code FUN_0016c5f0;
extern code FUN_0016c920;
extern code FUN_0016cf40;
extern code FUN_0016cf90;
extern code FUN_0016f190;
extern code FUN_0016f1f0;
extern code FUN_0016f490;
extern code FUN_00170a40;
extern code FUN_00170ab0;
extern code FUN_00170b20;
extern code FUN_00170b90;

extern code FUN_00173380;
extern code FUN_00177410;
extern code FUN_0017b500;
extern code FUN_0017b660;
extern code FUN_0017b860;
extern code FUN_001831e0;
extern code FUN_0018bee0;
extern code FUN_0018c0c0;
extern code FUN_0018eb30;
extern code FUN_00194b20;
extern code FUN_00194b80;
extern code FUN_00195020;
extern code FUN_00195290_y2;
extern code FUN_00198590;
extern code FUN_001a0040;


extern code FUN_001a0dc0;
extern code FUN_001a5320;
extern code FUN_001a56b0;
extern code FUN_001a56c0;
extern code FUN_001a56d0;
extern code FUN_001a5700;
extern code FUN_001a57a0;
extern code FUN_001a5aa0;
extern code FUN_001a91b0;
extern code FUN_001a9390;
extern code FUN_001a9760;
extern code FUN_001aaa20;
extern code FUN_001aaac0;
extern code FUN_001acc30;
extern code FUN_001ad870;
extern code FUN_001adc20;
extern code FUN_001adff0;
extern code FUN_001af930;
extern code FUN_001aff70;
extern code FUN_001b0020;
extern code FUN_001b01b0;
extern code FUN_001b01d0;
extern code FUN_001b0230;
extern code FUN_001b0250;
extern code FUN_001b9120;
extern code FUN_001c65e0;
extern code FUN_001c6d70;
extern code FUN_001c6dd0;
extern code FUN_001c7270;
extern code FUN_001c7b10;
extern code FUN_001d0110;
extern code FUN_001d22a0;
extern code FUN_001d8b00;
extern code FUN_001d8c60;
extern code FUN_001d8e60;
extern code FUN_001dde00;
extern code FUN_001ded40;
extern code FUN_001e13c0;
extern code FUN_00269690;
extern code FUN_002699a0;
extern code FUN_002699d0;
extern code FUN_00269a10;
extern code FUN_00269c80;
extern code FUN_00269ca0;
extern code FUN_002ff340;
extern code FUN_002ff760;
extern code FUN_00316e00;
extern code FUN_00316f70;
extern code FUN_003174e0;
extern code FUN_00318540;
extern code FUN_00318ed0;
extern code FUN_0031c1d0;
extern code FUN_0035bb40;
extern code FUN_0035bc00;
extern code FUN_0035c1a0;
extern code FUN_003952d0;
extern code FUN_003b2cb0;
extern code FUN_003b5d10;
extern code FUN_003b5d50;
extern code FUN_003b6030;
extern code FUN_003b7090;
extern code FUN_003bb010;
extern code FUN_003c72d0;
extern code FUN_003c7430;
extern code FUN_003c74e0;
extern code FUN_003c7560;
extern code FUN_003c75b0;
extern code FUN_003c77a0;
extern code FUN_003c7850;
extern code FUN_003c78d0;
extern code FUN_003c7b90;
extern code FUN_004222d0;
extern code FUN_00423fe0;
extern code FUN_00427830;
extern code FUN_00427a10;
extern code FUN_00427db0;
extern code FUN_00427de0;
extern code FUN_00427e20;
extern code FUN_00427e60;
extern code FUN_00427e70;
extern code FUN_00429e80;
extern code FUN_00469DC0;
extern code FUN_00474630;
extern code FUN_00488dd0;
extern code FUN_004ACE60;
extern code FUN_004ACE70;
extern code FUN_004b0fa0;
extern code FUN_004b1050;
extern code FUN_004b1090;
extern code FUN_004b1100;
extern code FUN_004b11a0;
extern code FUN_004b6680;
extern code FUN_004b6e10;
extern code FUN_004b6eb0;
extern code FUN_004b75d0;
extern code FUN_004bae00;
extern code FUN_004bb5d0;
extern code FUN_004c0240;
extern code FUN_004c0370;
extern code FUN_004c0550;
extern code FUN_004c06c0;
extern code FUN_004c15a0;
extern code FUN_004c1600;
extern code FUN_004c1750;
extern code FUN_004c17f0;
extern code FUN_004c1820;
extern code FUN_004c1850;
extern code FUN_004c18b0;
extern code FUN_004c1910;
extern code FUN_004c19f0;
extern code FUN_004c1c50;
extern code FUN_004c1cd0;
extern code FUN_004c1d10;
extern code FUN_004c1d50;
extern code FUN_004c1e60;
extern code FUN_004c1e70;
extern code FUN_004c1f70;
extern code FUN_004c2090;
extern code FUN_004c20b0;
extern code FUN_004c2120;
extern code FUN_004c2130;
extern code FUN_004c21b0;
extern code FUN_004c2d20;
extern code FUN_004c2f30;
extern code FUN_004c31b0;
extern code FUN_004c32a0;
extern code FUN_004c33d0;
extern code FUN_004c35d0;
extern code FUN_004c3880;
extern code FUN_004c38c0;
extern code FUN_004c3b50;
extern code FUN_004c3c30;
extern code FUN_004c4200;
extern code FUN_004c47e0;
extern code FUN_004c4930;
extern code FUN_004c5250;
extern code FUN_004c53f0;
extern code FUN_004c5620;
extern code FUN_004c5780;
extern code FUN_004c58a0;
extern code FUN_004c5960;
extern code FUN_004c59b0;
extern code FUN_004c5a00;
extern code FUN_004c5a50;
extern code FUN_004c5c30;
extern code FUN_004c6170;
extern code FUN_004c61b0;
extern code FUN_004c64b0;
extern code FUN_004c6560;
extern code FUN_004c65d0;
extern code FUN_004c6970;
extern code FUN_004c6ac0;
extern code FUN_004c6be0;
extern code FUN_004c6c20;
extern code FUN_004c6c60;
extern code FUN_004c7a50;
extern code FUN_004c7b60;
extern code FUN_004c7b90;
extern code FUN_004c7d00;
extern code FUN_004c7d30;
extern code FUN_004c7d80;
extern code FUN_004c81a0;
extern code FUN_004c81d0;
extern code FUN_004c8240;
extern code FUN_004c83c0;
extern code FUN_004c9df0;
extern code FUN_004ca000;
extern code FUN_004ca030;
extern code FUN_004ca510;
extern code FUN_004ca520;
extern code FUN_004ca550;
extern code FUN_004cace0;
extern code FUN_004cad30;
extern code FUN_004cae30;
extern code FUN_004caf10;
extern code FUN_004caf80;
extern code FUN_004cb1b0;
extern code FUN_004cb270;
extern code FUN_004cb2f0;
extern code FUN_004cb6e0;
extern code FUN_004cb7f0;
extern code FUN_004cb9f0;
extern code FUN_004cbe00;
extern code FUN_004cbeb0;
extern code FUN_004cbf20;
extern code FUN_004cc0a0;
extern code FUN_004cc1d0;
extern code FUN_004cc5c0;
extern code FUN_004cc6b0;
extern code FUN_004cdc70;
extern code FUN_004cdce0;
extern code FUN_004cdd50;
extern code FUN_004ce0f0;
extern code FUN_004cec10;
extern code FUN_004d0c30;
extern code FUN_004d0d10;
extern code FUN_004d0e40;
extern code FUN_004d0f00;
extern code FUN_004d0fd0;
extern code FUN_004d1110;
extern code FUN_004d1170;
extern code FUN_004d11d0;
extern code FUN_004d11f0;
extern code FUN_004d13b0;
extern code FUN_004d1840;
extern code FUN_004d18c0;
extern code FUN_004d4df0;
extern code FUN_004d51c0;
extern code FUN_004d59d0;
extern code FUN_004d5e90;
extern code FUN_004d5fe0;
extern code FUN_004d7f60;
extern code FUN_004ec2b0;
extern code FUN_004f0f30;
extern code FUN_004f1020;
extern code FUN_004f1e20;
extern code FUN_004f1e40;
extern code FUN_004f1ed0;
extern code FUN_004f1f80;
extern code FUN_004f1fd0;
extern code FUN_004f23c0;
extern code FUN_004f2430;
extern code FUN_004f2710;
extern code FUN_004f2e70;
extern code FUN_004f2f70;
extern code FUN_004f3010;
extern code FUN_004f3ec0;
extern code FUN_004f3f70;
extern code FUN_004f3f80;
extern code FUN_004f4640;
extern code FUN_004f4830;
extern code FUN_004f4950;
extern code FUN_00503a58;
extern code FUN_0050d3a0;
extern code FUN_0050d3f0;
extern code FUN_005211b8;
extern code FUN_00521250;
extern code FUN_00521408;
extern code FUN_005225a8;
extern code FUN_005225f8;
extern code FUN_00523e68;
extern code FUN_00524270;
extern code FUN_00524388;
extern code FUN_00524670;
extern code FUN_0052e6d8;
extern code FUN_0052e878;
extern code FUN_0052ea18;
extern code FUN_005316d0;

char FUN_00435440(char param_1);
char FUN_0043bc20(char param_1);
float FUN_0045b4e0(int param_1);
float FUN_004693a0(int param_1);
float FUN_0047cfd0(u32 *param_1,u8 (*param_2) [12],u8 (*param_3) [12], int param_4,int param_5);
float FUN_004a9560(float param_1,int param_2,u8 *param_3);
float FUN_004aa2c0(void);
int * FUN_00496cd0(u32 param_1,u32 *param_2,u64 param_3,u16 *param_4);
int * FUN_004ac120(int *param_1,u64 param_2);
int * FUN_004ac240(int *param_1);
int FUN_0044f120(RwV3d param_1);
int FUN_0044f170(RwV3d param_1);
int FUN_00457410(void);
int FUN_0045edd0(u32 *param_1);
int FUN_0045f540(int param_1,int param_2);
int FUN_00465b40(int param_1);
int FUN_00468350(int param_1);
int FUN_0046ad20(int *param_1,int param_2);
int FUN_0046b060(int param_1,u32 *param_2,int param_3);
int FUN_004753d0(int param_1,u32 param_2);
int FUN_00475540(int param_1,u64 param_2,u64 param_3,u32 param_4);
int FUN_00489320(int *param_1);
int FUN_00489ae0(int param_1);
int FUN_0048a7a0(int param_1);
int FUN_0048d200(int param_1);
int FUN_0048e4f0(long param_1);
int FUN_0048e890(int *param_1,long param_2,u64 param_3,int param_4);
int FUN_0048ed20(int param_1,int param_2);
int FUN_0048ede0(int param_1);
int FUN_0048ee30(int param_1,int param_2);
int FUN_004912b0(int param_1);
int FUN_00491cc0(int param_1);
int FUN_00492f80(int param_1,int param_2);
int FUN_00493cb0(u64 param_1);
int FUN_00495340(int *param_1,int param_2);
int FUN_004964f0(int param_1,char *param_2);
int FUN_00499400(int param_1,u64 param_2,int param_3,int param_4);
int FUN_0049c560(int param_1);
int FUN_0049c5c0(int param_1);
int FUN_0049c620(int param_1);
int FUN_0049d4d0(int param_1,int param_2,int *param_3,int *param_4,int *param_5,int *param_6);
int FUN_0049ecd0(int param_1);
int FUN_0049f340(int param_1);
int FUN_004a0ce0(int param_1,int *param_2,int param_3,u32 param_4);
int FUN_004a26d0(int param_1,int *param_2,int param_3,u32 param_4);
int FUN_004a5200(void);
int FUN_004a5290(void);
int FUN_004a5320(void);
int FUN_004a6630(int param_1,float *param_2,int param_3,int *param_4,int *param_5);
int FUN_004ab0e0(u64 param_1);
int FUN_004ace80(int param_1,float *param_2,u64 param_3,u32 *param_4,int *param_5);
long FUN_0045ec40(u16 param_1,u16 param_2,u32 *param_3,u32 param_4);
long FUN_0045efe0(u64 param_1);
long FUN_0045f140(u64 param_1,u16 param_2,u16 param_3,u64 param_4, u32 *param_5);
long FUN_00464280(u32 param_1);
long FUN_00464540(u64 param_1);
long FUN_00467c20(long param_1,u64 param_2,int param_3);
long FUN_0046bab0(long param_1,u64 param_2);
long FUN_0046bd00(long param_1,u64 param_2);
long FUN_0046bfb0(float param_1,long param_2,u8 *param_3,float *param_4,u32 param_5);
long FUN_00474260(u32 param_1,u32 param_2,u64 param_3,u64 param_4);
long FUN_00475d60(u64 param_1,u64 param_2,u64 param_3,u32 param_4, u32 param_5);
long FUN_0047ab70(void);
long FUN_0047b1a0(void);
long FUN_0047bb40(int param_1,int param_2,u32 param_3);
long FUN_0048a9a0(long param_1,u64 param_2);
long FUN_0048af80(u32 param_1);
long FUN_0048dab0(int param_1,long param_2,u64 param_3);
long FUN_00490050(u64 param_1);
long FUN_00490dc0(u64 param_1,int *param_2,int *param_3);
long FUN_00491880(void);
long FUN_00491b40(u64 param_1);
long FUN_00491de0(void);
long FUN_004920a0(u64 param_1);
long FUN_00494580(u64 param_1);
long FUN_004947c0(u8 param_1);
long FUN_00494be0(void);
long FUN_00494e30(u64 param_1);
long FUN_004954c0(u64 param_1,long param_2);
long FUN_00495b10(long param_1);
long FUN_00496230(u64 param_1,char *param_2,u32 param_3);
long FUN_00497130(u64 param_1,long param_2,u64 param_3,u64 param_4,long param_5);
long FUN_00498e70(int param_1);
long FUN_00499140(long param_1,u32 param_2);
long FUN_0049a080(long param_1);
long FUN_0049a400(u32 *param_1);
long FUN_0049c810(void);
long FUN_0049fe40(long param_1,int param_2,long param_3);
long FUN_0049fec0(long param_1,u32 param_2);
long FUN_004a35c0(long param_1,long param_2,u32 param_3);
long FUN_004a38f0(long param_1,long param_2,long param_3,long param_4);
long FUN_004a3a80(long param_1,long param_2,long param_3,long param_4);
long FUN_004a3c10(long param_1,long param_2,long param_3);
long FUN_004a3d70(long param_1,u32 param_2);
long FUN_004a3db0(long param_1,long param_2,long param_3);
long FUN_004a3e30(long param_1,int param_2,long param_3);
long FUN_004a5470(void);
long FUN_004a6ce0(u32 param_1,long param_2,u8 *param_3,u32 *param_4, u64 param_5);
long FUN_004a6eb0(float param_1,long param_2,u8 *param_3,float *param_4,float *param_5);
long FUN_004a7820(long param_1,u64 param_2,u32 param_3,u32 param_4);
long FUN_004a9490(long param_1);
long FUN_004a98a0(u64 param_1);
long FUN_004ac570(void);
long FUN_004ac5f0(long param_1);
long FUN_004ac710(long param_1);
long FUN_004acb90(u64 param_1);
long FUN_004aeea0(u64 param_1);
long FUN_004af210(int *param_1,int *param_2,u32 param_3,u64 param_4);
short * FUN_00496e80(int param_1,short param_2,short param_3);
short FUN_0043b980(char param_1,u64 param_2);
short FUN_0043bda0(char param_1,char param_2);
u16 FUN_00435660(char param_1);
short FUN_0043c180(char param_1);
short FUN_0043c340(char param_1);
short FUN_00453460(void);
u32 * FUN_0048f580(u64 param_1,int *param_2,int param_3,u32 param_4);
u32 * FUN_0048fbd0(u64 param_1,u64 param_2,u64 param_3,u32 param_4);
u32 * FUN_004a7e40(u32 *param_1,u32 param_2,u32 param_3,char *param_4);
u32 * FUN_004a8980(u32 *param_1,u64 param_2,u32 param_3,u64 param_4);
u32 * FUN_004a90f0(void);
u32 * FUN_004a9a80(u64 param_1);
u32 * FUN_004ab8c0(void);
u32 FUN_00431880(int param_1);
u32 FUN_00431aa0(int param_1);
u32 FUN_00432050(int param_1);
u32 FUN_00432600(int param_1);
u32 FUN_00432bb0(int param_1);
u32 FUN_00433160(int param_1);
u32 FUN_00433810(char param_1,char param_2);
u32 FUN_004339d0(int param_1);
u32 FUN_00433de0(int param_1);
u32 FUN_00434770(float param_1,float param_2,int param_3,float *param_4);
u32 FUN_00434920(float param_1,float param_2,int param_3,float *param_4);
u32 FUN_004352e0(void);
u32 FUN_00437e20(char param_1);
u32 FUN_0043a230(char param_1);
u32 FUN_0043a9d0(u64 param_1,u64 param_2,char param_3);
u32 FUN_0043c500(int param_1);
u32 FUN_0043c910(char param_1);
u32 FUN_0043ca30(int param_1);
u32 FUN_00449fe0(float param_1,float param_2,float param_3,float param_4,int param_5,short param_6);
u32 FUN_0044a110(float param_1,float param_2,float param_3,float param_4,int param_5,short param_6);
u32 FUN_0044f300(char param_1);
u32 FUN_0044ffb0(int param_1);
u32 FUN_004514a0(char param_1);
u32 FUN_004523c0(u64 param_1,char param_2);
u32 FUN_00452a70(char param_1,char param_2);
u32 FUN_004534b0(char param_1);
u32 FUN_00453ed0(char param_1,char param_2,char param_3,u32 *param_4,char param_5,char param_6);
u32 FUN_004541f0(int param_1);
u32 FUN_00457470(int param_1);
u32 FUN_004575e0(int param_1);
u32 FUN_004589e0(void);
u32 FUN_00458a80(char param_1,char param_2);
u32 FUN_00458cb0(u64 param_1,char param_2,char param_3);
u32 FUN_00459790(u64 param_1,char param_2);
u32 FUN_00459e00(char param_1);
u32 FUN_00459e80(int param_1);
u32 FUN_0045a020(int param_1);
u32 FUN_0045a280(u32 param_1,u32 param_2);
u32 FUN_0045af40(void);
u32 FUN_0045afd0(float param_1,int param_2,int param_3,int param_4,int param_5,int param_6, u8 param_7,u8 param_8,short param_9);
u32 FUN_0045b190(int param_1);
u32 FUN_0045b420(int param_1,float *param_2);
u32 FUN_0045df00(int param_1);
u32 FUN_0045e3e0(int param_1);
u32 FUN_0045e8c0_y2(u64 param_1);
u32 FUN_0045eaf0(void);
u32 FUN_0045eba0(void);
u32 FUN_00465590(int param_1,u64 param_2);
u32 FUN_00466710(int param_1);
u32 FUN_00466720(int param_1);
u32 FUN_00466730(u32 *param_1);
u32 FUN_00469030(int param_1);
u32 FUN_00469340(int param_1);
u32 FUN_004695f0(int param_1);
u32 FUN_00469650(int param_1);
u32 FUN_004696b0(int param_1);
u32 FUN_00469710(int param_1);
u32 FUN_004698e0(int param_1);
u32 FUN_00469a90(void);
u32 FUN_00469ce0(void);
u32 FUN_00469cf0(void);
u32 FUN_0046a6c0(int param_1,u64 param_2,u64 param_3,u64 param_4);
u32 FUN_0046a6f0(int param_1,u64 param_2,u64 param_3,u64 param_4);
u32 FUN_0046a720(int param_1,u64 param_2,u64 param_3,u64 param_4);
u32 FUN_0046a750(u64 param_1);
u32 FUN_0046a890(u64 param_1);
u32 FUN_0046eb10(int param_1,u32 *param_2);
u32 FUN_00473600(int *param_1,u32 param_2);
u32 FUN_00473b10(int *param_1,u32 param_2);
u32 FUN_00473fb0(u32 param_1);
u32 FUN_00474640(int param_1,int *param_2,u32 param_3,u32 param_4);
u32 FUN_00474a80(int param_1);
u32 FUN_00478440(int param_1,u32 *param_2);
u32 FUN_00478e80(u64 param_1,u32 param_2);
u32 FUN_00479840(int param_1,u32 *param_2);
u32 FUN_0047a210(u64 param_1,int param_2);
u32 FUN_0047a510(u64 param_1,u64 param_2,u64 param_3,u32 param_4);
u32 FUN_0047abf0(int param_1,u32 *param_2);
u32 FUN_0047bd20(u64 param_1);
u32 FUN_0047de30(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5);
u32 FUN_0047e9e0(u32 *param_1,float *param_2,float *param_3,int param_4,int param_5);
u32 FUN_0047fb10(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5);
u32 FUN_00480c30(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5);
u32 FUN_00481860(u32 *param_1,float *param_2,float *param_3,int param_4,int param_5);
u32 FUN_00482a50(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5);
u32 FUN_00483170(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5);
u32 FUN_004861b0(u64 param_1,u64 param_2,u32 param_3,u32 param_4);
u32 FUN_00486340(u32 param_1,int param_2,u32 param_3);
u32 FUN_00489020(int param_1);
u32 FUN_00489550(int *param_1,int param_2,long param_3,int param_4,long param_5,long param_6, long param_7,long param_8);
u32 FUN_004899f0(u64 param_1);
u32 FUN_00489a80(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
u32 FUN_0048a1a0(void);
u32 FUN_0048a2c0(int param_1);
u32 FUN_0048a3d0(u32 *param_1);
u32 FUN_0048a3e0(int param_1);
u32 FUN_0048a480(int param_1);
u32 FUN_0048abf0(void);
u32 FUN_0048ac00(void);
u32 FUN_0048da30(u64 param_1);
u32 FUN_0048ef30(int param_1);
f32 FUN_0048ef60(int param_1, int param_2);
u32 FUN_0048ef80(int param_1,int param_2);
int FUN_0048efe0(int param_1);
u32 FUN_00491a80(u64 param_1);
u32 FUN_00491ea0(u64 param_1);
u32 FUN_00492d50(u64 param_1);
u32 FUN_00493b60(u64 param_1);
u32 FUN_00494760(u64 param_1);
u32 FUN_00494cc0(u64 param_1);
u32 FUN_00495320(int *param_1,int param_2);
u32 FUN_00495c20(u64 param_1);
u32 FUN_00495c80(int *param_1);
u32 FUN_00497600(int param_1,u32 param_2,int *param_3,int param_4);
u32 FUN_004982b0(int *param_1,long param_2);
u32 FUN_00498e40(long param_1,long param_2);
u32 FUN_00499c20(code *param_1,u64 param_2);
u32 FUN_0049a170(u32 param_1);
u32 FUN_0049a290(int param_1);
u32 FUN_0049aeb0(u64 param_1);
u32 FUN_0049af20(int *param_1);
u32 FUN_0049c230(int param_1);
u32 FUN_0049c790(void);
u32 FUN_0049c7a0(u64 param_1,u32 *param_2);
u32 FUN_0049c8c0(void);
u32 FUN_0049cc70(int param_1);
u32 FUN_0049e6c0(int param_1);
u32 FUN_0049e780(int param_1);
u32 FUN_0049f5d0(int param_1,u32 *param_2);
u32 FUN_004a09d0(u64 param_1,u32 *param_2);
u32 FUN_004a1430(int param_1);
u32 FUN_004a2bb0(int param_1);
u32 FUN_004a4060(int param_1,int *param_2);
u32 FUN_004a42f0(int param_1);
u32 FUN_004a4f90(int param_1);
u32 FUN_004a5080(int param_1);
u32 FUN_004a5210(void);
u32 FUN_004a52a0(void);
u32 FUN_004a5330(void);
u32 FUN_004a5400(void);
u32 FUN_004a5540(u64 param_1);
u32 FUN_004a9330(void);
u32 FUN_004a9550(u32 param_1);
u32 FUN_004a96b0(int param_1);
u32 FUN_004a9bf0(void);
u32 FUN_004a9d80(float *param_1,float *param_2,float *param_3);
u32 FUN_004a9f20(float param_1,float param_2,float param_3,float param_4);
u32 FUN_004aa410(int param_1);
u32 FUN_004aa540(void);
u32 FUN_004aa6c0(void);
u32 FUN_004aada0(u32 param_1,u32 param_2);
u32 FUN_004aae00(u32 param_1,u32 param_2);
u32 FUN_004ab0c0(void);
u32 FUN_004ac870(void);
u32 FUN_004adb80(void);
u32 FUN_004ae010(int param_1);
u32 FUN_004ae8f0(int param_1);
u32 FUN_004ae900(int param_1);
u32 FUN_004af130(u64 param_1);
u32 FUN_00430180(u64 param_1);
u64 FUN_00430060(int param_1);
u64 FUN_00430bb0(int param_1);
u32 FUN_00431110(u64 param_1,YajimaVec2 param_2,char param_3,u8 param_4);
u32 FUN_00431670(int param_1,char param_2,u32 param_3);
u64 FUN_00439f60(int param_1,char param_2);
u64 FUN_00439f60(int param_1,char param_2);
u64 FUN_0043a0b0(u64 param_1,char param_2);
u32 FUN_00447e70(u64 param_1,u8 param_2,u8 param_3);
u64 FUN_0044aaf0(int param_1);
u64 FUN_0044aaf0(int param_1);
u32 FUN_0044ad20(u64 param_1,char param_2);
u32 FUN_0044e560(int param_1);
u32 FUN_004542c0(char param_1);
u32 FUN_00455e00(u32 param_1);
u32 FUN_00455e00(u32 param_1);
u32 FUN_004560d0(u64 param_1,float param_2,float param_3,u32 param_5,u32 param_6,float param_4);
u64 FUN_00457a40(u64 param_1);
u64 FUN_00457a40(u64 param_1);
u32 FUN_00458630(u64 param_1,char param_2,u8 param_3);
u32 FUN_00459f60(u64 param_1,u16 param_2,char param_3);
u64 FUN_0045ee00(u64 param_1,u64 param_2);
u64 FUN_0045f4e0(u64 param_1,int param_2);
u64 FUN_0045f580(u64 param_1,u64 param_2,int param_3,int param_4);
u64 FUN_0045f600(u64 param_1,u64 param_2,char *param_3,int param_4);
u64 FUN_00464020(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
u64 FUN_00464120(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
u64 FUN_004643b0(u64 param_1,int param_2,u32 param_3);
u64 FUN_004654a0(u64 param_1,u64 param_2);
u64 FUN_00465930(u64 param_1,u64 param_2);
u64 FUN_00465a00(u64 param_1);
u64 FUN_00465ae0(u64 param_1);
u64 FUN_00465bf0(u64 param_1,int param_2);
u64 FUN_00465cf0(u64 param_1,u64 param_2,int param_3);
u64 FUN_00465eb0(u64 param_1,u64 param_2,u32 param_3);
u64 FUN_00466260(u32 param_1,u32 *param_2,u32 *param_3,u32 param_4,u64 param_5);
u64 FUN_004663d0(u64 param_1);
u64 FUN_00466480(u32 param_1,int param_2,u32 param_3,u64 param_4);
u64 FUN_00466640(u64 param_1);
u64 FUN_00466ef0(u32 *param_1);
u64 FUN_00467590(u64 param_1);
u64 FUN_00467600(u64 param_1);
u64 FUN_004676c0(u64 param_1);
u64 FUN_004677f0(u64 param_1);
u64 FUN_00467860(u64 param_1,u64 param_2);
u64 FUN_00467b40(u64 param_1,int *param_2);
u64 FUN_00467fd0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00468560(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00468690(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_004687e0(long param_1,int *param_2);
u64 FUN_00468dc0(u64 param_1);
u64 FUN_00468e30(u64 param_1);
u64 FUN_00468ea0(u64 param_1,int param_2);
u64 FUN_00469060(u64 param_1,long param_2);
u64 FUN_00469280(u64 param_1,u32 param_2);
u64 FUN_004692e0(float param_1,u64 param_2);
u64 FUN_00469400(u64 param_1,int param_2);
u64 FUN_004694b0(u64 param_1,u32 param_2);
u64 FUN_00469510(u64 param_1,u32 param_2);
u64 FUN_00469590(u32 param_1,u64 param_2);
u64 FUN_00469770(u64 param_1,int param_2);
u64 FUN_00469840(u64 param_1,u32 param_2,u32 param_3);
u64 FUN_00469940(u64 param_1,u32 *param_2,u32 *param_3);
u64 FUN_004699b0(u64 param_1,u32 param_2,u32 param_3);
u64 FUN_00469a10(u64 param_1,long param_2,long param_3);
u64 FUN_00469d00(u64 param_1);
u64 FUN_00469d60(u64 param_1);
u64 FUN_00469e30(u64 param_1,int param_2);
u64 FUN_00469fe0(u64 param_1);
u64 FUN_0046a040(u64 param_1,int param_2);
u64 FUN_0046a0f0(u64 param_1,u64 param_2,int param_3);
u64 FUN_0046a230(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_0046a470(u64 param_1,int param_2);
u64 FUN_0046a600(u64 param_1);
u64 FUN_0046a660(u64 param_1);
u64 FUN_0046a830(u64 param_1);
u64 FUN_0046a970(u64 param_1,int param_2);
u64 FUN_0046aa80(u64 param_1,u32 *param_2);
u64 FUN_0046ac30(u64 param_1);
u64 FUN_0046ad80(u32 *param_1);
u64 FUN_0046afa0(u32 *param_1);
u64 FUN_0046b8e0(int param_1);
u64 FUN_0046c330(u64 param_1,u32 param_2);
u64 FUN_0046c5b0(int param_1);
u64 FUN_0046cd90(int param_1);
u64 FUN_0046d6f0(int param_1);
u64 FUN_0046e170(int param_1);
u64 FUN_0046eb90(int param_1,u32 *param_2);
u64 FUN_0046f400(u32 *param_1,u32 *param_2);
u64 FUN_0046fdd0(int param_1);
u64 FUN_00470200(float *param_1,float *param_2);
u64 FUN_004709e0(int param_1);
u64 FUN_00470e10(u32 *param_1,u32 *param_2);
u64 FUN_00471470(int param_1);
u64 FUN_004718a0(int param_1,u32 *param_2);
u64 FUN_00472270(int param_1);
u64 FUN_00472970(int param_1);
u64 FUN_004733c0(int param_1,int param_2);
u64 FUN_004734d0(u64 param_1);
u64 FUN_00474160(u64 param_1);
u64 FUN_004747f0(u64 param_1);
u64 FUN_00474820(int param_1,long param_2,u32 param_3);
u64 FUN_004748c0(int param_1,long param_2);
u64 FUN_004749a0(int param_1,long param_2);
u64 FUN_00474bb0(u64 param_1);
u64 FUN_00474c60(u64 param_1);
u64 FUN_00478520(int param_1);
u64 FUN_00478a70(void);
u64 FUN_00479900(int param_1);
u64 FUN_00479e50(void);
u64 FUN_0047a710(u64 param_1,int *param_2);
u64 FUN_0047b280(u64 param_1,float *param_2,u32 param_3,u8 *param_4);
u64 FUN_0047b750(u64 param_1,float *param_2,u32 param_3,float *param_4);
u64 FUN_0047be10(int param_1,int param_2,u64 param_3);
u64 FUN_00488cd0(u64 param_1);
u64 FUN_00488d40(u64 param_1);
u64 FUN_00489080(u64 param_1,int *param_2);
u64 FUN_00489160(u64 param_1,long param_2);
u64 FUN_00489730(u64 param_1);
u64 FUN_00489840(u64 param_1);
u64 FUN_004898e0(u64 param_1);
u64 FUN_00489960(u64 param_1);
u64 FUN_00489b70(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00489cd0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00489f20(u64 param_1,u64 param_2,int param_3,u64 param_4,u64 param_5);
u64 FUN_0048a2a0(u64 param_1,u32 param_2);
u64 FUN_0048a2e0(u64 param_1,int param_2);
u64 FUN_0048a370(u64 param_1);
u64 FUN_0048a4b0(u64 param_1);
u64 FUN_0048a790(u64 param_1);
u64 FUN_0048a800(u64 param_1,int param_2);
u64 FUN_0048ac10(u64 param_1,long param_2);
u64 FUN_0048b910(u64 param_1,float *param_2);
u64 FUN_0048cf00(u64 param_1);
u64 FUN_0048cfa0(u64 param_1);
u64 FUN_0048d0e0(u64 param_1);
u64 FUN_0048d270(int param_1,int param_2,u64 param_3);
u64 FUN_0048d370(u64 param_1,int param_2,u32 *param_3);
u64 FUN_0048d480(float param_1,int param_2,long param_3,u64 param_4,long param_5);
u64 FUN_0048d960(u64 param_1);
u64 FUN_0048e020(int *param_1,u64 param_2);
u64 FUN_0048e2d0(int *param_1,u64 param_2);
u64 FUN_0048e750(long param_1,u64 param_2);
u64 FUN_0048eab0(u64 param_1,int param_2);
u64 FUN_0048eb50(u64 param_1,int param_2,int param_3);
u64 FUN_0048ec20(u64 param_1,u64 param_2,int param_3,int param_4);
u64 FUN_0048ecf0(u64 param_1,u64 param_2,int param_3,int param_4);
u64 FUN_0048f340(u64 param_1,int param_2);
u64 FUN_0048f3c0(u64 param_1,u64 param_2,int param_3);
u64 FUN_0048f460(u64 param_1,int param_2);
u64 FUN_0048f4e0(u64 param_1,u64 param_2,int param_3);
u64 FUN_00490770(u64 param_1,u64 param_2,int param_3);
u64 FUN_00490810(u64 param_1);
u64 FUN_00490860(u64 param_1);
u64 FUN_004908d0(u64 param_1,int param_2);
u64 FUN_00490980(u64 param_1,u64 param_2);
u64 FUN_00490d00(u64 param_1);
u64 FUN_00490d40(u64 param_1);
u64 FUN_00490d90(u64 param_1);
u64 FUN_00491410(u64 param_1);
u64 FUN_004914d0(u64 param_1,int param_2);
u64 FUN_00491630(u64 param_1);
u64 FUN_004916d0(u64 param_1,code *param_2,u64 param_3);
u64 FUN_00491760(u64 param_1,code *param_2,u64 param_3);
u64 FUN_004917f0(u64 param_1,code *param_2,u64 param_3);
u64 FUN_004919b0(u64 param_1,int param_2,u32 param_3);
u64 FUN_00491ff0(u64 param_1,int param_2);
u64 FUN_00492020(u64 param_1,int param_2);
u64 FUN_00492060(u64 param_1,int param_2);
u64 FUN_00492d10(u64 param_1);
u64 FUN_00492e20(u64 param_1,float *param_2);
u64 FUN_00493210(u64 param_1,u16 *param_2,u16 param_3,u16 param_4, u16 param_5);
u64 FUN_00493230(u64 param_1,int param_2,long param_3);
u64 FUN_004932c0(u64 param_1,code *param_2,u64 param_3);
u64 FUN_00493370(u64 param_1,u16 param_2);
u64 FUN_004933d0(u64 param_1);
u64 FUN_00493b40(u64 param_1);
u64 FUN_004944b0(u64 param_1,u32 *param_2);
u64 FUN_004948b0(u64 param_1);
u64 FUN_00494930(u64 param_1,int param_2);
u64 FUN_004949c0(u64 param_1,int param_2);
u64 FUN_00494a40(u64 param_1,u64 param_2,int param_3);
u64 FUN_00494ae0(u64 param_1,int param_2);
u64 FUN_00494b70(u64 param_1);
u64 FUN_00494d50(u64 param_1,long param_2);
u64 FUN_00495260(u64 param_1);
u64 FUN_00495300(u64 param_1);
u64 FUN_00495a30(u64 param_1,int param_2);
u64 FUN_00495cf0(u64 param_1,u32 param_2,u16 param_3,u16 param_4, u16 param_5,u16 param_6,u16 param_7,u16 param_8, u16 param_9);
u64 FUN_00495f10(u64 param_1,code *param_2,u64 param_3);
u64 FUN_00495fb0(u32 *param_1,char *param_2,u64 param_3,u64 param_4);
u64 FUN_004967a0(u64 param_1);
u64 FUN_00496be0(u32 param_1,u32 *param_2,int param_3,u32 *param_4);
u64 FUN_00498720(int param_1,u64 param_2,u32 param_3);
u64 FUN_00499320(u64 param_1);
u64 FUN_00499a80(u64 param_1);
u64 FUN_00499af0(u64 param_1,int param_2);
u64 FUN_00499b90(u64 param_1);
u64 FUN_00499ca0(u64 param_1,code *param_2,u64 param_3);
u64 FUN_00499d30(u64 param_1);
u64 FUN_00499fd0(u64 param_1);
u64 FUN_0049a250(u64 param_1);
u64 FUN_0049a3d0(u64 param_1,code *param_2);
u64 FUN_0049a7c0(u64 param_1,code *param_2,u64 param_3);
u64 FUN_0049a870(u64 param_1,code *param_2,u64 param_3);
u64 FUN_0049aaf0(u64 param_1,int param_2);
u64 FUN_0049abf0(u64 param_1);
u64 FUN_0049ade0(u64 param_1,int param_2);
u64 FUN_0049ae30(u64 param_1);
u64 FUN_0049b180(u64 param_1);
u64 FUN_0049b2e0(u64 param_1);
u64 FUN_0049b3f0(u64 param_1,int param_2);
u64 FUN_0049b440(u64 param_1);
u64 FUN_0049b760(u64 param_1,int param_2);
u64 FUN_0049b7a0(u64 param_1);
u64 FUN_0049b850(u64 param_1,int param_2);
u64 FUN_0049bbc0(u64 param_1,u64 param_2);
u64 FUN_0049bbf0(u64 param_1,u64 param_2);
u64 FUN_0049bc20(u64 param_1,u64 param_2);
u64 FUN_0049bdc0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_0049c160(u64 param_1,int param_2);
u64 FUN_0049c1b0(u64 param_1,int param_2);
u64 FUN_0049c1e0(u64 param_1,int param_2);
u64 FUN_0049c240(u64 param_1,u64 param_2);
u64 FUN_0049c330(u64 param_1,code *param_2,u64 param_3);
u64 FUN_0049c3d0(u64 param_1,int param_2);
u64 FUN_0049c480(u64 param_1,int param_2);
u64 FUN_0049dc70(int param_1);
u64 FUN_0049e5a0(u64 param_1,int param_2);
u64 FUN_0049e830(u64 param_1,u64 param_2);
u64 FUN_0049e9f0(u64 param_1,u64 param_2);
u64 FUN_0049ee70(u64 param_1,u64 param_2);
u64 FUN_0049f040(u64 param_1,u64 param_2);
u64 FUN_0049faa0(u64 param_1);
u64 FUN_004a0430(u64 param_1,int param_2);
u64 FUN_004a0e00(int param_1);
u64 FUN_004a30d0(int param_1);
u64 FUN_004a3f20(u64 param_1);
u64 FUN_004a4d60(u64 param_1,int param_2);
u64 FUN_004a4da0(u64 param_1);
u64 FUN_004a4e40(u64 param_1);
u64 FUN_004a4ef0(u64 param_1);
u64 FUN_004a55b0(u64 param_1,float *param_2,float *param_3,float *param_4,float *param_5, float *param_6,float *param_7);
u64 FUN_004a5dd0(u64 param_1,u8 *param_2,u8 *param_3,u8 *param_4,u64 param_5);
u64 FUN_004a6200(u64 param_1,float *param_2,float *param_3,float *param_4,float *param_5);
u64 FUN_004a62e0(u64 param_1,long param_2);
u64 FUN_004a6360(u64 param_1,int param_2,u64 param_3);
u64 FUN_004a6530(u64 param_1,u64 param_2);
u64 FUN_004a6600(u64 param_1);
u64 FUN_004a7620(u64 param_1);
u64 FUN_004ab1b0(u64 param_1);
u64 FUN_004ab200(u32 param_1,u32 param_2,u64 param_3);
u64 FUN_004ab2c0(float param_1,float param_2,u64 param_3);
u64 FUN_004ab410(float param_1,float param_2,float param_3,float param_4,float param_5,float param_6, u64 param_7);
u64 FUN_004ab6a0(u64 param_1);
u64 FUN_004abd50(u64 param_1,u32 *param_2);
u64 FUN_004ac020(int *param_1,u64 param_2);
u64 FUN_004ac920(u64 param_1,int param_2,u64 param_3);
u64 FUN_004acb10(u64 param_1,u64 param_2);
u64 FUN_004ad480(u64 param_1,char *param_2);
u64 FUN_004ad5b0(u64 param_1,long param_2,u64 param_3);
u64 FUN_004ad6a0(int param_1);
u64 FUN_004ad700(u64 param_1,u64 param_2);
u64 FUN_004ad750(u64 param_1);
u64 FUN_004ad940(u64 param_1,u64 param_2);
u64 FUN_004adbd0(int *param_1);
u64 FUN_004adcc0(u64 param_1,u32 param_2);
u64 FUN_004addb0(u64 param_1,u64 param_2);
u64 FUN_004ade90(u64 param_1);
u64 FUN_004adf30(u64 param_1);
u64 FUN_004adfd0(u64 param_1,int param_2);
u64 FUN_004ae020(u64 param_1,u32 *param_2);
u64 FUN_004ae070(u32 param_1,u32 param_2,u64 param_3);
u64 FUN_004ae0c0(u32 param_1,u32 param_2,u64 param_3);
u64 FUN_004ae110(u64 param_1,u64 param_2);
u64 FUN_004ae150(u64 param_1,u64 param_2);
u32 FUN_004ae1d0(u32 param_1,u32 param_2);
u64 FUN_004ae1f0(int param_1,u32 *param_2);
u64 FUN_004ae270(u64 param_1,u64 param_2);
u64 FUN_004ae2f0(u64 param_1);
u64 FUN_004ae3b0(u64 param_1,u64 param_2);
u64 FUN_004ae690(u64 param_1);
u64 FUN_004ae790(u64 param_1);
u64 FUN_004ae960(u64 param_1,float *param_2,float *param_3);
u64 FUN_004aeb60(u64 param_1,code *param_2,u64 param_3);
u64 FUN_004aebf0(u64 param_1,u64 param_2,long param_3);
u32 FUN_004aef50(u32 param_1);
u64 FUN_004aef60(u64 param_1);
u64 FUN_004af340(u32 *param_1);
u64 FUN_004af760(u64 param_1);
u64 FUN_004af9d0(u64 param_1,float *param_2,float *param_3);
u64 FUN_004affe0(u64 param_1,u64 param_2,long param_3);
u8 * FUN_00493710(int param_1,int param_2,u32 param_3);
u8 * FUN_004aae60(void);
u8 ** FUN_0049ff00(void);
u8 ** FUN_004a3f10(void);
u32 FUN_00435260(char param_1);
s8 FUN_004353f0(int param_1);
u8 FUN_00435810(void);
u8 FUN_004359f0(int param_1,u8 param_2,u8 param_3,u32 *param_4, u8 param_5,u8 param_6);
u8 FUN_0043c730(char param_1);
char FUN_0043c7f0(char param_1);
char FUN_00449c90(u64 param_1,char param_2);
char FUN_0044a420(int param_1,int param_2,int param_3);
u32 FUN_0044f060(float param_1,int param_2,float *param_3);
u32 FUN_0044f1c0(float param_1,float *param_2,float *param_3);
u8 FUN_0044fab0(int param_1);
char FUN_00453480(void);
u32 FUN_00454400(f32 *param_1,char param_2);
u32 FUN_00454520(float *param_1,char param_2);
u8 FUN_00454a70(char param_1,RwV3d param_2);
u8 FUN_00454d00(RwV3d param_1);
char FUN_00457390(char param_1);
char FUN_004573d0(char param_1);
int FUN_0045a3b0(void);
u8 FUN_0045af90(int param_1);
int FUN_0045b480(int param_1);
int FUN_0045b4b0(int param_1);
u8 FUN_0045e010(int param_1);
u8 FUN_0045e0c0(int param_1);
u8 FUN_0045e170(int param_1);
u8 FUN_0045ec00(void);
u8 FUN_0045ec20(void);
u8 FUN_0045f7d0(void);
u8 FUN_004661b0(void);
u8 FUN_00468c50(void);
u8 FUN_0046a530(void);
u8 FUN_00473590(void);
u8 FUN_00477050(int param_1);
u8 FUN_00479030(int param_1);
u8 FUN_0047a3d0(int param_1);
u8 FUN_00488fe0(void);
u8 FUN_0048ad20(void);
u8 FUN_0048dcf0(void);
u8 FUN_0048f030(void);
u8 FUN_004915c0(void);
u8 FUN_0049a980(void);
u8 FUN_0049be50(void);
u8 FUN_0049c6c0(void);
u8 FUN_004a5100(void);
u8 FUN_004a9bd0(int param_1);
u8 FUN_004aa390(float param_1);
u8 FUN_004aa3d0(float param_1);
u8 FUN_004aaa60(void);
u8 FUN_004aab40(long param_1);
u8 FUN_004aac70(u32 *param_1);
u8 FUN_004ac390(long param_1);
u8 FUN_004accc0(float *param_1,int *param_2);
u8 FUN_004ae1e0(int param_1);
u8 FUN_004ae4e0(int param_1);
u8 FUN_004ae5a0(long param_1);
void FUN_00430150(int param_1);
void FUN_00430220(int param_1,u64 param_2);
void FUN_00430270(RwV4d* output, int object);
void FUN_004302a0(int param_1);
void FUN_004302b0(void);
void FUN_00430630(int param_1);
void FUN_00430780(u64 param_1,int param_2,int param_3,int param_4);
void FUN_00430a40(char param_1);
void FUN_004310e0(int param_1);
void FUN_004311f0(void *param_1,u32 param_2,u32 param_3);
void FUN_00431630(int param_1);
void FUN_004332f0(int param_1);
void FUN_004333d0(int param_1);
void FUN_004334d0(int param_1);
void FUN_004343d0(int param_1);
void FUN_004344f0(float *param_2,float param_1,int param_3,float *param_4,float *param_5);
void FUN_00434c90(char param_1);
void FUN_00434d30(void);
void FUN_00434e60(void);
void FUN_00434f60(u8 param_1);
void FUN_00434f70(void);
void FUN_00435060(u8 param_1);
void FUN_004350e0(char param_1,char param_2);
void FUN_00435370(u8 param_1);
void FUN_00435c00(int param_1);
void FUN_00437e00(void);
void FUN_00437e80(u32 *param_1,char param_2);
void FUN_00438010(int param_1);
void FUN_00439400(char param_1);
void FUN_00439520(int param_1);
void FUN_0043a1a0(char param_1,u8 param_2);
void FUN_0043a2f0(int param_1);
void FUN_0043a960(int param_1);
void FUN_0043bf50(u64 param_1);
void FUN_0043c660(int param_1);
void FUN_0043c7a0(char param_1,u8 param_2);
void FUN_00447ad0(int param_1);
void FUN_00447f90(float *param_1,int param_2,char param_3);
void FUN_00448060(int param_1,u8 param_2,u64 param_3,char param_4,short param_5, char param_6);
void FUN_00448cf0(int param_1,u8 param_2,u64 param_3,char param_4,short param_5, char param_6,int param_7);
void FUN_00449d10(int param_1);
void FUN_00449d60(int param_1);
void FUN_00449ed0(void);
void FUN_00449fa0(void);
void FUN_0044a240(float param_1,float param_2,float param_3,float param_4,int param_5 ,char param_6);
void FUN_0044a330(float param_1,float param_2,float param_3,float param_4,int param_5 ,char param_6);
void FUN_0044a630(int param_1);
void FUN_0044a790(u32 *param_1);
void FUN_0044a990(int param_1,u32 *param_2);
void FUN_0044acf0(int param_1);
void FUN_0044af60(u32 param_1);
void FUN_0044b7d0(int param_1);
void FUN_0044beb0(int param_1);
void FUN_0044d600(int param_1);
void FUN_0044dfc0(int param_1);
void FUN_0044e530(int param_1,u8 param_2);
void FUN_0044f270(float *param_1,float *param_2);
void FUN_004501b0(char param_1);
void FUN_00450b30(char param_1);
void FUN_00451d70(int param_1);
void FUN_00452010(float *param_1);
void FUN_00452f70(u32 *param_1,int param_2);
void FUN_004532d0(char param_1);
void FUN_004533e0(u8 param_1);
void FUN_00453470(u16 param_1);
void FUN_00453490(int param_1);
void FUN_00453d90(char param_1);
void FUN_00454110(int param_1);
void FUN_00454290(int param_1);
void FUN_004543c0(char param_1,u8 param_2);
void FUN_00454f50(char param_1,char param_2);
void FUN_00455b50(void);
void FUN_00455cf0(void);
void FUN_00456050(int param_1);
void FUN_004561d0(float param_1,float param_2,int param_3);
void FUN_004561f0(float param_1,int param_2);
void FUN_004563b0(f32 param_1, int param_2);
void FUN_004563c0(int param_1,u8 param_2);
void FUN_004563d0(int object, RwV2d value);
void FUN_00456400(int param_1,u8 param_2);
void FUN_00456410(char param_1);
void FUN_00456450(char param_1);
void FUN_00456490(char param_1);
void FUN_004564e0(char param_1);
void FUN_00456530(char param_1);
void FUN_00456580(char param_1);
void FUN_004565d0(char param_1);
void FUN_00456620(char param_1);
void FUN_00456670(u64 param_1,u64 param_2);
void FUN_00456a90(u32 param_1,char param_2,char param_3);
void FUN_00456ea0(u64 param_1,u64 param_2,u64 param_3);
void FUN_00457340(char param_1,u8 param_2,char param_3);
void FUN_00457980(int param_1);
void FUN_00458600(int param_1);
void FUN_00458850(int param_1);
void FUN_00458870(int param_1);
void FUN_00458890(void);
void FUN_00458920(int param_1);
void FUN_00458930(void);
void FUN_004589d0(int param_1,u8 param_2);
void FUN_00458b00(void);
void FUN_00458b60(void);
void FUN_00458bb0(void);
void FUN_00459d60(void);
void FUN_00459f30(int param_1);
void FUN_0045a220(int param_1);
void FUN_0045a3e0(void);
void FUN_0045a430(char param_1);
void FUN_0045a490(void);
void FUN_0045ace0(void);
void FUN_0045af70(u8 param_1);
void FUN_0045b620(u32 param_5,float param_1,float param_2,float param_3,float param_4,u8 param_6,int param_7);
void FUN_0045b830(int param_1,long param_2);
void FUN_0045b8f0(int param_1);
void FUN_0045bcb0(int param_1,u64 param_2);
void FUN_0045bd90(int param_1);
void FUN_0045c530(int param_1);
void FUN_0045c8c0(int param_1,int param_2);
void FUN_0045cdd0(int param_1,long param_2);
void FUN_0045ce90(int param_1);
void FUN_0045d990(int param_1,long param_2);
void FUN_0045e7b0(int param_1);
void FUN_0045e7e0(void);
void FUN_0045ea80(int param_1);
void FUN_0045edc0(void);
void FUN_0045f930(int param_1,float *param_2,code *param_3,u32 param_4);
void FUN_004606b0(int param_1,u64 param_2,code *param_3,u32 param_4);
void FUN_00460ec0(int param_1,u64 param_2,u32 param_3,code *param_4,u32 param_5);
void FUN_00461900(int param_1,float *param_2,u64 param_3,code *param_4,u32 param_5);
void FUN_00461d00(int param_1,u64 param_2,u32 param_3,code *param_4,u32 param_5);
void FUN_00461ea0(int param_1,float *param_2,u32 param_3,code *param_4,u32 param_5);
void FUN_00462bb0(int param_1,u64 param_2,u32 param_3,code *param_4,u32 param_5);
void FUN_00463490(int param_1,int param_2,float *param_3,u32 param_4,code *param_5, u32 param_6);
void FUN_00463b20(int param_1,int param_2,int param_3,u32 param_4,code *param_5, u32 param_6);
void FUN_00463f20(int param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00464850(float param_1,int param_2,int param_3,int param_4);
void FUN_00464e80(float param_1,int param_2,int param_3,int param_4);
void FUN_00465670(int param_1,int param_2);
void FUN_00468530(u64 param_1,u64 param_2,int param_3);
void FUN_00468660(u64 param_1,u64 param_2,int param_3);
void FUN_00468720(char *param_1,long param_2,int param_3);
void FUN_00469aa0(int param_1);
void FUN_00469b50(int param_1);
void FUN_00469bc0(int param_1);
void FUN_0046a8d0(int *param_1,int *param_2);
void FUN_0046a9e0(int *param_1);
void FUN_0046b1b0(u32 *param_1,int param_2,u32 *param_3);
void FUN_0046ea80(u64 param_1);
void FUN_00472130(u64 param_1);
void FUN_00472170(u64 param_1);
void FUN_004721b0(u64 param_1);
void FUN_004721f0(u64 param_1);
void FUN_00472230(u64 param_1);
void FUN_00473340(u64 param_1);
void FUN_00473380(u64 param_1);
void FUN_00474210(u64 param_1,u64 param_2,u64 param_3);
void FUN_00474d30(int param_1,int param_2);
void FUN_00474f20(int param_1,u32 param_2);
void FUN_00475c20(int param_1);
void FUN_00475cb0(int param_1);
void FUN_00476140(u32 *param_1,long param_2,u32 param_3);
void FUN_00476490(u64 *param_1,long param_2,u64 *param_3);
void FUN_00476720(int param_1,long param_2,u64 *param_3);
void FUN_00476980(int param_1,long param_2,u64 *param_3);
void FUN_00476c20(int param_1,int param_2,long param_3);
void FUN_00477150(int *param_1,int param_2,u64 param_3,u64 param_4,u32 param_5);
void FUN_00477470(int *param_1,u64 param_2,u64 param_3,u64 param_4, u32 param_5);
void FUN_00477610(int *param_1,u64 param_2,u64 param_3,int param_4,int param_5);
void FUN_00477810(u32 *param_1,int param_2,int param_3);
void FUN_00477a20(u32 *param_1,int param_2,int param_3);
void FUN_00477c90(int *param_1,int param_2,int param_3);
void FUN_00477eb0(int *param_1,int param_2,int param_3);
void FUN_00478100(int *param_1,int param_2,int param_3);
void FUN_00478280(int *param_1,int param_2,int param_3);
void FUN_00478cc0(int param_1,u32 *param_2);
void FUN_00479170(int *param_1,int param_2,u64 param_3,u64 param_4,u32 param_5);
void FUN_00479590(int *param_1,u64 param_2,u64 param_3,u64 param_4, u32 param_5);
void FUN_0047a050(int param_1,u32 *param_2);
void FUN_0047bf80(int param_1);
void FUN_0047c240(u32 *param_1,float *param_2,float *param_3,int param_4,int param_5);
void FUN_0047c8c0(u32 *param_1,float *param_2,float *param_3,int param_4,int param_5);
void FUN_004838e0(u32 *param_1,int param_2,int param_3);
void FUN_00485070(u32 *param_1,int param_2,int param_3);
void FUN_00485110(u32 *param_1,int param_2,int param_3);
void FUN_00485440(u32 *param_1,int param_2,int param_3);
void FUN_00485750(int *param_1,int param_2,int param_3);
void FUN_00485e20(int *param_1,int param_2,int param_3);
void FUN_00485ef0(int *param_1,int param_2,int param_3);
void FUN_00485ff0(int *param_1,int param_2,int param_3);
void FUN_004866c0(int param_1);
void FUN_00486c80(int *param_1,float *param_2,float *param_3,int param_4,int param_5);
void FUN_00487030(int *param_1,float *param_2,float *param_3,int param_4,int param_5);
void FUN_00487280(int *param_1,float *param_2,float *param_3,int param_4,int param_5);
void FUN_004876f0(int *param_1,float *param_2,float *param_3,long param_4,int param_5);
void FUN_00487bf0(u32 *param_1,int param_2,int param_3);
void FUN_00488550(int *param_1,int param_2,int param_3,int param_4,u32 param_5);
void FUN_00489350(u64 param_1,long param_2);
void FUN_004893e0(int param_1,int param_2,u32 param_3);
void FUN_00489460(int param_1,u32 *param_2,int *param_3,int param_4,u32 *param_5,u32 param_6);
void FUN_0048a3f0(u64 param_1,long param_2);
void FUN_0048dd70(int *param_1);
void FUN_0048de50(int *param_1,int *param_2);
void FUN_0048e610(int *param_1);
void FUN_0048efa0(int param_1,int param_2,u32 param_3);
void FUN_0048efc0(int param_1, int param_2, f32 param_3);
void FUN_00491100(int param_1);
void FUN_00492c30(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00492c60(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00492c90(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00492cc0(u64 param_1,u64 param_2);
void FUN_00492ce0(u64 param_1,u64 param_2);
void FUN_00492d00(u64 param_1);
void FUN_00493c50(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00493c80(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00494520(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00494550(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00494db0(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00494de0(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00494e10(u64 param_1,u64 param_2);
void FUN_00495480(int *param_1,int param_2);
void FUN_004959c0(u64 param_1);
void FUN_00496580(void);
void FUN_00496ad0(u64 param_1,int *param_2,short param_3,short param_4,int param_5, int param_6);
void FUN_00496f60(int param_1,int param_2,long param_3);
void FUN_00498e30(u64 param_1);
void FUN_00499230(void);
void FUN_00499250(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00499280(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_004992b0(u64 param_1,u64 param_2);
void FUN_004992d0(u64 param_1,u64 param_2);
void FUN_00499720(u64 param_1);
void FUN_00499850(int *param_1);
void FUN_00499e90(u32 param_1,u32 param_2);
void FUN_00499f40(int param_1);
void FUN_0049a920(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_0049a950(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_0049afa0(int param_1,u64 param_2);
void FUN_0049be20(int param_1);
void FUN_0049c680(void);
void FUN_0049c9b0(void);
void FUN_0049ca50(long param_1);
void FUN_0049cab0(float param_1,u8 *param_2);
void FUN_0049cbd0(int param_1,float *param_2);
void FUN_0049cc30(int param_1);
void FUN_0049e4f0(u64 param_1);
void FUN_0049ff10(u32 param_1,u32 param_2,int param_3,long param_4);
void FUN_004a0480(int param_1,int param_2);
void FUN_004a05d0(int param_1,int param_2);
void FUN_004a06c0(int param_1);
void FUN_004a08f0(int param_1,int *param_2,int param_3,u32 param_4);
void FUN_004a0dc0(int param_1);
void FUN_004a24a0(int param_1,int param_2);
void FUN_004a2560(u64 param_1,int *param_2);
void FUN_004a3540(int param_1);
void FUN_004a3f70(int param_1,u32 *param_2);
void FUN_004a53b0(void);
void FUN_004a91f0(void);
void FUN_004a97c0(u64 param_1,u64 param_2);
void FUN_004a9a70(int param_1);
void FUN_004aa550(u64 param_1);
void FUN_004aa5c0(void);
void FUN_004aa620(void);
void FUN_004aad50(void);
void FUN_004ab170(u32 *param_1);
void FUN_004ab910(float *param_1,float *param_2,float *param_3);
void FUN_004aba20(u64 param_1,u64 param_2,int param_3);
void FUN_004ac410(int *param_1);
void FUN_004ac7f0(void);
void FUN_004ac860(u32 param_1,u32 param_2);
void FUN_004adb50(void);
void FUN_004adc70(u64 param_1);
void FUN_004adc90(u64 param_1,u64 param_2);
void FUN_004adca0(void);
void FUN_004ae060(int param_1);
void FUN_004ae940(u64 param_1);









/* W212: first divergence is offset 216 after an exact prefix; the residual begins with
 * retail retaining the divided float in $f2 while this build puts it in $f0.  The
 * FUN_0045b620 template shares calls but not this straight-line float lifetime shape. */




















typedef struct {
  s16 x;
  s16 y;
  s16 previousX;
  s16 previousY;
} YRuntimePathNode;

typedef struct {
  u8 state;
  u8 pad_001[0xf7];
  u8 x;
  u8 y;
  u8 pad_0fa[9];
  u8 targetX;
  u8 targetY;
  u8 pad_105[0x107];
  s32 openCount;
  YRuntimePathNode nodes[256];
  u32 openNodes[256];
} YRuntimePathWork;





#pragma opt_common_subs reset







#pragma opt_loop_invariants reset







#undef fStack_220
#undef fStack_210
#undef fStack_200
#undef fStack_1f0
#undef fStack_1e0
#undef fStack_1d0
#undef fStack_1c0
#undef fStack_1b0
#undef fStack_1a0
#undef fStack_190
#undef fStack_180
#undef fStack_170
#undef fStack_160
#undef fStack_150
#undef fStack_140
#undef fStack_130
#undef fStack_120
#undef fStack_110
#undef fStack_100
#undef fStack_f0
#undef fStack_e0
#undef fStack_d0
#undef fStack_c0
#undef fStack_b0
#undef fStack_a0
#undef fStack_90
#undef fStack_80
#undef uStack_70
#undef uStack_60
#undef fStack_50
#undef fStack_40
#undef auStack_30
#undef auStack_20
#undef afStack_10






#pragma opt_dead_assignments reset






#pragma opt_loop_invariants reset


// The duration values selected by cases 0xc0 through 0xc5 are one contiguous
// six-element vector: the later selector indexes every case, including c4/c5.
// Keeping the last two values as separate scalar locals changes the generated
// stack layout and can eliminate their writes under MWCC alias analysis.
// The signed result from FUN_0017b5b0 also preserves the retail sign path.





#pragma opt_propagation reset
#pragma opt_dead_assignments reset










#pragma opt_propagation reset

#pragma opt_common_subs reset



#pragma opt_propagation reset



#pragma opt_dead_assignments reset

















#pragma opt_lifetimes reset
#pragma opt_propagation reset












#pragma opt_common_subs reset




#pragma opt_propagation reset
#pragma opt_dead_assignments reset

#pragma opt_propagation reset
#pragma opt_dead_assignments reset


/* measured opt_loop_invariants on: 880/864 nd650; off: 864/864 nd109; + opt_lifetimes on: 864/864 nd77; retained */

#pragma opt_loop_invariants reset
#pragma opt_lifetimes reset






/* W212: first divergence is offset 40 (global-base setup and saved work pointer);
 * the 260-byte object deficit confirms a full four-direction path reconstruction,
 * not the matched FUN_00431aa0 dispatch idiom. */









#pragma opt_propagation reset
#undef fStack_20
#undef fStack_1c
#undef fStack_18
#undef fStack_10
#undef fStack_c
#undef fStack_8
#undef fStack_90
#undef fStack_8c
#undef fStack_88


#pragma opt_common_subs reset
#pragma opt_propagation reset

#pragma opt_dead_assignments reset

/* W212: hoisting the first-loop invariants and preserving its distinct one/five
 * values improved nd287 -> nd283 (340 -> 332 bytes).  The remaining offset-0
 * divergence is the combined retail preheader; no window growth was introduced. */
#pragma opt_propagation reset


#pragma opt_lifetimes reset
#pragma opt_propagation reset


// MWCC b210 floor: the mixed-ABI prologue preserves $f14 before $a1/$a2; retail preserves
// $a1, then $a2, then $f14. The remaining body is instruction-identical after relocations.






















// W295: retail reloads row+0x54/row+0x168 for the FUN_001adc20 call (no CSE from the
// previous call) - three volatile-ordered loads reproduce it; not a scheduling floor.

#pragma opt_dead_assignments reset














#pragma alias FUN_002ff760_y2 FUN_002ff760
#pragma alias FUN_003174e0_y2 FUN_003174e0
#pragma alias FUN_003b7090_y2 FUN_003b7090
#pragma alias FUN_00195020_y2 FUN_00195020
extern void FUN_002ff760_y2(u32 param_1);
extern void FUN_003174e0_y2(u32 param_1);
extern void FUN_003b7090_y2(u32 param_1);
#pragma alias FUN_00195020_call2 FUN_00195020
extern void FUN_00195020_call2(u32 param_1);

#pragma opt_dead_assignments reset



#pragma opt_loop_invariants off
#pragma opt_loop_invariants reset









// FUN_0045A430

void FUN_0045a430(char param_1)

{
  int iVar1;
  
  if (iGpffffba08 != 0) {
    iVar1 = *(int *)(iGpffffba08 + 0x3c);
    *(char *)(iVar1 + 0x4c) = param_1;
    if (param_1 == '\0') {
      *(int *)(iVar1 + 0x58) = iGpffffb418 - *(char *)(iVar1 + 0x5c);
    }
    else {
      *(char *)(iVar1 + 0x5c) = (char)(iGpffffb418 - *(int *)(iVar1 + 0x58));
    }
  }
  return;
}

#pragma push
/* W373 singles base 1459/2100; loop 1459/2100; common 1693/2264; life 1460/2100; propagation 1323/1788; strength 1459/2100; dead 1459/2100. */
/* W420 verified: offset-accurate YRuntimeWork view reduced FUN_0045a490 nd1323/object1788 to nd1291/object1776, window2128, rate .7399 -> .7269. */
/* W420 negatives: removing/flattening rate use measured nd1343/object1820; pointer-cast field access measured nd1324/object1788; both reverted. */
#pragma opt_propagation off
// FUN_0045A490 NONMATCHING

void FUN_0045a490(void)

{
  struct YRuntimeWork {
    u32 data0;
    u8 pad08[6];
    u16 value;
    u8 data0c[0x3c];
    float rate;
  } *puVar1;
  int iVar2;
  u32 uVar3;
  u16 uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  puVar1 = *(struct YRuntimeWork **)(iGpffffba08 + 0x3c);
  if (iGpffffba08 != 0) {
    uVar3 = FUN_001158b0(0,puVar1->data0,0);
    iVar2 = (int)uVar3;
    *(char *)(iVar2 + 0x18) = (char)puVar1->value;
    fVar5 = (float)FUN_001126b0_typed((void*)uVar3);
    fVar7 = puVar1->rate;
    fVar8 = 16.0f - fVar7 * (fVar5 / 2.0f);
    fVar6 = (float)FUN_001126b0_typed((void*)uVar3);
    fVar8 += fVar6 / 2.0f;
    fVar5 = (float)FUN_00112740_typed((void*)uVar3);
    fVar7 = puVar1->rate;
    fVar6 = 140.0f - fVar7 * (fVar5 / 2.0f);
    fVar7 = (float)FUN_00112740_typed((void*)uVar3);
    fVar6 += fVar7 / 2.0f;
    *(float *)(iVar2 + 0x10) = fVar8;
    *(float *)(iVar2 + 0x14) = fVar6;
    fVar7 = puVar1->rate;
    fVar5 = fVar7 * 4096.0f;
    if (fVar5 < 2.1474836e+09f) {
      uVar4 = (u16)(int)fVar5;
    }
    else {
      uVar4 = (u16)(int)(fVar5 - 2.1474836e+09f);
    }
    *(u16 *)(iVar2 + 0x28) = uVar4 & 0xff;
    fVar7 = puVar1->rate;
    fVar5 = fVar7 * 4096.0f;
    if (fVar5 < 2.1474836e+09f) {
      uVar4 = (u16)(int)fVar5;
    }
    else {
      uVar4 = (u16)(int)(fVar5 - 2.1474836e+09f);
    }
    *(u16 *)(iVar2 + 0x2a) = uVar4 & 0xff;
    *(float *)(iVar2 + 0x2c) = 5.0f;
    FUN_001127d0(uVar3,1);
    FUN_00115980(uVar3);
    uVar3 = FUN_001158b0(0,puVar1->data0,0x14);
    iVar2 = (int)uVar3;
    fVar7 = puVar1->rate;
    *(float *)(iVar2 + 0x10) = fVar7 * 67.0f + fVar8 + 0.0f;
    *(float *)(iVar2 + 0x14) = fVar7 * 20.0f + fVar6 + 0.0f;
    fVar5 = fVar7 * 4096.0f;
    if (fVar5 < 2.1474836e+09f) {
      uVar4 = (u16)(int)fVar5;
    }
    else {
      uVar4 = (u16)(int)(fVar5 - 2.1474836e+09f);
    }
    *(u16 *)(iVar2 + 0x28) = uVar4 & 0xff;
    fVar7 = puVar1->rate;
    fVar5 = fVar7 * 4096.0f;
    if (fVar5 < 2.1474836e+09f) {
      uVar4 = (u16)(int)fVar5;
    }
    else {
      uVar4 = (u16)(int)(fVar5 - 2.1474836e+09f);
    }
    *(u16 *)(iVar2 + 0x2a) = uVar4 & 0xff;
    *(float *)(iVar2 + 0x2c) = 4.0f;
    FUN_001127d0(uVar3,1);
    FUN_00115980(uVar3);
    uVar3 = FUN_001158b0(0,puVar1->data0,*(char *)((u8 *)puVar1 + 0x54) + 10);
    iVar2 = (int)uVar3;
    *(char *)(iVar2 + 0x18) = (char)puVar1->value;
    fVar7 = puVar1->rate;
    *(float *)(iVar2 + 0x10) = fVar7 * 8.0f + fVar8 + 0.0f;
    *(float *)(iVar2 + 0x14) = fVar7 * 20.0f + fVar6 + 0.0f;
    fVar5 = fVar7 * 4096.0f;
    if (fVar5 < 2.1474836e+09f) {
      uVar4 = (u16)(int)fVar5;
    }
    else {
      uVar4 = (u16)(int)(fVar5 - 2.1474836e+09f);
    }
    *(u16 *)(iVar2 + 0x28) = uVar4 & 0xff;
    fVar7 = puVar1->rate;
    fVar5 = fVar7 * 4096.0f;
    if (fVar5 < 2.1474836e+09f) {
      uVar4 = (u16)(int)fVar5;
    }
    else {
      uVar4 = (u16)(int)(fVar5 - 2.1474836e+09f);
    }
    *(u16 *)(iVar2 + 0x2a) = uVar4 & 0xff;
    *(float *)(iVar2 + 0x2c) = 4.0f;
    FUN_001127d0(uVar3,1);
    FUN_00115980(uVar3);
    uVar3 = FUN_001158b0(0,puVar1->data0,*(char *)((u8 *)puVar1 + 0x55) + 10);
    iVar2 = (int)uVar3;
    *(char *)(iVar2 + 0x18) = (char)puVar1->value;
    fVar7 = puVar1->rate;
    *(float *)(iVar2 + 0x10) = fVar7 * 38.0f + fVar8 + 0.0f;
    *(float *)(iVar2 + 0x14) = fVar7 * 20.0f + fVar6 + 0.0f;
    fVar5 = fVar7 * 4096.0f;
    if (fVar5 < 2.1474836e+09f) {
      uVar4 = (u16)(int)fVar5;
    }
    else {
      uVar4 = (u16)(int)(fVar5 - 2.1474836e+09f);
    }
    *(u16 *)(iVar2 + 0x28) = uVar4 & 0xff;
    fVar7 = puVar1->rate;
    fVar5 = fVar7 * 4096.0f;
    if (fVar5 < 2.1474836e+09f) {
      uVar4 = (u16)(int)fVar5;
    }
    else {
      uVar4 = (u16)(int)(fVar5 - 2.1474836e+09f);
    }
    *(u16 *)(iVar2 + 0x2a) = uVar4 & 0xff;
    *(float *)(iVar2 + 0x2c) = 4.0f;
    FUN_001127d0(uVar3,1);
    FUN_00115980(uVar3);
    uVar3 = FUN_001158b0(0,puVar1->data0,*(char *)((u8 *)puVar1 + 0x56) + 10);
    iVar2 = (int)uVar3;
    *(char *)(iVar2 + 0x18) = (char)puVar1->value;
    fVar7 = puVar1->rate;
    *(float *)(iVar2 + 0x10) = fVar7 * 76.0f + fVar8 + 0.0f;
    *(float *)(iVar2 + 0x14) = fVar7 * 20.0f + fVar6 + 0.0f;
    fVar5 = fVar7 * 4096.0f;
    if (fVar5 < 2.1474836e+09f) {
      uVar4 = (u16)(int)fVar5;
    }
    else {
      uVar4 = (u16)(int)(fVar5 - 2.1474836e+09f);
    }
    *(u16 *)(iVar2 + 0x28) = uVar4 & 0xff;
    fVar7 = puVar1->rate;
    fVar5 = fVar7 * 4096.0f;
    if (fVar5 < 2.1474836e+09f) {
      uVar4 = (u16)(int)fVar5;
    }
    else {
      uVar4 = (u16)(int)(fVar5 - 2.1474836e+09f);
    }
    *(u16 *)(iVar2 + 0x2a) = uVar4 & 0xff;
    *(float *)(iVar2 + 0x2c) = 4.0f;
    FUN_001127d0(uVar3,1);
    FUN_00115980(uVar3);
    uVar3 = FUN_001158b0(0,puVar1->data0,*(char *)((u8 *)puVar1 + 0x57) + 10);
    iVar2 = (int)uVar3;
    *(char *)(iVar2 + 0x18) = (char)puVar1->value;
    fVar7 = puVar1->rate;
    *(float *)(iVar2 + 0x10) = fVar7 * 106.0f + fVar8 + 0.0f;
    *(float *)(iVar2 + 0x14) = fVar7 * 20.0f + fVar6 + 0.0f;
    fVar5 = fVar7 * 4096.0f;
    if (fVar5 < 2.1474836e+09f) {
      uVar4 = (u16)(int)fVar5;
    }
    else {
      uVar4 = (u16)(int)(fVar5 - 2.1474836e+09f);
    }
    *(u16 *)(iVar2 + 0x28) = uVar4 & 0xff;
    fVar7 = puVar1->rate;
    fVar5 = fVar7 * 4096.0f;
    if (fVar5 < 2.1474836e+09f) {
      uVar4 = (u16)(int)fVar5;
    }
    else {
      uVar4 = (u16)(int)(fVar5 - 2.1474836e+09f);
    }
    *(u16 *)(iVar2 + 0x2a) = uVar4 & 0xff;
    *(float *)(iVar2 + 0x2c) = 4.0f;
    FUN_001127d0(uVar3,1);
    FUN_00115980(uVar3);
  }
  return;
}

// Native `(u8)fVar8` costs +4 bytes (624/608 versus 620/608); retail keeps the expanded conversion.
#pragma pop
#pragma opt_propagation reset
#pragma push
/* W380 measured: without 632/608 nd408 (OVER window); opt_loop_invariants off 608/608 nd284.
   Restores the setting this function previously received from a leaked file-scope pragma. */
#pragma opt_loop_invariants off
/* W419 declaration-order probe: lVar5-first lowers FUN_0045ACE0 from nd284/object608 to nd274/object608; retained. */
// FUN_0045ACE0 NONMATCHING

void FUN_0045ace0(void)

{
  int lVar5;
  u32 uVar2;
  char cVar3;
  u32 iVar4;
  u32 *puVar1;
  int iVar6;
  u8 uVar7;
  float fVar8;
  
  if (iGpffffba08 != 0) {
    puVar1 = *(u32 **)(iGpffffba08 + 0x3c);
    if ((*(char *)(puVar1 + 0x13) == '\0') && (puVar1[0x14] != 0)) {
      *(char *)((int)puVar1 + 0x43) = uGpffffb418 - puVar1[0x16];
    }
    for (lVar5 = 0; lVar5 < 9; lVar5++) {
      if (*(char *)((int)puVar1 + 0x42) == lVar5) {
        iVar4 = (int)lVar5 * 6;
        uVar2 = FUN_001158b0(0,*puVar1,((u8 *)DAT_006b4b80)[iVar4]);
        fVar8 = (float)FUN_0052e878_typed(fGpffff82d8 * (float)(int)*(char *)((int)puVar1 + 0x43));
        fVar8 = fVar8 * -255.0f + 255.0f;
        if (fVar8 >= 2.1474836e+09f) {
          uVar7 = (u8)(int)(fVar8 - 2.1474836e+09f);
        }
        else {
          uVar7 = (u8)(int)fVar8;
        }
        iVar6 = (int)uVar2;
        *(u8 *)(iVar6 + 0x18) = uVar7;
        *(float *)(iVar6 + 0x10) = (float)(int)*(short *)((u8 *)DAT_006b4b82 + iVar4);
        *(float *)(iVar6 + 0x14) = (float)(int)*(short *)((u8 *)DAT_006b4b84 + iVar4);
        *(float *)(iVar6 + 0x2c) = 3.0f;
        FUN_001127d0(uVar2,1);
        FUN_00115980_arg(uVar2);
      }
    }
    if (((*(char *)(puVar1 + 0x13) == '\0') && (puVar1[0x14] != 0)) &&
       (!(*(char *)((int)puVar1 + 0x43) < '\x1e'))) {
      puVar1[0x16] = uGpffffb418;
      cVar3 = *(char *)((int)puVar1 + 0x42) + '\x01';
      *(char *)((int)puVar1 + 0x42) = cVar3;
      if ('\b' < cVar3) {
        ((char *)puVar1)[0x42] = 0;
      }
      iVar4 = puVar1[0x14] + -1;
      puVar1[0x14] = iVar4;
      cVar3 = (char)(iVar4 / 0x3c);
      *(char *)(puVar1 + 0x15) = cVar3 / '\n';
      *(char *)((int)puVar1 + 0x55) = cVar3 % '\n';
      cVar3 = (char)(iVar4 % 0x3c);
      *(char *)((int)puVar1 + 0x56) = cVar3 / '\n';
      *(char *)((int)puVar1 + 0x57) = cVar3 % '\n';
    }
  }
  return;
}

#pragma pop
#pragma opt_loop_invariants reset

// FUN_0045AF40

u32 FUN_0045af40(void)

{
  u32 uVar1;
  
  if (iGpffffba08 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(u32 *)(*(int *)(iGpffffba08 + 0x3c) + 0x50);
  }
  return uVar1;
}

// FUN_0045AF70

void FUN_0045af70(u8 param_1)

{
  if (iGpffffba08 != 0) {
    *(u8 *)(*(int *)(iGpffffba08 + 0x3c) + 0x5d) = param_1;
  }
  return;
}

// FUN_0045AF90

u8 FUN_0045af90(int param_1)

{
  if (param_1 != 0) goto clear;
  return 1;
clear:
  *(u32 *)(param_1 + 0x80) = 0;
  *(u32 *)(param_1 + 0x84) = 0;
  *(u32 *)(param_1 + 0x88) = 0;
  *(u32 *)(param_1 + 0x8c) = 0;
  *(u32 *)(param_1 + 0x90) = 0;
  *(u32 *)(param_1 + 0x94) = 0;
  return 0;
}

// FUN_0045AFD0

u32
FUN_0045afd0(float param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            u8 param_7,u8 param_8,short param_9)
{
  struct TweenEntry {
    float startX;
    float startY;
    float endX;
    float endY;
    float stepX;
    float stepY;
    float rate;
    s8 delay;
    s8 hold;
    s16 duration;
  };
  struct TweenState {
    struct TweenEntry entries[4];
    s32 current;
    s32 count;
    s32 frame;
    u32 flags;
    s32 timer;
    s32 total;
  };
  struct TweenState *state;
  struct TweenEntry *entry;
  float duration;

  if (param_2 == 0) {
    return 1;
  }
  state = (struct TweenState *)param_2;
  if (state->count >= 4) {
    return 2;
  }
  entry = &state->entries[state->count];
  entry->duration = param_9;
  if (entry->duration < 1) {
    entry->duration = 1;
  }
  duration = (float)entry->duration;
  entry->startX = (float)param_3;
  entry->startY = (float)param_4;
  entry->endX = (float)param_5;
  entry->endY = (float)param_6;
  entry->rate = param_1;
  if (param_1 > 0.0f) {
    entry->stepX = param_1 * (entry->endX - entry->startX);
    entry->stepY = entry->rate * (entry->endY - entry->startY);
  }
  else if (param_1 < 0.0f) {
    entry->stepX = entry->startX;
    entry->stepY = entry->startY;
  }
  else {
    entry->stepX = (entry->endX - entry->startX) / duration;
    entry->stepY = (entry->endY - entry->startY) / duration;
  }
  entry->delay = param_7;
  entry->hold = param_8;
  if (entry->delay < 0) {
    entry->delay = 0;
  }
  if (entry->hold < 0) {
    entry->hold = 0;
  }
  state->current = 0;
  state->count = state->count + 1;
  state->frame = 0;
  state->timer = 0;
  state->total += entry->duration + entry->delay + entry->hold;
  state->flags |= 1;
  state->flags &= 0xfffffffd;
  return 0;
}



static inline f32 yTimeBlend(f32 addend, f32 delta, f32 factor)
{
  return addend + delta * factor;
}
// FUN_0045B190

u32 FUN_0045b190(int param_1)

{
  char cVar1;
  int iVar3;
  int lVar4;
  float *pfVar5;
  u8 *iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  iVar6 = (u8 *)(uintptr_t)param_1;
    if ((*(u32 *)(iVar6 + 0x8c) & 2) != 0) {
      return 2;
    }
    if ((*(u32 *)(iVar6 + 0x8c) & 1) == 0) {
      return 0;
    }
        if ((*(int *)(iVar6 + 0x80) == 0) && (*(int *)(iVar6 + 0x88) == 0)) {
          *(u32 *)(iVar6 + 0x90) = 0;
        }
        pfVar5 = (float *)(iVar6 + *(int *)(iVar6 + 0x80) * 0x20);
        cVar1 = *(char *)(pfVar5 + 7);
        lVar4 = *(int *)(iVar6 + 0x88);
        if (!yTimeLess(lVar4,cVar1)) {
          iVar3 = (int)cVar1 + (int)*(short *)((int)pfVar5 + 0x1e);
          if (lVar4 < iVar3) {
            if (lVar4 == iVar3 + -1) {
              *pfVar5 = pfVar5[2];
              pfVar5[1] = pfVar5[3];
            }
            else if (pfVar5[6] < 0.0f) {
              fVar8 = (fGpffff8110 * (float)(*(int *)(iVar6 + 0x88) - (int)cVar1)) /
                      (float)(int)*(short *)((int)pfVar5 + 0x1e);
              fVar9 = pfVar5[4];
              fVar7 = (float)FUN_0052e878_typed(fVar8);
              *pfVar5 = yTimeBlend(fVar9, pfVar5[2] - fVar9, fVar7) + 0.0f;
              fVar9 = pfVar5[5];
              fVar7 = (float)FUN_0052e878_typed(fVar8);
              pfVar5[1] = yTimeBlend(fVar9, pfVar5[3] - fVar9, fVar7) + 0.0f;
            }
            else {
              *pfVar5 = *pfVar5 + pfVar5[4];
              pfVar5[1] = pfVar5[1] + pfVar5[5];
              if (pfVar5[6] > 0.0f) {
                pfVar5[4] = pfVar5[6] * (pfVar5[2] - *pfVar5);
                pfVar5[5] = pfVar5[6] * (pfVar5[3] - pfVar5[1]);
              }
            }
          }
          else if (!yTimeLess(lVar4,*(char *)((int)pfVar5 + 0x1d) + iVar3 + -1)) {
            iVar3 = *(int *)(iVar6 + 0x80) + 1;
            *(int *)(iVar6 + 0x80) = iVar3;
            if (!yTimeLess(iVar3,*(int *)(iVar6 + 0x84))) {
              *(u32 *)(iVar6 + 0x88) = 0;
              *(u32 *)(iVar6 + 0x90) = 0;
              *(int *)(iVar6 + 0x80) = *(int *)(iVar6 + 0x80) + -1;
              *(u32 *)(iVar6 + 0x8c) = *(u32 *)(iVar6 + 0x8c) | 2;
              return 2;
            }
            *(u32 *)(iVar6 + 0x88) = 0;
            return 1;
          }
        }
        *(int *)(iVar6 + 0x88) = *(int *)(iVar6 + 0x88) + 1;
        *(int *)(iVar6 + 0x90) = *(int *)(iVar6 + 0x90) + 1;
  return 1;
}

// FUN_0045B420

u32 FUN_0045b420(int param_1,float *param_2)
{
  struct Pair2 { float x; float y; };
  struct Pair2 *puVar1;
  struct Pair2 *puVar2;
  
  if ((param_1 == 0) || (param_2 == (float *)0)) {
    return 1;
  }
  if (*(int *)(param_1 + 0x84) < 1) {
    return 2;
  }
  puVar1 = (struct Pair2 *)(param_1 + (*(int *)(param_1 + 0x80) << 5));
  puVar2 = (struct Pair2 *)param_2;
  *puVar2 = *puVar1;
  return 0;
}

// FUN_0045B480

int FUN_0045b480(int param_1)

{
  int bVar1;
  
  if (param_1 == 0) {
    bVar1 = 0;
  }
  else {
    bVar1 = !((*(u32 *)((int)param_1 + 0x8c) & 2) > 0);
  }
  return bVar1;
}

// FUN_0045B4B0

int FUN_0045b4b0(int param_1)

{
  int bVar1;
  
  if (param_1 == 0) {
    bVar1 = 1;
  }
  else {
    bVar1 = !((*(u32 *)((int)param_1 + 0x8c) & 1) > 0);
  }
  return bVar1;
}

// MWCC b210 floor: the sole residual is commutative addu $v0,$a0,$v0 versus retail's
// addu $v0,$v0,$a0.
// FUN_0045B4E0

float FUN_0045b4e0(int param_1)
{
  int flags;
  int total;
  int start;
  int tableOffset;
  int endOffset;
  int current;
  int numerator;
  int denominator;
  float progress;

  if (param_1 == 0) {
    return 0.0f;
  }
  flags = *(u32 *)(param_1 + 0x8c);
  if ((flags & 2) != 0) {
    return 1.0f;
  }
  if ((flags & 1) == 0) {
    return 0.0f;
  }
  total = *(int *)(param_1 + 0x94);
  if (total < 1) {
    return 0.0f;
  }
  start = *(char *)(param_1 + 0x1c);
  tableOffset = *(int *)(param_1 + 0x84) * 0x20;
  endOffset = *(char *)(tableOffset + param_1 - 3);
  current = *(int *)(param_1 + 0x90);
  if (current < start) {
    return 0.0f;
  }
  if (current >= total - endOffset) {
    return 1.0f;
  }
  numerator = current - start;
  denominator = total - start - endOffset;
  if ((numerator < 1) || (denominator < 1)) {
    return 0.0f;
  }
  progress = (float)numerator / (float)denominator;
  if (progress < 0.0f) {
    progress = 0.0f;
  }
  else if (progress > 1.0f) {
    progress = 1.0f;
  }
  return progress;
}

// FUN_0045B620

void FUN_0045b620(u32 param_5,float param_1,float param_2,float param_3,float param_4,
                 u8 param_6,int param_7)

{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  uVar2 = FUN_001158b0(0,uGpffffba28,param_5);
  iVar1 = (int)uVar2;
  *(u32 *)(iVar1 + 0x2c) = 0;
  *(float *)(iVar1 + 0x10) = param_1;
  *(float *)(iVar1 + 0x14) = param_2;
  fVar4 = (float)FUN_001126b0_typed((void*)uVar2);
  fVar5 = (float)FUN_00112740_typed((void*)uVar2);
  *(char *)(iVar1 + 0x18) = 0xff - param_6;
  fVar6 = 4096.0f * param_3;
  uVar3 = (u16)fVar6;
  *(u16 *)(iVar1 + 0x28) = uVar3;
  fVar7 = 4096.0f * param_4;
  uVar3 = (u16)fVar7;
  *(u16 *)(iVar1 + 0x2a) = uVar3;
  if (param_7 == 1) {
    fVar6 = (float)FUN_001126b0_typed((void*)uVar2);
    fVar7 = (float)FUN_00112740_typed((void*)uVar2);
    *(float *)(iVar1 + 0x10) = param_1 - ((fVar6 - fVar4) + 0.5f) / 2.0f;
    *(float *)(iVar1 + 0x14) = param_2 - ((fVar7 - fVar5) + 0.5f) / 2.0f;
  }
  FUN_001127d0(uVar2,1);
  FUN_00115980_arg(uVar2);
  return;
}

// FUN_0045B830

void FUN_0045b830(int param_1,long param_2)
{
  int iVar1;
  int iVar4;
  int iVar3;
  int iVar2;

  iVar1 = *(int *)(param_1 + 0x3c);
  if (param_2 == 0) {
    iVar4 = 0xed;
    iVar2 = 0x31;
    iVar3 = iVar2;
  }
  else if (param_2 == 1) {
    iVar4 = 0xed;
    iVar3 = 0x31;
    iVar2 = 0x1d;
  }
  else {
    iVar4 = 0xed;
    iVar2 = 0x31;
    iVar3 = 0x1d;
  }
  FUN_0045af90(iVar1 + 0x2a8);
  FUN_0045afd0_call3(iVar1 + 0x2a8,iVar4,iVar3,iVar4,iVar2,uGpffff82d0,0,0,10);
  return;
}

#pragma push
/* W373 singles base 596/920; loop 596/920; common 588/904; life 596/920; propagation 646/924; strength 596/920; dead 597/920. */
#pragma opt_common_subs off
// FUN_0045B8F0 NONMATCHING

void FUN_0045b8f0(int param_1)
{
  int iVar1;
  int iVar2;
  u32 bVar1;

  iVar1 = *(int *)(param_1 + 0x3c);
  *(u32 *)(iVar1 + 0x28) = *(u32 *)(iVar1 + 0x1c);
  *(u32 *)(iVar1 + 0x2c) = *(u32 *)(iVar1 + 0x20);
  *(u32 *)(iVar1 + 0x30) = *(u32 *)(iVar1 + 0x24);
  bVar1 = ((*(u16 *)DAT_007e0952_abs & 0x4000) != 0);
  if (bVar1 == 0) {
    bVar1 = ((*(u16 *)DAT_007e095a_abs & 0x4000) != 0);
  }
  if (bVar1) {
    u8 *p094e = DAT_007e094e_abs;
    u8 *p0958 = DAT_007e0958_abs;
    u8 *ptable = DAT_007bc730_abs;
    do {
      iVar2 = *(int *)(iVar1 + 0x20) + 1;
      *(int *)(iVar1 + 0x20) = iVar2;
      if (5 < iVar2) {
        if ((*(u16 *)p094e & 0x4000) == 0 &&
            (*(u16 *)p0958 & 0x4000) == 0) {
          *(u32 *)(iVar1 + 0x20) = *(u32 *)(iVar1 + 0x2c);
        }
        else {
          *(u32 *)(iVar1 + 0x20) = 0;
        }
      }
    } while (*(short *)(ptable + *(int *)(iVar1 + 0x1c) * 2 +
                         *(int *)(iVar1 + 0x20) * 0x28) < 0);
  }
  if ((*(u16 *)DAT_007e0952_abs & 0x1000) != 0 ||
      (*(u16 *)DAT_007e095a_abs & 0x1000) != 0) {
    do {
      iVar2 = *(int *)(iVar1 + 0x20) - 1;
      *(int *)(iVar1 + 0x20) = iVar2;
      if (iVar2 < 0) {
        if ((*(u16 *)DAT_007e094e_abs & 0x1000) == 0 &&
            (*(u16 *)DAT_007e0958_abs & 0x1000) == 0) {
          *(u32 *)(iVar1 + 0x20) = *(u32 *)(iVar1 + 0x2c);
        }
        else {
          *(u32 *)(iVar1 + 0x20) = 5;
        }
      }
    } while (*(short *)(DAT_007bc730_abs + *(int *)(iVar1 + 0x1c) * 2 +
                         *(int *)(iVar1 + 0x20) * 0x28) < 0);
  }
  if ((*(u16 *)DAT_007e0952_abs & 0x2000) != 0 ||
      (*(u16 *)DAT_007e095a_abs & 0x2000) != 0) {
    do {
      iVar2 = *(int *)(iVar1 + 0x1c) + 1;
      *(int *)(iVar1 + 0x1c) = iVar2;
      if (0x13 < iVar2) {
        if ((*(u16 *)DAT_007e094e_abs & 0x2000) == 0 &&
            (*(u16 *)DAT_007e0958_abs & 0x2000) == 0) {
          *(u32 *)(iVar1 + 0x1c) = *(u32 *)(iVar1 + 0x28);
        }
        else {
          *(u32 *)(iVar1 + 0x1c) = 0;
        }
      }
    } while (*(short *)(DAT_007bc730_abs + *(int *)(iVar1 + 0x1c) * 2 +
                         *(int *)(iVar1 + 0x20) * 0x28) < 0);
  }
  if ((*(u16 *)DAT_007e0952_abs & 0x8000) != 0 ||
      (*(u16 *)DAT_007e095a_abs & 0x8000) != 0) {
    do {
      iVar2 = *(int *)(iVar1 + 0x1c) - 1;
      *(int *)(iVar1 + 0x1c) = iVar2;
      if (iVar2 < 0) {
        if ((*(u16 *)DAT_007e094e_abs & 0x8000) == 0 &&
            (*(u16 *)DAT_007e0958_abs & 0x8000) == 0) {
          *(u32 *)(iVar1 + 0x1c) = *(u32 *)(iVar1 + 0x28);
        }
        else {
          *(u32 *)(iVar1 + 0x1c) = 0x13;
        }
      }
    } while (*(short *)(DAT_007bc730_abs + *(int *)(iVar1 + 0x1c) * 2 +
                         *(int *)(iVar1 + 0x20) * 0x28) < 0);
  }
  iVar2 = *(int *)(iVar1 + 0x1c) % 5 + *(int *)(iVar1 + 0x20) * 5;
  *(int *)(iVar1 + 0x24) = iVar2;
  iVar2 = iVar2 + (*(int *)(iVar1 + 0x1c) / 5) * 0x1e;
  *(int *)(iVar1 + 0x24) = iVar2;
  if (iVar2 != *(int *)(iVar1 + 0x30)) {
    *(u32 *)(iVar1 + 0x34) = *(u32 *)(iVar1 + 0x28);
    *(u32 *)(iVar1 + 0x38) = *(u32 *)(iVar1 + 0x2c);
    *(u32 *)(iVar1 + 0x3c) = *(u32 *)(iVar1 + 0x30);
    FUN_0010a4e0(0,0,0,0);
  }
}
#pragma opt_common_subs reset

// FUN_0045BCB0

void FUN_0045bcb0(int param_1,u64 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 0x3c);
  if ((int)iGpffffba20 < 0x10) {
    if ((int)iGpffffba20 < 8) {
      FUN_00524828_u64((u8 *)DAT_0095c240_abs + iGpffffba20 * 2,param_2,2);
    }
    else {
      FUN_00524828_u64((u8 *)DAT_0095c220_abs + (iGpffffba20 + -8) * 2,param_2,2);
    }
    iGpffffba20 = iGpffffba20 + 1;
    if ((int)iGpffffba20 < 0x10) goto LAB_0045bd50;
    iGpffffba20 = 0xf;
    goto LAB_0045bd70;
LAB_0045bd50:
    if (iGpffffba20 == 8) {
      *(u32 *)(iVar1 + 0x1c34) = 1;
      FUN_0045b830(param_1,1);
    }
LAB_0045bd70:
    ;
  }
  return;
}

#pragma pop
#pragma push
/* W373 singles base 1203/1900; loop 1203/1900; common 1194/1928; life 1194/1900; propagation 1203/1900; strength 1203/1900; dead 1203/1900. */
#pragma opt_lifetimes on
// FUN_0045BD90 NONMATCHING

void FUN_0045bd90(int param_1)

{
  int iVar1;
  u8 bVar2;
  u32 uVar3;
  int iVar4;
  int lVar5;
  int iVar6;
  int iVar7;
  u8 auStack_4 [4];
  u16 *state;
  
  iVar1 = *(int *)((int)param_1 + 0x3c);
  for (iVar7 = 0; iVar7 < 6; iVar7 = iVar7 + 1) {
    *(u32 *)(iVar1 + iVar7 * 4 + 0x1c50) = 0;
  }
  state = (u16 *)(iVar1 + 0x1c4c);
  *state = 0;
  bVar2 = 0;
  if (iGpffffba24 == 0) {
    iVar7 = 0;
    for (iVar6 = 0; iVar6 < 8; iVar6 = iVar6 + 1) {
      lVar5 = FUN_00524670_typed((u64)((u8 *)gp0xffffae24),(u8(*)[16])((u8 *)DAT_0095c240_abs + iVar6 * 2),2);
      if (lVar5 == 0) {
        iVar7 = iVar7 + 1;
      }
    }
    if (iVar7 < 8) {
      iVar7 = 0;
      for (iVar6 = 0; iVar6 < 8; iVar6 = iVar6 + 1) {
        lVar5 = FUN_00524670_typed((u64)((u8 *)gp0xffffae24),(u8(*)[16])((u8 *)DAT_0095c220_abs + iVar6 * 2),2);
        if (lVar5 == 0) {
          iVar7 = iVar7 + 1;
        }
      }
      if (iVar7 < 8) {
        bVar2 = 1;
        *state = 1;
      }
    }
  }
  if ((((DAT_007e094e & 0x800) == 0) && ((DAT_007e0958 & 0x800) == 0)) || (!bVar2)) {
    *(u16 *)(iVar1 + 0x1c44) = 0;
    state = (u16 *)(iVar1 + 0x1c38);
    *state = 0;
    iVar7 = 0;
    if (iGpffffba24 >= 1) {
      iVar7 = 10;
    }
    else {
      if (iGpffffba20 < 8) {
        uVar3 = FUN_00524388_str((const char*)(0x95c240));
        iVar6 = iGpffffba20;
        if (uVar3 >> 1 != 0) {
          lVar5 = FUN_00524670_typed((u64)((u8 *)gp0xffffae24),(u8(*)[16])((u8 *)DAT_0095c240_abs + iGpffffba20 * 2),2);
          if (lVar5 != 0) {
            iVar7 = 0x15;
          }
          else {
            bVar2 = 0;
            do {
              iVar6 = iVar6 + 1;
              if (7 < iVar6) goto LAB_0045bfe0;
              lVar5 = FUN_00524670_typed((u64)((u8 *)gp0xffffae24),(u8(*)[16])((u8 *)DAT_0095c240_abs + iVar6 * 2),2);
            } while (lVar5 == 0);
            bVar2 = 1;
LAB_0045bfe0:
            if (bVar2) {
              iVar7 = 0x14;
            }
          }
        }
      }
      else {
        uVar3 = FUN_00524388_str((const char*)(0x95c220));
        iVar6 = iGpffffba20;
        if (uVar3 >> 1 != 0) {
          lVar5 = FUN_00524670_typed((u64)((u8 *)gp0xffffae24),(u8(*)[16])((u8 *)DAT_0095c220_abs + (iGpffffba20 + -8) * 2),2);
          if (lVar5 != 0) {
            iVar7 = 0x1f;
          }
          else {
            bVar2 = 0;
            for (iVar6 = iVar6 + -7; iVar6 < 8; iVar6 = iVar6 + 1) {
              lVar5 = FUN_00524670_typed((u64)((u8 *)gp0xffffae24),(u8(*)[16])((u8 *)DAT_0095c220_abs + iVar6 * 2),2);
              if (lVar5 != 0) {
                bVar2 = 1;
                break;
              }
            }
            if (bVar2) {
              iVar7 = 0x1e;
            }
          }
        }
      }
    }
    if (iVar7 != 0) {
      *state = 1;
    }
    if (((DAT_007e094e & 0x20) != 0) || ((DAT_007e0958 & 0x20) != 0)) {
      if (iVar7 == 0x1f) {
        FUN_00524828((u8 *)DAT_0095c220_abs + (iGpffffba20 + -8) * 2,(u8 *)gp0xffffae24,2);
      }
      else if (iVar7 == 0x1e) {
        for (iVar6 = iGpffffba20 + -7; iVar6 < 8; iVar6 = iVar6 + 1) {
          iVar4 = iVar6 * 2;
          ((u8 *)DAT_0095c21e)[iVar4] = ((u8 *)DAT_0095c220_abs)[iVar4];
          ((u8 *)DAT_0095c21f)[iVar4] = ((u8 *)DAT_0095c221)[iVar4];
        }
        FUN_00524828((void *)0x95c22e,(u8 *)gp0xffffae24,2);
      }
      else if (iVar7 == 0x15) {
        FUN_00524828((u8 *)DAT_0095c240_abs + iGpffffba20 * 2,(u8 *)gp0xffffae24,2);
      }
      else {
        iVar6 = iGpffffba20;
        if (iVar7 == 0x14) {
          while (iVar6 = iVar6 + 1, iVar6 < 8) {
            iVar4 = iVar6 * 2;
            ((u8 *)DAT_0095c23e)[iVar4] = ((u8 *)DAT_0095c240_abs)[iVar4];
            ((u8 *)DAT_0095c23f)[iVar4] = ((u8 *)DAT_0095c241)[iVar4];
          }
          FUN_00524828((void *)0x95c24e,(u8 *)gp0xffffae24,2);
        }
        else if (iVar7 == 10) {
          if (iGpffffba20 < 8) {
            FUN_00524828((u8 *)DAT_0095c240_abs + iGpffffba20 * 2,(u8 *)gp0xffffae24,2);
          }
          else {
            FUN_00524828((u8 *)DAT_0095c220_abs + (iGpffffba20 + -8) * 2,(u8 *)gp0xffffae24,2);
          }
        }
        else {
          iVar7 = 0;
        }
      }
      if (iVar7 != 0) {
        *(u32 *)(iVar1 + 0x1c50) = 1;
        FUN_0010a4e0(0,0,0,2);
        return;
      }
    }
    *(u16 *)(iVar1 + 0x1c3c) = 0;
    if (5 >= iGpffffba24) {
      *(u16 *)(iVar1 + 0x1c3c) = 1;
    }
    if (((DAT_007e094e & 0x40) == 0 && (DAT_007e0958 & 0x40) == 0) || (5 < iGpffffba24)) {
      *(u16 *)(iVar1 + 0x1c40) = 0;
      if (0 < iGpffffba20) {
        *(u16 *)(iVar1 + 0x1c40) = 1;
      }
      if (((DAT_007e094e & 4) != 0 || (DAT_007e0958 & 4) != 0) && (0 < iGpffffba20)) {
        iGpffffba20 = iGpffffba20 + -1;
        if (iGpffffba20 == 7) {
          *(u32 *)(iVar1 + 0x1c34) = 2;
          FUN_0045b830(param_1,2);
        }
        *(u32 *)(iVar1 + 0x1c58) = 1;
        FUN_0010a4e0(0,0,0,0);
      }
      *(u16 *)(iVar1 + 0x1c48) = 0;
      if (iGpffffba20 < 0xf) {
        *(u16 *)(iVar1 + 0x1c48) = 1;
      }
      if (((DAT_007e094e & 8) != 0 || (DAT_007e0958 & 8) != 0) && (iGpffffba20 < 0xf)) {
        iGpffffba20 = iGpffffba20 + 1;
        if (iGpffffba20 == 8) {
          *(u32 *)(iVar1 + 0x1c34) = 1;
          FUN_0045b830(param_1,1);
        }
        *(u32 *)(iVar1 + 0x1c60) = 1;
        FUN_0010a4e0(0,0,0,0);
      }
      FUN_0045b8f0(param_1);
    }
    else {
      FUN_00521250_typed((void *)(auStack_4),(const void *)(((u8 *)PTR_DAT_006b4de0)[*(int *)(iVar1 + 0x20)] + *(int *)(iVar1 + 0x1c) * 2),2);
      FUN_0045bcb0(param_1,*(u64 *)(auStack_4));
      FUN_0010a4e0(0,0,0,1);
    }
  }
  else {
    *(u32 *)(iVar1 + 0x14) = 3;
    *(u32 *)(iVar1 + 0x1c64) = 1;
    FUN_0010a4e0(0,0,0,1);
  }
  return;
}

#pragma pop
#pragma opt_lifetimes reset
// FUN_0045C530 NONMATCHING

void FUN_0045c530(int param_1)

{
  int iVar1;
  int iVar2;
  int lVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  u32 alpha;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  if (*(int *)(iVar1 + 0x14) != 1) {
    lVar3 = FUN_0045b4b0(iVar1 + 0xe0);
    if (lVar3 == 0) {
      FUN_0045af90(iVar1 + 0xe0);
    }
  }
  else {
    if (*(int *)(iVar1 + 0x24) != *(int *)(iVar1 + 0x30)) {
      *(u32 *)(iVar1 + 0x1c30) = 0;
    }
    else {
      iVar2 = *(int *)(iVar1 + 0x1c30) + 1;
      *(int *)(iVar1 + 0x1c30) = iVar2;
      if (0x59 < iVar2) {
        *(u32 *)(iVar1 + 0x1c30) = 0;
        iVar4 = (*(int *)(iVar1 + 0x1c) % 5) * 0x1b;
        iVar2 = *(int *)(iVar1 + 0x1c) / 5;
        if (iVar2 == 3) {
          iVar4 = iVar4 + 0x1da;
        }
        else if (iVar2 == 2) {
          iVar4 = iVar4 + 0x146;
        }
        else if (iVar2 == 1) {
          iVar4 = iVar4 + 0xb2;
        }
        else if (iVar2 == 0) {
          iVar4 = iVar4 + 0x1e;
        }
        iVar2 = *(int *)(iVar1 + 0x20) * 0x19 + 0xe5;
        FUN_0045af90(iVar1 + 0xe0);
        FUN_0045afd0(DAT_007cafc0,iVar1 + 0xe0,iVar4,iVar2,iVar4,iVar2,0,0,0x3c);
      }
    }
    lVar3 = FUN_0045b4b0(iVar1 + 0xe0);
    if ((lVar3 == 0) && (lVar3 = FUN_0045b480(iVar1 + 0xe0), lVar3 != 0)) {
      FUN_0045b190(iVar1 + 0xe0);
      iVar4 = *(int *)(iVar1 + 0x20);
      iVar5 = (*(int *)(iVar1 + 0x1c) % 5) * 0x1b;
      iVar2 = *(int *)(iVar1 + 0x1c) / 5;
      if (iVar2 == 3) {
        iVar5 = iVar5 + 0x1da;
      }
      else if (iVar2 == 2) {
        iVar5 = iVar5 + 0x146;
      }
      else if (iVar2 == 1) {
        iVar5 = iVar5 + 0xb2;
      }
      else if (iVar2 == 0) {
        iVar5 = iVar5 + 0x1e;
      }
      fVar7 = (float)FUN_0045b4e0(iVar1 + 0xe0);
      if (fVar7 < 0.5f) {
        fVar6 = fVar7 * 255.0f;
        alpha = (u32)fVar6 & 0xff;
      }
      else {
        fVar7 = 1.0f - fVar7;
        fVar6 = fVar7 * 255.0f;
        alpha = (u32)fVar6 & 0xff;
      }
      FUN_0045b620_call((float)(iVar5 + -0xc),(float)(iVar4 * 0x19 + 0xd9),fVar7 + 1.0f,
                        fVar7 + 1.0f,0xf,alpha,1);
    }
  }
  return;
}

#pragma push
/* W373 singles base 697/964; loop 697/964; common 722/988; life 695/964; propagation 575/968; strength 697/964; dead 697/968; pair life+prop 571/968. */
#pragma opt_lifetimes on
#pragma opt_propagation off
// FUN_0045C8C0 NONMATCHING

void FUN_0045c8c0(int param_1,int param_2)

{
  int iVar1;
  int lVar2;
  int iVar3;
  int iVar4;
  int *piVar6;
  int *piVar5;
  short *psVar7;
  short *psVar8;
  int iVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  int aiStack_70 [26];
  float fStack[2];
  u32 drawContext1;
  u32 drawContext2;
  int xCoord;
  int yCoord;
  u8 alpha;
  
  
  iVar4 = *(int *)(param_1 + 0x3c);
  piVar6 = (int *)DAT_006b4e00;
  piVar5 = aiStack_70;
  iVar3 = 0xc;
  do {
    iVar9 = *piVar6;
    iVar1 = piVar6[1];
    piVar6 = piVar6 + 2;
    iVar3 = iVar3 + -1;
    *piVar5 = iVar9;
    piVar5[1] = iVar1;
    piVar5 = piVar5 + 2;
  } while (0 < iVar3);
  iVar3 = iVar4 + param_2 * 0x130;
  iVar9 = iVar3 + 0x1510;
  iVar3 = iVar3 + 0x15a8;
  iVar4 = iVar4 + param_2 * 4;
  psVar8 = (short *)(iVar4 + 0x1c38);
  psVar7 = (short *)(iVar4 + 0x1c3a);
  if (*(short *)(iVar4 + 0x1c38) == 3) {
    if (*psVar7 != 3) {
      iVar4 = aiStack_70[param_2 * 4 + 2];
      iVar3 = aiStack_70[param_2 * 4 + 3];
      FUN_0045af90(iVar9);
      FUN_0045afd0(DAT_007cafc0,iVar9,iVar4,iVar3 + 0x1e,iVar4,iVar3,0,0,10);
      *psVar7 = *psVar8;
    }
    FUN_0045b190(iVar9);
    fVar11 = (float)FUN_0045b4e0(iVar9);
    fVar10 = fVar11 * 255.0f;
    alpha = (u8)fVar10;
    FUN_0045b420((iVar9),fStack);
    xCoord = (int)fStack[0];
    yCoord = (int)fStack[1];
    FUN_001159f0_3fv((float)xCoord,(float)yCoord,0,
                     drawContext1,DAT_007ce718,
                     aiStack_70[param_2 * 4 + 1],(u8)(0xff - alpha));
  }
  else {
    if (*(int *)(iVar4 + 0x1c50) != 0) {
      *(u32 *)(iVar4 + 0x1c50) = 0;
      iVar4 = aiStack_70[param_2 * 4 + 2];
      iVar1 = aiStack_70[param_2 * 4 + 3];
      FUN_0045af90(iVar3);
      FUN_0045afd0(DAT_007cafc0,iVar3,iVar4,iVar1,iVar4,iVar1,0,0,10);
    }
    lVar2 = FUN_0045b4b0(iVar3);
    if ((lVar2 == 0) && (lVar2 = FUN_0045b480(iVar3), lVar2 != 0)) {
      FUN_0045b190(iVar3);
      fVar11 = (float)FUN_0045b4e0(iVar3);
      fVar10 = (1.0f - fVar11) * 128.0f;
      iVar1 = (u8)fVar10;
      FUN_0045b420((iVar3),fStack);
      fVar12 = fVar11 / 3.0f;
      fVar11 = 1.0f + fVar12;
      FUN_0045b620_call((float)(int)fStack[0],(float)(int)fStack[1],fVar11,fVar11,
                        aiStack_70[param_2 * 4],iVar1,1);
    }
    if (*psVar8 != *psVar7) {
      if (*psVar8 == 0) {
        iVar4 = aiStack_70[param_2 * 4 + 2];
        iVar3 = aiStack_70[param_2 * 4 + 3];
        FUN_0045af90(iVar9);
        FUN_0045afd0(DAT_007cafc0,iVar9,iVar4,iVar3,iVar4,iVar3,0,0,10);
      }
      *psVar7 = *psVar8;
    }
    FUN_0045b190(iVar9);
    fVar11 = (float)FUN_0045b4e0(iVar9);
    if (*psVar7 == 0) {
      fVar10 = (1.0f - fVar11) * 255.0f;
      iVar1 = (u32)fVar10 & 0xff;
    }
    else {
      iVar1 = 0xff;
    }
    FUN_0045b420((iVar9),fStack);
    xCoord = (int)fStack[0];
    yCoord = (int)fStack[1];
    FUN_001159f0_3fv((float)xCoord,(float)yCoord,0,
                     drawContext2,DAT_007ce718,
                     aiStack_70[param_2 * 4 + 1],0);
    FUN_001159f0_3fv((float)xCoord,(float)yCoord,0,
                     drawContext2,DAT_007ce718,
                     aiStack_70[param_2 * 4],0xff - iVar1);
  }
  return;
}

// FUN_0045CDD0

void FUN_0045cdd0(int param_1,long param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)((int)param_1 + 0x3c);
  if ((param_2 == 0) && (*(int *)(iVar1 + 0x14) != 1)) {
    for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
      *(u16 *)(iVar1 + iVar2 * 4 + 0x1c38) = 0;
    }
  }
  FUN_0045c8c0(param_1,0);
  FUN_0045c8c0(param_1,1);
  FUN_0045c8c0(param_1,2);
  FUN_0045c8c0(param_1,4);
  FUN_0045c8c0(param_1,5);
  return;
}

#pragma pop
#pragma opt_lifetimes reset
#pragma opt_propagation reset
#pragma push
/* W373 singles base 2027/2720; loop 2027/2720; common 2027/2788; life 2022/2720; propagation 2032/2764; strength 2027/2720; dead 2027/2720; pair loop+life 2022/2720; common+life 2024/2788. */
#pragma opt_lifetimes on
// FUN_0045CE90 NONMATCHING

void FUN_0045ce90(int param_1)

{
  int iVar1;
  u32 uVar2;
  int lVar3;
  int iVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  u32 uVar12;
  u32 alpha;
  u32 alpha_top;
  u32 alpha_bottom;
  u32 drawContext;
  float fVar15;
  int iVar13;
  int iVar14;
  union {
    struct {
      u32 uStack_20;
      u32 uStack_1c;
      u32 uStack_18;
      u32 uStack_14;
      u32 uStack_10;
      u32 uStack_c;
    } words;
    float afStack_8[2];
  } scratch;
#define uStack_20 scratch.words.uStack_20
#define uStack_1c scratch.words.uStack_1c
#define uStack_18 scratch.words.uStack_18
#define uStack_14 scratch.words.uStack_14
#define uStack_10 scratch.words.uStack_10
#define uStack_c scratch.words.uStack_c
#define fStack_8 scratch.afStack_8[0]
#define fStack_4 scratch.afStack_8[1]
  
  iVar10 = *(int *)(param_1 + 0x3c);
  FUN_001159f0_3fv(0,0,0,param_1,(u8 *)DAT_007ce718,0xa4,0);
  FUN_0045b190(iVar10 + 0x2a8);
  fVar15 = (float)FUN_0045b4e0(iVar10 + 0x2a8);
  fVar15 = fVar15 * 255.0f;
  alpha = (u32)fVar15 & 0xffU;
  FUN_0045b420((iVar10 + 0x2a8),(float*)(&fStack_8));
  iVar13 = (int)fStack_8;
  iVar14 = (int)fStack_4;
  if (*(int *)(iVar10 + 0x1c34) == 0) {
    alpha_top = alpha;
    alpha_bottom = 0;
  }
  else if (*(int *)(iVar10 + 0x1c34) == 1) {
    alpha_bottom = alpha;
    alpha_top = (0xff - alpha_bottom) >> 2;
  }
  else if (*(int *)(iVar10 + 0x1c34) == 2) {
    alpha_top = alpha;
    alpha_bottom = (0xff - alpha_top) >> 2;
  }
  alpha_top = 0xff - alpha_top;
  FUN_001159f0_3fv((float)iVar13,(float)iVar14,0,drawContext,DAT_007ce718,0x13,alpha_top);
  FUN_001159f0_3fv((float)(iVar13 + 0x69),(float)iVar14,0,drawContext,DAT_007ce718,0x11,alpha_top);
  alpha_bottom = 0xff - alpha_bottom;
  FUN_001159f0_3fv((float)iVar13,(float)(iVar14 + 0x14),0,drawContext,DAT_007ce718,0x13,alpha_bottom);
  FUN_001159f0_3fv((float)(iVar13 + 0x69),(float)(iVar14 + 0x14),0,drawContext,DAT_007ce718,0x12,alpha_bottom);
  FUN_0045cdd0(param_1,0);
  if (*(int *)(iVar10 + 0x1c34) != 0) {
    alpha = 0xff;
  }
  alpha = 0xff - alpha;
  iVar13 = *(int *)(param_1 + 0x3c);
  FUN_001159f0_3fv(229.0f,150.0f,0,drawContext,DAT_007ce718,0x17,alpha);
  FUN_001159f0_3fv(229.0f,182.0f,0,drawContext,DAT_007ce718,0x17,alpha);
  FUN_00115bc0_3fv(412.0f,179.0f,0,drawContext,DAT_007ce718,0x1d,alpha,0x33,0x3a,0x4a);
  if (*(int *)(iVar13 + 0x14) != 3) {
    if (DAT_007ce710 >= 8) {
      iVar13 = DAT_007ce710 + -8;
      iVar14 = 0xb7;
    }
    else {
      iVar14 = 0x97;
      iVar13 = DAT_007ce710;
    }
    FUN_001159f0_3fv((float)(iVar13 * 0x1c + 0xe3),(float)iVar14,0,
                     drawContext,DAT_007ce718,0x18,alpha);
  }
  fVar15 = (float)FUN_0045b4e0(iVar10 + 0x210);
  fVar15 = fVar15 * 255.0f;
  alpha = 0xff - ((u32)fVar15 & 0xffU);
  FUN_0045b420((iVar10 + 0x210),(float*)(&fStack_8));
  FUN_001159f0_3fv(4.0f,(float)(int)fStack_4,0,drawContext,DAT_007ce718,0,alpha);
  FUN_001159f0_3fv(321.0f,(float)(int)fStack_4,0,drawContext,DAT_007ce718,1,alpha);
  iVar13 = *(int *)(iVar10 + 0x24) / 5;
  iVar14 = *(int *)(iVar10 + 0x30);
  iVar1 = *(int *)(iVar10 + 0x3c);
  for (iVar4 = 0; iVar4 < 0x18; iVar4 = iVar4 + 1) {
    iVar9 = (iVar4 / 6) * 0x94 + 0x1b;
    iVar8 = (iVar4 % 6) * 0x19 + 0xe5;
    FUN_001159f0_3fv((float)iVar9,(float)iVar8,0,uStack_c,DAT_007ce718,0x1b,0);
    if (*(int *)(iVar10 + 0x14) != 3) {
      if ((iVar13 != iVar14 / 5) && (iVar4 == iVar1 / 5)) {
        iVar11 = iVar10 + iVar4 * 0x98 + 0x340;
        FUN_0045af90(iVar11);
        FUN_0045afd0(DAT_007cafc0,iVar11,0,0,0,0,0,0,0x14);
      }
      iVar11 = iVar10 + iVar4 * 0x98 + 0x340;
      FUN_0045b190(iVar11);
      if (iVar4 == iVar13) {
        FUN_001159f0_3fv((float)iVar9,(float)iVar8,0,uStack_10,DAT_007ce718,0x1c,0);
      }
      else {
        lVar3 = FUN_0045b480(iVar11);
        if (lVar3 != 0) {
          fVar15 = (float)FUN_0045b4e0(iVar11);
          fVar15 = (1.0f - fVar15) * 255.0f;
          FUN_001159f0_3fv((float)iVar9,(float)iVar8,0,uStack_14,DAT_007ce718,0x1c,
                       0xff - ((u32)fVar15 & 0xffU) & 0xff);
        }
      }
    }
  }
  FUN_0045c530(param_1);
  if (*(int *)(iVar10 + 0x14) != 3) {
    iVar14 = (*(int *)(iVar10 + 0x1c) % 5) * 0x1b;
    iVar13 = *(int *)(iVar10 + 0x1c) / 5;
    if (iVar13 == 3) {
      iVar14 = iVar14 + 0x1da;
    }
    else if (iVar13 == 2) {
      iVar14 = iVar14 + 0x146;
    }
    else if (iVar13 == 1) {
      iVar14 = iVar14 + 0xb2;
    }
    else if (iVar13 == 0) {
      iVar14 = iVar14 + 0x1e;
    }
    FUN_001159f0_3fv((float)(iVar14 + -0xc),(float)(*(int *)(iVar10 + 0x20) * 0x19 + 0xd9),0,uStack_18,
                 DAT_007ce718,0xf,0);
  }
  for (iVar13 = 0; iVar13 < 6; iVar13 = iVar13 + 1) {
    for (iVar14 = 0; iVar14 < 0x14; iVar14 = iVar14 + 1) {
      if (-1 < *(short *)((u8 *)DAT_007bc730 + iVar14 * 2 + iVar13 * 0x28)) {
        iVar4 = (iVar14 % 5) * 0x1b;
        iVar1 = iVar14 / 5;
        if (iVar1 == 3) {
          iVar4 = iVar4 + 0x1da;
        }
        else if (iVar1 == 2) {
          iVar4 = iVar4 + 0x146;
        }
        else if (iVar1 == 1) {
          iVar4 = iVar4 + 0xb2;
        }
        else if (iVar1 == 0) {
          iVar4 = iVar4 + 0x1e;
        }
        uVar5 = 0x2e;
        uVar6 = 0x3c;
        uVar7 = 0x44;
        if (((*(int *)(iVar10 + 0x14) != 3) && (iVar14 == *(int *)(iVar10 + 0x1c))) &&
           (iVar13 == *(int *)(iVar10 + 0x20))) {
          uVar5 = 0xe0;
          uVar6 = 0xe0;
          uVar7 = 0xe0;
        }
        FUN_00115bc0_3fv((float)iVar4,(float)(iVar13 * 0x19 + 0xe5),0,uStack_1c,DAT_007ce718,
                     *(short *)((u8 *)DAT_007bc730 + iVar14 * 2 + iVar13 * 0x28) + 0x20,0x19,uVar5,uVar6,
                     uVar7);
      }
    }
  }
  if ((*(int *)(iVar10 + 0x14) == 3) && (*(int *)(iVar10 + 8) == 0)) {
    FUN_001159f0_3fv(0,102.0f,0,uStack_20,DAT_007ce718,0xac,0);
  }
  uVar2 = FUN_00524388_str((const char*)(0x95c240));
  if (uVar2 >> 1 != 0) {
    uVar2 = FUN_00524388_str((const char*)(0x95c240));
    iVar10 = 0xe6;
    for (uVar12 = 0; uVar12 < uVar2 >> 1; uVar12 = uVar12 + 1) {
      FUN_00524828((void *)0x7ce6fc,(u8 *)DAT_0095c240 + uVar12 * 2,2);
      FUN_003b2cb0_va(0,iVar10,0x79,0xffffffffffffffff,5,0,0x7ce6fc,0,0);
      iVar10 = iVar10 + 0x1c;
    }
  }
  uVar2 = FUN_00524388_str((const char*)(0x95c220));
  if (uVar2 >> 1 != 0) {
    uVar2 = FUN_00524388_str((const char*)(0x95c220));
    iVar10 = 0xe6;
    for (uVar12 = 0; uVar12 < uVar2 >> 1; uVar12 = uVar12 + 1) {
      FUN_00524828((void *)0x7ce6fc,(u8 *)DAT_0095c220 + uVar12 * 2,2);
      FUN_003b2cb0_va(0,iVar10,0x99,0xffffffffffffffff,5,0,0x7ce6fc,0,0);
      iVar10 = iVar10 + 0x1c;
    }
  }
  return;
}
#undef uStack_20
#undef uStack_1c
#undef uStack_18
#undef uStack_14
#undef uStack_10
#undef uStack_c
#undef fStack_8
#undef fStack_4

#pragma pop
#pragma opt_lifetimes reset
#pragma push
/* W380 measured FUN_0045D990: pre-closure 1344/947; propagation off 1368/900 (window 1392). Restores a setting lost when a leaked file-scope pragma was closed. */
#pragma opt_propagation off
// FUN_0045D990 NONMATCHING

void FUN_0045d990(int param_1,long param_2)

{
  int iVar1;
  short sVar2;
  int iVar3;
  int lVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float fVar9;
  u32 uStack_c;
  float afStack_8 [2];
  
  
  iVar3 = *(int *)((int)param_1 + 0x3c);
  if ((-1 < param_2) && (lVar4 = FUN_0045b4b0(iVar3 + 0x178), lVar4 == 0)) {
    fVar9 = (float)FUN_0045b4e0(iVar3 + 0x178);
    fVar9 = fVar9 * 255.0f;
    FUN_001159f0_3fv(0,0,0,param_1,(u8 *)DAT_007ce718,0xa4,
                     0xff - ((u32)fVar9 & 0xffU) & 0xff);
  }
  if (0 < param_2) {
    FUN_0045cdd0(param_1,1);
    lVar4 = FUN_0045b4b0(iVar3 + 0x210);
    if (lVar4 == 0) {
      FUN_0045b420((iVar3 + 0x210),afStack_8);
      fVar9 = (float)FUN_0045b4e0(iVar3 + 0x210);
      fVar9 = fVar9 * 255.0f;
      FUN_001159f0_3fv(4.0f,(float)(int)afStack_8[1],0,param_1,
                       (u8 *)DAT_007ce718,0,
                       0xff - ((u32)fVar9 & 0xffU) & 0xff);
      FUN_001159f0_3fv(321.0f,(float)(int)afStack_8[1],0,param_1,
                       (u8 *)DAT_007ce718,1,
                       0xff - ((u32)fVar9 & 0xffU) & 0xff);
    }
  }
  if (1 < param_2) {
    for (iVar8 = 0; iVar8 < 0x18; iVar8 = iVar8 + 1) {
      iVar6 = iVar3 + iVar8 * 0x98 + 0x340;
      lVar4 = FUN_0045b4b0(iVar6);
      if (lVar4 == 0) {
        fVar9 = (float)FUN_0045b4e0(iVar6);
        fVar9 = fVar9 * 255.0f;
        FUN_001159f0_3fv((float)((iVar8 / 6) * 0x94 + 0x1b),
                         (float)((iVar8 % 6) * 0x19 + 0xe5),0,param_1,
                         (u8 *)DAT_007ce718,0x1b,
                         0xff - ((u32)fVar9 & 0xffU) & 0xff);
      }
    }
  }
  if (1 < param_2) {
    for (iVar8 = 0; iVar8 < 6; iVar8 = iVar8 + 1) {
      iVar6 = iVar3 + iVar8 * 0x98;
      lVar4 = FUN_0045b4b0(iVar6 + 0x1180);
      if (lVar4 == 0) {
        for (iVar5 = 0; iVar5 < 0x14; iVar5 = iVar5 + 1) {
          sVar2 = *(short *)((u8 *)DAT_007bc730 + iVar5 * 2 + iVar8 * 0x28);
          if (-1 < sVar2) {
            iVar7 = (iVar5 % 5) * 0x1b;
            iVar1 = iVar5 / 5;
            if (iVar1 == 3) {
              iVar7 = iVar7 + 0x1da;
            }
            else if (iVar1 == 2) {
              iVar7 = iVar7 + 0x146;
            }
            else if (iVar1 == 1) {
              iVar7 = iVar7 + 0xb2;
            }
            else if (iVar1 == 0) {
              iVar7 = iVar7 + 0x1e;
            }
            fVar9 = (float)FUN_0045b4e0(iVar6 + 0x1180);
            fVar9 = fVar9 * 230.0f;
            FUN_0045b420((iVar6 + 0x1180),afStack_8);
            FUN_00115bc0_3fv((float)iVar7,(float)(iVar8 * 0x19 + 0xe5 + (int)afStack_8[1]),0,uStack_c,
                         DAT_007ce718,sVar2 + 0x20,0xff - ((u32)fVar9 & 0xffU) & 0xff,0x2e,0x3c,0x44);
          }
        }
      }
    }
  }
  return;
}
#pragma pop
#pragma opt_propagation reset

#pragma alias DAT_007ce700_y2 DAT_007ce700
extern u8 DAT_006b4c00[];
extern u32 DAT_007ce700_y2;
#pragma alias FUN_003c72d0_y2 FUN_003c72d0
#pragma alias FUN_003c7430_y2 FUN_003c7430
#pragma alias FUN_003c74e0_y2 FUN_003c74e0
#pragma alias FUN_003c7560_y2 FUN_003c7560
#pragma alias FUN_003c75b0_y2 FUN_003c75b0
#pragma alias FUN_003c77a0_y2 FUN_003c77a0
#pragma alias FUN_003c7850_y2 FUN_003c7850
#pragma alias FUN_003c78d0_y2 FUN_003c78d0
#pragma alias FUN_003c7b90_y2 FUN_003c7b90
extern void FUN_003c72d0_y2(void *param_1);
extern void FUN_003c7430_y2(int param_1);
extern void FUN_003c74e0_y2(int param_1);
extern void FUN_003c7560_y2(int param_1);
extern u32 FUN_003c75b0_y2(void);
extern void FUN_003c77a0_y2(void);
extern u32 FUN_003c7850_y2(void);
extern u32 FUN_003c78d0_y2(void);
extern void FUN_003c7b90_y2(void);

// FUN_0045DF00
u32 FUN_0045df00(int param_1)
{
  int *state;
  int mode;

  state = (int *)*(u32 *)(param_1 + 0x3c);
  mode = state[4];
  switch (mode) {
  case 0:
    DAT_007ce700_y2 = 0;
    FUN_003c77a0_y2();
    FUN_003c72d0_y2(DAT_006b4c00);
    FUN_003c7430_y2(1);
    FUN_003c74e0_y2(0);
    FUN_003c7560_y2(0);
    state[4] = 1;
    break;
  case 1:
    if (FUN_003c7850_y2() != 0) {
      FUN_003c7b90_y2();
      if (FUN_003c78d0_y2() == 0) {
        DAT_007ce700_y2 = FUN_003c75b0_y2();
      }
    }
    else {
      state[4] = 2;
    }
    break;
  case 2:
    FUN_003c77a0_y2();
    state[4] = 0;
    return DAT_007ce700_y2;
  default:
    break;
  }
  return 0xffffffff;
}
// FUN_0045E010
u8 FUN_0045e010(int param_1)
{
  int iVar1;
  int lVar2;

  iVar1 = *(int *)(param_1 + 0x3c);
  if (*(int *)(iVar1 + 8) == 0) {
    FUN_0045af90(iVar1 + 0x178);
    FUN_0045afd0_call3(iVar1 + 0x178,0,0,0,0,DAT_007cafc0,0,10,0x14);
    *(u32 *)(iVar1 + 8) = 1;
  }
  FUN_0045b190_arg(iVar1 + 0x178);
  lVar2 = FUN_0045b480(iVar1 + 0x178);
  if (lVar2 == 0) {
    *(u32 *)(iVar1 + 8) = 0;
    return 1;
  }
  return 0;
}

// FUN_0045E0C0

u8 FUN_0045e0c0(int param_1)

{
  int iVar1;
  int lVar2;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  if (*(int *)(iVar1 + 8) == 0) {
    FUN_0045af90(iVar1 + 0x210);
    FUN_0045afd0_call3(iVar1 + 0x210,4,0xe3,4,0xc5,DAT_007cafc0,0,0,10);
    *(u32 *)(iVar1 + 8) = 1;
  }
  FUN_0045b190_arg(iVar1 + 0x210);
  lVar2 = FUN_0045b480(iVar1 + 0x210);
  if (lVar2 == 0) {
    *(u32 *)(iVar1 + 8) = 0;
    return 1;
  }
  return 0;
}

#pragma push
#pragma opt_loop_invariants on
/* W373 singles base 372/596; loop 372/596; common 55/616; life 373/596; propagation 372/596; strength 372/596; dead 372/596. */
#pragma opt_common_subs off
/* W419 DAT_007ce704 _abs probes: u32 alias nd48/616 changed signed slti to sltiu; s32 alias stayed nd55/616; retained original. */
/* W420 negative: direct integer-first FUN_0045afd0_call3 without loop-index splitting measured nd386/object688 against window624; an inline integer-first wrapper stayed nd55/object616. W422 split the three loop indices (tail declarations) and used the interleaved call3 prototype, producing nd0/object616 at window624. */
// FUN_0045E170

u8 FUN_0045e170(int param_1)
{
  int base;
  int address;
  int loop;
  int result;
  int count;
  int entry;
  int loop2;
  int loop3;

  base = *(int *)(param_1 + 0x3c);
  if (*(int *)(base + 8) == 0) {
    DAT_007ce704 = 0;
    *(u32 *)(base + 8) = 1;
  }
  if ((DAT_007ce704 < 6) && (*(int *)(base + 0x18) % 6 == 0)) {
    for (loop = 0; loop < 4; loop++) {
      address = base + (DAT_007ce704 + loop * 6) * 0x98 + 0x340;
      FUN_0045af90(address);
      FUN_0045afd0_call3(address,0,0,0,0,DAT_007cafc0,0,0,6);
    }
    FUN_0045afd0_call3(base + DAT_007ce704 * 0x98 + 0x1180,
                       0,-2,0,0,DAT_007cafc0,0,0,0xc);
    DAT_007ce704++;
  }
  for (loop2 = 0; loop2 < 0x18; loop2++) {
    address = base + loop2 * 0x98 + 0x340;
    result = FUN_0045b4b0(address);
    if (result == 0) {
      FUN_0045b190(address);
    }
  }
  count = 0;
  for (loop3 = 0; loop3 < 6; loop3++) {
    result = FUN_0045b4b0(base + loop3 * 0x98 + 0x1180);
    if (result == 0) {
      entry = base + loop3 * 0x98 + 0x1180;
      FUN_0045b190(entry);
      result = FUN_0045b480(entry);
      if (result == 0) {
        count++;
      }
    }
  }
  if (count == 6) {
    *(u32 *)(base + 8) = 0;
    *(u32 *)(base + 0x18) = 0;
    return 1;
  }
  *(int *)(base + 0x18) = *(int *)(base + 0x18) + 1;
  return 0;
}

#pragma pop
#pragma opt_common_subs reset
#pragma push
/* W373 singles base 398/956; loop 398/956; common 636/1000; life 392/956; propagation 586/964; strength 398/956; dead 400/956. */
#pragma opt_lifetimes on
// FUN_0045E3E0 NONMATCHING

u32 FUN_0045e3e0(int param_1)

{
  u32 *puVar1;
  int lVar2;
  int iVar3;
  float fVar4;
  
  puVar1 = *(u32 **)((int)param_1 + 0x3c);
  if (DAT_007ce718 == 0) {
    return 0;
  }
  iVar3 = puVar1[1];
  switch (iVar3) {
  case 0:
    for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
      *(u16 *)(puVar1 + iVar3 + 0x70e) = 3;
      *(u16 *)((int)puVar1 + iVar3 * 4 + 0x1c3a) = 0;
    }
    *puVar1 = 0;
    puVar1[5] = 0;
    puVar1[1] = 1;
    break;
  case 1:
    if (((int)puVar1[3] < 3) && (lVar2 = PTR_FUN_006b4e60_abs[puVar1[3]](), lVar2 == 1)) {
      puVar1[3] = puVar1[3] + 1;
    }
    FUN_0045d990(param_1,puVar1[3]);
    if (2 < (int)puVar1[3]) {
      puVar1[3] = 0;
      puVar1[2] = 0;
      puVar1[6] = 0;
      puVar1[5] = 1;
      puVar1[1] = 2;
      puVar1[0x70d] = 0;
      FUN_0045b830(param_1,0);
    }
    break;
  case 2:
    if (puVar1[5] == 1) {
      FUN_0045bd90_arg(param_1);
      if ((puVar1[5] != 2) && (puVar1[5] == 3)) {
        puVar1[2] = 0;
        puVar1[4] = 0;
      }
    }
    else if (puVar1[5] == 3) {
      if (puVar1[2] != 0) {
        if (puVar1[6] == 0) {
          FUN_00108fd0_va(0x1e);
        }
        if (0x1d < (int)puVar1[6]) {
          puVar1[6] = 0;
          puVar1[1] = 3;
          return 0;
        }
        puVar1[6] = puVar1[6] + 1;
      }
      else {
        lVar2 = FUN_0045df00(param_1);
        if (lVar2 == 0) {
          iVar3 = 0xe;
          do {
            lVar2 = FUN_00524670_typed((u64)(0x7cdb14),(u8(*)[16])((u8 *)DAT_0095c240 + iVar3),2);
            if (lVar2 != 0) break;
            ((u8 *)DAT_0095c240)[iVar3] = 0;
            ((u8 *)DAT_0095c241)[iVar3] = 0;
            iVar3 = iVar3 + -2;
          } while (-1 < iVar3);
          iVar3 = 0xe;
          do {
            lVar2 = FUN_00524670_typed((u64)(0x7cdb14),(u8(*)[16])((u8 *)DAT_0095c220 + iVar3),2);
            if (lVar2 != 0) break;
            ((u8 *)DAT_0095c220)[iVar3] = 0;
            ((u8 *)DAT_0095c221)[iVar3] = 0;
            iVar3 = iVar3 + -2;
          } while (-1 < iVar3);
          FUN_00177410_typed((u8 *)(DAT_0095c240),(u8 *)(DAT_0095c220));
          puVar1[6] = 0;
          puVar1[2] = 1;
        }
        else if (lVar2 == 1) {
          puVar1[5] = 1;
        }
      }
    }
    FUN_0045ce90(param_1);
    if ((puVar1[5] == 3) && (puVar1[2] == 1)) {
      fVar4 = ((float)(int)puVar1[6] * 255.0f) / 30.0f;
      FUN_00113a30_va(0,0,0,(u32)fVar4 & 0xff,0x280,0x1e0);
    }
    break;
  case 3:
    return 0xffffffff;
  }
  return 0;
}

#pragma pop
#pragma opt_lifetimes reset
// FUN_0045E7B0

void FUN_0045e7b0(int param_1)

{
  DAT_0096017c_abs[0](*(u32 *)(param_1 + 0x3c));
  return;
}



extern u32 DAT_007caf94_y2;
extern u32 DAT_007cafa8_y2;
extern u32 DAT_007cafc0_y2;
extern u32 DAT_007cb134_y2;
extern u32 DAT_007cb138_y2;
extern u32 DAT_007ce704_y2;
extern u32 DAT_00960088_y2;
#pragma alias DAT_0096017c_camp DAT_0096017c
extern void (*DAT_0096017c_camp[])(...);
extern void FUN_001124b0_y2(u32 param_1);
extern void FUN_00108f70(void);
extern void FUN_0016f1f0_y2(int param_1,int param_2);
#pragma alias DAT_00960184_obj DAT_00960184
extern void* (*DAT_00960184_obj[])(...);
extern void FUN_00521408_y2(void *dst,s32 value,u32 size);
#pragma alias FUN_00194b20_typed FUN_00194b20
extern void *FUN_00194b20_typed(void *parent,const char *name,u32 priority,
                                 void *(*update)(void *),void (*destroy)(void *),
                                 void *workData);
extern u8 DAT_006b4e98[];
extern u32 fGpffff8110_y2;
extern u32 fGpffff8248_y2;
extern u32 fGpffff82d8_y2;
extern u32 uGpffff82b8_y2;
extern u32 uGpffff82d0_y2;
extern u32 uGpffff82d4_y2;

extern code FUN_00100d80_y2;
extern code FUN_001023a0;
extern code FUN_00108570;
extern code FUN_001085c0;
extern code FUN_00108710;
extern code FUN_0010a4e0_y2;
extern code FUN_0010c1a0;
extern code FUN_0010c3a0;
extern code FUN_001127d0_y2;
extern code FUN_001140d0_y2;
extern code FUN_001158b0_y2;
extern code FUN_00115980_y2;
extern code FUN_0016c470_y2;
extern code FUN_0016c4f0;
extern code FUN_0016c970_y2;
extern code FUN_00173300;
extern code FUN_0017b5b0_y2;
extern code FUN_0017be10;
extern code FUN_00195460_y2;
extern code FUN_001a0250;
extern code FUN_001a02c0;
extern code FUN_001ad910;
extern code FUN_001ad920;
extern code FUN_001ad940;
extern code FUN_001b00c0;
extern code FUN_001b0220;
extern code FUN_001b0240;
extern code FUN_001b0260;
extern code FUN_001bf220;
extern code FUN_001c6450_y2;
extern code FUN_001c6720_y2;
extern code FUN_001c7130;
extern code FUN_001c7160_y2;
extern code FUN_001cd670;
extern code FUN_001d3810;
extern code FUN_001d8d80_y2;
extern code FUN_001e1360;
extern code FUN_003182d0;
extern code FUN_00318b60;
extern code FUN_00421fe0_y2;
extern code FUN_004221a0;
extern code FUN_004229d0;
extern code FUN_00422c10;
extern code FUN_00422c30;
extern code FUN_00422c90;
extern code FUN_00427e50;
extern code FUN_00488f30;
extern code FUN_004c69f0;
extern code FUN_004d1260_y2;
extern code FUN_00524828_y2;

float FUN_0045b4e0_y2(long param_1);
int FUN_0044f120_y2(float *param_1);
int FUN_0044f170_y2(int param_1);
u16 FUN_0043c180_y2(char param_1);
u16 FUN_0043c340_y2(char param_1);
u16 FUN_00453460_y2(void);
u32 FUN_00431aa0_y2(u64 param_1);
u32 FUN_00432050_y2(u64 param_1);
u32 FUN_00432600_y2(u64 param_1);
u32 FUN_00432bb0_y2(u64 param_1);
u32 FUN_00434770_y2(float param_1,float param_2,u64 param_3,float *param_4);
u32 FUN_0043ca30_y2(u64 param_1);
u32 FUN_0045a280_y2(u64 param_1,int param_2);
u32 FUN_0045afd0_y2(float param_1,long param_2,int param_3,int param_4,int param_5,int param_6, u8 param_7,u8 param_8,short param_9);
u32 FUN_0045b190_y2(long param_1);
u32 FUN_0045b420_y2(long param_1,long param_2);
u32 FUN_0045e3e0_y2(u64 param_1);
u32 FUN_0045e8c0(int param_1);
u32 FUN_004af940(int param_1);
u64 FUN_00430180_y2(u64 param_1);
u64 FUN_00430bb0_y2(u64 param_1);
u64 FUN_00431110_y2(u64 param_1,u64 param_2,char param_3,u8 param_4);
u64 FUN_004312b0(u64 param_1);
u64 FUN_00431670_y2(u64 param_1,char param_2,u32 param_3);
u64 FUN_00439f60_y2(u64 param_1,char param_2);
u64 FUN_0043c690(u32 param_1);
u64 FUN_00447e70_y2(u64 param_1,u8 param_2,u8 param_3);
u64 FUN_0044aaf0_y2(u64 param_1);
u64 FUN_0044ad20_y2(u64 param_1,char param_2);
u64 FUN_0044e560_y2(u64 param_1);
u64 FUN_004542c0_y2(char param_1);
u64 FUN_00455e00_y2(u64 param_1);
u64 FUN_004560d0_y2(u32 param_1,u32 param_2,u32 param_3,u64 param_4, u32 param_5,u32 param_6);
u64 FUN_004579b0(u64 param_1);
u64 FUN_00458630_y2(u64 param_1,char param_2,u8 param_3);
u64 FUN_00459f60_y2(u64 param_1,u16 param_2,char param_3);
u8 FUN_00435260_y2(char param_1);
u8 FUN_004353f0_y2(int param_1);
u8 FUN_004359f0_y2(u64 param_1,u8 param_2,u8 param_3,u32 *param_4, u8 param_5,u8 param_6);
u8 FUN_0043c7f0_y2(char param_1);
u8 FUN_00449c90_y2(u64 param_1,char param_2);
u8 FUN_0044a420_y2(int param_1,long param_2,u64 param_3);
u8 FUN_0044f060_y2(float param_1,int param_2,float *param_3);
u8 FUN_0044f1c0_y2(float param_1,float *param_2,float *param_3);
u8 FUN_00453480_y2(void);
u8 FUN_00454400_y2(u32 *param_1,char param_2);
u8 FUN_00454520_y2(float *param_1,char param_2);
u8 FUN_00454a70_y2(char param_1,float *param_2);
u8 FUN_00454d00_y2(float *param_1);
u8 FUN_00457390_y2(char param_1);
u8 FUN_004573d0_y2(char param_1);
u8 FUN_0045a3b0_y2(void);
u8 FUN_0045af90_y2(long param_1);
u8 FUN_0045b480_y2(long param_1);
u8 FUN_0045b4b0_y2(long param_1);
void FUN_00430270_y2(u32 *param_1,int param_2);
void FUN_004311f0_y2(float *param_1,u32 param_2,u32 param_3);
void FUN_004344f0_y2(float param_1,float *param_2,int param_3,float *param_4,float *param_5);
void FUN_00435c00_y2(u64 param_1);
void FUN_00438010_y2(u64 param_1);
void FUN_00439520_y2(u64 param_1);
void FUN_00448060_y2(u64 param_1,u8 param_2,u64 param_3,char param_4,short param_5, char param_6);
void FUN_00448cf0_y2(u64 param_1,u8 param_2,u64 param_3,char param_4,short param_5, char param_6,int param_7);
void FUN_00449d60_y2(u64 param_1);
void FUN_0044a240_y2(u32 param_1,u32 param_2,float param_3,u32 param_4,int param_5 ,u8 param_6);
void FUN_0044a330_y2(u32 param_1,u32 param_2,float param_3,u32 param_4,int param_5 ,u8 param_6);
void FUN_0044af60_y2(u64 param_1);
void FUN_0044beb0_y2(u64 param_1);
void FUN_0044dfc0_y2(u64 param_1);
void FUN_004561d0_y2(u32 param_1,u32 param_2,int param_3);
void FUN_004563d0_y2(int param_1,u64 param_2);
void FUN_00456a90_y2(u64 param_1,u64 param_2,u64 param_3);
void FUN_0045b620_y2(float param_1,float param_2,float param_3,float param_4,u64 param_5, char param_6,int param_7);
void FUN_0045bcb0_y2(u64 param_1,u64 param_2);
void FUN_0045cdd0_y2(u64 param_1,long param_2);
void FUN_0045ce90_y2(u64 param_1);
void FUN_0045d990_y2(u64 param_1,long param_2);

extern u32 DAT_007ce708;

extern code FUN_00100d80_y2;
extern code FUN_001023a0;
extern code FUN_00108570;
extern code FUN_001085c0;
extern code FUN_00108710;
extern code FUN_0010a4e0_y2;
extern code FUN_0010c1a0;
extern code FUN_0010c3a0;
extern code FUN_001127d0_y2;
extern code FUN_001140d0_y2;
extern code FUN_001158b0_y2;
extern code FUN_00115980_y2;
extern code FUN_0016c470_y2;
extern code FUN_0016c4f0;
extern code FUN_0016c970_y2;
extern code FUN_00173300;
extern code FUN_0017b5b0_y2;
extern code FUN_0017be10;
extern code FUN_00195460_y2;
extern code FUN_001a0250;
extern code FUN_001a02c0;
extern code FUN_001ad910;
extern code FUN_001ad920;
extern code FUN_001ad940;
extern code FUN_001b00c0;
extern code FUN_001b0220;
extern code FUN_001b0240;
extern code FUN_001b0260;
extern code FUN_001bf220;
extern code FUN_001c6450_y2;
extern code FUN_001c6720_y2;
extern code FUN_001c7130;
extern code FUN_001c7160_y2;
extern code FUN_001cd670;
extern code FUN_001d3810;
extern code FUN_001d8d80_y2;
extern code FUN_001e1360;
extern code FUN_003182d0;
extern code FUN_00318b60;
extern code FUN_00421fe0_y2;
extern code FUN_004221a0;
extern code FUN_004229d0;
extern code FUN_00422c10;
extern code FUN_00422c30;
extern code FUN_00422c90;
extern code FUN_00427e50;
extern code FUN_00488f30;
extern code FUN_004c69f0;
extern code FUN_004d1260_y2;
extern code FUN_00524828_y2;

float FUN_0045b4e0_y2(long param_1);
int FUN_0044f120_y2(float *param_1);
int FUN_0044f170_y2(int param_1);
u16 FUN_0043c180_y2(char param_1);
u16 FUN_0043c340_y2(char param_1);
u16 FUN_00453460_y2(void);
u32 FUN_00431aa0_y2(u64 param_1);
u32 FUN_00432050_y2(u64 param_1);
u32 FUN_00432600_y2(u64 param_1);
u32 FUN_00432bb0_y2(u64 param_1);
u32 FUN_00434770_y2(float param_1,float param_2,u64 param_3,float *param_4);
u32 FUN_0043ca30_y2(u64 param_1);
u32 FUN_0045a280_y2(u64 param_1,int param_2);
u32 FUN_0045afd0_y2(float param_1,long param_2,int param_3,int param_4,int param_5,int param_6, u8 param_7,u8 param_8,short param_9);
u32 FUN_0045b190_y2(long param_1);
u32 FUN_0045b420_y2(long param_1,long param_2);
u32 FUN_0045e3e0_y2(u64 param_1);
u32 FUN_0045e8c0(int param_1);
u32 FUN_004af940(int param_1);
u64 FUN_00430180_y2(u64 param_1);
u64 FUN_00430bb0_y2(u64 param_1);
u64 FUN_00431110_y2(u64 param_1,u64 param_2,char param_3,u8 param_4);
u64 FUN_004312b0(u64 param_1);
u64 FUN_00431670_y2(u64 param_1,char param_2,u32 param_3);
u64 FUN_00439f60_y2(u64 param_1,char param_2);
u64 FUN_0043c690(u32 param_1);
u64 FUN_00447e70_y2(u64 param_1,u8 param_2,u8 param_3);
u64 FUN_0044aaf0_y2(u64 param_1);
u64 FUN_0044ad20_y2(u64 param_1,char param_2);
u64 FUN_0044e560_y2(u64 param_1);
u64 FUN_004542c0_y2(char param_1);
u64 FUN_00455e00_y2(u64 param_1);
u64 FUN_004560d0_y2(u32 param_1,u32 param_2,u32 param_3,u64 param_4, u32 param_5,u32 param_6);
u64 FUN_004579b0(u64 param_1);
u64 FUN_00458630_y2(u64 param_1,char param_2,u8 param_3);
u64 FUN_00459f60_y2(u64 param_1,u16 param_2,char param_3);
u8 FUN_00435260_y2(char param_1);
u8 FUN_004353f0_y2(int param_1);
u8 FUN_004359f0_y2(u64 param_1,u8 param_2,u8 param_3,u32 *param_4, u8 param_5,u8 param_6);
u8 FUN_0043c7f0_y2(char param_1);
u8 FUN_00449c90_y2(u64 param_1,char param_2);
u8 FUN_0044a420_y2(int param_1,long param_2,u64 param_3);
u8 FUN_0044f060_y2(float param_1,int param_2,float *param_3);
u8 FUN_0044f1c0_y2(float param_1,float *param_2,float *param_3);
u8 FUN_00453480_y2(void);
u8 FUN_00454400_y2(u32 *param_1,char param_2);
u8 FUN_00454520_y2(float *param_1,char param_2);
u8 FUN_00454a70_y2(char param_1,float *param_2);
u8 FUN_00454d00_y2(float *param_1);
u8 FUN_00457390_y2(char param_1);
u8 FUN_004573d0_y2(char param_1);
u8 FUN_0045a3b0_y2(void);
u8 FUN_0045af90_y2(long param_1);
u8 FUN_0045b480_y2(long param_1);
u8 FUN_0045b4b0_y2(long param_1);
void FUN_00430270_y2(u32 *param_1,int param_2);
void FUN_004311f0_y2(float *param_1,u32 param_2,u32 param_3);
void FUN_004344f0_y2(float param_1,float *param_2,int param_3,float *param_4,float *param_5);
void FUN_00435c00_y2(u64 param_1);
void FUN_00438010_y2(u64 param_1);
void FUN_00439520_y2(u64 param_1);
void FUN_00448060_y2(u64 param_1,u8 param_2,u64 param_3,char param_4,short param_5, char param_6);
void FUN_00448cf0_y2(u64 param_1,u8 param_2,u64 param_3,char param_4,short param_5, char param_6,int param_7);
void FUN_00449d60_y2(u64 param_1);
void FUN_0044a240_y2(u32 param_1,u32 param_2,float param_3,u32 param_4,int param_5 ,u8 param_6);
void FUN_0044a330_y2(u32 param_1,u32 param_2,float param_3,u32 param_4,int param_5 ,u8 param_6);
void FUN_0044af60_y2(u64 param_1);
void FUN_0044beb0_y2(u64 param_1);
void FUN_0044dfc0_y2(u64 param_1);
void FUN_004561d0_y2(u32 param_1,u32 param_2,int param_3);
void FUN_004563d0_y2(int param_1,u64 param_2);
void FUN_00456a90_y2(u64 param_1,u64 param_2,u64 param_3);
void FUN_0045b620_y2(float param_1,float param_2,float param_3,float param_4,u64 param_5, char param_6,int param_7);
void FUN_0045bcb0_y2(u64 param_1,u64 param_2);
void FUN_0045cdd0_y2(u64 param_1,long param_2);
void FUN_0045ce90_y2(u64 param_1);
void FUN_0045d990_y2(u64 param_1,long param_2);



#pragma alias DAT_0095c258_s1 DAT_0095c258
extern u32 DAT_0095c258_s1[];
#pragma alias DAT_0095c25c_s1 DAT_0095c25c
extern u32 DAT_0095c25c_s1[];
#pragma alias DAT_0095c260_s1 DAT_0095c260
extern u32 DAT_0095c260_s1[];

#pragma alias DAT_0095c240_mem DAT_0095c240
extern u8 DAT_0095c240_mem[];
#pragma alias DAT_0095c220_mem DAT_0095c220
extern u8 DAT_0095c220_mem[];
#pragma alias DAT_0095c240_loop DAT_0095c240
extern u8 DAT_0095c240_loop[];
#pragma alias DAT_0095c220_loop DAT_0095c220
extern u8 DAT_0095c220_loop[];

// FUN_0045E7E0

void FUN_0045e7e0(void)

{
  int iVar1;
  
  DAT_0095c258_s1[0] = 0;
  DAT_0095c25c_s1[0] = 0;
  DAT_0095c260_s1[0] = 0;
  DAT_007ce718 = 0;
  memset(DAT_0095c240_mem,0,0x12);
  memset(DAT_0095c220_mem,0,0x12);
  for (iVar1 = 0; iVar1 < 8; iVar1 = iVar1 + 1) {
    strcat((char *)DAT_0095c240_loop,(char *)&gp0xffffae24);
  }
  for (iVar1 = 0; iVar1 < 8; iVar1 = iVar1 + 1) {
    strcat((char *)DAT_0095c220_loop,(char *)&gp0xffffae24);
  }
  DAT_007ce714 = 0;
  DAT_007ce710 = 0;
  DAT_007ce70c = 0;
  return;
}

#pragma alias FUN_0045e7e0_camp FUN_0045e7e0
extern void FUN_0045e7e0_camp(void);
#pragma alias FUN_00109040_camp FUN_00109040
extern void FUN_00109040_camp(int,int);
#pragma alias FUN_00112370_camp FUN_00112370
extern u32 FUN_00112370_camp(int);
#pragma alias FUN_00111f30_camp FUN_00111f30
extern u32 FUN_00111f30_camp(u32);
#pragma alias FUN_00194b80_camp FUN_00194b80
extern u32 FUN_00194b80_camp(void *,u32,const char *,
                              void *(*)(void *),void (*)(void *),void *);
#pragma alias FUN_00195290_camp FUN_00195290
extern u32 FUN_00195290_camp(u32);

#pragma alias DAT_006b4e80_camp DAT_006b4e80
extern u8 DAT_006b4e80_camp[];
#pragma alias DAT_006b4e70_camp DAT_006b4e70
extern u8 DAT_006b4e70_camp[];
#pragma alias DAT_00960184_camp DAT_00960184
extern u32 (*DAT_00960184_camp[])(int,int,int);
#pragma alias FUN_0045e3e0_camp FUN_0045e3e0_y2
extern u8 FUN_0045e3e0_camp[];
#pragma alias FUN_0045e7b0_camp FUN_0045e7b0
extern u8 FUN_0045e7b0_camp[];

// FUN_0045E8C0

u32 FUN_0045e8c0(int param_1)

{
  u32 *puVar1;
  u32 uVar2;
  u32 lVar3;
  
  puVar1 = *(u32 **)(param_1 + 0x3c);
  switch(*puVar1) {
  case 0:
    FUN_0045e7e0_camp();
    *puVar1 = 1;
    FUN_00109040_camp(0x4f,0x1e);
    break;
  case 1:
    uVar2 = FUN_00112370_camp((int)DAT_006b4e80_camp);
    puVar1[2] = uVar2;
    *puVar1 = 2;
    break;
  case 2:
    lVar3 = FUN_00111f30_camp(puVar1[2]);
    if (lVar3 == 1) {
      DAT_007ce718 = puVar1[2];
      lVar3 = DAT_00960184_camp[0](1,0x1c68,0x40000);
      if (lVar3 == 0) {
        uVar2 = 0;
      }
      else {
        memset((void *)lVar3,0,0x1c68);
        uVar2 = FUN_00194b80_camp((void *)param_1, 0x106f,
                                  (const char *)DAT_006b4e70_camp,
                                  (void *(*)(void *))FUN_0045e3e0_camp,
                                  (void (*)(void *))FUN_0045e7b0_camp,
                                  (void *)lVar3);
      }
      puVar1[4] = uVar2;
      *puVar1 = 3;
    }
    break;
  case 3:
    puVar1[3] = 0;
    *puVar1 = 5;
    break;
  case 5:
    lVar3 = FUN_00195290_camp(puVar1[4]);
    if ((lVar3 == 3) || (lVar3 = FUN_00195290_camp(puVar1[4]), lVar3 == 0)) {
      puVar1[4] = 0;
      *puVar1 = 6;
    }
    break;
  case 6:
    DAT_007ce718 = 0;
    return 0xffffffff;
  }
  return 0;
}

// FUN_0045EA80

void FUN_0045ea80(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  if (*(int *)(iVar1 + 8) != 0) {
    FUN_001124b0_y2(*(u32 *)(iVar1 + 8));
    *(u32 *)(iVar1 + 8) = 0;
  }
  (*DAT_0096017c_camp)(iVar1);
  FUN_00108f70();
  FUN_0016f1f0_y2(0x1407,0);
  return;
}

// FUN_0045EAF0

u32 FUN_0045eaf0(void)

{
  u32 uVar1;
  void *lVar2;
  
  lVar2 = (*DAT_00960184_obj)(1,0x14,0x40000);
  if (lVar2 == 0) {
    uVar1 = 0;
  }
  else {
    FUN_00521408_y2(lVar2,0,0x14);
    uVar1 = (u32)FUN_00194b20_typed(0,(const char *)DAT_006b4e98,0x1488,
                                     (void *(*)(void *))FUN_0045e8c0,
                                     (void (*)(void *))FUN_0045ea80,lVar2);
    FUN_0016f1f0_y2(0x1407,1);
  }
  DAT_007ce708 = uVar1;
  return 1;
}

extern s32 FUN_00195290(u32 param_1);
// FUN_0045EBA0

u32 FUN_0045eba0(void)

{
  u32 uVar1;
  s32 lVar2;
  
  if (DAT_007ce708 == 0) {
    uVar1 = 1;
  }
  else {
    lVar2 = FUN_00195290(DAT_007ce708);
    if (lVar2 == 3) {
      DAT_007ce708 = 0;
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}
