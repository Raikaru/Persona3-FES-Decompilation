#include "Kosaka/Field/k_fldFrame.h"
#include "Kosaka/Field/k_field.h"
#include "Kosaka/Field/k_unit.h"
#include "Kosaka/Field/k_sceneDraw.h"
#include "Kosaka/k_footstep.h"
#include "Graphics/Model/mdlManager.h"
#include "Graphics/primitive.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kernel/Kwln/kwln.h"
#include "Scene/mt_scene.h"
#include "Scene/resrcManager.h"
#include "libm.h"

#pragma alias func_004912b0_y2 func_004912b0_y2

/* RenderWare's retail globals place memFuncs at absolute offset 0x178. */
#pragma alias rwGlobals_abs rwGlobals
extern u8 rwGlobals_abs[];
typedef void* (*KFldFrameRwCallocFunc)(u32 elemCount, u32 elemSize, u32 hint);
#pragma alias memcpy_k_fldFrame_typed memcpy
extern void* memcpy_k_fldFrame_typed(void* dst, const void* src, u32 size);
#pragma alias memset_k_fldFrame_typed memset
extern void* memset_k_fldFrame_typed(void* dst, s32 value, u32 size);


#define COLLISCTL_SUBSTEPS 3

static RwRGBA sDebugSphereColor = {0, 168, 168, 168};
static const RwV3d sAxisUp = {0.0f, 1.0f, 0.0f};
static const RwV3d sAxisForward = {0.0f, 0.0f, 1.0f};

KwlnTask* K_FldFrame_CreateCollisSphereTask(KwlnTask* parent);
void K_FldFrame_CollisSphereSetDrawEnabled(KwlnTask* collisSphereTask, u32 drawEnabled);

typedef struct FldFrameResourceCollision
{
    void* unk_00;
    void* unk_04;
    void* collisionWorld;
} FldFrameResourceCollision;

extern RwV3d D_00683780[];
extern const char D_00678CE0[];
#pragma alias D_00678CE0_typed D_00678CE0
extern const char D_00678CE0_typed[];
#pragma alias K_Clump_MatUsrDataHasData_typed K_Clump_MatUsrDataHasData
extern u32 K_Clump_MatUsrDataHasData_typed(const void* material, const char* name);
extern RwSphere* func_004912b0(void* atomic);
extern RwCamera* DAT_00960070;
#pragma alias DAT_00960070_abs DAT_00960070
extern u8 DAT_00960070_abs[];
typedef struct FldFrameAtomicQuery
{
    void* output;
    u8 intersection[0x2c];
    void* atomic;
} FldFrameAtomicQuery;
extern s32 func_001ab390(void* collision, const RwV3d* pos, RwV3d* translation,
                         f32 sphereCollisRadius);
extern s32 func_001abd20(void* collisionWorld, const RwV3d* pos, RwV3d* translation,
                          f32 sphereCollisRadius, u16 resTypeId);
extern void* func_001ac950(const RwV3d* line, void* unused,
                           const void* triangle, FldFrameRaycast* raycast);
extern void* func_001acb20(void* collisionWorld, FldFrameRaycast* raycast);
extern void func_00464020(void* collision, void* intersection, void* callback, void* param);
extern void func_00464120(void* collision, void* state, void* callback, void* param);
extern void FUN_004916d0(void* collisionWorld, void* callback, void* param);
extern RwMatrix* func_004cb2f0(void* frame);
extern RwV3d* func_004c6ca0(RwV3d* out, const RwV3d* in,
                            u32 count, const RwMatrix* matrix);
extern f32 func_004c6ac0(const RwV3d* vector);
extern f32 fGpffff8078;
extern f32 fGpffff820c;
#pragma alias jtbl_0096017C_abs jtbl_0096017C
extern u32 jtbl_0096017C_abs[];
extern u8 D_008717A0[];
extern u8 D_0086B180[];


typedef struct FldFrameMovePoint
{
    u32 kind;
    RwV3d position;
    f32 duration;
    KwlnTask* drawTask;
} FldFrameMovePoint;
typedef struct FldFrameMoveWork
{
    u32 state;
    u32 flags;
    u32 mode;
    void* resource;
    s32 animation;
    s32 targetAnimation;
    s32 pathMode;
    s32 pointCount;
    FldFrameMovePoint points[48];
    RwV3d startPosition;
    f32 currentAngle;
    f32 angleStep;
    s32 turnMode;
    s32 frame;
    RwV3d direction;
    f32 directionLength;
    void* drawMatrix;
    s32 frameCount;
    f32 frameRemainder;
    s32 pendingPointCount;
    u8 reserved[0x5a0 - 0x4dc];
} FldFrameMoveWork;
extern void* func_004c38c0(void);
extern void func_004c3880(void* matrix);
extern void func_0045edc0(void* work);
extern s32 func_001dde00(s32 value);
extern s32 func_001ded40(s32 value);
extern s32 func_003182d0(Model* model, s32 layer, s32 animation, s32 mode, s32 flag);
extern void func_003189f0(Model* model, s32 layer, f32 speed);
extern s32 func_00318540(Model* model, s32 layer);
extern void* func_00318b60(u32 id);
extern f32 func_001a5aa0(void* matrix);
extern s32 func_00530da0(f32 value);
extern s32 func_0052e118(s32 value);
extern s32 func_0045ec20(s32 left, s32 right);
extern f32 fGpffff82b0;
extern f32 fGpffff82b4;
extern void func_00318a30(Model* model, const RwV3d* offset, s32 combine);
extern void func_00318a50(Model* model, const RwV3d* axis, f32 angle,
                          s32 combine);
extern void func_004c31b0(RwMatrix* matrix, const RwV3d* axis, f32 angle,
                          s32 combine);
extern void func_001ad9e0(KwlnTask* ctl, void* matrix);
extern f32 func_004c69f0(RwV3d* out, const RwV3d* in);
extern f32 func_0052e9e8(f32 value);
extern KwlnTask* K_Draw_CreatePositionTask(s32 parent);
extern void K_Draw_SetPositionColor(KwlnTask* task, const RwRGBA* color);
extern void K_Draw_SetPositionPos(KwlnTask* task, const RwV3d* position);
extern void* func_0048dab0(s32 count, s32 mode, const RwV3d* position);
extern void func_0048d480(f32 frame, void* curve, s32 flags, RwV3d* output, s32 unused);
extern void func_0048da30(void* curve);
extern void* func_001a4cd0(s32 parent);
extern void func_001a4dc0(void* task, const RwRGBA* color);
extern void func_001a4e60(void* task, const RwV3d* position);
extern u8 D_007E095F[];
extern u8 D_007E095E[];
extern u8 D_007E0960[];
extern u8 D_007E0961[];
extern u8 D_007E094C[];
typedef struct FldFrameCollisionTriangle
{
    RwV3d normal;
    u8 reserved[16];
    const RwV3d* vertices[3];
} FldFrameCollisionTriangle;
typedef struct FldFrameCollisionCollector
{
    RwV3d points[64];
    RwV3d normals[64];
    f32 distances[64];
    u8 reserved[0x400];
    u32 mode;
    u32 count;
    u32 blockingCount;
    u8 tail[0x28];
    void* owner;
} FldFrameCollisionCollector;
typedef struct FldFrameCollisionQuery
{
    u8 prefix[0x10];
    RwV3d center;
    f32 radius;
    u8 reserved[0x18];
    u32 type;
} FldFrameCollisionQuery;
typedef struct FldFrameResourceSet
{
    u32 count;
    u32 reserved;
    void* items[64];
} FldFrameResourceSet;
typedef struct FldFrameResourceQuery
{
    void* output;
    u32 direction[6];
    u32 directionMode;
    RwV4d position;
    void* resource;
} FldFrameResourceQuery;
typedef struct FldFrameResourceTable
{
    u32 count;
    u8 reserved[4];
    void* items[64];
} FldFrameResourceTable;
typedef struct FldFrameMaterialWork
{
    u8 reserved_00[8];
    u32 flags;
    u8 reserved_0c[0x14];
    void* items;
    u32 itemCount;
    u8 reserved_28[4];
    void* indices;
} FldFrameMaterialWork;
typedef struct FldFrameMaterialLink
{
    u8 reserved_00[0x18];
    FldFrameMaterialWork* work;
} FldFrameMaterialLink;
typedef struct FldFrameMaterialSet
{
    FldFrameResourceTable* table;
    u8 reserved_04[0x2c];
    FldFrameMaterialLink* link;
} FldFrameMaterialSet;
typedef struct FldFrameMaterialIndex
{
    u8 reserved_00[6];
    u16 value;
} FldFrameMaterialIndex;
static const char sFldFrameMaterialName[] = "per3TrnsWall";
extern u8 DAT_008717f0[];
extern void* func_00318b80(u32 id);
extern void* func_00318b60(u32 id);
extern void* func_004353f0(void* arg);
extern void* func_002ff790_k_fldFrame_void(void* object);
extern u32 func_001acb70(void* collisionWorld, const RwV3d* line, RwV3d* hitPointDst);
extern u32 func_001afd40(KwlnTask* task, const RwV3d* position, f32 duration);
#include "Kosaka/k_clump.h"
#include "Kosaka/Field/k_dungeon.h"
#include "Main/g_data.h"
#include "h_cdvd.h"
#include "h_snd.h"
#include "rw/rpusrdat.h"
#include "rw/rpworld.h"
#include "temporary.h"
typedef void* (*KClumpCallback)(void* object, void* data);
typedef struct KClumpMaterialNode
{
    void* object;       // 0x00
    u32 enabled;         // 0x04
    u32 flags;           // 0x08
    f32 colorScale[4];   // 0x0c
    u32 kind;            // 0x1c
    u8 reserved[8];      // 0x20
    struct KClumpMaterialNode* next; // 0x28
} KClumpMaterialNode;
typedef struct KClumpContainer
{
    u8 reserved[0x18];
    void* resources;     // 0x18
} KClumpContainer;
typedef struct KClumpResourceList
{
    u8 reserved[0x20];
    void** materials;     // 0x20
    u32 count;            // 0x24
} KClumpResourceList;
typedef struct KClumpStreamWork
{
    u32 state;
    u8 pad04[0x0c];
    u32 mode;
    void* stream;
    u32 current;
    u16 currentStatus;
    u16 pad1e;
    u32 count;
    void* queuedStreams[8];
    u32 queuedValues[8];
    u16 queuedStatus[8];
} KClumpStreamWork;
typedef struct KClumpUserDataContext
{
    char name[0x40];
    u32 count;
} KClumpUserDataContext;
extern void* func_004916d0(void* object, KClumpCallback callback, void* data);
extern void* func_004932c0(void* object, KClumpCallback callback, void* data);
extern void* func_004cb6e0(void* object, KClumpCallback callback, void* data);
extern void* func_0048ee30(void* object, s32 index);
extern s32 func_0048ede0(void* object);
extern s32 func_0048ef30(void* object);
extern s32 func_0048a2c0(void* object);
extern s32 func_0048a480(void* object);
extern void func_0048a3f0(void* object, u32 mode);
extern void func_0048a2a0(void* object, void* data);
extern void func_00466640(void* data);
extern void func_001b5a30(void* material);
extern RwSphere* func_004912b0_y2(void* object);
extern void* func_0034fcd0(void* data);
extern void* func_0034fd10(void* data);
extern void* func_0034fd30(void* data);
extern void* func_0034fd50(void* data);
extern void* func_0034fd70(void* data, u16 value);
extern void* func_0034fcf0(void* data);
extern void* func_0034fdf0(void* data, void* value);
extern void* func_0034fe80(void* data, void* value);
extern void* func_001021c0(void* path, u8* mode);
extern u32 func_001c7130(f32 value, u32 state);
extern void FUN_001099d0(u32 value, ...);
extern void FUN_00108fd0(u32 value, ...);
extern u8 FUN_0016ef30(void);
extern u32 FUN_0016f190(u32 flag);
extern u32 FUN_0017e480(u32 a, u32 b, u32 c, u32 d);
extern void K_Assert(const char* message, s32 line);
extern void (*D_00960090)(u32 state, ...);
extern u32 D_007CE204;
extern u32 D_007CC1E4;
extern u32 D_007CC1F4;
extern u32 D_007CC1F8;
extern u32 D_007CC1C0;
extern u32 D_007CE158;
extern u32 D_008668F0[];
extern void (*jtbl_0096017C)(void* memory);
extern void* D_007D2D60;
extern u8 D_00960090_abs[];
extern u8 D_007D2D60_abs[];
extern u32 D_00960184[];
extern char D_00678C78;
extern char D_00678C78_abs[];
extern u32 D_00678C00[];
extern const char D_00678C28[];
extern const char D_00678C38[];
extern const char D_00678C48[];
extern const char D_00678C60[];
extern f32 D_007CE154;
extern const char D_00678BD8[];
extern const char D_00678BE8[];
extern const char D_00678C88[];
extern const char D_00678CA0[];
extern const char D_00678CB8[];
extern u8 D_0067F080[];
extern u8 D_0067F100[];
extern u8 D_0067F140[];
extern u8 D_0067F180[];
extern u8 D_0067F200[];
extern u8 D_0067F240[];
extern u8 D_0067F2C0[];
extern u8 D_0067F300[];
extern u8 D_0067F340[];
extern u8 D_0067F380[];
extern void* func_001a65c0(void* geometry, const char** name);
extern void* func_001a6860(void* object, u32* context);
extern void* func_001a6d20(void* object, u32* context);
extern void func_001a71a0(u32* state, u32 kind, void* object, u32 enabled, u32 flags);
extern void* func_001a7370(void* material, u32* state);
extern void* func_001a74e0(void* object, u32* state);
extern void func_001a7710(u32* state);
extern void func_001a7910(void* object, f32* scale);
extern void func_001a8920(u32* entries, const u32* source);
extern s32 func_001a8db0(KwlnTask* task);
extern s32 func_001a91b0(KwlnTask* task, void* data);
static inline u32 fldFrameAddOffset(u32 offset, u32 base)
{
    return offset + base;
}
static inline u32 fldFrameIndexedAddress(u32 index, u32 base)
{
    return index * 4 + base;
}

