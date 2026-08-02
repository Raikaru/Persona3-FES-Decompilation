#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Result/br_panel.h"
#include "Main/Battle/Result/br_res.h"
#include "Main/Social/sfl_res.h"
#include "Main/Social/sfl_script.h"
#include "Main/Battle/Data/datPersona.h"
#include "Main/g_data.h"
#include "h_fade.h"
#include "rw/rwcore.h"
#include "rw/rprandom.h"

typedef struct BrRootSetupParams {
    u32 flags;
    struct {
        u16 id;
        u16 pad;
        u32 value;
    } entries[3];
    u32 entryCount;
    u32 field20;
    u16 partyIds[4];
    u32 partyCount;
    u32 field30;
    u32 field34;
    u32 field38;
    u32 field3c;
    u32 field40;
} BrRootSetupParams;
#pragma alias brRewardAdvanceState func_001f6a60
#pragma alias brRewardRegisterEntry func_001f6d20
#pragma alias brRewardAnimateCurrentEntry func_001f6e80
#include "Utils.h"
#include "h_cdvd.h"
#include "Kosaka/Field/k_fieldRuntime.h"
typedef struct Model Model;
#define MDL_READASYNC 0
#define MODEL_TYPE_FLD 4
extern Model* mdlCreateFromPath(u16 type, u16 id, const char* path, u32 readMode);
extern Model* mdlCreateAndResolvePath(u16 type, u16 id, u32 readMode);
typedef struct RuntimeTask RuntimeTask;
typedef struct RuntimeWork RuntimeWork;
typedef struct RuntimeListNode RuntimeListNode;
typedef struct RuntimeVec3
{
    f32 x;
    f32 y;
    f32 z;
} RuntimeVec3;
    typedef struct RuntimeRenderCollection
    {
        u32 flags;
        u8* input;
        u8* entries;
        void** renderObjects;
        u8* commands;
        RuntimeVec3* worldPositions;
    } RuntimeRenderCollection;
struct RuntimeTask
{
    u8 reserved[0x3c];
    RuntimeWork* workData;
};
struct RuntimeWork
{
    u32 flags;
    u32 requestFlags;
    u32 completedFlags;
    u32 state;
    u32 phase;
    u32 selection;
    u32 currentIndex;
    u32 count;
    void* owner;
    void* resource;
    void* renderData;
    void* childTask;
    RuntimeListNode* previous;
    RuntimeListNode* next;
    RuntimeVec3* positions;
    RuntimeVec3* normals;
    u32 slots[1024];
};
typedef struct RuntimeTransitionWork
{
    u32 state;
    void* windowTask;
    u32 flags;
    u32 reserved0c;
    u16 resourceId;
    u8 reserved12[2];
    void* positionTask;
} RuntimeTransitionWork;
typedef struct RuntimeFieldEditorWork
{
    u32 state;
    void* controllerTask;
    void* noticeTask;
    void* menuTask;
    void* choiceTask;
    s32 selection;
} RuntimeFieldEditorWork;
extern void* func_001a3b10(void* parent, u32 width, u32 height, u32 mode);
extern void func_001a3dc0(void* task, const void* descriptors, u32 count);
extern void func_001a3bf0(void* task, u32 request);
extern s32 func_001a4510(void* task);
extern void func_001a3be0(void* task, u32 request);
extern void* func_001a4010(void* task, u32 index);
extern s32 func_00195460(void* task);
extern void FUN_00524270(void* destination, const char* source);
extern s32* func_001a41b0(void* task, u32 id);
extern void* func_004cb2f0(void* frame);
extern void K_Draw_CopyPositionCenter(RuntimeVec3* destination, void* task);
extern void* K_Draw_GetPositionMatrix(void* task);
extern void K_Draw_SetPositionPos(void* task, const RuntimeVec3* position);
extern void K_Draw_MovePositionInDir(f32 distance, void* task,
                                     const RuntimeVec3* direction);
extern void K_Draw_RotatePosition(void* task, const RuntimeVec3* axis,
                                  f32 angle);
extern void* func_001a5000(void* task);
extern u16 DAT_007e094c;
extern u16 DAT_007e094e;
#pragma alias DAT_007e094c_abs DAT_007e094c
#pragma alias DAT_007e094e_abs DAT_007e094e
extern u8 DAT_007e094c_abs[];
extern u8 DAT_007e094e_abs[];
extern u8 DAT_007e095e[];
extern u8 DAT_007e0960[];
extern u16 DAT_007e0952;
#pragma alias DAT_007e0952_abs DAT_007e0952
extern u8 DAT_007e0952_abs[];
extern u8 D_00683E10[];
extern char D_00683F70[];
extern char D_00683F88[];
extern char D_00683F98[];
extern char D_00683FB0[];
extern char D_00683FD0[];
extern char D_007CC2F8;
extern u8 D_007CC378;
extern const char D_00684680[];
extern const char D_006846A0[];
extern char D_007CC2FC;
extern char D_007CC300;
extern char D_007CC304;
extern char D_007CC308;
extern u8 D_00684370[];
extern char D_00684330[];
extern char D_00684380[];
extern void* func_001a4cd0(s32 parent);
extern u32 func_001a3f20(void* task, const char* name);
extern s32 func_00316f70(void* object);
extern void* func_00316e00(u16 majorId, u16 minorId, s32 mode);
extern void* func_00316b40(s32 majorId, s32 minorId, const char* path,
                           s32 mode);
extern u16 func_003b6270(u16 resourceId, u8 type, void* model);
extern void func_001a0dc0(u16 resourceId, s32 enabled);
extern void func_001ad8c0(f32 value, void* controller);
extern void func_001ad870(void* controller, u32 flags);
extern void func_001ad890(void* controller, u32 flags);
extern void func_001ad940(RuntimeVec3* output, void* controller);
extern void func_001addf0(f32 amount, void* controller,
                          const RuntimeVec3* direction);
extern void func_001adff0(f32 amount, void* controller,
                          const RuntimeVec3* direction);
extern void func_001ae0d0(void* controller);
extern void func_0019c320(f32 value, void* controller);
extern s32 func_001a4380(void* task, u32 id);
extern char D_006842D0[];
extern void func_004c2f10(void* matrix);
extern char D_00684120[];
extern char D_00684128[];
extern char D_00684220[];
extern char D_00684270[];
extern char D_00684290[];
extern RuntimeVec3 D_00684260;
typedef struct RuntimeControllerWork RuntimeControllerWork;
struct RuntimeControllerWork
{
    u32 state;
    void* windowTask;
    void* secondaryTask;
    u32 count;
    u16 majorId;
    u16 minorId;
    u16 resourceId;
    u8 type;
    u8 flags;
    f32 angle;
    u32 value;
    u8 sourceType;
    u8 sourceFlags;
    u8 reserved22[2];
    f32 scale;
    void* model;
    void* controller;
};
struct RuntimeListNode
{
    u32 flags;
    RuntimeWork* work;
    void* vertices;
    void* renderObjects;
    u8 reserved[8];
    RuntimeListNode* previous;
    RuntimeListNode* next;
};
typedef struct RuntimeMatrix
{
    f32 values[16];
} RuntimeMatrix;
typedef struct RuntimeTransitionAngles
{
    u8 reserved[0x24];
    RuntimeVec3 value;
} RuntimeTransitionAngles;
typedef struct RuntimeResetWork
{
    u32 flags;
    u32 value;
    u32 completedFlags;
    u32 reserved;
    void* work;
} RuntimeResetWork;
typedef struct RuntimePathWork
{
    u32 flags;
    RuntimeVec3* firstVectors;
    RuntimeVec3* secondVectors;
    RuntimeVec3* thirdVectors;
    RuntimeMatrix* matrix;
    u32 rowCount;
    u32 columnCount;
    u32 reserved;
    u8 color[4];
} RuntimePathWork;
typedef struct RuntimeDistanceWork
{
    void** config;
    u8 reserved04[4];
    s32 count;
    u8 reserved0c[4];
    RuntimeVec3* firstVectors;
    RuntimeVec3* secondVectors;
} RuntimeDistanceWork;
typedef struct RuntimeCommandWork
{
    u32 flags;
    u16* cursor;
    u8 reserved08[8];
    RuntimeWork* target;
    u32 elapsed;
    u16 delay;
    u16 reserved1a;
    u32 duration;
} RuntimeCommandWork;
extern void* DAT_0096017c[];
extern s32* PTR_DAT_007cd540;
extern void func_004c3880(void* matrix);
extern s32 datGetFlag_y2(u32 flag);
extern void* func_001e8e80(RuntimeWork* rawWork, void* material);
extern RuntimeWork* func_001ee2e0(const void* data);
extern RuntimeWork* func_001eeb90(RuntimeWork* input);
extern void func_001eee40(RuntimeWork* work);
extern void func_001eefc0(void* node);
extern void func_00100ec0(void* resource);
extern RuntimeMatrix* func_004c38c0(void);
extern void func_004c31b0(RuntimeMatrix* matrix, const RuntimeVec3* axis,
                          f32 angle, u32 mode);
extern void func_004c6c20(RuntimeVec3* destination,
                          const RuntimeVec3* source, s32 count,
                          RuntimeMatrix* matrix);
extern RuntimeVec3 D_00684400;
extern void func_00318d10(void* context, void* object, RuntimeMatrix* matrix);
extern void func_00492d10(void* manager, void* frame);
extern void func_00491a80(void* manager);
extern void* func_001e1840(void);
extern void FUN_00521250(void* destination, const void* source, u32 size);
extern s32 D_007CE2C0;
s32 func_001ef000(RuntimeListNode* node);
s32 func_001e8330(const RuntimeWork* work, s32 index);
void func_001e7f90(const RuntimeDistanceWork* data, f32 distance,
                   u32* section, f32* fraction);
extern void func_00493230();
void func_001ed0b0(RuntimeWork* work);
void func_001ed080(f32 value, RuntimeWork* work);
void func_001ed0f0(f32 amount, const RuntimeWork* work, s32 channel,
                   u8* output);
void func_001ef340(void* owner);
extern u8* func_001b9120(void);
extern u32 func_001b0910(void);
extern void* func_001016b0(void* resource);
extern void* func_001021c0(const char* path, u32* size);
typedef struct FieldRuntimeResourceNode FieldRuntimeResourceNode;
typedef struct FieldRuntimeTaskNode FieldRuntimeTaskNode;
typedef struct FieldArchiveRequest FieldArchiveRequest;
extern FieldRuntimeTaskNode* func_001e29e0(u32 resourceId);
struct FieldRuntimeResourceNode
{
    void* resource;
    u16 areaId;
    u16 roomId;
    u16 resourceId;
    u8 type;
    u8 flags;
    f32 angle;
    u32 value;
    u8 reserved14[0x0c];
    RuntimeMatrix matrix;
    u8 state;
    u8 sourceType;
    u8 reserved62[2];
    f32 scale;
    FieldRuntimeResourceNode* previous;
    FieldRuntimeResourceNode* next;
};
struct FieldRuntimeTaskNode
{
    void* task;
    u8 reserved04[0x0c];
    RuntimeMatrix matrix;
    u16 resourceId;
    u8 reserved52[2];
    FieldRuntimeTaskNode* previous;
    FieldRuntimeTaskNode* next;
    u8 reserved5c[4];
};
FieldRuntimeResourceNode* func_001e2850(void);
FieldRuntimeTaskNode* func_001e2a20(void);
struct FieldArchiveRequest
{
    u8 reserved0[0x110];
    void* data;
    u8 reserved1[4];
    u32 size;
};
extern void* kwlnTaskCreateWithAutoPriority_y2(void* parent, s32 priority, const char* name, void* update, void* destroy, void* work);
extern void kwlnTaskDestroyWithHierarchy_y2(void* task);
extern HCdvd* K_Fldrc_GetFldPacCdvd(void);
extern char D_00684020[];
extern char D_00684410[];
extern char D_00684470[];
extern char D_00684490[];
extern char D_00684430[];
extern char D_006844B0[];
extern char D_00684060[];
extern char D_00684040[];
extern char D_00684310[];
extern char D_006843A0[];
extern char D_006842A8[];
extern char D_006844D0[];
extern char D_006844F8[];
extern void func_0019d3f0(const char* file, s32 line);
extern f32 func_004c6ac0(RuntimeVec3* vector);
extern void func_004c69f0(RuntimeVec3* output, const RuntimeVec3* input);
extern void func_004c32a0(void* destination, const void* source);
extern void func_004c6be0(RuntimeVec3* destination,
                          const RuntimeVec3* source, void* matrix);
