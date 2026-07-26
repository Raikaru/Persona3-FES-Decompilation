#include "Kosaka/Field/k_fldrc.h"
#include "Kosaka/Field/k_fldFilter.h"
#include "Kosaka/Field/k_field.h"
#include "Kosaka/Field/k_sceneDraw.h"
#include "Kosaka/Field/k_fldCamera.h"
#include "Kosaka/k_assert.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Scene/mt_scene.h"
#include "Scene/resrcManager.h"
#include "Graphics/Model/mdlManager.h"
#include "Main/g_data.h"
#include "h_cdvd.h"
#include "temporary.h"
/* K_Field_Get aliases to prevent CSE/write-sinking from folding repeated calls. */
#pragma alias K_Field_Get_A K_Field_Get
extern void* K_Field_Get_A(void);
#pragma alias K_Field_Get_B K_Field_Get
extern void* K_Field_Get_B(void);
#pragma alias K_Field_Get_C K_Field_Get
extern void* K_Field_Get_C(void);
#pragma alias K_Field_Get_D K_Field_Get
extern void* K_Field_Get_D(void);
#pragma alias K_Field_Get_E K_Field_Get
extern void* K_Field_Get_E(void);
#pragma alias K_Field_Get_Z K_Field_Get
extern void* K_Field_Get_Z(void);

/* Retail field-resource callbacks use fixed-width aliases in the original EE build. */
typedef u8 undefined1;
typedef u16 undefined2;
typedef u32 undefined4;
typedef u64 undefined8;
extern void* (*DAT_00960184)(u32, ...);
#pragma alias DAT_00960184_abs DAT_00960184
extern u8 DAT_00960184_abs[];
extern void (*DAT_0096017c)(void*);
#pragma alias DAT_0096017c_abs DAT_0096017c
extern u32 DAT_0096017c_abs[];
extern void (*DAT_00960090)(u32, ...);
extern u8 PTR_DAT_007be9c8[];
extern u32* PTR_DAT_007cd540;
extern void* DAT_007ce0cc;
extern u64 DAT_00678f58;
extern u32 DAT_00678f60;
extern u64 DAT_00678f68;
extern u32 DAT_00678f70;
extern u32 DAT_007ce0d4;
extern u8 DAT_007ce0d8;
extern u8 DAT_007ce0dc;
extern u8 DAT_007ce0e0;
extern u8 DAT_007ce0e4;
extern u8 DAT_007ce0e8;
extern u8 DAT_007ce0ec;
extern u8 DAT_007ce0f0;
extern u8 DAT_007ce0f4;

/* Unrecovered engine entry points are kept typed at the ABI boundary. */
extern u32 FUN_001008b0();
extern u32 FUN_00100d80();
extern u32 FUN_00100ec0();
extern u32 FUN_001016b0();
extern u32 FUN_001021c0();
extern u32 FUN_0010c1a0();
extern u32 FUN_0010c3a0();
extern u32 FUN_0016ef30();
extern u32 FUN_0016f190();
extern u32 FUN_0017d920();
extern u32 FUN_0017da40();
extern u32 FUN_0017e480();
extern u32 FUN_00194b20();
typedef u32 (*KFldTaskUpdateFunc)(u32 task);
typedef void (*KFldTaskDestroyFunc)(u32 task);
extern u32 FUN_00194b80(u32 parent, u32 priority, const char* name,
                        KFldTaskUpdateFunc init, KFldTaskDestroyFunc destroy, u32 work);
extern u32 FUN_00195460();
extern u32 FUN_00198540();
extern u32 FUN_00198560();
extern u32 FUN_00198570();
extern u32 FUN_00198580();
extern u32 FUN_00198590();
extern u32 FUN_001985b0();
extern u32 FUN_001985e0();
extern u32 FUN_00198610();
extern u32 FUN_0019d3f0();
extern u32 FUN_0019fd40();
extern u32 FUN_0019fd70();
extern u32 FUN_0019fda0();
extern u32 FUN_0019fdd0();
extern u32 FUN_0019fe20();
extern u32 FUN_0019fe70();
extern u32 FUN_0019fec0();
extern u32 FUN_001a01c0();
extern u32 FUN_001a14c0();
extern u32 FUN_001a1540();
extern u32 FUN_001a6350();
extern u32 FUN_001a6400();
extern u32 FUN_001a64f0();
extern u32 FUN_001a66f0();
extern u32 FUN_001a6740();
extern u32 FUN_001a6c00();
extern u32 FUN_001a6e90();
extern u32 FUN_001a7570();
extern u32 FUN_001a7710();
extern u32 FUN_001a7b50();
extern u32 FUN_001a8140();
extern u32 FUN_001a88e0();
extern u32 FUN_001d4610();
extern u32 FUN_001d50c0();
extern u32 FUN_001d5130();
extern u32 FUN_00316b40();
extern u32 FUN_00316bd0();
extern u32 FUN_00316f70();
extern u32 FUN_00317450();
extern u32 FUN_003174e0();
extern u32 FUN_003182d0();
extern u32 FUN_003189f0();
extern u32 FUN_00318a30();
extern u32 FUN_00318a50();
extern u32 FUN_00318a70();
extern u32 FUN_00318ad0();
extern u32 FUN_00318b80();
extern u32 FUN_00319230();
extern u32 FUN_0034fcd0();
extern u32 FUN_0034fcf0();
extern u32 FUN_0034fd50();
extern u32 FUN_0034fdf0();
extern u32 FUN_0034fe30();
extern u32 FUN_0035bb40();
extern u32 FUN_003b5d50();
extern u32 FUN_0048d0e0();
extern u32 FUN_0048da30();
extern u32 FUN_0048ee70();
extern u32 FUN_0048eed0();
extern f32 FUN_0048ef60();
extern void FUN_0048efa0();
extern void FUN_0048efc0(int param_1, int param_2, f32 param_3);
extern u32 FUN_004916d0();
extern u32 FUN_00491cc0();
extern u32 FUN_00491ea0();
extern u32 FUN_004932c0();
extern u32 FUN_004944b0();
extern u32 FUN_0049a250();
extern u32 FUN_0049a290();
extern u32 FUN_0049a7c0();
extern u32 FUN_0049c160();
extern u32 FUN_0049c1b0();
extern u32 FUN_0049c3d0();
extern u32 FUN_0049c480();
extern u32 FUN_004bcbf0();
extern u32 FUN_004bda10();
extern u32 FUN_004c1970();
extern u32 FUN_004c2cc0();
extern u32 FUN_004c2d20();
extern u32 FUN_004c31b0();
extern u32 FUN_004c3880();
extern u32 FUN_004c38c0();
extern u32 FUN_004c5620();
extern u32 FUN_004c5780();
extern u32 FUN_004c58a0();
extern u32 FUN_004c6be0();
extern u32 FUN_004c8680();
extern u32 FUN_004c9d00();
extern u32 FUN_004c9d10();
extern u32 FUN_004c9d70(u32 camera, f32 value);
extern u32 FUN_004c9db0(u32 camera, f32 value);
extern u32 FUN_004cb270();
extern u32 FUN_004cb2f0();
extern u32 FUN_004cb7f0();
extern u32 FUN_004cb890();
extern u32 FUN_004d0d10();
extern u32 FUN_004d0dc0();
extern u32 FUN_004d7f60();
extern u32 FUN_0051e0f0();
extern u32 FUN_00523ac8();
extern u32 FUN_00523e68();
extern u32 FUN_00524270();
extern u32 FUN_001b9120();
extern u32 FUN_001ba5f0(u32 parentTask, u16 majorId, u16 minorId,
                        u16 param4, s16 param5, s16 param6, u32 flags,
                        u8 param8, u8 param9, s16 param10,
                        s32 param11, s32 param12, s32 param13, s32 param14);
extern s32 iGpffffb470;
extern s32 iGpffffb3e4;
extern u8 bGpffffb3f0;
extern u8 bGpffffb3ec;
extern u8 bGpffffb3f4;
extern u8 bGpffffb3e8;
extern u32 uGpffffb3dc;
extern u32 gp0xffff9538;
extern u32 gp0xffff9540;
extern u32 gp0xffff9548;
extern u32 gp0xffff9550;

static HCdvd* sFldFpcCdvd; // 007ce160. "field/pack/f%03d_%03d.fpc"
static HCdvd* sFldPacCdvd; // 007ce15c. "field/pack/f%03d_%03d.pac"

extern void* D_00867EF8;
extern void* D_00867EFC;
extern void* D_00867F00;
extern u32 FUN_001b2b30(u32 resource);
extern void FUN_001b2b90(u32 resource);
extern u32 FUN_001b2f00(u32* resource);
extern void FUN_001b3480(u32 resource);
extern u32 FUN_001b39e0(u32 resource);
extern void func_001bd450(u32 patternId, u32 mode);
extern void func_001bd8c0(void);
extern void* func_004cb2f0(u32 matrix);
extern u16 func_003b66b0(u16 resourceId, void* model);
extern void func_004c9d70(void* camera, f32 value);
extern MtScene* gMtScene;
extern void* D_0086BDC0[9];
extern void* uGpffffb590;
extern s32* piGpffffa850;
extern u16* puGpffffa850;
extern char D_00678D80[];
extern char D_00678E08[];
extern char D_00678E18[];
extern char D_00678FD0[];
extern char D_00679030[];
#pragma alias D_00679030_abs D_00679030
extern char D_00679030_abs[];
#pragma alias D_00679040_abs D_00679040
extern char D_00679040_abs[];
extern char D_00679040[];
extern char D_00679060[];
extern char D_00678DA0[];
extern char D_00678DC0[];
extern char D_00678DE0[];
extern char D_00678DF8[];
#pragma alias D_00678DF8_abs D_00678DF8
extern char D_00678DF8_abs[];
#pragma alias D_00678E50_abs D_00678E50
extern char D_00678E50_abs[];
#pragma alias D_00678E70_abs D_00678E70
extern char D_00678E70_abs[];
#pragma alias D_00678E90_abs D_00678E90
extern char D_00678E90_abs[];
extern char D_00678E50[];
extern char D_00678E70[];
extern char D_00678E90[];
extern u8 D_00678F90[];
extern HCdvd* func_001e2da0(u16 majorId, u16 minorId, s16 variant);
extern HCdvd* func_001e7470(u16 majorId, u16 minorId);
extern u32 func_001e2e50(void* request, void** outFile, u16 majorId,
                         u16 minorId, s16 variant);
extern u32 func_001e3940(void* resource, void* companion);
extern HCdvd* func_001e6cb0(u16 majorId, u16 minorId);
extern u32 func_001e6d50(HCdvd* request, void** outFile, u16 majorId,
                         u16 minorId);
extern void func_001e6ea0(void* fileMemory);
extern u32 func_001e74e0(void* request);
extern void func_001e7520(void* request);
extern u32 func_001a02c0(void);
extern void func_0019ff10(void);
extern void func_001a0040(u32 visible, u32 updateField);
extern u16 func_003b6790(u16 resourceId, void* resource);
extern void func_003b6f50(u16 resourceId, u32 type, f32 fov, void* matrix,
                          void* posOffset, f32 xzDeadZone, f32 yDeadZone);
extern u16 func_003b78b0(u16 resourceId, void* position, void* angles);
extern void func_003b7090(u16 resTypeId);
extern f32 func_001a5b30(void* matrix);
extern f32 func_001a5aa0(void* matrix);
extern f32 func_001a5bc0(void* matrix);
extern u32 func_001b8160(void);
extern u32 func_001b81f0(HCdvd* request);
extern u32 func_001b8680(void);
extern u32 func_001b8710(HCdvd* request);
extern u32 func_001b88d0(void);
extern u32 func_001b8960(HCdvd* request);
extern u32 FUN_001b6100(u32 id);
extern u32 FUN_001b61f0(void* resource, u32 archiveEntry);
extern void* func_001b83f0(void);
extern u16* func_001b85a0(u32 index);
extern void func_001b8870(void);
extern void func_001b8ae0(void);
extern void func_001b8b40(void);
extern u32 func_001b8c40(void);
extern void* kwlnGetMainCamera(void);
extern u32 func_001d6bc0(HCdvd* request, RwMatrix* matrix, f32* fov,
                         u32* type, RwV3d* posOffset, f32* xzDeadZone,
                         f32* yDeadZone);
u32 func_001b09b0(void);
void* FUN_001b2860(char* path);
void* FUN_001b2780(s16 majorId, s16 minorId);
void FUN_001b5e30(u32 color, const void* scale);
void FUN_001b5e60(u32 color, const void* scale);
void FUN_001b60a0(u32 value, const void* scale);
void FUN_001b60d0(u32 value, const void* scale);

// FUN_001b0710
void K_Fldrc_RequestArchives()
{
    s16 major;
    s16 minor;

    if (K_Field_Get()->rootTask != NULL)
    {
        major = K_Field_GetMajorId(K_Field_Get()->rootTask);
        minor = K_Field_GetMinorId(K_Field_Get()->rootTask);
        K_Fldrc_RequestFldPac(major, minor);

        major = K_Field_GetMajorId(K_Field_Get()->rootTask);
        minor = K_Field_GetMinorId(K_Field_Get()->rootTask);
        K_Fldrc_RequestFldFpc(major, minor);
    }
}

// FUN_001b07d0
u32 func_001b07d0(void)
{
    u32 loaded;

    loaded = true;
    if (K_Field_Get()->rootTask != NULL)
    {
        if (!K_Fldrc_IsFldPacLoaded())
        {
            loaded = false;
        }
        if (!func_001b09b0())
        {
            loaded = false;
        }
    }
    return loaded;
}

// FUN_001b0840
void K_Fldrc_DestroyArchives()
{
    K_Fldrc_DestroyFldPac();
    K_Fldrc_DestroyFldFpc();
}

// FUN_001b0870
void K_Fldrc_RequestFldPac(s16 majorId, s16 minorId)
{
    char buffer[64];

    if (sFldPacCdvd == NULL)
    {
        sprintf(buffer, "field/pack/f%03d_%03d.pac", majorId, minorId);
        sFldPacCdvd = H_Cdvd_Request(buffer, HCDVD_FILEARCHIVE);
    }
}

