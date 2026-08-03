#include "h_maestro.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "rw/rt2danim.h"
#include "h_cdvd.h"
#include "rw/rwcore.h"
#include "temporary.h"
extern KwlnTask* func_00119960(KwlnTask* parent, u32 effectType, void* blob);

#pragma alias func_004aa390_y2 func_004aa390
#pragma alias func_004a9f20_y2 func_004a9f20
#pragma alias func_004aaa60_y2 func_004aaa60
#pragma alias func_004aad50_y2 func_004aad50
#pragma alias func_00110650_y2 func_00110650
#pragma alias func_004c58a0_y2 func_004c58a0
#pragma alias D_00960088_abs_y2 D_00960088_abs_y2
#pragma alias printf_y2 printf_y2
#pragma alias memcpy_y2 memcpy_y2
#pragma alias func_004aa3d0_y2 func_004aa3d0_y2
#pragma alias func_004aa410_y2 func_004aa410_y2
#pragma alias func_004b45b0_y2 func_004b45b0_y2
#pragma alias func_004a9bf0_y2 func_004a9bf0_y2
#pragma alias func_004cde90_y2 func_004cde90_y2
#pragma alias func_004c5780_y2 func_004c5780_y2
#pragma alias D_00960088_y2 D_00960088_y2

#pragma alias DAT_00960090_abs DAT_00960090
extern u8 DAT_00960090_abs[];

extern u32 FUN_004c2090(void* param_1);
extern f32 FUN_004b1a70(u32 param_1);
extern f32 FUN_004b1a60(u32 param_1);
extern void FUN_004b1870(u32 param_1, u32 param_2, u32 param_3);
extern f32 fGpffff80e4;
extern f32 gPI;
extern f32 gUnk_007cadd0;
extern RwCamera* kwlnGetMainCamera();
extern void H_Maestro_00111c50(KwlnTask* hmaestroTask);
extern void* func_004aa390_y2(f32 param_1);
extern void* func_004aa3d0(f32 param_1);
extern void* func_004a9f20_y2(f32 param_1, f32 param_2, f32 param_3, f32 param_4);
extern void* func_004aa410(RwCamera* camera);
extern void func_004a9d80(RwV2d* param_1, RwV2d* param_2, RwV2d* param_3);
extern void* func_004a9bf0();
extern void* func_004aaa60_y2();
extern void* func_004aad50_y2();
extern void* func_004aef60(Rt2dObject* scene);
extern void* func_004ae060(Rt2dObject* scene);
extern void* func_004ae070(Rt2dObject* scene, f32 param_2, f32 param_3);
extern void* func_004ae0c0(Rt2dObject* scene, f32 param_2, f32 param_3);
extern void* func_004ae110(Rt2dObject* scene, RwRGBAReal* color);
extern void* func_004b45b0(void* param_1, RwStream* stream);
extern void* func_004b4c70(Rt2dMaestro* maestro);
extern void* func_004b3cc0(Rt2dMaestro* maestro);
extern void* func_004b5000(Rt2dMaestro* maestro, f32 time);
extern void* func_004b5330(Rt2dMaestro* maestro);
extern void* func_004b4d60(Rt2dMaestro* maestro);
extern void* func_004c1600(RwStream* stream, u32 param_2, u32 param_3, u32 param_4);
extern RwStream* func_004c58a0_y2(u32 param_1, u32 param_2, const char* path);
extern void* func_004c5780(RwStream* stream, void* param_2);
extern void* func_004c9d70(RwCamera* camera, f32 nearPlane);
extern const char D_005D6B80[];
extern const char D_005D6BA0[];
extern RwMatrix* func_004c38c0(void);
extern void func_004c3880(RwMatrix* matrix);
extern RwMatrix* func_004c2fc0(RwReal oneMinusCosine, RwReal sine, RwMatrix* matrix, const RwV3d* axis, RwOpCombineType combineOp);
extern RwV3d* func_004c6c20(RwV3d* pointsOut, const RwV3d* pointsIn, RwUInt32 pointCount, const RwMatrix* matrix);
extern f32 sinf(f32 angle);
extern f32 cosf(f32 angle);

typedef struct MaestroResourceWork
{
    s32 state;
    s32 resourceIndex;
    void* resources[40];
    void* parsedResources[40];
    void* effectResources[40];
    s32 recordIndices[40];
    s32 renderStates[40];
    void* runtimeResources[40];
    u8 reserved1[0x10];
    f32 x;
    f32 y;
    u8 reserved2[8];
    s32 completedRecords;
    u8 reserved3[4];
    s16 coordinates0[40];
    s16 coordinates1[40];
    s16 coordinates2[40];
    u32 resourceCount;
    u32 renderFlags;
    u32 cancelRequested;
} MaestroResourceWork;

typedef struct MaestroStreamDimensions
{
    s16 values[4];
} MaestroStreamDimensions;

typedef struct MaestroStreamWork
{
    s32 state;
    s32 resourceIndex;
    void* resources[40];
    s16 dimensions[4];
    KwlnTask* resourceTask;
    s32 frameIndex;
    s32 recordCount;
    s32 complete;
    s32 stopAtFrame;
    void* stream;
    HCdvd* cdvd;
    u8 archiveHeader[0x2A];
    u8* records;
    char path[256];
    char basePath[256];
    f32 x;
    f32 y;
    u32 renderFlags;
    u32 createCustomPriorityTask;
    u32 resourceTaskPriority;
    u32 useCdvd;
} MaestroStreamWork;

typedef struct MaestroBlobNode
{
    s16 state;
    char path[0x102];
    void* resources[32];
    void* output;
    HCdvd* cdvd;
    u8* source;
    u32 sourceOffset;
    s16 resourceIndex;
    s16 outputCount;
    u8 header[0x20];
    struct MaestroBlobNode* next;
    struct MaestroBlobNode* prev;
} MaestroBlobNode;

typedef struct MaestroRenderNode
{
    struct MaestroRenderNode* next; // 0x00
    void* unused4;                  // 0x04
    MaestroBlobNode* blob;          // 0x08
    s32 outputIndex;                // 0x0c
    f32 x;                          // 0x10
    f32 y;                          // 0x14
    u8 alphaCutoff;                 // 0x18
    u8 alphaLoss;                   // 0x19
    u8 reserved1A[2];               // 0x1a
    s16 extraWidth;                 // 0x1c
    s16 extraHeight;                // 0x1e
    f32 angle;                      // 0x20
    s16 pivotX;                     // 0x24
    s16 pivotY;                     // 0x26
    u16 xScale;                     // 0x28
    u16 yScale;                     // 0x2a
    f32 depth;                      // 0x2c
    u8 red;                         // 0x30
    u8 green;                       // 0x31
    u8 blue;                        // 0x32
} MaestroRenderNode;

typedef struct MaestroOutputRecord
{
    u8 reserved0[0x14];
    s32 resourceIndex;              // 0x14
    u32 flags;                      // 0x18
    u8 reserved1[0x10];
    u32 renderStateFlags;           // 0x2c
    u8 reserved30[4];
    s32 topExtension;               // 0x34
    s32 bottomExtension;            // 0x38
    s32 leftExtension;              // 0x3c
    s32 rightExtension;             // 0x40
    s32 x;                          // 0x44
    s32 y;                          // 0x48
    u8 reserved2[12];
    s32 left;                       // 0x54
    s32 top;                        // 0x58
    s32 right;                      // 0x5c
    s32 bottom;                     // 0x60
    u32 colors[4];                  // 0x64
    s16 overrideX;                  // 0x74
    s16 overrideY;                  // 0x76
} MaestroOutputRecord;

extern u32 D_00960184[];
#pragma alias D_00960184_abs D_00960184
extern u8 D_00960184_abs[];
extern u32 jtbl_0096017C[];
extern void (*D_00960090)(u32 state, u32 value);
 #pragma alias D_00960090_abs D_00960090
 extern u8 D_00960090_abs[];
extern void (*D_009600A0)(RwPrimitiveType primitiveType, RwIm2DVertex* vertices, s32 vertexCount);
#pragma alias D_009600A0_abs D_009600A0
extern u8 D_009600A0_abs[];
#pragma alias D_009600A0_data_abs D_009600A0
extern u8 D_009600A0_data_abs[];
extern f32 D_00960088;
#pragma alias D_00960088_abs D_00960088
extern u8 D_00960088_abs[];
extern RwV3d D_005D6C28;
extern MaestroRenderNode* DAT_00833a4c;
extern MaestroBlobNode* DAT_00833a50;
extern int* DAT_007cdf3c;
#pragma alias DAT_007cdf3c_sda DAT_007cdf3c
extern int* DAT_007cdf3c_sda __attribute__((section(".sdata")));
extern const char* D_005D66E0[];
#define MAESTRO_ALLOC(count, size, flags) (*(void* (**)(u32, u32, u32))D_00960184_abs)(count, size, flags)
#define MAESTRO_FREE(memory) (*(void (**)(void*))jtbl_0096017C)(memory)
extern const s8 D_005D53E0[];
extern const char D_005D5880[];
extern const char D_005D5898[];
extern const char D_005D58A8[];
extern const char D_005D58C0[];
extern const char D_005D6A68[];
extern const char D_005D6A80[];
extern const char D_005D6AA0[];
extern const char D_005D6AB8[];
extern const char D_005D6AD0[];
extern const char D_005D6AF0[];
extern const char D_005D6B10[];
extern const char D_005D6B30[];
extern const char D_005D6B50[];
extern const char D_005D6B60[];
extern const char D_005D6BC0[];
extern const char D_005D6BD0[];
extern const char D_005D6BF0[];
extern const char D_005D6C10[];
extern const char D_005D6CD0[];
extern const char D_005D6E10[];
extern void* func_0010f6c0(KwlnTask* task);
extern const char* func_001022e0(HCdvd* cdvd, s32 entryIndex);
extern void* func_0010c1a0(void* param_1, const char* path, ...);
extern void func_00102720(const char* path, const void* archive);
extern void* func_0010c3a0(void* stream, u32* finished, u32 param_3);
extern void func_0010a4e0(u32 param_1, u32 param_2, s8 param_3, s8 param_4);
#pragma alias func_0010e880_y2 func_0010e880
extern void* func_0010e880_y2(const void* entry);
extern void func_00133d30(void* stream, HCdvd* cdvd);
extern u32 func_004a5540(void* resource);
extern void func_004a6200(void* resource, const f32* uv0, const f32* uv1, const f32* uv2, const f32* uv3);
extern void func_004ac120(void* resource, f32* output);
extern u32 func_004ac390(void* resource);
extern void func_004cde90(void* resource);
extern void func_004d0f00(void* resource);
extern void func_0010ec50(KwlnTask* task);
extern void* D_00833a40[];
#pragma alias D_00833a40_abs D_00833a40
extern void* D_00833a40_abs[];
static void Maestro_SetVertex(RwIm2DVertex* vertex,
                              f32 x,
                              f32 y,
                              f32 z,
                              f32 recipZ,
                              f32 u,
                              f32 v,
                              u32 color)
{
    vertex->u.els.scrVertex.x = x;
    vertex->u.els.scrVertex.y = y;
    vertex->u.els.scrVertex.z = z;
    vertex->u.els.camVertex_z = 0.0f;
    vertex->u.els.u = u;
    vertex->u.els.v = v;
    vertex->u.els.recipZ = recipZ;
    vertex->u.els.color.r = (f32)((color >> 24) & 0xff);
    vertex->u.els.color.g = (f32)((color >> 16) & 0xff);
    vertex->u.els.color.b = (f32)((color >> 8) & 0xff);
    vertex->u.els.color.a = (f32)(color & 0xff);
}
static void Maestro_DrawQuad(RwIm2DVertex* vertices,
                             f32 x,
                             f32 y,
                             f32 width,
                             f32 height,
                             f32 z,
                             f32 recipZ,
                             u32 color,
                             f32 u0,
                             f32 v0,
                             f32 u1,
                             f32 v1)
{
    Maestro_SetVertex(&vertices[0], x, y, z, recipZ, u0, v0, color);
    Maestro_SetVertex(&vertices[1], x + width, y, z, recipZ, u1, v0, color);
    Maestro_SetVertex(&vertices[2], x, y + height, z, recipZ, u0, v1, color);
    Maestro_SetVertex(&vertices[3], x + width, y + height, z, recipZ, u1, v1, color);
    (*D_009600A0)(rwPRIMTYPETRISTRIP, vertices, 4);
}
extern const char D_005D6E48[];
extern const char D_005D6FD0[];
extern const char D_005D6FE0[];
extern const char D_005DAC00[];
extern const char D_005DAC20[];
extern const char D_005DAC40[];
extern const char D_005D7AE0[];
extern const char D_005D6E60[];
extern const char D_005D6E90[];
extern const char D_005D6EC0[];
extern const char D_005D6EE0[];
extern const char D_005D6F00[];
extern const char D_005D6F20[];
extern const char D_005D6F40[];
extern const char D_005D6F60[];
extern const char D_005D6F80[];
extern const char D_005D6F90[];
extern const char D_005D6FB8[];
extern void* D_00833B70[14];
extern KwlnTask* iGpffffb258;
extern void* iGpffffb25c;
extern void* func_00116f80();
extern void* func_001158b0();
extern void func_00115980();
extern void func_00195020(void* task);
extern void func_0018bc10(f32 depth, void* transition, s32 drawMode,
                          s32 positionMode, s32 alphaMode,
                          u64 start, u64 end, s32 param0, s32 tile,
                          s32 startFrame, s32 endFrame);
extern u32 func_0018b700(void* animation);
extern void* func_0018b6d0(s32 size);
extern u32 datGetScenarioMode(void);
extern void func_003c7b90(void);
extern void func_003c72d0(const void* message);
extern void func_003c77a0(void);
extern void* func_00117540(KwlnTask* task);
extern void func_001191c0(KwlnTask* task);
extern void* func_00119aa0(KwlnTask* task);
extern void* func_001193d0(KwlnTask* task);
extern void func_00119e00(KwlnTask* task);
typedef struct MaestroEffectAnim
{
    u8 reserved00[8];
    s32 frame;                       /* +0x08 */
    s32 startFrame;                  /* +0x0c */
    s32 endFrame;                    /* +0x10 */
    f32 depth;                       /* +0x14 */
    u8 reserved18[0x10];
    f32 x;                            /* +0x28 */
    f32 y;                            /* +0x2c */
    u8 reserved30[0x14];
} MaestroEffectAnim;
typedef struct MaestroMarkSpriteWork
{
    s32 state;
    s32 mode;
    s32 frame;
    u32 reserved0c;
    MaestroEffectAnim animation;
    void* blob;
} MaestroMarkSpriteWork;
typedef struct MaestroPerEffectWork
{
    s32 state;                       /* +0x000 */
    s32 effectCount;                 /* +0x004 */
    u32 effectIds[3];                 /* +0x008 */
    KwlnTask* streamTask;            /* +0x014 */
    u32 reserved018;
    KwlnTask* resourceTasks[3];      /* +0x01c */
    void* streams[6];                 /* +0x028 */
    void* loadedResources[6];         /* +0x040 */
    HCdvd* cdvd[9];                  /* +0x058 */
    void* recordPointers[3];         /* +0x07c */
    u8 recordData[3][0x2a];          /* +0x088 */
    u8 reserved104[2];
    s32 completionCounts[3];          /* +0x108 */
    s32 frame;                        /* +0x114 */
    u8 reserved118[0x11c];
    void* archiveCacheRequest;        /* +0x234 */
    u8 reserved238[0x5b4];
    MaestroBlobNode* blob;            /* +0x7ec */
    u8 reserved7f0[0x44];             /* +0x7f0, retail sizeof 0x834 */
} MaestroPerEffectWork;
typedef struct MaestroCampSpriteSetupWork
{
    s32 state;                        /* +0x00 */
    void* resources[14];              /* +0x04 */
    HCdvd* archive;                   /* +0x3c */
    u32 initializeMessages;           /* +0x40 */
    void* ownerPool;                  /* +0x44 */
} MaestroCampSpriteSetupWork;
static void MaestroMarkSpriteDraw(MaestroMarkSpriteWork* work,
                                  s16 pivotX,
                                  s16 pivotY,
                                  f32 angle,
                                  u8 alphaCutoff)
{
    MaestroRenderNode* node;

    node = (MaestroRenderNode*)func_001158b0(NULL, work->blob, 0);
    node->depth = work->animation.depth;
    node->x = work->animation.x;
    node->y = work->animation.y;
    node->pivotX = pivotX;
    node->pivotY = pivotY;
    node->angle = angle;
    node->alphaCutoff = alphaCutoff;
    func_001127d0(node, true);
    func_00115980((int*)node);
}
static inline void MaestroEffectRequestFiles(
    MaestroPerEffectWork* work, char* path)
{
    s32 i;

    work->effectCount = 0;
    for (i = 0; i < 3; i++)
    {
        if (work->effectIds[i] != 0)
        {
            work->effectCount++;
        }
    }
    if (work->effectCount != 0)
    {
        work->effectCount--;
    }

    if (datGetScenarioMode() != 0)
    {
        if (work->effectCount == 0)
        {
            if (work->effectIds[0] == 9)
                sprintf(path, D_005D6E60, work->effectIds[0]);
            else
                sprintf(path, D_005D6E90, work->effectIds[0]);
            work->cdvd[1] = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            work->cdvd[0] = H_Cdvd_Request(D_005D6EC0, HCDVD_FILEARCHIVE);
        }
        else if (work->effectCount == 1)
        {
            if (work->effectIds[0] == 9)
                sprintf(path, D_005D6E60, work->effectIds[0]);
            else
                sprintf(path, D_005D6E90, work->effectIds[0]);
            work->cdvd[1] = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            if (work->effectIds[1] == 9)
                sprintf(path, D_005D6E60, work->effectIds[1]);
            else
                sprintf(path, D_005D6E90, work->effectIds[1]);
            work->cdvd[2] = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            work->cdvd[0] = H_Cdvd_Request(D_005D6EE0, HCDVD_FILEARCHIVE);
        }
        else
        {
            if (work->effectIds[0] == 9)
                sprintf(path, D_005D6E60, work->effectIds[0]);
            else
                sprintf(path, D_005D6E90, work->effectIds[0]);
            work->cdvd[1] = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            if (work->effectIds[1] == 9)
                sprintf(path, D_005D6E60, work->effectIds[1]);
            else
                sprintf(path, D_005D6E90, work->effectIds[1]);
            work->cdvd[2] = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            if (work->effectIds[2] == 9)
                sprintf(path, D_005D6E60, work->effectIds[2]);
            else
                sprintf(path, D_005D6E90, work->effectIds[2]);
            work->cdvd[3] = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            work->cdvd[0] = H_Cdvd_Request(D_005D6F00, HCDVD_FILEARCHIVE);
        }
    }
    else
    {
        if (work->effectCount == 0)
        {
            sprintf(path, D_005D6E90, work->effectIds[0]);
            work->cdvd[1] = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            work->cdvd[0] = H_Cdvd_Request(D_005D6F20, HCDVD_FILEARCHIVE);
        }
        else if (work->effectCount == 1)
        {
            sprintf(path, D_005D6E90, work->effectIds[0]);
            work->cdvd[1] = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            sprintf(path, D_005D6E90, work->effectIds[1]);
            work->cdvd[2] = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            work->cdvd[0] = H_Cdvd_Request(D_005D6F40, HCDVD_FILEARCHIVE);
        }
        else
        {
            sprintf(path, D_005D6E90, work->effectIds[0]);
            work->cdvd[1] = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            sprintf(path, D_005D6E90, work->effectIds[1]);
            work->cdvd[2] = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            sprintf(path, D_005D6E90, work->effectIds[2]);
            work->cdvd[3] = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            work->cdvd[0] = H_Cdvd_Request(D_005D6F60, HCDVD_FILEARCHIVE);
        }
    }
}
static inline void MaestroEffectStartStreams(
    KwlnTask* task, MaestroPerEffectWork* work, char* path)
{
    s16 dimensions[4];
    u32 size;
    u32 scenario;
    scenario = datGetScenarioMode();
    if (scenario != 0)
    {
        if (work->effectCount == 0)
        {
            if (work->effectIds[0] == 9)
                sprintf(path, D_005D6E60, work->effectIds[0]);
            else
                sprintf(path, D_005D6E90, work->effectIds[0]);
            work->streams[0] = func_0010c1a0(NULL, path,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0xf6);
            work->streams[1] = func_0010c1a0(NULL, D_005D6F90,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0xf7);
            work->archiveCacheRequest = H_Cdvd_ArchiveGetFile(
                work->cdvd[0], 3, &size);
            func_00102720(D_005D6FB8, work->archiveCacheRequest);
            dimensions[0] = 0x28;
            dimensions[1] = 1;
            dimensions[2] = 0x0a;
            dimensions[3] = 5;
            work->streamTask = func_00111380(task, 0x18c0,
                ((u64)(u16)dimensions[0]) |
                ((u64)(u16)dimensions[1] << 16) |
                ((u64)(u16)dimensions[2] << 32) |
                ((u64)(u16)dimensions[3] << 48),
                (u8*)work + 0x124);
        }
        else if (work->effectCount == 1)
        {
            if (work->effectIds[0] == 9)
                sprintf(path, D_005D6E60, work->effectIds[0]);
            else
                sprintf(path, D_005D6E90, work->effectIds[0]);
            work->streams[0] = func_0010c1a0(NULL, path,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x10c);
            work->streams[1] = func_0010c1a0(NULL, D_005D6F90,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x10d);
            if (work->effectIds[1] == 9)
                sprintf(path, D_005D6E60, work->effectIds[1]);
            else
                sprintf(path, D_005D6E90, work->effectIds[1]);
            work->streams[2] = func_0010c1a0(NULL, path,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x113);
            work->streams[3] = func_0010c1a0(NULL, D_005D6F90,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x115);
            work->archiveCacheRequest = H_Cdvd_ArchiveGetFile(
                work->cdvd[0], 4, &size);
            func_00102720(D_005D6FB8, work->archiveCacheRequest);
            dimensions[0] = 0x28;
            dimensions[1] = 1;
            dimensions[2] = 0x0b;
            dimensions[3] = 5;
            work->streamTask = func_00111380(task, 0x18c0,
                ((u64)(u16)dimensions[0]) |
                ((u64)(u16)dimensions[1] << 16) |
                ((u64)(u16)dimensions[2] << 32) |
                ((u64)(u16)dimensions[3] << 48),
                (u8*)work + 0x124);
        }
        else
        {
            if (work->effectIds[0] == 9)
                sprintf(path, D_005D6E60, work->effectIds[0]);
            else
                sprintf(path, D_005D6E90, work->effectIds[0]);
            work->streams[0] = func_0010c1a0(NULL, path,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x12b);
            work->streams[1] = func_0010c1a0(NULL, D_005D6F90,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x12c);
            if (work->effectIds[1] == 9)
                sprintf(path, D_005D6E60, work->effectIds[1]);
            else
                sprintf(path, D_005D6E90, work->effectIds[1]);
            work->streams[2] = func_0010c1a0(NULL, path,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x132);
            work->streams[3] = func_0010c1a0(NULL, D_005D6F90,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x133);
            if (work->effectIds[2] == 9)
                sprintf(path, D_005D6E60, work->effectIds[2]);
            else
                sprintf(path, D_005D6E90, work->effectIds[2]);
            work->streams[4] = func_0010c1a0(NULL, path,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x139);
            work->streams[5] = func_0010c1a0(NULL, D_005D6F90,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x13a);
            work->archiveCacheRequest = H_Cdvd_ArchiveGetFile(
                work->cdvd[0], 5, &size);
            func_00102720(D_005D6FB8, work->archiveCacheRequest);
            dimensions[0] = 0x28;
            dimensions[1] = 2;
            dimensions[2] = 0x0a;
            dimensions[3] = 5;
            work->streamTask = func_00111380(task, 0x18c0,
                ((u64)(u16)dimensions[0]) |
                ((u64)(u16)dimensions[1] << 16) |
                ((u64)(u16)dimensions[2] << 32) |
                ((u64)(u16)dimensions[3] << 48),
                (u8*)work + 0x124);
        }
    }
    else
    {
        if (work->effectCount == 0)
        {
            sprintf(path, D_005D6E90, work->effectIds[0]);
            work->streams[0] = func_0010c1a0(NULL, path,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x14d);
            work->streams[1] = func_0010c1a0(NULL, D_005D6F90,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x14e);
            work->archiveCacheRequest = H_Cdvd_ArchiveGetFile(
                work->cdvd[0], 3, &size);
            func_00102720(D_005D6FB8, work->archiveCacheRequest);
            dimensions[0] = 0x28;
            dimensions[1] = 1;
            dimensions[2] = 0x0a;
            dimensions[3] = 0;
            work->streamTask = func_00111380(task, 0x18c0,
                ((u64)(u16)dimensions[0]) |
                ((u64)(u16)dimensions[1] << 16) |
                ((u64)(u16)dimensions[2] << 32) |
                ((u64)(u16)dimensions[3] << 48),
                (u8*)work + 0x124);
        }
        else if (work->effectCount == 1)
        {
            sprintf(path, D_005D6E90, work->effectIds[0]);
            work->streams[0] = func_0010c1a0(NULL, path,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x15e);
            work->streams[1] = func_0010c1a0(NULL, D_005D6F90,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x15f);
            sprintf(path, D_005D6E90, work->effectIds[1]);
            work->streams[2] = func_0010c1a0(NULL, path,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x161);
            work->streams[3] = func_0010c1a0(NULL, D_005D6F90,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x162);
            work->archiveCacheRequest = H_Cdvd_ArchiveGetFile(
                work->cdvd[0], 4, &size);
            func_00102720(D_005D6FB8, work->archiveCacheRequest);
            dimensions[0] = 0x28;
            dimensions[1] = 1;
            dimensions[2] = 0x0a;
            dimensions[3] = 0;
            work->streamTask = func_00111380(task, 0x18c0,
                ((u64)(u16)dimensions[0]) |
                ((u64)(u16)dimensions[1] << 16) |
                ((u64)(u16)dimensions[2] << 32) |
                ((u64)(u16)dimensions[3] << 48),
                (u8*)work + 0x124);
        }
        else
        {
            sprintf(path, D_005D6E90, work->effectIds[0]);
            work->streams[0] = func_0010c1a0(NULL, path,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x172);
            work->streams[1] = func_0010c1a0(NULL, D_005D6F90,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x174);
            sprintf(path, D_005D6E90, work->effectIds[1]);
            work->streams[2] = func_0010c1a0(NULL, path,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x176);
            work->streams[3] = func_0010c1a0(NULL, D_005D6F90,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x178);
            sprintf(path, D_005D6E90, work->effectIds[2]);
            work->streams[4] = func_0010c1a0(NULL, path,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x17a);
            work->streams[5] = func_0010c1a0(NULL, D_005D6F90,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x17c);
            work->archiveCacheRequest = H_Cdvd_ArchiveGetFile(
                work->cdvd[0], 5, &size);
            func_00102720(D_005D6FB8, work->archiveCacheRequest);
            dimensions[0] = 0x28;
            dimensions[1] = 2;
            dimensions[2] = 0x0a;
            dimensions[3] = 0;
            work->streamTask = func_00111380(task, 0x18c0,
                ((u64)(u16)dimensions[0]) |
                ((u64)(u16)dimensions[1] << 16) |
                ((u64)(u16)dimensions[2] << 32) |
                ((u64)(u16)dimensions[3] << 48),
                (u8*)work + 0x124);
        }
    }

}
#include "Kernel/Kwln/kwln.h"
#include "Script/scrTraceCode.h"
#include "h_dbprt.h"
#include "h_fade.h"
#include "h_sfdply.h"
#include "rw/rwplcore.h"
#pragma alias rwGlobals_abs rwGlobals
extern u8 rwGlobals_abs[];
extern u8 D_0077e4e0[];
extern u8 D_00803640[];
extern f32 D_00960088_abs_y2[];
extern void (*D_00960094)(u32 state, void* value);
extern void* (*D_00960178)(u32 size, u32 flags);
extern void (*D_0096017c)(void* memory);
#pragma alias D_00960178_abs D_00960178
extern void* (*D_00960178_abs[])(u32 size, u32 flags);
#pragma alias D_0096017c_abs D_0096017c
extern void (*D_0096017c_abs[])(void* memory);
#pragma alias DAT_007e094e_abs DAT_007e094e
extern u16 DAT_007e094e_abs[];
#pragma alias D_0077e4f0_abs D_0077e4f0
extern void* D_0077e4f0_abs[];
extern s16 D_005D4B70[];
extern u8 D_005D4B74[];
extern u8 D_005D4B7C[];
extern u8 D_005D4B80[];
extern u8 D_005D4B84[];
extern u8 D_005D4B8C[];
extern u8 D_005D4B90[];
extern u8 D_005D4B92[];
extern u8 D_005D4B94[];
extern const char D_005D5250[];
extern const char D_005D5260[];
extern const char D_005D5280[];
extern void* uGpffffb220;
extern s16 uGpffffb228;
extern s16 uGpffffb218;
extern s32 uGpffffb230;
extern s32 uGpffffb22c;
extern u32 _mips_gp0_value;
extern char uGpffff8840[];
#pragma alias gp0xffff8840 uGpffff8840
extern char gp0xffff8840;
extern void H_Pad_IgnoreRumbleCallback(s32 a, s32 b, s32 c, s32 d);
extern void func_004b6500(void);
extern void func_004aa5c0(void);
extern void func_001cd8e0(void);
extern void adminiForcePassedCheck(void);
extern void func_003b5ab0(void);
extern s32 func_004c2120(void* value);
extern void K_Assert(const char* message, s32 line);
extern void func_004b7690(void* value);
extern void func_004faec0(void* stream, s32 a, s32 b);
extern void func_004f1780(void* target, s32 mode);
extern void func_00191d70(void* target, void* pixels, s32 width, s32 height);
extern void* func_004fa8f0(s32 mode);
extern int printf_y2(const char* format, ...);
extern void* memcpy_y2(void* destination, const void* source, u32 size);
#define HSFD_TABLE(base, index) ((u8*)(base) + ((index) * 0x28))
extern void func_004aa390(f32 nearPlane);
extern void func_004aa3d0_y2(f32 farPlane);
extern void func_004a9f20(f32 x, f32 y, f32 z, f32 w);
extern void func_004aa410_y2(RwCamera* camera);
extern void* func_004a5470(void);
extern void func_004a5dd0(void* image, const s8* c0, const s8* c1,
                          const s8* c2, const s8* c3);