extern f32 D_007CADD4;
extern char D_007CC348;
extern char D_007CC350;
extern u32 D_007CE2C4;
extern u32 D_007CE200;
extern u32 D_007CE244;
extern u8* K_Field_Get(void);
extern u32 D_007CDF38;
extern void FUN_00523ac8(char* destination, const char* format, ...);
extern void FUN_005225a8(const char* format, ...);
extern void* func_004bad50(void* file, const char* path);
extern char D_006843F0[];
extern void* (*DAT_00960184)(u32, ...);
#pragma alias DAT_00960184_abs DAT_00960184
extern void* (*DAT_00960184_abs[])(...);
extern void FUN_00521408(void* destination, s32 value, u32 size);
extern void func_00195770(s32 enabled);
extern void func_001949e0(void);
extern void func_004bf540();
extern void* func_00493710(s32 vertexCount, s32 triangleCount, void* data);
extern void func_00493210(void* geometry, void* triangle, u16 a, u16 b, u16 c);
extern void* func_00491880(void);
extern void func_004919b0(void* manager, void* geometry, s32 index);
extern void func_00493b60(void* geometry);
extern void* func_004ca5b0(void);
extern void func_004ca560(void* dimensions, void* context);
extern void func_004d7f60(s32 index, u32 value);
extern void func_00263db0(void);
extern void func_002737a0(void);
extern void func_004caf80(void* object);
extern void func_00494cc0(void* object);
extern void* func_00494be0(void);
extern void func_00494d50(void* material, void* texture);
extern void* func_004caf10(void);
extern void func_004933d0(void* geometry);
extern void func_00493370(void* renderObject, u32 state);
extern void func_004cb930(void* geometry);
extern void func_004cb7f0(void* geometry, void* matrix, s32 mode);
extern void* func_00318b60(void* owner);
extern char D_00684508[];
extern void* func_00198590(void);
extern void func_004c9d10(void* context);
extern void func_004c9d00(void* context);
extern u16 D_006844E8[];
#define FIELD_RUNTIME_ALLOCATOR (*(void* (**)(u32, ...))0x00960184)
#define FIELD_RUNTIME_PRIMARY_ALLOCATOR (*(void* (**)(u32, u32))0x00960178)
extern void (*DAT_00960094)(s32 state, u32* value);
extern void (*DAT_00960090)(s32 state, u32 value);
extern FieldRuntimeResourceNode* D_007CE2B8;
extern FieldRuntimeTaskNode* D_007CE2BC;
extern void* D_007CE2C8;
extern RuntimeListNode* D_007CE2CC;
extern void* D_007CE2D0;
extern void* D_007CE2D4;
extern char D_00684518[];
extern char D_00684530[];
extern void* func_00100d80(const char* path, s32 mode);
extern void func_001023a0(void* resource);
extern void* func_004d1260(const char* path, s32 mode);
extern void* func_00194e10(const char* name, u32 priority, u32 a, u32 b,
                           void* update, void* destroy, void* work);
s32 func_001ef060();
extern void* func_001b83f0(void);
extern u16* func_001b85a0(u32 index);
extern u16* func_001b8d60(u32 index);
extern void* func_001b8db0(void* record);
extern void func_003b78b0(u16 resourceId, void* position, void* angles);
extern u16 func_003b5e90(u16 resourceId);
extern f32 func_001a5aa0(void* matrix);
extern f32 func_001a5bc0(void* matrix);
extern f32 func_001a5b30(void* matrix);
extern void H_Fade_FadeOut_y2(void);
extern void H_Fade_SetType_y2(s32 type);
extern void func_001e2430(void);
extern void* kwlnGetMainCamera_y2(void);
extern void* func_001e0510(void* task, void* camera);
extern void* func_001e4b40(void* task);
extern void* func_001e5850(void* task);
extern void func_003b7090(u16 resourceId);
extern void func_00195020(void* task);
extern void* func_001e6030(void* task);
extern void func_001a4dc0(void* task, const void* color);
extern void func_001e2a70(FieldRuntimeTaskNode* node, s32 releaseResource);
extern RuntimeVec3 D_006843B0;
extern char D_006843C0[];
extern char D_006843D0[];
extern char D_006843E0[];
extern f32 D_007CB118[];
extern u8 D_007CC338[];
extern u8 D_007CC33C[];
extern void* func_001e6a70(void* task);
extern void func_001e2930(s32 value);
extern void func_001e2b10(s32 value);
extern s32 func_001e2bd0();
extern void func_001e9a90(void* work);
extern s32 func_001ed9e0(void* work);
extern void func_001edbe0(RuntimeRenderCollection* work);
extern void func_001edf10(void* work);
extern void func_001eba50(RuntimeResetWork* work);
extern void func_001eba80(RuntimeCommandWork* work, u32* result);
extern void func_001ebd80(RuntimeWork* work, s32 param2);
extern f32 func_001ecd90(void* data, s32 index, s32 vectorSet);
extern f32 func_001ecec0(void* data, s32 index);
extern s32 func_00236340(void);
extern void func_003c7430_y2(s32 mode);
extern s32 func_003c7850(void);
extern void func_003c7650_y2(s32 mode);
extern void func_003c72d0(void* work);
extern void* func_002345d0(s32 mode);
extern void func_003c7990();
extern void func_003c7c20(s32 group, s32 id, s32 kind);
extern void func_0010a4e0_y2(s32 a0, s32 a1, s32 a2, s32 a3);
extern void H_Snd_PlayBgm(s32 id, s32 restart);
extern void func_0010a370_y2(s32 mode, const char* name);
extern void func_00234070(void);
extern void func_00235010(void);
extern void func_00263170(void);
extern void func_00272810(void);
extern void func_00275bc0(void);
extern void func_00276930(void);
extern void func_002770f0(void);
extern s32 func_001f4910(void* controller);
extern s32 func_00233ad0(void);
extern s32 func_00233bb0(void);
extern void func_001f4930(void* controller);
extern void func_001f1c90(RuntimeTask* task);
extern s32 func_001f4970(void* controller);
extern s32 func_001f30b0_y2(void* controller);
extern void func_001f1aa0(RuntimeTask* task);
extern s32 func_001b07d0(void);
extern void func_001b0840(void);
extern void func_00233c00(void);
extern void func_001f0a60(RuntimeTask* task);
extern void func_001f0ab0(RuntimeTask* task);
extern void func_00108570(void);
extern void func_00108670(s32 mode);
extern void func_001086a0(s32 mode);
extern void func_001f0d70(RuntimeTask* task);
extern s32 func_00233d20(void);
extern void func_002767e0(void);
extern void func_001f10b0(void);
extern void func_001f10f0(void);
extern void func_001f0fd0(RuntimeTask* task);
extern void func_001f0eb0(RuntimeTask* task);
extern void* func_001f1210(RuntimeTask* task);
extern s32 func_001fb1b0(s32 type, u16 id);
extern s32 func_0017d800(void);
extern u32 func_00173220_y2(u16 id);
extern void func_003c7bc0_y2(s32 group, u32 value);
extern void func_00264e30(u16 id);
extern void* func_00264ff0(void);
extern void func_00272400(void* entry);
extern void func_002769c0(void* resource, u16 id);
extern s32 func_00275370(void);
extern void func_00276ba0(void);
extern void func_00276d90(void);
extern void func_001085c0(void);
extern void func_002753c0(void);
extern s32 func_002727c0(void);
extern void func_00277070(void);
extern void func_00264ef0(u16 id);
extern void* iGpffffb6fc;
extern char D_00684578[];
extern char D_00684588[];
extern char D_006845A0[];
extern s32 func_001a0250(void);
extern void func_001a1540(s32 a, s32 b, s32 line, const char* file);
extern void func_003b6870(u16 resourceId, const RuntimeVec3* position,
                          f32 angleX, f32 angleY, f32 angleZ, u32 packed);
extern void func_003b69a0(u16 resourceId, const RuntimeVec3* position,
                          f32 angleX, f32 angleY, f32 angleZ, u32 packed);
extern void func_003b6ad0(u16 resourceId, const RuntimeVec3* position,
                          f32 angle);
extern void func_003b6b90(u16 resourceId, const RuntimeVec3* position,
                          f32 angle);
extern void func_003b6c50(u16 resourceId, const RuntimeVec3* position,
                          f32 angle);
extern void func_003b6d10(u16 resourceId, const RuntimeVec3* position,
                          f32 angle);
extern void func_003b6dd0(u16 resourceId, const RuntimeVec3* position,
                          f32 angle);
extern void func_003b6e90(u16 resourceId, const RuntimeVec3* position,
                          f32 angle);
extern void* func_003b5d10(u16 resourceId);
extern char D_00684450[];
extern s32 func_001ef7f0(RuntimeTask* task);
extern s32 func_001f07a0(RuntimeTask* task);
extern void* func_00194b80(void* parent, s32 priority, const char* name,
                           void* update, void* destroy, void* work);
extern void func_001f0970_y2(RuntimeTask* task);
extern s32 func_001f08c0_y2(RuntimeTask* task);
extern s32 func_001f0900_y2(RuntimeTask* task);
extern s32 func_001f0940_y2(RuntimeTask* task);
extern void func_00195550(void* parent, void* child);
extern void func_001f0ad0_y2(void* task, void* parent);
extern void func_00233970(void* work);
extern void func_00234820(void* work);
extern void func_002626e0(void* work);
extern void brPersonaInit(void* work);
extern void func_00272330(void* work);
extern void func_00275a70(void* work);
extern void func_00276910(void* work);
extern void func_00276d10(void* work);
extern void func_0021eac0_y2(void* object, f32 value);
extern void func_0021d8e0(void* object, const f32* rectangle);
extern void func_0021d950(void* object, const u8* color);
extern void func_002339d0(void);
extern void* func_001f2080_y2(void* work);
extern void func_001f48d0(void* work);
extern char D_00684548[];
extern char D_00684560[];
extern RuntimeWork* D_007CE2D8;
extern u32 D_007CDF0C;
void func_001e88f0(RuntimeWork* work, s32 section, RuntimeVec3* output);

static void Runtime_Clear(RuntimeWork* work, u32 first, u32 count)
{
    u32 i;

    for (i = 0; i < count; i++)
    {
        work->slots[first + i] = 0;
    }
}
static void Runtime_Unlink(RuntimeListNode** head, RuntimeListNode** tail, RuntimeListNode* node)
{
    if (node->next != NULL)
    {
        node->next->previous = node->previous;
    }
    if (node->previous != NULL)
    {
        node->previous->next = node->next;
    }
    if (*head == node)
    {
        *head = node->next;
    }
    if (*tail == node)
    {
        *tail = node->previous;
    }
}
static u32 Runtime_RingIndex(const RuntimeWork* work, u32 index)
{
    s32 remaining;

    remaining = (s32)work->count - 1 - (s32)index;
    if (remaining < 0)
    {
        remaining += (s32)work->slots[0];
    }
    return (u32)remaining;
}


