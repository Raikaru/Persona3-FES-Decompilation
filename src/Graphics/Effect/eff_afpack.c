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



























// W419 afpack opt_lifetimes was neutral at nd1603/object2128; opt_common_subs off reached nd1593/object2228 (over window).
// FUN_001EE2E0 NONMATCHING
RuntimeWork* func_001ee2e0(const void* rawData)
{
    typedef struct RuntimeParsedEntry
    {
        void* model;
        void* config;
        u32 firstValue;
        u32 secondValue;
        u32 thirdValue;
        f32 scale;
    } RuntimeParsedEntry;
    typedef struct RuntimeParsedModel
    {
        f32 values[13];
    } RuntimeParsedModel;
    typedef struct RuntimeParsedConfig
    {
        u32 flags;
        void* sharedData;
        u8 colors[16];
    } RuntimeParsedConfig;
    typedef struct RuntimeParsedData
    {
        u32 identifier;
        u16 entryCount;
        u16 modelCount;
        u16 configCount;
        u16 reserved0a;
        RuntimeParsedEntry* entries;
        RuntimeParsedModel* models;
        RuntimeParsedConfig* configs;
        u32* vectors;
        void** payloads;
        void* owner;
    } RuntimeParsedData;
    typedef struct RuntimeInputHeader
    {
        u32 version;
        u32 identifier;
        u16 entryCount;
        u16 modelCount;
        u16 configCount;
        u16 reserved0e;
        u8 records[1];
    } RuntimeInputHeader;

    const RuntimeInputHeader* input;
    const u8* cursor;
    const u8* inputModels[16];
    const u8* inputConfigs[16];
    const u8* inputConfigColors[16];
    const u8* inputEntries[16];
    const u8* inputPayloads[16];
    RuntimeParsedData* output;
    u8* outputCursor;
    u32 allocationSize;
    u32 payloadSize;
    s32 entryIndex;
    s32 modelIndex;
    s32 configIndex;
    s32 colorIndex;
    s32 searchIndex;
    u16 referenceId;

    input = rawData;
    cursor = input->records;

    for (modelIndex = 0; modelIndex < input->modelCount; modelIndex++)
    {
        inputModels[modelIndex] = cursor;
        cursor += 0x38;
    }
    for (configIndex = 0;
         configIndex < input->configCount;
         configIndex++)
    {
        inputConfigs[configIndex] = cursor;
        cursor += 8;
        if (*(s16*)(inputConfigs[configIndex] + 4) == 0)
        {
            cursor += 4;
        }
        else
        {
            func_0019d3f0(D_00684508, 0x1b1);
        }
        inputConfigColors[configIndex] = cursor;
        if (*(s16*)(inputConfigs[configIndex] + 6) == 0)
        {
            cursor += 16;
        }
        else
        {
            func_0019d3f0(D_00684508, 0x1bd);
        }
    }
    for (entryIndex = 0; entryIndex < input->entryCount; entryIndex++)
    {
        inputEntries[entryIndex] = cursor;
        if (input->version == 0x65)
        {
            cursor += 0x20;
        }
        else if (input->version == 0x64)
        {
            cursor += 0x18;
        }
        else
        {
            func_0019d3f0(D_00684508, 0x1cb);
        }
        inputPayloads[entryIndex] = cursor;
        if (input->version == 0x65)
        {
            cursor += *(u32*)(inputEntries[entryIndex] + 0x1c);
        }
        else if (input->version == 0x64)
        {
            cursor += *(u32*)(inputEntries[entryIndex] + 0x14);
        }
    }

    allocationSize =
        0x24 +
        input->entryCount * sizeof(RuntimeParsedEntry) +
        input->modelCount * sizeof(RuntimeParsedModel) +
        input->configCount * sizeof(RuntimeParsedConfig) +
        input->entryCount * sizeof(void*) +
        input->entryCount * sizeof(u32) * 2;
    for (entryIndex = 0; entryIndex < input->entryCount; entryIndex++)
    {
        if (input->version == 0x65)
        {
            allocationSize += *(u32*)(inputEntries[entryIndex] + 0x1c);
        }
        else if (input->version == 0x64)
        {
            allocationSize += *(u32*)(inputEntries[entryIndex] + 0x14);
        }
    }

    output = FIELD_RUNTIME_PRIMARY_ALLOCATOR(allocationSize, 0x40000);
    outputCursor = (u8*)output + sizeof(RuntimeParsedData);
    output->entries = (RuntimeParsedEntry*)outputCursor;
    outputCursor += input->entryCount * sizeof(RuntimeParsedEntry);
    output->models = (RuntimeParsedModel*)outputCursor;
    outputCursor += input->modelCount * sizeof(RuntimeParsedModel);
    output->configs = (RuntimeParsedConfig*)outputCursor;
    outputCursor += input->configCount * sizeof(RuntimeParsedConfig);
    output->payloads = (void**)outputCursor;
    outputCursor += input->entryCount * sizeof(void*);
    for (entryIndex = 0; entryIndex < input->entryCount; entryIndex++)
    {
        output->payloads[entryIndex] = outputCursor;
        if (input->version == 0x65)
        {
            outputCursor += *(u32*)(inputEntries[entryIndex] + 0x1c);
        }
        else if (input->version == 0x64)
        {
            outputCursor += *(u32*)(inputEntries[entryIndex] + 0x14);
        }
    }
    output->vectors = (u32*)outputCursor;
    output->identifier = input->identifier;
    output->entryCount = input->entryCount;
    output->modelCount = input->modelCount;
    output->configCount = input->configCount;

    for (modelIndex = 0; modelIndex < input->modelCount; modelIndex++)
    {
        const f32* source = (const f32*)(inputModels[modelIndex] + 4);
        RuntimeParsedModel* model = &output->models[modelIndex];

        model->values[0] = source[0];
        model->values[1] = source[1];
        model->values[2] = source[2];
        model->values[3] = source[3];
        model->values[4] = source[4];
        model->values[5] = source[5];
        model->values[6] = source[6];
        model->values[7] = source[7];
        model->values[9] = source[8];
        model->values[8] = source[9];
        model->values[10] = source[10];
        model->values[11] = source[11];
        model->values[12] = source[12];
    }
    for (configIndex = 0;
         configIndex < input->configCount;
         configIndex++)
    {
        RuntimeParsedConfig* config = &output->configs[configIndex];

        config->flags = *(u16*)(inputConfigs[configIndex] + 2);
        if ((config->flags & 1) != 0)
        {
            config->sharedData = D_007CE2D4;
        }
        else
        {
            config->sharedData = NULL;
        }
        if (*(s16*)(inputConfigs[configIndex] + 6) == 0)
        {
            for (colorIndex = 0; colorIndex < 4; colorIndex++)
            {
                const u8* source =
                    inputConfigColors[configIndex] + colorIndex * 4;
                u8* color = (u8*)config + (colorIndex >> 1) * 8 +
                            (colorIndex & 1) * 4 + 8;

                color[0] = source[0];
                color[1] = source[1];
                color[2] = source[2];
                color[3] = source[3];
            }
        }
        else
        {
            func_0019d3f0(D_00684508, 0x231);
        }
    }

    for (entryIndex = 0; entryIndex < input->entryCount; entryIndex++)
    {
        const u8* source = inputEntries[entryIndex];
        RuntimeParsedEntry* entry = &output->entries[entryIndex];

        if (input->version == 0x65)
        {
            referenceId = *(u16*)(source + 2);
        }
        else if (input->version == 0x64)
        {
            referenceId = *(u16*)(source + 2);
        }
        for (searchIndex = 0;
             searchIndex < input->modelCount &&
             referenceId != *(u16*)inputModels[searchIndex];
             searchIndex++)
        {
        }
        entry->model = &output->models[searchIndex];

        if (input->version == 0x65)
        {
            referenceId = *(u16*)(source + 4);
        }
        else if (input->version == 0x64)
        {
            referenceId = *(u16*)(source + 4);
        }
        for (searchIndex = 0;
             searchIndex < input->configCount &&
             referenceId != *(u16*)inputConfigs[searchIndex];
             searchIndex++)
        {
        }
        entry->config = &output->configs[searchIndex];
        if (input->version == 0x65)
        {
            entry->firstValue = *(u16*)(source + 0x10);
        }
        else if (input->version == 0x64)
        {
            entry->firstValue = *(u16*)(source + 0x10);
        }
        if (input->version == 0x65)
        {
            entry->secondValue = *(u16*)(source + 0x12);
        }
        else if (input->version == 0x64)
        {
            entry->secondValue = *(u16*)(source + 0x12);
        }
        switch (input->version)
        {
            case 0x64:
                entry->thirdValue = 0;
                break;
            case 0x65:
                entry->thirdValue = *(u16*)(source + 0x14);
                break;
        }
        switch (input->version)
        {
            case 0x64:
                entry->scale = 10.0f;
                break;
            case 0x65:
                entry->scale = *(f32*)(source + 0x18);
                break;
        }
        switch (input->version)
        {
            case 0x64:
                output->vectors[entryIndex * 2] = *(u32*)(source + 8);
                output->vectors[entryIndex * 2 + 1] =
                    *(u32*)(source + 0x0c);
                break;
            case 0x65:
                output->vectors[entryIndex * 2] = *(u32*)(source + 8);
                output->vectors[entryIndex * 2 + 1] =
                    *(u32*)(source + 0x0c);
                break;
        }
        switch (input->version)
        {
            case 0x64:
                FUN_00521250(output->payloads[entryIndex],
                             inputPayloads[entryIndex],
                             *(u32*)(source + 0x14));
                break;
            case 0x65:
                FUN_00521250(output->payloads[entryIndex],
                             inputPayloads[entryIndex],
                             *(u32*)(source + 0x1c));
                break;
        }
    }
    return (RuntimeWork*)output;
}

