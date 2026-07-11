#include "Kernel/Kwln/kwln.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kernel/Kwln/kwlnRoot.h"
#include "Kernel/h_memcard.h"
#include "Kernel/h_malloc.h"
#include "rw/rpworld.h"
#include "rw/rprandom.h"
#include "sce/eekernel.h"
#include "sce/eeregs.h"
#include "sce/sifdev.h"
#include "sce/sifrpc.h"
#include "sce/libcdvd.h"
#include "h_pad.h"
#include "h_chrdsp.h"
#include "temporary.h"
#include "Main/g_data.h"
#include "Main/admini.h"
#include "Main/Battle/Panel/bs_root.h"
#include "Kosaka/Field/k_field.h"
#include "Kosaka/Field/k_fldFilter.h"
#include "Kosaka/k_data.h"
#include "Yajima/y_misc.h"
#include "h_cdvd.h"
#include "h_dbprt.h"
#include "h_fade.h"

#define KWLN_COMMON_RENDERSTATES (rwRENDERSTATEFOGDENSITY + 1)

#define LOAD_IOP_MODULE(fileName, args, argp)                   \
    do                                                          \
    {                                                           \
    } while (sceSifLoadModule((fileName), (args), (argp)) < 0);

static RwRGBA sClearColor;         // 007ce128
static RwRGBA sClearColorAlt;      // 007ce124
static u32 sFlags;                 // 007ce120
static u32 sFrameCount2;           // 007ce10c
static u32 sFrameCount;            // 007ce108
u32 gT0CountVal;                   // 007ce0fc. Current value of T0_COUNT reg
u8 gFogAlpha;                      // 007ce0e4
static u8 sbssPad3[0x03];
u8 gFogGreen;                      // 007ce0e0
static u8 sbssPad2[0x03];
u8 gFogBlue;                       // 007ce0dc
static u8 sbssPad1[0x03];
u8 gFogRed;                        // 007ce0d8
u32 gFogEnabled;                   // 007ce0d4
static KwlnTask* sRootTask;        // 007ce0d0
u32 gCurrWorldIdx;                 // 007ce0cc. always 0
static s32 sMainThreadId;          // 007ce0c8
static RwCamera* sMainCamera;      // 007ce0c0
static RpLight* sSecondaryLight;    // 007ce0b0
static RpLight* sDirectionalLight; // 007ce0ac
static RpLight* sAmbientLight;     // 007ce0a8
static RpWorld* sWorlds[2];        // 007ce0a0. Only the first index is used
static u64 sT0Count64;             // 007ce098

// a lot of them are probably temporary here
f32 g18deg = 3.14159274 / 10;               // 007caf00
f32 gRadToDegFactor = 180.0f / 3.14159274;  // 007caea8
f32 gPI = 3.14159274;                       // 007cae58
f32 gUnk_007cadd0 = 0.7f;                   // 007cadd0. 0.69999999f
f32 gRadToDegFactor2 = 180.0f / 3.14159274;
f32 gAspectRatio = 4.0f / 3.0f;             // 007cad1c

u32 sPushedRenderStates[KWLN_COMMON_RENDERSTATES]; // 00847eb0
typedef struct KwlnPluginRegistration
{
    void* pluginData;
    u32 parentPluginId;
    u32 pluginSize;
    u32 basePluginId;
    void* callback;
} KwlnPluginRegistration;

static const KwlnPluginRegistration sPluginRegistrations[] =
{
    { (void*)0x006b4f20, 0,       0x1001, 1, NULL },
    { (void*)0x006b4fb0, 0x1001,  0x1002, 2, NULL },
    { (void*)0x006b4fd0, 0x1001,  0x1003, 2, NULL },
    { (void*)0x006b4ff0, 0,       4,      1, NULL },
    { (void*)0x006b5080, 0,       5,      1, NULL },
    { (void*)0x006b5110, 4,       6,      2, NULL },
    { (void*)0x006b5130, 5,       7,      2, NULL },
    { (void*)0x006b51e0, 0,       0x1100b, 1, NULL },
    { (void*)0x006b5270, 0,       0x1100c, 1, NULL },
    { (void*)0x006b5300, 0x1100b, 0x1100d, 2, NULL },
    { (void*)0x006b5320, 0x1100c, 0x1100e, 2, NULL },
    { (void*)0x006b5340, 0x1100b, 0x1100f, 2, NULL },
    { (void*)0x006b5360, 0x1100c, 0x11010, 2, NULL },
    { (void*)0x006b53a0, 0,       0x11001, 1, NULL },
    { (void*)0x006b5430, 0x11001, 0x11002, 2, NULL },
    { (void*)0x006b5500, 0,       0x11011, 1, NULL },
    { (void*)0x006b5590, 0,       0x11012, 1, NULL },
    { (void*)0x006b5620, 0x11011, 0x11013, 2, NULL },
    { (void*)0x006b5640, 0x11012, 0x11014, 2, NULL },
    { (void*)0x006b5ae0, 0,       0x1001f, 2, NULL },
    { (void*)0x006b5a50, 0,       0x10020, 1, NULL },
    { (void*)0x006b5b00, 0,       0x10021, 1, NULL },
    { (void*)0x006b5b90, 0,       0x10022, 1, NULL },
    { (void*)0x006b5c20, 0,       0x10023, 1, NULL },
    { (void*)0x006b5cb0, 0,       0x10024, 1, NULL },
    { (void*)0x006b5d70, 0,       0x1002a, 1, NULL },
    { (void*)0x006b5e00, 0,       0x1002b, 1, NULL },
    { (void*)0x006b5940, 0,       0x1001d, 1, NULL },
    { (void*)0x006b59d0, 0x1001d, 0x1001e, 2, NULL },
    { (void*)0x006b57f0, 0,       0x1001b, 1, NULL },
    { (void*)0x006b5880, 0x1001b, 0x1001c, 2, NULL },
    { (void*)0x006b56a0, 0,       0x10019, 1, NULL },
    { (void*)0x006b5730, 0x10019, 0x1001a, 2, NULL },
};

