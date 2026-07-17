#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Utils.h"
#include "rw/rwplcore.h"
#include "rw/rtquat.h"

static u32* sSflCamera; // DAT_007ce33c
extern u32 DAT_00960070[];
u32 FUN_0024d430();
void FUN_0024d5e0();
void FUN_0024d7d0();
u32 FUN_0024d3b0();

// FUN_0024d110
void sflCamera0024d110(u32* param_1)
{
    K_ASSERT(sSflCamera == NULL, 0x42);
    *param_1 = 0;
    param_1[1] = 0;
    sSflCamera = param_1;
}

// FUN_0024d160
void sflCamera0024d160(void)
{
    K_ASSERT(sSflCamera != NULL, 0x3b);
    K_ASSERT(sSflCamera != NULL, 0x4e);
    sSflCamera = NULL;
}

// FUN_0024d280
void sflCamera0024d280(u32 param_1)
{
    u32* work;

    K_ASSERT(sSflCamera != NULL, 0x3b);
    work = sSflCamera;
    work[4] = param_1;
    *work |= 1;
}

// FUN_0024d940
void sflCamera0024d940(int param_1, u32 param_2)
{
    K_ASSERT(*(int*)(param_1 + 0x2c) != 0, 0x124);
    *(u32*)(param_1 + 0x34) = param_2;
}

// FUN_0024d9a0
void sflCamera0024d9a0(int param_1, u32 param_2)
{
    K_ASSERT(*(int*)(param_1 + 0x2c) != 0, 0x129);
    *(u32*)(param_1 + 0x3c) = param_2;
}

// FUN_0024d1c0
void sflCamera0024d1c0(void)
{
    u32* puVar1;
    u32 uVar2;

    K_ASSERT(sSflCamera != NULL, 0x3b);
    puVar1 = sSflCamera;
    K_ASSERT(DAT_00960070[0] == 0, 0x58);
    if ((~*puVar1 & 1) == 0 && (~*puVar1 & 2) == 0) {
        uVar2 = FUN_0024d430(*(u16*)((int)puVar1 + 0xc));
        FUN_0024d5e0(uVar2);
        FUN_0024d7d0(puVar1[4], uVar2);
    }
}

// FUN_0024d2e0
void sflCamera0024d2e0(int param_1, u32* param_2)
{
    u32* puVar1;

    K_ASSERT(sSflCamera != NULL, 0x3b);
    puVar1 = sSflCamera;
    K_ASSERT(FUN_0024d3b0(param_1) == 0, 0x79);
    *(u16*)((int)param_2 + 4) = (u16)param_1;
    if (puVar1[1] != 0) {
        param_2[2] = puVar1[2];
        param_2[3] = 0;
        *(u32*)((int)puVar1[2] + 0xc) = (u32)param_2;
        puVar1[2] = (u32)param_2;
    } else {
        param_2[3] = 0;
        param_2[2] = 0;
        puVar1[1] = (u32)param_2;
        puVar1[2] = (u32)param_2;
    }
    param_2[0x10] = 0;
}

// FUN_0024d3b0
u32 sflCamera0024d3b0(int param_1)
{
    int iVar1;
    int key;

    K_ASSERT(sSflCamera != NULL, 0x3b);
    iVar1 = sSflCamera[1];
    key = param_1 & 0xffff;
    while (iVar1 != 0) {
        if (*(u16*)(iVar1 + 4) == key) {
            return 1;
        }
        iVar1 = *(int*)(iVar1 + 0xc);
    }
    return 0;
}

// FUN_0024d430
int sflCamera0024d430(int param_1)
{
    int iVar1;
    int key;

    K_ASSERT(sSflCamera != NULL, 0x3b);
    iVar1 = sSflCamera[1];
    key = param_1 & 0xffff;
    while (iVar1 != 0) {
        if (*(u16*)(iVar1 + 4) == key) {
            return iVar1;
        }
        iVar1 = *(int*)(iVar1 + 0xc);
    }
    K_ASSERT(0, 0xaf);
    return 0;
}
static u32* sSflCameraNodes; // DAT_007ce350

extern void gcPose0024f090(void* pose);
extern void gcPose002503f0(void* pose, s32 index, u32 value);
extern void gcPose0024fd20(void* pose);
extern void gcPose0024fd40(void* pose);
extern void* func_004c38c0(void);
extern void func_004c3880(void* matrix);
extern void func_004cb750(void* matrix, const void* source, s32 mode);
void func_0024da60(void* camera);

