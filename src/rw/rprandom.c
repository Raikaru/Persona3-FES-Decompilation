#include "rw/rprandom.h"

extern RwUInt32 D_0095D410[];
extern RwUInt32 uGpffffaed4;

typedef struct RpRandomGlobals
{
    RwUInt32 *state;
    RwUInt32 *jptr;
    RwUInt32 *kptr;
    RwUInt32 *end;
} RpRandomGlobals;

extern RwInt32 iGpffffba88;

#define RANDOMGLOBALS ((RpRandomGlobals*)((RwUInt8*)&rwGlobals + iGpffffba88))

// FUN_00488c70 NONMATCHING
#pragma optimization_level 3
void RpRandomSeedMT(RwUInt32 seed)
{
    RwInt32 count;
    RwUInt32* state;

    seed = seed | 1;
    uGpffffaed4 = 0;
    state = &D_0095D410[1];
    count = 0x270;
    D_0095D410[0] = seed;
    count = count - 1;
    if (count != 0)
    {
        do
        {
            seed = seed * 0x10dcd;
            count = count - 1;
            *state = seed;
            state++;
        } while (count != 0);
    }
}
#pragma optimization_level 2

// FUN_00488dd0
#pragma optimization_level 3
void RpRandomSeed(RwUInt32 seed)
{
    RwInt32 j;
    RwInt32 offset;
    RwInt32 warmup;
    RwUInt32* state;
    RpRandomGlobals* globals;

    j = 1;
    offset = sizeof(RwUInt32);
    *RANDOMGLOBALS->state = seed;

    do
    {
        j += 6;
        state = (RwUInt32*)((RwUInt8*)RANDOMGLOBALS->state + offset);
        *state = state[-1] * 0x41c64e6d + 0x3039;

        state = (RwUInt32*)((RwUInt8*)RANDOMGLOBALS->state + offset);
        state[1] = *state * 0x41c64e6d + 0x3039;

        state = (RwUInt32*)((RwUInt8*)RANDOMGLOBALS->state + offset);
        state[2] = state[1] * 0x41c64e6d + 0x3039;

        state = (RwUInt32*)((RwUInt8*)RANDOMGLOBALS->state + offset);
        state[3] = state[2] * 0x41c64e6d + 0x3039;

        state = (RwUInt32*)((RwUInt8*)RANDOMGLOBALS->state + offset);
        state[4] = state[3] * 0x41c64e6d + 0x3039;

        state = (RwUInt32*)((RwUInt8*)RANDOMGLOBALS->state + offset);
        offset += 6 * sizeof(RwUInt32);
        state[5] = state[4] * 0x41c64e6d + 0x3039;
    } while (j < 0x1f);

    warmup = 0;
    globals = RANDOMGLOBALS;
    globals->jptr = globals->state + 3;
    globals->kptr = globals->state;

    do
    {
        RpRandom();
        warmup++;
    } while (warmup < 0x136);
}
#pragma optimization_level 2

// FUN_00488f30 NONMATCHING
RwUInt32 RpRandom(void)
{
    RwUInt32 result;
    RwUInt32* next;

    *RANDOMGLOBALS->jptr = *RANDOMGLOBALS->kptr + *RANDOMGLOBALS->jptr;
    result = *RANDOMGLOBALS->jptr;
    next = RANDOMGLOBALS->jptr + 1;
    RANDOMGLOBALS->jptr = next;
    result = result >> 1;
    if (next >= RANDOMGLOBALS->end)
    {
        RANDOMGLOBALS->jptr = RANDOMGLOBALS->state;
        RANDOMGLOBALS->kptr++;
    }
    else
    {
        RANDOMGLOBALS->kptr++;
        if (RANDOMGLOBALS->kptr >= RANDOMGLOBALS->end)
        {
            RANDOMGLOBALS->kptr = RANDOMGLOBALS->state;
        }
    }

    return result;
}

/* Recovered engine region 0x430000-0x4AFFFF */
#include "temporary.h"

typedef int (*code)(...);
typedef u8 bool;
#ifndef CONCAT44
#define CONCAT44(hi, lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif
#ifndef CONCAT22
#define CONCAT22(hi, lo) ((u32)((((u32)(u16)(hi)) << 16) | (u16)(lo)))
#endif

typedef union Vec128 { struct { u32 _0_4_; u32 _4_4_; u32 _8_4_; u32 _12_4_; }; struct { u64 _0_8_; u64 _8_8_; }; u8 _bytes[16]; } Vec128;
static Vec128 rwVecZero(void) { Vec128 v; v._0_8_=0; v._8_8_=0; return v; }
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
extern u32 DAT_007caf94;
extern u32 DAT_007cafa8;
extern u32 DAT_007cafc0;
extern u32 DAT_007cb134;
extern u32 DAT_007cb138;
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
extern u32 DAT_007ce704;
extern u32 DAT_007ce70c;
extern u32 DAT_007ce710;
extern u32 DAT_007ce714;
extern u32 DAT_007ce718;
extern u32 DAT_007e094e;
extern u32 DAT_007e0952;
extern u32 DAT_007e0958;
extern u32 DAT_007e095a;
extern u32 DAT_0086be00;
extern u32 DAT_0086e6e8;
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
extern u32 DAT_0095c221;
extern u32 DAT_0095c23e;
extern u32 DAT_0095c23f;
extern u32 DAT_0095c240;
extern u32 DAT_0095c241;
extern u32 DAT_0095c258;
extern u32 DAT_0095c25c;
extern u32 DAT_0095c260;
extern u32 DAT_00960088;
extern code DAT_00960090;
extern code DAT_009600a0;
extern code DAT_0096017c;
extern code DAT_00960184;
extern u32 PTR_DAT_006b46f0;
extern u32 PTR_DAT_006b4720;
extern u32 PTR_DAT_006b4de0;
extern u32 PTR_FUN_006b4e60;
extern u8 cGpffffb9cc;
extern u32 fGpffff8110;
extern u32 fGpffff8248;
extern u32 fGpffff82d8;
extern u32 gp0xffffae24;
extern u32 gp0xffffb9f7;
extern u32 iGpffffb418;
extern u32 iGpffffb5a0;
extern u32 iGpffffb9fc;
extern u32 iGpffffba08;
extern u32 iGpffffba20;
extern u32 iGpffffba24;
extern u32 uGpffff82b8;
extern u32 uGpffff82d0;
extern u32 uGpffff82d4;
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

extern code FUN_00100d80;
extern code FUN_00100ec0;
extern code FUN_001016b0;
extern code FUN_00102100;
extern code FUN_001023a0;
extern code FUN_00108570;
extern code FUN_001085c0;
extern code FUN_00108670;
extern code FUN_00108710;
extern code FUN_00108fd0;
extern code FUN_0010a4e0;
extern code FUN_0010c1a0;
extern code FUN_0010c3a0;
extern code FUN_00111f30;
extern code FUN_001120c0;
extern code FUN_00112370;
extern code FUN_00112420;
extern code FUN_001124b0;
extern code FUN_001126b0;
extern code FUN_00112740;
extern code FUN_001127d0;
extern code FUN_00113a30;
extern code FUN_001140d0;
extern code FUN_001158b0;
extern code FUN_00115980;
extern code FUN_001159f0;
extern code FUN_00115bc0;
extern code FUN_0016c470;
extern code FUN_0016c4f0;
extern code FUN_0016c570;
extern code FUN_0016c5f0;
extern code FUN_0016c920;
extern code FUN_0016c970;
extern code FUN_0016cf40;
extern code FUN_0016cf90;
extern code FUN_0016f190;
extern code FUN_0016f1f0;
extern code FUN_0016f490;
extern code FUN_00170a40;
extern code FUN_00170ab0;
extern code FUN_00170b20;
extern code FUN_00170b90;
extern code FUN_00173300;
extern code FUN_00173380;
extern code FUN_00177410;
extern code FUN_0017b500;
extern code FUN_0017b5b0;
extern code FUN_0017b660;
extern code FUN_0017b860;
extern code FUN_0017be10;
extern code FUN_001831e0;
extern code FUN_0018bee0;
extern code FUN_0018c0c0;
extern code FUN_0018eb30;
extern code FUN_00194b20;
extern code FUN_00194b80;
extern code FUN_00195020;
extern code FUN_00195460;
extern code FUN_00198590;
extern code FUN_001a0040;
extern code FUN_001a0250;
extern code FUN_001a02c0;
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
extern code FUN_001ad910;
extern code FUN_001ad920;
extern code FUN_001ad940;
extern code FUN_001adc20;
extern code FUN_001adff0;
extern code FUN_001af930;
extern code FUN_001afa20;
extern code FUN_001aff70;
extern code FUN_001b0020;
extern code FUN_001b00c0;
extern code FUN_001b01b0;
extern code FUN_001b01d0;
extern code FUN_001b0220;
extern code FUN_001b0230;
extern code FUN_001b0240;
extern code FUN_001b0250;
extern code FUN_001b0260;
extern code FUN_001b9120;
extern code FUN_001bf220;
extern code FUN_001c6450;
extern code FUN_001c65e0;
extern code FUN_001c6720;
extern code FUN_001c6d70;
extern code FUN_001c6dd0;
extern code FUN_001c7130;
extern code FUN_001c7160;
extern code FUN_001c7270;
extern code FUN_001c7b10;
extern code FUN_001cd670;
extern code FUN_001d0110;
extern code FUN_001d22a0;
extern code FUN_001d3810;
extern code FUN_001d8b00;
extern code FUN_001d8c60;
extern code FUN_001d8d80;
extern code FUN_001d8e60;
extern code FUN_001dde00;
extern code FUN_001ded40;
extern code FUN_001e1360;
extern code FUN_001e13c0;
extern code FUN_00269690;
extern code FUN_002699a0;
extern code FUN_002699d0;
extern code FUN_00269a10;
extern code FUN_00269c80;
extern code FUN_00269ca0;
extern code FUN_002ff340;
extern code FUN_002ff760;
extern code FUN_002ff790;
extern code FUN_00316e00;
extern code FUN_00316f70;
extern code FUN_003174e0;
extern code FUN_003182d0;
extern code FUN_00318540;
extern code FUN_00318b60;
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
extern code FUN_00421fe0;
extern code FUN_004221a0;
extern code FUN_004222d0;
extern code FUN_004229d0;
extern code FUN_00422c10;
extern code FUN_00422c30;
extern code FUN_00422c90;
extern code FUN_00423fe0;
extern code FUN_00427830;
extern code FUN_00427a10;
extern code FUN_00427db0;
extern code FUN_00427de0;
extern code FUN_00427e20;
extern code FUN_00427e50;
extern code FUN_00427e60;
extern code FUN_00427e70;
extern code FUN_00429e80;
extern code FUN_00488f30;
extern code FUN_004c31b0;
extern code FUN_004c3880;
extern code FUN_004c38c0;
extern code FUN_004c69f0;
extern code FUN_004c6ac0;
extern code FUN_004c6be0;
extern code FUN_004d0f00;
extern code FUN_004d1260;
extern code FUN_004d7f60;
extern code FUN_00521250;
extern code FUN_00521408;
extern code FUN_00523e68;
extern code FUN_00524388;
extern code FUN_00524670;
extern code FUN_00524828;
extern code FUN_0052e878;
extern code FUN_0052ea18;