#pragma alias func_003c7850_y2 func_003c7850
#pragma alias func_003c72d0_y2 func_003c72d0
#pragma alias func_003c7990_y2 func_003c7990
#pragma alias func_003c7c20_y2 func_003c7c20
#pragma alias func_001f1c90_y2 func_001f1c90
#pragma alias func_001f1aa0_y2 func_001f1aa0
#pragma alias func_001f0a60_y2 func_001f0a60
#pragma alias func_001f0ab0_y2 func_001f0ab0
#pragma alias func_001f0d70_y2 func_001f0d70
#pragma alias func_001f10b0_y2 func_001f10b0
#pragma alias func_001f10f0_y2 func_001f10f0
#pragma alias func_001f0fd0_y2 func_001f0fd0
#pragma alias func_001f0eb0_y2 func_001f0eb0
#pragma alias func_001f1210_y2 func_001f1210
#pragma alias datGetFlag_y2 datGetFlag
#pragma alias kwlnTaskCreateWithAutoPriority_y2 kwlnTaskCreateWithAutoPriority
#pragma alias kwlnTaskDestroyWithHierarchy_y2 kwlnTaskDestroyWithHierarchy
#pragma alias H_Fade_FadeOut_y2 H_Fade_FadeOut
#pragma alias H_Fade_SetType_y2 H_Fade_SetType
#pragma alias kwlnGetMainCamera_y2 kwlnGetMainCamera
#pragma alias func_003c7430_y2 func_003c7430
#pragma alias func_003c7650_y2 func_003c7650
#pragma alias func_0010a4e0_y2 func_0010a4e0
#pragma alias func_0010a370_y2 func_0010a370
#pragma alias func_001f30b0_y2 func_001f30b0
#pragma alias func_00173220_y2 func_00173220
#pragma alias func_003c7bc0_y2 func_003c7bc0
#pragma alias func_001f0970_y2 func_001f0970
#pragma alias func_001f08c0_y2 func_001f08c0
#pragma alias func_001f0900_y2 func_001f0900
#pragma alias func_001f0940_y2 func_001f0940
#pragma alias func_001f0ad0_y2 func_001f0ad0
#pragma alias func_0021eac0_y2 func_0021eac0
#pragma alias func_001f2080_y2 func_001f2080

#pragma alias sflResGetTutorialFileUnchecked FUN_0020ea00
extern void* sflResGetTutorialFileUnchecked();


/*
 * Battle-result tasks deliberately use byte offsets.  The retail work areas
 * are private to the result system and are shared by several child tasks;
 * keeping the offsets here avoids inventing public layouts for those areas.
 */
#define BR_U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define BR_S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define BR_U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define BR_S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define BR_U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define BR_TASK_WORK(t) ((u8 *)((t)->workData))
#define BR_ROOT_TASK_WORK(t) BR_TASK_WORK(t)
#define BR_SET_STATE(p, s) (BR_U32((p), 0x0c) = (u32)(s))
#define BR_ALLOC2(n, f) (*(void *(**)(u32, u32))jtbl_00960178_abs)((n), (f))
#define BR_FREE(p) (*(void (**)(void *))jtbl_0096017C)((p))

static u8 *sBrRoot;       /* GP-relative -0x4a18 */
static u8 *sBrCard;       /* GP-relative -0x4a14 */
static u8 *sBrReward;     /* GP-relative -0x4a10 */

extern u32 jtbl_00960178[];
#pragma alias jtbl_00960178_abs jtbl_00960178
extern u8 jtbl_00960178_abs[];
extern u32 jtbl_0096017C[];

/* Result-resource and data helpers not yet described by public headers. */
extern s32 printf(const char *, ...);
extern const char D_006845c0[];
extern const char D_006845d0[];
extern const char D_006845f0[];
 
extern void func_002350f0(void);
extern void func_00278550(void);
extern void func_00275cb0(void);
extern void func_003c77a0(void);
extern void brPersonaShutdown(void);
extern void brPersonaDestroy(void);
extern void brHero00262730(void);
extern void brHero002630e0(void);
extern void func_00234960(void);
extern void func_00233e70(void);
extern void func_00272380(void);
extern void func_00275a80(void);
extern void func_00276920(void);
extern void func_00276d30(void);
extern void func_002362e0(void);
extern void func_00262790(void);
extern void func_00275a90(void);
extern void func_0010a370(s32, const char *);
extern void func_00171390(u32);
extern void func_00174e20(u16);
extern u32 dat00171360(u16);
extern s32 func_0016d280(s32);
extern u32 func_0016f380(u32);
extern void func_0016f3e0(u32, u32);
extern u32 func_00173220(u16);
extern u32 func_00174b40(u16);
extern u32 func_001756f0(void);
extern u32 func_00175410(void);
extern u32 func_00175ce0(DatPersonaWork *, u16 *);
extern u32 func_001761b0(DatPersonaWork *);
extern u32 func_00176100(DatPersonaWork *, u16 *);
extern u32 func_001fbdf0(u32, u32, u32, u32, u32);
extern u32 func_001fbfa0(u32, u32, u32, u32, u32, u32);
extern u32 func_001f9e90(u16, u32);
extern void func_001fb4b0(void *, s32, s32, s32, s32 *, s32 *);
extern u8 *DAT_007ce430;
extern u32 func_001f9680(s32 *);
extern void func_001f9c60(void);
extern u32 func_001f9a80(void);
extern void func_001f98d0(void);
extern void sflResult001f9770(u16 *, s32 *);
extern void sflResult001f9800(u16 *, s32 *);
extern u32 sflResult001f9890(void);
extern void sflResult001f9630(void);
extern void *func_001ef500(void *);

extern void func_00219c90(void *);
extern void func_00239170(void *);
extern void func_0023d7a0(void *);
extern void func_0023d7f0(void);
extern void func_0024da00(void *);
extern void sflCamera0024d110(void *);
extern void func_002534d0(void *);
extern void sflScript00259610(void *);
extern void sflCursor0025a110(void *);
extern void func_00215a50(void *);
extern void func_00260970(void *);
extern void sflCount0025b4a0(void *);
extern void sflPersonaInit(void *);
extern u32 sflGround0023c350(void);
extern void func_00219d90(void);
extern void func_00215fc0(void);
extern u32 func_00254f20(void);
extern u32 func_00254f70(void);
extern void func_003c72d0_y2(void *);
extern void func_0023d130(void);
extern void func_0023ee50(void);
extern void sflCard00259250(void);
extern u32 sflGround0023d1f0(void);
extern u32 sflCard002592c0(void);
extern u32 sflCard002582b0(void);
extern void sflScript00259640(void);
extern u32 func_00259740(void);
extern u32 sflScript002596f0(void);
extern u32 sflCard00258af0(void);
extern u32 sflCount0025b640(void);
extern void sflCount0025b5f0(void);
extern void sflCursor0025aa70(void);
extern void sflCard00258490(void);
extern u8 *func_00256030(void);
extern void sflCard00258090(void);
extern void sflCard002580e0(void);
extern void func_0023f1d0(void);
extern void func_0023cda0(void);
extern void func_003c74e0(void);
extern u32 sflPanel0023f390(void);
extern u32 sflGround0023d0e0(void);
extern void func_00255fe0(void);
extern void func_002550b0(void);
extern void func_00258300(void);
extern u32 func_003c7610(void);
extern void func_003c7990_y2(s32);
extern u32 func_003c7850_y2(void);
extern u32 func_003c7650(s32);
extern u32 func_003c78d0(void);
extern void func_002594c0(void);
extern u32 sflCard002595c0(void);
extern void func_003c94e0(void *);
extern void func_003c9790(s32);
extern void func_0025b690(void);
extern void func_0025a130(void);
extern void func_0023d8f0(void);
extern void func_0024db90(void);
extern void func_0024dc10(void);
extern void sflCamera0024d1c0(void);
extern void func_00253a40(void);
extern void func_002392d0(void);
extern void sflPersonaUpdate(void);

extern void func_0023b990(void);
extern void func_00254b90(void);
extern void func_0025bbf0(void);
extern void func_0025a440(void);
extern void func_001f64c0(void);
extern void func_002168f0(void);
extern void func_0023e970(void);
extern void sflPersonaShutdown(void *);
extern void sflCount0025b4b0(void);
extern void func_00215aa0(void);
extern void sflPsel00260a10(void);
extern void func_0025a120(void);
extern void func_00259630(void);
extern void sflCard00253560(void);
extern void sflCamera0024d160(void);
extern void func_0024da20(void);
extern void sflPanel0023d870(void);
extern void func_0023d7b0(void);
extern void sflGround00239280(void);
extern void func_0021a1b0(void);

extern void func_004c9d70(void *, float);
extern void func_0021a840(void);
extern void func_0024fd10(void *);
extern void func_0024f9f0(void *, const float *);
extern void func_0024da60(void *);
extern void func_0024f090(void *);
extern void func_0024d8d0(void *);
extern void sflCamera0024d2e0(s32, void *);
extern void sflCamera0024d940(void *, void *);
extern void sflCamera0024d9a0(void *, void *);
extern void sflCamera0024d280(void *);
extern void func_0024d4c0(s32);
extern void func_0023c280(void);
extern u8 *func_00209e10(void);
extern u8 *func_00209e20(void);
extern u8 *func_00209e60(void);
extern u8 *func_00209e70(void);
extern u8 *func_00209dc0(void);
extern u8 *func_00209dd0(void);
extern u8 *func_00209d00(void);
extern u8 *func_00209c40(void);
extern u8 *func_00209c80(void);
extern u8 *func_00209cc0(void);
extern u8 *func_00209d40(u8 *);
extern char *func_00209e80(void);
extern char *func_00209e90(void);
extern u32 func_00255130(void);
extern void func_00254e10(void);
extern void *sflCard002537f0(u16);
extern u32 sflCard002536b0(u32, u32);
extern void sflCard00255170(void *);
extern void sflCard00255190(void *);
extern void func_002551b0(void *);
extern void sflCard00253920(void);
extern void sflScript00259690(void *, u32);
extern void sflScript00259b00(u16);
extern void sflScript00259b60(u16);
extern void sflScript00259c10(void);
extern void sflScript00259bc0(void);
extern void sflScript00259c60(u16);
extern void sflScript00259cc0(void);
extern void sflScriptQueueEndCommand(void);
extern void sflScriptQueueWaitCommand(u16 frames);
extern void sflScriptQueueOpenCommand(u16 card);
extern void sflScriptQueueWaitForActionsCommand(void);
extern void sflScriptQueueStartActionsCommand(void);
extern void sflScriptQueueSetCardValueCommand(u16 value);
extern void sflScriptQueueShuffleCommand(void);
extern void func_002595c0(void);
extern void func_002508c0(void *, const float *, s32);
extern void func_0020b250(void *);
extern void func_00209f00(void *);
extern void func_0020c590(void *, u16);
extern void func_0020a800(void *);
extern void func_0020c5f0(void *, u32, u32);
extern void func_0024fd80(void *);
extern f32 func_0020c500(void *, f32);
extern void func_0020c400(void *, const float *, float, float *);
extern void func_0020cc80(void *, const u8 *);
extern void gcPose0024f960(void *, const float *);
extern void sflResSetSpriteScale(void *, const f32 *);
extern void sflResSetSpriteRotation(void *, const f32 *);
extern void func_004bdde0(f32, f32 *, const f32 *, u32);
extern void func_0020ac90(void *);
extern void *sflResGetBaseSpriteData(void);
extern u32 func_0035c250(u32);
extern u32 sflResult001f99f0(void);
extern u32 func_001831e0(s16, s16, const void *);
extern u32 scrForceTraceCode(void *);
extern void K_Fldrc_DestroyArchives(void);
extern void func_00217590(u16);
extern void func_00215b00(void);
extern void scrReleaseScript(void *);
extern void *scrStartScriptFirstPrcd(void *header);
extern void func_0021ab80(u16 id);
extern void func_0021a920(u32 majorId, u32 minorId);
extern char D_00684850[];
extern char D_00684620[];
extern char D_006846CE[];
extern char D_006846DE[];
extern char D_00684718[];
extern char D_00684730[];
extern char D_00684750[];
extern char D_00684770[];
extern char D_00684788[];
extern char D_006847A0[];
extern char D_006847D0[];
extern char D_006847E0[];
extern char D_006847F0[];
extern char D_00684800[];
extern char D_00684810[];
extern char D_00684820[];
extern char D_00684830[];
extern char D_00684840[];
extern char D_00696950[];
extern char D_00696948[];
extern char D_00696964[];
extern char D_00696960[];
extern char D_00696958[];
extern u32 func_00255130(void);
extern void func_00257f10(void);
extern void func_002599c0(u32, u32);
extern void func_00259a60(u32, s32);
extern void sflScript00259970(void);
extern f32 func_00530da0(f32);
extern u32 datGetScenarioMode(void);
extern void sflResRequestBaseArchive(void);
extern u32 func_001f9170(s32);
extern void func_00173660(DatPersonaWork *, s32);
extern u32 func_0021a120(void);
extern void func_00258300(void);
extern void func_002550b0(void);
extern void *func_0034fcd0(void *);
extern u16 datGetMaxHp(s16);
extern void *sflResGetBaseDataFile(s32);
extern u16 func_00170760(s16, s16);
extern void func_00170860(s16, s16, u16);
extern void datSetMoney(u32);
extern void func_001828d0(s16, void *, void *);
#pragma alias func_001828d0_2arg func_001828d0
extern void func_001828d0_2arg(s16, void *);
extern void func_00182d90(s16, s16, u32, void *);
extern void func_00521250(void *, const void *, u32);
extern u32 func_003c7bc0(s32, u32);
extern u32 func_003c7c20_y2(s32, u32, u32);
extern void func_003c7430(s32);
extern void func_0010a4e0(s32, s32, s32, s32);
extern const char *h_camp_getAcademicLevelString(s16);
extern const char *h_camp_getCharmLevelString(s16);
extern const char *h_camp_getCourageLevelString(s16);
extern void func_0021eac0(void *, float);
extern void func_0023f010(void);
extern void func_0023ca10(void);
extern void *kwlnGetMainCamera(void);
extern void func_00255f80(void);
extern void func_0025a7d0(void);
extern void func_0025b4f0(void);
extern void sflPanel0023f3e0(void);
extern void sflCard00259310(void);
extern u32 sflCard002561c0(void *);
extern u32 sflCard002561d0(void *);
extern u32 sflCard00259380(void);
extern void sflResult001f9100(void);
extern void sflResSetSpritePosition(void *, const float *);
extern void func_0034fcf0(void *);
extern u32 D_00684610[];
extern u32 func_001775a0(u32, ...);
extern u32 func_0016c6f0(u32);
extern u32 func_00177280(u32);
extern u32 func_0011a810(u32);
extern u32 func_0016c740(u32);
extern u32 func_001772f0(u32);
extern u32 func_0011a840(u32);
extern u32 func_0016c790(u32);
extern u32 func_00177360(u32);
extern u32 func_0011a870(u32);
extern u32 func_0016c4f0(u32);
extern u32 func_0016c5f0(u32);
extern u32 func_0016c570(u32);
extern u32 func_0016c970(u32);
extern u32 func_0016c920(u32);
extern void func_0016cf40(u32, u32);
extern void func_0016cf90(u32, u32);
extern void func_0016d8b0(u32, u32);
extern void func_0016d6b0(u32, u32);
extern u32 func_00488f30(void);
extern void sflResRequestTutorialArchive(void);
extern u32 func_0016f190(u32);
extern void func_0023f430(void);
extern u32 func_002561c0(void *);
extern u32 func_002561d0(void *);
extern void func_005225a8(const char *, s32, s32);
extern void func_00174800(u32);
extern void func_00174650(u32, u32, u32);
extern void func_0016cfe0(u32, u32);
extern void func_0016d090(u32, u32);
extern void func_0016d160(u32, u32);


