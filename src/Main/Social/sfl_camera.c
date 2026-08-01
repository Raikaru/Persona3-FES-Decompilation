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


static u32* sSflCameraNodes; // DAT_007ce350
extern void gcPose0024f090(void* pose);
extern void gcPose002503f0(void* pose, s32 index, u32 value);
extern void gcPose0024fd20(void* pose);
extern void gcPose0024fd40(void* pose);
extern void* func_004c38c0(void);
extern void func_004c3880(void* matrix);
extern void func_004cb750(void* matrix, const void* source, s32 mode);
extern u32 RpRandom(void);
extern void gcPose0024f960(void* pose, RwV3d* output);
extern RwV3d* gcPose0024faa0(void* pose);
extern void gcPose0024fba0(void* pose, RtQuat* output);
extern void func_0024f7f0(void* pose, const RwV3d* offset);
extern void func_00250280(void* pose, const RwV3d* offset);
extern void FUN_004bdde0(f32 angle, f32* output, const f32* axis, s32 mode);
extern void FUN_004c69f0(RwV3d* output, const RwV3d* input);
extern f32 fGpffff81f8;
extern RwV3d DAT_0068e9b0;
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
static inline u32* sflCameraFindRequiredNode(u32* node, s32 id)
{
    u32 key;

    key = (u16)id;
    while (node != NULL) {
        if (*(u16*)((u8*)node + 4) == key) {
            return node;
        }
        node = (u32*)node[3];
    }
    K_ASSERT(0, 0xaf);
    return NULL;
}

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

// FUN_0024d280
void sflCamera0024d280(u32 param_1)
{
    u32* work;

    K_ASSERT(sSflCamera != NULL, 0x3b);
    work = sSflCamera;
    work[4] = param_1;
    *work |= 1;
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

// FUN_0024D4C0
void func_0024d4c0(s32 id)
{
    u32* work;
    u32* node;

    K_ASSERT(sSflCamera != NULL, 0x3b);
    work = sSflCamera;
    K_ASSERT(work != NULL, 0x3b);
    node = (u32*)sSflCamera[1];
    node = sflCameraFindRequiredNode(node, id);
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

// FUN_0024D5E0 MATCHING
void func_0024d5e0(u8* node)
{
    RwV3d forward;
    RwV3d right;
    f32 axisX;
    f32 axisY;
    f32 axisZ;
    RwV3d up;
    RwV3d posePosition;
    void* matrix;

    K_ASSERT(*(u32*)(node + 0x2c) != 0, 0xd0);
    matrix = func_004c38c0();
    *(u32*)(node + 0x40) += 0x10000;
    switch (*(u32*)(node + 0x2c)) {
    case 1:
        switch (*(u32*)(node + 0x30)) {
        case 1:
            gcPose0024f960(node + 0x44, (RwV3d*)(node + 0x20));
            break;
        }
        switch (*(u32*)(node + 0x38)) {
        case 1:
            gcPose0024f960((void*)*(u32*)(node + 0x3c), &posePosition);
            forward.x = posePosition.x - *(f32*)(node + 0x20);
            forward.y = posePosition.y - *(f32*)(node + 0x24);
            forward.z = posePosition.z - *(f32*)(node + 0x28);
            RwV3dLength(&forward);
            RwV3dNormalize(&forward, &forward);
            axisX = 0.0f;
            axisY = 1.0f;
            axisZ = 0.0f;
            right.x = axisY * forward.z - axisZ * forward.y;
            right.y = axisZ * forward.x - axisX * forward.z;
            right.z = axisX * forward.y - axisY * forward.x;
            up.x = forward.y * right.z - forward.z * right.y;
            up.y = forward.z * right.x - forward.x * right.z;
            up.z = forward.x * right.y - forward.y * right.x;
            RwV3dNormalize((RwV3d*)((u8*)matrix + 0x20), &forward);
            RwV3dNormalize((RwV3d*)((u8*)matrix + 0), &right);
            RwV3dNormalize((RwV3d*)((u8*)matrix + 0x10), &up);
            RtQuatConvertFromMatrix((RtQuat*)(node + 0x10), matrix);
            break;
        }
        break;
    default:
        K_ASSERT(0, 0xfc);
        break;
    }
    func_004c3880(matrix);
}





// FUN_0024D7D0 MATCHING
void func_0024d7d0(void* camera, const RwV3d* position)
{
    u8* matrix;
    f32 y;
    f32 x;
    f32 z;
    f32 real;
    f32 norm;
    f32 scale;
    f32 twoX;
    f32 twoY;
    f32 twoZ;
    f32 xx;
    f32 xy;
    f32 xz;
    f32 yy;
    f32 yz;
    f32 zz;
    f32 xw;
    f32 yw;
    f32 zw;

    matrix = *(u8**)((u8*)camera + 4);
    y = *(f32*)((u8*)position + 0x14);
    x = *(f32*)((u8*)position + 0x10);
    z = *(f32*)((u8*)position + 0x18);
    real = *(f32*)((u8*)position + 0x1c);

    norm = y * y;
    norm += x * x;
    norm += z * z;
    norm = norm + real * real;
    scale = 2.0f / norm;
    twoX = x * scale;
    twoY = y * scale;
    twoZ = z * scale;
    xw = twoX * real;
    yw = twoY * real;
    zw = twoZ * real;
    xx = x * twoX;
    xy = y * twoY;
    xz = z * twoZ;
    yy = y * twoZ;
    yz = z * twoX;
    zz = x * twoY;

    *(f32*)(matrix + 0x10) = 1.0f - (xy + xz);
    *(f32*)(matrix + 0x14) = zz + zw;
    *(f32*)(matrix + 0x18) = yz - yw;
    *(f32*)(matrix + 0x20) = zz - zw;
    *(f32*)(matrix + 0x24) = 1.0f - (xz + xx);
    *(f32*)(matrix + 0x28) = yy + xw;
    *(f32*)(matrix + 0x30) = yz + yw;
    *(f32*)(matrix + 0x34) = yy - xw;
    *(f32*)(matrix + 0x38) = 1.0f - (xx + xy);
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

// FUN_0024DA00
void func_0024da00(u32* work)
{
    work[0] = 0;
    work[1] = 0;
    sSflCameraNodes = work;
}






// Retail cross-check restored the state-0 interpolation path and state-2 mode fields.
// The state-0 mode-3 path now clamps, interpolates, and clears completion flags.
// State-2 mode-3 uses the node's inline pose payload, matching retail addressing.
// State-2 mode-4 uses its distinct duration field for the second cubic segment.
// Queue setup and cleanup avoid an unnecessary persistent counter local.
// The function remains NONMATCHING while these semantic repairs alter scheduling.