// FUN_001b08d0
u8 K_Fldrc_IsFldPacLoaded()
{
    if (sFldPacCdvd == NULL)
    {
        return true;
    }

    return H_Cdvd_IsFileLoaded(sFldPacCdvd) != false;
}

// FUN_001b0910
HCdvd* K_Fldrc_GetFldPacCdvd()
{
    return sFldPacCdvd;
}

// FUN_001b0920
void K_Fldrc_DestroyFldPac()

{
    if (sFldPacCdvd != NULL)
    {
        H_Cdvd_Destroy(sFldPacCdvd);
        sFldPacCdvd = NULL;
    }
}

// FUN_001b0950
void K_Fldrc_RequestFldFpc(s16 majorId, s16 minorId)
{
    char buffer[64];

    if (sFldFpcCdvd == NULL)
    {
        sprintf(buffer, "field/pack/f%03d_%03d.fpc", majorId, minorId);
        sFldFpcCdvd = H_Cdvd_Request(buffer, HCDVD_FILEARCHIVE);
    }
}

// FUN_001b09b0
u32 func_001b09b0(void)
{
    if (sFldFpcCdvd == NULL)
    {
        return true;
    }
    return H_Cdvd_IsFileLoaded(sFldFpcCdvd) != false;
}

// FUN_001b09f0
void K_Fldrc_DestroyFldFpc()
{
    if (sFldFpcCdvd != NULL)
    {
        H_Cdvd_Destroy(sFldFpcCdvd);
        sFldFpcCdvd = NULL;
    }
}

/*
 * Reconstructed field resource selection and FPC registration paths from
 * the retail call/store sequence; duplicated K_Field_Get accesses and the
 * secondary pack path are intentional. Branch/register layout still differs
 * from retail in the large dispatch prologue.
 */
#pragma push
// FUN_001b0a20 NONMATCHING
void K_Fldrc_001b0a20(s16 majorId, s16 minorId)
{
    char path[64];
    char path2[64];
    u32 count;
    u32 index;
    u32 dungeon;
    u8* field;

    field = (u8*)K_Field_Get();
    *(u32*)(field + 0x1168) = 0;
    field = (u8*)K_Field_Get_A();
    *(u32*)(field + 0x1058) = 0;

    index = (u16)majorId;
    dungeon = (((majorId >= 51) && (majorId < 59)) ||
               ((majorId >= 71) && (majorId < 79)));
    if (((majorId >= 21) && (majorId < 51) && (minorId == 0)) ||
        (dungeon != 0))
    {
        if (dungeon != 0)
        {
            index = (u16)(majorId - 30);
            *(u32*)((u8*)K_Field_Get() + 0x38) |= 0x80000000;
            *(void**)((u8*)K_Field_Get() + 0x10cc) =
                func_001e7470((u16)majorId, (u16)minorId);
            if (uGpffffb590 == NULL)
            {
                uGpffffb590 = mdlCreateFromPath(MODEL_TYPE_FLD, 0xffff,
                                                 D_00678DA0, MDL_READASYNC);
            }
        }
        if (*(u32*)((u8*)K_Field_Get() + 0x38) & 0x80000000)
        {
            if (sFldFpcCdvd == NULL)
            {
                sprintf(path, D_00678D80, majorId, minorId);
                sFldFpcCdvd = H_Cdvd_Request(path, HCDVD_FILEARCHIVE);
            }
            field = (u8*)K_Field_Get_A();
            count = *(u32*)(field + 0x105c);
            field = (u8*)K_Field_Get_B();
            *(s16*)(field + 0x1060 + count * 4) = (s16)index;
            field = (u8*)K_Field_Get_C();
            *(s16*)(field + 0x1062 + count * 4) = 18;
            field = (u8*)K_Field_Get_D();
            *(s16*)(field + 0x1060 + (count + 1) * 4) = (s16)index;
            field = (u8*)K_Field_Get_E();
            *(s16*)(field + 0x1062 + (count + 1) * 4) = 8;
            field = (u8*)K_Field_Get_A();
            *(s16*)(field + 0x1060 + (count + 2) * 4) = (s16)index;
            field = (u8*)K_Field_Get_B();
            *(s16*)(field + 0x1062 + (count + 2) * 4) = 7;
            field = (u8*)K_Field_Get_C();
            *(s16*)(field + 0x1060 + (count + 3) * 4) = (s16)index;
            field = (u8*)K_Field_Get_D();
            *(s16*)(field + 0x1062 + (count + 3) * 4) = 6;
            field = (u8*)K_Field_Get_E();
            *(s16*)(field + 0x1060 + (count + 4) * 4) = (s16)index;
            field = (u8*)K_Field_Get_A();
            *(s16*)(field + 0x1062 + (count + 4) * 4) = 5;
            field = (u8*)K_Field_Get_B();
            *(s16*)(field + 0x1060 + (count + 5) * 4) = (s16)index;
            field = (u8*)K_Field_Get_C();
            *(s16*)(field + 0x1062 + (count + 5) * 4) = 4;
            field = (u8*)K_Field_Get_D();
            *(s16*)(field + 0x1060 + (count + 6) * 4) = (s16)index;
            field = (u8*)K_Field_Get_E();
            *(s16*)(field + 0x1062 + (count + 6) * 4) = 3;
            field = (u8*)K_Field_Get_A();
            *(s16*)(field + 0x1060 + (count + 7) * 4) = (s16)index;
            field = (u8*)K_Field_Get_B();
            *(s16*)(field + 0x1062 + (count + 7) * 4) = 2;
            field = (u8*)K_Field_Get_C();
            *(s16*)(field + 0x1060 + (count + 8) * 4) = (s16)index;
            field = (u8*)K_Field_Get_D();
            *(s16*)(field + 0x1062 + (count + 8) * 4) = 1;
            field = (u8*)K_Field_Get_E();
            *(u32*)(field + 0x105c) = count + 9;
        }
        else
        {
            for (count = 0; count < 9; count++)
            {
                field = (u8*)K_Field_Get_A();
                *(void**)(field + 0x116c + count * 4) =
                    D_0086BDC0[count];
            }
            field = (u8*)K_Field_Get_B();
            *(u32*)(field + 0x1168) = 9;
            field = (u8*)K_Field_Get_C();
            *(u32*)(field + 0x1058) = 4;
        }
    }
    else
    {
        if (uGpffffb590 == NULL)
        {
            sprintf(path2, D_00678D80, majorId, minorId);
            sFldFpcCdvd = H_Cdvd_Request(path2, HCDVD_FILEARCHIVE);
        }
        field = (u8*)K_Field_Get_A();
        count = *(u32*)(field + 0x105c);
        field = (u8*)K_Field_Get_B();
        *(s16*)(field + 0x1060 + count * 4) = majorId;
        field = (u8*)K_Field_Get_C();
        count = *(u32*)(field + 0x105c);
        field = (u8*)K_Field_Get_D();
        *(s16*)(field + 0x1062 + count * 4) = minorId;
        field = (u8*)K_Field_Get_E();
        count = *(u32*)(field + 0x105c);
        field = (u8*)K_Field_Get_A();
        *(u32*)(field + 0x105c) = count + 1;
    }
    if (((majorId >= 21) && (majorId < 29) && (minorId == 0)) ||
        ((majorId >= 41) && (majorId < 49) && (minorId == 0)) ||
        ((majorId >= 51) && (majorId < 59)) ||
        ((majorId >= 71) && (majorId < 79)))
    {
        *(Model**)((u8*)K_Field_Get() + 0x11ec) =
            mdlCreateFromPath(MODEL_TYPE_FLD, 0xfffe, D_00678DC0,
                              MDL_READASYNC);
        *(Model**)((u8*)K_Field_Get() + 0x11f0) =
            mdlCreateFromPath(MODEL_TYPE_FLD, 0xfffd, D_00678DE0,
                              MDL_READASYNC);
    }
    *(u32*)0x007ce164 = *(u32*)0x007cdeac;
}
#pragma pop
/*
 * Retail keeps the field resource table as direct archive pointers.
 * The initialization phases therefore store and pass those pointers directly,
 * rather than treating each table entry as a wrapper with an a44 member.
 * Archive readiness and destruction are inlined to preserve the retail calls.
 */
#pragma push
#pragma opt_cse off
// FUN_001b10f0 NONMATCHING
u32 K_Fldrc_Init()
{
    u32 state;
    u32 count;
    u32 i;
    u32 errors;
    u32 scenePath;
    u8* node;
    void* resource;
    void* output;
    Resrc* list;
    Resrc* next;
    RwMatrix cameraMatrix;
    RwV3d cameraOffset;
    f32 cameraFov;
    f32 xzDeadZone;
    f32 yDeadZone;
    u32 cameraType;
    u16 handle;

    state = *(u32*)((u8*)K_Field_Get() + 0x1058);
    if (state == 0x3e7)
    {
        if (sFldPacCdvd != NULL)
        {
            H_Cdvd_Destroy(sFldPacCdvd);
            sFldPacCdvd = NULL;
        }
        return true;
    }
    switch (state)
    {
        case 0:
            goto init_phase0;
        case 1:
            goto init_phase1;
        case 2:
            goto init_phase2;
        case 3:
            goto init_phase3;
        case 4:
            goto init_phase4;
        case 5:
            goto init_phase5;
        case 6:
            goto init_phase6;
        case 7:
            goto init_phase7;
        case 8:
            goto init_phase8;
        case 9:
            goto init_phase9;
        case 0x0a:
            goto init_phase10;
        case 0x1e:
            goto init_phase1e;
        case 0x1f:
            goto init_phase1f;
        case 0x20:
            goto init_phase20;
        case 0x28:
            goto init_phase28;
        case 0x29:
            goto init_phase29;
        default:
            return false;
    }

init_phase0:
    if ((sFldPacCdvd != NULL &&
         H_Cdvd_IsFileLoaded(sFldPacCdvd) == false) ||
        (sFldFpcCdvd != NULL &&
         H_Cdvd_IsFileLoaded(sFldFpcCdvd) == false))
    {
        return false;
    }
    *(s32*)((u8*)K_Field_Get() + 0x105c) -= 1;
    *(void**)((u8*)K_Field_Get() + 0x116c +
              *(u32*)((u8*)K_Field_Get() + 0x1168) * 4) =
        FUN_001b2780(
            (u16)*(s16*)((u8*)K_Field_Get() + 0x1060 +
                         *(u32*)((u8*)K_Field_Get() + 0x105c) * 4),
            (u16)*(s16*)((u8*)K_Field_Get() + 0x1062 +
                         *(u32*)((u8*)K_Field_Get() + 0x105c) * 4));
    *(u32*)((u8*)K_Field_Get_Z() + 0x1058) = 1;

init_phase1:
    resource = *(void**)((u8*)K_Field_Get() + 0x116c +
                         *(u32*)((u8*)K_Field_Get() + 0x1168) * 4);
    if (FUN_001b2b30((u32)resource) == false)
    {
        return false;
    }
    resource = *(void**)((u8*)K_Field_Get() + 0x116c +
                         *(u32*)((u8*)K_Field_Get() + 0x1168) * 4);
    FUN_001b2b90((u32)resource);
    *(u32*)((u8*)K_Field_Get_Z() + 0x1058) = 2;

init_phase2:
    count = *(u32*)((u8*)K_Field_Get() + 0x1168);
    resource = *(void**)((u8*)K_Field_Get() + 0x116c + count * 4);
    if (FUN_001b2f00((u32*)resource) == false)
    {
        return false;
    }
    *(u32*)((u8*)K_Field_Get() + 0x1168) += 1;
    if (*(s32*)((u8*)K_Field_Get() + 0x105c) > 0)
    {
        *(u32*)((u8*)K_Field_Get_Z() + 0x1058) = 0;
        return false;
    }
    if ((gMtScene->flags & 0x80000000) != 0)
    {
        gMtScene->fldMajorId =
            *(u16*)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c) + 4);
        gMtScene->fldMinorId =
            *(u16*)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c) + 6);
    }
    for (i = 0; i < *(u32*)((u8*)K_Field_Get() + 0x1168); i++)
    {
        resource = *(void**)((u8*)K_Field_Get() + 0x116c + i * 4);
        FUN_001b3480((u32)resource);
    }
    *(u32*)((u8*)K_Field_Get_Z() + 0x1058) = 3;

init_phase3:
    errors = 0;
    for (i = 0; i < *(u32*)((u8*)K_Field_Get() + 0x1168); i++)
    {
        resource = *(void**)((u8*)K_Field_Get() + 0x116c + i * 4);
        if (FUN_001b39e0((u32)resource) == false)
        {
            errors++;
        }
    }
    if (errors != 0)
    {
        return false;
    }
    if (sFldFpcCdvd != NULL)
    {
        H_Cdvd_Destroy(sFldFpcCdvd);
        sFldFpcCdvd = NULL;
    }
    *(u32*)((u8*)K_Field_Get_Z() + 0x1058) = 4;

init_phase4:
    if ((*(Model**)((u8*)K_Field_Get() + 0x11ec) != NULL) &&
        (mdlStreamRead(*(Model**)((u8*)K_Field_Get() + 0x11ec)) == false))
    {
        return false;
    }
    if ((*(Model**)((u8*)K_Field_Get() + 0x11f0) != NULL) &&
        (mdlStreamRead(*(Model**)((u8*)K_Field_Get() + 0x11f0)) == false))
    {
        return false;
    }
    count = *(u32*)0x007ce164;
    *(u32*)0x007ce164 = *(u32*)0x007cdeac - count;
    if (gMtScene->fldMajorId < 0xc8)
    {
        *(u32*)0x007ce164 += 0x32000;
    }
    D_00867EF8 = (void*)func_001b8160();
    D_00867EFC = (void*)func_001b8680();
    D_00867F00 = (void*)func_001b88d0();
    *(u32*)((u8*)K_Field_Get_Z() + 0x1058) = 5;