char FUN_00435440(char param_1);
char FUN_0043bc20(char param_1);
float FUN_0045b4e0(long param_1);
float FUN_004693a0(int param_1);
float FUN_0047cfd0(u32 *param_1,u8 (*param_2) [12],u8 (*param_3) [12], int param_4,int param_5);
float FUN_004a9560(float param_1,int param_2,u8 *param_3);
float FUN_004aa2c0(void);
int * FUN_00496cd0(u32 param_1,u32 *param_2,u64 param_3,u16 *param_4);
int * FUN_004ac120(int *param_1,u64 param_2);
int * FUN_004ac240(int *param_1);
int FUN_0044f120(float *param_1);
int FUN_0044f170(int param_1);
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
u16 FUN_0043c180(char param_1);
u16 FUN_0043c340(char param_1);
u16 FUN_00453460(void);
u32 * FUN_0048f580(u64 param_1,int *param_2,int param_3,u32 param_4);
u32 * FUN_0048fbd0(u64 param_1,u64 param_2,u64 param_3,u32 param_4);
u32 * FUN_004a7e40(u32 *param_1,u32 param_2,u32 param_3,char *param_4);
u32 * FUN_004a8980(u32 *param_1,u64 param_2,u32 param_3,u64 param_4);
u32 * FUN_004a90f0(void);
u32 * FUN_004a9a80(u64 param_1);
u32 * FUN_004ab8c0(void);
u32 FUN_00431880(int param_1);
u32 FUN_00431aa0(u64 param_1);
u32 FUN_00432050(u64 param_1);
u32 FUN_00432600(u64 param_1);
u32 FUN_00432bb0(u64 param_1);
u32 FUN_00433160(int param_1);
u32 FUN_00433810(char param_1,char param_2);
u32 FUN_004339d0(int param_1);
u32 FUN_00433de0(int param_1);
u32 FUN_00434770(float param_1,float param_2,u64 param_3,float *param_4);
u32 FUN_00434920(float param_1,float param_2,int param_3,float *param_4);
u32 FUN_004352e0(void);
u32 FUN_00437e20(char param_1);
u32 FUN_0043a230(char param_1);
u32 FUN_0043a9d0(u64 param_1,u64 param_2,char param_3);
u32 FUN_0043c500(int param_1);
u32 FUN_0043c910(char param_1);
u32 FUN_0043ca30(u64 param_1);
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
u32 FUN_0045a280(u64 param_1,int param_2);
u32 FUN_0045af40(void);
u32 FUN_0045afd0(float param_1,long param_2,int param_3,int param_4,int param_5,int param_6, u8 param_7,u8 param_8,short param_9);
u32 FUN_0045b190(long param_1);
u32 FUN_0045b420(long param_1,long param_2);
u32 FUN_0045df00(int param_1);
u32 FUN_0045e3e0(u64 param_1);
u32 FUN_0045e8c0(u64 param_1);
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
#pragma alias FUN_0048a2c0_noarg FUN_0048a2c0
extern u32 FUN_0048a2c0_noarg(void);
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
u32 FUN_004af940(int param_1);
u64 FUN_00430060(int param_1);
u64 FUN_00430180(u64 param_1);
u64 FUN_00430bb0(u64 param_1);
u64 FUN_00431110(u64 param_1,u64 param_2,char param_3,u8 param_4);
u64 FUN_004312b0(u64 param_1);
u64 FUN_00431670(u64 param_1,char param_2,u32 param_3);
u64 FUN_00439f60(u64 param_1,char param_2);
u64 FUN_0043a0b0(u64 param_1,char param_2);
u64 FUN_0043c690(u32 param_1);
u64 FUN_00447e70(u64 param_1,u8 param_2,u8 param_3);
u64 FUN_0044aaf0(u64 param_1);
u64 FUN_0044ad20(u64 param_1,char param_2);
u64 FUN_0044e560(u64 param_1);
u64 FUN_004542c0(char param_1);
u64 FUN_00454620(char param_1);
u64 FUN_00455e00(u64 param_1);
u64 FUN_004560d0(u32 param_1,u32 param_2,u32 param_3,u64 param_4, u32 param_5,u32 param_6);
u64 FUN_004579b0(u64 param_1);
u64 FUN_00457a40(u64 param_1);
u64 FUN_00458630(u64 param_1,char param_2,u8 param_3);
u64 FUN_00459f60(u64 param_1,u16 param_2,char param_3);
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
int FUN_0048a2a0(int param_1,u32 param_2);
u64 FUN_0048a2e0(u64 param_1,int param_2);
u64 FUN_0048a370(int param_1);
u64 FUN_0048a4b0(u32 param_1);
u64 FUN_0048a790(u64 param_1);
u64 FUN_0048a800(u64 param_1,int param_2);
u64 FUN_0048ac10(u64 param_1,long param_2);
u64 FUN_0048b910(u32 param_1,float *param_2);
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
u8 FUN_00435260(char param_1);
u8 FUN_004353f0(int param_1);
u8 FUN_00435810(void);
u8 FUN_004359f0(u64 param_1,u8 param_2,u8 param_3,u32 *param_4, u8 param_5,u8 param_6);
u8 FUN_0043c730(char param_1);
u8 FUN_0043c7f0(char param_1);
u8 FUN_00449c90(u64 param_1,char param_2);
u8 FUN_0044a420(int param_1,long param_2,u64 param_3);
u8 FUN_0044f060(float param_1,int param_2,float *param_3);
u8 FUN_0044f1c0(float param_1,float *param_2,float *param_3);
u8 FUN_0044fab0(int param_1);
u8 FUN_00453480(void);
u8 FUN_00454400(u32 *param_1,char param_2);
u8 FUN_00454520(float *param_1,char param_2);
u8 FUN_00454a70(char param_1,float *param_2);
u8 FUN_00454d00(float *param_1);
u8 FUN_00457390(char param_1);
u8 FUN_004573d0(char param_1);
u8 FUN_0045a3b0(void);
u8 FUN_0045af90(long param_1);
u8 FUN_0045b480(long param_1);
u8 FUN_0045b4b0(long param_1);
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
u32 FUN_00488fe0(void);
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
void FUN_00430270(u32 *param_1,int param_2);
void FUN_004302a0(int param_1);
void FUN_004302b0(void);
void FUN_00430630(int param_1);
void FUN_00430780(u64 param_1,int param_2,int param_3,int param_4);
void FUN_00430a40(char param_1);
void FUN_004310e0(int param_1);
void FUN_004311f0(float *param_1,u32 param_2,u32 param_3);
void FUN_00431630(int param_1);
void FUN_004332f0(int param_1);
void FUN_004333d0(int param_1);
void FUN_004334d0(int param_1);
void FUN_004343d0(int param_1);
void FUN_004344f0(float param_1,float *param_2,int param_3,float *param_4,float *param_5);
void FUN_00434c90(char param_1);
void FUN_00434d30(void);
void FUN_00434e60(void);
void FUN_00434f60(u8 param_1);
void FUN_00434f70(void);
void FUN_00435060(u8 param_1);
void FUN_004350e0(char param_1,char param_2);
void FUN_00435370(u8 param_1);
void FUN_00435c00(u64 param_1);
void FUN_00437e00(void);
void FUN_00437e80(u32 *param_1,char param_2);
void FUN_00438010(u64 param_1);
void FUN_00439400(char param_1);
void FUN_00439520(u64 param_1);
void FUN_0043a1a0(char param_1,u8 param_2);
void FUN_0043a2f0(int param_1);
void FUN_0043a960(int param_1);
void FUN_0043bf50(u64 param_1);
void FUN_0043c660(int param_1);
void FUN_0043c7a0(char param_1,u8 param_2);
void FUN_00447ad0(int param_1);
void FUN_00447f90(float *param_1,int param_2,char param_3);
void FUN_00448060(u64 param_1,u8 param_2,u64 param_3,char param_4,short param_5, char param_6);
void FUN_00448cf0(u64 param_1,u8 param_2,u64 param_3,char param_4,short param_5, char param_6,int param_7);
void FUN_00449d10(int param_1);
void FUN_00449d60(u64 param_1);
void FUN_00449ed0(void);
void FUN_00449fa0(void);
void FUN_0044a240(u32 param_1,u32 param_2,float param_3,u32 param_4,int param_5 ,u8 param_6);
void FUN_0044a330(u32 param_1,u32 param_2,float param_3,u32 param_4,int param_5 ,u8 param_6);
void FUN_0044a630(int param_1);
void FUN_0044a790(u32 *param_1);
void FUN_0044a990(int param_1,u32 *param_2);
void FUN_0044acf0(int param_1);
void FUN_0044af60(u64 param_1);
void FUN_0044b7d0(int param_1);
void FUN_0044beb0(u64 param_1);
void FUN_0044d600(int param_1);
void FUN_0044dfc0(u64 param_1);
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
void FUN_004561d0(u32 param_1,u32 param_2,int param_3);
void FUN_004561f0(float param_1,int param_2);
void FUN_004563b0(f32 param_1, int param_2);
void FUN_004563c0(int param_1,u8 param_2);
void FUN_004563d0(int param_1,u64 param_2);
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
void FUN_00456a90(u64 param_1,u64 param_2,u64 param_3);
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
void FUN_0045b620(float param_1,float param_2,float param_3,float param_4,u64 param_5, char param_6,int param_7);
void FUN_0045b830(int param_1,long param_2);
void FUN_0045b8f0(int param_1);
void FUN_0045bcb0(u64 param_1,u64 param_2);
void FUN_0045bd90(u64 param_1);
void FUN_0045c530(int param_1);
void FUN_0045c8c0(int param_1,int param_2);
void FUN_0045cdd0(u64 param_1,long param_2);
void FUN_0045ce90(u64 param_1);
void FUN_0045d990(u64 param_1,long param_2);
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

extern u32 DAT_007ce77c;
extern u32 DAT_007ce7b4;
extern u32 DAT_0095de10;
extern u32 DAT_0095de14;
extern u32 DAT_0095de18;
#pragma alias DAT_0095de18_abs DAT_0095de18
extern u32 DAT_0095de18_abs[];
extern u32 DAT_0095de1c;
extern u32 DAT_0095de20;
extern u32 DAT_0095de28;
extern u32 DAT_0095de30;
extern u32 DAT_0095de40;
extern u32 DAT_0095de50;
extern u32 DAT_0095de68;
extern u32 DAT_00960070;
#pragma alias DAT_00960070_abs DAT_00960070
extern u32 DAT_00960070_abs[];
#pragma alias DAT_0095de14_abs DAT_0095de14
extern u32 DAT_0095de14_abs[];
#pragma alias DAT_0096017c_abs DAT_0096017c
extern void (*DAT_0096017c_abs[])(void);
#pragma alias DAT_0096018c_abs DAT_0096018c
extern void (*DAT_0096018c_abs[])(u32,u64);
#pragma alias FUN_004ca520_typed FUN_004ca520
extern int FUN_004ca520_typed(int,int,u8*,u8*);
#pragma alias FUN_00488d40_abs FUN_00488d40
extern u8 FUN_00488d40_abs[];
#pragma alias FUN_00488cd0_abs FUN_00488cd0
extern u8 FUN_00488cd0_abs[];
#pragma alias FUN_00521408_typed FUN_00521408
extern void FUN_00521408_typed(int,int,int);
extern u32 DAT_00960074;
extern u32 DAT_00960078;
extern u32 DAT_0096007c;
extern code DAT_00960140;
extern code DAT_00960178;
extern code DAT_0096017c;
extern code DAT_00960188;
extern code DAT_0096018c;
extern u32 iGpffffba8c;
extern u32 iGpffffba90;
extern u32 iGpffffba94;
extern u32 iGpffffba98;
extern u32 iGpffffba9c;
extern u32 iGpffffbaa0;
extern u32 iGpffffbaa4;
extern u32 iGpffffbaa8;
extern u32 iGpffffbaac;
extern u32 iGpffffbab0;
extern u32 iGpffffbab4;
extern u32 iGpffffbab8;
extern u32 uGpffffaed8;
extern u32 uGpffffaedc;
extern u32 uGpffffba88;
extern char getCopCondition(int,int);

extern code FUN_00100d80;
extern code FUN_00100ec0;
extern code FUN_001016b0;
extern code FUN_00102100;
extern code FUN_001023a0;
extern code FUN_00108570;
extern code FUN_001085c0;
extern code FUN_00108670;
extern code FUN_00108710;
extern code FUN_00108f70;
extern code FUN_00108fd0;
extern code FUN_00109040;
extern code FUN_0010a4e0;
extern code FUN_0010c1a0;
extern code FUN_0010c3a0;
extern code FUN_00111f30;
extern code FUN_001120c0;
extern code FUN_00112370;
extern code FUN_00112420;
extern code FUN_001124b0;
extern code FUN_001126b0;
extern code FUN_00112740;
extern code FUN_001127d0;
extern code FUN_00113a30;
extern code FUN_001140d0;
extern code FUN_001158b0;
extern code FUN_00115980;
extern code FUN_001159f0;
extern code FUN_00115bc0;
extern code FUN_0016c470;
extern code FUN_0016c4f0;
extern code FUN_0016c570;
extern code FUN_0016c5f0;
extern code FUN_0016c920;
extern code FUN_0016c970;
extern code FUN_0016cf40;
extern code FUN_0016cf90;
extern code FUN_0016f190;
extern code FUN_0016f1f0;
extern code FUN_0016f490;
extern code FUN_00170a40;
extern code FUN_00170ab0;
extern code FUN_00170b20;
extern code FUN_00170b90;
extern code FUN_00173300;
extern code FUN_00173380;
extern code FUN_00177410;
extern code FUN_0017b500;
extern code FUN_0017b5b0;
extern code FUN_0017b660;
extern code FUN_0017b860;
extern code FUN_0017be10;
extern code FUN_001831e0;
extern code FUN_0018bee0;
extern code FUN_0018c0c0;
extern code FUN_0018eb30;
extern code FUN_00194b20;
extern code FUN_00194b80;
extern code FUN_00195020;
extern code FUN_00195290;
extern code FUN_00195460;
extern code FUN_00198590;
extern code FUN_001a0040;
extern code FUN_001a0250;
extern code FUN_001a02c0;
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
extern code FUN_001ad910;
extern code FUN_001ad920;
extern code FUN_001ad940;
extern code FUN_001adc20;
extern code FUN_001adff0;
extern code FUN_001af930;
extern code FUN_001afa20;
extern code FUN_001aff70;
extern code FUN_001b0020;
extern code FUN_001b00c0;
extern code FUN_001b01b0;
extern code FUN_001b01d0;
extern code FUN_001b0220;
extern code FUN_001b0230;
extern code FUN_001b0240;
extern code FUN_001b0250;
extern code FUN_001b0260;
extern code FUN_001b9120;
extern code FUN_001bf220;
extern code FUN_001c6450;
extern code FUN_001c65e0;
extern code FUN_001c6720;
extern code FUN_001c6d70;
extern code FUN_001c6dd0;
extern code FUN_001c7130;
extern code FUN_001c7160;
extern code FUN_001c7270;
extern code FUN_001c7b10;
extern code FUN_001cd670;
extern code FUN_001d0110;
extern code FUN_001d22a0;
extern code FUN_001d3810;
extern code FUN_001d8b00;
extern code FUN_001d8c60;
extern code FUN_001d8d80;
extern code FUN_001d8e60;
extern code FUN_001dde00;
extern code FUN_001ded40;
extern code FUN_001e1360;
extern code FUN_001e13c0;
extern code FUN_00269690;
extern code FUN_002699a0;
extern code FUN_002699d0;
extern code FUN_00269a10;
extern code FUN_00269c80;
extern code FUN_00269ca0;
extern code FUN_002ff340;
extern code FUN_002ff760;
extern code FUN_002ff790;
extern code FUN_00316e00;
extern code FUN_00316f70;
extern code FUN_003174e0;
extern code FUN_003182d0;
extern code FUN_00318540;
extern code FUN_00318b60;
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
extern code FUN_00421fe0;
extern code FUN_004221a0;
extern code FUN_004222d0;
extern code FUN_004229d0;
extern code FUN_00422c10;
extern code FUN_00422c30;
extern code FUN_00422c90;
extern code FUN_00423fe0;
extern code FUN_00427830;
extern code FUN_00427a10;
extern code FUN_00427db0;
extern code FUN_00427de0;
extern code FUN_00427e20;
extern code FUN_00427e50;
extern code FUN_00427e60;
extern code FUN_00427e70;
extern code FUN_00429e80;
extern code FUN_00469DC0;
extern code FUN_00474630;
extern code FUN_00488dd0;
extern code FUN_00488f30;
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
extern code FUN_004c69f0;
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
extern code FUN_004d1260;
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
extern code FUN_00524828;
extern code FUN_0052e6d8;
extern code FUN_0052e878;
extern code FUN_0052ea18;
extern code FUN_005316d0;