static inline FldFrameMoveWork* fldFrameMoveWork(KwlnTask* task)
{
    return (FldFrameMoveWork*)task->workData;
}
static inline Model* fldFrameMoveModel(const FldFrameMoveWork* work)
{
    return *(Model**)((u8*)work->resource + 0x128);
}
static KwlnTask* fldFrameMoveCtl(const FldFrameMoveWork* work)
{
    if (work->resource == NULL)
    {
        return NULL;
    }
    return *(KwlnTask**)((u8*)work->resource + 0x1e0);
}
static void fldFrameMoveCopyPoint(FldFrameMovePoint* dst,
                                  const FldFrameMovePoint* src)
{
    *dst = *src;
}
static void fldFrameMoveResolvePosition(const RwV3d* input, RwV3d* output)
{
    RwV3d line[2];

    line[0] = *input;
    line[1] = *input;
    if (K_Scene_001a0250() != false)
    {
        line[0].y += 600.0f;
    }
    else
    {
        line[0].y += 200.0f;
    }
    line[1].y -= 1000.0f;
    if (K_FldFrame_Raycast(line, output) == false)
    {
        *output = *input;
    }
}
static void fldFrameMoveCreateDebugPoint(FldFrameMoveWork* work,
                                         FldFrameMovePoint* point,
                                         const RwRGBA* color)
{
    if ((work->flags & 0x80000000) != 0)
    {
        point->drawTask = K_Draw_CreatePositionTask(0);
        if (point->drawTask != NULL)
        {
            K_Draw_SetPositionColor(point->drawTask, color);
            K_Draw_SetPositionPos(point->drawTask, &point->position);
        }
    }
}
static void fldFrameMoveAppend(FldFrameMoveWork* work,
                               u32 kind,
                               const RwV3d* position,
                               f32 duration)
{
    FldFrameMovePoint* point;

    if (work->pointCount >= 47)
    {
        return;
    }
    point = &work->points[work->pointCount];
    point->kind = kind;
    point->position = *position;
    point->duration = duration;
    point->drawTask = NULL;
    work->pointCount++;
}
static void fldFrameMoveSetAnimation(FldFrameMoveWork* work,
                                     s16 animation,
                                     u16 blendFrames)
{
    Model* model = fldFrameMoveModel(work);

    if (model == NULL)
    {
        return;
    }
    if (mdlAnimGetId(model, 0) != animation)
    {
        mdlAnimSet(model, 0, animation, blendFrames, 1);
    }
    mdlAnimSetSpeed(model, 0, 1.0f);
}
static f32 FldFrame_Dot(const RwV3d* a, const RwV3d* b)
{
    return a->x * b->x + a->y * b->y + a->z * b->z;
}
static f32 FldFrame_LengthSquared(const RwV3d* value)
{
    return FldFrame_Dot(value, value);
}
static void FldFrame_CollisionCollectorReset(FldFrameCollisionCollector* collector)
{
    s32 i;

    collector->mode = 0;
    collector->count = 0;
    collector->blockingCount = 0;
    collector->owner = NULL;

    for (i = 0; i < 64; i++)
    {
        collector->points[i].x = 0.0f;
        collector->points[i].y = 0.0f;
        collector->points[i].z = 0.0f;
        collector->normals[i].x = 0.0f;
        collector->normals[i].y = 0.0f;
        collector->normals[i].z = 0.0f;
        collector->distances[i] = 1.0e30f;
    }
}
static s32 FldFrame_FindCollision(const FldFrameCollisionCollector* collector,
                                  const RwV3d* normal)
{
    s32 i;

    for (i = 0; i < (s32)collector->count; i++)
    {
        if (collector->normals[i].x == normal->x &&
            collector->normals[i].y == normal->y &&
            collector->normals[i].z == normal->z)
        {
            return i;
        }
    }
    return -1;
}
static void FldFrame_RecordCollision(FldFrameCollisionCollector* collector,
                                      const RwV3d* point, const RwV3d* normal,
                                      f32 distance)
{
    s32 index;

    index = FldFrame_FindCollision(collector, normal);
    if (index < 0)
    {
        if (collector->count >= 64)
        {
            return;
        }
        index = collector->count;
        collector->count++;
    }

    if (distance < collector->distances[index])
    {
        collector->points[index] = *point;
        collector->normals[index] = *normal;
        collector->distances[index] = distance;
    }
}
static void FldFrame_ApplyCollisions(FldFrameCollisionCollector* collector,
                                     RwV3d* translation, f32 radius)
{
    s32 i;

    for (i = 0; i < (s32)collector->count; i++)
    {
        RwV3d normal;
        f32 distance;
        f32 correction;
        f32 inward;

        distance = collector->distances[i];
        correction = radius - distance;
        if (correction <= 0.0f)
        {
            continue;
        }

        normal = collector->normals[i];
        if (FldFrame_LengthSquared(&normal) > 0.000001f)
        {
            RwV3dNormalize(&normal, &normal);
        }

        inward = FldFrame_Dot(translation, &normal);
        if (inward < 0.0f)
        {
            translation->x -= normal.x * inward;
            translation->y -= normal.y * inward;
            translation->z -= normal.z * inward;
        }

        if (FldFrame_LengthSquared(translation) < 0.000001f)
        {
            translation->x += normal.x * correction;
            translation->y += normal.y * correction;
            translation->z += normal.z * correction;
        }
    }
}
static u32 kclump_word(const void* object, u32 offset)
{
    return *(const u32*)((const u8*)object + offset);
}
static void kclump_set_word(void* object, u32 offset, u32 value)
{
    *(u32*)((u8*)object + offset) = value;
}
static f32 kclump_float(const void* object, u32 offset)
{
    return *(const f32*)((const u8*)object + offset);
}
static void kclump_set_float(void* object, u32 offset, f32 value)
{
    *(f32*)((u8*)object + offset) = value;
}
static inline void* kclump_alloc(u32 count, u32 size, u32 flags)
{
    return (*(void* (**)(u32, u32, u32))D_00960184)(count, size, flags);
}
static void kclump_free(void* memory)
{
    if (memory != NULL)
    {
        jtbl_0096017C(memory);
    }
}
static void kclump_call_resource(void* resource)
{
    void (*render)(void);

    render = *(void (**)(void))((u8*)resource + 0x48);
    if (render != NULL)
    {
        render();
    }
}
static u32 kclump_render_item(KClumpMaterialNode* item, u32 callbackFlag)
{
    RwSphere* sphere;

    sphere = func_004912b0_y2(item->object);
    if (sphere == NULL || RwCameraFrustumTestSphere((RwCamera*)D_007D2D60, sphere) == rwSPHEREOUTSIDE)
    {
        return 0;
    }

    if (item->enabled == 1)
    {
        D_00960090(0xe, 0);
    }
    if (*(u32*)callbackFlag == 1)
    {
        kclump_call_resource(item->object);
    }
    if (item->enabled == 1)
    {
        D_00960090(0xe, 1);
    }
    return 1;
}
static u32 kclump_scale_color(u32 component, f32 scale)
{
    f32 value;

    value = (f32)component * scale;
    if (value > 255.0f)
    {
        return 0xff;
    }
    if (value < 0.0f)
    {
        return 0;
    }
    return (u32)value;
}
static void kclump_render_list(void* list, u32 callbackFlag)
{
    KClumpMaterialNode* item;

    item = list != NULL ? *(KClumpMaterialNode**)list : NULL;
    while (item != NULL)
    {
        kclump_render_item(item, callbackFlag);
        item = item->next;
    }
}

// FUN_001a8920
void func_001a8920(u32* entries, const u32* source)
{
    u32* destination;
    s32 i;
    u32 value;

    if ((s32)entries[0] >= 0x80)
    {
        K_Assert(D_00678C78_abs, 0x3eb);
    }
    destination = (u32*)(entries[0] * 11 * 4);
    destination = (u32*)((u8*)destination + (u32)entries);
    destination++;
    i = 11;
    do
    {
        value = *source++;
        i--;
        *destination = value;
        destination++;
    } while (i > 0);
    entries[0]++;
}

// FUN_001a89c0
s32 func_001a89c0(const u32* left, const u32* right)
{
    RwCamera* camera;
    RwMatrix* cameraMatrix;
    RwV3d leftDelta;
    RwV3d rightDelta;
    RwV3d cameraPosition;
    f32 leftDistance;
    f32 rightDistance;

    camera = kwlnGetMainCamera();
    cameraMatrix = func_004cb2f0(*(void**)((u8*)camera + 4));
    cameraPosition = cameraMatrix->pos;
    leftDelta.x = func_004cb2f0(*(void**)(*left + 4))->pos.x - cameraPosition.x;
    leftDelta.y = func_004cb2f0(*(void**)(*left + 4))->pos.y - cameraPosition.y;
    leftDelta.z = func_004cb2f0(*(void**)(*left + 4))->pos.z - cameraPosition.z;
    rightDelta.x = func_004cb2f0(*(void**)(*right + 4))->pos.x - cameraPosition.x;
    rightDelta.y = func_004cb2f0(*(void**)(*right + 4))->pos.y - cameraPosition.y;
    rightDelta.z = func_004cb2f0(*(void**)(*right + 4))->pos.z - cameraPosition.z;
    leftDistance = RwV3dLength(&leftDelta);
    rightDistance = RwV3dLength(&rightDelta);
    return (s32)(leftDistance - rightDistance);
}

// FUN_001a8b10
void func_001a8b10(u32* entries)
{
    s32 i;
    KClumpMaterialNode* item;
    RwSphere* sphere;

    {
        s32 count = (s32)entries[0];
        qsort(entries + 1, count, 0x2c,
              (int (*)(const void*, const void*))func_001a89c0);
    }
    for (i = (s32)entries[0] - 1; i >= 0; i--)
    {
        item = (KClumpMaterialNode*)((u8*)entries + 4 + i * 0x2c);
        sphere = func_004912b0_y2(item->object);
        if (RwCameraFrustumTestSphere(
                (RwCamera*)*(void**)D_007D2D60_abs, sphere) != rwSPHEREOUTSIDE)
        {
            if (item->enabled == 1)
            {
                (*(void (**)(u32, ...))D_00960090_abs)(0xe, 0);
            }
            func_001a7910(item->object, (f32*)((u8*)item + 0x0c));
            if (item->colorScale[3] < 1.0f && item->colorScale[3] > 0.0f)
            {
                void (**renderState)(u32, ...);
                renderState = (void (**)(u32, ...))D_00960090_abs;
                (*renderState)(6, 1);
                (*renderState)(8, 1);
                RpSkyRenderStateSet(2, (void*)0x44);
                RpSkyRenderStateSet(3, (void*)0x72001);
                if (item->kind == 2)
                {
                    (*(void (**)(void*))((u8*)item->object + 0x48))(
                        item->object);
                }
                renderState = (void (**)(u32, ...))D_00960090_abs;
                (*renderState)(6, 1);
                (*renderState)(8, 0);
                switch (item->kind)
                {
                case 2:
                {
                    RpSkyRenderStateSet(2, (void*)0x44);
                    RpSkyRenderStateSet(3, (void*)0x717fb);
                }
                    break;
                case 4:
                {
                    RpSkyRenderStateSet(2, (void*)0x42);
                    RpSkyRenderStateSet(3, (void*)0x71801);
                }
                    break;
                case 3:
                {
                    RpSkyRenderStateSet(2, (void*)0x48);
                    RpSkyRenderStateSet(3, (void*)0x71801);
                }
                    break;
                }
                (*(void (**)(void*))((u8*)item->object + 0x48))(item->object);
            }
            if (item->enabled == 1)
            {
                (*(void (**)(u32, ...))D_00960090_abs)(0xe, 1);
            }
        }
    }
}

/* W420 operand-order probes for the loop address at offset 360:
 * direct pointer, scalar base+offset, base/offset inline, adjacent inline,
 * one-line inline, and opt_propagation-reset inline variants all grew the
 * object to 576/560 with nd192-193; replacing all indexed accesses stayed
 * nd143/560. The single-index helper was 576/560 nd193. Retain the nd2/552
 * indexed form. */
// FUN_001a8db0
s32 func_001a8db0(KwlnTask* task)
{
    u32* work;
    s32 i;
    u32 mode;

    work = (u32*)task->workData;
    switch (work[0])
    {
    case 0:
    {
        if (work[3] == 0)
        {
            if (H_Cdvd_IsFileLoaded((HCdvd*)work[1]) == 0)
            {
                break;
            }
            if (work[1] != 0)
            {
                work[5] = (u32)func_0034fcd0(*(void**)((u8*)work[1] + 0x110));
                H_Cdvd_Destroy((HCdvd*)work[1]);
                work[1] = 0;
            }
        }
        else
        {
            work[5] = (u32)func_0034fcd0(func_001021c0(work + 0x1d, (u8*)&mode));
        }
        work[0]++;
    }
        break;
    case 1:
        break;
    case 2:
    {
        if (work[4] == 0 && work[8] == 0)
        {
            work[0] = 1;
        }
        else
        {
            if (work[4] == 1)
            {
                if (work[6] < work[2])
                {
                    func_0034fd30((void*)work[5]);
                    func_0034fd70(
                        (void*)*(volatile u32*)&work[5],
                        (u16)work[7]);
                    work[6]++;
                }
                else
                {
                    work[4] = 0;
                }
            }
            for (i = 0; i < 8; i++)
            {
                if (*(u32*)(fldFrameIndexedAddress((u32)i, (u32)work) + 36) != 0)
                {
                    if (work[0x11 + i] < work[2])
                    {
                        func_0034fd30((void*)work[9 + i]);
                        func_0034fd70((void*)work[9 + i], *(u16*)((u8*)work + 100 + i * 2));
                        work[0x11 + i]++;
                    }
                    else
                    {
                        func_0034fcf0((void*)work[9 + i]);
                        work[9 + i] = 0;
                        work[8]--;
                    }
                }
            }
        }
    }
        break;
    case 3:
    {
        return -1;
    }
    }
    return 0;
}

// FUN_001a8fe0
void func_001a8fe0(KwlnTask* task)
{
    u32* work;
    s32 i;
    KwlnTask* parent;

    parent = task;
    work = (u32*)parent->workData;
    for (i = 0; i < 8; i++)
    {
        if (*(u32*)((u8*)work + (i * 4) + 36) != 0)
        {
            func_0034fcf0((void*)*(u32*)((u8*)work + (i * 4) + 36));
        }
    }
    if (work[5] != 0)
    {
        func_0034fcf0((void*)work[5]);
    }
    (*(void (**)(void*))jtbl_0096017C_abs)(parent->workData);
}