typedef struct KwlnWorldBounds
{
    RwV3d maximum;
    RwV3d minimum;
} KwlnWorldBounds;
typedef struct KwlnCameraView
{
    RwV2d offset;
    u32 width;
    u32 height;
} KwlnCameraView;

typedef void* (*KwlnAllocateFunc)(u32 size, u32 alignment);

#define KWLN_U32_AT(address) (*(volatile u32*)(address))
#define KWLN_F32_AT(address) (*(volatile f32*)(address))
#define KWLN_LIGHT_AT(address) (*(RpLight* volatile*)(address))
extern u32 DAT_007cdffc;
extern void* DAT_007ce0c4;
extern u8 DAT_00960070[];
extern char gp0xffff9430;
extern void D_00847F00(void);
extern void D_00847F04(void);
extern void D_00847F08(void);
extern void D_00847F0C(void);
extern void D_00847F10(void);
extern void D_00847F14(void);
extern void D_00847F30(void);
extern void D_00847F34(void);
extern void D_00847F38(void);
extern void D_00847F3C(void);
extern void D_00847F50(void);
extern const void D_00678798[];
extern const void D_006787A8[];
extern const void D_006787B8[];
extern const void D_005E5150[];
extern const void D_006418E0[];
extern const void D_00644330[];
extern u32 D_005E4F60[];
extern void H_Dbprt_Init();

u16 datGetMaxHp(s16 pcId);
u32 func_0017d7b0(void);
u32 func_001755c0(void);
void func_001754a0(u32 value);
void func_00505e48(const char* message);
void func_00540ea8(void);
void func_0016c1d0(void);
u16 func_0016c670(s16 pcId);
void func_0016f320(void);
void dat0016f450(void);
void func_0016fea0(s16 category, s32 id, u16 value);
void func_00170b20(s16 pcId, s16 index, u16 value);
void func_00170b90(s16 pcId, s16 index, u16 value);
void func_00175820(u16 pcId, u16 personaId);
void func_001773d0(void);
void func_001779a0(void);
void dat00177ce0(s16 pcId, u8 level);
void func_0017adf0(void);
void func_0017b1a0(void);
void func_0017b2a0(void);
void func_0017c190(void);
void func_0017c280(void);
void func_0017d3c0(void);
void func_0017d7c0(s32 value);
void func_00182c50(s32 id, void* record);
void func_001830c0(void* record);
void func_001cd7a0(void);
void func_001fa0d0(void);
void func_001fc1f0(void);
void func_0025b440(void);
void func_004ac860(u32 size, u32 alignment);
RwMemoryFunctions* func_001040f0(void);
RwCamera* func_00195c80(u32 width, u32 height, u32 zBuffer);
void func_0045f7d0(void);
void func_004661b0(void);
void func_00468c50(void);
void func_0046a530(void);
void func_0046a750(u32 count);
void func_0046a830(KwlnPluginRegistration* registration);
void func_00473590(void);
void func_00488fe0(void);
void func_0048a1a0(void);
void func_0048dcf0(void);
void func_0048f030(void);
void func_00494760(void* object);
void* func_004947c0(u32 type);
void func_0049a980(void);
RpWorld* func_0049a400(const KwlnWorldBounds* bounds);
void func_0049c160(RpWorld* world, RwCamera* camera);
void func_0049c3d0(RpWorld* world, void* object);
void func_004a9f20(f32 x, f32 y, f32 z, f32 w);
void func_004aa390(f32 nearPlane);
void func_004aa3d0(f32 farPlane);
void func_004aa550(RwCamera* camera);
void func_004b6350(void);
void func_004b6640(void);
void func_004b8830(void);
void func_004c4c00(u32 value);
void func_004c7cf0(s32 value);
void func_004c9d70(RwCamera* camera, f32 value);
void func_004c9db0(RwCamera* camera, f32 value);
void func_004ca560(u32* output, const void* descriptor);
const void* func_004ca5b0(void);
void func_004ca600(u32 value);
void func_004ca640(void);
void func_004ca700(u32* output);
void* func_004caf10(void);
void func_004cb890(void* frame, f32 value, const void* vector, u32 mode);
void func_004cb930(void* frame);
s32 func_004ccd50(void** output, void* callback, void* cleanup);
void func_004d1840(void* object, void* frame);
void func_004d6ab0(u32 size, u32 alignment, u32 flags);
void func_004d82a0(u32 value);
void func_004d8300(u32 value);
void func_004d8310(u32 value);
u32 func_004f1e10(void);
void func_004f8e10(void);
void func_0053b220(u32 value);
s32 func_0053b2c0(void* output, const void* data, u32 value);
void func_0053b4f8(void* output);
void func_0053ea90(void);
void func_00540570(void* callback, void* userData);
void func_00540588(u32 value);
void func_005417e0(u32 width, u32 height);
void func_00547668(void* data);
void func_0054cfe8(void);
void func_00566b08(void* output, const void* data);
void func_00567820(void* data);
void func_00569f60(u32 a0, u32 a1, u32 a2);
void func_0057f768(void* data);
void func_00101c70(void);
void func_00108740(void);
void func_00108bc0(void);
void func_0010bf70(void);
void func_0010c050(void);
void func_0010cac0(void);
void func_0010cdd0(void);
void func_00119a20(void);
void func_00111f50(void);
void func_001b7bb0(void);
void func_001b7d00(void);
void func_001b8b40(void);
void func_001b8c40(void);
void func_001d4290(void);
void func_001d7260(void);
void func_001dca10(void);
void func_001e7720(void);
void func_0018bc80(void);
void func_0018e4a0(void);
void func_001eef20(void);
void func_0020c8d0(void);
void func_0027e180(void);
void func_0031b470(void);
void func_00322010(void);
void func_00396bf0(u32 value);
void func_003b4ee0(void);
void func_003bd130(void);
void func_003bd280(void);
void func_004302b0(void);
void func_004ba2a0(void);
void func_004bad50(void);
void func_0010e500(void);
void func_0010e5f0(void);
void func_00197f80(void* param_1, void* param_2);
void func_00177d40(void);
void func_00195980(f32 scale, f32 aspectRatio, RwCamera* camera, KwlnCameraView* view);
void func_0019d360(void);
void func_0035aba0(void);
void func_004944b0(void* object, const void* data);
void func_004fa4b8(void* callback);
s32 func_00197fe0(void);