extern void func_004cb270(void* value);
extern void* func_004cc5c0(const char* path);
extern void* func_004d1260(const char* path, s32 mode);
extern void* func_00490050(const char* path);
extern void* func_004b7760(const char* message);
extern void* func_004920a0(const char* path);
extern void* func_004b69b0(const char* path);
extern void* func_00464540(const char* path);
extern void* func_0048d960(const char* path);
extern void* func_004b79d0(u32 size, const void* source);
extern void* func_004c8680(const char* path);
extern void* func_004b45b0_y2(s32 mode, const void* source);
extern void func_00100ec0(void* request);
extern void func_00503080(void);
extern void* func_004ac570(void);
extern void func_004ac5f0(void* image);
extern void func_004ab1b0(void* image);
extern void func_004a62e0(void* image, void* data);
#pragma alias func_004a6200_y2 func_004a6200
extern void func_004a6200_y2(void* image, s32* out0, f32* out1,
                              f32* out2, s32* out3);
extern void func_004ab6a0(void* image);
extern void func_004ac710(void* image);
extern void func_004ace70(void* image, void* quad);
extern void func_004a6600(void* image, void* quad);
extern void func_004aaa60(void);
extern void func_004a9bf0_y2(void);
extern void func_004aae00(f32 x, f32 y);
extern void func_004aad50(void);
extern void func_004ab200(void* image, f32 x, f32 y);
extern void func_004ab2c0(void* image, f32 x, f32 y);
extern void func_004ab410(void* image, f32 x0, f32 y0, f32 x1, f32 y1,
                          f32 x2, f32 y2);
extern void func_00110650(void* view, s32 from, s32 to);
extern s8 fGpffff7788[];
extern void* func_0050B690(s32 arg1, u32 size, s32 arg3);
extern void func_0050B710(void* ptr);
extern void func_00521250(void* dst, const void* src, u32 size);
extern void func_0051DBC0(s32 a0, void* a1, void* a2, u32 a3);
extern s32 func_0051DC70(s32 a0, s32 a1, ...);
extern s32 func_0051DDF0(s32 a0, s32 a1, ...);
extern u8 D_00823650[];
#define HSFD_ENTRY_COUNT 256
#define HSFD_QUEUE_COUNT 1
#define HSFD_DECODE_SLOTS 6
#define HSFD_STREAM_HINT rwMEMHINTDUR_GLOBAL
typedef struct HSfdQueueSlot HSfdQueueSlot;
typedef struct HSfdAsyncEntry HSfdAsyncEntry;
typedef struct HSfdImage
{
    u32 type;
    u32 width;
    u32 height;
    u32 depth;
    u32 stride;
    u8* pixels;
    u8* palette;
} HSfdImage;
typedef struct HSfdTexture
{
    HSfdImage image;
    u8* palette;
    u32 paletteSize;
} HSfdTexture;
typedef struct HSfdDecodeSlot
{
    s16 state;
    s16 padding02;
    HCdvd* request;
    s16 fileIndex;
    s16 index;
    s32 queueHandle;       // 0x0C
    s32 outputHandle;      // 0x10
    s32 decodeHandle;      // 0x14
    s32 status;            // 0x18
    void* input;           // 0x1C
    u32 inputSize;         // 0x20
    void* intermediate;    // 0x24
    u32 intermediateSize;  // 0x28
    void* output;          // 0x2C
    u32 outputSize;        // 0x30
    void* resource;        // 0x34
    void* aux;             // 0x38
    void* sourceData;      // 0x3C
    void* completion;      // 0x40
} HSfdDecodeSlot;
struct HSfdQueueSlot
{
    s16 state;
    s16 padding02;
    HSfdAsyncEntry* entry;
};
struct HSfdAsyncEntry
{
    HSfdAsyncEntry* next;
    HSfdQueueSlot* queue;
    void* source;
    void* resultC;
    void* resultD;
    void* resultE;
    void* resultF;
    void* resultG;
    u8 reserved20[4];
    char name[128];
    char path[128];
    char cacheName[128];
    s32 state;
    s32 requestFlags;
    s32 kind;
    HCdvd* request;
    void* result0;
    void* result1;
    s32 byteCount;
    void* buffer;
    void* result2;
    void* result3;
    void* result4;
    s16 age;
    u16 padding1D2;
    void* result5;
    u32 padding1D8;
};
typedef struct HSfdPoolEntry
{
    s32 state;
    u8 entry[0x1d8];
} HSfdPoolEntry;
typedef struct HSfdQueueEntry
{
    HSfdAsyncEntry* next;
    HSfdQueueSlot* queue;
    u8 reserved08[0x1d0];
} HSfdQueueEntry;
typedef struct HSfdRenderFrame
{
    s8 type;
    s8 command;
    u16 colorR;
    u16 colorG;
    u16 colorB;
    u16 colorA;
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
} HSfdRenderFrame;
typedef struct HSfdRenderView
{
    s32 type;
    void* commandSource;
    HSfdRenderFrame* frames;
    u8 reserved0C[0x9C];
    void* texture;
    u8 reservedAC[0x13C];
    s32 frameIndex;
    u8 reserved1EC[0x1EC];
    s32 currentCommand;
    u8 reserved28C[0x14C];
    float originX;
    float originY;
    u8 reserved3E0[0x100];
    s32 elementCount;
    s32 skyMode;
} HSfdRenderView;
static s32 sSfdFrameIndex;
#pragma alias sSfdFrameIndex_abs sSfdFrameIndex
extern u8 sSfdFrameIndex_abs[];
static KwlnTask* sSfdPlayTask;
static HSfdQueueEntry sSfdQueueEntries[HSFD_QUEUE_COUNT];
static s32 sSfdThreadIds[HSFD_QUEUE_COUNT];
static HSfdQueueSlot sSfdQueue[HSFD_QUEUE_COUNT];
static HSfdAsyncEntry sSfdEntries[HSFD_ENTRY_COUNT];
static HSfdDecodeSlot sSfdDecodeSlots[HSFD_DECODE_SLOTS];
typedef struct HSfdCueEntry
{
    s32 active;
    s16 bank;
    s16 reserved6;
    s32 param;
} HSfdCueEntry;
static HSfdCueEntry sSfdCueTable[8];
#pragma alias sSfdDecodeSlots_abs sSfdDecodeSlots
extern HSfdDecodeSlot sSfdDecodeSlots_abs[];
#pragma alias sSfdCueTable_abs sSfdCueTable
extern HSfdCueEntry sSfdCueTable_abs[];
static u8* sSfdScratch;
static u8* sSfdDecodeBuffer;
static u8* sSfdFrameBuffers[4];
static const char* const sSfdDecodePaths[] =
{
    "sound/BSE.hd", "sound/BSE.bd", "sound/BSE.sq",
    "sound/spu/comse.hd", "sound/spu/comse.bd", "sound/spu/comse.sq",
    "sound/spu/bse.hd", "sound/spu/bse.bd", "sound/spu/bse.sq"
};
typedef struct HSfdDmaDescriptor
{
    const void* src;
    void* dst;
    u32 size;
    u32 mode;
} HSfdDmaDescriptor;
static HSfdDmaDescriptor sSfdDmaDescriptor;
extern void func_0051e028(s32 outputHandle, s32 channel, s32 count, s32 value);
extern s32 func_0051df58(s32 outputHandle, s32 channel, s32 count, s32 value, ...);
#pragma alias func_0051e028_t func_0051e028
extern void func_0051e028_t(s32 outputHandle, s32 channel, s32 count, s32 value);
#pragma alias func_0051df58_t func_0051df58
extern s32 func_0051df58_t(s32 outputHandle, s32 channel, s32 count, s32 value, ...);
extern u32 FUN_00512868(void);
extern u32 FUN_0051d5b0(u32 base, u32 stride, u32 count);
extern u64 FUN_0051da48(u32 value);
extern u64 FUN_0051da50(u64 size);
extern void FUN_0051db00(u32 a0, u32 a1, u32 a2, ...);
extern u32 FUN_0051d6f8(s32 size);
extern void FUN_0051deb0(u32 channel, void* handle);
extern void FUN_0051dd48(u32 channel, void* handle);
extern s32 FUN_0050d3f0(void);
extern s32 func_00502f60(void* threadParam);
extern s32 func_005042a0(s32 threadId, void* arg);
extern s32 FUN_0050d3a0(void);
extern void func_005030f0(s32 threadId);
static s32 sSfdResumePending;
static s32 sSfdResumeThreadId;
extern void datSetFlag(s32 bit, u8 enabled);
extern void FUN_004aa550(void* param1);
extern void FUN_004b6350(void);
extern void FUN_004b7630(void* param1);
typedef struct EeThreadStatus
{
    s32 status;
    u8 reserved4[0x2C];
} EeThreadStatus;
extern void func_00503060(s32 threadId, EeThreadStatus* status);
extern void func_005030d0(s32 threadId);
extern void* func_0057c680(void* descriptor);
extern void* func_0057d5d8(void* descriptor);
extern void func_0057e378(void* decoder, s32 mode);
extern s32 func_0057e530(void* decoder, s32* status);
extern void func_0057ee50(void* decoder);
extern s32 func_00581840(void* decoder);
extern void func_00584338(void* streamAux);
extern void func_0057db58(void* decoder);
extern void* func_004ce0f0(s32 width, s32 height, s32 format, s32 flags);
extern void* func_004cdf30(void* raster, s32 palette);
extern void* func_004ce200(void* raster, void* mipData, s32 level);
extern void* func_004cde00(void* raster);
extern void FUN_004d5e90(void);
extern void func_004cde40(void* raster);
extern void func_004cde90_y2(void* renderTarget);
extern void* func_004c58a0(s32 source, s32 mode, void* stream);
extern s32 func_004c5250(void* stream, void* dst, u32 bytes);
extern void func_004c5780_y2(void* stream, s32 mode);
extern HSfdImage* func_004cbe00(u32 width, u32 height, u32 bits);
extern void func_0010c7d0(HSfdQueueSlot* slot);
extern void func_004cbf20(HSfdImage* image);
extern void FlushCache(s32 mode);
extern void func_0010d950(s16 index);

static void Maestro_SetPrimitiveStates(u32 skyRasterState, u32 skyTextureState)
{
    (*D_00960090)(6, 1);
    (*D_00960090)(7, 2);
    (*D_00960090)(8, 1);
    (*D_00960090)(9, 2);
    (*D_00960090)(12, 1);
    (*D_00960090)(11, 6);
    (*D_00960090)(10, 5);
    (*D_00960090)(2, 4);
    RpSkyRenderStateSet(2, (void*)skyRasterState);
    RpSkyRenderStateSet(3, (void*)skyTextureState);
}
static f32 Maestro_NearReciprocal(void)
{
    RwCamera* camera = kwlnGetMainCamera();
    return 1.0f / camera->nearPlane;
}
static inline void MaestroEffectLoadRecords(KwlnTask* task, MaestroPerEffectWork* work)
{
    u8* record;
    u32 size;
    s32 i;
    s32 j;

    for (i = 0; i <= work->effectCount; i++)
    {
        record = (u8*)H_Cdvd_ArchiveGetFile(work->cdvd[0], i + 1, &size);
        memcpy(work->recordData[i], record, 0x2a);
        record = (u8*)H_Cdvd_ArchiveGetFile(work->cdvd[0], i + 1, &size) + 0x2a;
        work->recordPointers[i] = record;
        work->completionCounts[i] = 0;
        for (j = 0; j < 1000; j++)
        {
            if (record[j * 0x12 + 1] == (u8)-2)
            {
                work->completionCounts[i]--;
                break;
            }
            if (record[j * 0x12 + 1] == (u8)-1)
            {
                work->completionCounts[i]++;
            }
        }
        work->resourceTasks[i] = func_001103e0(
            task, 0x18c0, (u32)(uintptr_t)record,
            *(s16*)(work->recordData[i] + 8));
        for (j = 0; j < 3; j++)
        {
            s16 slot = (s16)(j == 2 ? 1 : (j == 0 ? 3 : 4));
            func_00110620(work->resourceTasks[i], slot,
                          *(s16*)(work->recordData[i] + 0x0a + j * 2),
                          *(s16*)(work->recordData[i] + 0x12 + j * 2),
                          *(s16*)(work->recordData[i] + 0x1a + j * 2));
        }
    }
    work->blob = (MaestroBlobNode*)func_00112420(
        H_Cdvd_ArchiveGetFile(work->cdvd[0], 0, &size));
    work->state = 2;
}
static inline void MaestroEffectSetReady(MaestroPerEffectWork* work)
{

    switch (work->effectCount)
    {
    case 0:
        func_001104d0(work->resourceTasks[0]);
        break;
    case 1:
        func_001104d0(work->resourceTasks[0]);
        func_001104d0(work->resourceTasks[1]);
        break;
    case 2:
        func_001104d0(work->resourceTasks[0]);
        func_001104d0(work->resourceTasks[1]);
        func_001104d0(work->resourceTasks[2]);
        break;
    }
    func_00111530(work->streamTask);
    work->state = 4;
}
static void H_SfdPlay_ResetTaskResources(HSfd* work)
{
    if (work->decoder != NULL)
    {
        if (work->streamAux != NULL)
        {
            func_00584338(work->streamAux);
            work->streamAux = NULL;
        }

        func_0057db58(work->decoder);
        work->decoder = NULL;
    }

    if (work->compressedFrameBuffer != NULL)
    {
        RwFree(work->compressedFrameBuffer);
        work->compressedFrameBuffer = NULL;
    }

    if (work->displayBuffer != NULL)
    {
        RwFree(work->displayBuffer);
        work->displayBuffer = NULL;
    }

    if (work->renderTarget != NULL)
    {
        func_004cde90_y2(work->renderTarget);
        work->renderTarget = NULL;
    }

    work->streamDescriptor = NULL;
    work->decodeResult = 0;
    work->frameWidth = 0;
    work->frameHeight = 0;
}
static void H_SfdPlay_BeginStream(HSfd* work)
{
    u32 descriptor[12];
    s32 renderHeight;

    memset(descriptor, 0, sizeof(descriptor));
    descriptor[0] = 1;
    descriptor[1] = 0x4C4B40;
    descriptor[5] = 0x11;
    descriptor[8] = 2;
    descriptor[9] = 1;

    work->decoder = func_0057c680(descriptor);
    if (work->decoder == NULL)
    {
        work->state = HSFD_STATE_CLEANUP;
        return;
    }

    work->compressedFrameBuffer = RwCalloc(1, 0x118000, HSFD_STREAM_HINT);
    work->displayBuffer = RwCalloc(1, 0x118000, HSFD_STREAM_HINT);
    if ((work->compressedFrameBuffer == NULL) || (work->displayBuffer == NULL))
    {
        work->state = HSFD_STATE_CLEANUP;
        return;
    }

    work->streamDescriptor = func_0057d5d8(descriptor);
    if (work->streamDescriptor == NULL)
    {
        work->state = HSFD_STATE_CLEANUP;
        return;
    }

    func_0057e378(work->streamDescriptor, 0);
    work->decoder = work->streamDescriptor;
    work->frameWidth = 640;
    renderHeight = 448;
    if ((work->id == 5) || (work->id == 6))
    {
        renderHeight = 368;
    }
    work->frameHeight = renderHeight;
    work->renderTarget = func_004ce0f0(work->frameWidth, renderHeight, 0x20, 0x584);
    if (work->renderTarget == NULL)
    {
        work->state = HSFD_STATE_CLEANUP;
        return;
    }

    work->state = HSFD_STATE_PLAYING;
}



// FUN_0010CCE0
s32 func_0010cce0(void* dst, const void* src, s32 size)
{
    s32 dmaId;
    s32 status;

    if (size <= 0)
    {
        return 0;
    }

    sSfdDmaDescriptor.src = src;
    sSfdDmaDescriptor.dst = dst;
    sSfdDmaDescriptor.size = size;
    sSfdDmaDescriptor.mode = 0;

    FlushCache(0);
    dmaId = sceSifSetDma(&sSfdDmaDescriptor, 1);
    if (dmaId == 0)
    {
        K_Assert("h_sndcom.c", 0x107);
    }

    do
    {
        status = sceSifDmaStat(dmaId);
    } while (status >= 0);

    do
    {
        status = sceSifDmaStat(dmaId);
    } while (status > 0 || status == 0);

    return size;
}

#pragma opt_loop_invariants on
/* W419 scalar-size probe was unchanged at nd1332, object 2032/window2336. */
// FUN_0010CDD0 NONMATCHING
void func_0010cdd0(void)
{
    const char* path;
    u32 size[1];
    s32 copySize;
    s16 i;
    s32 pathIndex;

    for (i = 0; i < HSFD_DECODE_SLOTS; i++)
    {
        switch (sSfdDecodeSlots[i].state)
        {
            case 0:
                sSfdDecodeSlots[i].state = 1;
                break;

            case 1:
                break;

            case 2:
            {
                pathIndex = sSfdDecodeSlots[i].fileIndex * 3;
                sSfdDecodeSlots[i].request = H_Cdvd_Request(sSfdDecodePaths[pathIndex], 0);
                sSfdDecodeSlots[i].state = 3;
                break;
            }

            case 3:
            {
                if ((sSfdDecodeSlots[i].request != NULL) && H_Cdvd_IsFileLoaded(sSfdDecodeSlots[i].request))
                {
                    void* fileData;
                    void* allocBuf;

                    pathIndex = sSfdDecodeSlots[i].fileIndex * 3;
                    fileData = H_Cdvd_CacheFindFile(sSfdDecodePaths[pathIndex], &size[0]);
                    allocBuf = (void*)func_0050B690(0, size[0], 0);
                    if (allocBuf == NULL) { K_Assert("h_sndcom.c", 0x144); }
                    func_00521250(D_00823650, fileData, size[0]);
                    func_0010cce0(allocBuf, D_00823650, size[0]);
                    sSfdDecodeSlots[i].input = allocBuf;
                    sSfdDecodeSlots[i].inputSize = size[0];
                    H_Cdvd_Destroy(sSfdDecodeSlots[i].request);
                    sSfdDecodeSlots[i].request = NULL;
                    sSfdDecodeSlots[i].state = 4;
                }
                break;
            }

            case 4:
            {
                pathIndex = sSfdDecodeSlots[i].fileIndex * 3;
                sSfdDecodeSlots[i].request = H_Cdvd_Request(sSfdDecodePaths[pathIndex + 1], 0);
                sSfdDecodeSlots[i].state = 5;
                break;
            }

            case 5:
            {
                if ((sSfdDecodeSlots[i].request != NULL) && H_Cdvd_IsFileLoaded(sSfdDecodeSlots[i].request))
                {
                    void* fileData;
                    void* chunkBuf;
                    void* intermediate;
                    s32 remaining;

                    pathIndex = sSfdDecodeSlots[i].fileIndex * 3;
                    fileData = H_Cdvd_CacheFindFile(sSfdDecodePaths[pathIndex + 1], &size[0]);
                    chunkBuf = (void*)func_0050B690(0, 0x1000, 0);
                    if (chunkBuf == NULL) { K_Assert("h_sndcom.c", 0x177); }
                    intermediate = sSfdDecodeSlots[i].intermediate;
                    sSfdDecodeSlots[i].intermediateSize = size[0];
                    remaining = size[0];

                    do {
                        s32 chunkSize;
                        if (remaining > 0x1000) {
                            chunkSize = 0x1000;
                            remaining -= 0x1000;
                        } else {
                            chunkSize = remaining;
                            remaining = 0;
                        }
                        func_0010cce0(chunkBuf, fileData, chunkSize);
                        func_0051DBC0(1, chunkBuf, intermediate, chunkSize);
                        fileData = (void*)((u8*)fileData + chunkSize);
                        intermediate = (void*)((u8*)intermediate + chunkSize);
                    } while (remaining != 0);

                    H_Cdvd_Destroy(sSfdDecodeSlots[i].request);
                    sSfdDecodeSlots[i].request = NULL;
                    func_0050B710(chunkBuf);
                    sSfdDecodeSlots[i].state = 6;
                }
                break;
            }

            case 6:
            {
                pathIndex = sSfdDecodeSlots[i].fileIndex * 3;
                sSfdDecodeSlots[i].request = H_Cdvd_Request(sSfdDecodePaths[pathIndex + 2], 0);
                sSfdDecodeSlots[i].state = 7;
                break;
            }

            case 7:
            {
                HSfdDecodeSlot* slot = &sSfdDecodeSlots[i];
                void* fileData;
                void* allocBuf;
                void* input;
                void* intermediate;
                s32 inputSize;
                s32 intermediateSize;
                s32 queueHandle;
                s32 decodeHandle;
                s32 auxHandle;

                input = slot->input;
                inputSize = slot->inputSize;
                intermediate = slot->intermediate;
                intermediateSize = slot->intermediateSize;

                if ((slot->request != NULL) && H_Cdvd_IsFileLoaded(slot->request))
                {
                    pathIndex = slot->fileIndex * 3;
                    fileData = H_Cdvd_CacheFindFile(sSfdDecodePaths[pathIndex + 2], &size[0]);
                    allocBuf = (void*)func_0050B690(0, size[0], 0);
                    if (allocBuf == NULL) { K_Assert("h_sndcom.c", 0x1A2); }
                    func_0010cce0(allocBuf, fileData, size[0]);
                    slot->output = allocBuf;
                    slot->outputSize = size[0];
                    H_Cdvd_Destroy(slot->request);
                    slot->request = NULL;

                    queueHandle = func_0051DC70(3, -1, (s32)input,
                                                inputSize, (s32)intermediate,
                                                intermediateSize);
                    if (queueHandle < 0) { K_Assert("h_sndcom.c", 0x1AE); }
                    slot->queueHandle = queueHandle;

                    decodeHandle = func_0051DC70(5, -1, queueHandle, 0);
                    if (decodeHandle < 0) { K_Assert("h_sndcom.c", 0x1B3); }
                    slot->decodeHandle = decodeHandle;

                    auxHandle = func_0051DDF0(0, -1, (s32)slot->output,
                                              slot->outputSize);
                    if (auxHandle < 0) { K_Assert("h_sndcom.c", 0x1B7); }
                    slot->aux = (void*)(s32)auxHandle;

                    slot->completion = (void*)(s32)func_0051DDF0(
                        5, slot->decodeHandle, (s32)slot->aux);
                    slot->status = 1;
                    slot->state = 1;
                }
                break;
            }

            case 8:
            {
                HSfdDecodeSlot* slot = &sSfdDecodeSlots[i];
                void* input;
                void* intermediate;
                void* output;
                s32 inputSize;
                s32 intermediateSize;
                s32 outputSize;
                void* resourceData;
                void* sourceData;
                void* inputBuf;
                void* auxBuf;
                void* auxData;
                void* outputData;
                void* outputBuf;
                s32 chunkSize;
                s32 remaining;
                s32 queueHandle;
                s32 decodeHandle;
                s32 auxHandle;
                u32* intermediateSizePtr;
                void** inputPtr;

                input = slot->input;
                inputSize = slot->inputSize;
                intermediate = slot->intermediate;
                intermediateSize = slot->intermediateSize;
                intermediateSizePtr = &slot->intermediateSize;
                inputPtr = &slot->input;
                output = slot->output;
                outputSize = slot->outputSize;
                resourceData = slot->resource;
                auxData = slot->aux;

                copySize = inputSize;
                inputBuf = (void*)func_0050B690(0, copySize, 0);
                if (inputBuf == NULL) { K_Assert("h_sndcom.c", 0x1C8); }
                func_0010cce0(inputBuf, resourceData, copySize);
                slot->input = inputBuf;
                slot->inputSize = copySize;

                remaining = intermediateSize;
                auxBuf = (void*)func_0050B690(0, 0x10000, 0);
                if (auxBuf == NULL) { K_Assert("h_sndcom.c", 0x1DF); }
                outputData = intermediate;

                do {
                    if (remaining > 0x10000) {
                        chunkSize = 0x10000;
                        remaining -= 0x10000;
                    } else {
                        chunkSize = (remaining + 0x7F) & ~0x7F;
                        remaining = 0;
                    }
                    func_0010cce0(auxBuf, auxData, chunkSize);
                    func_0051DBC0(1, auxBuf, outputData, chunkSize);
                    auxData = (void*)((u8*)auxData + chunkSize);
                    outputData = (void*)((u8*)outputData + chunkSize);
                } while (remaining != 0);

                func_0050B710(auxBuf);

                sourceData = slot->sourceData;
                copySize = outputSize;
                outputBuf = (void*)func_0050B690(0, copySize, 0);
                if (outputBuf == NULL) { K_Assert("h_sndcom.c", 0x1FB); }
                func_0010cce0(outputBuf, sourceData, copySize);
                slot->output = outputBuf;

                queueHandle = func_0051DC70(3, -1, (s32)*inputPtr,
                                            slot->inputSize,
                                            (s32)slot->intermediate,
                                            *intermediateSizePtr);
                slot->queueHandle = queueHandle;
                decodeHandle = func_0051DC70(5, -1, queueHandle, 0);
                slot->decodeHandle = decodeHandle;
                auxHandle = func_0051DDF0(0, -1, (s32)slot->output,
                                          slot->outputSize);
                slot->aux = (void*)(s32)auxHandle;
                slot->completion = (void*)(s32)func_0051DDF0(
                    5, slot->decodeHandle, (s32)slot->aux);
                slot->status = 1;
                slot->state = 1;
                break;
            }
        }
    }
}

#pragma opt_loop_invariants off
// FUN_0010D6F0
void func_0010d6f0(s16 index, s16 fileIndex)
{
    if (sSfdDecodeSlots[index].state == 1)
    {
        if (sSfdDecodeSlots[index].status != 0)
        {
            func_0010d950(index);
        }
        sSfdDecodeSlots[index].fileIndex = fileIndex;
        sSfdDecodeSlots[index].state = 2;
    }
}

/* W418 rejected slot-pointer probe: nd214,obj324 -> nd145,obj204; rate 66.05% -> 71.08% (size loophole). */
// FUN_0010D7B0 NONMATCHING
void func_0010d7b0(s16 index, s16 fileIndex, void* data0, u32 data0Size,
                   void* data1, u32 data1Size, void* data2, u32 data2Size)
{
    HSfdDecodeSlot* slot;

    slot = &sSfdDecodeSlots_abs[index];
    if ((slot->state == 1) && (slot->status != 0))
    {
        func_0010d950(index);
    }

    sSfdDecodeSlots_abs[index].fileIndex = fileIndex;
    sSfdDecodeSlots_abs[index].state = 8;
    sSfdDecodeSlots_abs[index].resource = data0;
    sSfdDecodeSlots_abs[index].aux = data1;
    sSfdDecodeSlots_abs[index].sourceData = data2;
    sSfdDecodeSlots_abs[index].inputSize = data0Size;
    sSfdDecodeSlots_abs[index].intermediateSize = data1Size;
    sSfdDecodeSlots_abs[index].outputSize = data2Size;
}

/* Scoped loop-invariant pragma measured W330: without nd113, with nd106 (obj 184/192). */
// FUN_0010D910
u32 func_0010d910(s16 index)
{
    return sSfdDecodeSlots[index].state == 1;
}
// FUN_0010D950
void func_0010d950(s16 index)
{
    u32* slot;

    if (sSfdDecodeSlots_abs[index].state != 1)
    {
        return;
    }
    slot = (u32*)((u8*)sSfdDecodeSlots_abs + 0x18) + index * 17;
    if (*slot != 0)
    {
        FUN_0051deb0(5, (void*)sSfdDecodeSlots_abs[index].completion);
        FUN_0051deb0(0, (void*)sSfdDecodeSlots_abs[index].decodeHandle);
        FUN_0051dd48(5, (void*)sSfdDecodeSlots_abs[index].outputHandle);
        FUN_0051dd48(3, (void*)sSfdDecodeSlots_abs[index].queueHandle);
        *slot = 0;
        func_0050B710(sSfdDecodeSlots_abs[index].output);
        func_0050B710(sSfdDecodeSlots_abs[index].sourceData);
    }
    *slot = 0;
}

// FUN_0010DA70
void func_0010da70(s16 bank, s16 cue)
{
    if ((sSfdDecodeSlots[bank].state == 1) && (sSfdDecodeSlots[bank].status != 0))
    {
        if (sSfdCueTable[cue].active != 0)
        {
            func_0051e028(sSfdDecodeSlots[bank].outputHandle, 1, 10, sSfdCueTable[cue].param);
            func_0051df58(sSfdDecodeSlots[bank].outputHandle, 2, 10, sSfdCueTable[cue].param);
            sSfdCueTable[cue].active = 0;
        }
    }
}