init_phase5:
    if ((D_00867EF8 != NULL) &&
        (func_001b81f0((HCdvd*)D_00867EF8) == false))
    {
        return false;
    }
    D_00867EF8 = NULL;
    if ((D_00867EFC != NULL) &&
        (func_001b8710((HCdvd*)D_00867EFC) == false))
    {
        return false;
    }
    D_00867EFC = NULL;
    if ((D_00867F00 != NULL) &&
        (func_001b8960((HCdvd*)D_00867F00) == false))
    {
        return false;
    }
    D_00867F00 = NULL;
    if (func_001a02c0() == 1)
    {
        node = *(u8**)((u8*)K_Field_Get() + 0x116c);
        *(void**)(node + 0xa44) =
            func_001e2da0((u16)gMtScene->fldMajorId, (u16)gMtScene->fldMinorId,
                          gMtScene->unk_14);
    }
    else
    {
        for (i = 0; i < *(u32*)((u8*)K_Field_Get() + 0x1168); i++)
        {
            *(void**)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c + i * 4) +
                      0xa44) =
                func_001e2da0(
                    *(u16*)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c +
                                         i * 4) + 4),
                    *(u16*)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c +
                                         i * 4) + 6),
                    gMtScene->unk_14);
        }
    }
    *(u32*)((u8*)K_Field_Get_Z() + 0x1058) = 6;

init_phase6:
    errors = 0;
    if (func_001a02c0() == 1)
    {
        node = *(u8**)((u8*)K_Field_Get() + 0x116c);
        if (func_001e2e50(*(void**)(node + 0xa44),
                          (void**)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c) +
                                   0xa48),
                          (u16)gMtScene->fldMajorId, (u16)gMtScene->fldMinorId,
                          gMtScene->unk_14) == false)
        {
            errors++;
        }
    }
    else
    {
        for (i = 0; i < *(u32*)((u8*)K_Field_Get() + 0x1168); i++)
        {
            if (func_001e2e50(
                    *(void**)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c +
                                           i * 4) + 0xa44),
                    (void**)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c +
                                          i * 4) + 0xa48),
                    *(u16*)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c +
                                         i * 4) + 4),
                    *(u16*)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c +
                                         i * 4) + 6),
                    gMtScene->unk_14) == false)
            {
                errors++;
            }
        }
    }
    if (errors != 0)
    {
        return false;
    }
    *(u32*)((u8*)K_Field_Get_Z() + 0x1058) = 7;

init_phase7:
    errors = 0;
    if (((gMtScene->fldMajorId < 0x3b) ||
          ((gMtScene->fldMajorId >= 0x47) && (gMtScene->fldMajorId < 0x4f))) &&
         (uGpffffb590 != NULL) &&
        (mdlStreamRead((Model*)uGpffffb590) == false))
    {
        errors++;
    }
    if (func_001e74e0(*(void**)((u8*)K_Field_Get() + 0x10cc)) == false)
    {
        errors++;
    }
    for (i = 0; i < *(u32*)((u8*)K_Field_Get() + 0x1168); i++)
    {
        if (func_001e3940(
                *(void**)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c + i * 4) +
                          0xa44),
                *(void**)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c + i * 4) +
                          0xa48)) == false)
        {
            errors++;
        }
        else
        {
            *(void**)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c + i * 4) +
                      0xa44) = NULL;
        }
    }
    if (errors != 0)
    {
        return false;
    }
    for (i = 0; i < *(u32*)((u8*)K_Field_Get() + 0x1168); i++)
    {
        if (*(void**)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c + i * 4) +
                      0xa3c) == NULL)
        {
            *(HCdvd**)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c + i * 4) +
                       0xa38) =
                func_001e6cb0(
                    *(u16*)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c +
                                         i * 4) + 4),
                    *(u16*)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c +
                                         i * 4) + 6));
        }
    }
    if ((gMtScene->fldMajorId < 0x3b) ||
        ((gMtScene->fldMajorId >= 0x47) && (gMtScene->fldMajorId < 0x4f)))
    {
        HCdvd* eventRequest;
        void* eventPayload;

        eventRequest = *(HCdvd**)((u8*)K_Field_Get() + 0x10cc);
        eventPayload = *(void**)((u8*)eventRequest + 0x110);
        memcpy((u8*)eventPayload + 4,
               (u8*)*(HCdvd**)((u8*)K_Field_Get() + 0x10cc) + 0x48, 0x1000);
        func_001e7520(*(HCdvd**)((u8*)K_Field_Get() + 0x10cc));
        *(HCdvd**)((u8*)K_Field_Get() + 0x10cc) =
            func_001e6cb0((u16)gMtScene->fldMajorId, (u16)gMtScene->fldMinorId);
    }
    *(u32*)((u8*)K_Field_Get_Z() + 0x1058) = 8;

init_phase8:
    if ((gMtScene->fldMajorId < 0x3b) ||
        ((gMtScene->fldMajorId >= 0x47) && (gMtScene->fldMajorId < 0x4f)))
    {
        for (i = 0; i < *(u32*)((u8*)K_Field_Get() + 0x1168); i++)
        {
            if (func_001e6d50(
                    *(HCdvd**)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c +
                                            i * 4) + 0xa38),
                    (void**)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c +
                                          i * 4) + 0xa3c),
                    *(u16*)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c +
                                         i * 4) + 4),
                    *(u16*)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c +
                                         i * 4) + 6)) == false)
            {
                return false;
            }
            *(HCdvd**)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c + i * 4) +
                       0xa38) = NULL;
        }
        output = NULL;
        if (func_001e6d50(*(HCdvd**)((u8*)K_Field_Get() + 0x10cc), &output,
                          (u16)gMtScene->fldMajorId, (u16)gMtScene->fldMinorId) ==
            false)
        {
            return false;
        }
        if (output != NULL)
        {
            func_001e6ea0(output);
            (*DAT_0096017c)(output);
        }
        *(HCdvd**)((u8*)K_Field_Get() + 0x10cc) = NULL;
    }
    else
    {
        for (i = 0; i < *(u32*)((u8*)K_Field_Get() + 0x1168); i++)
        {
            func_001e6ea0(
                *(void**)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c + i * 4) +
                          0xa3c));
            *(HCdvd**)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c + i * 4) +
                       0xa38) = NULL;
        }
    }
    scenePath = K_Scene_001a0250();
    if (scenePath == 1)
    {
        for (i = 0; i < 9; i++)
        {
            D_0086BDC0[i] =
                *(void**)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c + i * 4) +
                          0xa3c);
        }
        if (datGetScenarioMode() == 0)
        {
            func_001bd450((u32)(gMtScene->fldMajorId - 0x14), 1);
        }
        else
        {
            func_001bd450((u32)(gMtScene->fldMajorId - 0x28), 1);
        }
        func_001bd8c0();
    }
    else if ((gMtScene->fldMajorId < 0x3b) ||
             ((gMtScene->fldMajorId >= 0x47) &&
              (gMtScene->fldMajorId < 0x4f)))
    {
        for (i = 0; i < 9; i++)
        {
            D_0086BDC0[i] =
                *(void**)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c + i * 4) +
                          0xa3c);
        }
        func_001bd8c0();
    }
    else
    {
        node = *(u8**)((u8*)K_Field_Get() + 0x116c);
        func_003b6790(0, node);
        for (i = 0;
             i < *(u32*)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c) + 0x118);
             i++)
        {
            void* matrix;

            matrix = func_004cb2f0(
                *(u32*)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c) +
                        i * 0x18 + 0x124));
            if ((*(u16*)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c) +
                         i * 0x18 + 0x11c) == 0) ||
                (*(u16*)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c) +
                         i * 0x18 + 0x11c) == 2))
            {
                handle = MT_Scene_CreateResModelFld(
                    *(u16*)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c) +
                            i * 0x18 + 0x120),
                    *(Model**)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c) +
                               i * 0x18 + 0x128));
                if (handle == 0)
                {
                    K_Assert(D_00678DF8, 0x2e4);
                }
                {
                    f32 angles[3];

                    angles[0] = func_001a5b30(matrix);
                    angles[1] = func_001a5aa0(matrix);
                    angles[2] = func_001a5bc0(matrix);
                    func_003b78b0(handle, (u8*)matrix + 0x30, angles);
                }
                if ((*(u16*)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c) +
                             i * 0x18 + 0x11e) & 2) != 0)
                {
                    Resrc* res;

                    res = MT_Scene_GetRes(handle);
                    if (res != NULL)
                    {
                        *(u32*)((u8*)res + 0x110) = 1;
                    }
                }
                *(void**)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c) +
                          i * 0x18 + 0x128) = NULL;
            }
        }
        for (i = 0;
             i < *(u32*)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c) + 0x118);
             i++)
        {
            if (*(u16*)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c) +
                        i * 0x18 + 0x11c) == 1)
            {
                handle = func_003b66b0(
                    *(u16*)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c) +
                            i * 0x18 + 0x120),
                    *(void**)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c) +
                              i * 0x18 + 0x12c));
                if (handle == 0)
                {
                    K_Assert(D_00678DF8, 0x305);
                }
                *(void**)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c) +
                          i * 0x18 + 0x12c) = NULL;
                {
                    Resrc* res;

                    res = MT_Scene_GetRes(handle);
                    if (res != NULL)
                    {
                        res->flags |= 2;
                    }
                }
            }
        }
        *(u32*)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c) + 0x118) = 0;
        func_0019ff10();
        func_001a0040(1, 1);
    }

init_camera_common:
    gMtScene->cmrCdvd = (HCdvd*)FUN_001b6100((u16)gMtScene->unk_16);
    if (gMtScene->fldMajorId >= 0xc8)
    {
        func_004c9d70(kwlnGetMainCamera(), 35.0f);
    }
    if (gMtScene->fldMajorId < 0xc8)
    {
        func_004c9d70(kwlnGetMainCamera(), 100.0f);
    }
    if (gMtScene->cmrCdvd == NULL)
    {
        gMtScene->cmrCdvd = func_001d6b10();
        if (gMtScene->cmrCdvd == NULL)
        {
            *(u32*)((u8*)K_Field_Get_Z() + 0x1058) = 0x3e7;
            return false;
        }
        *(u32*)((u8*)K_Field_Get_Z() + 0x1058) = 0x0a;
        goto init_phase10;
    }
    *(u32*)((u8*)K_Field_Get_Z() + 0x1058) = 9;

init_phase9:
    if (FUN_001b61f0(gMtScene->cmrCdvd, (u16)gMtScene->unk_16) == false)
    {
        return false;
    }
    gMtScene->cmrCdvd = func_001d6b10();
    if (gMtScene->cmrCdvd == NULL)
    {
        *(u32*)((u8*)K_Field_Get_Z() + 0x1058) = 0x3e7;
        return false;
    }
    *(u32*)((u8*)K_Field_Get_Z() + 0x1058) = 0x0a;

init_phase10:
    if (FUN_001b61f0(gMtScene->cmrCdvd, (u16)gMtScene->unk_16) == false)
    {
        return false;
    }
    gMtScene->cmrCdvd = func_001d6b10();
    if (gMtScene->cmrCdvd == NULL)
    {
        *(u32*)((u8*)K_Field_Get_Z() + 0x1058) = 0x3e7;
        return false;
    }
    if (func_001d6bc0(gMtScene->cmrCdvd, &cameraMatrix, &cameraFov,
                      &cameraType, &cameraOffset, &xzDeadZone,
                      &yDeadZone) == false)
    {
        return false;
    }
    func_003b6f50(0, cameraType, cameraFov, &cameraMatrix, &cameraOffset,
                  xzDeadZone, yDeadZone);
    *(u32*)((u8*)K_Field_Get_Z() + 0x1058) = 0x3e7;
    return false;

init_phase1e:
    list = MT_Scene_GetResListHead(3);
    while (list != NULL)
    {
        next = list->next;
        func_003b7090(list->resTypeId);
        list = next;
    }
    list = MT_Scene_GetResListHead(8);
    while (list != NULL)
    {
        next = list->next;
        func_003b7090(list->resTypeId);
        list = next;
    }
    if (func_001a02c0() == 1)
    {
        node = *(u8**)((u8*)K_Field_Get() + 0x116c);
        *(void**)(node + 0xa44) =
            func_001e2da0((u16)gMtScene->fldMajorId, (u16)gMtScene->fldMinorId,
                          gMtScene->unk_14);
    }
    else
    {
        for (i = 0; i < *(u32*)((u8*)K_Field_Get() + 0x1168); i++)
        {
            *(void**)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c + i * 4) +
                      0xa44) =
                func_001e2da0(
                    *(u16*)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c +
                                         i * 4) + 4),
                    *(u16*)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c +
                                         i * 4) + 6),
                    gMtScene->unk_14);
        }
    }
    *(u32*)((u8*)K_Field_Get_Z() + 0x1058) = 0x1f;

init_phase1f:
    errors = 0;
    if (func_001a02c0() == 1)
    {
        node = *(u8**)((u8*)K_Field_Get() + 0x116c);
        if (func_001e2e50(*(void**)(node + 0xa44),
                          (void**)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c) +
                                   0xa48),
                          (u16)gMtScene->fldMajorId, (u16)gMtScene->fldMinorId,
                          gMtScene->unk_14) == false)
        {
            errors++;
        }
    }
    else
    {
        for (i = 0; i < *(u32*)((u8*)K_Field_Get() + 0x1168); i++)
        {
            if (func_001e2e50(
                    *(void**)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c +
                                           i * 4) + 0xa44),
                    (void**)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c +
                                          i * 4) + 0xa48),
                    *(u16*)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c +
                                         i * 4) + 4),
                    *(u16*)((u8*)*(u8**)((u8*)K_Field_Get() + 0x116c +
                                         i * 4) + 6),
                    gMtScene->unk_14) == false)
            {
                errors++;
            }
        }
    }
    if (errors != 0)
    {
        return false;
    }
    *(u32*)((u8*)K_Field_Get_Z() + 0x1058) = 0x20;

init_phase20:
    node = *(u8**)((u8*)K_Field_Get() + 0x116c);
    for (i = 0; i < *(u32*)(node + 0x118); i++)
    {
        u8* record;
        u16 recordType;

        record = node + i * 0x18;
        recordType = *(u16*)(record + 0x11c);
        if (recordType == 1)
        {
            handle = func_003b66b0(*(u16*)(record + 0x120),
                                   *(void**)(record + 0x12c));
            if (handle == 0)
            {
                K_Assert(D_00678DF8, 0x305);
            }
            *(void**)(record + 0x12c) = NULL;
            {
                Resrc* res;

                res = MT_Scene_GetRes(handle);
                if (res != NULL)
                {
                    res->flags |= 2;
                }
            }
        }
    }
    *(u32*)(node + 0x118) = 0;
    func_0019ff10();
    func_001a0040(1, 1);
    goto init_camera_common;