void func_001f0990(KwlnTask *);
void func_001f0f40(KwlnTask *);
void func_001f0ff0(void);
u8 *brRoot001f1c50(void);
void func_001f1140(KwlnTask *);
void func_001f13b0(KwlnTask *);
void brRoot001f1e90(KwlnTask *);
void func_001f30d0(KwlnTask *);
void func_001f30f0(KwlnTask *);
void func_001f3270(KwlnTask *);
void func_001f4650(KwlnTask *, const u8 *);
void func_001f4750(KwlnTask *);
u32 func_001f4990(void);
void func_001f4a00(void);
void func_001f53a0(void);
void func_001f54a0(void);
void func_001f5510(void);
void func_001f55e0(void);
void func_001f5650(void);
void func_001f56b0(void);
u32 func_001f5760(u16);
u32 func_001f5810(KwlnTask *);
void func_001f58f0(u8 *);
void func_001f5950(void);
void func_001f59b0(void);
void *func_001f5b20(void);
void func_001f64c0(void);
u32 func_001f65e0(void);
void func_001f6630(void);
void brRewardAdvanceState(void);
void brRewardAnimateCurrentEntry(void);
void brRewardRegisterEntry(const f32 *);
void func_001f7030(void);
void func_001f70d0(void);
void func_001f7170(void);
void func_001f7210(void);
#pragma alias func_001f2300_update func_001f2300
extern void *func_001f2300_update(KwlnTask *);
#pragma alias func_001f2fd0_destroy func_001f2fd0
extern void func_001f2fd0_destroy(KwlnTask *);
void *func_001f2f50(KwlnTask *);
void *func_001f2f80(KwlnTask *);
void func_001f2fd0(KwlnTask *);
void func_001f2ff0(KwlnTask *);
u32 func_001f30b0(KwlnTask *);
void *func_001f2300(KwlnTask *);

static void brCopyWords(u8 *dst, const u8 *src, u32 count)
{
    u32 i;
    for (i = 0; i < count; i++) {
        dst[i] = src[i];
    }
}

static u32 brRootFlags(void)
{
    return sBrRoot != NULL ? BR_U32(sBrRoot, 0) : 0;
}

static u32 brCardFlags(void)
{
    return sBrCard != NULL ? BR_U32(sBrCard, 4) : 0;
}

static u32 brRewardFlags(void)
{
    return sBrReward != NULL ? BR_U32(sBrReward, 0) : 0;
}