/* W389: nd 10, obj 524/528 before and after; absolute rwGlobals+0x184 call fixed the retail load form, declaration swap was neutral. Remaining nd10 is loop register colouring (base/index a2/a3 swap) plus commutative addu. */
// FUN_001a9080
KwlnTask* func_001a9080(KwlnTask* parent, const char* path, u32 state, HCdvd* cdvd)
{
    KwlnTask* task;
    u32* work;

    work = (u32*)(*(void* (**)(u32, u32, u32))D_00960184)(1, 0xb4, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreate(parent, D_00678C88, 0x14,
                          (KwlnTaskUpdateFunc)func_001a8db0,
                          (KwlnTaskDestroyFunc)func_001a8fe0, work);
    if (cdvd == NULL)
    {
        work[1] = (u32)H_Cdvd_Request(path, 0);
    }
    else
    {
        work[1] = (u32)cdvd;
        work[3] = 1;
    }
    work[2] = state;
    strcpy((char*)&work[0x1d], path);
    return task;
}

// FUN_001a9180
u32 func_001a9180(const KwlnTask* task)
{
    if (task == NULL)
    {
        return true;
    }
    return *(s32*)task->workData >= 1;
}

// FUN_001a91b0
s32 func_001a91b0(KwlnTask* task, void* data)
{
    KClumpStreamWork* work;
    KClumpStreamWork* indexedWork;
    s32 index;
    void* stream;
    u32 indexOffset;
    void** streamSlot;

    work = (KClumpStreamWork*)task->workData;
    index = -1;
    if (work->mode == 1)
    {
        index = 0;
        while (index < 8)
        {
            indexedWork = work;
            indexedWork = (KClumpStreamWork*)((s32)indexedWork + index * 4);
            if (indexedWork->queuedStreams[0] == NULL)
            {
                break;
            }
            index++;
        }
        indexOffset = index * 4;
        indexedWork = work;
        indexedWork = (KClumpStreamWork*)(indexOffset + (s32)indexedWork);
        streamSlot = &indexedWork->queuedStreams[0];
        *streamSlot = func_0034fd50(work->stream);
        stream = *streamSlot;
        func_0034fdf0(stream, data);
        *(u32*)((u8*)work->queuedValues + indexOffset) = 0;
        work->queuedStatus[index] = 2;
        work->count++;
    }
    else
    {
        func_0034fd10(work->stream);
        func_0034fdf0(work->stream, data);
        work->current = 0;
        work->mode = 1;
        work->currentStatus = 2;
    }
    work->state = 2;
    return index;
}

// FUN_001a92d0
void func_001a92d0(KwlnTask* task, s32 index, void* data)
{
    u32* work = (u32*)task->workData;
    void* stream;

    if (index >= 0)
    {
        stream = (void*)work[9 + index];
        if (stream != NULL)
        {
            func_0034fdf0(stream, data);
        }
    }
    else
    {
        func_0034fdf0((void*)work[5], data);
    }
}

// FUN_001a9330
void func_001a9330(KwlnTask* task, s32 index, void* data)
{
    u32* work = (u32*)task->workData;
    void* stream;

    if (index >= 0)
    {
        stream = (void*)work[9 + index];
        if (stream != NULL)
        {
            func_0034fe80(stream, data);
        }
    }
    else
    {
        func_0034fe80((void*)work[5], data);
    }
}

// FUN_001a9390
void func_001a9390(KwlnTask* task, s32 index, u16 value)
{
    u32* work = (u32*)task->workData;

    if (index >= 0)
    {
        if (work[9 + index] != 0)
        {
            *((u16*)((u8*)work + 0x64) + index) = value;
        }
    }
    else
    {
        *(u16*)((u8*)work + 0x1c) = value;
    }
}

// FUN_001a93d0
u32 func_001a93d0(const KwlnTask* task, s32 index)
{
    u32* work = (u32*)task->workData;
    if (index >= 0)
    {
        return work[0x11 + index];
    }
    return work[6];
}

// FUN_001a9400
void func_001a9400(KwlnTask* task, s32 index)
{
    u32* work = (u32*)task->workData;
    if (index >= 0)
    {
        if (work[9 + index] != 0)
        {
            func_0034fcf0((void*)work[9 + index]);
            work[9 + index] = 0;
            work[8]--;
        }
    }
    else
    {
        work[4] = 0;
    }
}

// FUN_001a9470
void func_001a9470(KwlnTask* task)
{
    u32* work;
    s32 i;

    if (task == NULL)
    {
        return;
    }
    work = (u32*)task->workData;
    for (i = 0; i < 8; i++)
    {
        if (*(u32*)((u8*)work + i * 4 + 0x24) != 0)
        {
            func_0034fcf0((void*)*(u32*)((u8*)work + i * 4 + 0x24));
            *(u32*)((u8*)work + i * 4 + 0x24) = 0;
        }
    }
    work[8] = 0;
    if (work[5] != 0)
    {
        work[4] = 0;
    }
}

// FUN_001a9500
s32 func_001a9500(KwlnTask* task)
{
    typedef struct KClumpSoundUpdateWork
    {
        s32 state;
        s32 delay;
        s32 timer;
        s32 count;
        u32 values[8];
        RwV3d positions[8];
        u32 sounds[8];
        u32 flags[8];
    } KClumpSoundUpdateWork;
    KClumpSoundUpdateWork* work;
    s32 i;
    s32 fieldIndex;
    u8* fieldBase;

    work = (KClumpSoundUpdateWork*)task->workData;
    switch (work->state)
    {
    case 0:
        work->state++;
    case 1:
        if (work->count > 0)
        {
            fieldBase = (u8*)K_Field_Get();
            fieldIndex = (s32)work->values[0];
            func_001a91b0(
                *(KwlnTask**)(fieldBase + fieldIndex * 4 + 0x11f4),
                &work->positions[0]);
            if (((s32)work->sounds[0] <= -1) != 0)
            {
            }
            else
            {
                func_0010a4e0(1, 8, (s16)work->sounds[0], (s16)work->flags[0]);
            }
            work->count--;
            for (i = 1; i < 8; i++)
            {
                *((u32*)work + 4 + i - 1) = *((u32*)work + 4 + i);
                ((RwV3d*)work)[4 + i - 1] = ((RwV3d*)work)[4 + i];
                work->sounds[i - 1] = work->sounds[i];
                work->flags[i - 1] = work->flags[i];
            }
            work->timer = 0;
            work->state++;
        }
        break;
    case 2:
        if (work->timer < work->delay)
        {
            work->timer++;
        }
        else
        {
            work->state = 1;
        }
        break;
    case 3:
        return -1;
    }
    return 0;
}

// FUN_001a9690
void func_001a9690(KwlnTask* task)
{
    (*(void (**)(void*))((u8*)0x00960000 + 0x17c))(task->workData);
}

// FUN_001a96c0
KwlnTask* func_001a96c0(KwlnTask* parent)
{
    u32* work;
    KwlnTask* task;

    work = (u32*)(*(void* (**)(u32, u32, u32))D_00960184)(1, 0xd0, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreateWithAutoPriority(parent, 10, D_00678CA0,
                                          (KwlnTaskUpdateFunc)func_001a9500,
                                          (KwlnTaskDestroyFunc)func_001a9690, work);
    work[1] = 0x14;
    return task;
}

// FUN_001a9760
void func_001a9760(KwlnTask* task, u32 value, const RwV3d* position, u32 sound, u32 flags)
{
    typedef struct KClumpSoundWork
    {
        s32 header[3];
        s32 count;
        u32 values[8];
        RwV3d positions[8];
        u32 sounds[8];
        u32 flags[8];
    } KClumpSoundWork;
    KClumpSoundWork* work;

    if (task == NULL)
    {
        return;
    }
    work = (KClumpSoundWork*)task->workData;
    if (work->count >= 8)
    {
        K_Assert(&D_00678C78, 0x260);
    }
    work->values[work->count] = value;
    work->positions[work->count] = *position;
    work->sounds[work->count] = sound;
    work->flags[work->count] = flags;
    work->count++;
}

// FUN_001a9850 NONMATCHING
void func_001a9850(void)
{
    s32 floor;
    u32 scenario;

    if (D_007CE204 == 1)
    {
        return;
    }
    floor = (s32)K_FldDungeon_GetCurrentFloor();
    if (floor > 0)
    {
        if (floor >= 2 && (s32)FUN_0016f380(1) > 0)
        {
            H_Snd_PlayBgm((s16)FUN_0016f380(1), 1);
            return;
        }
        scenario = datGetScenarioMode();
        if (scenario == 0)
        {
            if (floor >= 0x191) H_Snd_PlayBgm(0x46, 1);
            else if (floor >= 0x190) H_Snd_PlayBgm(1, 1);
            else if (floor >= 0x122) H_Snd_PlayBgm(1, 1);
            else if (floor >= 0xff) H_Snd_PlayBgm(0x4b, 1);
            else if (floor >= 0xd7) H_Snd_PlayBgm(0x4a, 1);
            else if (floor >= 0xa5) H_Snd_PlayBgm(0x49, 1);
            else if (floor >= 0x73) H_Snd_PlayBgm(0x48, 1);
            else if (floor >= 0x41) H_Snd_PlayBgm(0x51, 1);
            else if (floor >= 0x11) H_Snd_PlayBgm(0x46, 1);
            else if (floor >= 2) H_Snd_PlayBgm(1, 1);
            else if (floor > 0) H_Snd_PlayBgm(0x47, 1);
        }
        else
        {
            if (floor >= 0xa1) H_Snd_PlayBgm(100, 1);
            else if (floor >= 0x83) H_Snd_PlayBgm(99, 1);
            else if (floor >= 0x65) H_Snd_PlayBgm(98, 1);
            else if (floor >= 0x47) H_Snd_PlayBgm(97, 1);
            else if (floor >= 0x29) H_Snd_PlayBgm(96, 1);
            else if (floor >= 0x15) H_Snd_PlayBgm(95, 1);
            else if (floor >= 2) H_Snd_PlayBgm(0x5e, 1);
            else if (floor == 1) H_Snd_PlayBgm(0x65, 1);
        }
    }
    else
    {
    if ((gMtScene->fldMajorId == 7 && gMtScene->fldMinorId == 6) ||
        (gMtScene->fldMajorId == 8 && gMtScene->fldMinorId == 1) ||
        (gMtScene->fldMajorId == 9 && gMtScene->fldMinorId == 1))
    {
        if ((u8)FUN_0016ef30() == 8)
        {
            FUN_001099d0(0x47, 1);
            return;
        }
    }
    if (datGetFlag(0xe00) == 1)
    {
        FUN_001099d0(0x13);
        return;
    }
    if (datGetFlag(0xe60) == 1)
    {
        FUN_00108fd0(0x14);
        return;
    }
    if (gMtScene->fldMajorId == 0x1f)
    {
        FUN_001099d0(0x14);
        return;
    }
    if (datGetFlag(0xeef) == 1)
    {
        FUN_001099d0(0x14);
        return;
    }
    if (gMtScene->fldMajorId == 0x21) FUN_00108fd0(0x14);
    else if (gMtScene->fldMajorId == 0x22) FUN_001099d0(0x16);
    else if (gMtScene->fldMajorId == 0x23) FUN_001099d0(0x15);
    else if (gMtScene->fldMajorId == 0x25) FUN_001099d0(0x47);
    else if (gMtScene->fldMajorId == 0x0e && gMtScene->fldMinorId == 5) FUN_00108fd0(0x14);
    else if (gMtScene->fldMajorId == 8 && gMtScene->fldMinorId == 3) FUN_001099d0(0x36, 1);
    else if (gMtScene->fldMajorId == 5 && gMtScene->fldMinorId == 3) FUN_001099d0(0x36, 1);
    else if (gMtScene->fldMajorId == 8 && gMtScene->fldMinorId == 9) FUN_00108fd0(0x14);
    else if (gMtScene->fldMajorId == 7 && gMtScene->fldMinorId == 1)
    {
        if ((u8)FUN_0016ef30() < 2 || (u8)FUN_0016ef30() > 6)
            FUN_00108fd0(0x14);
    }
    else if (gMtScene->fldMajorId == 8 || gMtScene->fldMajorId == 9 ||
             gMtScene->fldMajorId == 10 || gMtScene->fldMajorId == 0xc ||
             (gMtScene->fldMajorId == 7 && gMtScene->fldMinorId == 9))
    {
        if (FUN_0017e480(4, 5, 0xc, 0x1f) == 1 ||
            FUN_0017e480(3, 1, 3, 5) == 1)
            FUN_001099d0(0x57, 1);
        else if (FUN_0017e480(1, 1, 2, 0x1c) == 1)
            FUN_001099d0(0x50);
    }
    else if (gMtScene->fldMajorId == 5 && gMtScene->fldMinorId == 1) FUN_001099d0(0x19);
    else if (gMtScene->fldMajorId == 0x0e) FUN_001099d0(0x20, 1);
    else if (gMtScene->fldMajorId == 6)
    {
        if (FUN_0017e480(4, 5, 8, 0x1f) == 1 ||
            FUN_0017e480(3, 1, 3, 5) == 1) FUN_001099d0(0x32, 1);
        else if (FUN_0017e480(9, 1, 0xc, 0x1f) == 1) FUN_001099d0(0x33);
        else if (FUN_0017e480(1, 1, 2, 0x1c) == 1) FUN_001099d0(0x34);
    }
    else if (gMtScene->fldMajorId == 7)
    {
        if (FUN_0017e480(4, 5, 0xc, 0x1f) == 1) FUN_001099d0(0x35);
        else if (FUN_0017e480(1, 1, 2, 0x1c) == 1) FUN_001099d0(0x4d);
        else if (FUN_0017e480(3, 1, 3, 5) == 1) FUN_001099d0(0x5c);
    }
    else if (gMtScene->fldMajorId == 4) FUN_001099d0(0x4d, 1);
    else if (gMtScene->fldMajorId == 0x27 && gMtScene->fldMinorId == 1) FUN_001099d0(0x65);
    }
}

// FUN_001aa1b0
void func_001aa1b0(void)
{
    if (((gMtScene->fldMajorId == 6 && gMtScene->fldMinorId == 1) ||
         (gMtScene->fldMajorId == 6 && gMtScene->fldMinorId == 3) ||
         (gMtScene->fldMajorId == 6 && gMtScene->fldMinorId == 4) ||
         (gMtScene->fldMajorId == 6 && gMtScene->fldMinorId == 7) ||
         (gMtScene->fldMajorId == 6 && gMtScene->fldMinorId == 0xb) ||
         (gMtScene->fldMajorId == 6 && gMtScene->fldMinorId == 0x14)) &&
        (FUN_0016ef30() == 1 || FUN_0016ef30() == 3 || FUN_0016ef30() == 5))
    {
        func_0010a410(4, (const char*)D_0067F080);
        return;
    }

    if (((gMtScene->fldMajorId == 6 && gMtScene->fldMinorId == 2) ||
         (gMtScene->fldMajorId == 6 && gMtScene->fldMinorId == 5) ||
         (gMtScene->fldMajorId == 6 && gMtScene->fldMinorId == 0x10)) &&
        (FUN_0016ef30() == 5 || FUN_0016ef30() == 3) &&
        FUN_0017e480(7, 0x12, 9, 0x14) == 1)
    {
        func_0010a410(4, (const char*)D_0067F100);
        return;
    }

    if (gMtScene->fldMajorId == 7 && gMtScene->fldMinorId == 1 &&
        (FUN_0016ef30() == 4 || FUN_0016ef30() == 5 || FUN_0016ef30() == 6 || FUN_0016ef30() == 7) &&
        FUN_0017e480(9, 0x12, 9, 0x12) == 1)
    {
        func_0010a410(4, (const char*)D_0067F200);
        return;
    }

    if (gMtScene->fldMajorId == 7 && gMtScene->fldMinorId == 1 &&
        FUN_0016ef30() == 4 &&
        FUN_0017e480(7, 0x12, 9, 0x14) == 1)
    {
        func_0010a410(4, (const char*)D_0067F100);
        return;
    }

    if (gMtScene->fldMajorId == 7 && gMtScene->fldMinorId == 1 && FUN_0016ef30() == 7)
    {
        func_0010a410(4, (const char*)D_0067F240);
        return;
    }

    if (gMtScene->fldMajorId == 7 && gMtScene->fldMinorId == 1 && FUN_0016ef30() == 1)
    {
        func_0010a410(4, (const char*)D_0067F180);
        return;
    }

    if (((gMtScene->fldMajorId == 7 && gMtScene->fldMinorId == 9) ||
         (gMtScene->fldMajorId == 9 && gMtScene->fldMinorId == 1) ||
         (gMtScene->fldMajorId == 9 && gMtScene->fldMinorId == 2) ||
         (gMtScene->fldMajorId == 9 && gMtScene->fldMinorId == 7) ||
         (gMtScene->fldMajorId == 0xc && gMtScene->fldMinorId == 1)) &&
        (FUN_0016ef30() == 5 || FUN_0016ef30() == 4) &&
        FUN_0017e480(7, 0x12, 9, 0x14) == 1)
    {
        func_0010a410(4, (const char*)D_0067F100);
        return;
    }

    if (((gMtScene->fldMajorId == 6 && gMtScene->fldMinorId == 2) ||
         (gMtScene->fldMajorId == 6 && gMtScene->fldMinorId == 0x10) ||
         (gMtScene->fldMajorId == 7 && gMtScene->fldMinorId == 9) ||
         (gMtScene->fldMajorId == 0xc && gMtScene->fldMinorId == 1)) &&
        (FUN_0016ef30() == 5 || FUN_0016ef30() == 4 || FUN_0016ef30() == 6 || FUN_0016ef30() == 7) &&
        FUN_0017e480(0xa, 0x10, 0xb, 0x19) == 1)
    {
        func_0010a410(4, (const char*)D_0067F140);
        return;
    }

    if (gMtScene->fldMajorId == 6 && FUN_0016f190(0xe60) == 1)
    {
        func_0010a410(4, (const char*)D_0067F240);
        return;
    }

    if (gMtScene->fldMajorId == 0x0e && gMtScene->fldMinorId == 1)
    {
        func_0010a410(4, (const char*)D_0067F340);
        return;
    }

    if (gMtScene->fldMajorId == 0x0e && gMtScene->fldMinorId == 5)
    {
        func_0010a410(4, (const char*)D_0067F300);
        return;
    }

    if (gMtScene->fldMajorId == 0x21 && gMtScene->fldMinorId == 1)
    {
        func_0010a410(4, (const char*)D_0067F2C0);
        return;
    }

    if (gMtScene->fldMajorId == 0x21)
    {
        func_0010a410(4, (const char*)D_0067F380);
        return;
    }

    func_00109f60(4, 0);
}

// FUN_001aa8f0
void* func_001aa8f0(KwlnTask* task)
{
    u32* work = (u32*)task->workData;
    if (work[1] == 1)
    {
        if (work[2] > 0x96)
        {
            func_0010a4e0(0, 5, 1, 0x22);
            work[2] = 0;
        }
    }
    else if (func_001c7130(2600, work[0]) == 1)
    {
        if (work[2] > 0x96)
        {
            func_0010a4e0(0, 5, 1, 0x21);
            work[2] = 0;
        }
    }
    else if (work[2] > 0xb4)
    {
        func_0010a4e0(0, 5, 1, 0x20);
        work[2] = 0;
    }
    work[2]++;
    return NULL;
}

// FUN_001aa9f0
void func_001aa9f0(KwlnTask* task)
{
    (*(void (**)(void*))((u8*)0x00960000 + 0x17c))(task->workData);
}
/*
 * Field movement-path work data.
 *
 * The retail task allocates 0x5a0 bytes. Keeping the point records explicit
 * is useful here: the public queue helpers below are also used by event code,
 * and the controller stores a complete 0x18-byte record for every point.
 */











/* Removing this worsens FUN_001ae480 (nd16 -> nd101) - measured W161. */
// FUN_001aaa20
KwlnTask* func_001aaa20(KwlnTask* parent, u32 value)
{
    u32* work;
    KwlnTask* task;

    work = (u32*)(*(void* (**)(u32, u32, u32))D_00960184)(1, 0x0c, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreateWithAutoPriority(parent, 10, D_00678CB8,
                                          (KwlnTaskUpdateFunc)func_001aa8f0,
                                          (KwlnTaskDestroyFunc)func_001aa9f0, work);
    work[0] = value;
    return task;
}


// FUN_001aaac0
void func_001aaac0(KwlnTask* task, u32 value)
{
    *(u32*)((u8*)task->workData + 4) = value;
}

/* W419: case-local i0/i1/i2 declarations reduce K_FldFrame_IsPointInTriangle nd85 -> 1 at object 832/832; one axis-selection branch target remains for follow-up. */
/* W419 failed shape probes from nd1: axis-shape nd6/832, inner-invert nd10/832, condexpr nd9/832; single-case-switch variants nd643/856 and nd627/872 (over 832-byte window); explicit join-goto stayed nd1/832. */
/* W419 failed exact tail-out probe: moving the axis-1/axis-0 tail outside the absZ/absY guard gave nd608/object772/window832, so it was reverted. */
/* W419 failed mirrored outer-condition probe (absZ <= absY with original body): nd2/object832/window832, semantically reverses the axis choice, so it was reverted. */
/* W421 probes: fldFrameIndexedAddress(index, base) reduced func_001a8db0
 * nd2/object552/window560 (0.003623) to nd0/object552/window560 (0.000000),
 * and the MATCH was banked. Axis nested-tail stayed nd1/832/832 (0.001202);
 * inner conditional nd9/832/832 (0.010817); full conditional nd600/828/832
 * (0.712919); unguarded tail
 * nd608/772/832 (0.787565). */
/* W421 collision address probes: fldFrameAddOffset(offset, base) in one
 * loop gave nd9/object524/window528 (0.017176), both loops nd8/524/528
 * (0.015267), while base-first helper order returned nd10/524/528
 * (0.019084). Remaining register-role rows are offsets 236, 280, 348, 392:
 * candidate index uses $a2 where retail uses $a3 (offset 236 sll, 280 addu,
 * 348 sll, 392 addu). W422 offsetPc/offsetEc split, shared-offset merge,
 * and signed offset split each gave 9 differing fndiff words at
 * object524/window528; the a2/a3 role cycle remains. */
// FUN_001aaad0 NONMATCHING
u32 K_FldFrame_IsPointInTriangle(const RwV3d* point, const RwV3d** tri, const RwV3d* normal)
{
    s32 i0;
    s32 i1;
    s32 i2;
    s32 axis;
    s32 previous;
    u32 inside;
    f32 primary0;
    f32 primary1;
    f32 primary2;
    f32 absX;
    f32 absY;
    f32 absZ;

    inside = false;
    absX = fabsf(normal->x);
    absY = fabsf(normal->y);
    absZ = fabsf(normal->z);
    if (!(absZ <= absY))
    {
        if (!(absZ <= absX))
        {
            axis = 2;
        }
        else
        {
            axis = 0;
        }
    }
    else if (!(absY <= absX))
    {
        axis = 1;
    }
    else
    {
        axis = 0;
    }

    if (axis != 0x7fffffff)
    {
        previous = 2;
        switch (axis)
        {
        case 0:
            i0 = 0;
            primary0 = point->y;
            for (; i0 < 3; i0++)
            {
                if (((tri[i0]->y <= primary0) && (primary0 < tri[previous]->y)) ||
                    ((tri[previous]->y <= primary0) && (primary0 < tri[i0]->y)))
                {
                    if (point->z < tri[i0]->z +
                        ((primary0 - tri[i0]->y) * (tri[previous]->z - tri[i0]->z)) /
                        (tri[previous]->y - tri[i0]->y))
                    {
                        inside = !inside;
                    }
                }
                previous = i0;
            }
            break;
        case 1:
            i1 = 0;
            primary1 = point->z;
            for (; i1 < 3; i1++)
            {
                if (((tri[i1]->z <= primary1) && (primary1 < tri[previous]->z)) ||
                    ((tri[previous]->z <= primary1) && (primary1 < tri[i1]->z)))
                {
                    if (point->x < tri[i1]->x +
                        ((primary1 - tri[i1]->z) * (tri[previous]->x - tri[i1]->x)) /
                        (tri[previous]->z - tri[i1]->z))
                    {
                        inside = !inside;
                    }
                }
                previous = i1;
            }
            break;
        case 2:
            i2 = 0;
            primary2 = point->y;
            for (; i2 < 3; i2++)
            {
                if (((tri[i2]->y <= primary2) && (primary2 < tri[previous]->y)) ||
                    ((tri[previous]->y <= primary2) && (primary2 < tri[i2]->y)))
                {
                    if (point->x < tri[i2]->x +
                        ((primary2 - tri[i2]->y) * (tri[previous]->x - tri[i2]->x)) /
                        (tri[previous]->y - tri[i2]->y))
                    {
                        inside = !inside;
                    }
                }
                previous = i2;
            }
            break;
        default:
            break;
        }
    }

    return inside;
}

// FUN_001aae10
RwV3d* func_001aae10(RwV3d* dst, const RwV3d* point,
                     const RwV3d* start, const RwV3d* end)
{
    RwV3d edge;
    f32 projection;
    f32 edgeLengthSquared;
    f32 fraction;

    edge.x = end->x - start->x;
    edge.y = end->y - start->y;
    edge.z = end->z - start->z;
    projection = point->x * edge.x + point->y * edge.y + point->z * edge.z -
                 (start->x * edge.x + start->y * edge.y + start->z * edge.z);

    if (projection <= 0.0f)
    {
        *dst = *start;
    }
    else
    {
        edgeLengthSquared = edge.x * edge.x + edge.y * edge.y + edge.z * edge.z;
        if (projection < edgeLengthSquared)
        {
            fraction = projection / edgeLengthSquared;
            dst->x = edge.x * fraction;
            dst->y = edge.y * fraction;
            dst->z = edge.z * fraction;
            dst->x += start->x;
            dst->y += start->y;
            dst->z += start->z;
        }
        else
        {
            *dst = *end;
        }
    }

    return dst;
}

// Retail fully inlines fldFrameMoveWork/fldFrameMoveResolvePosition, and
// (pathMode==0 branch) fldFrameMoveAppend/fldFrameMoveCreateDebugPoint -
// none are called via jal. K_FldFrame_Raycast is duplicated per branch,
// not shared. Dispatch uses work->pathMode (0x18), not work->mode (0x8,
// a different field - see func_001b0260/func_001b0240). Residual: a
// register-bank floor (764B vs 800B window); logic verified vs retail.
// FUN_001aaf30 NONMATCHING
void* func_001aaf30(const RwV3d* point, void* unused,
                    const FldFrameCollisionTriangle* triangle,
                    FldFrameCollisionCollector* collector)
{
    RwV3d projected;
    RwV3d closest;
    RwV3d delta;
    f32 signedDistance;
    f32 distance;
    f32 edgeDistance;
    s32 i;
    s32 index;

    (void)unused;

    signedDistance =
        triangle->vertices[0]->x * triangle->normal.x +
        triangle->vertices[0]->y * triangle->normal.y +
        triangle->vertices[0]->z * triangle->normal.z -
        (point->x * triangle->normal.x +
         point->y * triangle->normal.y +
         point->z * triangle->normal.z);
    projected.x = point->x + triangle->normal.x * signedDistance;
    projected.y = point->y + triangle->normal.y * signedDistance;
    projected.z = point->z + triangle->normal.z * signedDistance;

    if (K_FldFrame_IsPointInTriangle(&projected,
                                      (const RwV3d**)triangle->vertices,
                                      &triangle->normal))
    {
        distance = fabsf(signedDistance);
        index = 0;
        while (index < (s32)collector->count &&
               (collector->normals[index].x != triangle->normal.x ||
                collector->normals[index].y != triangle->normal.y ||
                collector->normals[index].z != triangle->normal.z))
        {
            index++;
        }
        if (index < (s32)collector->count)
        {
            if (distance < collector->distances[index])
            {
                collector->points[index] = projected;
                collector->normals[index] = triangle->normal;
                collector->distances[index] = distance;
            }
        }
        else
        {
            index = collector->count;
            if (distance < collector->distances[index])
            {
                collector->points[index] = projected;
                collector->normals[index] = triangle->normal;
                collector->distances[index] = distance;
                collector->count++;
            }
        }
    }
    else
    {
        distance = 1.0e30f;
        for (i = 0; i < 3; i++)
        {
            func_001aae10(&closest, &projected, triangle->vertices[i],
                          triangle->vertices[(i + 1) % 3]);
            delta.x = point->x - closest.x;
            delta.y = point->y - closest.y;
            delta.z = point->z - closest.z;
            edgeDistance = func_004c6ac0(&delta);
            if (edgeDistance < distance)
            {
                distance = edgeDistance;
                projected = closest;
            }
        }
        if (distance < 1.0e30f)
        {
            index = 0;
            while (index < (s32)collector->count &&
                   (collector->normals[index].x != triangle->normal.x ||
                    collector->normals[index].y != triangle->normal.y ||
                    collector->normals[index].z != triangle->normal.z))
            {
                index++;
            }
            if (index < (s32)collector->count)
            {
                if (distance < collector->distances[index])
                {
                    collector->points[index] = projected;
                    collector->normals[index] = triangle->normal;
                    collector->distances[index] = distance;
                }
            }
            else
            {
                index = collector->count;
                if (distance < collector->distances[index])
                {
                    collector->points[index] = projected;
                    collector->normals[index] = triangle->normal;
                    collector->distances[index] = distance;
                    collector->count++;
                }
            }
        }
    }

    return (void*)triangle;
}

// Same inlining pattern as func_001afa20 above (fldFrameMoveWork,
// fldFrameMoveResolvePosition, fldFrameMoveAppend/CreateDebugPoint all
// inlined; retail does not jal any of them) - simpler single-path variant
// with a fixed kind=3, no pathMode dispatch.
// FUN_001ab390 NONMATCHING
s32 func_001ab390(void* collision, const RwV3d* pos,
                  RwV3d* translation, f32 sphereCollisRadius)
{
    FldFrameCollisionQuery query;
    FldFrameCollisionCollector collector;
    RwV3d diff;
    f32 correction;
    f32 adjustX;
    f32 adjustY;
    f32 adjustZ;
    f32 dot;
    s32 i;
    s32 result;

    result = 0;
    query.center.x = pos->x + translation->x;
    query.center.y = pos->y + translation->y;
    query.center.z = pos->z + translation->z;
    query.radius = sphereCollisRadius;
    query.type = 3;
    /*
     * The engine consumes the copied 16-byte center/radius block at +0x20.
     * Retail uses the EE's quadword load/store pair for this aggregate copy.
     */
    __asm__ volatile (
        "lq $v0, 0xbb0($sp)\n"
        "sq $v0, 0xbc0($sp)\n"
        :
        :
        : "$v0", "memory");
    for (i = 0; i < 64; i++)
    {
        memset_k_fldFrame_typed(&collector.points[i], 0, sizeof(RwV3d));
        memset_k_fldFrame_typed(&collector.normals[i], 0, sizeof(RwV3d));
        collector.distances[i] = 1.0e30f;
    }
    collector.count = 0;
    if (collision == NULL)
    {
        return 0;
    }

    func_00464020(collision, (u8*)&query + 0x20, func_001aaf30, &collector);
    for (i = 0; i < (s32)collector.count; i++)
    {
        if (collector.distances[i] < 1.0e30f)
        {
            diff.x = query.center.x - collector.points[i].x;
            diff.y = query.center.y - collector.points[i].y;
            diff.z = query.center.z - collector.points[i].z;
            func_004c69f0(&diff, &diff);
            correction = query.radius - collector.distances[i];
            adjustX = diff.x * correction;
            adjustY = diff.y * correction;
            adjustZ = diff.z * correction;
            dot = translation->y * diff.y +
                  translation->x * diff.x +
                  translation->z * diff.z;
            if (dot < 0.0f)
            {
                translation->x -= diff.x * dot;
                translation->y -= diff.y * dot;
                translation->z -= diff.z * dot;
            }
            result = 1;
            if (translation->x == 0.0f &&
                translation->y == 0.0f &&
                translation->z == 0.0f)
            {
                translation->x += adjustX;
                translation->y += adjustY;
                translation->z += adjustZ;
                result = 1;
            }
        }
    }
    return result;
}

// The existing model/matrix-derived position guess did not match retail
// at all - retail's bytes have NO fldFrameMoveModel/mdlGetMatrix calls
// and never write points[pointCount].position for this kind=1 point (it
// is a duration/kind-only marker point, position is left whatever it was).
// FUN_001ab640 NONMATCHING
void* func_001ab640(const RwV3d* point, const void* triangle,
                    FldFrameCollisionCollector* collector)
{
    const FldFrameCollisionTriangle* candidate;
    RwV3d projected;
    RwV3d normal;
    RwV3d vertices[3];
    RwV3d closest;
    RwV3d delta;
    const RwV3d* vertexPointers[3];
    RwMatrix* matrix;
    f32 distance;
    f32 planeDistance;
    s32 index;
    s32 i;

    candidate = (const FldFrameCollisionTriangle*)triangle;
    normal = candidate->normal;
    matrix = func_004cb2f0(*(void**)((u8*)collector->owner + 4));
    func_004c6ca0(&normal, &candidate->normal, 1, matrix);
    func_004c69f0(&normal, &normal);

    for (i = 0; i < 3; i++)
    {
        func_004c6c20(&vertices[i], candidate->vertices[i], 1, matrix);
        vertexPointers[i] = &vertices[i];
    }

    if (normal.x * *(f32*)((u8*)collector + 0xb0c) +
        normal.y * *(f32*)((u8*)collector + 0xb10) +
        normal.z * *(f32*)((u8*)collector + 0xb14) >= 0.0f &&
        collector->mode == 0)
    {
        return (void*)triangle;
    }

    if (fabsf(normal.y) <= fGpffff8078)
    {
        return (void*)triangle;
    }

    planeDistance =
        (vertices[0].x * normal.x + vertices[0].y * normal.y +
         vertices[0].z * normal.z) -
        (point->x * normal.x + point->y * normal.y + point->z * normal.z);
    projected.x = point->x + normal.x * planeDistance;
    projected.y = point->y + normal.y * planeDistance;
    projected.z = point->z + normal.z * planeDistance;

    if (K_FldFrame_IsPointInTriangle(&projected, vertexPointers, &normal))
    {
        distance = fabsf(planeDistance);
        index = 0;
        while (index < (s32)collector->count &&
               (collector->normals[index].x != normal.x ||
                collector->normals[index].y != normal.y ||
                collector->normals[index].z != normal.z))
        {
            index++;
        }
        if (index < (s32)collector->count)
        {
            if (distance < collector->distances[index])
            {
                collector->points[index] = projected;
                collector->normals[index] = normal;
                collector->distances[index] = distance;
                if (collector->mode == 1 &&
                    *(u32*)((u8*)collector + 0xa00 + index * 4) == 0)
                {
                    collector->blockingCount++;
                    *(u32*)((u8*)collector + 0xa00 + index * 4) = 1;
                }
            }
        }
        else
        {
            index = collector->count;
            if (distance < collector->distances[index])
            {
                collector->points[index] = projected;
                collector->normals[index] = normal;
                collector->distances[index] = distance;
                if (collector->mode == 1 &&
                    *(u32*)((u8*)collector + 0xa00 + index * 4) == 0)
                {
                    collector->blockingCount++;
                    *(u32*)((u8*)collector + 0xa00 + index * 4) = 1;
                }
                collector->count++;
            }
        }
        return (void*)triangle;
    }

    for (i = 0; i < 3; i++)
    {
        func_001aae10(&closest, &projected, vertexPointers[i],
                      vertexPointers[(i + 1) % 3]);
        delta.x = point->x - closest.x;
        delta.y = point->y - closest.y;
        delta.z = point->z - closest.z;
        distance = func_004c6ac0(&delta);

        index = 0;
        while (index < (s32)collector->count &&
               (collector->normals[index].x != normal.x ||
                collector->normals[index].y != normal.y ||
                collector->normals[index].z != normal.z))
        {
            index++;
        }
        if (index < (s32)collector->count)
        {
            if (distance < collector->distances[index])
            {
                collector->points[index] = closest;
                collector->normals[index] = normal;
                collector->distances[index] = distance;
                if (collector->mode == 1 &&
                    *(u32*)((u8*)collector + 0xa00 + index * 4) == 0)
                {
                    collector->blockingCount++;
                    *(u32*)((u8*)collector + 0xa00 + index * 4) = 1;
                }
            }
        }
        else
        {
            index = collector->count;
            if (distance < collector->distances[index])
            {
                collector->points[index] = closest;
                collector->normals[index] = normal;
                collector->distances[index] = distance;
                if (collector->mode == 1 &&
                    *(u32*)((u8*)collector + 0xa00 + index * 4) == 0)
                {
                    collector->blockingCount++;
                    *(u32*)((u8*)collector + 0xa00 + index * 4) = 1;
                }
                collector->count++;
            }
        }
    }
    return (void*)triangle;
}

// FUN_001abcd0
void* func_001abcd0(void* collisionWorld, void* state)
{
    *(void**)((u8*)state + 0xb34) = collisionWorld;
    func_00464120(collisionWorld, (u8*)state + 0xb18,
                  func_001ab640, state);
    return collisionWorld;
}

// FUN_001abd20 NONMATCHING
s32 func_001abd20(void* collisionWorld, const RwV3d* pos,
                   RwV3d* translation, f32 sphereCollisRadius, u16 resTypeId)
{
    FldFrameCollisionCollector collector;
    void* type10ListHead;
    RwV3d query;
    void* type3ListHead;
    void* type1ListHead;
    s32 i;
    void* listNode;
    void* listThree;
    void* model;
    RwV3d diff;
    RwV3d rayOrigin;
    RwV3d hitPoint;
    f32 posY;
    f32 posZ;
    u16 resTypeMask;
    s32 returnVal;

    returnVal = 0;

    type10ListHead = (void*)func_003b5d50(10);
    type3ListHead = (void*)func_003b5d50(3);
    type1ListHead = (void*)func_003b5d50(1);

    query.x = pos->x + translation->x;
    query.y = pos->y + translation->y;
    query.z = pos->z + translation->z;
    collector.count = 0;
    collector.blockingCount = 0;
    collector.owner = NULL;
    for (i = 0; i < 64; i++)
    {
        memset_k_fldFrame_typed(&collector.points[i], 0, sizeof(RwV3d));
        memset_k_fldFrame_typed(&collector.normals[i], 0, sizeof(RwV3d));
        collector.distances[i] = 1.0e30f;
        *(u32*)((u8*)&collector + 0xa00 + i * 4) = 0;
    }
    collector.owner = collisionWorld;

    for (i = 0; i < 7; i++)
    {
        *(u32*)((u8*)&collector + 0xb18 + i * 4) =
            *(u32*)((u8*)&collector + 0xb60 + i * 4);
    }

    func_004c69f0((RwV3d*)((u8*)&collector + 0xb0c), translation);
    memset_k_fldFrame_typed((u8*)&collector + 0xb38, 0, 0xc);

    if (collisionWorld == NULL)
        return 0;
    collector.mode = 1;
    FUN_004916d0(collisionWorld, func_001abcd0, &collector);
    collector.mode = 0;

    resTypeMask = (u16)resTypeId;

    listNode = *(void**)((u8*)type10ListHead + 0xf8);
    while (listNode != NULL)
    {
        if ((*(u32*)((u8*)listNode + 0x28) & 2) &&
            (*(u32*)((u8*)listNode + 0x110) == 1))
        {
            model = (void*)func_00318b80(*(u32*)((u8*)listNode + 0x104));
            if (model != NULL)
            {
                FUN_004916d0(model, func_001abcd0, &collector);
                rayOrigin = *pos;
                rayOrigin.y += 400.0f;
                hitPoint.x = 0.0f;
                hitPoint.y = 0.0f;
                hitPoint.z = 0.0f;
                if (func_001acb70(model, &rayOrigin, &hitPoint) == 1)
                    translation->y = hitPoint.y - (pos->y - sphereCollisRadius);
            }
        }
        listNode = *(void**)((u8*)listNode + 0xf8);
    }

    listThree = *(void**)((u8*)type3ListHead + 0xf8);
    while (listThree != NULL)
    {
        if ((*(u32*)((u8*)listThree + 0x28) & 2) &&
            (*(u32*)((u8*)listThree + 0x110) == 1))
        {
            model = (void*)func_00318b80(*(u32*)((u8*)listThree + 0x104));
            if (model != NULL)
            {
                translation->y = -(pos->y - sphereCollisRadius);
            }
        }
        listThree = *(void**)((u8*)listThree + 0xf8);
    }
    if (K_Scene_001a0250() && K_Scene_001a0250())
    {
        s32 quadIter;
        for (quadIter = 0; quadIter < 4; quadIter++)
        {
            void* gridEntry;
            void* objData;
            s32 entryOff = quadIter * 448;
            gridEntry = D_008717A0 + entryOff;

            if (*(u32*)((u8*)gridEntry + 0x48) == 0) continue;
            if (*(u32*)((u8*)gridEntry + 0x54) == 0) continue;
            if (*(u16*)(*(void**)((u8*)gridEntry + 0x54)) == resTypeMask) continue;

            objData = *(void**)((u8*)gridEntry + 0x54);
            model = (void*)func_00318b80(*(u32*)((u8*)objData + 0x1e8));
            if (model != NULL)
            {
                FUN_004916d0(model, func_001abcd0, &collector);
            }
            else if (resTypeMask == 0x400)
            {
                void* rootObj;
                RwV3d* vecA;
                RwV3d* vecB;
                f32 dist;
                s32 moveCount;

                rootObj = (void*)func_00318b60(*(u32*)(DAT_008717f0 + 0));
                vecA = (RwV3d*)((u8*)rootObj + 0x30);
                vecB = (RwV3d*)((u8*)func_00318b60(*(u32*)((u8*)gridEntry + 0x50)) + 0x30);

                diff.x = vecB->x - vecA->x;
                diff.y = vecB->y - vecA->y;
                diff.z = vecB->z - vecA->z;

                dist = func_004c69f0(&diff, &diff);
                if (dist >= 97.0f) continue;
                moveCount = func_001b0220(*(void**)((u8*)gridEntry + 0x170));
                if (moveCount != 0) continue;

                if (func_002ff790_k_fldFrame_void(*(void**)((u8*)gridEntry + 0x48)) != NULL)
                    continue;
                if (*(u32*)((u8*)gridEntry + 0x48) == 0) continue;

                {
                    u8 typeCode;
                    void* typeInfo = func_004353f0(gridEntry);
                    typeCode = (u8)(((u32)typeInfo >> 24) >> 8);
                    if (typeCode == 5) continue;
                }

                {
                    RwV3d scaled;
                    scaled.x = diff.x * 50.0f;
                    scaled.y = diff.y * 50.0f;
                    scaled.z = diff.z * 50.0f;
                    scaled.x += vecA->x;
                    scaled.y += vecA->y;
                    scaled.z += vecA->z;
                    func_001afd40(*(KwlnTask**)(*(u32*)((u8*)gridEntry + 0x170)),
                                  &scaled, 50.0f);
                }
            }
        }
    }
    if ((resTypeMask & 0x3ff) < 100)
    {
        u8* cell;
        s32 cellX;
        s32 cellZ;

        cellX = (s32)((pos->x + 400.0f) / 800.0f);
        cellZ = (s32)((pos->z + 400.0f) / 800.0f);
        cell = D_0086B180 + cellZ * 0x310 + cellX * 0xc4;
        for (i = 0; i < 100; i++)
        {
            void* entry;
            entry = *(void**)(cell + i * 4);
            if (entry != NULL && *(u32*)((u8*)entry + 0x48) != 0 &&
                *(void**)((u8*)entry + 0x54) != NULL)
            {
                void* data = *(void**)((u8*)entry + 0x54);
                if (*(u32*)((u8*)data + 0x28) & 2)
                {
                    model = (void*)func_00318b80(
                        *(u32*)((u8*)data + 0x1e8));
                    if (model != NULL)
                        FUN_004916d0(model, func_001abcd0, &collector);
                }
            }
        }
        for (i = 0; i < 100; i++)
        {
            void* entry;
            entry = *(void**)(cell + 0x60 + i * 4);
            if (entry != NULL && *(u32*)entry != 0)
            {
                model = (void*)func_00318b80(
                    *(u32*)((u8*)entry + 0x134));
                if (model != NULL)
                    FUN_004916d0(model, func_001abcd0, &collector);
            }
        }
    }
    {
        u8* cell;
        void* extraData;
        cell = D_0086B180 +
               (s32)((pos->z + 400.0f) / 800.0f) * 0x310 +
               (s32)((pos->x + 400.0f) / 800.0f) * 0xc4;
        extraData = *(void**)(cell + 0x310);
        if (extraData != NULL)
        {
            model = (void*)func_00318b80(*(u32*)((u8*)extraData + 0x114));
            if (model != NULL)
                FUN_004916d0(model, func_001abcd0, &collector);
        }
    }
    listNode = *(void**)((u8*)type1ListHead + 0xf8);
    while (listNode != NULL)
    {
        if ((*(u32*)((u8*)listNode + 0x28) & 2))
        {
            s32 field114 = *(s32*)((u8*)listNode + 0x114);
            if (field114 != 0)
            {
                model = (void*)func_00318b80(field114);
                if (model != NULL)
                    FUN_004916d0(model, func_001abcd0, &collector);
            }
        }
        listNode = *(void**)((u8*)listNode + 0xf8);
    }

    posY = pos->y;
    posZ = pos->z;
    for (i = 0; i < (s32)collector.count; i++)
    {
        RwV3d normal;
        f32 distance;
        f32 correction;
        f32 direction;
        u32 blocking;

        distance = collector.distances[i];
        if (distance >= 1.0e30f)
            continue;

        diff.x = collector.points[i].x - pos->x;
        diff.y = collector.points[i].y - posY;
        diff.z = collector.points[i].z - posZ;
        func_004c69f0(&diff, &diff);

        correction = sphereCollisRadius - collector.distances[i];
        if (correction <= 0.0f)
            continue;

        blocking = *(u32*)((u8*)&collector + 0xa00 + i * 4);
        if (collector.mode == 1 && blocking == 1)
        {
            normal = collector.normals[i];
            direction = translation->x * normal.x +
                        translation->y * normal.y +
                        translation->z * normal.z;
            if (direction < 0.0f)
                continue;
        }

        translation->x += diff.x * correction;
        translation->y += diff.y * correction;
        translation->z += diff.z * correction;
        returnVal = 1;

        if (translation->x == 0.0f &&
            translation->y == 0.0f &&
            translation->z == 0.0f)
        {
            translation->x += diff.x * correction;
            translation->y += diff.y * correction;
            translation->z += diff.z * correction;
        }
    }

    {
        f32 trLen;
        trLen = func_004c69f0(&diff, translation);
        if (trLen > 9.0f)
        {
            translation->x = 8.5f * diff.x;
            translation->y = 8.5f * diff.y;
            translation->z = 8.5f * diff.z;
        }
    }

    return returnVal;
}

// FUN_001ac750
void K_FldFrame_HandleCollis(const RwV3d* pos, RwV3d* translation, f32 sphereCollisRadius,
                             u16 resTypeId)
{
    Resrc* res;
    void* collisionWorld;
    Resrc* fldRes;
    s32 xGrid;
    s32 zGrid;
    u32 gridResTypeId;
    u32 belowMin;

    if ((*(FldFrameCollisionState**)((u8*)K_Field_Get() + FLDFRAME_FIELD_STATE_OFFSET))->flags &
        FLDFRAME_COLLIS_FLAG_STATICWORLD)
    {
        func_001ab390(
            (*(FldFrameCollisionState**)((u8*)K_Field_Get() + FLDFRAME_FIELD_STATE_OFFSET))->staticCollision,
            pos, translation, sphereCollisRadius);
        return;
    }

    collisionWorld = NULL;
    if (K_Scene_001a0250() == true)
    {
        goto resource;
    }
    belowMin = gMtScene->fldMajorId < 0x33;
    if (belowMin)
    {
        goto fallback;
    }
    if (gMtScene->fldMajorId >= 0x4f)
    {
        goto fallback;
    }

resource:
    fldRes = MT_Scene_GetResListHead(RESRC_TYPE_FLD);
    res = MT_Scene_GetRes(resTypeId);
    if (RESRC_GET_TYPE(resTypeId) == RESRC_TYPE_MODELCHAR)
    {
        xGrid = K_FldFrame_CtlGetXGrid(((ResrcModelChar*)res)->collisCtlTask);
        zGrid = K_FldFrame_CtlGetZGrid(((ResrcModelChar*)res)->collisCtlTask);
    }
    else
    {
        xGrid = K_FldFrame_CtlGetXGrid(((ResrcModelNpc*)res)->collisCtlTask);
        zGrid = K_FldFrame_CtlGetZGrid(((ResrcModelNpc*)res)->collisCtlTask);
    }
    gridResTypeId = *(u16*)((u8*)K_Field_Get() + 0x4c + zGrid * 0x100 + xGrid * 0x10);

    while (fldRes != NULL)
    {
        if (fldRes->resTypeId == gridResTypeId)
        {
            collisionWorld = ((FldFrameResourceCollision*)((ResrcFld*)fldRes)->unk_160)->collisionWorld;
            break;
        }
        fldRes = fldRes->next;
    }
    goto done;

fallback:
    collisionWorld =
        (*(FldFrameCollisionState**)((u8*)K_Field_Get() + FLDFRAME_FIELD_STATE_OFFSET))->collisionWorld;

done:
    func_001abd20(collisionWorld, pos, translation, sphereCollisRadius, resTypeId);
}

/* W423 raycast FPU-role probes: unused f32 local, scalar segment locals,
 * and declaration-order relocation each stayed nd59/object240/window240
 * (0.245833), reverted. */
// FUN_001ac950 NONMATCHING
void* func_001ac950(const RwV3d* line, void* unused,
                    const void* triangle, FldFrameRaycast* raycast)
{
    typedef struct FldFrameLine
    {
        RwV3d point[2];
    } FldFrameLine;
    const FldFrameCollisionTriangle* candidate;
    FldFrameLine lineCopy;
    RwV3d segment;
    f32 normalY;
    f32 normalX;
    f32 normalZ;
    f32 denominator;
    f32 vertexDot;
    f32 lineDot;
    f32 fraction;

    lineCopy = *(const FldFrameLine*)line;
    candidate = (const FldFrameCollisionTriangle*)triangle;
    segment.x = lineCopy.point[0].x - lineCopy.point[1].x;
    segment.y = lineCopy.point[0].y - lineCopy.point[1].y;
    segment.z = lineCopy.point[0].z - lineCopy.point[1].z;
    normalY = candidate->normal.y;
    normalX = candidate->normal.x;
    normalZ = candidate->normal.z;
    denominator = normalY * segment.y;
    denominator += normalX * segment.x;
    denominator += normalZ * segment.z;
    vertexDot = normalZ * candidate->vertices[0]->z;
    vertexDot += normalX * candidate->vertices[0]->x;
    vertexDot += normalY * candidate->vertices[0]->y;
    lineDot = normalZ * lineCopy.point[0].z;
    lineDot += normalX * lineCopy.point[0].x;
    lineDot += normalY * lineCopy.point[0].y;
    fraction = -(-vertexDot + lineDot) / denominator;
    raycast->hitPointDst->x = lineCopy.point[0].x + segment.x * fraction;
    raycast->hitPointDst->y = lineCopy.point[0].y + segment.y * fraction;
    raycast->hitPointDst->z = lineCopy.point[0].z + segment.z * fraction;
    raycast->didHit = true;
    return NULL;
}

// FUN_001aca40
void* func_001aca40(f32 fraction, const RwV3d* line,
                    void* unused, FldFrameRaycast* raycast)
{
    typedef struct FldFrameLine
    {
        RwV3d point[2];
    } FldFrameLine;
    FldFrameLine lineCopy;
    RwV3d segment;

    lineCopy = *(const FldFrameLine*)line;
    if (raycast->nearestFraction > fraction)
    {
        segment.x = lineCopy.point[1].x - lineCopy.point[0].x;
        segment.y = lineCopy.point[1].y - lineCopy.point[0].y;
        segment.z = lineCopy.point[1].z - lineCopy.point[0].z;
        segment.x *= fraction;
        segment.y *= fraction;
        segment.z *= fraction;
        segment.x += lineCopy.point[0].x;
        segment.y += lineCopy.point[0].y;
        segment.z += lineCopy.point[0].z;
        *raycast->hitPointDst = segment;
        raycast->didHit = true;
        raycast->nearestFraction = fraction;
    }
    return unused;
}

// FUN_001acb20
void* func_001acb20(void* collisionWorld, FldFrameRaycast* raycast)
{
    raycast->hitObject = collisionWorld;
    func_00464120(collisionWorld, &raycast->line[0],
                  func_001aca40, raycast);
    return collisionWorld;
}

// FUN_001acb70
u32 func_001acb70(void* collisionWorld, const RwV3d* line,
                  RwV3d* hitPointDst)
{
    typedef struct FldFrameLine
    {
        RwV3d point[2];
    } FldFrameLine;
    typedef struct FldFrameIntersection
    {
        FldFrameLine line;
        u32 type;
    } FldFrameIntersection;
    FldFrameLine lineCopy __attribute__((aligned(16)));
    FldFrameIntersection intersection __attribute__((aligned(16)));
    FldFrameRaycast raycast;

    lineCopy = *(const FldFrameLine*)line;
    raycast.hitPointDst = hitPointDst;
    raycast.didHit = false;
    raycast.nearestFraction = fGpffff820c;
    intersection.type = 1;
    intersection.line = lineCopy;
    *(FldFrameIntersection*)&raycast.line[0] = intersection;

    if (collisionWorld == NULL)
    {
        return false;
    }
    FUN_004916d0(collisionWorld, func_001acb20, &raycast);
    return raycast.didHit;
}

// FUN_001acc30 NONMATCHING
u32 K_FldFrame_Raycast(const RwV3d* line, RwV3d* hitPointDst)
{
    FldFrameCollisionState* state;
    FldFrameRaycast raycast;
    FldFrameRaycast staticRaycast;
    Resrc* fldRes;
    void* collisionWorld;
    s32 xGrid;
    s32 zGrid;
    u16 gridResTypeId;

    state = *(FldFrameCollisionState**)((u8*)K_Field_Get() +
                                        FLDFRAME_FIELD_STATE_OFFSET);
    if (state->flags & FLDFRAME_COLLIS_FLAG_STATICWORLD)
    {
        state = *(FldFrameCollisionState**)((u8*)K_Field_Get() +
                                            FLDFRAME_FIELD_STATE_OFFSET);
        staticRaycast.hitPointDst = hitPointDst;
        staticRaycast.didHit = false;
        staticRaycast.line[0] = line[0];
        staticRaycast.line[1] = line[1];
        staticRaycast.intersectionType = 1;
        staticRaycast.nearestFraction = 1.0f;
        staticRaycast.hitObject = NULL;
        if (state->staticCollision != NULL)
        {
            func_00464020(state->staticCollision, &staticRaycast.line[0],
                          func_001ac950, &staticRaycast);
        }
        return staticRaycast.didHit;
    }

    collisionWorld = NULL;
    if ((K_Scene_001a0250() == true) ||
        ((gMtScene->fldMajorId > 0x32) && (gMtScene->fldMajorId < 0x4f)))
    {
        fldRes = MT_Scene_GetResListHead(RESRC_TYPE_FLD);
        xGrid = (line[0].x + 400.0f) / 800.0f;
        zGrid = (line[0].z + 400.0f) / 800.0f;
        gridResTypeId = K_Field_Get()->dungeonCells[zGrid][xGrid].resourceId;
        while (fldRes != NULL)
        {
            if (fldRes->resTypeId == gridResTypeId)
            {
                collisionWorld =
                    ((FldFrameResourceCollision*)((ResrcFld*)fldRes)->unk_160)
                        ->collisionWorld;
                break;
            }
            fldRes = fldRes->next;
        }
    }
    else
    {
        collisionWorld =
            (*(FldFrameCollisionState**)((u8*)K_Field_Get() +
                                         FLDFRAME_FIELD_STATE_OFFSET))
                ->collisionWorld;
    }

    if (collisionWorld != NULL)
    {
        raycast.hitPointDst = hitPointDst;
        raycast.didHit = false;
        raycast.line[0] = line[0];
        raycast.line[1] = line[1];
        raycast.intersectionType = 1;
        raycast.nearestFraction = 1.0f;
        raycast.hitObject = NULL;
        FUN_004916d0(collisionWorld, func_001acb20, &raycast);
        return raycast.didHit;
    }
    return false;
}

// FUN_001ace90
void* func_001ace90(void* resource, void* unused, FldFrameMaterialSet* set)
{
    FldFrameMaterialWork* work;
    FldFrameResourceTable* table;
    FldFrameMaterialIndex* indices;
    void** slot;
    void* item;
    s32 count;
    s32 j;
    s32 i;
    u32 key;
    u16 index;
    work = set->link->work;
    indices = (FldFrameMaterialIndex*)work->indices;
    work->flags |= 0x40;
    key = *(u32*)((u8*)unused + 0x18);
    index = indices[key].value;
    item = ((void**)work->items)[index];
    if (!K_Clump_MatUsrDataHasData_typed(item, sFldFrameMaterialName))
    {
        return unused;
    }

    count = work->itemCount;
    i = 0;
    while (i < count)
    {
        item = ((void**)work->items)[i];
        j = 0;
        while (j < 0x40)
        {
            table = set->table;
            slot = (void**)((u8*)table + j * 4 + 8);
            if (*slot == NULL)
            {
                *slot = item;
                table = set->table;
                table->count++;
                break;
            }
            if (*slot == item)
            {
                break;
            }
            j++;
        }
        i++;
    }
    return unused;
}

/*
 * The collision package passes triangle data as a small, engine-private
 * record.  Keeping the record definition here makes the callback code
 * readable without exposing that implementation detail in the public header.
 */















// FUN_001acfc0
void* func_001acfc0(void* resource, void* state)
{
    RwSphere* sphere;

    func_004912b0(resource);
    sphere = func_004912b0(resource);
    if (RwCameraFrustumTestSphere(*(RwCamera**)DAT_00960070_abs, sphere) != rwSPHEREOUTSIDE)
    {
        *(void**)((u8*)state + 0x30) = resource;
        func_00464120(resource, (u8*)state + 4, func_001ace90, state);
    }
    return resource;
}

// FUN_001ad050
void func_001ad050(void* collisionWorld, const RwV4d* position,
                   u32* direction, void* result)
{
    struct
    {
        void* output;
        u32 direction[6];
        u32 directionMode;
        RwV4d position;
        u32 reserved;
    } resources;
    struct
    {
        u32 x;
        u32 y;
    } *src, *dst;
    u32 x, y;
    s32 i;

    memset_k_fldFrame_typed(&resources, 0, sizeof(resources));
    resources.directionMode = 1;
    src = (void*)direction;
    dst = (void*)resources.direction;
    i = 3;
    do
    {
        x = src->x;
        y = src->y;
        src++;
        i--;
        dst->x = x;
        dst->y = y;
        dst++;
    } while (i > 0);
    resources.position = *position;
    resources.output = result;
    FUN_004916d0(collisionWorld, func_001acfc0, &resources);
}

// FUN_001ad120
void* func_001ad120(void* unused, void* collision, FldFrameAtomicQuery* query)
{
    void* geometry;
    void* entry;
    u8* triangles;
    u8* triangle;
    u32 offset;
    u32 materialIndex;
    void** materials;
    void* material;
    s32 i;

    geometry = *(void**)((u8*)query->atomic + 0x18);
    triangles = *(u8**)((u8*)geometry + 0x2c);
    entry = *(void**)((u8*)geometry + 8);
    entry = (void*)((uintptr_t)entry | 0x40);
    *(void**)((u8*)geometry + 8) = entry;
    offset = *(u32*)((u8*)collision + 0x18) * 8;
    offset += (u32)triangles;
    triangle = (u8*)offset;
    materialIndex = *(u16*)(triangle + 6);
    materials = *(void***)((u8*)geometry + 0x20);
    material = materials[materialIndex];
    if (!K_Clump_MatUsrDataHasData_typed(material, D_00678CE0_typed))
    {
        return collision;
    }

    for (i = 0; i < 64; i++)
    {
        void** slot;

        slot = (void**)query->output;
        slot += i;
        slot = (void**)((u8*)slot + 0x108);
        if (*slot == NULL)
        {
            *slot = query->atomic;
            (*(u32*)((u8*)query->output + 4))++;
            break;
        }
        if (*slot == query->atomic)
        {
            break;
        }
    }
    return collision;
}

// Reconstructed point/triangle callback using the retail collector layout.
// Remaining differences are MWCCPS2 stack-slot and register scheduling residuals.
// FUN_001ad220
void func_001ad220(void* object, const RwV3d* point, void* result)
{
    FldFrameAtomicQuery query;
    u32* src;
    u32* dst;
    u32 x;
    u32 y;
    s32 i;
    RwSphere* sphere;

    memset_k_fldFrame_typed(&query, 0, sizeof(query));
    *(u32*)(query.intersection + 0x18) = 1;
    src = (u32*)point;
    dst = (u32*)query.intersection;
    i = 3;
    do
    {
        x = src[0];
        y = src[1];
        src += 2;
        i--;
        dst[0] = x;
        dst[1] = y;
        dst += 2;
    } while (i > 0);
    query.output = result;
    sphere = func_004912b0(*(void**)object);
    if (RwCameraFrustumTestSphere(*(RwCamera**)DAT_00960070_abs, sphere) != rwSPHEREOUTSIDE)
    {
        query.atomic = *(void**)object;
        func_00464120(query.atomic, query.intersection,
                      func_001ad120, &query);
    }
}
// FUN_001ad2f0
void* K_FldFrame_UpdateCtlTask(KwlnTask* collisCtlTask)
{
    CollisCtl* ctl;
    ResrcModelChar* charList; // unused
    ResrcModelNpc* npcList;   // unused
    RwMatrix* mdlMatrix;
    RwV3d line[2];
    RwV3d hitPoint;
    RwV3d translation;
    RwV3d pos;
    s32 i;

    ctl = (CollisCtl*)collisCtlTask->workData;

    charList = (ResrcModelChar*)MT_Scene_GetResListHead(RESRC_TYPE_MODELCHAR);
    npcList = (ResrcModelNpc*)MT_Scene_GetResListHead(RESRC_TYPE_MODELNPC);

    if (ctl->flags & COLLISCTL_FLAG_NOUPDATE)
    {
        return KWLNTASK_CONTINUE;
    }

    switch (ctl->state)
    {
        case COLLISCTL_STATE_DIRTY:
            mdlMatrix = mdlGetMatrix(ctl->mdl);
            pos = mdlMatrix->pos;

            if (ctl->flags & COLLISCTL_FLAG_GROUNDSNAP && 
                !(ctl->flags & COLLISCTL_FLAG_NOCOLLIS))
            {
                line[0] = line[1] = pos;

                if (K_Scene_001a0250())
                {
                    line[0].y += 600.0f;
                }
                else
                {
                    line[0].y += 200.0f;
                }

                line[1].y -= 1000.0f;

                if (K_FldFrame_Raycast(line, &hitPoint) == true)
                {
                    ctl->velocity.y = -(pos.y - hitPoint.y);
                }
            }

            for (i = 0; i < COLLISCTL_SUBSTEPS; i++)
            {
                translation.x = ctl->velocity.x / COLLISCTL_SUBSTEPS;
                translation.y = ctl->velocity.y / COLLISCTL_SUBSTEPS;
                translation.z = ctl->velocity.z / COLLISCTL_SUBSTEPS;

                pos = mdlGetMatrix(ctl->mdl)->pos;
                pos.y += ctl->sphereCollisRadius;

                if (!(ctl->flags & COLLISCTL_FLAG_NOCOLLIS))
                {
                    K_FldFrame_HandleCollis(&pos, &translation, ctl->sphereCollisRadius, ctl->resTypeId);
                }

                mdlTranslate(ctl->mdl, &translation, rwCOMBINEPOSTCONCAT);
            }

            ctl->xGrid = (mdlMatrix->pos.x + 400.0f) / 800.0f;
            ctl->zGrid = (mdlMatrix->pos.z + 400.0f) / 800.0f;

            if (RESRC_GET_ID(ctl->resTypeId) < 100)
            {
                K_Footstep_Update(ctl->mdl, ctl->charId, ctl->resTypeId);
            }

            ctl->state++; // COLLISCTL_STATE_NOTDIRTY
            break;

        case COLLISCTL_STATE_NOTDIRTY:
            mdlMatrix = mdlGetMatrix(ctl->mdl);

            if (ctl->flags & COLLISCTL_FLAG_DEBUGDRAW)
            {
                K_FldFrame_CollisSphereSetDrawEnabled(collisCtlTask->child, true);
            }
            else
            {
                K_FldFrame_CollisSphereSetDrawEnabled(collisCtlTask->child, false);
            }
            break;
        
        case COLLISCTL_STATE_IDLE: break;
    }

    return KWLNTASK_CONTINUE;
}

#pragma alias func_002ff790_k_fldFrame_void func_002ff790

// Remaining: post-grid collision processing (type1 walk, final apply, dampening)
// FUN_001ad630
void K_FldFrame_DestroyCtlTask(KwlnTask* collisCtlTask)
{
    RwFree(collisCtlTask->workData);
}
/* W389 sweep: baseline nd 59, obj 240/240; all six knobs and 15 pairs stayed nd59/obj240, except opt_common_subs off (nd246, obj364/240). Retained no pragma; documented residual is scheduling of x/y vector loads versus multiplies. */
/* W423 CreateCtlTask pointer-role probe: merging computed units into
 * unitsBase with direct global bases worsened nd27/object524/window528
 * (0.051527), reverted. */
// FUN_001ad660 NONMATCHING
KwlnTask* K_FldFrame_CreateCtlTask(KwlnTask* parent, u32 resTypeId, s32 unused, f32 sphereCollisRadius)
{
    KwlnTask* task;
    CollisCtl* ctl;
    Resrc* res;
    s32 i;
    FldUnit* unitsBase;
    FldUnit* units;
    KFldFrameRwCallocFunc callocFunc;
    callocFunc = *(KFldFrameRwCallocFunc*)(rwGlobals_abs + 0x184);
    ctl = (*callocFunc)(1, sizeof(CollisCtl), rwMEMHINTDUR_GLOBAL);
    if (ctl == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreateWithAutoPriority(parent,
                                          10,
                                          "collision controler",
                                          K_FldFrame_UpdateCtlTask,
                                          K_FldFrame_DestroyCtlTask,
                                          ctl);

    ctl->state = COLLISCTL_STATE_NOTDIRTY;
    ctl->resTypeId = resTypeId;
    ctl->sphereCollisRadius = sphereCollisRadius;
    ctl->unk_24 = 0;

    if (RESRC_GET_TYPE(resTypeId) == RESRC_TYPE_MODELCHAR)
    {
        res = MT_Scene_GetRes(resTypeId);
        if (res != NULL)
        {
            ctl->mdl = ((ResrcModelChar*)res)->mdl;
        }
        i = 0;
        unitsBase = gFldUnitsPc;
        for (; i < FLDUNIT_PC_MAX; i++)
        {
            units = (FldUnit*)fldFrameAddOffset((u32)(i * sizeof(FldUnit)), (u32)unitsBase);
            if (units->genusBase != NULL &&
                units->mdl == ((ResrcModelChar*)res)->mdl)
            {
                u16 charId;

                charId = gFldUnitsPc[i].charId;
                ctl->charId = charId;
                ctl->fldUnit = units;
                break;
            }
        }

        i = 0;
        unitsBase = gFldUnitsEc;
        for (; i < FLDUNIT_EC_MAX; i++)
        {
            units = (FldUnit*)fldFrameAddOffset((u32)(i * sizeof(FldUnit)), (u32)unitsBase);
            if (units->genusBase != NULL &&
                units->mdl == ((ResrcModelChar*)res)->mdl)
            {
                u16 charId;

                charId = gFldUnitsEc[i].charId;
                ctl->charId = charId;
                ctl->fldUnit = units;
                break;
            }
        }
    }
    else if (RESRC_GET_TYPE(resTypeId) == RESRC_TYPE_MODELNPC)
    {
        res = MT_Scene_GetRes(resTypeId);
        if (res != NULL)
        {
            ctl->mdl = ((ResrcModelNpc*)res)->mdl;
        }
    }

    K_FldFrame_CreateCollisSphereTask(task);

    return task;
}

// FUN_001ad870
void K_FldFrame_CtlSetFlags(KwlnTask* collisCtlTask, u32 flags)
{
    ((CollisCtl*)collisCtlTask->workData)->flags |= flags;
}

// FUN_001ad890
void K_FldFrame_CtlClearFlags(KwlnTask* collisCtlTask, u32 flags)
{
    ((CollisCtl*)collisCtlTask->workData)->flags &= ~flags;
}

// FUN_001ad8b0
f32 K_FldFrame_CtlGetSphereCollisRadius(KwlnTask* collisCtlTask)
{
    return ((CollisCtl*)collisCtlTask->workData)->sphereCollisRadius;
}

// FUN_001ad8c0
void K_FldFrame_CtlSetSphereCollisRadius(KwlnTask* collisCtlTask, f32 radius)
{
    CollisCtl* ctl;

    ctl = (CollisCtl*)collisCtlTask->workData;
    ctl->sphereCollisRadius = radius;

    if (radius == 0.0f)
    {
        ctl->flags |= COLLISCTL_FLAG_NOCOLLIS;
        return;
    }

    ctl->flags &= ~COLLISCTL_FLAG_NOCOLLIS;
}

// FUN_001ad910
s32 K_FldFrame_CtlGetXGrid(KwlnTask* collisCtlTask)
{
    return ((CollisCtl*)collisCtlTask->workData)->xGrid;
}

// FUN_001ad920
s32 K_FldFrame_CtlGetZGrid(KwlnTask* collisCtlTask)
{
    return ((CollisCtl*)collisCtlTask->workData)->zGrid;
}

// FUN_001ad930
u32 K_FldFrame_CtlGetTotalDist(KwlnTask* collisCtlTask)
{
    return ((CollisCtl*)collisCtlTask->workData)->totalDist;
}

// FUN_001ad940
void K_FldFrame_CtlCopyPos(RwV3d* dst, KwlnTask* collisCtlTask)
{
    CollisCtl* ctl = (CollisCtl*)collisCtlTask->workData;
    RwV3d vec = {0};

    if (ctl->mdl != NULL)
    {
        vec = mdlGetMatrix(ctl->mdl)->pos;
    }

    *dst = vec;
}

// FUN_001ad9e0
void K_FldFrame_CtlUpdateMdlMat(KwlnTask* collisCtlTask, const RwMatrix* mat)
{
    CollisCtl* ctl = (CollisCtl*)collisCtlTask->workData;
    RwV3d originalPos;
    RwV3d zeroPos = {0};
    RwMatrixTolerance initialTolerance;
    RwMatrixTolerance rotatedTolerance;
    RwMatrixTolerance finalTolerance;

    if (ctl->mdl != NULL)
    {
        originalPos = mdlGetMatrix(ctl->mdl)->pos;
        mdlGetMatrix(ctl->mdl)->pos = zeroPos;
        RwEngineGetMatrixTolerances(&initialTolerance);
        RwMatrixOptimize(mdlGetMatrix(ctl->mdl), &initialTolerance);
        RwMatrixUpdate(mdlGetMatrix(ctl->mdl));

        mdlGetMatrix(ctl->mdl)->right = mat->right;
        mdlGetMatrix(ctl->mdl)->up = mat->up;
        mdlGetMatrix(ctl->mdl)->at = mat->at;
        RwEngineGetMatrixTolerances(&rotatedTolerance);
        RwMatrixOptimize(mdlGetMatrix(ctl->mdl), &rotatedTolerance);
        RwMatrixUpdate(mdlGetMatrix(ctl->mdl));

        if (ctl->fldUnit != NULL)
        {
            mdlScale(ctl->mdl, &D_00683780[ctl->fldUnit->scaleIdx], rwCOMBINEPOSTCONCAT);
        }

        mdlGetMatrix(ctl->mdl)->pos = originalPos;
        RwEngineGetMatrixTolerances(&finalTolerance);
        RwMatrixOptimize(mdlGetMatrix(ctl->mdl), &finalTolerance);
        RwMatrixUpdate(mdlGetMatrix(ctl->mdl));
    }
}

// FUN_001adc20
void func_001adc20(KwlnTask* collisCtlTask, const RwV3d* position)
{
    CollisCtl* ctl;
    RwMatrixTolerance tolerance;

    ctl = (CollisCtl*)collisCtlTask->workData;
    if (ctl->mdl == NULL)
    {
        return;
    }

    mdlGetMatrix(ctl->mdl)->pos = *position;
    RwEngineGetMatrixTolerances(&tolerance);
    RwMatrixOptimize(mdlGetMatrix(ctl->mdl), &tolerance);
    RwMatrixUpdate(mdlGetMatrix(ctl->mdl));
    ctl->xGrid = (mdlGetMatrix(ctl->mdl)->pos.x + 400.0f) / 800.0f;
    ctl->zGrid = (mdlGetMatrix(ctl->mdl)->pos.z + 400.0f) / 800.0f;
}
// FUN_001add40
void func_001add40(KwlnTask* collisCtlTask)
{
    CollisCtl* ctl;

    ctl = (CollisCtl*)collisCtlTask->workData;
    ctl->xGrid = (mdlGetMatrix(ctl->mdl)->pos.x + 400.0f) / 800.0f;
    ctl->zGrid = (mdlGetMatrix(ctl->mdl)->pos.z + 400.0f) / 800.0f;

}


// FUN_001addf0
void K_FldFrame_CtlMoveInDir(f32 dist, KwlnTask* collisCtlTask, const RwV3d* normalizedDir)
{
    CollisCtl* ctl;
    RwV3d velocity;

    ctl = (CollisCtl*)collisCtlTask->workData;
    velocity = *normalizedDir;

    if (ctl->state == COLLISCTL_STATE_NOTDIRTY)
    {
        velocity.x *= dist;
        velocity.y *= dist;
        velocity.z *= dist;
        
        ctl->totalDist += (u32)dist;
        ctl->velocity = velocity;

        ctl->state = COLLISCTL_STATE_DIRTY;
    }
}





/* The retail code uses these engine entry points through the split executable. */
#pragma alias D_00960090_abs D_00960090
#pragma alias D_007D2D60_abs D_007D2D60
#pragma alias D_00678C78_abs D_00678C78





























// MWCC floor: retail holds D_00678C00 in $v1 while b210 assigns the equivalent
// pointer lifetime to $a0; direct indexing regresses nd5 to nd34.





// The retail entry uses the opposite null-state branch layout; MWCC keeps the equivalent beqz form.
// The nine volatile list traversals and final state release are otherwise instruction-identical.








// FUN_001adec0
void K_FldFrame_CtlMoveForward(f32 dist, KwlnTask* collisCtlTask)
{
    CollisCtl* ctl = (CollisCtl*)collisCtlTask->workData;
    RwV3d velocity = {0};

    if (ctl->state == COLLISCTL_STATE_NOTDIRTY)
    {
        velocity = mdlGetMatrix(ctl->mdl)->at;
        RwV3dNormalize(&velocity, &velocity);
        
        velocity.x *= dist;
        velocity.y *= dist;
        velocity.z *= dist;

        ctl->totalDist += (u32)dist;
        ctl->velocity = velocity;

        ctl->state = COLLISCTL_STATE_DIRTY;
    }
}

// FUN_001adff0
void K_FldFrame_CtlRotate(KwlnTask* collisCtlTask, const RwV3d* axis, f32 angle)
{
    CollisCtl* ctl;
    RwV3d originalPos;
    RwV3d negPos;

    ctl = (CollisCtl*)collisCtlTask->workData;

    if (ctl->mdl != NULL)
    {
        originalPos = mdlGetMatrix(ctl->mdl)->pos;

        negPos.x = originalPos.x * -1.0f;
        negPos.y = originalPos.y * -1.0f;
        negPos.z = originalPos.z * -1.0f;

        mdlTranslate(ctl->mdl, &negPos, rwCOMBINEPOSTCONCAT); // basically just do pos + (-pos) = (0, 0, 0)
        mdlRotate(ctl->mdl, axis, angle, rwCOMBINEPOSTCONCAT);
        mdlTranslate(ctl->mdl, &originalPos, rwCOMBINEPOSTCONCAT);
    }
}

// FUN_001ae0d0
void func_001ae0d0(KwlnTask* collisCtlTask)
{
    CollisCtl* ctl;
    RwMatrix* matrix;
    RwV3d line[2];
    RwV3d hitPoint;
    RwMatrixTolerance tolerance;

    ctl = (CollisCtl*)collisCtlTask->workData;
    matrix = mdlGetMatrix(ctl->mdl);
    line[1] = matrix->pos;
    line[0] = line[1];
    line[0].y += ctl->sphereCollisRadius;
    line[1].y -= 800.0f;
    if (K_FldFrame_Raycast(line, &hitPoint) == true)
    {
        hitPoint.y += 3.0f;
        ctl = (CollisCtl*)collisCtlTask->workData;
        if (ctl->mdl != NULL)
        {
            mdlGetMatrix(ctl->mdl)->pos = hitPoint;
            RwEngineGetMatrixTolerances(&tolerance);
            RwMatrixOptimize(mdlGetMatrix(ctl->mdl), &tolerance);
            RwMatrixUpdate(mdlGetMatrix(ctl->mdl));
            ctl->xGrid = (mdlGetMatrix(ctl->mdl)->pos.x + 400.0f) / 800.0f;
            ctl->zGrid = (mdlGetMatrix(ctl->mdl)->pos.z + 400.0f) / 800.0f;
        }
    }
}

/* One commutative address add remains. */
// FUN_001ae290
void* K_FldFrame_UpdateCollisSphereTask(KwlnTask* collisSphereTask)
{
    CollisSphereDebug* debug;
    CollisCtl* ctl;
    f32 radius;

    debug = (CollisSphereDebug*)collisSphereTask->workData;
    ctl = (CollisCtl*)collisSphereTask->parent->workData;
    radius = ctl->sphereCollisRadius;

    {
        RwV3d spherePos;
        volatile /* Removing this qualifier loses K_FldFrame_UpdateCollisSphereTask (MATCH nd0 -> MISMATCH nd101, size 296 -> 280) - measured W170. */ RwV3d posCopy;
        RwV3d pos = {0};
        RwRGBA color;

        if (ctl->mdl != NULL)
        {
            pos = mdlGetMatrix(ctl->mdl)->pos;
        }

        posCopy = pos;
        spherePos = posCopy;
        color = sDebugSphereColor;

        if (debug->drawEnabled == 0)
        {
            return KWLNTASK_CONTINUE;
        }

        spherePos.y += radius;
        if (RwCameraBeginUpdate(kwlnGetMainCamera()) != NULL)
        {
            primSphereLine3D(&spherePos, radius, &color, true);
            RwCameraEndUpdate(kwlnGetMainCamera());
        }
    }

    return KWLNTASK_CONTINUE;
}

// FUN_001ae3c0
void K_FldFrame_DestroyCollisSphereTask(KwlnTask* collisSphereTask)
{
    RwFree(collisSphereTask->workData);
}

// FUN_001ae3f0
KwlnTask* K_FldFrame_CreateCollisSphereTask(KwlnTask* parent)
{
    CollisSphereDebug* work;

    work = RwCalloc(1, sizeof(CollisSphereDebug), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    return kwlnTaskCreate(parent,
                          "collis sphere",
                          4174,
                          K_FldFrame_UpdateCollisSphereTask,
                          K_FldFrame_DestroyCollisSphereTask,
                          work);
}

// FUN_001ae470
void K_FldFrame_CollisSphereSetDrawEnabled(KwlnTask* collisSphereTask, u32 drawEnabled)
{
    ((CollisSphereDebug*)collisSphereTask->workData)->drawEnabled = drawEnabled;
}

#pragma opt_loop_invariants on

// FUN_001ae480
u32 func_001ae480(KwlnTask* task)
{
    FldFrameMoveWork* work;
    s32 i;

    work = (FldFrameMoveWork*)task->workData;
    if (work->pointCount > 0)
    {
        if ((work->flags & 0x80000000) != 0 &&
            work->points[0].drawTask != NULL)
        {
            kwlnTaskDestroyWithHierarchy(work->points[0].drawTask);
            work->points[0].drawTask = NULL;
        }
        memset_k_fldFrame_typed(&work->points[0], 0, sizeof(FldFrameMovePoint));
        work->pointCount--;
        for (i = 0; i < work->pointCount; i++)
        {
            work->points[i] = work->points[i + 1];
            work->points[i + 1].drawTask = NULL;
        }
        return true;
    }
    return false;
}
#pragma opt_loop_invariants reset

// FUN_001ae580 NONMATCHING
void* func_001ae580(KwlnTask* task)
{
    FldFrameMoveWork* work;
    Model* model;
    s32 i;
    f32 amount;
    f32 localAngleStep;
    f32 localAngle;
    f32 localAngleB;
    RwV3d translation;
    RwV3d localDir;
    RwV3d localPosition;
    s32 mode;
    s32 pointCount;

    work = fldFrameMoveWork(task);
    model = fldFrameMoveModel(work);
    pointCount = work->pointCount;
    mode = work->mode;
    if (mode == 1)
    {
        return KWLNTASK_CONTINUE;
    }
    localAngleStep = 0.0f;
    localAngle = 0.0f;
    localAngleB = 0.0f;
    localDir = sAxisUp;
    localPosition = sAxisForward;
    switch (work->state)
    {
    case 0:
    {
        work->drawMatrix = func_004c38c0();
        work->state = 1;
        return KWLNTASK_CONTINUE;
    }
    case 1:
    {
        s32 kind;
        s32 anim;

        if (pointCount > 0 || work->pendingPointCount > 0)
        {
            kind = (s32)work->points[0].kind;
            if (kind == 1 || kind == 4)
            {
                if ((*(u16*)work->resource & 0x3ff) < 100)
                {
                    func_003182d0(fldFrameMoveModel(work), 0,
                                  (s16)func_001dde00(work->animation), 2, 1);
                }
                else
                {
                    func_003182d0(fldFrameMoveModel(work), 0, 0, 8, 1);
                }
                func_003189f0(fldFrameMoveModel(work), 0, 1.0f);
                work->frameCount = (s32)work->points[0].duration;
                work->state = 5;
            }
            else if (kind == 2)
            {
                anim = (s16)func_001dde00(work->animation);
                if ((*(u16*)work->resource & 0x3ff) < 100)
                {
                    func_003182d0(fldFrameMoveModel(work), 0, anim, 2, 1);
                }
                else
                {
                    func_003182d0(fldFrameMoveModel(work), 0, anim, 8, anim);
                }
                func_003189f0(fldFrameMoveModel(work), 0, 1.0f);
                work->frameCount = (s32)work->points[0].duration;
                work->state = 6;
            }
            else if (kind != 5)
            {
                if ((*(u16*)work->resource & 0x3ff) < 100)
                {
                    anim = (s16)func_00318540(fldFrameMoveModel(work), 0);
                    if (anim != func_001ded40(work->animation))
                    {
                        func_003182d0(fldFrameMoveModel(work), 0,
                                      (s16)func_001ded40(work->animation), 8, 1);
                    }
                }
                else
                {
                    anim = (s16)func_00318540(fldFrameMoveModel(work), 0);
                    if (anim != 1)
                    {
                        func_003182d0(fldFrameMoveModel(work), 0, 1, 8, 1);
                    }
                }
                work->targetAnimation = 8;
                work->state = 2;
            }
            return KWLNTASK_CONTINUE;
        }
        if (work->targetAnimation > 0)
        {
            work->targetAnimation--;
            return KWLNTASK_CONTINUE;
        }
        anim = (s16)func_00318540(fldFrameMoveModel(work), 0);
        if ((*(u16*)work->resource & 0x3ff) < 100)
        {
            if (anim != 4 && anim != 0x15 &&
                anim != func_001dde00(work->animation))
            {
                func_003182d0(fldFrameMoveModel(work), 0,
                              (s16)func_001dde00(work->animation), 8, 1);
                func_003189f0(fldFrameMoveModel(work), 0, 1.0f);
            }
        }
        else if (anim != 3 && anim != 0)
        {
            func_003182d0(fldFrameMoveModel(work), 0, 0, 8, 1);
            func_003189f0(fldFrameMoveModel(work), 0, 1.0f);
        }
        return KWLNTASK_CONTINUE;
    }
    case 2:
    {
        s32 pending = work->pendingPointCount;
        if (pending > 0)
        {
            if (pending < 3)
            {
                if (work->pointCount + pending < 48)
                {
                    for (i = 0; i < work->pendingPointCount; i++)
                    {
                        const u8* source = (const u8*)work + 0x4e0 + i * 0x18;

                        work->points[work->pointCount].position.x =
                            *(const f32*)(source + 0x00);
                        work->points[work->pointCount].position.y =
                            *(const f32*)(source + 0x04);
                        work->points[work->pointCount].position.z =
                            *(const f32*)(source + 0x08);
                        work->points[work->pointCount].duration =
                            *(const f32*)(source + 0x0c);
                        work->points[work->pointCount].kind = 0;
                        work->pointCount++;
                    }
                    work->pendingPointCount = 0;
                }
            }
            else if (work->pointCount + pending * 4 < 48)
            {
                RwV3d curvePoints[13];
                void* curve;
                s32 index;
                s32 step;
                f32 stepScale;

                index = -1;
                if (work->pointCount > 0)
                {
                    index = work->pointCount - 1;
                    while (index >= 0 && work->points[index].kind != 0)
                    {
                        index--;
                    }
                }
                if (index >= 0)
                {
                    curvePoints[0] = work->points[index].position;
                }
                else
                {
                    const u8* origin =
                        (const u8*)func_00318b60((u32)fldFrameMoveModel(work));

                    curvePoints[0].x = *(const f32*)(origin + 0x30);
                    curvePoints[0].y = *(const f32*)(origin + 0x34);
                    curvePoints[0].z = *(const f32*)(origin + 0x38);
                }
                for (i = 0; i < work->pendingPointCount; i++)
                {
                    const u8* source = (const u8*)work + 0x4e0 + i * 0x18;

                    curvePoints[i + 1].x = *(const f32*)(source + 0x00);
                    curvePoints[i + 1].y = *(const f32*)(source + 0x04);
                    curvePoints[i + 1].z = *(const f32*)(source + 0x08);
                }
                curve = func_0048dab0(work->pendingPointCount + 1, 1, curvePoints);
                stepScale = 1.0f / (f32)(work->pendingPointCount * 4);
                for (step = 1; step < work->pendingPointCount * 4; step++)
                {
                    func_0048d480((f32)step * stepScale, curve, 0xa,
                                  &work->points[work->pointCount].position, 0);
                    work->points[work->pointCount].duration =
                        *(const f32*)((const u8*)work + 0x4ec +
                                      (work->pendingPointCount / 4) * 0x18);
                    work->points[work->pointCount].kind = 0;
                    fldFrameMoveCreateDebugPoint(
                        work, &work->points[work->pointCount],
                        &sDebugSphereColor);
                    work->pointCount++;
                }
                work->pendingPointCount = 0;
                func_0048da30(curve);
            }
        }
        pointCount = work->pointCount;
        if (pointCount <= 0)
        {
            work->state = 1;
            return KWLNTASK_CONTINUE;
        }
        {
            const u8* origin =
                (const u8*)func_00318b60((u32)fldFrameMoveModel(work));

            work->startPosition.x = *(const f32*)(origin + 0x30);
            work->startPosition.y = *(const f32*)(origin + 0x34);
            work->startPosition.z = *(const f32*)(origin + 0x38);
            translation = work->points[0].position;
            work->startPosition.y = 0.0f;
            translation.y = 0.0f;
            work->direction.x = translation.x - work->startPosition.x;
            work->direction.y = 0.0f - work->startPosition.y;
            work->direction.z = translation.z - work->startPosition.z;
            work->directionLength =
                func_004c69f0(&work->direction, &work->direction);
        }
        localAngle = fGpffff82b0 *
                     func_0052e9e8(work->direction.y * localPosition.y +
                                   work->direction.x * localPosition.x +
                                   work->direction.z * localPosition.z);
        if (work->direction.x < 0.0f)
        {
            localAngle = localAngle * -1.0f;
        }
        if (work->turnMode != 0)
        {
            localAngleStep =
                180.0f +
                func_001a5aa0(func_00318b60((u32)fldFrameMoveModel(work)));
            work->currentAngle = localAngleStep;
            localAngle = 180.0f + localAngle;
            if (localAngle <= localAngleStep)
            {
                localAngleB = (360.0f - localAngleStep) + localAngle;
            }
            else
            {
                localAngleB = (360.0f - localAngle) + localAngleStep;
            }
            amount = localAngle - localAngleStep;
            if (func_0045ec20(func_0052e118(func_00530da0(localAngleB)),
                              func_0052e118(func_00530da0(amount))) != 0)
            {
                localAngleB = amount;
            }
            work->frame = 0;
            work->angleStep = localAngleB / (f32)work->turnMode;
            work->currentAngle = localAngle;
        }
        else
        {
            work->currentAngle = 180.0f + localAngle;
        }
        work->frameCount =
            (s32)(work->directionLength / work->points[0].duration);
        work->frameRemainder =
            work->directionLength -
            work->points[0].duration * (f32)work->frameCount;
        if (work->frameRemainder > 0.0f)
        {
            work->frameCount++;
        }
        work->state = 3;
        return KWLNTASK_CONTINUE;
    }
    case 3:
    {
        if (model == NULL)
        {
            func_001ae480(task);
            work->state = 1;
            return KWLNTASK_CONTINUE;
        }
        amount = work->directionLength / (f32)work->frameCount;
        translation.x = work->direction.x * amount;
        translation.y = work->direction.y * amount;
        translation.z = work->direction.z * amount;
        mdlTranslate(model, &translation, rwCOMBINEPOSTCONCAT);
        if (work->points[0].drawTask != NULL)
        {
            K_Draw_SetPositionPos(work->points[0].drawTask,
                                  &mdlGetMatrix(model)->pos);
        }
        work->frameCount--;
        if (work->frameCount <= 0)
        {
            mdlGetMatrix(model)->pos = work->points[0].position;
            func_001ae480(task);
            {
                u8* ctl = *(u8**)((u8*)work + 0x4cc);
                *(u32*)(ctl + 0x28) = 0x3f800000;
                *(u32*)(ctl + 0x14) = 0x3f800000;
                *(u32*)(ctl + 0x00) = 0x3f800000;
                *(u32*)(ctl + 0x10) = 0;
                *(u32*)(ctl + 0x08) = 0;
                *(u32*)(ctl + 0x04) = 0;
                *(u32*)(ctl + 0x24) = 0;
                *(u32*)(ctl + 0x20) = 0;
                *(u32*)(ctl + 0x18) = 0;
                *(u32*)(ctl + 0x38) = 0;
                *(u32*)(ctl + 0x34) = 0;
                *(u32*)(ctl + 0x30) = 0;
                *(u32*)(ctl + 0x0c) |= 0x200003;
            }
            func_004c31b0((RwMatrix*)work->drawMatrix, &localDir,
                          localAngleStep, 2);
            func_001ad9e0(fldFrameMoveCtl(work), work->drawMatrix);
            work->state = 4;
        }
        return KWLNTASK_CONTINUE;
    }
    case 4:
    {
        RwV3d targetDir;
        f32 targetLen;

        if (model == NULL)
        {
            func_001ae480(task);
            work->state = 1;
            return KWLNTASK_CONTINUE;
        }
        localPosition = mdlGetMatrix(model)->pos;
        targetDir.x = work->points[0].position.x - localPosition.x;
        targetDir.y = work->points[0].position.y - localPosition.y;
        targetDir.z = work->points[0].position.z - localPosition.z;
        targetLen = RwV3dNormalize(&targetDir, &targetDir);
        amount = targetLen / (f32)work->frameCount;
        translation.x = work->direction.x * amount;
        translation.y = work->direction.y * amount;
        translation.z = work->direction.z * amount;
        mdlTranslate(model, &translation, rwCOMBINEPOSTCONCAT);
        if (work->points[0].drawTask != NULL)
        {
            K_Draw_SetPositionPos(work->points[0].drawTask,
                                  &mdlGetMatrix(model)->pos);
        }
        work->frameCount--;
        if (work->frameCount <= 0)
        {
            mdlGetMatrix(model)->pos = work->points[0].position;
            func_001ae480(task);
            work->state = (mode == 1 || mode == 4) ? 1 : 2;
        }
        return KWLNTASK_CONTINUE;
    }
    case 5:
    {
        CollisCtl* ctl;
        RwV3d velocity = {0.0f, 0.0f, 0.0f};

        ctl = (CollisCtl*)fldFrameMoveCtl(work)->workData;
        amount = work->points[0].duration;
        if (ctl->state == COLLISCTL_STATE_NOTDIRTY)
        {
            velocity = ((RwMatrix*)func_00318b60((u32)ctl->mdl))->at;
            func_004c69f0(&velocity, &velocity);
            velocity.x *= amount;
            velocity.y *= amount;
            velocity.z *= amount;
            ctl->totalDist += (u32)amount;
            ctl->velocity = velocity;
            ctl->state = COLLISCTL_STATE_DIRTY;
        }
        if ((*(u16*)work->resource & 0x3ff) >= 100)
        {
            f32 speed = amount / fGpffff82b4 * 2.0f;

            if (ctl->mdl->id == 3)
            {
                speed = 1.0f;
            }
            func_003189f0(ctl->mdl, 0, speed);
        }
        work->frameCount--;
        if (work->frameCount < 0)
        {
            func_001ae480(task);
            work->state = (mode == 1 || mode == 4) ? 1 : 2;
        }
        return KWLNTASK_CONTINUE;
    }
    case 6:
    {
        const u8* origin =
            (const u8*)func_00318b60((u32)fldFrameMoveModel(work));

        work->startPosition.x = *(const f32*)(origin + 0x30);
        work->startPosition.y = *(const f32*)(origin + 0x34);
        work->startPosition.z = *(const f32*)(origin + 0x38);
        work->direction.x =
            work->points[0].position.x - work->startPosition.x;
        work->direction.y =
            work->points[0].position.y - work->startPosition.y;
        work->direction.z =
            work->points[0].position.z - work->startPosition.z;
        work->directionLength =
            func_004c69f0(&work->direction, &work->direction);
        localAngle = fGpffff82b0 *
                     func_0052e9e8(work->direction.y * localPosition.y +
                                   work->direction.x * localPosition.x +
                                   work->direction.z * localPosition.z);
        if (work->direction.x < 0.0f)
        {
            localAngle = localAngle * -1.0f;
        }
        localAngleStep =
            180.0f +
            func_001a5aa0(func_00318b60((u32)fldFrameMoveModel(work)));
        work->currentAngle = localAngleStep;
        localAngle = 180.0f + localAngle;
        if (localAngle <= localAngleStep)
        {
            localAngleB = (360.0f - localAngleStep) + localAngle;
        }
        else
        {
            localAngleB = (360.0f - localAngle) + localAngleStep;
        }
        amount = localAngle - localAngleStep;
        if (func_0045ec20(func_0052e118(func_00530da0(localAngleB)),
                          func_0052e118(func_00530da0(amount))) != 0)
        {
            localAngleB = amount;
        }
        work->frame = 0;
        work->angleStep = localAngleB / work->points[0].duration;
        work->currentAngle = localAngle;
        work->state = 7;
        return KWLNTASK_CONTINUE;
    }
    case 7:
    {
        if ((u32)work->frame < (u32)(s32)work->points[0].duration)
        {
            RwV3d pivot;
            RwV3d offset;
            f32 step;
            Model* target;

            localDir = sAxisUp;
            step = work->angleStep;
            target = *(Model**)((u8*)fldFrameMoveCtl(work)->workData + 0x10);
            if (target != NULL)
            {
                const u8* origin = (const u8*)func_00318b60((u32)target);

                pivot.x = *(const f32*)(origin + 0x30);
                pivot.y = *(const f32*)(origin + 0x34);
                pivot.z = *(const f32*)(origin + 0x38);
                offset.x = -1.0f * pivot.x;
                offset.y = -1.0f * pivot.y;
                offset.z = -1.0f * pivot.z;
                func_00318a30(
                    *(Model**)((u8*)fldFrameMoveCtl(work)->workData + 0x10),
                    &offset, 2);
                func_00318a50(
                    *(Model**)((u8*)fldFrameMoveCtl(work)->workData + 0x10),
                    &localDir, step, 2);
                func_00318a30(
                    *(Model**)((u8*)fldFrameMoveCtl(work)->workData + 0x10),
                    &pivot, 2);
            }
            work->frame++;
            return KWLNTASK_CONTINUE;
        }
        {
            u8* ctl = *(u8**)((u8*)work + 0x4cc);
            *(u32*)(ctl + 0x28) = 0x3f800000;
            *(u32*)(ctl + 0x14) = 0x3f800000;
            *(u32*)(ctl + 0x00) = 0x3f800000;
            *(u32*)(ctl + 0x10) = 0;
            *(u32*)(ctl + 0x08) = 0;
            *(u32*)(ctl + 0x04) = 0;
            *(u32*)(ctl + 0x24) = 0;
            *(u32*)(ctl + 0x20) = 0;
            *(u32*)(ctl + 0x18) = 0;
            *(u32*)(ctl + 0x38) = 0;
            *(u32*)(ctl + 0x34) = 0;
            *(u32*)(ctl + 0x30) = 0;
            *(u32*)(ctl + 0x0c) |= 0x200003;
        }
        ((RwMatrix*)work->drawMatrix)->at.z = 1.0f;
        ((RwMatrix*)work->drawMatrix)->up.y = 1.0f;
        ((RwMatrix*)work->drawMatrix)->right.x = 1.0f;
        ((RwMatrix*)work->drawMatrix)->up.x = 0.0f;
        ((RwMatrix*)work->drawMatrix)->right.z = 0.0f;
        ((RwMatrix*)work->drawMatrix)->right.y = 0.0f;
        ((RwMatrix*)work->drawMatrix)->at.y = 0.0f;
        ((RwMatrix*)work->drawMatrix)->at.x = 0.0f;
        ((RwMatrix*)work->drawMatrix)->up.z = 0.0f;
        ((RwMatrix*)work->drawMatrix)->pos.z = 0.0f;
        ((RwMatrix*)work->drawMatrix)->pos.y = 0.0f;
        ((RwMatrix*)work->drawMatrix)->pos.x = 0.0f;
        ((RwMatrix*)work->drawMatrix)->flags |=
            rwMATRIXINTERNALIDENTITY | rwMATRIXTYPEORTHONORMAL;
        func_004c31b0((RwMatrix*)work->drawMatrix, &localDir,
                      work->currentAngle - 180.0f, 1);
        func_001ad9e0(fldFrameMoveCtl(work), work->drawMatrix);
        func_001ae480(task);
        work->state = 1;
        return KWLNTASK_CONTINUE;
    }
    case 8:
    {
        work->state = 1;
        return KWLNTASK_CONTINUE;
    }
    default:
        break;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_001af8e0
void func_001af8e0(KwlnTask* task)
{
    FldFrameMoveWork* work = (FldFrameMoveWork*)task->workData;

    if (work->drawMatrix != NULL)
    {
        func_004c3880(work->drawMatrix);
    }
    (*(void (**)(void*))jtbl_0096017C_abs)(task->workData);
}

// FUN_001af930
KwlnTask* func_001af930(KwlnTask* parent, void* resource)
{
    u32 animation;
    FldFrameMoveWork* work;
    KwlnTask* task;
    work = (FldFrameMoveWork*)RwCalloc(1, 0x5a0, rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreateWithAutoPriority(parent,
                                          10,
                                          "field move",
                                          func_001ae580,
                                          func_001af8e0,
                                          work);
    work->resource = resource;
    if ((*(u16*)resource & 0x3ff) < 100)
    {
        animation = *(u16*)((u8*)*(Model**)((u8*)resource + 0x128) + 0xd6);
        if (animation > 0xff)
        {
            work->animation = animation >> 8;
        }
        else
        {
            work->animation = animation;
        }
        work->turnMode = 0;
    }
    else
    {
        work->turnMode = 5;
    }
    return task;
}

// Replacing both 12-byte typed memcpy calls with direct RwV3d stores removes the retail-extra calls but worsens normalized_diff 363 -> 379 (object 784 -> 792, window 800); retain typed helpers (measured W414).
// FUN_001AFA20 NONMATCHING
u32 func_001afa20(f32 duration, KwlnTask* task, const RwV3d* position)
{
    FldFrameMoveWork* work;
    RwV3d line[2];
    RwV3d resolved;
    RwV3d* output;
    f32 debugColor;

    work = (FldFrameMoveWork*)task->workData;
    line[1] = *position;
    line[0] = *position;
    if (K_Scene_001a0250() != false)
    {
        line[0].y += 600.0f;
    }
    else
    {
        line[0].y += 200.0f;
    }
    line[1].y -= 1000.0f;
    switch (work->pathMode)
    {
    case 0:
        if (work->pointCount < 47)
        {
            if (K_FldFrame_Raycast(line, &resolved) == true)
            {
                work->points[work->pointCount].position = resolved;
            }
            else
            {
                work->points[work->pointCount].position = *position;
            }
            work->points[work->pointCount].duration = duration;
            work->points[work->pointCount].kind = 0;
            if ((work->flags & 0x80000000) != 0)
            {
                debugColor = *(f32*)&sDebugSphereColor;
                work->points[work->pointCount].drawTask = K_Draw_CreatePositionTask(0);
                K_Draw_SetPositionColor(work->points[work->pointCount].drawTask,
                                        (RwRGBA*)&debugColor);
                K_Draw_SetPositionPos(work->points[work->pointCount].drawTask,
                                      &work->points[work->pointCount].position);
            }
            work->pointCount++;
            return true;
        }
        return false;
    case 1:
        if (work->pendingPointCount < 7)
        {
            if (K_FldFrame_Raycast(line, &resolved) == true)
            {
                output = (RwV3d*)((u8*)work + 0x4e0 + work->pendingPointCount * 0x18);
                *output = resolved;
            }
            else
            {
                output = (RwV3d*)((u8*)work + 0x4e0 + work->pendingPointCount * 0x18);
                *output = *position;
            }
            *(f32*)((u8*)work + 0x4e0 + work->pendingPointCount * 0x18 + 0x0c) = duration;
            work->pendingPointCount++;
            return true;
        }
        return false;
    default:
        return false;
    }
}

// FUN_001AFD40
u32 func_001afd40(KwlnTask* task, const RwV3d* position, f32 duration)
{
    FldFrameMoveWork* work;
    RwV3d line[2];
    RwV3d resolved;
    f32 debugColor;

    work = (FldFrameMoveWork*)task->workData;
    line[1] = *position;
    line[0] = line[1];
    if (K_Scene_001a0250() != false)
    {
        line[0].y += 600.0f;
    }
    else
    {
        line[0].y += 200.0f;
    }
    line[1].y -= 1000.0f;
    if (work->pointCount >= 47)
    {
        goto done;
    }
    if (K_FldFrame_Raycast(line, &resolved) == true)
    {
        work->points[work->pointCount].position = resolved;
    }
    else
    {
        work->points[work->pointCount].position = *position;
    }
    work->points[work->pointCount].duration = duration;
    work->points[work->pointCount].kind = 3;
    if ((work->flags & 0x80000000) != 0)
    {
        debugColor = *(f32*)&sDebugSphereColor;
        work->points[work->pointCount].drawTask = K_Draw_CreatePositionTask(0);
        K_Draw_SetPositionColor(work->points[work->pointCount].drawTask,
                                (RwRGBA*)&debugColor);
        K_Draw_SetPositionPos(work->points[work->pointCount].drawTask,
                              &work->points[work->pointCount].position);
    }
    work->pointCount++;
    return true;
done:
    return false;
}

// FUN_001AFF70
u32 func_001aff70(KwlnTask* task, s32 duration)
{
    FldFrameMoveWork* work;

    work = (FldFrameMoveWork*)task->workData;
    if (work->pointCount < 47)
    {
        if (work->pointCount > 0 &&
            work->points[work->pointCount - 1].kind == 1)
        {
            return false;
        }
        work->points[work->pointCount].kind = 1;
        work->points[work->pointCount].duration = (f32)duration;
        work->pointCount++;
        return true;
    }
    return false;
}

// FUN_001b0020
u32 func_001b0020(KwlnTask* task, const RwV3d* position, s32 duration)
{
    FldFrameMoveWork* work;

    work = (FldFrameMoveWork*)task->workData;
    if (work->pointCount < 47)
    {
        work->points[work->pointCount].kind = 2;
        work->points[work->pointCount].position = *position;
        work->points[work->pointCount].duration = (f32)duration;
        work->pointCount++;
        return true;
    }
    return false;
}

// FUN_001b00c0
void func_001b00c0(KwlnTask* task)
{
    FldFrameMoveWork* work;
    s32 i;
    Model* model;

    work = (FldFrameMoveWork*)task->workData;
    if (work->points[0].kind == 3)
    {
        return;
    }
    if (work->points[0].kind == 4)
    {
        return;
    }
    if ((work->flags & 0x80000000) != 0)
    {
        for (i = 0; i < work->pointCount; i++)
        {
            if (*(KwlnTask**)((u8*)work + 0x20 + i * 0x18 + 0x14) != NULL)
            {
                kwlnTaskDestroyWithHierarchy(
                    *(KwlnTask**)((u8*)work + 0x20 + i * 0x18 + 0x14));
            }
            *(KwlnTask**)((u8*)work + 0x20 + i * 0x18 + 0x14) = NULL;
        }
    }
    if (work->pointCount == 0)
    {
        goto reset;
    }
    model = *(Model**)((u8*)work->resource + 0x128);
    mdlLookAtDisableTarget(model);
reset:
    memset_k_fldFrame_typed(work->points, 0, sizeof(work->points));
    work->pointCount = 0;
    work->pendingPointCount = 0;
    work->state = 1;
}

// FUN_001b01b0
u32* func_001b01b0(KwlnTask* task, s32 index)
{
    return &((FldFrameMoveWork*)task->workData)->points[index].kind;
}

// FUN_001b01d0
void func_001b01d0(KwlnTask* task, s32 index, const FldFrameMovePoint* point)
{
    FldFrameMoveWork* work;
    s32 offset;

    work = (FldFrameMoveWork*)task->workData;
    offset = index * 0x18;
    *(FldFrameMovePoint*)(offset + (int)work + 0x20) = *point;
}

// FUN_001b0220
s32 func_001b0220(KwlnTask* task)
{
    return ((FldFrameMoveWork*)task->workData)->pointCount;
}

// Retail offsets 0x000-0x730: scene/time/date dispatch and 13 audio-table branches; 0x734-0x73f is tail padding.
// FUN_001b0230
void func_001b0230(KwlnTask* task, s32 pointCount)
{
    ((FldFrameMoveWork*)task->workData)->pointCount = pointCount;
}

// FUN_001b0240
void func_001b0240(KwlnTask* task, s32 mode)
{
    ((FldFrameMoveWork*)task->workData)->pathMode = mode;
}

// FUN_001b0250
void func_001b0250(KwlnTask* task, s32 turnMode)
{
    ((FldFrameMoveWork*)task->workData)->turnMode = turnMode;
}

// FUN_001b0260
void func_001b0260(KwlnTask* task, s32 mode)
{
    FldFrameMoveWork* work;
    CollisCtl* ctl;

    work = (FldFrameMoveWork*)task->workData;
    work->mode = mode;
    if (mode == 1)
    {
        ctl = (CollisCtl*)((KwlnTask*)*(void**)((u8*)work->resource + 0x1e0))->workData;
        ctl->flags |= COLLISCTL_FLAG_NOUPDATE;
    }
    else
    {
        ctl = (CollisCtl*)((KwlnTask*)*(void**)((u8*)work->resource + 0x1e0))->workData;
        ctl->flags &= ~COLLISCTL_FLAG_NOUPDATE;
    }
}

// FUN_001b02c0 NONMATCHING
f32 func_001b02c0(s32 inputIndex, s32 usePad)
{
    RwV3d direction;
    RwV3d normalized;
    u16 flags;
    s32 offset;
    s32 i;
    f32 angle;

    offset = inputIndex * 0x36;
    for (i = 0; i < (s32)sizeof(direction); i++)
    {
        ((u8*)&direction)[i] = 0;
    }

    flags = *(u16*)(D_007E094C + inputIndex * 0x1b);
    if (usePad == 0)
    {
        direction.z = (f32)D_007E095F[offset] - 128.0f;
        if ((flags & 0x1000) != 0)
        {
            direction.z = -128.0f;
        }
        else if ((flags & 0x4000) != 0)
        {
            direction.z = 128.0f;
        }
        if ((flags & 0xa000) != 0 &&
            direction.z >= -48.0f && direction.z <= 48.0f)
        {
            direction.z = 0.0f;
        }

        direction.x = (f32)D_007E095E[offset] - 128.0f;
        if ((flags & 0x8000) != 0)
        {
            direction.x = -128.0f;
        }
        else if ((flags & 0x2000) != 0)
        {
            direction.x = 128.0f;
        }
        if ((flags & 0x5000) != 0 &&
            direction.x >= -48.0f && direction.x <= 48.0f)
        {
            direction.x = 0.0f;
        }
    }
    else
    {
        direction.z = (f32)D_007E0961[offset] - 128.0f;
        if (direction.z >= -48.0f && direction.z <= 48.0f)
        {
            direction.z = 0.0f;
        }
        direction.x = (f32)D_007E0960[offset] - 128.0f;
        if (direction.x >= -48.0f && direction.x <= 48.0f)
        {
            direction.x = 0.0f;
        }
    }

    if (direction.z < -48.0f || direction.z > 48.0f ||
        direction.x < -48.0f || direction.x > 48.0f)
    {
        func_004c69f0(&normalized, &direction);
        angle = func_0052e9e8(normalized.z / normalized.x) * 57.2957795f;
        if (direction.x < 0.0f)
        {
            angle = 360.0f - angle;
        }
        angle += 180.0f;
        if (angle > 360.0f)
        {
            angle -= 360.0f;
        }
        return angle;
    }
    return 0.0f;
}