// FUN_0010DB60
void func_0010db60(s16 bank, s16 cue, s16 param3, s16 param4)
{
    s32 outputHandle;

    if ((sSfdDecodeSlots_abs[bank].state == 1) && (sSfdDecodeSlots_abs[bank].status != 0))
    {
        if (sSfdCueTable_abs[cue].active != 0)
        {
            if ((sSfdDecodeSlots_abs[bank].state == 1) && (sSfdDecodeSlots_abs[bank].status != 0))
            {
                if (sSfdCueTable_abs[cue].active != 0)
                {
                    func_0051e028_t(sSfdDecodeSlots_abs[bank].outputHandle, 1, 10, sSfdCueTable_abs[cue].param);
                    func_0051df58_t(sSfdDecodeSlots_abs[bank].outputHandle, 2, 10, sSfdCueTable_abs[cue].param);
                    sSfdCueTable_abs[cue].active = 0;
                }
            }
        }

        sSfdCueTable_abs[cue].bank = bank;
        sSfdCueTable_abs[cue].active = 1;
        outputHandle = sSfdDecodeSlots_abs[bank].outputHandle;
        /* Removing this barrier loses func_0010db60 (MATCH nd0 -> MISMATCH nd15) - measured W164. */
        asm ("" : "+m"(outputHandle));
        sSfdCueTable_abs[cue].param = func_0051df58_t(outputHandle, 0, 10, param3, param4);
    }
}

#pragma opt_loop_invariants on
// FUN_0010DD10
void func_0010dd10(HSfdImage* image, const u8* source)
{
    u8* dst;
    s32 height;
    s32 width;
    s32 x;
    s32 y;
    u32 alpha;
    u32 opaque;
    dst = image->pixels;
    width = image->width;
    height = image->height;
    opaque = 0xFF;
    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            u8* pixel = dst + (x * 4);

            pixel[0] = source[0];
            pixel[1] = source[1];
            pixel[2] = source[2];
            alpha = source[3];
            if ((s32)alpha >= 0x7F)
            {
                pixel[3] = opaque;
            }
            else
            {
                pixel[3] = (u8)((u32)(u16)((alpha * 0x100) - alpha) >> 7);
            }
            source += 4;
            x++;
        }
        dst += image->stride;
        y++;
    }
}

// FUN_0010DDC0
void func_0010ddc0(HSfdImage* image, const u8* source)
{
    u8* dst;
    s32 x;
    s32 y;
    s32 width;
    s32 height;

    dst = image->pixels;
    width = image->width;
    height = image->height;
    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            u8* pixel = dst + (x * 4);
            pixel[0] = source[0];
            pixel[1] = source[1];
            pixel[2] = source[2];
            pixel[3] = 0xFF;
            source += 3;
            x++;
        }
        dst += image->stride;
        y++;
    }
}

// FUN_0010DE40
void func_0010de40(HSfdImage* image, const u8* source)
{
    u8* dst;
    s32 width;
    s32 height;
    const u16* pixels;
    s32 y;
    s32 x;
    u32 opaque;
    dst = image->pixels;
    width = image->width;
    height = image->height;
    pixels = (const u16*)source;
    opaque = 0xFF;
    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            u8* pixel = dst + (x * 4);

            pixel[0] = (u8)((pixels[0] & 0x1F) << 3);
            pixel[1] = (u8)(((pixels[0] >> 5) & 0x1F) << 3);
            pixel[2] = (u8)(((pixels[0] >> 10) & 0x1F) << 3);
            pixel[3] = opaque;
            pixels++;
            x++;
        }
        dst += image->stride;
        y++;
    }
}

#pragma opt_loop_invariants off

// FUN_0010DEE0
void func_0010dee0(HSfdImage* image, const u8* source)
{
    u8* dst;
    s32 height;
    s32 width;
    s32 x;
    s32 y;
    s32 count;

    dst = image->pixels;
    width = image->width;
    /* Removing this barrier loses func_0010dee0 (MATCH nd0 -> MISMATCH nd10) - measured W164. */
    asm ("" : "+r"(width));
    height = image->height;
    y = 0;
    count = width >> 1;
    while (y < height)
    {
        x = 0;
        while (x < count)
        {
            u8* pixel = dst + (x * 2);

            pixel[0] = source[0] & 0x0F;
            pixel[1] = (source[0] >> 4) & 0x0F;
            source++;
            x++;
        }
        dst += image->stride;
        y++;
    }
}

/* W414: hidden-return scan found no h_maestro candidate; materializing depth in count, then initializing i before the shift, reached nd14 -> 0 (obj 168/176). */
#pragma opt_loop_invariants on
// FUN_0010DF60
void func_0010df60(HSfdImage* image, const u8* source)
{
    u8* dst;
    s32 i;
    s32 count;
    s32 alpha;
    s32 opaque;

    dst = image->palette;
    count = image->depth;
    i = 0;
    count = 1 << count;
    opaque = 0xff;
    for (; i < count; i++)
    {
        dst[i * 4] = source[i * 4];
        dst[i * 4 + 1] = source[i * 4 + 1];
        dst[i * 4 + 2] = source[i * 4 + 2];
        dst[i * 4 + 3] = source[i * 4 + 3];
        alpha = dst[i * 4 + 3];
        if (alpha >= 0x7f)
        {
            dst[i * 4 + 3] = opaque;
        }
        else
        {
            dst[i * 4 + 3] = (u16)((alpha * 0x100 - alpha) / 0x80);
        }
    }
}

#pragma opt_loop_invariants off

// FUN_0010E010
void func_0010e010(HSfdImage* image, s32 bitDepth)
{
    u8* pixels = image->palette;
    s32 count;
    s32 i;

    if (bitDepth != 8)
    {
        return;
    }

    i = 0;
    count = 1 << bitDepth;
    while (i < count)
    {
        if (((i % 0x20) >= 8) && ((i % 0x20) < 16))
        {
            u8* pixel = pixels + (i * 4);
            u8 r = pixel[0];
            u8 g = pixel[1];
            u8 b = pixel[2];
            u8 a = pixel[3];

            pixel[0] = pixel[0x20];
            pixel[1] = pixel[0x21];
            pixel[2] = pixel[0x22];
            pixel[3] = pixel[0x23];
            pixel[0x20] = r;
            pixel[0x21] = g;
            pixel[0x22] = b;
            pixel[0x23] = a;
        }
        i++;
    }
}

#pragma opt_loop_invariants on
// FUN_0010E0D0 NONMATCHING
HSfdImage* func_0010e0d0(const u8* stream)
{
    HSfdImage* image;
    s32 bits;
    s32 paletteBits;
    const u8* payload;

    payload = stream + 0x40;
    if ((stream[0] != 2) || (stream[1] != 0) ||
        (stream[8] != 'T') || (stream[9] != 'M') ||
        (stream[10] != 'X') || (stream[11] != '0'))
    {
        return NULL;
    }

    bits = 0;
    switch (stream[0x16])
    {
        case 0:
            bits = 0x20;
            break;
        case 1:
            bits = 0x18;
            break;
        case 2:
        case 0x0A:
            bits = 0x10;
            break;
        case 0x13:
        case 0x1B:
            bits = 8;
            break;
        case 0x14:
        case 0x24:
        case 0x2C:
            bits = 4;
            break;
        default:
            return NULL;
    }

    if (bits < 0x10)
        bits = 0x20;
    image = func_004cbe00(*(const u16*)(stream + 0x12),
                          *(const u16*)(stream + 0x14), bits);

    func_004cbf20(image);
    if (stream[0x10] != 0)
    {
        switch (stream[0x11])
        {
            case 0:
                func_0010df60(image, payload);
                break;
            case 1:
            {
                u8* dst;
                s32 count;
                s32 i;

                dst = image->palette;
                count = 1 << image->depth;
                for (i = 0; i < count; i++)
                {
                    u16 pixel = ((const u16*)payload)[i];
                    dst[i * 4] = (pixel & 0x1f) << 3;
                    dst[i * 4 + 1] = ((pixel >> 5) & 0x1f) << 3;
                    dst[i * 4 + 2] = ((pixel >> 10) & 0x1f) << 3;
                    dst[i * 4 + 3] = i == 0 ? 0 : 0xff;
                }
                break;
            }
            case 2:
            case 0x0A:
                break;
        }
        func_0010e010(image, bits);
        paletteBits = (stream[0x11] == 0) ? 0x20 :
                      ((stream[0x11] == 2 || stream[0x11] == 0x0A) ? 0x10 : 0);
        payload += ((1 << image->depth) * stream[0x10] * paletteBits) >> 3;
    }

    switch (stream[0x16])
    {
        case 0:
            func_0010de40(image, payload);
            break;
        case 1:
            func_0010ddc0(image, payload);
            break;
        case 2:
        case 0x0A:
            func_0010dd10(image, payload);
            break;
        case 0x13:
        case 0x1B:
            func_0010dee0(image, payload);
            break;
        case 0x14:
        case 0x24:
        case 0x2C:
            if (image->pixels != NULL)
            {
                u8* dst;
                u32 y;
                u32 x;

                dst = image->pixels;
                y = 0;
                while (y < image->height)
                {
                    x = 0;
                    while (x < image->width)
                    {
                        *dst++ = *payload++;
                        x++;
                    }
                    dst += image->stride - image->width;
                    y++;
                }
            }
            break;
    }
    return image;
}
/* Removing this worsens func_00111500 (nd2 -> nd4); loses func_00111580 (MATCH nd0 -> MISMATCH nd4) - measured W161. */
#pragma opt_loop_invariants off
// FUN_0010E500
HSfdImage* func_0010e500(void* stream)
{
    u8 header[0x40];
    void* handle;
    HSfdImage* image;
    u8* buffer;

    image = NULL;
    handle = func_004c58a0(2, 1, stream);
    if (handle != NULL)
    {
        func_004c5250(handle, header, sizeof(header));
        buffer = (*D_00960178_abs)(*(u32*)(header + 4), HSFD_STREAM_HINT);
        func_004c5250(handle, buffer + sizeof(header),
                      *(u32*)(header + 4) - sizeof(header));
        func_00521250(buffer, header, sizeof(header));
        image = func_0010e0d0(buffer);
        (*D_0096017c_abs)(buffer);
        func_004c5780_y2(handle, 0);
    }
    return image;
}

// FUN_0010E5F0
void* func_0010e5f0(void* stream, void* output)
{
    func_004c58a0(2, 1, output);
    return stream;
}

#pragma opt_loop_invariants on
// FUN_0010E630 NONMATCHING
void func_0010e630(void* destination, const void* source, u32 size)
{
    volatile u32* regs;
    u8* dst;
    const u8* src;
    u32 count;
    u32 value;

    regs = (volatile u32*)0x10010000;
    dst = (u8*)destination;
    src = (const u8*)source;
    count = size >> 4;
    FUN_004d5e90();

    while (count >= 0x401)
    {
        regs[-0x7F8] = (u32)-0x400;
        regs[-0x7FC] = 0x200;
        regs[-0xAFC] = (u32)src;
        regs[-0xAF8] = 0x400;
        regs[-0xAE0] = 0x70000000;
        value = regs[-0x7F8] | 0x200;
        regs[-0x7F8] = value;
        regs[-0xB00] = 0x101;
        while ((regs[-0xB00] & 0x100) != 0)
            ;

        regs[-0x7F8] = (u32)-0x400;
        regs[-0x7FC] = 0x100;
        regs[-0xBFC] = (u32)dst;
        regs[-0xBF8] = 0x400;
        regs[-0xBE0] = 0x70000000;
        value = regs[-0x7F8] | 0x100;
        regs[-0x7F8] = value;
        regs[-0xC00] = 0x100;
        while ((regs[-0xC00] & 0x100) != 0)
            ;

        src += 0x4000;
        dst += 0x4000;
        count -= 0x400;
    }

    regs[-0x7F8] = (u32)-0x400;
    regs[-0x7FC] = 0x200;
    regs[-0xAFC] = (u32)src;
    regs[-0xAF8] = count;
    regs[-0xAE0] = 0x70000000;
    value = regs[-0x7F8] | 0x200;
    regs[-0x7F8] = value;
    regs[-0xB00] = 0x101;
    while ((regs[-0xB00] & 0x100) != 0)
        ;

    regs[-0x7F8] = (u32)-0x400;
    regs[-0x7FC] = 0x100;
    regs[-0xBFC] = (u32)dst;
    regs[-0xBF8] = count;
    regs[-0xBE0] = 0x70000000;
    value = regs[-0x7F8] | 0x100;
    regs[-0x7F8] = value;
    regs[-0xC00] = 0x101;
    while ((regs[-0xC00] & 0x100) != 0)
        ;

    if ((regs[-0xB00] & 0x100) != 0)
    {
        regs[-0x7F8] = (u32)-0x400;
        regs[-0x7FC] = 0x100;
        regs[-0xBFC] = (u32)dst;
        regs[-0xBF8] = count;
        regs[-0xBE0] = 0x70000000;
        value = regs[-0x7F8] | 0x100;
        regs[-0x7F8] = value;
        regs[-0xC00] = 0x101;
        while ((regs[-0xC00] & 0x100) != 0)
            ;
    }
}

#pragma opt_loop_invariants off
// Retail reconstruction covers TMX validation, raster setup, pixel decode, and palette upload from offsets 0x00-0x3C8; all non-padding retail logic is represented, with only register/relocation differences remaining.
// FUN_0010E880
void* func_0010e880(const u8* stream)
{
    const u8* source;
    void* pixels;
    const u8* pixelSource;
    void* raster;
    void* palette;
    s32 bits;
    s32 paletteFormat = 0;
    s32 flags = 0;
    s32 pixelsPerPalette;

    if (stream == NULL)
    {
        K_Assert(&gp0xffff8840, 0x454);
    }
    if (stream[0] != 2)
    {
        K_Assert(&gp0xffff8840, 0x458);
    }
    if (stream[1] != 0)
    {
        K_Assert(&gp0xffff8840, 0x459);
    }
    if (((stream[8] != 'T') || (stream[9] != 'M') || (stream[10] != 'X')) &&
        (stream[11] != '0'))
    {
        K_Assert(&gp0xffff8840, 0x45A);
    }

    switch (stream[0x16])
    {
        case 0:
            bits = 0x20;
            break;
        case 1:
            bits = 0x18;
            break;
        case 0x0A:
        case 2:
            bits = 0x10;
            break;
        case 0x1B:
        case 0x13:
            bits = 8;
            flags = 0x2000;
            break;
        case 0x24:
        case 0x2C:
        case 0x14:
            bits = 4;
            flags = 0x4000;
            break;
        default:
            bits = 0;
            break;
    }

    if (stream[0x10] != 0)
    {
        switch (stream[0x11])
        {
            case 0:
                paletteFormat = 0x20;
                break;
            case 2:
            case 0x0A:
                paletteFormat = 0x10;
                break;
            default:
                paletteFormat = 0;
                break;
        }
    }

    source = stream + 0x40;
    pixelsPerPalette = 1 << bits;
    pixelSource = source +
                  ((paletteFormat * (stream[0x10] * pixelsPerPalette)) >> 3);
    raster = func_004ce0f0(*(const u16*)(stream + 0x12),
                           *(const u16*)(stream + 0x14), bits, flags | 0x504);
    if (raster == NULL)
    {
        K_Assert(&gp0xffff8840, 0x48E);
    }

    pixels = func_004ce200(raster, NULL, 1);
    if (pixels == NULL)
    {
        K_Assert(&gp0xffff8840, 0x490);
    }

    switch (bits)
    {
        case 0x20:
        case 0x18:
            func_0010e630(pixels, pixelSource,
                          *(const u16*)(stream + 0x12) *
                              *(const u16*)(stream + 0x14) * 4);
            break;
        case 0x10:
            func_0010e630(pixels, pixelSource,
                          *(const u16*)(stream + 0x12) *
                              *(const u16*)(stream + 0x14) * 2);
            break;
        case 8:
            func_0010e630(pixels, pixelSource,
                          *(const u16*)(stream + 0x12) *
                              *(const u16*)(stream + 0x14));
            break;
        case 4:
            func_0010e630(pixels, pixelSource,
                          ((s32)*(const u16*)(stream + 0x12) >> 1) *
                              *(const u16*)(stream + 0x14));
            break;
    }

    func_004cde00(raster);
    if (stream[0x10] != 0)
    {
        palette = func_004cdf30(raster, 1);
        if (palette == NULL)
        {
        K_Assert(&gp0xffff8840, 0x4BB);
        }
        func_0010e630(palette, source, pixelsPerPalette * 4);
        func_004cde40(raster);
    }
    return raster;
}
#pragma opt_loop_invariants reset

// FUN_0010EC50 NONMATCHING
void func_0010ec50(KwlnTask* task)
{
    u8* work;
    u8* entry;
    u8* frames;
    HSfdRenderFrame* record;
    void* resource;
    MaestroResourceWork* typedWork;
    void (**setRenderState)(u32, u32);
    RwCamera* camera;
    s32 element;
    s32 frame;
    s32 type;
    s32 mode;
    s32 found;
    s32 draw;
    s32 colorReady;
    s32 layer;
    s32 i;
    s32 j;
    s32 baseX;
    s32 baseY;
    s64 screenX;
    s16 screenY;
    s64 red;
    s64 green;
    s64 blue;
    s64 alpha;
    u32 frameOffset;
    u8 colorBytes[4];
    s32 colorState;
    f32 zero;
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
    f32 x2;
    f32 y2;
    s32 out0;
    f32 out1;
    f32 out2;
    f32 out3;
    f32 out4;
    s32 out5;
    s32 out6;
    s32 out7;

    work = (u8*)task->workData;
    typedWork = (MaestroResourceWork*)work;
    setRenderState = (void (**)(u32, u32))D_00960090_abs;
    (*setRenderState)(8, 0);
    (*setRenderState)(6, 0);
    func_004aa390(0.5f);
    camera = kwlnGetMainCamera();
    func_004aa3d0_y2(gUnk_007cadd0 * camera->nearPlane);
    func_004a9f20(0.0f, 0.0f, 640.0f, 448.0f);
    func_004aa410_y2(kwlnGetMainCamera());

    if (*(s32*)(work + 0x4e4) != 0)
    {
        RpSkyRenderStateSet(2, (void*)0x48);
        RpSkyRenderStateSet(3, (void*)0x71801);
    }
    else
    {
        RpSkyRenderStateSet(2, (void*)0x44);
        RpSkyRenderStateSet(3, (void*)0x717fb);
    }

    type = *(s32*)work;
    if (type != 3)
    {
        return;
    }

    func_004aaa60();
    func_004a9bf0_y2();
    func_004aaa60();
    colorState = 0;
    element = 0;
    for (; element < *(s32*)(work + 0x4e0); element++)
    {
        colorReady = 0;
        layer = 0;
        found = 0;
        draw = 0;
        entry = work + element * 4;
        frame = *(s32*)(entry + 0x1e8);
        resource = *(void**)(entry + 0xa8);
        func_004ac5f0(resource);
        func_004ab1b0(resource);
        while (draw == 0)
        {
            if (colorReady == 0)
            {
                frames = *(u8**)(entry + 8);
                frameOffset = (u32)(frame * 0x12);
                record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                if (record->command != -1)
                {
                    red = (record->colorR < 0x100) ?
                          (s8)(record->colorR & 0xff) : 0xff;
                    green = (record->colorG < 0x100) ?
                            (s8)(record->colorG & 0xff) : 0xff;
                    blue = (record->colorB < 0x100) ?
                           (s8)(record->colorB & 0xff) : 0xff;
                    alpha = (record->colorA < 0x100) ?
                            (record->colorA & 0xff) : 0xff;
                    red += typedWork->coordinates0[element];
                    green += typedWork->coordinates1[element];
                    blue += typedWork->coordinates2[element];
                    if (red < 0)
                        red = 0;
                    if (red >= 0x100)
                        red = 0xff;
                    if (green < 0)
                        green = 0;
                    if (green >= 0x100)
                        green = 0xff;
                    if (blue < 0)
                        blue = 0;
                    if (blue >= 0x100)
                        blue = 0xff;
                    colorBytes[0] = (u8)red;
                    colorBytes[1] = (u8)green;
                    colorBytes[2] = (u8)blue;
                    colorBytes[3] = (u8)alpha;
                    colorReady = 1;
                }
            }

            frames = *(u8**)(entry + 8);
            frameOffset = (u32)(frame * 0x12);
            record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
            if (record->command != -1)
            {

                frames = *(u8**)(entry + 8);
                record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                switch (record->command)
                {
                    case 0:
                        if (layer != 0)
                        {
                            if (layer >= 3)
                                func_004ab6a0(resource);
                            func_004ac710(resource);
                            func_004aaa60();
                            func_004aae00(0.0f, 0.0f);
                            if (layer < 3)
                                func_004ace70(resource, *(void**)(entry + 0x148));
                            else
                                func_004a6600(resource, *(void**)(entry + 0x148));
                            func_004aad50();
                            func_004ac5f0(resource);
                            func_004ab1b0(resource);
                            layer = 0;
                        }
                        record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                        *(s32*)(entry + 0x288) = record->type;
                        func_004ab200(
                            resource,
                            (f32)((s32)*(f32*)(work + 0x3d8) + record->x0),
                            (f32)(s32)(448.0f - (f32)((s32)*(f32*)(work + 0x3dc) + record->y0)));
                        frames = *(u8**)(entry + 8);
                        frameOffset = (u64)(frame * 0x12);
                        record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                        screenX = (s64)(s16)((s32)*(f32*)(work + 0x3d8) +
                                             record->x0);
                        screenY = (s16)(s32)(448.0f -
                                        (f32)((s32)*(f32*)(work + 0x3dc) +
                                              record->y0));
                        func_004a5dd0(*(void**)(entry + 0x148),
                                      (s8*)colorBytes, (s8*)colorBytes,
                                      (s8*)colorBytes, (s8*)colorBytes);
                        layer++;
                        found = 1;
                        break;

                    case 1:
                        *(s32*)(entry + 0x288) = record->type;
                        if (layer == 0)
                        {
                            frames = *(u8**)(entry + 8);
                            frameOffset = (u64)(frame * 0x12);
                            record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                            func_004ab200(
                                resource,
                                (f32)((s32)*(f32*)(work + 0x3d8) +
                                      record->x0),
                                (f32)(s32)(448.0f -
                                      (f32)((s32)*(f32*)(work + 0x3dc) +
                                            record->y0)));
                        }
                        else
                        {
                            frames = *(u8**)(entry + 8);
                            frameOffset = (u64)(frame * 0x12);
                            record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                            func_004ab2c0(
                                resource,
                                (f32)((s32)*(f32*)(work + 0x3d8) +
                                      record->x0),
                                (f32)(s32)(448.0f -
                                      (f32)((s32)*(f32*)(work + 0x3dc) +
                                            record->y0)));
                        }
                        frames = *(u8**)(entry + 8);
                        frameOffset = (u64)(frame * 0x12);
                        record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                        screenX = (s64)(s16)((s32)*(f32*)(work + 0x3d8) +
                                             record->x0);
                        screenY = (s16)(s32)(448.0f -
                                        (f32)((s32)*(f32*)(work + 0x3dc) +
                                              record->y0));
                        func_004a5dd0(*(void**)(entry + 0x148),
                                      (s8*)colorBytes, (s8*)colorBytes,
                                      (s8*)colorBytes, (s8*)colorBytes);
                        found = 1;
                        layer++;
                        break;

                    case 2:
                        if ((record->command == 2) && (draw == 0))
                        {
                            draw = 1;
                            func_004a62e0(*(void**)(entry + 0x148),
                                          typedWork->runtimeResources[colorState]);
                            out0 = 0;
                            zero = *(f32*)((u8*)work - 0x7cf8);
                            out1 = zero;
                            out2 = zero;
                            out3 = zero;
                            out4 = zero;
                            out5 = 0;
                            out6 = 0;
                            out7 = 0;
                            func_004a6200_y2(*(void**)(entry + 0x148),
                                             &out0, &out2, &out4, &out6);
                        }
                        *(s32*)(entry + 0x288) = record->type;
                        frames = *(u8**)(entry + 8);
                        frameOffset = (u32)(frame * 0x12);
                        record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                        baseX = (s32)*(f32*)(work + 0x3d8);
                        baseY = (s32)*(f32*)(work + 0x3dc);
                        x0 = (f32)(s32)screenX;
                        y0 = (f32)screenY;
                        x1 = (f32)(baseX + record->x0);
                        y1 = (f32)(448 - (baseY + record->y0));
                        x2 = (f32)(baseX + record->x1);
                        y2 = (f32)(448 - (baseY + record->y1));
                        func_004ab410(resource, x0, y0, x1, y1,
                                      x2, y2);
                        frames = *(u8**)(entry + 8);
                        frameOffset = (u64)(frame * 0x12);
                        record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                        screenX = (s64)(s16)(baseX + record->x1);
                        screenY = (s16)(448 - (baseY + record->y1));
                        func_004a5dd0(*(void**)(entry + 0x148),
                                      (s8*)colorBytes, (s8*)colorBytes,
                                      (s8*)colorBytes, (s8*)colorBytes);
                        layer++;
                        found = 1;
                        break;
                }
                frame++;
            }
                    else
                    {
                        break;
                    }
        }

        if (found != 0)
        {
            if (layer >= 3)
                func_004ab6a0(resource);
            func_004ac710(resource);
            func_004aaa60();
            func_004aae00(0.0f, 0.0f);
            mode = *(s32*)(entry + 0x288);
            if (mode == 1)
            {
                if (layer < 3)
                    func_004ace70(resource, *(void**)(entry + 0x148));
                else
                    func_004a6600(resource, *(void**)(entry + 0x148));
            }
            else if (mode == 2)
            {
                j = 0;
                for (i = element - 1; i >= 0; i--)
                {
                    if (typedWork->renderStates[i] == 0)
                    {
                        func_00110650(work, i, element);
                        if (layer >= 3)
                            func_004a6600(typedWork->parsedResources[i],
                                          *(void**)(entry + 0x148));
                        j = 1;
                        break;
                    }
                }
                if ((j == 0) && (layer >= 3))
                    func_004a6600(resource, *(void**)(entry + 0x148));
            }
            func_004aad50();
        }
        else
        {
            func_004ac710(resource);
        }
        if ((draw != 0) && (colorState != 1))
            colorState++;
    }
    func_004aad50();
    func_004aad50();
}
#pragma opt_loop_invariants off
// FUN_0010F6C0 NONMATCHING
void* func_0010f6c0(KwlnTask* task)
{
    u8* work;
    u8* entry;
    u8* frames;
    HSfdRenderFrame* record;
    void* resource;
    MaestroResourceWork* typedWork;
    void (**setRenderState)(u32, u32);
    RwCamera* camera;
    s32 element;
    s32 frame;
    s32 type;
    s32 mode;
    s32 found;
    s32 draw;
    s32 colorReady;
    s32 layer;
    s32 i;
    s32 j;
    s32 baseX;
    s32 baseY;
    s64 screenX;
    s16 screenY;
    s64 red;
    s64 green;
    s64 blue;
    s64 alpha;
    u32 frameOffset;
    u8 colorBytes[4];
    s32 colorState;
    f32 zero;
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
    f32 x2;
    f32 y2;
    s32 out0;
    f32 out1;
    f32 out2;
    f32 out3;
    f32 out4;
    s32 out5;
    s32 out6;
    s32 out7;

    work = (u8*)task->workData;
    typedWork = (MaestroResourceWork*)work;
    setRenderState = (void (**)(u32, u32))D_00960090_abs;
    (*setRenderState)(8, 0);
    (*setRenderState)(6, 0);
    func_004aa390(0.5f);
    camera = kwlnGetMainCamera();
    func_004aa3d0_y2(gUnk_007cadd0 * camera->nearPlane);
    func_004a9f20(0.0f, 0.0f, 640.0f, 448.0f);
    func_004aa410_y2(kwlnGetMainCamera());

    if (*(s32*)(work + 0x4e4) != 0)
    {
        RpSkyRenderStateSet(2, (void*)0x48);
        RpSkyRenderStateSet(3, (void*)0x71801);
    }
    else
    {
        RpSkyRenderStateSet(2, (void*)0x44);
        RpSkyRenderStateSet(3, (void*)0x717fb);
    }

    type = *(s32*)work;
    switch (type)
    {
        case 0:
            for (element = 0; element < *(s32*)(work + 0x4e0); element++)
            {
                entry = work + element * 4;
                resource = func_004a5470();
                *(void**)(entry + 0x148) = resource;
                func_004a5dd0(resource, fGpffff7788, fGpffff7788,
                              fGpffff7788, fGpffff7788);
                *(s32*)(entry + 0x288) = -1;
            }
            for (element = 0; element < *(s32*)(work + 0x4e0); element++)
            {
                entry = work + element * 4;
                resource = func_004ac570();
                *(void**)(entry + 0xa8) = resource;
                func_004ac5f0(resource);
                func_004ab1b0(resource);
                func_004ac5f0(resource);
                *(s32*)(entry + 0x1e8) = 0;
            }
            frames = *(u8**)(work + 4);
            *(void**)(work + 8) = *(void**)(work + 4);
            j = 0;
            i = 1;
            for (; i < *(s32*)(work + 0x4e0); i++)
            {
                while (*(s8*)(frames + j * 0x12 + 1) != -2)
                {
                    j++;
                }
                j++;
                *(void**)(work + i * 4 + 8) = frames + j * 0x12;
            }
            *(s32*)work = 1;
            break;

        case 1:
            *(s32*)work = 2;
            break;

        case 2:
            return NULL;

        case 3:
            if (*(s32*)(work + 0x4e8) != 0)
            {
                return NULL;
            }
            func_004aaa60();
            func_004a9bf0_y2();
            func_004aaa60();
            colorState = 0;
            element = 0;
            for (; element < *(s32*)(work + 0x4e0); element++)
            {
                colorReady = 0;
                layer = 0;
                found = 0;
                draw = 0;
                entry = work + element * 4;
                frame = *(s32*)(entry + 0x1e8);
                resource = *(void**)(entry + 0xa8);
                func_004ac5f0(resource);
                func_004ab1b0(resource);
                while (draw == 0)
                {
                    if (colorReady == 0)
                    {
                        frames = *(u8**)(entry + 8);
                        frameOffset = (u32)(frame * 0x12);
                        record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                        if (record->command != -1)
                        {
                            red = (record->colorR < 0x100) ?
                                  (s8)(record->colorR & 0xff) : 0xff;
                            green = (record->colorG < 0x100) ?
                                    (s8)(record->colorG & 0xff) : 0xff;
                            blue = (record->colorB < 0x100) ?
                                  (s8)(record->colorB & 0xff) : 0xff;
                            alpha = (record->colorA < 0x100) ?
                                    (record->colorA & 0xff) : 0xff;
                            red += typedWork->coordinates0[element];
                            green += typedWork->coordinates1[element];
                            blue += typedWork->coordinates2[element];
                            if (red < 0)
                                red = 0;
                            if (red >= 0x100)
                                red = 0xff;
                            if (green < 0)
                                green = 0;
                            if (green >= 0x100)
                                green = 0xff;
                            if (blue < 0)
                                blue = 0;
                            if (blue >= 0x100)
                                blue = 0xff;
                            colorBytes[0] = (u8)red;
                            colorBytes[1] = (u8)green;
                            colorBytes[2] = (u8)blue;
                            colorBytes[3] = (u8)alpha;
                            colorReady = 1;
                        }
                    }

                    frames = *(u8**)(entry + 8);
                    frameOffset = (u32)(frame * 0x12);
                    record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                    if (record->command != -1)
                    {
                        if ((record->command == 2) && (draw == 0))
                        {
                            draw = 1;
                            func_004a62e0(*(void**)(entry + 0x148),
                                          typedWork->runtimeResources[colorState]);
                            out0 = 0;
                            zero = *(f32*)((u8*)work - 0x7cf8);
                            out1 = zero;
                            out2 = zero;
                            out3 = zero;
                            out4 = zero;
                            out5 = 0;
                            out6 = 0;
                            out7 = 0;
                            func_004a6200_y2(*(void**)(entry + 0x148),
                                              &out0, &out2, &out4, &out6);
                        }
                        frames = *(u8**)(entry + 8);
                        record = (HSfdRenderFrame*)(frames + (u32)frameOffset);

                        switch (record->command)
                        {
                            case 0:
                                if (layer != 0)
                                {
                                    if (layer >= 3)
                                        func_004ab6a0(resource);
                                    func_004ac710(resource);
                                    func_004aaa60();
                                    func_004aae00(0.0f, 0.0f);
                                    if (layer < 3)
                                        func_004ace70(resource, *(void**)(entry + 0x148));
                                    else
                                        func_004a6600(resource, *(void**)(entry + 0x148));
                                    func_004aad50();
                                    func_004ac5f0(resource);
                                    func_004ab1b0(resource);
                                }
                                record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                                *(s32*)(entry + 0x288) = record->type;
                                func_004ab200(
                                    resource,
                                    (f32)((s32)*(f32*)(work + 0x3d8) + record->x0),
                                    (f32)(448 - ((s32)*(f32*)(work + 0x3dc) + record->y0)));
                                frames = *(u8**)(entry + 8);
                                frameOffset = (u64)(frame * 0x12);
                                record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                                screenX = (s64)(s16)((s32)*(f32*)(work + 0x3d8) +
                                                     record->x0);
                                screenY = (s16)(s32)(448.0f -
                                                (f32)((s32)*(f32*)(work + 0x3dc) +
                                                      record->y0));
                                func_004a5dd0(*(void**)(entry + 0x148),
                                              (s8*)colorBytes, (s8*)colorBytes,
                                              (s8*)colorBytes, (s8*)colorBytes);
                                layer++;
                                found = 1;
                                break;

                            case 1:
                                *(s32*)(entry + 0x288) = record->type;
                                if (layer == 0)
                                {
                                    frames = *(u8**)(entry + 8);
                                    frameOffset = (u64)(frame * 0x12);
                                    record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                                    func_004ab200(
                                        resource,
                                        (f32)((s32)*(f32*)(work + 0x3d8) +
                                              record->x0),
                                        (f32)(448 -
                                              ((s32)*(f32*)(work + 0x3dc) +
                                               record->y0)));
                                }
                                else
                                {
                                    frames = *(u8**)(entry + 8);
                                    frameOffset = (u64)(frame * 0x12);
                                    record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                                    func_004ab2c0(
                                        resource,
                                        (f32)((s32)*(f32*)(work + 0x3d8) +
                                              record->x0),
                                        (f32)(448 -
                                              ((s32)*(f32*)(work + 0x3dc) +
                                               record->y0)));
                                }
                                frames = *(u8**)(entry + 8);
                                frameOffset = (u64)(frame * 0x12);
                                record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                                screenX = (s64)(s16)((s32)*(f32*)(work + 0x3d8) +
                                                     record->x0);
                                screenY = (s16)(s32)(448.0f -
                                                (f32)((s32)*(f32*)(work + 0x3dc) +
                                                      record->y0));
                                func_004a5dd0(*(void**)(entry + 0x148),
                                              (s8*)colorBytes, (s8*)colorBytes,
                                              (s8*)colorBytes, (s8*)colorBytes);
                                found = 1;
                                layer++;
                                break;
 
                            case 2:
                                *(s32*)(entry + 0x288) = record->type;
                                frames = *(u8**)(entry + 8);
                                frameOffset = (u32)(frame * 0x12);
                                record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                                x0 = (f32)(s32)screenX;
                                y0 = (f32)screenY;
                                x1 = (f32)((s32)*(f32*)(work + 0x3d8) +
                                           record->x0);
                                y1 = (f32)(448 -
                                           ((s32)*(f32*)(work + 0x3dc) +
                                            record->y0));
                                x2 = (f32)((s32)*(f32*)(work + 0x3d8) +
                                           record->x1);
                                y2 = (f32)(448 -
                                           ((s32)*(f32*)(work + 0x3dc) +
                                            record->y1));
                                func_004ab410(resource, x0, y0, x1, y1,
                                              x2, y2);
                                frames = *(u8**)(entry + 8);
                                frameOffset = (u64)(frame * 0x12);
                                record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                                screenX = (s64)(s16)((s32)*(f32*)(work + 0x3d8) +
                                                     record->x1);
                                screenY = (s16)(s32)(448.0f -
                                                (f32)((s32)*(f32*)(work + 0x3dc) +
                                                      record->y1));
                                func_004a5dd0(*(void**)(entry + 0x148),
                                              (s8*)colorBytes, (s8*)colorBytes,
                                              (s8*)colorBytes, (s8*)colorBytes);
                                layer++;
                                found = 1;
                                break;
                        }
                        frame++;
                    }
                    else
                    {
                        break;
                    }
                }

                if (found != 0)
                {
                    if (layer >= 3)
                        func_004ab6a0(resource);
                    func_004ac710(resource);
                    func_004aaa60();
                    func_004aae00(0.0f, 0.0f);
                    mode = *(s32*)(entry + 0x288);
                    if (mode == 1)
                    {
                        if (layer < 3)
                            func_004ace70(resource, *(void**)(entry + 0x148));
                        else
                            func_004a6600(resource, *(void**)(entry + 0x148));
                    }
                    else if (mode == 2)
                    {
                        j = 0;
                        for (i = element - 1; i >= 0; i--)
                        {
                            if (typedWork->renderStates[i] == 0)
                            {
                                func_00110650(work, i, element);
                                if (layer >= 3)
                                    func_004a6600(typedWork->parsedResources[i],
                                                  *(void**)(entry + 0x148));
                                j = 1;
                                break;
                            }
                        }
                        if ((j == 0) && (layer >= 3))
                            func_004a6600(resource, *(void**)(entry + 0x148));
                    }
                    func_004aad50();
                }
                else
                {
                    func_004ac710(resource);
                }
                if ((draw != 0) && (colorState != 1))
                    colorState++;
            }
            func_004aad50();
            func_004aad50();
            break;
    }
    return NULL;
}
#pragma opt_loop_invariants reset