// FUN_001EEB90
RuntimeWork* func_001eeb90(RuntimeWork* input)
{
    typedef struct RuntimeRenderInput
    {
        u32 version;
        s16 count;
        u8 reserved06[6];
        void* entries;
    } RuntimeRenderInput;
    typedef struct RuntimeRenderWork
    {
        u32 flags;
        RuntimeWork* input;
        u8* entries;
        void** renderObjects;
        void* buffer10;
        void* buffer14;
        u8 reserved18[8];
        u8 color[4];
    } RuntimeRenderWork;

    RuntimeRenderInput* config;
    RuntimeRenderWork* work;
    u8* allocationEnd;
    void* geometry;
    void* resource;
    void** renderObjects;
    void* materialResult;
    s32 renderOffset;
    s32 index;
    volatile u8 color[4];

    config = (RuntimeRenderInput*)input;
    allocationEnd = (u8*)0;
    /* load-bearing: removing this file's 14 zero-width barriers loses 6 MATCHes (001E3940 nd0->32, 001E7AA0 ->9, 001E9920 ->5, 001ECD90 ->21, 001EDF10 ->407, 001EEB90 ->22) - measured W172 */
    __asm__ volatile ("" : "+r"(allocationEnd));
    allocationEnd += 0x24;
    allocationEnd += config->count * 0x4c;
    allocationEnd += config->count * 8;
    allocationEnd += config->count * 0x20;
    allocationEnd += config->count * 0x18;
    work = FIELD_RUNTIME_PRIMARY_ALLOCATOR(
        (u32)allocationEnd, 0x40000);
    work->entries = (u8*)work + 0x24;
    work->renderObjects =
        (void**)(work->entries + config->count * 0x4c);
    work->buffer10 =
        (u8*)work->renderObjects + config->count * 8;
    work->buffer14 =
        (u8*)work->buffer10 + config->count * 0x20;
    work->flags = 0;
    work->input = input;
    work->color[0] = 0xff;
    work->color[1] = 0xff;
    work->color[2] = 0xff;
    work->color[3] = 0xfe;

    index = 0;
    if (config->count > 0)
    {
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = 0xfe;
        for (; index < config->count; index++)
        {
            func_001e9920(
                work->entries + index * 0x4c,
                (u8*)config->entries + index * 0x18);
            renderOffset = index * 8;
            materialResult = func_00494be0();
            renderObjects = work->renderObjects;
            __asm__ volatile (
                "addu %0, %0, %1"
                : "+r"(renderObjects)
                : "r"(renderOffset));
            renderObjects[1] = materialResult;
            resource =
                *(void**)(*(u8**)(work->entries + index * 0x4c) + 4);
            if ((*(u32*)resource & 1) != 0)
            {
                renderObjects = work->renderObjects;
                __asm__ volatile (
                    "addu %0, %0, %1"
                    : "+r"(renderObjects)
                    : "r"(renderOffset));
                func_00494d50(
                    renderObjects[1], *((void**)resource + 1));
            }
            renderOffset = index * 8;
            {
                void* material;
                u8 color0;
                u8 color1;
                u8 color2;
                u8 color3;

                renderObjects = work->renderObjects;
                __asm__ volatile (
                    "addu %0, %0, %1"
                    : "+r"(renderObjects)
                    : "r"(renderOffset));
                material = renderObjects[1];
                color0 = color[0];
                color1 = color[1];
                color2 = color[2];
                color3 = color[3];
                ((u8*)material)[4] = color0;
                ((u8*)material)[5] = color1;
                ((u8*)material)[6] = color2;
                ((u8*)material)[7] = color3;
            }

            {
                RuntimeWork* runtimeEntry;

                runtimeEntry =
                    (RuntimeWork*)(work->entries + index * 0x4c);
                /* load-bearing: removing this file's 14 zero-width barriers loses 6 MATCHes (001E3940 nd0->32, 001E7AA0 ->9, 001E9920 ->5, 001ECD90 ->21, 001EDF10 ->407, 001EEB90 ->22) - measured W172 */
                __asm__ volatile (
                    "" : "+r"(runtimeEntry) : : "memory");
                renderObjects = work->renderObjects;
                __asm__ volatile (
                    "addu %0, %0, %1"
                    : "+r"(renderObjects)
                    : "r"(renderOffset));
                geometry = func_001e8e80(runtimeEntry, renderObjects[1]);
            }
            work->renderObjects[index * 2] = func_00491880();
            func_004919b0(work->renderObjects[index * 2], geometry, 0);
            func_00492d10(work->renderObjects[index * 2], func_004caf10());
            func_00493b60(geometry);
            func_001ed8a0(work->entries + index * 0x4c, geometry);
            func_004933d0(geometry);
        }
    }
    return (RuntimeWork*)work;
}

