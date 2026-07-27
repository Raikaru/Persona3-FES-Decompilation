#include "Utils.h"
#include "h_cdvd.h"
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

extern void* func_001a3b10(void* parent, u32 width, u32 height, u32 mode);
extern void func_001a3dc0(void* task, const void* descriptors, u32 count);
extern void func_001a3bf0(void* task, u32 request);
extern s32 func_001a4510(void* task);
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
extern u8 DAT_007e095e[];
extern u8 DAT_007e0960[];
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
    u8 reserved08[8];
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
extern u32 D_007CDF38;
extern void FUN_00523ac8(char* destination, const char* format, ...);
extern void FUN_005225a8(const char* format, ...);
extern void* func_004bad50(void* file, const char* path);
extern char D_006843F0[];
extern void* (*DAT_00960184)(u32, ...);
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
extern void func_001e0510(void* task, void* camera);
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
extern s32 func_001e2bd0(void);
extern void func_001e9a90(void* work);
extern s32 func_001ed9e0(void* work);
extern void func_001edbe0(void* work);
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
extern void func_003c7990(s32 mode);
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
extern void func_00264d80(void* work);
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

// FUN_001E1850 NONMATCHING
s32 func_001e1850(RuntimeTask* task)
{
    RuntimeWork* work;
    void* controller;

    work = task->workData;
    controller = NULL;
    switch (work->state)
    {
        case 0:
            work->resource = RwCalloc(1, 0x20, 2);
            work->selection = work->slots[5] & 0xff;
            work->state = 1;
            break;

        case 1:
            if ((work->requestFlags & 0x40) != 0)
            {
                switch (work->selection)
                {
                    case 0: controller = task; func_001e0510(task, kwlnGetMainCamera()); break;
                    case 1: controller = func_001e4b40(task); break;
                    case 2: controller = func_001e5850(task); break;
                    case 3: controller = func_001e6030(task); break;
                    case 4: controller = func_001e6a70(task); break;
                    default: break;
                }
                if (controller != NULL)
                {
                    work->childTask = controller;
                    work->state = 2;
                }
            }
            break;

        case 2:
            if (work->childTask == NULL || kwlnTaskExists(work->childTask) == 0)
            {
                if (work->resource != NULL)
                {
                    RwFree(work->resource);
                    work->resource = NULL;
                }
                work->state = 3;
            }
            break;

        case 3:
            if ((work->requestFlags & 0x20) != 0)
            {
                func_001e2930(0);
                func_001e2b10(1);
                Runtime_Clear(work, 0, 2);
                work->state = 4;
            }
            break;

        case 4:
            if ((work->requestFlags & 0x40) != 0)
            {
                work->selection = (work->selection + 1) & 0xff;
            }
            else if ((work->requestFlags & 0x20) != 0)
            {
                work->selection = (work->selection - 1) & 0xff;
            }
            else if ((work->requestFlags & 0x0a) != 0)
            {
                work->selection = (work->selection + 10) & 0xff;
            }
            else if ((work->requestFlags & 0x05) != 0)
            {
                work->selection = (work->selection - 10) & 0xff;
            }
            if ((work->requestFlags & 0x40) != 0 && func_001e2bd0() != 0)
            {
                work->completedFlags |= 1;
                work->state = 5;
            }
            break;

        default:
            return -1;
    }
    return 0;
}

// FUN_001E2300. Tear down global field-transition state.
void func_001e2300(RuntimeTask* task)
{
    func_001e2930(0);
    func_001e2b10(0);
    FUN_00521408(&D_007CE2B8, 0, 8);
    ((void (*)(void*))DAT_0096017c[0])(task->workData);
}