// FUN_001EF7F0
s32 func_001ef7f0(RuntimeTask* task)
{
    RuntimeWork* work;
    u16 input;
    u8* bytes;
    struct
    {
        u32 flags;
        u16 id;
        u16 reserved;
        void* resource;
    } entry;

    work = task->workData;
    bytes = (u8*)work;
    func_00234070();
    func_00235010();
    func_00263170();
    func_00272810();
    func_00275bc0();
    func_00276930();
    func_002770f0();

    if ((work->flags & 0x40) != 0)
    {
        work->flags &= ~0x40;
        return 0;
    }

    if ((work->requestFlags & 1) != 0 &&
        func_001f4910(*(void**)((u8*)work + 0x94)) == 0)
    {
        work->completedFlags |= 1;
        work->requestFlags &= ~1;
    }
    if ((work->requestFlags & 2) != 0 && func_00233ad0() == 0)
    {
        work->completedFlags |= 2;
        work->requestFlags &= ~2;
    }
    if ((work->requestFlags & 4) != 0 && func_00233bb0() == 0)
    {
        work->completedFlags |= 4;
        work->requestFlags &= ~4;
    }

    switch (work->state)
    {
        case 0:
            if ((work->flags & 2) != 0)
            {
                if ((~work->completedFlags & 1) != 0)
                {
                    break;
                }
            }
            else if ((~work->completedFlags & 2) != 0)
            {
                break;
            }
            if ((~work->flags & 0x2000) != 0)
            {
                break;
            }

            if ((work->flags & 2) != 0)
            {
                func_0010a4e0_y2(1, 0, 6, 14);
                func_001f4930(*(void**)((u8*)work + 0x94));
            }
            else
            {
                func_001f1c90(task);
            }
            if ((work->flags & 2) != 0)
            {
                H_Snd_PlayBgm(78, 1);
            }
            else
            {
                H_Snd_PlayBgm(60, 1);
            }
            work->state = 1;
            break;

        case 1:
            if ((work->flags & 2) != 0)
            {
                if (func_001f4970(*(void**)((u8*)work + 0x94)) != 0)
                {
                    break;
                }
            }
            else if (func_00236340() != 0)
            {
                break;
            }
            work->flags &= ~0x2000;
            work->state = 2;
            break;

        case 2:
            break;

        case 3:
            if (func_001f30b0_y2(*(void**)((u8*)work + 0x94)) != 0)
            {
                break;
            }
            if (func_00233ad0() != 0)
            {
                break;
            }
            func_001f1aa0(task);
            func_001f1c90(task);
            if ((work->flags & 0x2c) != 0)
            {
                work->state = 4;
            }
            else
            {
                work->state = 6;
            }
            break;

        case 4:
            if (func_001b07d0() != 0)
            {
                func_001b0840();
                work->state = 5;
            }
            break;

        case 5:
            if ((work->flags & 8) != 0)
            {
                func_00233c00();
            }
            work->state = 6;
            break;

        case 6:
            if (func_00236340() == 0)
            {
                func_001f0a60(task);
                func_001f0ab0(task);
            }
            break;

        case 7:
            switch ((u32)work->renderData)
            {
                case 0:
                    input = *(u16*)DAT_007e094e_abs;
                    if ((input & 0x40) != 0 ||
                        (*(u16*)DAT_007e094c_abs & 0x10) != 0 ||
                        (input & 0x20) != 0)
                    {
                        if (*(void**)((u8*)work + 0xa680) == NULL)
                        {
                            func_00108570();
                            func_00108670(5);
                            func_001086a0(1);
                            func_002362e0();
                            work->flags &= ~0x200000;
                            work->renderData = (void*)1;
                        }
                        else
                        {
                            func_001f0d70(task);
                        }
                    }
                    break;

                case 1:
                    if (func_00236340() == 0)
                    {
                        func_001f0d70(task);
                    }
                    break;

                default:
                    break;
            }
            break;

        case 9:
            switch (*(u32*)(bytes + 0x38))
            {
                case 0:
                {
                    u16 id;
                    s32 value;
                    if ((~work->completedFlags & 4) != 0)
                    {
                        break;
                    }
                    if (*(u32*)(bytes + 0x3c) != 0)
                    {
                        func_0019d3f0(D_00684578, 0x2c6);
                    }
                    func_003c72d0(func_002345d0(1));
                    *(u32*)(bytes + 0x3c) = 2;
                    *(s32*)(bytes + 0x154) = 0;
                    id = ((u16*)(bytes + 0x140))[
                        *(s32*)(bytes + 0x154)];
                    func_003c7c20(0, id, 5);
                    if (iGpffffb6fc != NULL)
                    {
                        value = func_001fb1b0(6, id);
                        if (func_0017d800() != 0)
                        {
                            if (value == 2)
                            {
                                value = 7;
                            }
                            else if (value == 4)
                            {
                                value = 8;
                            }
                        }
                        func_003c7430_y2(value);
                    }
                    else
                    {
                        func_003c7430_y2(5);
                    }
                    FUN_005225a8(D_00684588);
                    *(u32*)(bytes + 0x38) = 1;
                    break;
                }

                case 1:
                {
                    s32 value;
                    func_003c7990(1);
                    if (func_003c7850() != 0)
                    {
                        break;
                    }
                    func_003c7650_y2(1);
                    value = *(s32*)(bytes + 0x154);
                    func_003c7c20(
                        0, ((u16*)(bytes + 0x140))[value], 5);
                    func_003c7430_y2(6);
                    *(u32*)(bytes + 0x38) = 2;
                    break;
                }

                case 2:
                {
                    u16 id;
                    s32 value;
                    func_003c7990(1);
                    if (func_003c7850() != 0)
                    {
                        break;
                    }
                    func_003c7650_y2(1);
                    value = ++*(s32*)(bytes + 0x154);
                    if (value < *(s32*)(bytes + 0x150))
                    {
                        id = ((u16*)(bytes + 0x140))[value];
                        func_003c7c20(0, id, 5);
                        if (iGpffffb6fc != NULL)
                        {
                            value = func_001fb1b0(6, id);
                            if (func_0017d800() != 0)
                            {
                                if (value == 2)
                                {
                                    value = 7;
                                }
                                else if (value == 4)
                                {
                                    value = 8;
                                }
                            }
                            func_003c7430_y2(value);
                        }
                        else
                        {
                            func_003c7430_y2(5);
                        }
                        *(u32*)(bytes + 0x38) = 1;
                    }
                    else
                    {
                        *(s32*)(bytes + 0xa790) = 0;
                        *(u32*)(bytes + 0x38) = 3;
                    }
                    break;
                }

                case 3:
                {
                    s32 value;
                    value = *(s32*)(bytes + 0xa790);
                    if (value < 12)
                    {
                        *(s32*)(bytes + 0xa790) = value + 1;
                        break;
                    }
                    func_001f0eb0(task);
                    if (*(u32*)(bytes + 0xa680) == 1)
                    {
                        func_00108570();
                        func_00108670(5);
                        func_001086a0(1);
                        func_002362e0();
                        work->flags &= ~0x200000;
                        *(u32*)(bytes + 0x38) = 4;
                    }
                    else
                    {
                        if (*(u32*)(bytes + 0x3c) != 2)
                        {
                            func_0019d3f0(D_00684578, 0x32a);
                        }
                        func_003c77a0();
                        func_003c72d0(func_002345d0(0));
                        *(u32*)(bytes + 0x3c) = 1;
                        func_001f0d70(task);
                    }
                    break;
                }

                case 4:
                    if (func_00236340() == 0)
                    {
                        func_001f0d70(task);
                    }
                    break;

                default:
                    break;
            }
            break;

        case 8:
            switch (*(u32*)(bytes + 0x10))
            {
                case 0:
                    if ((~work->completedFlags & 4) != 0 ||
                        func_00233d20() != 0)
                    {
                        break;
                    }
                    if (*(u32*)(bytes + 0x3c) != 0)
                    {
                        func_0019d3f0(D_00684578, 0x34c);
                    }
                    func_003c72d0(func_002345d0(0));
                    *(u32*)(bytes + 0x3c) = 1;
                    func_001f0ff0();
                    break;

                case 1:
                    if (func_00236340() != 0)
                    {
                        break;
                    }
                    if ((~work->flags & 0x80000) != 0)
                    {
                        func_002767e0();
                        work->flags |= 0x80000;
                    }
                    if ((work->flags & 0x40000) != 0)
                    {
                        func_003c7990(0);
                        if (func_003c7850() != 0)
                        {
                            break;
                        }
                        func_003c7650_y2(0);
                        func_001f10b0();
                    }
                    else if (*(u32*)(bytes + 0xa680) == 2)
                    {
                        func_003c7990(1);
                        if (func_003c7850() != 0)
                        {
                            break;
                        }
                        func_003c7650_y2(1);
                        func_001f10f0();
                    }
                    else
                    {
                        func_003c7990(1);
                        if (func_003c7850() != 0)
                        {
                            break;
                        }
                        func_003c7650_y2(1);
                        func_001f0d70(task);
                    }
                    break;

                case 2:
                    func_003c7990(0);
                    if (func_003c7850() != 0)
                    {
                        break;
                    }
                    func_003c7650_y2(0);
                    func_003c7c20(0, func_00175410() & 0xffff, 0);
                    func_003c7430_y2(4);
                    func_0010a4e0_y2(1, 0, 8, 0);
                    *(u32*)(bytes + 0x10) = 3;
                    break;

                case 3:
                    if (*(u32*)(bytes + 0xa680) == 2)
                    {
                        func_003c7990(1);
                        if (func_003c7850() != 0)
                        {
                            break;
                        }
                        func_003c7650_y2(1);
                        func_001f10f0();
                    }
                    else
                    {
                        func_003c7990(1);
                        if (func_003c7850() != 0)
                        {
                            break;
                        }
                        func_003c7650_y2(1);
                        func_001f0d70(task);
                    }
                    break;

                case 4:
                    if (H_Fade_IsFadeOutDone() != 0)
                    {
                        func_001f0fd0(task);
                        func_001f0d70(task);
                    }
                    break;

                default:
                    break;
            }
            break;

        case 10:
        case 11:
            break;

        case 12:
            switch (work->selection)
            {
                case 0:
                    if ((~work->completedFlags & 4) != 0)
                    {
                        break;
                    }
                    if (*(u32*)(bytes + 0x3c) != 0)
                    {
                        func_0019d3f0(D_00684578, 0x3c1);
                    }
                    func_003c72d0(func_002345d0(0));
                    *(u32*)(bytes + 0x3c) = 1;
                    *(s32*)(bytes + 0xc4) = 0;
                    func_003c7bc0_y2(
                        0, func_00173220_y2(
                               ((u16*)(bytes + 0xd4))[
                                   *(s32*)(bytes + 0xc4)]));
                    func_003c7430_y2(1);
                    work->selection = 1;
                    break;

                case 1:
                    if (func_00236340() != 0)
                    {
                        break;
                    }
                    func_003c7990(1);
                    if (func_003c7850() != 0)
                    {
                        break;
                    }
                    func_003c7650_y2(1);
                    if ((~work->flags & 0x200000) != 0)
                    {
                        func_00108570();
                        func_00108670(5);
                        work->selection = 2;
                    }
                    else
                    {
                        work->selection = 3;
                    }
                    break;

                case 2:
                    if (H_Fade_IsFadeOutDone() != 0)
                    {
                        work->selection = 3;
                    }
                    break;

                case 3:
                    func_003c77a0();
                    *(u32*)(bytes + 0x3c) = 0;
                    if ((~work->flags & 0x100000) != 0)
                    {
                        func_00275a90();
                        work->flags |= 0x100000;
                    }
                    if (*(u32*)(bytes + 0x3c) != 0)
                    {
                        func_0019d3f0(D_00684578, 0x3f3);
                    }
                    func_00264e30(
                        ((u16*)(bytes + 0xd4))[
                            *(s32*)(bytes + 0xc4)]);
                    *(u32*)(bytes + 0x3c) = 3;
                    entry.flags = 0;
                    entry.id = ((u16*)(bytes + 0xd4))[
                        *(s32*)(bytes + 0xc4)];
                    entry.resource = func_00264ff0();
                    func_00272400(&entry);
                    func_002769c0(entry.resource, entry.id);
                    work->flags |= 0x10000;
                    if ((work->flags & 8) != 0)
                    {
                        func_001f0fd0(task);
                    }
                    work->selection = 4;
                    break;

                case 4:
                    if (func_00275370() != 0)
                    {
                        break;
                    }
                    func_00276ba0();
                    func_00276d90();
                    if ((work->flags & 0x200000) != 0)
                    {
                        func_002362e0();
                        work->flags &= ~0x200000;
                    }
                    else
                    {
                        func_00108670(2);
                        func_001085c0();
                    }
                    func_0010a370_y2(3, D_006845A0);
                    work->selection = 5;
                    break;

                case 5:
                    if (H_Fade_IsFadeOutDone() != 0)
                    {
                        func_002753c0();
                        work->selection = 6;
                    }
                    break;

                case 6:
                {
                    s32 value;
                    if (func_002727c0() != 0)
                    {
                        break;
                    }
                    value = ++*(s32*)(bytes + 0xc4);
                    if (value < *(s32*)(bytes + 0xec))
                    {
                        func_00277070();
                        entry.flags = 0;
                        entry.id = ((u16*)(bytes + 0xd4))[
                            *(s32*)(bytes + 0xc4)];
                        entry.resource = func_00264ff0();
                        func_00272400(&entry);
                        func_00264ef0(
                            ((u16*)(bytes + 0xd4))[
                                *(s32*)(bytes + 0xc4)]);
                        work->selection = 4;
                    }
                    else
                    {
                        work->flags &= ~0x10000;
                        if (*(u32*)(bytes + 0xa680) == 3)
                        {
                            func_00108570();
                            func_00108670(2);
                            work->selection = 7;
                        }
                        else
                        {
                            func_001f1210(task);
                            func_001f0d70(task);
                        }
                    }
                    break;
                }

                case 7:
                    if (H_Fade_IsFadeOutDone() != 0)
                    {
                        func_001f1210(task);
                        func_001f0d70(task);
                    }
                    break;

                default:
                    break;
            }
            break;

        default:
            break;
    }
    return 0;
}

// FUN_001F07A0. Apply field render channels and update runtime subsystems.
s32 func_001f07a0(RuntimeTask* task)
{
    RuntimeWork* work;
    u32 dispatchAddress;
    void* channel;

    work = task->workData;
    if ((work->flags & 0x10000) != 0)
    {
        __asm__ volatile ("lui %0, 0x96\n\taddiu %0, %0, 0x90" : "=r"(dispatchAddress));
        (*(void (**)())dispatchAddress)(8, 0);
        (*(void (**)())dispatchAddress)(6, 0);
        (*(void (**)())dispatchAddress)(9, 2);
        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        (*(void (**)())dispatchAddress)(1, 0);
        __asm__ volatile ("lui %0, 0x96\n\taddiu %0, %0, 0x9c" : "=r"(dispatchAddress));
        __asm__ volatile ("ori $at, $zero, 0xa690\n\taddu %0, %1, $at" : "=r"(channel) : "r"(work) : "$1");
        (*(void (**)())dispatchAddress)(channel, 4, 0, 1, 2);
        __asm__ volatile ("ori $at, $zero, 0xa690\n\taddu %0, %1, $at" : "=r"(channel) : "r"(work) : "$1");
        (*(void (**)())dispatchAddress)(channel, 4, 0, 2, 3);
    }
    func_00263db0();
    func_002737a0();
    return 0;
}

// FUN_001f08c0
void *func_001f08c0(KwlnTask *task)
{
    u8 *work = BR_TASK_WORK(task);
    if ((BR_U32(work, 0) & 0x400000) != 0) {
        func_002350f0();
    }
    return KWLNTASK_CONTINUE;
}

// FUN_001f0900
void *func_001f0900(KwlnTask *task)
{
    u8 *work = BR_TASK_WORK(task);
    u32 flags = ~BR_U32(work, 0);
    if ((flags & 0x400000) != 0) {
        func_002350f0();
    }
    return KWLNTASK_CONTINUE;
}

// FUN_001f0940
void *func_001f0940(KwlnTask *task)
{
    (void)task;
    func_00278550();
    func_00275cb0();
    return KWLNTASK_CONTINUE;
}

// FUN_001f0970
void func_001f0970(KwlnTask *task)
{
    func_001f0990(task);
}

// FUN_001f0990
void func_001f0990(KwlnTask *task)
{
    u8 *work = BR_TASK_WORK(task);
    if ((BR_U32(work, 0) & 4) == 0) {
        if ((BR_U32(work, 0) & 8) == 0) {
            if ((BR_U32(work, 0) & 0x20) == 0) {
                goto br_cleanup_done;
            }
        }
    }
    func_003c77a0();
br_cleanup_done:
    brPersonaShutdown();
    brHero00262730();
    func_00234960();
    brRes00233e70();
    func_00272380();
    func_00275a80();
    func_00276920();
    func_00276d30();
    if ((BR_U32(work, 0) & 0x8000) != 0) {
        func_001f30d0((KwlnTask *)BR_U32(work, 0x94));
    }
    BR_FREE(task->workData);
}


// FUN_001f0a60
void func_001f0a60_y2(KwlnTask *task)
{
    u32 *work = (u32 *)BR_TASK_WORK(task);
    func_001f30d0((KwlnTask *)work[0x25]);
    work[0] &= ~0x8000u;
    work[0x25] = 0;
}
// FUN_001F0AB0
void func_001f0ab0_y2(KwlnTask *task)
{
    task = (KwlnTask *)task->workData;
    BR_U32(task, 0x28) = 0;
    BR_U32(task, 0xc) = 7;
}


/* W414 full fndiff/JAL review: retail and candidate both call printf twice in order; sentinel local, hoisted-id, and scoped-j probes all stayed nd23/368B (window 368B), reverted. */
/* W418 declaration/width and loop-shape probes stayed nd23/368B; unsigned variants regressed nd24-25 and wider locals exceeded the window. */
/* SocialBig W419 negative: direct no-local loop rewrite stayed nd23/368B; reverted. */
/* W419 static-inline brRootAdd(offset, base) address-order probe stayed nd23/368B (window368, rate .062500), reverted. */