// FUN_00195de0 NONMATCHING
void kwlnInitGameData()
{
    u32 preservedFlags[7];
    u8 standardRecord[0x20];
    u8 alternateRecord[0x20];
    s32 i;

    KWLN_U32_AT(0x007cdffc) = 0;
    if (KWLN_U32_AT(0x007cdf78) != 0)
    {
        for (i = 0; i < 7; i++)
        {
            preservedFlags[i] = datGetFlag(0x183 + i);
        }
    }

    func_0017c280();
    func_0017adf0();
    H_Dbprt_Flush();
    datSetMoney(0);
    datCompendiumInit();
    func_0017d7c0(0);
    func_001773d0();

    for (i = 1; i < 11; i++)
    {
        datInitUnit(i);
        if (datGetScenarioMode() != 0)
        {
            if (i == 1)
            {
                datSetLevel(i, 20);
            }
        }
        else if (i == 1)
        {
            datSetLevel(i, 1);
        }

        if (i == 1)
        {
            datSetNextExp(i, datGetScenarioMode() != 0 ? 0x2bca : 0);
        }

        datSetHp(i, 0);
        datSetSp(i, 0);
        datSetAcademicPoint(i, 0);
        datSetCharmPoint(i, 0);
        datSetCouragePoint(i, 0);
        datSetPhysicalCondition(i, 0);
        datSetBadStatus(i, 0);
        datSetEquipmentIdx(i, 0, -1);
        datSetEquipmentIdx(i, 1, -1);
        datSetEquipmentIdx(i, 2, -1);
        datSetEquipmentIdx(i, 3, -1);
        datInitPersona(i);

        if (datGetScenarioMode() != 0)
        {
            func_00175820(i, ((const u16*)0x005e4f40)[i - 1]);
        }
        else
        {
            func_00175820(i, ((const u16*)0x005e4f20)[i - 1]);
        }
        datSetHp(i, datGetMaxHp(i));
        datSetSp(i, func_0016c670(i));
        datSetFatigueCounter(i, 0x20);
        datSetOldFatigueCounter(i, 0x20);

        if (i != 1)
        {
            dat00177ce0(i, datGetLevel(i));
        }
    }

    datClearFlagAll();
    dat0016f450();
    func_0016f320();

    if (datGetScenarioMode() != 0)
    {
        datSetTime(1);
        datSetDaysSinceApr5(0x168);
        datSetFlag(0x141d, 0);
        datSetFlag(0x1005, 1);
        datSetFlag(0x1006, 0);
    }
    else
    {
        datSetTime(0);
        datSetDaysSinceApr5(2);
        datSetFlag(0x141d, 1);
        datSetFlag(0x1005, 0);
        datSetFlag(0x1006, 1);
    }
    datSetFlag(0xa03, 1);
    datSetSkipToTarget(0);

    for (i = 0; i < 300; i++)
    {
        func_0016fea0(1, i, 0);
    }

    for (i = 0; i < 20; i++)
    {
        func_0016fea0(-1, i, 0);
        func_0016fea0(0x102, i, 0);
        func_0016fea0(0x103, i, 0);
        func_0016fea0(0x104, i, 0);
        func_0016fea0(0x105, i, 0);
        func_0016fea0(0x106, i, 0);
        func_0016fea0(0x107, i, 0);
        func_0016fea0(0x108, i, 0);
        func_0016fea0(0x109, i, 0);
        func_0016fea0(0x10a, i, 0);

        func_00170b20(2, 0, 0);
        func_00170b90(2, 0, 0);
        func_00170b20(3, 0, 0);
        func_00170b90(3, 0, 0);
        func_00170b20(4, 0, 0);
        func_00170b90(4, 0, 0);
        func_00170b20(5, 0, 0);
        func_00170b90(5, 0, 0);
        func_00170b20(6, 0, 0);
        func_00170b90(6, 0, 0);
        func_00170b20(7, 0, 0);
        func_00170b90(7, 0, 0);
        func_00170b20(8, 0, 0);
        func_00170b90(8, 0, 0);
        func_00170b20(9, 0, 0);
        func_00170b90(9, 0, 0);
        func_00170b20(10, 0, 0);
        func_00170b90(10, 0, 0);
    }

    for (i = 0; i < 300; i++)
    {
        func_00170860(1, i + 0xfa0, 0);
        func_00170860(-1, i + 0xfa0, 0);
    }

    func_001779a0();
    if (datGetScenarioMode() == 0)
    {
        func_00182c50(0x20, standardRecord);
        func_001830c0(standardRecord);
        func_00182c50(0x3e9, standardRecord);
        func_001830c0(standardRecord);
        func_00182c50(0x7d1, standardRecord);
        func_001830c0(standardRecord);
        func_00182c50(0xc38, standardRecord);
        func_001830c0(standardRecord);
    }
    else
    {
        func_00182c50(0xcb, alternateRecord);
        func_001830c0(alternateRecord);
        func_00182c50(0x431, alternateRecord);
        func_001830c0(alternateRecord);
        func_00182c50(0x819, alternateRecord);
        func_001830c0(alternateRecord);
        func_00182c50(0xc3c, alternateRecord);
        func_001830c0(alternateRecord);
    }

    datSetEquipmentIdx(1, 0, 0);
    datSetEquipmentIdx(1, 1, 1);
    datSetEquipmentIdx(1, 2, 2);
    datSetEquipmentIdx(1, 3, 3);
    func_001fa0d0();
    func_001fc1f0();
    datSetPartyId(0, 0);
    datSetPartyId(1, 0);
    datSetPartyId(2, 0);
    datSetPartyId(3, 0);
    datResetTotalBtl();
    K_Field_Init();
    func_001cd7a0();
    func_0017b1a0();
    func_0025b440();
    func_0017d3c0();
    func_0017c190();
    func_0017b2a0();

    if (KWLN_U32_AT(0x007cdf78) != 0)
    {
        for (i = 0; i < 7; i++)
        {
            datSetFlag(0x183 + i, preservedFlags[i]);
        }
        KWLN_U32_AT(0x007cdf78) = 0;
    }

    datInitSocialLink();
}