// FUN_001EEE40. Bind render entries and initialize their runtime state.
void func_001eee40(RuntimeWork* rawWork)
{
    typedef struct RuntimeRenderCollection
    {
        u32 flags;
        void* config;
        void* renderObjects;
        u32 reserved;
        RuntimeResetWork* entries;
    } RuntimeRenderCollection;

    RuntimeRenderCollection* work;
    RuntimeResetWork* entry;
    s32 i;
    u32 status;

    work = (RuntimeRenderCollection*)rawWork;
    for (i = 0; i < *(s16*)((u8*)work->config + 4); i++)
    {
        entry = (RuntimeResetWork*)((u8*)work->entries + i * 0x20);
        entry->completedFlags = ((u32**)((u8*)work->config + 0x1c))[0][i];
        entry->work = (u8*)work->renderObjects + i * 0x4c;
        func_001eba50(entry);
    }
    work->flags |= 1;
    for (i = 0; i < *(s16*)((u8*)work->config + 4); i++)
    {
        entry = (RuntimeResetWork*)((u8*)work->entries + i * 0x20);
        func_001eba80((RuntimeCommandWork*)entry, &status);
    }
}

// FUN_001EEF20. Initialize the active field-runtime service.
void func_001eef20(void)
{
    void* resource;

    resource = func_00100d80(D_00684518, 0);
    func_001023a0(resource);
    D_007CE2D4 = func_004d1260(D_00684518, 0);
    func_00100ec0(resource);
    D_007CE2CC = NULL;
    D_007CE2C8 = NULL;
    D_007CE2D0 = func_00194e10(
        D_00684530, 0x104a, 1, 2, (void*)func_001ef060, NULL, 0);
}