// FUN_001f0ad0 NONMATCHING
void func_001f0ad0(KwlnTask *task, const BrRootSetupParams *params)
{
    u32 *work;
    s32 i;
    s32 j;

    work = (u32 *)BR_TASK_WORK(task);
    if ((params->flags & 1) != 0) {
        work[0] |= 2;
    }
    work[0xb0 / 4] = params->entryCount;
    for (i = 0; i < (s32)params->entryCount; i++) {
        const u8 *entry = (const u8 *)params + i * 8;
        u8 *dst = (u8 *)work + i * 8;
        BR_U16(dst, 0x98) = BR_U16(entry, 4);
        BR_U32(dst, 0x9c) = BR_U32(entry, 8);
    }
    work[0xb4 / 4] = params->field20;
    work[0x118 / 4] = params->partyCount;
    work[0x11c / 4] = params->field30;
    printf(D_006845c0, work[0x118 / 4]);
    printf(D_006845d0, work[0x11c / 4]);
    work[0x114 / 4] = 0;
    for (j = 0; j < (s32)params->partyCount; j++) {
        u16 id = params->partyIds[j];
        if (id == 1) {
            continue;
        }
        BR_U16((u8 *)work + work[0x114 / 4] * 2, 0x10c) = id;
        work[0x114 / 4] = work[0x114 / 4] + 1;
    }
    work[0x2a58 / 4] = params->field3c;
    work[0x12c / 4] = params->field34;
    work[0x130 / 4] = params->field38;
    work[0x124 / 4] = params->field3c;
    work[0x128 / 4] = params->field40;
    work[0x120 / 4] = 0;
    if ((params->flags & 2) != 0) {
        work[0x120 / 4] |= 1;
    }
}

// FUN_001f0c40 NONMATCHING
void func_001f0c40(KwlnTask *task)
{
    u8 *entry;
    u8 *work;
    s32 i;
    s32 j;
    work = task->workData;
    for (i = 0; i < (s32)BR_U32(work, 0xb0); i++) {
        entry = work + i * 8 + 0x98;
        if (dat00171360(BR_U16(entry, 0)) != 0) {
            func_00171390(BR_U16(entry, 0));
        } else {
            u8 *base = work + i * 8;
            s32 level = (s32)(func_00170760(1, BR_S16(entry, 0)) & 0xffff);
            level += BR_S32(base, 0x9c);
            if (level >= 100) {
                level = 99;
            }
            func_00170860(1, BR_S16(entry, 0), (u16)level);
        }
    }
    for (j = 0; j < (s32)BR_U32(work, 0x108); j++) {
        func_00174e20(BR_U16(work + j * 2, 0xf0));
    }
    BR_U32(work, 0) &= ~1u;
    BR_SET_STATE(work, 13);
}

// FUN_001f0d70
void func_001f0d70_y2(KwlnTask *task)
{
    u8 *work;
    u32 state;

    work = BR_TASK_WORK(task);
    state = BR_U32(work, 0x0c);
    for (;;) {
        switch (state) {
        case 7:
            if ((BR_U32(work, 0) & 4) != 0) {
                brRoot001f1e90(task);
                return;
            }
            state = 9;
            break;
        case 9:
            if ((BR_U32(work, 0) & 8) != 0) {
                func_001f0f40(task);
                return;
            }
            state = 8;
            break;
        case 8:
            if ((BR_U32(work, 0) & 0x20) != 0) {
                func_001f1140(task);
                return;
            }
            state = 12;
            break;
        case 12:
            func_001f0c40(task);
            return;
        default:
            K_ASSERT(0, 0x582);
            break;
        }
    }
}

// FUN_001f0eb0
void func_001f0eb0_y2(KwlnTask *task)
{
    u8 *work = BR_TASK_WORK(task);
    s32 i;
    DatPersonaWork *persona = datPersonaGetByPcId(6);
    for (i = 0; i < BR_S32(work, 0x150); i++) {
        datPersonaSetSkill(persona, BR_U16(work + i * 2, 0x140));
    }
    BR_U32(work, 0) &= ~0x400000u;
}

// FUN_001f0f40
void func_001f0f40(KwlnTask *task)
{
    u32 *work = (u32 *)BR_TASK_WORK(task);
    if ((~work[2] & 4) != 0) {
        K_ASSERT((~work[1] & 4) != 0, 0x59f);
        brRes00233b20();
        work[1] |= 4;
        work[4] = 0;
    } else {
        func_001f0ff0();
    }
    work[3] = 8;
}

// FUN_001f0fd0
void func_001f0fd0_y2(KwlnTask *task)
{
    (void)task;
    brHero002630e0();
}

// FUN_001f0ff0
void func_001f0ff0(void)
{
    u8 *work = brRoot001f1c50();
    u32 level = datGetLevel(1);
    func_003c7c20_y2(0, level, 0);
    func_003c7430(2);
    func_002362e0();
    BR_U32(work, 0) &= ~0x200000u;
    BR_U32(work, 0) &= ~0x80000u;
    func_00262790();
    func_00275a90();
    BR_U32(work, 0) |= 0x100000;
    func_0010a370(3, "battle result");
    BR_U32(work, 0x10) = 1;
}

// FUN_001f10b0
void func_001f10b0_y2(void)
{
    u8 *work = brRoot001f1c50();
    func_003c7430(3);
    BR_U32(work, 0x10) = 2;
}

// FUN_001f10f0
void func_001f10f0_y2(void)
{
    u8 *work = brRoot001f1c50();
    H_Fade_FadeOut();
    H_Fade_SetType(2);
    BR_U32(work, 0x10) = 4;
}

// FUN_001f1140
void func_001f1140(KwlnTask *task)
{
    volatile /* Removing this function's qualifier batch loses func_001f1140 (MATCH nd0 -> MISMATCH nd46, size 200 -> 188) - measured W170. */ u32 *work = (volatile /* Removing this function's qualifier batch loses func_001f1140 (MATCH nd0 -> MISMATCH nd46, size 200 -> 188) - measured W170. */ u32 *)BR_TASK_WORK(task);
    if ((~work[2] & 4) != 0) {
        K_ASSERT((~work[1] & 4) != 0, 0x5e5);
        brRes00233b20();
        work[1] |= 4;
        work[5] = 0;
    } else {
        u32 index = (work[0xc4 / 4] = 0);
        u32 addr = index * 2;
        addr = addr + (u32)work + 0xd4;
        func_003c7bc0(0, func_00173220(*(u16 *)addr));
        func_003c7430(1);
        work[5] = 1;
    }
    work[3] = 12;
}

/* Retail 0x1f13f0-0x1f1a64: level-up propagation, hero/party EXP, and
 * newly learned-skill collection. */
// FUN_001f1210
void *func_001f1210_y2(void)
{
    brPersonaDestroy();
    return (void *)func_003c7650(1);
}

// FUN_001f1240
void func_001f1240(KwlnTask *task)
{
    u32 *work = (u32 *)BR_TASK_WORK(task);
    f32 ratio;

    K_ASSERT((~work[0] & 0x20000) != 0, 0x603);
    if (((~work[0]) & 2) != 0) {
        ratio = (f32)(s32)work[0xb4 / 4] / (f32)(s32)work[0x11c / 4];
    } else {
        ratio = ((f32)(s32)work[0xb4 / 4] * (f32)(s32)work[0x2a5c / 4] / 100.0f) /
                (f32)(s32)work[0x11c / 4];
    }
    if (ratio == 0.0f) {
        work[0xb8 / 4] = 0;
    } else if (ratio < 1.0f) {
        work[0xb8 / 4] = 1;
    } else {
        work[0xb8 / 4] = (s32)ratio;
    }
    work[0x2a54 / 4] = work[0x130 / 4];
    work[0x2a50 / 4] = func_001fbdf0((u8)datGetLevel(1), work[0x2a54 / 4],
                                     work[0xb8 / 4], work[0x2a58 / 4],
                                     work[0x11c / 4]);
    func_001f13b0(task);
    work[0] |= 0x20000;
}

// FUN_001f13b0 NONMATCHING
void func_001f13b0(KwlnTask *task)
{
    s32 *work = (s32 *)BR_TASK_WORK(task);
    s32 oldLevel;
    s32 newLevel;
    s32 heroCount;
    s32 i;
    s32 heroId;
    DatPersonaWork *persona;
    u16 *skills;
    s32 skillCount;
    s32 skill;
    s32 firstIndex;
    s32 indexCount;
    s32 j;
    s32 learnedCount;
    u8 *entry;
    u8 *current;

    /* Retail +0x24..+0x94: apply the hero's pending EXP before deriving
     * the resulting level, then print the level transition. */
    oldLevel = datGetLevel(1);
    work[0xbc / 4] = oldLevel;
    datDidCharacterLevelUp(1, work[0x2a50 / 4]);
    newLevel = func_0016d280(datGetNextExp(1));
    datSetLevel(1, newLevel);
    work[0xc0 / 4] = datGetLevel(1);
    printf(D_006845f0, work[0xbc / 4], work[0xc0 / 4]);
    if (work[0xbc / 4] != work[0xc0 / 4]) {
        work[0] |= 8;
        if (work[0xc0 / 4] > 0 && !datGetFlag(0x120c)) {
            datSetFlag(0x120c, 1);
            work[0] |= 0x40000;
        }
        if (work[0xc0 / 4] >= 10 && !datGetFlag(0x120d)) {
            datSetFlag(0x120d, 1);
            work[0] |= 0x40000;
        }
        if (work[0xc0 / 4] >= 20 && !datGetFlag(0x1201)) {
            datSetFlag(0x1201, 1);
            work[0] |= 0x40000;
        }
        if (work[0xc0 / 4] >= 30 && !datGetFlag(0x1202)) {
            datSetFlag(0x1202, 1);
            work[0] |= 0x40000;
        }
    }

    /* Retail +0x1c8..+0x3d0: walk every hero Persona.  The three skill
     * IDs are separate retail call sites, not one merged fallback call. */
    work[0xec / 4] = 0;
    heroId = datPersonaGetByPcId(1)->id;
    heroCount = func_001756f0() & 0xffff;
    for (i = 0; i < heroCount; i++) {
        persona = datPersonaGetHeroPersona((s16)i);
        K_ASSERT(persona != NULL, 0x665);
        if (persona->id == heroId) {
            datPersonaAddExp(persona, (s32)func_001fbdf0(
                (u32)persona->level, work[0x2a54 / 4],
                work[0xb8 / 4], work[0x2a58 / 4],
                work[0x11c / 4]));
        } else {
            skills = datPersonaGetSkills(persona);
            skillCount = datPersonaCountValidSkills(persona);
            skill = 0;
            while (skill < skillCount) {
                if (skills[skill] == 0x22b) {
                    break;
                }
                skill++;
            }
            if (skill < skillCount) {
                datPersonaAddExp(persona, (s32)func_001fbfa0(
                    (u32)persona->level, work[0x2a54 / 4],
                    work[0xb8 / 4], 0x22b,
                    work[0x2a58 / 4], work[0x11c / 4]));
            } else {
                skill = 0;
                while (skill < skillCount) {
                    if (skills[skill] == 0x22a) {
                        break;
                    }
                    skill++;
                }
                if (skill < skillCount) {
                    datPersonaAddExp(persona, (s32)func_001fbfa0(
                        (u32)persona->level, work[0x2a54 / 4],
                        work[0xb8 / 4], 0x22a,
                        work[0x2a58 / 4], work[0x11c / 4]));
                } else {
                    skill = 0;
                    while (skill < skillCount) {
                        if (skills[skill] == 0x229) {
                            break;
                        }
                        skill++;
                    }
                    if (skill < skillCount) {
                        datPersonaAddExp(persona, (s32)func_001fbfa0(
                            (u32)persona->level, work[0x2a54 / 4],
                            work[0xb8 / 4], 0x229,
                            work[0x2a58 / 4], work[0x11c / 4]));
                    }
                }
            }
        }
    }

    /* Retail +0x3e0..+0x464: collect Personas that learned skills. */
    learnedCount = 0;
    for (i = 0; i < heroCount; i++) {
        persona = datPersonaGetHeroPersona((s16)i);
        K_ASSERT(persona != NULL, 0x6ac);
        if (func_001761b0(persona) != 0) {
            BR_U16((u8 *)work + learnedCount * 2, 0xd4) = persona->id;
            learnedCount++;
        }
    }
    work[0xec / 4] = learnedCount;
    if (learnedCount != 0) {
        work[0] |= 0x20;
    }

    /* Retail +0x494..+0x4d8: update each non-hero party member's result. */
    for (i = 0; i < work[0x114 / 4]; i++) {
        u8 *pcEntry = (u8 *)work + 0x10c + i * 2;
        s16 pc = *(s16 *)pcEntry;
        func_001f9e90(*(u16 *)pcEntry,
                       func_001fbdf0(datGetLevel(pc), work[0x2a54 / 4],
                                     work[0xb8 / 4], work[0x2a58 / 4],
                                     work[0x11c / 4]));
    }

    /* Retail +0x4e0..+0x640: process the optional sixth Persona's
     * learned-skill table and copy type-1 entries into the result. */
    if (datGetFlag(0x140)) {
        persona = datPersonaGetByPcId(6);
        K_ASSERT(persona != NULL, 0x6c9);
        datPersonaAddExp(persona, (s32)func_001fbdf0(
            datGetLevel(6), work[0x2a54 / 4], work[0xb8 / 4],
            work[0x2a58 / 4], work[0x11c / 4]));
        if (func_001761b0(persona) != 0) {
            func_00175ce0(persona, (u16 *)((u8 *)work + 0x158));
            entry = DAT_007ce430 + (persona->id - 0xc0) * 0x26e + 4;
            func_001fb4b0(entry, 0x20, persona->level,
                          BR_U8((u8 *)work, 0x158), &firstIndex, &indexCount);
            work[0x150 / 4] = 0;
            current = entry + firstIndex * 4;
            for (j = 0; j < indexCount; j++, current += 4) {
                if (current[1] == 1) {
                    BR_U16((u8 *)work + work[0x150 / 4] * 2, 0x140) =
                        BR_U16(current, 2);
                    work[0x150 / 4]++;
                }
            }
            func_00176100(persona, (u16 *)((u8 *)work + 0x158));
            if (work[0x150 / 4] != 0) {
                work[0] |= 4;
            }
        }
    }

    if (work[0xec / 4] != 0) {
        work[(0x10000 - 0x5980) / 4] = 3;
    } else if ((work[0] & 8) != 0) {
        work[(0x10000 - 0x5980) / 4] = 2;
    } else if ((work[0] & 4) != 0) {
        work[(0x10000 - 0x5980) / 4] = 1;
    } else {
        work[(0x10000 - 0x5980) / 4] = 0;
    }
}