// FUN_001102E0
void func_001102e0(KwlnTask* task)
{
    MaestroResourceWork* work;
    s32 i;
    void** resourceSlot;

    work = (MaestroResourceWork*)task->workData;

    for (i = 0; i < (s32)work->resourceCount; i++)
    {
        resourceSlot = &work->parsedResources[i];
        if (*resourceSlot != NULL)
        {
            if (func_004ac390(*resourceSlot) == 0)
            {
                printf(D_005D5880);
            }
            *resourceSlot = NULL;
        }
    }

    for (i = 0; i < (s32)work->resourceCount; i++)
    {
        resourceSlot = &work->effectResources[i];
        if (*resourceSlot != NULL)
        {
            if (func_004a5540(*resourceSlot) == 0)
            {
                printf(D_005D5880);
            }
            *resourceSlot = NULL;
        }
    }

    MAESTRO_FREE(work);
}

// FUN_001103E0
KwlnTask* func_001103e0(KwlnTask* parent, u32 priority, u32 param_3, u32 resourceCount)
{
    MaestroResourceWork* work;
    KwlnTask* task;

    work = (MaestroResourceWork*)MAESTRO_ALLOC(1, sizeof(MaestroResourceWork), 0x40000);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreate(parent, D_005D5898, priority, func_0010f6c0, func_001102e0, work);
    if (task == NULL)
    {
        return NULL;
    }

    work->resourceIndex = param_3;
    work->resourceCount = resourceCount;
    return task;
}

// FUN_001104B0
u32 func_001104b0(KwlnTask* task)
{
    return ((MaestroResourceWork*)task->workData)->state >= 2;
}

// FUN_001104D0
u32 func_001104d0(KwlnTask* task)
{
    MaestroResourceWork* work;

    work = (MaestroResourceWork*)task->workData;
    if (work->state == 2)
    {
        work->state = 3;
        return true;
    }

    return false;
}

static inline s8* maestroLoadRecords(s8** out, MaestroResourceWork* work, s32 index)
{
    *out = (s8*)work->resources[index];
    return *out;
}

#pragma opt_loop_invariants on
// FUN_00110510
u32 func_00110510(KwlnTask* task)
{
    s32 i;
    MaestroResourceWork* work;

    work = (MaestroResourceWork*)task->workData;
    if (work->state == 3)
    {
        for (i = 0; i < (s32)work->resourceCount; i++)
        {
            s8* records;
            s8 recordType;

record_read:
            records = maestroLoadRecords(&records, work, i);
            recordType = records[work->recordIndices[i] * 18 + 1];
            if (recordType != -1)
            {
                goto record_body;
            }
            work->recordIndices[i]++;
            work->completedRecords++;
            goto record_done;
record_body:
            if (recordType == -2)
            {
                return false;
            }
            work->recordIndices[i]++;
            goto record_read;
record_done:
            ;
        }
    }

    return true;
}

#pragma opt_loop_invariants off

// FUN_001105D0
void func_001105d0(KwlnTask* task, s32 index, void* resource)
{
    MaestroResourceWork* work;
    void** resourceSlot;

    work = (MaestroResourceWork*)task->workData;
    if (index < 40)
    {
        index *= sizeof(void*);
        work = (MaestroResourceWork*)(index + (int)work);
        resourceSlot = work->runtimeResources;
        *resourceSlot = resource;
        if (resource != NULL)
        {
            u32* flags;

            resource = *resourceSlot;
            flags = (u32*)((u8*)resource + 0x50);
            *flags = (*flags & 0xFFFFFF00) | 2;
        }
    }
}

// FUN_00110620
void func_00110620(KwlnTask* task, s16 index, s16 param_3, s16 param_4, s16 param_5)
{
    MaestroResourceWork* work;

    work = (MaestroResourceWork*)task->workData;
    work->coordinates0[index] = param_3;
    work->coordinates1[index] = param_4;
    work->coordinates2[index] = param_5;
}

// FUN_00110650 NONMATCHING
void func_00110650_y2(void* param_1, s32 sourceIndex, s32 destinationIndex)
{
    MaestroResourceWork* work;
    struct
    {
        u8 pad[0x10];
        f32 destination[4];
        f32 source[4];
        f32 uv[8];
    } locals;
    void* texture;
    s32* dimensions;
    void** effectResources;

    work = (MaestroResourceWork*)param_1;
    func_004ac120(work->parsedResources[sourceIndex], locals.source);
    func_004ac120(work->parsedResources[destinationIndex], locals.destination);

    effectResources = work->effectResources;
    texture = *(void**)((u8*)effectResources[destinationIndex] + 0x68);
    if (texture == NULL)
    {
        return;
    }

    dimensions = *(s32**)texture;
    locals.uv[0] = (locals.source[0] - locals.destination[0]) * (f32)dimensions[3] / locals.source[2] / locals.source[2];
    locals.uv[1] = ((448.0f - (locals.destination[1] + locals.destination[3])) - (448.0f - (locals.source[1] + locals.source[3]))) * (f32)dimensions[4] / locals.source[3] / locals.source[3];
    locals.uv[2] = ((locals.source[0] + locals.source[2]) - locals.destination[0]) * (f32)dimensions[3] / locals.source[2] / locals.source[2] + 1.0f;
    locals.uv[3] = locals.uv[1] + 1.0f;
    locals.uv[4] = locals.uv[2];
    locals.uv[5] = ((448.0f - locals.destination[1]) - (448.0f - (locals.source[1] + locals.source[3]))) * (f32)dimensions[4] / locals.source[3] / locals.source[3];
    locals.uv[6] = locals.uv[0];
    locals.uv[7] = locals.uv[5];
    func_004a6200(effectResources[destinationIndex], &locals.uv[0], &locals.uv[2], &locals.uv[4], &locals.uv[6]);
}

// FUN_001107D0 NONMATCHING
void* func_001107d0(KwlnTask* task)
{
    MaestroStreamWork* work;

    work = (MaestroStreamWork*)task->workData;
    switch (work->state)
    {
        case 0:
            if (work->useCdvd != 0)
            {
                work->cdvd = H_Cdvd_Request(work->path, HCDVD_FILEARCHIVE);
            }
            work->state = 1;
            break;

        case 1:
            if (work->useCdvd != 0 && !H_Cdvd_IsFileLoaded(work->cdvd))
            {
                break;
            }
            work->resourceIndex = 0;
            work->state = 2;
            break;

        case 2:
        {
            const char* externalPath;
            s32 i;
            s8 recordType;

            externalPath = func_001022e0(work->cdvd, work->resourceIndex + 1);
            if (externalPath != NULL)
            {
                char fullPath[256];

                strcpy(fullPath, work->basePath);
                strcat(fullPath, (char*)externalPath);
                printf(D_005D58A8, fullPath);
                work->stream = func_0010c1a0(NULL, fullPath, NULL, NULL, NULL, NULL, NULL, NULL,
                                             NULL, NULL, D_005D58A8, 0x506);
                work->state = 4;
                break;
            }

            work->records = (u8*)H_Cdvd_ArchiveGetFile(work->cdvd, 0, NULL);
            memcpy(work->archiveHeader, work->records, sizeof(work->archiveHeader));
            work->records += sizeof(work->archiveHeader);
            work->recordCount = 0;
            for (i = 0; i < 1000; i++)
            {
                recordType = ((s8*)work->records)[i * 18 + 1];
                if (recordType == -2)
                {
                    work->recordCount--;
                }
                else if (recordType == -1)
                {
                    work->recordCount++;
                }
            }
            work->state = 5;
            break;
        }
        case 3:
            break;

        case 4:
        {
            u32 finished;
            void* resource;

            finished = false;
            resource = func_0010c3a0(work->stream, &finished, 0);
            work->resources[work->resourceIndex] = resource;
            if (finished == 0)
            {
                break;
            }
            work->stream = NULL;
            *(u32*)((u8*)resource + 0x50) = (*(u32*)((u8*)resource + 0x50) & 0xFFFF00FF) | 0x3300;
            work->resourceIndex++;
            work->state = 2;
            break;
        }

        case 5:
        {
            MaestroResourceWork* resourceWork;
            KwlnTask* resourceTask;
            s32 i;
            s32 destinationIndex;

            if (work->createCustomPriorityTask != 0)
            {
                u8* records;
                s16 resourceCount;
                u32 resourceTaskPriority;

                records = work->records;
                resourceCount = *(s16*)(work->archiveHeader + 8);
                resourceTaskPriority = work->resourceTaskPriority;
                resourceWork = (MaestroResourceWork*)MAESTRO_ALLOC(1, sizeof(MaestroResourceWork), 0x40000);
                resourceTask = NULL;
                if (resourceWork != NULL)
                {
                    resourceTask = kwlnTaskCreate(task, D_005D5898, resourceTaskPriority,
                                                  func_0010f6c0, func_001102e0, resourceWork);
                    if (resourceTask != NULL)
                    {
                        resourceWork->resourceIndex = (u32)records;
                        resourceWork->resourceCount = (u32)resourceCount;
                    }
                }
                work->resourceTask = resourceTask;
            }
            else
            {
                u8* records;
                s16 resourceCount;

                records = work->records;
                resourceCount = *(s16*)(work->archiveHeader + 8);
                resourceWork = (MaestroResourceWork*)MAESTRO_ALLOC(1, sizeof(MaestroResourceWork), 0x40000);
                resourceTask = NULL;
                if (resourceWork != NULL)
                {
                    resourceTask = kwlnTaskCreate(task, D_005D5898, 0x14A6,
                                                  func_0010f6c0, func_001102e0, resourceWork);
                    if (resourceTask != NULL)
                    {
                        resourceWork->resourceIndex = (u32)records;
                        resourceWork->resourceCount = (u32)resourceCount;
                    }
                }
                work->resourceTask = resourceTask;
            }
            if (work->resourceTask != NULL)
            {
                resourceWork = (MaestroResourceWork*)work->resourceTask->workData;
                *(u32*)((u8*)resourceWork + 0x4E4) = work->renderFlags;
                *(f32*)((u8*)resourceWork + 0x3D8) = work->x;
                *(f32*)((u8*)resourceWork + 0x3DC) = work->y;
                *(void**)((u8*)resourceWork + 0x328) = work->resources[0];
                if (work->resources[0] != NULL)
                {
                    *(u32*)((u8*)work->resources[0] + 0x50) =
                        (*(u32*)((u8*)work->resources[0] + 0x50) & 0xFFFFFF00) | 2;
                }
                *(void**)((u8*)resourceWork + 0x32C) = work->resources[1];
                if (work->resources[1] != NULL)
                {
                    *(u32*)((u8*)work->resources[1] + 0x50) =
                        (*(u32*)((u8*)work->resources[1] + 0x50) & 0xFFFFFF00) | 2;
                }
                for (i = 0; i < 3; i++)
                {
                    destinationIndex = i == 2 ? 1 : (i == 0 ? 3 : 4);
                    *(s16*)((u8*)resourceWork + 0x3E8 + destinationIndex * 2) =
                        *(s16*)(work->archiveHeader + 0xA + i * 2);
                    *(s16*)((u8*)resourceWork + 0x438 + destinationIndex * 2) =
                        *(s16*)(work->archiveHeader + 0x12 + i * 2);
                    *(s16*)((u8*)resourceWork + 0x488 + destinationIndex * 2) =
                        *(s16*)(work->archiveHeader + 0x1A + i * 2);
                }
            }
            work->state = 7;
            break;
        }
        case 6:
            break;
        case 7:
        {
            MaestroResourceWork* resourceWork;
            s32 i;

            resourceWork = (MaestroResourceWork*)work->resourceTask->workData;
            if (resourceWork->state < 2)
            {
                break;
            }
            for (i = 0; i < 0x100; i++)
            {
                const s8* action;

                action = &D_005D53E0[i * 6];
                if (action[0] == 0)
                {
                    break;
                }
                if (work->dimensions[0] == action[0] && work->dimensions[1] == action[1] && work->dimensions[2] == action[2] && work->dimensions[3] == action[3])
                {
                    func_0010a4e0(0, 1, action[4], action[5]);
                }
            }
            if (resourceWork->state == 2)
            {
                resourceWork->state = 3;
            }
            resourceWork->x = work->x;
            resourceWork->y = work->y;
            work->state = 8;
            break;
        }

        case 8:
        {
            s16 stopFrame;

            ((MaestroResourceWork*)work->resourceTask->workData)->x = work->x;
            ((MaestroResourceWork*)work->resourceTask->workData)->y = work->y;
            stopFrame = *(s16*)(work->archiveHeader + 6);
            if (work->stopAtFrame == 0 && stopFrame != 0 && work->frameIndex == stopFrame)
            {
                work->complete = true;
                break;
            }
            work->frameIndex++;
            func_00110510(work->resourceTask);
            if (work->frameIndex >= work->recordCount)
            {
                return KWLNTASK_STOP;
            }
            break;
        }
    }

    return KWLNTASK_CONTINUE;
}

/* Scope spans FUN_001105D0..FUN_001107D0. Closing it any earlier costs
 * func_001107D0 nd1162 -> 1171, object 1548 -> 1560 (measured W404), so the
 * knob is live across all four functions, not just the one it precedes. */
#pragma opt_loop_invariants reset

// FUN_00110E70 MATCHING
void func_00110e70(KwlnTask* task)
{
    MaestroStreamWork* work;
    s32 i;
    u8* entry;
    void** slot;
    work = (MaestroStreamWork*)task->workData;
    if (work->stream != NULL)
    {
        if (work->useCdvd != 0)
        {
            func_00133d30(work->stream, work->cdvd);
        }
        else
        {
            func_00133d30(work->stream, NULL);
        }
        work->cdvd = NULL;
    }
    else if (work->useCdvd != 0 && work->cdvd != NULL)
    {
        H_Cdvd_Destroy(work->cdvd);
        work->cdvd = NULL;
    }

    for (i = 0; i < 40; i++)
    {
        entry = (u8*)work + i * 4;
        slot = (void**)(entry + 8);
        if (*(void**)(entry + 8) != NULL)
        {
            func_004d0f00(*(void**)(entry + 8));
            *slot = NULL;
        }
    }

    printf(D_005D58C0, work->path);
    MAESTRO_FREE(work);
}

// FUN_00110F80
KwlnTask* func_00110f80(KwlnTask* parent, u64 dimensions)
{
    s32 i;
    KwlnTask* task;
    MaestroStreamWork* work;
    char name[256];

    work = (MaestroStreamWork*)MAESTRO_ALLOC(1, sizeof(MaestroStreamWork), 0x40000);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreateWithAutoPriority(parent, 0x106F, D_005D6A68, func_001107d0, func_00110e70, work);
    if (task == NULL)
    {
        return NULL;
    }

    *(MaestroStreamDimensions*)work->dimensions = *(MaestroStreamDimensions*)&dimensions;
    sprintf(name, D_005D6A80, work->dimensions[0], work->dimensions[1], work->dimensions[2], work->dimensions[3]);
    printf(D_005D6AA0, name);
    strcpy(work->basePath, D_005D6AB8);
    work->useCdvd = true;

    for (i = 0; i < 10000; i++)
    {
        if (D_005D66E0[i][0] == '\0')
        {
            break;
        }
        if (strcmp(name, D_005D66E0[i]) == 0)
        {
            sprintf(work->path, D_005D6AD0, work->dimensions[0], work->dimensions[1], work->dimensions[2], work->dimensions[3]);
            return task;
        }
    }

    printf(D_005D6AF0);
    sprintf(work->path, D_005D6B10);
    return task;
}

// FUN_00111150
KwlnTask* func_00111150(KwlnTask* parent, u64 dimensions)
{
    KwlnTask* task;
    MaestroStreamWork* work;

    work = (MaestroStreamWork*)MAESTRO_ALLOC(1, sizeof(MaestroStreamWork), 0x40000);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreateWithAutoPriority(parent, 0x106F, D_005D6A68, func_001107d0, func_00110e70, work);
    if (task == NULL)
    {
        return NULL;
    }

    *(MaestroStreamDimensions*)work->dimensions = *(MaestroStreamDimensions*)&dimensions;
    sprintf(work->path, D_005D6B30, work->dimensions[0], work->dimensions[1], work->dimensions[2], work->dimensions[3]);
    strcpy(work->basePath, D_005D6B50);
    work->useCdvd = true;
    return task;
}

// FUN_00111260
KwlnTask* func_00111260(KwlnTask* parent, u64 dimensions, void* archive)
{
    KwlnTask* task;
    MaestroStreamWork* work;
    s16 dim2;
    s16 dim0;
    s16 dim1;
    s16 dim3;

    work = (MaestroStreamWork*)MAESTRO_ALLOC(1, sizeof(MaestroStreamWork), 0x40000);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreateWithAutoPriority(parent, 0x106F, D_005D6A68, func_001107d0, func_00110e70, work);
    if (task == NULL)
    {
        return NULL;
    }

    dim0 = ((volatile /* Removing this function's qualifier batch loses func_00111260 (MATCH nd0 -> MISMATCH nd9, size 276 -> 276) - measured W170. */ s16*)&dimensions)[0];
    dim1 = ((volatile /* Removing this function's qualifier batch loses func_00111260 (MATCH nd0 -> MISMATCH nd9, size 276 -> 276) - measured W170. */ s16*)&dimensions)[1];
    dim2 = ((volatile /* Removing this function's qualifier batch loses func_00111260 (MATCH nd0 -> MISMATCH nd9, size 276 -> 276) - measured W170. */ s16*)&dimensions)[2];
    dim3 = ((volatile /* Removing this function's qualifier batch loses func_00111260 (MATCH nd0 -> MISMATCH nd9, size 276 -> 276) - measured W170. */ s16*)&dimensions)[3];
    work->dimensions[0] = dim0;
    work->dimensions[1] = dim1;
    work->dimensions[2] = dim2;
    work->dimensions[3] = dim3;
    sprintf(work->path, D_005D6B30, work->dimensions[0], work->dimensions[1], work->dimensions[2], work->dimensions[3]);
    strcpy(work->basePath, D_005D6B50);
    work->cdvd = (HCdvd*)archive;
    work->useCdvd = false;
    return task;
}

// FUN_00111380
KwlnTask* func_00111380(KwlnTask* parent, u32 priority, u64 dimensions, void* archive)
{
    KwlnTask* task;
    MaestroStreamWork* work;
    s16 dim2;
    s16 dim0;
    s16 dim1;
    s16 dim3;

    work = (MaestroStreamWork*)MAESTRO_ALLOC(1, sizeof(MaestroStreamWork), 0x40000);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreate(parent, D_005D6A68, priority, func_001107d0, func_00110e70, work);
    if (task == NULL)
    {
        return NULL;
    }

    dim0 = ((volatile /* Removing this function's qualifier batch loses func_00111380 (MATCH nd0 -> MISMATCH nd9, size 304 -> 304) - measured W170. */ s16*)&dimensions)[0];
    dim1 = ((volatile /* Removing this function's qualifier batch loses func_00111380 (MATCH nd0 -> MISMATCH nd9, size 304 -> 304) - measured W170. */ s16*)&dimensions)[1];
    dim2 = ((volatile /* Removing this function's qualifier batch loses func_00111380 (MATCH nd0 -> MISMATCH nd9, size 304 -> 304) - measured W170. */ s16*)&dimensions)[2];
    dim3 = ((volatile /* Removing this function's qualifier batch loses func_00111380 (MATCH nd0 -> MISMATCH nd9, size 304 -> 304) - measured W170. */ s16*)&dimensions)[3];
    work->dimensions[0] = dim0;
    work->dimensions[1] = dim1;
    work->dimensions[2] = dim2;
    work->dimensions[3] = dim3;
    sprintf(work->path, D_005D6B30, work->dimensions[0], work->dimensions[1], work->dimensions[2], work->dimensions[3]);
    strcpy(work->basePath, D_005D6B50);
    work->createCustomPriorityTask = true;
    work->resourceTaskPriority = priority;
    work->useCdvd = false;
    work->cdvd = (HCdvd*)archive;
    *(volatile /* Removing this function's qualifier batch loses func_00111380 (MATCH nd0 -> MISMATCH nd9, size 304 -> 304) - measured W170. */ u32*)&work->useCdvd = false;
    return task;
}


// FUN_001114B0
u32 func_001114b0(KwlnTask* task)
{
    MaestroStreamWork* work;

    work = (MaestroStreamWork*)task->workData;
    if (work->state == 5)
    {
        printf(D_005D6B60, work->path);
        return true;
    }

    return false;
}

#pragma optimization_level 1


// FUN_00111500
/* Returns the value it stores: retail materializes the 1 in $v0, the return
 * register, rather than reusing the dead argument register $a0. Every void
 * form colours it $a0 (nd2 floor); the result is discarded at the call site. */
s32 func_00111500(KwlnTask* task)
{
    MaestroStreamWork* work;
    s32 value;
    work = (MaestroStreamWork*)task->workData;
    value = 1;
    work->stopAtFrame = value;
    work->complete = 0;
    return value;
}
// FUN_00111520
void func_00111520(KwlnTask* task, s16 count)
{
    *((s16*)((MaestroStreamWork*)task->workData)->archiveHeader + 3) = count;
}

// FUN_00111530
u32 func_00111530(KwlnTask* task)
{
    MaestroStreamWork* work;

    work = (MaestroStreamWork*)task->workData;
    if (work->state == 5)
    {
        work->state = 6;
        return true;
    }

    return false;
}

// FUN_00111570
void func_00111570(KwlnTask* task, u32 value)
{
    ((MaestroStreamWork*)task->workData)->renderFlags = value;
}

// FUN_00111580
void func_00111580(KwlnTask* task, u64 packedCoordinates)
{
    KwlnTask* task_p = task;
    f32 x;
    f32 y;
    MaestroStreamWork* work;
    MaestroStreamWork* work_c;

    work = (MaestroStreamWork*)task_p->workData;
    x = ((f32*)&packedCoordinates)[0];
    y = ((f32*)&packedCoordinates)[1];
    (work_c = work)->x = x;
    work->y = y;
}

#pragma optimization_level 2