void func_0024dc90(void* camera);
static u32* sflCameraNodeHead(void)
{
    K_ASSERT(sSflCamera != NULL, 0x3b);
    return (u32*)sSflCamera[1];
}

static u32* sflCameraFindNode(u16 id)
{
    u32* node;

    node = sflCameraNodeHead();
    while (node != NULL) {
        if (*(u16*)((u8*)node + 4) == id) {
            return node;
        }
        node = (u32*)node[3];
    }
    return NULL;
}

// FUN_0024D4C0 NONMATCHING
void func_0024d4c0(s32 id)
{
    u32* work;
    u32* node;
    u32 key;

    K_ASSERT(sSflCamera != NULL, 0x3b);
    work = sSflCamera;
    K_ASSERT(work != NULL, 0x3b);
    node = (u32*)sSflCamera[1];
    key = id & 0xffff;
    while (node != NULL) {
        switch (*(u16*)((u8*)node + 4) != key) {
        case 0:
            goto found;
        default:
            node = (u32*)node[3];
            break;
        }
    }
    K_ASSERT(0, 0xaf);
    node = NULL;
found:
    *(u16*)((u8*)work + 0xc) = (u16)id;
    *work |= 2;
    switch (node[0xb]) {
    case 1:
        gcPose0024f090((u8*)node + 0xa8);
        gcPose002503f0(node + 0x11, 0, node[0xd]);
        gcPose0024f090((u8*)node + 0x44);
        break;
    }
}

// FUN_0024D5E0 NONMATCHING
void func_0024d5e0(void* node)
{
    RwV3d target;
    RwV3d forward;
    RwV3d up;
    RwV3d right;
    void* matrix;

    K_ASSERT(*(u32*)((u8*)node + 0x2c) != 0, 0xd0);
    matrix = func_004c38c0();
    if (matrix == NULL) {
        return;
    }
    target = *(RwV3d*)((u8*)node + 0x20);
    forward = *(RwV3d*)((u8*)node + 0x30);
    forward.x -= target.x;
    forward.y -= target.y;
    forward.z -= target.z;
    RwV3dNormalize(&forward, &forward);
    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
    right.x = up.y * forward.z - up.z * forward.y;
    right.y = up.z * forward.x - up.x * forward.z;
    right.z = up.x * forward.y - up.y * forward.x;
    RwV3dNormalize(&right, &right);
    up.x = forward.y * right.z - forward.z * right.y;
    up.y = forward.z * right.x - forward.x * right.z;
    up.z = forward.x * right.y - forward.y * right.x;
    RwV3dNormalize(&up, &up);
    *(RwV3d*)((u8*)matrix + 0) = right;
    *(RwV3d*)((u8*)matrix + 0x10) = up;
    *(RwV3d*)((u8*)matrix + 0x20) = forward;
    func_004c3880(matrix);
}

// FUN_0024D7D0 NONMATCHING
void func_0024d7d0(void* camera, const RwV3d* position)
{
    RwV3d direction;
    f32 length;
    u8* matrix;

    K_ASSERT(camera != NULL, 0x3b);
    matrix = *(u8**)((u8*)camera + 4);
    if (matrix == NULL || position == NULL) {
        return;
    }
    direction = *position;
    length = RwV3dLength(&direction);
    if (length > 0.0f) {
        direction.x /= length;
        direction.y /= length;
        direction.z /= length;
    }
    *(f32*)(matrix + 0x10) = 1.0f - direction.x * direction.x;
    *(f32*)(matrix + 0x14) = direction.x * direction.y;
    *(f32*)(matrix + 0x18) = direction.x * direction.z;
    *(f32*)(matrix + 0x20) = direction.y * direction.x;
    *(f32*)(matrix + 0x24) = 1.0f - direction.y * direction.y;
    *(f32*)(matrix + 0x28) = direction.y * direction.z;
    *(f32*)(matrix + 0x30) = direction.z * direction.x;
    *(f32*)(matrix + 0x34) = direction.z * direction.y;
    *(f32*)(matrix + 0x38) = 1.0f - direction.z * direction.z;
    *(u32*)(matrix + 0x40) = 0;
    *(u32*)(matrix + 0x44) = 0;
    *(u32*)(matrix + 0x48) = 0;
    *(u32*)(matrix + 0x1c) = 3;
    func_004cb750(matrix, (u8*)position + 0x20, 2);
}