char FUN_00435440(char param_1);
char FUN_0043bc20(char param_1);
float FUN_0045b4e0(long param_1);
float FUN_004693a0(int param_1);
float FUN_0047cfd0(u32 *param_1,u8 (*param_2) [12],u8 (*param_3) [12], int param_4,int param_5);
float FUN_004a9560(float param_1,int param_2,u8 *param_3);
float FUN_004aa2c0(void);
int * FUN_00496cd0(u32 param_1,u32 *param_2,u64 param_3,u16 *param_4);
int * FUN_004ac120(int *param_1,u64 param_2);
int * FUN_004ac240(int *param_1);
int FUN_0044f120(float *param_1);
int FUN_0044f170(int param_1);
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
u16 FUN_0043c180(char param_1);
u16 FUN_0043c340(char param_1);
u16 FUN_00453460(void);
u32 * FUN_0048f580(u64 param_1,int *param_2,int param_3,u32 param_4);
u32 * FUN_0048fbd0(u64 param_1,u64 param_2,u64 param_3,u32 param_4);
u32 * FUN_004a7e40(u32 *param_1,u32 param_2,u32 param_3,char *param_4);
u32 * FUN_004a8980(u32 *param_1,u64 param_2,u32 param_3,u64 param_4);
u32 * FUN_004a90f0(void);
u32 * FUN_004a9a80(u64 param_1);
u32 * FUN_004ab8c0(void);
u32 FUN_00431880(int param_1);
u32 FUN_00431aa0(u64 param_1);
u32 FUN_00432050(u64 param_1);
u32 FUN_00432600(u64 param_1);
u32 FUN_00432bb0(u64 param_1);
u32 FUN_00433160(int param_1);
u32 FUN_00433810(char param_1,char param_2);
u32 FUN_004339d0(int param_1);
u32 FUN_00433de0(int param_1);
u32 FUN_00434770(float param_1,float param_2,u64 param_3,float *param_4);
u32 FUN_00434920(float param_1,float param_2,int param_3,float *param_4);
u32 FUN_004352e0(void);
u32 FUN_00437e20(char param_1);
u32 FUN_0043a230(char param_1);
u32 FUN_0043a9d0(u64 param_1,u64 param_2,char param_3);
u32 FUN_0043c500(int param_1);
u32 FUN_0043c910(char param_1);
u32 FUN_0043ca30(u64 param_1);
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
u32 FUN_0045a280(u64 param_1,int param_2);
u32 FUN_0045af40(void);
u32 FUN_0045afd0(float param_1,long param_2,int param_3,int param_4,int param_5,int param_6, u8 param_7,u8 param_8,short param_9);
u32 FUN_0045b190(long param_1);
u32 FUN_0045b420(long param_1,long param_2);
u32 FUN_0045df00(int param_1);
u32 FUN_0045e3e0(u64 param_1);
u32 FUN_0045e8c0(u64 param_1);
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
u32 FUN_004af940(int param_1);
u64 FUN_00430060(int param_1);
u64 FUN_00430180(u64 param_1);
u64 FUN_00430bb0(u64 param_1);
u64 FUN_00431110(u64 param_1,u64 param_2,char param_3,u8 param_4);
u64 FUN_004312b0(u64 param_1);
u64 FUN_00431670(u64 param_1,char param_2,u32 param_3);
u64 FUN_00439f60(u64 param_1,char param_2);
u64 FUN_0043a0b0(u64 param_1,char param_2);
u64 FUN_0043c690(u32 param_1);
u64 FUN_00447e70(u64 param_1,u8 param_2,u8 param_3);
u64 FUN_0044aaf0(u64 param_1);
u64 FUN_0044ad20(u64 param_1,char param_2);
u64 FUN_0044e560(u64 param_1);
u64 FUN_004542c0(char param_1);
u64 FUN_00454620(char param_1);
u64 FUN_00455e00(u64 param_1);
u64 FUN_004560d0(u32 param_1,u32 param_2,u32 param_3,u64 param_4, u32 param_5,u32 param_6);
u64 FUN_004579b0(u64 param_1);
u64 FUN_00457a40(u64 param_1);
u64 FUN_00458630(u64 param_1,char param_2,u8 param_3);
u64 FUN_00459f60(u64 param_1,u16 param_2,char param_3);
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
int FUN_0048a2a0(int param_1,u32 param_2);
u64 FUN_0048a2e0(u64 param_1,int param_2);
u64 FUN_0048a370(int param_1);
u64 FUN_0048a4b0(u32 param_1);
u64 FUN_0048a790(u64 param_1);
u64 FUN_0048a800(u64 param_1,int param_2);
u64 FUN_0048ac10(u64 param_1,long param_2);
u64 FUN_0048b910(u32 param_1,float *param_2);
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
u8 FUN_00435260(char param_1);
u8 FUN_004353f0(int param_1);
u8 FUN_00435810(void);
u8 FUN_004359f0(u64 param_1,u8 param_2,u8 param_3,u32 *param_4, u8 param_5,u8 param_6);
u8 FUN_0043c730(char param_1);
u8 FUN_0043c7f0(char param_1);
u8 FUN_00449c90(u64 param_1,char param_2);
u8 FUN_0044a420(int param_1,long param_2,u64 param_3);
u8 FUN_0044f060(float param_1,int param_2,float *param_3);
u8 FUN_0044f1c0(float param_1,float *param_2,float *param_3);
u8 FUN_0044fab0(int param_1);
u8 FUN_00453480(void);
u8 FUN_00454400(u32 *param_1,char param_2);
u8 FUN_00454520(float *param_1,char param_2);
u8 FUN_00454a70(char param_1,float *param_2);
u8 FUN_00454d00(float *param_1);
u8 FUN_00457390(char param_1);
u8 FUN_004573d0(char param_1);
u8 FUN_0045a3b0(void);
u8 FUN_0045af90(long param_1);
u8 FUN_0045b480(long param_1);
u8 FUN_0045b4b0(long param_1);
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
u32 FUN_00488fe0(void);
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
void FUN_00430270(u32 *param_1,int param_2);
void FUN_004302a0(int param_1);
void FUN_004302b0(void);
void FUN_00430630(int param_1);
void FUN_00430780(u64 param_1,int param_2,int param_3,int param_4);
void FUN_00430a40(char param_1);
void FUN_004310e0(int param_1);
void FUN_004311f0(float *param_1,u32 param_2,u32 param_3);
void FUN_00431630(int param_1);
void FUN_004332f0(int param_1);
void FUN_004333d0(int param_1);
void FUN_004334d0(int param_1);
void FUN_004343d0(int param_1);
void FUN_004344f0(float param_1,float *param_2,int param_3,float *param_4,float *param_5);
void FUN_00434c90(char param_1);
void FUN_00434d30(void);
void FUN_00434e60(void);
void FUN_00434f60(u8 param_1);
void FUN_00434f70(void);
void FUN_00435060(u8 param_1);
void FUN_004350e0(char param_1,char param_2);
void FUN_00435370(u8 param_1);
void FUN_00435c00(u64 param_1);
void FUN_00437e00(void);
void FUN_00437e80(u32 *param_1,char param_2);
void FUN_00438010(u64 param_1);
void FUN_00439400(char param_1);
void FUN_00439520(u64 param_1);
void FUN_0043a1a0(char param_1,u8 param_2);
void FUN_0043a2f0(int param_1);
void FUN_0043a960(int param_1);
void FUN_0043bf50(u64 param_1);
void FUN_0043c660(int param_1);
void FUN_0043c7a0(char param_1,u8 param_2);
void FUN_00447ad0(int param_1);
void FUN_00447f90(float *param_1,int param_2,char param_3);
void FUN_00448060(u64 param_1,u8 param_2,u64 param_3,char param_4,short param_5, char param_6);
void FUN_00448cf0(u64 param_1,u8 param_2,u64 param_3,char param_4,short param_5, char param_6,int param_7);
void FUN_00449d10(int param_1);
void FUN_00449d60(u64 param_1);
void FUN_00449ed0(void);
void FUN_00449fa0(void);
void FUN_0044a240(u32 param_1,u32 param_2,float param_3,u32 param_4,int param_5 ,u8 param_6);
void FUN_0044a330(u32 param_1,u32 param_2,float param_3,u32 param_4,int param_5 ,u8 param_6);
void FUN_0044a630(int param_1);
void FUN_0044a790(u32 *param_1);
void FUN_0044a990(int param_1,u32 *param_2);
void FUN_0044acf0(int param_1);
void FUN_0044af60(u64 param_1);
void FUN_0044b7d0(int param_1);
void FUN_0044beb0(u64 param_1);
void FUN_0044d600(int param_1);
void FUN_0044dfc0(u64 param_1);
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
void FUN_004561d0(u32 param_1,u32 param_2,int param_3);
void FUN_004561f0(float param_1,int param_2);
void FUN_004563b0(f32 param_1, int param_2);
void FUN_004563c0(int param_1,u8 param_2);
void FUN_004563d0(int param_1,u64 param_2);
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
void FUN_00456a90(u64 param_1,u64 param_2,u64 param_3);
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
void FUN_0045b620(float param_1,float param_2,float param_3,float param_4,u64 param_5, char param_6,int param_7);
void FUN_0045b830(int param_1,long param_2);
void FUN_0045b8f0(int param_1);
void FUN_0045bcb0(u64 param_1,u64 param_2);
void FUN_0045bd90(u64 param_1);
void FUN_0045c530(int param_1);
void FUN_0045c8c0(int param_1,int param_2);
void FUN_0045cdd0(u64 param_1,long param_2);
void FUN_0045ce90(u64 param_1);
void FUN_0045d990(u64 param_1,long param_2);
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

#pragma schedule on
// FUN_00488CD0 NONMATCHING

u64 FUN_00488cd0(u64 param_1)
{
  if (*(int *)((u8 *)DAT_00960070_abs + iGpffffba88) != 0) {
    DAT_0096017c_abs[0]();
    *(u32 *)((u8 *)DAT_00960070_abs + iGpffffba88) = 0;
  }
  return param_1;
}
#pragma schedule off

// FUN_00488D40 NONMATCHING

u64 FUN_00488d40(u64 param_1)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = (*DAT_00960178)(0x7c,0x4010c);
  piVar2 = (int *)((int)(u8 *)DAT_00960070 + iGpffffba88);
  *piVar2 = iVar1;
  if (*piVar2 == 0) {
    param_1 = 0;
  }
  else {
    *(int *)((int)(u8 *)DAT_00960074 + iGpffffba88) = *piVar2 + 0xc;
    *(int *)((int)(u8 *)DAT_00960078 + iGpffffba88) = *piVar2;
    *(int *)((u8 *)DAT_0096007c + iGpffffba88) = *piVar2 + 0x7c;
    ((code)FUN_00488dd0)(0xffffffff9a319039);
  }
  return param_1;
}

#pragma schedule on
// FUN_00488FE0
u32 FUN_00488fe0(void)
{
  int lVar1;

  lVar1 = FUN_004ca520_typed(0x10,0x10c,FUN_00488d40_abs,FUN_00488cd0_abs);
  uGpffffba88 = lVar1;
  return lVar1 >= 0;
}
#pragma schedule off
#pragma schedule on
// FUN_00489020 NONMATCHING
u32 FUN_00489020(int param_1)
{
  u32 *puVar1;
  u32 uVar2;

  puVar1 = (u32 *)(param_1 + 0x2c);
  if (*(int *)(param_1 + 0x38) != 0) {
    DAT_0096017c_abs[0]();
  }
  uVar2 = 1;
  puVar1[0] = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  return uVar2;
}
#pragma schedule off

// FUN_00489080 NONMATCHING
u64 FUN_00489080(u64 param_1,int *param_2)
{
  long lVar1;
  
  lVar1 = ((code)FUN_004c17f0)(param_1,param_2 + 0xb,4);
  if (lVar1 == 0) {
    param_1 = 0;
  }
  else {
    lVar1 = ((code)FUN_004c17f0)(param_1,param_2 + 0xc,4);
    if (lVar1 == 0) {
      param_1 = 0;
    }
    else {
      lVar1 = ((code)FUN_004c17f0)(param_1,param_2 + 0xd,4);
      if (lVar1 == 0) {
        param_1 = 0;
      }
      else if ((param_2[0xc] != 0) &&
              (lVar1 = ((code)FUN_004c53f0)(param_1,param_2[0xe],
                                    *param_2 + param_2[0xc] * 2 + param_2[0xd] * 2), lVar1 == 0)) {
        param_1 = 0;
      }
    }
  }
  return param_1;
}


// FUN_00489160 NONMATCHING

u64 FUN_00489160(u64 param_1,long param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  int *piVar5;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  piVar5 = (int *)param_2;
  lVar3 = ((code)FUN_004c1910)(param_1,&iStack_c,4);
  if (lVar3 == 0) {
    param_1 = 0;
  }
  else {
    lVar3 = ((code)FUN_004c1910)(param_1,&iStack_4,4);
    if (lVar3 == 0) {
      param_1 = 0;
    }
    else {
      lVar3 = ((code)FUN_004c1910)(param_1,&iStack_8,4);
      if (lVar3 == 0) {
        param_1 = 0;
      }
      else if (0 < iStack_4) {
        iVar1 = *piVar5;
        ((code)FUN_00489020)(param_2);
        iVar4 = iVar1 + iStack_4 * 2 + iStack_8 * 2;
        iVar2 = (*DAT_00960178)(iVar4,0x30116);
        piVar5[0xe] = iVar2;
        if (piVar5[0xe] == 0) {
          param_2 = 0;
        }
        else {
          ((code)FUN_00521408)(piVar5[0xe],0,iVar4);
          piVar5[0xb] = iStack_c;
          piVar5[0xc] = iStack_4;
          piVar5[0xd] = iStack_8;
          piVar5[0xf] = piVar5[0xe] + iVar1;
          piVar5[0x10] = piVar5[0xf] + iStack_4 * 2;
        }
        if (param_2 == 0) {
          param_1 = 0;
        }
        else {
          lVar3 = ((code)FUN_004c5250)(param_1,piVar5[0xe],*piVar5 + piVar5[0xc] * 2 + piVar5[0xd] * 2);
          if (lVar3 == 0) {
            (*DAT_0096017c)(piVar5 + 0xb);
            param_1 = 0;
          }
        }
      }
    }
  }
  return param_1;
}

// FUN_00489320 NONMATCHING
int FUN_00489320(int *param_1)
{
  int iVar1;

  iVar1 = 0xc;
  if (param_1[0xc] != 0) {
    iVar1 = *param_1 + param_1[0xc] * 2 + param_1[0xd] * 2 + 0xc;
  }
  return iVar1;
}


// FUN_00489350 NONMATCHING

void FUN_00489350(u64 param_1,long param_2)

{
  long lVar1;
  
  lVar1 = ((code)FUN_004ca550)(0x120);
  if ((lVar1 == -1) && (param_2 == 2)) {
    param_2 = 1;
  }
  else {
    lVar1 = ((code)FUN_004ca550)(0x12e);
    if ((lVar1 == -1) && (param_2 == 3)) {
      param_2 = 1;
    }
  }
  ((code)FUN_0048ac10)(param_1,param_2);
  return;
}

// FUN_004893E0 NONMATCHING

void FUN_004893e0(int param_1,int param_2,u32 param_3)

{
  int *piVar1;
  u32 uVar2;
  u32 uVar3;
  
  *(u32 *)(param_1 + 0x10) = 1;
  uVar3 = 0;
  if (param_3 != 0) {
    do {
      uVar2 = *(u32 *)(param_1 + 0x10);
      if (uVar2 < 4) {
        piVar1 = (int *)(param_2 + uVar2 * 4);
        do {
          if (*piVar1 == 0) break;
          *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
          if (*(int *)(param_1 + 0x10) == 4) {
            return;
          }
          uVar2 = uVar2 + 1;
          piVar1 = piVar1 + 1;
        } while (uVar2 < 4);
      }
      uVar3 = uVar3 + 1;
      param_2 = param_2 + 0x10;
    } while (uVar3 < param_3);
  }
  return;
}

// FUN_00489460 NONMATCHING

void FUN_00489460(int param_1,u32 *param_2,int *param_3,int param_4,u32 *param_5,u32 param_6)

{
  u32 uVar1;
  u8 bVar2;
  u32 uVar3;
  int *piVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  
  uVar6 = 0;
  *param_5 = 0;
  if (param_6 != 0) {
    do {
      uVar5 = 0;
      if (*(int *)(param_1 + 0x10) != 0) {
        uVar3 = 0;
        piVar4 = param_3;
        do {
          if (*piVar4 != 0) {
            bVar2 = 1;
            uVar1 = *param_5;
            uVar8 = 0;
            uVar7 = *param_2 >> (uVar3 & 0x1f);
            if (uVar1 != 0) {
              do {
                if ((uVar7 & 0xff) == (u32)*(u8 *)(param_4 + uVar8)) {
                  bVar2 = 0;
                  break;
                }
                uVar8 = uVar8 + 1;
              } while (uVar8 < uVar1);
            }
            if (bVar2) {
              *(char *)(param_4 + uVar1) = (char)uVar7;
              *param_5 = *param_5 + 1;
            }
          }
          uVar5 = uVar5 + 1;
          piVar4 = piVar4 + 1;
          uVar3 = uVar3 + 8;
        } while (uVar5 < *(u32 *)(param_1 + 0x10));
      }
      uVar6 = uVar6 + 1;
      param_3 = param_3 + 4;
      param_2 = param_2 + 1;
    } while (uVar6 < param_6);
  }
  return;
}

// FUN_00489550 NONMATCHING

u32
FUN_00489550(int *param_1,int param_2,long param_3,int param_4,long param_5,long param_6,
            long param_7,long param_8)