// FUN_001967d0 NONMATCHING
void func_001967d0(void)
{
    struct
    {
        u32 preservedFlagIds[0x3d * 2];
        u32 padding[2];
        u32 preservedFlagValues[200];
        u32 preservedFlags[7];
    } resetStorage;
#define preservedFlagIds resetStorage.preservedFlagIds
#define preservedFlagValues resetStorage.preservedFlagValues
#define preservedFlags resetStorage.preservedFlags
    u32 initialAuxValue;
    u16 initialPersona;
    s32 i;
    s32 copyCount;
    u32* source;
    u32* destination;

    source = D_005E4F60;
    destination = preservedFlagIds;
    copyCount = 0x3d;
    do
    {
        destination[0] = source[0];
        destination[1] = source[1];
        source += 2;
        destination += 2;
        copyCount--;
    } while (copyCount != 0);

    initialAuxValue = FUN_0016f380(0x2f);
    func_0017d7c0(func_0017d7b0() + 1);

    for (i = 0; i < 7; i++)
    {
        preservedFlags[i] = datGetFlag(0x183 + i);
    }

    for (i = 0; i < 200; i++)
    {
        if (preservedFlagIds[i] == 0)
        {
            break;
        }
        preservedFlagValues[i] = datGetFlag(preservedFlagIds[i]);
    }

    func_0017c280();
    func_0017adf0();

    initialPersona = func_001755c0();
    datInitPersona(1);
    func_00175820(1, ((const u16*)0x005e4f20)[0]);
    datSetPhysicalCondition(1, 0);
    datSetBadStatus(1, 0);
    datSetHp(1, datGetMaxHp(1));
    datSetSp(1, func_0016c670(1));
    datSetFatigueCounter(1, 0x20);
    datSetOldFatigueCounter(1, 0x20);

    for (i = 2; i < 11; i++)
    {
        datInitUnit(i);
        datSetHp(i, 0);
        datSetSp(i, 0);
        datSetAcademicPoint(i, 0);
        datSetCharmPoint(i, 0);
        datSetCouragePoint(i, 0);
        datSetPhysicalCondition(i, 0);
        datSetBadStatus(i, 0);
        datSetEquipmentIdx(i, 0, (u16)-1);
        datSetEquipmentIdx(i, 1, (u16)-1);
        datSetEquipmentIdx(i, 2, (u16)-1);
        datSetEquipmentIdx(i, 3, (u16)-1);
        datInitPersona(i);
        func_00175820(i, ((const u16*)0x005e4f20)[i - 1]);
        datSetHp(i, datGetMaxHp(i));
        datSetSp(i, func_0016c670(i));
        datSetFatigueCounter(i, 0x20);
        datSetOldFatigueCounter(i, 0x20);
        dat00177ce0(i, datGetLevel(i));
    }

    datClearFlagAll();
    dat0016f450();
    func_0016f320();
    datSetTime(0);
    datSetDaysSinceApr5(2);
    datSetFlag(0xa03, 1);
    datSetSkipToTarget(0);

    for (i = 0; i < 20; i++)
    {
        func_0016fea0(-1, i, 0);
        func_0016fea0(0x102, i, 0);
        func_0016fea0(0x103, i, 0);
        func_0016fea0(0x104, i, 0);
        func_0016fea0(0x105, i, 0);
        func_0016fea0(0x106, i, 0);
        func_0016fea0(0x107, i, 0);
        func_0016fea0(0x108, i, 0);
        func_0016fea0(0x109, i, 0);
        func_0016fea0(0x10a, i, 0);

        func_00170b20(2, 0, 0);
        func_00170b90(2, 0, 0);
        func_00170b20(3, 0, 0);
        func_00170b90(3, 0, 0);
        func_00170b20(4, 0, 0);
        func_00170b90(4, 0, 0);
        func_00170b20(5, 0, 0);
        func_00170b90(5, 0, 0);
        func_00170b20(6, 0, 0);
        func_00170b90(6, 0, 0);
        func_00170b20(7, 0, 0);
        func_00170b90(7, 0, 0);
        func_00170b20(8, 0, 0);
        func_00170b90(8, 0, 0);
        func_00170b20(9, 0, 0);
        func_00170b90(9, 0, 0);
        func_00170b20(10, 0, 0);
        func_00170b90(10, 0, 0);
    }

    for (i = 0; i < 300; i++)
    {
        func_00170860(1, i + 0xfa0, 0);
        func_00170860(-1, i + 0xfa0, 0);
    }

    func_001779a0();
    func_001fa0d0();
    func_001fc1f0();
    datSetPartyId(0, 0);
    datSetPartyId(1, 0);
    datSetPartyId(2, 0);
    datSetPartyId(3, 0);
    datResetTotalBtl();
    func_0017b1a0();
    func_0025b440();
    func_0017d3c0();
    func_0017c190();
    func_0017b2a0();
    datInitSocialLink();

    for (i = 0; i < 7; i++)
    {
        datSetFlag(0x183 + i, preservedFlags[i]);
    }

    for (i = 0; i < 200; i++)
    {
        if (preservedFlagIds[i] == 0)
        {
            break;
        }
        datSetFlag(preservedFlagIds[i], preservedFlagValues[i]);
    }

    func_001754a0(initialPersona);
    datSetFlag(0x1310, 1);
    datSetFlag(0x141d, 1);
    FUN_0016f3e0(0x2f, initialAuxValue);
}
#undef preservedFlagIds
#undef preservedFlagValues
#undef preservedFlags