// FUN_0024D8D0
void func_0024d8d0(void* camera)
{
    u8* work;

    work = (u8*)camera;
    *(u32*)(work + 0x2c) = 1;
    *(u32*)(work + 0x30) = 1;
    *(u32*)(work + 0x38) = 1;
    gcPose0024fd20(work + 0xa8);
    func_0024da60(work + 0xa8);
    gcPose0024fd40(work + 0x44);
    func_0024da60(work + 0x44);
}

// FUN_0024DA00
void func_0024da00(u32* work)
{
    work[0] = 0;
    work[1] = 0;
    sSflCameraNodes = work;
}

// FUN_0024DA20
void func_0024da20(void)
{
    K_ASSERT(sSflCameraNodes != NULL, 0x5d);
    sSflCameraNodes = NULL;
}

// FUN_0024DA60
void func_0024da60(void* camera)
{
    u32* list;

    K_ASSERT(sSflCameraNodes != NULL, 0x5d);
    list = sSflCameraNodes;
    *(u32*)((u8*)camera + 8) = 0;
    *(u32*)((u8*)camera + 0x10) = 0;
    if (list[0] != 0) {
        *(u32*)((u8*)camera + 0) = list[1];
        *(u32*)((u8*)camera + 4) = 0;
        ((u32*)list[1])[1] = (u32)camera;
        list[1] = (u32)camera;
    } else {
        *(u32*)((u8*)camera + 4) = 0;
        *(u32*)((u8*)camera + 0) = 0;
        list[0] = (u32)camera;
        list[1] = (u32)camera;
    }
}

// FUN_0024DAF0
void func_0024daf0(u32* camera)
{
    u32* list;
    u32* link;

    K_ASSERT(sSflCameraNodes != NULL, 0x5d);
    list = sSflCameraNodes;
    link = (u32*)camera[1];
    if (link != NULL) {
        link[0] = camera[0];
    }
    link = (u32*)camera[0];
    if (link != NULL) {
        link[1] = camera[1];
    }
    if (camera == (u32*)list[0]) {
        list[0] = camera[1];
    }
    if (camera == (u32*)list[1]) {
        list[1] = camera[0];
    }
}

// FUN_0024DB90
void func_0024db90(void)
{
    u32* camera;

    K_ASSERT(sSflCameraNodes != NULL, 0x5d);
    camera = (u32*)sSflCameraNodes[0];
    while (camera != NULL) {
        if ((~camera[2] & 1u) == 0) {
            bpTut00251010(camera, 0x10000);
        }
        camera = (u32*)camera[1];
    }
}

// FUN_0024DC10
void func_0024dc10(void)
{
    u32* camera;
    u32* list;

    K_ASSERT(sSflCameraNodes != NULL, 0x5d);
    list = sSflCameraNodes;
    list[0x82] = 0;
    camera = (u32*)list[0];
    while (camera != NULL) {
        func_0024dc90(camera);
        camera = (u32*)camera[1];
    }
}

// FUN_0024DC90 NONMATCHING
void func_0024dc90(void* camera)
{
    u8* node;
    u32 state;
    u32 mode;
    u32 timer;
    RwV3d position;
    RwV3d target;
    RwV3d offset;
    s32 i;

    K_ASSERT(sSflCameraNodes != NULL, 0x5d);
    node = (u8*)camera;
    state = *(u32*)(node + 0xc);
    mode = *(u32*)(node + 0x20);
    timer = *(u32*)(node + 0x10);
    if ((*(u32*)(node + 8) & 3u) != 3u) {
        return;
    }
    timer++;
    *(u32*)(node + 0x10) = timer;
    if (state == 0) {
        return;
    }
    if (state == 1 && timer < 0x20) {
        f32 blend = (f32)timer / 32.0f;
        position = *(RwV3d*)(node + 0x20);
        target = *(RwV3d*)(node + 0x30);
        position.x += (target.x - position.x) * blend;
        position.y += (target.y - position.y) * blend;
        position.z += (target.z - position.z) * blend;
        *(RwV3d*)(node + 0x20) = position;
    } else if (state == 2 && timer > 0x20) {
        *(u32*)(node + 8) &= ~2u;
    } else if (state == 3 && timer > 0x40) {
        *(u32*)(node + 8) &= ~2u;
    }
    if (mode == 1) {
        offset.x = 0.0f;
        offset.y = 0.0f;
        offset.z = *(f32*)(node + 0x58);
        gcPose0024f090(node + 0x44);
    }
    for (i = 0; i < 2; i++) {
        if (*(u32*)(node + 0x44 + i * 4) != 0) {
            *(u32*)(node + 0x44 + i * 4) += 1;
        }
    }
}
