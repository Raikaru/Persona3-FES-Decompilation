#ifndef K_FLDFRAME_H
#define K_FLDFRAME_H

#include "Utils.h"
#include "rw/rwplcore.h"

typedef struct Model Model;
typedef struct KwlnTask KwlnTask;
typedef struct FldUnit FldUnit;

#define COLLISCTL_FLAG_NOUPDATE   (1 << 27) // 0x8000000
#define COLLISCTL_FLAG_NOCOLLIS   (1 << 28) // 0x10000000. Disable collisions
#define COLLISCTL_FLAG_GROUNDSNAP (1 << 30) // 0x40000000
#define COLLISCTL_FLAG_DEBUGDRAW  (1 << 31) // 0x80000000. Draw collisions

#define FLDFRAME_COLLIS_FLAG_STATICWORLD (1 << 0) // 0x01. Use the static collision world

// Location of Field's frame collision state pointer.
#define FLDFRAME_FIELD_STATE_OFFSET 0x116c

typedef enum
{
    COLLISCTL_STATE_DIRTY,
    COLLISCTL_STATE_NOTDIRTY,
    COLLISCTL_STATE_IDLE
} CollisCtlState;

// 52 bytes. Task data for a "collision controler" task
typedef struct CollisCtl
{
    u32 state;              // 0x00. See 'CollisCtlState' enum
    u32 flags;              // 0x04. See 'COLLISCTL_FLAG_*'
    u16 resTypeId;          // 0x08. Typeid of the resrc owning the CollisCtl
    u16 charId;             // 0x0a
    FldUnit* fldUnit;       // 0x0c
    Model* mdl;             // 0x10
    RwV3d velocity;         // 0x14
    f32 sphereCollisRadius; // 0x20. Radius of the sphere collision
    s32 unk_24;             // 0x24
    u32 totalDist;          // 0x28. Total distance travelled (weirdly it's not a float)
    s32 xGrid;              // 0x2c. Current X grid
    s32 zGrid;              // 0x30. Current Z grid
} CollisCtl;

// 4 bytes. Task data for the collision-sphere debug child task.
typedef struct CollisSphereDebug
{
    u32 drawEnabled; // 0x00
} CollisSphereDebug;

// 16 bytes. Collision state referenced by Field at FLDFRAME_FIELD_STATE_OFFSET.
typedef struct FldFrameCollisionState
{
    u32 flags;               // 0x00. See FLDFRAME_COLLIS_FLAG_*.
    u32 unk_04;              // 0x04
    void* collisionWorld;    // 0x08. Dynamic field collision world.
    void* staticCollision;   // 0x0c. Static collision tree.
} FldFrameCollisionState;

// 44 bytes. Callback state passed through RenderWare field raycasts.
typedef struct FldFrameRaycast
{
    RwV3d* hitPointDst;    // 0x00
    u32 didHit;            // 0x04
    RwV3d line[2];         // 0x08
    u32 intersectionType;  // 0x20. RpIntersection line type.
    f32 nearestFraction;   // 0x24
    void* hitObject;       // 0x28
} FldFrameRaycast;

u32 K_FldFrame_IsPointInTriangle(const RwV3d* point, const RwV3d** tri, const RwV3d* normal);
u32 K_FldFrame_Raycast(const RwV3d* line, RwV3d* hitPointDst);

// collis ctl
KwlnTask* K_FldFrame_CreateCtlTask(KwlnTask* parent, u32 resTypeId, s32 unused, f32 sphereCollisRadius);
f32 K_FldFrame_CtlGetSphereCollisRadius(KwlnTask* collisCtlTask);
void K_FldFrame_CtlSetSphereCollisRadius(KwlnTask* collisCtlTask, f32 radius);
s32 K_FldFrame_CtlGetXGrid(KwlnTask* collisCtlTask);
s32 K_FldFrame_CtlGetZGrid(KwlnTask* collisCtlTask);
u32 K_FldFrame_CtlGetTotalDist(KwlnTask* collisCtlTask);
void K_FldFrame_CtlSetFlags(KwlnTask* collisCtlTask, u32 flags);
void K_FldFrame_CtlClearFlags(KwlnTask* collisCtlTask, u32 flags);
void K_FldFrame_CtlCopyPos(RwV3d* dst, KwlnTask* collisCtlTask);
void K_FldFrame_CtlUpdateMdlMat(KwlnTask* collisCtlTask, const RwMatrix* mat);
void K_FldFrame_CtlMoveInDir(f32 dist, KwlnTask* collisCtlTask, const RwV3d* normalizedDir);
void K_FldFrame_CtlMoveForward(f32 dist, KwlnTask* collisCtlTask);
void K_FldFrame_CtlRotate(KwlnTask* collisCtlTask, const RwV3d* axis, f32 angle);

#endif