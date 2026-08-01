#include "Kosaka/k_sequence.h"
#include "Kosaka/Field/k_dungeon.h"
#include "Kosaka/Field/k_field.h"
#include "Kosaka/k_assert.h"
#include "Kernel/Kwln/kwlnTask.h"

#include "Kosaka/Field/k_fldrc.h"
#include "Kosaka/Field/k_fldFilter.h"
#include "Kosaka/Field/k_sceneDraw.h"
#include "Kosaka/Field/k_fldCamera.h"
#include "Scene/mt_scene.h"
#include "Scene/resrcManager.h"
#include "Graphics/Model/mdlManager.h"
#include "Main/g_data.h"
#include "h_cdvd.h"
#include "temporary.h"
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
#pragma alias DAT_00678f68_abs DAT_00678f68
extern u64 DAT_00678f68_abs[];
#pragma alias DAT_00678f70_abs DAT_00678f70
extern f32 DAT_00678f70_abs[];
extern char D_00678E30[];
typedef struct FldrcColor
{
    f32 value[3];
} __attribute__((packed)) FldrcColor;
#pragma alias DAT_00678f68_color DAT_00678f68
extern FldrcColor DAT_00678f68_color;
#pragma alias FUN_004cb890_typed FUN_004cb890
extern u32 FUN_004cb890_typed(u32 model, void* color, f32 angle, u32 mode);
extern u32 DAT_007ce0d4;
extern u8 DAT_007ce0d8;
extern u8 DAT_007ce0dc;
extern u8 DAT_007ce0e0;
extern u8 DAT_007ce0e4;
extern u8 DAT_007ce0e8;
extern u8 DAT_007ce0ec;
extern u8 DAT_007ce0f0;
extern u8 DAT_007ce0f4;
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
#pragma alias FUN_00318a50_typed FUN_00318a50
extern u32 FUN_00318a50_typed(u32 model, void* color, f32 angle, u32 mode);
#pragma alias FUN_0034fe30_typed FUN_0034fe30
extern u32 FUN_0034fe30_typed(u32 model, f32 x, f32 y, f32 z);
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
extern void FUN_004c31b0(void* matrix, const void* axis, f32 angle, s32 combine);
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
extern u8 D_00678FB0[];
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
typedef struct FldrcCloneRecord
{
    u32 words[6];
} FldrcCloneRecord;




// This field-root task creator has no recovered canonical name; see k_field.c.
KwlnTask* func_001ba5f0(KwlnTask* parentTask, u16 majorId, u16 minorId,
                        u16 fieldParam4, u16 fieldParam5, u16 fieldParam6, u32 flags,
                        u8 fieldParam8, u8 fieldParam9, s16 fieldParam10,
                        s32 eventParam0, s32 eventParam1, s32 eventParam2, s32 eventParam3);

// 28-byte ADMINI_SEQ_FIELD2 payload.  The first 12 bytes are not read by this callback.
typedef struct
{
    u8 unused[0x0c];
    s32 eventParam0; // 0x0c
    s32 eventParam1; // 0x10
    s32 eventParam2; // 0x14
} SeqField2;

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

// FUN_001b7850
s32 K_Seq_ExitField(void)
{
    if (K_Field_Get()->rootTask != NULL)
    {
        kwlnTaskDestroyWithHierarchy(K_Field_Get()->rootTask);

        K_Field_Get()->rootTask = NULL;
    }

    return 0;
}

// FUN_001b78a0
u8 K_Seq_CheckField(void)
{
    if (kwlnTaskExists(K_Field_Get()->rootTask) == true)
    {
        return false;
    }

    K_Field_Get()->rootTask = NULL;

    return true;
}

// FUN_001b7900
void K_Seq_CallField2(u8 isRestored, void* seqData)
{
    SeqField2* fieldData;

    fieldData = (SeqField2*)seqData;
    K_ASSERT(fieldData->eventParam0 != 0, 0x91);

    K_Field_Get()->rootTask = func_001ba5f0(NULL,
                                            0, 0, 0, 0, 0,
                                            0, 0, 0, 0,
                                            fieldData->eventParam0,
                                            fieldData->eventParam1,
                                            fieldData->eventParam2,
                                            0);
}

// FUN_001b79a0
s32 K_Seq_ExitField2(void)
{
    if (K_Field_Get()->rootTask != NULL)
    {
        kwlnTaskDestroyWithHierarchy(K_Field_Get()->rootTask);
        K_Field_Get()->rootTask = NULL;
    }

    return 0;
}

// FUN_001b79f0
u8 K_Seq_CheckField2(void)
{
    if (kwlnTaskExists(K_Field_Get()->rootTask) == true)
    {
        return false;
    }

    K_Field_Get()->rootTask = NULL;
    return true;
}

// FUN_001b7a50
void K_Seq_CallDungeon(u8 isRestored, void* seqData)
{
    SeqDungeon* seq = (SeqDungeon*)seqData;

    gDungeonTask = K_FldDungeon_CreateTask(NULL, seq->floor, seq->unk_04);
}

// FUN_001b7a90
s32 K_Seq_ExitDungeon(void)
{
    if (gDungeonTask != NULL)
    {
        kwlnTaskDestroyWithHierarchy(gDungeonTask);
    }

    return 0;
}

/* K_Field_Get aliases to prevent CSE/write-sinking from folding repeated calls. */

/* Retail field-resource callbacks use fixed-width aliases in the original EE build. */

/* Unrecovered engine entry points are kept typed at the ABI boundary. */













/*
 * Reconstructed field resource selection and FPC registration paths from
 * the retail call/store sequence; duplicated K_Field_Get accesses and the
 * secondary pack path are intentional. Branch/register layout still differs
 * from retail in the large dispatch prologue.
 */
#pragma opt_loop_invariants off
/*
 * Retail keeps the field resource table as direct archive pointers.
 * The initialization phases therefore store and pass those pointers directly,
 * rather than treating each table entry as a wrapper with an a44 member.
 * Archive readiness and destruction are inlined to preserve the retail calls.
 */























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





// FUN_001b7ac0
u8 K_Seq_CheckDungeon(void)
{
    if (kwlnTaskExists(gDungeonTask) == true)
    {
        return false;
    }

    gDungeonTask = NULL;

    return true;
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
#pragma opt_loop_invariants reset