// FUN_00196770
void kwlnPushCommonRenderStates()
{
    s32 i;

    for (i = 0; i < KWLN_COMMON_RENDERSTATES; i++)
    {
        RwRenderStateGet(i, &sPushedRenderStates[i]);
    }
}

// FUN_00196fe0
s32 kwlnT0OverflowHandler(s32 intc)
{
    if (intc == INTC_TIM0 && 
       (DGET_T0_MODE() & (1 << T_MODE_OVFF_O)))
    {
        DGET_T0_MODE() |= (1 << T_MODE_OVFF_O);

        sT0Count64 += 0x10000;
    }

    ExitHandler();

    return 0;
}

// FUN_00197030. HPad, memcard and IOP module init
void kwlnInitPS2Systems()
{
    char img[64];

    sceSifInitRpc(0);
    sceSifInitIopHeap();

    sceCdInit(SCECdINIT);
    sceCdMmode(SCECdDVD);

    sprintf(img, "cdrom0:\\LIB31\\%s;1", IOP_IMAGE_FILE);
    while (sceSifRebootIop(img) ? 0 : 1);
    while (sceSifSyncIop() ? 0 : 1);
    sceSifInitRpc(0);
    sceSifInitIopHeap();

    sceCdInit(SCECdINIT);
    sceCdMmode(SCECdDVD);

    AddIntcHandler(INTC_TIM0, kwlnT0OverflowHandler, 0);

    sT0Count64 = 0;

    DPUT_T0_COUNT(0);
    DPUT_T0_COMP(0);
    DPUT_T0_HOLD(0);
    DPUT_T0_MODE((1 << T_MODE_CLKS_O) | (1 << T_MODE_CUE_O) | (1 << T_MODE_OVFE_O));
    DPUT_T1_COUNT(0);

    EnableIntc(INTC_TIM0);

    sFrameCount = 0;
    sFrameCount2 = 0;

    LOAD_IOP_MODULE("cdrom0:\\LIB31\\SIO2MAN.IRX;1", 0, NULL);
    LOAD_IOP_MODULE("cdrom0:\\LIB31\\SIO2D.IRX;1", 0, NULL);
    LOAD_IOP_MODULE("cdrom0:\\LIB31\\PADMAN.IRX;1", 0, NULL);
    LOAD_IOP_MODULE("cdrom0:\\LIB31\\DBCMAN.IRX;1", 0, NULL);
    LOAD_IOP_MODULE("cdrom0:\\LIB31\\MC2_S1.IRX;1", 0, NULL);
    LOAD_IOP_MODULE("cdrom0:\\LIB31\\LIBSD.IRX;1", 0, NULL);
    LOAD_IOP_MODULE("cdrom0:\\LIB31\\CRI_ADXI.IRX;1", 20, "sdinit=0 spucore=1");
    LOAD_IOP_MODULE("cdrom0:\\LIB31\\SDRDRV.IRX;1", 0, NULL);
    LOAD_IOP_MODULE("cdrom0:\\LIB31\\MODHSYN.IRX;1", 0, NULL);
    LOAD_IOP_MODULE("cdrom0:\\LIB31\\MODMSIN.IRX;1", 0, NULL);
    LOAD_IOP_MODULE("cdrom0:\\LIB31\\MODSESQ.IRX;1", 0, NULL);
    LOAD_IOP_MODULE("cdrom0:\\LIB31\\SKSOUND.IRX;1", 0, NULL);
    LOAD_IOP_MODULE("cdrom0:\\LIB31\\SKHSYNTH.IRX;1", 0, NULL);
    LOAD_IOP_MODULE("cdrom0:\\LIB31\\SKHSYNTH.IRX;1", 0, NULL); // ?
    LOAD_IOP_MODULE("cdrom0:\\LIB31\\SKSESQ.IRX;1", 24, "maxtrack=16\0maxentry=16");

    H_Pad_Init();
    H_Memcard_Init();

    sMainThreadId = GetThreadId();
}