{
  u8 bVar1;
  int iVar2;
  u32 uVar3;
  u32 *puVar4;
  u32 *puVar5;
  int iVar6;
  u32 *puVar7;
  int iVar8;
  
  iVar6 = (int)param_3;
  iVar8 = iVar6 + param_4 * 0x14 + param_2 * 0x40 + 0xf;
  iVar2 = (*DAT_00960178)(iVar8,0x30116);
  param_1[0x11] = iVar2;
  if (param_1[0x11] == 0) {
    uVar3 = 0;
  }
  else {
    ((code)FUN_00521408)(param_1[0x11],0,iVar8);
    *param_1 = param_2;
    param_1[1] = iVar6;
    param_1[2] = param_1[0x11];
    param_1[3] = param_1[2] + iVar6 + 0xfU & 0xfffffff0;
    param_1[5] = param_1[3] + param_2 * 0x40;
    param_1[6] = param_1[5] + param_4 * 4;
    if ((param_5 != 0) && (param_3 != 0)) {
      ((code)FUN_00521250)(param_1[2],param_5,param_3);
    }
    if ((param_8 != 0) && (iVar2 = *param_1 + -1, *param_1 != 0)) {
      iVar6 = iVar2 * 0x40;
      puVar7 = (u32 *)((int)param_8 + iVar6);
      do {
        iVar8 = 8;
        puVar5 = (u32 *)(param_1[3] + iVar6);
        puVar4 = puVar7;
        do {
          iVar8 = iVar8 + -1;
          uVar3 = puVar4[1];
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 2;
          puVar5[1] = uVar3;
          puVar5 = puVar5 + 2;
        } while (0 < iVar8);
        puVar7 = puVar7 + -0x10;
        iVar6 = iVar6 + -0x40;
        bVar1 = iVar2 != 0;
        iVar2 = iVar2 + -1;
      } while (bVar1);
    }
    if (param_7 != 0) {
      ((code)FUN_00521250)(param_1[5],param_7,param_4 * 4);
    }
    if (param_6 != 0) {
      ((code)FUN_00521250)(param_1[6],param_6,param_4 << 4);
    }
    uVar3 = 1;
  }
  return uVar3;
}

// FUN_00489730 NONMATCHING

u64 FUN_00489730(u64 param_1)

{
  long lVar1;
  u64 uVar2;
  u32 uVar3;
  
  if (DAT_0095de30 == 0) {
    uVar3 = 1;
    lVar1 = ((code)FUN_004ca550)(0x120);
    if (lVar1 != -1) {
      uVar3 = 3;
    }
    lVar1 = ((code)FUN_004ca550)(0x12e);
    if (lVar1 != -1) {
      uVar3 = uVar3 | 4;
    }
    ((code)FUN_0048abf0)(uVar3);
    DAT_0095de28 = thunk_FUN_004c3970(0x48,uGpffffaed8,4,uGpffffaedc,0x95dde0,0x40116);
    uVar2 = (*DAT_00960178)(0x400f,0x40116);
    DAT_0095de20 = (int)uVar2;
    ((code)FUN_00521408)(uVar2,0,0x400f);
    DAT_0095de1c = DAT_0095de20 + 0xfU & 0xfffffff0;
  }
  DAT_0095de30 = DAT_0095de30 + 1;
  return param_1;
}

// FUN_00489840 NONMATCHING

u64 FUN_00489840(u64 param_1)

{
  DAT_0095de30 = DAT_0095de30 + -1;
  if (DAT_0095de30 == 0) {
    ((code)FUN_0048ac00)();
    ((code)FUN_004c3c30)(DAT_0095de28);
    DAT_0095de28 = 0;
    (*DAT_0096017c)(DAT_0095de20);
    DAT_0095de20 = 0;
  }
  return param_1;
}

// FUN_004898E0 NONMATCHING

u64 FUN_004898e0(u64 param_1)
{
  int iVar1;
  u32 uVar2;
  
  iVar1 = *(int *)((int)param_1 + DAT_0095de18);
  if (iVar1 != 0) {
    ((code)FUN_0048a790)();
    uVar2 = ((code)FUN_0048a370)(iVar1);
    *(u32 *)((int)param_1 + DAT_0095de18) = uVar2;
  }
  return param_1;
}

// FUN_00489960 NONMATCHING
u64 FUN_00489960(u64 param_1)
{
  u32 uVar1;

  uVar1 = DAT_0095de14_abs[0];
  FUN_00521408_typed((int)((u8 *)param_1 + uVar1),0,4);
  return param_1;
}

// FUN_004899F0 NONMATCHING

u32 FUN_004899f0(u64 param_1)

{
  int iVar1;
  long lVar2;
  u64 uVar3;
  
  uVar3 = 1;
  lVar2 = ((code)FUN_004ca550)(0x120);
  if ((lVar2 != -1) && (iVar1 = ((code)FUN_00492d00)(0x120), *(char *)((int)param_1 + iVar1) != '\0')) {
    uVar3 = 2;
  }
  if ((*(int *)((int)param_1 + 0x18) != 0) && (lVar2 = ((code)FUN_0048a2c0)(), lVar2 != 0)) {
    ((code)FUN_00489350)(param_1,uVar3);
  }
  return 1;
}

// FUN_00489A80 NONMATCHING

u32 FUN_00489a80(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  long lVar1;
  
  if ((*(int *)((int)param_1 + 0x18) != 0) && (lVar1 = ((code)FUN_0048a2c0)(), lVar1 != 0)) {
    ((code)FUN_00489350)(param_1,param_4);
  }
  return 1;
}

// FUN_00489AE0 NONMATCHING

int FUN_00489ae0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = *(int **)(param_1 + DAT_0095de18);
  iVar5 = 0;
  if (piVar1 != (int *)0x0) {
    if ((*(u32 *)(param_1 + 8) & 0x1000000) == 0) {
      iVar2 = *(int *)(param_1 + 0x14);
      iVar3 = piVar1[1];
      iVar4 = *piVar1;
      iVar5 = ((code)FUN_00489320)(piVar1);
      iVar5 = iVar3 + 4 + iVar2 * 0x14 + iVar4 * 0x40 + iVar5;
    }
    else {
      iVar5 = ((code)FUN_0048a7a0)();
    }
  }
  return iVar5;
}

// FUN_00489B70 NONMATCHING

u64 FUN_00489b70(u64 param_1,u64 param_2,u64 param_3)

{
  u8 *pbVar1;
  long lVar2;
  int iVar3;
  u32 uStack_4;
  
  iVar3 = (int)param_3;
  pbVar1 = *(u8 **)(iVar3 + DAT_0095de18);
  if (pbVar1 != (u8 *)0x0) {
    if ((*(u32 *)(iVar3 + 8) & 0x1000000) == 0) {
      iVar3 = *(int *)(iVar3 + 0x14);
      uStack_4 = (u32)*pbVar1 |
                 (*(u32 *)(pbVar1 + 0x10) & 0xff) << 0x10 | (*(u32 *)(pbVar1 + 4) & 0xff) << 8;
      lVar2 = ((code)FUN_004c17f0)(param_1,&uStack_4,4);
      if (lVar2 == 0) {
        param_1 = 0;
      }
      else {
        lVar2 = ((code)FUN_004c53f0)(param_1,*(u32 *)(pbVar1 + 8),*(u32 *)(pbVar1 + 4));
        if (lVar2 == 0) {
          param_1 = 0;
        }
        else {
          lVar2 = ((code)FUN_004c17f0)(param_1,*(u32 *)(pbVar1 + 0x14),iVar3 << 2);
          if (lVar2 == 0) {
            param_1 = 0;
          }
          else {
            lVar2 = ((code)FUN_004c1750)(param_1,*(u32 *)(pbVar1 + 0x18),iVar3 << 4);
            if (lVar2 == 0) {
              param_1 = 0;
            }
            else {
              lVar2 = ((code)FUN_004c1750)(param_1,*(u32 *)(pbVar1 + 0xc),*(int *)pbVar1 << 6);
              if (lVar2 == 0) {
                param_1 = 0;
              }
              else {
                lVar2 = ((code)FUN_00489080)(param_1,pbVar1);
                if (lVar2 == 0) {
                  param_1 = 0;
                }
              }
            }
          }
        }
      }
    }
    else {
      lVar2 = ((code)FUN_0048a800)(param_1,param_3);
      if (lVar2 == 0) {
        param_1 = 0;
      }
    }
  }
  return param_1;
}

// FUN_00489CD0 NONMATCHING

u64 FUN_00489cd0(u64 param_1,u64 param_2,u64 param_3)

{
  int iVar1;
  u32 uVar2;
  long lVar3;
  long lVar4;
  u32 uVar5;
  int *piVar6;
  u32 uVar7;
  u8 auStack_110 [264];
  u32 uStack_8;
  u32 uStack_4;
  
  if ((*(u32 *)((int)param_3 + 8) & 0x1000000) == 0) {
    lVar3 = ((code)FUN_004c1910)(param_1,&uStack_4,4);
    if (lVar3 == 0) {
      param_1 = 0;
    }
    else {
      iVar1 = *(int *)((int)param_3 + 0x14);
      uVar7 = uStack_4 >> 8 & 0xff;
      uVar5 = uStack_4 >> 0x10 & 0xff;
      uStack_8 = uVar7;
      lVar3 = (*DAT_00960188)(DAT_0095de28,0x30116);
      ((code)FUN_00521408)(lVar3,0,0x48);
      if (uVar5 == 0) {
        ((code)FUN_004893e0)(lVar3,0,iVar1);
      }
      if (uStack_8 == 0) {
        ((code)FUN_00489460)(lVar3,0,0,auStack_110,&uStack_8,iVar1);
      }
      lVar4 = ((code)FUN_00489550)(lVar3,uStack_4 & 0xff,uStack_8,iVar1,auStack_110,0,0,0);
      if (lVar4 == 0) {
        (*DAT_0096018c)(DAT_0095de28,lVar3);
        lVar3 = 0;
      }
      if (lVar3 == 0) {
        param_1 = 0;
      }
      else {
        piVar6 = (int *)lVar3;
        uVar2 = ((code)FUN_004c5250)(param_1,piVar6[2],uVar7);
        if (uVar7 == uVar2) {
          lVar4 = ((code)FUN_004c1910)(param_1,piVar6[5],iVar1 << 2);
          if (lVar4 == 0) {
            param_1 = 0;
          }
          else {
            lVar4 = ((code)FUN_004c18b0)(param_1,piVar6[6],iVar1 << 4);
            if (lVar4 == 0) {
              param_1 = 0;
            }
            else {
              piVar6[4] = uVar5;
              lVar4 = ((code)FUN_004c18b0)(param_1,piVar6[3],*piVar6 << 6);
              if (lVar4 == 0) {
                param_1 = 0;
              }
              else {
                lVar4 = ((code)FUN_00489160)(param_1,lVar3);
                if (lVar4 == 0) {
                  param_1 = 0;
                }
                else {
                  ((code)FUN_0048a2e0)(param_3,lVar3);
                }
              }
            }
          }
        }
        else {
          param_1 = 0;
        }
      }
    }
  }
  else {
    lVar3 = ((code)FUN_0048a9a0)(param_1,param_3);
    if (lVar3 == 0) {
      param_1 = 0;
    }
  }
  return param_1;
}

// FUN_00489F20 NONMATCHING

u64
FUN_00489f20(u64 param_1,u64 param_2,int param_3,u64 param_4,u64 param_5
            )

{
  int iVar1;
  int iVar2;
  long lVar3;
  u64 uVar4;
  int iVar5;
  u32 *puVar6;
  u32 uVar7;
  u8 auStack_110 [264];
  int iStack_8;
  int iStack_4;
  
  iVar1 = *(int *)(param_3 + 0x18);
  lVar3 = ((code)FUN_0048a2c0)(iVar1);
  if (lVar3 == 0) {
    lVar3 = ((code)FUN_004c1910)(param_1,&iStack_4,4);
    if (lVar3 == 0) {
      param_1 = 0;
    }
    else {
      iVar2 = *(int *)(iVar1 + 0x14);
      iStack_8 = iStack_4;
      uVar4 = (*DAT_00960188)(DAT_0095de28,0x30116);
      ((code)FUN_00521408)(uVar4,0,0x48);
      if (iStack_8 == 0) {
        ((code)FUN_00489460)(uVar4,0,0,auStack_110,&iStack_8,iVar2);
      }
      lVar3 = ((code)FUN_00489550)(uVar4,iStack_4,iStack_8,iVar2,auStack_110,0,0,0);
      if (lVar3 == 0) {
        (*DAT_0096018c)(DAT_0095de28,uVar4);
        uVar4 = 0;
      }
      lVar3 = ((code)FUN_004c5620)(param_1,4);
      if (lVar3 == 0) {
        param_1 = 0;
      }
      else {
        puVar6 = (u32 *)uVar4;
        lVar3 = ((code)FUN_004c1910)(param_1,puVar6[5],iVar2 << 2);
        if (lVar3 == 0) {
          param_1 = 0;
        }
        else {
          lVar3 = ((code)FUN_004c18b0)(param_1,puVar6[6],iVar2 << 4);
          if (lVar3 == 0) {
            param_1 = 0;
          }
          else {
            uVar7 = 0;
            if (*puVar6 != 0) {
              iVar5 = 0;
              do {
                lVar3 = ((code)FUN_004c5620)(param_1,0xc);
                if (lVar3 == 0) {
                  return 0;
                }
                lVar3 = ((code)FUN_004c18b0)(param_1,puVar6[3] + iVar5,0x40);
                if (lVar3 == 0) {
                  return 0;
                }
                uVar7 = uVar7 + 1;
                iVar5 = iVar5 + 0x40;
              } while (uVar7 < *puVar6);
            }
            ((code)FUN_004893e0)(uVar4,puVar6[6],iVar2);
            ((code)FUN_00489460)();
            ((code)FUN_0048a2e0)(iVar1,uVar4);
          }
        }
      }
    }
  }
  else {
    lVar3 = ((code)FUN_004c5620)(param_1,param_5);
    if (lVar3 == 0) {
      param_1 = 0;
    }
  }
  return param_1;
}

// FUN_0048A1A0 NONMATCHING

u32 FUN_0048a1a0(void)
{
  DAT_0095de10 = ((code)FUN_004ca520)(0,0x116,0x489730,0x489840);
  DAT_0095de14 = ((code)FUN_00492c30)(4,0x116,0x489960,0x4899a0,0x4899d0);
  ((code)FUN_00492c90)(0x116,0x489f20,0x48a180,0x48a190);
  ((code)FUN_00492cc0)(0x116,0x4899f0);
  ((code)FUN_00492ce0)(0x116,0x489a80);
  DAT_0095de18 = ((code)FUN_00493c50)(4,0x116,0x4898c0,0x4898e0,0x489950);
  ((code)FUN_00493c80)(0x116,0x489cd0,0x489b70,0x489ae0);
  return 1;
}

#pragma schedule on
// FUN_0048A2A0
int FUN_0048a2a0(int param_1,u32 param_2)
{
  int iVar1;
  u32 uVar1;

  iVar1 = param_1;
  uVar1 = DAT_0095de14_abs[0];
  *(u32 *)((u8 *)iVar1 + uVar1) = param_2;
  return iVar1;
}
#pragma schedule off

#pragma schedule on
// FUN_0048A2C0
u32 FUN_0048a2c0(int param_1)
{
  return *(u32 *)(param_1 + DAT_0095de18_abs[0]);
}
#pragma schedule off

#pragma alias DAT_0095de18_abs DAT_0095de18
extern u32 DAT_0095de18_abs[];