// FUN_001EEFC0. Append a field runtime node to the active list.
void func_001eefc0(void* node)
{
    if (D_007CE2C8 == NULL)
    {
        *(void**)((u8*)node + 0x18) = NULL;
        *(void**)((u8*)node + 0x1c) = NULL;
        D_007CE2CC = (RuntimeListNode*)node;
        D_007CE2C8 = node;
        return;
    }
    else
    {
        *(void**)((u8*)node + 0x18) = D_007CE2C8;
        *(void**)((u8*)node + 0x1c) = NULL;
        *(void**)((u8*)D_007CE2C8 + 0x1c) = node;
    }
    D_007CE2C8 = node;
}

// FUN_001EF000. Check whether a runtime node is active in the field list.
s32 func_001ef000(RuntimeListNode* node)
{
    RuntimeListNode* current;

    current = D_007CE2CC;
    while (current != NULL)
    {
        if (current == node)
        {
            break;
        }
        current = *(RuntimeListNode**)((u8*)current + 0x1c);
    }
    if (current == NULL)
    {
        return 0;
    }
    return !(node->flags & 8);
}

// FUN_001EF060. Update, retire, and render every active field runtime node.
s32 func_001ef060(void)
{
    u32 active;
    RuntimeListNode* node;
    RuntimeWork* work;
    void* context;
    s32 index;
    u32 freeAddress;
    RuntimeListNode* current;

    for (node = D_007CE2CC; node != NULL; node = node->next)
    {
        if ((node->flags & 8) != 0)
        {
            func_001edbe0((RuntimeRenderCollection*)node);
        }
        else if ((node->flags & 2) != 0)
        {
            func_001edbe0((RuntimeRenderCollection*)node);
            node->flags &= ~2;
        }
    }

    current = D_007CE2CC;
    while (current != NULL)
    {
        node = current;
        current = current->next;
        active = 0;
        for (index = 0; index < *(s16*)((u8*)node->work + 4); index++)
        {
            active |= func_001ed9e0((u8*)*(void**)((u8*)node + 0x10) +
                                    index * 0x20);
        }

        if (active == 0)
        {
            if (D_007CE2CC == NULL)
            {
                func_0019d3f0(D_00684508, 0x322);
            }
            if (D_007CE2C8 == NULL)
            {
                func_0019d3f0(D_00684508, 0x323);
            }

            if (node->next != NULL)
            {
                node->next->previous = node->previous;
            }
            if (node->previous != NULL)
            {
                node->previous->next = node->next;
            }
            if (node == D_007CE2C8)
            {
                D_007CE2C8 = node->previous;
            }
            if (node == D_007CE2CC)
            {
                D_007CE2CC = node->next;
            }

            work = node->work;
            for (index = 0; index < *(s16*)((u8*)node->work + 4); index++)
            {
                func_001e9a90((u8*)node->vertices + index * 0x4c);
                func_004caf80(*(void**)((u8*)*(void**)((u8*)node->renderObjects +
                                                       index * 8) + 4));
                func_00491a80(*(void**)((u8*)node->renderObjects + index * 8));
                func_00494cc0(*(void**)((u8*)node->renderObjects + index * 8 + 4));
            }
            __asm__ volatile ("lui %0, 0x96\n\taddiu %0, %0, 0x17c" : "=r"(freeAddress));
            (*(void (**)(void*))freeAddress)(node);
            (*(void (**)(void*))freeAddress)(work);
        }
    }

    context = func_00198590();
    func_004c9d10(context);
    for (node = D_007CE2CC; node != NULL; node = node->next)
    {
        if ((node->flags & 8) != 0)
        {
            func_001edf10(node);
        }
        else if ((node->flags & 4) != 0)
        {
            func_001edf10(node);
            node->flags &= ~4;
        }
    }
    func_004c9d00(context);
    return 0;
}