// FUN_00197350. RenderWare engine, plugin, world, light, camera, and callback initialization NONMATCHING
void kwlnInitRenderer()
{
    KwlnPluginRegistration registration;
    KwlnWorldBounds bounds =
    {
        { 150.0f, 150.0f, 150.0f },
        { -150.0f, -150.0f, -150.0f },
    };
    u32 cameraDescriptor[2];
    KwlnCameraView cameraView;
    void* frame;
    KwlnAllocateFunc allocate;
    s32 callbacksRegistered;
    s32 i;

    func_004ac860(0x20, 0x20);
    RwEngineInit(func_001040f0(), 0, 0x800000);
    func_0046a750(7);

    for (i = 0; i < ARRAY_SIZE(sPluginRegistrations); i++)
    {
        registration = sPluginRegistrations[i];
        func_0046a830(&registration);

        if (i == 6)
        {
            func_0049a980();
            func_0045f7d0();
            func_0048dcf0();
            func_00468c50();
        }
        else if (i == 12)
        {
            func_004b6640();
            func_004661b0();
            func_0048a1a0();
        }
        else if (i == 18)
        {
            func_0046a530();
            func_004b8830();
            func_004f8e10();
        }
        else if (i == 26)
        {
            func_00473590();
        }
    }

    func_00488fe0();
    func_0048f030();
    cameraDescriptor[0] = 0;
    func_004ca700(cameraDescriptor);
    func_004d82a0(0);
    func_004ca600(0x52);
    func_004c4c00(0x380000);
    func_0035aba0();
    func_004d6ab0(0x280000, 0x400, 0);
    func_004ca640();
    func_0019d360();

    sWorlds[gCurrWorldIdx] = func_0049a400(&bounds);
    sAmbientLight = func_004947c0(2);
    if (sAmbientLight != NULL)
    {
        func_004944b0(sAmbientLight, (const void*)0x006784c0);
        func_0049c3d0(sWorlds[gCurrWorldIdx], sAmbientLight);
    }

    sDirectionalLight = func_004947c0(1);
    if (sDirectionalLight != NULL)
    {
        frame = func_004caf10();
        if (frame != NULL)
        {
            ((u8*)sDirectionalLight)[2] = 1;
            func_004cb930(frame);
            func_004d1840(sDirectionalLight, frame);
            func_004944b0(sDirectionalLight, (const void*)0x006784f0);
            func_0049c3d0(sWorlds[gCurrWorldIdx], sDirectionalLight);
        }
        else
        {
            func_00494760(sDirectionalLight);
            sDirectionalLight = NULL;
        }
    }

    KWLN_LIGHT_AT(0x007ce0b0) = func_004947c0(1);
    if (KWLN_LIGHT_AT(0x007ce0b0) != NULL)
    {
        frame = func_004caf10();
        if (frame != NULL)
        {
            ((u8*)KWLN_LIGHT_AT(0x007ce0b0))[2] = 1;
            func_004cb890(frame, 25.0f, (const void*)0x006784d0, 0);
            func_004cb890(frame, 170.0f, (const void*)0x006784e0, 2);
            func_004d1840(KWLN_LIGHT_AT(0x007ce0b0), frame);
            func_004944b0(KWLN_LIGHT_AT(0x007ce0b0), (const void*)0x00678500);
            func_0049c3d0(sWorlds[gCurrWorldIdx], KWLN_LIGHT_AT(0x007ce0b0));
        }
        else
        {
            func_00494760(KWLN_LIGHT_AT(0x007ce0b0));
            KWLN_LIGHT_AT(0x007ce0b0) = NULL;
        }
    }

    func_004ca560(cameraDescriptor, func_004ca5b0());
    sMainCamera = func_00195c80(cameraDescriptor[0], cameraDescriptor[1], 1);
    if (sMainCamera != NULL)
    {
        func_004c9db0(sMainCamera, 25600.0f);
        func_004c9d70(sMainCamera, 20.0f);
        func_0049c160(sWorlds[gCurrWorldIdx], sMainCamera);
        cameraView.offset.x = 0.0f;
        cameraView.offset.y = 0.0f;
        cameraView.width = cameraDescriptor[0];
        cameraView.height = cameraDescriptor[1];
        func_00195980(0.5f, KWLN_F32_AT(0x007cad1c), sMainCamera, &cameraView);
        sMainCamera->fogPlane = KWLN_F32_AT(0x007cad20);
    }

    printf((const char*)0x00678740, func_004f1e10(), sMainCamera->frameBuffer->depth, sMainCamera->zBuffer->depth);
    func_004aa550(sMainCamera);
    func_004aa390(0.5f);
    func_004aa3d0(KWLN_F32_AT(0x007cad24) * sMainCamera->nearPlane);
    func_004a9f20(0.0f, 0.0f, 640.0f, 448.0f);
    func_004b6350();

    allocate = *(KwlnAllocateFunc*)0x00960178;
    KWLN_U32_AT(0x0095f57c) = (u32)allocate(0xc000, 0x40000);
    KWLN_U32_AT(0x0095f580) = 0x3000;
    H_Malloc_Init(allocate(0xa0000, 0x40000), 0xa0000);

    callbacksRegistered = func_004ccd50((void**)0x007cc90c, func_004ba2a0, func_004bad50);
    if (callbacksRegistered != 0)
    {
        callbacksRegistered = func_004ccd50((void**)0x007cc910, func_0010e500, func_0010e5f0);
    }
    if (callbacksRegistered == 0)
    {
        K_Abort((const char*)0x00678770, (const char*)0x007cc918, 0x4c8);
    }
}

