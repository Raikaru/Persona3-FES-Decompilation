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
extern s32 datGetFlag(u32 flag);
extern void* func_001e8e80(RuntimeWork* rawWork, void* material);
extern RuntimeWork* func_001ee2e0(const void* data);
extern RuntimeWork* func_001eeb90();
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


extern void* RwCalloc(u32 count, u32 size, u32 hint);
extern void RwFree(void* memory);
extern void* kwlnTaskCreateWithAutoPriority(void* parent, s32 priority, const char* name, void* update, void* destroy, void* work);
extern void kwlnTaskDestroyWithHierarchy(void* task);
extern s32 kwlnTaskExists(void* task);
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
extern s32 H_Fade_IsFadeOutDone(void);
extern void H_Fade_FadeOut(void);
extern void H_Fade_FadeIn(void);
extern void H_Fade_SetType(s32 type);
extern void H_Fade_SetDuration(s32 duration);
extern void func_001e2430(void);
extern void* kwlnGetMainCamera(void);
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
extern void func_002362e0(void);
extern void func_003c7430(s32 mode);
extern s32 func_003c7850(void);
extern void func_003c7650(s32 mode);
extern void func_003c72d0(void* work);
extern void* func_002345d0(s32 mode);
extern void func_003c77a0(void);
extern void func_003c7990();
extern void func_003c7c20(s32 group, s32 id, s32 kind);
extern void func_0010a4e0(s32 a0, s32 a1, s32 a2, s32 a3);
extern void H_Snd_PlayBgm(s32 id, s32 restart);
extern void func_0010a370(s32 mode, const char* name);
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
extern s32 func_001f30b0(void* controller);
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
extern void func_001f0ff0(void);
extern void func_001f10b0(void);
extern void func_001f10f0(void);
extern void func_001f0fd0(RuntimeTask* task);
extern void func_001f0eb0(RuntimeTask* task);
extern void* func_001f1210(RuntimeTask* task);
extern u32 func_00175410(void);
extern s32 func_001fb1b0(s32 type, u16 id);
extern s32 func_0017d800(void);
extern u32 func_00173220(u16 id);
extern void func_003c7bc0(s32 group, u32 value);
extern void func_00275a90(void);
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
extern void func_001f0970(RuntimeTask* task);
extern s32 func_001f08c0(RuntimeTask* task);
extern s32 func_001f0900(RuntimeTask* task);
extern s32 func_001f0940(RuntimeTask* task);
extern void func_00195550(void* parent, void* child);
extern void func_001f0ad0(void* task, void* parent);
extern void func_00233970(void* work);
extern void func_00234820(void* work);
extern void func_002626e0(void* work);
extern void brPersonaInit(void* work);
extern void func_00272330(void* work);
extern void func_00275a70(void* work);
extern void func_00276910(void* work);
extern void func_00276d10(void* work);
extern void func_0021eac0(void* object, f32 value);
extern void func_0021d8e0(void* object, const f32* rectangle);
extern void func_0021d950(void* object, const u8* color);
extern void func_002339d0(void);
extern void* func_001f2080(void* work);
extern void func_001f48d0(void* work);
extern char D_00684548[];
extern char D_00684560[];
extern RuntimeWork* D_007CE2D8;
extern u32 D_007CDF0C;
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

/* Retail field-editor controller: menu dispatch, modal prompts, cursor updates,
 * and editor task lifetime management are reconstructed for states 0 through 8. */














/* Retail field archive loader: both asynchronous and cached-file paths now
 * build model arrays, resolve both supplemental descriptor tables, and place
 * every field record. */





































void func_001e88f0(RuntimeWork* work, s32 section, RuntimeVec3* output);




































/* Retail request completion and all thirteen top-level runtime states are
 * reconstructed, including the nested result and persona resource flows. */
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
                func_0010a4e0(1, 0, 6, 14);
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
            if (func_001f30b0(*(void**)((u8*)work + 0x94)) != 0)
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
                        func_003c7430(value);
                    }
                    else
                    {
                        func_003c7430(5);
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
                    func_003c7650(1);
                    value = *(s32*)(bytes + 0x154);
                    func_003c7c20(
                        0, ((u16*)(bytes + 0x140))[value], 5);
                    func_003c7430(6);
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
                    func_003c7650(1);
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
                            func_003c7430(value);
                        }
                        else
                        {
                            func_003c7430(5);
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
                        func_003c7650(0);
                        func_001f10b0();
                    }
                    else if (*(u32*)(bytes + 0xa680) == 2)
                    {
                        func_003c7990(1);
                        if (func_003c7850() != 0)
                        {
                            break;
                        }
                        func_003c7650(1);
                        func_001f10f0();
                    }
                    else
                    {
                        func_003c7990(1);
                        if (func_003c7850() != 0)
                        {
                            break;
                        }
                        func_003c7650(1);
                        func_001f0d70(task);
                    }
                    break;

                case 2:
                    func_003c7990(0);
                    if (func_003c7850() != 0)
                    {
                        break;
                    }
                    func_003c7650(0);
                    func_003c7c20(0, func_00175410() & 0xffff, 0);
                    func_003c7430(4);
                    func_0010a4e0(1, 0, 8, 0);
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
                        func_003c7650(1);
                        func_001f10f0();
                    }
                    else
                    {
                        func_003c7990(1);
                        if (func_003c7850() != 0)
                        {
                            break;
                        }
                        func_003c7650(1);
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
                    func_003c7bc0(
                        0, func_00173220(
                               ((u16*)(bytes + 0xd4))[
                                   *(s32*)(bytes + 0xc4)]));
                    func_003c7430(1);
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
                    func_003c7650(1);
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
                    func_0010a370(3, D_006845A0);
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
