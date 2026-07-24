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
extern u32 RpRandom(void);
extern void gcPose0024f960(void* pose, RwV3d* output);
extern RwV3d* gcPose0024faa0(void* pose);
extern void gcPose0024fba0(void* pose, RtQuat* output);
extern void func_0024f7f0(void* pose, const RwV3d* offset);
extern void func_00250280(void* pose, const RwV3d* offset);
extern void FUN_004bdde0(f32 angle, f32* output, const f32* axis, s32 mode);
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

// Retail cross-check restored the state-0 interpolation path and state-2 mode fields.
// The state-0 mode-3 path now clamps, interpolates, and clears completion flags.
// State-2 mode-3 uses the node's inline pose payload, matching retail addressing.
// State-2 mode-4 uses its distinct duration field for the second cubic segment.
// Queue setup and cleanup avoid an unnecessary persistent counter local.
// The function remains NONMATCHING while these semantic repairs alter scheduling.
// FUN_0024DC90 NONMATCHING
void func_0024dc90(void* camera)
{
    u32* list;
    u8* node;
    u32 queued;
    u32 i;
    u32* pose;
    u32** poses;
    f32* p;
    f32 ratio;
    f32 ratio2;
    f32 oneMinus;
    f32 dot;
    f32 angle;
    f32 extent;
    s32 random;
    u32 duration;
    RwV3d first;
    RwV3d second;
    RwV3d value;
    RwV3d offset;
    RwV3d axis;
    RwV3d cross;
    RtQuat quat;
    RtQuat nextQuat;
    RtQuat composed;

    K_ASSERT(sSflCameraNodes != NULL, 0x5d);
    list = sSflCameraNodes;
    K_ASSERT(list[0x82] == 0, 0xe6);
    list[list[0x82] + 2] = (u32)camera;
    list[0x82]++;

    while (list[0x82] != 0) {
        u32 flags;
        u32 state;
        u32 mode;
        node = (u8*)list[list[0x82] + 1];
        flags = *(u32*)(node + 8);
        queued = 0;
        if ((flags & 1) != 0 && (flags & 2) != 0) {
            state = *(u32*)(node + 0xc);

            switch (state) {
            case 0: {
                mode = *(u32*)(node + 0x20);
                switch (mode) { case 1: { u32 oldTimer;
                u32 firstDuration;
                
                p = (f32*)(node + 0x24);
                oldTimer = *(u32*)(node + 0x10);
                firstDuration = (*(u32*)(node + 0x58)) << 16;
                ratio = (f32)(s32)oldTimer / (f32)(s32)firstDuration;
                
                offset.x = p[6] - p[9];
                offset.y = p[7] - p[10];
                offset.z = p[8] - p[11];
                first = offset;
                first.x = -first.x;
                first.y = -first.y;
                first.z = -first.z;
                p[0] = p[9];
                p[1] = p[10];
                p[2] = p[11];
                extent = p[12];
                
                random = (s32)(RpRandom() & 0xfff);
                offset.x = extent / 2.0f - extent * (f32)random / 4096.0f;
                random = (s32)(RpRandom() & 0xfff);
                offset.y = extent / 2.0f - extent * (f32)random / 4096.0f;
                random = (s32)(RpRandom() & 0xfff);
                offset.z = extent / 2.0f - extent * (f32)random / 4096.0f;
                p[9] = offset.x;
                p[10] = offset.y;
                p[11] = offset.z;
                func_0024f7f0(node, &first);
                *(u32*)(node + 0x10) = 0;
                
                if (oldTimer >= firstDuration) {
                    oneMinus = 1.0f - ratio;
                    value.x = p[0] * oneMinus * oneMinus * oneMinus +
                              3.0f * p[3] * ratio * oneMinus * oneMinus +
                              3.0f * p[6] * ratio * ratio * oneMinus +
                              p[9] * ratio * ratio * ratio;
                    value.y = p[1] * oneMinus * oneMinus * oneMinus +
                              3.0f * p[4] * ratio * oneMinus * oneMinus +
                              3.0f * p[7] * ratio * ratio * oneMinus +
                              p[10] * ratio * ratio * ratio;
                    value.z = p[2] * oneMinus * oneMinus * oneMinus +
                              3.0f * p[5] * ratio * oneMinus * oneMinus +
                              3.0f * p[8] * ratio * ratio * oneMinus +
                              p[11] * ratio * ratio * ratio;
                    *(RwV3d*)(node + 0x14) = value;
                }
                duration = (*(u32*)(node + 0x34)) << 16;
                ratio2 = (f32)(s32)*(u32*)(node + 0x10) /
                         (f32)(s32)duration;
                oneMinus = 1.0f - ratio2;
                value.x = p[0] * oneMinus * oneMinus * oneMinus +
                          3.0f * p[3] * ratio2 * oneMinus * oneMinus +
                          3.0f * p[6] * ratio2 * ratio2 * oneMinus +
                          p[9] * ratio2 * ratio2 * ratio2;
                value.y = p[1] * oneMinus * oneMinus * oneMinus +
                          3.0f * p[4] * ratio2 * oneMinus * oneMinus +
                          3.0f * p[7] * ratio2 * ratio2 * oneMinus +
                          p[10] * ratio2 * ratio2 * ratio2;
                value.z = p[2] * oneMinus * oneMinus * oneMinus +
                          3.0f * p[5] * ratio2 * oneMinus * oneMinus +
                          3.0f * p[8] * ratio2 * ratio2 * oneMinus +
                          p[11] * ratio2 * ratio2 * ratio2;
                *(RwV3d*)(node + 0x14) = value; } break; case 0: break; case 2: { poses = (u32**)(node + 0x24);
                queued = 0;
                for (i = 0; i < 3; i++) {
                    pose = poses[i];
                    if (pose != NULL && (pose[2] & 2) == 0) {
                        K_ASSERT(list[0x82] < 0x80, 0x132);
                        list[list[0x82] + 2] = (u32)pose;
                        list[0x82]++;
                        queued = 1;
                    }
                }
                if (queued == 0) {
                    value.x = 0.0f;
                    value.y = 0.0f;
                    value.z = 0.0f;
                    for (i = 0; i < 3; i++) {
                        if (poses[i] != NULL) {
                            gcPose0024f960(poses[i], &first);
                            value.x += first.x;
                            value.y += first.y;
                            value.z += first.z;
                        }
                    }
                    *(RwV3d*)(node + 0x14) = value;
                } } break; case 3: { p = (f32*)(node + 0x24);
                if ((*(u32*)(node + 0x28) & 1u) != 0) {
                    if (*(u32*)(node + 0x10) >= *(u32*)(node + 0x2c)) {
                        *(u32*)(node + 0x10) = *(u32*)(node + 0x2c);
                    }
                    if (*(u32*)p == 0) {
                        ratio = (f32)(s32)*(u32*)(node + 0x10) /
                                (f32)(s32)*(u32*)(node + 0x2c);
                        first.x = p[6];
                        first.y = p[7];
                        first.z = p[8];
                        second.x = p[3];
                        second.y = p[4];
                        second.z = p[5];
                        second.x -= first.x;
                        second.y -= first.y;
                        second.z -= first.z;
                        second.x *= ratio;
                        second.y *= ratio;
                        second.z *= ratio;
                        value.x = first.x + second.x;
                        value.y = first.y + second.y;
                        value.z = first.z + second.z;
                        *(RwV3d*)(node + 0x14) = value;
                    }
                    else if (*(u32*)p == 1) {
                        ratio = (f32)(s32)*(u32*)(node + 0x10) /
                                1966080.0f;
                        ratio *= 0.5f;
                        value.x = p[3] * ratio + p[6];
                        value.y = p[4] * ratio + p[7];
                        value.z = p[5] * ratio + p[8];
                        *(RwV3d*)(node + 0x14) = value;
                    }
                }
                if ((*(u32*)(node + 0x28) & 1u) != 0 &&
                    *(u32*)(node + 0x10) >= *(u32*)(node + 0x2c)) {
                    *(u32*)(node + 0x28) &= ~2u;
                } } break; default: { K_ASSERT(0, 0x17d); } break; }
                break;
            }
            case 1: {
                mode = *(u32*)(node + 0x20);
                if (mode == 1) {
                    poses = (u32**)(node + 0x28);
                    queued = 0;
                    for (i = 0; i < 2; i++) {
                        pose = poses[i];
                        if ((pose[2] & 2) == 0) {
                            K_ASSERT(list[0x82] < 0x80, 0x1a9);
                            list[list[0x82] + 2] = (u32)pose;
                            list[0x82]++;
                            queued = 1;
                        }
                    }
                    if (queued == 0) {
                        gcPose0024f960(poses[0], &first);
                        gcPose0024f960(poses[1], &second);
                        value.x = second.x - first.x;
                        value.y = second.y - first.y;
                        value.z = second.z - first.z;
                        *(RwV3d*)(node + 0x14) = value;
                    }
                }
                else if (mode != 0) {
                    K_ASSERT(0, 0x1a9);
                }
                break;
            }
            case 2: {
                mode = *(u32*)(node + 0x24);
                if (mode == 1) {
                    poses = (u32**)(node + 0x28);
                    queued = 0;
                    for (i = 0; i < 2; i++) {
                        pose = poses[i];
                        if (pose != NULL && (pose[2] & 2) == 0) {
                            K_ASSERT(list[0x82] < 0x80, 0x1c4);
                            list[list[0x82] + 2] = (u32)pose;
                            list[0x82]++;
                            queued = 1;
                        }
                    }
                    if (queued == 0) {
                        gcPose0024f960(poses[0], &second);
                        gcPose0024f960(poses[1], &first);
                        value.x = first.x - second.x;
                        value.y = first.y - second.y;
                        value.z = first.z - second.z;
                        *(RwV3d*)(node + 0x14) = value;
                    }
                }
                else if (mode == 2) {
                    poses = (u32**)(node + 0x28);
                    queued = 0;
                    for (i = 0; i < 3; i++) {
                        pose = poses[i];
                        if (pose != NULL && (pose[2] & 2) == 0) {
                            K_ASSERT(list[0x82] < 0x80, 0x212);
                            list[list[0x82] + 2] = (u32)pose;
                            list[0x82]++;
                            queued = 1;
                        }
                    }
                    if (queued == 0) {
                        queued = 0;
                        for (i = 0; i < 3; i++) {
                            pose = poses[i];
                            if (pose != NULL) {
                                if (queued == 0) {
                                    gcPose0024fba0(pose, &quat);
                                    queued = 1;
                                }
                                else {
                                    gcPose0024fba0(pose, &nextQuat);
                                    composed.real = quat.real * nextQuat.real -
                                        (quat.imag.x * nextQuat.imag.x +
                                         quat.imag.y * nextQuat.imag.y +
                                         quat.imag.z * nextQuat.imag.z);
                                    composed.imag.x = quat.real * nextQuat.imag.x +
                                        quat.imag.x * nextQuat.real +
                                        quat.imag.y * nextQuat.imag.z -
                                        quat.imag.z * nextQuat.imag.y;
                                    composed.imag.y = quat.real * nextQuat.imag.y +
                                        quat.imag.y * nextQuat.real +
                                        quat.imag.z * nextQuat.imag.x -
                                        quat.imag.x * nextQuat.imag.z;
                                    composed.imag.z = quat.real * nextQuat.imag.z +
                                        quat.imag.z * nextQuat.real +
                                        quat.imag.x * nextQuat.imag.y -
                                        quat.imag.y * nextQuat.imag.x;
                                    quat = composed;
                                }
                            }
                        }
                        *(RtQuat*)(node + 0x14) = quat;
                    }
                }
                else if (mode == 3) {
                    pose = (u32*)(node + 0x28);
                    if ((*(u32*)(node + 0x10) >= pose[2]) &&
                        ((pose[1] & 1) != 0)) {
                        *(u32*)(node + 0x10) = pose[2];
                    }
                    if (pose[0] == 0) {
                        ratio = (f32)(s32)*(u32*)(node + 0x10) /
                                (f32)(s32)pose[2];
                        angle = ((f32)*(s32*)((u8*)pose + 0x1c) -
                                 (f32)*(s32*)((u8*)pose + 0x18)) * ratio +
                                (f32)*(s32*)((u8*)pose + 0x18);
                        angle = angle / fGpffff81f8 * 360.0f;
                        FUN_004bdde0(angle, (f32*)(node + 0x14),
                                     (const f32*)(node + 0x34), 0);
                    }
                    else if (pose[0] == 1) {
                        ratio = (f32)(s32)*(u32*)(node + 0x10) /
                                1966080.0f;
                        angle = (f32)*(s32*)((u8*)pose + 0x20) +
                                0.5f * (f32)*(s32*)((u8*)pose + 0x24) * ratio;
                        angle = angle / fGpffff81f8 * 360.0f;
                        FUN_004bdde0(angle, (f32*)(node + 0x14),
                                     (const f32*)(node + 0x34), 0);
                    }
                    else {
                        K_ASSERT(0, 0x2a5);
                    }
                    if ((pose[1] & 1) != 0 &&
                        *(u32*)(node + 0x10) >= pose[2]) {
                        pose[1] &= ~2u;
                    }
                }
                else if (mode == 4) {
                    u32 oldTimer;
                    u32 firstDuration;

                    p = (f32*)(node + 0x28);
                    oldTimer = *(u32*)(node + 0x10);
                    firstDuration = (*(u32*)(node + 0x64)) << 16;
                    ratio = (f32)(s32)oldTimer / (f32)(s32)firstDuration;
                    offset.x = p[6] - p[9];
                    offset.y = p[7] - p[10];
                    offset.z = p[8] - p[11];
                    first = offset;
                    first.x = -first.x;
                    first.y = -first.y;
                    first.z = -first.z;
                    p[0] = p[9];
                    p[1] = p[10];
                    p[2] = p[11];
                    extent = p[12];
                    random = (s32)(RpRandom() & 0xfff);
                    offset.x = extent / 2.0f - extent * (f32)random / 4096.0f;
                    random = (s32)(RpRandom() & 0xfff);
                    offset.y = extent / 2.0f - extent * (f32)random / 4096.0f;
                    random = (s32)(RpRandom() & 0xfff);
                    offset.z = extent / 2.0f - extent * (f32)random / 4096.0f;
                    p[9] = offset.x;
                    p[10] = offset.y;
                    p[11] = offset.z;
                    func_00250280(node, &first);
                    *(u32*)(node + 0x10) = 0;
                    if (oldTimer >= firstDuration) {
                        oneMinus = 1.0f - ratio;
                        value.x = p[0] * oneMinus * oneMinus * oneMinus +
                                  3.0f * p[3] * ratio * oneMinus * oneMinus +
                                  3.0f * p[6] * ratio * ratio * oneMinus +
                                  p[9] * ratio * ratio * ratio;
                        value.y = p[1] * oneMinus * oneMinus * oneMinus +
                                  3.0f * p[4] * ratio * oneMinus * oneMinus +
                                  3.0f * p[7] * ratio * ratio * oneMinus +
                                  p[10] * ratio * ratio * ratio;
                        value.z = p[2] * oneMinus * oneMinus * oneMinus +
                                  3.0f * p[5] * ratio * oneMinus * oneMinus +
                                  3.0f * p[8] * ratio * ratio * oneMinus +
                                  p[11] * ratio * ratio * ratio;
                        *(RwV3d*)(node + 0x14) = value;
                    }
                    duration = (*(u32*)(node + 0x3c)) << 16;
                    ratio2 = (f32)(s32)*(u32*)(node + 0x10) /
                             (f32)(s32)duration;
                    oneMinus = 1.0f - ratio2;
                    value.x = p[0] * oneMinus * oneMinus * oneMinus +
                              3.0f * p[3] * ratio2 * oneMinus * oneMinus +
                              3.0f * p[6] * ratio2 * ratio2 * oneMinus +
                              p[9] * ratio2 * ratio2 * ratio2;
                    value.y = p[1] * oneMinus * oneMinus * oneMinus +
                              3.0f * p[4] * ratio2 * oneMinus * oneMinus +
                              3.0f * p[7] * ratio2 * ratio2 * oneMinus +
                              p[10] * ratio2 * ratio2 * ratio2;
                    value.z = p[2] * oneMinus * oneMinus * oneMinus +
                              3.0f * p[5] * ratio2 * oneMinus * oneMinus +
                              3.0f * p[8] * ratio2 * ratio2 * oneMinus +
                              p[11] * ratio2 * ratio2 * ratio2;
                    value.x *= p[17];
                    value.y *= p[17];
                    value.z *= p[17];
                    *(RwV3d*)(node + 0xe0) = value;
                    axis.x = 1.0f;
                    axis.y = 0.0f;
                    axis.z = 0.0f;
                    FUN_004bdde0(value.x, (f32*)(node + 0x90),
                                 (const f32*)&axis, 0);
                    axis.x = 0.0f;
                    axis.y = 1.0f;
                    axis.z = 0.0f;
                    FUN_004bdde0(value.y, (f32*)(node + 0x90),
                                 (const f32*)&axis, 2);
                    axis.x = 0.0f;
                    axis.y = 0.0f;
                    axis.z = 1.0f;
                    FUN_004bdde0(value.z, (f32*)(node + 0x90),
                                 (const f32*)&axis, 2);
                    *(RtQuat*)(node + 0x14) = *(RtQuat*)(node + 0x90);
                }
                else {
                    K_ASSERT(0, 0x2ab);
                break;
            }
                break;
            }
            default:
                K_ASSERT(0, 0x2ab);
                break;
            }
        }
        if (queued == 0) {
            *(u32*)(node + 8) &= ~3u;
            list[0x82]--;
        }
    }
}