// FUN_0048A2E0 NONMATCHING

u64 FUN_0048a2e0(u64 param_1,int param_2)
{
  int iVar1;
  long lVar2;
  
  iVar1 = *(int *)((int)param_1 + DAT_0095de18);
  if (param_2 != iVar1) {
    if (iVar1 != 0) {
      ((code)FUN_0048a790)();
    }
    *(int *)((int)param_1 + DAT_0095de18) = param_2;
    if ((param_2 != 0) && (lVar2 = ((code)FUN_0048a4b0)(param_1), lVar2 == 0)) {
      param_1 = 0;
    }
  }
  return param_1;
}

#pragma schedule on
// FUN_0048A370 NONMATCHING
u64 FUN_0048a370(int param_1)
{
  if (*(int *)(param_1 + 0x44) != 0) {
    DAT_0096017c_abs[0]();
  }
  FUN_00489020(param_1);
  DAT_0096018c_abs[0](DAT_0095de28,param_1);
  return 0;
}
#pragma schedule off

// FUN_0048A3D0
#pragma optimization_level 3
u32 FUN_0048a3d0(u32 *param_1)
{
  return *param_1;
}
#pragma optimization_level 2

// FUN_0048A3E0
#pragma optimization_level 3
u32 FUN_0048a3e0(int param_1)
{
  return *(u32 *)(param_1 + 0xc);
}
#pragma optimization_level 2

// FUN_0048A3F0 NONMATCHING
void FUN_0048a3f0(u64 param_1,long param_2)
{
  long lVar1;
  
  lVar1 = ((code)FUN_004ca550)(0x120);
  if ((lVar1 == -1) && (param_2 == 2)) {
    param_2 = 1;
  }
  else {
    lVar1 = ((code)FUN_004ca550)(0x12e);
    if ((lVar1 == -1) && (param_2 == 3)) {
      param_2 = 1;
    }
  }
  ((code)FUN_0048ac10)(param_1,param_2);
  return;
}

// FUN_0048A480 NONMATCHING
u32 FUN_0048a480(int param_1)
{
  u32 uVar1;

  if (*(int *)(*(int *)(param_1 + 0x6c) + 0x2c) == 0x116) {
    uVar1 = *(u32 *)(*(int *)(param_1 + 0x6c) + 0x30);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

#pragma optimization_level 3
#pragma schedule on
// FUN_0048A4B0 NONMATCHING
u64 FUN_0048a4b0(u32 param_1)
{
  u32 uVar1;
  int iVar2;
  u32 uVar3;
  u32 *puVar4;
  u32 *puVar5;
  u32 uVar6;
  u32 uVar7;
  int iVar8;

  if ((*(u32 *)((int)param_1 + 8) & 0x1000000) == 0) {
    iVar2 = FUN_0048a2c0_noarg();
    puVar5 = *(u32 **)(iVar2 + 0x18);
    puVar4 = *(u32 **)(iVar2 + 0x14);
    uVar1 = *(u32 *)((int)param_1 + 0x14);
    *(u32 *)(iVar2 + 0x1c) = 0;
    *(u32 *)(iVar2 + 0x20) = 0;
    *(u32 *)(iVar2 + 0x24) = 0;
    *(u32 *)(iVar2 + 0x28) = 0;
    if (*(int *)(iVar2 + 0x30) == 0) {
      uVar6 = 0;
      if (uVar1 != 0) {
        do {
          *puVar5 = *puVar5 & 0xfffffc00 | ((u8)*puVar4 + 1) * 4;
          if (*(float *)(puVar5 + 1) != 0.0f) {
            uVar7 = puVar5[1] & 0xfffffc00 | ((*puVar4 >> 8 & 0xff) + 1) * 4;
          }
          else {
            uVar7 = 0;
          }
          uVar3 = (u32)(*(float *)(puVar5 + 1) != 0.0f);
          puVar5[1] = uVar7;
          if (*(float *)(puVar5 + 2) == 0.0f) {
            uVar7 = 0;
          }
          else {
            uVar3 = uVar3 + 1;
            uVar7 = puVar5[2] & 0xfffffc00 | ((*puVar4 >> 0x10 & 0xff) + 1) * 4;
          }
          puVar5[2] = uVar7;
          if (*(float *)(puVar5 + 3) == 0.0f) {
            uVar7 = 0;
          }
          else {
            uVar3 = uVar3 + 1;
            uVar7 = puVar5[3] & 0xfffffc00 | ((*puVar4 >> 0x18) + 1) * 4;
          }
          puVar5[3] = uVar7;
          iVar8 = iVar2 + uVar3 * 4;
          uVar6 = uVar6 + 1;
          puVar5 = puVar5 + 4;
          puVar4 = puVar4 + 1;
          *(int *)(iVar8 + 0x1c) = *(int *)(iVar8 + 0x1c) + 1;
        } while (uVar6 < uVar1);
      }
    }
    else {
      uVar6 = 0;
      if (uVar1 != 0) {
        do {
          *puVar5 = *puVar5 & 0xfffffc00 |
                    (*(u8 *)(*(int *)(iVar2 + 0x38) + (u32)(u8)*puVar4) + 1) * 4;
          if (*(float *)(puVar5 + 1) != 0.0f) {
            uVar7 = puVar5[1] & 0xfffffc00 |
                    (*(u8 *)(*(int *)(iVar2 + 0x38) + (*puVar4 >> 8 & 0xff)) + 1) * 4;
          }
          else {
            uVar7 = 0;
          }
          uVar3 = (u32)(*(float *)(puVar5 + 1) != 0.0f);
          puVar5[1] = uVar7;
          if (*(float *)(puVar5 + 2) == 0.0f) {
            uVar7 = 0;
          }
          else {
            uVar3 = uVar3 + 1;
            uVar7 = puVar5[2] & 0xfffffc00 |
                    (*(u8 *)(*(int *)(iVar2 + 0x38) + (*puVar4 >> 0x10 & 0xff)) + 1) * 4;
          }
          puVar5[2] = uVar7;
          if (*(float *)(puVar5 + 3) == 0.0f) {
            uVar7 = 0;
          }
          else {
            uVar3 = uVar3 + 1;
            uVar7 = puVar5[3] & 0xfffffc00 |
                    (*(u8 *)(*(int *)(iVar2 + 0x38) + (*puVar4 >> 0x18)) + 1) * 4;
          }
          puVar5[3] = uVar7;
          iVar8 = iVar2 + uVar3 * 4;
          uVar6 = uVar6 + 1;
          puVar5 = puVar5 + 4;
          puVar4 = puVar4 + 1;
          *(int *)(iVar8 + 0x1c) = *(int *)(iVar8 + 0x1c) + 1;
        } while (uVar6 < uVar1);
      }
    }
  }
  return param_1;
}
#pragma schedule off
#pragma optimization_level 2
// FUN_0048A790
#pragma optimization_level 3
u64 FUN_0048a790(u64 param_1)
{
  return param_1;
}
#pragma optimization_level 2

// FUN_0048A7A0 NONMATCHING
#pragma schedule on
int FUN_0048a7a0(int param_1)
{
  int *piVar1;
  int iVar2;

  piVar1 = *(int **)(param_1 + DAT_0095de18);
  iVar2 = *piVar1 * 0x40 + piVar1[1] + 0x14;
  return iVar2 + 0x10 + FUN_00489320(piVar1);
}
#pragma schedule off

// FUN_0048A800 NONMATCHING



u64 FUN_0048a800(u64 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  u8 *pbVar3;
  int iVar4;
  long lVar5;
  u32 auStack_8 [2];
  
  auStack_8[1] = 4;
  iVar1 = **(int **)(param_2 + DAT_0095de18);
  iVar2 = (*(int **)(param_2 + DAT_0095de18))[1];
  iVar4 = ((code)FUN_00489320)();
  lVar5 = ((code)FUN_004c15a0)(param_1,1,iVar1 * 0x40 + iVar2 + iVar4 + 0x18,0x37002,0x37);
  if (lVar5 == 0) {
    param_1 = 0;
  }
  else {
    lVar5 = ((code)FUN_004c17f0)(param_1,auStack_8 + 1,4);
    if (lVar5 == 0) {
      param_1 = 0;
    }
    else {
      pbVar3 = *(u8 **)(param_2 + DAT_0095de18);
      auStack_8[0] = (u32)*pbVar3 |
                     (*(u32 *)(pbVar3 + 0x10) & 0xff) << 0x10 | (*(u32 *)(pbVar3 + 4) & 0xff) << 8
      ;
      lVar5 = ((code)FUN_004c17f0)(param_1,auStack_8,4);
      if (lVar5 == 0) {
        param_1 = 0;
      }
      else {
        lVar5 = ((code)FUN_004c53f0)(param_1,*(u32 *)(pbVar3 + 8),*(u32 *)(pbVar3 + 4));
        if (lVar5 == 0) {
          param_1 = 0;
        }
        else {
          lVar5 = ((code)FUN_004c53f0)(param_1,*(u32 *)(pbVar3 + 0xc),*(int *)pbVar3 << 6);
          if (lVar5 == 0) {
            param_1 = 0;
          }
          else {
            lVar5 = ((code)FUN_004c17f0)(param_1,pbVar3 + 0x1c,0x10);
            if (lVar5 == 0) {
              param_1 = 0;
            }
            else {
              lVar5 = ((code)FUN_00489080)(param_1,pbVar3);
              if (lVar5 == 0) {
                param_1 = 0;
              }
            }
          }
        }
      }
    }
  }
  return param_1;
}

// FUN_0048A9A0 NONMATCHING

long FUN_0048a9a0(long param_1,u64 param_2)

{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  long lVar4;
  u64 uVar5;
  u32 *puVar6;
  int iVar7;
  u32 uStack_18;
  u32 uStack_14;
  int iStack_10;
  u32 uStack_c;
  int iStack_8;
  u32 uStack_4;
  
  lVar4 = ((code)FUN_004c1600)(param_1,1,&iStack_8,&uStack_4);
  if (lVar4 == 0) {
    param_1 = 0;
  }
  else if ((uStack_4 < 0x35000) || (0x37002 < uStack_4)) {
    uStack_18 = 0x116;
    uStack_14 = ((code)FUN_004c1d10)(0xffffffff80000004);
    ((code)FUN_004c1c50)(&uStack_18);
    param_1 = 0;
  }
  else {
    lVar4 = ((code)FUN_004c1910)(param_1,&iStack_10,4);
    if (lVar4 == 0) {
      param_1 = 0;
    }
    else if (iStack_10 == 4) {
      uVar5 = (*DAT_00960188)(DAT_0095de28,0x30116);
      ((code)FUN_00521408)(uVar5,0,0x48);
      lVar4 = ((code)FUN_004c1910)(param_1,&uStack_c,4);
      if (lVar4 == 0) {
        param_1 = 0;
      }
      else {
        puVar6 = (u32 *)uVar5;
        *puVar6 = uStack_c & 0xff;
        puVar6[1] = uStack_c >> 8 & 0xff;
        puVar6[4] = uStack_c >> 0x10 & 0xff;
        uVar1 = puVar6[1];
        iVar7 = *puVar6 * 0x40;
        iStack_8 = iVar7 + uVar1;
        uVar2 = (*DAT_00960178)(iStack_8 + 0xf,0x30116);
        puVar6[0x11] = uVar2;
        puVar6[3] = puVar6[0x11] + 0xf & 0xfffffff0;
        puVar6[2] = puVar6[3] + *puVar6 * 0x40;
        uVar2 = ((code)FUN_004c5250)(param_1,puVar6[2],uVar1);
        if (uVar1 == uVar2) {
          iVar3 = ((code)FUN_004c5250)(param_1,puVar6[3],iVar7);
          if (iVar7 == iVar3) {
            lVar4 = ((code)FUN_004c1910)(param_1,puVar6 + 7,0x10);
            if (lVar4 == param_1) {
              lVar4 = ((code)FUN_00489160)(param_1,uVar5);
              if (lVar4 == 0) {
                param_1 = 0;
              }
              else {
                ((code)FUN_0048a2e0)(param_2,uVar5);
              }
            }
            else {
              param_1 = 0;
            }
          }
          else {
            param_1 = 0;
          }
        }
        else {
          param_1 = 0;
        }
      }
    }
    else {
      param_1 = 0;
    }
  }
  return param_1;
}

// FUN_0048ABF0
#pragma optimization_level 3
u32 FUN_0048abf0(void)
{
  return 1;
}
#pragma optimization_level 2

// FUN_0048AC00
#pragma optimization_level 3
u32 FUN_0048ac00(void)
{
  return 1;
}
#pragma optimization_level 2

// FUN_0048AC10 NONMATCHING

u64 FUN_0048ac10(u64 param_1,long param_2)

{
  u8 bVar1;
  int iVar2;
  u32 uVar3;
  int iVar4;
  u64 uVar5;
  
  iVar4 = (int)param_1;
  bVar1 = (*(u32 *)(*(int *)(iVar4 + 0x18) + 8) & 0x80) == 0;
  iVar2 = ((code)FUN_00492d00)(0x120);
  if (param_2 == 0) {
    uVar5 = 0x11002;
    if (*(char *)(iVar4 + iVar2) != '\0') {
      if (bVar1) {
        uVar5 = 0x11013;
      }
      else {
        uVar5 = 0x11014;
      }
    }
  }
  else if (param_2 == 3) {
    uVar5 = 0x11002;
  }
  else if (param_2 == 2) {
    if (bVar1) {
      uVar5 = 0x11013;
    }
    else {
      uVar5 = 0x11014;
    }
  }
  else if (param_2 == 1) {
    uVar5 = 0x11002;
  }
  else {
    uVar5 = 0x11002;
  }
  uVar3 = ((code)FUN_0046a890)(uVar5);
  *(u32 *)(iVar4 + 0x6c) = uVar3;
  return param_1;
}

// FUN_0048AD20 NONMATCHING

u8 FUN_0048ad20(void)

{
  int iVar1;
  long lVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  u32 uStack_8;
  u32 uStack_4;
  
  lVar2 = (*DAT_00960178)(0x3030,0x40102);
  iGpffffba8c = (int)lVar2;
  if (lVar2 == 0) {
    uStack_8 = 0x102;
    uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000013,0x3030);
    ((code)FUN_004c1c50)(&uStack_8);
  }
  else {
    iGpffffba90 = iGpffffba8c + 0x404;
    iGpffffba94 = iGpffffba8c + 0x808;
    iGpffffba98 = iGpffffba8c + 0xc0c;
    iVar3 = 0;
    iGpffffba9c = iGpffffba8c + 0x1010;
    iGpffffbaa0 = iGpffffba8c + 0x1414;
    iGpffffbaa4 = iGpffffba8c + 0x1818;
    iGpffffbaa8 = iGpffffba8c + 0x1c1c;
    iGpffffbaac = iGpffffba8c + 0x2020;
    iGpffffbab0 = iGpffffba8c + 0x2424;
    iGpffffbab4 = iGpffffba8c + 0x2828;
    iGpffffbab8 = iGpffffba8c + 0x2c2c;
    iVar1 = 0;
    do {
      fVar4 = (float)iVar3;
      iVar3 = iVar3 + 1;
      fVar4 = fVar4 / 256.0;
      *(float *)(iGpffffba8c + iVar1) = (fVar4 * fVar4 * fVar4) / 6.0;
      fVar5 = fVar4 * -3.0;
      *(float *)(iGpffffba90 + iVar1) = (fVar4 * ((fVar5 + 3.0) * fVar4 + 3.0) + 1.0) / 6.0;
      fVar7 = fVar4 * 3.0;
      *(float *)(iGpffffba94 + iVar1) = (fVar4 * (fVar7 - 6.0) * fVar4 + 4.0) / 6.0;
      fVar6 = fVar4 * -1.0;
      *(float *)(iGpffffba98 + iVar1) = (fVar4 * ((fVar6 + 3.0) * fVar4 - 3.0) + 1.0) / 6.0;
      *(float *)(iGpffffba9c + iVar1) = (fVar4 * fVar4) / 2.0;
      *(float *)(iGpffffbaa0 + iVar1) = ((fVar5 + 2.0) * fVar4 + 1.0) / 2.0;
      *(float *)(iGpffffbaa4 + iVar1) = ((fVar7 + -4.0) * fVar4) / 2.0;
      *(float *)(iGpffffbaa8 + iVar1) = ((fVar6 + 2.0) * fVar4 - 1.0) / 2.0;
      *(float *)(iGpffffbaac + iVar1) = fVar4;
      *(float *)(iGpffffbab0 + iVar1) = fVar5 + 1.0;
      *(float *)(iGpffffbab4 + iVar1) = fVar7 - 2.0;
      *(float *)(iGpffffbab8 + iVar1) = fVar6 + 1.0;
      iVar1 = iVar1 + 4;
    } while (iVar3 < 0x101);
  }
  return iGpffffba8c != 0;
}

#pragma optimization_level 3
#pragma schedule on
// FUN_0048AF80 NONMATCHING

long FUN_0048af80(u32 param_1)

{
  int *piVar1;
  u32 *puVar2;
  long lVar3;
  long lVar4;
  u32 uVar5;
  int *piVar6;
  int iVar7;
  u8 bVar8;
  int iVar9;
  int iVar10;
  u8 bVar11;
  int iVar12;
  int iVar13;
  float *pfVar14;
  float *pfVar15;
  int *piVar16;
  int iVar17;
  int iVar18;
  u32 *puVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  float fVar23;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  iVar22 = param_1 * 4;
  lVar3 = (*DAT_00960178)(param_1 * iVar22,0x30102);
  if (lVar3 == 0) {
    uStack_8 = 0x102;
    uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000013,param_1 * iVar22);
    ((code)FUN_004c1c50)(&uStack_8);
    lVar3 = 0;
  }
  else {
    ((code)FUN_00521408)(lVar3,0,param_1 * param_1 * 4);
    iVar20 = (param_1 - 1) * 4;
    lVar4 = (*DAT_00960178)(iVar20,0x30102);
    if (lVar4 == 0) {
      uStack_10 = 0x102;
      uStack_c = ((code)FUN_004c1d10)(0xffffffff80000013,iVar20);
      ((code)FUN_004c1c50)(&uStack_10);
      lVar4 = 0;
    }
    else {
      iVar12 = param_1 - 1;
      puVar2 = (u32 *)lVar4;
      *puVar2 = 1;
      iVar20 = 2;
      puVar2[1] = 4;
      if (2 < iVar12) {
        if (8 < (int)(param_1 - 3)) {
          bVar8 = 0;
          if ((1 < iVar12) && (iVar12 < 0x7fffffff)) {
            bVar8 = 1;
          }
          if (bVar8) {
            piVar6 = (int *)(puVar2 + 2);
            do {
              iVar20 = iVar20 + 8;
              *piVar6 = piVar6[-1] * 4 - piVar6[-2];
              piVar6[1] = *piVar6 * 4 - piVar6[-1];
              piVar6[2] = piVar6[1] * 4 - *piVar6;
              piVar6[3] = piVar6[2] * 4 - piVar6[1];
              piVar6[4] = piVar6[3] * 4 - piVar6[2];
              piVar6[5] = piVar6[4] * 4 - piVar6[3];
              piVar6[6] = piVar6[5] * 4 - piVar6[4];
              piVar6[7] = piVar6[6] * 4 - piVar6[5];
              piVar6 = piVar6 + 8;
            } while (iVar20 < (int)(param_1 - 9));
          }
        }
        if (iVar20 < (int)(param_1 - 1)) {
          piVar6 = (int *)(puVar2 + iVar20);
          do {
            iVar20 = iVar20 + 1;
            *piVar6 = piVar6[-1] * 4 - piVar6[-2];
            piVar6 = piVar6 + 1;
          } while (iVar20 < (int)(param_1 - 1));
        }
      }
    }
    if (lVar4 == 0) {
      (*DAT_0096017c)(lVar3);
      lVar3 = 0;
    }
    else {
      iVar20 = *(int *)(param_1 * 4 + (int)lVar4 + -8);
      (*DAT_0096017c)(lVar4);
      lVar4 = (*DAT_00960178)(iVar22,0x30102);
      if (lVar4 == 0) {
        uStack_18 = 0x102;
        uStack_14 = ((code)FUN_004c1d10)(0xffffffff80000013,iVar22);
        ((code)FUN_004c1c50)(&uStack_18);
        lVar4 = 0;
      }
      else {
        iVar22 = 2;
        puVar2 = (u32 *)lVar4;
        *puVar2 = 1;
        puVar2[1] = 2;
        if (2 < (int)param_1) {
          if (8 < (int)(param_1 - 2)) {
            bVar8 = 0;
            if ((1 < (int)param_1) && ((int)param_1 < 0x7fffffff)) {
              bVar8 = 1;
            }
            if (bVar8) {
              piVar6 = (int *)(puVar2 + 2);
              do {
                iVar22 = iVar22 + 8;
                *piVar6 = piVar6[-1] * 4 - piVar6[-2];
                piVar6[1] = *piVar6 * 4 - piVar6[-1];
                piVar6[2] = piVar6[1] * 4 - *piVar6;
                piVar6[3] = piVar6[2] * 4 - piVar6[1];
                piVar6[4] = piVar6[3] * 4 - piVar6[2];
                piVar6[5] = piVar6[4] * 4 - piVar6[3];
                piVar6[6] = piVar6[5] * 4 - piVar6[4];
                piVar6[7] = piVar6[6] * 4 - piVar6[5];
                piVar6 = piVar6 + 8;
              } while (iVar22 < (int)(param_1 - 8));
            }
          }
          if (iVar22 < (int)param_1) {
            piVar6 = (int *)(puVar2 + iVar22);
            do {
              iVar22 = iVar22 + 1;
              *piVar6 = piVar6[-1] * 4 - piVar6[-2];
              piVar6 = piVar6 + 1;
            } while (iVar22 < (int)param_1);
          }
        }
      }
      if (lVar4 == 0) {
        (*DAT_0096017c)(lVar3);
        lVar3 = 0;
      }
      else {
        iVar12 = param_1 - 2;
        iVar22 = (int)lVar4;
        if (-1 < iVar12) {
          uVar5 = param_1;
          if ((int)param_1 < 0) {
            uVar5 = param_1 + 1;
          }
          if (8 < (int)uVar5 >> 1) {
            bVar8 = 0;
            if ((-1 < (int)(param_1 - 2)) && (-0x7fffffff < (int)(param_1 - 2))) {
              bVar8 = 1;
            }
            if (bVar8) {
              piVar6 = (int *)(iVar22 + iVar12 * 4);
              do {
                iVar12 = iVar12 + -0x10;
                *piVar6 = -*piVar6;
                piVar6[-2] = -piVar6[-2];
                piVar6[-4] = -piVar6[-4];
                piVar6[-6] = -piVar6[-6];
                piVar6[-8] = -piVar6[-8];
                piVar6[-10] = -piVar6[-10];
                piVar6[-0xc] = -piVar6[-0xc];
                piVar6[-0xe] = -piVar6[-0xe];
                piVar6 = piVar6 + -0x10;
              } while (0xf < iVar12);
            }
          }
          if (-1 < iVar12) {
            piVar6 = (int *)(iVar22 + iVar12 * 4);
            do {
              iVar12 = iVar12 + -2;
              *piVar6 = -*piVar6;
              piVar6 = piVar6 + -2;
            } while (-1 < iVar12);
          }
        }
        iVar12 = 2;
        if ((param_1 & 1) == 0) {
          iVar12 = -2;
        }
        iVar13 = 0;
        puVar2 = (u32 *)lVar3;
        if (0 < (int)param_1) {
          iVar17 = 0;
          fVar23 = (float)iVar20;
          iVar20 = 1;
          do {
            pfVar15 = (float *)(puVar2 + iVar17);
            piVar6 = (int *)(iVar22 + ((param_1 - 1) - iVar13) * 4);
            *pfVar15 = (float)*piVar6 / fVar23;
            if (0 < iVar13) {
              iVar18 = iVar20;
              if (8 < iVar13) {
                iVar7 = 0;
                if ((0 < iVar13) && (iVar13 < 0x7fffffff)) {
                  iVar7 = iVar20;
                }
                if (iVar7 != 0) {
                  pfVar14 = pfVar15 + 1;
                  piVar16 = (int *)(iVar22 + 4);
                  do {
                    *pfVar14 = (float)(iVar12 * *piVar16 * *piVar6) / fVar23;
                    pfVar14[1] = (float)(iVar12 * piVar16[1] * *piVar6) / fVar23;
                    pfVar14[2] = (float)(iVar12 * piVar16[2] * *piVar6) / fVar23;
                    pfVar14[3] = (float)(iVar12 * piVar16[3] * *piVar6) / fVar23;
                    pfVar14[4] = (float)(iVar12 * piVar16[4] * *piVar6) / fVar23;
                    pfVar14[5] = (float)(iVar12 * piVar16[5] * *piVar6) / fVar23;
                    pfVar14[6] = (float)(iVar12 * piVar16[6] * *piVar6) / fVar23;
                    piVar1 = piVar16 + 7;
                    iVar18 = iVar18 + 8;
                    piVar16 = piVar16 + 8;
                    pfVar14[7] = (float)(iVar12 * *piVar1 * *piVar6) / fVar23;
                    pfVar14 = pfVar14 + 8;
                  } while (iVar18 <= iVar13 + -8);
                }
              }
              if (iVar18 <= iVar13) {
                pfVar15 = pfVar15 + iVar18;
                piVar16 = (int *)(iVar22 + iVar18 * 4);
                do {
                  iVar7 = *piVar16;
                  iVar18 = iVar18 + 1;
                  piVar16 = piVar16 + 1;
                  *pfVar15 = (float)(iVar12 * iVar7 * *piVar6) / fVar23;
                  pfVar15 = pfVar15 + 1;
                } while (iVar18 <= iVar13);
              }
            }
            iVar13 = iVar13 + 1;
            iVar17 = iVar17 + param_1;
          } while (iVar13 < (int)param_1);
        }
        iVar22 = 0;
        puVar2[param_1 * param_1 + -1] = *puVar2;
        if (0 < (int)param_1) {
          iVar20 = param_1 - 1;
          iVar12 = 0;
          do {
            if (iVar22 < iVar20) {
              iVar13 = iVar20;
              if (8 < iVar20 - iVar22) {
                bVar8 = 0;
                if ((iVar22 <= iVar20) && (-0x80000000 < iVar22)) {
                  bVar8 = 1;
                }
                bVar11 = 0;
                if ((bVar8) && (-0x80000000 < iVar20)) {
                  bVar11 = 1;
                }
                if (bVar11) {
                  puVar19 = puVar2 + iVar12 + iVar20;
                  iVar17 = param_1 * (param_1 - iVar22) + -1;
                  do {
                    *puVar19 = puVar2[iVar17 - iVar13];
                    iVar9 = iVar13 + -3;
                    iVar10 = iVar13 + -4;
                    puVar19[-1] = puVar2[iVar17 - (iVar13 + -1)];
                    iVar18 = iVar13 + -5;
                    iVar7 = iVar13 + -6;
                    puVar19[-2] = puVar2[iVar17 - (iVar13 + -2)];
                    iVar21 = iVar13 + -7;
                    iVar13 = iVar13 + -8;
                    puVar19[-3] = puVar2[iVar17 - iVar9];
                    puVar19[-4] = puVar2[iVar17 - iVar10];
                    puVar19[-5] = puVar2[iVar17 - iVar18];
                    puVar19[-6] = puVar2[iVar17 - iVar7];
                    puVar19[-7] = puVar2[iVar17 - iVar21];
                    puVar19 = puVar19 + -8;
                  } while (iVar22 + 8 < iVar13);
                }
              }
              if (iVar22 < iVar13) {
                puVar19 = puVar2 + iVar12 + iVar13;
                do {
                  iVar17 = (param_1 * (param_1 - iVar22) + -1) - iVar13;
                  iVar13 = iVar13 + -1;
                  *puVar19 = puVar2[iVar17];
                  puVar19 = puVar19 + -1;
                } while (iVar22 < iVar13);
              }
            }
            iVar22 = iVar22 + 1;
            iVar12 = iVar12 + param_1;
          } while (iVar22 < (int)param_1);
        }
        (*DAT_0096017c)(lVar4);
      }
    }
  }
  return lVar3;
}
#pragma schedule off
#pragma optimization_level 2