// FUN_001E2370. Create the field-transition task when scene state permits.
RuntimeTask* func_001e2370(RuntimeTask* parent)
{
    RuntimeWork* work;
    RuntimeTask* task;
    if (PTR_DAT_007cd540[2] == 0 || PTR_DAT_007cd540[0] == -1)
    {
        return NULL;
    }


    work = FIELD_RUNTIME_ALLOCATOR(1, 0x18, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreateWithAutoPriority(parent, 10, "field transition", func_001e1850, func_001e2300, work);
    func_001e2430();
    return task;
}

// FUN_001E2430
void func_001e2430(void)
{
    typedef struct RuntimeFieldDefinition
    {
        u16 resourceId;
        u8 reserved002[2];
        RuntimeVec3 position;
        f32 angles[3];
        u8 reserved01c[0x0c];
        u32 flags;
        u8 reserved02c[0xcc];
        struct RuntimeFieldDefinition* next;
        u8 reserved0fc[0x2c];
        void* resource;
        u8 reserved12c[0xb4];
        u16 type;
        u8 sourceType;
        u8 reserved1e3;
        u32 value;
        u32 angle;
        u8 reserved1ec[4];
        void* source;
    } RuntimeFieldDefinition;
    typedef struct RuntimeQuaternion
    {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    } RuntimeQuaternion;

    extern RuntimeFieldDefinition* func_003b5d50(u32 type);
    extern f32 func_001ad8b0(u32 angle);
    extern RuntimeMatrix* func_00318b60(void* resource);
    extern u8 func_0019c300(void* source);
    extern f32 func_0019c490(void* source);
    extern void* func_001a4cd0(s32 type);
    extern RuntimeMatrix* func_001a4e50(void* object);
    extern void func_004c2cc0(RuntimeQuaternion* quaternion);
    extern void func_004c2d20(RuntimeMatrix* matrix,
                              const RuntimeQuaternion* quaternion);
    extern void func_004c2f10(RuntimeMatrix* matrix);
    extern RuntimeVec3 D_00683FF0;
    extern RuntimeVec3 D_00684000;
    extern RuntimeVec3 D_00684010;

    RuntimeFieldDefinition* resourceDefinition;
    RuntimeFieldDefinition* taskDefinition;
    FieldRuntimeResourceNode* resourceNode;
    FieldRuntimeTaskNode* taskNode;
    u32 matrixFlags;
    RuntimeQuaternion quaternion;
    RuntimeVec3 firstAxis;
    RuntimeVec3 secondAxis;
    RuntimeVec3 thirdAxis;

    resourceDefinition = func_003b5d50(3);
    taskDefinition = func_003b5d50(8);

    while (resourceDefinition != NULL)
    {
        resourceNode = func_001e2850();
        resourceNode->resource = resourceDefinition->resource;
        resourceNode->resourceId = resourceDefinition->resourceId;
        resourceNode->areaId =
            *(u16*)((u8*)resourceDefinition->resource + 0xd4);
        resourceNode->roomId =
            *(u16*)((u8*)resourceDefinition->resource + 0xd6);
        resourceNode->angle = func_001ad8b0(resourceDefinition->angle);
        if ((resourceDefinition->flags & 0x80000000) != 0)
        {
            resourceNode->flags |= 1;
        }
        else
        {
            resourceNode->flags &= 0xfe;
        }
        resourceNode->type = resourceDefinition->type;
        resourceNode->value = resourceDefinition->value;
        resourceNode->sourceType = resourceDefinition->sourceType;
        resourceNode->matrix =
            *func_00318b60(resourceDefinition->resource);
        resourceNode->state = func_0019c300(resourceDefinition->source);
        resourceNode->scale = func_0019c490(resourceDefinition->source);
        resourceDefinition = resourceDefinition->next;
    }

    while (taskDefinition != NULL)
    {
        taskNode = func_001e2a20();
        firstAxis = D_00683FF0;
        secondAxis = D_00684000;
        thirdAxis = D_00684010;
        taskNode->resourceId = taskDefinition->resourceId;
        taskNode->task = func_001a4cd0(0);
        func_001a4e50(taskNode->task)->values[0] =
            func_001a4e50(taskNode->task)->values[5] =
                func_001a4e50(taskNode->task)->values[10] = 1.0f;
        func_001a4e50(taskNode->task)->values[12] =
            func_001a4e50(taskNode->task)->values[13] =
                func_001a4e50(taskNode->task)->values[14] =
                    func_001a4e50(taskNode->task)->values[6] =
                        func_001a4e50(taskNode->task)->values[8] =
                            func_001a4e50(taskNode->task)->values[9] =
                                func_001a4e50(taskNode->task)->values[1] =
                                    func_001a4e50(taskNode->task)->values[2] =
                                        func_001a4e50(taskNode->task)->values[4] =
                                            0.0f;
        matrixFlags =
            *(u32*)&func_001a4e50(taskNode->task)->values[3] | 0x20003;
        *(u32*)&func_001a4e50(taskNode->task)->values[3] = matrixFlags;
        func_004c31b0(func_001a4e50(taskNode->task),
                      &firstAxis, taskDefinition->angles[0], 2);
        func_004c31b0(func_001a4e50(taskNode->task),
                      &secondAxis, taskDefinition->angles[1], 2);
        func_004c31b0(func_001a4e50(taskNode->task),
                      &thirdAxis, taskDefinition->angles[2], 2);
        *(RuntimeVec3*)&func_001a4e50(taskNode->task)->values[12] =
            taskDefinition->position;
        func_004c2cc0(&quaternion);
        func_004c2d20(func_001a4e50(taskNode->task), &quaternion);
        func_004c2f10(func_001a4e50(taskNode->task));
        taskNode->matrix = *func_001a4e50(taskNode->task);
        taskDefinition = taskDefinition->next;
    }
}

// FUN_001E2810. Find a loaded field resource by its 16-bit identifier.
FieldRuntimeResourceNode* func_001e2810(u32 resourceId)
{
    FieldRuntimeResourceNode* node;

    node = D_007CE2B8;
    resourceId = (u16)resourceId;
    while (node != NULL)
    {
        if (node->resourceId == resourceId)
        {
            break;
        }
        node = node->next;
    }
    return node;
}

// FUN_001E2850. Allocate and prepend a field resource node.
FieldRuntimeResourceNode* func_001e2850(void)
{
    FieldRuntimeResourceNode* node;

    node = FIELD_RUNTIME_ALLOCATOR(1, 0x70, 0x40000);
    if (D_007CE2B8 != NULL)
    {
        D_007CE2B8->previous = node;
    }
    node->next = D_007CE2B8;
    D_007CE2B8 = node;
    return node;
}

// FUN_001E28A0. Unlink and release a field resource node.
void func_001e28a0(FieldRuntimeResourceNode* node, s32 releaseResource)
{
    if (releaseResource == 1)
    {
        func_003b7090(node->resourceId);
    }
    if (node->previous != NULL)
    {
        node->previous->next = node->next;
    }
    else
    {
        D_007CE2B8 = node->next;
    }
    if (node->next != NULL)
    {
        node->next->previous = node->previous;
    }
    ((void (*)(void*))DAT_0096017c[0])(node);
}

// FUN_001E2930
void func_001e2930(s32 enabled)
{
    FieldRuntimeResourceNode* node;

    node = D_007CE2B8;
    while (node != NULL)
    {
        if (enabled == 1)
        {
            func_003b7090(node->resourceId);
        }
        if (node->previous != NULL)
        {
            node->previous->next = node->next;
        }
        else
        {
            D_007CE2B8 = node->next;
        }
        if (node->next != NULL)
        {
            node->next->previous = node->previous;
        }
        (*(void (**)(void*))0x0096017C)(node);
        node = node->next;
    }
}

// FUN_001E29E0. Find a field task by its 16-bit resource identifier.
FieldRuntimeTaskNode* func_001e29e0(u32 resourceId)
{
    FieldRuntimeTaskNode* node;

    node = D_007CE2BC;
    resourceId = (u16)resourceId;
    while (node != NULL)
    {
        if (node->resourceId == resourceId)
        {
            break;
        }
        node = node->next;
    }
    return node;
}

// FUN_001E2A20. Allocate and prepend a field task node.
FieldRuntimeTaskNode* func_001e2a20(void)
{
    FieldRuntimeTaskNode* node;

    node = FIELD_RUNTIME_ALLOCATOR(1, 0x60, 0x40000);
    if (D_007CE2BC != NULL)
    {
        D_007CE2BC->previous = node;
    }
    node->next = D_007CE2BC;
    D_007CE2BC = node;
    return node;
}

// FUN_001E2A70. Unlink and release a field task node.
void func_001e2a70(FieldRuntimeTaskNode* node, s32 releaseResource)
{
    if (releaseResource == 1)
    {
        func_003b7090(node->resourceId);
    }
    func_00195020(node->task);
    if (node->previous != NULL)
    {
        node->previous->next = node->next;
    }
    else
    {
        D_007CE2BC = node->next;
    }
    if (node->next != NULL)
    {
        node->next->previous = node->previous;
    }
    ((void (*)(void*))DAT_0096017c[0])(node);
}

// FUN_001E2B10
void func_001e2b10(s32 enabled)
{
    FieldRuntimeTaskNode* node;

    node = D_007CE2BC;
    while (node != NULL)
    {
        if (enabled == 1)
        {
            func_003b7090(node->resourceId);
        }
        kwlnTaskDestroyWithHierarchy(node->task);
        if (node->previous != NULL)
        {
            node->previous->next = node->next;
        }
        else
        {
            D_007CE2BC = node->next;
        }
        if (node->next != NULL)
        {
            node->next->previous = node->previous;
        }
        (*(void (**)(void*))0x0096017C)(node);
        node = node->next;
    }
}

// FUN_001E2BD0. Serialize and release the active field-transition lists.
s32 func_001e2bd0(void)
{
    typedef struct RuntimeTransitionHeads
    {
        void* first;
        void* second;
    } RuntimeTransitionHeads;
    typedef struct RuntimeSerializedHeader
    {
        u32 magic;
        u32 version;
        u32 firstCount;
        u32 firstSize;
        u32 secondCount;
        u32 secondSize;
    } RuntimeSerializedHeader;

    RuntimeTransitionHeads* heads;
    RuntimeSerializedHeader* header;
    u8* first;
    u8* second;
    u8* initialSecond;
    u8* output;
    void* allocation;
    s32 firstCount;
    s32 secondCount;

    heads = func_001e1840();
    first = heads->first;
    heads = func_001e1840();
    initialSecond = heads->second;
    if (D_007CE2C0 == 1)
    {
        return 0;
    }
    if (PTR_DAT_007cd540[0] == -1)
    {
        return 0;
    }

    firstCount = 0;
    while (first != NULL)
    {
        first = *(u8**)(first + 0x6c);
        firstCount++;
    }
    secondCount = 0;
    while (initialSecond != NULL)
    {
        initialSecond = *(u8**)(initialSecond + 0x58);
        secondCount++;
    }

    allocation = FIELD_RUNTIME_ALLOCATOR(
        1, firstCount * 0x70 + sizeof(RuntimeSerializedHeader) + secondCount * 0x60,
        0x40000);
    header = allocation;
    header->magic = 0x12345678;
    header->version = 0x10001;
    header->firstCount = firstCount;
    header->firstSize = 0x70;
    header->secondCount = secondCount;
    header->secondSize = 0x60;
    output = (u8*)(header + 1);

    heads = func_001e1840();
    first = heads->first;
    while (first != NULL)
    {
        FUN_00521250(output, first, 0x70);
        output += 0x70;
        first = *(u8**)(first + 0x6c);
    }
    heads = func_001e1840();
    second = heads->second;
    while (second != NULL)
    {
        FUN_00521250(output, second, 0x60);
        output += 0x60;
        second = *(u8**)(second + 0x58);
    }
    ((void (*)(void*))DAT_0096017c[0])(allocation);
    return 1;
}

// FUN_001E2DA0. Request the selected field archive when no request is active.
HCdvd* func_001e2da0(u16 majorId, u16 minorId, s16 variant)
{
    char path[128];
    HCdvd* result;

    if (K_Fldrc_GetFldPacCdvd() == NULL)
    {
        sprintf(path, D_00684020, majorId, minorId, (s32)variant);
        if (H_Cdvd_FileExists(path) == 0)
        {
            result = NULL;
        }
        else
        {
            result = H_Cdvd_Request(path, HCDVD_FILENORMAL);
        }
    }
    else
    {
        result = (HCdvd*)1;
    }
    return result;
}

// FUN_001E2E50 NONMATCHING
u32 func_001e2e50(void* request, void** outFileMemory,
                  u16 majorId, u16 minorId, s16 variant)
{
    u8* field;
    u8* fileMemory;
    u32 fileSize;
    u32 modelCount;
    u32 placementCount;
    u32 i;
    u32 modelIndex;
    u32* metadata;
    Model** models;

    if (outFileMemory != NULL)
    {
        *outFileMemory = NULL;
    }
    if (request == NULL)
    {
        return true;
    }

    fileMemory = NULL;
    fileSize = 0;
    if (K_Fldrc_GetFldPacCdvd() != NULL)
    {
        char path[128];

        sprintf(path, D_00684060, majorId, minorId, (s32)variant);
        fileMemory = (u8*)H_Cdvd_CacheFindFile(path, &fileSize);
        if (fileMemory == NULL)
        {
            return false;
        }
    }
    else
    {
        if (H_Cdvd_IsFileLoaded((HCdvd*)request) == 0)
        {
            return false;
        }
        fileMemory = (u8*)((HCdvd*)request)->fileMemory;
        fileSize = ((HCdvd*)request)->fileSize;
    }
    if (outFileMemory != NULL)
    {
        *outFileMemory = fileMemory;
    }

    field = (u8*)K_Field_Get();
    modelCount = *(u32*)(fileMemory + 0x08);
    *(u32*)(field + 0x10c0) = modelCount;
    models = (Model**)RwCalloc(1, modelCount * sizeof(Model*), 0x40000);
    metadata = (u32*)RwCalloc(1, modelCount * 9 * sizeof(u32), 0x40000);
    *(Model***)(field + 0x10c4) = models;
    *(u32**)(field + 0x10c8) = metadata;
    if (modelCount != 0 && (models == NULL || metadata == NULL))
    {
        return false;
    }

    modelIndex = 0;
    for (i = 0; i < modelCount; i++)
    {
        u8* record = fileMemory + 0x18 + i * 0x70;
        u16 type = *(u16*)(record + 0x04);
        u16 id = *(u16*)(record + 0x06);
        Model* model;

        if (type == MODEL_TYPE_FLD && id == 0xffff &&
            (*(u32*)0x007ce200 == 1))
        {
            model = mdlCreateFromPath(type, id, D_00684040, MDL_READASYNC);
        }
        else
        {
            model = mdlCreateAndResolvePath(type, id, MDL_READASYNC);
        }
        if (model != NULL)
        {
            models[modelIndex] = model;
            metadata[modelIndex * 9 + 2] = i;
            modelIndex++;
        }
    }

    placementCount = *(u32*)(fileMemory + 0x10);
    for (i = 0; i < placementCount; i++)
    {
        u8* record = fileMemory + 0x18 + i * 0x60;
        u16 resourceId = (u16)(*(u16*)(record + 0x50) & 0x3ff);
        f32 angles[3];

        resourceId = func_003b5e90(resourceId);
        angles[0] = func_001a5b30(record + 0x10);
        angles[1] = func_001a5aa0(record + 0x10);
        angles[2] = func_001a5bc0(record + 0x10);
        func_003b78b0(resourceId, record + 0x40, angles);
    }
    (void)fileSize;
    return true;
}

// FUN_001E3940
s32 func_001e3940(void* resource, u8* fileData)
{
    typedef struct RuntimeFieldDescriptor
    {
        s32 type;
        void* data;
        s32 recordIndex;
        u8 reserved0c[0x18];
    } RuntimeFieldDescriptor;
    typedef struct RuntimeFieldRecord
    {
        u8 reserved00[8];
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
    } RuntimeFieldRecord;
    typedef struct RuntimeFieldObject
    {
        u8 reserved000[0x28];
        u32 flags;
        u8 reserved02c[0xfc];
        void* model;
        u8 reserved12c[0xb4];
        u16 type;
        u8 sourceType;
        u8 reserved1e3;
        u32 value;
        void* angleController;
        void* frame;
        void* stateController;
        s32 descriptorType;
        void* firstDescriptor;
        void* secondDescriptor;
        u8 reserved200[0x10];
        void* effect;
    } RuntimeFieldObject;
    typedef struct RuntimeScaleDescriptor
    {
        u8 reserved00[6];
        s16 animationId;
        u8 reserved08[0x0c];
        f32 scale;
    } RuntimeScaleDescriptor;
    typedef struct RuntimeEffectDescriptor
    {
        u8 reserved00[0x68];
        s16 animationId;
        u8 reserved6a[0x0a];
        s32 effectIndex;
    } RuntimeEffectDescriptor;

    extern s32 func_00316f70(void* value);
    extern s32 func_001b7e30(void);
    extern u16 func_003b6270(u16 resourceId, u8 type, void* model);
    extern void func_001a0dc0(u16 resourceId, s32 enabled);
    extern RuntimeFieldObject* func_003b5d10(u16 resourceId);
    extern RuntimeMatrix* func_00318b60(void* model);
    extern f32 func_001a5b30(const RuntimeMatrix* matrix);
    extern f32 func_001a5aa0(const RuntimeMatrix* matrix);
    extern f32 func_001a5bc0(const RuntimeMatrix* matrix);
    extern void func_003b78b0(u16 resourceId, const RuntimeVec3* position,
                              const RuntimeVec3* angles);
    extern void func_001ad8c0(f32 value, void* controller);
    extern void func_0019c320(f32 value, void* controller);
    extern void* func_00317450(Model* model);
    extern void func_00318a50(void* frame, const RuntimeVec3* axis,
                              f32 angle, s32 mode);
    extern void func_00318a90(void* frame, const RuntimeVec3* scale,
                              s32 mode);
    extern void func_00318a30(void* frame, const RuntimeVec3* position,
                              s32 mode);
    extern void func_00317730(void* frame);
    extern void func_003182d0(void* model, s32 slot, s16 animationId,
                              s32 mode, s32 enabled);
    extern s32 func_0016f190(s32 flag);
    extern void* func_001dd460(void* controller, s32 type, s32 priority);
    extern void func_001dd5f0(void* effect, void* model);
    extern void func_001dd5e0(void* effect, s32 enabled);
    extern void func_001b8cf0(RuntimeFieldDescriptor* descriptor);
    extern void func_001a1540(s32 first, s32 second, s32 size,
                              const char* name);
    extern RuntimeVec3 D_00684080;
    extern char D_00684090[];
    extern Model* gFldBaseMdl;

    RuntimeFieldRecord* record;
    RuntimeFieldObject* object;
    RuntimeMatrix* matrix;
    RuntimeVec3 angles;
    RuntimeVec3 axis;
    RuntimeVec3 scale;
    RuntimeVec3 animationScale;
    u8* recordBase;
    u32 readyIndex;
    u32 index;
    u32 descriptorOffset;
    u16 objectId;
    u8 objectType;
    s32 effectType;
    void (**allocator)(void*);

    if (resource == NULL)
    {
        return true;
    }

    for (readyIndex = 0;
         readyIndex < *(u32*)(func_001b9120() + 0x10c0);
         readyIndex++)
    {
        if (func_00316f70(
                (*(void***)(func_001b9120() + 0x10c4))[readyIndex]) == 0)
        {
            return false;
        }
    }
    if (func_001b7e30() == 0)
    {
        return false;
    }
    if (func_001b0910() == 0)
    {
        fileData = *(u8**)((u8*)resource + 0x110);
    }
    else if (fileData != NULL)
    {
        __asm__ volatile (".set reorder" : "+r"(fileData));
    }
    else
    {
        return true;
    }

    recordBase = fileData + 0x18;
    for (index = 0;
         index < *(u32*)(func_001b9120() + 0x10c0);
         index++)
    {
        RuntimeFieldDescriptor* descriptor;

        objectType = 3;
        axis = D_00684080;
        descriptorOffset = index * sizeof(RuntimeFieldDescriptor);
        descriptor = (RuntimeFieldDescriptor*)
            ((u8*)*(RuntimeFieldDescriptor**)
                (func_001b9120() + 0x10c8) + descriptorOffset);
        record = (RuntimeFieldRecord*)
            (recordBase + *(u32*)(fileData + 0x0c) *
             descriptor->recordIndex);
        if (*(u32*)(fileData + 4) > 0x10000)
        {
            objectType = record->state;
        }
        objectId = func_003b6270(
            record->resourceId & 0x3ff, objectType & 0xff,
            (*(void***)(func_001b9120() + 0x10c4))[index]);
        func_001a0dc0(objectId, 1);
        object = func_003b5d10(objectId);
        matrix = func_00318b60(
            (*(void***)(func_001b9120() + 0x10c4))[index]);
        *matrix = record->matrix;
        angles.x = func_001a5b30(&record->matrix);
        angles.y = func_001a5aa0(&record->matrix);
        angles.z = func_001a5bc0(&record->matrix);
        func_003b78b0(objectId, (RuntimeVec3*)((u8*)record + 0x50),
                      &angles);
        func_004c2f10(func_00318b60(
            (*(void***)(func_001b9120() + 0x10c4))[index]));
        {
            void* controller;

            controller = object->angleController;
            __asm__ volatile ("" : "+r"(controller));
            func_001ad8c0(record->angle, controller);
            controller = object->stateController;
            __asm__ volatile ("" : "+r"(controller));
            func_0019c320(record->scale, controller);
        }
        scale.x = record->angle;
        scale.y = record->angle;
        scale.z = record->angle;
        object->frame = func_00317450(gFldBaseMdl);
        func_00318a50(object->frame, &axis, angles.y, 2);
        func_00318a90(object->frame, &scale, 2);
        func_00318a30(object->frame,
                      (RuntimeVec3*)&record->matrix.values[12], 2);
        func_00317730(object->frame);
        if ((record->flags & 1) != 0)
        {
            object->flags |= 0x80000000;
        }
        else
        {
            object->flags &= 0x7fffffff;
        }
        object->type = record->type;
        object->value = record->value;
        object->sourceType = record->sourceType;
        object->descriptorType =
            (*(RuntimeFieldDescriptor**)
                (func_001b9120() + 0x10c8))[index].type;
        if (object->descriptorType == 1)
        {
            {
                RuntimeFieldDescriptor* descriptorTable;

                descriptorTable = *(RuntimeFieldDescriptor**)
                    (func_001b9120() + 0x10c8);
                __asm__ volatile (
                    "addu %0, %0, %1"
                    : "+r"(descriptorTable)
                    : "r"(descriptorOffset));
                object->firstDescriptor = descriptorTable->data;
            }
            if (((RuntimeScaleDescriptor*)object->firstDescriptor)->scale !=
                0.0f)
            {
                animationScale.z =
                    ((RuntimeScaleDescriptor*)object->firstDescriptor)->scale;
                animationScale.y =
                    ((RuntimeScaleDescriptor*)object->firstDescriptor)->scale;
                animationScale.x =
                    ((RuntimeScaleDescriptor*)object->firstDescriptor)->scale;
                func_00318a90(object->model, &animationScale, 1);
            }
            {
                s16 animationId;

                animationId =
                    ((RuntimeScaleDescriptor*)object->firstDescriptor)->
                        animationId;
                __asm__ volatile ("" : "+r"(animationId));
                func_003182d0(object->model, 0, animationId, 8, 1);
            }
        }
        else if (object->descriptorType == 2)
        {
            {
                RuntimeFieldDescriptor* descriptorTable;

                descriptorTable = *(RuntimeFieldDescriptor**)
                    (func_001b9120() + 0x10c8);
                __asm__ volatile (
                    "addu %0, %0, %1"
                    : "+r"(descriptorTable)
                    : "r"(descriptorOffset));
                object->secondDescriptor = descriptorTable->data;
            }
            {
                s16 animationId;

                animationId =
                    ((RuntimeEffectDescriptor*)object->secondDescriptor)->
                        animationId;
                __asm__ volatile ("" : "+r"(animationId));
                func_003182d0(object->model, 0, animationId, 8, 1);
            }
            if (((RuntimeEffectDescriptor*)object->secondDescriptor)->
                    effectIndex != 0xff)
            {
                effectType = 3;
                if (func_0016f190(
                        ((RuntimeEffectDescriptor*)object->secondDescriptor)->
                            effectIndex + 0x900))
                {
                    effectType = 2;
                }
                else if (func_0016f190(
                             ((RuntimeEffectDescriptor*)
                                 object->secondDescriptor)->effectIndex +
                             0x940))
                {
                    effectType = 1;
                }
                object->effect = func_001dd460(
                    object->angleController, effectType, 0x1058);
                func_001dd5f0(object->effect, object->model);
                func_001dd5e0(object->effect, 1);
            }
            func_001b8cf0(
                &(*(RuntimeFieldDescriptor**)
                    (func_001b9120() + 0x10c8))[index]);
        }
    }

    allocator = (void (**)(void*))DAT_0096017c;
    allocator[0](*(void**)(func_001b9120() + 0x10c4));
    allocator[0](*(void**)(func_001b9120() + 0x10c8));
    if (*(u32*)(fileData + 4) <= 0x10000)
    {
        func_001a1540(0, 0, 0x184, D_00684090);
    }
    *(u32*)(func_001b9120() + 0x10c0) = 0;
    *(void**)(func_001b9120() + 0x10c4) = NULL;
    if (func_001b0910() == 0)
    {
        func_00100ec0(resource);
    }
    return true;
}

// FUN_001E3F10 NONMATCHING
void func_001e3f10(RuntimeTask* task)
{
    RuntimeControllerWork* work;
    RuntimeVec3 axis;
    RuntimeVec3 base;
    RuntimeVec3 direction;
    RuntimeVec3 center;
    RuntimeVec3 adjusted;
    RuntimeVec3 cameraPosition;
    RuntimeVec3 cameraDirection;
    RuntimeVec3 position;
    RuntimeVec3 angles;
    RuntimeMatrix rotation;
    RuntimeMatrix* matrix;
    FieldRuntimeResourceNode* resourceNode;
    void* camera;
    void* object;
    void* frame;
    u32 input;
    u32 result;
    u32 value;
    u32 matrixFlags;
    s32 signedValue;
    u16 resourceId;
    f32 distance;
    f32 angle;
    f32 x;
    f32 y;

    work = (RuntimeControllerWork*)task->workData;
    switch (work->state)
    {
        case 0:
            work->windowTask = func_001a3b10(task, 0x122, 0xdc, 2);
            func_001a3f20(work->windowTask, D_00684120);
            func_001a3f20(work->windowTask, D_00684128);
            func_001a3bf0(work->windowTask, 1);
            work->state++;
            break;

        case 1:
            if ((DAT_007e094e & 0x40) != 0)
            {
                result = (u32)func_001a4510(work->windowTask);
                if (result == 0)
                {
                    func_00195020(work->windowTask);
                    work->windowTask = func_001a3b10(task, 0x20, 0x20, 2);
                    func_001a3dc0(work->windowTask, D_00684120, 8);
                    func_001a3bf0(work->windowTask, 1);
                    work->state = 2;
                }
                else if (result == 1)
                {
                    func_00195020(work->windowTask);
                    work->windowTask = func_001a3b10(task, 0x20, 0x20, 2);
                    func_001a3dc0(work->windowTask, D_00684220, 2);
                    func_001a3bf0(work->windowTask, 1);
                    work->state = 3;
                }
            }
            break;

        case 2:
            if ((DAT_007e094e & 0x40) != 0)
            {
                result = (u32)func_001a4510(work->windowTask);
                if (result == 7)
                {
                    work->majorId = (u16)*(u32*)func_001a41b0(
                        work->windowTask, 1);
                    work->minorId = (u16)*(u32*)func_001a41b0(
                        work->windowTask, 2);
                    resourceId = *(u16*)func_001a41b0(
                        work->windowTask, 0);
                    signedValue = *(s32*)func_001a41b0(
                        work->windowTask, 4);
                    work->angle = (f32)signedValue;
                    work->sourceType = (u8)*(u32*)func_001a41b0(
                        work->windowTask, 5);
                    signedValue = *(s32*)func_001a41b0(
                        work->windowTask, 6);
                    work->scale = (f32)signedValue;
                    work->sourceFlags = 0;
                    value = *(u32*)func_001a41b0(work->windowTask, 3);
                    if (value == 1)
                    {
                        work->flags |= 1;
                    }
                    else
                    {
                        work->flags &= (u8)~1;
                    }
                    value = ((u32)resourceId & 0x3ff) | 0xc00;
                    if (func_001e2810(value) != NULL)
                    {
                        func_001a1540((s32)task, 0, 0xb4, D_00684270);
                    }
                    else
                    {
                        work->model = func_00316e00(
                            work->majorId, work->minorId, 0);
                        work->state = 4;
                    }
                    break;
                }
            }
            if ((DAT_007e094e & 0x20) != 0)
            {
                work->state = 6;
            }
            break;

        case 3:
            if ((DAT_007e094e & 0x40) != 0)
            {
                result = (u32)func_001a4510(work->windowTask);
                if (result == 1)
                {
                    resourceId = *(u16*)func_001a41b0(
                        work->windowTask, 0);
                    work->majorId = 4;
                    work->minorId = 0xffff;
                    work->angle = 120.0f;
                    work->sourceType = 3;
                    work->scale = 60.0f;
                    work->sourceFlags = 1;
                    value = ((u32)resourceId & 0x3ff) | 0xc00;
                    if (func_001e2810(value) != NULL)
                    {
                        func_001a1540((s32)task, 0, 0xb4, D_00684270);
                    }
                    else
                    {
                        work->model = func_00316b40(
                            4, 0xffff, D_00684290, 0);
                        work->state = 4;
                    }
                    break;
                }
            }
            if ((DAT_007e094e & 0x20) != 0)
            {
                work->state = 6;
            }
            break;

        case 4:
            resourceId = *(u16*)func_001a41b0(work->windowTask, 0);
            if (func_00316f70(work->model) == 0)
            {
                break;
            }
            work->resourceId = func_003b6270(
                resourceId, work->sourceType, work->model);
            func_001a0dc0(work->resourceId, 1);
            object = func_003b5d10(work->resourceId);
            work->controller = *(void**)((u8*)object + 0x1e8);
            func_001ad8c0(work->angle, work->controller);
            func_001ad870(work->controller, 0x80000000);
            func_00195020(work->windowTask);
            camera = func_00198590();
            frame = *(void**)((u8*)camera + 4);
            matrix = (RuntimeMatrix*)func_004cb2f0(frame);
            cameraDirection.x = matrix->values[12];
            cameraDirection.y = matrix->values[13];
            cameraDirection.z = matrix->values[14];
            cameraPosition.x = matrix->values[8];
            cameraPosition.y = matrix->values[9];
            cameraPosition.z = matrix->values[10];
            func_004c69f0(&cameraPosition, &cameraPosition);
            cameraPosition.x *= 1000.0f;
            cameraPosition.y *= 1000.0f;
            cameraPosition.z *= 1000.0f;
            cameraDirection.x += cameraPosition.x;
            cameraDirection.y += cameraPosition.y;
            cameraDirection.z += cameraPosition.z;
            func_001adc20(work->controller, &cameraDirection);
            break;

        case 5:
            axis = D_00684260;
            input = DAT_007e094c;
            x = (f32)DAT_007e095e[1] * 2.0f - 128.0f;
            y = (f32)DAT_007e095e[0] * 2.0f - 128.0f;
            if ((input & 0x1000) != 0)
            {
                x = -128.0f;
            }
            if ((input & 0x4000) != 0)
            {
                x = 128.0f;
            }
            if ((input & 0x8000) != 0)
            {
                y = -128.0f;
            }
            if ((input & 0x2000) != 0)
            {
                y = 128.0f;
            }
            base.x = y;
            base.y = 0.0f;
            base.z = x;
            camera = func_00198590();
            frame = *(void**)((u8*)camera + 4);
            angle = func_001a5aa0(func_004cb2f0(frame));
            if (x < -48.0f || x > 48.0f ||
                y < -48.0f || y > 48.0f)
            {
                matrixFlags = *(u32*)&rotation.values[3];
                rotation.values[0] = 1.0f;
                rotation.values[5] = 1.0f;
                rotation.values[10] = 1.0f;
                rotation.values[1] = 0.0f;
                rotation.values[2] = 0.0f;
                rotation.values[4] = 0.0f;
                rotation.values[6] = 0.0f;
                rotation.values[8] = 0.0f;
                rotation.values[9] = 0.0f;
                rotation.values[12] = 0.0f;
                rotation.values[13] = 0.0f;
                rotation.values[14] = 0.0f;
                matrixFlags |= 0x20003;
                *(u32*)&rotation.values[3] = matrixFlags;
                func_004c31b0(&rotation, &axis, angle, 1);
                direction = base;
                func_004c69f0(&direction, &base);
                direction.x = -direction.x;
                direction.y = -direction.y;
                direction.z = -direction.z;
                func_004c6be0(&direction, &direction, &rotation);
                distance = (x + y) * D_007CB118[0] / 2.0f;
                func_001addf0(
                    distance, work->controller, &direction);
            }
            if (x < -48.0f || x > 48.0f)
            {
                position = D_00684260;
                distance = y * D_007CB118[1];
                func_001adff0(
                    distance, work->controller, &position);
            }
            if ((input & 6) != 0)
            {
                func_001ad940(&center, work->controller);
                adjusted = center;
                adjusted.y -= 10.0f;
                func_001adc20(work->controller, &adjusted);
            }
            if ((input & 9) != 0)
            {
                func_001ad940(&center, work->controller);
                adjusted = center;
                adjusted.y += 10.0f;
                func_001adc20(work->controller, &adjusted);
            }
            if ((input & 0x80) != 0)
            {
                func_001ae0d0(work->controller);
            }
            if ((input & 0x20) != 0)
            {
                func_003b7090(work->resourceId);
                work->state = 0;
                break;
            }
            if ((input & 0x40) != 0)
            {
                resourceNode = func_001e2850();
                resourceNode->resource = work->model;
                resourceNode->areaId = work->majorId;
                resourceNode->roomId = work->minorId;
                resourceNode->resourceId = work->resourceId;
                resourceNode->angle = work->angle;
                resourceNode->type = work->type;
                resourceNode->flags = work->flags;
                resourceNode->value = work->value;
                resourceNode->state = work->sourceType;
                resourceNode->sourceType = work->sourceFlags;
                resourceNode->scale = work->scale;
                object = func_003b5d10(work->resourceId);
                if ((resourceNode->flags & 1) != 0)
                {
                    *(u32*)((u8*)object + 0x28) |= 0x80000000;
                }
                else
                {
                    *(u32*)((u8*)object + 0x28) &= 0x7fffffff;
                }
                *(u16*)((u8*)object + 0x1e0) = resourceNode->type;
                *(u32*)((u8*)object + 0x1e4) = resourceNode->value;
                matrix = (RuntimeMatrix*)func_00318b60(work->model);
                resourceNode->matrix = *matrix;
                func_0019c320(
                    work->scale, *(void**)((u8*)object + 0x1f0));
                angles.x = func_001a5b30(&resourceNode->matrix);
                angles.y = func_001a5aa0(&resourceNode->matrix);
                angles.z = func_001a5bc0(&resourceNode->matrix);
                func_003b78b0(
                    resourceNode->resourceId,
                    (u8*)resourceNode + 0x50, &angles);
                func_001ad890(
                    *(void**)((u8*)object + 0x1e8), 0x80000000);
                matrix = (RuntimeMatrix*)func_00318b60(work->model);
                func_004c2f10(matrix);
                work->state = 0;
            }
            break;

        case 6:
            return;
    }
}

// FUN_001E4B10
void func_001e4b10(RuntimeTask* task, u32 request)
{
    ((void (*)(void*, u32))DAT_0096017c[0])(task->workData, request);
}

// FUN_001E4B40. Create the primary field controller task.
void* func_001e4b40(void* parent)
{
    void* work;

    work = FIELD_RUNTIME_ALLOCATOR(1, 0x30, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    return kwlnTaskCreateWithAutoPriority(
        parent, 0x106f, D_006842A8,
        (void*)func_001e3f10, (void*)func_001e4b10, work);
}

// FUN_001E4BC0 NONMATCHING
s32 func_001e4bc0(RuntimeTask* task)
{
    RuntimeControllerWork* work;
    FieldRuntimeResourceNode* node;
    FieldRuntimeResourceNode* selected;
    void* manager;
    void* object;
    RuntimeMatrix* matrix;
    RuntimeVec3 axis;
    RuntimeVec3 base;
    RuntimeVec3 direction;
    RuntimeVec3 center;
    RuntimeVec3 adjusted;
    RuntimeVec3 position;
    RuntimeVec3 angles;
    RuntimeMatrix rotation;
    char text[96];
    u32 input;
    u32 index;
    u32 result;
    u32 value;
    u32 matrixFlags;
    s32 signedValue;
    u32 count;
    f32 distance;
    f32 angle;
    f32 x;
    f32 y;

    work = (RuntimeControllerWork*)task->workData;
    switch (work->state)
    {
        case 0:
            manager = func_001e1840();
            node = *(FieldRuntimeResourceNode**)manager;
            count = 0;
            work->windowTask = func_001a3b10(task, 0x20, 0x20, 2);
            while (node != NULL)
            {
                FUN_00523ac8(
                    text, D_006842D0,
                    (u32)(node->resourceId & 0x3ff),
                    node->areaId, node->roomId);
                index = func_001a3f20(work->windowTask, text);
                *(FieldRuntimeResourceNode**)func_001a41b0(
                    work->windowTask, index) = node;
                count++;
                node = node->next;
            }
            *(u32*)((u8*)work + 0xc) = count;
            if (count != 0)
            {
                func_001a3bf0(work->windowTask, 1);
                work->state++;
            }
            else
            {
                func_00195020(work->windowTask);
                work->state = 6;
            }
            break;

        case 1:
            index = 0;
            count = *(u32*)((u8*)work + 0xc);
            while (index < count)
            {
                node = *(FieldRuntimeResourceNode**)func_001a41b0(
                    work->windowTask, index);
                object = func_003b5d10(node->resourceId);
                func_001ad890(
                    *(void**)((u8*)object + 0x1e8), 0x80000000);
                index++;
            }
            selected = *(FieldRuntimeResourceNode**)func_001a41b0(
                work->windowTask,
                (u32)func_001a4510(work->windowTask));
            object = func_003b5d10(selected->resourceId);
            func_001ad870(
                *(void**)((u8*)object + 0x1e8), 0x80000000);
            input = DAT_007e094e;
            if ((input & 0x40) != 0)
            {
                func_00195020(work->windowTask);
                work->model = selected->resource;
                work->resourceId = selected->resourceId;
                object = func_003b5d10(work->resourceId);
                func_001ad870(
                    *(void**)((u8*)object + 0x1e8), 0x80000000);
                work->windowTask = func_001a3b10(
                    task, 0x20, 0x20, 2);
                func_001a3dc0(work->windowTask, D_00684120, 8);
                *(u32*)func_001a41b0(work->windowTask, 4) =
                    (u32)(s32)work->angle;
                *(u32*)func_001a41b0(work->windowTask, 5) =
                    work->sourceType;
                *(u32*)func_001a41b0(work->windowTask, 6) =
                    (u32)(s32)work->scale;
                if ((work->flags & 1) != 0)
                {
                    *(u32*)func_001a41b0(work->windowTask, 3) = 1;
                }
                else
                {
                    *(u32*)func_001a41b0(work->windowTask, 3) = 0;
                }
                func_001a4380(work->windowTask, 1);
                func_001a4380(work->windowTask, 2);
                func_001a4380(work->windowTask, 0);
                func_001a4380(work->windowTask, 7);
                func_001a3f20(work->windowTask, D_006843D0);
                func_001a3f20(work->windowTask, D_006843E0);
                func_001a3bf0(work->windowTask, 1);
            }
            else if ((input & 0x20) != 0)
            {
                func_00195020(work->windowTask);
                work->state = 6;
            }
            break;

        case 2:
            work->state++;
            break;

        case 3:
            value = *(u32*)func_001a41b0(work->windowTask, 4);
            work->angle = (f32)(s32)value;
            func_001ad8c0(work->angle, work->controller);
            work->sourceType = (u8)*(u32*)func_001a41b0(
                work->windowTask, 5);
            signedValue = *(s32*)func_001a41b0(
                work->windowTask, 6);
            work->scale = (f32)signedValue;
            value = *(u32*)func_001a41b0(work->windowTask, 3);
            if (value == 1)
            {
                work->flags |= 1;
            }
            else
            {
                work->flags &= (u8)~1;
            }
            if ((DAT_007e094e & 0x40) != 0)
            {
                result = (u32)func_001a4510(work->windowTask);
                if (result == 9)
                {
                    work->controller = func_001a3b10(
                        task, 0x12c, 0xdc, 2);
                    func_001a3f20(work->controller, D_006843D0);
                    func_001a3f20(work->controller, D_006843E0);
                    func_001a3bf0(work->controller, 1);
                    func_001a3bf0(work->windowTask, 0);
                    work->state = 5;
                }
                else if (result == 8)
                {
                    func_001a3bf0(work->windowTask, 0);
                    work->state++;
                }
            }
            if ((DAT_007e094e & 0x20) != 0)
            {
                node = func_001e2810(work->resourceId);
                object = func_003b5d10(work->resourceId);
                matrix = (RuntimeMatrix*)func_00318b60(
                    *(void**)node);
                if (node != NULL)
                {
                    node->matrix = *matrix;
                }
                func_003b78b0(
                    work->resourceId, (u8*)node + 0x50, &angles);
                func_0019c320(
                    work->scale, *(void**)((u8*)object + 0x1f0));
                angles.x = func_001a5b30(&node->matrix);
                angles.y = func_001a5aa0(&node->matrix);
                angles.z = func_001a5bc0(&node->matrix);
                func_003b78b0(
                    work->resourceId, (u8*)node + 0x50, &angles);
                func_00195020(work->windowTask);
                func_001ad890(
                    *(void**)((u8*)object + 0x1e8), 0x80000000);
                work->state = 0;
            }
            break;

        case 4:
            axis = D_006843B0;
            input = DAT_007e094c;
            x = (f32)DAT_007e095e[1] * 2.0f - 128.0f;
            y = (f32)DAT_007e095e[0] * 2.0f - 128.0f;
            if ((input & 0x1000) != 0)
            {
                x = -128.0f;
            }
            if ((input & 0x4000) != 0)
            {
                x = 128.0f;
            }
            if ((input & 0x8000) != 0)
            {
                y = -128.0f;
            }
            if ((input & 0x2000) != 0)
            {
                y = 128.0f;
            }
            base.x = y;
            base.y = 0.0f;
            base.z = x;
            angle = func_001a5aa0(
                func_004cb2f0(*(void**)((u8*)func_00198590() + 4)));
            if (x < -48.0f || x > 48.0f ||
                y < -48.0f || y > 48.0f)
            {
                matrixFlags = *(u32*)&rotation.values[3];
                rotation.values[0] = 1.0f;
                rotation.values[5] = 1.0f;
                rotation.values[10] = 1.0f;
                rotation.values[1] = 0.0f;
                rotation.values[2] = 0.0f;
                rotation.values[4] = 0.0f;
                rotation.values[6] = 0.0f;
                rotation.values[8] = 0.0f;
                rotation.values[9] = 0.0f;
                rotation.values[12] = 0.0f;
                rotation.values[13] = 0.0f;
                rotation.values[14] = 0.0f;
                matrixFlags |= 0x20003;
                *(u32*)&rotation.values[3] = matrixFlags;
                func_004c31b0(&rotation, &axis, angle, 1);
                direction = base;
                func_004c69f0(&direction, &base);
                direction.x = -direction.x;
                direction.y = -direction.y;
                direction.z = -direction.z;
                func_004c6be0(&direction, &direction, &rotation);
                distance = (x + y) * D_007CB118[0] / 2.0f;
                func_001addf0(distance, work->model, &direction);
            }
            if (x < -48.0f || x > 48.0f)
            {
                position = D_00684260;
                distance = y * D_007CB118[1];
                func_001adff0(distance, work->model, &position);
            }
            if ((input & 6) != 0)
            {
                func_001ad940(&center, work->model);
                adjusted = center;
                adjusted.y -= 10.0f;
                func_001adc20(work->model, &adjusted);
            }
            if ((input & 9) != 0)
            {
                func_001ad940(&center, work->model);
                adjusted = center;
                adjusted.y += 10.0f;
                func_001adc20(work->model, &adjusted);
            }
            if ((input & 0x80) != 0)
            {
                func_001ae0d0(work->model);
            }
            if ((input & 0x60) != 0)
            {
                func_001a3bf0(work->windowTask, 1);
                work->state = 3;
            }
            break;

        case 5:
            if ((DAT_007e094e & 0x40) != 0)
            {
                result = (u32)func_001a4510(work->controller);
                if (result == 1)
                {
                    work->state = 3;
                    func_001a3bf0(work->windowTask, 1);
                }
                else if (result == 0)
                {
                    work->state = 0;
                }
                else
                {
                    node = func_001e2810(work->resourceId);
                    func_001e28a0(node, 1);
                    func_00195020(work->windowTask);
                    func_00195020(work->controller);
                }
            }
            break;

        case 6:
            return -1;
    }
    return 0;
}

// FUN_001E5820
void func_001e5820(RuntimeTask* task, u32 request)
{
    ((void (*)(void*, u32))DAT_0096017c[0])(task->workData, request);
}

// FUN_001E5850. Create the field controller task.
void* func_001e5850(void* parent)
{
    void* work;

    work = FIELD_RUNTIME_ALLOCATOR(1, 0x30, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    return kwlnTaskCreateWithAutoPriority(
        parent, 0x106f, D_00684310,
        (void*)func_001e4bc0, (void*)func_001e5820, work);
}

// The transition task builds a 0x20-by-0x20 input window, resolves a field
// resource, then drives a position task from the two analog axes.  The
// remaining work is the original resource-specific path after offset 0x704.
// FUN_001E58D0 NONMATCHING
s32 func_001e58d0(RuntimeTask* task)
{
    RuntimeTransitionWork* work;
    RuntimeVec3 axis;
    RuntimeVec3 firstAxis;
    RuntimeVec3 secondAxis;
    RuntimeVec3 direction;
    RuntimeVec3 center;
    RuntimeVec3 adjusted;
    RuntimeMatrix rotation;
    RuntimeTransitionAngles angles;
    FieldRuntimeTaskNode* taskNode;
    RuntimeMatrix* positionMatrix;
    void* camera;
    void* frame;
    u32 input;
    u32 matrixFlags;
    f32 distance;
    f32 angle;
    f32 x;
    f32 y;
    u16 resourceId;

    work = (RuntimeTransitionWork*)task->workData;

    if (work->state == 3)
    {
        return -1;
    }
    if (work->state == 2)
    {
        goto state2;
    }
    if (work->state == 1)
    {
        goto state1;
    }
    if (work->state != 0)
    {
        return 0;
    }

    work->windowTask = func_001a3b10(task, 0x20, 0x20, 2);
    func_001a3dc0(work->windowTask, D_00684330, 2);
    func_001a3bf0(work->windowTask, 1);
    work->state++;
    return 0;

state1:
    if ((DAT_007e094e & 0x40) == 0)
    {
        return 0;
    }
    if (func_001a4510(work->windowTask) != 1)
    {
        return 0;
    }
    resourceId = (u16)*func_001a41b0(work->windowTask, 0);
    resourceId = (u16)((resourceId & 0x3ff) | 0x2000);
    if (func_001e29e0(resourceId) == NULL)
    {
        return 0;
    }
    func_001a1540(0, 0, 0xb4, D_00684380);
    work->resourceId = func_003b5e90(resourceId);
    func_003b5d10(work->resourceId);
    work->positionTask = func_001a4cd0(0);
    func_00195020(work->windowTask);
    work->state++;
    return 0;

state2:
    axis = *(RuntimeVec3*)D_00684370;

    firstAxis.x = 0.0f;
    firstAxis.y = 0.0f;
    firstAxis.z = 0.0f;
    secondAxis.x = 0.0f;
    secondAxis.y = 0.0f;
    secondAxis.z = 0.0f;
    input = *(u8*)(&DAT_007e095e[0]);
    x = (f32)input * 2.0f - 128.0f;
    input = *(u8*)(&DAT_007e0960[0]);
    y = (f32)input * 2.0f - 128.0f;
    if ((DAT_007e094c & 0x1000) != 0)
    {
        x = -128.0f;
    }
    if ((DAT_007e094c & 0x4000) != 0)
    {
        x = 128.0f;
    }
    if ((DAT_007e094c & 0x8000) != 0)
    {
        y = -128.0f;
    }
    if ((DAT_007e094c & 0x2000) != 0)
    {
        y = 128.0f;
    }
    firstAxis.x = x;
    secondAxis.x = y;

    camera = func_00198590();
    frame = *(void**)((u8*)camera + 4);
    angle = func_001a5aa0(func_004cb2f0(frame));
    if (x < -48.0f || x > 48.0f || y < -48.0f || y > 48.0f)
    {
        matrixFlags = *(u32*)&rotation.values[3];
        rotation.values[0] = 1.0f;
        rotation.values[5] = 1.0f;
        rotation.values[10] = 1.0f;
        rotation.values[1] = 0.0f;
        rotation.values[2] = 0.0f;
        rotation.values[4] = 0.0f;
        rotation.values[6] = 0.0f;
        rotation.values[8] = 0.0f;
        rotation.values[9] = 0.0f;
        rotation.values[12] = 0.0f;
        rotation.values[13] = 0.0f;
        rotation.values[14] = 0.0f;
        matrixFlags |= 0x20003;
        *(u32*)&rotation.values[3] = matrixFlags;
        func_004c31b0(&rotation, &axis, angle, 2);
        direction = firstAxis;
        func_004c69f0(&direction, &direction);
        direction.x = -direction.x;
        direction.y = -direction.y;
        direction.z = -direction.z;
        func_004c6be0(&direction, &direction, &rotation);
        distance = (x + y) * 1.0f / 2.0f;
        K_Draw_MovePositionInDir(distance, work->positionTask, &direction);
    }
    if (x < -48.0f || x > 48.0f)
    {
        K_Draw_RotatePosition(work->positionTask, &axis, y * 1.0f);
    }
    input = DAT_007e094c;
    if ((input & 6) != 0)
    {
        K_Draw_CopyPositionCenter(&center, work->positionTask);
        adjusted = center;
        adjusted.y -= 10.0f;
        K_Draw_SetPositionPos(work->positionTask, &adjusted);
    }
    if ((input & 9) != 0)
    {
        K_Draw_CopyPositionCenter(&center, work->positionTask);
        adjusted = center;
        adjusted.y += 10.0f;
        K_Draw_SetPositionPos(work->positionTask, &adjusted);
    }
    if ((input & 0x80) != 0)
    {
        func_001a5000(work->positionTask);
    }
    if ((input & 0x20) != 0)
    {
        func_003b7090(work->resourceId);
        func_00195020(work->positionTask);
        work->state = 0;
    }
    if ((input & 0x40) != 0)
    {
        taskNode = func_001e2a20();
        taskNode->resourceId = work->resourceId;
        taskNode->task = work->positionTask;
        positionMatrix = (RuntimeMatrix*)K_Draw_GetPositionMatrix(
            work->positionTask);
        taskNode->matrix = *positionMatrix;
        angles.value.x = func_001a5b30(&taskNode->matrix);
        angles.value.y = func_001a5aa0(&taskNode->matrix);
        angles.value.z = func_001a5bc0(&taskNode->matrix);
        func_003b78b0(taskNode->resourceId, (u8*)taskNode + 0x40,
                     &angles.value);
        work->state = 0;
    }
    return 0;
}

// FUN_001E6000
void func_001e6000(RuntimeTask* task, u32 request)
{
    ((void (*)(void*, u32))DAT_0096017c[0])(task->workData, request);
}

// FUN_001E6030. Create the field transition task.
void* func_001e6030(void* parent)
{
    void* work;

    work = FIELD_RUNTIME_ALLOCATOR(1, 0x18, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    return kwlnTaskCreateWithAutoPriority(
        parent, 10, D_006843A0,
        (void*)func_001e58d0, (void*)func_001e6000, work);
}

// FUN_001E60B0 NONMATCHING
s32 func_001e60b0(RuntimeTask* task)
{
    typedef struct RuntimeAuxWork
    {
        u32 state;
        void* windowTask;
        void* auxiliaryTask;
        u32 count;
        u16 resourceId;
        u8 reserved12[2];
        void* positionTask;
    } RuntimeAuxWork;

    RuntimeAuxWork* work;
    void* resourceManager;
    u8* node;
    u8* selected;
    u8* nodeAddress;
    void* camera;
    void* frame;
    void* positionMatrix;
    FieldRuntimeTaskNode* taskNode;
    RuntimeVec3 axis;
    RuntimeVec3 firstAxis;
    RuntimeVec3 direction;
    RuntimeVec3 center;
    RuntimeVec3 adjusted;
    RuntimeMatrix rotation;
    RuntimeTransitionAngles angles;
    char text[112];
    u32 input;
    u32 index;
    u32 matrixFlags;
    s32 result;
    f32 distance;
    f32 angle;
    f32 x;
    f32 y;

    work = (RuntimeAuxWork*)task->workData;
    switch (work->state)
    {
        case 0:
            resourceManager = func_001e1840();
            node = *(u8**)((u8*)resourceManager + 4);
            work->count = 0;
            work->windowTask = func_001a3b10(task, 0x20, 0x20, 2);
            while (node != NULL)
            {
                FUN_00523ac8(
                    text, D_006843C0,
                    (u32)(*(u16*)(node + 0x50) & 0x3ff));
                index = func_001a3f20(work->windowTask, text);
                nodeAddress = (u8*)func_001a41b0(work->windowTask, index);
                *(u8**)nodeAddress = node;
                work->count++;
                node = *(u8**)(node + 0x58);
            }
            if (work->count != 0)
            {
                func_001a3bf0(work->windowTask, 1);
                work->state = work->state + 1;
            }
            else
            {
                func_00195020(work->windowTask);
                work->state = 6;
            }
            break;

        case 1:
            index = 0;
            while (index < work->count)
            {
                nodeAddress = (u8*)func_001a41b0(work->windowTask, index);
                node = *(u8**)nodeAddress;
                func_003b5d10(*(u16*)(node + 0x50));
                func_001a4dc0(*(void**)node, D_007CC338);
                index++;
            }
            selected = *(u8**)func_001a41b0(
                work->windowTask, func_001a4510(work->windowTask));
            func_003b5d10(*(u16*)(selected + 0x50));
            func_001a4dc0(*(void**)selected, D_007CC33C);
            if ((DAT_007e094e & 0x40) != 0)
            {
                work->positionTask = *(void**)selected;
                work->resourceId = *(u16*)(selected + 0x50);
                func_003b5d10(work->resourceId);
                work->windowTask = func_001a3b10(task, 0x20, 0x20, 2);
                func_001a3f20(work->windowTask, D_006843D0);
                func_001a3f20(work->windowTask, D_006843E0);
                func_001a3bf0(work->windowTask, 1);
                work->state = work->state + 1;
            }
            else if ((DAT_007e094e & 0x20) != 0)
            {
                func_00195020(work->windowTask);
                work->state = 6;
            }
            break;

        case 2:
            work->state = work->state + 1;
            break;

        case 3:
            if ((DAT_007e094e & 0x40) != 0)
            {
                result = func_001a4510(work->windowTask);
                if (result == 1)
                {
                    work->auxiliaryTask =
                        func_001a3b10(task, 0x12c, 0xdc, 2);
                    func_001a3f20(work->auxiliaryTask, D_006843D0);
                    func_001a3f20(work->auxiliaryTask, D_006843E0);
                    func_001a3bf0(work->auxiliaryTask, 1);
                    func_001a3bf0(work->windowTask, 0);
                    work->state = 5;
                }
                else if (result == 0)
                {
                    func_001a3bf0(work->windowTask, 0);
                    work->state = work->state + 1;
                }
                else if ((DAT_007e094e & 0x20) != 0)
                {
                    func_00195020(work->windowTask);
                    work->state = 0;
                }
            }
            break;

        case 4:
            axis = D_006843B0;
            firstAxis.x = 0.0f;
            firstAxis.y = 0.0f;
            firstAxis.z = 0.0f;
            input = *(u8*)(&DAT_007e095e[1]);
            x = (f32)input * 2.0f - 128.0f;
            input = *(u8*)(&DAT_007e095e[0]);
            y = (f32)input * 2.0f - 128.0f;
            if ((DAT_007e094c & 0x1000) != 0)
            {
                x = -128.0f;
            }
            if ((DAT_007e094c & 0x4000) != 0)
            {
                x = 128.0f;
            }
            if ((DAT_007e094c & 0x8000) != 0)
            {
                y = -128.0f;
            }
            if ((DAT_007e094c & 0x2000) != 0)
            {
                y = 128.0f;
            }
            firstAxis.x = y;
            firstAxis.z = x;

            camera = func_00198590();
            frame = *(void**)((u8*)camera + 4);
            angle = func_001a5aa0(func_004cb2f0(frame));
            if (x < -48.0f || x > 48.0f ||
                y < -48.0f || y > 48.0f)
            {
                matrixFlags = *(u32*)&rotation.values[3];
                rotation.values[0] = 1.0f;
                rotation.values[5] = 1.0f;
                rotation.values[10] = 1.0f;
                rotation.values[1] = 0.0f;
                rotation.values[2] = 0.0f;
                rotation.values[4] = 0.0f;
                rotation.values[6] = 0.0f;
                rotation.values[8] = 0.0f;
                rotation.values[9] = 0.0f;
                rotation.values[12] = 0.0f;
                rotation.values[13] = 0.0f;
                rotation.values[14] = 0.0f;
                matrixFlags |= 0x20003;
                *(u32*)&rotation.values[3] = matrixFlags;
                func_004c31b0(&rotation, &axis, angle, 1);
                direction = firstAxis;
                func_004c69f0(&direction, &firstAxis);
                direction.x = -direction.x;
                direction.y = -direction.y;
                direction.z = -direction.z;
                distance = (x + y) * D_007CB118[0] / 2.0f;
                K_Draw_MovePositionInDir(
                    distance, work->positionTask, &direction);
            }
            if (x < -48.0f || x > 48.0f)
            {
                K_Draw_RotatePosition(work->positionTask, &axis,
                                       y * D_007CB118[1]);
            }
            input = DAT_007e094c;
            if ((input & 6) != 0)
            {
                K_Draw_CopyPositionCenter(&center, work->positionTask);
                adjusted = center;
                adjusted.y -= 10.0f;
                K_Draw_SetPositionPos(work->positionTask, &adjusted);
            }
            if ((input & 9) != 0)
            {
                K_Draw_CopyPositionCenter(&center, work->positionTask);
                adjusted = center;
                adjusted.y += 10.0f;
                K_Draw_SetPositionPos(work->positionTask, &adjusted);
            }
            if ((input & 0x80) != 0)
            {
                func_001a5000(work->positionTask);
            }
            if ((input & 0x20) != 0)
            {
                func_003b7090(work->resourceId);
                func_00195020(work->positionTask);
                work->state = 0;
            }
            if ((input & 0x40) != 0)
            {
                func_001a3bf0(work->windowTask, 1);
                taskNode = func_001e2a20();
                taskNode->resourceId = work->resourceId;
                taskNode->task = work->positionTask;
                positionMatrix = K_Draw_GetPositionMatrix(
                    work->positionTask);
                taskNode->matrix = *(RuntimeMatrix*)positionMatrix;
                angles.value.x = func_001a5b30(&taskNode->matrix);
                angles.value.y = func_001a5aa0(&taskNode->matrix);
                angles.value.z = func_001a5bc0(&taskNode->matrix);
                func_003b78b0(taskNode->resourceId,
                             (u8*)taskNode + 0x40, &angles.value);
                work->state = 0;
            }
            break;

        case 5:
            if ((DAT_007e094e & 0x40) != 0)
            {
                result = func_001a4510(work->auxiliaryTask);
                if (result == 1)
                {
                    work->state = 3;
                    func_001a3bf0(work->windowTask, 1);
                }
                else if (result == 0)
                {
                    work->state = 0;
                }
                else
                {
                    taskNode = func_001e29e0(work->resourceId);
                    func_001e2a70(taskNode, 1);
                    func_00195020(work->windowTask);
                    func_00195020(work->auxiliaryTask);
                }
            }
            break;

        case 6:
            return -1;
    }
    return 0;
}

// FUN_001E6A40
void func_001e6a40(RuntimeTask* task, u32 request)
{
    ((void (*)(void*, u32))DAT_0096017c[0])(task->workData, request);
}

// FUN_001E6A70. Create the auxiliary field controller task.
void* func_001e6a70(void* parent)
{
    void* work;

    work = FIELD_RUNTIME_ALLOCATOR(1, 0x18, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    return kwlnTaskCreateWithAutoPriority(
        parent, 0x106f, D_006843F0,
        (void*)func_001e60b0, (void*)func_001e6a40, work);
}

// FUN_001E6AF0. Build, rotate, and translate a four-vertex field quad.
void func_001e6af0(RuntimeVec3* vertices, const RuntimeVec3* translation,
                   f32 width, f32 depth, f32 angle)
{
    RuntimeMatrix* matrix;
    RuntimeVec3 axis;
    s32 i;

    matrix = func_004c38c0();
    axis = D_00684400;
    __asm__ volatile (
        "neg.s $f0, %1\n\t"
        "lui $v1, 0x4000\n\t"
        "mtc1 $v1, $f3\n\t"
        "nop\n\t"
        "div.s $f2, $f0, $f3\n\t"
        "swc1 $f2, 0x00(%0)\n\t"
        "sw $zero, 0x04(%0)\n\t"
        "neg.s $f0, %2\n\t"
        "div.s $f0, $f0, $f3\n\t"
        "swc1 $f0, 0x08(%0)\n\t"
        "div.s $f1, %1, $f3\n\t"
        "swc1 $f1, 0x0c(%0)\n\t"
        "sw $zero, 0x10(%0)\n\t"
        "swc1 $f0, 0x14(%0)\n\t"
        "swc1 $f2, 0x18(%0)\n\t"
        "sw $zero, 0x1c(%0)\n\t"
        "div.s $f0, %2, $f3\n\t"
        "swc1 $f0, 0x20(%0)\n\t"
        "swc1 $f1, 0x24(%0)\n\t"
        "sw $zero, 0x28(%0)\n\t"
        "swc1 $f0, 0x2c(%0)"
        :
        : "r"(vertices), "f"(width), "f"(depth)
        : "$3", "$f0", "$f1", "$f2", "$f3", "memory");

    matrix->values[10] = 1.0f;
    matrix->values[5] = 1.0f;
    matrix->values[0] = 1.0f;
    matrix->values[4] = 0.0f;
    matrix->values[2] = 0.0f;
    matrix->values[1] = 0.0f;
    matrix->values[9] = 0.0f;
    matrix->values[8] = 0.0f;
    matrix->values[6] = 0.0f;
    matrix->values[14] = 0.0f;
    matrix->values[13] = 0.0f;
    matrix->values[12] = 0.0f;
    *(u32*)&matrix->values[3] |= 0x20003;

    func_004c31b0(matrix, &axis, angle, 2);
    func_004c6c20(vertices, vertices, 4, matrix);
    func_004c3880(matrix);
    for (i = 0; i < 4; i++)
    {
        vertices[i].x += translation->x;
        vertices[i].y += translation->y;
        vertices[i].z += translation->z;
    }
}

// FUN_001E6CB0. Request the field-specific resource archive.
HCdvd* func_001e6cb0(u16 majorId, u16 minorId)
{
    char path[128];
    HCdvd* result;

    if (K_Fldrc_GetFldPacCdvd() == NULL)
    {
        sprintf(path, D_00684410, majorId, minorId);
        if (H_Cdvd_FileExists(path) == 0)
        {
            result = NULL;
        }
        else
        {
            result = H_Cdvd_Request(path, HCDVD_FILENORMAL);
        }
    }
    else
    {
        result = (HCdvd*)1;
    }
    return result;
}

// FUN_001E6D50. Load a field runtime archive from disc or the cache.
u32 func_001e6d50(HCdvd* request, void** outFile, u16 majorId,
                  u16 minorId)
{
    char path[76];
    void* cached;
    void* allocated;
    volatile u32 size;
    u32 callSize;

    if (request == NULL)
    {
        return 1;
    }
    if (func_001b0910() == 0)
    {
        if (func_001016b0(request) != NULL)
        {
            callSize = request->fileSize;
            *outFile = FIELD_RUNTIME_ALLOCATOR(1, callSize, 0x40000);
            callSize = request->fileSize;
            FUN_00521250(*outFile, request->fileMemory, callSize);
            func_00100ec0(request);
            return 1;
        }
    }
    else
    {
        FUN_00523ac8(path, D_00684430, majorId, minorId);
        cached = func_001021c0(path, (u32*)&size);
        if (cached != NULL)
        {
            callSize = size;
            allocated = FIELD_RUNTIME_ALLOCATOR(1, callSize, 0x40000);
            *outFile = allocated;
            callSize = size;
            FUN_00521250(allocated, cached, callSize);
        }
        return 1;
    }
    return 0;
}

// FUN_001E6EA0 NONMATCHING
void func_001e6ea0(u8* data)
{
    u16* simpleRecord;
    u32 index;
    void* object;
    u16* record;
    u32 version;
    u32 firstIndex;

    if (data == NULL)
    {
        return;
    }

    version = *(u32*)(data + 4);
    if (version == 0x10000)
    {
        record = (u16*)(data + 0x28);
    }
    else if (version == 0x10001)
    {
        record = (u16*)(data + 0x30);
    }
    else if (version == 0x10002)
    {
        record = (u16*)(data + 0x38);
    }
    else
    {
        record = (u16*)(data + 0x48);
    }

    for (firstIndex = 0; firstIndex < *(u32*)(data + 8); firstIndex++)
    {
        if (func_001a0250() == 0)
        {
            func_003b6870(
                record[0] & 0x3ff,
                (RuntimeVec3*)(record + 4),
                *(f32*)(record + 10),
                *(f32*)(record + 12),
                *(f32*)(record + 14),
                *(u32*)((u8*)record + 4));
        }
        record += 16;
    }
    simpleRecord = record;

    for (index = 0; index < *(u32*)(data + 0x10); index++)
    {
        func_003b6ad0(simpleRecord[0] & 0x3ff,
                      (RuntimeVec3*)(simpleRecord + 2),
                      *(f32*)(simpleRecord + 8));
        simpleRecord += 10;
    }

    if (func_001a0250() == 0)
    {
        for (index = 0; index < *(u32*)(data + 0x18); index++)
        {
            func_003b6b90(simpleRecord[0] & 0x3ff,
                          (RuntimeVec3*)(simpleRecord + 2),
                          *(f32*)(simpleRecord + 8));
            simpleRecord += 10;
        }
        for (index = 0; index < *(u32*)(data + 0x20); index++)
        {
            func_003b6c50(simpleRecord[0] & 0x3ff,
                          (RuntimeVec3*)(simpleRecord + 2),
                          *(f32*)(simpleRecord + 8));
            simpleRecord += 10;
        }
        if (*(u32*)(data + 4) >= 0x10001)
        {
            for (index = 0; index < *(u32*)(data + 0x28); index++)
            {
                func_003b6d10(simpleRecord[0] & 0x3ff,
                              (RuntimeVec3*)(simpleRecord + 2),
                              *(f32*)(simpleRecord + 8));
                simpleRecord += 10;
            }
        }
        if (*(u32*)(data + 4) >= 0x10002)
        {
            record = simpleRecord;
            for (firstIndex = 0; firstIndex < *(u32*)(data + 0x30); firstIndex++)
            {
                func_003b69a0(
                    record[0] & 0x3ff,
                    (RuntimeVec3*)(record + 4),
                    *(f32*)(record + 10),
                    *(f32*)(record + 12),
                    *(f32*)(record + 14),
                    *(u32*)((u8*)record + 4));
                object = func_003b5d10(
                    (record[0] & 0x3ff) | 0x5400);
                *(u32*)((u8*)object + 0x14c) = record[1];
                record += 16;
            }
        }
        if (*(u32*)(data + 4) >= 0x10003)
        {
            for (firstIndex = 0; firstIndex < *(u32*)(data + 0x38); firstIndex++)
            {
                func_003b6dd0(record[0] & 0x3ff,
                              (RuntimeVec3*)(record + 2),
                              *(f32*)(record + 8));
                record += 10;
            }
            for (firstIndex = 0; firstIndex < *(u32*)(data + 0x40); firstIndex++)
            {
                func_003b6e90(record[0] & 0x3ff,
                              (RuntimeVec3*)(record + 2),
                              *(f32*)(record + 8));
                record += 10;
            }
        }
    }

    if (*(u32*)(data + 4) < 0x10003)
    {
        func_001a1540(0, 0, 0x184, D_00684450);
    }
}

// FUN_001E7200. Request the field event archive.
void* func_001e7200(u16 majorId)
{
    char path[128];
    void* result;

    if (K_Fldrc_GetFldPacCdvd() == NULL)
    {
        sprintf(path, D_00684470, majorId);
        if (H_Cdvd_FileExists(path) == 0)
        {
            result = NULL;
        }
        else
        {
            result = H_Cdvd_Request(path, HCDVD_FILENORMAL);
        }
    }
    else
    {
        result = (void*)1;
    }
    return result;
}

// FUN_001E7290. Load the current field archive into the global field buffer.
s32 func_001e7290(FieldArchiveRequest* request, u16 majorId)
{
    char path[76];
    volatile u32 size;
    u32 requestSize;
    void* source;
    void* buffer;
    void* field;
    s32 result;

    if (request == NULL)
    {
        result = 1;
        goto done;
    }

    if (func_001b0910() == 0)
    {
        if (func_001016b0(request) == NULL)
        {
            goto failure;
        }

        requestSize = request->size;
        buffer = FIELD_RUNTIME_ALLOCATOR(1, requestSize, 0x40000);
        *(void**)(func_001b9120() + 0x1048) = buffer;
        *(u32*)(func_001b9120() + 0x104c) = request->size;
        field = func_001b9120();
        __asm__ volatile (
            ".set noreorder\n\t"
            "lw $a2, 0x118(%0)\n\t"
            "lw $a0, 0x1048(%1)\n\t"
            "lw $a1, 0x110(%0)\n\t"
            "jal FUN_00521250\n\t"
            "nop\n\t"
            ".set reorder"
            :
            : "r"(request), "r"(field)
            : "$4", "$5", "$6", "$31", "memory");
        func_00100ec0(request);
        result = 1;
        goto done;
    }

    FUN_00523ac8(path, D_00684490, majorId);
    source = func_001021c0(path, (u32*)&size);
    if (source != NULL)
    {
        buffer = FIELD_RUNTIME_ALLOCATOR(1, size, 0x40000);
        *(void**)(func_001b9120() + 0x1048) = buffer;
        *(u32*)(func_001b9120() + 0x104c) = size;
        FUN_00521250(*(void**)(func_001b9120() + 0x1048), source, size);
    }
    result = 1;
    goto done;

failure:
    result = 0;
done:
    return result;
}

// FUN_001E7410. Release the field-global loaded buffer.
void func_001e7410(void)
{
    u8* field;

    field = func_001b9120();
    if (*(void**)(field + 0x1048) != NULL)
    {
        field = func_001b9120();
        ((void (*)(void*))DAT_0096017c[0])(*(void**)(field + 0x1048));
        field = func_001b9120();
        *(void**)(field + 0x1048) = NULL;
    }
}

// FUN_001E7470
HCdvd* func_001e7470(u16 majorId, u16 minorId)
{
    char path[128];

    sprintf(path, D_006844B0, majorId, minorId);
    if (H_Cdvd_FileExists(path) == 0)
    {
        return NULL;
    }
    return H_Cdvd_Request(path, HCDVD_FILENORMAL);
}

// FUN_001E74E0
s32 func_001e74e0(void* request)
{
    if (request == NULL)
    {
        return 1;
    }
    return H_Cdvd_IsFileLoaded(request) != 0;
}

// FUN_001E7520. Release a loaded field resource.
void func_001e7520(void* request)
{
    func_00100ec0(request);
}

// FUN_001E7540. Load a formatted field resource and register it.
void* func_001e7540(void* file, const char* name, void* callback)
{
    char path[64];
    void* result;

    FUN_00523ac8(path, D_006844D0, D_007CE2C4, name, callback);
    D_007CDF38 = 0;
    result = func_004bad50(file, path);
    FUN_005225a8(&D_007CC348, result);
    return file;
}

// FUN_001E75B0. Restore the main camera from a saved runtime snapshot.
void* func_001e75b0(void* cameraBackup)
{
    typedef struct RuntimeBlock8
    {
        u32 words[2];
    } RuntimeBlock8;
    typedef struct RuntimeBlock18
    {
        u32 words[6];
    } RuntimeBlock18;
    typedef struct RuntimeBlock40
    {
        u32 words[16];
    } RuntimeBlock40;
    typedef struct RuntimeBlock60
    {
        u32 words[24];
    } RuntimeBlock60;
    typedef struct RuntimeBlock78
    {
        u32 words[30];
    } RuntimeBlock78;
    typedef struct RuntimeCameraState
    {
        u8 reserved0[0x20];
        RuntimeBlock40 block20;
        u8 reserved60[8];
        RuntimeBlock8 block68;
        u8 reserved70[8];
        RuntimeBlock8 block78;
        u8 reserved80[0x14];
        RuntimeBlock78 block94;
        RuntimeBlock18 block10c;
        RuntimeBlock60 block124;
    } RuntimeCameraState;

    RuntimeCameraState* source;
    RuntimeCameraState* camera;

    source = cameraBackup;
    FUN_005225a8(&D_007CC350);
    camera = kwlnGetMainCamera();
    camera->block20 = source->block20;
    camera = kwlnGetMainCamera();
    camera->block68 = source->block68;
    camera = kwlnGetMainCamera();
    camera->block78 = source->block78;
    camera = kwlnGetMainCamera();
    camera->block94 = source->block94;
    camera = kwlnGetMainCamera();
    camera->block10c = source->block10c;
    camera = kwlnGetMainCamera();
    camera->block124 = source->block124;
    func_00195770(0);
    func_001949e0();
    func_00195770(1);
    return cameraBackup;
}

// FUN_001E7720. Reconfigure the main camera while preserving runtime state.
void func_001e7720(void)
{
    typedef struct RuntimeBlock8
    {
        u32 words[2];
    } RuntimeBlock8;
    typedef struct RuntimeBlock18
    {
        u32 words[6];
    } RuntimeBlock18;
    typedef struct RuntimeBlock40
    {
        u32 words[16];
    } RuntimeBlock40;
    typedef struct RuntimeBlock60
    {
        u32 words[24];
    } RuntimeBlock60;
    typedef struct RuntimeBlock78
    {
        u32 words[30];
    } RuntimeBlock78;
    typedef struct RuntimeCameraState
    {
        u8 reserved0[0x20];
        RuntimeBlock40 block20;
        u8 reserved60[8];
        RuntimeBlock8 block68;
        u8 reserved70[8];
        RuntimeBlock8 block78;
        u8 reserved80[0x14];
        RuntimeBlock78 block94;
        RuntimeBlock18 block10c;
        RuntimeBlock60 block124;
        u8 reserved184[0x0c];
    } RuntimeCameraState;
    typedef unsigned int RuntimeU128 __attribute__((mode(TI)));
    typedef union RuntimeCameraSnapshot
    {
        RuntimeCameraState state;
        RuntimeU128 aligned[25];
    } RuntimeCameraSnapshot;

    RuntimeCameraSnapshot snapshot;
    RuntimeCameraState* camera;

    camera = kwlnGetMainCamera();
    snapshot = *(RuntimeCameraSnapshot*)camera;
    func_004bf540(
        kwlnGetMainCamera(), 0x500, 0x380, 0x280, 0x1c0,
        func_001e75b0, func_001e7540, 0);
    camera = kwlnGetMainCamera();
    camera->block20 = snapshot.state.block20;
    camera = kwlnGetMainCamera();
    camera->block68 = snapshot.state.block68;
    camera = kwlnGetMainCamera();
    camera->block78 = snapshot.state.block78;
    camera = kwlnGetMainCamera();
    camera->block94 = snapshot.state.block94;
    camera = kwlnGetMainCamera();
    camera->block10c = snapshot.state.block10c;
    camera = kwlnGetMainCamera();
    camera->block124 = snapshot.state.block124;
    D_007CE2C4++;
}

// FUN_001E78C0. Build the field quad geometry and attach its render manager.
void* func_001e78c0(s32 count, void* data)
{
    typedef struct RuntimeGeometry
    {
        u8 reserved0[0x2c];
        void* triangles;
        u8 reserved30[0x2c];
        void* material;
    } RuntimeGeometry;
    typedef struct RuntimeVec4
    {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    } RuntimeVec4;

    RuntimeGeometry* geometry;
    void* triangle;
    u16* indices;
    void* material;
    void* manager;
    RuntimeVec4 bounds;
    s32 base;
    s32 i;
    s32 j;

    geometry = func_00493710(count * 4, count * 2, data);
    triangle = geometry->triangles;
    base = 0;
    for (i = 0; i < count; i++)
    {
        for (j = 0; j < 6; j += 3)
        {
            indices = &D_006844E8[j];
            func_00493210(
                geometry,
                triangle,
                base + indices[0],
                base + indices[1],
                base + indices[2]);
            triangle = (u8*)triangle + 8;
        }
        base += 4;
    }

    material = geometry->material;
    bounds.x = 0.0f;
    bounds.y = 0.0f;
    bounds.z =
        (*(f32*)((u8*)kwlnGetMainCamera() + 0x80) +
         *(f32*)((u8*)kwlnGetMainCamera() + 0x84)) /
        2.0f;
    bounds.w = 0.0f;
    *(RuntimeVec4*)((u8*)material + 4) = bounds;

    manager = func_00491880();
    func_004919b0(manager, geometry, 0);
    func_00493b60(geometry);
    func_00492d10(manager, *(void**)((u8*)kwlnGetMainCamera() + 4));
    return manager;
}

// FUN_001E7A60. Detach and destroy a field render manager.
void func_001e7a60(void* renderData)
{
    func_00492d10(renderData, NULL);
    func_00491a80(renderData);
}

// FUN_001E7AA0. Submit both halves of a field render sample.
void func_001e7aa0(RuntimeWork* work, s32 index, void* data)
{
    u8* entry;
    u8* secondEntry;

    entry = *(u8**)((u8*)(uintptr_t)work->currentIndex + 0x2c) + index * 0x10;
    secondEntry = entry + 8;
    __asm__ volatile ("" : "+r"(secondEntry) : : "memory");
    func_00493230((void*)(uintptr_t)work->currentIndex, entry);
    func_00493230((void*)(uintptr_t)work->currentIndex, secondEntry, data);
}

// FUN_001E7B10. Project a four-vertex field quad into screen coordinates.
void func_001e7b10(RuntimeVec3* vertices, f32 scale)
{
    typedef struct RuntimeDimensions
    {
        s32 width;
        s32 height;
        s32 reserved[6];
    } RuntimeDimensions;

    f32* cameraScale;
    void* context;
    RuntimeDimensions dimensions;
    RuntimeVec3* vertex;
    f32 scaledWidth;
    f32 scaledHeight;
    f32 half;
    u32 i;
    u32 halfBits;

    cameraScale = (f32*)((u8*)kwlnGetMainCamera() + 0x68);
    kwlnGetMainCamera();
    scaledWidth = cameraScale[0] * scale * 2.0f;
    scaledHeight = cameraScale[1] * scale * 2.0f;
    context = func_004ca5b0();
    func_004ca560(&dimensions, context);
    __asm__ volatile ("daddu %0, $zero, $zero\n\tlui %1, 0x3f00\n\tmtc1 %1, %2"
                      : "=r"(i), "=r"(halfBits), "=f"(half));

    while (i < 4)
    {
        vertex = &vertices[i];
        vertex->x =
            scaledWidth * (-vertex->x / (f32)dimensions.width + half);
        vertex->y =
            scaledHeight * (-vertex->y / (f32)dimensions.height + half);
        vertex->z = scale;
        i++;
    }
}

// FUN_001E7C20. Convert a depth-buffer value through the camera projection.
f32 func_001e7c20(u32 depth)
{
    f32 firstPlane;
    f32 secondPlane;
    f32 negativeMaximum;
    f32 value;
    s32 maximum;

    firstPlane = *(f32*)((u8*)kwlnGetMainCamera() + 0x80);
    secondPlane = *(f32*)((u8*)kwlnGetMainCamera() + 0x84);
    maximum = 0xffff;
    __asm__ volatile ("" : "+r"(maximum));
    negativeMaximum = -(f32)maximum;
    value = (f32)depth;
    return (negativeMaximum * firstPlane * secondPlane) /
           (negativeMaximum * secondPlane -
            (value - 65535.0f) * (secondPlane - firstPlane));
}

// FUN_001E7CE0. Allocate and initialize sampled field path storage.
RuntimePathWork* func_001e7ce0(u32 columns, u32 rows)
{
    RuntimePathWork* work;
    u8* cursor;
    u32 firstSize;
    u32 secondSize;
    u32 size;

    firstSize = columns * 0x18;
    secondSize = (columns + 1) * 0x0c;
    size = (rows + 1) * 0x24;
    size += firstSize;
    size += secondSize;
    work = FIELD_RUNTIME_PRIMARY_ALLOCATOR(size, 0x40000);

    cursor = (u8*)work + sizeof(RuntimePathWork);
    work->firstVectors = (RuntimeVec3*)cursor;
    cursor += firstSize;
    work->secondVectors = (RuntimeVec3*)cursor;
    cursor += secondSize;
    work->thirdVectors = (RuntimeVec3*)cursor;

    work->matrix = func_004c38c0();
    work->flags = 0;
    work->reserved = 0;
    work->columnCount = columns;
    work->rowCount = rows;
    work->color[0] = 0xff;
    work->color[1] = 0xff;
    work->color[2] = 0xff;
    work->color[3] = 0xff;
    work->flags |= 1;
    work->flags |= 2;
    return work;
}

// FUN_001E7DE0
void func_001e7de0(RuntimePathWork* work)
{
    func_004c3880(work->matrix);
    ((void (*)(void*))DAT_0096017c[0])(work);
}

// FUN_001E7E30. Measure both path-edge distances for one section.
f32 func_001e7e30(const RuntimeDistanceWork* work, s32 index)
{
    s32 firstIndex;
    s32 nextIndex;
    RuntimeVec3 delta;
    f32 total;
    f32 result;
    f32 length;

    firstIndex = func_001e8330((const RuntimeWork*)work, index);
    nextIndex = func_001e8330((const RuntimeWork*)work, index + 1);
    total = 0.0f;

    delta.x = work->firstVectors[nextIndex].x -
              work->firstVectors[firstIndex].x;
    delta.y = work->firstVectors[nextIndex].y -
              work->firstVectors[firstIndex].y;
    delta.z = work->firstVectors[nextIndex].z -
              work->firstVectors[firstIndex].z;
    total += func_004c6ac0(&delta);

    delta.x = work->secondVectors[nextIndex].x -
              work->secondVectors[firstIndex].x;
    delta.y = work->secondVectors[nextIndex].y -
              work->secondVectors[firstIndex].y;
    delta.z = work->secondVectors[nextIndex].z -
              work->secondVectors[firstIndex].z;
    length = func_004c6ac0(&delta);
    __asm__ volatile (
        "add.s $f2, %2, %3\n\t"
        "mtc1 $zero, $f1\n\t"
        "lw $v0, 0(%1)\n\t"
        "lw $v0, 0($v0)\n\t"
        "lwc1 %0, 0x2c($v0)\n\t"
        "adda.s $f1, $f1\n\t"
        "madd.s %0, $f2, %0"
        : "=f"(result)
        : "r"(work), "f"(total), "f"(length)
        : "$2", "$f1", "$f2");
    return result;
}

// FUN_001E7F90. Resolve a normalized path distance to a segment and fraction.
void func_001e7f90(const RuntimeDistanceWork* data, f32 distance, u32* section,
                   f32* fraction)
{
    RuntimeVec3 leadingDelta;
    RuntimeVec3 trailingDelta;
    u8* vectorBase;
    RuntimeVec3* nextSample;
    RuntimeVec3* firstSample;
    s32 firstOffset;
    s32 nextOffset;
    s32 leadingIndex;
    s32 trailingIndex;
    s32 firstIndex;
    s32 nextIndex;
    s32 totalIndex;
    s32 currentSection;
    f32 previous;
    f32 cumulative;
    f32 total;
    f32 scaledLength;
    f32 sectionLength;
    f32 nextX;
    f32 targetDistance = distance;
    total = 0.0f;
    for (totalIndex = 0; totalIndex < data->count - 1; totalIndex++)
    {
        total += func_001e7e30(data, totalIndex);
    }

    if (total <= 0.0f)
    {
        *section = 0;
        *fraction = 0.0f;
        return;
    }

    currentSection = 0;
    while (currentSection < data->count - 1)
    {

        cumulative = 0.0f;
        for (leadingIndex = 0; leadingIndex < currentSection + 1;
             leadingIndex++)
        {
            firstIndex = func_001e8330((const RuntimeWork*)data, leadingIndex);
            nextIndex =
                func_001e8330((const RuntimeWork*)data, leadingIndex + 1);
            sectionLength = 0.0f;
            vectorBase = (u8*)data->firstVectors;
            firstOffset = firstIndex * sizeof(RuntimeVec3);
            nextOffset = nextIndex * sizeof(RuntimeVec3);
            nextSample = (RuntimeVec3*)(vectorBase + nextOffset);
            nextX = nextSample->x;
            firstSample = (RuntimeVec3*)(vectorBase + firstOffset);
            leadingDelta.x = nextX - firstSample->x;
            leadingDelta.y = nextSample->y - firstSample->y;
            leadingDelta.z = nextSample->z - firstSample->z;
            sectionLength += func_004c6ac0(&leadingDelta);

            vectorBase = (u8*)data->secondVectors;
            nextSample = (RuntimeVec3*)(vectorBase + nextOffset);
            nextX = nextSample->x;
            firstSample = (RuntimeVec3*)(vectorBase + firstOffset);
            leadingDelta.x = nextX - firstSample->x;
            leadingDelta.y = nextSample->y - firstSample->y;
            leadingDelta.z = nextSample->z - firstSample->z;
            sectionLength += func_004c6ac0(&leadingDelta);
            scaledLength = 0.0f;
            scaledLength +=
                sectionLength *
                *(f32*)((u8*)*(void**)data->config + 0x2c);
            cumulative += scaledLength / total;
        }
        if (targetDistance < cumulative)
        {
            break;
        }
        currentSection++;
    }

    if (currentSection == 0)
    {
        previous = 0.0f;
    }
    else
    {
        previous = 0.0f;
        for (trailingIndex = 0; trailingIndex < currentSection;
             trailingIndex++)
        {
            firstIndex = func_001e8330((const RuntimeWork*)data, trailingIndex);
            nextIndex =
                func_001e8330((const RuntimeWork*)data, trailingIndex + 1);
            sectionLength = 0.0f;
            vectorBase = (u8*)data->firstVectors;
            firstOffset = firstIndex * sizeof(RuntimeVec3);
            nextOffset = nextIndex * sizeof(RuntimeVec3);
            nextSample = (RuntimeVec3*)(vectorBase + nextOffset);
            nextX = nextSample->x;
            firstSample = (RuntimeVec3*)(vectorBase + firstOffset);
            trailingDelta.x = nextX - firstSample->x;
            trailingDelta.y = nextSample->y - firstSample->y;
            trailingDelta.z = nextSample->z - firstSample->z;
            sectionLength += func_004c6ac0(&trailingDelta);
            vectorBase = (u8*)data->secondVectors;

            nextSample = (RuntimeVec3*)(vectorBase + nextOffset);
            nextX = nextSample->x;
            firstSample = (RuntimeVec3*)(vectorBase + firstOffset);
            trailingDelta.x = nextX - firstSample->x;
            trailingDelta.y = nextSample->y - firstSample->y;
            trailingDelta.z = nextSample->z - firstSample->z;
            sectionLength += func_004c6ac0(&trailingDelta);
            scaledLength = 0.0f;
            scaledLength +=
                sectionLength *
                *(f32*)((u8*)*(void**)data->config + 0x2c);
            previous += scaledLength / total;
        }
    }

    *section = currentSection;
    sectionLength = cumulative - previous;
    if (sectionLength <= 0.0f)
    {
        func_0019d3f0(D_006844F8, 0x81);
    }
    *fraction = (targetDistance - previous) / sectionLength;
}

// FUN_001E8330. Translate a logical sample index into the ring buffer.
s32 func_001e8330(const RuntimeWork* work, s32 index)
{
    s32 result;

    result = (s32)work->state - 1 - index;
    if (result < 0)
    {
        result += (s32)work->completedFlags;
    }
    return result;
}

void func_001e88f0(RuntimeWork* work, s32 section, RuntimeVec3* output);

// FUN_001E8360. Build a path surface direction for one segment side.
void func_001e8360(RuntimeWork* work, s32 section, s32 side, RuntimeVec3* output)
{
    typedef struct RuntimeSurfaceWork
    {
        void* config;
        u32 state;
        s32 count;
        s32 cursor;
        RuntimeVec3* vectors[2];
    } RuntimeSurfaceWork;

    RuntimeSurfaceWork* data;
    RuntimeVec3* points[2][2];
    RuntimeVec3 sideDelta;
    RuntimeVec3 forward;
    RuntimeVec3 normal;
    RuntimeVec3 axis;
    RuntimeVec3 frameNormal;
    RuntimeVec3* point;
    RuntimeVec3** pointRow;
    s32 firstIndex;
    u32 selected;
    u32 other;
    f32 projection;

    data = (RuntimeSurfaceWork*)work;
    if (data->count < 2)
    {
        func_0019d3f0(D_006844F8, 0xad);
    }

    if (section == data->count - 1)
    {
        s32 secondIndex;
        secondIndex = data->cursor - 1 - section;
        if (secondIndex < 0)
        {
            secondIndex += data->count;
        }
        firstIndex = data->cursor - section;
        if (firstIndex < 0)
        {
            firstIndex += data->count;
        }

        func_001e88f0(work, section, &frameNormal);
        points[0][0] = &data->vectors[(other = side & 1)][secondIndex];
        selected = (side + 1) & 1;
        points[0][1] = &data->vectors[selected][secondIndex];
        points[1][0] = &data->vectors[other][firstIndex];
        points[1][1] = &data->vectors[selected][firstIndex];

        pointRow = points[other];
        point = pointRow[selected];
        sideDelta.x = point->x - points[0][0]->x;
        sideDelta.y = point->y - points[0][0]->y;
        sideDelta.z = point->z - points[0][0]->z;
        func_004c69f0(&sideDelta, &sideDelta);

        pointRow = points[selected];
        point = pointRow[other];
        projection = point->x;
        forward.x = projection - points[0][0]->x;
        forward.y = point->y - points[0][0]->y;
        forward.z = point->z - points[0][0]->z;
        func_004c69f0(&forward, &forward);

        normal.x = sideDelta.y * forward.z - sideDelta.z * forward.y;
        normal.y = sideDelta.z * forward.x - sideDelta.x * forward.z;
        normal.z = sideDelta.x * forward.y - sideDelta.y * forward.x;
        func_004c69f0(&normal, &normal);

        switch (side)
        {
        case 0:
            axis.x = normal.y * sideDelta.z - normal.z * sideDelta.y;
            axis.y = normal.z * sideDelta.x - normal.x * sideDelta.z;
            axis.z = normal.x * sideDelta.y - normal.y * sideDelta.x;
            break;
        case 1:
            axis.x = forward.y * normal.z - forward.z * normal.y;
            axis.y = forward.z * normal.x - forward.x * normal.z;
            axis.z = forward.x * normal.y - forward.y * normal.x;
            break;
        }

        projection =
            axis.x * frameNormal.x + axis.y * frameNormal.y + axis.z * frameNormal.z;
        axis.x *= projection;
        axis.y *= projection;
        axis.z *= projection;
        func_004c69f0(output, &axis);
    }
    else
    {
        s32 secondIndex;
        secondIndex = data->cursor - 1 - section;
        if (secondIndex < 0)
        {
            secondIndex += data->count;
        }
        firstIndex = -2 - section;
        firstIndex += data->cursor;
        if (firstIndex < 0)
        {
            firstIndex += data->count;
        }

        func_001e88f0(work, section, &frameNormal);
        points[0][0] = &data->vectors[(other = side & 1)][secondIndex];
        selected = (side + 1) & 1;
        points[0][1] = &data->vectors[selected][secondIndex];
        points[1][0] = &data->vectors[other][firstIndex];
        points[1][1] = &data->vectors[selected][firstIndex];

        pointRow = points[other];
        point = pointRow[selected];
        sideDelta.x = point->x - points[0][0]->x;
        sideDelta.y = point->y - points[0][0]->y;
        sideDelta.z = point->z - points[0][0]->z;
        func_004c69f0(&sideDelta, &sideDelta);

        pointRow = points[selected];
        point = pointRow[other];
        projection = point->x;
        forward.x = projection - points[0][0]->x;
        forward.y = point->y - points[0][0]->y;
        forward.z = point->z - points[0][0]->z;
        func_004c69f0(&forward, &forward);

        normal.x = sideDelta.y * forward.z - sideDelta.z * forward.y;
        normal.y = sideDelta.z * forward.x - sideDelta.x * forward.z;
        normal.z = sideDelta.x * forward.y - sideDelta.y * forward.x;
        func_004c69f0(&normal, &normal);

        switch (side)
        {
        case 0:
            axis.x = sideDelta.y * normal.z - sideDelta.z * normal.y;
            axis.y = sideDelta.z * normal.x - sideDelta.x * normal.z;
            axis.z = sideDelta.x * normal.y - sideDelta.y * normal.x;
            break;
        case 1:
            axis.x = normal.y * forward.z - normal.z * forward.y;
            axis.y = normal.z * forward.x - normal.x * forward.z;
            axis.z = normal.x * forward.y - normal.y * forward.x;
            break;
        }

        projection =
            axis.x * frameNormal.x + axis.y * frameNormal.y + axis.z * frameNormal.z;
        axis.x *= projection;
        axis.y *= projection;
        axis.z *= projection;
        func_004c69f0(output, &axis);
    }
}

// FUN_001E88F0. Build the path frame normal for a ring-buffer segment.
void func_001e88f0(RuntimeWork* work, s32 section, RuntimeVec3* output)
{
    typedef struct RuntimeFrameWork
    {
        void* config;
        u32 state;
        s32 count;
        s32 cursor;
        RuntimeVec3* firstVectors;
        RuntimeVec3* secondVectors;
    } RuntimeFrameWork;

    RuntimeFrameWork* data;
    RuntimeVec3* firstLeading;
    RuntimeVec3* firstTrailing;
    RuntimeVec3* secondLeading;
    RuntimeVec3* secondTrailing;
    RuntimeVec3 leadingDelta;
    RuntimeVec3 secondSide;
    RuntimeVec3 normal;
    s32 firstIndex;
    f32 leadingLength;
    f32 trailingLength;

    data = (RuntimeFrameWork*)work;
    if (data->count < 2)
    {
        func_0019d3f0(D_006844F8, 0xfa);
    }

    if (section == data->count - 1)
    {
        s32 secondIndex;
        firstIndex = data->cursor - 1 - section;
        if (firstIndex < 0)
        {
            firstIndex += data->count;
        }
        firstLeading = &data->firstVectors[firstIndex];
        firstTrailing = &data->secondVectors[firstIndex];

        secondIndex = data->cursor - section;
        if (secondIndex < 0)
        {
            secondIndex += data->count;
        }
        secondLeading = &data->firstVectors[secondIndex];
        secondTrailing = &data->secondVectors[secondIndex];

        leadingDelta.x = firstLeading->x - secondLeading->x;
        leadingDelta.y = firstLeading->y - secondLeading->y;
        leadingDelta.z = firstLeading->z - secondLeading->z;
        leadingLength = func_004c6ac0(&leadingDelta);

        leadingDelta.x = firstTrailing->x - secondTrailing->x;
        leadingDelta.y = firstTrailing->y - secondTrailing->y;
        leadingDelta.z = firstTrailing->z - secondTrailing->z;
        trailingLength = func_004c6ac0(&leadingDelta);

        leadingDelta.x = firstTrailing->x - firstLeading->x;
        leadingDelta.y = firstTrailing->y - firstLeading->y;
        leadingDelta.z = firstTrailing->z - firstLeading->z;
        func_004c69f0(&leadingDelta, &leadingDelta);

        secondSide.x = secondTrailing->x - secondLeading->x;
        secondSide.y = secondTrailing->y - secondLeading->y;
        secondSide.z = secondTrailing->z - secondLeading->z;
        func_004c69f0(&secondSide, &secondSide);

        normal.x = leadingDelta.y * secondSide.z - leadingDelta.z * secondSide.y;
        normal.y = leadingDelta.z * secondSide.x - leadingDelta.x * secondSide.z;
        normal.z = leadingDelta.x * secondSide.y - leadingDelta.y * secondSide.x;
        func_004c69f0(&normal, &normal);

        *output = normal;
        if (!(leadingLength <= trailingLength))
        {
            output->x = leadingDelta.y * normal.z - leadingDelta.z * normal.y;
            output->y = leadingDelta.z * normal.x - leadingDelta.x * normal.z;
            output->z = leadingDelta.x * normal.y - leadingDelta.y * normal.x;
        }
        else
        {
            output->x = normal.y * leadingDelta.z - normal.z * leadingDelta.y;
            output->y = normal.z * leadingDelta.x - normal.x * leadingDelta.z;
            output->z = normal.x * leadingDelta.y - normal.y * leadingDelta.x;
        }
    }
    else
    {
        s32 secondIndex;
        firstIndex = data->cursor - 1 - section;
        if (firstIndex < 0)
        {
            firstIndex += data->count;
        }
        firstLeading = &data->firstVectors[firstIndex];
        firstTrailing = &data->secondVectors[firstIndex];

        secondIndex = -2 - section;
        secondIndex += data->cursor;
        if (secondIndex < 0)
        {
            secondIndex += data->count;
        }
        secondLeading = &data->firstVectors[secondIndex];
        secondTrailing = &data->secondVectors[secondIndex];

        leadingDelta.x = firstLeading->x - secondLeading->x;
        leadingDelta.y = firstLeading->y - secondLeading->y;
        leadingDelta.z = firstLeading->z - secondLeading->z;
        leadingLength = func_004c6ac0(&leadingDelta);

        leadingDelta.x = firstTrailing->x - secondTrailing->x;
        leadingDelta.y = firstTrailing->y - secondTrailing->y;
        leadingDelta.z = firstTrailing->z - secondTrailing->z;
        trailingLength = func_004c6ac0(&leadingDelta);

        leadingDelta.x = firstTrailing->x - firstLeading->x;
        leadingDelta.y = firstTrailing->y - firstLeading->y;
        leadingDelta.z = firstTrailing->z - firstLeading->z;
        func_004c69f0(&leadingDelta, &leadingDelta);

        secondSide.x = secondTrailing->x - secondLeading->x;
        secondSide.y = secondTrailing->y - secondLeading->y;
        secondSide.z = secondTrailing->z - secondLeading->z;
        func_004c69f0(&secondSide, &secondSide);

        normal.x = secondSide.y * leadingDelta.z - secondSide.z * leadingDelta.y;
        normal.y = secondSide.z * leadingDelta.x - secondSide.x * leadingDelta.z;
        normal.z = secondSide.x * leadingDelta.y - secondSide.y * leadingDelta.x;
        func_004c69f0(&normal, &normal);

        *output = normal;
        if (!(leadingLength <= trailingLength))
        {
            output->x = leadingDelta.y * normal.z - leadingDelta.z * normal.y;
            output->y = leadingDelta.z * normal.x - leadingDelta.x * normal.z;
            output->z = leadingDelta.x * normal.y - leadingDelta.y * normal.x;
        }
        else
        {
            output->x = normal.y * leadingDelta.z - normal.z * leadingDelta.y;
            output->y = normal.z * leadingDelta.x - normal.x * leadingDelta.z;
            output->z = normal.x * leadingDelta.y - normal.y * leadingDelta.x;
        }
    }
}

// FUN_001E8E80 NONMATCHING
void* func_001e8e80(RuntimeWork* rawWork, void* material)
{
    typedef struct RuntimeGeometryConfig
    {
        u32 reserved00;
        u32* flags;
        u32 reserved08;
        s32 count;
    } RuntimeGeometryConfig;
    typedef struct RuntimeGeometryWork
    {
        RuntimeGeometryConfig* config;
        u32 state;
        u32 currentIndex;
        s32 count;
        RuntimeVec3* vectors[6];
        RuntimePathWork* firstPath;
        RuntimePathWork* secondPath;
        void* extraData;
        RuntimeMatrix* matrix;
        u8 reserved38[0x10];
        s16 mode;
    } RuntimeGeometryWork;
    typedef struct RuntimeGeometry
    {
        u8 reserved00[0x2c];
        u8* triangles;
        u8* colors;
        f32* texCoords;
        u8 reserved38[0x24];
        void* frame;
    } RuntimeGeometry;
    typedef struct RuntimeVec4
    {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    } RuntimeVec4;

    RuntimeGeometryWork* work;
    RuntimeGeometry* geometry;
    u8* triangle;
    u8* color;
    f32* texCoord;
    f32* texCoordBase;
    u32 format;
    s32 triangleCount;
    s32 vertexCount;
    s32 index;
    RuntimeVec4 bounds;
    s32 baseIndex;
    s32 endIndex;
    s16 nextBase;
    f32 denominator;
    f32 step;
    f32 amount;

    work = (RuntimeGeometryWork*)rawWork;
    format = 0x4a;
    if ((*work->config->flags & 1) != 0)
    {
        format |= 4;
    }

    triangleCount = 0;
    vertexCount = 0;
    if (work->mode == 2)
    {
        triangleCount = work->config->count * 4 + 4;
        vertexCount = work->config->count * 3 + 6;
    }
    else if (work->mode == 1)
    {
        triangleCount = work->config->count * 4 + 4;
        vertexCount = work->config->count * 3 + 6;
    }
    else if (work->mode == 0)
    {
        triangleCount = (work->config->count - 1) * 2 + 1;
        vertexCount = work->config->count * 2 + 1;
    }

    geometry = func_00493710(
        vertexCount, triangleCount, (void*)(uintptr_t)format);
    triangle = geometry->triangles;
    if (work->mode == 2)
    {
        func_00493210(geometry, triangle, 0, 3, 2);
        func_00493210(geometry, triangle + 8, 2, 4, 1);
        triangle += 0x10;
        baseIndex = 2;
        for (index = 0; index < work->config->count; index++)
        {
            nextBase = baseIndex + 3;
            func_00493210(geometry, triangle, baseIndex, baseIndex + 1,
                          nextBase);
            func_00493210(geometry, triangle + 8, baseIndex, nextBase,
                          baseIndex + 2);
            func_00493210(geometry, triangle + 0x10, baseIndex + 1,
                          baseIndex + 4, nextBase);
            func_00493210(geometry, triangle + 0x18, baseIndex + 2,
                          nextBase, baseIndex + 5);
            triangle += 0x20;
            baseIndex += 3;
        }
        func_00493210(geometry, triangle, baseIndex, baseIndex + 1,
                      baseIndex + 3);
        func_00493210(geometry, triangle + 8, baseIndex, baseIndex + 3,
                      baseIndex + 2);
    }
    else if (work->mode == 1)
    {
        func_00493210(geometry, triangle, 0, 3, 2);
        func_00493210(geometry, triangle + 8, 2, 4, 1);
        triangle += 0x10;
        baseIndex = 2;
        for (index = 0; index < work->config->count; index++)
        {
            nextBase = baseIndex + 3;
            func_00493210(geometry, triangle, baseIndex, baseIndex + 1,
                          nextBase);
            func_00493210(geometry, triangle + 8, baseIndex, nextBase,
                          baseIndex + 2);
            func_00493210(geometry, triangle + 0x10, baseIndex + 1,
                          baseIndex + 4, nextBase);
            func_00493210(geometry, triangle + 0x18, baseIndex + 2,
                          nextBase, baseIndex + 5);
            triangle += 0x20;
            baseIndex += 3;
        }
        func_00493210(geometry, triangle, baseIndex, baseIndex + 1,
                      baseIndex + 3);
        func_00493210(geometry, triangle + 8, baseIndex, baseIndex + 3,
                      baseIndex + 2);
    }
    else if (work->mode == 0)
    {
        for (index = 0; index < work->config->count - 1; index++)
        {
            baseIndex = index * 2;
            func_00493210(geometry, triangle, baseIndex, baseIndex + 1,
                          baseIndex + 2);
            func_00493210(geometry, triangle + 8, baseIndex + 1,
                          baseIndex + 3, baseIndex + 2);
            triangle += 0x10;
        }
        baseIndex = index * 2;
        func_00493210(geometry, triangle, baseIndex, baseIndex + 1,
                      baseIndex + 2);
    }

    triangle = geometry->triangles;
    for (index = 0; index < triangleCount; index++)
    {
        func_00493230(geometry, triangle, material);
        triangle += 8;
    }

    if (work->mode == 2)
    {
        color = geometry->colors;
        for (index = 0; index < vertexCount; index++)
        {
            color[0] = 0;
            color[1] = 0;
            color[2] = 0;
            color[3] = 0;
            color += 4;
        }
    }
    else if (work->mode == 1)
    {
        color = geometry->colors;
        for (index = 0; index < vertexCount; index++)
        {
            color[0] = 0;
            color[1] = 0;
            color[2] = 0;
            color[3] = 0;
            color += 4;
        }
    }
    else if (work->mode == 0)
    {
        color = geometry->colors;
        for (index = 0; index < work->config->count; index++)
        {
            if (index == 0)
            {
                amount = 0.0f / (f32)(work->config->count - 1);
            }
            else
            {
                amount = ((f32)index - 0.5f) /
                         (f32)(work->config->count - 1);
            }
            func_001ed0f0(amount, rawWork, 0, color);
            color += 8;
        }
        func_001ed0f0(1.0f, rawWork, 0, color);

        color = geometry->colors + 4;
        for (index = 0; index < work->config->count; index++)
        {
            amount = (f32)index / (f32)(work->config->count - 1);
            func_001ed0f0(amount, rawWork, 1, color);
            color += 8;
        }
    }

    if ((*work->config->flags & 1) != 0)
    {
        if (work->mode == 2)
        {
            texCoordBase = geometry->texCoords;
            vertexCount = work->config->count * 3 + 6;
            denominator = (f32)work->config->count + 0.5f;
            texCoordBase[0] = 0.0f;
            texCoordBase[1] = 0.0f;
            texCoordBase[2] = 0.0f;
            texCoordBase[3] = 1.0f;
            texCoordBase[4] = 0.0f;
            texCoordBase[5] = 0.5f;
            endIndex = vertexCount * 2;
            texCoordBase[endIndex - 6] = 1.0f;
            texCoordBase[endIndex - 5] = 0.0f;
            texCoordBase[endIndex - 4] = 1.0f;
            texCoordBase[endIndex - 3] = 1.0f;
            texCoordBase[endIndex - 2] = 1.0f;
            texCoordBase[endIndex - 1] = 0.5f;

            step = 1.0f / denominator;
            amount = 0.5f / denominator;
            texCoord = texCoordBase;
            for (index = 0; index < work->config->count; index++)
            {
                texCoord[6] = amount;
                texCoord[7] = 0.0f;
                texCoord[8] = amount;
                texCoord[9] = 1.0f;
                amount += step;
                texCoord += 6;
            }

            texCoord = texCoordBase + 10;
            amount = step;
            for (index = 0; index < work->config->count; index++)
            {
                texCoord[0] = amount;
                texCoord[1] = 0.5f;
                amount += step;
                texCoord += 6;
            }
        }
        else if (work->mode == 1)
        {
            texCoordBase = geometry->texCoords;
            vertexCount = work->config->count * 3 + 6;
            denominator = (f32)work->config->count + 0.5f;
            texCoordBase[0] = 0.0f;
            texCoordBase[1] = 0.0f;
            texCoordBase[2] = 0.0f;
            texCoordBase[3] = 1.0f;
            texCoordBase[4] = 0.0f;
            texCoordBase[5] = 0.5f;
            endIndex = vertexCount * 2;
            texCoordBase[endIndex - 6] = 1.0f;
            texCoordBase[endIndex - 5] = 0.0f;
            texCoordBase[endIndex - 4] = 1.0f;
            texCoordBase[endIndex - 3] = 1.0f;
            texCoordBase[endIndex - 2] = 1.0f;
            texCoordBase[endIndex - 1] = 0.5f;

            step = 1.0f / denominator;
            amount = 0.5f / denominator;
            texCoord = texCoordBase;
            for (index = 0; index < work->config->count; index++)
            {
                texCoord[6] = amount;
                texCoord[7] = 0.0f;
                texCoord[8] = amount;
                texCoord[9] = 1.0f;
                amount += step;
                texCoord += 6;
            }

            texCoord = texCoordBase + 10;
            amount = step;
            for (index = 0; index < work->config->count; index++)
            {
                texCoord[0] = amount;
                texCoord[1] = 0.5f;
                amount += step;
                texCoord += 6;
            }
        }
        else if (work->mode == 0)
        {
            texCoord = geometry->texCoords;
            for (index = 0; index < work->config->count; index++)
            {
                if (work->config->count - 1 < 1)
                {
                    func_0019d3f0(D_006844F8, 0x229);
                }
                if (index == 0)
                {
                    texCoord[0] =
                        0.0f / (f32)(work->config->count - 1);
                }
                else
                {
                    texCoord[0] = ((f32)index - 0.5f) /
                                  (f32)(work->config->count - 1);
                }
                texCoord[1] = 0.0f;
                texCoord += 4;
            }
            texCoord[0] = 1.0f;
            texCoord[1] = 0.0f;

            texCoord = geometry->texCoords + 2;
            for (index = 0; index < work->config->count; index++)
            {
                if (work->config->count - 1 < 1)
                {
                    func_0019d3f0(D_006844F8, 0x237);
                }
                texCoord[0] =
                    (f32)index / (f32)(work->config->count - 1);
                texCoord[1] = 1.0f;
                texCoord += 4;
            }
        }
    }

    bounds.x = 0.0f;
    bounds.y = 0.0f;
    bounds.z = 0.0f;
    bounds.w = 1000000000;
    *(RuntimeVec4*)((u8*)geometry->frame + 4) = bounds;
    return geometry;
}

// FUN_001E9920. Allocate path buffers and initialize sampled path state.
void func_001e9920(void* outputData, const void* configData)
{
    typedef struct RuntimePathConfig
    {
        u8 reserved0[8];
        u32 firstCount;
        u32 secondCount;
        u32 value;
    } RuntimePathConfig;
    typedef struct RuntimePathObject
    {
        const RuntimePathConfig* config;
        u32 state;
        u32 currentIndex;
        u32 count;
        RuntimeVec3* vectors[6];
        RuntimePathWork* firstPath;
        RuntimePathWork* secondPath;
        void* extraData;
        RuntimeMatrix* matrix;
        u8 reserved38[0x10];
        s16 value;
    } RuntimePathObject;

    RuntimePathObject* output;
    const RuntimePathConfig* config;
    u32 size;
    u32 secondSize;
    u32 highPart;

    output = outputData;
    config = configData;
    size = 0;
    size += config->firstCount * 0x18;
    size += config->firstCount * 0x30;
    secondSize = config->secondCount << 1;
    highPart = config->secondCount << 4;
    __asm__ volatile ("" : "+r"(highPart));
    highPart += secondSize;
    secondSize = highPart;
    __asm__ volatile ("" : "+r"(secondSize));
    size += secondSize << 2;
    output->vectors[0] = FIELD_RUNTIME_PRIMARY_ALLOCATOR(size, 0x40000);
    output->vectors[1] = output->vectors[0] + config->firstCount;
    output->vectors[2] = output->vectors[1] + config->firstCount;
    output->vectors[3] = output->vectors[2] + config->firstCount;
    output->vectors[4] = output->vectors[3] + config->firstCount;
    output->vectors[5] = output->vectors[4] + config->firstCount;
    output->extraData = output->vectors[5] + config->firstCount;

    output->state = 0;
    output->config = config;
    output->currentIndex = 0;
    output->count = 0;
    output->firstPath = func_001e7ce0(config->firstCount - 1, 0x40);
    output->secondPath = func_001e7ce0(config->firstCount - 1, 0x40);
    output->matrix = func_004c38c0();
    output->value = (s16)config->value;
}

// FUN_001E9A90. Release a field runtime object's owned resources.
void func_001e9a90(void* workData)
{
    RuntimeWork* work;

    work = (RuntimeWork*)workData;
    func_004c3880(work->next);
    func_001e7de0((RuntimePathWork*)work->renderData);
    func_001e7de0((RuntimePathWork*)work->childTask);
    ((void (*)(void*))DAT_0096017c[0])((void*)(uintptr_t)work->phase);
}

// FUN_001E9AF0 NONMATCHING
void func_001e9af0(RuntimeWork* workData, u32* renderRef)
{
    typedef struct RuntimePathEntryWork
    {
        void* config;
        u32 flags;
        u32 firstIndex;
        u32 currentIndex;
        RuntimeVec3* vectors[6];
        u8 reserved28[0x20];
        s16 state;
    } RuntimePathEntryWork;
    RuntimePathEntryWork* work;
    void* renderObject;

    work = (RuntimePathEntryWork*)workData;
    renderObject = (void*)(uintptr_t)*renderRef;
    if (renderObject == NULL)
    {
        return;
    }
    func_00493370(renderObject, 0x1a);
    if ((work->flags & 2) != 0)
    {
        return;
    }
    switch (work->state)
    {
    case 0:
    {
        u8* color;
        u32 count;
        u32 index;
        f32 amount;
        u8* color1;
        u32 index1;
        f32 amount1;

        color = *(u8**)((u8*)renderObject + 0x30);
        count = *(u32*)((u8*)work->config + 0xc);
        if (count <= 1)
        {
            func_0019d3f0(D_006844F8, 0x3d4);
        }
        for (index = 0; index < count; index++)
        {
            amount = (f32)index / (f32)(count - 1);
            func_001ed0f0(amount, (RuntimeWork*)work, 0, color);
            color += 8;
        }
        func_001ed0f0(1.0f, (RuntimeWork*)work, 0, color);
        color1 = *(u8**)((u8*)renderObject + 0x30) + 4;
        if (count <= 1)
        {
            func_0019d3f0(D_006844F8, 0x3df);
        }
        for (index1 = 0; index1 < count; index1++)
        {
            amount1 = (f32)index1 / (f32)(count - 1);
            func_001ed0f0(amount1, (RuntimeWork*)work, 1, color1);
            color1 += 8;
        }
    }
    case 1:
    {
        u8* color2;
        u32 count2;
        u32 index2;
        u32 tail2;
        f32 denominator2;
        f32 step2;
        f32 amount2;
        u8* cursor2;

        color2 = *(u8**)((u8*)renderObject + 0x30);
        count2 = *(u32*)((u8*)work->config + 0xc);
        func_001ed0f0(0.0f, (RuntimeWork*)work, 0, color2);
        func_001ed0f0(0.0f, (RuntimeWork*)work, 1, color2 + 4);
        for (index2 = 0; index2 < count2; index2++)
        {
            u8* sample;

            sample = color2 + index2 * 12 + 8;
            sample[0] = (u8)((sample[-8] + sample[-4] +
                              sample[4] + sample[8]) >> 2);
            sample[1] = (u8)((sample[-7] + sample[-3] +
                              sample[5] + sample[9]) >> 2);
            sample[2] = (u8)((sample[-6] + sample[-2] +
                              sample[6] + sample[10]) >> 2);
            sample[3] = (u8)((sample[-5] + sample[-1] +
                              sample[7] + sample[11]) >> 2);
        }
        tail2 = count2 * 3 + 6;
        func_001ed0f0(
            1.0f, (RuntimeWork*)work, 0, color2 + (tail2 - 3) * 4);
        func_001ed0f0(
            1.0f, (RuntimeWork*)work, 1, color2 + (tail2 - 2) * 4);
        denominator2 = (f32)count2 + 0.5f;
        step2 = 1.0f / denominator2;
        amount2 = 0.5f / denominator2;
        cursor2 = color2 + 12;
        for (index2 = 0; index2 < count2; index2++)
        {
            func_001ed0f0(
                amount2, (RuntimeWork*)work, 1, cursor2);
            cursor2 += 4;
            func_001ed0f0(
                amount2, (RuntimeWork*)work, 1, cursor2);
            cursor2 += 8;
            amount2 += step2;
        }
        work->flags |= 2;
    }
    case 2:
    {
        u8* color3;
        u32 count3;
        u32 index3;
        u32 tail3;
        f32 denominator3;
        f32 step3;
        f32 amount3;
        u8* cursor3;

        color3 = *(u8**)((u8*)renderObject + 0x30);
        count3 = *(u32*)((u8*)work->config + 0xc);
        func_001ed0f0(0.0f, (RuntimeWork*)work, 1, color3);
        func_001ed0f0(1.0f, (RuntimeWork*)work, 1, color3 + 4);
        tail3 = count3 * 3 + 6;
        func_001ed0f0(
            1.0f, (RuntimeWork*)work, 1, color3 + (tail3 - 3) * 4);
        func_001ed0f0(
            1.0f, (RuntimeWork*)work, 1, color3 + (tail3 - 2) * 4);
        denominator3 = (f32)count3 + 0.5f;
        step3 = 1.0f / denominator3;
        amount3 = 0.5f / denominator3;
        cursor3 = color3 + 12;
        for (index3 = 0; index3 < count3; index3++)
        {
            func_001ed0f0(
                amount3, (RuntimeWork*)work, 1, cursor3);
            cursor3 += 4;
            func_001ed0f0(
                amount3, (RuntimeWork*)work, 1, cursor3);
            cursor3 += 8;
            amount3 += step3;
        }
        func_001ed0f0(0.0f, (RuntimeWork*)work, 0, color3 + 8);
        func_001ed0f0(
            1.0f, (RuntimeWork*)work, 0, color3 + (tail3 - 1) * 4);
        step3 = 1.0f / denominator3;
        amount3 = step3;
        cursor3 = color3 + 20;
        for (index3 = 0; index3 < count3; index3++)
        {
            func_001ed0f0(
                amount3, (RuntimeWork*)work, 0, cursor3);
            cursor3 += 12;
            amount3 += step3;
        }
    }
    default:
        break;
    }
    {
        RuntimeVec3* vertices;
        RuntimeVec3* vector0;
        RuntimeVec3* vector1;
        RuntimeVec3* vector2;
        RuntimeVec3* vector3;
        RuntimeVec3 sample0;
        RuntimeVec3 sample1;
        RuntimeVec3 blended;
        u32 count;
        u32 index;
        u32 section;
        f32 fraction;
        f32 amount;
        f32 denominator;

        vertices = *(RuntimeVec3**)((u8*)renderObject + 0x5c + 0x14);
        vector0 = work->vectors[0];
        vector1 = work->vectors[1];
        vector2 = work->vectors[2];
        vector3 = work->vectors[3];
        count = *(u32*)((u8*)work->config + 0xc);
        section = 0;
        fraction = 0.0f;
        amount = 0.0f;
        denominator = (f32)(count - 1);
        if (work->state == 0 && vertices != NULL &&
            vector0 != NULL && vector1 != NULL)
            if (count < 2)
            {
                func_0019d3f0(D_006844F8, 0x43f);
            }
        {
        func_001e7f90((const RuntimeDistanceWork*)work, amount,
                      &section, &fraction);
        amount = denominator > 0.0f ? 0.5f / denominator : 0.0f;
        func_001e7f90((const RuntimeDistanceWork*)work, amount,
                      &section, &fraction);
        amount = denominator > 0.0f ? 1.0f / denominator : 1.0f;
        func_001e7f90((const RuntimeDistanceWork*)work, amount,
                      &section, &fraction);
            index = 0;
            while (index < count)
            {
                sample0 = vector0[section < count ? section : index];
                sample1 = vector1[section < count ? section : index];
                blended.x = sample0.x +
                            (sample1.x - sample0.x) * fraction;
                blended.y = sample0.y +
                            (sample1.y - sample0.y) * fraction;
                blended.z = sample0.z +
                            (sample1.z - sample0.z) * fraction;
                vertices[index] = blended;
                index++;
            }
        }
        if (work->state == 1)
        {
            if (count < 2)
            {
                func_0019d3f0(D_006844F8, 0x449);
            }
            amount = 0.0f;
            func_001e7f90((const RuntimeDistanceWork*)work, amount,
                          &section, &fraction);
            amount = 1.0f;
            func_001e7f90((const RuntimeDistanceWork*)work, amount,
                          &section, &fraction);
            if (vertices != NULL && vector2 != NULL && vector3 != NULL)
            {
                sample0 = vector2[section < count ? section : 0];
                sample1 = vector3[section < count ? section : 0];
                blended.x = sample0.x +
                            (sample1.x - sample0.x) * fraction;
                blended.y = sample0.y +
                            (sample1.y - sample0.y) * fraction;
                blended.z = sample0.z +
                            (sample1.z - sample0.z) * fraction;
                vertices[0] = blended;
            }
        }
        if (work->state == 2 && count < 2)
        {
            func_0019d3f0(D_006844F8, 0x483);
        }
        (void)vector2;
        (void)vector3;
        (void)section;
        (void)fraction;
        (void)amount;
        (void)denominator;
    }
}

// FUN_001EB920. Append a position-normal sample and refresh queue state.
void func_001eb920(void* data, const RuntimeVec3* position, const RuntimeVec3* normal)
{
    typedef struct RuntimeSampleQueue
    {
        void* config;
        u32 reserved;
        s32 count;
        s32 writeIndex;
        RuntimeVec3* positions;
        RuntimeVec3* normals;
    } RuntimeSampleQueue;

    RuntimeSampleQueue* queue;
    s32 index;

    queue = data;
    index = queue->writeIndex;
    queue->positions[index] = *position;
    queue->normals[index] = *normal;

    if (queue->count < *(s32*)((u8*)queue->config + 8))
    {
        queue->count++;
    }
    queue->writeIndex++;
    queue->writeIndex %= *(s32*)((u8*)queue->config + 8);

    switch (queue->count)
    {
    case 0:
        func_0019d3f0(D_006844F8, 0x5be);
        break;
    case 1:
        break;
    case 2:
        func_001ebd80((RuntimeWork*)queue, 0);
        break;
    default:
        func_001ebd80((RuntimeWork*)queue, 1);
        func_001ebd80((RuntimeWork*)queue, 0);
        break;
    }
}

// FUN_001EBA50
void func_001eba50(RuntimeResetWork* work)
{
    work->value = work->completedFlags;
    work->flags = 0;
    func_001ed0b0(work->work);
}

// FUN_001EBA80 NONMATCHING
void func_001eba80(RuntimeCommandWork* work, u32* unused)
{
    u16* cursor;
    u32 duration;
    u16* durationParts;
    RuntimeWork* target;
    s32 stop;

    cursor = work->cursor;
    stop = 0;
    do
    {
        switch (*cursor)
        {
        case 0:
            stop = 1;
            break;
        case 1:
            if ((~work->flags & 1) != 0)
            {
                if ((((u32)(cursor + 1) >> 1) & 1) != 0)
                {
                    durationParts = (u16*)&duration;
                    durationParts[0] = cursor[1];
                    durationParts[1] = cursor[2];
                }
                else
                {
                    duration = *(u32*)(cursor + 1);
                }
                work->flags |= 1;
                work->elapsed = 0;
            }
            else
            {
                work->elapsed++;
            }
            if ((((u32)(cursor + 1) >> 1) & 1) != 0)
            {
                durationParts = (u16*)&duration;
                durationParts[0] = cursor[1];
                durationParts[1] = cursor[2];
            }
            else
            {
                duration = *(u32*)(cursor + 1);
            }
            stop = 1;
            if (work->elapsed >= duration)
            {
                cursor += 3;
                work->flags &= ~1;
                stop = 0;
            }
            break;
        case 0x100:
            work->flags |= 2;
            cursor++;
            break;
        case 0x101:
            work->flags &= ~2;
            cursor++;
            break;
        case 0x102:
            target = work->target;
            target->completedFlags = 0;
            target->state = 0;
            cursor++;
            break;
        case 0x200:
            {
                __asm__ volatile (
                    ".set noreorder\n"
                    "lhu $v1, 0x18(%1)\n"
                    "beq $v1, $zero, command_delay_zero\n"
                    "nop\n"
                    "b command_delay_done\n"
                    "nop\n"
                    "command_delay_zero:\n"
                    "lw $a0, 0x1c(%1)\n"
                    "beq $a0, $zero, command_delay_done\n"
                    "nop\n"
                    "bltz $a0, command_delay_unsigned\n"
                    "nop\n"
                    "mtc1 $a0, $f0\n"
                    "nop\n"
                    "cvt.s.w $f1, $f0\n"
                    "b command_delay_converted\n"
                    "nop\n"
                    "command_delay_unsigned:\n"
                    "srl $v1, $a0, 1\n"
                    "andi $v0, $a0, 1\n"
                    "or $v1, $v1, $v0\n"
                    "mtc1 $v1, $f0\n"
                    "nop\n"
                    "cvt.s.w $f1, $f0\n"
                    "add.s $f1, $f1, $f1\n"
                    "command_delay_converted:\n"
                    "lui $v0, 0x41f0\n"
                    "mtc1 $v0, $f0\n"
                    "nop\n"
                    "div.s $f12, $f1, $f0\n"
                    "nop\n"
                    "nop\n"
                    "lw $a0, 0x10(%1)\n"
                    "jal func_001ed080\n"
                    "nop\n"
                    "command_delay_done:\n"
                    "addiu %0, %0, 2\n"
                    ".set reorder\n"
                    : "+r"(cursor)
                    : "r"(work)
                    : "$v0", "$v1", "$a0", "$f0", "$f1", "$f12", "memory");
            }
            break;
        case 0x201:
            work->delay = (s16)cursor[1];
            cursor += 2;
            break;
        case 0x202:
            if ((((u32)(cursor + 1) >> 1) & 1) != 0)
            {
                durationParts = (u16*)&duration;
                durationParts[0] = cursor[1];
                durationParts[1] = cursor[2];
            }
            else
            {
                duration = *(u32*)(cursor + 1);
            }
            work->duration = duration;
            cursor += 3;
            break;
        case 0x400:
            work->flags |= 8;
            cursor++;
            break;
        }
    } while ((u32)(stop != 0) ^ 1);
    work->cursor = cursor;
}

// FUN_001EBD80 NONMATCHING
void func_001ebd80(RuntimeWork* work, s32 param2)
{
    typedef struct RuntimeSurfaceQueue
    {
        u8* config;
        u32 reserved;
        s32 count;
        s32 cursor;
        RuntimeVec3* vectors[2];
        RuntimeVec3* axisOut[4];
    } RuntimeSurfaceQueue;

    RuntimeSurfaceQueue* queue = (RuntimeSurfaceQueue*)work;
    u8* config;
    f32 weightNear[2];
    f32 weightFar[2];
    f32 vel0;
    f32 vel1;
    s32 sideBool;
    f32 coefA;
    f32 coefB;
    f32 coefC;
    RuntimeVec3 accum;
    RuntimeVec3 delta;
    s32 idxA;
    s32 idxB;
    s32 idxW;
    f32 weight0;
    f32 weight1;
    s32 section2;

    config = *(u8**)queue->config;
    weightNear[0] = *(f32*)(config + 0x1c);
    weightFar[0] = *(f32*)(config + 0x24);
    weightNear[1] = *(f32*)(config + 0x20);
    weightFar[1] = *(f32*)(config + 0x28);

    vel0 = func_001ecd90(queue, param2, 0);
    vel1 = func_001ecd90(queue, param2, 1);
    sideBool = (vel0 <= vel1) ? 1 : 0;

    if (queue->count == 2)
    {
        config = *(u8**)queue->config;
        coefA = *(f32*)(config + 0xc);
        coefB = *(f32*)(config + 0x10);
        coefC = 0.0f;
    }
    else if (param2 == 0)
    {
        config = *(u8**)queue->config;
        coefA = *(f32*)(config + 0xc);
        coefB = *(f32*)(config + 0x10);
        coefC = 0.0f;
    }
    else
    {
        config = *(u8**)queue->config;
        coefA = *(f32*)(config + 0x0);
        coefB = *(f32*)(config + 0x8);
        coefC = *(f32*)(config + 0x4);
    }

    /* ---- iteration 1: section=param2, side=0(sideBool), axisOut[0] ---- */
    accum.x = 0.0f;
    accum.y = 0.0f;
    accum.z = 0.0f;

    weight0 = weightNear[sideBool] * func_001ecd90(queue, param2, 0);
    weight0 += weightFar[sideBool] * func_001ecec0(queue, param2);

    func_001e8360((RuntimeWork*)queue, param2, 0, &delta);
    delta.x *= coefA;
    delta.y *= coefA;
    delta.z *= coefA;
    accum.x += delta.x;
    accum.y += delta.y;
    accum.z += delta.z;

    if (queue->count < 2)
    {
        func_0019d3f0(D_006844F8, 0x151);
    }
    if (param2 != 0)
    {
        delta.x = 0.0f;
        delta.y = 0.0f;
        delta.z = 0.0f;
    }
    else
    {
        idxA = (queue->count - 1) - param2;
        if (idxA < 0)
        {
            idxA += queue->count;
        }
        idxB = queue->count - param2;
        if (idxB < 0)
        {
            idxB += queue->count;
        }
        delta.x = queue->vectors[0][idxB].x - queue->vectors[0][idxA].x;
        delta.y = queue->vectors[0][idxB].y - queue->vectors[0][idxA].y;
        delta.z = queue->vectors[0][idxB].z - queue->vectors[0][idxA].z;
    }
    func_004c69f0(&delta, &delta);
    delta.x *= coefC;
    delta.y *= coefC;
    delta.z *= coefC;
    accum.x += delta.x;
    accum.y += delta.y;
    accum.z += delta.z;

    if (queue->count < 2)
    {
        func_0019d3f0(D_006844F8, 0x13a);
    }
    if (param2 == queue->count - 1)
    {
        delta.x = 0.0f;
        delta.y = 0.0f;
        delta.z = 0.0f;
    }
    else
    {
        idxA = (queue->count - 1) - param2;
        if (idxA < 0)
        {
            idxA += queue->count;
        }
        idxB = (-2 - param2) + queue->count;
        if (idxB < 0)
        {
            idxB += queue->count;
        }
        delta.x = queue->vectors[1][idxB].x - queue->vectors[1][idxA].x;
        delta.y = queue->vectors[1][idxB].y - queue->vectors[1][idxA].y;
        delta.z = queue->vectors[1][idxB].z - queue->vectors[1][idxA].z;
    }
    func_004c69f0(&delta, &delta);
    delta.x *= coefB;
    delta.y *= coefB;
    delta.z *= coefB;
    accum.x += delta.x;
    accum.y += delta.y;
    accum.z += delta.z;

    accum.x *= weight0;
    accum.y *= weight0;
    accum.z *= weight0;

    idxW = (queue->cursor - 1) - param2;
    if (idxW < 0)
    {
        idxW += queue->count;
    }
    queue->axisOut[0][idxW] = accum;

    /* ---- iteration 2: section=param2, side=1(!sideBool), axisOut[2] ---- */
    accum.x = 0.0f;
    accum.y = 0.0f;
    accum.z = 0.0f;

    weight1 = weightNear[!sideBool] * func_001ecd90(queue, param2, 1);
    weight1 += weightFar[!sideBool] * func_001ecec0(queue, param2);

    func_001e8360((RuntimeWork*)queue, param2, 1, &delta);
    delta.x *= coefA;
    delta.y *= coefA;
    delta.z *= coefA;
    accum.x += delta.x;
    accum.y += delta.y;
    accum.z += delta.z;

    if (queue->count < 2)
    {
        func_0019d3f0(D_006844F8, 0x151);
    }
    if (param2 != 0)
    {
        delta.x = 0.0f;
        delta.y = 0.0f;
        delta.z = 0.0f;
    }
    else
    {
        idxA = (queue->count - 1) - param2;
        if (idxA < 0)
        {
            idxA += queue->count;
        }
        idxB = queue->count - param2;
        if (idxB < 0)
        {
            idxB += queue->count;
        }
        delta.x = queue->vectors[0][idxB].x - queue->vectors[0][idxA].x;
        delta.y = queue->vectors[0][idxB].y - queue->vectors[0][idxA].y;
        delta.z = queue->vectors[0][idxB].z - queue->vectors[0][idxA].z;
    }
    func_004c69f0(&delta, &delta);
    delta.x *= coefC;
    delta.y *= coefC;
    delta.z *= coefC;
    accum.x += delta.x;
    accum.y += delta.y;
    accum.z += delta.z;

    if (queue->count < 2)
    {
        func_0019d3f0(D_006844F8, 0x13a);
    }
    if (param2 == queue->count - 1)
    {
        delta.x = 0.0f;
        delta.y = 0.0f;
        delta.z = 0.0f;
    }
    else
    {
        idxA = (queue->count - 1) - param2;
        if (idxA < 0)
        {
            idxA += queue->count;
        }
        idxB = (-2 - param2) + queue->count;
        if (idxB < 0)
        {
            idxB += queue->count;
        }
        delta.x = queue->vectors[1][idxB].x - queue->vectors[1][idxA].x;
        delta.y = queue->vectors[1][idxB].y - queue->vectors[1][idxA].y;
        delta.z = queue->vectors[1][idxB].z - queue->vectors[1][idxA].z;
    }
    func_004c69f0(&delta, &delta);
    delta.x *= coefB;
    delta.y *= coefB;
    delta.z *= coefB;
    accum.x += delta.x;
    accum.y += delta.y;
    accum.z += delta.z;

    accum.x *= weight1;
    accum.y *= weight1;
    accum.z *= weight1;

    idxW = (queue->cursor - 1) - param2;
    if (idxW < 0)
    {
        idxW += queue->count;
    }
    queue->axisOut[2][idxW] = accum;

    if (queue->count == 2)
    {
        config = *(u8**)queue->config;
        coefA = *(f32*)(config + 0x14);
        coefB = 0.0f;
        coefC = *(f32*)(config + 0x18);
    }
    else if (queue->count == 3 && param2 == 1)
    {
        config = *(u8**)queue->config;
        coefA = *(f32*)(config + 0x14);
        coefB = 0.0f;
        coefC = *(f32*)(config + 0x18);
    }
    else
    {
        config = *(u8**)queue->config;
        coefA = *(f32*)(config + 0x0);
        coefB = *(f32*)(config + 0x8);
        coefC = *(f32*)(config + 0x4);
    }
    section2 = param2 + 1;

    /* ---- iteration 3: section=param2+1, side=0(sideBool), axisOut[1], reuses weight0 ---- */
    accum.x = 0.0f;
    accum.y = 0.0f;
    accum.z = 0.0f;

    func_001e8360((RuntimeWork*)queue, section2, 0, &delta);
    delta.x *= coefA;
    delta.y *= coefA;
    delta.z *= coefA;
    accum.x += delta.x;
    accum.y += delta.y;
    accum.z += delta.z;

    if (queue->count < 2)
    {
        func_0019d3f0(D_006844F8, 0x151);
    }
    if (section2 != 0)
    {
        delta.x = 0.0f;
        delta.y = 0.0f;
        delta.z = 0.0f;
    }
    else
    {
        idxA = (queue->count - 1) - section2;
        if (idxA < 0)
        {
            idxA += queue->count;
        }
        idxB = queue->count - section2;
        if (idxB < 0)
        {
            idxB += queue->count;
        }
        delta.x = queue->vectors[0][idxB].x - queue->vectors[0][idxA].x;
        delta.y = queue->vectors[0][idxB].y - queue->vectors[0][idxA].y;
        delta.z = queue->vectors[0][idxB].z - queue->vectors[0][idxA].z;
    }
    func_004c69f0(&delta, &delta);
    delta.x *= coefC;
    delta.y *= coefC;
    delta.z *= coefC;
    accum.x += delta.x;
    accum.y += delta.y;
    accum.z += delta.z;

    if (queue->count < 2)
    {
        func_0019d3f0(D_006844F8, 0x13a);
    }
    if (section2 == queue->count - 1)
    {
        delta.x = 0.0f;
        delta.y = 0.0f;
        delta.z = 0.0f;
    }
    else
    {
        idxA = (queue->count - 1) - section2;
        if (idxA < 0)
        {
            idxA += queue->count;
        }
        idxB = (-2 - section2) + queue->count;
        if (idxB < 0)
        {
            idxB += queue->count;
        }
        delta.x = queue->vectors[1][idxB].x - queue->vectors[1][idxA].x;
        delta.y = queue->vectors[1][idxB].y - queue->vectors[1][idxA].y;
        delta.z = queue->vectors[1][idxB].z - queue->vectors[1][idxA].z;
    }
    func_004c69f0(&delta, &delta);
    delta.x *= coefB;
    delta.y *= coefB;
    delta.z *= coefB;
    accum.x += delta.x;
    accum.y += delta.y;
    accum.z += delta.z;

    accum.x *= weight0;
    accum.y *= weight0;
    accum.z *= weight0;

    idxW = (queue->cursor - 1) - param2;
    if (idxW < 0)
    {
        idxW += queue->count;
    }
    queue->axisOut[1][idxW] = accum;

    /* ---- iteration 4: section=param2+1, side=1(!sideBool), axisOut[3], reuses weight1 ---- */
    accum.x = 0.0f;
    accum.y = 0.0f;
    accum.z = 0.0f;

    func_001e8360((RuntimeWork*)queue, section2, 1, &delta);
    delta.x *= coefA;
    delta.y *= coefA;
    delta.z *= coefA;
    accum.x += delta.x;
    accum.y += delta.y;
    accum.z += delta.z;

    if (queue->count < 2)
    {
        func_0019d3f0(D_006844F8, 0x151);
    }
    if (section2 != 0)
    {
        delta.x = 0.0f;
        delta.y = 0.0f;
        delta.z = 0.0f;
    }
    else
    {
        idxA = (queue->count - 1) - section2;
        if (idxA < 0)
        {
            idxA += queue->count;
        }
        idxB = queue->count - section2;
        if (idxB < 0)
        {
            idxB += queue->count;
        }
        delta.x = queue->vectors[0][idxB].x - queue->vectors[0][idxA].x;
        delta.y = queue->vectors[0][idxB].y - queue->vectors[0][idxA].y;
        delta.z = queue->vectors[0][idxB].z - queue->vectors[0][idxA].z;
    }
    func_004c69f0(&delta, &delta);
    delta.x *= coefC;
    delta.y *= coefC;
    delta.z *= coefC;
    accum.x += delta.x;
    accum.y += delta.y;
    accum.z += delta.z;

    if (queue->count < 2)
    {
        func_0019d3f0(D_006844F8, 0x13a);
    }
    if (section2 == queue->count - 1)
    {
        delta.x = 0.0f;
        delta.y = 0.0f;
        delta.z = 0.0f;
    }
    else
    {
        idxA = (queue->count - 1) - section2;
        if (idxA < 0)
        {
            idxA += queue->count;
        }
        idxB = (-2 - section2) + queue->count;
        if (idxB < 0)
        {
            idxB += queue->count;
        }
        delta.x = queue->vectors[1][idxB].x - queue->vectors[1][idxA].x;
        delta.y = queue->vectors[1][idxB].y - queue->vectors[1][idxA].y;
        delta.z = queue->vectors[1][idxB].z - queue->vectors[1][idxA].z;
    }
    func_004c69f0(&delta, &delta);
    delta.x *= coefB;
    delta.y *= coefB;
    delta.z *= coefB;
    accum.x += delta.x;
    accum.y += delta.y;
    accum.z += delta.z;

    accum.x *= weight1;
    accum.y *= weight1;
    accum.z *= weight1;

    idxW = (queue->cursor - 1) - param2;
    if (idxW < 0)
    {
        idxW += queue->count;
    }
    queue->axisOut[3][idxW] = accum;

}

// FUN_001ECD90
f32 func_001ecd90(void* data, s32 index, s32 vectorSet)
{
    typedef struct RuntimeVectorHistory
    {
        u32 reserved[2];
        s32 count;
        s32 current;
        RuntimeVec3* vectors[2];
    } RuntimeVectorHistory;

    RuntimeVectorHistory* history;
    s32 sampleIndex;
    u32 vectorOffset;
    u32 sampleOffset;
    RuntimeVec3* firstSamples;
    RuntimeVec3* secondSamples;
    RuntimeVec3* sample;
    RuntimeVec3 delta;
    f32 sampleValue;

    history = data;
    if (index == history->count - 1)
    {
        func_0019d3f0(D_006844F8, 0x6fb);
    }

    sampleIndex = (-2 - index) + history->current;
    if (sampleIndex < 0)
    {
        sampleIndex += history->count;
    }
    __asm__ volatile ("sll %0, %1, 2"
                      : "=r"(vectorOffset)
                      : "r"(vectorSet));
    __asm__ volatile ("addu %0, %1, %2"
                      : "=r"(firstSamples)
                      : "r"(vectorOffset), "r"(history));
    firstSamples = *(RuntimeVec3**)((u8*)firstSamples + 0x10);
    delta = firstSamples[sampleIndex];
    sampleIndex = (history->current - 1) - index;
    if (sampleIndex < 0)
    {
        sampleIndex += history->count;
    }
    sampleOffset = sampleIndex * sizeof(RuntimeVec3);
    __asm__ volatile ("" : "+r"(sampleOffset));
    secondSamples = history->vectors[vectorSet];
    sample = (RuntimeVec3*)((u8*)secondSamples + sampleOffset);
    sampleValue = sample->x;
    __asm__ volatile ("" : "+f"(sampleValue));
    delta.x -= sampleValue;
    delta.y -= sample->y;
    delta.z -= sample->z;
    return func_004c6ac0(&delta);
}

// FUN_001ECEC0. Measure the bend between adjacent sampled directions.
f32 func_001ecec0(void* data, s32 index)
{
    typedef struct RuntimeVectorHistory
    {
        u32 reserved[2];
        s32 count;
        s32 current;
        RuntimeVec3* positions;
        RuntimeVec3* normals;
    } RuntimeVectorHistory;

    RuntimeVectorHistory* history;
    s32 sampleIndex;
    RuntimeVec3 first;
    RuntimeVec3 second;

    history = data;
    if (index == history->count - 1)
    {
        func_0019d3f0(D_006844F8, 0x70c);
    }

    sampleIndex = (history->current - 1) - index;
    if (sampleIndex < 0)
    {
        sampleIndex += history->count;
    }
    first = history->normals[sampleIndex];
    first.x -= history->positions[sampleIndex].x;
    first.y -= history->positions[sampleIndex].y;
    first.z -= history->positions[sampleIndex].z;
    func_004c69f0(&first, &first);

    sampleIndex = (-2 - index) + history->current;
    if (sampleIndex < 0)
    {
        sampleIndex += history->count;
    }
    second = history->normals[sampleIndex];
    second.x -= history->positions[sampleIndex].x;
    second.y -= history->positions[sampleIndex].y;
    second.z -= history->positions[sampleIndex].z;
    func_004c69f0(&second, &second);

    return (1.0f - (first.x * second.x + first.y * second.y + first.z * second.z)) / 2.0f;
}

// FUN_001ED080. Initialize the field interpolation target.
void func_001ed080(f32 value, RuntimeWork* work)
{
    *(u32*)((u8*)work + 0x38) = 0;
    *(f32*)((u8*)work + 0x40) = *(f32*)((u8*)work + 0x3c);
    *(f32*)((u8*)work + 0x44) = value;
    work->requestFlags |= 1;
}

// FUN_001ED0B0. Reset field interpolation state.
void func_001ed0b0(RuntimeWork* work)
{
    work->requestFlags = 0;
    *(u32*)((u8*)work + 0x3c) = 0;
    work->completedFlags = 0;
    work->state = 0;
}

// FUN_001ED0D0. Accumulate field interpolation time.
void func_001ed0d0(RuntimeWork* work, const f32* delta)
{
    *(f32*)((u8*)work + 0x3c) += *delta;
}

// FUN_001ED0F0. Interpolate one path color pair with the active fade.
void func_001ed0f0(f32 amount, const RuntimeWork* work, s32 channel, u8* output)
{
    const u8* colors[2] = {0};
    const u8* colorData;
    f32 inverseAmount;
    f32 duration;
    f32 fade;

    colorData = (const u8*)(channel << 3);
    colorData = *(const u8**)((const u8*)*(const void* const*)work + 4) + (u32)colorData;
    colors[0] = colorData + 8;
    colors[1] = colorData + 12;
    inverseAmount = 1.0f - amount;

    if ((*(const u32*)((const u8*)work + 4) & 1) != 0)
    {
        duration = *(const f32*)((const u8*)work + 0x44);
        if (duration > 0.0f)
        {
            fade = 1.0f -
                (*(const f32*)((const u8*)work + 0x3c) -
                 *(const f32*)((const u8*)work + 0x40)) /
                    duration;
            if (fade < 0.0f)
            {
                fade = 0.0f;
            }
        }
        else if (duration == 0.0f)
        {
            if (*(const f32*)((const u8*)work + 0x3c) >=
                *(const f32*)((const u8*)work + 0x40))
            {
                fade = 0.0f;
            }
            else
            {
                fade = 1.0f;
            }
        }

        output[0] = (u8)(fade * (amount * colors[1][0] + inverseAmount * colors[0][0]));
        output[1] = (u8)(fade * (amount * colors[1][1] + inverseAmount * colors[0][1]));
        output[2] = (u8)(fade * (amount * colors[1][2] + inverseAmount * colors[0][2]));
        output[3] = (u8)(fade * (amount * colors[1][3] + inverseAmount * colors[0][3]));
    }
    else
    {
        output[0] = (u8)(amount * colors[1][0] + inverseAmount * colors[0][0]);
        output[1] = (u8)(amount * colors[1][1] + inverseAmount * colors[0][1]);
        output[2] = (u8)(amount * colors[1][2] + inverseAmount * colors[0][2]);
        output[3] = (u8)(amount * colors[1][3] + inverseAmount * colors[0][3]);
    }
}

// FUN_001ED8A0. Clear generated colors, vertices, and render bounds.
void func_001ed8a0(void* work, void* renderData)
{
    typedef struct RuntimeVec4
    {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    } RuntimeVec4;
    typedef struct RuntimeGeometry
    {
        u8 reserved[0x14];
        RuntimeVec3* vertices;
    } RuntimeGeometry;
    typedef struct RuntimeRenderData
    {
        u8 reserved0[0x30];
        u8* colors;
        u8 reserved1[0x28];
        RuntimeGeometry* geometry;
    } RuntimeRenderData;

    RuntimeRenderData* render;
    RuntimeVec3* vertices;
    s32 colorIndex;
    u8* colors;
    RuntimeVec4 bounds;
    s32 count;
    s32 i;
    s16 type;

    render = (RuntimeRenderData*)renderData;
    type = *(s16*)((u8*)work + 0x48);
    switch (type)
    {
        case 0:
            count = *(s32*)(*(u8**)work + 0x0c) * 2 + 1;
            break;
        case 1:
            count = *(s32*)(*(u8**)work + 0x0c) * 3 + 6;
            break;
        case 2:
            count = *(s32*)(*(u8**)work + 0x0c) * 3 + 6;
            break;
    }

    colors = render->colors;
    for (colorIndex = 0; colorIndex < count; colorIndex++, colors += 4)
    {
        colors[0] = 0;
        colors[1] = 0;
        colors[2] = 0;
        colors[3] = 0;
    }

    vertices = render->geometry->vertices;
    for (i = 0; i < count; i++, vertices++)
    {
        vertices->x = 0.0f;
        vertices->y = 0.0f;
        vertices->z = 0.0f;
    }

    bounds.x = 0.0f;
    bounds.y = 0.0f;
    bounds.z = 0.0f;
    bounds.w = 1000000000;
    *(RuntimeVec4*)((u8*)render->geometry + 4) = bounds;
}

// FUN_001ED9E0. Check whether the field resource contains any entries.
s32 func_001ed9e0(void* workData)
{
    RuntimeWork* work;

    work = (RuntimeWork*)workData;
    return *(u16*)(uintptr_t)work->requestFlags != 0;
}

// FUN_001EDA00. Build and register a field render object.
void* func_001eda00(void* work, u32 value)
{
    RuntimeWork* initial;
    RuntimeWork* object;

    if (datGetFlag(0x1400) != 0)
    {
        return NULL;
    }
    initial = func_001ee2e0(work);
    initial->owner = (void*)(uintptr_t)value;
    object = func_001eeb90(initial);
    func_001eefc0(object);
    func_001eee40(object);
    return object;
}

// FUN_001EDA90. Update linked render matrices and cache their translations.
void func_001eda90(RuntimeWork* work)
{
    s32 i;
    RuntimeMatrix* firstMatrix;
    RuntimeMatrix* secondMatrix;
    u8* request;
    s32 offset;

    if (func_001ef000((RuntimeListNode*)work) == 0)
    {
        return;
    }

    firstMatrix = func_004c38c0();
    secondMatrix = func_004c38c0();
    i = 0;
    while (i < *(s16*)((u8*)(uintptr_t)work->requestFlags + 4))
    {
        __asm__ volatile ("lw %1, 4(%2)\n\tsll %0, %3, 3"
                          : "=r"(offset), "=r"(request)
                          : "r"(work), "r"(i));
        func_00318d10(
            *(void**)(request + 0x20),
            *(void**)((u8*)*(void**)(request + 0x18) + offset),
            firstMatrix);
        func_00318d10(
            *(void**)((u8*)(uintptr_t)work->requestFlags + 0x20),
            *(void**)((u8*)*(void**)((u8*)(uintptr_t)work->requestFlags + 0x18) +
                      offset + 4),
            secondMatrix);
        ((RuntimeVec3*)(uintptr_t)work->selection)[i * 2] =
            *(RuntimeVec3*)((u8*)firstMatrix + 0x30);
        ((RuntimeVec3*)(uintptr_t)work->selection)[i * 2 + 1] =
            *(RuntimeVec3*)((u8*)secondMatrix + 0x30);
        i++;
    }

    work->flags |= 2;
    func_004c3880(firstMatrix);
    func_004c3880(secondMatrix);
}

// FUN_001EDBE0 NONMATCHING
void func_001edbe0(void* workData)
{
    typedef struct RuntimeRenderCollection
    {
        u32 flags;
        u8* input;
        u8* entries;
        void** renderObjects;
        u8* commands;
        RuntimeVec3* worldPositions;
    } RuntimeRenderCollection;
    typedef struct RuntimeColor
    {
        u8 red;
        u8 green;
        u8 blue;
        u8 alpha;
    } RuntimeColor;

    RuntimeRenderCollection* work;
    u8* command;
    u8* entry;
    void* matrix;
    void* owner;
    void* material;
    RuntimeVec3 first;
    RuntimeVec3 second;
    RuntimeColor color;
    u32 commandResult;
    u32 frameValue;
    f32 delta;
    s32 active;
    s32 index;

    work = (RuntimeRenderCollection*)workData;
    active = *(f32*)((u8*)*(void**)(work->input + 0x20) + 0xf4) != 0.0f;

    for (index = 0; index < *(s16*)(work->input + 4); index++)
    {
        command = work->commands + index * 0x20;
        entry = work->entries + index * 0x4c;

        if (active != 0)
        {
            func_001eba80((RuntimeCommandWork*)command, &commandResult);
            if ((~work->flags & 8) != 0 &&
                (*(u32*)command & 2) != 0)
            {
                if ((*(u32*)command & 8) != 0)
                {
                    func_001eb920(
                        entry,
                        &work->worldPositions[index * 2],
                        &work->worldPositions[index * 2 + 1]);
                }
                else
                {
                    matrix = func_004c38c0();
                    owner = *(void**)(work->input + 0x20);
                    if ((~*(u16*)((u8*)owner + 0xd8) & 0x8000) != 0)
                    {
                        func_004c32a0(matrix, func_00318b60(owner));
                    }
                    else
                    {
                        func_004c32a0(matrix, (u8*)owner + 0x90);
                    }
                    func_004c6be0(
                        &first,
                        &work->worldPositions[index * 2], matrix);
                    func_004c6be0(
                        &second,
                        &work->worldPositions[index * 2 + 1], matrix);
                    func_001eb920(
                        entry,
                        &first, &second);
                    func_004c3880(matrix);
                }
            }
        }

        if (active != 0)
        {
            delta = D_007CADD4;
        }
        else
        {
            delta = 0.0f;
        }

        if ((work->flags & 0x10) != 0)
        {
            color = *(RuntimeColor*)((u8*)work + 0x20);
            if (color.alpha == 0xff)
            {
                color.alpha = 0xfe;
            }
            material = work->renderObjects[index * 2 + 1];
            ((u8*)material)[4] = color.red;
            ((u8*)material)[5] = color.green;
            ((u8*)material)[6] = color.blue;
            ((u8*)material)[7] = color.alpha;
        }

        func_001ed0d0(
            (RuntimeWork*)entry, &delta);
        frameValue = *(u32*)((u8*)work->renderObjects[index * 2] + 0x18);
        ((void (*)(void*, u32*))func_001e9af0)(
            entry, &frameValue);
    }
}

// FUN_001EDED0. Mark an active field runtime node for processing.
void func_001eded0(RuntimeWork* work)
{
    if (func_001ef000((RuntimeListNode*)work) != 0)
    {
        work->flags |= 4;
    }
}

// FUN_001EDF10. Render every geometry entry with temporary render state.
void func_001edf10(void* workData)
{
    typedef struct RuntimeRenderCollection
    {
        u32 flags;
        u8* input;
        u8* entries;
        void** renderObjects;
        u8* commands;
    } RuntimeRenderCollection;
    typedef void (*GetRenderStateFn)(s32 state, u32* value);
    typedef void (*SetRenderStateFn)(s32 state, u32 value);

    RuntimeRenderCollection* work;
    void* geometry;
    void* owner;
    void* matrix;
    u32 stateApi;
    s32 index;
    u32 state20;
    u32 state10;
    u32 state11;
    u32 state6;
    u32 state8;
    u32 state14;

    work = (RuntimeRenderCollection*)workData;
    __asm__ volatile ("lui %0, 0x96\n\taddiu %0, %0, 0x94"
                      : "=r"(stateApi));
    (*(GetRenderStateFn*)stateApi)(0x14, &state20);
    (*(GetRenderStateFn*)stateApi)(0x0a, &state10);
    (*(GetRenderStateFn*)stateApi)(0x0b, &state11);
    (*(GetRenderStateFn*)stateApi)(8, &state8);
    (*(GetRenderStateFn*)stateApi)(6, &state6);
    (*(GetRenderStateFn*)stateApi)(0x0e, &state14);

    __asm__ volatile ("lui %0, 0x96\n\taddiu %0, %0, 0x90"
                      : "=r"(stateApi));
    (*(SetRenderStateFn*)stateApi)(9, 2);
    (*(SetRenderStateFn*)stateApi)(0x14, 1);
    (*(SetRenderStateFn*)stateApi)(8, 0);
    (*(SetRenderStateFn*)stateApi)(6, 1);
    (*(SetRenderStateFn*)stateApi)(0x0e, 0);
    (*(SetRenderStateFn*)stateApi)(0x0c, 1);

    index = 0;
    while (index < *(s16*)(work->input + 4))
    {
        func_004d7f60(2, 0x48);
        func_004d7f60(3, 0x71801);

        geometry = *(void**)((u8*)work->renderObjects[index * 2] + 4);
        if ((*(u32*)(work->commands + index * 0x20) & 8) != 0)
        {
            func_004cb930(geometry);
        }
        else
        {
            func_004cb930(geometry);
            owner = *(void**)(work->input + 0x20);
            if ((~*(u16*)((u8*)owner + 0xd8) & 0x8000) != 0)
            {
                matrix = func_00318b60(owner);
                func_004cb7f0(geometry, matrix, 0);
            }
            else
            {
                func_004cb7f0(geometry, (u8*)owner + 0x90, 0);
            }
        }
        __asm__ volatile ("" : "+r"(index));
        {
            void* callbackObject;
            void** renderObjects;
            renderObjects = work->renderObjects;
            __asm__ volatile ("" : "+r"(renderObjects));
            callbackObject = *(void**)((u8*)renderObjects + index * 8);
            ((void (*)(void*))*(void**)((u8*)callbackObject + 0x48))(
                callbackObject);
        }
        index++;
    }

    __asm__ volatile ("lui %0, 0x96\n\taddiu %0, %0, 0x90"
                      : "=r"(stateApi));
    (*(SetRenderStateFn*)stateApi)(0x0e, state14);
    (*(SetRenderStateFn*)stateApi)(0x0b, state11);
    (*(SetRenderStateFn*)stateApi)(0x0a, state10);
    (*(SetRenderStateFn*)stateApi)(0x14, state20);
    (*(SetRenderStateFn*)stateApi)(8, state8);
    (*(SetRenderStateFn*)stateApi)(6, state6);
}

// FUN_001EE1D0. Activate a field runtime node and its owner.
void func_001ee1d0(RuntimeWork* work)
{
    if (func_001ef000((RuntimeListNode*)work) != 0)
    {
        work->flags |= 8;
        func_001ef340(*(void**)((u8*)(uintptr_t)work->requestFlags + 0x20));
    }
}

// FUN_001EE220. Reserved field-runtime hook.
void func_001ee220(void)
{
}

// FUN_001EE230. Update the render color and mark it dirty.
void func_001ee230(RuntimeWork* work, const u8* color)
{
    typedef struct RuntimeColor
    {
        u8 red;
        u8 green;
        u8 blue;
        u8 alpha;
    } RuntimeColor;
    typedef struct RuntimeColorWork
    {
        u32 flags;
        u8 reserved[0x1c];
        RuntimeColor color;
    } RuntimeColorWork;
    RuntimeColorWork* colorWork;
    const RuntimeColor* requested;

    colorWork = (RuntimeColorWork*)work;
    requested = (const RuntimeColor*)color;
    if (func_001ef000((RuntimeListNode*)work) == 0)
    {
        return;
    }

    if (colorWork->color.red != requested->red ||
        colorWork->color.green != requested->green ||
        colorWork->color.blue != requested->blue ||
        colorWork->color.alpha != requested->alpha)
    {
        colorWork->color = *requested;
        colorWork->flags |= 0x10;
    }
}

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
        if (input->version == 0x65)
        {
            entry->thirdValue = *(u16*)(source + 0x14);
        }
        else if (input->version == 0x64)
        {
            entry->thirdValue = 0;
        }
        if (input->version == 0x65)
        {
            entry->scale = *(f32*)(source + 0x18);
        }
        else if (input->version == 0x64)
        {
            entry->scale = 10.0f;
        }
        if (input->version == 0x65)
        {
            output->vectors[entryIndex * 2] = *(u32*)(source + 8);
            output->vectors[entryIndex * 2 + 1] = *(u32*)(source + 0x0c);
        }
        else if (input->version == 0x64)
        {
            output->vectors[entryIndex * 2] = *(u32*)(source + 8);
            output->vectors[entryIndex * 2 + 1] = *(u32*)(source + 0x0c);
        }
        if (input->version == 0x65)
        {
            FUN_00521250(output->payloads[entryIndex],
                         inputPayloads[entryIndex],
                         *(u32*)(source + 0x1c));
        }
        else if (input->version == 0x64)
        {
            FUN_00521250(output->payloads[entryIndex],
                         inputPayloads[entryIndex],
                         *(u32*)(source + 0x14));
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
            func_001edbe0(node);
        }
        else if ((node->flags & 2) != 0)
        {
            func_001edbe0(node);
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
    func_00264d80(bytes + 0x63d0);
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

// FUN_001EF7F0 NONMATCHING
s32 func_001ef7f0(RuntimeTask* task)
{
    RuntimeWork* work;

    work = task->workData;
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
    if ((work->requestFlags & 7) != 0)
    {
        work->completedFlags |= work->requestFlags & 7;
        work->requestFlags &= ~7;
    }
    switch (work->state)
    {
        case 0:
            if ((work->flags & 0x2000) == 0)
            {
                H_Snd_PlayBgm((work->flags & 2) != 0 ? 78 : 60, 1);
                work->state = 1;
            }
            break;

        case 1:
            if (func_00236340() == 0)
            {
                work->flags &= ~0x2000;
                work->state = 2;
            }
            break;

        case 2:
            func_003c7650(1);
            if ((work->flags & 0x2c) != 0)
            {
                work->phase = 4;
            }
            else
            {
                work->phase = 6;
            }
            work->state = 3;
            break;

        case 3:
            if (func_00236340() == 0)
            {
                if ((work->flags & 0x200000) != 0)
                {
                    H_Fade_FadeOut();
                    H_Fade_SetType(5);
                    H_Fade_SetDuration(1);
                    func_002362e0();
                    work->flags &= ~0x200000;
                }
                work->state = 4;
            }
            break;

        case 4:
            if (H_Fade_IsFadeOutDone() != 0)
            {
                func_003c77a0();
                work->state = 5;
            }
            break;

        case 5:
            if ((work->flags & 0x200000) != 0)
            {
                func_002362e0();
                work->flags &= ~0x200000;
            }
            else
            {
                H_Fade_SetType(2);
                H_Fade_FadeIn();
            }
            work->state = 6;
            break;

        case 6:
            if (H_Fade_IsFadeOutDone() != 0)
            {
                work->state = 7;
            }
            break;

        case 7:
            func_003c7990(1);
            if (func_003c7850() == 0)
            {
                func_003c7650(1);
                work->state = 0;
            }
            break;

        default:
            work->state = 0;
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