// FUN_001EF340. Remove and destroy every field entry owned by an object.
void func_001ef340(void* owner)
{
    RuntimeListNode* current;
    RuntimeListNode* node;
    RuntimeWork* work;
    u32 freeAddress;
    s32 index;

    current = D_007CE2CC;
    while (current != NULL)
    {
        node = current;
        current = current->next;
        if (node->work->owner == owner)
        {
            if (D_007CE2CC == NULL)
            {
                func_0019d3f0(D_00684508, 0x322);
            }
            if (D_007CE2C8 == NULL)
            {
                func_0019d3f0(D_00684508, 0x323);
            }

            if (node->next != NULL)
            {
                node->next->previous = node->previous;
            }
            if (node->previous != NULL)
            {
                node->previous->next = node->next;
            }
            if (node == D_007CE2C8)
            {
                D_007CE2C8 = node->previous;
            }
            if (node == D_007CE2CC)
            {
                D_007CE2CC = node->next;
            }

            work = node->work;
            for (index = 0; index < *(s16*)((u8*)node->work + 4); index++)
            {
                func_001e9a90((u8*)node->vertices + index * 0x4c);
                func_004caf80(*(void**)((u8*)*(void**)((u8*)node->renderObjects +
                                                       index * 8) + 4));
                func_00491a80(*(void**)((u8*)node->renderObjects + index * 8));
                func_00494cc0(*(void**)((u8*)node->renderObjects + index * 8 + 4));
            }
            __asm__ volatile ("lui %0, 0x96\n\taddiu %0, %0, 0x17c" : "=r"(freeAddress));
            (*(void (**)(void*))freeAddress)(node);
            (*(void (**)(void*))freeAddress)(work);
        }
    }
}