init_phase28:
    if ((gMtScene->flags & 4) == 0)
    {
        *(u32*)((u8*)K_Field_Get_Z() + 0x1058) = 0x3e7;
        return false;
    }
    gMtScene->cmrCdvd = (HCdvd*)FUN_001b6100((u16)gMtScene->unk_16);
    *(u32*)((u8*)K_Field_Get_Z() + 0x1058) = 0x29;

init_phase29:
    if (FUN_001b61f0(gMtScene->cmrCdvd, (u16)gMtScene->unk_16) == false)
    {
        return false;
    }
    *(u32*)((u8*)K_Field_Get_Z() + 0x1058) = 0x3e7;
    return false;
}
#pragma pop

// FUN_001b5850
void* K_Fldrc_UpdateFilterTask(KwlnTask* fldFilterTask)
{
    K_FldFilter_Main();

    return KWLNTASK_CONTINUE;
}

// FUN_001b5880
void K_Fldrc_DestroyFilterTask(KwlnTask* fldFilterTask)
{
    RwFree(fldFilterTask->workData);
}

// FUN_001b58b0
KwlnTask* K_Fldrc_CreateFilterTask(KwlnTask* parent)
{
    FldFilterWork* work;
    KwlnTask* task;

    work = RwCalloc(1, sizeof(FldFilterWork), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreate(parent,
                          "field filter",
                          4197,
                          K_Fldrc_UpdateFilterTask,
                          K_Fldrc_DestroyFilterTask,
                          work);

    work->unk_08 = 1;
    work->unk_0c = 200;

    return task;
}
// FUN_001b4720 NONMATCHING
void FUN_001b4720(void* camera, u32* resource)
{
    u32 savedLight[4];
    u32 savedFog[4];
    u32 savedStates[16];
    u32* state;
    u32 world;
    u32 light;
    u32 value;
    s32 i;
    u32 count;

    state = (u32*)FUN_00198560();
    savedLight[0] = state[6];
    savedLight[1] = state[7];
    savedLight[2] = state[8];
    savedLight[3] = state[9];
    state = (u32*)FUN_00198570();
    savedFog[0] = state[6];
    savedFog[1] = state[7];
    savedFog[2] = state[8];
    savedFog[3] = state[9];
    state = (u32*)FUN_00198570();
    for (i = 0; i < 16; i++)
    {
        savedStates[i] = ((u32*)(*(u32*)((u8*)state + 4) + 0x10))[i];
    }

    light = FUN_00198560();
    value = FUN_0019fd40();
    FUN_004944b0(light, value);
    light = FUN_00198570();
    value = FUN_0019fd70();
    FUN_004944b0(light, value);
    state = (u32*)FUN_00198570();
    value = FUN_0019fda0();
    FUN_004cb7f0(*(u32*)((u8*)state + 4), value, 0);
    state = (u32*)FUN_00198570();
    *((u8*)state + 2) = 3;
    FUN_00198570();

    if ((*resource & 1) == 0)
    {
        light = FUN_00198540((u32)DAT_007ce0cc);
        value = FUN_00198580();
        FUN_0049c480(light, value);
    }
    else
    {
        light = FUN_00198540((u32)DAT_007ce0cc);
        FUN_0049c1b0(light, (u32)camera);
        if ((*resource & 0x80000000) == 0)
        {
            if ((*resource & 0x40000000) == 0)
            {
                FUN_0049c160(resource[2], (u32)camera);
            }
            else
            {
                FUN_0049c160(resource[4], (u32)camera);
            }
        }
        else
        {
            FUN_0049c160(resource[3], (u32)camera);
        }
        light = FUN_00198540((u32)DAT_007ce0cc);
        value = FUN_00198560();
        FUN_0049c480(light, value);
        light = FUN_00198540((u32)DAT_007ce0cc);
        value = FUN_00198570();
        FUN_0049c480(light, value);
        if ((*resource & 0x80000000) == 0)
        {
            if ((*resource & 0x40000000) == 0)
            {
                value = FUN_00198560();
                FUN_0049c3d0(resource[2], value);
                value = FUN_00198570();
                FUN_0049c3d0(resource[2], value);
            }
            else
            {
                value = FUN_00198560();
                FUN_0049c3d0(resource[4], value);
                value = FUN_00198570();
                FUN_0049c3d0(resource[4], value);
            }
        }
        else
        {
            value = FUN_00198560();
            FUN_0049c3d0(resource[3], value);
            value = FUN_00198570();
            FUN_0049c3d0(resource[3], value);
        }
    }

    world = FUN_004c9d10((u32)camera);
    if (world == 0)
    {
        FUN_0019d3f0(0x678df8, 0x82d);
    }
    FUN_00198610(2, 0);
    FUN_00198610(2, 1);
    if ((*resource & 0xc0000000) == 0)
    {
        count = resource[5];
        for (i = 0; (u32)i < count; i++)
        {
            if (resource[i + 0x26] != 0)
            {
                FUN_001a8140(resource[i + 0x26], 1);
            }
        }
    }
    FUN_004c9d00((u32)camera);

    if ((*resource & 1) == 0)
    {
        light = FUN_00198540((u32)DAT_007ce0cc);
        value = FUN_00198580();
        FUN_0049c3d0(light, value);
    }
    else
    {
        if ((*resource & 0x80000000) == 0)
        {
            if ((*resource & 0x40000000) == 0)
            {
                value = FUN_00198560();
                FUN_0049c480(resource[2], value);
                value = FUN_00198570();
                FUN_0049c480(resource[2], value);
            }
            else
            {
                value = FUN_00198560();
                FUN_0049c480(resource[4], value);
                value = FUN_00198570();
                FUN_0049c480(resource[4], value);
            }
        }
        else
        {
            value = FUN_00198560();
            FUN_0049c480(resource[3], value);
            value = FUN_00198570();
            FUN_0049c480(resource[3], value);
        }
        light = FUN_00198540((u32)DAT_007ce0cc);
        value = FUN_00198560();
        FUN_0049c3d0(light, value);
        light = FUN_00198540((u32)DAT_007ce0cc);
        value = FUN_00198570();
        FUN_0049c3d0(light, value);
        if ((*resource & 0x80000000) == 0)
        {
            if ((*resource & 0x40000000) == 0)
            {
                FUN_0049c1b0(resource[2], (u32)camera);
            }
            else
            {
                FUN_0049c1b0(resource[4], (u32)camera);
            }
        }
        else
        {
            FUN_0049c1b0(resource[3], (u32)camera);
        }
        light = FUN_00198540((u32)DAT_007ce0cc);
        FUN_0049c160(light, (u32)camera);
    }

    state = (u32*)FUN_00198560();
    FUN_004944b0(state, savedLight);
    state = (u32*)FUN_00198570();
    FUN_004944b0(state, savedFog);
    state = (u32*)FUN_00198570();
    FUN_004cb7f0(*(u32*)((u8*)state + 4), savedStates, 0);
    state = (u32*)FUN_00198570();
    *((u8*)state + 2) = 3;
    FUN_00198570();
    FUN_00198610(3, 0);
}

#pragma push
#pragma opt_loop_invariants on
// FUN_001b4e00 NONMATCHING
void FUN_001b4e00(u32 unused, u32* resource, const f32* offset)
{
    u32 i;
    u32 count;
    s16 type;
    u32 object;
    u32 frame;
    u32 matrix;
    f32* pos;
    f32 xyz[3];
    u32 localMatrix[16];
    u32 atomic;

    (void)unused;
    pos = (f32*)offset;
    if ((*resource & 1) == 0)
    {
        if (resource[2] != 0)
        {
            object = *(u32*)(resource[2] + 4);
            matrix = FUN_004cb2f0(object);
            xyz[0] = *(f32*)(matrix + 0x30) + pos[0];
            xyz[1] = *(f32*)(matrix + 0x34) + pos[1];
            xyz[2] = *(f32*)(matrix + 0x38) + pos[2];
            *(f32*)(object + 0x40) = xyz[0];
            *(f32*)(object + 0x44) = xyz[1];
            *(f32*)(object + 0x48) = xyz[2];
            FUN_004c2cc0(localMatrix);
            FUN_004c2d20(object + 0x10, localMatrix);
            FUN_004cb270(object);
        }
        if (resource[4] != 0)
        {
            object = *(u32*)(resource[4] + 4);
            matrix = FUN_004cb2f0(object);
            xyz[0] = *(f32*)(matrix + 0x30) + pos[0];
            xyz[1] = *(f32*)(matrix + 0x34) + pos[1];
            xyz[2] = *(f32*)(matrix + 0x38) + pos[2];
            *(f32*)(object + 0x40) = xyz[0];
            *(f32*)(object + 0x44) = xyz[1];
            *(f32*)(object + 0x48) = xyz[2];
            FUN_004c2cc0(localMatrix);
            FUN_004c2d20(object + 0x10, localMatrix);
            FUN_004cb270(object);
        }
    }
    count = resource[5];
    for (i = 0; i < count; i++)
    {
        if (resource[i + 6] != 0)
        {
            object = *(u32*)(resource[i + 6] + 4);
            matrix = FUN_004cb2f0(object);
            xyz[0] = *(f32*)(matrix + 0x30) + pos[0];
            xyz[1] = *(f32*)(matrix + 0x34) + pos[1];
            xyz[2] = *(f32*)(matrix + 0x38) + pos[2];
            *(f32*)(object + 0x40) = xyz[0];
            *(f32*)(object + 0x44) = xyz[1];
            *(f32*)(object + 0x48) = xyz[2];
            FUN_004c2cc0(localMatrix);
            FUN_004c2d20(object + 0x10, localMatrix);
            FUN_004cb270(object);
        }
    }
    count = resource[0x46];
    for (i = 0; i < count; i++)
    {
        type = (s16)resource[i * 6 + 0x47];
        if ((type == 0) || (type == 2))
        {
            FUN_00318a30(resource[i * 6 + 0x4a], (u32)offset, 2);
        }
        else if (type == 1)
        {
            u32 transform[15];
            f32 modelPos[3];
            u32* params;

            params = (u32*)FUN_004c38c0();
            params[0] = 0x3f800000;
            params[1] = 0;
            params[2] = 0;
            params[3] = 0x20003;
            params[4] = 0;
            params[5] = 0x3f800000;
            params[6] = 0;
            params[8] = 0;
            params[9] = 0;
            params[10] = 0;
            params[12] = 0;
            params[13] = 0;
            params[14] = 0x3f800000;
            transform[0] = DAT_00678f58;
            transform[1] = DAT_00678f60;
            FUN_004c31b0(unused, (u32)params, transform, 2);
            matrix = FUN_004cb2f0(resource[i * 6 + 0x49]);
            modelPos[0] = *(f32*)(matrix + 0x30);
            modelPos[1] = *(f32*)(matrix + 0x34);
            modelPos[2] = *(f32*)(matrix + 0x38);
            FUN_004c6be0(modelPos, modelPos, (u32)params);
            modelPos[0] += pos[0];
            modelPos[1] += pos[1];
            modelPos[2] += pos[2];
            FUN_0034fdf0(resource[i * 6 + 0x4b], modelPos);
            FUN_004c3880((u32)params);
        }
    }
}
#pragma opt_loop_invariants off
#pragma pop

// FUN_001b5200 NONMATCHING
void FUN_001b5200(u32 unused, u32* resource)
{
    u32 i;
    u32 count;
    s16 type;
    u32 color[3];

    (void)unused;
    color[0] = DAT_00678f68;
    color[1] = DAT_00678f70;
    color[2] = 0;
    if ((*resource & 1) == 0)
    {
        if (resource[2] != 0)
        {
            FUN_004cb890(*(u32*)(resource[2] + 4), color, 2);
        }
        if (resource[4] != 0)
        {
            FUN_004cb890(*(u32*)(resource[4] + 4), color, 2);
        }
    }
    count = resource[5];
    for (i = 0; i < count; i++)
    {
        if (resource[i + 6] != 0)
        {
            FUN_004cb890(*(u32*)(resource[i + 6] + 4), color, 2);
        }
    }
    count = resource[0x46];
    for (i = 0; i < count; i++)
    {
        type = (s16)resource[i * 6 + 0x47];
        if ((type == 0) || (type == 2))
        {
            FUN_00318a50(unused, resource[i * 6 + 0x4a], color, 2);
        }
        else if (type == 1)
        {
            FUN_0034fe30(0, unused, 0, resource[i * 6 + 0x4b]);
        }
    }
}

// FUN_001b5380 NONMATCHING
void* FUN_001b5380(u32* resource, void* position, u32 direction)
{
    u32* copy;
    u32 i;
    u32 j;
    s16 type;
    u32 model;
    u32 source;

    if ((*resource & 1) != 0)
    {
        return NULL;
    }
    copy = (u32*)(*DAT_00960184)(1, 0xa4c, 0x40000);
    if (copy == NULL)
    {
        return NULL;
    }
    copy[0] = resource[0] | 2;
    copy[1] = resource[1];
    *(u16*)((u8*)copy + 6) = *(u16*)((u8*)resource + 6);
    if (resource[2] != 0)
    {
        source = FUN_00491cc0(resource[2]);
        copy[2] = source;
        copy[3] = FUN_001a7570(source);
    }
    if (resource[4] != 0)
    {
        copy[4] = FUN_00491cc0(resource[4]);
    }
    copy[5] = resource[5];
    for (i = 0; i < resource[5]; i++)
    {
        if (resource[i + 6] != 0)
        {
            source = FUN_00491cc0(resource[i + 6]);
            copy[i + 6] = source;
            copy[i + 0x26] = FUN_001a7570(source);
        }
    }
    copy[0x46] = resource[0x46];
    for (i = 0; i < resource[0x46]; i++)
    {
        for (j = 0; j < 6; j++)
        {
            copy[i * 6 + 0x47 + j] = resource[i * 6 + 0x47 + j];
        }
        type = (s16)resource[i * 6 + 0x47];
        if ((type == 0) || (type == 2))
        {
            copy[i * 6 + 0x4a] = FUN_00317450(resource[i * 6 + 0x4a]);
        }
        else if (type == 1)
        {
            copy[i * 6 + 0x4b] = FUN_0034fd50(resource[i * 6 + 0x4b]);
        }
    }
    copy[0x288] = resource[0x288];
    copy[0x289] = resource[0x289];
    copy[0x28a] = resource[0x28a];
    FUN_001b5200((u32)((f32)direction * 90.0f), copy);
    FUN_001b4e00((u32)((f32)direction * 90.0f), copy, (const f32*)position);
    return copy;
}

// FUN_001b5610
void FUN_001b5610(u32* resource, const f32* color)
{
    u32 i;
    u32 count;
    s32 node;
    u32 model;

    node = FUN_003b5d50(10);
    if ((*resource & 1) != 0)
    {
        FUN_001b60d0(resource[2], color);
    }
    for (i = 0; i < resource[5]; i++)
    {
        FUN_001b60a0(*(u32*)((u8*)resource + i * 4 + 0x18), color);
    }
    (void)count;
    while (node != 0)
    {
        model = FUN_00318b80(*(u32*)(node + 0x104));
        FUN_001b60a0(model, color);
        node = *(s32*)(node + 0xf8);
    }
}

// FUN_001b56f0 NONMATCHING
void FUN_001b56f0(u32* resource, const f32* color)
{
    u32 i;
    s32 node;
    u8 rgba[4];
    const f32* values;
    u32 model;

    node = FUN_003b5d50(10);
    if ((*resource & 1) != 0)
    {
        FUN_001b5e60(resource[2], color);
    }
    for (i = 0; i < resource[5]; i++)
    {
        FUN_001b5e30(resource[i + 6], color);
    }
    values = color;
    rgba[0] = (u8)(values[0] * 255.0f + 0.5f);
    rgba[1] = (u8)(values[1] * 255.0f + 0.5f);
    rgba[2] = (u8)(values[2] * 255.0f + 0.5f);
    rgba[3] = (u8)(values[3] * 255.0f + 0.5f);
    while (node != 0)
    {
        model = *(u32*)(node + 0x104);
        FUN_00318ad0(model, rgba);
        node = *(s32*)(node + 0xf8);
    }
}
// FUN_001b5950
void FUN_001b5950(u32 task, u32 value)
{
    u32 work;

    work = *(u32*)(task + 0x3c);
    *(u32*)(work + 4) = value;
    FUN_001d50c0(value, *(u32*)(work + 8), *(u32*)(work + 0x10));
}

// FUN_001b5990
void FUN_001b5990(u32 task, u32 value)
{
    u32 work;

    work = *(u32*)(task + 0x3c);
    *(u32*)(work + 8) = value;
    FUN_001d50c0(*(u32*)(work + 4), value, *(u32*)(work + 0x10));
}

// FUN_001b59c0
void FUN_001b59c0(u32 task, u32 value)
{
    u32 work;

    work = *(u32*)(task + 0x3c);
    *(u32*)(work + 0x10) = value;
    FUN_001d50c0(*(u32*)(work + 4), *(u32*)(work + 8), value);
}

// FUN_001b5a00
void FUN_001b5a00(u32 task, u32 value)
{
    u32 work;

    work = *(u32*)(task + 0x3c);
    *(u32*)(work + 0x0c) = value;
    FUN_001d5130(value);
}

// FUN_001b5a30
void FUN_001b5a30(u8* color)
{
    u32 value;
    u32 packed;

    if (FUN_001a64f0((u32)color, D_00678F90) == 0)
    {
        packed = (u32)color[7] << 24 |
                 (u32)color[4] << 16 |
                 (u32)color[5] << 8 |
                 (u32)color[6];
        value = FUN_0048ee70((u32)color, D_00678F90, 1, 1);
        value = FUN_0048eed0((u32)color, value);
        FUN_0048efa0(value, 0, packed);
    }
}

// FUN_001b5ae0
void FUN_001b5ae0(u32 value, const u8* rgba)
{
    u32 target;
    u32 color;
    u32 packed;

    target = FUN_001a6350(value, D_00678F90);
    color = (u32)rgba[3] << 24;
    color |= (u32)rgba[0] << 16;
    packed = ((u32)rgba[1] << 8) | color;
    FUN_0048efa0(target, 0, (u32)rgba[2] | packed);
}

// FUN_001b5b50 MATCHING
void* FUN_001b5b50(void* color, const f32* scale)
{
    u32 mode;
    volatile u8 rgba[4];
    u32 value;
    u32 packed;
    u32 r;
    u32 g;
    u32 b;
    u32 a;
    u8 out0;
    u8 out1;
    u8 out2;
    u8 out3;

    if (FUN_001a64f0((u32)color, D_00678F90) == 0)
    {
        packed = (u32)((u8*)color)[7] << 24 |
                 (u32)((u8*)color)[4] << 16 |
                 (u32)((u8*)color)[5] << 8 |
                 (u32)((u8*)color)[6];
        value = FUN_0048ee70((u32)color, D_00678F90, 1, 1);
        value = FUN_0048eed0((u32)color, value);
        FUN_0048efa0(value, 0, packed);
    }
    mode = FUN_001a64f0((u32)color, D_00678F90);
    if (mode == 1)
    {
        value = FUN_001a6400((u32)color, D_00678F90);
        r = (s32)((f32)((value >> 16) & 0xff) * scale[0]);
        g = (s32)((f32)((value >> 8) & 0xff) * scale[1]);
        b = (s32)((f32)(value & 0xff) * scale[2]);
        a = (s32)((f32)((value >> 24) & 0xff) * scale[3]);
        if (r > 0xff) r = 0xff;
        rgba[0] = (u8)r;
        if (g > 0xff) g = 0xff;
        rgba[1] = (u8)g;
        if (b > 0xff) b = 0xff;
        rgba[2] = (u8)b;
        if (a > 0xff) a = 0xff;
        rgba[3] = (u8)a;
        out0 = rgba[0];
        out1 = rgba[1];
        out2 = rgba[2];
        out3 = rgba[3];
        ((u8*)color)[4] = out0;
        ((u8*)color)[5] = out1;
        ((u8*)color)[6] = out2;
        ((u8*)color)[7] = out3;
    }
    return color;
}

// FUN_001b5df0
void* FUN_001b5df0(void* color, const void* scale)
{
    FUN_004932c0(*(u32*)((u8*)color + 0x18), (void (*)())FUN_001b5b50, (u32)scale);
    return color;
}

// FUN_001b5e30
void FUN_001b5e30(u32 color, const void* scale)
{
    FUN_004916d0(color, (void (*)())FUN_001b5df0, (u32)scale);
}

// FUN_001b5e60
void FUN_001b5e60(u32 color, const void* scale)
{
    FUN_0049a7c0(color, (void (*)())FUN_001b5b50, (u32)scale);
}

// FUN_001b5e90 NONMATCHING
void* FUN_001b5e90(void* value, const f32* scale)
{
    u32 target;
    f32* base;
    f32 out[3];

    if (FUN_001a64f0((u32)value, 0x678fb0) == 0)
    {
        target = FUN_0048ee70((u32)value, 0x678fb0, 2, 3);
        target = FUN_0048eed0((u32)value, target);
        FUN_0048efc0(target, 0, *(f32*)((u8*)value + 0x0c));
        FUN_0048efc0(target, 1, *(f32*)((u8*)value + 0x10));
        FUN_0048efc0(target, 2, *(f32*)((u8*)value + 0x14));
    }
    target = FUN_001a6350((u32)value, 0x678fb0);
    if (target != 0)
    {
        out[0] = FUN_0048ef60(target, 0) * scale[0];
        out[1] = FUN_0048ef60(target, 1) * scale[1];
        out[2] = FUN_0048ef60(target, 2) * scale[2];
        if (out[0] > 1.0f) out[0] = 1.0f;
        if (out[1] > 1.0f) out[1] = 1.0f;
        if (out[2] > 1.0f) out[2] = 1.0f;
        base = (f32*)((u8*)value + 0x0c);
        base[0] = out[0];
        base[1] = out[1];
        base[2] = out[2];
    }
    return value;
}

// FUN_001b6060
void* FUN_001b6060(void* value, const void* scale)
{
    FUN_004932c0(*(u32*)((u8*)value + 0x18), (void (*)())FUN_001b5e90, (u32)scale);
    return value;
}

// FUN_001b60a0
void FUN_001b60a0(u32 value, const void* scale)
{
    FUN_004916d0(value, (void (*)())FUN_001b6060, (u32)scale);
}

// FUN_001b60d0
void FUN_001b60d0(u32 value, const void* scale)
{
    FUN_0049a7c0(value, (void (*)())FUN_001b5e90, (u32)scale);
}
#pragma push
#pragma opt_rebuildconditionals off
// FUN_001b6100
u32 FUN_001b6100(u32 id)
{
    char path[128];
    u32 value;
    s32 current;

    if (*PTR_DAT_007cd540 == 0xffffffff)
    {
        return 0;
    }
    if (K_Fldrc_GetFldPacCdvd() != NULL)
    {
        goto have_pac;
    }
    FUN_00523ac8(path, D_00678FD0, *PTR_DAT_007cd540, id);
    current = (s32)*PTR_DAT_007cd540;
    if (current < 0x33)
    {
        goto archive_ready;
    }
    if (current >= 0x3b)
    {
        goto archive_ready;
    }
    FUN_00523ac8(path, D_00678FD0, current - 0x1e, 0);
archive_ready:
    if (FUN_001008b0(path) == 0)
    {
        value = 0;
        goto done;
    }
    value = FUN_00100d80(path, 0);
    goto done;
have_pac:
    value = 1;
done:
    return value;
}
#pragma pop

static void fldrc_copy_words(u32 dst, u32 src, u32 count)
{
    u32 i;
    for (i = 0; i < count; i++)
    {
        *(u32*)(dst + i * 4) = *(u32*)(src + i * 4);
    }
}

static inline void fldrc_apply_field_config(u32 config)
{
    u32* dst;
    u32 listA;
    u32 listB;
    u32 node;
    u32 i;
    u32 count;
    u32 version;
    f32 farPlane;
    u32* field;

    listA = FUN_003b5d50(4);
    listB = FUN_003b5d50(5);
    FUN_0019fdd0(*(u8*)(config + 8));
    FUN_0019fe20(*(u8*)(config + 9));
    FUN_0019fe70(*(u8*)(config + 10));
    FUN_0019fec0(*(u8*)(config + 0x0b));
    if (*(u8*)(config + 0x0f) == 1)
    {
        DAT_007ce0d4 = 1;
    }
    else
    {
        DAT_007ce0d4 = 0;
    }
    DAT_007ce0d8 = *(u8*)(config + 0x0c);
    DAT_007ce0dc = *(u8*)(config + 0x0d);
    DAT_007ce0e0 = *(u8*)(config + 0x0e);
    DAT_007ce0e4 = 0;
    DAT_007ce0e8 = DAT_007ce0d8;
    DAT_007ce0ec = DAT_007ce0dc;
    DAT_007ce0f0 = DAT_007ce0e0;
    DAT_007ce0f4 = 0;
    FUN_001985b0(DAT_007ce0d8, DAT_007ce0dc, DAT_007ce0e0, 0);
    FUN_001985e0(DAT_007ce0d8, DAT_007ce0dc, DAT_007ce0e0, 0);
    FUN_004c9db0(FUN_00198590(), *(f32*)(config + 0x14));
    *(f32*)(FUN_00198590() + 0x88) = *(f32*)(config + 0x10);
    FUN_00198590();

    version = *(u32*)(config + 4);
    if (version > 0x10003)
    {
        farPlane = *(f32*)(config + 0x18);
        if (farPlane > 1.0f)
        {
            FUN_004c9d70(FUN_00198590(), farPlane);
        }
        if (farPlane == 50.0f)
        {
            FUN_004c9d70(FUN_00198590(), 100.0f);
        }
        if (*(s8*)(config + 0x1ff) == -1)
        {
            FUN_001985b0(*(u8*)(config + 0x1fc),
                         *(u8*)(config + 0x1fd),
                         *(u8*)(config + 0x1fe), 0);
            FUN_001985e0(*(u8*)(config + 0x1fc),
                         *(u8*)(config + 0x1fd),
                         *(u8*)(config + 0x1fe), 0);
        }
    }

    dst = (u32*)FUN_0019fd40();
    ((f32*)dst)[0] = *(f32*)(config + 0x1c);
    ((f32*)dst)[1] = *(f32*)(config + 0x20);
    ((f32*)dst)[2] = *(f32*)(config + 0x24);
    ((f32*)dst)[3] = *(f32*)(config + 0x28);
    dst = (u32*)FUN_0019fd70();
    ((f32*)dst)[0] = *(f32*)(config + 0x2c);
    ((f32*)dst)[1] = *(f32*)(config + 0x30);
    ((f32*)dst)[2] = *(f32*)(config + 0x34);
    ((f32*)dst)[3] = *(f32*)(config + 0x38);
    dst = (u32*)FUN_0019fda0();
    {
        u32* src = (u32*)(config + 0x40);
        u32 n = 8;
        while (n > 0)
        {
            dst[0] = src[0];
            dst[1] = src[1];
            src += 2;
            dst += 2;
            n--;
        }
    }

    if (listB != 0)
    {
        ((f32*)(listB + 0x100))[0] = *(f32*)(config + 0x80);
        ((f32*)(listB + 0x100))[1] = *(f32*)(config + 0x84);
        ((f32*)(listB + 0x100))[2] = *(f32*)(config + 0x88);
        ((f32*)(listB + 0x100))[3] = *(f32*)(config + 0x8c);
        ((f32*)(listB + 0x110))[0] = *(f32*)(config + 0x90);
        ((f32*)(listB + 0x110))[1] = *(f32*)(config + 0x94);
        ((f32*)(listB + 0x110))[2] = *(f32*)(config + 0x98);
        ((f32*)(listB + 0x110))[3] = *(f32*)(config + 0x9c);
        {
            u32* src = (u32*)(config + 0xa0);
            u32* out = (u32*)(listB + 0x120);
            u32 n = 8;
            while (n > 0)
            {
                out[0] = src[0];
                out[1] = src[1];
                src += 2;
                out += 2;
                n--;
            }
        }
        ((f32*)(listB + 0x160))[0] = *(f32*)(config + 0xe0);
        ((f32*)(listB + 0x160))[1] = *(f32*)(config + 0xe4);
        ((f32*)(listB + 0x160))[2] = *(f32*)(config + 0xe8);
        ((f32*)(listB + 0x160))[3] = *(f32*)(config + 0xec);
        {
            u32* src = (u32*)(config + 0xf0);
            u32* out = (u32*)(listB + 0x170);
            u32 n = 8;
            while (n > 0)
            {
                out[0] = src[0];
                out[1] = src[1];
                src += 2;
                out += 2;
                n--;
            }
        }
    }

    if (version > 0x10000)
    {
        count = *(u32*)((u8*)K_Field_Get() + 0x1168);
        K_Field_Get_A();
        for (i = 0; i < count; i++)
        {
            node = *(u32*)((u8*)K_Field_Get() + 0x116c + i * 4);
            ((u32*)node)[0xa20 / 4] = ((u32*)config)[0x130 / 4];
            ((u32*)node)[0xa24 / 4] = ((u32*)config)[0x134 / 4];
            ((u32*)node)[0xa28 / 4] = ((u32*)config)[0x138 / 4];
            FUN_001b5610((u32*)node, (const f32*)(node + 0xa20));
        }
    }

    if ((version > 0x10001) && (listA != 0))
    {
        ((u32*)listA)[0x100 / 4] = ((u32*)config)[0x13c / 4];
        ((u32*)listA)[0x104 / 4] = ((u32*)config)[0x140 / 4];
        ((u32*)listA)[0x108 / 4] = ((u32*)config)[0x144 / 4];
        ((u32*)listA)[0x10c / 4] = ((u32*)config)[0x148 / 4];
        ((u32*)listA)[0x110 / 4] = ((u32*)config)[0x14c / 4];
        ((u32*)listA)[0x114 / 4] = ((u32*)config)[0x150 / 4];
        ((u32*)listA)[0x118 / 4] = ((u32*)config)[0x154 / 4];
        ((u32*)listA)[0x11c / 4] = ((u32*)config)[0x158 / 4];
        for (i = 0; i < 8; i++)
        {
            ((u32*)listA)[0x120 / 4 + i * 2] =
                ((u32*)config)[0x160 / 4 + i * 2];
            ((u32*)listA)[0x124 / 4 + i * 2] =
                ((u32*)config)[0x164 / 4 + i * 2];
        }
        ((u32*)listA)[0x160 / 4] = ((u32*)config)[0x1a0 / 4];
        ((u32*)listA)[0x164 / 4] = ((u32*)config)[0x1a4 / 4];
        ((u32*)listA)[0x168 / 4] = ((u32*)config)[0x1a8 / 4];
        ((u32*)listA)[0x16c / 4] = ((u32*)config)[0x1ac / 4];
        for (i = 0; i < 8; i++)
        {
            ((u32*)listA)[0x170 / 4 + i * 2] =
                ((u32*)config)[0x1b0 / 4 + i * 2];
            ((u32*)listA)[0x174 / 4 + i * 2] =
                ((u32*)config)[0x1b4 / 4 + i * 2];
        }
    }

    if (version > 0x10002)
    {
        listA = FUN_003b5d50(1);
        listB = FUN_003b5d50(3);
        count = *(u32*)((u8*)K_Field_Get() + 0x1168);
        K_Field_Get_A();
        for (i = 0; i < count; i++)
        {
            node = *(u32*)((u8*)K_Field_Get() + 0x116c + i * 4);
            ((u32*)node)[0xa2c / 4] = ((u32*)config)[0x1f0 / 4];
            ((u32*)node)[0xa30 / 4] = ((u32*)config)[0x1f4 / 4];
            ((u32*)node)[0xa34 / 4] = ((u32*)config)[0x1f8 / 4];
        }
        while (listA != 0)
        {
            u32 model = FUN_00318b80(*(u32*)(listA + 0x128));
            FUN_004916d0(model, 0x1b6060, config + 0x1f0);
            listA = *(u32*)(listA + 0xf8);
        }
        while (listB != 0)
        {
            u32 model = FUN_00318b80(*(u32*)(listB + 0x128));
            FUN_004916d0(model, 0x1b6060, config + 0x1f0);
            listB = *(u32*)(listB + 0xf8);
        }
    }
    if (version < 0x10004)
    {
        FUN_001a1540(0, 0, 0x178, 0x678ff0);
    }
}

#pragma push
#pragma opt_loop_invariants on
// FUN_001b61f0 NONMATCHING
u32 FUN_001b61f0(void* resource, u32 archiveEntry)
{
    char path[76];
    u32 config;
    s32 current;

    if (resource == NULL)
    {
        return 1;
    }
    if (K_Fldrc_GetFldPacCdvd() == NULL)
    {
        config = FUN_001016b0((u32)resource);
        if (config == 0)
        {
            return 0;
        }
        config = *(u32*)((u8*)resource + 0x110);
        fldrc_apply_field_config(config);
        FUN_00100ec0((u32)resource);
        return 1;
    }

    FUN_00523ac8(path, 0x679010, *PTR_DAT_007cd540, archiveEntry);
    current = (s32)*PTR_DAT_007cd540;
    if ((current > 0x32) && (current < 0x3b))
    {
        FUN_00523ac8(path, 0x679010, current - 0x1e, 0);
    }
    config = FUN_001021c0(path, path);
    if (config != 0)
    {
        fldrc_apply_field_config(config);
    }
    return 1;
}
#pragma opt_loop_invariants off
#pragma pop
static u32 fldrc_event_override(u16 group, u32 id)
{
    if (((group == 6) && ((id == 4) || (id == 5) || (id == 7) || (id == 8) ||
                          (id == 0x15) || (id == 0x16))) ||
        ((group == 7) && ((id == 1) || (id == 3) || (id == 4) || (id == 5) ||
                          (id == 6) || (id == 7) || (id == 0x0e) || (id == 0x0f))) ||
        (group == 8) ||
        ((group == 9) && ((id == 3) || (id == 4) || (id == 5) || (id == 6))) ||
        ((group == 10) && (id == 2)) ||
        ((group == 0x0e) && (id == 2)) ||
        ((group == 0x0f) && (id == 1)) ||
        ((group == 0x10) && ((id == 4) || (id == 5))))
    {
        if ((FUN_0017e480(4, 0x1b, 0x0c, 0x1f) == 1) ||
            (FUN_0017e480(1, 1, 2, 0x1c) == 1))
        {
            return id;
        }
    }
    return 0xffffffff;
}

// FUN_001b6eb0 NONMATCHING
u32 FUN_001b6eb0(u16 group, u32 id)
{
    u8 mode;
    u32 result;
    u32 event;

    id &= 0xffff;
    result = id;
    FUN_0017d920();
    FUN_0017da40();
    mode = (u8)FUN_0016ef30();
    if ((group == 0x0f) && (id == 6))
    {
        return id;
    }
    if ((group == 1) && (mode == 6))
    {
        return 0xc9;
    }
    if (group != 1 &&
        (((group < 0x14 || group > 0x1c) &&
          (group < 0x28 || group > 0x30)) || id < 0x32))
    {
        if ((group == 0x21) && (id == 1) && (mode == 6))
        {
            return 0xc9;
        }
        event = FUN_001a01c0();
        if ((event != 1) && (group < 200))
        {
            /*
             * Retail mode jump table 0x7b6b00.  The case declaration order
             * below follows the retail body order: 0x1b7034, 0x1b73bc,
             * 0x1b7468, 0x1b7484, and 0x1b7490.
             */
            switch (mode)
            {
                /* Retail mode 1-4 body: 0x1b7034-0x1b7138. */
                case 1:
                case 2:
                case 3:
                case 4:
                    if (FUN_0017e480(3, 1, 3, 5) != 1 &&
                        FUN_0017e480(4, 5, 4, 0x1a) != 1 &&
                        FUN_0017e480(4, 0x1b, 9, 0x16) == 1)
                    {
                        result = id + 500;
                        if ((group == 6) && (id == 0x0d))
                        {
                            result = 0x71;
                        }
                    }
                    else if (FUN_0017e480(9, 0x17, 0x0c, 3) == 1)
                    {
                        result = id + 600;
                    }
                    else if ((FUN_0017e480(0x0c, 4, 0x0c, 0x1f) == 1) ||
                             (FUN_0017e480(1, 1, 2, 0x1c) == 1))
                    {
                        result = id + 700;
                    }
                    break;

                /* Retail mode 5 body: 0x1b73bc-0x1b7468. */
                case 5:
                    result = id + 100;
                    if (((group == 7) && (id == 0x0e)) ||
                        ((group == 7) && (id == 0x0f)) ||
                        (group == 8) ||
                        ((group == 9) && (id == 3)) ||
                        ((group == 9) && (id == 4)) ||
                        ((group == 9) && (id == 5)) ||
                        ((group == 9) && (id == 6)))
                    {
                        result = id;
                    }
                    break;

                /* Retail modes 6-7 body: 0x1b7468-0x1b7490. */
                case 6:
                case 7:
                    result = id + 200;
                    if (group == 8)
                    {
                        result = id;
                    }
                    break;

                /* Retail mode 0 body: 0x1b7484-0x1b7490. */
                case 0:
                    result = id + 400;
                    break;

                /* Retail mode 8 body: 0x1b7490-0x1b7494. */
                case 8:
                    result = id + 300;
                    break;

                default:
                    break;
            }

            /*
             * Retail's inlined event override chain occupies 0x1b7154-
             * 0x1b73b0; keep each accessor call at its retail use site.
             */
            if (((group == 6) && (id == 4)) ||
                ((group == 6) && (id == 5)) ||
                ((group == 6) && (id == 7)) ||
                ((group == 6) && (id == 8)) ||
                ((group == 6) && (id == 0x15)) ||
                ((group == 6) && (id == 0x16)) ||
                ((group == 7) && (id == 1)) ||
                ((group == 7) && (id == 3)) ||
                ((group == 7) && ((id == 4) || (id == 5) ||
                                  (id == 6) || (id == 7) || (id == 0x0e) || (id == 0x0f))) ||
                (group == 8) ||
                ((group == 9) && ((id == 3) || (id == 4) || (id == 5) || (id == 6))) ||
                ((group == 10) && (id == 2)) ||
                ((group == 0x0e) && (id == 2)) ||
                ((group == 0x0f) && (id == 1)) ||
                ((group == 0x10) && ((id == 4) || (id == 5))))
            {
                if ((FUN_0017e480(4, 0x1b, 0x0c, 0x1f) == 1) ||
                    (FUN_0017e480(1, 1, 2, 0x1c) == 1))
                {
                    result = id;
                }
            }
            /*
             * Retail post-dispatch overrides: 0x1b74ac-0x1b7570.
             * Preserve the repeated group comparisons that drive layout.
             */
            if (((group == 6) && (id == 0x16)) ||
                ((group == 7) && (id == 0x0a)) ||
                ((group == 7) && (id == 0x0b)) ||
                ((group == 7) && (id == 0x0c)) ||
                ((group == 7) && (id == 0x0d)) ||
                ((group == 8) && (id == 3)) ||
                ((group == 9) && (id == 5)) ||
                ((group == 0x10) && (id == 4)) ||
                ((group == 0x10) && (id == 5)))
            {
                result = id;
            }
            if (group == 4)
            {
                result = id + 200;
                if (FUN_0016f190(0x2d8) != 0)
                {
                    result = id + 300;
                }
            }
            if ((group == 5) || (group == 0x27))
            {
                result = id;
            }
        }
    }
    return result;
}

// FUN_001b75e0 NONMATCHING
u32 FUN_001b75e0(u32 task)
{
    s32* work;

    work = (s32*)*(u32*)(task + 0x3c);
    if (work[0] == 2)
    {
        goto state2;
    }
    if (work[0] == 1)
    {
        goto state1;
    }
    if (work[0] == 0)
    {
        goto state0;
    }
    goto done;
state0:
    if (FUN_001016b0((u32)work[1]) != 0)
    {
        work[2] = (s32)FUN_0035bb40(10, *(u32*)((u8*)work[1] + 0x110), 0);
        work[0] = work[0] + 1;
    }
    goto done;
state1:
    if (FUN_00195460((u32)work[2]) != 1)
    {
        work[0] = work[0] + 1;
    }
    goto done;
state2:
    return 0xffffffff;
done:
    return 0;
}

// FUN_001b76b0
void FUN_001b76b0(u32 task)
{
    FUN_00100ec0(*(u32*)(*(u32*)(task + 0x3c) + 4));
    (*(void (**)(void*))DAT_0096017c_abs)(*(void**)(task + 0x3c));
}

// FUN_001b7700
void* FUN_001b7700(void* parent)
{
    void* task;
    u32 work;

    work = (u32)(*(void* (**)(u32, u32, u32))DAT_00960184_abs)(1, 0x0c, 0x40000);
    if (work == 0)
    {
        return NULL;
    }
    task = (void*)FUN_00194b80((u32)parent, 10, D_00679030_abs,
                               FUN_001b75e0, FUN_001b76b0, work);
    *(u32*)(work + 4) = FUN_00100d80(D_00679040_abs, 0);
    return task;
}

// FUN_001b77b0
void FUN_001b77b0(void* parent, const s16* params)
{
    u32* field;
    u32 task;

    if (((const u16*)params)[0] == 0)
    {
        FUN_0019d3f0(D_00679060, 0x58);
    }
    task = FUN_001ba5f0(0, ((const u16*)params)[0],
                        ((const u16*)params)[1], ((const u16*)params)[2],
                        params[3], params[4], 0, 6, 0x80, 0,
                        -1, -1, -1, -1);
    field = (u32*)FUN_001b9120();
    *field = task;
    (void)parent;
}
// FUN_001b2780
void* FUN_001b2780(s16 majorId, s16 minorId)
{
    char path[40];
    char token[8];

    if (iGpffffb470 == 0)
    {
        FUN_00524270(path, D_00678E08);
    }
    else
    {
        FUN_00524270(path, D_00678E18);
    }
    FUN_00523ac8(token, (const char*)&gp0xffff9538 - 0x6ac8, majorId);
    FUN_00523e68(path, token);
    FUN_00523ac8(token, (const char*)&gp0xffff9540 - 0x6ac0, minorId);
    FUN_00523e68(path, token);
    FUN_00523e68(path, (const char*)&gp0xffff9548 - 0x6ab8);
    return FUN_001b2860(path);
}

// FUN_001b2860 NONMATCHING
void* FUN_001b2860(char* path)
{
    u32 resource;
    u32 payload;
    char* end;
    char digits[4];
    u32 valid;

    resource = (u32)(*DAT_00960184)(1, 0xa4c, 0x40000);
    if (resource == 0)
    {
        return NULL;
    }
    payload = (u32)(*DAT_00960184)(1, 0x124, 0x40000);
    *(u32*)(resource + 0xa40) = payload;
    if (payload == 0)
    {
        (*DAT_0096017c)((void*)resource);
        return NULL;
    }
    FUN_00524270((void*)payload, path);
    end = path;
    while (*end != '\0')
    {
        end++;
    }
    while ((end > path) && (*end != '/'))
    {
        end--;
    }
    valid = 0;
    if (end[1] == 'f')
    {
        valid = ((PTR_DAT_007be9c8[(u8)end[7]] & 4) != 0) &&
                ((PTR_DAT_007be9c8[(u8)end[6]] & 4) != 0) &&
                (end[5] == '_') &&
                ((PTR_DAT_007be9c8[(u8)end[4]] & 4) != 0) &&
                ((PTR_DAT_007be9c8[(u8)end[3]] & 4) != 0) &&
                ((PTR_DAT_007be9c8[(u8)end[2]] & 4) != 0) &&
                ((PTR_DAT_007be9c8[(u8)end[8]] & 4) != 0);
    }
    if (valid != 0)
    {
        digits[0] = end[2];
        digits[1] = end[3];
        digits[2] = end[4];
        digits[3] = 0;
        *(u16*)(resource + 4) = (u16)FUN_0051e0f0(digits);
        digits[0] = end[6];
        digits[1] = end[7];
        digits[2] = end[8];
        digits[3] = 0;
        *(u16*)(resource + 6) = (u16)FUN_0051e0f0(digits);
    }
    else
    {
        *(u16*)(resource + 4) = 0xffff;
        *(u16*)(resource + 6) = 0xffff;
    }
    if (iGpffffb470 == 0)
    {
        *(u32*)(payload + 0x80) = FUN_00100d80(payload, 0);
    }
    else
    {
        *(u32*)(payload + 0x80) = 1;
    }
    return (void*)resource;
}

// FUN_001b2b30
u32 FUN_001b2b30(u32 resource)
{
    u32 payload;

    payload = *(u32*)(resource + 0xa40);
    if (*(u32*)(payload + 0x80) == 0)
    {
        return true;
    }
    if (iGpffffb470 == 0)
    {
        return FUN_001016b0(*(u32*)(payload + 0x80)) != 0;
    }
    return true;
}

// FUN_001b2b90 NONMATCHING
void FUN_001b2b90(u32 resource)
{
    u32 payload;
    u32 metadata;
    u32 stream;
    u32 entry;
    u32 type;
    u32 entryOffset;
    u32* header;
    u32 index;

    payload = *(u32*)(resource + 0xa40);
    metadata = 0;
    stream = FUN_001021c0(payload, &metadata);
    entryOffset = stream;
    if (stream == 0)
    {
        return;
    }
    header = (u32*)FUN_004c58a0(3, 1, &entryOffset);
    if (header == NULL)
    {
        if (payload != 0)
        {
            FUN_00100ec0(*(u32*)(payload + 0x80));
            (*DAT_0096017c)((void*)payload);
        }
        if (resource != 0)
        {
            (*DAT_0096017c)((void*)resource);
        }
        return;
    }
    while (FUN_004c1970((u32)header, &type) != 0)
    {
        if (type == 0x0c)
        {
            *(u32*)(resource + 0xa1c) = FUN_0048d0e0((u32)header);
        }
        else if (type == 0x16)
        {
            entry = FUN_004c8680((u32)header);
            FUN_004d0dc0(entry, 0x1a13b0, payload + 0x120);
            FUN_004d0d10(entry);
        }
        else if (type == 0x23)
        {
            entry = FUN_004bda10((u32)header);
            FUN_004d0dc0(entry, 0x1a13b0, payload + 0x120);
            FUN_004d0d10(entry);
        }
        else if (type == 0x10)
        {
            entryOffset = stream + *(u32*)((u8*)header + 0x0c);
            metadata = 0;
            entry = FUN_004c58a0(3, 1, &entryOffset);
            index = *(u32*)(payload + 0x98);
            *(u32*)(payload + index * 4 + 0x9c) =
                FUN_0010c1a0(2, 0, 0, 0, entry, 0, 0, 0);
            FUN_004c5620((u32)header, &metadata);
            *(u32*)(payload + 0x98) = index + 1;
        }
        else if (type == 0x0b)
        {
            index = *(u32*)(payload + 0x8c);
            entryOffset = stream + *(u32*)((u8*)header + 0x0c);
            if (*(u32*)(payload + index * 4 + 0x90) != 0)
            {
                entryOffset = stream;
            }
            metadata = 0;
            entry = FUN_004c58a0(3, 1, &entryOffset);
            *(u32*)(payload + index * 4 + 0x90) =
                FUN_0010c1a0(1, 0, 0, 0, entry, 0, 0, 0);
            FUN_004c5620((u32)header, &metadata);
            *(u32*)(payload + 0x8c) = index + 1;
        }
        else
        {
            FUN_004c5620((u32)header, &metadata);
        }
    }
    if (header != NULL)
    {
        FUN_004c5780((u32)header, 0);
    }
}
// FUN_001b2f00 NONMATCHING
u32 FUN_001b2f00(u32* resource)
{
    u32 payload;
    u32 i;
    u32 pending;
    u32 object;
    u32 loaded;
    u32 tagged;
    u32 state;
    u32 kind;
    u32 result;

    pending = 0;
    payload = resource[0x290];
    if (payload == 0)
    {
        return 1;
    }
    if (*(u32*)(payload + 0x84) != 0)
    {
        if (*(u32*)(payload + 0x120) != 0)
        {
            FUN_0019d3f0(0x678df8, 0x534);
        }
        state = 0;
        kind = 0;
        object = FUN_0010c3a0(payload, &state, &kind);
        if (state == 1)
        {
            FUN_004d0dc0(object, 0x1a13b0, payload + 0x120);
            FUN_004d0d10(object);
            *(u32*)(payload + 0x84) = 0;
            if (kind != 0)
            {
                FUN_004c5780(kind, 0);
            }
        }
        else
        {
            pending = 1;
        }
    }
    for (i = 0; i < *(u32*)(payload + 0x8c); i++)
    {
        object = *(u32*)(payload + i * 4 + 0x90);
        if (object == 0)
        {
            continue;
        }
        state = 0;
        kind = 0;
        loaded = FUN_0010c3a0(object, &state, &kind);
        if (state == 1)
        {
            if (loaded == 0)
            {
                FUN_0019d3f0(0x678df8, 0x550);
            }
            tagged = FUN_001a6740(loaded, 0x678e30);
            if (tagged == 0)
            {
                if (resource[3] == 0)
                {
                    resource[3] = loaded;
                    FUN_004bcbf0(loaded, FUN_00198590());
                }
                else
                {
                    resource[2] = loaded;
                }
            }
            else
            {
                resource[4] = loaded;
            }
            *(u32*)(payload + i * 4 + 0x90) = 0;
            resource[0] |= 1;
            if (kind != 0)
            {
                FUN_004c5780(kind, 0);
            }
        }
        else
        {
            pending++;
        }
    }
    for (i = 0; i < *(u32*)(payload + 0x98); i++)
    {
        object = *(u32*)(payload + i * 4 + 0x9c);
        if (object == 0)
        {
            continue;
        }
        state = 0;
        kind = 0;
        loaded = FUN_0010c3a0(object, &state, &kind);
        if (state == 1)
        {
            if (loaded == 0)
            {
                FUN_0019d3f0(0x678df8, 0x571);
            }
            tagged = FUN_001a66f0(loaded, 0x678e30);
            if (tagged == 0)
            {
                if (((resource[0] & 1) == 0) && (resource[2] == 0))
                {
                    resource[2] = loaded;
                    resource[3] = FUN_001a7570(loaded);
                }
                else
                {
                    resource[resource[5] + 6] = loaded;
                    resource[resource[5] + 0x26] = FUN_001a7570(loaded);
                    resource[5]++;
                }
            }
            else
            {
                resource[4] = loaded;
            }
            *(u32*)(payload + i * 4 + 0x9c) = 0;
            if (kind != 0)
            {
                FUN_004c5780(kind, 0);
            }
        }
        else
        {
            pending++;
        }
    }
    *(u32*)(payload + 0x11c) = 0;
    if (pending != 0)
    {
        return 0;
    }
    if (resource[2] == 0)
    {
        resource[0] |= 0x20000000;
        resource[2] = resource[3];
    }
    if (((resource[0] & 1) == 0) && (resource[5] == 0))
    {
        resource[0] |= 0x20000000;
    }
    if (iGpffffb470 == 0)
    {
        FUN_00100ec0(*(u32*)(payload + 0x80));
    }
    resource[0x288] = 0x3f800000;
    resource[0x289] = 0x3f800000;
    resource[0x28a] = 0x3f800000;
    result = 1;
    return result;
}

// FUN_001b32f0
u32 FUN_001b32f0(void* resource, u32 wanted, u32* hasOverlay)
{
    u32 outer;
    s32 inner;
    s32 count;
    u32 result;
    u32 type[2];
    u32 match[2];
    u32 found[2];

    result = 0;
    outer = 0;
    goto outer_check;
outer_body:
    {
        u8* entry = (u8*)resource + outer * 4;
        count = FUN_001a6c00(*(u32*)(entry + 0x18), D_00678E50_abs);
        inner = 0;
        goto inner_check;
inner_body:
        FUN_001a6e90(match, *(u32*)(entry + 0x18), D_00678E70_abs, inner);
        if (match[0] == 0)
        {
            K_Assert(D_00678DF8_abs, 0x5d2);
        }
        FUN_001a6e90(type, *(u32*)(entry + 0x18), D_00678E50_abs, inner);
        FUN_001a6e90(found, *(u32*)(entry + 0x18), D_00678E90_abs, inner);
        if (found[0] != 0)
        {
            *hasOverlay = 1;
        }
        else
        {
            *hasOverlay = 0;
        }
        if (type[0] == 1)
        {
            goto inner_increment;
        }
        if (wanted != match[0])
        {
            goto inner_increment;
        }
        result = type[1];
        goto done;
inner_increment:
        inner++;
inner_check:
        if (inner < count)
        {
            goto inner_body;
        }
        outer++;
outer_check:
        if (outer < *(u32*)((u8*)resource + 0x14))
        {
            goto outer_body;
        }
    }
done:
    return result;
}
#pragma push
#pragma opt_loop_invariants on
// FUN_001b3480 NONMATCHING
void FUN_001b3480(u32 resource)
{
    u32 group;
    u32 entry;
    u32 count;
    u32 i;
    u32 query[16];
    u32 active;
    u32 id;
    u32 overlay;
    u32 mode;
    u32 flags;
    u32 record;
    u32 metadata;
    u32 stream;
    char path[256];
    char token[64];
    u32 fieldId;

    for (group = 0; group < *(u32*)(resource + 0x14); group++)
    {
        entry = resource + group * 4;
        count = FUN_001a6c00(*(u32*)(entry + 0x18), 0x678e50);
        for (i = 0; i < count; i++)
        {
            FUN_001a6e90(&query[0], *(u32*)(entry + 0x18), 0x678eb0, i);
            active = query[0];
            if (active == 0)
            {
                continue;
            }
            FUN_001a6e90(&query[1], *(u32*)(entry + 0x18), 0x678e70, i);
            id = query[1];
            if (id == 0)
            {
                FUN_0019d3f0(0x678df8, 0x60a);
            }
            record = resource + *(u32*)(resource + 0x118) * 0x18;
            *(u16*)(record + 0x20) = (u16)id;
            FUN_001a6e90(&query[2], *(u32*)(entry + 0x18), 0x678e90, i);
            overlay = query[2];
            if (overlay != 0)
            {
                *(u16*)(record + 0x1e) = 2;
            }
            FUN_001a6e90(&query[3], *(u32*)(entry + 0x18), 0x678e50, i);
            mode = query[3];
            if (mode == 0)
            {
                if (iGpffffb470 == 0)
                {
                    FUN_00524270(path, 0x678ec8);
                    FUN_00523ac8(token, &gp0xffff9550,
                                 *(u16*)(resource + 4));
                    FUN_00523e68(path, token);
                    FUN_00523ac8(token, 0x678ed8, id);
                    FUN_00523e68(path, token);
                    *(u32*)(record + 0x28) =
                        FUN_00316b40(4, (u16)id, path, 0);
                }
                else
                {
                    FUN_00524270(path, 0x678ee8);
                    FUN_00523ac8(token, &gp0xffff9550,
                                 *(u16*)(resource + 4));
                    FUN_00523e68(path, token);
                    FUN_00523ac8(token, 0x678ed8, id);
                    FUN_00523e68(path, token);
                    metadata = 0;
                    stream = FUN_001021c0(path, &metadata);
                    *(u32*)(record + 0x28) =
                        FUN_00316bd0(4, (u16)id, stream, metadata, 0);
                }
            }
            else if (mode == 1)
            {
                if (iGpffffb470 == 0)
                {
                    FUN_00524270(path, 0x678ef8);
                    FUN_00523ac8(token, &gp0xffff9550,
                                 *(u16*)(resource + 4));
                    FUN_00523e68(path, token);
                    FUN_00523ac8(token, 0x678f08, id);
                    FUN_00523e68(path, token);
                    *(u32*)(record + 0x30) = FUN_00100d80(path, 0);
                    if (*(u32*)(record + 0x30) == 0)
                    {
                        FUN_0019d3f0(0x678df8, 0x650);
                    }
                }
                else
                {
                    FUN_00524270(path, 0x678f18);
                    FUN_00523ac8(token, &gp0xffff9550,
                                 *(u16*)(resource + 4));
                    FUN_00523e68(path, token);
                    FUN_00523ac8(token, 0x678f08, id);
                    FUN_00523e68(path, token);
                    metadata = 0;
                    *(u32*)(record + 0x30) = FUN_001021c0(path, &metadata);
                }
            }
            else if (mode == 2)
            {
                FUN_00524270(path, 0x678f30);
                FUN_00523ac8(token, 0x678ed8, id);
                FUN_00523e68(path, token);
                fieldId = (id + 1000) & 0xffff;
                *(u32*)(record + 0x28) =
                    FUN_00316b40(4, fieldId, path, 0);
            }
            FUN_001a6e90(&query[4], *(u32*)(entry + 0x18), 0x678f40, i);
            flags = query[4];
            if (mode == 0)
            {
                *(u16*)(record + 0x1e) |= (u16)flags;
            }
            *(u32*)(record + 4) = 0;
            *(u32*)(resource + 0x118) += 1;
        }
    }
}
#pragma opt_loop_invariants off
#pragma pop
// FUN_001b39e0 NONMATCHING
u32 FUN_001b39e0(u32 resource)
{
    s32 firstIndex;
    s32 secondIndex;
    u8* record;
    u32 type;
    u32 object;
    u32 matrix;

    firstIndex = 0;
    goto first_check;
first_body:
    record = (u8*)resource + firstIndex * 0x18;
    type = *(u16*)(record + 0x11c);
    if (type == 0)
    {
        object = *(u32*)(record + 0x128);
        if (FUN_00316f70(object) == 0)
        {
            return 0;
        }
        goto first_increment;
    }
    if (type == 2)
    {
        object = *(u32*)(record + 0x128);
        if (FUN_00316f70(object) == 0)
        {
            return 0;
        }
        goto first_increment;
    }
    if (type != 1)
    {
        goto first_increment;
    }
    if (iGpffffb470 != 0)
    {
        goto first_increment;
    }
    object = *(u32*)(record + 0x130);
    if (object == 0)
    {
        goto first_increment;
    }
    if (FUN_001016b0(object) != 0)
    {
        goto first_increment;
    }
    return 0;
first_increment:
    firstIndex++;
first_check:
    if ((u32)firstIndex < *(u32*)((u8*)resource + 0x118))
    {
        goto first_body;
    }

    secondIndex = 0;
    goto second_check;
second_body:
    record = (u8*)resource + secondIndex * 0x18;
    type = *(u16*)(record + 0x11c);
    if (type == 0)
    {
        goto stream_model;
    }
    if (type == 2)
    {
        goto stream_model;
    }
    if (type != 1)
    {
        goto second_increment;
    }
    if (*(u32*)(record + 0x130) == 0)
    {
        goto second_increment;
    }
    if (iGpffffb470 == 0)
    {
        object = FUN_0034fcd0(*(u32*)(*(u32*)(record + 0x130) + 0x110));
    }
    else
    {
        object = FUN_0034fcd0();
    }
    *(u32*)(record + 0x12c) = object;
    matrix = (u32)FUN_004cb2f0(*(u32*)(record + 0x124));
    FUN_0034fdf0(object, matrix + 0x30);
    if (iGpffffb470 == 0)
    {
        FUN_00100ec0(*(u32*)(record + 0x130));
    }
    *(u32*)(record + 0x130) = 0;
    goto second_increment;
stream_model:
    object = *(u32*)(record + 0x128);
    matrix = (u32)FUN_004cb2f0(*(u32*)(record + 0x124));
    FUN_00318a70(object, matrix, 0);
    FUN_00319230(object, 3);
    if ((*(u16*)(record + 0x11e) & 1) == 0)
    {
        FUN_003182d0(object, 0, 0, 8, 1);
    }
    else
    {
        FUN_003189f0(0, object, 0);
    }
second_increment:
    secondIndex++;
second_check:
    if ((u32)secondIndex < *(u32*)((u8*)resource + 0x118))
    {
        goto second_body;
    }
    if (*(u32*)((u8*)resource + 0xa40) != 0)
    {
        object = *(u32*)((u8*)resource + 0xa40);
        FUN_001a14c0(*(u32*)(object + 0x120));
        (*(void (**)(void*))DAT_0096017c_abs)((void*)object);
        *(u32*)((u8*)resource + 0xa40) = 0;
    }
    return 1;
}

// FUN_001b3c90
void FUN_001b3c90(void* resource)
{
    u32 firstIndex;
    u32 secondIndex;

    if ((*(u32*)resource & 1) != 0)
    {
        if (*(u32*)((u8*)resource + 8) != 0 &&
            *(u32*)((u8*)resource + 8) != *(u32*)((u8*)resource + 0x0c))
        {
            FUN_0049a290(*(u32*)((u8*)resource + 8));
        }
        if (*(u32*)((u8*)resource + 0x0c) != 0)
        {
            FUN_0049a290(*(u32*)((u8*)resource + 0x0c));
        }
        if (*(u32*)((u8*)resource + 0x10) != 0)
        {
            FUN_0049a290(*(u32*)((u8*)resource + 0x10));
        }
    }
    else
    {
        FUN_001a7710(*(u32*)((u8*)resource + 0x0c));
        if (*(u32*)((u8*)resource + 8) != 0)
        {
            FUN_00491ea0(*(u32*)((u8*)resource + 8));
        }
        if (*(u32*)((u8*)resource + 0x10) != 0)
        {
            FUN_00491ea0(*(u32*)((u8*)resource + 0x10));
        }
    }
    for (firstIndex = 0; firstIndex < *(u32*)((u8*)resource + 0x14); firstIndex++)
    {
        FUN_001a7710(*(u32*)((u8*)resource + 0x98 + firstIndex * 4));
        FUN_00491ea0(*(u32*)((u8*)resource + 0x18 + firstIndex * 4));
    }
    for (secondIndex = 0; secondIndex < *(u32*)((u8*)resource + 0x118); secondIndex++)
    {
        u8* record = (u8*)resource + secondIndex * 0x18;
        u16 type = *(u16*)(record + 0x11c);
        if ((type == 0) || (type == 2))
        {
            FUN_003174e0(*(u32*)(record + 0x128));
        }
        else if (type == 1)
        {
            FUN_0034fcf0(*(u32*)(record + 0x12c));
        }
    }
    if (*(u32*)((u8*)resource + 0xa1c) != 0)
    {
        FUN_0048da30(*(u32*)((u8*)resource + 0xa1c));
    }
    if (*(u32*)((u8*)resource + 0xa3c) != 0)
    {
        (*(void (**)(void*))DAT_0096017c_abs)(*(void**)((u8*)resource + 0xa3c));
    }
    (*(void (**)(void*))DAT_0096017c_abs)(resource);
}
static inline void fldrc_render_begin(void)
{
    FUN_00198610(0x40000002, 0);
    FUN_00198610(2, 1);
    (*DAT_00960090)(6, 1);
    (*DAT_00960090)(8, 1);
    if (iGpffffb3e4 == 1)
    {
        (*DAT_00960090)(0x0e);
        (*DAT_00960090)(0x0f,
                        (u32)bGpffffb3f0 |
                        ((u32)bGpffffb3ec << 8) |
                        ((u32)bGpffffb3e8 << 16) |
                        ((u32)bGpffffb3f4 << 24));
        (*DAT_00960090)(0x10, 1);
    }
}

// FUN_001b3e50 NONMATCHING
void FUN_001b3e50(void* camera, u32* resource)
{
    f32 savedLight[4];
    f32 savedFog[4];
    u32 savedStates[16];
    u32* state;
    f32* fstate;
    u32* stateData;
    u32 light;
    u32 value;
    u32 world;
    u32 i;

    FUN_004d7f60(2, 0x44);
    FUN_004d7f60(3, 0x717fb);
    fstate = (f32*)FUN_00198560();
    savedLight[0] = fstate[6];
    savedLight[1] = fstate[7];
    savedLight[2] = fstate[8];
    savedLight[3] = fstate[9];
    fstate = (f32*)FUN_00198570();
    savedFog[0] = fstate[6];
    savedFog[1] = fstate[7];
    savedFog[2] = fstate[8];
    savedFog[3] = fstate[9];
    state = (u32*)FUN_00198570();
    stateData = (u32*)(*(u32*)((u8*)state + 4) + 0x10);
    for (i = 0; i < 8; i++)
    {
        savedStates[i * 2] = stateData[0];
        savedStates[i * 2 + 1] = stateData[1];
        stateData += 2;
    }
    light = FUN_00198560();
    value = FUN_0019fd40();
    FUN_004944b0(light, value);
    light = FUN_00198570();
    value = FUN_0019fd70();
    FUN_004944b0(light, value);
    state = (u32*)FUN_00198570();
    FUN_004cb7f0(*(u32*)((u8*)state + 4), FUN_0019fda0(), 0);
    state = (u32*)FUN_00198570();
    *((u8*)state + 2) = 3;
    FUN_00198570();

    if ((*resource & 1) != 0)
    {
        light = FUN_00198540(uGpffffb3dc);
        FUN_0049c1b0(light, (u32)camera);
        if ((*resource & 0x80000000) == 0)
        {
            if ((*resource & 0x40000000) == 0)
            {
                FUN_0049c160(resource[2], (u32)camera);
            }
            else if (resource[4] != 0)
            {
                FUN_0049c160(resource[4], (u32)camera);
            }
        }
        else
        {
            FUN_0049c160(resource[3], (u32)camera);
        }
        light = FUN_00198540(uGpffffb3dc);
        value = FUN_00198560();
        FUN_0049c480(light, value);
        light = FUN_00198540(uGpffffb3dc);
        value = FUN_00198570();
        FUN_0049c480(light, value);
        if ((*resource & 0x80000000) == 0)
        {
            if ((*resource & 0x40000000) == 0)
            {
                value = FUN_00198560();
                FUN_0049c3d0(resource[2], value);
                value = FUN_00198570();
                FUN_0049c3d0(resource[2], value);
            }
            else
            {
                value = FUN_00198560();
                FUN_0049c3d0(resource[4], value);
                value = FUN_00198570();
                FUN_0049c3d0(resource[4], value);
            }
        }
        else
        {
            value = FUN_00198560();
            FUN_0049c3d0(resource[3], value);
            value = FUN_00198570();
            FUN_0049c3d0(resource[3], value);
        }
    }
    else
    {
        light = FUN_00198540(uGpffffb3dc);
        value = FUN_00198580();
        FUN_0049c3d0(light, value);
    }

    if ((*resource & 1) == 0)
    {
        world = FUN_004c9d10((u32)camera);
        if (world == 0)
        {
            FUN_0019d3f0(0x678df8, 0x7a4);
        }
        else
        {
            fldrc_render_begin();
            if ((*resource & 0x80000000) == 0)
            {
                if ((*resource & 0x40000000) != 0)
                {
                    if (resource[4] != 0)
                    {
                        FUN_001a88e0(resource[4]);
                    }
                }
            }
            else if (resource[3] == 0)
            {
                FUN_001a88e0(resource[2]);
            }
            else
            {
                FUN_001a7b50(resource[3], 1);
            }
        }
    }
    else if (resource[2] != 0)
    {
        world = FUN_004c9d10((u32)camera);
        if (world == 0)
        {
            FUN_0019d3f0(0x678df8, 0x783);
        }
        else
        {
            fldrc_render_begin();
            if ((*resource & 0x80000000) == 0)
            {
                if ((*resource & 0x40000000) == 0)
                {
                    FUN_0049a250(resource[2]);
                }
                else
                {
                    FUN_0049a250(resource[4]);
                }
            }
            else
            {
                FUN_0049a250(resource[3]);
            }
        }
    }
    if ((*resource & 0xc0000000) == 0)
    {
        for (i = 0; i < resource[5]; i++)
        {
            if (resource[i + 0x26] == 0)
            {
                FUN_001a88e0(resource[i + 6]);
            }
            else
            {
                FUN_001a7b50(resource[i + 0x26], 1);
            }
        }
    }
    FUN_004c9d00((u32)camera);
    if ((*resource & 1) == 0)
    {
        light = FUN_00198540(uGpffffb3dc);
        value = FUN_00198580();
        FUN_0049c3d0(light, value);
    }
    else
    {
        if ((*resource & 0x80000000) == 0)
        {
            if ((*resource & 0x40000000) == 0)
            {
                value = FUN_00198560();
                FUN_0049c480(resource[2], value);
                value = FUN_00198570();
                FUN_0049c480(resource[2], value);
            }
            else
            {
                value = FUN_00198560();
                FUN_0049c480(resource[4], value);
                value = FUN_00198570();
                FUN_0049c480(resource[4], value);
            }
        }
        else
        {
            value = FUN_00198560();
            FUN_0049c480(resource[3], value);
            value = FUN_00198570();
            FUN_0049c480(resource[3], value);
        }
        light = FUN_00198540(uGpffffb3dc);
        value = FUN_00198560();
        FUN_0049c3d0(light, value);
        light = FUN_00198540(uGpffffb3dc);
        value = FUN_00198570();
        FUN_0049c3d0(light, value);
        if ((*resource & 0x80000000) == 0)
        {
            if ((*resource & 0x40000000) == 0)
            {
                FUN_0049c1b0(resource[2], (u32)camera);
            }
            else
            {
                FUN_0049c1b0(resource[4], (u32)camera);
            }
        }
        else
        {
            FUN_0049c1b0(resource[3], (u32)camera);
        }
        light = FUN_00198540(uGpffffb3dc);
        FUN_0049c160(light, (u32)camera);
    }
    state = (u32*)FUN_00198560();
    FUN_004944b0(state, savedLight);
    state = (u32*)FUN_00198570();
    FUN_004944b0(state, savedFog);
    state = (u32*)FUN_00198570();
    FUN_004cb7f0(*(u32*)((u8*)state + 4), savedStates, 0);
    state = (u32*)FUN_00198570();
    *((u8*)state + 2) = 3;
    FUN_00198570();
    FUN_00198610(3, 0);
}