#pragma optimization_level 3
#pragma schedule on
// FUN_0048B910 NONMATCHING

u64 FUN_0048b910(u32 param_1,float *param_2)

{
  float *pfVar1;
  float *pfVar2;
  u8 bVar3;
  u32 uVar4;
  u32 uVar5;
  u32 *puVar6;
  long lVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  int iVar12;
  float *pfVar13;
  float *pfVar14;
  float *pfVar15;
  float *pfVar16;
  float *pfVar17;
  float *pfVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  u32 *puVar24;
  float *pfVar25;
  u32 uVar26;
  int iVar27;
  u32 uVar28;
  u32 uVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  float fVar38;
  float fVar39;
  float fVar40;
  float fVar41;
  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_34;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  uVar4 = ((code)FUN_0048d200)();
  iVar27 = (int)param_1;
  puVar24 = (u32 *)(iVar27 + 0x38);
  if (*(int *)(iVar27 + 0xc) != 2) {
    if (*(int *)(iVar27 + 0xc) != 1) {
      uStack_20 = 0x102;
      uStack_1c = ((code)FUN_004c1d10)();
      ((code)FUN_004c1c50)(&uStack_20);
      return 0;
    }
    uVar26 = uVar4;
    if (9 < (int)uVar4) {
      uVar26 = 10;
    }
    iVar23 = *(int *)((u8 *)DAT_0095de40 + uVar26 * 4);
    if (iVar23 != 0) {
      iVar22 = 0;
      if (0 < (int)uVar4) {
        iVar19 = 0;
        iVar12 = uVar26 - uVar4;
        uVar5 = uVar26;
        if ((int)uVar26 < 0) {
          uVar5 = uVar26 + 1;
        }
        iVar9 = (int)uVar5 >> 1;
        puVar6 = puVar24;
        do {
          fStack_10 = 0.0;
          fStack_c = 0.0;
          fStack_8 = 0.0;
          if (iVar22 < iVar9) {
            iVar10 = 0;
            if (0 < (int)uVar26) {
              if (8 < (int)uVar26) {
                bVar3 = 0;
                if ((-1 < (int)uVar26) && ((int)uVar26 < 0x7fffffff)) {
                  bVar3 = 1;
                }
                if (bVar3) {
                  pfVar25 = (float *)(iVar23 + iVar19 * 4);
                  pfVar11 = param_2;
                  do {
                    iVar10 = iVar10 + 8;
                    fVar38 = *pfVar25;
                    pfVar13 = pfVar11 + 2;
                    fVar37 = pfVar25[1];
                    pfVar14 = pfVar11 + 5;
                    fVar36 = pfVar25[2];
                    fVar39 = pfVar25[3];
                    pfVar15 = pfVar11 + 8;
                    fVar41 = pfVar25[6];
                    pfVar16 = pfVar11 + 0xb;
                    fVar34 = pfVar25[4];
                    pfVar17 = pfVar11 + 0xe;
                    fVar40 = pfVar25[5];
                    pfVar18 = pfVar11 + 0x11;
                    pfVar1 = pfVar11 + 0x14;
                    fVar35 = pfVar25[7];
                    pfVar2 = pfVar11 + 0x17;
                    pfVar25 = pfVar25 + 8;
                    fStack_10 = pfVar11[0x15] * fVar35 +
                                pfVar11[0x12] * fVar41 +
                                pfVar11[0xf] * fVar40 +
                                pfVar11[0xc] * fVar34 +
                                pfVar11[9] * fVar39 +
                                pfVar11[6] * fVar36 +
                                pfVar11[3] * fVar37 + *pfVar11 * fVar38 + fStack_10 + 0.0 + 0.0 +
                                0.0 + 0.0 + 0.0 + 0.0 + 0.0 + 0.0;
                    fStack_c = pfVar11[0x16] * fVar35 +
                               pfVar11[0x13] * fVar41 +
                               pfVar11[0x10] * fVar40 +
                               pfVar11[0xd] * fVar34 +
                               pfVar11[10] * fVar39 +
                               pfVar11[7] * fVar36 +
                               pfVar11[4] * fVar37 + pfVar11[1] * fVar38 + fStack_c + 0.0 + 0.0 +
                               0.0 + 0.0 + 0.0 + 0.0 + 0.0 + 0.0;
                    pfVar11 = pfVar11 + 0x18;
                    fStack_8 = *pfVar2 * fVar35 +
                               *pfVar1 * fVar41 +
                               *pfVar18 * fVar40 +
                               *pfVar17 * fVar34 +
                               *pfVar16 * fVar39 +
                               *pfVar15 * fVar36 +
                               *pfVar14 * fVar37 + *pfVar13 * fVar38 + fStack_8 + 0.0 + 0.0 + 0.0 +
                               0.0 + 0.0 + 0.0 + 0.0 + 0.0;
                  } while (iVar10 < (int)(uVar26 - 8));
                }
              }
              if (iVar10 < (int)uVar26) {
                pfVar11 = (float *)(iVar23 + iVar19 * 4 + iVar10 * 4);
                pfVar25 = param_2 + iVar10 * 3;
                do {
                  iVar10 = iVar10 + 1;
                  fVar37 = *pfVar11;
                  pfVar13 = pfVar25 + 2;
                  pfVar11 = pfVar11 + 1;
                  fStack_10 = *pfVar25 * fVar37 + fStack_10 + 0.0;
                  fStack_c = pfVar25[1] * fVar37 + fStack_c + 0.0;
                  pfVar25 = pfVar25 + 3;
                  fStack_8 = *pfVar13 * fVar37 + fStack_8 + 0.0;
                } while (iVar10 < (int)uVar26);
              }
            }
          }
          else if (iVar22 < (int)(uVar4 - iVar9)) {
            iVar10 = 0;
            if (0 < (int)uVar26) {
              pfVar25 = param_2 + (iVar22 - iVar9) * 3;
              pfVar11 = (float *)(iVar23 + uVar26 * iVar9 * 4);
              do {
                iVar10 = iVar10 + 1;
                fVar37 = *pfVar11;
                pfVar13 = pfVar25 + 2;
                pfVar11 = pfVar11 + 1;
                fStack_10 = *pfVar25 * fVar37 + fStack_10 + 0.0;
                fStack_c = pfVar25[1] * fVar37 + fStack_c + 0.0;
                pfVar25 = pfVar25 + 3;
                fStack_8 = *pfVar13 * fVar37 + fStack_8 + 0.0;
              } while (iVar10 < (int)uVar26);
            }
          }
          else {
            iVar10 = 0;
            if (0 < (int)uVar26) {
              pfVar25 = (float *)(iVar23 + uVar26 * iVar12 * 4);
              pfVar11 = param_2 + (uVar4 - uVar26) * 3;
              do {
                iVar10 = iVar10 + 1;
                fVar37 = *pfVar25;
                pfVar13 = pfVar11 + 2;
                pfVar25 = pfVar25 + 1;
                fStack_10 = *pfVar11 * fVar37 + fStack_10 + 0.0;
                fStack_c = pfVar11[1] * fVar37 + fStack_c + 0.0;
                pfVar11 = pfVar11 + 3;
                fStack_8 = *pfVar13 * fVar37 + fStack_8 + 0.0;
              } while (iVar10 < (int)uVar26);
            }
          }
          iVar22 = iVar22 + 1;
          iVar19 = iVar19 + uVar26;
          iVar12 = iVar12 + 1;
          puVar6[3] = fStack_10;
          puVar6[4] = fStack_c;
          puVar6[5] = fStack_8;
          puVar6 = puVar6 + 3;
        } while (iVar22 < (int)uVar4);
      }
      *puVar24 = *(u32 *)(iVar27 + 0x50);
      *(u32 *)(iVar27 + 0x3c) = *(u32 *)(iVar27 + 0x54);
      *(u32 *)(iVar27 + 0x40) = *(u32 *)(iVar27 + 0x58);
      puVar24[uVar4 * 3 + 3] = puVar24[uVar4 * 3 + -3];
      puVar24[uVar4 * 3 + 4] = puVar24[uVar4 * 3 + -2];
      puVar24[uVar4 * 3 + 5] = puVar24[uVar4 * 3 + -1];
      return param_1;
    }
    uStack_18 = 0x102;
    uStack_14 = ((code)FUN_004c1d10)(0xffffffff80000016);
    ((code)FUN_004c1c50)(&uStack_18);
    return 0;
  }
  uVar26 = uVar4;
  if (9 < (int)uVar4) {
    uVar26 = 10;
  }
  uVar5 = uVar26 & 1;
  if (((int)uVar26 < 0) && (uVar5 != 0)) {
    uVar5 = uVar5 - 2;
  }
  iVar23 = (int)uVar26 >> 1;
  if (uVar5 == 0) {
    if ((int)uVar26 < 0) {
      iVar23 = (int)(uVar26 + 1) >> 1;
    }
    lVar7 = (*DAT_00960178)(iVar23 << 2,0x30102);
    if (lVar7 == 0) {
      uStack_38 = 0x102;
      uStack_34 = ((code)FUN_004c1d10)(0xffffffff80000013,iVar23 << 2);
      ((code)FUN_004c1c50)(&uStack_38);
      lVar7 = 0;
    }
    else {
      puVar6 = (u32 *)lVar7;
      *puVar6 = 1;
      iVar22 = 2;
      puVar6[1] = 4;
      if (2 < iVar23) {
        if (8 < iVar23 + -2) {
          bVar3 = 0;
          if ((1 < iVar23) && (iVar23 < 0x7fffffff)) {
            bVar3 = 1;
          }
          if (bVar3) {
            piVar8 = (int *)(puVar6 + 2);
            do {
              iVar22 = iVar22 + 8;
              *piVar8 = piVar8[-1] * 4 - piVar8[-2];
              piVar8[1] = *piVar8 * 4 - piVar8[-1];
              piVar8[2] = piVar8[1] * 4 - *piVar8;
              piVar8[3] = piVar8[2] * 4 - piVar8[1];
              piVar8[4] = piVar8[3] * 4 - piVar8[2];
              piVar8[5] = piVar8[4] * 4 - piVar8[3];
              piVar8[6] = piVar8[5] * 4 - piVar8[4];
              piVar8[7] = piVar8[6] * 4 - piVar8[5];
              piVar8 = piVar8 + 8;
            } while (iVar22 < iVar23 + -8);
          }
        }
        if (iVar22 < iVar23) {
          piVar8 = (int *)(puVar6 + iVar22);
          do {
            iVar22 = iVar22 + 1;
            *piVar8 = piVar8[-1] * 4 - piVar8[-2];
            piVar8 = piVar8 + 1;
          } while (iVar22 < iVar23);
        }
      }
    }
    if (lVar7 == 0) {
      return 0;
    }
    iVar12 = *(int *)(iVar23 * 4 + (int)lVar7 + -4);
    (*DAT_0096017c)(lVar7);
    iVar22 = iVar23 + 1;
    lVar7 = (*DAT_00960178)(iVar22 * 4,0x30102);
    if (lVar7 == 0) {
      uStack_40 = 0x102;
      uStack_3c = ((code)FUN_004c1d10)(0xffffffff80000013,iVar22 * 4);
      ((code)FUN_004c1c50)(&uStack_40);
      lVar7 = 0;
    }
    else {
      iVar19 = 2;
      puVar6 = (u32 *)lVar7;
      *puVar6 = 1;
      puVar6[1] = 2;
      if (2 < iVar22) {
        if (8 < iVar23 + -1) {
          bVar3 = 0;
          if ((1 < iVar22) && (iVar22 < 0x7fffffff)) {
            bVar3 = 1;
          }
          if (bVar3) {
            piVar8 = (int *)(puVar6 + 2);
            do {
              iVar19 = iVar19 + 8;
              *piVar8 = piVar8[-1] * 4 - piVar8[-2];
              piVar8[1] = *piVar8 * 4 - piVar8[-1];
              piVar8[2] = piVar8[1] * 4 - *piVar8;
              piVar8[3] = piVar8[2] * 4 - piVar8[1];
              piVar8[4] = piVar8[3] * 4 - piVar8[2];
              piVar8[5] = piVar8[4] * 4 - piVar8[3];
              piVar8[6] = piVar8[5] * 4 - piVar8[4];
              piVar8[7] = piVar8[6] * 4 - piVar8[5];
              piVar8 = piVar8 + 8;
            } while (iVar19 < iVar23 + -7);
          }
        }
        if (iVar19 < iVar22) {
          piVar8 = (int *)(puVar6 + iVar19);
          do {
            iVar19 = iVar19 + 1;
            *piVar8 = piVar8[-1] * 4 - piVar8[-2];
            piVar8 = piVar8 + 1;
          } while (iVar19 < iVar23 + 1);
        }
      }
    }
    if (lVar7 == 0) {
      return 0;
    }
  }
  else {
    if ((int)uVar26 < 0) {
      iVar23 = (int)(uVar26 + 1) >> 1;
    }
    iVar22 = iVar23 + 1;
    iVar19 = iVar22 * 4;
    lVar7 = (*DAT_00960178)(iVar19,0x30102);
    if (lVar7 == 0) {
      uStack_28 = 0x102;
      uStack_24 = ((code)FUN_004c1d10)(0xffffffff80000013,iVar19);
      ((code)FUN_004c1c50)(&uStack_28);
      lVar7 = 0;
    }
    else {
      puVar6 = (u32 *)lVar7;
      *puVar6 = 1;
      iVar12 = 2;
      puVar6[1] = 3;
      if (2 < iVar22) {
        if (8 < iVar23 + -1) {
          bVar3 = 0;
          if ((1 < iVar22) && (iVar22 < 0x7fffffff)) {
            bVar3 = 1;
          }
          if (bVar3) {
            piVar8 = (int *)(puVar6 + 2);
            do {
              iVar12 = iVar12 + 8;
              *piVar8 = piVar8[-1] * 4 - piVar8[-2];
              piVar8[1] = *piVar8 * 4 - piVar8[-1];
              piVar8[2] = piVar8[1] * 4 - *piVar8;
              piVar8[3] = piVar8[2] * 4 - piVar8[1];
              piVar8[4] = piVar8[3] * 4 - piVar8[2];
              piVar8[5] = piVar8[4] * 4 - piVar8[3];
              piVar8[6] = piVar8[5] * 4 - piVar8[4];
              piVar8[7] = piVar8[6] * 4 - piVar8[5];
              piVar8 = piVar8 + 8;
            } while (iVar12 < iVar23 + -7);
          }
        }
        if (iVar12 < iVar22) {
          piVar8 = (int *)(puVar6 + iVar12);
          do {
            iVar12 = iVar12 + 1;
            *piVar8 = piVar8[-1] * 4 - piVar8[-2];
            piVar8 = piVar8 + 1;
          } while (iVar12 < iVar23 + 1);
        }
      }
    }
    if (lVar7 == 0) {
      return 0;
    }
    iVar12 = *(int *)((int)lVar7 + iVar23 * 4);
    (*DAT_0096017c)(lVar7);
    lVar7 = (*DAT_00960178)(iVar19,0x30102);
    if (lVar7 == 0) {
      uStack_30 = 0x102;
      uStack_2c = ((code)FUN_004c1d10)(0xffffffff80000013,iVar19);
      ((code)FUN_004c1c50)(&uStack_30);
      lVar7 = 0;
    }
    else {
      puVar6 = (u32 *)lVar7;
      *puVar6 = 1;
      iVar19 = 2;
      puVar6[1] = 5;
      if (2 < iVar22) {
        if (8 < iVar23 + -1) {
          bVar3 = 0;
          if ((1 < iVar22) && (iVar22 < 0x7fffffff)) {
            bVar3 = 1;
          }
          if (bVar3) {
            piVar8 = (int *)(puVar6 + 2);
            do {
              iVar19 = iVar19 + 8;
              *piVar8 = piVar8[-1] * 4 - piVar8[-2];
              piVar8[1] = *piVar8 * 4 - piVar8[-1];
              piVar8[2] = piVar8[1] * 4 - *piVar8;
              piVar8[3] = piVar8[2] * 4 - piVar8[1];
              piVar8[4] = piVar8[3] * 4 - piVar8[2];
              piVar8[5] = piVar8[4] * 4 - piVar8[3];
              piVar8[6] = piVar8[5] * 4 - piVar8[4];
              piVar8[7] = piVar8[6] * 4 - piVar8[5];
              piVar8 = piVar8 + 8;
            } while (iVar19 < iVar23 + -7);
          }
        }
        if (iVar19 < iVar22) {
          piVar8 = (int *)(puVar6 + iVar19);
          do {
            iVar19 = iVar19 + 1;
            *piVar8 = piVar8[-1] * 4 - piVar8[-2];
            piVar8 = piVar8 + 1;
          } while (iVar19 < iVar23 + 1);
        }
      }
    }
    if (lVar7 == 0) {
      return 0;
    }
  }
  fVar37 = 1.0 / (float)iVar12;
  iVar19 = iVar23 + -1;
  iVar12 = (int)lVar7;
  if (-1 < iVar19) {
    if (iVar22 < 0) {
      iVar22 = iVar22 + 1;
    }
    if (8 < iVar22 >> 1) {
      bVar3 = 0;
      if ((-1 < iVar19) && (-0x7fffffff < iVar19)) {
        bVar3 = 1;
      }
      if (bVar3) {
        piVar8 = (int *)(iVar12 + iVar19 * 4);
        do {
          iVar19 = iVar19 + -0x10;
          *piVar8 = -*piVar8;
          piVar8[-2] = -piVar8[-2];
          piVar8[-4] = -piVar8[-4];
          piVar8[-6] = -piVar8[-6];
          piVar8[-8] = -piVar8[-8];
          piVar8[-10] = -piVar8[-10];
          piVar8[-0xc] = -piVar8[-0xc];
          piVar8[-0xe] = -piVar8[-0xe];
          piVar8 = piVar8 + -0x10;
        } while (0xf < iVar19);
      }
    }
    if (-1 < iVar19) {
      piVar8 = (int *)(iVar12 + iVar19 * 4);
      do {
        iVar19 = iVar19 + -2;
        *piVar8 = -*piVar8;
        piVar8 = piVar8 + -2;
      } while (-1 < iVar19);
    }
  }
  iVar22 = 0;
  if (0 < (int)uVar4) {
    iVar19 = uVar26 + 1;
    iVar9 = iVar23 + 1;
    if (iVar19 < 0) {
      iVar19 = uVar26 + 2;
    }
    iVar19 = iVar19 >> 1;
    puVar6 = puVar24;
    do {
      iVar10 = 1;
      pfVar11 = param_2 + (iVar22 % (int)uVar4) * 3;
      fVar35 = (float)*(int *)(iVar12 + iVar23 * 4);
      fVar36 = fVar35 * *pfVar11;
      fVar34 = fVar35 * pfVar11[1];
      fVar35 = fVar35 * pfVar11[2];
      if (1 < iVar9) {
        if (8 < iVar23) {
          bVar3 = 0;
          if ((0 < iVar9) && (iVar9 < 0x7fffffff)) {
            bVar3 = 1;
          }
          if (bVar3) {
            do {
              pfVar11 = param_2 + ((iVar10 + iVar22) % (int)uVar4) * 3;
              fVar33 = (float)*(int *)(iVar12 + (iVar23 - iVar10) * 4);
              pfVar25 = param_2 + ((iVar10 + 1 + iVar22) % (int)uVar4) * 3;
              fVar38 = (float)*(int *)(iVar12 + (iVar23 - (iVar10 + 1)) * 4);
              pfVar13 = param_2 + ((iVar10 + 2 + iVar22) % (int)uVar4) * 3;
              fVar39 = (float)*(int *)(iVar12 + (iVar23 - (iVar10 + 2)) * 4);
              pfVar14 = param_2 + ((iVar10 + 3 + iVar22) % (int)uVar4) * 3;
              fVar40 = (float)*(int *)(iVar12 + (iVar23 - (iVar10 + 3)) * 4);
              pfVar15 = param_2 + ((iVar10 + 4 + iVar22) % (int)uVar4) * 3;
              fVar41 = (float)*(int *)(iVar12 + (iVar23 - (iVar10 + 4)) * 4);
              pfVar16 = param_2 + ((iVar10 + 5 + iVar22) % (int)uVar4) * 3;
              fVar30 = (float)*(int *)(iVar12 + (iVar23 - (iVar10 + 5)) * 4);
              iVar20 = iVar10 + 7;
              pfVar17 = param_2 + ((iVar10 + 6 + iVar22) % (int)uVar4) * 3;
              fVar31 = (float)*(int *)(iVar12 + (iVar23 - (iVar10 + 6)) * 4);
              iVar10 = iVar10 + 8;
              pfVar18 = param_2 + ((iVar20 + iVar22) % (int)uVar4) * 3;
              fVar32 = (float)*(int *)(iVar12 + (iVar23 - iVar20) * 4);
              fVar36 = *pfVar18 * fVar32 +
                       *pfVar17 * fVar31 +
                       *pfVar16 * fVar30 +
                       *pfVar15 * fVar41 +
                       *pfVar14 * fVar40 +
                       *pfVar13 * fVar39 +
                       *pfVar25 * fVar38 + *pfVar11 * fVar33 + fVar36 + 0.0 + 0.0 + 0.0 + 0.0 + 0.0
                       + 0.0 + 0.0 + 0.0;
              fVar34 = pfVar18[1] * fVar32 +
                       pfVar17[1] * fVar31 +
                       pfVar16[1] * fVar30 +
                       pfVar15[1] * fVar41 +
                       pfVar14[1] * fVar40 +
                       pfVar13[1] * fVar39 +
                       pfVar25[1] * fVar38 + pfVar11[1] * fVar33 + fVar34 + 0.0 + 0.0 + 0.0 + 0.0 +
                       0.0 + 0.0 + 0.0 + 0.0;
              fVar35 = pfVar18[2] * fVar32 +
                       pfVar17[2] * fVar31 +
                       pfVar16[2] * fVar30 +
                       pfVar15[2] * fVar41 +
                       pfVar14[2] * fVar40 +
                       pfVar13[2] * fVar39 +
                       pfVar25[2] * fVar38 + pfVar11[2] * fVar33 + fVar35 + 0.0 + 0.0 + 0.0 + 0.0 +
                       0.0 + 0.0 + 0.0 + 0.0;
            } while (iVar10 < iVar23 + -7);
          }
        }
        for (; iVar10 < iVar9; iVar10 = iVar10 + 1) {
          pfVar11 = param_2 + ((iVar10 + iVar22) % (int)uVar4) * 3;
          fVar38 = (float)*(int *)(iVar12 + (iVar23 - iVar10) * 4);
          fVar36 = *pfVar11 * fVar38 + fVar36 + 0.0;
          fVar34 = pfVar11[1] * fVar38 + fVar34 + 0.0;
          fVar35 = pfVar11[2] * fVar38 + fVar35 + 0.0;
        }
      }
      iVar10 = 1;
      if (1 < iVar19) {
        if (8 < iVar19 + -1) {
          bVar3 = 0;
          if ((0 < iVar19) && (iVar19 < 0x7fffffff)) {
            bVar3 = 1;
          }
          if (bVar3) {
            iVar20 = uVar4 + iVar22;
            do {
              pfVar11 = param_2 + ((iVar20 - iVar10) % (int)uVar4) * 3;
              fVar33 = (float)*(int *)(iVar12 + (iVar23 - iVar10) * 4);
              pfVar14 = param_2 + ((iVar20 - (iVar10 + 1)) % (int)uVar4) * 3;
              fVar38 = (float)*(int *)(iVar12 + (iVar23 - (iVar10 + 1)) * 4);
              pfVar15 = param_2 + ((iVar20 - (iVar10 + 2)) % (int)uVar4) * 3;
              fVar39 = (float)*(int *)(iVar12 + (iVar23 - (iVar10 + 2)) * 4);
              pfVar16 = param_2 + ((iVar20 - (iVar10 + 3)) % (int)uVar4) * 3;
              fVar40 = (float)*(int *)(iVar12 + (iVar23 - (iVar10 + 3)) * 4);
              pfVar17 = param_2 + ((iVar20 - (iVar10 + 4)) % (int)uVar4) * 3;
              fVar41 = (float)*(int *)(iVar12 + (iVar23 - (iVar10 + 4)) * 4);
              pfVar18 = param_2 + ((iVar20 - (iVar10 + 5)) % (int)uVar4) * 3;
              fVar30 = (float)*(int *)(iVar12 + (iVar23 - (iVar10 + 5)) * 4);
              iVar21 = iVar10 + 7;
              pfVar25 = param_2 + ((iVar20 - (iVar10 + 6)) % (int)uVar4) * 3;
              fVar31 = (float)*(int *)(iVar12 + (iVar23 - (iVar10 + 6)) * 4);
              iVar10 = iVar10 + 8;
              pfVar13 = param_2 + ((iVar20 - iVar21) % (int)uVar4) * 3;
              fVar32 = (float)*(int *)(iVar12 + (iVar23 - iVar21) * 4);
              fVar36 = *pfVar13 * fVar32 +
                       *pfVar25 * fVar31 +
                       *pfVar18 * fVar30 +
                       *pfVar17 * fVar41 +
                       *pfVar16 * fVar40 +
                       *pfVar15 * fVar39 +
                       *pfVar14 * fVar38 + *pfVar11 * fVar33 + fVar36 + 0.0 + 0.0 + 0.0 + 0.0 + 0.0
                       + 0.0 + 0.0 + 0.0;
              fVar34 = pfVar13[1] * fVar32 +
                       pfVar25[1] * fVar31 +
                       pfVar18[1] * fVar30 +
                       pfVar17[1] * fVar41 +
                       pfVar16[1] * fVar40 +
                       pfVar15[1] * fVar39 +
                       pfVar14[1] * fVar38 + pfVar11[1] * fVar33 + fVar34 + 0.0 + 0.0 + 0.0 + 0.0 +
                       0.0 + 0.0 + 0.0 + 0.0;
              fVar35 = pfVar13[2] * fVar32 +
                       pfVar25[2] * fVar31 +
                       pfVar18[2] * fVar30 +
                       pfVar17[2] * fVar41 +
                       pfVar16[2] * fVar40 +
                       pfVar15[2] * fVar39 +
                       pfVar14[2] * fVar38 + pfVar11[2] * fVar33 + fVar35 + 0.0 + 0.0 + 0.0 + 0.0 +
                       0.0 + 0.0 + 0.0 + 0.0;
            } while (iVar10 < iVar19 + -8);
          }
        }
        if (iVar10 < iVar19) {
          do {
            iVar20 = (uVar4 + iVar22) - iVar10;
            iVar21 = iVar23 - iVar10;
            iVar10 = iVar10 + 1;
            pfVar11 = param_2 + (iVar20 % (int)uVar4) * 3;
            fVar38 = (float)*(int *)(iVar12 + iVar21 * 4);
            fVar36 = *pfVar11 * fVar38 + fVar36 + 0.0;
            fVar34 = pfVar11[1] * fVar38 + fVar34 + 0.0;
            fVar35 = pfVar11[2] * fVar38 + fVar35 + 0.0;
          } while (iVar10 < iVar19);
        }
      }
      iVar22 = iVar22 + 1;
      puVar6[3] = fVar36 * fVar37;
      puVar6[4] = fVar34 * fVar37;
      puVar6[5] = fVar35 * fVar37;
      puVar6 = puVar6 + 3;
    } while (iVar22 < (int)uVar4);
  }
  puVar6 = puVar24 + uVar4 * 3;
  uVar28 = puVar6[1];
  uVar29 = puVar6[2];
  *puVar24 = *puVar6;
  *(u32 *)(iVar27 + 0x3c) = uVar28;
  *(u32 *)(iVar27 + 0x40) = uVar29;
  uVar28 = *(u32 *)(iVar27 + 0x48);
  uVar29 = *(u32 *)(iVar27 + 0x4c);
  puVar6[3] = *(u32 *)(iVar27 + 0x44);
  puVar6[4] = uVar28;
  puVar6[5] = uVar29;
  uVar28 = *(u32 *)(iVar27 + 0x54);
  uVar29 = *(u32 *)(iVar27 + 0x58);
  puVar6[6] = *(u32 *)(iVar27 + 0x50);
  puVar6[7] = uVar28;
  puVar6[8] = uVar29;
  (*DAT_0096017c)(lVar7);
  return param_1;
}
#pragma schedule off
#pragma optimization_level 2