// FUN_001f1aa0
void *func_001f1aa0_y2(KwlnTask *task)
{
    u8 *work = BR_TASK_WORK(task);
    sflResult001f9800((u16 *)(work + 0xf0), (s32 *)(work + 0x108));
    BR_U32(work, 0x2a5c) = sflResult001f9890();
}

// FUN_001f1ae0
KwlnTask *func_001f1ae0(KwlnTask *parent)
{
    return (KwlnTask *)func_001ef500(parent);
}

// FUN_001f1b00
u32 func_001f1b00(KwlnTask *task)
{
    return BR_U32(BR_TASK_WORK(task), 0) & 1;
}

// FUN_001f1b20
void func_001f1b20(KwlnTask *task)
{
    BR_U32(BR_TASK_WORK(task), 0) |= 0x2000;
}

// FUN_001f1b40
u32 func_001f1b40(KwlnTask *task)
{
    return BR_U32(BR_TASK_WORK(task), 0) & 0x2000;
}

// FUN_001f1b60
void brRoot001f1b60(KwlnTask* task)
{
    u8* root;
    u8* work;

    root = BR_TASK_WORK(task);
    K_ASSERT(BR_U32(root, 0x0c) == 2, 0x51e);
    if ((BR_U32(root, 0) & 2) != 0) {
        work = BR_TASK_WORK(task);
        func_001f30f0((KwlnTask*)BR_U32(work, 0x94));
        brRes002339d0();
        BR_U32(work, 0) |= 0x8000;
        BR_U32(work, 0x0c) = 3;
    } else {
        work = BR_TASK_WORK(task);
        BR_U32(work, 0x28) = 0;
        BR_U32(work, 0x0c) = 7;
    }
    BR_U32(root, 0) |= 0x40;
    BR_U32(root, 0) |= 1;
}

// FUN_001f1c20
void func_001f1c20(KwlnTask *task)
{
    sBrRoot = NULL;
    kwlnTaskDestroyWithHierarchy(task);
}

#pragma opt_propagation off
// FUN_001f1c50
u8 *brRoot001f1c50(void)
{
    K_ASSERT(sBrRoot != NULL, 0x755);
    return sBrRoot;
}

/* W419 retail loop-branch reconstruction with conditional stores grew to nd237/328B (window352, rate .722561) versus landed nd216/300B; reverted. */
/* W419 target setup reorder/removal of non-retail flag bit: nd239/324B -> nd216/300B, window352; rates .737654 -> .720000. */
// FUN_001f1c90 NONMATCHING
void func_001f1c90_y2(KwlnTask *task)
{
    void *work = task->workData;
    u32 params[12];
    s32 i;

    func_001f1240(task);
    BR_U32(params, 0) = 0;
    BR_U32(params, 0x2c) = BR_U32(work, 0x2a50);
    BR_U32(params, 0x28) = BR_U32(work, 0xb0);
    if (BR_S32(work, 0x2a5c) >= 0x65) {
        BR_U32(params, 0) |= 1;
    }
    for (i = 0; i < (s32)BR_U32(work, 0xb0); i++) {
        u8 *entry = (u8 *)work + i * 8 + 0x98;
        ((u32 *)params)[i * 3 + 1] = dat00171360(BR_U16(entry, 0)) != 0;
        ((u16 *)params)[i * 6 + 4] = BR_U16(entry, 0);
        ((u32 *)params)[i * 3 + 3] = BR_U32(entry, 4);
    }
    if ((BR_U32(work, 0) & 2) == 0 && (BR_U32(work, 0) & 8) != 0) {
        brRes00233c00();
    }
    brPanel00234a00((u32 *)params);
    brPanel00236280();
    BR_U32(work, 0) |= 0x200000;
}
#pragma opt_propagation reset

// FUN_001f1df0
void brRoot001f1df0(u16 *outIds, s32 *count)
{
    s32 i;
    u8 *root;
    u16 *dst;
    K_ASSERT(sBrRoot != NULL, 0x755);
    root = sBrRoot;
    outIds[0] = 1;
    for (i = 0; i < BR_S32(root, 0x114); i++) {
        dst = outIds + i;
        dst[1] = BR_U16(root + i * 2, 0x10c);
    }
    *count = BR_S32(root, 0x114) + 1;
}

// FUN_001f1e90
void brRoot001f1e90(KwlnTask *task)
{
    u32 *work = (u32 *)BR_TASK_WORK(task);
    K_ASSERT((~work[1] & 4) != 0, 0x79c);
    K_ASSERT((~work[2] & 4) != 0, 0x79d);
    brRes00233b20();
    work[0] |= 0x400000;
    work[1] |= 4;
    work[14] = 0;
    work[3] = 9;
}

// FUN_001f1f40
u32 func_001f1f40(void)
{
    u8 *work;
    u32 value;
    u32 condition;

    K_ASSERT(sBrRoot != NULL, 0x755);
    work = sBrRoot;
    K_ASSERT(work != NULL, 0x755);
    {
        u32 *root;
        root = (u32 *)sBrRoot;
        if ((root[0] & 0x8000) == 0) {
            condition = 0;
        } else if (root[0x25] == 0) {
            condition = 0;
        } else {
            condition = 1;
        }
    }
    if (condition == 1) {
        K_ASSERT(sBrRoot != NULL, 0x755);
        {
            u32 *root = (u32 *)sBrRoot;
            if ((root[0] & 0x8000) == 0) {
                value = 1;
            } else if (root[0x25] == 0) {
                value = 1;
            } else {
                value = func_001f5810((KwlnTask *)root[0x25]);
            }
        }
        return value == 1;
    }
    if ((BR_U32(work, 0) & 0x20000) != 0) {
        u32 bits = BR_U32(work, 0) & 0x2c;
        return (bits != 0) ^ 1;
    }
    return 0;
}

// FUN_001f2080 NONMATCHING
KwlnTask *func_001f2080(const u8 *params)
{
    u8 *work = (u8 *)BR_ALLOC2(0x2a220, 0x40000);
    KwlnTask *task;
    KwlnTask *child;
    RwV2d viewWindow;
    sBrCard = work;
    BR_U32(work, 4) = 0;
    BR_U32(work, 0x14) = 0;
    task = kwlnTaskCreateWithAutoPriority(NULL, 10, "battle result card",
                                          func_001f2300_update, func_001f2fd0_destroy, work);
    child = kwlnTaskInitEx("battle result ground", 0x106f, 1, 2,
                           func_001f2f50, NULL, work);
    BR_U32(work, 0x0c) = (u32)child;
    kwlnTaskAddChild(task, child);
    child = kwlnTaskInitEx("battle result draw", 0x18a6, 1, 2,
                           func_001f2f80, NULL, work);
    BR_U32(work, 0x10) = (u32)child;
    kwlnTaskAddChild(task, child);
    viewWindow.x = 1.0f;
    viewWindow.y = 0.5f;
    RwCameraSetViewWindow((RwCamera *)kwlnGetMainCamera(), &viewWindow);
    BR_U32(work, 4) |= 3;
    func_00219c90(work + 0x95c0);
    sflResInit((SflResourceManager *)(work + 0x60));
    func_00239170(work + 0xf0);
    func_0023d7a0(work + 0x8e90);
    func_0023d7f0();
    func_0024da00(work + 0xbd04);
    sflCamera0024d110(work + 0xbcf0);
    func_002534d0(work + 0xc100);
    sflScriptInit((SflScriptWork*)(work + 0xbf10));
    sflCursor0025a110(work + 0x1ed90);
    func_001f58f0(work + 0x1fd60);
    func_00215a50(work + 0x23280);
    func_00260970(work + 0x29320);
    sflCount0025b4a0(work + 0x29bf0);
    sflPersonaInit(work + 0x2a200);
    BR_U32(work, 0xe4) = 0;
    func_001f4650(task, params);
    BR_U32(work, 8) = 0;
    func_001f3270(task);
    BR_U32(work, 0x2a210) = 0;
    return task;
}