// FUN_00197f80
void func_00197f80(void* param_1, void* param_2)
{
    (void)param_1;
    func_00505e48((const char*)param_2);
    func_00505e48(&gp0xffff9430);
}



// FUN_00197fb0
void kwln00197fb0(void* param_1, void* param_2)
{
    printf(param_2);
}
// FUN_00197fe0
s32 func_00197fe0(void)
{
    func_00540ea8();
    __asm__ volatile("sync");
    __asm__ volatile("ei");
    return 0;
}

// FUN_00198010. Runtime, asynchronous I/O, task, field, and battle bootstrap NONMATCHING
void kwln00198010()
{
    H_Cdvd_Init();
    func_00101c70();
    func_00177d40();
    func_00119a20();
    func_0010cac0();
    func_00108740();

    memset((void*)D_00847F10, 0, 0x14);
    KWLN_U32_AT(0x00847f10) = (u32)(&gp0xffff9430 + 4);
    KWLN_U32_AT(0x00847f14) = 0;
    func_00547668((void*)D_00847F10);
    func_00540588(0);
    func_005417e0(5, 5);
    func_0053ea90();
    func_0054cfe8();
    func_00540570(kwln00197fb0, NULL);
    func_004fa4b8(func_00197fe0);

    KWLN_U32_AT(0x00847f00) = 6;
    KWLN_U32_AT(0x00847f04) = 3;
    KWLN_U32_AT(0x00847f08) = 0x344;
    KWLN_U32_AT(0x00847f0c) = 0x00847f50;
    func_00567820((void*)D_00847F00);
    func_00569f60(0, 0, 1);
    func_0053b220(0);

    while (func_0053b2c0(&gp0xffff9430 + 8, D_00678798, 0) != 0)
    {
    }
    while (func_0053b2c0(&gp0xffff9430 + 12, D_006787A8, 0) != 0)
    {
    }
    while (func_0053b2c0(&gp0xffff9430 + 16, D_006787B8, 0) != 0)
    {
    }
    func_00566b08(&gp0xffff9430 + 8, D_005E5150);
    func_00566b08(&gp0xffff9430 + 12, D_006418E0);
    func_00566b08(&gp0xffff9430 + 16, D_00644330);
    func_0053b4f8(&gp0xffff9430 + 8);

    memset((void*)D_00847F30, 0, 0x20);
    KWLN_F32_AT(0x00847f30) = *((f32*)&gAspectRatio + 4);
    KWLN_U32_AT(0x00847f34) = 1;
    KWLN_U32_AT(0x00847f38) = 1;
    KWLN_U32_AT(0x00847f3c) = 0;
    func_0057f768((void*)D_00847F30);
    func_00540570(func_00197f80, NULL);

    kwlnSetFlags(0x80000000, true);
    adminiCreateTask();
    func_0031b470();
    H_Dbprt_Init(sMainCamera);
    H_Chrdsp_Init();
    kwlnPushCommonRenderStates();
    func_004d8300(1);
    func_004d8310(1);
    func_0010c050();
    func_00322010();
    func_0027e180();
    func_003bd130();
    func_003b4ee0();
    func_00396bf0(0);
    func_003bd280();
    K_FldFilter_Init();
    func_001dca10();
    func_001b7d00();
    K_Data_LoadFldMainScript();
    K_Data_LoadDngFloorsData(0);
    func_001d7260();
    func_001b7bb0();
    K_Data_CreateFldBaseMdl();
    func_001d4290();
    func_001b8b40();
    func_001b8c40();
    H_Fade_ReadPak();
    func_00111f50();
    func_0018e4a0();
    func_0018bc80();
    func_001eef20();
    FUN_0016f3e0(0x3f, 0);
    func_0017c280();
    func_0016c1d0();
    func_0020c8d0();
    func_004302b0();
    bsRootInit();
}