// FUN_0048CF00 NONMATCHING

u64 FUN_0048cf00(u64 param_1)

{
  u32 *puVar1;
  int iVar2;
  
  DAT_007ce7b4 = DAT_007ce7b4 + -1;
  if (DAT_007ce7b4 == 0) {
    iVar2 = 10;
    puVar1 = (u32 *)((u8 *)DAT_0095de68);
    do {
      (*DAT_0096017c)(*puVar1);
      iVar2 = iVar2 + -1;
      *puVar1 = 0;
      puVar1 = puVar1 + -1;
    } while (3 < iVar2);
    (*DAT_0096017c)(DAT_007ce77c);
    DAT_007ce77c = 0;
  }
  return param_1;
}

// FUN_0048CFA0 NONMATCHING

u64 FUN_0048cfa0(u64 param_1)

{
  u8 bVar1;
  long lVar2;
  u32 *puVar3;
  int iVar4;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  if (DAT_007ce7b4 == 0) {
    lVar2 = ((code)FUN_0048ad20)();
    if (lVar2 == 0) {
      uStack_8 = 0x102;
      uStack_4 = ((code)FUN_004c1d10)(3);
      ((code)FUN_004c1c50)(&uStack_8);
      return 0;
    }
    iVar4 = 4;
    puVar3 = (u32 *)((u8 *)DAT_0095de50);
LAB_0048cff4:
    lVar2 = ((code)FUN_0048af80)(iVar4);
    *puVar3 = (int)lVar2;
    if (lVar2 != 0) goto LAB_0048d01c;
    iVar4 = iVar4 + -1;
    if (3 < iVar4) {
      puVar3 = (u32 *)((u8 *)DAT_0095de40 + iVar4 * 4);
      do {
        (*DAT_0096017c)(*puVar3);
        iVar4 = iVar4 + -1;
        *puVar3 = 0;
        puVar3 = puVar3 + -1;
      } while (3 < iVar4);
    }
    bVar1 = 0;
    goto LAB_0048d030;
  }
LAB_0048cfc4:
  DAT_007ce7b4 = DAT_007ce7b4 + 1;
  return param_1;
LAB_0048d01c:
  iVar4 = iVar4 + 1;
  puVar3 = puVar3 + 1;
  if (10 < iVar4) goto code_r0x0048d02c;
  goto LAB_0048cff4;
code_r0x0048d02c:
  bVar1 = 1;
LAB_0048d030:
  if (!bVar1) {
    uStack_10 = 0x102;
    uStack_c = ((code)FUN_004c1d10)(3);
    ((code)FUN_004c1c50)(&uStack_10);
    return 0;
  }
  goto LAB_0048cfc4;
}