/* Retail request completion and all thirteen top-level runtime states are
 * reconstructed, including the nested result and persona resource flows. */


// FUN_001EF500. Allocate and initialize the field runtime and its task hierarchy.
RuntimeTask* func_001ef500(RuntimeTask* parent)
{
    RuntimeTask* task;
    RuntimeWork* work;
    RuntimeTask* child;
    u8* bytes;
    struct
    {
        f32 rectangle[4];
        u8 reserved[28];
        u8 color[4];
    } layout;

    work = FIELD_RUNTIME_PRIMARY_ALLOCATOR(0xa7a0, 0x40000);
    bytes = (u8*)work;
    D_007CE2D8 = work;
    *(u32*)(bytes + 0x00) = 0;
    *(u32*)(bytes + 0x04) = 0;
    *(u32*)(bytes + 0x08) = 0;
    *(u32*)(bytes + 0x3c) = 0;
    *(u32*)(bytes + 0x108) = 0;
    *(u32*)(bytes + 0x2a5c) = 100;

    task = func_00194b80(NULL, 10, D_00684548, func_001ef7f0,
                        func_001f0970, work);

    child = func_00194e10(D_00684560, 0x106f, 1, 2,
                          func_001f07a0, NULL, work);
    *(RuntimeTask**)(bytes + 0x18) = child;
    func_00195550(task, child);

    child = func_00194e10(D_00684560, 0x1488, 1, 2,
                          func_001f08c0, NULL, work);
    *(RuntimeTask**)(bytes + 0x1c) = child;
    func_00195550(task, child);

    child = func_00194e10(D_00684560, 0x18bf, 1, 2,
                          func_001f0900, NULL, work);
    *(RuntimeTask**)(bytes + 0x20) = child;
    func_00195550(task, child);

    child = func_00194e10(D_00684560, 0x18ab, 1, 2,
                          func_001f0940, NULL, work);
    *(RuntimeTask**)(bytes + 0x24) = child;
    func_00195550(task, child);

    *(u32*)(bytes + 0x94) = 0;
    func_001f0ad0(task, parent);
    func_00233970(bytes + 0x390);
    func_00234820(bytes + 0x3e0);
    func_002626e0(bytes + 0x2a60);
    brPersonaInit(bytes + 0x63d0);
    func_00272330(bytes + 0x180);
    func_00275a70(bytes + 0x63e0);
    func_00276910(bytes + 0x6a00);
    func_00276d10(bytes + 0x6a10);

    func_0021eac0(bytes + 0xa690, 0.0f);
    layout.rectangle[0] = 0.0f;
    layout.rectangle[1] = 0.0f;
    layout.rectangle[2] = 640.0f;
    layout.rectangle[3] = 448.0f;
    func_0021d8e0(bytes + 0xa690, layout.rectangle);
    layout.color[0] = 0;
    layout.color[1] = 120;
    layout.color[2] = 180;
    layout.color[3] = 255;
    func_0021d950(bytes + 0xa690, layout.color);

    if ((work->flags & 2) != 0)
    {
        *(void**)(bytes + 0x94) = func_001f2080(bytes + 0x120);
        func_001f48d0(*(void**)(bytes + 0x94));
        work->requestFlags |= 1;
    }
    else
    {
        func_002339d0();
        work->requestFlags |= 2;
    }
    work->state = 0;
    D_007CDF0C = 0;
    return task;
}

/* Retail request completion and all thirteen top-level runtime states are
 * reconstructed, including the nested result and persona resource flows. */