// FUN_001f2300 NONMATCHING
void *func_001f2300(KwlnTask *task)
{
    u8 *work = BR_TASK_WORK(task);
    u32 temp;
    if ((BR_U32(work, 4) & 0x80) != 0 && sflResIsGroundArchivePending() == 0) {
        BR_U32(work, 4) &= ~0x80u;
    }
    if ((BR_U32(work, 4) & 0x100) != 0 && sflGround0023c350() == 0) {
        BR_U32(work, 4) &= ~0x100u;
    }
    func_00219d90();
    sflResUpdate();
    func_00215fc0();
    func_001f5b20();
    switch (BR_U32(work, 8)) {
    case 1:
        if (sflResIsBaseArchivePending() == 0 && func_00254f20() == 0 && BR_U32(work, 0x2a210) != 0) {
            func_00254f70();
            if (BR_U32(work, 0xe4) == 0) {
                func_003c72d0_y2((void *)sflResGetBaseSpriteData());
                func_0023d130();
                sflResRequestEffectArchive();
                sflResRequestPersonaChangeSprite();
            }
            func_0023ee50();
            sflCard00259250();
            BR_U32(work, 8) = 2;
        }
        break;
    case 2:
        if (sflGround0023d1f0() == 0 && sflCard002592c0() == 0) {
            BR_U32(work, 8) = func_001f4990() ? 4 : 3;
        }
        break;
    case 3:
        if ((BR_U32(work, 4) & 2) == 0) {
            u16 v;
            sflResRequestTutorialArchive();
            v = *(u16*)DAT_007e094e_abs;
            if ((v & 0x9ff) != 0 || (*(u16*)DAT_007e094c_abs & 0x10) != 0) {
                func_001f4a00();
            }
        }
        break;
    case 7:
        if (sflCard002582b0() == 0) {
            sflScriptStartQueuedCommands();
            BR_U32(work, 0x1fd5c) = 0;
            BR_U32(work, 8) = 8;
        }
        break;
    case 8:
        temp = BR_U32(work, 0x1fd5c);
        if (temp < 15) {
            BR_U32(work, 0x1fd5c) = temp + 1;
        }
        if (BR_U32(work, 0x1fd5c) == 15 &&
            ((*(u16*)DAT_007e094e_abs & 0x40) != 0 ||
             (*(u16*)DAT_007e094c_abs & 0x10) != 0)) {
            func_00258a50();
            BR_U32(work, 8) = 9;
        } else {
            func_00259740();
            if (func_002596f0() == 0) {
                BR_U32(work, 0x14) = 0;
                BR_U32(work, 8) = 10;
            }
        }
        break;
    case 10:
        if ((s32)BR_U32(work, 0x14) >= 0) {
            func_001f55e0();
        } else {
            BR_U32(work, 0x14)++;
        }
        break;
    case 9:
        if (sflCard00258af0() == 0) {
            func_001f55e0();
        }
        break;
    case 11:
    {
        u8 *card;
        u32 randomValue;
        u32 chance;
        u32 ready;

        if (sflCount0025b640() != 0 &&
            (*(u16 *)DAT_007e094e_abs & 0x40) == 0 &&
            (*(u16 *)DAT_007e094c_abs & 0x10) == 0) {
            break;
        }
        sflCount0025b5f0();
        sflCursor0025aa70();
        func_001f56b0();
        sflCard00258490();
        card = func_00256030();
        func_0023f430();
        func_003c7650(0);
        BR_U32(work, 4) &= ~0x20u;
        if (BR_U32(work, 0xe4) < 7 && func_0016f190(0x1318) != 0) {
            randomValue = func_00488f30() % 100;
            chance = (&D_007CC378)[BR_U32(work, 0xe4)];
            func_005225a8(D_00684680, (s32)randomValue, (s32)chance);
            if (randomValue < (&D_007CC378)[BR_U32(work, 0xe4)]) {
                BR_U32(work, 4) |= 0x200;
            }
        }
        if (BR_U32(card, 4) != 2) {
            BR_U32(work, 4) &= ~0x200u;
        }
        if (func_002561d0(card) == 0) {
            BR_U32(work, 4) &= ~0x200u;
        }
        if (BR_U32(card, 4) == 0 && func_002561c0(card) == 0) {
            BR_U32(work, 4) &= ~0x200u;
        }
        ready = 0;
        if ((BR_U32(work, 4) & 0x200) == 0) {
            randomValue = func_00488f30() % 100;
            switch (BR_U32(card, 4)) {
            case 0:
                if (func_002561c0(card) != 0 && randomValue < 3) {
                    ready = 1;
                }
                break;
            case 1:
                if (func_002561d0(card) != 0 && randomValue < 10) {
                    ready = 1;
                }
                break;
            case 2:
                if (randomValue < 10) {
                    ready = 1;
                }
                break;
            }
        }
        func_0010a4e0(1, 0, 6, 1);
        if (ready != 0) {
            BR_U32(work, 8) = 13;
            sflCard00258090();
        } else {
            func_001f4750(task);
            sflCard002580e0();
        }
        break;
    }
    case 13:
        if (sflResIsEffectArchivePending() == 0) {
            func_0010a4e0(1, 15, 6, 13);
            func_0023f1d0();
            func_0023cda0();
            func_003c7430(5);
            func_003c74e0();
            BR_U32(work, 8) = 0x0e;
        }
        break;
    case 17:
    {
        u8 *card;

        if (sflPanel0023f390() == 0 && sflGround0023d0e0() == 0) {
            if ((BR_U32(work, 4) & 0x200) != 0) {
                func_003c7990_y2(1);
                if (func_003c7850_y2() == 0) {
                    func_003c7650(1);
                }
            } else {
                func_003c7990_y2(0);
                if (func_003c7850_y2() == 0) {
                    func_003c7650(0);
                }
            }
            if ((BR_U32(work, 4) & 0x40) != 0) {
                BR_U32(work, 4) &= ~0x40u;
            } else {
                card = func_00256030();
                temp = BR_U32(card, 4);
                switch (temp) {
                case 0:
                    if (func_002561c0(card) == 0 &&
                        func_001f5760(*(u16 *)(card + 8)) == 0) {
                        brRewardRegisterEntry((const f32 *)&card[4]);
                    }
                    break;
                case 1:
                    brRewardRegisterEntry((const f32 *)&card[4]);
                    break;
                case 2:
                    func_001f9630();
                    break;
                }
                if (func_002561d0(card) != 0) {
                    BR_U32(work, 4) |= 0x1000u;
                }
                if ((BR_U32(work, 4) & 0x200) != 0) {
                    BR_U32(work, 8) = 0x12;
                } else {
                    func_00255fe0();
                    func_001f53a0();
                }
            }
        }
        break;
    }
    case 18:
        if (sflResIsEffectArchivePending() == 0) {
            func_0023f010();
            func_0010a4e0(1, 2, 6, 13);
            if (BR_U32(work, 0xe4) == 0) {
                func_0023ca10();
            }
            BR_U32(work, 8) = 0x13;
        }
        break;
    case 19:
        if (sflPanel0023f390() == 0 && func_0023cd50() == 0) {
            if (func_0016f190(0x1416) == 0) {
                func_003c7430(7);
                func_0016f1f0(0x1416, 1);
            } else {
                func_003c7430(6);
            }
            func_003c74e0();
            BR_U32(work, 8) = 0x14;
        }
        break;
    case 20:
        func_003c7990_y2(0);
        if (func_003c7850_y2() == 0) {
            BR_U32(work, 8) = 0x15;
        }
        break;
    case 21:
        func_003c7650(1);
        temp = func_003c7610();
        if (temp == 0) {
            func_001f5650();
        } else if (temp == 1) {
            func_001f53a0();
        }
        break;
    case 25:
        if (sflCard00259380() == 0) {
            BR_U32(work, 0xe4)++;
            func_00255fe0();
            func_002550b0();
            func_00258300();
            func_001f3270(task);
        }
        break;
    case 14:
        func_003c7990_y2(0);
        if (func_003c7850_y2() == 0) {
            BR_U32(work, 8) = 0x0f;
        }
        break;
    case 15:
        if (func_003c78d0() == 0) {
            func_003c7650(0);
            printf(D_006846A0);
            temp = func_003c7610();
            if (temp == 0) {
                func_002594c0();
                BR_U32(work, 8) = 0x10;
            } else if (temp == 1) {
                func_001f4750(task);
            }
        }
        break;
    case 16:
        if (sflCard002595c0() == 0) {
            func_001f4750(task);
        }
        break;
    case 22:
        if (func_001f65e0() == 0) {
            BR_U32(work, 8) = 0x17;
        }
        break;
    case 23:
        if (sflResIsEffectArchivePending() == 0) {
            func_001f5510();
        }
        break;
    case 4:
        if (sflResIsTutorialArchivePending() == 0) {
            func_003c77a0();
            func_003c72d0_y2((void *)sflResGetTutorialFileUnchecked());
            func_003c7430(0);
            BR_U32(work, 8) = 5;
        }
        break;
    case 5:
        func_003c7990_y2(1);
        if (func_003c7850_y2() == 0) {
            func_003c7650(1);
            func_003c77a0();
            func_003c94e0((void *)sflResGetTutorialFileUnchecked());
            func_003c9790(0);
            BR_U32(work, 8) = 6;
        }
        break;
    case 6:
        func_003c7990_y2(1);
        if (func_003c7850_y2() == 0) {
            func_003c7650(1);
            func_003c77a0();
            sflResDestroyTutorialFiles();
            func_003c72d0_y2((void *)sflResGetBaseSpriteData());
            BR_U32(work, 8) = 3;
        }
        break;
    case 24:
        func_003c7990_y2(0);
        if (func_003c7850_y2() == 0) {
            func_003c7650(0);
            func_001f53a0();
        }
        break;
    case 0:
    case 12:
    default:
        break;
    }
    func_0025b690();
    func_0025a130();
    func_0023d8f0();
    func_0024db90();
    func_0024dc10();
    sflCamera0024d1c0();
    func_00253a40();
    func_002392d0();
    sflPersonaUpdate();
    BR_U32(work, 4) &= ~3u;
    return KWLNTASK_CONTINUE;
}

// FUN_001f2f50
void *func_001f2f50(KwlnTask *task)
{
    (void)task;
    func_0023b990();
    return KWLNTASK_CONTINUE;
}

// FUN_001f2f80
void *func_001f2f80(KwlnTask *task)
{
    func_00254b90();
    func_0025bbf0();
    func_0025a440();
    func_001f64c0();
    func_002168f0();
    func_0023e970();
    return KWLNTASK_CONTINUE;
}

// FUN_001f2fd0
void func_001f2fd0(KwlnTask *task)
{
    func_001f2ff0(task);
}

// FUN_001f2ff0
void func_001f2ff0(KwlnTask *task)
{
    sflPersonaShutdown(task);
    sflCount0025b4b0();
    func_001f5950();
    func_00215aa0();
    sflPsel00260a10();
    func_0025a120();
    func_00259630();
    sflCard00253560();
    sflCamera0024d160();
    func_0024da20();
    sflPanel0023d870();
    func_0023d7b0();
    sflGround00239280();
    func_0021a1b0();
    sflResShutdown();
    func_003c77a0();
    BR_FREE(task->workData);
    sBrCard = NULL;
}

// FUN_001f30b0
u32 func_001f30b0(KwlnTask *task)
{
    return BR_U32(BR_TASK_WORK(task), 4) & 1;
}

/* Retail 0x1f3270-0x1f4648: reconstructed result-card selection and reward dispatch. */






















/* Retail reconstruction spans 0x001f6630-0x001f6a5c: reward reset, card setup, and two indexed animation passes. */































/* Retail field-editor controller: menu dispatch, modal prompts, cursor updates,
 * and editor task lifetime management are reconstructed for states 0 through 8. */














/* Retail field archive loader: both asynchronous and cached-file paths now
 * build model arrays, resolve both supplemental descriptor tables, and place
 * every field record. */









































































/* Retail request completion and all thirteen top-level runtime states are
 * reconstructed, including the nested result and persona resource flows. */
// FUN_001f30d0
void func_001f30d0(KwlnTask *task)
{
    kwlnTaskDestroyWithHierarchy(task);
}

// FUN_001f30f0
void func_001f30f0(KwlnTask *task)
{
    u8 *work = BR_TASK_WORK(task);
    u32 rect[3];

    func_004c9d70(kwlnGetMainCamera(), 1.0f);
    func_0021a840();
    BR_U32(work, 0xe4) = 0;
    rect[0] = 0;
    rect[1] = 0x42c80000;
    rect[2] = 0;
    func_0024fd10(work + 0xc034);
    func_0024f9f0(work + 0xc034, (const float *)rect);
    func_0024da60(work + 0xc034);
    func_0024f090(work + 0xc034);
    rect[0] = 0;
    rect[1] = 0x42c80000;
    rect[2] = 0x43480000;
    func_0024fd10(work + 0xc098);
    func_0024f9f0(work + 0xc098, (const float *)rect);
    func_0024da60(work + 0xc098);
    func_0024f090(work + 0xc098);
    func_0024d8d0(work + 0xbf28);
    sflCamera0024d2e0(0, work + 0xbf28);
    sflCamera0024d940(work + 0xbf28, work + 0xc034);
    sflCamera0024d9a0(work + 0xbf28, work + 0xc098);
    sflCamera0024d280(kwlnGetMainCamera());
    func_0024d4c0(0);
    BR_U32(work, 0x2a210) = 1;
}