// FUN_0048D0E0 NONMATCHING

u64 FUN_0048d0e0(u64 param_1)

{
  long lVar1;
  u64 uVar2;
  long lVar3;
  int iVar4;
  u8 auStack_30 [32];
  int iStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  lVar1 = ((code)FUN_004c5250)(param_1,auStack_30,0x28);
  if (lVar1 == 0x28) {
    iVar4 = iStack_10 * 0xc;
    lVar1 = (*DAT_00960178)(iVar4,0x10102);
    if (lVar1 == 0) {
      uStack_8 = 0x102;
      uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000013,iVar4);
      ((code)FUN_004c1c50)(&uStack_8);
      uVar2 = 0;
    }
    else {
      lVar3 = ((code)FUN_004c18b0)(param_1,lVar1,iVar4);
      if (lVar3 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = ((code)FUN_0048dab0)(iStack_10,uStack_c,lVar1);
        (*DAT_00960140)((u8 *)uVar2 + 0x18,auStack_30,0x20);
        *(u8 *)uVar2 = 0xc;
        (*DAT_0096017c)(lVar1);
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

// FUN_0048D200 NONMATCHING

int FUN_0048d200(int param_1)

{
  int iVar1;
  u32 uStack_8;
  u32 uStack_4;
  
  if (*(int *)(param_1 + 0xc) == 2) {
    iVar1 = *(int *)(param_1 + 8) + -3;
  }
  else if (*(int *)(param_1 + 0xc) == 1) {
    iVar1 = *(int *)(param_1 + 8) + -2;
  }
  else {
    uStack_8 = 0x102;
    uStack_4 = ((code)FUN_004c1d10)(1);
    ((code)FUN_004c1c50)(&uStack_8);
    iVar1 = 0;
  }
  return iVar1;
}