// FUN_001983a0
u8 kwlnUpdate()
{
    if (DAT_007cdffc != 0)
    {
        DAT_007ce0c4 = DAT_00960070;
        DAT_007cdffc = 0;
        KWLN_U32_AT(0x10000000) = 0;
        KWLN_U32_AT(0x10000010) = 0x83;
    }
    else
    {
        gT0CountVal = Y_Misc_GetT0Count();
        H_Cdvd_Read();
        func_0010cdd0();
        func_00108bc0();
        H_Pad_Update();
        sFlags &= ~KWLN_FLAG_ERR;

        if ((HPAD_CHKBTN_PRESSED(HPAD_PORT_2, HPAD_BTN_L1) &&
             HPAD_CHKBTN_PRESSED(HPAD_PORT_2, HPAD_BTN_SELECT)) &&
            HPAD_CHKBTN_JUSTPRESSED(HPAD_PORT_2, HPAD_BTN_START))
        {
            func_001e7720();
        }
        else
        {
            if (kwlnTaskMain() == 0)
            {
                return false;
            }
        }

frame_end:
        func_0010bf70();
        func_004c7cf0(1);
    }

    sFrameCount++;
    sFrameCount2++;

    return true;
}

// FUN_001984c0. Initialize everything + main loop
void kwlnMain()
{
    kwlnInitPS2Systems();
    kwlnInitRenderer();
    kwln00198010();

    while (true)
    {
        sRootTask = kwlnRootCreateTask();
        
        kwlnInitGameData();

        RpRandomSeed(DGET_T0_COUNT());
        RpRandomSeedMT(DGET_T0_COUNT());

        // main loop
        while (kwlnTaskExists(sRootTask))
        {
            kwlnUpdate();
        }
    }
}

// FUN_00198540
RpWorld* kwlnGetWorld(u32 worldIdx)
{
    return sWorlds[worldIdx];
}



// FUN_00198560
RpLight* kwlnGetAmbientLight()
{
    return sAmbientLight;
}

// FUN_00198570
RpLight* kwlnGetDirectionalLight()
{
    return sDirectionalLight;
}
// FUN_00198580
RpLight* func_00198580()
{
    return sSecondaryLight;
}

// FUN_00198590
RwCamera* kwlnGetMainCamera()
{
    return sMainCamera;
}

// FUN_001985a0
RwRGBA* kwlnGetClearColor()
{
    return &sClearColor;
}

// FUN_001985b0
void kwlnSetClearColor(u8 r, u8 g, u8 b, u8 a)
{
    sClearColor.r = r;
    sClearColor.g = g;
    sClearColor.b = b;
    sClearColor.a = a;
}

// FUN_001985d0
RwRGBA* func_001985d0()
{
    return &sClearColorAlt;
}

// FUN_001985e0
void func_001985e0(u8 r, u8 g, u8 b, u8 a)
{
    sClearColorAlt.r = r;
    sClearColorAlt.g = g;
    sClearColorAlt.b = b;
    sClearColorAlt.a = a;
}

// FUN_00198600
u32 kwlnGetFlags()
{
    return sFlags;
}

// FUN_00198610
void kwlnSetFlags(u32 flag, u32 enabled)
{
    if (enabled == true)
    {
        sFlags |= flag;
        return;
    }

    sFlags &= ~flag;
}