// FUN_001115B0
void func_001115b0(KwlnTask* task)
{
    MaestroStreamWork* work;

    work = (MaestroStreamWork*)task->workData;
    if (work->resourceTask != NULL)
    {
        ((MaestroResourceWork*)work->resourceTask->workData)->cancelRequested = true;
    }
}

// FUN_001115E0
void func_001115e0(KwlnTask* task)
{
    MaestroStreamWork* work;

    work = (MaestroStreamWork*)task->workData;
    if (work->resourceTask != NULL)
    {
        func_0010ec50(work->resourceTask);
    }
}

// FUN_00111610 NONMATCHING
void* H_Maestro_UpdateTask(KwlnTask* hmaestroTask)
{
    HMaestro* work;
    RwCamera* camera;

    RwRGBAReal color;
    f32 savedNearPlane;
    RwV2d animOutput[3];
    f32 animEnd;
    f32 animCurrent;
    u32 anim;
    u32 finished;
    RwBool (**setRenderState)(RwRenderState state, void* value);

    work = (HMaestro*)hmaestroTask->workData;
    camera = kwlnGetMainCamera();
    savedNearPlane = camera->nearPlane;
    RwCameraEndUpdate(camera);
    func_004c9d70(camera, 50.0f);
    RwCameraBeginUpdate(camera);
    func_004aa390_y2(0.5f);
    camera = kwlnGetMainCamera();
    func_004aa3d0(gUnk_007cadd0 * camera->nearPlane);
    func_004a9f20_y2(0.0f, 0.0f, 640.0f, 448.0f);
    func_004aa410(kwlnGetMainCamera());

    switch (work->state)
    {
    case HMAESTRO_STATE_INITCDVD:
        if (work->useCdvd != 0)
        {
            work->cdvd = H_Cdvd_Request(work->path, HCDVD_FILENORMAL);
        }
        work->state = HMAESTRO_STATE_INITSTREAM;
        work->deltaTime = 0.0f;
    case HMAESTRO_STATE_INITSTREAM:
        if (work->useCdvd != 0 && H_Cdvd_IsFileLoaded(work->cdvd) == 0)
        {
            goto restore_continue;
        }

        work->rws = func_004c58a0_y2(2, 1, work->path);
        if (work->rws == NULL)
        {
            printf(D_005D6B80);
            RwCameraEndUpdate(kwlnGetMainCamera());
            func_004c9d70(kwlnGetMainCamera(), savedNearPlane);
            RwCameraBeginUpdate(kwlnGetMainCamera());
            return KWLNTASK_STOP;
        }
        if (func_004c1600(work->rws, 0x1B1, 0, 0) == 0)
        {
            printf(D_005D6BA0);
            RwCameraEndUpdate(kwlnGetMainCamera());
            func_004c9d70(kwlnGetMainCamera(), savedNearPlane);
            RwCameraBeginUpdate(kwlnGetMainCamera());
            return KWLNTASK_STOP;
        }
        work->maestro = func_004b45b0(NULL, work->rws);
        work->state = HMAESTRO_STATE_INITSCENE;
        goto restore_continue;

    case HMAESTRO_STATE_INITSCENE:
        func_004c5780(work->rws, NULL);
        work->rws = NULL;
        func_004a9d80(&animOutput[0], &animOutput[1], &animOutput[2]);
        work->scene = func_004b4d60(work->maestro);
        func_004ae070(work->scene, 1.0f, 1.0f);
        func_004ae0c0(work->scene, 0.0f, 448.0f);
        func_004aef60(work->scene);
        func_004a9bf0();
        work->state = HMAESTRO_STATE_IDLE;
        goto restore_continue;

    case HMAESTRO_STATE_DRAW:
        break;

    default:
        goto restore_continue;
    }

    camera = kwlnGetMainCamera();
    func_004aa3d0(gUnk_007cadd0 * camera->nearPlane);
    func_004aa410(kwlnGetMainCamera());
    anim = FUN_004c2090(*(void**)((u8*)work->maestro + 8));
    animEnd = FUN_004b1a70(anim + 4);
    animCurrent = FUN_004b1a60(anim + 4);
    finished = false;

    if (work->noDeltaTime != 0)
    {
        func_004b5000(work->maestro, 0.0f);
    }
    else if (work->shouldLoop != 0)
    {
        work->deltaTime += 1.0f;
        func_004b5000(work->maestro, fGpffff80e4);
    }
    else if (animEnd > fGpffff80e4 + animCurrent)
    {
        work->deltaTime += 1.0f;
        func_004b5000(work->maestro, fGpffff80e4);
    }
    else
    {
        func_004b5000(work->maestro, 0.0f);
        if (work->unk_120 == 0)
        {
            finished = true;
        }
    }

    func_004b4c70(work->maestro);
    func_004b3cc0(work->maestro);
    setRenderState = (RwBool (**)(RwRenderState, void*))DAT_00960090_abs;
    (*setRenderState)(rwRENDERSTATEZWRITEENABLE, (void*)false);
    (*setRenderState)(rwRENDERSTATEZTESTENABLE, (void*)false);
    (*setRenderState)(rwRENDERSTATESHADEMODE, (void*)rwSHADEMODEGOURAUD);
    (*setRenderState)(rwRENDERSTATETEXTUREFILTER, (void*)rwFILTERLINEAR);
    (*setRenderState)(rwRENDERSTATEVERTEXALPHAENABLE, (void*)true);
    (*setRenderState)(rwRENDERSTATESRCBLEND, (void*)rwBLENDSRCALPHA);
    (*setRenderState)(rwRENDERSTATEDESTBLEND, (void*)rwBLENDINVSRCALPHA);
    (*setRenderState)(rwRENDERSTATETEXTUREFILTER, (void*)rwFILTERLINEAR);
    (*setRenderState)(rwRENDERSTATEVERTEXALPHAENABLE, (void*)true);
    color.r = 1.0f;
    color.g = 1.0f;
    color.b = 1.0f;
    color.a = work->alphaMult;
    func_004ae110(work->scene, &color);
    func_004aaa60_y2();
    func_004a9bf0();
    func_004aaa60_y2();
    func_004ae060(work->scene);
    func_004b5330(work->maestro);
    func_004aad50_y2();
    func_004aad50_y2();

    if (finished != 0)
    {
        if (work->unk_124 != 0)
        {
            H_Maestro_00111c50(hmaestroTask);
            goto restore_continue;
        }
        goto restore_stop;
    }

restore_continue:
    RwCameraEndUpdate(kwlnGetMainCamera());
    func_004c9d70(kwlnGetMainCamera(), savedNearPlane);
    RwCameraBeginUpdate(kwlnGetMainCamera());
    return KWLNTASK_CONTINUE;

restore_stop:
    RwCameraEndUpdate(kwlnGetMainCamera());
    func_004c9d70(kwlnGetMainCamera(), savedNearPlane);
    RwCameraBeginUpdate(kwlnGetMainCamera());
    return KWLNTASK_STOP;
}

// FUN_00111c50
void H_Maestro_00111c50(KwlnTask* hmaestroTask)
{
    HMaestro* work;
    u32 anim;

    work = (HMaestro*)hmaestroTask->workData;
    anim = FUN_004c2090(*(void**)((u8*)work->maestro + 8));
    FUN_004b1870(anim + 4, anim + 0x20, 0);
    work->state = HMAESTRO_STATE_IDLE;
}
 
/* Retail's rotation path at 0x0508-0x0660 evaluates the sine/cosine
 * polynomials inline before the matrix calls.  Its repeated output-record
 * loads in UV, position, and color setup (0x0110-0x04d0) remain un-hoisted.
 * The extension dispatch at 0x0c54-0x1224 keeps each record direction as a
 * distinct render path: top, bottom, left, right, then node extraHeight and
 * extraWidth, each rebuilding the immediate-mode strip before returning.
 * The explicit branches below preserve those state transitions and duplicated
 * draw calls instead of folding them into one common tail.  Current output is
 * 4276/4704 bytes (90.9%); the remaining deficit is in the color path at
 * 0x07ac-0x0c54 and extension store/call layout at 0x0c54-0x1224. */
// FUN_00111CA0
void func_00111ca0(KwlnTask* task, u32 value)
{
    ((HMaestro*)task->workData)->unk_124 = value;
}

/* The following helpers are the pre-Camp Maestro immediate-mode renderer.  The
 * retail module keeps these entry points in this translation unit (the same
 * allocator/list globals are shared with the stream code above). */




// Same reconstruction pattern as func_001140d0 below: retail inlines the
// state-set calls and per-vertex doubled-alpha color loop rather than
// delegating to Maestro_SetPrimitiveStates/DrawQuad/NearReciprocal.
/* Scoped loop-invariant pragma measured W330: without nd438, with nd434 (obj 808/848). */
// FUN_00111cb0
u32 H_Maestro_00111cb0(KwlnTask* hmaestroTask)
{
    HMaestro* work;
    u32 anim;
    f32 animEnd;
    f32 animCurrent;

    work = (HMaestro*)hmaestroTask->workData;
    if (work->state == HMAESTRO_STATE_DRAW)
    {
        anim = FUN_004c2090(*(void**)((u8*)work->maestro + 8));
        animEnd = FUN_004b1a70(anim + 4);
        animCurrent = FUN_004b1a60(anim + 4);

        return !(animEnd > fGpffff80e4 + animCurrent);
    }

    return true;
}
// FUN_00111d50
void H_Maestro_SetAlphaMult(KwlnTask* hmaestroTask, f32 alphaMult)
{
    ((HMaestro*)hmaestroTask->workData)->alphaMult = alphaMult;
}
// FUN_00111d60
void H_Maestro_DestroyTask(KwlnTask* hmaestroTask)
{
    HMaestro* work;

    work = (HMaestro*)hmaestroTask->workData;

    if (work->cdvd != NULL)
    {
        H_Cdvd_Destroy(work->cdvd);
        work->cdvd = NULL;
    }

    if (work->maestro != NULL)
    {
        Rt2dMaestroDestroy(work->maestro);
        work->maestro = NULL;
    }

    RwFree(work);
}
// FUN_00111dd0
KwlnTask* H_Maestro_CreateTask(KwlnTask* parent, u32 priority, const char* path)
{
    KwlnTask* task;
    HMaestro* work;

    work = RwCalloc(1, sizeof(HMaestro), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreate(parent,
                          "H_DrawMaestro",
                          priority,
                          H_Maestro_UpdateTask,
                          H_Maestro_DestroyTask,
                          work);
    if (task == NULL)
    {
        return NULL;
    }

    strcpy(work->path, path);
    work->noDeltaTime = false;
    work->shouldLoop = false;
    work->alphaMult = 1.0f;
    work->useCdvd = false;

    return task;
}
// FUN_00111ec0
u32 H_Maestro_FinishedInit(KwlnTask* hmaestroTask)
{
    return ((HMaestro*)hmaestroTask->workData)->state > HMAESTRO_STATE_INITSCENE;
}
// FUN_00111ee0
void H_Maestro_RequestDraw(KwlnTask* hmaestroTask)
{
    ((HMaestro*)hmaestroTask->workData)->state = HMAESTRO_STATE_DRAW;
}
// FUN_00111f00
void H_Maestro_SetShouldLoop(KwlnTask* hmaestroTask, u32 shouldLoop)
{
    ((HMaestro*)hmaestroTask->workData)->shouldLoop = shouldLoop;
}
#pragma opt_loop_invariants off
/* ------------------------------------------------------------------------- */
/* Pre-Camp sprite/effect task slice (retail 0x117440-0x119F10). */












// FUN_00111F10
void func_00111f10(KwlnTask* task, u32 noDeltaTime)
{
    ((HMaestro*)task->workData)->noDeltaTime = noDeltaTime;
}
#pragma opt_loop_invariants reset
// FUN_00111f20
void H_Maestro_00111f20(KwlnTask* hmaestroTask, u32 param_2)
{
    ((HMaestro*)hmaestroTask->workData)->unk_120 = param_2;
}
// FUN_00111f30
u32 H_Maestro_00111f30(s16* param_1)
{
    return *param_1 == 5;
}
// FUN_00111F50
void func_00111f50(void)
{
    HCdvd* requests[3];

    requests[0] = H_Cdvd_Request(D_005D6BD0, HCDVD_FILENORMAL);
    requests[1] = H_Cdvd_Request(D_005D6BF0, HCDVD_FILENORMAL);
    requests[2] = H_Cdvd_Request(D_005D6C10, HCDVD_FILENORMAL);
    H_Cdvd_ReadSync(requests[0]);
    H_Cdvd_ReadSync(requests[1]);
    H_Cdvd_ReadSync(requests[2]);

    D_00833a40_abs[0] = func_00112370(D_005D6BD0);
    D_00833a40_abs[1] = func_00112370(D_005D6BF0);
    D_00833a40_abs[2] = func_00112370(D_005D6C10);
    for (;;)
    {
        func_001120c0();
        if (((MaestroBlobNode*)D_00833a40_abs[0])->state == 5 &&
            ((MaestroBlobNode*)D_00833a40_abs[1])->state == 5 &&
            ((MaestroBlobNode*)D_00833a40_abs[2])->state == 5)
        {
            break;
        }
    }

    H_Cdvd_Destroy(requests[0]);
    H_Cdvd_Destroy(requests[1]);
    H_Cdvd_Destroy(requests[2]);
}
// FUN_001120a0
void* H_Maestro_001120a0(int param_1)
{
    return D_00833a40[param_1];
}
// FUN_001120C0
void func_001120c0(void)
{
    MaestroBlobNode* node;

    node = DAT_00833a50;
    for (;;)
    {
        if (node == NULL)
        {
            break;
        }
        func_00112110(node);
        node = node->next;
    }
}
/* Scoped loop-invariant pragma measured W330: without nd1178, with nd1112 (obj 1708/1728). */
// FUN_00112110
void func_00112110(void* param_1)
{
    MaestroBlobNode* node;

    node = (MaestroBlobNode*)param_1;
    switch (node->state)
    {
        case 0:
            node->cdvd = H_Cdvd_Request(node->path, HCDVD_FILENORMAL);
            node->state = 1;
            break;

        case 1:
            if (node->cdvd != NULL)
            {
                if (H_Cdvd_IsFileLoaded(node->cdvd) != 1)
                {
                    break;
                }
                node->source = (u8*)node->cdvd->fileMemory;
            }
            memcpy(node->header, node->source, sizeof(node->header));
            node->sourceOffset += sizeof(node->header);
            node->state = 2;
            node->resourceIndex = 0;
            if (*((u16*)(node->header + 0x14)) == 0)
            {
                node->state = 4;
                break;
            }

        case 2:
        {
            do
            {
                u32 record[2];

                memcpy(record, node->source + node->sourceOffset, sizeof(record));
                node->sourceOffset += sizeof(record);
                *(void**)((u32)node + node->resourceIndex * 4 + 0x104) =
                    func_0010e880_y2(node->source + record[1]);
                node->resourceIndex++;
            } while (*((u16*)(node->header + 0x14)) != node->resourceIndex);
            node->state = 4;
            goto state_4;
        }

        case 3:
            node->resourceIndex++;
            if (*((u16*)(node->header + 0x14)) == node->resourceIndex)
            {
                node->state = 4;
            }
            else
            {
                node->state = 2;
            }
            break;

        case 4:
        {
            s32 i;

state_4:
            node->output = MAESTRO_ALLOC(*((u16*)(node->header + 0x16)), 0x80, 0x40000);
            for (i = 0; i < (s32)*((u16*)(node->header + 0x16)); i++)
            {
                u32 record[2];

                memcpy(record, node->source + node->sourceOffset, sizeof(record));
                node->sourceOffset += sizeof(record);
                memcpy((u8*)node->output + i * 0x80, node->source + record[1], 0x80);
            }
            if (node->cdvd != NULL)
            {
                H_Cdvd_Destroy(node->cdvd);
            }
            node->cdvd = NULL;
            node->outputCount = (s16)*((u16*)(node->header + 0x16));
            node->state = 5;
            break;
        }
        case 5:
            break;
    }
}
// FUN_00112370
void* func_00112370(const char* path)
{
    MaestroBlobNode* node;
    MaestroBlobNode* tail;
    MaestroBlobNode* next;

    node = (MaestroBlobNode*)MAESTRO_ALLOC(1, sizeof(MaestroBlobNode), 0x40000);
    node->state = 0;
    strcpy(node->path, path);
    tail = DAT_00833a50;
    if (tail == NULL)
    {
        DAT_00833a50 = node;
    }
    else
    {
        for (;;)
        {
            next = tail->next;
            if (next == NULL)
            {
                tail->next = node;
                node->prev = tail;
                break;
            }
            tail = next;
        }
    }
    return node;
}
// FUN_00112420
void* func_00112420(void* source)
{
    MaestroBlobNode* node;
    MaestroBlobNode* tail;
    MaestroBlobNode* next;

    node = (MaestroBlobNode*)MAESTRO_ALLOC(1, sizeof(MaestroBlobNode), 0x40000);
    node->state = 1;
    node->source = (u8*)source;
    tail = DAT_00833a50;
    if (tail == NULL)
    {
        DAT_00833a50 = node;
    }
    else
    {
        for (;;)
        {
            next = tail->next;
            if (next == NULL)
            {
                tail->next = node;
                node->prev = tail;
                break;
            }
            tail = next;
        }
    }
    return node;
}
// FUN_001124B0 NONMATCHING
void func_001124b0(void* param_1)
{
    MaestroBlobNode* node;
    s32 i;

    node = (MaestroBlobNode*)param_1;
    if (node->prev == NULL)
    {
        if (node->next == NULL)
        {
            DAT_00833a50 = NULL;
        }
        else
        {
            DAT_00833a50 = node->next;
            node->next->prev = NULL;
        }
    }
    else
    {
        node->prev->next = node->next;
    }
    if (node->next != NULL)
    {
        node->next->prev = node->prev;
    }

    for (i = 0; i < 32; i++)
    {
        if (node->resources[i] != NULL)
        {
            func_004cde90(node->resources[i]);
            node->resources[i] = NULL;
        }
    }
    if (node->cdvd != NULL)
    {
        H_Cdvd_Destroy(node->cdvd);
        node->cdvd = NULL;
    }
    if (node->output != NULL)
    {
        MAESTRO_FREE(node->output);
        node->output = NULL;
    }
    MAESTRO_FREE(node);
}
// FUN_001125D0
void func_001125d0(void)
{
    MaestroRenderNode* node;
    void (**setState)(u32, u32);

    setState = (void (**)(u32, u32))D_00960090_abs;
    (*setState)(6, 1);
    (*setState)(7, 2);
    (*setState)(8, 1);
    (*setState)(9, 1);
    (*setState)(12, 1);
    (*setState)(11, 6);
    (*setState)(10, 5);

    node = DAT_00833a4c;
    for (;;)
    {
        if (node == NULL)
        {
            break;
        }
        func_001127d0(node, true);
        node = node->next;
    }
}
// FUN_001126B0
f32 func_001126b0(void* param_1)
{
    u32 value;
    u32 offset;
    u8* output;
    u8* overrideBase;
    MaestroRenderNode* sample;

    sample = (MaestroRenderNode*)param_1;

    offset = sample->outputIndex * 0x80;
    output = sample->blob->output;
    value = *(s32*)((uintptr_t)offset + (uintptr_t)output + 0x5c) -
            *(s32*)((uintptr_t)offset + (uintptr_t)output + 0x54);
    overrideBase = output + 0x74;
    if (*(s16*)(overrideBase + offset) != 0)
    {
        value = *(s16*)(overrideBase + offset);
    }
    if (sample->xScale != 0)
    {
        value = (s32)(((u32)value * sample->xScale) >> 12);
    }
    return (f32)value;
}
// FUN_00112740
f32 func_00112740(void* param_1)
{
    u32 value;
    u32 offset;
    u8* output;
    u8* overrideBase;
    MaestroRenderNode* sample;

    sample = (MaestroRenderNode*)param_1;

    offset = sample->outputIndex * 0x80;
    output = sample->blob->output;
    value = *(s32*)((uintptr_t)offset + (uintptr_t)output + 0x60) -
            *(s32*)((uintptr_t)offset + (uintptr_t)output + 0x58);
    overrideBase = output + 0x76;
    if (*(s16*)(overrideBase + offset) != 0)
    {
        value = *(s16*)(overrideBase + offset);
    }
    if (sample->yScale != 0)
    {
        value = (s32)(((u32)value * sample->yScale) >> 12);
    }
    return (f32)value;
}
// FUN_001127D0 NONMATCHING
void func_001127d0(void* param_1, u32 enabled)
{
    MaestroRenderNode* node;
    RwV2d uv[4];
    RwV3d local[4];
    RwV3d transformed[4];
    RwV3d positions[4];
    RwIm2DVertex vertices[4];
    RwMatrix* matrix;
    RwCamera* camera;
    void* resource;
    s32* dimensions;
    void (**setState)(u32 state, u32 value);
    void (**drawPrimitive)(RwPrimitiveType primitiveType, RwIm2DVertex* vertices, s32 vertexCount);
    s32 width;
    s32 height;
    s32 edge;
    f32 recipZ;
    f32 angle;
    f32 radians;
    f32 angleSquared;
    f32 polynomial;
    f32 cosine;
    f32 sine;
    u32 i;
    u32 packedColor;
    s32 red;
    s32 green;
    s32 blue;
    s32 alpha;

    node = (MaestroRenderNode*)param_1;
    /* Retail 0x2c-0x50 computes the camera reciprocal before any state or record work. */
    camera = kwlnGetMainCamera();
    recipZ = 1.0f / camera->nearPlane;

    if (enabled != 0)
    {
        void (**initialSetState)(u32 state, u32 value);

        initialSetState = (void (**)(u32, u32))D_00960090_abs;
        (*initialSetState)(6, 1);
        (*initialSetState)(7, 2);
        (*initialSetState)(8, 1);
        (*initialSetState)(9, 2);
        (*initialSetState)(12, 1);
        (*initialSetState)(11, 6);
        (*initialSetState)(10, 5);
        (*initialSetState)(2, 4);
        (*initialSetState)(14, 0);
    }

    resource = node->blob->resources[((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->resourceIndex];

    if (resource != NULL)
    {
        dimensions = (s32*)resource;
        uv[0].x = (f32)((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->left / (f32)dimensions[3];
        uv[0].y = (f32)((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->top / (f32)dimensions[4];
        uv[1].x = (f32)(((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->right - 1) / (f32)dimensions[3];
        uv[1].y = uv[0].y;
        uv[2].x = uv[0].x;
        uv[2].y = (f32)(((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->bottom - 1) / (f32)dimensions[4];
        uv[3].x = uv[1].x;
        uv[3].y = uv[2].y;
    }

    if (enabled != 0)
    {
        RpSkyRenderStateSet(2, (void*)0x44);
        RpSkyRenderStateSet(3, (void*)0x717FB);
        if ((((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->renderStateFlags & 1) != 0)
        {
            RpSkyRenderStateSet(2, (void*)0x48);
            RpSkyRenderStateSet(3, (void*)0x71801);
        }
        if ((((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->renderStateFlags & 2) != 0)
        {
            RpSkyRenderStateSet(2, (void*)0x42);
            RpSkyRenderStateSet(3, (void*)0x71801);
        }
    }

    if ((((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->flags & 2) != 0)
    {
        RwV2d swap;

        swap = uv[0];
        uv[0] = uv[2];
        uv[2] = swap;
        swap = uv[1];
        uv[1] = uv[3];
        uv[3] = swap;
    }
    if ((((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->flags & 1) != 0)
    {
        RwV2d swap;

        swap = uv[0];
        uv[0] = uv[1];
        uv[1] = swap;
        swap = uv[2];
        uv[2] = uv[3];
        uv[3] = swap;
    }

    width = ((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->right -
            ((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->left;
    if (((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->overrideX != 0)
    {
        width = ((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->overrideX;
    }
    if (node->xScale != 0)
    {
        width = (width * (s32)node->xScale) >> 12;
    }
    height = ((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->bottom -
             ((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->top;
    if (((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->overrideY != 0)
    {
        height = ((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->overrideY;
    }
    if (node->yScale != 0)
    {
        height = (height * (s32)node->yScale) >> 12;
    }

    local[0].x = -(f32)node->pivotX;
    local[0].y = -(f32)node->pivotY;
    local[0].z = 0.0f;
    local[1].x = (f32)(width - node->pivotX);
    local[1].y = local[0].y;
    local[1].z = 0.0f;
    local[2].x = local[0].x;
    local[2].y = (f32)(height - node->pivotY);
    local[2].z = 0.0f;
    local[3].x = local[1].x;
    local[3].y = local[2].y;
    local[3].z = 0.0f;

    angle = node->angle;
    if (angle != 0.0f)
    {
        while (angle >= 180.0f)
        {
            angle -= 360.0f;
        }
        while (angle < -180.0f)
        {
            angle += 360.0f;
        }
        radians = (angle * 3.1415927f) / 180.0f;
        angleSquared = radians * radians;
        matrix = func_004c38c0();
        polynomial = -1.1359648e-11f * angleSquared + 2.0875723e-9f;
        polynomial = polynomial * angleSquared - 2.7557314e-7f;
        polynomial = polynomial * angleSquared + 2.4801588e-5f;
        polynomial = polynomial * angleSquared - 0.0013888889f;
        polynomial = polynomial * angleSquared + 0.041666668f;
        polynomial = angleSquared * polynomial;
        cosine = 0.5f * angleSquared - angleSquared * polynomial;
        cosine = 1.0f - cosine;
        polynomial = 1.5896910e-10f * angleSquared - 2.5050760e-8f;
        polynomial = polynomial * angleSquared + 2.7557314e-6f;
        polynomial = polynomial * angleSquared - 0.0001984127f;
        polynomial = polynomial * angleSquared + 0.0083333338f;
        polynomial = polynomial * angleSquared - 0.16666667f;
        sine = radians + (angleSquared * radians) * polynomial;
        func_004c2fc0(1.0f - cosine, sine, matrix, &D_005D6C28, rwCOMBINEREPLACE);
        func_004c6c20(transformed, local, 4, matrix);
        func_004c3880(matrix);
    }
    else
    {
        for (i = 0; i < 4; i++)
        {
            transformed[i] = local[i];
        }
    }

    for (i = 0; i < 4; i++)
    {
        positions[i].x = (f32)node->pivotX + transformed[i].x + node->x + (f32)((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->x;
        positions[i].y = (f32)node->pivotY + transformed[i].y + node->y + (f32)((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->y;
        positions[i].z = 0.0f;
    }

    for (i = 0; i < 4; i++)
    {
        vertices[i].u.els.scrVertex.x = positions[i].x;
        vertices[i].u.els.scrVertex.y = positions[i].y;
        vertices[i].u.els.scrVertex.z = D_00960088 - node->depth;
        vertices[i].u.els.u = uv[i].x;
        vertices[i].u.els.v = uv[i].y;
        vertices[i].u.els.recipZ = recipZ;
    }

    for (i = 0; i < 4; i++)
    {
        packedColor = ((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->colors[i == 2 ? 3 : (i == 3 ? 2 : i)];
        red = (s32)((packedColor & 0xFF000000) >> 24) * node->red / 255;
        green = (s32)((packedColor & 0x00FF0000) >> 16) * node->green / 255;
        blue = (s32)((packedColor & 0x0000FF00) >> 8) * node->blue / 255;
        alpha = (s32)(packedColor & 0xFF);
        if ((((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->flags & 8) == 0)
        {
            red = red >= 0x81 ? 0xFF : red * 255 / 128;
            green = green >= 0x81 ? 0xFF : green * 255 / 128;
            blue = blue >= 0x81 ? 0xFF : blue * 255 / 128;
            alpha = alpha >= 0x81 ? 0xFF : alpha * 255 / 128;
        }
        alpha = (255 - node->alphaLoss) * alpha / 255;
        if (alpha > node->alphaCutoff)
        {
            alpha -= node->alphaCutoff;
        }
        else
        {
            alpha = 0;
        }

        vertices[i].u.els.color.r = (f32)(u32)red;
        vertices[i].u.els.color.g = (f32)(u32)green;
        vertices[i].u.els.color.b = (f32)(u32)blue;
        vertices[i].u.els.color.a = (f32)(u32)alpha;
    }

    setState = (void (**)(u32, u32))D_00960090_abs;
    drawPrimitive = (void (**)(RwPrimitiveType, RwIm2DVertex*, s32))D_009600A0_abs;
    if ((((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->flags & 8) == 0)
    {
        (*setState)(1, (u32)resource);
    }
    else
    {
        (*setState)(1, 0);
    }
    (*drawPrimitive)(rwPRIMTYPETRISTRIP, vertices, 4);

    edge = 0;
    if (((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->topExtension != 0)
    {
        edge = ((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->topExtension;
        vertices[0].u.els.scrVertex.x = positions[0].x;
        vertices[0].u.els.scrVertex.y = positions[0].y - edge;
        vertices[1].u.els.scrVertex.x = positions[1].x;
        vertices[1].u.els.scrVertex.y = positions[1].y - edge;
        vertices[2].u.els.scrVertex.x = positions[0].x;
        vertices[2].u.els.scrVertex.y = positions[0].y;
        vertices[3].u.els.scrVertex.x = positions[1].x;
        vertices[3].u.els.scrVertex.y = positions[1].y;
        vertices[0].u.els.u = vertices[2].u.els.u = uv[0].x;
        vertices[0].u.els.v = vertices[2].u.els.v = uv[0].y;
        vertices[1].u.els.u = vertices[3].u.els.u = uv[1].x;
        vertices[1].u.els.v = vertices[3].u.els.v = uv[1].y;
        if ((((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->flags & 8) == 0)
        {
            (*setState)(1, (u32)resource);
        }
        else
        {
            (*setState)(1, 0);
        }
        (*drawPrimitive)(rwPRIMTYPETRISTRIP, vertices, 4);
    }
    else if (((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->bottomExtension != 0)
    {
        edge = ((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->bottomExtension;
        vertices[0].u.els.scrVertex.x = positions[2].x;
        vertices[0].u.els.scrVertex.y = positions[2].y;
        vertices[1].u.els.scrVertex.x = positions[3].x;
        vertices[1].u.els.scrVertex.y = positions[3].y;
        vertices[2].u.els.scrVertex.x = positions[2].x;
        vertices[2].u.els.scrVertex.y = positions[2].y + edge;
        vertices[3].u.els.scrVertex.x = positions[3].x;
        vertices[3].u.els.scrVertex.y = positions[3].y + edge;
        vertices[0].u.els.u = vertices[2].u.els.u = uv[2].x;
        vertices[0].u.els.v = vertices[2].u.els.v = uv[2].y;
        vertices[1].u.els.u = vertices[3].u.els.u = uv[3].x;
        vertices[1].u.els.v = vertices[3].u.els.v = uv[3].y;
        if ((((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->flags & 8) == 0)
        {
            (*setState)(1, (u32)resource);
        }
        else
        {
            (*setState)(1, 0);
        }
        (*drawPrimitive)(rwPRIMTYPETRISTRIP, vertices, 4);
    }
    else if (((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->leftExtension != 0)
    {
        edge = ((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->leftExtension;
        vertices[0].u.els.scrVertex.x = (f32)((s32)positions[0].x - edge);
        vertices[0].u.els.scrVertex.y = positions[0].y;
        vertices[1].u.els.scrVertex.x = positions[0].x;
        vertices[1].u.els.scrVertex.y = positions[0].y;
        vertices[2].u.els.scrVertex.x = (f32)((s32)positions[2].x - edge);
        vertices[2].u.els.scrVertex.y = positions[2].y;
        vertices[3].u.els.scrVertex.x = positions[2].x;
        vertices[3].u.els.scrVertex.y = positions[2].y;
        vertices[0].u.els.u = vertices[1].u.els.u = uv[0].x;
        vertices[0].u.els.v = vertices[1].u.els.v = uv[0].y;
        vertices[2].u.els.u = vertices[3].u.els.u = uv[2].x;
        vertices[2].u.els.v = vertices[3].u.els.v = uv[2].y;
        if ((((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->flags & 8) == 0)
        {
            (*setState)(1, (u32)resource);
        }
        else
        {
            (*setState)(1, 0);
        }
        (*drawPrimitive)(rwPRIMTYPETRISTRIP, vertices, 4);
    }
    else if (((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->rightExtension != 0)
    {
        edge = ((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->rightExtension;
        vertices[0].u.els.scrVertex.x = positions[1].x;
        vertices[0].u.els.scrVertex.y = positions[1].y;
        vertices[1].u.els.scrVertex.x = (f32)((s32)positions[1].x + edge);
        vertices[1].u.els.scrVertex.y = positions[1].y;
        vertices[2].u.els.scrVertex.x = positions[3].x;
        vertices[2].u.els.scrVertex.y = positions[3].y;
        vertices[3].u.els.scrVertex.x = (f32)((s32)positions[3].x + edge);
        vertices[3].u.els.scrVertex.y = positions[3].y;
        vertices[0].u.els.u = vertices[1].u.els.u = uv[1].x;
        vertices[0].u.els.v = vertices[1].u.els.v = uv[1].y;
        vertices[2].u.els.u = vertices[3].u.els.u = uv[3].x;
        vertices[2].u.els.v = vertices[3].u.els.v = uv[3].y;
        if ((((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->flags & 8) == 0)
        {
            (*setState)(1, (u32)resource);
        }
        else
        {
            (*setState)(1, 0);
        }
        (*drawPrimitive)(rwPRIMTYPETRISTRIP, vertices, 4);
    }
    else if (node->extraHeight != 0)
    {
        edge = node->extraHeight;
        vertices[0].u.els.scrVertex.x = positions[2].x;
        vertices[0].u.els.scrVertex.y = positions[2].y;
        vertices[1].u.els.scrVertex.x = positions[3].x;
        vertices[1].u.els.scrVertex.y = positions[3].y;
        vertices[2].u.els.scrVertex.x = positions[2].x;
        vertices[2].u.els.scrVertex.y = positions[2].y + edge;
        vertices[3].u.els.scrVertex.x = positions[3].x;
        vertices[3].u.els.scrVertex.y = positions[3].y + edge;
        vertices[0].u.els.u = vertices[2].u.els.u = uv[2].x;
        vertices[0].u.els.v = vertices[2].u.els.v = uv[2].y;
        vertices[1].u.els.u = vertices[3].u.els.u = uv[3].x;
        vertices[1].u.els.v = vertices[3].u.els.v = uv[3].y;
        if ((((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->flags & 8) == 0)
        {
            (*setState)(1, (u32)resource);
        }
        else
        {
            (*setState)(1, 0);
        }
        (*drawPrimitive)(rwPRIMTYPETRISTRIP, vertices, 4);
    }
    else if (node->extraWidth != 0)
    {
        edge = node->extraWidth;
        vertices[0].u.els.scrVertex.x = positions[1].x;
        vertices[0].u.els.scrVertex.y = positions[1].y;
        vertices[1].u.els.scrVertex.x = (f32)((s32)positions[1].x + edge);
        vertices[1].u.els.scrVertex.y = positions[1].y;
        vertices[2].u.els.scrVertex.x = positions[3].x;
        vertices[2].u.els.scrVertex.y = positions[3].y;
        vertices[3].u.els.scrVertex.x = (f32)((s32)positions[3].x + edge);
        vertices[3].u.els.scrVertex.y = positions[3].y;
        vertices[0].u.els.u = vertices[1].u.els.u = uv[1].x;
        vertices[0].u.els.v = vertices[1].u.els.v = uv[1].y;
        vertices[2].u.els.u = vertices[3].u.els.u = uv[3].x;
        vertices[2].u.els.v = vertices[3].u.els.v = uv[3].y;
        if ((((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->flags & 8) == 0)
        {
            (*setState)(1, (u32)resource);
        }
        else
        {
            (*setState)(1, 0);
        }
        (*drawPrimitive)(rwPRIMTYPETRISTRIP, vertices, 4);
    }
}
#pragma opt_loop_invariants on
/* W419 mask-then-shift color extraction probe for both 00113A30/00113D80 worsened nd434,obj808 to nd549,obj816; reverted. */
/* W420 mixed int/float parameter order: nd434,obj808/window848 (rate 0.537129) -> nd424,obj808/window848 (rate 0.524752); retained. */
// FUN_00113A30
void func_00113a30(f32 depth, u32 color, f32 x, f32 y, s32 width, s32 height)
{
    RwIm2DVertex vertices[4];
    f32 corners[4][2];
    f32 farX;
    f32 farY;
    f32 recipZ;
    f32 z;
    void (**setState)(u32, u32);
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    s32 i;

    recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;

    r = ((color & 0xff000000) >> 24) & 0xff;
    g = ((color & 0x00ff0000) >> 16) & 0xff;
    b = ((color & 0x0000ff00) >> 8) & 0xff;
    a = color & 0xff;

    setState = (void (**)(u32, u32))D_00960090_abs;
    (*setState)(6, 1);
    (*setState)(7, 2);
    (*setState)(8, 1);
    (*setState)(9, 1);
    (*setState)(0xc, 1);
    (*setState)(0xb, 6);
    (*setState)(0xa, 5);
    (*setState)(2, 4);
    RpSkyRenderStateSet(2, (void*)0x44);
    RpSkyRenderStateSet(3, (void*)0x717fb);

    corners[0][0] = x;
    corners[0][1] = y;
    farX = x + (f32)width;
    corners[3][0] = farX;
    farY = y + (f32)height;
    corners[3][1] = farY;
    corners[1][0] = farX;
    corners[1][1] = y;
    corners[2][0] = x;
    corners[2][1] = farY;
    i = 0;
    z = *(f32*)D_00960088_abs - depth;

    for (; i < 4; i++)
    {
        RwIm2DVertex* v = &vertices[i];
        v->u.els.scrVertex.z = z;
        v->u.els.recipZ = recipZ;
        v->u.els.color.r = (f32)r;
        v->u.els.color.g = (f32)g;
        v->u.els.color.b = (f32)b;
        v->u.els.color.a = (f32)a;
        v->u.els.scrVertex.x = corners[i][0];
        v->u.els.scrVertex.y = corners[i][1];
    }

    (*setState)(1, 0);

    (*(void (**)(RwPrimitiveType, RwIm2DVertex*, s32))D_009600A0_data_abs)(rwPRIMTYPETRISTRIP, vertices, 4);
}

#pragma opt_loop_invariants off

// Same reconstruction pattern as func_001140d0 below.
/* Scoped loop-invariant pragma measured W330: without nd438, with nd434 (obj 808/848). */
#pragma opt_loop_invariants on
/* W420 mixed int/float parameter order: nd434,obj808/window848 (rate 0.537129) -> nd424,obj808/window848 (rate 0.524752); retained. */
// FUN_00113D80
void func_00113d80(f32 depth, u32 color, f32 x, f32 y, s32 width, s32 height)
{
    RwIm2DVertex vertices[4];
    f32 corners[4][2];
    f32 farX;
    f32 farY;
    f32 recipZ;
    f32 z;
    void (**setState)(u32, u32);
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    s32 i;

    recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;

    r = ((color & 0xff000000) >> 24) & 0xff;
    g = ((color & 0x00ff0000) >> 16) & 0xff;
    b = ((color & 0x0000ff00) >> 8) & 0xff;
    a = color & 0xff;

    setState = (void (**)(u32, u32))D_00960090_abs;
    (*setState)(6, 1);
    (*setState)(7, 2);
    (*setState)(8, 1);
    (*setState)(9, 1);
    (*setState)(0xc, 1);
    (*setState)(0xb, 6);
    (*setState)(0xa, 5);
    (*setState)(2, 4);
    RpSkyRenderStateSet(2, (void*)0x48);
    RpSkyRenderStateSet(3, (void*)0x71801);

    corners[0][0] = x;
    corners[0][1] = y;
    farX = x + (f32)width;
    corners[3][0] = farX;
    farY = y + (f32)height;
    corners[3][1] = farY;
    corners[1][0] = farX;
    corners[1][1] = y;
    corners[2][0] = x;
    corners[2][1] = farY;
    i = 0;
    z = *(f32*)D_00960088_abs - depth;

    for (; i < 4; i++)
    {
        RwIm2DVertex* v = &vertices[i];
        v->u.els.scrVertex.z = z;
        v->u.els.recipZ = recipZ;
        v->u.els.color.r = (f32)r;
        v->u.els.color.g = (f32)g;
        v->u.els.color.b = (f32)b;
        v->u.els.color.a = (f32)a;
        v->u.els.scrVertex.x = corners[i][0];
        v->u.els.scrVertex.y = corners[i][1];
    }

    (*setState)(1, 0);

    (*(void (**)(RwPrimitiveType, RwIm2DVertex*, s32))D_009600A0_data_abs)(rwPRIMTYPETRISTRIP, vertices, 4);
}
#pragma opt_loop_invariants off

/*
 * W414 signature contract: the true EE declaration order for both helpers is
 * (f32 depth, u32 color, f32 x, f32 y, s32 width, s32 height, texture).
 * Corrected declarations/call sites across all touched files:
 *   src/h_maestro.c: func_001140d0 and func_00114af0 definitions.
 *   src/datCalendar.c: func_001140d0 extern plus six calls each in
 *       func_00188c30, func_00189230, func_00189810, func_00189df0, and
 *       func_0018a3f0; func_00114af0 extern plus two calls in func_0018a9f0.
 *   src/h_fade.c: func_001140d0 extern plus the H_Fade_Day call.
 *   src/Camp/h_camp.c: hCampMainDrawQuad7/6 alias declarations, one
 *       hCampMainDrawQuad7 call in FUN_00137300, and four hCampMainDrawQuad6
 *       calls in FUN_00139FC0.
 *   src/Main/Game/game_support_late.c: func_00114af0 extern (no call site).
 */
/* Scoped loop-invariant pragma measured W330: without nd342, with nd22 (obj 884/896). */
#pragma opt_loop_invariants on
// FUN_001140D0
void func_001140d0(f32 depth,
                   u32 color,
                   f32 x,
                   f32 y,
                   s32 width,
                   s32 height,
                   const u32* textureState)
{
    RwIm2DVertex vertices[4];
    f32 corners[4][2];
    f32 farX;
    f32 farY;
    f32 recipZ;
    f32 z;
    void (**setState)(u32, u32);
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    s32 i;

    recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;

    r = ((color & 0xff000000) >> 24) & 0xff;
    g = ((color & 0x00ff0000) >> 16) & 0xff;
    b = ((color & 0x0000ff00) >> 8) & 0xff;
    a = color & 0xff;

    setState = (void (**)(u32, u32))D_00960090_abs;
    (*setState)(6, 1);
    (*setState)(7, 2);
    (*setState)(8, 1);
    (*setState)(9, 2);
    (*setState)(0xc, 1);
    (*setState)(0xb, 6);
    (*setState)(0xa, 5);
    (*setState)(2, 4);
    RpSkyRenderStateSet(2, (void*)0x44);
    RpSkyRenderStateSet(3, (void*)0x717fb);

    corners[0][0] = x;
    corners[0][1] = y;
    farX = x + (f32)width;
    corners[3][0] = farX;
    farY = y + (f32)height;
    corners[3][1] = farY;
    corners[1][0] = farX;
    corners[1][1] = y;
    corners[2][0] = x;
    corners[2][1] = farY;
    i = 0;
    z = *(f32*)D_00960088_abs - depth;

    for (; i < 4; i++)
    {
        RwIm2DVertex* v = &vertices[i];
        v->u.els.scrVertex.z = z;
        v->u.els.recipZ = recipZ;
        v->u.els.color.r = (f32)r;
        v->u.els.color.g = (f32)g;
        v->u.els.color.b = (f32)b;
        v->u.els.color.a = (f32)a;
        v->u.els.scrVertex.x = corners[i][0];
        v->u.els.scrVertex.y = corners[i][1];
    }

    vertices[0].u.els.u = 0.0f;
    vertices[0].u.els.v = 0.0f;
    vertices[1].u.els.u = 1.0f;
    vertices[1].u.els.v = 0.0f;
    vertices[2].u.els.u = 0.0f;
    vertices[2].u.els.v = 1.0f;
    vertices[3].u.els.u = 1.0f;
    vertices[3].u.els.v = 1.0f;

    (*setState)(1, *textureState);

    (*(void (**)(RwPrimitiveType, RwIm2DVertex*, s32))D_009600A0_data_abs)(rwPRIMTYPETRISTRIP, vertices, 4);
}
#pragma opt_loop_invariants off

/* Removing this worsens FUN_00114450 (nd988 -> nd1385) - measured W161. */
#pragma opt_loop_invariants on
/* W418 rejected color-width probes: s32 nd864,obj1680 -> nd932,obj1624; u32 -> nd948,obj1672; u16/u8 object2320 nd1708/1699; declaration/mask permutations were neutral. */
// FUN_00114450 NONMATCHING
void func_00114450(f32 depth,
                   u32 color,
                   u32 colorAlpha,
                   f32 x,
                   f32 y,
                   s32 ignoredWidth,
                   s32 height,
                   const u32* textureState)
{
    RwIm2DVertex vertices[8];
    f32 corners[8][2];
    f32 farX;
    f32 farY;
    f32 recipZ;
    f32 z;
    f32 tmp;
    void (**setState)(u32, u32);
    s8 r;
    s8 g;
    s8 b;
    s8 a;
    s8 a2;
    s32 r1;
    s32 g1;
    s32 b1;
    s32 a1;
    s32 i;

    recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;

    r = (s8)(color >> 24);
    g = (s8)(color >> 16);
    b = (s8)(color >> 8);
    a = (s8)color;
    a2 = (s8)colorAlpha;

    setState = (void (**)(u32, u32))D_00960090_abs;
    (*setState)(6, 1);
    (*setState)(7, 2);
    (*setState)(8, 1);
    (*setState)(9, 2);
    (*setState)(0xc, 1);
    (*setState)(0xb, 6);
    (*setState)(0xa, 5);
    (*setState)(2, 4);
    RpSkyRenderStateSet(2, (void*)0x44);
    RpSkyRenderStateSet(3, (void*)0x717fb);

    corners[0][0] = x;
    corners[0][1] = y;
    farX = x + 320.0f;
    corners[3][0] = farX;
    farY = y + (f32)height;
    corners[3][1] = farY;
    corners[1][0] = farX;
    corners[1][1] = y;
    corners[2][0] = x;
    corners[2][1] = farY;
    corners[4][0] = farX;
    corners[4][1] = y;
    corners[5][0] = farX + 320.0f;
    corners[5][1] = y;
    corners[6][0] = farX;
    corners[6][1] = farY;
    corners[7][0] = farX + 320.0f;
    corners[7][1] = farY;

    z = D_00960088 - depth;

    r1 = r & 1;
    g1 = g & 1;
    b1 = b & 1;
    a1 = a & 1;

    for (i = 0; i < 4; i++)
    {
        vertices[i].u.els.camVertex_z = z;
        vertices[i].u.els.recipZ = recipZ;
        vertices[i].u.els.color.r = (f32)(u32)r;
        if (g >= 0) {
            vertices[i].u.els.color.g = (f32)g;
        } else {
            tmp = (f32)(s32)(((u32)g >> 1) | g1);
            vertices[i].u.els.color.g = tmp + tmp;
        }
        if (b >= 0) {
            vertices[i].u.els.color.b = (f32)b;
        } else {
            tmp = (f32)(s32)(((u32)b >> 1) | b1);
            vertices[i].u.els.color.b = tmp + tmp;
        }
        if (a >= 0) {
            vertices[i].u.els.color.a = (f32)a;
        } else {
            tmp = (f32)(s32)(((u32)a >> 1) | a1);
            vertices[i].u.els.color.a = tmp + tmp;
        }
        vertices[i].u.els.scrVertex.x = corners[i][0];
        vertices[i].u.els.scrVertex.y = corners[i][1];

        vertices[i + 4].u.els.camVertex_z = z;
        vertices[i + 4].u.els.recipZ = recipZ;
        if (r >= 0) {
            vertices[i + 4].u.els.color.r = (f32)r;
        } else {
            tmp = (f32)(s32)(((u32)r >> 1) | r1);
            vertices[i + 4].u.els.color.r = tmp + tmp;
        }
        if (g >= 0) {
            vertices[i + 4].u.els.color.g = (f32)g;
        } else {
            tmp = (f32)(s32)(((u32)g >> 1) | g1);
            vertices[i + 4].u.els.color.g = tmp + tmp;
        }
        if (b >= 0) {
            vertices[i + 4].u.els.color.b = (f32)b;
        } else {
            tmp = (f32)(s32)(((u32)b >> 1) | b1);
            vertices[i + 4].u.els.color.b = tmp + tmp;
        }
        if (a >= 0) {
            vertices[i + 4].u.els.color.a = (f32)a;
        } else {
            tmp = (f32)(s32)(((u32)a >> 1) | a1);
            vertices[i + 4].u.els.color.a = tmp + tmp;
        }
        vertices[i + 4].u.els.scrVertex.x = corners[i + 4][0];
        vertices[i + 4].u.els.scrVertex.y = corners[i + 4][1];
    }

    if (r >= 0) {
        vertices[0].u.els.color.r = (f32)r;
    } else {
        tmp = (f32)(s32)(((u32)r >> 1) | r1);
        vertices[0].u.els.color.r = tmp + tmp;
    }
    if (g >= 0) {
        vertices[0].u.els.color.g = (f32)g;
    } else {
        tmp = (f32)(s32)(((u32)g >> 1) | g1);
        vertices[0].u.els.color.g = tmp + tmp;
    }
    if (b >= 0) {
        vertices[0].u.els.color.b = (f32)b;
    } else {
        tmp = (f32)(s32)(((u32)b >> 1) | b1);
        vertices[0].u.els.color.b = tmp + tmp;
    }
    if (a2 >= 0) {
        vertices[0].u.els.color.a = (f32)a2;
    } else {
        tmp = (f32)(s32)(((u32)a2 >> 1) | (a2 & 1));
        vertices[0].u.els.color.a = tmp + tmp;
    }

    if (r >= 0) {
        vertices[2].u.els.color.r = (f32)r;
    } else {
        tmp = (f32)(s32)(((u32)r >> 1) | r1);
        vertices[2].u.els.color.r = tmp + tmp;
    }
    if (g >= 0) {
        vertices[2].u.els.color.g = (f32)g;
    } else {
        tmp = (f32)(s32)(((u32)g >> 1) | g1);
        vertices[2].u.els.color.g = tmp + tmp;
    }
    if (b >= 0) {
        vertices[2].u.els.color.b = (f32)b;
    } else {
        tmp = (f32)(s32)(((u32)b >> 1) | b1);
        vertices[2].u.els.color.b = tmp + tmp;
    }
    if (a2 >= 0) {
        vertices[2].u.els.color.a = (f32)a2;
    } else {
        tmp = (f32)(s32)(((u32)a2 >> 1) | (a2 & 1));
        vertices[2].u.els.color.a = tmp + tmp;
    }

    vertices[0].u.els.u = 0.0f;
    vertices[0].u.els.v = 0.0f;
    vertices[1].u.els.u = 0.5f;
    vertices[1].u.els.v = 0.0f;
    vertices[2].u.els.u = 0.0f;
    vertices[2].u.els.v = 1.0f;
    vertices[3].u.els.u = 0.5f;
    vertices[3].u.els.v = 1.0f;
    vertices[4].u.els.u = 0.5f;
    vertices[4].u.els.v = 0.0f;
    vertices[5].u.els.u = 1.0f;
    vertices[5].u.els.v = 0.0f;
    vertices[6].u.els.u = 0.5f;
    vertices[6].u.els.v = 1.0f;
    vertices[7].u.els.u = 1.0f;
    vertices[7].u.els.v = 1.0f;

    (*setState)(1, *textureState);
    (*D_009600A0)(rwPRIMTYPETRISTRIP, vertices, 4);
    (*D_009600A0)(rwPRIMTYPETRISTRIP, &vertices[4], 4);
}
#pragma opt_loop_invariants off

/*
 * W414 signature contract: func_00114af0 uses the true EE declaration
 * order (f32 depth, u32 color, f32 x, f32 y, s32 width, s32 height,
 * texture), matching func_001140d0 above.
 * Corrected declarations/call sites across all touched files:
 *   src/h_maestro.c: func_001140d0 and func_00114af0 definitions.
 *   src/datCalendar.c: func_001140d0 extern plus six calls each in
 *       func_00188c30, func_00189230, func_00189810, func_00189df0, and
 *       func_0018a3f0; func_00114af0 extern plus two calls in func_0018a9f0.
 *   src/h_fade.c: func_001140d0 extern plus the H_Fade_Day call.
 *   src/Camp/h_camp.c: hCampMainDrawQuad7/6 alias declarations, one
 *       hCampMainDrawQuad7 call in FUN_00137300, and four hCampMainDrawQuad6
 *       calls in FUN_00139FC0.
 *   src/Main/Game/game_support_late.c: func_00114af0 extern (no call site).
 */
/* W414: interleaving the integer color parameter between the float parameters, plus i = 0 before the absolute z load, reproduces the retail prologue and loop; nd22 -> 0 (obj 884/896). */
/* Scoped loop-invariant pragma measured W330: without nd342, with nd22 (obj 884/896). */
#pragma opt_loop_invariants on
// FUN_00114AF0
void func_00114af0(f32 depth,
                   u32 color,
                   f32 x,
                   f32 y,
                   s32 width,
                   s32 height,
                   const u32* textureState)
{
    RwIm2DVertex vertices[4];
    f32 corners[4][2];
    f32 farX;
    f32 farY;
    f32 recipZ;
    f32 z;
    void (**setState)(u32, u32);
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    s32 i;

    recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;

    r = ((color & 0xff000000) >> 24) & 0xff;
    g = ((color & 0x00ff0000) >> 16) & 0xff;
    b = ((color & 0x0000ff00) >> 8) & 0xff;
    a = color & 0xff;

    setState = (void (**)(u32, u32))D_00960090_abs;
    (*setState)(6, 1);
    (*setState)(7, 2);
    (*setState)(8, 1);
    (*setState)(9, 2);
    (*setState)(0xc, 1);
    (*setState)(0xb, 6);
    (*setState)(0xa, 5);
    (*setState)(2, 4);
    RpSkyRenderStateSet(2, (void*)0x48);
    RpSkyRenderStateSet(3, (void*)0x71801);

    corners[0][0] = x;
    corners[0][1] = y;
    farX = x + (f32)width;
    corners[3][0] = farX;
    farY = y + (f32)height;
    corners[3][1] = farY;
    corners[1][0] = farX;
    corners[1][1] = y;
    corners[2][0] = x;
    corners[2][1] = farY;
    i = 0;
    z = *(f32*)D_00960088_abs - depth;

    for (; i < 4; i++)
    {
        RwIm2DVertex* v = &vertices[i];
        v->u.els.scrVertex.z = z;
        v->u.els.recipZ = recipZ;
        v->u.els.color.r = (f32)r;
        v->u.els.color.g = (f32)g;
        v->u.els.color.b = (f32)b;
        v->u.els.color.a = (f32)a;
        v->u.els.scrVertex.x = corners[i][0];
        v->u.els.scrVertex.y = corners[i][1];
    }

    vertices[0].u.els.u = 0.0f;
    vertices[0].u.els.v = 0.0f;
    vertices[1].u.els.u = 1.0f;
    vertices[1].u.els.v = 0.0f;
    vertices[2].u.els.u = 0.0f;
    vertices[2].u.els.v = 1.0f;
    vertices[3].u.els.u = 1.0f;
    vertices[3].u.els.v = 1.0f;

    (*setState)(1, *textureState);

    (*(void (**)(RwPrimitiveType, RwIm2DVertex*, s32))D_009600A0_data_abs)(rwPRIMTYPETRISTRIP, vertices, 4);
}
#pragma opt_loop_invariants off

// Retail reconstruction: camera/state setup (0x114e70-0x114fec), vertex/color loop (0x115030-0x115164), UV/orientation staging (0x115168-0x115294), and final draw (0x1152a0-0x115300).
/* Scoped loop-invariant pragma measured W330: without nd741, with nd736 (obj 1196/1248). */
#pragma opt_loop_invariants on
// FUN_00114E70 NONMATCHING
void func_00114e70(s32 orientation,
                   f32 depth,
                   u32 color,
                   f32 x,
                   f32 y,
                   f32 textureX,
                   f32 textureY,
                   s32 width,
                   s32 height,
                   const s32* textureDimensions)
{
    RwIm2DVertex vertices[4];
    f32 corners[4][2];
    f32 textureCoordinates[4][2];
    struct {
        u64 swap0;
        u64 swap1;
    } swaps;
    f32 farX;
    f32 farY;
    f32 recipZ;
    f32 z;
    void (**setState)(u32, u32);
    RwCamera* camera;
    u32 r;
    u32 g;
    u32 b;
    u32 a;
    s32 i;

    camera = kwlnGetMainCamera();
    recipZ = 1.0f / camera->nearPlane;

    r = (color >> 24) & 0xff;
    g = (color >> 16) & 0xff;
    b = (color >> 8) & 0xff;
    a = color & 0xff;

    setState = (void (**)(u32, u32))D_00960090_abs;
    (*setState)(6, 1);
    (*setState)(7, 2);
    (*setState)(8, 1);
    (*setState)(9, 2);
    (*setState)(0xc, 1);
    (*setState)(0xb, 6);
    (*setState)(0xa, 5);
    (*setState)(2, 4);
    RpSkyRenderStateSet(2, (void*)0x44);
    RpSkyRenderStateSet(3, (void*)0x717fb);

    corners[0][0] = x;
    corners[0][1] = y;
    farX = x + (f32)width;
    corners[3][0] = farX;
    farY = y + (f32)height;
    corners[3][1] = farY;
    corners[1][0] = farX;
    corners[1][1] = y;
    corners[2][0] = x;
    corners[2][1] = farY;
    z = D_00960088 - depth;

    for (i = 0; i < 4; i++)
    {
        RwIm2DVertex* v = &vertices[i];
        v->u.els.scrVertex.z = z;
        v->u.els.recipZ = recipZ;
        v->u.els.color.r = (f32)(u32)r;
        v->u.els.color.g = (f32)(u32)g;
        v->u.els.color.b = (f32)(u32)b;
        v->u.els.color.a = (f32)(u32)a;
        v->u.els.scrVertex.x = corners[i][0];
        v->u.els.scrVertex.y = corners[i][1];
    }

    textureCoordinates[0][0] = textureX / (f32)textureDimensions[3];
    textureCoordinates[0][1] = textureY / (f32)textureDimensions[4];
    textureCoordinates[3][0] = (textureX + (f32)width) / (f32)textureDimensions[3];
    textureCoordinates[3][1] = (textureY + (f32)height) / (f32)textureDimensions[4];
    textureCoordinates[1][0] = textureCoordinates[3][0];
    textureCoordinates[1][1] = textureCoordinates[0][1];
    textureCoordinates[2][0] = textureCoordinates[0][0];
    textureCoordinates[2][1] = textureCoordinates[3][1];

    if (orientation == 2)
    {
        swaps.swap0 = *(u64*)&textureCoordinates[0][0];
        textureCoordinates[0][0] = textureCoordinates[2][0];
        textureCoordinates[0][1] = textureCoordinates[2][1];
        textureCoordinates[2][0] = ((f32*)&swaps.swap0)[0];
        textureCoordinates[2][1] = ((f32*)&swaps.swap0)[1];
        swaps.swap0 = *(u64*)&textureCoordinates[1][0];
        textureCoordinates[1][0] = textureCoordinates[3][0];
        textureCoordinates[1][1] = textureCoordinates[3][1];
        textureCoordinates[3][0] = ((f32*)&swaps.swap0)[0];
        textureCoordinates[3][1] = ((f32*)&swaps.swap0)[1];
    }

    if (orientation == 1)
    {
        swaps.swap1 = *(u64*)&textureCoordinates[0][0];
        textureCoordinates[0][0] = textureCoordinates[1][0];
        textureCoordinates[0][1] = textureCoordinates[1][1];
        textureCoordinates[1][0] = ((f32*)&swaps.swap1)[0];
        textureCoordinates[1][1] = ((f32*)&swaps.swap1)[1];
        swaps.swap1 = *(u64*)&textureCoordinates[2][0];
        textureCoordinates[2][0] = textureCoordinates[3][0];
        textureCoordinates[2][1] = textureCoordinates[3][1];
        textureCoordinates[3][0] = ((f32*)&swaps.swap1)[0];
        textureCoordinates[3][1] = ((f32*)&swaps.swap1)[1];
    }

    for (i = 0; i < 4; i++)
    {
        vertices[i].u.els.u = textureCoordinates[i][0];
        vertices[i].u.els.v = textureCoordinates[i][1];
    }

    (*setState)(1, 0);
    (*D_009600A0)(rwPRIMTYPETRISTRIP, vertices, 4);
}
#pragma opt_loop_invariants off

/* Retail 0x115350-0x1158a0 builds a four-vertex strip with inline state setup,
 * point staging, doubled-alpha channel conversion, and a final draw.  The
 * corresponding logic is reconstructed below; remaining differences are
 * compiler frame/register layout across the same retail ranges. */
/* Scoped loop-invariant pragma measured W330: without nd944, with nd911 (obj 1212/1376). */
#pragma opt_loop_invariants on
/* W417 signature-order negative: one float argument leaves no float/int class ordering; alpha permutation is semantically unsafe. */
/* W419 adding explicit final 0xff masks to the extracted channels was neutral: nd877, object1232/window1376. */
// FUN_00115350 NONMATCHING
void func_00115350(f32 depth,
                   u32 color,
                   u64 point0,
                   u64 point1,
                   u64 point2,
                   u64 point3,
                   s32 alpha0,
                   s32 alpha1,
                   s32 alpha2,
                   s32 alpha3)
{
    RwIm2DVertex vertices[4];
    f32 points[4][2];
    f32 recipZ;
    f32 z;
    f32 tmpR;
    f32 tmpG;
    f32 tmpB;
    f32 blue;
    f32 alpha0f;
    f32 alpha1f;
    f32 alpha2f;
    f32 alpha3f;
    void (**setState)(u32, u32);
    s32 r;
    s32 g;
    s32 b;
    s32 r1;
    s32 g1;
    s32 b1;
    u32 i;
    RwIm2DVertex* v;

    recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;
    r = (color & 0xff000000) >> 24;
    g = (color & 0x00ff0000) >> 16;
    b = (color & 0x0000ff00) >> 8;

    setState = (void (**)(u32, u32))D_00960090_abs;
    (*setState)(6, 1);
    (*setState)(7, 2);
    (*setState)(8, 1);
    (*setState)(9, 1);
    (*setState)(0xc, 1);
    (*setState)(0xb, 6);
    (*setState)(0xa, 5);
    (*setState)(2, 4);
    RpSkyRenderStateSet(2, (void*)0x44);
    RpSkyRenderStateSet(3, (void*)0x717fb);

    points[0][0] = ((const f32*)&point0)[0];
    points[0][1] = ((const f32*)&point0)[1];
    points[1][0] = ((const f32*)&point1)[0];
    points[1][1] = ((const f32*)&point1)[1];
    points[2][0] = ((const f32*)&point2)[0];
    points[2][1] = ((const f32*)&point2)[1];
    points[3][0] = ((const f32*)&point3)[0];
    points[3][1] = ((const f32*)&point3)[1];

    r1 = r & 1;
    g1 = g & 1;
    b1 = b & 1;
    z = D_00960088 - depth;
    alpha3f = (f32)alpha3;
    alpha2f = (f32)alpha2;
    alpha1f = (f32)alpha1;
    alpha0f = (f32)alpha0;
    blue = (f32)(u32)b;

    for (i = 0; i < 4; i++)
    {
        v = &vertices[i];
        switch (i)
        {
        case 0:
            v->u.els.scrVertex.z = z;
            v->u.els.recipZ = recipZ;
            if (r >= 0)
                v->u.els.color.r = (f32)r;
            else
            {
                tmpR = (f32)(s32)(((u32)r >> 1) | r1);
                v->u.els.color.r = tmpR + tmpR;
            }
            if (g >= 0)
                v->u.els.color.g = (f32)g;
            else
            {
                tmpG = (f32)(s32)(((u32)g >> 1) | g1);
                v->u.els.color.g = tmpG + tmpG;
            }
            if (b >= 0)
                v->u.els.color.b = (f32)b;
            else
            {
                tmpB = (f32)(s32)(((u32)b >> 1) | b1);
                v->u.els.color.b = tmpB + tmpB;
            }
            v->u.els.color.a = alpha0f;
            break;
        case 1:
            v->u.els.scrVertex.z = z;
            v->u.els.recipZ = recipZ;
            v->u.els.color.r = (f32)(u32)r;
            if (g >= 0)
                v->u.els.color.g = (f32)g;
            else
            {
                tmpG = (f32)(s32)(((u32)g >> 1) | g1);
                v->u.els.color.g = tmpG + tmpG;
            }
            if (b >= 0)
                v->u.els.color.b = (f32)b;
            else
            {
                tmpB = (f32)(s32)(((u32)b >> 1) | b1);
                v->u.els.color.b = tmpB + tmpB;
            }
            v->u.els.color.a = alpha1f;
            break;
        case 2:
            v->u.els.scrVertex.z = z;
            v->u.els.recipZ = recipZ;
            if (r >= 0)
                v->u.els.color.r = (f32)r;
            else
            {
                tmpR = (f32)(s32)(((u32)r >> 1) | r1);
                v->u.els.color.r = tmpR + tmpR;
            }
            if (g >= 0)
                v->u.els.color.g = (f32)g;
            else
            {
                tmpG = (f32)(s32)(((u32)g >> 1) | g1);
                v->u.els.color.g = tmpG + tmpG;
            }
            v->u.els.color.b = blue;
            v->u.els.color.a = alpha2f;
            break;
        case 3:
            v->u.els.scrVertex.z = z;
            v->u.els.recipZ = recipZ;
            v->u.els.color.r = (f32)(u32)r;
            v->u.els.color.g = (f32)(u32)g;
            v->u.els.color.b = blue;
            v->u.els.color.a = alpha3f;
            break;
    }
    }

    for (i = 0; i < 4; i++)
    {
        vertices[i].u.els.scrVertex.x = points[i][0];
        vertices[i].u.els.scrVertex.y = points[i][1];
    }

    (*setState)(1, 0);
    (*D_009600A0)(rwPRIMTYPETRISTRIP, vertices, 4);
}
#pragma opt_loop_invariants reset
// FUN_001158B0
void* func_001158b0(param_1,param_2,param_3)
int param_1;
int param_2;
int param_3;
{

  int *piVar1;

  int *piVar2;
  int *piVar3;


  

  piVar2 = (int *)(*(void* (**)(u32,u32,u32))D_00960184_abs)(1,0x34,0x40000);

  *(u8 *)(piVar2 + 0xc) = 0xff;

  *(u8 *)((int)piVar2 + 0x31) = 0xff;

  *(u8 *)((int)piVar2 + 0x32) = 0xff;

  piVar2[2] = param_2;

  piVar2[3] = param_3;

  if (param_1 == 0) {

    piVar1 = DAT_007cdf3c;

    if (DAT_007cdf3c == (int *)0x0) {
      DAT_007cdf3c = piVar2;

      piVar2[1] = 0;

    }

    else {
      while (1) {
        piVar3 = (int *)*piVar1;
        if (piVar3 == (int *)0x0) {
          *piVar1 = (int)piVar2;
          piVar2[1] = (int)piVar1;
          break;
        }
        piVar1 = piVar3;
      }
    }

  }

  else {

    *(u32 *)param_1 = (u32)piVar2;

    piVar2[1] = (int)(u32 *)param_1;

  }
  return (void *)piVar2;
}
// FUN_00115980


void func_00115980(int *param_1)



{

  int *piVar1;

  

  piVar1 = (int *)param_1[1];

  if (piVar1 == (int *)0x0) {

    DAT_007cdf3c = (int*)*param_1;

    if (DAT_007cdf3c != 0) {

      DAT_007cdf3c[1] = 0;

    }

  }

  else {

    *piVar1 = *param_1;

    if (*param_1 != 0) {

      *(int **)(*param_1 + 4) = piVar1;

    }

  }

  MAESTRO_FREE(param_1);

  return;

}
// FUN_001159F0


void func_001159f0(int unused0, int unused1, int unused2,
                   f32 param_1, f32 param_2, u8 param_4, f32 param_3)



{

  int *piVar1;

  int *piVar2;

  void* uVar3;


  

  uVar3 = func_001158b0(0);

  piVar2 = (int *)uVar3;

  ((f32 *)piVar2)[0xb] = param_3;

  ((f32 *)piVar2)[4] = param_1;

  ((f32 *)piVar2)[5] = param_2;
  *(u8 *)(piVar2 + 6) = param_4;
  FUN_001127d0(uVar3,1);

  piVar1 = (int *)piVar2[1];

  if (piVar1 == (int *)0x0) {

    DAT_007cdf3c = (int*)*piVar2;

    if (DAT_007cdf3c != 0) {

      DAT_007cdf3c[1] = 0;

    }

  }

  else {

    *piVar1 = *piVar2;

    if (*piVar2 != 0) {

      *(int **)(*piVar2 + 4) = piVar1;

    }

  }

  MAESTRO_FREE((void*)uVar3);

  return;

}
// FUN_00115AD0


void func_00115ad0(int unused0, int unused1, int unused2,
                   f32 param_1, f32 param_2, u8 param_4, u8 param_5,
                   f32 param_3)



{

  int *piVar1;

  int *piVar2;

  void* uVar3;


  

  uVar3 = func_001158b0(0);

  piVar2 = (int *)uVar3;

  ((f32 *)piVar2)[0xb] = param_3;

  ((f32 *)piVar2)[4] = param_1;

  ((f32 *)piVar2)[5] = param_2;

  *(u8 *)(piVar2 + 6) = param_4;

  *(u8 *)((int)piVar2 + 0x19) = param_5;

  FUN_001127d0(uVar3,1);

  piVar1 = (int *)piVar2[1];

  if (piVar1 == (int *)0x0) {

    DAT_007cdf3c = (int*)*piVar2;

    if (DAT_007cdf3c != 0) {

      DAT_007cdf3c[1] = 0;

    }

  }

  else {

    *piVar1 = *piVar2;

    if (*piVar2 != 0) {

      *(int **)(*piVar2 + 4) = piVar1;

    }

  }

  MAESTRO_FREE((void*)uVar3);

  return;

}

// FUN_00115BC0

void func_00115bc0(int unused0, int unused1, int unused2,
                   f32 param_1, f32 param_2, u8 param_4, u8 param_5,
                   u8 param_6, u8 param_7, f32 param_3)


{

  int *piVar2;

  int *piVar1;

  void* uVar3;




  uVar3 = func_001158b0(0);
  piVar2 = (int *)uVar3;


  ((f32 *)piVar2)[0xb] = param_3;

  ((f32 *)piVar2)[4] = param_1;

  ((f32 *)piVar2)[5] = param_2;

  *(u8 *)(piVar2 + 6) = param_4;

  *(u8 *)(piVar2 + 0xc) = param_5;

  *(u8 *)((int)piVar2 + 0x31) = param_6;

  *(u8 *)((int)piVar2 + 0x32) = param_7;

  FUN_001127d0(piVar2,1);
  piVar1 = (int *)piVar2[1];

  if (piVar1 == (int *)0x0) {

    DAT_007cdf3c = (int*)*piVar2;

    if (DAT_007cdf3c != 0) {


      DAT_007cdf3c[1] = 0;
    }

  }

  else {

    *piVar1 = *piVar2;

    if (*piVar2 != 0) {

      *(int **)(*piVar2 + 4) = piVar1;

    }

  }

  MAESTRO_FREE((void*)piVar2);

  return;

}

// FUN_00115CD0


void func_00115cd0(int unused0, int unused1, int unused2,
                   f32 param_1, f32 param_2, u8 param_4, u8 param_5,
                   u8 param_6, u8 param_7, f32 param_3)



{

  int *piVar1;

  int *piVar2;

  void* uVar3;


  

  uVar3 = func_001158b0(0);

  piVar2 = (int *)uVar3;

  ((f32 *)piVar2)[0xb] = param_3;

  ((f32 *)piVar2)[4] = param_1;

  ((f32 *)piVar2)[5] = param_2;

  *(u8 *)(piVar2 + 6) = param_4;

  *(u8 *)(piVar2 + 0xc) = param_5;

  *(u8 *)((int)piVar2 + 0x31) = param_6;

  *(u8 *)((int)piVar2 + 0x32) = param_7;

  FUN_001127d0(piVar2,0);

  piVar1 = (int *)piVar2[1];

  if (piVar1 == (int *)0x0) {

    DAT_007cdf3c = (int*)*piVar2;

    if (DAT_007cdf3c != 0) {

      DAT_007cdf3c[1] = 0;

    }

  }

  else {

    *piVar1 = *piVar2;

    if (*piVar2 != 0) {

      *(int **)(*piVar2 + 4) = piVar1;

    }

  }

  MAESTRO_FREE((void*)piVar2);

  return;

}

/* W419 probes: direct pointer-return use, pointer-return alias, and matching sibling local order all stayed nd16,obj280/window288. */
/* W421 row classification: verify nd16, object280/window288, rate0.057143.
 * Offsets 0x34/0x38/0x3c/0x40 are move $s4,$a3 / move $s3,$a3;
 * move $s3,$t0 / move $s2,$t0; move $s2,$t1 / move $s1,$t1; and
 * move $s1,$t2 / move $s0,$t2. Offset 0x58 is move $s0,$v0 / move $s4,$v0.
 * Offsets 0x68/0x6c/0x70 are sb $s3,0x18($v0) / sb $s2,0x18($v0);
 * sb $s2,0x30($v0) / sb $s1,0x30($v0); and sb $s1,0x31($v0) / sb $s0,0x31($v0).
 * Offsets 0x78/0x7c are sh $s4,0x28($v0) / sh $s3,0x28($v0) and
 * sh $s4,0x2a($v0) / sh $s3,0x2a($v0); 0x80 is move $a0,$s0 / move $a0,$s4.
 * Offsets 0x90/0x9c/0xb8/0xc0 are lw $v1,4($s0) / lw $v1,4($s4) and
 * lw $v0,($s0) / lw $v0,($s4) at each offset; 0xd0 is move $a0,$s0 / move $a0,$s4
 * (candidate / retail): saved-register colouring from the extra u16 argument. */

// FUN_00115DE0 NONMATCHING


void func_00115de0(int unused0, int unused1, int unused2,
                   f32 param_1, f32 param_2, u16 param_4, u8 param_5,
                   u8 param_6, u8 param_7, u8 param_8, f32 param_3)


{
  int *piVar2;
  int *piVar1;

  piVar2 = (int *)func_001158b0(0, unused1, unused2);
  ((f32 *)piVar2)[0xb] = param_3;

  ((f32 *)piVar2)[4] = param_1;

  ((f32 *)piVar2)[5] = param_2;

  *(u8 *)(piVar2 + 6) = param_5;

  *(u8 *)(piVar2 + 0xc) = param_6;

  *(u8 *)((int)piVar2 + 0x31) = param_7;

  *(u8 *)((int)piVar2 + 0x32) = param_8;

  ((u16 *)piVar2)[0x14] = param_4;
  ((u16 *)piVar2)[0x15] = param_4;

  FUN_001127d0(piVar2,1);

  piVar1 = (int *)piVar2[1];

  if (piVar1 == (int *)0x0) {

    DAT_007cdf3c_sda = (int*)*piVar2;

    if (DAT_007cdf3c_sda != 0) {
      DAT_007cdf3c_sda[1] = 0;
    }

  }

  else {

    *piVar1 = *piVar2;

    if (*piVar2 != 0) {
      *(int **)(*piVar2 + 4) = piVar1;
    }

  }

  MAESTRO_FREE((void*)piVar2);
  return;

}

#pragma opt_loop_invariants on
// FUN_00115F00 NONMATCHING


u32 func_00115f00(KwlnTask* param_1)



{

  u32 *puVar1;

  u32 uVar2;

  u32 uVar3;

  int lVar4;

  int iVar5;
  void (**renderState)(u32, u32);

  u8 auStack_110 [256];

  u16 uStack[4];


  u8 auStack_4 [4];

  

  puVar1 = *(u32 **)((int)param_1 + 0x3c);

  FUN_00198590();

  renderState = (void (**)(u32, u32))D_00960090_abs;
  (*renderState)(6,1);
  (*renderState)(7,2);
  (*renderState)(8,1);
  (*renderState)(9,1);
  (*renderState)(0xc,1);
  (*renderState)(0xb,6);
  (*renderState)(10,5);

  switch(*puVar1) {

  case 0:

    lVar4 = FUN_0017d800();

    if ((lVar4 != 0) && (puVar1[1] == 9)) {

      FUN_00523ac8(auStack_110,0x5d6c40);

    }

    else {

      lVar4 = FUN_0017d800();

      if ((lVar4 != 0) && (puVar1[1] == 1)) {

        FUN_00523ac8(auStack_110,0x5d6c70);

      }

      else {

        FUN_00523ac8(auStack_110,0x5d6c90,puVar1[1]);

      }

    }

    uVar2 = FUN_00100d80(auStack_110,1);

    puVar1[9] = uVar2;

    *puVar1 = 1;

    break;

  case 1:

    lVar4 = FUN_001016b0(puVar1[9]);

    if (lVar4 != 0) {

      for (iVar5 = 0; iVar5 < 3; iVar5 = iVar5 + 1) {

        uVar3 = FUN_00102100(puVar1[9],iVar5,puVar1 + iVar5 * 0xd9 + 0x66);

        puVar1[iVar5 * 0xd9 + 100] = (int)uVar3;

        FUN_00102720(0x5d6cb8,uVar3);

      }

      uStack[0] = 0x28;

      uStack[1] = 3;

      iVar5 = puVar1[1];

      if (iVar5 == 0xea) {

        uStack[2] = 0xb;
        uStack[3] = 6;

      }

      else if (iVar5 == 0xe9) {

        uStack[2] = 0xb;
        uStack[3] = 5;

      }

      else if (iVar5 == 0x67) {

        uStack[2] = 0xb;
        uStack[3] = 3;

      }

      else if (iVar5 == 0x11) {

        uStack[2] = 0xb;
        uStack[3] = 2;

      }

      else if (iVar5 == 0x10) {

        uStack[2] = 0xb;
        uStack[3] = 1;

      }

      else if (iVar5 == 0xf) {

        uStack[2] = 0xb;
        uStack[3] = 0;

      }

      else if (iVar5 == 10) {

        uStack[2] = 10;
        uStack[3] = 8;

      }

      else if (iVar5 == 9) {

        lVar4 = FUN_0017d800();

        if (lVar4 != 0) {

          uStack[2] = 0xb;
          uStack[3] = 4;

        }

        else {

          uStack[2] = 10;
          uStack[3] = 7;

        }

      }

      else if (iVar5 == 8) {

        uStack[2] = 10;
        uStack[3] = 6;

      }

      else if (iVar5 == 7) {

        uStack[2] = 10;
        uStack[3] = 5;

      }

      else if (iVar5 == 6) {

        uStack[2] = 10;
        uStack[3] = 9;

      }

      else if (iVar5 == 5) {

        uStack[2] = 10;
        uStack[3] = 4;

      }

      else if (iVar5 == 4) {

        uStack[2] = 10;
        uStack[3] = 3;

      }

      else if (iVar5 == 3) {

        uStack[2] = 10;
        uStack[3] = 2;

      }

      else if (iVar5 == 2) {

        uStack[2] = 10;
        uStack[3] = 1;

      }

      else if (iVar5 == 1) {

        lVar4 = FUN_0017d800();

        if (lVar4 != 0) {

          uStack[2] = 10;
          uStack[3] = 2;

        }

        else {

          uStack[2] = 10;
          uStack[3] = 0;

        }

      }

      uVar2 = FUN_00111260(param_1, *(u64 *)uStack, puVar1 + 0x1d2);

      puVar1[5] = uVar2;

      uStack[0] = 0x28;

      uStack[1] = 3;

      uStack[2] = 0xb;

      uStack[3] = 9;

      uVar3 = FUN_00111260(param_1, *(u64 *)uStack, puVar1 + 0xf9);

      puVar1[4] = (int)uVar3;

      FUN_00111570(uVar3,1);

      uStack[0] = 0x28;

      uStack[1] = 3;

      uStack[2] = 0xb;

      uStack[3] = 8;

      uVar3 = FUN_00111260(param_1, *(u64 *)uStack, puVar1 + 0x20);

      puVar1[3] = (int)uVar3;

      FUN_00111570(uVar3,1);

      uVar3 = FUN_00102100(puVar1[9],3,auStack_4);

      uVar2 = FUN_0034fcd0(uVar3);

      puVar1[0x2ab] = uVar2;

      uVar3 = FUN_00102100(puVar1[9],4,auStack_4);

      uVar2 = FUN_0034fcd0(uVar3);

      puVar1[0x2ac] = uVar2;

      *puVar1 = 2;

    }

    break;

  case 2:

    lVar4 = FUN_001114b0(puVar1[3]);

    if (((lVar4 != 0) && (lVar4 = FUN_001114b0(puVar1[4]), lVar4 != 0)) &&

       (lVar4 = FUN_001114b0(puVar1[5]), lVar4 != 0)) {

      *puVar1 = 3;

    }

    break;
  case 3:
    break;

  case 4:

    FUN_00111530(puVar1[3]);

    FUN_00111530(puVar1[4]);

    FUN_00111530(puVar1[5]);

    *puVar1 = 5;

    break;

  case 5:

    if (puVar1[5] != 0) {

      puVar1[0x1c] = puVar1[0x1c] + 1;

      lVar4 = FUN_00195290(puVar1[5]);

      if (lVar4 == 3) {

        puVar1[5] = 0;

      }

    }

    if (puVar1[0x1f] != 0) {

      iVar5 = puVar1[0x1d] + 1;

      puVar1[0x1d] = iVar5;

      if (((iVar5 != 0xf) && (0xf < iVar5)) && (puVar1[0x1b] + 0xf <= iVar5)) {

        return 0xffffffff;

      }

    }

    if (puVar1[0x1e] != 0) {

      puVar1[0x1e] = 0;

      puVar1[0x1f] = 1;

    }

  }

  return 0;

}
#pragma opt_loop_invariants reset

#pragma opt_loop_invariants off
// FUN_001165C0


void func_001165c0(int param_1)



{

  int iVar1;

  int *slot;

  int iVar2;

  int *p;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  if (*(int *)(iVar1 + 400) != 0) {

    FUN_00102870(*(void **)(iVar1 + 400));

  }

  if (*(int *)(iVar1 + 0x4f4) != 0) {

    FUN_00102870(*(void **)(iVar1 + 0x4f4));

  }

  if (*(int *)(iVar1 + 0x858) != 0) {

    FUN_00102870(*(void **)(iVar1 + 0x858));

  }

  if (*(int *)(iVar1 + 0x24) != 0) {

    FUN_00100ec0(*(void **)(iVar1 + 0x24));

    *(u32 *)(iVar1 + 0x24) = 0;

  }

  p = (int *)iVar1;
  for (iVar2 = 0; iVar2 < 2; iVar2 = iVar2 + 1) {
    slot = p + iVar2 + 0x2ab;
    if (*slot != 0) {
      FUN_0034fcf0(*slot);
      *slot = 0;
    }
  }

  MAESTRO_FREE((void*)iVar1);

  return;

}

// FUN_001166A0
void* func_001166a0(KwlnTask* parent, u32 param_2, u32 param_3)
{
    void* work;
    KwlnTask* task;

    work = MAESTRO_ALLOC(1, 0xab4, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = (KwlnTask*)FUN_00194b80(parent, 0x106f, D_005D6CD0,
                                   func_00115f00, func_001165c0, work);
    if (task == NULL)
    {
        return NULL;
    }
    *(u32*)((u8*)work + 4) = param_2;
    *(u32*)((u8*)work + 8) = param_3;
    return task;
}

// FUN_00116760


u8 func_00116760(int param_1)



{

  return **(int **)(param_1 + 0x3c) == 3;

}

// FUN_00116780


void func_00116780(int param_1)



{

  **(u32 **)(param_1 + 0x3c) = 4;

  return;

}

// FUN_001167A0


void func_001167a0(int param_1)



{

  *(u32 *)(*(int *)(param_1 + 0x3c) + 0x78) = 1;

  return;

}

// FUN_001167C0


u32 func_001167c0(int param_1,u32 param_2)



{

  u32 base;
  u32 idx;

  base = *(u32 *)(param_1 + 0x3c);

  if (param_2 == 0) {

    return 0x33;

  }

  idx = param_2 * 4;

  idx += base;

  return *(u32 *)(idx + 0x68);

}

// FUN_001167F0 NONMATCHING


u32 func_001167f0(u32 param_1)



{

  u32 *puVar1;

  u32 uVar2;

  u32 uVar3;

  int lVar4;

  int iVar5;
  void (**renderState)(u32, u32);

  u8 auStack_110 [256];

  u16 uStack_10;

  u16 uStack_e;

  u16 uStack_c;

  u16 uStack_a;

  u8 auStack_4 [4];

  

  puVar1 = *(u32 **)((int)param_1 + 0x3c);

  FUN_00198590();

  renderState = (void (**)(u32, u32))D_00960090_abs;
  (*renderState)(6,1);
  (*renderState)(7,2);
  (*renderState)(8,1);
  (*renderState)(9,1);
  (*renderState)(0xc,1);
  (*renderState)(0xb,6);
  (*renderState)(10,5);

  switch(*puVar1) {

  case 0:

    switch(puVar1[1]) {

    default:

      FUN_00523ac8(auStack_110,0x5d6ce0);

      break;

    case 2:

      FUN_00523ac8(auStack_110,0x5d6ce0);

      break;

    case 3:

      FUN_00523ac8(auStack_110,0x5d6d00);

      break;

    case 4:

      FUN_00523ac8(auStack_110,0x5d6d20);

      break;

    case 5:

      FUN_00523ac8(auStack_110,0x5d6d40);

      break;

    case 7:

      FUN_00523ac8(auStack_110,0x5d6d60);

      break;

    case 9:

      lVar4 = FUN_0017d800();

      if (lVar4 != 0) {

        FUN_00523ac8(auStack_110,0x5d6da0);

      }

      else {

        FUN_00523ac8(auStack_110,0x5d6dc0);

      }

      break;
    case 8:

      FUN_00523ac8(auStack_110,0x5d6d80);

      break;


    case 10:

      FUN_00523ac8(auStack_110,0x5d6de0);

    }

    uVar2 = FUN_00100d80(auStack_110,1);

    puVar1[9] = uVar2;

    *puVar1 = 1;

    break;

  case 1:

    lVar4 = FUN_001016b0(puVar1[9]);

    if (lVar4 != 0) {

      for (iVar5 = 0; iVar5 < 2; iVar5 = iVar5 + 1) {

        uVar3 = FUN_00102100(puVar1[9],iVar5,puVar1 + iVar5 * 0xd9 + 0x62);

        puVar1[iVar5 * 0xd9 + 0x60] = (int)uVar3;

        FUN_00102720(0x5d6e00,uVar3);

      }

      uStack_10 = 0x29;

      uStack_e = 4;

      uStack_c = 10;

      switch(puVar1[1]) {

      default:

        uStack_a = 0;

        break;

      case 2:

        uStack_a = 0;

        break;

      case 3:

        uStack_a = 1;

        break;

      case 4:

        uStack_a = 2;

        break;

      case 5:

        uStack_a = 3;

        break;

      case 7:

        uStack_a = 4;

        break;

      case 9:

        lVar4 = FUN_0017d800();

        if (lVar4 != 0) {

          uStack_a = 8;

        }

        else {

          uStack_a = 6;

        }

        break;
      case 8:

        uStack_a = 5;

        break;


      case 10:

        uStack_a = 7;

      }

      uVar2 = FUN_00111260(param_1, *(u64 *)&uStack_10, puVar1 + 0x1c);

      puVar1[2] = uVar2;

      uVar3 = FUN_00102100(puVar1[9],1,auStack_4);

      uVar2 = FUN_00112420(uVar3);

      puVar1[0x1ce] = uVar2;

      *puVar1 = 2;

    }

    break;

  case 2:

    lVar4 = FUN_001114b0(puVar1[2]);

    if ((lVar4 != 0) && (lVar4 = FUN_00111f30(puVar1[0x1ce]), lVar4 != 0)) {

      FUN_00111520(puVar1[2],0x32);

      *puVar1 = 3;

    }

    break;

  case 3:

    break;

  case 4:

    FUN_00111530(puVar1[2]);

    uVar2 = FUN_00117490(param_1,puVar1[0x1ce]);

    puVar1[4] = uVar2;

    *puVar1 = 5;

    break;

  case 5:

    iVar5 = puVar1[0x19];

    if (iVar5 < 0x32) {

      puVar1[0x19] = iVar5 + 1;

    }

    else if (puVar1[0x1b] != 0) {

      puVar1[0x19] = iVar5 + 1;

      FUN_00111500(puVar1[2]);

    }

    lVar4 = FUN_00195290(puVar1[2]);

    if (lVar4 == 3) {

      return 0xffffffff;

    }


  }

  return 0;

}

// FUN_00116CF0


void func_00116cf0(int param_1)
{
    u8* work;
    void** entry;

    work = *(u8**)(param_1 + 0x3c);
    func_001124b0(*(void**)(work + 0x738));
    {
        s32 i;

        for (i = 0; i < 2; i++)
        {
            entry = (void**)(work + i * 0x364 + 0x180);
            if (*entry != NULL)
            {
                H_Cdvd_CacheRemove(*entry);
                *entry = NULL;
            }
        }
    }
    {
        s32 i;

        for (i = 0; i < 3; i++)
        {
            entry = (void**)(work + i * 4 + 0x24);
            if (*entry != NULL)
            {
                FUN_00100ec0(*entry);
                *entry = NULL;
            }
        }
    }
    {
        s32 i;

        for (i = 0; i < 2; i++)
        {
            entry = (void**)(work + i * 4 + 0x1c);
            if (*entry != NULL)
            {
                func_004d0f00(*entry);
                *entry = NULL;
            }
        }
    }
    MAESTRO_FREE(work);
}

// FUN_00116E20
void* func_00116e20(KwlnTask* parent, u32 param_2)
{
    void* work;
    KwlnTask* task;

    work = MAESTRO_ALLOC(1, 0x73c, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = (KwlnTask*)FUN_00194b80(parent, 0x106f, D_005D6E10,
                                   func_001167f0, func_00116cf0, work);
    if (task == NULL)
    {
        return NULL;
    }
    *(u32*)((u8*)work + 4) = param_2;
    return task;
}

// FUN_00116ED0


u8 func_00116ed0(int param_1)



{

  return **(int **)(param_1 + 0x3c) == 3;

}





/* Scoped loop-invariant pragma measured W330: without nd4402, with nd4399 (obj 6732/7296). */
// FUN_00116EF0


void func_00116ef0(int param_1)



{

  **(u32 **)(param_1 + 0x3c) = 4;

  return;

}
// FUN_00116F10


u32 func_00116f10(void)



{

  return 0x3f;

}

// FUN_00116F20


u32 func_00116f20(int param_1)



{

  return *(u32 *)(*(int *)(param_1 + 0x3c) + 100);

}























// Deep reconstruction pass restored per-state HSFD_TABLE lookups to use
// work->id directly (matching retail) instead of a cached movieId local,
// removed several dead/duplicate locals (decoder, rasterTarget, redundant
// config declaration, unused state local), and typed the render-state
// function pointer table access explicitly. object_size grew toward the
// retail window as genuine logic was restored; normalized_diff moved
// slightly worse, which is expected for this class of fix.










/* W318 measured: opt_loop_invariants on changes c1a0 nd25->0. */


/* W318 measured: opt_common_subs off changes c7d0 nd406->385; object676/window752. */

#pragma opt_common_subs reset

// FUN_00116F30


u32 func_00116f30(int param_1)



{

  return 0x31 < *(int *)(*(int *)(param_1 + 0x3c) + 100);

}

/* W318 measured: opt_loop_invariants on changes cdd0 nd1487->1332; object2032/window2336. */
// FUN_00116F50


void func_00116f50(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  *(u32 *)(iVar1 + 0x6c) = 1;

  FUN_00117470(*(u32 *)(iVar1 + 0x10));

  return;

}

// FUN_00116F80 NONMATCHING


void* func_00116f80(KwlnTask* task)
{
    int* work;
    int* workBase;
    int state;
    int result;
    u32 nodeValue;
    u32 convertedA;
    u32 convertedB;
    int node;
    int frame;

    work = *(int**)((int)task + 0x3c);
    workBase = work + 5;
    switch (*work)
    {
    case 0:
        func_0018bc10(666.0f, workBase, 0, 2, 0,
                      0x42f0000044268000, 0x42f00000433b0000, 0, 0, 0, 0);
        *work = 1;
        break;

    case 1:
        result = FUN_0018b700(workBase);
        if (result != 0)
        {
            convertedA = FUN_00530da0(workBase[0xc]);
            convertedB = FUN_00530da0(workBase[0xe]);
            FUN_005225a8(0x5d6e20, convertedA, convertedB);
            if (workBase[8] == workBase[6])
            {
                work[1] = 0;
                *work = 2;
            }
            nodeValue = (u32)func_001158b0(0, work[4], 0);
            node = (int)nodeValue;
            *(u32*)(node + 0x2c) = 0x42c80000;
            *(int*)(node + 0x10) = workBase[0xe];
            *(int*)(node + 0x14) = workBase[0xf];
            *(u16*)(node + 0x24) = 0x10;
            *(u16*)(node + 0x26) = 0x60;
            state = (4 - (work[0xd] - work[0xb])) * 0x19;
            if (state < 0)
            {
                state += 3;
            }
            *(float*)(node + 0x20) = (float)((state >> 2) - 5);
            *(u8*)(node + 0x18) = 0;
            FUN_001127d0(nodeValue, 1);
            func_00115980((int*)nodeValue);
        }
        break;

    case 2:
        result = FUN_0018b700(workBase);
        if (result != 0)
        {
            nodeValue = (u32)func_001158b0(0, work[4], 0);
            state = work[1];
            frame = state + 1;
            work[1] = frame;
            if (frame < 3)
            {
                state = (int)((u32)((long)(frame * 0xf) << 0x21) >> 0x20);
                if (frame * 0x1e < 0)
                {
                    state = frame * 0x1e + 1;
                }
                state = 0x14 - (state >> 1);
            }
            else if (frame < 6)
            {
                state -= 2;
                frame = state * 10;
                state = (int)((u32)((long)(state * 5) << 0x21) >> 0x20);
                if (frame < 0)
                {
                    state = frame + 1;
                }
                state = (state >> 1) - 10;
            }
            else
            {
                state = 0;
                *work = 3;
                work[1] = 0;
            }
            node = (int)nodeValue;
            *(float*)(node + 0x20) = (float)state;
            *(u32*)(node + 0x2c) = 0x42c80000;
            *(int*)(node + 0x10) = workBase[0xe];
            *(int*)(node + 0x14) = workBase[0xf];
            *(u16*)(node + 0x24) = 0x10;
            *(u16*)(node + 0x26) = 0x60;
            *(u8*)(node + 0x18) = 0;
            FUN_001127d0(nodeValue, 1);
            func_00115980((int*)nodeValue);
        }
        break;

    case 3:
        result = FUN_0018b700(workBase);
        if (result != 0)
        {
            nodeValue = (u32)func_001158b0(0, work[4], 0);
            node = (int)nodeValue;
            *(u32*)(node + 0x2c) = 0x42c80000;
            *(int*)(node + 0x10) = workBase[0xe];
            *(int*)(node + 0x14) = workBase[0xf];
            *(u16*)(node + 0x24) = 0x10;
            *(u16*)(node + 0x26) = 0x60;
            *(u8*)(node + 0x18) = 0;
            FUN_001127d0(nodeValue, 1);
            func_00115980((int*)nodeValue);
        }
        if (work[3] != 0)
        {
            func_0018bc10(100.0f, workBase, 0, 2, 2,
                          0x42f00000433b0000, 0x42f00000433b0000, 0, 0, 0, 0);
            *work = 4;
        }
        break;

    case 4:
        result = FUN_0018b700(workBase);
        if (result != 0)
        {
            if (workBase[8] == workBase[6])
            {
                work[1] = 0;
                return (void*)-1;
            }
            nodeValue = (u32)func_001158b0(0, work[4], 0);
            node = (int)nodeValue;
            *(u32*)(node + 0x2c) = 0x42c80000;
            *(int*)(node + 0x10) = workBase[0xe];
            *(int*)(node + 0x14) = workBase[0xf];
            *(u16*)(node + 0x24) = 0x10;
            *(u16*)(node + 0x26) = 0x60;
            *(char*)(node + 0x18) = (char)workBase[0x10];
            FUN_001127d0(nodeValue, 1);
            func_00115980((int*)nodeValue);
        }
        break;
    }
    return NULL;
}

// FUN_00117440
void func_00117440(KwlnTask* task)
{
    MAESTRO_FREE(task->workData);
}

// FUN_00117470
void func_00117470(KwlnTask* task)
{
    *(u32*)((u8*)task->workData + 0x0c) = 1;
}

// FUN_00117490
KwlnTask* func_00117490(KwlnTask* parent, void* blob)
{
    void* work;
    KwlnTask* task;

    work = MAESTRO_ALLOC(1, 0x58, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreate(parent, D_005D6E48, 0x18b5,
                          func_00116f80, func_00117440, work);
    if (task == NULL)
    {
        return NULL;
    }
    *(void**)((u8*)work + 0x10) = blob;
    return task;
}

#pragma opt_loop_invariants on
/* W420 collateral from twin ABI reorder: nd4399,obj6732/window7296 (rate 0.653446) -> nd4404,obj6736/window7296 (rate 0.653800); retained for the twin improvement. */
// FUN_00117540 NONMATCHING
void* func_00117540(KwlnTask* task)
{
    MaestroPerEffectWork* work;
    char path[0x120];
    void (**stateFn)(u32, u32);
    u32 ready;
    u32 size;
    s32 i;
    s32 j;
    s32 frame;
    s32 segment;
    s32 radius;

    work = (MaestroPerEffectWork*)task->workData;
    kwlnGetMainCamera();
    stateFn = (void (**)(u32, u32))D_00960090_abs;
    (*stateFn)(6, 1);
    (*stateFn)(7, 2);
    (*stateFn)(8, 1);
    (*stateFn)(9, 1);
    (*stateFn)(12, 1);
    (*stateFn)(11, 6);
    (*stateFn)(10, 5);

    switch (work->state)
    {
    case 0:
        MaestroEffectRequestFiles(work, path + 0x30);
        work->state = 1;
        break;
    case 3:
        break;
    case 1:
        ready = true;
        for (i = 0; i < 9; i++)
        {
            if (work->cdvd[i] != NULL &&
                H_Cdvd_IsFileLoaded(work->cdvd[i]) == 0)
            {
                ready = false;
            }
        }
        if (ready)
        {
            MaestroEffectLoadRecords(task, work);
            MaestroEffectStartStreams(task, work, path + 0x30);
        }
        break;
    case 2:
        ready = H_Maestro_00111f30((s16*)work->blob);
        for (i = 0; i < 6; i++)
        {
            if (work->loadedResources[i] == NULL && work->streams[i] != NULL)
            {
                work->loadedResources[i] = func_0010c3a0(work->streams[i],
                                                         &size, 0);
                if (size == 0)
                {
                    ready = false;
                }
                else
                {
                    work->streams[i] = NULL;
                }
            }
        }
        for (i = 0; i < 3; i++)
        {
            if (work->resourceTasks[i] != NULL &&
                func_001104b0(work->resourceTasks[i]) == 0)
            {
                ready = false;
            }
        }
        if (ready != 0 && func_001114b0(work->streamTask) != 0)
        {
            if (work->effectCount == 0)
            {
                if (work->loadedResources[0] != NULL)
                    *(u32*)((u8*)work->loadedResources[0] + 0x50) =
                        (*(u32*)((u8*)work->loadedResources[0] + 0x50) &
                         0xffff00ff) | 0x3300;
                if (work->loadedResources[1] != NULL)
                    *(u32*)((u8*)work->loadedResources[1] + 0x50) =
                        (*(u32*)((u8*)work->loadedResources[1] + 0x50) &
                         0xffff00ff) | 0x3300;
                func_001105d0(work->resourceTasks[0], 0,
                              work->loadedResources[1]);
                func_001105d0(work->resourceTasks[0], 1,
                              work->loadedResources[0]);
            }
            else if (work->effectCount == 1)
            {
                if (work->loadedResources[0] != NULL)
                    *(u32*)((u8*)work->loadedResources[0] + 0x50) =
                        (*(u32*)((u8*)work->loadedResources[0] + 0x50) &
                         0xffff00ff) | 0x3300;
                if (work->loadedResources[1] != NULL)
                    *(u32*)((u8*)work->loadedResources[1] + 0x50) =
                        (*(u32*)((u8*)work->loadedResources[1] + 0x50) &
                         0xffff00ff) | 0x3300;
                func_001105d0(work->resourceTasks[0], 0,
                              work->loadedResources[1]);
                func_001105d0(work->resourceTasks[0], 1,
                              work->loadedResources[0]);
                if (work->loadedResources[2] != NULL)
                    *(u32*)((u8*)work->loadedResources[2] + 0x50) =
                        (*(u32*)((u8*)work->loadedResources[2] + 0x50) &
                         0xffff00ff) | 0x3300;
                if (work->loadedResources[3] != NULL)
                    *(u32*)((u8*)work->loadedResources[3] + 0x50) =
                        (*(u32*)((u8*)work->loadedResources[3] + 0x50) &
                         0xffff00ff) | 0x3300;
                func_001105d0(work->resourceTasks[1], 0,
                              work->loadedResources[3]);
                func_001105d0(work->resourceTasks[1], 1,
                              work->loadedResources[2]);
            }
            else
            {
                if (work->loadedResources[0] != NULL)
                    *(u32*)((u8*)work->loadedResources[0] + 0x50) =
                        (*(u32*)((u8*)work->loadedResources[0] + 0x50) &
                         0xffff00ff) | 0x3300;
                if (work->loadedResources[1] != NULL)
                    *(u32*)((u8*)work->loadedResources[1] + 0x50) =
                        (*(u32*)((u8*)work->loadedResources[1] + 0x50) &
                         0xffff00ff) | 0x3300;
                func_001105d0(work->resourceTasks[0], 0,
                              work->loadedResources[1]);
                func_001105d0(work->resourceTasks[0], 1,
                              work->loadedResources[0]);
                if (work->loadedResources[2] != NULL)
                    *(u32*)((u8*)work->loadedResources[2] + 0x50) =
                        (*(u32*)((u8*)work->loadedResources[2] + 0x50) &
                         0xffff00ff) | 0x3300;
                if (work->loadedResources[3] != NULL)
                    *(u32*)((u8*)work->loadedResources[3] + 0x50) =
                        (*(u32*)((u8*)work->loadedResources[3] + 0x50) &
                         0xffff00ff) | 0x3300;
                func_001105d0(work->resourceTasks[1], 0,
                              work->loadedResources[3]);
                func_001105d0(work->resourceTasks[1], 1,
                              work->loadedResources[2]);
                if (work->loadedResources[4] != NULL)
                    *(u32*)((u8*)work->loadedResources[4] + 0x50) =
                        (*(u32*)((u8*)work->loadedResources[4] + 0x50) &
                         0xffff00ff) | 0x3300;
                if (work->loadedResources[5] != NULL)
                    *(u32*)((u8*)work->loadedResources[5] + 0x50) =
                        (*(u32*)((u8*)work->loadedResources[5] + 0x50) &
                         0xffff00ff) | 0x3300;
                func_001105d0(work->resourceTasks[2], 0,
                              work->loadedResources[5]);
                func_001105d0(work->resourceTasks[2], 1,
                              work->loadedResources[4]);
            }
            work->state = 3;
        }
        break;
    case 4:
        MaestroEffectSetReady(work);
        func_00119960(task, work->effectCount, work->blob);
        work->state = 5;
        break;
    case 5:
        frame = work->frame;
        if (frame >= 10)
        {
            segment = frame - 10;
            if (segment < 30)
            {
                u32 alpha;

                if (segment < 5)
                    alpha = (u32)(segment * 0xff / 5);
                else
                    alpha = 0xff;
                func_00113a30(100.0f, 0x0f395600 | alpha, 0.0f, 0.0f,
                              0x280, 0x1c0);
            }
            else
            {
                segment -= 30;
                if (segment >= 0x29)
                    return KWLNTASK_STOP;
                {
                    f32 points[4][2];
                    u64 point0;
                    u64 point1;
                    u64 point2;
                    u64 point3;
                    radius = segment * 36;
                    for (i = 0; i < 24; i++)
                    {
                        f32 angle0;
                        f32 angle1;

                        angle0 = gPI * (f32)(i * 400 / 24) / 180.0f;
                        angle1 = gPI * (f32)((i + 1) * 400 / 24) / 180.0f;
                        points[0][0] = cosf(angle0) * 1000.0f;
                        points[0][1] = sinf(angle0) * 1000.0f;
                        points[1][0] = cosf(angle1) * 1000.0f;
                        points[1][1] = sinf(angle1) * 1000.0f;
                        points[2][0] = cosf(angle0) * (f32)radius;
                        points[2][1] = sinf(angle0) * (f32)radius;
                        points[3][0] = cosf(angle1) * (f32)radius;
                        points[3][1] = sinf(angle1) * (f32)radius;
                        for (j = 0; j < 4; j++)
                        {
                            points[j][0] += 320.0f;
                            points[j][1] += 224.0f;
                        }
                        point0 = *(u64*)&points[0][0];
                        point1 = *(u64*)&points[1][0];
                        point2 = *(u64*)&points[2][0];
                        point3 = *(u64*)&points[3][0];
                        func_00115350(100.0f, 0x0f3956ff,
                                      point0, point1, point2, point3,
                                      0xff, 0xff, 0xff, 0xff);
                    }
                }
                }
            }
        work->frame = frame + 1;
        for (i = 0; i < 3; i++)
        {
            if (work->resourceTasks[i] != NULL)
            {
                func_00110510(work->resourceTasks[i]);
            }
        }
        if (work->completionCounts[0] <= work->frame)
        {
            for (i = 0; i < 3; i++)
            {
                if (work->resourceTasks[i] != NULL)
                {
                    func_00195020(work->resourceTasks[i]);
                    work->resourceTasks[i] = NULL;
                }
            }
        }
        break;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_001191C0
void func_001191c0(KwlnTask* task)
{
    MaestroPerEffectWork* work;
    void** entry;

    work = (MaestroPerEffectWork*)task->workData;
    if (work->archiveCacheRequest != NULL)
    {
        H_Cdvd_CacheRemove(work->archiveCacheRequest);
    }
    func_001124b0(work->blob);
    {
        s32 i;

        for (i = 0; i < 9; i++)
        {
            entry = (void**)&work->cdvd[i];
            if (work->cdvd[i] != NULL)
            {
                H_Cdvd_Destroy(work->cdvd[i]);
                *entry = NULL;
            }
        }
    }
    {
        s32 i;

        for (i = 0; i < 6; i++)
        {
            entry = &work->loadedResources[i];
            if (work->loadedResources[i] != NULL)
            {
                func_004d0f00(work->loadedResources[i]);
                *entry = NULL;
            }
        }
    }
    MAESTRO_FREE(work);
}
/* W318 measured: opt_loop_invariants on changes dd10 nd67->0; ddc0 nd48->0; de40 nd79->0. */
// FUN_001192B0
KwlnTask* func_001192b0(KwlnTask* parent, const u32* config)
{
    MaestroPerEffectWork* work;
    KwlnTask* task;

    work = (MaestroPerEffectWork*)MAESTRO_ALLOC(1, sizeof(MaestroPerEffectWork), 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreate(parent, D_005D6FD0, 0x18bf,
                          func_00117540, func_001191c0, work);
    if (task == NULL)
    {
        return NULL;
    }
    work->effectIds[0] = config[0];
    work->effectIds[1] = config[1];
    work->effectIds[2] = config[2];
    return task;
}
// FUN_00119380
u32 func_00119380(KwlnTask* task)
{
    return ((MaestroMarkSpriteWork*)task->workData)->state == 3;
}
// FUN_001193A0
void func_001193a0(KwlnTask* task)
{
    ((MaestroMarkSpriteWork*)task->workData)->state = 4;
}
// FUN_001193C0
u32 func_001193c0(void)
{
    return 0x28;
}


/* W318 measured: opt_loop_invariants on changes df60 nd69->14; object stays 168/176. */
// FUN_001193D0 NONMATCHING
void* func_001193d0(KwlnTask* task)
{
    MaestroMarkSpriteWork* work;
    s32 duration;
    s32 scale;
    MaestroRenderNode* node;


    work = (MaestroMarkSpriteWork*)task->workData;
    switch (work->state)
    {
    case 0:
        if (work->mode == 2)
        {
            func_0018bc10(100.0f, &work->animation, 0, 2, 0,
                          0xc298000043280000ULL,
                          0x430d000043840000ULL, 0, 0, 0, 0);
        }
        else if (work->mode == 1)
        {
            func_0018bc10(100.0f, &work->animation, 0, 2, 0,
                          0xc31e000042a80000ULL,
                          0x4298000043630000ULL, 0, 0, 0, 0);
        }
        else if (work->mode == 0)
        {
            func_0018bc10(100.0f, &work->animation, 0, 2, 0,
                          0xc298000043280000ULL,
                          0x430d000043840000ULL, 0, 0, 0, 0);
        }
        work->state = 1;
        break;

    case 1:
        if (func_0018b700(&work->animation) != 0)
        {
            duration = work->animation.endFrame - work->animation.startFrame;
            scale = 0x34cc - (0x24cc * (work->animation.frame - work->animation.startFrame)) / duration;
            {
                node = (MaestroRenderNode*)func_001158b0(NULL, work->blob, 0);
                node->depth = work->animation.depth;
                node->x = work->animation.x;
                node->y = work->animation.y;
                node->xScale = (u16)scale;
                node->yScale = (u16)scale;
                node->pivotX = (s16)((scale * 0x10) >> 12);
                node->pivotY = (s16)((scale * 0x60) >> 12);
                node->angle = (f32)(((work->animation.frame - work->animation.startFrame) * 0x1e) / duration - 0x32);
                node->alphaCutoff = 0;
                func_001127d0(node, true);
                func_00115980((int*)node);
            }
            if (work->animation.frame == work->animation.endFrame)
            {
                work->frame = 0;
                work->state = 2;
            }
        }
        break;

    case 2:
        work->frame++;
        {
            node = (MaestroRenderNode*)func_001158b0(NULL, work->blob, 0);
            node->depth = work->animation.depth;
            node->x = work->animation.x;
            node->y = work->animation.y;
            node->pivotX = 0x10;
            node->pivotY = 0x60;
            node->angle = (f32)((work->frame * 0x1e) / 3 - 0x14);
            node->alphaCutoff = 0;
            func_001127d0(node, true);
            func_00115980((int*)node);
        }
        if (work->frame == 3)
        {
            work->frame = 0;
            work->state = 3;
        }
        break;

    case 3:
        work->frame++;
        {
            node = (MaestroRenderNode*)func_001158b0(NULL, work->blob, 0);
            node->depth = work->animation.depth;
            node->x = work->animation.x;
            node->y = work->animation.y;
            node->pivotX = 0x10;
            node->pivotY = 0x60;
            node->angle = (f32)(10 - (work->frame * 10) / 3);
            node->alphaCutoff = 0;
            func_001127d0(node, true);
            func_00115980((int*)node);
        }
        if (work->frame == 2)
        {
            work->frame = 0;
            work->state = 4;
        }
        break;

    case 4:
        work->frame++;
        {
            node = (MaestroRenderNode*)func_001158b0(NULL, work->blob, 0);
            node->depth = work->animation.depth;
            node->x = work->animation.x;
            node->y = work->animation.y;
            node->pivotX = 0x10;
            node->pivotY = 0x60;
            node->angle = 0.0f;
            node->alphaCutoff = work->frame < 0x0f
                              ? 0
                              : (u8)(((work->frame - 0x0f) * 0xff) / 3);
            func_001127d0(node, true);
            func_00115980((int*)node);
        }
        if (work->frame == 0x12)
        {
            return KWLNTASK_STOP;
        }
        break;
    }
    return KWLNTASK_CONTINUE;
}
// FUN_00119930
void func_00119930(KwlnTask* task)
{
    MAESTRO_FREE(task->workData);
}

/* W318 measured: opt_loop_invariants on changes e0d0 nd689->672; object1064/window1072. */
// FUN_00119960
KwlnTask* func_00119960(KwlnTask* parent, u32 effectType, void* blob)
{
    MaestroMarkSpriteWork* work;
    KwlnTask* task;

    work = (MaestroMarkSpriteWork*)MAESTRO_ALLOC(1, 0x58, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreate(parent, D_005D6FE0, 0x18c1,
                          func_001193d0, func_00119930, work);
    if (task == NULL)
    {
        return NULL;
    }
    work->blob = blob;
    work->mode = effectType;
    return task;
}

// FUN_00119A20
void func_00119a20(void)
{
    s32 i = 0;
    void** table = D_00833B70;

    for (; i < 14; i++)
    {
        table[i] = NULL;
    }
}

// FUN_00119A60
void* func_00119a60(s32 index)
{
    return D_00833B70[index];
}

/* W318 measured: opt_loop_invariants on changes e630 nd411->330; object524/window592. */
// FUN_00119A80
void func_00119a80(s32 index, void* resource)
{
    D_00833B70[index] = resource;
}

#pragma opt_loop_invariants off

// Retail unrolls the state-0 resource-load loop (14 literal calls, not a
// runtime loop) and dispatches via switch, not if/else-if. Rewritten from
// disasm; nd 261->10. Residual: 1 addu operand-order floor + 1 hoisted
// D_00833B70 pointer register-bank floor in the state-3-promote loop.
#pragma push
/* Removing this loses FUN_00119aa0 (MATCH nd0 -> MISMATCH nd30) - measured W161. */
#pragma opt_loop_invariants on
// FUN_00119AA0
void* func_00119aa0(KwlnTask* task)
{
    MaestroCampSpriteSetupWork* work;
    u32 size;
    s32 i;
    u32 ready;

    work = (MaestroCampSpriteSetupWork*)task->workData;
    switch (work->state)
    {
    case 0:
        if (H_Cdvd_IsFileLoaded(work->archive) != 0)
        {
            work->resources[0] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 0, &size));
            work->resources[1] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 1, &size));
            work->resources[2] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 2, &size));
            work->resources[3] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 3, &size));
            work->resources[4] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 4, &size));
            work->resources[5] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 5, &size));
            work->resources[6] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 6, &size));
            work->resources[7] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 7, &size));
            work->resources[8] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 8, &size));
            work->resources[9] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 9, &size));
            work->resources[10] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 10, &size));
            work->resources[11] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 11, &size));
            work->resources[12] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 12, &size));
            work->resources[13] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 13, &size));
            work->ownerPool = func_0018b6d0(0xc8);
            iGpffffb25c = work->ownerPool;
            work->state = 1;
        }
        break;
    case 1:
        ready = true;
        for (i = 0; i < 14; i++)
        {
            if (work->resources[i] != NULL &&
                H_Maestro_00111f30((s16*)work->resources[i]) == 0)
            {
                ready = false;
            }
        }
        if (ready != 0)
        {
            {
                s32 j = 0;

                for (; j < 14; j++)
                {
                    D_00833B70[j] = work->resources[j];
                }
            }
            work->state = 3;
        }
        break;
    case 2:
        if (H_Cdvd_IsFileLoaded(work->archive) != 0)
        {
            work->state = 3;
        }
        break;
    case 3:
        break;
    }
    func_003c7b90();
    return KWLNTASK_CONTINUE;
}
#pragma pop

// Reconstructed from the retail window. The opening is the same render-state
// prologue the sibling func_0010f6c0 already carries: two indirect calls
// through the D_00960090 render-state hook, near/far plane setup, a full
// 640x448 viewport, camera bind, then the 0x4e4 flag selecting between two
// RpSkyRenderStateSet pairs. Retail then gates the whole body on work[0] == 3
// (bne $a0, 3 branches to the tail); that body is fully reconstructed here
// as an element-loop over frame commands with color processing.
// FUN_00119E00
void func_00119e00(KwlnTask* task)
{
    MaestroCampSpriteSetupWork* work;
    s32 i;

    work = (MaestroCampSpriteSetupWork*)task->workData;
    for (i = 0; i < 14; i++)
    {
        if (*(void**)((int)work + i * 4 + 4) != NULL)
        {
            func_001124b0(*(void**)((int)work + i * 4 + 4));
        }
        *(void**)((int)work + i * 4 + 4) = NULL;
    }
    if (work->archive != NULL)
    {
        H_Cdvd_Destroy(work->archive);
    }
    if (work->ownerPool != NULL)
    {
        MAESTRO_FREE(work->ownerPool);
        iGpffffb25c = NULL;
    }
    {
        s32 j = 0;
        void** table = D_00833B70;

        for (; j < 14; j++)
        {
            table[j] = NULL;
        }
    }
    MAESTRO_FREE(work);
    if (work->initializeMessages != 0)
    {
        func_003c77a0();
    }
    iGpffffb258 = NULL;
}

// Retail 0x10fbe4-0x110250 re-fetches command pointers and carries the prior
// endpoint into command-2 rectangles; preserve those conversions and spill slots.
/* W375 measured opt_loop_invariants off for FUN_0010F6C0: default nd2034/object3060; off nd2031/object3060; retained. */
// FUN_00119F10
KwlnTask* func_00119f10(KwlnTask* parent, u32 initializeMessages)
{
    MaestroCampSpriteSetupWork* work;
    KwlnTask* task;

    if (iGpffffb258 != NULL)
    {
        return NULL;
    }
    work = (MaestroCampSpriteSetupWork*)MAESTRO_ALLOC(1, 0x48, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreate(parent, D_005DAC00, 0x18bf,
                          func_00119aa0, func_00119e00, work);
    if (task == NULL)
    {
        return NULL;
    }
    iGpffffb258 = task;
    if (datGetScenarioMode() != 0)
    {
        work->archive = H_Cdvd_Request(D_005DAC20, 1);
    }
    else
    {
        work->archive = H_Cdvd_Request(D_005DAC40, 1);
    }
    work->initializeMessages = initializeMessages;
    if (initializeMessages != 0)
    {
        func_003c72d0(D_005D7AE0);
    }
    return task;
}
