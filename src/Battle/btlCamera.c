#include "Battle/btlCamera.h"
#include "Battle/battle.h"
#include "Battle/btlUnit.h"
#include "Battle/btlBoss.h"
#include "Kosaka/k_view.h"
#include "Kernel/Kwln/kwln.h"
#include "Main/Battle/Data/datUnit.h"
#include "Graphics/primitive.h"
#include "Battle/btlAction.h"
#include "libm.h"

/* Recovered battle-misc support prelude */
typedef int (*code)(...);
typedef union Local128 { u64 d[2]; u32 w[4]; } Local128;
typedef struct LocalCameraPacket {
  Local128 flag80;
  Local128 flag20;
  Local128 flag8;
  Local128 flag2;
  Local128 flag1;
  f32 f100;
  f32 f104;
  f32 f108;
  f32 f10c;
  f32 f110;
  f32 f114;
  f32 f118;
  f32 f11c;
  RwV3d center;
} LocalCameraPacket;
u32 FUN_002a32f0(int param_1);
u32 FUN_002a3380(u8* camera);
u32 FUN_002a3420(int param_1);
u8 FUN_002a3520(int param_1);
u64 FUN_002a3550(u8* camera);
u32 FUN_002a3590(float *param_1, float *param_2);
s32 FUN_002a3750(BtlCamera* camera,u32 unit);
extern s16 btlUnit00282c30(BtlUnit* unit);
extern s16 func_002835e0(BtlUnit* unit,u16 id,f32 scale);
extern s16 btlUnitGetAnimFrame(BtlUnit* unit);
u8 FUN_002a3820(int param_1);
#pragma alias FUN_002a3820_u32 FUN_002a3820
extern u32 FUN_002a3820_u32(int param_1);
extern void FUN_004c31b0_typed(RwMatrix *matrix, const RwV3d *axis, f32 angle, s32 mode);
#pragma alias FUN_004c31b0_typed FUN_004c31b0
u32 FUN_002a3850(int param_1);
u16 FUN_002a3a80(void);
void FUN_002a3a90(int param_1);
void FUN_002a3e80(float param_1,u8* param_2,u8* param_3,u8* param_4,u32 param_5);
 #pragma alias FUN_002a3e80_ab330 FUN_002a3e80
 extern void FUN_002a3e80_ab330(BtlAction* action, RwV3d* unitPos,
                                 f32* targetPos, s32 mode, f32 distance);
extern u64 FUN_00280050();
#pragma alias FUN_00280050_typed FUN_00280050
extern void FUN_00280050_typed(BtlUnit* unit, RwV3d* out);
extern f32 gp0xffff80e0;
u64 FUN_0027ffb0();
#pragma alias FUN_002a3520_result FUN_002a3520
u32 FUN_002a3520_result(int param_1);
#pragma alias FUN_002fdbb0_result FUN_002fdbb0
extern u32 FUN_002fdbb0_result(BtlAction* action, BtlUnit* persona);
extern f32 fGpffff8090;
#pragma alias FUN_002a3520_s32 FUN_002a3520
extern s32 FUN_002a3520_s32(void);
#pragma alias FUN_002a3550_s32 FUN_002a3550
extern s32 FUN_002a3550_s32(u8* camera);
/* Target-local ABI aliases for FUN_002b3980. */
#pragma alias FUN_002a3e80_action FUN_002a3e80
extern void FUN_002a3e80_action(void* action, u32 arg_1, u32 arg_2, u32 arg_3, u32 arg_4);
extern u8* DAT_007ce3ec;
void FUN_002a42a0(void);
void FUN_002a4470(f32 *param_1, f32 *param_2);
void FUN_002a44b0(f32 *param_1, f32 *param_2);
void FUN_002a44f0(f32 *param_1, f32 *param_2);
void FUN_002a4530(float *param_1,float *param_2,float *param_3,float *param_4);
void FUN_002a4690(void* out, const void* first, const void* second, const void* config);
void FUN_002a4a70(void);
void FUN_002a4c20(void);
extern f32 DAT_007cae38;
extern f32 DAT_007caf3c;
extern f32 DAT_007caf40;
extern f32 DAT_007caf44;
extern f32 DAT_007caf48;
extern f32 DAT_007caf4c;
extern f32 DAT_007caf50;
extern f32 DAT_007caf54;
extern code DAT_00960178[];
extern code DAT_0096017c[];
extern int iGpffffb710;
extern u16 (*gp0xffffb710)[14];
extern u8* iGpffffb6fc;
extern u8 DAT_006941d4[];
extern u8 DAT_00694c90[];
extern u8* DAT_007ce3ec;
void FUN_002a42a0(void);
void FUN_002a4470(f32 *param_1, f32 *param_2);
void FUN_002a44b0(f32 *param_1, f32 *param_2);
void FUN_002a44f0(f32 *param_1, f32 *param_2);
void FUN_002a4530(float *param_1,float *param_2,float *param_3,float *param_4);
void FUN_002a4690(void* out, const void* first, const void* second, const void* config);
/* b6070 exact call signatures */
#pragma alias FUN_00300580_b6070 FUN_00300580
extern long FUN_00300580_b6070(void* unitData, u32 flags);
#pragma alias FUN_00280130_b6070 FUN_00280130
extern void FUN_00280130_b6070(BtlUnit* unit, RwV3d* out);
#pragma alias FUN_004be1e0_b6070 FUN_004be1e0
extern void FUN_004be1e0_b6070(RwV3d* out, const RwV3d* basis, s32 count, const void* source);
#pragma alias FUN_004c31b0_b6070 FUN_004c31b0
extern void FUN_004c31b0_b6070(RwMatrix* matrix, const RwV3d* axis, f32 angle, s32 mode);
#pragma alias FUN_004c69f0_b6070 FUN_004c69f0
extern f32 FUN_004c69f0_b6070(RwV3d* out, const RwV3d* in);
#pragma alias FUN_004c6c60_b6070 FUN_004c6c60
extern void FUN_004c6c60_b6070(RwV3d* out, const RwV3d* in, const RwMatrix* matrix);
#pragma alias FUN_002a4690_b6070 FUN_002a4690
extern void FUN_002a4690_b6070(void* out, const void* first, const void* second, const void* config);
#pragma alias FUN_002a2290_b6070 FUN_002a2290
extern void FUN_002a2290_b6070(BtlCamera* camera, const RwV3d* start, const RwV3d* end, s32 mode);
#pragma alias FUN_002a3110_b6070 FUN_002a3110
extern void FUN_002a3110_b6070(BtlCamera* camera, f32 step);
void FUN_002a4a70(void);
void FUN_002a4c20(void);
extern f32 DAT_007cae38;
extern f32 DAT_007caf3c;
extern f32 DAT_007caf40;
extern f32 DAT_007caf44;
extern f32 DAT_007caf48;
extern f32 DAT_007caf4c;
extern f32 DAT_007caf50;
extern f32 DAT_007caf54;
extern code DAT_00960178[];
extern code DAT_0096017c[];
extern int iGpffffb710;
extern u16 (*gp0xffffb710)[14];
extern u8* iGpffffb6fc;
extern u8 DAT_006941d4[];
extern u8 DAT_00694c90[];
void FUN_002a4a70(void);
void FUN_002a4c20(void);
extern f32 DAT_007cae38;
extern f32 DAT_007caf3c;
extern f32 DAT_007caf40;
extern f32 DAT_007caf44;
extern f32 DAT_007caf48;
extern f32 DAT_007caf4c;
extern f32 DAT_007caf50;
extern f32 DAT_007caf54;
extern code DAT_00960178[];
extern code DAT_0096017c[];
extern int iGpffffb710;
extern u16 (*gp0xffffb710)[14];
extern u8* iGpffffb6fc;
extern u8 DAT_006941d4[];
extern u8 DAT_00694c90[];

extern f32 FUN_002d21e0(f32 target, f32* motion);
extern f32 fGpffff807c;
extern f32 fGpffff80e8;
extern u64 FUN_004c6c60(RwV3d* out, RwV3d* in, RwMatrix* matrix);
extern u64 FUN_002d1de0();
extern f32 fGpffff83cc;
extern void FUN_002a3010(BtlCamera* camera, f32 step);
extern void FUN_002a2ed0();
extern RwV3d D_00697880;
extern RwV3d D_006978A0;
typedef struct F32Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} F32Vec4;
extern RwV3d D_00697870;
extern f32 FUN_002d1fd0(f32* from, f32* to, f32* eye, f32* out);
#pragma alias FUN_002d1f30_b21f0v2 FUN_002d1f30
extern f32 FUN_002d1f30_b21f0v2(RtQuat *first, RtQuat *second);
#pragma alias FUN_00280130_b21f0v2 FUN_00280130
extern void FUN_00280130_b21f0v2(BtlUnit *unit, RwV3d *out);
#pragma alias FUN_004c69f0_b21f0v2 FUN_004c69f0
extern f32 FUN_004c69f0_b21f0v2(RwV3d *out, RwV3d *in);
#pragma alias FUN_004c6b20_b21f0v2 FUN_004c6b20
extern void FUN_004c6b20_b21f0v2(RwV3d *out, RwV3d *in);
extern void func_002af960(BtlCamera* camera);
extern f32 fGpffff8060;
extern f32 fGpffff8030;
extern f32 fGpffff8134;
extern u8* iGpffffb73c;
extern f32 D_00697898;
extern f32 fGpffff80c0;
extern u32 effMiscRand(void* state);
extern int FUN_00198590();
extern void FUN_004c9d70(int handle, f32 value);
extern void FUN_001a4580(int handle, f32 value);
extern u32 FUN_0048dab0(int, int, u32);
extern f32 fGpffff8064;
extern f32 fGpffff8078;
extern f32 fGpffff8080;
extern f32 fGpffff8084;
extern f32 fGpffff8088;
extern f32 fGpffff80c4;
extern f32 fGpffff811c;
extern void btlUnit002880e0(BtlUnit* unit, u16 param_2);
extern RwV3d D_00697890;
extern float gp0xffff8070;
extern f32 gp0xffff8030;
extern f32 gp0xffff8094;
extern f32 fGpffff82c8;
extern f32 fGpffff805c;
extern u32 FUN_002a2050(u16* camera, f32* pos, f32* rot);
extern void FUN_002a1e00(f32* out, f32* start, f32* end, f32 t);
extern f32 FUN_00280870(u32 param_1, u32 param_2, void* param_3, void* param_4, void* param_5, u32 param_6);
extern f32 tanf(f32 angle);
extern f32 fGpffff8098;
#pragma alias FUN_004be1e0_typed FUN_004be1e0
extern void FUN_004be1e0_typed(RwV3d *out, const RwV3d *basis, s32 mode, const void *source);
#pragma alias FUN_004be310_typed FUN_004be310
extern void FUN_004be310_typed(const void *first, const void *second, void *out);
#pragma alias FUN_004c6b20_typed FUN_004c6b20
extern void FUN_004c6b20_typed(f32 *out, f32 *in);
extern u8 DAT_006978A0[];
extern u8 DAT_006978A0_arr[];
extern u8 DAT_00697880_arr[];
extern f32 FUN_002d1f30_typed(const f32 *first, const f32 *second);
#pragma alias FUN_002d1f30_typed FUN_002d1f30



// 006939f0
static const BtlCameraStateEntry sCameraStateEntries[] =
{
    // TODO
    {NULL, NULL, 0, 0, NULL}, // BTLCAMERA_STATE_NULL
    {NULL, NULL, 1, 0, "NOP"}, // BTLCAMERA_STATE_NOP
};

// FUN_002a31b0 NONMATCHING
void btlCameraUpdate(BtlCamera* camera)
{
    f32 step;
    f32 t;
    f32 poly;
    u16 flags;
    u8* g;

    flags = *(u16*)camera;
    if ((flags & 2) != 0)
    {
        step = FUN_002d21e0(1.0f, (f32*)((u8*)camera + 0x84)) - *(f32*)((u8*)camera + 0x80);
    }
    else if ((flags & 4) != 0)
    {
        t = *(f32*)((u8*)camera + 0x94);
        if (t < fGpffff83cc)
        {
            t = t + 1.0f / *(f32*)((u8*)camera + 0x84);
            *(f32*)((int)camera + 0x94) = t;
            step = 2.0f * ((0.0f + -1.0f + (-2.0f * t) * t + 4.0f * t) - 0.5f) -
                   *(f32*)((u8*)camera + 0x80);
        }
        else
        {
            step = 0.0f;
        }
    }
    else
    {
        step = 1.0f / *(f32*)((u8*)camera + 0x84);
    }
    *(f32*)((u8*)camera + 0x80) += step;
    FUN_002a3010(camera, step);
    g = iGpffffb6fc;
    FUN_002a2ed0(g + 0x20, g + 0xbc, g + 0xc8);
}

// FUN_002a38f0 NONMATCHING
void btlCameraSetState(u16 state, BtlAction* action, u32 param_3)
{
    const BtlCameraStateEntry* entry;
    const BtlCameraStateEntry* bossEntry;
    s32 temp_3;
    s32 temp_6;
    long var_7;

    bossEntry = btlBossGetCameraStateEntry(state);
    if (bossEntry == NULL)
    {
        entry = &sCameraStateEntries[state];
    }
    else
    {
        entry = bossEntry;
    }
    temp_6 = state & 0xffff;
    if (gBtl->camera.state != temp_6 || entry->unk_08 != 0)
    {
        var_7 = 2;
        while ((u16)var_7 == 0)
        {
            *(u16*)(iGpffffb6fc + 0x104 + (u16)var_7 * 2) =
                *(u16*)(iGpffffb6fc + 0x102 + (u16)var_7 * 2);
            var_7 = ((u16)var_7 - 1) & 0xffff;
        }

        *(u16*)((u8*)gBtl + 0x104) = gBtl->camera.state;
        if (gBtl->camera.state == temp_6)
        {
            *(u16*)((u8*)gBtl + 0x10a) =
                *(u16*)((u8*)gBtl + 0x10a) + 1;
        }
        else
        {
            *(u16*)((u8*)gBtl + 0x10a) = 0;
        }
        gBtl->camera.state = state;
        gBtl->camera.updateCounter = 0;
        gBtl->camera.framesUntilUpdate = 0;
        gBtl->camera.action = action;

        if (entry->unk_0c != 0)
        {
            gBtl->camera.flags |= BTLCAMERA_FLAG_UNK02;
        }
        else
        {
            gBtl->camera.flags &= ~BTLCAMERA_FLAG_UNK02;
        }

        if (param_3 != 0)
        {
            FUN_002a42a0();
        }
        if (entry->init != NULL)
        {
            entry->init(&gBtl->camera);
        }
    }
}

// FUN_002a3b00
u32 btlCameraUpdateSetStatePacket(void* work)
{
    BtlCameraPacketSetState* packet;

    packet = (BtlCameraPacketSetState*)work;

    btlCameraSetState(packet->state, packet->action, 1);

    return 1;
}

// FUN_002a3b40
BtlPacket* btlCameraCreateSetStatePacket(BtlAction* action, u16 state)
{
    BtlPacket* packet;
    BtlCameraPacketSetState* work;

    packet = btlPacketCreate(BTLCAMERA_PACKET_SETSTATE, sizeof(BtlCameraPacketSetState));

    packet->updateFunc = btlCameraUpdateSetStatePacket;

    work = (BtlCameraPacketSetState*)packet->workData;

    work->action = action;
    work->state = state;

    return packet;
}

// FUN_002a3ba0
u32 btlCameraUpdateMoveToPacket(void* work)
{
    BtlCameraPacketMoveTo* packet;
    struct
    {
        BtlCameraKeyFrame current;
        u32 pad;
        BtlCameraKeyFrame start;
        BtlCameraKeyFrame end;
    } frames;
    u16* cameraData;
    u8* battleBytes;

    packet = (BtlCameraPacketMoveTo*)work;

    btlCameraSetState(BTLCAMERA_STATE_NOP, packet->action, 1);

    if (packet->currPosAsStart != 0)
    {
        FUN_002a4470((f32*)&frames.start,
                     (f32*)((u8*)gBtl + 0xbc));
    }
    else
    {
        FUN_002a4690(&frames.start.rot, &packet->startPos,
                     &packet->startTarget, &D_00697880);
        frames.start.pos = packet->startPos;
    }

    FUN_002a4690(&frames.end.rot, &packet->endPos, &packet->endTarget,
                 &D_00697880);
    frames.end.pos = packet->endPos;

    cameraData = (u16*)((u8*)gBtl + 0x20);
    cameraData[0] = 1;
    cameraData[0x3a] = 0;
    cameraData[0x3b] = 0;
    cameraData[0x3c] = 0;
    *(u32*)((u8*)cameraData + 0x80) = 0;
    *(u32*)((u8*)cameraData + 0x7c) = 0;

    FUN_002a2050(cameraData, (f32*)&frames.start.pos,
                 (f32*)&frames.start.rot);
    FUN_002a1e00((f32*)&frames.current, (f32*)&frames.start,
                 (f32*)&frames.end, fGpffff82c8);
    FUN_002a2050(cameraData, (f32*)&frames.current.pos,
                 (f32*)&frames.current.rot);
    FUN_002a1e00((f32*)&frames.current, (f32*)&frames.start,
                 (f32*)&frames.end, fGpffff805c);
    FUN_002a2050(cameraData, (f32*)&frames.current.pos,
                 (f32*)&frames.current.rot);
    FUN_002a2050(cameraData, (f32*)&frames.end.pos,
                 (f32*)&frames.end.rot);

    battleBytes = (u8*)gBtl;
    *(f32*)(battleBytes + 0xa4) =
        (60.0f * (2.0f * packet->duration)) / 2.0f;
    *(f32*)(battleBytes + 0xb4) = 0.5f;
    *(u16*)(battleBytes + 0x20) =
        (u16)(*(u16*)(battleBytes + 0x20) & 0xfffd);
    *(u16*)(battleBytes + 0x20) =
        (u16)(*(u16*)(battleBytes + 0x20) | 4);

    return 1;
}

// FUN_002a3d70
BtlPacket* btlCameraCreateMoveToPacket(BtlAction* action, 
                                       const RwV3d* startPos,
                                       const RwV3d* startTarget,
                                       const RwV3d* endPos,
                                       const RwV3d* endTarget,
                                       f32 duration)
{
    BtlPacket* packet;
    BtlCameraPacketMoveTo* work;

    packet = btlPacketCreate(BTLCAMERA_PACKET_MOVETO, sizeof(BtlCameraPacketMoveTo));

    packet->updateFunc = btlCameraUpdateMoveToPacket;

    work = (BtlCameraPacketMoveTo*)packet->workData;

    work->action = action;
    work->duration = duration;

    if (startPos != NULL && startTarget != NULL)
    {
        work->startPos = *startPos;
        work->startTarget = *startTarget;

        work->currPosAsStart = 0;
    }
    else
    {
        work->currPosAsStart = 1;
    }

    work->endPos = *endPos;
    work->endTarget = *endTarget;

    return packet;
}

// FUN_002a4330
void btlCameraCheckUnitFade()
{
    RwFrame* cameraFrame;
    RwMatrix* cameraMat;
    BtlUnitList* currUnitList;
    BtlUnit* currUnit;
    u16 i;
    RwV3d sphereCenter;
    RwV3d diff;

    cameraFrame = (RwFrame*)kwlnGetMainCamera()->object.object.parent;
    cameraMat = &cameraFrame->modelling;

    // PC and EC
    for (i = 0; i < UNIT_GENUS_PS; i++)
    {
        currUnitList = &gBtl->unitLists[i];
        currUnit = currUnitList->head;

        while (currUnit != NULL)
        {
            if (currUnit->flags3 & BTLUNIT_FLAG3_UNK08)
            {
                btlUnitGetSphereWorldCenter(currUnit, (RwV3d*)&sphereCenter);

                diff.x = cameraMat->pos.x - sphereCenter.x;
                diff.y = cameraMat->pos.y - sphereCenter.y;
                diff.z = cameraMat->pos.z - sphereCenter.z;

                if (RwV3dLength(&diff) <= (currUnit->sphereRadius * currUnit->scale) + 200.0f)
                {
                    btlUnitSetFlags(currUnit, BTLUNIT_FLAG_FADE);
                }
                else
                {
                    btlUnitClearFlags(currUnit, BTLUNIT_FLAG_FADE);
                }
            }

            currUnit = currUnit->next;
        }
    }
}

// FUN_002a46e0
void btlCameraMain()
{
    const BtlCameraStateEntry* entry;
    u16 state;
    RwMatrix mat;

    if (!(gBtl->camera.flags & BTLCAMERA_FLAG_FREEZE))
    {
        if (gBtl->camera.framesUntilUpdate <= 0)
        {
            state = gBtl->camera.state;
            entry = btlBossGetCameraStateEntry(state);
            if (entry == NULL)
            {
                entry = &sCameraStateEntries[state];
            }

            if (entry->update != NULL)
            {
                entry->update(&gBtl->camera);
            }

            btlCameraUpdate(&gBtl->camera);

            gBtl->camera.updateCounter++;
        }
        else
        {
            gBtl->camera.framesUntilUpdate--;
        }

        RtQuatConvertToMatrix(&gBtl->camera.rot, &mat);
        mat.pos = gBtl->camera.pos;

        RwFrameTransform((RwFrame*)kwlnGetMainCamera()->object.object.parent,
                         &mat,
                         rwCOMBINEREPLACE);
        K_View_SetFov(kwlnGetMainCamera(), gRadToDegFactor2 * gBtl->camera.fovRad);
    }

    if (gBtl->camera.flags & BTLCAMERA_FLAG_UNK02)
    {
        btlCameraCheckUnitFade();
    }
}

// FUN_002a48f0
void btlCameraDebugDraw()
{
    RwMatrix axisMat;
    RwRGBA quadCol;

    if (!(gBtl->flags & BTL_FLAG_UNK04) &&
        !(gBtl->flags2 & BTL_FLAG2_UNK04) &&
         (gBtl->flags2 & BTL_FLAG2_UNK08))
    {
        quadCol.r = 255;
        quadCol.g = 255;
        quadCol.b = 0;
        quadCol.a = 255;

        RtQuatConvertToMatrix(&gBtl->camera.rot, &axisMat);
        axisMat.pos = gBtl->camera.pos;

        primQuad3D(&gBtl->camera.pos, &quadCol, 6.0f, 1);
        primAxisLine3D(&axisMat, 150.0f, 1);
    }
}

// FUN_002a4c50
void btlCameraFreeze()
{
    gBtl->camera.flags |= BTLCAMERA_FLAG_FREEZE;
}
extern void FUN_002a2290(u16* camera, RwV3d* first, RwV3d* second, int mode);
extern void FUN_002a3110(u16* camera, f32 param_1);
extern f32 FUN_002d1f30();
extern u64 FUN_00351bb0();
extern u64 FUN_004be310();
extern u64 FUN_004c6b20();
extern f32 FUN_0052e930(f32 x);
extern void FUN_002b6460();

extern f32 fGpffff812c;
typedef struct BtlCameraQuatBlend
{
    RtQuat first;
    RtQuat second;
    f32 scalar;
    s32 flag;
} BtlCameraQuatBlend;

extern void FUN_0027f7c0(BtlUnit* unit, RwV3d* out, void* p3, void* p4);
extern RwV3d D_00697880;
extern float fGpffff8094;
extern float fGpffff8070;
extern void FUN_004bdde0(f32* quat, const f32* axis, f32 angle, s32 mode);
extern RwV3d D_006978A0;
extern f32 fGpffff80f0;
extern f32 fGpffff80f4;
extern f32 fGpffff80f8;
extern f32 fGpffff8138;
extern f32 fGpffff8130;
extern f32 fGpffff8048;
extern f32 fGpffff8118;
extern f32 fGpffff8050;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern u16 FUN_002d1600(int);
extern u32 FUN_002d6290(int);
extern u32 FUN_002d62d0(int);
extern u32 FUN_002d6370(s16);
extern u32 FUN_002d63b0(int, s16, int);

// FUN_002a4c70 NONMATCHING
void FUN_002a4c70(f32 param_1, f32 param_2, BtlCamera* camera)
{
    struct CameraWork
    {
        BtlCameraKeyFrame current;
        RwV3d target;
        RtQuat targetRot;
        u8 pad_38[8];
        BtlCameraQuatBlend blend;
        u8 pad_68[8];
        RtQuat blendedRot;
        u8 pad_80[8];
        RwV2d horizontal;
        RwV3d center;
        u8 pad_9c[4];
        RwV3d pointNear;
        u8 pad_ac[4];
        RwV3d delta;
        u8 pad_bc[4];
        RwV3d candidate;
        u8 pad_cc[4];
    } work;
    BtlUnit* unit;
    f32 halfDistance;
    f32 desiredDistance;
    f32 radius;
    f32 nearAngle;
    f32 angle;
    f32 ratio;
    f32 sideOffset;
    f32 scale;
    f32 x;
    f32 xSquared;

    unit = *(BtlUnit**)((u8*)camera->action + 0x30);
    radius = unit->sphereRadius * unit->scale;
    FUN_002a4470((f32*)&work.current, (f32*)((u8*)camera + 0x9c));
    btlUnitGetSphereWorldCenter(unit, &work.center);

    if (radius < 180.0f)
    {
        work.center.y = work.center.y +
                        fGpffff8094 * (unit->unk_8c * unit->scale);
        desiredDistance = (1.5f * radius) /
                          FUN_0052e930(0.5f * camera->fovRad);
    }
    else
    {
        work.center.y = work.center.y +
                        0.25f * (unit->unk_8c * unit->scale);
        desiredDistance = (2.5f * radius) /
                          FUN_0052e930(0.5f * camera->fovRad);
    }

    work.delta.x = work.current.pos.x - work.center.x;
    work.delta.y = work.current.pos.y - work.center.y;
    work.delta.z = work.current.pos.z - work.center.z;
    halfDistance = RwV3dLength(&work.delta) * 0.5f;
    if (desiredDistance > halfDistance)
    {
        desiredDistance = halfDistance;
    }

    RtQuatTransformVectors(&work.delta, &D_00697890, 1, &unit->rot);
    x = 0.5f * radius;
    work.candidate.x = work.delta.x * x;
    work.candidate.y = work.delta.y * x;
    work.candidate.z = work.delta.z * x;
    work.pointNear.x = work.center.x + work.candidate.x;
    work.pointNear.y = work.center.y + work.candidate.y;
    work.pointNear.z = work.center.z + work.candidate.z;

    work.candidate.x = work.delta.x * desiredDistance;
    work.candidate.y = work.delta.y * desiredDistance;
    work.candidate.z = work.delta.z * desiredDistance;
    work.candidate.x = work.candidate.x + work.center.x;
    work.candidate.y = work.candidate.y + work.center.y;
    work.candidate.z = work.candidate.z + work.center.z;
    work.candidate.y +=
        fGpffff8098 * (unit->unk_8c * unit->scale);

    work.delta.x = work.candidate.x - work.pointNear.x;
    work.delta.y = work.candidate.y - work.pointNear.y;
    work.delta.z = work.candidate.z - work.pointNear.z;
    RwV3dNormalize(&work.delta, &work.delta);
    work.candidate.x = work.delta.x * desiredDistance;
    work.candidate.y = work.delta.y * desiredDistance;
    work.candidate.z = work.delta.z * desiredDistance;
    work.candidate.x = work.candidate.x + work.pointNear.x;
    work.candidate.y = work.candidate.y + work.pointNear.y;
    work.candidate.z = work.candidate.z + work.pointNear.z;

    FUN_002a4690(&work.targetRot, &work.candidate,
                 &work.pointNear, &D_00697880);
    angle = FUN_002d1f30((f32*)&work.current.rot,
                         (f32*)&work.targetRot);
    nearAngle = fGpffff812c * param_1;
    if (angle > nearAngle)
    {
        if (angle > fGpffff812c * param_2)
        {
            u16 cameraMode;

            cameraMode = *(u16*)((u8*)camera + 0xe4);
            if (cameraMode != 2 &&
                cameraMode != 0x23 &&
                cameraMode != 0x1f &&
                cameraMode != 0x1d &&
                cameraMode != 0x1c)
            {
                FUN_002b6460(camera);
                FUN_00351bb0(8);
                return;
            }
        }

        ratio = nearAngle / angle;
        FUN_004be310((f32*)&work.current.rot,
                     (f32*)&work.targetRot,
                     (f32*)&work.blend);
        if (ratio <= 0.0f)
        {
            work.blendedRot = work.current.rot;
        }
        else if (ratio >= 1.0f)
        {
            work.blendedRot = work.targetRot;
        }
        else
        {
            f32 firstWeight;
            f32 secondWeight;

            firstWeight = 1.0f - ratio;
            secondWeight = ratio;
            if (work.blend.flag == 0)
            {
                x = firstWeight * work.blend.scalar;
                xSquared = x * x;
                firstWeight =
                    xSquared * x *
                    (xSquared *
                     (xSquared *
                      (xSquared *
                       (xSquared *
                        (fGpffff8130 * xSquared +
                         fGpffff8048) +
                        fGpffff8118) +
                       fGpffff8050) +
                      fGpffff8054) +
                     fGpffff8058) +
                    x;

                x = secondWeight * work.blend.scalar;
                xSquared = x * x;
                secondWeight =
                    xSquared * x *
                    (xSquared *
                     (xSquared *
                      (xSquared *
                       (xSquared *
                        (fGpffff8130 * xSquared +
                         fGpffff8048) +
                        fGpffff8118) +
                       fGpffff8050) +
                      fGpffff8054) +
                     fGpffff8058) +
                    x;
            }

            work.blendedRot.imag.x =
                work.blend.first.imag.x * firstWeight +
                work.blend.second.imag.x * secondWeight;
            work.blendedRot.imag.y =
                work.blend.first.imag.y * firstWeight +
                work.blend.second.imag.y * secondWeight;
            work.blendedRot.imag.z =
                work.blend.first.imag.z * firstWeight +
                work.blend.second.imag.z * secondWeight;
            work.blendedRot.real =
                work.blend.first.real * firstWeight +
                work.blend.second.real * secondWeight;
        }

        RtQuatTransformVectors(&work.delta, &D_006978A0, 1,
                               &work.blendedRot);
        work.candidate.x = work.pointNear.x + work.delta.x;
        work.candidate.y = work.pointNear.y + work.delta.y;
        work.candidate.z = work.pointNear.z + work.delta.z;
        FUN_002a4690(&work.targetRot, &work.candidate,
                     &work.pointNear, &D_00697880);
    }

    if (halfDistance < 600.0f)
    {
        halfDistance = 600.0f;
    }
    RtQuatTransformVectors(&work.delta, &D_006978A0, 1,
                           &work.targetRot);
    work.delta.x *= halfDistance;
    work.delta.y *= halfDistance;
    work.delta.z *= halfDistance;

    sideOffset = halfDistance *
                 FUN_0052e930(gp0xffff8070 *
                              (0.5f * camera->fovRad)) *
                 0.21875f;
    work.horizontal.x = work.delta.x;
    work.horizontal.y = work.delta.z;
    FUN_004c6b20((f32*)&work.horizontal,
                 (f32*)&work.horizontal);
    work.pointNear.x += work.horizontal.y * sideOffset;
    work.pointNear.z -= work.horizontal.x * sideOffset;

    work.target.x = work.pointNear.x + work.delta.x;
    work.target.y = work.pointNear.y + work.delta.y;
    work.target.z = work.pointNear.z + work.delta.z;
    if (work.current.pos.y < 100.0f)
    {
        work.current.pos.y = 100.0f;
    }
    if (work.target.y < 100.0f)
    {
        work.target.y = 100.0f;
    }

    angle = FUN_002d1f30((f32*)&work.current.rot,
                         (f32*)&work.targetRot);
    scale = 2.0f;
    if (angle > 0.0f)
    {
        ratio = nearAngle / angle;
        if (ratio > 1.0f)
        {
            scale = ratio * 1.25f;
        }
        else
        {
            scale = 1.25f;
        }
        if (scale > 2.0f)
        {
            scale = 2.0f;
        }
    }
    FUN_002a2290((u16*)camera, &work.current.pos, &work.target, 1);
    FUN_002a3110((u16*)camera, scale);
}

// FUN_002A5430
void FUN_002a5430(BtlCamera* camera)
{
    FUN_002a4c70(45.0f, 200.0f, camera);
}

// FUN_002a5460
void FUN_002a5460(BtlCamera* camera)
{
    BtlAction* action;
    BtlUnit* unit;
    RwV3d center;

    action = camera->action;
    if (action != NULL &&
        (*(u16*)((u8*)action + 0x1a) & 1) != 0)
    {
        unit = *(BtlUnit**)((u8*)action + 0x30);
        btlUnitGetSphereWorldCenter(unit, &center);
        FUN_002a3e80(unit->sphereRadius * unit->scale * 0.5f,
                     (u8*)camera->action,
                     (u8*)((u8*)camera + 0x9c),
                     (u8*)&center,
                     0x31);
    }
}

/* Retail camera callbacks for the 0x2A4C70-0x2A95D0 window.  The original
 * routines share the same unit framing and look-at path; the callbacks keep
 * that state typed while remaining NONMATCHING until instruction scheduling
 * is tuned against the retail object. */
static BtlUnit* btlCameraRangeUnit(BtlCamera* camera)
{
    if (camera == NULL || camera->action == NULL)
    {
        return NULL;
    }
    return camera->action->unit;
}

static BtlUnit* btlCameraRangeTarget(BtlCamera* camera)
{
    BtlAction* target;
    if (camera == NULL || camera->action == NULL)
    {
        return NULL;
    }
    target = camera->action->target.targetedActions[0];
    return target != NULL ? target->unit : NULL;
}

static void btlCameraRangeCross(RwV3d* out, const RwV3d* a, const RwV3d* b)
{
    out->x = a->y * b->z - a->z * b->y;
    out->y = a->z * b->x - a->x * b->z;
    out->z = a->x * b->y - a->y * b->x;
}

static void btlCameraRangeLookAt(BtlCamera* camera, const RwV3d* eye,
                                 const RwV3d* target)
{
    RwV3d at;
    RwV3d upAxis;
    RwV3d right;
    RwV3d up;
    RwMatrix matrix;

    at.x = target->x - eye->x;
    at.y = target->y - eye->y;
    at.z = target->z - eye->z;
    if (RwV3dNormalize(&at, &at) <= 0.0001f)
    {
        at.x = 0.0f;
        at.y = 0.0f;
        at.z = 1.0f;
    }
    upAxis.x = 0.0f;
    upAxis.y = 1.0f;
    upAxis.z = 0.0f;
    btlCameraRangeCross(&right, &upAxis, &at);
    if (RwV3dNormalize(&right, &right) <= 0.0001f)
    {
        upAxis.x = 0.0f;
        upAxis.y = 0.0f;
        upAxis.z = 1.0f;
        btlCameraRangeCross(&right, &upAxis, &at);
        RwV3dNormalize(&right, &right);
    }
    btlCameraRangeCross(&up, &at, &right);
    RwV3dNormalize(&up, &up);
    matrix.right = right;
    matrix.up = up;
    matrix.at = at;
    matrix.pos = *eye;
    matrix.pad1 = matrix.pad2 = matrix.pad3 = 0;
    rwMatrixSetFlags(&matrix, rwMATRIXTYPEORTHONORMAL);
    camera->pos = *eye;
    RtQuatConvertFromMatrix(&camera->rot, &matrix);
}

static void btlCameraRangeFrame(BtlCamera* camera, const RwV3d* first,
                                const RwV3d* second, f32 margin, f32 minimum)
{
    RwV3d center;
    RwV3d delta;
    RwV3d direction;
    RwV3d eye;
    f32 radius;
    f32 distance;

    if (camera == NULL || first == NULL)
    {
        return;
    }
    if (second != NULL)
    {
        center.x = (first->x + second->x) * 0.5f;
        center.y = (first->y + second->y) * 0.5f;
        center.z = (first->z + second->z) * 0.5f;
        delta.x = second->x - first->x;
        delta.y = second->y - first->y;
        delta.z = second->z - first->z;
        radius = RwV3dLength(&delta) * 0.5f;
    }
    else
    {
        center = *first;
        radius = 0.0f;
    }
    radius += 100.0f;
    distance = radius * (margin < 1.0f ? 1.0f : margin);
    if (distance < minimum)
    {
        distance = minimum;
    }
    direction.x = camera->pos.x - center.x;
    direction.y = camera->pos.y - center.y;
    direction.z = camera->pos.z - center.z;
    if (RwV3dNormalize(&direction, &direction) <= 0.0001f)
    {
        direction.x = 0.0f;
        direction.y = 0.25f;
        direction.z = 1.0f;
        RwV3dNormalize(&direction, &direction);
    }
    eye.x = center.x + direction.x * distance;
    eye.y = center.y + direction.y * distance;
    eye.z = center.z + direction.z * distance;
    btlCameraRangeLookAt(camera, &eye, &center);
    camera->keyFrameIdx = 0;
    camera->keyFrames[0].pos = eye;
    camera->keyFrames[0].rot = camera->rot;
    camera->framesUntilUpdate = 0;
    if (camera->fovRad <= 0.01f)
    {
        camera->fovRad = 0.7853982f;
    }
}

static void btlCameraRangeActionFrame(BtlCamera* camera, f32 margin,
                                      f32 minimum, u32 includeTarget)
{
    BtlUnit* unit;
    BtlUnit* target;
    RwV3d first;
    RwV3d second;

    unit = btlCameraRangeUnit(camera);
    if (unit == NULL)
    {
        return;
    }
    btlUnitGetSphereWorldCenter(unit, (RwV3d*)&first);
    target = includeTarget != 0 ? btlCameraRangeTarget(camera) : NULL;
    if (target != NULL && target != unit)
    {
        btlUnitGetSphereWorldCenter(target, (RwV3d*)&second);
        btlCameraRangeFrame(camera, &first, &second, margin, minimum);
    }
    else
    {
        btlCameraRangeFrame(camera, &first, NULL, margin, minimum);
    }
}


// FUN_002a54f0 NONMATCHING
void btlCameraFrameAction(BtlCamera* camera, u32 closeView, s32 nearScale, s32 farScale)
{
    f32 maxY;
    RwV3d scaled;
    RwV3d forward;
    RwV3d sphereCenter;
    RwV3d rotated;
    RwV3d center;
    RwV3d candidate;
    RwV3d targetCenter;
    RwMatrix rotation;
    RtQuat blendedRot;
    RtQuat quaternion;
    BtlCameraQuatBlend blend;
    BtlCameraKeyFrame frames[2];
    f32 distance;
    f32 fovDistance;
    f32 nearDistance;
    f32 radius;
    f32 half;
    f32 angle;
    f32 nearAngle;
    f32 ratio;
    f32 firstWeight;
    f32 x;
    f32 xSquared;
    f32 r;
    f32 r2;
    BtlUnit* unit;
    BtlAction* targetAction;
    unit = camera->action->unit;
    if (closeView == 0)
    {
        FUN_002a4470((f32*)&frames[0], (f32*)((u8*)camera + 0x9c));
        distance = unit->sphereRadius * unit->scale;
        btlUnitGetSphereWorldCenter(unit, &sphereCenter);
        RtQuatTransformVectors(&forward, &D_00697890, 1, &unit->rot);
        half = 0.5f * distance;
        scaled.x = forward.x * half;
        scaled.y = forward.y * half;
        scaled.z = forward.z * half;
        candidate.x = sphereCenter.x + scaled.x;
        candidate.y = sphereCenter.y + scaled.y;
        candidate.z = sphereCenter.z + scaled.z;
        candidate.y += 0.25f * (unit->unk_8c * unit->scale);
        FUN_00280870(3, 0, 0, &maxY, 0, 1);
        scaled = frames[0].pos;
        if (maxY < scaled.y)
        {
            scaled.y = maxY;
        }
        else
        {
            half = unit->scale * unit->unk_8c;
            if (half > scaled.y)
            {
                scaled.y = half;
            }
        }
        FUN_002a4690(&frames[1].rot, &scaled, &candidate, &D_00697880);
        angle = FUN_002d1f30((f32*)&frames[0].rot, (f32*)&frames[1].rot);
        nearDistance = (f32)nearScale;
        nearDistance = fGpffff80e8 * nearDistance;
        if (angle > nearDistance)
        {
            if (angle <= fGpffff80e8 * (f32)farScale)
            {
                radius = nearDistance / angle;
                FUN_004be310((f32*)&frames[0].rot, (f32*)&frames[1].rot,
                             (f32*)&blend);
                if (radius <= 0.0f)
                {
                    blendedRot = frames[0].rot;
                }
                else if (1.0f <= radius)
                {
                    blendedRot = frames[1].rot;
                }
                else
                {
                    firstWeight = 1.0f - radius;
                    if (blend.flag == 0)
                    {
                        x = firstWeight * blend.scalar;
                        xSquared = x * x;
                        r = fGpffff8048 + fGpffff8130 * xSquared;
                        r = fGpffff8118 + xSquared * r;
                        r = fGpffff8050 + xSquared * r;
                        r = fGpffff8054 + xSquared * r;
                        r2 = fGpffff8058 + xSquared * r;
                        firstWeight = x + xSquared * x * r2;
                        x = radius * blend.scalar;
                        xSquared = x * x;
                        r = fGpffff8048 + fGpffff8130 * xSquared;
                        r = fGpffff8118 + xSquared * r;
                        r = fGpffff8050 + xSquared * r;
                        r = fGpffff8054 + xSquared * r;
                        r2 = fGpffff8058 + xSquared * r;
                        radius = x + xSquared * x * r2;
                    }
                    blendedRot.imag.x = blend.first.imag.x * firstWeight;
                    blendedRot.imag.y = blend.first.imag.y * firstWeight;
                    blendedRot.imag.z = blend.first.imag.z * firstWeight;
                    blendedRot.imag.x = 0.0f + blendedRot.imag.x +
                                        blend.second.imag.x * radius;
                    blendedRot.imag.y = 0.0f + blendedRot.imag.y +
                                        blend.second.imag.y * radius;
                    blendedRot.imag.z = 0.0f + blendedRot.imag.z +
                                        blend.second.imag.z * radius;
                    blendedRot.real = blend.first.real * firstWeight +
                                      blend.second.real * radius;
                }
                RtQuatTransformVectors(&forward, &D_006978A0, 1,
                                        &blendedRot);
                scaled.x = center.x + forward.x;
                scaled.y = center.y + forward.y;
                scaled.z = center.z + forward.z;
                FUN_002a4690(&frames[1].rot, &scaled, &center,
                             &D_00697880);
            }
            else
            {
                goto close_frame;
            }
        }
        forward.x = frames[0].pos.x - candidate.x;
        forward.y = frames[0].pos.y - candidate.y;
        forward.z = frames[0].pos.z - candidate.z;
        radius = RwV3dNormalize(&forward, &forward);
        radius = radius * fGpffff80c4;
        half = 0.5f * camera->fovRad;
        fovDistance = 1.5f * distance / tanf(half);
        if (!(fovDistance <= radius))
        {
            radius = fovDistance;
        }
        if (radius < (f32)0x226)
        {
            radius = (f32)0x226;
        }
        RtQuatTransformVectors(&forward, &D_006978A0, 1, &frames[1].rot);
        scaled.x = forward.x * radius;
        scaled.y = forward.y * radius;
        scaled.z = forward.z * radius;
        frames[1].pos.x = candidate.x + scaled.x;
        frames[1].pos.y = candidate.y + scaled.y;
        frames[1].pos.z = candidate.z + scaled.z;
        if (frames[0].pos.y < 25.0f)
        {
            frames[0].pos.y = 25.0f;
        }
        if (frames[1].pos.y < 25.0f)
        {
            frames[1].pos.y = 25.0f;
        }
        angle = FUN_002d1f30((f32*)&frames[0].rot,
                             (f32*)&frames[1].rot);
        radius = 2.0f;
        if (angle > 0.0f)
        {
            ratio = nearDistance / angle;
            radius = 1.0f;
            if (ratio > radius)
            {
                radius = ratio * radius;
            }
            ratio = 2.0f;
            if (radius <= ratio)
            {
                goto radius_clamped;
            }
            radius = ratio;
        }
    radius_clamped:
        FUN_002a2290((u16*)camera, &frames[0].pos, &frames[1].pos, 1);
        FUN_002a3110((u16*)camera, radius);
        return;
    }

close_frame:
    targetAction = (BtlAction*)FUN_002d6290((int)camera->action);
    btlUnitGetSphereWorldCenter(unit, &candidate);
    candidate.y += 0.25f * (unit->unk_8c * unit->scale);
    if (camera->action->target.targetedCount == 1 &&
        unit == camera->action->target.targetedActions[0]->unit)
    {
        RtQuatTransformVectors(&rotated, &D_00697890, 1, &unit->rot);
    }
    else
    {
        if (targetAction != NULL)
        {
            btlUnitGetSphereWorldCenter(
                (*(BtlAction**)((u8*)camera->action + 0x38))->unit,
                &targetCenter);
        }
        else
        {
            FUN_00280870((s32)FUN_002d1600((int)((u8*)camera->action + 0x38)) & 0xffff,
                         1, &targetCenter, 0, 0, 1);
        }
        FUN_002d1de0(&quaternion, &candidate, &targetCenter);
        RtQuatTransformVectors(&rotated, &D_00697890, 1, &quaternion);
    }
    radius = 4.0f * (unit->sphereRadius * unit->scale);
    half = 2.5f * (unit->sphereRadius * unit->scale);
    switch (datCalcRand(3))
    {
    case 0:
        nearAngle = 30.0f;
        break;
    case 1:
        nearAngle = -30.0f;
        break;
    default:
        nearAngle = 0.0f;
        break;
    }
    switch (datCalcRand(3))
    {
    case 0:
        angle = 15.0f;
        break;
    case 1:
        angle = -15.0f;
        break;
    default:
        angle = 0.0f;
        break;
    }
    RwMatrixRotate(&rotation, &D_00697870, angle, 0);
    RwMatrixRotate(&rotation, &D_00697880, nearAngle, 2);
    FUN_004c6c60(&forward, &rotated, &rotation);
    distance = radius / tanf(fGpffff8070 * (0.5f * camera->fovRad));
    forward.x *= distance;
    forward.y *= distance;
    forward.z *= distance;
    center.x = candidate.x;
    center.y = candidate.y;
    center.z = candidate.z;
    frames[0].pos.x = center.x + forward.x;
    frames[0].pos.y = center.y + forward.y;
    frames[0].pos.z = center.z + forward.z;
    FUN_002a4690(&frames[0].rot, &frames[0].pos, &center,
                 &D_00697880);
    distance = half / tanf(fGpffff8070 * (0.5f * camera->fovRad));
    forward.x = rotated.x * distance;
    forward.y = rotated.y * distance;
    forward.z = rotated.z * distance;
    center.x = candidate.x;
    center.y = candidate.y;
    center.z = candidate.z;
    frames[1].pos.x = center.x + forward.x;
    frames[1].pos.y = center.y + forward.y;
    frames[1].pos.z = center.z + forward.z;
    FUN_002a4690(&frames[1].rot, &frames[1].pos, &center,
                 &D_00697880);
    FUN_002a3e80(0.0f, (u8*)camera->action, NULL, NULL, 1);
    if (frames[0].pos.y < 25.0f)
    {
        frames[0].pos.y = 25.0f;
    }
    if (frames[1].pos.y < 25.0f)
    {
        frames[1].pos.y = 25.0f;
    }
    FUN_002a2290((u16*)camera, &frames[0].pos, &frames[1].pos, 1);
    FUN_002a3110((u16*)camera, 3.0f);
}

// FUN_002a5ee0
void btlCameraFrameActionDefault(BtlCamera* camera)
{
    u32 closeView;

    switch (*(u16 *)(DAT_007ce3ec + 0x104))
    {
    case 0x1d:
        closeView = 1;
        break;
    default:
        closeView = 0;
        break;
    }
    btlCameraFrameAction(camera, closeView, 40, 70);
}

// FUN_002a5f40
void btlCameraFrameActionClose(BtlCamera* camera)
{
    int cameraAddress;
    int actionAddress;
    BtlUnit* unit;
    RwV3d center;

    cameraAddress = (int)camera;
    actionAddress = *(int *)(cameraAddress + 0xe0);
    if (actionAddress != 0 && (*(u16 *)(actionAddress + 0x1a) & 1) != 0)
    {
        unit = *(BtlUnit **)(actionAddress + 0x30);
        FUN_0027ffb0(unit, &center);
        FUN_002a3e80(unit->sphereRadius * unit->scale * 0.25f,
                     (u8 *)(uintptr_t)*(u32 *)(cameraAddress + 0xe0),
                     (u8 *)(uintptr_t)(cameraAddress + 0x9c), (u8 *)&center, 0x31);
    }
}

// FUN_002a5fd0 NONMATCHING
void btlCameraFrameActionPair(BtlCamera* camera)
{
    RwV3d secondPos;
    RwV3d dir;
    RwV3d firstPos;
    RwV3d center1;
    RwV3d center2;
    RtQuat blended;
    BtlCameraQuatBlend blend;
    BtlCameraKeyFrame frames[2];
    f32 hs[4];
    BtlAction* action;
    BtlUnit* unit;
    BtlUnit* unit2;
    f32 len2;
    f32 ratio;
    f32 w1;
    f32 x;
    f32 x2;
    f32 r;
    f32 r2;
    f32 dot;
    f32 angle;

    action = camera->action;
    unit = action->unit;
    unit2 = *(BtlUnit**)(*(int*)((u8*)action + 0x38) + 0x30);
    FUN_002a4470((f32*)&frames[0], (f32*)((u8*)camera + 0x9c));
    btlUnitGetSphereWorldCenter(unit, &center1);
    btlUnitGetSphereWorldCenter(unit2, &center2);
    center1.y = 0.0f + center1.y + fGpffff8094 * (unit->unk_8c * unit->scale);
    if (center1.y < 100.0f)
    {
        center1.y = 100.0f;
    }
    dir.x = frames[0].pos.x - center1.x;
    dir.y = frames[0].pos.y - center1.y;
    dir.z = frames[0].pos.z - center1.z;
    len2 = RwV3dLength(&dir);
    len2 = len2 * fGpffff8060;
    hs[2] = dir.x;
    hs[3] = dir.z;
    FUN_004c6b20(hs + 2, hs + 2);
    center2.y = center1.y;
    dir.x = center2.x - center1.x;
    dir.y = center2.y - center1.y;
    dir.z = center2.z - center1.z;
    RwV3dNormalize(&dir, &dir);
    hs[0] = dir.x;
    hs[1] = dir.z;
    dot = dir.x * hs[2] + dir.z * hs[3];
    if (dot < 0.0f)
    {
        dir.x = -dir.x;
        dir.y = -dir.y;
        dir.z = -dir.z;
    }
    secondPos.x = dir.x * (unit2->sphereRadius * unit2->scale);
    secondPos.y = dir.y * (unit2->sphereRadius * unit2->scale);
    secondPos.z = dir.z * (unit2->sphereRadius * unit2->scale);
    firstPos.x = center1.x + secondPos.x;
    firstPos.y = center1.y + secondPos.y;
    firstPos.z = center1.z + secondPos.z;
    dir.x = dir.x * (5.0f * (unit->sphereRadius * unit->scale));
    dir.y = dir.y * (5.0f * (unit->sphereRadius * unit->scale));
    dir.z = dir.z * (5.0f * (unit->sphereRadius * unit->scale));
    secondPos.x = center1.x + dir.x;
    secondPos.y = center1.y + dir.y;
    secondPos.z = center1.z + dir.z;
    secondPos.y = 0.0f + center2.y + 0.5f * (unit2->unk_8c * unit2->scale);
    dir.x = secondPos.x - center1.x;
    dir.y = secondPos.y - center1.y;
    dir.z = secondPos.z - center1.z;
    RwV3dNormalize(&dir, &dir);
    FUN_002a4690(&frames[1].rot, &secondPos, &firstPos, &D_00697880);
    angle = FUN_002d1f30((f32*)&frames[0].rot, (f32*)&frames[1].rot);
    if (angle > fGpffff8134)
    {
        ratio = fGpffff8134 / angle;
        FUN_004be310((f32*)&frames[0].rot, (f32*)&frames[1].rot, (f32*)&blend);
        if (ratio <= 0.0f)
        {
            blended = frames[0].rot;
        }
        else if (1.0f <= ratio)
        {
            blended = frames[1].rot;
        }
        else
        {
            w1 = 1.0f - ratio;
            if (blend.flag == 0)
            {
                x = w1 * blend.scalar;
                x2 = x * x;
                r = fGpffff8048 + fGpffff8130 * x2;
                r = fGpffff8118 + x2 * r;
                r = fGpffff8050 + x2 * r;
                r = fGpffff8054 + x2 * r;
                r2 = fGpffff8058 + x2 * r;
                w1 = x + x2 * x * r2;
                x = ratio * blend.scalar;
                x2 = x * x;
                r = fGpffff8048 + fGpffff8130 * x2;
                r = fGpffff8118 + x2 * r;
                r = fGpffff8050 + x2 * r;
                r = fGpffff8054 + x2 * r;
                r2 = fGpffff8058 + x2 * r;
                ratio = x + x2 * x * r2;
            }
            blended.imag.x = blend.first.imag.x * w1;
            blended.imag.y = blend.first.imag.y * w1;
            blended.imag.z = blend.first.imag.z * w1;
            blended.imag.x = 0.0f + blended.imag.x + blend.second.imag.x * ratio;
            blended.imag.y = 0.0f + blended.imag.y + blend.second.imag.y * ratio;
            blended.imag.z = 0.0f + blended.imag.z + blend.second.imag.z * ratio;
            blended.real = blend.first.real * w1 + blend.second.real * ratio;
        }
        RtQuatTransformVectors(&dir, &D_006978A0, 1, &blended);
        secondPos.x = firstPos.x + dir.x;
        secondPos.y = firstPos.y + dir.y;
        secondPos.z = firstPos.z + dir.z;
        FUN_002a4690(&frames[1].rot, &secondPos, &firstPos, &D_00697880);
    }
    if (len2 < 600.0f)
    {
        len2 = 600.0f;
    }
    dir.x = dir.x * len2;
    dir.y = dir.y * len2;
    dir.z = dir.z * len2;
    frames[1].pos.x = firstPos.x + dir.x;
    frames[1].pos.y = firstPos.y + dir.y;
    frames[1].pos.z = firstPos.z + dir.z;
    FUN_002a2290((u16*)camera, &frames[0].pos, &frames[1].pos, 1);
    FUN_002a3110((u16*)camera, 1.0f);
}

// FUN_002a6560
void btlCameraFrameActionQuarter(BtlCamera* camera)
{
    int cameraAddress;
    int actionAddress;
    BtlUnit* unit;
    RwV3d center;

    cameraAddress = (int)camera;
    actionAddress = *(int *)(cameraAddress + 0xe0);
    if (actionAddress != 0 && (*(u16 *)(actionAddress + 0x1a) & 1) != 0)
    {
        unit = *(BtlUnit **)(actionAddress + 0x30);
        FUN_0027ffb0(unit, &center);
        FUN_002a3e80(unit->sphereRadius * unit->scale * 0.25f,
                     (u8 *)(uintptr_t)*(u32 *)(cameraAddress + 0xe0),
                     (u8 *)(uintptr_t)(cameraAddress + 0x9c), (u8 *)&center, 0x33);
    }
}

// FUN_002a65f0 NONMATCHING
void btlCameraFrameActionDuel(BtlCamera* camera)
{
    f32 horiz[2];
    RwV3d candidate;
    RwV3d eyeAdj;
    RwV3d direction;
    RwV3d sideDirection;
    RwV3d center;
    RwV3d selectedCenter;
    RwV3d unitPoint;
    RwV3d targetCenter;
    RtQuat blended;
    RtQuat rots[2];
    BtlCameraQuatBlend blend;
    BtlCameraKeyFrame frames[2];
    BtlUnit* unit;
    BtlUnit* target;
    f32 radius;
    f32 sideOffset;
    f32 height;
    f32 angle;
    f32 ratio;
    f32 w1;
    f32 x;
    f32 x2;
    f32 r;
    f32 r2;
    f32 dist;
    f32 selectedRadius;
    f32 dot;
    f32 sideLength;
    unit = camera->action->unit;
    target = camera->action->target.targetedActions[0]->unit;
    FUN_002a4470((f32*)&frames[0], (f32*)((u8*)camera + 0x9c));
    unitPoint.x = unit->unk_dc.x;
    unitPoint.y = unit->sphereCenter.y * unit->scale;
    unitPoint.z = unit->unk_dc.z;
    FUN_0027ffb0(target, &targetCenter);
    {
        f32 targetHeight;
    height = unit->unk_8c * unit->scale;
    height = unitPoint.y + fGpffff8094 * height;
    ratio = target->unk_8c * target->scale;
    targetHeight = targetCenter.y + fGpffff8094 * ratio;
    height = height + targetHeight;
    radius = *(f32*)((u8*)unit + 0xe8);
    radius += unit->sphereRadius * unit->scale;
    radius += target->sphereRadius * target->scale;
    targetCenter.y = 0.0f;
    unitPoint.y = 0.0f;
    direction.x = unit->unk_dc.x - targetCenter.x;
    direction.y = *(f32*)((u8*)unit + 0xe0) - unitPoint.y;
    direction.z = unit->unk_dc.z - targetCenter.z;
    RwV3dNormalize(&direction, &direction);
    targetHeight = 0.25f * radius;
    center.x = direction.x * targetHeight;
    center.y = direction.y * targetHeight;
    center.z = direction.z * targetHeight;
    center.x = targetCenter.x + center.x;
    center.y = targetCenter.y + center.y;
    center.z = targetCenter.z + center.z;
    {
        f32 halfHeight;
    halfHeight = 0.5f * height;
    center.y = halfHeight;
    eyeAdj = frames[0].pos;
    eyeAdj.y = height;
    *(f32*)((int)(uintptr_t)camera + 0x10c) =
        0.5f * *(f32*)((int)(uintptr_t)unit + 0xe8);
    *(RwV3d*)((u8*)camera + 0x100) = center;
    FUN_002a4690(&frames[1].rot, &eyeAdj, &center, &D_00697880);
    height = radius;
    height += unit->sphereRadius * unit->scale;
    height += target->sphereRadius * target->scale;
    angle = FUN_002d1f30((f32*)&frames[0].rot, (f32*)&frames[1].rot);
    if (angle > fGpffff80f0)
    {
        ratio = fGpffff80f0 / angle;
        FUN_004be310((f32*)&frames[0].rot, (f32*)&frames[1].rot, (f32*)&blend);
        if (ratio <= 0.0f)
        {
            blended = frames[0].rot;
        }
        else if (1.0f <= ratio)
        {
            blended = frames[1].rot;
        }
        else
        {
            w1 = 1.0f - ratio;
            if (blend.flag == 0)
            {
                x = w1 * blend.scalar;
                x2 = x * x;
                r = fGpffff8048 + fGpffff8130 * x2;
                r = fGpffff8118 + x2 * r;
                r = fGpffff8050 + x2 * r;
                r = fGpffff8054 + x2 * r;
                r2 = fGpffff8058 + x2 * r;
                w1 = x + x2 * x * r2;
                x = ratio * blend.scalar;
                x2 = x * x;
                r = fGpffff8048 + fGpffff8130 * x2;
                r = fGpffff8118 + x2 * r;
                r = fGpffff8050 + x2 * r;
                r = fGpffff8054 + x2 * r;
                r2 = fGpffff8058 + x2 * r;
                ratio = x + x2 * x * r2;
            }
            blended.imag.x = blend.first.imag.x * w1;
            blended.imag.y = blend.first.imag.y * w1;
            blended.imag.z = blend.first.imag.z * w1;
            blended.imag.x = 0.0f + blended.imag.x + blend.second.imag.x * ratio;
            blended.imag.y = 0.0f + blended.imag.y + blend.second.imag.y * ratio;
            blended.imag.z = 0.0f + blended.imag.z + blend.second.imag.z * ratio;
            blended.real = blend.first.real * w1 + blend.second.real * ratio;
        }
        RtQuatTransformVectors(&eyeAdj, &D_006978A0, 1, &blended);
        eyeAdj.x = eyeAdj.x + center.x;
        eyeAdj.y = eyeAdj.y + center.y;
        eyeAdj.z = eyeAdj.z + center.z;
        FUN_002a4690(&frames[1].rot, &eyeAdj, &center, &D_00697880);
    }
    else if (angle < fGpffff80f4)
    {
        FUN_004bdde0((f32*)&frames[1].rot, (const f32*)&D_00697880, fGpffff80f8, 2);
    }
    if (height < 675.0f)
    {
        height = 675.0f;
    }
    dist = (1.5f * (0.5f * height)) /
           FUN_0052e930(fGpffff8070 * (0.5f * camera->fovRad));
    RtQuatTransformVectors(&eyeAdj, &D_006978A0, 1, &frames[1].rot);
    direction.y = eyeAdj.y;
    RwV3dNormalize(&direction, &direction);
    angle = eyeAdj.x * direction.x +
            eyeAdj.y * direction.y +
            eyeAdj.z * direction.z;
    if (angle >= 0.0f)
    {
        selectedRadius = unit->sphereRadius * unit->scale;
        selectedCenter = unitPoint;
    }
    else
    {
        selectedRadius = target->sphereRadius * target->scale;
        selectedCenter = targetCenter;
    }
    candidate.x = targetCenter.x + direction.z * selectedRadius;
    candidate.y = center.y;
    candidate.z = targetCenter.z - direction.x * selectedRadius;
    sideDirection.x = candidate.x - center.x;
    sideDirection.y = candidate.y - center.y;
    sideDirection.z = candidate.z - center.z;
    RwV3dNormalize(&sideDirection, &sideDirection);
    dot = 0.0f +
          sideDirection.x * direction.x +
          sideDirection.y * direction.y +
          sideDirection.z * direction.z;
    if (fabsf(angle) > fabsf(dot) &&
        dot != 0.0f && angle != 0.0f)
    {
        horiz[0] = center.x - selectedCenter.x;
        horiz[1] = center.z - selectedCenter.z;
        sideLength = RwV2dLength((RwV2d*)horiz);
        candidate.y = center.y + halfHeight * sideLength / dist;
        candidate.x = selectedCenter.x + direction.z * selectedRadius;
        candidate.z = selectedCenter.z - direction.x * selectedRadius;
        FUN_002a4690(&rots[0], &candidate, &center, &D_00697880);
        angle = FUN_002d1f30((f32*)&frames[0].rot, (f32*)&rots[0]);
        candidate.x = selectedCenter.x - direction.z * selectedRadius;
        candidate.z = selectedCenter.z + direction.x * selectedRadius;
        FUN_002a4690(&rots[1], &candidate, &center, &D_00697880);
        ratio = FUN_002d1f30((f32*)&frames[0].rot, (f32*)&rots[1]);
        if (angle < ratio)
        {
            frames[1].rot = rots[0];
        }
        else
        {
            frames[1].rot = rots[1];
        }
        RtQuatTransformVectors(&eyeAdj, &D_006978A0, 1, &frames[1].rot);
    }
    eyeAdj.x = eyeAdj.x * dist;
    eyeAdj.y = eyeAdj.y * dist;
    eyeAdj.z = eyeAdj.z * dist;
    sideOffset = dist * FUN_0052e930(fGpffff8070 * (0.5f * camera->fovRad));
    sideOffset = sideOffset * 0.21875f;
    horiz[0] = eyeAdj.x;
    horiz[1] = eyeAdj.z;
    FUN_004c6b20(horiz, horiz);
    center.x = 0.0f + center.x + horiz[1] * sideOffset;
    center.z = 0.0f + center.z - horiz[0] * sideOffset;
    frames[1].pos.x = center.x + eyeAdj.x;
    frames[1].pos.y = center.y + eyeAdj.y;
    frames[1].pos.z = center.z + eyeAdj.z;
    FUN_002a3590((f32*)&frames[0].pos, (f32*)&frames[0].pos);
    FUN_002a3590((f32*)&frames[1].pos, (f32*)&frames[1].pos);
    FUN_002a2290((u16*)camera, &frames[0].pos, &frames[1].pos, 1);
    FUN_002a3110((u16*)camera, 2.0f);
    }
    }
}

// FUN_002a6ed0
void FUN_002a6ed0(void)
{
}

// FUN_002a6ee0 NONMATCHING
void btlCameraFrameActionSide(BtlCamera* camera)
{
    RwV3d center1;
    RwV3d center2;
    RwV3d eyeBase;
    RwV3d sideDir;
    RwV3d dir;
    RwV3d pos;
    f32 eyePt[2];
    f32 out[2];
    f32 rayTo[2];
    f32 rayFrom[2];
    f32 hs[4];
    BtlCameraKeyFrame out2;
    BtlAction* action;
    BtlUnit* unit;
    BtlUnit* unit2;
    f32 len;
    f32 two;
    f32 radius1;
    f32 radius2;
    f32 eyeZ;
    f32 eyeY;
    f32 t;
    f32 dot;
    f32 dot2;
    f32 radius;
    f32 f6;
    f32 ret;
    f32 dist;
    f32 f2;

    action = camera->action;
    unit = action->unit;
    unit2 = *(BtlUnit**)(*(int*)((u8*)action + 0x38) + 0x30);
    btlUnitGetSphereWorldCenter(unit, &center1);
    btlUnitGetSphereWorldCenter(unit2, &center2);
    radius1 = unit->sphereRadius * unit->scale;
    radius2 = unit2->sphereRadius * unit2->scale;
    dir.x = center1.x - center2.x;
    dir.y = center1.y - center2.y;
    dir.z = center1.z - center2.z;
    len = RwV3dNormalize(&dir, &dir);
    hs[2] = camera->pos.x - center1.x;
    hs[3] = camera->pos.z - center1.z;
    FUN_004c6b20(hs + 2, hs + 2);
    t = fGpffff8060 * len;
    sideDir.x = dir.x * t;
    sideDir.y = dir.y * t;
    sideDir.z = dir.z * t;
    sideDir.x += center2.x;
    sideDir.y += center2.y;
    sideDir.z += center2.z;
    hs[0] = dir.x;
    hs[1] = dir.z;
    dot = dir.x * hs[2] + dir.z * hs[3];
    if (dot >= 0.0f)
    {
        eyeBase = center1;
        radius = unit->sphereRadius * unit->scale;
        f6 = 2.5f * radius;
        two = 2.25f;
        if (eyeBase.y < 125.0f)
        {
            eyeBase.y = 125.0f;
        }
    }
    else
    {
        unit = unit2;
        eyeBase = center2;
        radius = unit2->sphereRadius * unit2->scale;
        f6 = 2.5f * radius;
        two = 2.25f;
    }
    hs[0] = dir.z;
    hs[1] = -dir.x;
    eyeY = eyeBase.y;
    pos.y = 0.0f + eyeY + fGpffff8030 * (unit->unk_8c * unit->scale);
    dot2 = hs[0] * hs[2] + hs[1] * hs[3];
    if (dot2 >= 0.0f)
    {
        pos.x = eyeBase.x + hs[0] * f6;
        eyeZ = eyeBase.z;
        pos.z = eyeZ - hs[1] * f6;
    }
    else
    {
        pos.x = eyeBase.x - hs[0] * f6;
        eyeZ = eyeBase.z;
        pos.z = eyeZ + hs[1] * f6;
    }
    FUN_002a4690(&out2.rot, &pos, &sideDir, &D_00697880);
    RtQuatTransformVectors(&dir, &D_006978A0, 1, &out2.rot);
    rayFrom[0] = sideDir.x;
    rayFrom[1] = sideDir.z;
    rayTo[0] = pos.x;
    rayTo[1] = pos.z;
    eyePt[0] = eyeBase.x;
    eyePt[1] = eyeZ;
    ret = FUN_002d1fd0(rayFrom,rayTo,eyePt,out);
    dist = 0.0f + ret + two * (unit->sphereRadius * unit->scale);
    pos.x = out[0];
    pos.y = eyeY;
    pos.z = out[1];
    f2 = dist / FUN_0052e930(fGpffff8070 * (0.5f * camera->fovRad));
    if (f2 < 500.0f)
    {
        f2 = 500.0f;
    }
    dir.x = dir.x * f2;
    dir.y = dir.y * f2;
    dir.z = dir.z * f2;
    out2.pos.x = pos.x + dir.x;
    out2.pos.y = pos.y + dir.y;
    out2.pos.z = pos.z + dir.z;
    if (out2.pos.y < 25.0f)
    {
        out2.pos.y = 25.0f;
    }
    FUN_002a44b0((f32*)&camera->pos, (f32*)&out2.pos);
    func_002af960(camera);
    FUN_002a3e80(0.5f * (radius2 + (len + radius1)),
                 (u8*)camera->action,
                 (u8*)&camera->pos,
                 (u8*)camera + 0x100,
                 3);
    if (radius1 <= radius2)
    {
        radius1 = radius2;
    }
    FUN_002a3e80(radius1,
                 *(u8**)((int)camera + 0xe0),
                 (u8*)&center1,
                 (u8*)&center2,
                 3);
}

// FUN_002a7380
void func_002a7380(void)
{
}

// FUN_002a7390 NONMATCHING
void btlCameraFrameActionTarget(BtlCamera* camera)
{
    f32 horiz[2];
    RwV3d eyeAdj;
    RwV3d center;
    RtQuat blended;
    BtlCameraQuatBlend blend;
    BtlCameraKeyFrame frames[2];
    BtlUnit* unit;
    f32 height;
    f32 angle;
    f32 ratio;
    f32 w1;
    f32 x;
    f32 x2;
    f32 r;
    f32 r2;
    f32 dist;
    f32 sideOffset;

    unit = camera->action->unit;
    FUN_002a4470((f32*)&frames[0], (f32*)((u8*)camera + 0x9c));
    FUN_0027f7c0(unit, &center, 0, 0);
    height = unit->sphereCenter.y * unit->scale;
    height += fGpffff8094 * (unit->unk_8c * unit->scale);
    center.y = height;
    eyeAdj = frames[0].pos;
    eyeAdj.y = height;
    FUN_002a4690(&frames[1].rot, &eyeAdj, &center, &D_00697880);
    angle = FUN_002d1f30((f32*)&frames[0].rot, (f32*)&frames[1].rot);
    if (angle > fGpffff80f0)
    {
        ratio = fGpffff80f0 / angle;
        FUN_004be310((f32*)&frames[0].rot, (f32*)&frames[1].rot, (f32*)&blend);
        if (ratio <= 0.0f)
        {
            blended = frames[0].rot;
        }
        else if (1.0f <= ratio)
        {
            blended = frames[1].rot;
        }
        else
        {
            w1 = 1.0f - ratio;
            if (blend.flag == 0)
            {
                x = w1 * blend.scalar;
                x2 = x * x;
                r = fGpffff8048 + fGpffff8130 * x2;
                r = fGpffff8118 + x2 * r;
                r = fGpffff8050 + x2 * r;
                r = fGpffff8054 + x2 * r;
                r2 = fGpffff8058 + x2 * r;
                w1 = x + x2 * x * r2;
                x = ratio * blend.scalar;
                x2 = x * x;
                r = fGpffff8048 + fGpffff8130 * x2;
                r = fGpffff8118 + x2 * r;
                r = fGpffff8050 + x2 * r;
                r = fGpffff8054 + x2 * r;
                r2 = fGpffff8058 + x2 * r;
                ratio = x + x2 * x * r2;
            }
            blended.imag.x = blend.first.imag.x * w1;
            blended.imag.y = blend.first.imag.y * w1;
            blended.imag.z = blend.first.imag.z * w1;
            blended.imag.x = 0.0f + blended.imag.x + blend.second.imag.x * ratio;
            blended.imag.y = 0.0f + blended.imag.y + blend.second.imag.y * ratio;
            blended.imag.z = 0.0f + blended.imag.z + blend.second.imag.z * ratio;
            blended.real = blend.first.real * w1 + blend.second.real * ratio;
        }
        RtQuatTransformVectors(&eyeAdj, &D_006978A0, 1, &blended);
        eyeAdj.x = eyeAdj.x + center.x;
        eyeAdj.y = eyeAdj.y + center.y;
        eyeAdj.z = eyeAdj.z + center.z;
        FUN_002a4690(&frames[1].rot, &eyeAdj, &center, &D_00697880);
    }
    else if (angle < fGpffff80f4)
    {
        FUN_004bdde0((f32*)&frames[1].rot, (const f32*)&D_00697880, fGpffff80f8, 2);
    }
    RtQuatTransformVectors(&eyeAdj, &D_006978A0, 1, &frames[1].rot);
    dist = 375 / FUN_0052e930(fGpffff8070 * (0.5f * camera->fovRad));
    eyeAdj.x = eyeAdj.x * dist;
    eyeAdj.y = eyeAdj.y * dist;
    eyeAdj.z = eyeAdj.z * dist;
    sideOffset = dist * FUN_0052e930(fGpffff8070 * (0.5f * camera->fovRad));
    sideOffset = sideOffset * 0.21875f;
    horiz[0] = eyeAdj.x;
    horiz[1] = eyeAdj.z;
    FUN_004c6b20(horiz, horiz);
    center.x = 0.0f + center.x + horiz[1] * sideOffset;
    center.z = 0.0f + center.z - horiz[0] * sideOffset;
    frames[1].pos.x = center.x + eyeAdj.x;
    frames[1].pos.y = center.y + eyeAdj.y;
    frames[1].pos.z = center.z + eyeAdj.z;
    if (frames[1].pos.y < 25.0f)
    {
        frames[1].pos.y = 25.0f;
    }
    FUN_002a2290((u16*)camera, &frames[0].pos, &frames[1].pos, 1);
    FUN_002a3110((u16*)camera, fGpffff8138);
}

// FUN_002a7820
void func_002a7820(void)
{
}

// FUN_002a7830
u32 btlCameraSelectMode(BtlCamera* camera)
{
    s16 commandId;
    u16 targetMask;

    commandId = *(s16 *)((u8 *)camera->action + 0x6e);
    if (FUN_002d6290((int)camera->action) != 0)
    {
        if (*(BtlAction **)((u8 *)camera->action + 0x38) == camera->action)
        {
            return 1;
        }
        if (FUN_002a32f0((int)camera) != 0)
        {
            return 2;
        }
        if (FUN_002d6370(commandId) == 0)
        {
            return 2;
        }
        if (camera->action->unit->genus == 0 &&
            FUN_002d63b0((int)camera->action->unit->personaUnit,
                        commandId, 1) == 0)
        {
            return 2;
        }
        return 4;
    }

    targetMask = FUN_002d1600((int)((u8 *)camera->action + 0x38));
    if ((targetMask & 3) == 3)
    {
        return 6;
    }
    if (camera->action->unit->genus == 0 && (targetMask & 1) != 0)
    {
        if (FUN_002d62d0((int)camera->action) != 0)
        {
            return 6;
        }
        if (*(BtlAction **)((u8 *)camera->action + 0x38) == camera->action)
        {
            return 1;
        }
        if (FUN_002d6370(commandId) != 0)
        {
            return 4;
        }
        return 2;
    }
    if (FUN_002d6370(commandId) == 0)
    {
        return 3;
    }
    return 5;
}

typedef struct BtlCameraTargetingWork
{
    BtlCameraKeyFrame first;
    RwV3d secondPos;
    RtQuat secondRot;
    u8 pad_38[8];
    RwMatrix matrix;
    u8 pad_7c[4];
    u8 pad_80[8];
    RwV3d targetPos;
    f32 horiz[2];
    RwV3d candidate;
    u8 pad_9c[4];
    RwV3d sidePoint;
    u8 pad_ac[4];
    RwV3d diff;
    u8 pad_bc[4];
    RwV3d direction;
    u8 pad_cc[4];
    RwV3d desired;
    u8 pad_dc[4];
    RwV3d generated;
    u8 pad_ec[4];
    RwV3d sphereCenter;
    f32 radius;
} BtlCameraTargetingWork;


extern u64 FUN_004c6c60(RwV3d* out, RwV3d* in, RwMatrix* matrix);
// FUN_002a79f0 NONMATCHING
void btlCameraFrameActionTargeting(BtlCamera* camera)
{
    BtlCameraTargetingWork work;
    BtlUnit* unit;
    BtlUnit* persona;
    f32 range;
    f32 distance;
    f32 half;
    f32 fovScale;
    f32 scale;
    f32 sideOffset;
    f32 tanHalf;

    FUN_002a4470((f32*)&work.first.pos, (f32*)&camera->pos);
    unit = camera->action->unit;
    btlUnitGetSphereWorldCenter(unit, &work.sphereCenter);
    range = FUN_00280870(3, 1, &work.generated.x, &work.radius, 0, 0);
    if (FUN_002a3420((int)camera) != 0 || FUN_002a3380((u8*)camera) != 0)
    {
        persona = unit->personaUnit;
        if (persona != NULL)
        {
            btlUnit002880e0(persona, 0);
            *(BtlUnit**)((u8*)camera + 0x120) = unit->personaUnit;
            *(u16*)((u8*)camera + 0x124) = 1;
        }
        work.generated.y = 0.75f * work.radius;
        work.sphereCenter.y = work.generated.y;
        half = 0.5f;
        fovScale = fGpffff8070;

        distance = range / tanf(fovScale * (half * camera->fovRad));
        if (distance < 1000.0f)
        {
            distance = 1000.0f;
        }

        if (work.generated.x == work.sphereCenter.x &&
            work.generated.z == work.sphereCenter.z)
        {
            *(s64*)&work.direction = *(volatile s64 *)(uintptr_t)0x00697890;
            work.direction.z = *(volatile f32 *)(uintptr_t)0x00697898;
        }
        else
        {
            work.direction.x = work.generated.x - work.sphereCenter.x;
            work.direction.y = work.generated.y - work.sphereCenter.y;
            work.direction.z = work.generated.z - work.sphereCenter.z;
            RwV3dNormalize(&work.direction, &work.direction);
        }

        work.direction.x = work.direction.x * range;
        work.direction.y = work.direction.y * range;
        work.direction.z = work.direction.z * range;
        work.desired.x = work.generated.x + work.direction.x;
        work.desired.y = work.generated.y + work.direction.y;
        work.desired.z = work.generated.z + work.direction.z;
        work.desired.y = 1.25f * work.radius;
    }
    else
    {
        persona = unit->personaUnit;
        if (persona != NULL)
        {
            btlUnit002880e0(persona, 0);
            *(BtlUnit**)((u8*)camera + 0x120) = unit->personaUnit;
            *(u16*)((u8*)camera + 0x124) = 1;
        }
        work.generated.y = 0.75f * work.radius;
        work.sphereCenter.y = work.generated.y;
        half = 0.5f;
        fovScale = fGpffff8070;

        distance = range / tanf(fovScale * (half * camera->fovRad));
        if (distance < 1200.0f)
        {
            distance = 1200.0f;
        }

        if (work.generated.x == work.sphereCenter.x &&
            work.generated.z == work.sphereCenter.z)
        {
            *(s64*)&work.direction = *(volatile s64 *)(uintptr_t)0x00697890;
            work.direction.z = *(volatile f32 *)(uintptr_t)0x00697898;
        }
        else
        {
            work.direction.x = work.generated.x - work.sphereCenter.x;
            work.direction.y = work.generated.y - work.sphereCenter.y;
            work.direction.z = work.generated.z - work.sphereCenter.z;
            RwV3dNormalize(&work.direction, &work.direction);
        }

        work.direction.x = work.direction.x * range;
        work.direction.y = work.direction.y * range;
        work.direction.z = work.direction.z * range;
        work.desired.x = work.generated.x + work.direction.x;
        work.desired.y = work.generated.y + work.direction.y;
        work.desired.z = work.generated.z + work.direction.z;
        work.desired.y = fGpffff80c0 * work.radius;
        if (work.desired.y > 200.0f)
        {
            work.desired.y = 200.0f;
        }

        work.candidate.x = work.desired.x;
        work.candidate.y = work.generated.y;
        work.candidate.z = work.desired.z;
        work.diff.x = work.candidate.x - work.generated.x;
        work.diff.y = work.generated.y - work.generated.y;
        work.diff.z = work.candidate.z - work.generated.z;
        scale = fGpffff8098 * RwV3dNormalize(&work.diff, &work.diff);
        work.sidePoint.x = work.diff.x * scale;
        work.sidePoint.y = work.diff.y * scale;
        work.sidePoint.z = work.diff.z * scale;
        work.sidePoint.x = work.sidePoint.x + work.generated.x;
        work.sidePoint.y = work.sidePoint.y + work.generated.y;
        work.sidePoint.z = work.sidePoint.z + work.generated.z;
    }
    *(s64*)&work.targetPos = *(s64*)&work.desired;
    work.targetPos.z = work.desired.z;
    work.targetPos.y = work.generated.y;
    work.diff.x = work.targetPos.x - work.generated.x;
    work.diff.y = work.targetPos.y - work.generated.y;
    work.diff.z = work.targetPos.z - work.generated.z;
    scale = fGpffff8098 * RwV3dNormalize(&work.diff, &work.diff);
    work.sidePoint.x = work.diff.x * scale;
    work.sidePoint.y = work.diff.y * scale;
    work.sidePoint.z = work.diff.z * scale;
    work.sidePoint.x = work.sidePoint.x + work.generated.x;
    work.sidePoint.y = work.sidePoint.y + work.generated.y;
    work.sidePoint.z = work.sidePoint.z + work.generated.z;

    FUN_002a4690(&work.secondRot, &work.desired, &work.sidePoint, &D_00697880);
    work.direction.x = work.desired.x - work.sidePoint.x;
    work.direction.y = work.desired.y - work.sidePoint.y;
    work.direction.z = work.desired.z - work.sidePoint.z;
    RwV3dNormalize(&work.direction, &work.direction);
    tanHalf = tanf(fovScale * (half * camera->fovRad));
    sideOffset = distance * tanHalf;
    sideOffset = sideOffset * 0.21875f;
    work.horiz[0] = work.direction.x;
    work.horiz[1] = work.direction.z;
    FUN_004c6b20(work.horiz, work.horiz);
    work.sidePoint.x = 0.0f + work.sidePoint.x +
                       work.horiz[1] * sideOffset;
    work.sidePoint.z = 0.0f + work.sidePoint.z -
                       work.horiz[0] * sideOffset;

    work.diff.x = work.direction.x * distance;
    work.diff.y = work.direction.y * distance;
    work.diff.z = work.direction.z * distance;
    work.secondPos.x = work.sidePoint.x + work.diff.x;
    work.secondPos.y = work.sidePoint.y + work.diff.y;
    work.secondPos.z = work.sidePoint.z + work.diff.z;

    if (effMiscRand(0) & 1)
    {
        RwMatrixRotate(&work.matrix, &D_00697880, -30.0f, rwCOMBINEREPLACE);
    }
    else
    {
        RwMatrixRotate(&work.matrix, &D_00697880, 30.0f, rwCOMBINEREPLACE);
    }
    FUN_004c6c60((RwV3d*)&work.diff, (RwV3d*)&work.direction, &work.matrix);
    work.diff.x = work.diff.x * distance;
    work.diff.y = work.diff.y * distance;
    work.diff.z = work.diff.z * distance;
    work.first.pos.x = work.sidePoint.x + work.diff.x;
    work.first.pos.y = work.sidePoint.y + work.diff.y;
    work.first.pos.z = work.sidePoint.z + work.diff.z;
    FUN_002a4690(&work.first.rot, &work.first.pos, &work.sidePoint, &D_00697880);
    FUN_00351bb0(0xC);
    FUN_002a3590((f32*)&work.first.pos, (f32*)&work.first.pos);
    FUN_002a3590((f32*)&work.secondPos, (f32*)&work.secondPos);
    if (work.first.pos.y < 25.0f)
    {
        work.first.pos.y = 25.0f;
    }
    if (work.secondPos.y < 25.0f)
    {
        work.secondPos.y = 25.0f;
    }
    FUN_002a2290((u16*)camera, &work.first.pos, &work.secondPos, 1);
    FUN_002a3110((u16*)camera, 10.0f);
}

// FUN_002a8150 NONMATCHING
void btlCameraFrameActionPersona(BtlCamera* camera, u32 suppressEffects,
                                 u32 useCurrentTarget)
{
    BtlUnit* unit;
    BtlUnit* persona;
    struct
    {
        f32 buf[48];
        RwV3d base;
        f32 basePad;
        RwV3d transformed;
        f32 transformedPad;
        RwV3d direction;
        f32 directionPad;
        RwV3d candidate;
        f32 candidatePad;
        RwV3d center2;
        f32 center2Pad;
        RwV3d center1;
        f32 center1Pad;
        RwV3d midpoint;
    } work;
#define buf work.buf
#define PERSONA_BASE work.base
#define PERSONA_TRANSFORMED work.transformed
#define PERSONA_DIRECTION work.direction
#define PERSONA_CANDIDATE work.candidate
#define PERSONA_CENTER2 work.center2
#define PERSONA_CENTER1 work.center1
#define PERSONA_MIDPOINT work.midpoint
    f32 f25;
    f32 f24;
    f32 f22;
    f32 f26;
    f32 f23;
    f32 f20;
    f32 f27;
    f32 f20b;
    f32 f22b;
    f32 f23b;
    f32 f26b;
    f32 f1;
    f32 f0;
    s32 mode;
    if (FUN_002a3520_s32() != 0)
        goto mode_true;
    if ((int)FUN_002a3550_s32((u8*)camera) == 0)
        goto mode_false;
mode_true:
    mode = 1;
    goto mode_done;
mode_false:
    mode = 0;
mode_done:
    unit = camera->action->unit;
    persona = unit->personaUnit;
    btlUnitGetSphereWorldCenter(unit, &PERSONA_CENTER1);
    btlUnitGetSphereWorldCenter(persona, &PERSONA_CENTER2);
    f25 = PERSONA_CENTER1.y + 0.5f * (unit->unk_8c * unit->scale);
    f24 = PERSONA_CENTER2.y + 0.5f * (persona->unk_8c * persona->scale);
    f22 = unit->sphereRadius * unit->scale;
    f26 = persona->sphereRadius * persona->scale;
    if (mode != 0 ||
        ((*(u16*)(iGpffffb73c +
                  ((*(u16*)((u8*)persona + 0xa4)) * 0x58)) & 1) == 0))
    {
        if (mode == 0)
        {
            btlUnit002880e0(persona, 0);
            PERSONA_MIDPOINT.x = PERSONA_CENTER1.x + PERSONA_CENTER2.x;
            PERSONA_MIDPOINT.y = PERSONA_CENTER1.y + PERSONA_CENTER2.y;
            PERSONA_MIDPOINT.z = PERSONA_CENTER1.z + PERSONA_CENTER2.z;
            PERSONA_MIDPOINT.x = PERSONA_MIDPOINT.x * 0.5f;
            PERSONA_MIDPOINT.y = PERSONA_MIDPOINT.y * 0.5f;
            PERSONA_MIDPOINT.z = PERSONA_MIDPOINT.z * 0.5f;
            PERSONA_DIRECTION.x = PERSONA_CENTER1.x - PERSONA_MIDPOINT.x;
            PERSONA_DIRECTION.y = PERSONA_CENTER1.y - PERSONA_MIDPOINT.y;
            PERSONA_DIRECTION.z = PERSONA_CENTER1.z - PERSONA_MIDPOINT.z;
            f23 = RwV3dLength(&PERSONA_DIRECTION) + f22;
            PERSONA_CANDIDATE = PERSONA_CENTER1;
            PERSONA_CANDIDATE.y = f25;
            PERSONA_DIRECTION.x = PERSONA_CANDIDATE.x - PERSONA_MIDPOINT.x;
            PERSONA_DIRECTION.y = PERSONA_CANDIDATE.y - PERSONA_MIDPOINT.y;
            PERSONA_DIRECTION.z = PERSONA_CANDIDATE.z - PERSONA_MIDPOINT.z;
            f0 = RwV3dLength(&PERSONA_DIRECTION);
            if (f23 <= f0) f23 = f0;
            PERSONA_DIRECTION.x = PERSONA_CENTER2.x - PERSONA_MIDPOINT.x;
            PERSONA_DIRECTION.y = PERSONA_CENTER2.y - PERSONA_MIDPOINT.y;
            PERSONA_DIRECTION.z = PERSONA_CENTER2.z - PERSONA_MIDPOINT.z;
            f20 = RwV3dLength(&PERSONA_DIRECTION) + f26;
            PERSONA_CANDIDATE = PERSONA_CENTER2;
            PERSONA_CANDIDATE.y = f24;
            PERSONA_DIRECTION.x = PERSONA_CANDIDATE.x - PERSONA_MIDPOINT.x;
            PERSONA_DIRECTION.y = PERSONA_CANDIDATE.y - PERSONA_MIDPOINT.y;
            PERSONA_DIRECTION.z = PERSONA_CANDIDATE.z - PERSONA_MIDPOINT.z;
            f0 = RwV3dLength(&PERSONA_DIRECTION);
            if (f20 > f0) f20 = f0;
            *(u64*)(buf + 48) = *(u64*)(buf + 72);
            PERSONA_BASE.z = PERSONA_MIDPOINT.z;
            if (f23 <= f20) f23 = f20;
            f27 = f23 * 1.75f;
        }
        else
        {
            *(u64*)(buf + 44) = *(u64*)(buf + 68);
            buf[46] = PERSONA_CENTER1.z;
            *(u64*)(buf + 72) = *(u64*)(buf + 68);
            PERSONA_MIDPOINT.z = PERSONA_CENTER1.z;
            *(u64*)(buf + 48) = *(u64*)(buf + 68);
            PERSONA_BASE.z = PERSONA_CENTER1.z;
            f24 = 1.0f + f25;
            f27 = 5.5f * f22;
        }
        buf[34] = camera->pos.x - PERSONA_BASE.x;
        buf[35] = camera->pos.z - PERSONA_BASE.z;
        FUN_004c6b20(&buf[34], &buf[34]);
        RtQuatTransformVectors((RwV3d*)(buf + 52), &D_00697890, 1, &unit->rot);
        buf[32] = PERSONA_TRANSFORMED.z;
        buf[33] = -PERSONA_TRANSFORMED.x;
        FUN_004c6b20(&buf[32], &buf[32]);
        f22b = buf[32] * buf[34] + buf[33] * buf[35];
        RwMatrixRotate((RwMatrix*)(buf + 16), &D_00697880,
                       f22b < 0.0f ? -37.5f : 37.5f, rwCOMBINEREPLACE);
        FUN_004c6c60((RwV3d*)(buf + 56), (RwV3d*)(buf + 52),
                     (RwMatrix*)(buf + 16));
        PERSONA_DIRECTION.x *= f27;
        PERSONA_DIRECTION.y *= f27;
        PERSONA_DIRECTION.z *= f27;
        PERSONA_CANDIDATE.x = PERSONA_MIDPOINT.x + PERSONA_DIRECTION.x;
        PERSONA_CANDIDATE.y = PERSONA_MIDPOINT.y + PERSONA_DIRECTION.y;
        PERSONA_CANDIDATE.z = PERSONA_MIDPOINT.z + PERSONA_DIRECTION.z;
        if (f25 < f24) PERSONA_CANDIDATE.y = fGpffff807c * f24;
        PERSONA_DIRECTION.x = PERSONA_CANDIDATE.x - PERSONA_BASE.x;
        PERSONA_DIRECTION.y = PERSONA_CANDIDATE.y - PERSONA_BASE.y;
        PERSONA_DIRECTION.z = PERSONA_CANDIDATE.z - PERSONA_BASE.z;
        RwV3dNormalize((RwV3d*)(buf + 56), (RwV3d*)(buf + 56));
        FUN_002a4690((void*)(buf + 10), (void*)(buf + 60),
                     (void*)(buf + 48), &D_00697880);
        f26b = f27 / FUN_0052e930(fGpffff8070 * (0.5f * camera->fovRad));
        FUN_0052e930(fGpffff8070 * (0.5f * camera->fovRad));
        buf[46] = PERSONA_DIRECTION.x;
        buf[47] = PERSONA_DIRECTION.z;
        FUN_004c6b20(&buf[46], &buf[46]);
        f23b = f26b * FUN_0052e930(fGpffff8070 * (0.5f * camera->fovRad));
        f23b = f23b * 0.21875f;
        PERSONA_BASE.x = PERSONA_BASE.z + buf[47] * f23b;
        PERSONA_BASE.z = PERSONA_BASE.z - buf[46] * f23b;
        PERSONA_DIRECTION.x *= f26b;
        PERSONA_CANDIDATE.x = PERSONA_BASE.x + PERSONA_DIRECTION.x;
        PERSONA_CANDIDATE.y = PERSONA_BASE.y + PERSONA_DIRECTION.y;
        PERSONA_CANDIDATE.z = PERSONA_BASE.z + PERSONA_DIRECTION.z;
        RwMatrixRotate((RwMatrix*)(buf + 16), &D_00697880,
                       f22b < 0.0f ? -70.0f : 70.0f, rwCOMBINEREPLACE);
        FUN_004c6c60((RwV3d*)(buf + 56), (RwV3d*)(buf + 52),
                     (RwMatrix*)(buf + 16));
        PERSONA_DIRECTION.x *= f27;
        PERSONA_DIRECTION.y *= f27;
        PERSONA_DIRECTION.z *= f27;
        PERSONA_CANDIDATE.x = PERSONA_MIDPOINT.x + PERSONA_DIRECTION.x;
        PERSONA_CANDIDATE.y = PERSONA_MIDPOINT.y + PERSONA_DIRECTION.y;
        PERSONA_CANDIDATE.z = PERSONA_MIDPOINT.z + PERSONA_DIRECTION.z;
        if (f25 < f24) PERSONA_CANDIDATE.y = fGpffff807c * f24;
        PERSONA_DIRECTION.x = PERSONA_CANDIDATE.x - PERSONA_BASE.x;
        PERSONA_DIRECTION.y = PERSONA_CANDIDATE.y - PERSONA_BASE.y;
        PERSONA_DIRECTION.z = PERSONA_CANDIDATE.z - PERSONA_BASE.z;
        RwV3dNormalize((RwV3d*)(buf + 56), (RwV3d*)(buf + 56));
        *(u64*)(buf + 48) = *(u64*)(buf + 72);
        PERSONA_BASE.z = PERSONA_MIDPOINT.z;
        FUN_002a4690((void*)(buf + 3), (void*)(buf + 60),
                     (void*)(buf + 48), &D_00697880);
        FUN_0052e930(fGpffff8070 * (0.5f * camera->fovRad));
        buf[46] = PERSONA_DIRECTION.x;
        buf[47] = PERSONA_DIRECTION.z;
        FUN_004c6b20(&buf[46], &buf[46]);
        f23b = f20 * FUN_0052e930(fGpffff8070 * (0.5f * camera->fovRad));
        f23b = f23b * 0.21875f;
        PERSONA_BASE.x = PERSONA_BASE.z + buf[47] * f23b;
        PERSONA_BASE.z = PERSONA_BASE.z - buf[46] * f23b;
        PERSONA_DIRECTION.x *= f26b;
        PERSONA_CANDIDATE.x = PERSONA_BASE.x + PERSONA_DIRECTION.x;
        PERSONA_CANDIDATE.y = PERSONA_BASE.y + PERSONA_DIRECTION.y;
        PERSONA_CANDIDATE.z = PERSONA_BASE.z + PERSONA_DIRECTION.z;
    }
    else
    {
        btlUnit002880e0(persona, 1);
        *(u64*)(buf + 40) = *(u64*)(buf + 64);
        buf[42] = PERSONA_CENTER2.z;
        *(u64*)(buf + 48) = *(u64*)(buf + 64);
        PERSONA_BASE.z = PERSONA_CENTER2.z;
        PERSONA_BASE.y = 0.25f * f24;
        PERSONA_BASE.x = *(f32*)(buf + 64);
        PERSONA_BASE.z = PERSONA_CENTER2.z;
        PERSONA_BASE.y = fGpffff8080 * f24;
        RtQuatTransformVectors((RwV3d*)(buf + 52), &D_00697890, 1, &unit->rot);
        PERSONA_DIRECTION.x = PERSONA_TRANSFORMED.x * f26;
        PERSONA_DIRECTION.y = PERSONA_TRANSFORMED.y * f26;
        PERSONA_DIRECTION.z = PERSONA_TRANSFORMED.z * f26;
        PERSONA_CANDIDATE.x = PERSONA_BASE.x + PERSONA_DIRECTION.x;
        PERSONA_CANDIDATE.y = PERSONA_BASE.y + PERSONA_DIRECTION.y;
        PERSONA_CANDIDATE.z = PERSONA_BASE.z + PERSONA_DIRECTION.z;
        PERSONA_CANDIDATE.y = fGpffff8084 * PERSONA_BASE.y;
        PERSONA_DIRECTION.x = PERSONA_CANDIDATE.x - PERSONA_BASE.x;
        PERSONA_DIRECTION.y = PERSONA_CANDIDATE.y - PERSONA_BASE.y;
        PERSONA_DIRECTION.z = PERSONA_CANDIDATE.z - PERSONA_BASE.z;
        RwV3dNormalize((RwV3d*)(buf + 56), (RwV3d*)(buf + 56));
        FUN_002a4690((void*)(buf + 10), (void*)(buf + 60),
                     (void*)(buf + 48), &D_00697880);
        f20b = 0.5f * f24;
        if (f26 > f20b)
            f20 = (1.25f * f26) /
                  FUN_0052e930(fGpffff8070 * (0.5f * camera->fovRad));
        else
            f20 = (1.25f * f20b) /
                  FUN_0052e930(0.5f * camera->fovRad);
        if (f20 - f26 < 375.0f) f20 = 375.0f + f26;
        PERSONA_CANDIDATE.x = PERSONA_DIRECTION.x * f20;
        PERSONA_CANDIDATE.y = PERSONA_DIRECTION.y * f20;
        PERSONA_CANDIDATE.z = PERSONA_DIRECTION.z * f20;
        buf[7] = PERSONA_BASE.x + PERSONA_CANDIDATE.x;
        buf[8] = PERSONA_BASE.y + PERSONA_CANDIDATE.y;
        buf[9] = PERSONA_BASE.z + PERSONA_CANDIDATE.z;
        *(u64*)(buf + 48) = *(u64*)(buf + 68);
        PERSONA_BASE.z = PERSONA_CENTER1.z;
        PERSONA_BASE.y = f25;
        PERSONA_DIRECTION.x = PERSONA_TRANSFORMED.x * f26;
        PERSONA_DIRECTION.y = PERSONA_TRANSFORMED.y * f26;
        PERSONA_DIRECTION.z = PERSONA_TRANSFORMED.z * f26;
        PERSONA_CANDIDATE.x = PERSONA_BASE.x + PERSONA_DIRECTION.x;
        PERSONA_CANDIDATE.y = PERSONA_BASE.y + PERSONA_DIRECTION.y;
        PERSONA_CANDIDATE.z = PERSONA_BASE.z + PERSONA_DIRECTION.z;
        FUN_002a4690((void*)(buf + 3), (void*)(buf + 60),
                     (void*)(buf + 48), &D_00697880);
        f1 = fGpffff8088 * f20;
        PERSONA_DIRECTION.x = PERSONA_TRANSFORMED.x * f1;
        PERSONA_DIRECTION.y = PERSONA_TRANSFORMED.y * f1;
        PERSONA_DIRECTION.z = PERSONA_TRANSFORMED.z * f1;
        buf[4] = PERSONA_BASE.x + PERSONA_DIRECTION.x;
        buf[5] = PERSONA_BASE.y + PERSONA_DIRECTION.y;
        buf[6] = PERSONA_BASE.z + PERSONA_DIRECTION.z;
    }
    if (buf[5] < 25.0f) buf[5] = 25.0f;
    if (buf[8] < 25.0f) buf[8] = 25.0f;
    if (useCurrentTarget == 0)
    {
        buf[4] = buf[7];
        buf[5] = buf[8];
        buf[6] = buf[9];
        buf[3] = buf[11];
        buf[10] = buf[12];
        buf[11] = buf[13];
        buf[12] = buf[14];
    }
    FUN_002a3e80(0.0f, (u8*)camera->action, 0, 0, 1);
    FUN_002a2290((u16*)camera, (RwV3d*)(buf + 4), (RwV3d*)(buf + 7), 1);
    FUN_002a3110((u16*)camera, 2.5f);
    if (suppressEffects != 0) FUN_00351bb0(0xc);
#undef buf
#undef PERSONA_DIRECTION
#undef PERSONA_CANDIDATE
#undef PERSONA_CENTER2
#undef PERSONA_CENTER1
#undef PERSONA_MIDPOINT

}

// FUN_002a8d20
void btlCameraFrameActionAll(BtlCamera* camera, u32 suppressEffects)
{
    RwV3d midpoint;
    RwV3d center1;
    RwV3d center2;
    RwV3d candidate;
    RwV3d direction;
    RwV3d transformed;
    RwV3d base;
    RwV3d aux;
    f32 work[14];
    BtlUnit* unit;
    BtlUnit* persona;
    f32 radius1;
    f32 radius2;
    f32 height1;
    f32 height2;
    f32 distance1;
    f32 distance2;
    f32 halfHeight;
    f32 scale;
    f32 f;

    unit = camera->action->unit;
    persona = unit->personaUnit;
    btlUnitGetSphereWorldCenter(unit, &center1);
    btlUnitGetSphereWorldCenter(persona, &center2);
    height1 = unit->unk_8c * unit->scale;
    height1 = center1.y + 0.5f * height1;
    height2 = persona->unk_8c * persona->scale;
    height2 = center2.y + 0.5f * height2;
    radius1 = unit->sphereRadius * unit->scale;
    radius2 = persona->sphereRadius * persona->scale;
    if ((*(u16*)(iGpffffb73c + (persona->charId * 0x58)) & 1) == 0)
    {
        btlUnit002880e0(persona, 0);
        midpoint.x = center1.x + center2.x;
        midpoint.y = center1.y + center2.y;
        midpoint.z = center1.z + center2.z;
        midpoint.x = midpoint.x * 0.5f;
        midpoint.y = midpoint.y * 0.5f;
        midpoint.z = midpoint.z * 0.5f;
        direction.x = center1.x - midpoint.x;
        direction.y = center1.y - midpoint.y;
        direction.z = center1.z - midpoint.z;
        f = RwV3dLength(&direction);
        distance1 = f + radius1;
        candidate = center1;
        candidate.y = height1;
        direction.x = candidate.x - midpoint.x;
        direction.y = candidate.y - midpoint.y;
        direction.z = candidate.z - midpoint.z;
        f = RwV3dLength(&direction);
        distance1 = (distance1 > f) ? distance1 : f;
        direction.x = center2.x - midpoint.x;
        direction.y = center2.y - midpoint.y;
        direction.z = center2.z - midpoint.z;
        f = RwV3dLength(&direction);
        distance2 = f + radius2;
        candidate = center2;
        candidate.y = height2;
        direction.x = candidate.x - midpoint.x;
        direction.y = candidate.y - midpoint.y;
        direction.z = candidate.z - midpoint.z;
        f = RwV3dLength(&direction);
        distance2 = (distance2 > f) ? distance2 : f;
        base = midpoint;
        if (height1 < height2) halfHeight = fGpffff8084 * height2;
        else halfHeight = fGpffff8084 * height1;
        base.y = halfHeight;
        distance1 = (distance1 > distance2) ? distance1 : distance2;
        scale = distance1 * fGpffff811c;
        RtQuatTransformVectors(&transformed, &D_00697890, 1, &unit->rot);
        direction.x = transformed.x * scale;
        direction.y = transformed.y * scale;
        direction.z = transformed.z * scale;
        candidate.x = direction.x + midpoint.x;
        candidate.y = direction.y + midpoint.y;
        candidate.z = direction.z + midpoint.z;
        if (height1 < height2) halfHeight = 0.5f * height2;
        else halfHeight = 0.5f * height1;
        candidate.y = halfHeight;
        direction.x = candidate.x - base.x;
        direction.y = candidate.y - base.y;
        direction.z = candidate.z - base.z;
        RwV3dNormalize(&direction, &direction);
        FUN_002a4690((RtQuat*)(work + 10), &candidate, &base, &D_00697880);
        radius1 = scale / FUN_0052e930(fGpffff8070 * (0.5f * camera->fovRad));
        candidate.x = direction.x * radius1;
        candidate.y = direction.y * radius1;
        candidate.z = direction.z * radius1;
        work[7] = base.x + candidate.x;
        work[8] = base.y + candidate.y;
        work[9] = base.z + candidate.z;
        base = center1;
        f = 0.75f * height1;
        base.y = f;
        direction.x = transformed.x * radius2;
        direction.y = transformed.y * radius2;
        direction.z = transformed.z * radius2;
        candidate.x = direction.x + base.x;
        candidate.y = direction.y + base.y;
        candidate.z = direction.z + base.z;
        FUN_002a4690((RtQuat*)(work + 3), &candidate, &base, &D_00697880);
        f = 0.75f * radius1;
        candidate.x = transformed.x * f;
        candidate.y = transformed.y * f;
        candidate.z = transformed.z * f;
        work[0] = base.x + candidate.x;
        work[1] = base.y + candidate.y;
        work[2] = base.z + candidate.z;
    }
    else
    {
        btlUnit002880e0(persona, 1);
        aux = center2;
        midpoint = center2;
        midpoint.y = fGpffff8088 * height2;
        base = center2;
        base.y = fGpffff8064 * height2;
        RtQuatTransformVectors(&transformed, &D_00697890, 1, &unit->rot);
        direction.x = transformed.x * radius2;
        direction.y = transformed.y * radius2;
        direction.z = transformed.z * radius2;
        candidate.x = direction.x + midpoint.x;
        candidate.y = direction.y + midpoint.y;
        candidate.z = direction.z + midpoint.z;
        candidate.y = fGpffff8084 * midpoint.y;
        direction.x = candidate.x - base.x;
        direction.y = candidate.y - base.y;
        direction.z = candidate.z - base.z;
        RwV3dNormalize(&direction, &direction);
        FUN_002a4690((RtQuat*)(work + 10), &candidate, &base, &D_00697880);
        halfHeight = 0.5f * height2;
        if (radius2 > halfHeight)
            radius1 = (1.25f * radius2) /
                      FUN_0052e930(fGpffff8070 * (0.5f * camera->fovRad));
        else
            radius1 = (1.25f * halfHeight) /
                      FUN_0052e930(0.5f * camera->fovRad);
        if (radius1 - radius2 < 350.0f) radius1 = 350.0f + radius2;
        candidate.x = direction.x * radius1;
        candidate.y = direction.y * radius1;
        candidate.z = direction.z * radius1;
        work[7] = base.x + candidate.x;
        work[8] = base.y + candidate.y;
        work[9] = base.z + candidate.z;
        base = center1;
        base.y = height1;
        direction.x = transformed.x * radius2;
        direction.y = transformed.y * radius2;
        direction.z = transformed.z * radius2;
        candidate.x = direction.x + base.x;
        candidate.y = direction.y + base.y;
        candidate.z = direction.z + base.z;
        FUN_002a4690((RtQuat*)(work + 3), &candidate, &base, &D_00697880);
        f = fGpffff80c4 * radius1;
        candidate.x = transformed.x * f;
        candidate.y = transformed.y * f;
        candidate.z = transformed.z * f;
        work[0] = base.x + candidate.x;
        work[1] = base.y + candidate.y;
        work[2] = base.z + candidate.z;
    }
    if (work[1] < 25.0f) work[1] = 25.0f;
    if (work[8] < 25.0f) work[8] = 25.0f;
    FUN_002a3e80(0.0f, (u8*)camera->action, 0, 0, 1);
    FUN_002a2290((u16*)camera, (RwV3d*)work, (RwV3d*)(work + 7), 1);
    FUN_002a3110((u16*)camera, 2.0f);
    if (suppressEffects != 0) FUN_00351bb0(0xc);
}

// FUN_002a95d0 NONMATCHING
void btlCameraFrameActionResult(BtlCamera* camera, u32 suppressEffects,
                                u32 useCurrentTarget)
{
    struct
    {
        f32 b0;
        f32 b4;
        f32 b8;
        RtQuat quat;
        f32 cc;
        f32 d0;
        f32 d4;
        RtQuat quatCopy;
        f32 f0;
        f32 f4;
        f32 f8;
        f32 fc;
        f32 f100;
        f32 f104;
        f32 f108;
        f32 f10c;
        f32 f110;
        f32 f114;
        f32 f118;
        f32 f11c;
        f32 f120;
        f32 f124;
        f32 f128;
        f32 f12c;
        union
        {
            s64 pair;
            struct
            {
                f32 x;
                f32 y;
            } xy;
        } pair130;
        f32 f138;
        f32 f140;
        f32 f144;
        f32 f148;
        f32 f150;
        f32 f154;
        f32 f158;
        f32 f160;
        f32 f164;
        f32 f168;
        union
        {
            s64 pair;
            struct
            {
                f32 x;
                f32 y;
            } xy;
        } pair170;
        f32 f178;
        f32 centerPad2[3];
        RwV3d personaCenter;
        f32 centerPad0;
        RwV3d targetCenter;
        f32 centerPad1;
        RwV3d unitCenter;
    } l;
    BtlUnit* unit;
    BtlUnit* persona;
    BtlUnit* target;
    f32 unitHeight;
    f32 personaHeight;
    f32 targetHeight;
    f32 unitRadius;
    f32 personaRadius;
    f32 targetRadius;
    f32 distance;
    f32 cameraDistance;
    f32 projection;
    f32 cross;
    f32 side;
    f32 modeScale;
    u32 personaResult;
    u32 special;
    u32 mode;

    unit = camera->action->unit;
    target = camera->action->target.targetedActions[0]->unit;
    persona = unit->personaUnit;
    personaResult = FUN_002fdbb0_result(camera->action, persona) != 0;
    special = FUN_002a3520_result((int)camera) != 0;
    if (special == 0 && FUN_002a3550((u8*)camera) != 0)
    {
        special = 1;
    }

    btlUnitGetSphereWorldCenter(unit, &l.unitCenter);
    btlUnitGetSphereWorldCenter(persona, &l.personaCenter);
    unitHeight = l.unitCenter.y + 0.5f * (unit->unk_8c * unit->scale);
    personaHeight = l.personaCenter.y +
                    0.5f * (persona->unk_8c * persona->scale);
    if (personaResult == 0 && unitHeight < personaHeight && special == 0)
    {
        l.unitCenter.y = 0.25f * (unitHeight + personaHeight);
        unitHeight = personaHeight;
    }

    unitRadius = unit->sphereRadius * unit->scale;
    personaRadius = persona->sphereRadius * persona->scale;
    if (personaResult == 0 && unitRadius < personaRadius && special == 0)
    {
        unitRadius = personaRadius;
    }
    if (unitRadius < 50.0f)
    {
        unitRadius = 50.0f;
    }

    btlUnitGetSphereWorldCenter(target, &l.targetCenter);
    targetHeight = l.targetCenter.y +
                   0.5f * (target->unk_8c * target->scale);
    if (targetHeight > 450.0f)
    {
        l.targetCenter.y =
            l.targetCenter.y - 0.5f * (target->unk_8c * target->scale);
        targetHeight = 450.0f;
    }
    targetRadius = target->sphereRadius * target->scale;

    mode = FUN_002a3420((int)camera);
    modeScale = 1.0f;
    if (special != 0 || mode != 0)
    {
        btlUnit002880e0(persona, 1);
        *(BtlUnit**)((u8*)camera + 0x120) = persona;
        *(u16*)((u8*)camera + 0x124) = 0;
        modeScale = 3.0f;
    }
    else
    {
        btlUnit002880e0(persona, 0);
        *(BtlUnit**)((u8*)camera + 0x120) = persona;
        *(u16*)((u8*)camera + 0x124) = 1;
        if ((*(u16*)(iGpffffb73c + (persona->charId * 0x58)) & 1) != 0)
        {
            if (personaHeight < 750.0f)
            {
                l.personaCenter.y = fGpffff8060 * personaHeight;
            }
            else
            {
                l.personaCenter.y = fGpffff8090 * personaHeight;
            }
            l.targetCenter.y = fGpffff8094 * targetHeight;
            modeScale = 1.5f;
        }
    }

    l.f150 = l.unitCenter.x - l.targetCenter.x;
    l.f154 = l.unitCenter.y - l.targetCenter.y;
    l.f158 = l.unitCenter.z - l.targetCenter.z;
    distance = RwV3dNormalize((RwV3d*)&l.f150, (RwV3d*)&l.f150);
    side = fGpffff8098 * distance;
    l.f160 = l.f150 * side + l.targetCenter.x;
    l.f164 = l.f154 * side + l.targetCenter.y;
    l.f168 = l.f158 * side + l.targetCenter.z;
    l.f8 = camera->pos.x - l.f160;
    l.fc = camera->pos.z - l.f168;
    FUN_004c6b20(&l.f8, &l.f8);

    if (personaResult != 0 ||
        ((effMiscRand(0) & 1) != 0 && FUN_002a3380((u8*)camera) != 0))
    {
        btlUnit002880e0(persona, 1);
        *(BtlUnit**)((u8*)camera + 0x120) = persona;
        *(u16*)((u8*)camera + 0x124) = 0;

        l.pair170.pair = *(s64*)&l.unitCenter;
        l.f178 = l.unitCenter.z;
        l.f0 = l.f158;
        l.f4 = -l.f150;
        cross = (l.f4 * l.fc) + (l.f0 * l.f8);
        if (unitHeight < targetHeight)
        {
            l.f144 = l.pair170.xy.y + fGpffff8030 * unitHeight;
        }
        else
        {
            l.f144 = l.pair170.xy.y - fGpffff8030 * unitHeight;
        }
        side = 2.25f * unitRadius;
        if (!(cross < 0.0f))
        {
            l.f140 = l.pair170.xy.x + l.f0 * side;
            l.f148 = l.f178 - l.f4 * side;
        }
        else
        {
            l.f140 = l.pair170.xy.x - l.f0 * side;
            l.f148 = l.f178 + l.f4 * side;
            side = 0.5f * distance;
            l.f160 = l.f150 * side + l.targetCenter.x;
            l.f164 = l.f154 * side + l.targetCenter.y;
            l.f168 = l.f158 * side + l.targetCenter.z;
        }
        l.f164 = l.f164 + 0.5f * (target->unk_8c * target->scale);

        FUN_002a4690(&l.quat, &l.f140, &l.f160, &D_00697880);
        RtQuatTransformVectors((RwV3d*)&l.f150, &D_006978A0, 1,
                               &l.quat);
        l.f100 = l.f160;
        l.f104 = l.f168;
        l.f108 = l.f140;
        l.f10c = l.f148;
        l.f128 = l.pair170.xy.x;
        l.f12c = l.f178;
        projection = FUN_002d1fd0(&l.f100, &l.f108, &l.f128,
                                  &l.f120);
        l.f140 = l.f120;
        l.f144 = l.pair170.xy.y + 0.5f * unitHeight;
        l.f148 = l.f124;
        cameraDistance = (projection + 1.5f * unitRadius) /
                         tanf(fGpffff8070 * (0.5f * camera->fovRad));
        if (cameraDistance < 226.0f)
        {
            cameraDistance = 226.0f;
        }
        l.f150 *= cameraDistance;
        l.f154 *= cameraDistance;
        l.f158 *= cameraDistance;
        if (cross < 0.0f)
        {
            side = cameraDistance *
                   tanf(fGpffff8070 * (0.5f * camera->fovRad));
            side = side * 0.21875f;
            l.f118 = l.f150;
            l.f11c = l.f158;
            FUN_004c6b20(&l.f118, &l.f118);
            side = side * 1.25f;
            l.f140 = l.f140 + l.f11c * side;
            l.f148 = l.f148 - l.f118 * side;
        }

        l.quatCopy.imag.x = l.quat.imag.x;
        l.quatCopy.imag.y = l.quat.imag.y;
        l.quatCopy.imag.z = l.quat.imag.z;
        l.quatCopy.real = l.quat.real;
        l.cc = l.f140 + l.f150;
        l.d0 = l.f144 + l.f154;
        l.d4 = l.f148 + l.f158;
        if (l.d0 < 25.0f)
        {
            l.d0 = 25.0f;
        }
        l.f144 = l.f144 - fGpffff8094 * unitHeight;
        l.b0 = l.f140 + l.f150;
        l.b4 = l.f144 + l.f154;
        l.b8 = l.f148 + l.f158;
        if (l.b4 < 25.0f)
        {
            l.b4 = 25.0f;
        }
        modeScale = 3.0f;
    }
    else
    {
        if ((*(u16*)(iGpffffb73c + (persona->charId * 0x58)) & 1) == 0)
        {
            btlUnit002880e0(persona, 0);
        }
        else
        {
            btlUnit002880e0(persona, 1);
        }
        *(BtlUnit**)((u8*)camera + 0x120) = persona;
        *(u16*)((u8*)camera + 0x124) = 1;

        l.pair170.pair = *(s64*)&l.targetCenter;
        l.f178 = l.targetCenter.z;
        if (l.pair170.xy.y < 125.0f)
        {
            l.pair170.xy.y = 125.0f;
        }
        l.f0 = l.f158;
        l.f4 = -l.f150;
        cross = (l.f4 * l.fc) + (l.f0 * l.f8);
        side = 1.25f * targetRadius;
        l.f144 = l.pair170.xy.y;
        if (!(cross < 0.0f))
        {
            l.f140 = l.pair170.xy.x + l.f0 * side;
            l.f148 = l.f178 - l.f4 * side;
            l.pair130.pair = *(s64*)&l.f150;
            l.f138 = l.f158;
        }
        else
        {
            l.f140 = l.pair170.xy.x - l.f0 * side;
            l.f148 = l.f178 + l.f4 * side;
        }

        FUN_002a4690(&l.quat, &l.f140, &l.f160, &D_00697880);
        RtQuatTransformVectors((RwV3d*)&l.f150, &D_006978A0, 1,
                               &l.quat);
        l.f100 = l.f160;
        l.f104 = l.f168;
        l.f108 = l.f140;
        l.f10c = l.f148;
        l.f128 = l.pair170.xy.x;
        l.f12c = l.f178;
        FUN_002d1fd0(&l.f100, &l.f108, &l.f128, &l.f120);
        l.f140 = l.f120;
        l.f148 = l.f124;
        cameraDistance = (1.5f * modeScale) /
                         tanf(fGpffff8070 * (0.5f * camera->fovRad));
        if (cameraDistance < 226.0f)
        {
            cameraDistance = 226.0f;
        }
        l.f150 *= cameraDistance;
        l.f154 *= cameraDistance;
        l.f158 *= cameraDistance;
        if (!(cross < 0.0f))
        {
            l.f140 = l.f140 - l.pair130.xy.y * side;
            l.f148 = l.f148 + l.pair130.xy.x * side;
        }

        l.b0 = l.f140 + l.f150;
        l.b4 = l.f144 + l.f154;
        l.b8 = l.f148 + l.f158;
        if (l.b4 < 25.0f)
        {
            l.b4 = 25.0f;
        }
        l.quatCopy.imag.x = l.quat.imag.x;
        l.quatCopy.imag.y = l.quat.imag.y;
        l.quatCopy.imag.z = l.quat.imag.z;
        l.quatCopy.real = l.quat.real;
        l.cc = l.b0;
        l.d0 = l.b4;
        l.d4 = l.b8;

        l.f150 = l.unitCenter.x - l.cc;
        l.f154 = l.unitCenter.y - l.d0;
        l.f158 = l.unitCenter.z - l.d4;
        distance = RwV3dNormalize((RwV3d*)&l.f150,
                                  (RwV3d*)&l.f150);
        l.pair170.pair = *(s64*)&l.unitCenter;
        l.f178 = l.unitCenter.z;
        l.pair170.xy.y = l.pair170.xy.y +
                         0.25f * (unit->unk_8c * unit->scale);
        FUN_002a4690(&l.quat, &l.cc, &l.pair170.xy.x, &D_00697880);
        side = fGpffff8088 * distance;
        l.f150 *= side;
        l.f154 *= side;
        l.f158 *= side;
        l.b0 = l.cc + l.f150;
        l.b4 = l.d0 + l.f154;
        l.b8 = l.d4 + l.f158;
        if (l.b4 < 25.0f)
        {
            l.b4 = 25.0f;
        }
        if (l.d0 < 25.0f)
        {
            l.d0 = 25.0f;
        }
        modeScale = 1.0f;
    }

    if (useCurrentTarget == 0)
    {
        l.b0 = l.cc;
        l.b4 = l.d0;
        l.b8 = l.d4;
        l.quat.imag.x = l.quatCopy.imag.x;
        l.quat.imag.y = l.quatCopy.imag.y;
        l.quat.imag.z = l.quatCopy.imag.z;
        l.quat.real = l.quatCopy.real;
    }
    FUN_002a3e80(50.0f, (u8*)camera->action, (u8*)&target->pos,
                 (u8*)&l.b0, 3);
    FUN_002a2290((u16*)camera, (RwV3d*)&l.b0, (RwV3d*)&l.cc, 1);
    FUN_002a3110((u16*)camera, modeScale);
    if (suppressEffects != 0)
    {
        FUN_00351bb0(12);
    }
}



/* Retail camera recovery for the 0x2b02xx-0x2b8cxx slice.  The bodies below
 * retain the complete branch/data flow recovered from the executable; all
 * entries remain NONMATCHING until instruction scheduling is cleaned up. */
typedef u8 undefined1;
typedef u16 undefined2;
typedef u32 undefined4;
typedef u64 undefined8;
typedef void undefined;

#ifndef CONCAT44
#define CONCAT44(hi, lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif
#ifndef ABS
#define ABS(x) ((x) < 0 ? -(x) : (x))
#endif
extern u64 FUN_0019d400();
extern u32 FUN_0027ec10();
extern u64 FUN_0027f650();
extern u64 FUN_0027f680();
extern u64 FUN_0027f940();
extern u64 FUN_00280050();
extern u64 FUN_00280130();
extern u64 FUN_00280200();
extern u64 FUN_002802d0();
extern u64 FUN_00280390();
extern u64 FUN_00281270();
extern u64 FUN_00281290();
extern u64 FUN_002812b0();
extern s16 FUN_002835e0(BtlUnit* unit, u16 id, f32 scale);
extern s16 FUN_00284040();
extern u64 FUN_00288110();
extern int FUN_00288da0(int param_1, short param_2);
extern u64 FUN_0029a1d0();
extern u64 FUN_002a2170();
extern void FUN_002a2660(BtlCamera* camera, BtlCameraKeyFrame* first,
                         BtlCameraKeyFrame* second, BtlCameraKeyFrame* third,
                         BtlCameraKeyFrame* fourth, int mode);
extern u64 FUN_002add10();
extern u64 FUN_002d1de0();
extern float FUN_002d1f30();
extern u64 FUN_002d2280();
extern u64 FUN_002d4040();
extern u64 FUN_002d4e10();
extern int FUN_002d5bf0();
extern s16 FUN_002f8eb0(BtlUnit* unit, s16 index);
extern u64 FUN_002fa240();
extern u64 FUN_002fdcf0();
extern u32 FUN_002ffbc0();
extern u64 FUN_00300580();
extern u8 FUN_00308c60();
extern u64 FUN_00308a50(u16 param_1);
extern u8 FUN_003093a0();
extern u64 FUN_0030b5a0();
extern u64 FUN_0030c3a0();
extern u64 FUN_004be1e0();
extern u64 FUN_004c31b0();
extern float FUN_004c69f0();
extern float FUN_004c6ac0();
extern float FUN_004c6af0();
extern u64 FUN_004c6c60();
extern u64 FUN_00521250();
extern u64 FUN_00521408();
extern u64 FUN_00523ac8();
extern u32 DAT_007ce404;
extern u8* iGpffffb6fc;
extern void LAB_002b8970(u32 *work);
extern void LAB_002b8b50(u32 *work);
extern u8 DAT_006944b0[];
extern u8 DAT_006945b0[];
extern u8 DAT_006946a4[];
extern u8 DAT_00694798[];
extern u8 DAT_00694890[];
extern u8 DAT_00694990[];
extern u8 DAT_00694a90[];
extern u8 DAT_00694b90[];
extern u8 DAT_00694c90[];
extern u8 DAT_00694d90[];
extern RwV3d D_00694E90;
extern f32 D_00694E9C[3];
extern RwV3d D_00694EA0;
extern RwV3d D_00694EA4;
extern RwV3d D_00694ED0;
extern RwV3d D_00694ED4;
extern RwV3d D_00694ED8;
extern RwV3d D_00694EDC;
extern RwV3d D_00694EE0;
extern RwV3d D_00694EE4;
extern u8 DAT_00694fe8;
extern u8 D_00694F10[];
extern u8 D_00696410[];
extern u8 D_00696430[];
extern u8 DAT_00694fea;
extern u8 DAT_00694fec;
extern u32 DAT_00697880;
extern u32 DAT_00697888;
extern float DAT_007cad20;
extern float DAT_007cad38;
extern float DAT_007cad40;
extern float DAT_007cad44;
extern float DAT_007cad48;
extern float DAT_007cad5c;
extern float DAT_007cad60;
extern float DAT_007cad64;
extern float DAT_007cad68;
extern float DAT_007cad6c;
extern float DAT_007cad74;
extern float DAT_007cad7c;
extern float DAT_007cad84;
extern float DAT_007cad88;
extern float DAT_007cad94;
extern float DAT_007cada4;
extern float DAT_007cadb4;
extern float DAT_007cadc4;
extern float DAT_007cadd0;
extern float DAT_007cadf0;
extern float DAT_007cadf4;
extern float DAT_007cae08;
extern float DAT_007cae20;
extern float DAT_007cae2c;
extern float fGpffff8048;
extern float fGpffff8050;
extern float fGpffff8054;
extern float fGpffff8058;
extern float fGpffff806c;
extern float fGpffff8070;
extern float fGpffff8088;
extern float fGpffff8094;
extern float fGpffff8098;
extern float fGpffff809c;
extern float fGpffff80b4;
extern float fGpffff80c4;
extern float fGpffff80d4;
extern f32 fGpffff80b4;
extern float fGpffff8114;
extern float fGpffff8118;
extern f32 uGpffff808c;
extern f32 uGpffff80fc;
extern f32 uGpffff8100;
extern u32 uGpffff8140;
extern f32 fGpffff80e0;
extern f32 fGpffff813c;
extern u8 D_00694EB0[];
extern u8 D_00694EBC[];
extern u8 D_00694EF0[];
extern u8 D_00694EFC[];
extern u32 FUN_002b64d0(int param_1, int param_2);
extern u32 FUN_002b6bd0(int param_1);
extern void FUN_002b6bf0(undefined4 *param_1, undefined4 param_2, undefined4 param_3, u32 param_4, u16 param_5);
extern u8* FUN_002b6cd0(int param_1);
extern void FUN_002b6de0(unsigned short *param_1);
// FUN_002B0210
void FUN_002b0210(int param_1)
{
  int iVar1;
  
  iVar1 = param_1;
  param_1 = *(int *)(param_1 + 0xe0);
  if ((((param_1 != 0) && (*(u16 *)(param_1 + 0x6a) == 1)) &&
      (*(int *)(iVar1 + 0x118) == *(int *)(param_1 + 0x38))) &&
     ((*(u16 *)(param_1 + 0x1a) & 1) != 0)) {
    FUN_002a3e80(*(float *)(iVar1 + 0x10c), (u8 *)(uintptr_t)param_1,
                 (u8 *)(uintptr_t)(iVar1 + 0x9c),
                 (u8 *)(uintptr_t)(iVar1 + 0x100), 0x33);
  }
  return;
}

// FUN_002b0280 NONMATCHING

void FUN_002b0280(float param_1,undefined8 param_2,long param_3,long param_4)

{
  int iVar1;
  char cVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  undefined4 uStack_78;
  float fStack_74;
  undefined8 uStack_70;
  float fStack_68;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  undefined8 uStack_30;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar4 = (int)param_2;
  iVar6 = *(int *)(*(int *)(iVar4 + 0xe0) + 0x30);
  iVar1 = *(int *)(*(int *)(*(int *)(iVar4 + 0xe0) + 0x38) + 0x30);
  FUN_0027ffb0(iVar6,&fStack_10);
  FUN_0027ffb0(iVar1,&fStack_20);
  fVar7 = *(float *)(iVar1 + 0x8c);
  fVar9 = *(float *)(iVar1 + 0x2c);
  fVar16 = fStack_1c + 0.0;
  if (fStack_1c < 125.0) {
    fStack_1c = 125.0;
  }
  fVar13 = *(float *)(iVar6 + 0x90) * *(float *)(iVar6 + 0x2c);
  fVar11 = *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c);
  fStack_50 = fStack_10 - fStack_20;
  fStack_4c = fStack_c - fStack_1c;
  fStack_48 = fStack_8 - fStack_18;
  fVar10 = (float)FUN_004c69f0(&fStack_50,&fStack_50);
  fVar8 = DAT_007cad88 * fVar10;
  fStack_40 = fStack_50 * fVar8 + fStack_20;
  fStack_3c = fStack_4c * fVar8 + fStack_1c;
  fStack_38 = fStack_48 * fVar8 + fStack_18;
  fStack_98 = *(float *)(iVar4 + 0x9c) - fStack_40;
  fStack_94 = *(float *)(iVar4 + 0xa4) - fStack_38;
  FUN_004c6b20(&fStack_98,&fStack_98);
  fVar8 = fStack_1c;
  fStack_a0 = fStack_50;
  fStack_9c = fStack_48;
  fVar12 = fStack_50 * fStack_98 + fStack_48 * fStack_94;
  if (((fVar12 < 0.0) && (param_4 != 1)) || (param_3 != 0)) {
    fVar10 = fVar10 * 0.5;
    fStack_40 = fStack_50 * fVar10 + fStack_20;
    fStack_3c = fStack_4c * fVar10 + fStack_1c;
    fStack_38 = fStack_48 * fVar10 + fStack_18;
    uStack_30 = CONCAT44(fStack_1c,fStack_20);
    fStack_28 = fStack_18;
    fVar7 = *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c) * 1.25;
    fStack_a0 = fStack_48;
    fStack_9c = -fStack_50;
    fVar9 = fStack_48 * fStack_98 + fStack_9c * fStack_94;
    fStack_5c = fStack_1c;
    if (fStack_1c < fStack_c) {
      fStack_5c = fStack_c;
    }
    if (0.0 <= fVar9) {
      fStack_60 = fStack_48 * fVar7 + fStack_20 + 0.0;
      fStack_58 = (fStack_18 + 0.0) - fStack_50 * fVar7;
      uStack_70 = CONCAT44(fStack_4c,fStack_50);
      fStack_68 = fStack_48;
    }
    else {
      fStack_60 = (fStack_20 + 0.0) - fStack_48 * fVar7;
      fStack_58 = fStack_50 * fVar7 + fStack_18 + 0.0;
    }
    fVar10 = fStack_18;
    FUN_004be1e0(&fStack_50,0x6978a0,1,&uStack_b8);
    fStack_90 = fStack_40;
    fStack_8c = fStack_38;
    fStack_88 = fStack_60;
    fStack_84 = fStack_58;
    uStack_78 = (float)uStack_30;
    fStack_74 = fVar10;
    fVar16 = (float)FUN_002d1fd0((f32*)&fStack_90,(f32*)&fStack_88,(f32*)&uStack_78,(f32*)&fStack_80);
    fVar7 = DAT_007cad60;
    fVar14 = *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c) * 1.5 + fVar16 + 0.0;
    fStack_60 = fStack_80;
    fStack_5c = fVar8;
    fStack_58 = fStack_7c;
    fVar15 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar4 + 0xb8) * 0.5);
    fVar16 = 550.0;
    if (550.0 <= fVar14 / fVar15) {
      fVar16 = fVar14 / fVar15;
    }
    fStack_50 = fStack_50 * fVar16;
    fStack_4c = fStack_4c * fVar16;
    fStack_48 = fStack_48 * fVar16;
    if (0.0 <= fVar9) {
      fVar16 = *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c) * 0.5;
      fStack_60 = (fStack_60 + 0.0) - fStack_68 * fVar16;
      fStack_58 = (float)uStack_70 * fVar16 + fStack_58 + 0.0;
    }
    fStack_c4 = fStack_60 + fStack_50;
    fStack_c0 = fStack_5c + fStack_4c;
    fStack_bc = fStack_58 + fStack_48;
    iVar5 = iVar1;
  }
  else {
    uStack_30 = CONCAT44(fStack_c,fStack_10);
    fStack_28 = fStack_8;
    fVar10 = *(float *)(iVar6 + 0x90) * *(float *)(iVar6 + 0x2c) * 2.5;
    if ((((*(char *)(iVar6 + 0xa2) == '\0') &&
         ((*(short *)(iVar6 + 0xa4) == 3 || (lVar3 = FUN_002d5bf0(iVar6), lVar3 != 0)))) &&
        (cVar2 = FUN_003093a0(*(undefined4 *)(iVar6 + 0xa2c)), cVar2 == '\x02')) &&
       (lVar3 = FUN_002a32f0(param_2), lVar3 == 0)) {
      fVar15 = 85.0;
    }
    else {
      fVar15 = 0.0;
    }
    if (fVar7 * fVar9 * 0.5 + fVar16 <= 400.0) {
      fStack_3c = DAT_007cad7c * *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) +
                  fStack_3c + 0.0;
    }
    else {
      fStack_3c = DAT_007cad5c * *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) +
                  fStack_3c + 0.0;
    }
    fStack_a0 = fStack_48;
    fStack_9c = -fStack_50;
    fVar9 = fStack_48 * fStack_98 + fStack_9c * fStack_94;
    fVar8 = (float)(uStack_30 >> 32);
    fVar15 = fVar15 + (float)(uStack_30 >> 32);
    fStack_5c = *(float *)(iVar6 + 0x8c) * *(float *)(iVar6 + 0x2c) * 0.5 + fVar15 + 0.0;
    if (0.0 <= fVar9) {
      fStack_60 = fStack_48 * fVar10 + (float)uStack_30 + 0.0;
      fStack_58 = (fStack_28 + 0.0) - fStack_50 * fVar10;
    }
    else {
      fStack_60 = ((float)uStack_30 + 0.0) - fStack_48 * fVar10;
      fStack_58 = fStack_50 * fVar10 + fStack_28 + 0.0;
      uStack_70 = CONCAT44(fStack_4c,fStack_50);
      fStack_68 = fStack_48;
    }
    fVar10 = fStack_28;
    FUN_004be1e0(&fStack_50,0x6978a0,1,&uStack_b8);
    fStack_90 = fStack_40;
    fStack_8c = fStack_38;
    fStack_88 = fStack_60;
    fStack_84 = fStack_58;
    uStack_78 = (float)uStack_30;
    fStack_74 = fVar10;
    fVar16 = (float)FUN_002d1fd0((f32*)&fStack_90,(f32*)&fStack_88,(f32*)&uStack_78,(f32*)&fStack_80);
    fVar7 = DAT_007cad60;
    fVar16 = *(float *)(iVar6 + 0x90) * *(float *)(iVar6 + 0x2c) * 2.0 + fVar16 + 0.0;
    fStack_60 = fStack_80;
    fStack_5c = *(float *)(iVar6 + 0x8c) * *(float *)(iVar6 + 0x2c) * 0.25 + fVar15 + 0.0;
    fStack_58 = fStack_7c;
    fVar15 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar4 + 0xb8) * 0.5);
    fVar16 = fVar16 / fVar15;
    fStack_50 = fStack_50 * fVar16;
    fStack_4c = fStack_4c * fVar16;
    fStack_48 = fStack_48 * fVar16;
    if (fVar9 < 0.0) {
      fVar16 = *(float *)(iVar6 + 0x90) * *(float *)(iVar6 + 0x2c) * 2.0;
      fStack_60 = fStack_68 * fVar16 + fStack_60 + 0.0;
      fStack_58 = (fStack_58 + 0.0) - (float)uStack_70 * fVar16;
    }
    fStack_c4 = fStack_60 + fStack_50;
    fStack_c0 = fStack_5c + fStack_4c;
    fStack_bc = fStack_58 + fStack_48;
    iVar5 = iVar6;
    iVar6 = iVar1;
  }
  fVar16 = (float)FUN_002d1f30(&uStack_d4,&uStack_b8);
  if ((param_1 <= 0.0) || (param_1 = DAT_007cadf4 * param_1, param_1 < fVar16)) {
    if (fVar12 < 0.0) {
      FUN_004be1e0(&fStack_50,0x6978a0,1,&uStack_b8);
      fStack_50 = fStack_50 * 200.0;
      fStack_4c = fStack_4c * 200.0;
      fStack_48 = fStack_48 * 200.0;
      fStack_e0 = fStack_c4 + fStack_50;
      fStack_dc = fStack_c0 + fStack_4c;
      fStack_d8 = fStack_bc + fStack_48;
      uStack_d4 = uStack_b8;
      uStack_d0 = uStack_b4;
      uStack_cc = uStack_b0;
      uStack_c8 = uStack_ac;
      if (fStack_dc < 25.0) {
        fStack_dc = 25.0;
      }
      if (fStack_c0 < 25.0) {
        fStack_c0 = 25.0;
      }
    }
    else {
      fVar16 = *(float *)(iVar5 + 0x90) * *(float *)(iVar5 + 0x2c);
      fStack_50 = fStack_10 - fStack_20;
      fStack_4c = fStack_c - fStack_1c;
      fStack_48 = fStack_8 - fStack_18;
      FUN_004c69f0(&fStack_50,&fStack_50);
      fStack_5c = DAT_007cadb4 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) + fVar8 + 0.0;
      if (0.0 <= fVar9) {
        fStack_60 = ((float)uStack_30 + 0.0) - fStack_48 * fVar16;
        fStack_58 = fStack_50 * fVar16 + fVar10 + 0.0;
      }
      else {
        fStack_60 = fStack_48 * fVar16 + (float)uStack_30 + 0.0;
        fStack_58 = (fVar10 + 0.0) - fStack_50 * fVar16;
      }
      FUN_004be1e0(&fStack_50,0x6978a0,1,&uStack_d4);
      fStack_90 = fStack_40;
      fStack_8c = fStack_38;
      fStack_88 = fStack_60;
      fStack_84 = fStack_58;
      uStack_78 = (float)uStack_30;
      fStack_74 = fVar10;
      FUN_002d1fd0((f32*)&fStack_90,(f32*)&fStack_88,(f32*)&uStack_78,(f32*)&fStack_80);
      fStack_60 = fStack_80;
      fStack_5c = DAT_007cadb4 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) + fVar8 + 0.0;
      fStack_58 = fStack_7c;
      fVar7 = (float)FUN_0052e930(fVar7 * *(float *)(iVar4 + 0xb8) * 0.5);
      fVar7 = (*(float *)(iVar5 + 0x90) * *(float *)(iVar5 + 0x2c) * 4.0) / fVar7;
      fStack_50 = fStack_50 * fVar7;
      fStack_4c = fStack_4c * fVar7;
      fStack_48 = fStack_48 * fVar7;
      fStack_e0 = fStack_60 + fStack_50;
      fStack_dc = fStack_5c + fStack_4c;
      fStack_d8 = fStack_58 + fStack_48;
      if (fStack_dc < 25.0) {
        fStack_dc = 25.0;
      }
      if (fStack_c0 < 25.0) {
        fStack_c0 = 25.0;
      }
    }
    if (fVar13 <= fVar11) {
      fVar13 = fVar11;
    }
  }
  else {
    if (fVar13 <= fVar11) {
      fVar13 = fVar11;
    }
    if (fStack_dc < 25.0) {
      fStack_dc = 25.0;
    }
    if (fStack_c0 < 25.0) {
      fStack_c0 = 25.0;
    }
    fVar9 = (float)FUN_002d1f30(&uStack_d4,&uStack_b8);
    fVar7 = 1.25;
    if (0.0 < fVar9) {
      param_1 = param_1 / fVar9;
      fVar7 = DAT_007cad94;
      if (1.0 < param_1) {
        fVar7 = param_1 * DAT_007cad94;
      }
      if (1.25 < fVar7) {
        fVar7 = 1.25;
      }
    }
  }
  return;
}

// FUN_002b1020

void FUN_002b1020(undefined8 param_1)

{
  FUN_002b0280(50.0f,param_1,0,0);
  return;
}

// FUN_002b1050
void btlCameraNoOp(void)
{
}

// FUN_002b1060 NONMATCHING

void FUN_002b1060(BtlCamera* camera, f32 param_1, f32 param_2)
{
    struct
    {
        BtlCameraKeyFrame current;
        RwV3d final;
        RtQuat rotation;
        u8 pad_38[8];
        RwMatrix matrix;
        RtQuat rotationA;
        RtQuat rotationB;
        f32 pair[4];
        u8 pad_b0[8];
        RwV3d center;
        u8 pad_c4[4];
        f32 sourceX;
        f32 sourceHeight;
        f32 sourceZ;
        u8 pad_d4[4];
        s64 selectedXY;
        f32 selectedZ;
        u8 pad_e4[4];
        RwV3d scaled;
        u8 pad_f4[4];
        RwV3d normalized;
        u8 pad_104[4];
        RwV3d difference;
        u8 pad_114[4];
        RwV3d rotated;
        u8 pad_124[4];
        RwV3d candidate;
        u8 pad_134[4];
        f32 pair2[2];
    } work;
    BtlUnit* target;
    BtlUnit* unit;
    f32 range;
    f32 distance;
    f32 factor;
    f32 dot;
    f32 radius;

    unit = camera->action->unit;
    target = camera->action->target.targetedActions[0]->unit;
    FUN_002a4470((f32*)&work.current, (f32*)((u8*)camera + 0x9c));

    work.sourceX = unit->unk_dc.x;
    work.sourceHeight = unit->sphereCenter.y * unit->scale;
    work.sourceZ = unit->unk_dc.z;
    btlUnitGetSphereWorldCenter(target, &work.center);

    factor = work.sourceHeight +
             (unit->unk_8c * unit->scale) * fGpffff8094;
    distance = work.center.y +
               (target->unk_8c * target->scale) * fGpffff8094;
    distance = factor + distance;
    range = *(f32*)((u8*)unit + 0xe8) +
            unit->sphereRadius * unit->scale;
    range = range + target->sphereRadius * target->scale;
    work.center.y = 0.0f;
    work.sourceHeight = 0.0f;

    work.difference.x = unit->unk_dc.x - work.center.x;
    work.difference.y = unit->unk_dc.y - work.center.y;
    work.difference.z = unit->unk_dc.z - work.center.z;
    RwV3dNormalize(&work.difference, &work.difference);
    factor = 0.25f * range;
    work.scaled.x = work.difference.x * factor;
    work.scaled.y = work.difference.y * factor;
    work.scaled.z = work.difference.z * factor;
    work.scaled.x = work.scaled.x + work.center.x;
    work.scaled.y = work.scaled.y + work.center.y;
    work.scaled.z = work.scaled.z + work.center.z;
    work.scaled.y = distance * 0.5f;
    *(RwV3d*)((u8*)camera + 0x100) = work.scaled;
    *(f32*)((u8*)camera + 0x10c) =
        0.5f * *(f32*)((u8*)unit + 0xe8);
    work.rotated.x = work.current.pos.x - work.scaled.x;
    work.rotated.y = work.current.pos.y - work.scaled.y;
    work.rotated.z = work.current.pos.z - work.scaled.z;
    work.pair[0] = work.difference.z;
    work.pair[1] = -work.difference.x;
    work.pair[2] = work.current.pos.x - work.scaled.x;
    work.pair[3] = work.current.pos.z - work.scaled.z;
    FUN_004c6b20(work.pair, work.pair);
    FUN_004c6b20(work.pair + 2, work.pair + 2);
    dot = work.pair[0] * work.pair[2] +
          work.pair[1] * work.pair[3];

    if (dot >= 0.0f)
        RwMatrixRotate(&work.matrix, &D_00697880, param_1, rwCOMBINEREPLACE);
    else
        RwMatrixRotate(&work.matrix, &D_00697880, -param_1, rwCOMBINEREPLACE);
    FUN_004c6c60(&work.rotated, &work.rotated, &work.matrix);
    work.rotated.x = work.rotated.x + work.scaled.x;
    work.rotated.y = work.rotated.y + work.scaled.y;
    work.rotated.z = work.rotated.z + work.scaled.z;
    FUN_002a4690(&work.rotation, &work.rotated, &work.scaled,
                 &D_00697880);

    if (range < 400.0f)
        range = 400.0f;
    factor = (0.5f * range) /
             FUN_0052e930(fGpffff8070 * (0.5f * camera->fovRad));
    FUN_004be1e0_typed(&work.rotated, &D_006978A0, 1, &work.rotation);

    work.difference.y = work.rotated.y;
    RwV3dNormalize(&work.difference, &work.difference);
    dot = work.difference.z * work.rotated.z +
          work.difference.x * work.rotated.x +
          work.difference.y * work.rotated.y;
    distance = dot;
    if (dot >= 0.0f)
    {
        work.selectedXY = *(s64*)&work.sourceX;
        work.selectedZ = work.sourceZ;
        radius = unit->sphereRadius * unit->scale;
    }
    else
    {
        work.selectedXY = *(s64*)&work.center;
        work.selectedZ = work.center.z;
        radius = target->sphereRadius * target->scale;
    }

    work.candidate.x = work.difference.z * radius +
                       ((RwV2d*)&work.selectedXY)->x + 0.0f;
    work.candidate.y = work.scaled.y;
    work.candidate.z = (work.selectedZ + 0.0f) -
                       work.difference.x * radius;
    work.normalized.x = work.candidate.x - work.scaled.x;
    work.normalized.y = work.candidate.y - work.scaled.y;
    work.normalized.z = work.candidate.z - work.scaled.z;
    RwV3dNormalize(&work.normalized, &work.normalized);
    dot = work.normalized.z * work.difference.z +
          work.normalized.x * work.difference.x +
          work.normalized.y * work.difference.y;
    if ((ABS(dot) < ABS(distance)) && dot != 0.0f && distance != 0.0f)
    {
        work.pair2[0] = work.scaled.x -
                        ((RwV2d*)&work.selectedXY)->x;
        work.pair2[1] = work.scaled.z - work.selectedZ;
        work.candidate.y = work.scaled.y +
                           (work.scaled.y * FUN_004c6af0(work.pair2)) /
                           factor;
        work.candidate.x = work.difference.z * radius +
                           ((RwV2d*)&work.selectedXY)->x + 0.0f;
        work.candidate.z = (work.selectedZ + 0.0f) -
                           work.difference.x * radius;
        FUN_002a4690(&work.rotationA, &work.candidate, &work.scaled,
                     &D_00697880);
        radius = FUN_002d1f30_typed((const f32*)&work.current.rot,
                                    (const f32*)&work.rotationA);
        work.candidate.x = ((RwV2d*)&work.selectedXY)->x + 0.0f -
                           work.difference.z * radius;
        work.candidate.z = work.difference.x * radius +
                           work.selectedZ + 0.0f;
        FUN_002a4690(&work.rotationB, &work.candidate, &work.scaled,
                     &D_00697880);
        dot = FUN_002d1f30_typed((const f32*)&work.current.rot,
                                 (const f32*)&work.rotationB);
        if (radius < dot)
            work.rotation = work.rotationA;
        else
            work.rotation = work.rotationB;
        FUN_004be1e0_typed(&work.rotated, &D_006978A0, 1, &work.rotation);
    }

    work.rotated.x = work.rotated.x * factor;
    work.rotated.y = work.rotated.y * factor;
    work.rotated.z = work.rotated.z * factor;
    distance = factor *
               FUN_0052e930(fGpffff8070 * (0.5f * camera->fovRad));
    distance = distance * 0.21875f;
    work.pair2[0] = work.rotated.x;
    work.pair2[1] = work.rotated.z;
    FUN_004c6b20(work.pair2, work.pair2);
    work.scaled.x = work.pair2[1] * distance + work.scaled.x + 0.0f;
    work.scaled.z = (work.scaled.z + 0.0f) -
                    work.pair2[0] * distance;
    work.final.x = work.scaled.x + work.rotated.x;
    work.final.y = work.scaled.y + work.rotated.y;
    work.final.z = work.scaled.z + work.rotated.z;
    FUN_002a2290((u16*)camera, &work.current.pos, &work.final, 1);
    FUN_002a3110((u16*)camera, param_2);
}

// FUN_002b17a0 NONMATCHING

void FUN_002b17a0(BtlCamera* camera, f32 param_1, f32 param_2)
{
    struct
    {
        BtlCameraKeyFrame frames[4];
        RwMatrix matrix;
        f32 pair[4];
        RwV3d center;
        f32 pad_center;
        RwV3d difference;
        f32 pad_difference;
        RwV3d transformed;
        f32 pad_transformed;
        RwV3d scaled;
        f32 pad_scaled;
        RwV3d normalized;
    } work;
    volatile f32 pad[4];
    BtlUnit* unit;
    BtlUnit* target;
    RwV3d* framePos;
    f32 distance;
    f32 dot;
    f32 halfDistance;
    f32 angle;
    f32 half;
    u32 index;
    f32 tempHalf;
    f32 sourceProduct;
    unit = camera->action->unit;
    target = camera->action->target.targetedActions[0]->unit;
    FUN_002a4470((f32*)&work.frames[0], (f32*)((u8*)camera + 0x9c));
    distance = unit->sphereCenter.y * unit->scale;
    btlUnitGetSphereWorldCenter(target, &work.center);

    sourceProduct = unit->unk_8c * unit->scale;
    halfDistance = distance + fGpffff8094 * sourceProduct;
    halfDistance = halfDistance +
                   (work.center.y +
                    fGpffff8094 * (target->unk_8c * target->scale));
    work.center.y = 0.0f;
    work.normalized.x = unit->unk_dc.x - work.center.x;
    work.normalized.y = unit->unk_dc.y - work.center.y;
    work.normalized.z = unit->unk_dc.z - work.center.z;
    distance = RwV3dNormalize(&work.normalized, &work.normalized);
    half = 0.5f;
    work.scaled.x = work.normalized.x * (half * distance);
    work.scaled.y = work.normalized.y * (half * distance);
    work.scaled.z = work.normalized.z * (half * distance);
    work.scaled.x = work.scaled.x + work.center.x;
    work.scaled.y = work.scaled.y + work.center.y;
    work.scaled.z = work.scaled.z + work.center.z;
    tempHalf = half * halfDistance;
    halfDistance = tempHalf;
    work.scaled.y = halfDistance;
    work.pair[0] = work.normalized.z;
    work.pair[1] = -work.normalized.x;
    work.pair[2] = work.frames[0].pos.x - work.scaled.x;
    work.pair[3] = work.frames[0].pos.z - work.scaled.z;
    FUN_004c6b20(work.pair, work.pair);
    FUN_004c6b20(work.pair + 2, work.pair + 2);
    dot = work.pair[0] * work.pair[2] + work.pair[1] * work.pair[3];
    if (dot < 0.0f)
        goto negative_distance;
    distance = distance * fGpffff8094;
    work.scaled.x = work.normalized.x * distance;
    work.scaled.y = work.normalized.y * distance;
    work.scaled.z = work.normalized.z * distance;
    goto distance_done;
negative_distance:
    distance = distance * 0.5f;
    work.scaled.x = work.normalized.x * distance;
    work.scaled.y = work.normalized.y * distance;
    work.scaled.z = work.normalized.z * distance;
distance_done:
    work.scaled.x = work.scaled.x + work.center.x;
    work.scaled.y = work.scaled.y + work.center.y;
    work.scaled.z = work.scaled.z + work.center.z;
    work.scaled.y = halfDistance;
    *(f32*)((u8*)camera + 0x10c) = 0.5f * *(f32*)((u8*)unit + 0xe8);
    *(RwV3d*)((u8*)camera + 0x100) = work.scaled;
    work.difference.x = work.frames[0].pos.x - work.scaled.x;
    work.difference.y = work.frames[0].pos.y - work.scaled.y;
    work.difference.z = work.frames[0].pos.z - work.scaled.z;
    halfDistance = param_1 / 3.0f;
    angle = halfDistance;
    index = 1;
    while ((s32)(index & 0xffff) < 4)
    {
        if (dot < 0.0f)
            goto rotate_negative;
        RwMatrixRotate(&work.matrix, &D_00697880, halfDistance, rwCOMBINEREPLACE);
        goto rotate_done;
rotate_negative:
        RwMatrixRotate(&work.matrix, &D_00697880, -halfDistance, rwCOMBINEREPLACE);
rotate_done:
        FUN_004c6c60(&work.transformed, &work.difference, &work.matrix);
        framePos = &work.frames[(u16)index].pos;
        framePos->x = work.transformed.x + work.scaled.x;
        framePos->y = work.transformed.y + work.scaled.y;
        framePos->z = work.transformed.z + work.scaled.z;
        FUN_002a4690(&work.frames[(u16)index].rot, &work.frames[(u16)index].pos,
                     &work.scaled, &D_00697880);
        halfDistance = halfDistance + angle;
        index = (index + 1) & 0xffff;
    }
    FUN_002a2660(camera, &work.frames[0], &work.frames[1],
                 &work.frames[2], &work.frames[3], 1);
    FUN_002a3110((u16*)camera, param_2);
}

// FUN_002b1bc0

void FUN_002b1bc0(int param_1)
{
  u32 fl;
  u8 *work;

  if (*(u8 *)(*(int *)(*(int *)(param_1 + 0xe0) + 0x30) + 0xa2) == 0) {
    work = iGpffffb6fc;
    fl = *(u32 *)(work + 0xc);
    if ((fl & 0x200000) == 0 || *(u16 *)(*(int *)(work + 0xbbc) + 8) != 0x1b4) {
      *(undefined4 *)(param_1 + 0x11c) = *(undefined4 *)(*(int *)(param_1 + 0xe0) + 0x38);
      work = iGpffffb6fc;
      fl = *(u32 *)(work + 0xc);
      if ((fl & 0x200000) == 0) {
        switch (*(u16 *)(work + 0x10a)) {
        case 0:
          FUN_002b1060((BtlCamera*)param_1, 40.0f, 2.0f);
          break;
        case 1:
          FUN_002b17a0((BtlCamera*)param_1, 100.0f, 3.0f);
          break;
        }
      }
      else {
        switch (*(u16 *)(work + 0x10a)) {
        case 0:
          FUN_002b1060((BtlCamera*)param_1, 20.0f, 2.0f);
          break;
        case 1:
          FUN_002b17a0((BtlCamera*)param_1, 50.0f, 3.0f);
          break;
        }
      }
    }
  }
}


// FUN_002B1CF0
void FUN_002b1cf0(int param_1)
{
  u16 uVar1;
  u16 uVar2;
  int iVar3;

  iVar3 = param_1;
  param_1 = *(int *)(param_1 + 0xe0);
  if (((param_1 != 0) && (*(u16 *)(param_1 + 0x6a) == 1)) &&
     (*(int *)(iVar3 + 0x11c) == *(int *)(param_1 + 0x38))) {
    uVar1 = *(u16 *)(param_1 + 0x1a);
    if ((((uVar1 & 1) != 0) && (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) == 0)) &&
       (((*(u32 *)(iGpffffb6fc + 0xc) & 0x200000) == 0 ||
        (*(u16 *)(*(int *)(iGpffffb6fc + 0xbbc) + 8) != 0x1b4)))) {
      uVar2 = *(u16 *)(iGpffffb6fc + 0x10a);
      if (uVar2 == 1) {
        goto nonzero;
      }
      switch (uVar2) {
      case 0:
        goto zero;
      default:
        goto nonzero;
      }
zero:
      if ((param_1 != 0) && ((uVar1 & 1) != 0)) {
        FUN_002a3e80(*(float *)(iVar3 + 0x10c), (u8 *)(uintptr_t)param_1,
                     (u8 *)(uintptr_t)(iVar3 + 0x9c),
                     (u8 *)(uintptr_t)(iVar3 + 0x100), 0x33);
      }
      goto end;
nonzero:
      if ((param_1 != 0) && ((uVar1 & 1) != 0)) {
        FUN_002a3e80(*(float *)(iVar3 + 0x10c), (u8 *)(uintptr_t)param_1,
                     (u8 *)(uintptr_t)(iVar3 + 0x9c),
                     (u8 *)(uintptr_t)(iVar3 + 0x100), 0x33);
      }
    }
  }
end:
  return;
}

extern u8 DAT_00693d10[];

// FUN_002b1e00

void FUN_002b1e00(int param_1)

{
  int iVar1;
  char cVar2;
  undefined2 uVar3;
  u32 uVar4;
  long lVar5;
  int unaff_s1_lo;
  u8 *pVar;
  
  *(undefined4 *)(param_1 + 0x100) = *(undefined4 *)(*(int *)(param_1 + 0xe0) + 0x38);
  iVar1 = *(int *)(*(int *)(param_1 + 0xe0) + 0x30);
  if (*(u8 *)(iVar1 + 0xa2) == '\0') {
    uVar3 = FUN_002d5bf0(iVar1) ? 3 : *(u16 *)(iVar1 + 0xa4);
    switch(uVar3) {
    case 1:
      uVar4 = FUN_00308c60(*(undefined4 *)(iVar1 + 0xa2c));
      unaff_s1_lo = (int)&DAT_00693d10[(uVar4 & 0xff) * 0xf4];
      break;
    case 2:
      unaff_s1_lo = (u32)(uintptr_t)&DAT_006944b0;
      break;
    case 3:
      switch (FUN_003093a0(*(undefined4 *)(iVar1 + 0xa2c))) {
      case 1:
        unaff_s1_lo = (u32)(uintptr_t)&DAT_006945b0;
        break;
      case 2:
        unaff_s1_lo = (u32)(uintptr_t)&DAT_006946a4;
        break;
      case 3:
        unaff_s1_lo = (u32)(uintptr_t)&DAT_00694798;
        break;
      }
      break;
    case 4:
      unaff_s1_lo = (u32)(uintptr_t)&DAT_00694890;
      break;
    case 5:
      unaff_s1_lo = (u32)(uintptr_t)&DAT_00694990;
      break;
    case 7:
      unaff_s1_lo = (u32)(uintptr_t)&DAT_00694a90;
      break;
    case 8:
      unaff_s1_lo = (u32)(uintptr_t)&DAT_00694b90;
      break;
    case 9:
      unaff_s1_lo = (u32)(uintptr_t)&DAT_00694c90;
      break;
    case 10:
      unaff_s1_lo = (u32)(uintptr_t)&DAT_00694d90;
    }
    FUN_002b6bf0((undefined4*)(uintptr_t)(param_1 + 0xec),*(int *)(param_1 + 0xe0),
                 *(undefined4 *)(*(int *)(param_1 + 0xe0) + 0x38),unaff_s1_lo,3);
    pVar = FUN_002b6cd0(param_1 + 0xec);
    if (pVar != 0) {
      if (*(u16 *)(pVar + 0x1c) == 1) {
        FUN_002a3e80(0.0f,*(u8 **)(param_1 + 0xe0),(u8 *)0,(u8 *)0,1);
        FUN_002a3e80(0.0f,*(u8 **)(param_1 + 0xe0),(u8 *)0,(u8 *)0,8);
        *(undefined4 *)(param_1 + 0x110) = 1;
      }
      else {
        FUN_002a3e80(0.0f,*(u8 **)(param_1 + 0xe0),(u8 *)0,(u8 *)0,0xa);
        *(undefined4 *)(param_1 + 0x110) = 0;
      }
    }
    *(undefined4 *)(param_1 + 0x114) = 0;
  }
  return;
}

// FUN_002b2060 NONMATCHING

void FUN_002b2060(int param_1)

{
  int iVar1;
  u16 uVar2;
  int iVar4;
  u8 *pVar;
  u32 uVarMode;
  int iVar5;
  u8 *pCenter;
  
  iVar4 = (int)param_1;
  iVar1 = *(int *)(iVar4 + 0xe0);
  if ((((iVar1 != 0) && (*(u16 *)(iVar1 + 0x6a) == 1)) && (*(int *)(iVar4 + 0x100) != 0)) &&
     ((*(int *)(iVar4 + 0x100) == *(int *)(iVar1 + 0x38) && ((*(u16 *)(iVar1 + 0x1a) & 1) != 0)))
     ) {
    if (FUN_002b6bd0(iVar4 + 0xec) != 0) {
      FUN_002b64d0(param_1,iVar4 + 0xec);
    }
    pVar = FUN_002b6cd0(iVar4 + 0xec);
    if (pVar != 0) {
      if (*(u16 *)(pVar + 0x1c) == 1) {
        if (*(int *)(iVar4 + 0x114) != 0) {
          FUN_002a3e80(0.0f,(u8*)(uintptr_t)*(undefined4 *)(iVar4 + 0xe0),
                       (u8*)0,(u8*)0,0x81);
        }
        *(undefined4 *)(iVar4 + 0x110) = 1;
      }
      else {
        if (*(int *)(iVar4 + 0x110) == 1) {
          uVar2 = 3;
        }
        else {
          uVar2 = 0x33;
        }
        uVarMode = uVar2;
        if (*(int *)(iVar4 + 0x114) == 0) {
          if (FUN_0030b5a0(*(undefined4 *)(*(int *)(*(int *)(iVar4 + 0x100) + 0x30) + 0xa2c),0) == 0) {
            pCenter = *(u8 **)(*(int *)(iVar4 + 0x100) + 0x30) + 4;
            FUN_002a3e80(50.0f,(u8*)(uintptr_t)*(undefined4 *)(iVar4 + 0xe0),
                         (u8*)(uintptr_t)(iVar4 + 0x9c),pCenter,uVarMode);
          }
        }
        else {
          FUN_002a3e80(0.0f,(u8*)(uintptr_t)*(undefined4 *)(iVar4 + 0xe0),
                       (u8*)0,(u8*)0,uVarMode);
        }
        *(undefined4 *)(iVar4 + 0x110) = 0;
      }
    }
  }
  return;
}

// FUN_002b21f0 NONMATCHING

void FUN_002b21f0(BtlCamera *camera,f32 param_1,int param_2)
{
  int iVar1;
  float fVar2;
  int iVar3;
  undefined8 uVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  undefined1 auStack_d0 [12];
  undefined1 auStack_c4 [16];
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  volatile u8 stackPad[0x80];
  undefined1 auStack_a8 [24];
  BtlCameraKeyFrame frame;
  RwV3d pointA;
  RwV3d pointB;
  RwV3d pointC;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar3 = (int)camera;
  iVar6 = *(int *)(*(int *)(iVar3 + 0xe0) + 0x30);
  iVar1 = *(int *)(*(int *)(*(int *)(iVar3 + 0xe0) + 0x38) + 0x30);
  FUN_00280130_b21f0v2((BtlUnit*)iVar6,&pointA);
  FUN_00280130_b21f0v2((BtlUnit*)iVar1,&pointB);
  fStack_50 = pointA.x - pointB.x;
  fStack_4c = pointA.y - pointB.y;
  fStack_48 = pointA.z - pointB.z;
  fVar7 = FUN_004c69f0_b21f0v2((RwV3d*)&fStack_50,(RwV3d*)&fStack_50);
  fStack_88 = *(float *)(iVar3 + 0x9c) - pointA.x;
  fStack_84 = *(float *)(iVar3 + 0xa4) - pointA.z;
  FUN_004c6b20_b21f0v2((RwV3d*)&fStack_88,(RwV3d*)&fStack_88);
  fStack_90 = fStack_50;
  fStack_8c = fStack_48;
  if (param_2 != 0) {
    if ((*(u32 *)(iGpffffb6fc + 0xc) & 0x200000) == 0) {
      *(u32 *)(iVar3 + 0x104) = (u32)(0.0 <= fStack_50 * fStack_88 + fStack_48 * fStack_84);
    }
    else {
      *(undefined4 *)(iVar3 + 0x104) = 0;
    }
  }
  if (*(int *)(iVar3 + 0x104) == 1) {
    fStack_2c = pointA.y;
    fStack_28 = pointA.z;
    fVar9 = *(float *)(iVar6 + 0x90) * *(float *)(iVar6 + 0x2c) * 1.25;
    fVar7 = fGpffff8098 * fVar7;
    fStack_40 = fStack_50 * fVar7;
    fStack_3c = fStack_4c * fVar7;
    fStack_38 = fStack_48 * fVar7;
    if (pointA.y < 100.0) {
      fStack_2c = 100.0;
    }
    fStack_30 = pointA.x;
    fVar7 = fGpffff809c;
    iVar5 = iVar6;
    iVar6 = iVar1;
  }
  else {
    fStack_30 = pointB.x;
    fStack_2c = pointB.y;
    fStack_28 = pointB.z;
    fVar9 = fGpffff8098 * *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c);
    fVar7 = 2.5;
    pointA.y = (pointA.y + 0.0) - *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) * 0.25;
    if (pointA.y < 100.0) {
      pointA.y = 100.0;
    }
    fStack_50 = pointA.x - pointB.x;
    fStack_4c = pointA.y - pointB.y;
    fStack_48 = pointA.z - pointB.z;
    fStack_38 = FUN_004c69f0_b21f0v2((RwV3d*)&fStack_50,(RwV3d*)&fStack_50);
    fStack_38 = fStack_38 * 0.25;
    fStack_40 = fStack_50 * fStack_38;
    fStack_3c = fStack_4c * fStack_38;
    fStack_38 = fStack_48 * fStack_38;
    iVar5 = iVar1;
  }
  fVar2 = fStack_2c;
  fStack_40 = fStack_40 + pointB.x;
  fStack_3c = fStack_3c + pointB.y;
  fStack_38 = fStack_38 + pointB.z;
  fStack_90 = fStack_48;
  fStack_8c = -fStack_50;
  if (param_2 != 0) {
    *(u32 *)(iVar3 + 0x108) = (u32)(0.0 <= fStack_48 * fStack_88 + fStack_8c * fStack_84);
  }
  if (*(int *)(iVar3 + 0x108) == 1) {
    fStack_60 = fStack_48 * fVar9 + fStack_30 + 0.0;
    fStack_58 = (fStack_28 + 0.0) - fStack_50 * fVar9;
  }
  else {
    fStack_60 = (fStack_30 + 0.0) - fStack_48 * fVar9;
    fStack_58 = fStack_50 * fVar9 + fStack_28 + 0.0;
  }
  fVar9 = fStack_28;
  fStack_80 = fStack_40;
  fStack_7c = fStack_38;
  fStack_78 = fStack_60;
  fStack_74 = fStack_58;
  fStack_68 = fStack_30;
  fStack_64 = fVar9;
  fVar9 = (float)FUN_002d1fd0((f32*)&fStack_80,(f32*)&fStack_78,(f32*)&fStack_68,(f32*)&fStack_70);
  fVar8 = fVar7 * *(float *)(iVar5 + 0x90) * *(float *)(iVar5 + 0x2c) + fVar9 + 0.0;
  fStack_60 = fStack_70;
  fStack_58 = fStack_6c;
  fStack_5c = fVar2;
  FUN_002a4690((void *)auStack_c4,
               (const void *)&fStack_60,
               (const void *)&fStack_40, &D_00697880);
  fVar9 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar3 + 0xb8) * 0.5);
  FUN_004be1e0(&fStack_50,0x6978a0,1,(void *)auStack_c4);
  fVar7 = 500.0;
  if (500.0 <= fVar8 / fVar9) {
    fVar7 = fVar8 / fVar9;
  }
  fStack_50 = fStack_50 * fVar7;
  fStack_4c = fStack_4c * fVar7;
  fStack_48 = fStack_48 * fVar7;
  fStack_b4 = fStack_60 + fStack_50;
  fStack_b0 = fStack_5c + fStack_4c;
  fStack_ac = fStack_58 + fStack_48;
  if (fStack_b0 < 12.5) {
    fStack_b0 = 12.5;
  }
  FUN_002a4470((f32*)&frame,(f32*)((u8*)camera + 0x9c));
  if (param_2 != 0) {
    fVar7 = FUN_002d1f30_b21f0v2(&frame.rot,(RtQuat*)auStack_c4);
    if (fGpffff80d4 < fVar7) {
      FUN_002a44f0((f32*)&frame,(f32*)&fStack_ac);
      uVar4 = 3;
    }
    else {
      uVar4 = 0x23;
    }
    FUN_002a3e80(50.0f,(u8*)camera->action,(u8*)(iVar5 + 4),
                 (u8*)&fStack_ac,(u32)uVar4);
  }
  FUN_002a2290((u16*)camera,(RwV3d*)&frame.pos,(RwV3d*)&fStack_ac,1);
  FUN_002a3110((u16*)camera,param_1);
  return;
}

// FUN_002b2800

void FUN_002b2800(BtlCamera *camera)
{
  s64 lVar1;
  undefined2 uVar2;
  BtlAction *action;
  s16 targetId;

  action = camera->action;
  targetId = *(volatile s16 *)&action->target.specificId;
  lVar1 = FUN_002f8eb0(action->unit, targetId);
  if (lVar1 == -1) {
    lVar1 = 4;
  }
  uVar2 = FUN_002835e0(camera->action->unit, lVar1 & 0xffff, 1.0f);
  *(undefined2 *)((u8 *)camera + 0x10e) = uVar2;
  *(undefined4 *)((u8 *)camera + 0x100) =
      *(undefined4 *)((u8 *)camera->action + 0x38);
  *(undefined2 *)((u8 *)camera + 0x10c) = 0;
  return;
}
// FUN_002b2880
void FUN_002b2880(int param_1)
{
  int iVar1;
  f32 speed;

  iVar1 = *(int *)(param_1 + 0xe0);
  if ((((iVar1 != 0) && (*(u16 *)(iVar1 + 0x6a) == 1)) &&
      (*(int *)(param_1 + 0x100) == *(int *)(iVar1 + 0x38))) && ((*(u16 *)(iVar1 + 0x1a) & 1) != 0)
     ) {
    if (*(u16 *)(param_1 + 0x10e) <= *(u16 *)(param_1 + 0x10c)) {
      speed = (*(int *)(param_1 + 0x108) != 0) ? uGpffff80fc : uGpffff808c;
    }
    else {
      speed = uGpffff8100;
    }
    FUN_002b21f0((BtlCamera*)param_1, speed, *(u16 *)(param_1 + 0x10c) == 0);
    *(short *)(param_1 + 0x10c) = *(u16 *)(param_1 + 0x10c) + 1;
  }
  return;
}

// FUN_002b2940 NONMATCHING

void FUN_002b2940(void *arg0)
{
    struct
    {
        RwV3d output;
        RtQuat transform;
        u8 pad_1c[4];
        f32 fromX;
        f32 fromZ;
        f32 toX;
        f32 toZ;
        f32 eyeX;
        f32 eyeZ;
        f32 normX;
        f32 normZ;
        u8 pad_40[8];
        f32 eye2X;
        f32 eye2Z;
        RwV3d direction;
        u8 pad_bc[4];
        RwV3d center;
        u8 pad_cc[4];
        RwV3d endpoint;
        u8 pad_dc[4];
        RwV3d sourceCenter;
        u8 pad_ec[4];
        RwV3d targetCenter;
        u8 pad_fc[4];
    } scratch;
    u8 genus;
    BtlUnit *target;
    BtlUnit *unit;
    void *action;
    BtlCamera *camera;
    f32 radius;
    f32 distance;

    camera = (BtlCamera*)arg0;
    action = *(void **)((u8*)camera + 0xe0);
    unit = *(BtlUnit**)((u8*)action + 0x30);
    genus = *(u8*)((u8*)unit + 0xa2);
    target = *(BtlUnit**)((u8*)*(void **)((u8*)action + 0x38) + 0x30);
    radius = target->sphereRadius * target->scale;
    btlUnitGetSphereWorldCenter(target, &scratch.targetCenter);
    btlUnitGetSphereWorldCenter(unit, &scratch.sourceCenter);
    if (!(scratch.targetCenter.y <= scratch.sourceCenter.y))
    {
        scratch.targetCenter.y =
            (scratch.targetCenter.y + 0.0f) -
            fGpffff8094 * (target->unk_8c * target->scale);
        scratch.sourceCenter.y =
            (scratch.sourceCenter.y + 0.0f) +
            fGpffff806c * (unit->unk_8c * unit->scale);
    }
    else
    {
        scratch.targetCenter.y =
            (scratch.targetCenter.y + 0.0f) +
            fGpffff8094 * (target->unk_8c * target->scale);
        scratch.sourceCenter.y =
            (scratch.sourceCenter.y + 0.0f) -
            fGpffff8094 * (unit->unk_8c * unit->scale);
    }
    if (scratch.targetCenter.y < 65.0f)
    {
        scratch.targetCenter.y = 65.0f;
    }

    scratch.direction.x = scratch.sourceCenter.x - scratch.targetCenter.x;
    scratch.direction.y = scratch.sourceCenter.y - scratch.targetCenter.y;
    scratch.direction.z = scratch.sourceCenter.z - scratch.targetCenter.z;
    scratch.direction.x = scratch.direction.x * fGpffff8088;
    scratch.direction.y = scratch.direction.y * fGpffff8088;
    scratch.direction.z = scratch.direction.z * fGpffff8088;
    scratch.center.x = scratch.targetCenter.x + scratch.direction.x;
    scratch.center.y = scratch.targetCenter.y + scratch.direction.y;
    scratch.center.z = scratch.targetCenter.z + scratch.direction.z;

    scratch.normX = scratch.targetCenter.x - camera->pos.x;
    scratch.normZ = scratch.targetCenter.z - camera->pos.z;
    scratch.fromX = scratch.normX;
    scratch.fromZ = scratch.normZ;
    FUN_004c6b20(&scratch.fromX, &scratch.fromX);
    FUN_004be1e0(&scratch.direction, 0x697870, 1,
                 (u8*)target + 0x1c);
    scratch.eyeX = scratch.direction.x;
    scratch.eyeZ = scratch.direction.z;
    FUN_004c6b20(&scratch.eyeX, &scratch.eyeX);

    if (genus == 0)
    {
        scratch.direction.x = scratch.direction.x * (radius * 0.5f);
        scratch.direction.y = scratch.direction.y * (radius * 0.5f);
        scratch.direction.z = scratch.direction.z * (radius * 0.5f);
        scratch.endpoint.x = scratch.targetCenter.x - scratch.direction.x;
        scratch.endpoint.y = scratch.targetCenter.y - scratch.direction.y;
        scratch.endpoint.z = scratch.targetCenter.z - scratch.direction.z;
    }
    else
    {
        scratch.direction.x = scratch.direction.x * (radius * 1.5f);
        scratch.direction.y = scratch.direction.y * (radius * 1.5f);
        scratch.direction.z = scratch.direction.z * (radius * 1.5f);
        if (scratch.eyeX * scratch.fromX +
            scratch.eyeZ * scratch.fromZ < 0.0f)
        {
            scratch.endpoint.x = scratch.targetCenter.x + scratch.direction.x;
            scratch.endpoint.y = scratch.targetCenter.y + scratch.direction.y;
            scratch.endpoint.z = scratch.targetCenter.z + scratch.direction.z;
        }
        else
        {
            scratch.endpoint.x = scratch.targetCenter.x - scratch.direction.x;
            scratch.endpoint.y = scratch.targetCenter.y - scratch.direction.y;
            scratch.endpoint.z = scratch.targetCenter.z - scratch.direction.z;
        }
    }

    FUN_002a4690(&scratch.transform, &scratch.endpoint, &scratch.center,
                 &D_00697880);
    scratch.fromX = scratch.center.x;
    scratch.fromZ = scratch.center.z;
    scratch.toX = scratch.endpoint.x;
    scratch.toZ = scratch.endpoint.z;
    scratch.eye2X = scratch.targetCenter.x;
    scratch.eye2Z = scratch.targetCenter.z;
    distance = FUN_002d1fd0(&scratch.fromX, &scratch.toX,
                            &scratch.eye2X, NULL);
    if (genus == 0)
    {
        if (radius <= 100.0f)
        {
            radius = 100.0f;
        }
    }
    else if (radius <= 125.0f)
    {
        radius = 125.0f;
    }
    distance = 160.0f;
    if (160.0f <= distance + radius)
    {
        distance = distance + radius;
    }
    scratch.direction.x = scratch.center.x - scratch.endpoint.x;
    scratch.direction.y = scratch.center.y - scratch.endpoint.y;
    scratch.direction.z = scratch.center.z - scratch.endpoint.z;
    radius = RwV3dLength(&scratch.direction);
    distance = radius +
               distance / FUN_0052e930(fGpffff8070 * camera->fovRad * 0.5f);
    if (distance <= 0.0f)
    {
        distance = 0.0f;
    }
    FUN_004be1e0(&scratch.direction, 0x6978a0, 1,
                 (u8*)&scratch.transform);
    scratch.direction.x = scratch.direction.x * distance;
    scratch.direction.y = scratch.direction.y * distance;
    scratch.direction.z = scratch.direction.z * distance;
    scratch.output.x = scratch.center.x + scratch.direction.x;
    scratch.output.y = scratch.center.y + scratch.direction.y;
    scratch.output.z = scratch.center.z + scratch.direction.z;
    if (scratch.output.y < 25.0f)
    {
        scratch.output.y = 25.0f;
    }
    FUN_002a3e80(400.0f, (u8*)camera->action, (u8*)&scratch.output,
                 (u8*)&scratch.center, 3);
    FUN_002a2170(camera, (f32*)&scratch.output);
}

// FUN_002b2eb0 NONMATCHING

void FUN_002b2eb0(int param_1, float *param_2)
{
  struct {
    f32 values[9];
    s32 flag;
    f32 extra[2];
    RtQuat blend;
    f32 scale[2];
    RwV3d helper;
    f32 pad94;
    RwV3d transformed;
    f32 padA4;
    f32 output[3];
    f32 padb4;
    f32 unkB8;
    f32 result;
  } work;
  f32 ratio;
  f32 angle;
  f32 initial;
  f32 inverse;
  f32 curve;
  f32 poly;

  initial = FUN_00280870(3, 1, &work.helper, &work.result, &work.unkB8, 1);
  ratio = initial / FUN_0052e930(fGpffff8070 * (0.5f * *(f32 *)(param_1 + 0xb8)));
  work.output[0] = 0.0f;
  work.output[1] = work.result;
  work.output[2] = -initial;
  FUN_002a4690(param_2 + 3, work.output, &work.helper, (const void *)DAT_00697880_arr);
  angle = FUN_002d1f30_typed((f32 *)(param_1 + 0xa8), param_2 + 3);
  if (!(angle <= fGpffff80d4)) {
    ratio = fGpffff80d4 / angle;
    FUN_004be310_typed((void *)(param_1 + 0xa8), param_2 + 3, work.values);
    if (ratio <= 0.0f) {
      work.blend = *(RtQuat *)(param_1 + 0xa8);
    } else if (1.0f <= ratio) {
      work.blend = *(RtQuat *)((u8 *)param_2 + 0xc);
    } else {
      inverse = 1.0f - ratio;
      if (work.flag == 0) {
        inverse = inverse * work.values[8];
        curve = inverse * inverse;
        poly = fGpffff8114 * curve + fGpffff8048 + 0.0f;
        poly = curve * poly + fGpffff8118 + 0.0f;
        poly = curve * poly + fGpffff8050 + 0.0f;
        poly = curve * poly + fGpffff8054 + 0.0f;
        poly = curve * poly + fGpffff8058 + 0.0f;
        inverse = curve * inverse * poly + inverse + 0.0f;
        ratio = ratio * work.values[8];
        curve = ratio * ratio;
        poly = fGpffff8114 * curve + fGpffff8048 + 0.0f;
        poly = curve * poly + fGpffff8118 + 0.0f;
        poly = curve * poly + fGpffff8050 + 0.0f;
        poly = curve * poly + fGpffff8054 + 0.0f;
        poly = curve * poly + fGpffff8058 + 0.0f;
        ratio = curve * ratio * poly + ratio + 0.0f;
      }
      work.blend.imag.x = work.values[0] * inverse;
      work.blend.imag.y = work.values[1] * inverse;
      work.blend.imag.z = work.values[2] * inverse;
      work.blend.imag.x = work.blend.imag.x + work.values[4] * ratio + 0.0f;
      work.blend.imag.y = work.blend.imag.y + work.values[5] * ratio + 0.0f;
      work.blend.imag.z = work.blend.imag.z + work.values[6] * ratio + 0.0f;
      work.blend.real = work.values[3] * inverse + work.values[7] * ratio;
    }
    FUN_004be1e0_typed(&work.transformed, (const RwV3d *)DAT_006978A0_arr, 1, &work.blend);
    work.output[0] = work.helper.x + work.transformed.x;
    work.output[1] = work.helper.y + work.transformed.y;
    work.output[2] = work.helper.z + work.transformed.z;
    FUN_002a4690(param_2 + 3, work.output, &work.helper, (const void *)DAT_00697880_arr);
  }
  if (ratio < 700.0f) {
    ratio = 700.0f;
  }
  FUN_004be1e0_typed(&work.transformed, (const RwV3d *)DAT_006978A0_arr, 1, param_2 + 3);
  work.transformed.x = work.transformed.x * ratio;
  work.transformed.y = work.transformed.y * ratio;
  work.transformed.z = work.transformed.z * ratio;
  ratio = ratio * FUN_0052e930(fGpffff8070 * (0.5f * *(f32 *)(param_1 + 0xb8)));
  ratio = ratio * 0.21875f;
  work.scale[0] = work.transformed.x;
  work.scale[1] = work.transformed.z;
  FUN_004c6b20_typed(work.scale, work.scale);
  curve = ratio;
  work.helper.x = work.helper.x + work.scale[1] * curve + 0.0f;
  work.helper.z = work.helper.z - work.scale[0] * curve + 0.0f;
  param_2[0] = work.helper.x + work.transformed.x;
  param_2[1] = work.helper.y + work.transformed.y;
  param_2[2] = work.helper.z + work.transformed.z;
}

// FUN_002b32c0

void FUN_002b32c0(u16* camera)

{
  struct {
    undefined1 first[28];
    undefined1 second[36];
  } scratch;

  FUN_002a4470((f32*)scratch.first, (f32*)((u8*)camera + 0x9c));
  FUN_002b2eb0((int)camera, (float*)scratch.second);
  FUN_002a2290(camera, (RwV3d*)scratch.first, (RwV3d*)scratch.second, 1);
  FUN_002a3110(camera, 10.0f);
  return;
}

// FUN_002b3330
void func_002b3330(void)
{
}

// FUN_002b3340

void FUN_002b3340(BtlCamera* camera)
{
    int iVar1;
    int iVar2;
    f32 distance;
    f32 minDistance;
    f32 norm;
    f32 height;
    f32 candidate;
    struct {
        RwV3d out;
        RtQuat unk;
        f32 pad0;
        RwV3d diff;
        f32 pad1;
        RwV3d pos;
        f32 posPad;
        RwV3d target;
    } scratch;

    iVar2 = (int)camera;
    iVar1 = *(int*)(iVar2 + 0xe0);
    if (iVar1 != 0)
    {
        iVar1 = *(int*)(iVar1 + 0x30);
    }
    else
    {
        iVar1 = *(int*)(*(int*)(iGpffffb6fc + 0x148) + 0x30);
    }
    distance = FUN_00280870(3, 1, &scratch.target, &height, 0, 1);
    FUN_00280050(iVar1, &scratch.pos);
    scratch.target.y = 0.0f;
    scratch.pos.y = 0.0f;
    if ((scratch.pos.x == scratch.target.x) &&
        (scratch.pos.z == scratch.target.z))
    {
        FUN_00280050(*(int*)(*(int*)(iGpffffb6fc + 0x148) + 0x30),
                     &scratch.pos);
        scratch.pos.y = 0.0f;
    }
    scratch.diff.x = scratch.pos.x - scratch.target.x;
    scratch.diff.y = scratch.pos.y - scratch.target.y;
    scratch.diff.z = scratch.pos.z - scratch.target.z;
    FUN_004c69f0(&scratch.diff.x, &scratch.diff.x);
    scratch.diff.x = scratch.diff.x * distance;
    scratch.diff.y = scratch.diff.y * distance;
    scratch.diff.z = scratch.diff.z * distance;
    scratch.pos.x = scratch.target.x + scratch.diff.x;
    scratch.pos.y = scratch.target.y + scratch.diff.y;
    scratch.pos.z = scratch.target.z + scratch.diff.z;
    minDistance = 0.75f *
                  (*(f32*)(iVar1 + 0x8c) *
                   *(f32*)(iVar1 + 0x2c));
    norm = fGpffff80c4 * height;
    norm = (!(norm > minDistance)) ? minDistance : norm;
    scratch.pos.y = norm;
    FUN_002a4690(&scratch.unk, &scratch.pos, &scratch.target, &D_00697880);
    minDistance = (0.75f * distance) /
                  FUN_0052e930(gp0xffff8070 *
                               (0.5f * *(f32*)(iVar2 + 0xb8)));
    scratch.diff.x = scratch.pos.x - scratch.target.x;
    scratch.diff.y = scratch.pos.y - scratch.target.y;
    scratch.diff.z = scratch.pos.z - scratch.target.z;
    norm = FUN_004c69f0(&scratch.diff.x, &scratch.diff.x);
    distance = FUN_0052e930(gp0xffff8070 *
                            (0.5f * *(f32*)(iVar2 + 0xb8)));
    candidate = norm +
                (*(f32*)(iVar1 + 0x90) *
                 *(f32*)(iVar1 + 0x2c) * 2.0f) /
                distance;
    if (!(minDistance <= candidate))
    {
        minDistance = minDistance + 0.0f;
    }
    else
    {
        minDistance = candidate;
    }
    scratch.diff.x = scratch.diff.x * minDistance;
    scratch.diff.y = scratch.diff.y * minDistance;
    scratch.diff.z = scratch.diff.z * minDistance;
    scratch.out.x = scratch.diff.x + scratch.target.x;
    scratch.out.y = scratch.diff.y + scratch.target.y;
    scratch.out.z = scratch.diff.z + scratch.target.z;
    FUN_002a3590((f32*)&scratch.out, (f32*)&scratch.out);
    FUN_002a3e80(0.0f, (u8*)0, (u8*)0, (u8*)0, 0x40);
    FUN_002a2170((BtlCamera*)(uintptr_t)iVar2, (f32*)&scratch.out);
    FUN_002a44b0((f32*)(iVar2 + 0x9c), (f32*)&scratch.out);
}

// FUN_002b3680
void FUN_002b3680(void)
{
}

// FUN_002b3690

void FUN_002b3690(BtlCamera* camera)
{
    BtlUnit* unit;
    f32 firstScale;
    f32 secondScale;
    struct
    {
        RwV3d firstPos;
        RtQuat firstRot;
        RwV3d secondPos;
        RtQuat secondRot;
        u8 pad_38[8];
        RwV3d direction;
        u8 pad_4c[4];
        RwV3d base;
        u8 pad_5c[4];
        RwV3d center;
        f32 scalar;
    } work;

    unit = *(BtlUnit**)(*(u8**)(iGpffffb6fc + 0x148) + 0x30);
    firstScale = FUN_00280870(3, 0, 0, &work.scalar, 0, 1);
    FUN_00280870(2, 0, &work.base, 0, 0, 1);
    work.base.y = 0.5f * work.scalar;
    FUN_00280050_typed(unit, &work.center);
    work.center.y = work.center.y + 0.75f * (unit->unk_8c * unit->scale);
    FUN_002a4690(&work.firstRot, &work.center, &work.base, &D_00697880);
    work.secondRot = work.firstRot;
    secondScale = 250.0f / tanf(0.5f * camera->fovRad);
    if (*(u8*)(iGpffffb6fc + 0xba4) <= 1)
        goto rotation_done;
    FUN_004bdde0((f32*)&work.firstRot, (const f32*)&D_00697880,
                 30.0f, 2);
rotation_done:
    RtQuatTransformVectors(&work.direction, &D_006978A0, 1,
                           &work.firstRot);
    work.direction.x = work.direction.x * secondScale;
    work.direction.y = work.direction.y * secondScale;
    work.direction.z = work.direction.z * secondScale;
    work.firstPos.x = work.base.x + work.direction.x;
    work.firstPos.y = work.base.y + work.direction.y;
    work.firstPos.z = work.base.z + work.direction.z;
    firstScale = (0.875f * firstScale) /
                 tanf(gp0xffff8070 * (0.5f * camera->fovRad));
    if (*(u8*)(iGpffffb6fc + 0xba4) == 1)
    {
        firstScale +=
            (0.5f * (unit->unk_8c * unit->scale)) /
            tanf(0.5f * camera->fovRad);
    }
    RtQuatTransformVectors(&work.direction, &D_006978A0, 1,
                           &work.secondRot);
    work.direction.x = work.direction.x * firstScale;
    work.direction.y = work.direction.y * firstScale;
    work.direction.z = work.direction.z * firstScale;
    work.secondPos.x = work.base.x + work.direction.x;
    work.secondPos.y = work.base.y + work.direction.y;
    work.secondPos.z = work.base.z + work.direction.z;
    FUN_002a2290((u16*)camera, &work.firstPos, &work.secondPos, 1);
    FUN_002a3110((u16*)camera, gp0xffff80e0);
}

// FUN_002b3980

void FUN_002b3980(BtlCamera* camera)
{
    struct B3980Scratch {
        u8 records[4][28];
        RwMatrix matrix;
        RwV3d view;
        u32 viewPad;
        RwV3d transformed;
        u32 transformedPad;
        RwV3d center;
        u32 centerPad;
        f32 output[3];
    };
    f32 temp_f1;
    f32 var_f25;
    f32 var_f24;
    f32 var_f23;
    f32 temp_f22;
    f32 temp_f21_2;
    f32 temp_f20_2;
    f32 temp_f20;
    f32 temp_f21;
    s32 var_17;
    BtlUnit* temp_16;
    struct B3980Scratch scratch;
    temp_16 = camera->action->unit;
    FUN_0027ffb0(temp_16, &scratch.center);
    temp_f1 = temp_16->scale;
    temp_f20 = temp_16->sphereRadius * temp_f1;
    temp_f21 = 0.5f * (temp_16->unk_8c * temp_f1);
    scratch.center.y = fGpffff80b4 * temp_f21 + scratch.center.y + 0.0f;
    if (!(temp_f20 <= temp_f21)) {
        var_f25 = (1.25f * temp_f20) /
                  FUN_0052e930(fGpffff8070 * (camera->fovRad * 0.5f));
    } else {
        var_f25 = (1.25f * temp_f21) /
                  FUN_0052e930(camera->fovRad * 0.5f);
    }
    if (FUN_002ffbc0(100) > 0x32) {
        var_f24 = 60.0f;
        var_f23 = -30.0f;
    } else {
        var_f24 = -60.0f;
        var_f23 = 30.0f;
    }
    var_17 = 0;
    while ((var_17 & 0xffff) < 4) {
        FUN_004c31b0_typed(&scratch.matrix, &D_00697880, var_f24, 0);
        FUN_004c6c60(&scratch.view, &D_00697890, &scratch.matrix);
        FUN_004be1e0(&scratch.transformed, &scratch.view, 1, &temp_16->rot);
        temp_f22 = scratch.transformed.x * var_f25;
        temp_f21_2 = scratch.transformed.y * var_f25;
        temp_f20_2 = scratch.transformed.z * var_f25;
        scratch.output[0] = scratch.center.x + temp_f22;
        scratch.output[1] = scratch.center.y + temp_f21_2;
        scratch.output[2] = scratch.center.z + temp_f20_2;
        FUN_002a4690(scratch.records[(u16)var_17] + 0xc,
                     scratch.output, &scratch.center, &D_00697880);
        *(f32 *)(scratch.records[(u16)var_17] + 0x00) = scratch.center.x + temp_f22;
        *(f32 *)(scratch.records[(u16)var_17] + 0x04) = scratch.center.y + temp_f21_2;
        *(f32 *)(scratch.records[(u16)var_17] + 0x08) = scratch.center.z + temp_f20_2;
        var_f24 = var_f24 + var_f23;
        var_f25 = var_f25 + 37.5f;
        var_17 = (var_17 + 1) & 0xffff;
    }
    FUN_002a3e80(0.0f, (u8*)camera->action, 0, 0, 1);
    FUN_002a2660(camera, (BtlCameraKeyFrame*)&scratch.records[0],
                 (BtlCameraKeyFrame*)&scratch.records[1],
                 (BtlCameraKeyFrame*)&scratch.records[2],
                 (BtlCameraKeyFrame*)&scratch.records[3], 1);
    FUN_002a3110((u16*)camera, 6.0f);
}

// FUN_002b3c60

void FUN_002b3c60(BtlCamera* camera)
{
  RwV3d center;
  RwV3d transformed;
  struct {
    u8 frameBytes[0x70];
    RwMatrix matrix;
    f32 directionX;
    f32 directionY;
    f32 directionZ;
  } scratch;
  BtlUnit* unit;
  f32 radius;
  f32 halfHeight;
  f32 distance;
  f32 angle;
  s32 i;

  unit = camera->action->unit;
  btlUnitGetSphereWorldCenter(unit, &center);
  radius = unit->sphereRadius * unit->scale;
  halfHeight = 0.5f * (unit->unk_8c * unit->scale);
  center.y = 0.0f + center.y + fGpffff80b4 * halfHeight;
  RtQuatTransformVectors(&transformed, &D_00697890, 1, &unit->rot);
  scratch.directionX = 350.0f * transformed.x;
  scratch.directionY = 350.0f * transformed.y;
  scratch.directionZ = 350.0f * transformed.z;
  distance = (center.y + scratch.directionY) - 35.0f;
  transformed.x = (center.x + scratch.directionX) - center.x;
  transformed.y = distance - center.y;
  transformed.z = (center.z + scratch.directionZ) - center.z;
  RwV3dNormalize(&transformed, &transformed);
  if (!(radius < halfHeight))
  {
    distance = 1.75f * radius /
               tanf(fGpffff8070 * (0.5f * camera->fovRad));
  }
  else
  {
    distance = fGpffff8070 * halfHeight /
               tanf(0.5f * camera->fovRad);
  }
  angle = 65.0f;
  i = 0;
  while ((i & 0xffff) < 4)
  {
    RwMatrixRotate(&scratch.matrix, &D_00697880, angle,
                   rwCOMBINEREPLACE);
    FUN_004c6c60((RwV3d*)&scratch.directionX, &transformed,
                 &scratch.matrix);
    ((BtlCameraKeyFrame*)scratch.frameBytes)[(u16)i].pos.x =
        0.0f + center.x + scratch.directionX * distance;
    ((BtlCameraKeyFrame*)scratch.frameBytes)[(u16)i].pos.y =
        0.0f + center.y + scratch.directionY * distance;
    ((BtlCameraKeyFrame*)scratch.frameBytes)[(u16)i].pos.z =
        0.0f + center.z + scratch.directionZ * distance;
    if (((BtlCameraKeyFrame*)scratch.frameBytes)[(u16)i].pos.y < 5.0f)
    {
      ((BtlCameraKeyFrame*)scratch.frameBytes)[(u16)i].pos.y = 5.0f;
    }
    FUN_002a4690(&((BtlCameraKeyFrame*)scratch.frameBytes)[(u16)i].rot,
                 &((BtlCameraKeyFrame*)scratch.frameBytes)[(u16)i].pos,
                 &center, &D_00697880);
    angle = angle + -25.0f;
    distance = distance + 25.0f;
    i = (i + 1) & 0xffff;
  }
  FUN_002a3e80(0.0f, (u8*)camera->action, 0, 0, 1);
  FUN_002a2660(camera, (BtlCameraKeyFrame*)&scratch.frameBytes[0],
               (BtlCameraKeyFrame*)&scratch.frameBytes[0x1c],
               (BtlCameraKeyFrame*)&scratch.frameBytes[0x38],
               (BtlCameraKeyFrame*)&scratch.frameBytes[0x54], 1);
  FUN_002a3110((u16*)camera, 10.0f);
}

// FUN_002b3f80

void FUN_002b3f80(BtlCamera* camera)
{
  struct Scratch {
    RwV3d matrix;
    u8 gap_0c[16];
    RwV3d transformed;
    RwV3d view;
    u8 gap_30[4];
    RwV3d center;
    u8 gap_40[4];
    RwV3d direction;
    u8 gap_50[4];
    RwV3d target;
    u8 gap_60[4];
    RwV3d endpoint;
    u8 gap_70[4];
    RwV3d candidate;
    u8 gap_80[4];
    f32 halfA;
    f32 halfB;
  } scratch;
  BtlUnit* unit;
  f32 scale;
  f32 length;
  f32 factor;
  f32 midpoint;

  unit = *(BtlUnit**)(*(int*)((u8*)camera + 0xe0) + 0x30);
  FUN_002a4470((f32*)&scratch.matrix, (f32*)((u8*)camera + 0x9c));
  scale = FUN_00280870(3, 1, &scratch.endpoint, &scratch.halfB, &scratch.halfA, 1);
  midpoint = scratch.halfB - scratch.halfA;
  scratch.endpoint.y = midpoint * 0.5f + scratch.halfA + 0.0f;
  scale = scale / tanf(fGpffff8070 * (*(f32*)((u8*)camera + 0xb8) * 0.5f));
  FUN_00280050(unit, &scratch.center);
  scratch.target.x = scratch.center.x;
  scratch.target.y = scratch.endpoint.y;
  scratch.target.z = scratch.center.z;
  scratch.direction.x = scratch.center.x - scratch.endpoint.x;
  scratch.direction.y = scratch.target.y - scratch.target.y;
  scratch.direction.z = scratch.center.z - scratch.endpoint.z;
  length = FUN_004c69f0(&scratch.direction, &scratch.direction);
  factor = fGpffff8098;
  factor = factor * length;
  length = factor;
  scratch.direction.x = scratch.direction.x * length;
  scratch.direction.y = scratch.direction.y * length;
  scratch.direction.z = scratch.direction.z * length;
  scratch.candidate.x = scratch.endpoint.x + scratch.direction.x;
  scratch.candidate.y = scratch.endpoint.y + scratch.direction.y;
  scratch.candidate.z = scratch.endpoint.z + scratch.direction.z;
  scratch.target.x = scratch.center.x;
  scratch.target.y = scratch.halfB * 2.5f;
  scratch.target.z = scratch.center.z;
  FUN_002a4690(&scratch.view, &scratch.target, &scratch.candidate, &D_00697880);
  FUN_004be1e0(&scratch.direction, &D_006978A0, 1, &scratch.view);
  scratch.direction.x = scratch.direction.x * scale;
  scratch.direction.y = scratch.direction.y * scale;
  scratch.direction.z = scratch.direction.z * scale;
  scratch.transformed.x = scratch.candidate.x + scratch.direction.x;
  scratch.transformed.y = scratch.candidate.y + scratch.direction.y;
  scratch.transformed.z = scratch.candidate.z + scratch.direction.z;
  FUN_002a3590((f32*)&scratch.matrix, (f32*)&scratch.matrix);
  FUN_002a3590((f32*)&scratch.transformed, (f32*)&scratch.transformed);
  FUN_002a2290((u16*)camera, &scratch.matrix, &scratch.transformed, 1);
  FUN_002a3110((u16*)camera, 0.75f);
}

// FUN_002b41e0 NONMATCHING
void FUN_002b41e0(BtlCamera* camera)
{
    struct B41Work
    {
        BtlCameraKeyFrame current;
        RwV3d target;
        RtQuat targetRot;
        u8 pad_38[8];
        BtlCameraQuatBlend blend;
        u8 pad_68[8];
        RtQuat blendedRot;
        u8 pad_80[8];
        RwV2d horizontal;
        RwV3d center;
        u8 pad_9c[4];
        RwV3d pointNear;
        u8 pad_ac[4];
        RwV3d delta;
        u8 pad_bc[4];
        RwV3d candidate;
        u8 pad_cc[4];
    } work;
    BtlUnit* unit;
    f32 halfDistance;
    f32 desiredDistance;
    f32 radius;
    f32 angle;
    f32 ratio;
    f32 sideOffset;
    f32 x;
    f32 xSquared;

    unit = *(BtlUnit**)((u8*)camera->action + 0x30);
    radius = unit->sphereRadius * unit->scale;
    FUN_002a4470((f32*)&work.current, (f32*)((u8*)camera + 0x9c));
    FUN_00280050(unit, &work.center);

    work.delta.x = work.current.pos.x - work.center.x;
    work.delta.y = work.current.pos.y - work.center.y;
    work.delta.z = work.current.pos.z - work.center.z;
    halfDistance = RwV3dLength(&work.delta) * 0.5f;
    desiredDistance = (1.5f * radius) /
                      FUN_0052e930(0.5f * camera->fovRad);

    RtQuatTransformVectors(&work.delta, &D_00697890, 1, &unit->rot);
    x = 0.5f * radius;
    work.candidate.x = work.delta.x * x;
    work.candidate.y = work.delta.y * x;
    work.candidate.z = work.delta.z * x;
    work.pointNear.x = work.center.x + work.candidate.x;
    work.pointNear.y = work.center.y + work.candidate.y;
    work.pointNear.z = work.center.z + work.candidate.z;

    work.candidate.x = work.delta.x * desiredDistance;
    work.candidate.y = work.delta.y * desiredDistance;
    work.candidate.z = work.delta.z * desiredDistance;
    work.candidate.x = work.candidate.x + work.pointNear.x;
    work.candidate.y = work.candidate.y + work.pointNear.y;
    work.candidate.z = work.candidate.z + work.pointNear.z;
    work.candidate.y = work.candidate.y +
        fGpffff8084 * (unit->unk_8c * unit->scale) + 0.0f;

    FUN_002a4690(&work.targetRot, &work.candidate,
                 &work.pointNear, &D_00697880);
    angle = FUN_002d1f30((f32*)&work.current.rot,
                         (f32*)&work.targetRot);
    if (angle > fGpffff80d4)
    {
        ratio = fGpffff80d4 / angle;
        FUN_004be310((f32*)&work.current.rot,
                     (f32*)&work.targetRot,
                     (f32*)&work.blend);
        if (ratio <= 0.0f)
        {
            work.blendedRot = work.current.rot;
        }
        else if (1.0f <= ratio)
        {
            work.blendedRot = work.targetRot;
        }
        else
        {
            f32 firstWeight;

            firstWeight = 1.0f - ratio;
            if (work.blend.flag == 0)
            {
                x = firstWeight * work.blend.scalar;
                xSquared = x * x;
                firstWeight = fGpffff8130 * xSquared + fGpffff8048;
                firstWeight = xSquared * firstWeight + fGpffff8118;
                firstWeight = xSquared * firstWeight + fGpffff8050;
                firstWeight = xSquared * firstWeight + fGpffff8054;
                firstWeight = xSquared * firstWeight + fGpffff8058;
                firstWeight = xSquared * x * firstWeight + x;

                x = ratio * work.blend.scalar;
                xSquared = x * x;
                ratio =
                    xSquared * x *
                    (xSquared *
                     (xSquared *
                      (xSquared *
                       (xSquared *
                        (fGpffff8130 * xSquared +
                         fGpffff8048) +
                        fGpffff8118) +
                       fGpffff8050) +
                      fGpffff8054) +
                     fGpffff8058) +
                    x;
            }

            work.blendedRot.imag.x =
                work.blend.first.imag.x * firstWeight;
            work.blendedRot.imag.y =
                work.blend.first.imag.y * firstWeight;
            work.blendedRot.imag.z =
                work.blend.first.imag.z * firstWeight;
            work.blendedRot.imag.x = work.blendedRot.imag.x +
                work.blend.second.imag.x * ratio + 0.0f;
            work.blendedRot.imag.y = work.blendedRot.imag.y +
                work.blend.second.imag.y * ratio + 0.0f;
            work.blendedRot.imag.z = work.blendedRot.imag.z +
                work.blend.second.imag.z * ratio + 0.0f;
            work.blendedRot.real =
                work.blend.first.real * firstWeight +
                work.blend.second.real * ratio;
        }

        RtQuatTransformVectors(&work.delta, &D_006978A0, 1,
                               &work.blendedRot);
        work.candidate.x = work.pointNear.x + work.delta.x;
        work.candidate.y = work.pointNear.y + work.delta.y;
        work.candidate.z = work.pointNear.z + work.delta.z;
        FUN_002a4690(&work.targetRot, &work.candidate,
                     &work.pointNear, &D_00697880);
    }

    if (halfDistance < 600.0f)
    {
        halfDistance = 600.0f;
    }
    RtQuatTransformVectors(&work.delta, &D_006978A0, 1,
                           &work.targetRot);
    work.delta.x *= halfDistance;
    work.delta.y *= halfDistance;
    work.delta.z *= halfDistance;

    sideOffset = halfDistance *
                 FUN_0052e930(gp0xffff8070 *
                              (0.5f * camera->fovRad));
    sideOffset = sideOffset * 0.21875f;
    work.horizontal.x = work.delta.x;
    work.horizontal.y = work.delta.z;
    FUN_004c6b20((f32*)&work.horizontal,
                 (f32*)&work.horizontal);
    work.pointNear.x += work.horizontal.y * sideOffset;
    work.pointNear.z -= work.horizontal.x * sideOffset;

    work.target.x = work.pointNear.x + work.delta.x;
    work.target.y = work.pointNear.y + work.delta.y;
    work.target.z = work.pointNear.z + work.delta.z;
    FUN_002a2290((u16*)camera, &work.current.pos, &work.target, 1);
    FUN_002a3110((u16*)camera, 1.25f);
}

// FUN_002b4720

void FUN_002b4720(int param_1)

{
  int iVar1;
  undefined1 auStack_10 [16];
  
  iVar1 = *(int *)(param_1 + 0xe0);
  if ((iVar1 != 0) && ((*(u16 *)(iVar1 + 0x1a) & 1) != 0)) {
    iVar1 = *(int *)(iVar1 + 0x30);
    FUN_0027ffb0(iVar1,auStack_10);
    FUN_002a3e80(*(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c) * 0.5f,
                 (u8*)(uintptr_t)*(undefined4 *)(param_1 + 0xe0),
                 (u8*)(uintptr_t)(param_1 + 0x9c),(u8*)auStack_10,0x31);
  }
  return;
}

// FUN_002b47b0
void FUN_002b47b0(BtlCamera* camera)
{
  typedef struct B47Scratch {
    f32 finalPos[3];
    f32 quatCopy[4];
    f32 worldBase[3];
    f32 quat[4];
    u8 pad0[8];
    f32 transformed[3];
    u8 pad1[4];
    f32 worldSecond[3];
    u8 pad2[4];
    f32 worldFirst[3];
    u8 pad3[4];
    f32 sourceSecond[3];
    u8 pad4[4];
    f32 sourceFirst[3];
    u8 pad5[4];
  } B47Scratch;
  BtlAction* action;
  BtlUnit* unit;
  s16 state;
  B47Scratch scratch;
  extern u8 (*gp0xffffb714)[0x4c];
  extern void FUN_004be1e0(RwV3d*, const RwV3d*, int, void*);

  action = camera->action;
  if ((action->unk_1a & 1) == 0) {
    return;
  }
  unit = action->unit;
  if (unit->genus != 1) {
    return;
  }

  state = unit->unk_9e0;
  switch (state) {
  case 3:
    *(RwV3d*)scratch.sourceFirst = *(RwV3d*)((u8*)(unit->charId * 0x4c) + (int)gp0xffffb714 + 0x1c);
    *(RwV3d*)scratch.sourceSecond = *(RwV3d*)((u8*)(unit->charId * 0x4c) + (int)gp0xffffb714 + 0x28);
    break;
  case 9:
    *(RwV3d*)scratch.sourceFirst = *(RwV3d*)((u8*)(unit->charId * 0x4c) + (int)gp0xffffb714 + 0x34);
    *(RwV3d*)scratch.sourceSecond = *(RwV3d*)((u8*)(unit->charId * 0x4c) + (int)gp0xffffb714 + 0x40);
    break;
  case 0x11:
    if (FUN_0030c3a0(unit->datUnit) != 0) {
      *(RwV3d*)scratch.sourceFirst = *(RwV3d*)((u8*)(unit->charId * 0x4c) + (int)gp0xffffb714 + 0x1c);
      *(RwV3d*)scratch.sourceSecond = *(RwV3d*)((u8*)(unit->charId * 0x4c) + (int)gp0xffffb714 + 0x28);
      break;
    }
  default:
    *(RwV3d*)scratch.sourceFirst = *(RwV3d*)((u8*)(unit->charId * 0x4c) + (int)gp0xffffb714 + 4);
    *(RwV3d*)scratch.sourceSecond = *(RwV3d*)((u8*)(unit->charId * 0x4c) + (int)gp0xffffb714 + 0x10);
    break;
  }

  FUN_004be1e0((RwV3d*)scratch.sourceFirst,
               (RwV3d*)scratch.sourceFirst, 1, (u8*)unit + 0x1c);
  FUN_004be1e0((RwV3d*)scratch.sourceSecond,
               (RwV3d*)scratch.sourceSecond, 1,
               (void*)((u8*)&unit->pos + 0x18));
  scratch.worldFirst[0] = unit->pos.x + scratch.sourceFirst[0];
  scratch.worldFirst[1] = unit->pos.y + scratch.sourceFirst[1];
  scratch.worldFirst[2] = unit->pos.z + scratch.sourceFirst[2];
  scratch.worldSecond[0] = unit->pos.x + scratch.sourceSecond[0];
  scratch.worldSecond[1] = unit->pos.y + scratch.sourceSecond[1];
  scratch.worldSecond[2] = unit->pos.z + scratch.sourceSecond[2];

  FUN_002a4690(scratch.quat, scratch.worldFirst, scratch.worldSecond,
               &D_00697880);
  *(RwV3d*)scratch.worldBase = *(RwV3d*)scratch.worldFirst;
  *(RtQuat*)scratch.quatCopy = *(RtQuat*)scratch.quat;
  FUN_004be1e0((RwV3d*)scratch.transformed, &D_006978A0, 1,
               scratch.quat);
  scratch.transformed[0] = scratch.transformed[0] * 100.0f;
  scratch.transformed[1] = scratch.transformed[1] * 100.0f;
  scratch.transformed[2] = scratch.transformed[2] * 100.0f;
  scratch.finalPos[0] = scratch.worldBase[0] + scratch.transformed[0];
  scratch.finalPos[1] = scratch.worldBase[1] + scratch.transformed[1];
  scratch.finalPos[2] = scratch.worldBase[2] + scratch.transformed[2];
  if (scratch.finalPos[1] < 25.0f) {
    scratch.finalPos[1] = 25.0f;
  }
  FUN_002a3e80(0.0f, (u8*)camera->action, 0, 0, 1);
  FUN_002a2290((u16*)camera, (RwV3d*)scratch.finalPos,
               (RwV3d*)scratch.worldBase, 1);
  FUN_002a3110((u16*)camera, 2.0f);
}

// FUN_002b4bc0

void FUN_002b4bc0(int param_1)
{
  FUN_002a3e80(0.0f, (u8 *)(uintptr_t)*(int *)(param_1 + 0xe0), 0, 0, 0);
}


// FUN_002B4C00
void FUN_002b4c00(int param_1)
{
  struct {
    RwV3d first;
    u8 firstTransform[16];
    RwV3d second;
    u8 secondTransform[16];
  } scratch;
  u16* cameraData;

  if (*(int *)(param_1 + 0xd8) == 0) {
    FUN_002a4690(scratch.firstTransform, &D_00694E90, D_00694EB0, &D_00697880);
    scratch.first = D_00694E90;
    FUN_002a4690(scratch.secondTransform, &D_00694ED0, D_00694EF0, &D_00697880);
    scratch.second = D_00694ED0;
    FUN_002a2290((u16 *)(iGpffffb6fc + 0x20), &scratch.first, &scratch.second, 1);
    cameraData = (u16 *)(iGpffffb6fc + 0x20);
    FUN_002a3110(cameraData, fGpffff813c);
  } else if (*(int *)(param_1 + 0xd8) == 0x25) {
    FUN_002a4690(scratch.firstTransform, D_00694E9C, D_00694EBC, &D_00697880);
    scratch.first = *(RwV3d*)D_00694E9C;
    FUN_002a4690(scratch.secondTransform, &D_00694EDC, D_00694EFC, &D_00697880);
    scratch.second = D_00694EDC;
    FUN_002a2290((u16 *)(iGpffffb6fc + 0x20), &scratch.first, &scratch.second, 1);
    cameraData = (u16 *)(iGpffffb6fc + 0x20);
    FUN_002a3110(cameraData, fGpffff80e0);
  }
}

// FUN_002b4db0

void FUN_002b4db0(int param_2,float param_1)
{
  extern void FUN_004c31b0(void *,void *,f32,int);
  extern f32 FUN_0052e930(f32);
  int iVar1;
  float fVar2;
  float fVar3;
  u8 auStack_90[0x80];
  iVar1 = param_2;

  fVar2 = (float)FUN_00280870(3,0,auStack_90 + 0x70,0,0,1);
  *(u32 *)(auStack_90 + 0x74) = 0;
  FUN_004c31b0(auStack_90,&D_00697870,-17.5f,0);
  FUN_004c31b0(auStack_90,&D_00697880,*(f32 *)(iVar1 + 0x100),2);
  FUN_004c6c60((f32 *)(auStack_90 + 0x60),&D_00697890,auStack_90);
  fVar3 = FUN_0052e930(fGpffff8070 * (0.5f * *(float *)(iVar1 + 0xb8)));
  fVar3 = (fVar2 * param_1) / fVar3;
  *(f32 *)(auStack_90 + 0x40) = *(f32 *)(auStack_90 + 0x60) * fVar3;
  *(f32 *)(auStack_90 + 0x44) = *(f32 *)(auStack_90 + 0x64) * fVar3;
  *(f32 *)(auStack_90 + 0x48) = *(f32 *)(auStack_90 + 0x68) * fVar3;
  FUN_002a4690(auStack_90 + 0x4c,auStack_90 + 0x40,auStack_90 + 0x70,&D_00697880);
  if (*(f32 *)(auStack_90 + 0x44) < 25.0f) {
    *(f32 *)(auStack_90 + 0x44) = 25.0f;
  }
  *(float *)(iVar1 + 0x100) = *(float *)(iVar1 + 0x100) + 0.25f;
  if ((*(u32 *)(iGpffffb6fc + 0xc) & 0x200000) == 0) {
    FUN_002a3590((float *)(auStack_90 + 0x40),(float *)(auStack_90 + 0x40));
  }
  FUN_002a2170(iVar1,(f32 *)(auStack_90 + 0x40));
}

// FUN_002b4f40

void FUN_002b4f40(int param_1)

{
  *(float *)(param_1 + 0x100) = (float)FUN_002ffbc0(0x168);
  FUN_002a3e80(0.0f, (u8 *)(uintptr_t)*(int *)(param_1 + 0xe0), 0, 0, 0x40);
}

#pragma alias FUN_002b4db0_float FUN_002b4db0
extern void FUN_002b4db0_float(float);

// FUN_002b4fd0
void FUN_002b4fd0(void)

{
  FUN_002b4db0_float(DAT_007cad94);
  return;
}

// FUN_002b5000

void FUN_002b5000(int param_1)

{
  int iVar1;
  float fVar3;
  float fVar4;
  float fVar5;
  RwV3d mat;
  RwV3d pos;
  RwV3d diff;
  struct {
    u8 out [28];
    f32 end [3];
    RtQuat unk;
  } pkt;

  iVar1 = *(int *)(*(int *)(param_1 + 0xe0) + 0x30);
  FUN_002a4470((f32 *)pkt.out,(f32 *)((u8 *)param_1 + 0x9c));
  fVar3 = FUN_00280870(3,1,&mat,0,0,1);
  mat.y = 0.0f;
  FUN_00280050(iVar1,&pos);
  pos.y = pos.y + 0.0f + DAT_007cad74 * (*(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c));
  FUN_002a4690(&pkt.unk,&pos,&mat,&D_00697880);
  fVar4 = FUN_0052e930(DAT_007cad60 * (0.5f * *(float *)(param_1 + 0xb8)));
  fVar3 = fVar3 / fVar4;
  diff.x = pos.x - mat.x;
  diff.y = pos.y - mat.y;
  diff.z = pos.z - mat.z;
  fVar5 = FUN_004c69f0(&diff,&diff);
  fVar4 = FUN_0052e930(DAT_007cad60 * (0.5f * *(float *)(param_1 + 0xb8)));
  fVar5 = fVar5 + (5.0f * (*(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c))) / fVar4;
  if (!(fVar3 <= fVar5)) {
    fVar3 = fVar3 + 0.0f;
  }
  else {
    fVar3 = fVar5;
  }
  diff.x = diff.x * fVar3;
  diff.y = diff.y * fVar3;
  diff.z = diff.z * fVar3;
  pkt.end[0] = diff.x + mat.x;
  pkt.end[1] = diff.y + mat.y;
  pkt.end[2] = diff.z + mat.z;
  if ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x200000) == 0) {
    FUN_002a3590(pkt.end,pkt.end);
  }
  FUN_002a2290((u16 *)param_1,(RwV3d *)pkt.out,(RwV3d *)pkt.end,1);
  FUN_002a3110((u16 *)param_1,1.0f);
  return;
}

// FUN_002b5240 NONMATCHING

void FUN_002b5240(BtlCamera* camera)
{
    BtlCamera* cam;
    BtlUnit* unit;
    BtlUnit* unit2;
    struct {
        f32 outX;
        f32 outY;
        f32 outZ;
        u8 quat[16];
        u8 pad[0xc];
        f32 sx;
        f32 sz;
        f32 px;
        f32 py;
        f32 pz;
        u8 padPoint[4];
        f32 vx;
        f32 vy;
        f32 vz;
        u8 padView[4];
        f32 d2x;
        f32 d2y;
        f32 d2z;
        u8 padD2[4];
        f32 dx;
        f32 dy;
        f32 dz;
        u8 padDelta[4];
        RwV3d center2;
        u8 padCenter[4];
        RwV3d center1;
    } w;
    f32 factor;
    f32 radiusFactor;
    f32 radius;
    f32 scale;
    f32 length;
    f32 horizFactor;
    f32 pzTemp;

    cam = camera;
    unit = cam->action->unit;
    unit2 = *(BtlUnit**)(*(u8**)(DAT_007ce3ec + 0x148) + 0x30);
    btlUnitGetSphereWorldCenter(unit, &w.center1);
    radius = unit->sphereRadius * unit->scale;
    btlUnitGetSphereWorldCenter(unit2, &w.center2);

    w.dx = w.center1.x - w.center2.x;
    w.dy = w.center1.y - w.center2.y;
    w.dz = w.center1.z - w.center2.z;
    factor = gp0xffff8030 * FUN_004c69f0(&w.dx, &w.dx);
    w.vx = w.dx * factor;
    w.vy = w.dy * factor;
    w.vz = w.dz * factor;
    w.vx = w.vx + w.center2.x;
    w.vy = w.vy + w.center2.y;
    w.vz = w.vz + w.center2.z;

    *(u64*)&w.px = *(u64*)&w.center1;
    pzTemp = w.center1.z;
    w.pz = pzTemp;
    w.py = w.center2.y;
    w.d2x = w.px - w.center2.x;
    w.d2y = w.py - w.py;
    w.d2z = *(volatile f32*)&w.pz - w.center2.z;
    FUN_004c69f0(&w.d2x, &w.d2x);
    factor = 1.5f * radius;
    w.px = w.px - w.d2z * factor;
    w.pz = w.d2x * factor + w.pz;
    w.py = w.center1.y + (unit->unk_8c * unit->scale) * gp0xffff8094;
    FUN_002a4690(w.quat, &w.px, &w.vx, &D_00697880);

    scale = 0.5f * cam->fovRad;
    radiusFactor = 5.0f * radius / tanf(gp0xffff8070 * scale);
    w.dx = *(volatile f32*)&w.dx * radiusFactor;
    w.dy = w.dy * radiusFactor;
    w.dz = w.dz * radiusFactor;
    w.dz = w.pz + w.dz - w.vz;
    w.dy = w.py + w.dy - w.vy;
    w.dx = w.px + w.dx - w.vx;
    length = FUN_004c69f0(&w.dx, &w.dx);
    w.dx = w.dx * length;
    w.dy = w.dy * length;
    w.dz = w.dz * length;

    scale = 0.5f * cam->fovRad;
    factor = length * tanf(gp0xffff8070 * scale);
    horizFactor = factor * 0.1328125f;
    w.sx = w.dx;
    w.sz = w.dz;
    FUN_004c6b20(&w.sx, &w.sx);
    w.vx = w.vx - w.sz * horizFactor;
    w.vz = w.sx * horizFactor + w.vz;

    w.outX = w.vx + w.dx;
    w.outY = w.vy + w.dy;
    w.outZ = w.vz + w.dz;
    if (w.outY < 25.0f) {
        w.outY = 25.0f;
    }
    FUN_002a2170(cam, &w.outX);
    FUN_002a3e80(50.0f, (u8*)cam->action, (u8*)&w.center1,
                 (u8*)&w.center2, 5);
}

// FUN_002b55d0

void FUN_002b55d0(void)

{
  FUN_00351bb0(8);
  return;
}


// FUN_002b5600
void FUN_002b5600(void* param_1)

{
  u8 auStack_20[32];

  FUN_002add10(param_1,0,0,auStack_20);
  FUN_002a2170((u16*)param_1,auStack_20);
  return;
}

// FUN_002b5650

void FUN_002b5650(int param_1)

{
  *(float *)(param_1 + 0x100) = (float)FUN_002ffbc0(0x168);
  FUN_002a3e80(0.0f, (u8 *)(uintptr_t)*(int *)(param_1 + 0xe0), 0, 0, 0x40);
}

// FUN_002b56e0 NONMATCHING

void FUN_002b56e0(u8* param_1)
{
  BtlUnit* unit;
  RwV3d spB0;
  RwV3d spA0;
  RwV3d sp90;
  struct {
    f32 outX;
    f32 outY;
    f32 outZ;
    u8 quat[16];
  } scratch;
  RwMatrix sp30;

  unit = *(BtlUnit **)(*(int *)(iGpffffb6fc + 0x148) + 0x30);
  FUN_0027ffb0(unit, &spB0);
  spB0.y = 0.0f;
  RtQuatTransformVectors(&sp90, &D_00697890, 1, &unit->rot);
  RwMatrixRotate(&sp30, &D_00697880, -52.5f, rwCOMBINEREPLACE);
  FUN_004c6c60(&spA0, &sp90, &sp30);
  spA0.x = spA0.x * 80.0f;
  spA0.y = spA0.y * 80.0f;
  spA0.z = spA0.z * 80.0f;
  spB0.x = spB0.x + spA0.x;
  spB0.y = spB0.y + spA0.y;
  spB0.z = spB0.z + spA0.z;
  RwMatrixRotate(&sp30, &D_00697870, -30.0f, rwCOMBINEREPLACE);
  RwMatrixRotate(&sp30, &D_00697880, *(f32 *)(param_1 + 0x100), rwCOMBINEPOSTCONCAT);
  FUN_004c6c60(&spA0, &D_00697890, &sp30);
  scratch.outX = spB0.x + 400.0f * spA0.x;
  scratch.outY = spB0.y + 400.0f * spA0.y;
  scratch.outZ = spB0.z + 400.0f * spA0.z;
  FUN_002a4690(scratch.quat, &scratch.outX, &spB0, &D_00697880);
  if (scratch.outY < 25.0f) {
    scratch.outY = 25.0f;
  }
  *(f32 *)(param_1 + 0x100) = *(f32 *)(param_1 + 0x100) + 0.25f;
  FUN_002a3e80(0.0f, 0, 0, 0, 4);
  FUN_002a2170(param_1, &scratch.outX);
}

// FUN_002b58f0 NONMATCHING

void FUN_002b58f0(BtlCamera* param_1)
{
    int iVar1;
    f32 fVar2;
    f32 fVar3;
    f32 fVar4;
    f32 quatW;
    f32 quatZ;
    f32 quatY;
    f32 quatX;
    struct {
        f32 fStack_40;
        f32 fStack_44;
        f32 fStack_48;
        f32 qSlot4c;
        f32 qSlot50;
        f32 qSlot54;
        f32 qSlot58;
        f32 fStack_5c;
        f32 fStack_60;
        f32 fStack_64;
        RtQuat quat;
        u8 pad_38[8];
        RwMatrix matrix;
        u8 pad_80[8];
        f32 fStack_c8;
        f32 fStack_cc;
        f32 fStack_d0;
        f32 fStack_d4;
        f32 fStack_d8;
        u8 pad_9c[4];
        f32 fStack_e0;
        f32 fStack_e4;
        f32 fStack_e8;
        u8 pad_ac[4];
        f32 fStack_f0;
        f32 fStack_f4;
        f32 fStack_f8;
        u8 pad_bc[4];
        f32 fStack_100;
        f32 fStack_104;
        f32 fStack_108;
        u8 pad_cc[4];
        f32 fStack_110;
        f32 fStack_114;
        f32 fStack_118;
    } work;
    #define fStack_40 work.fStack_40
    #define fStack_44 work.fStack_44
    #define fStack_48 work.fStack_48
    #define fStack_5c work.fStack_5c
    #define fStack_4c work.qSlot4c
    #define fStack_50 work.qSlot50
    #define fStack_54 work.qSlot54
    #define fStack_58 work.qSlot58
    #define fStack_60 work.fStack_60
    #define fStack_64 work.fStack_64
    #define fStack_c8 work.fStack_c8
    #define fStack_cc work.fStack_cc
    #define fStack_d0 work.fStack_d0
    #define fStack_d4 work.fStack_d4
    #define fStack_d8 work.fStack_d8
    #define fStack_e0 work.fStack_e0
    #define fStack_e4 work.fStack_e4
    #define fStack_e8 work.fStack_e8
    #define fStack_f0 work.fStack_f0
    #define fStack_f4 work.fStack_f4
    #define fStack_f8 work.fStack_f8
    #define fStack_100 work.fStack_100
    #define fStack_104 work.fStack_104
    #define fStack_108 work.fStack_108
    #define fStack_110 work.fStack_110
    #define fStack_114 work.fStack_114
    #define fStack_118 work.fStack_118
    #define matrix work.matrix
    #define quat work.quat
    extern void FUN_004c31b0(RwMatrix* mat, const RwV3d* axis, f32 angle, s32 mode);
    extern void FUN_004be1e0(RwV3d* out, const RwV3d* basis, s32 mode, void* source);

    iVar1 = *(int *)(*(int *)(iGpffffb6fc + 0x148) + 0x30);
    fVar2 = FUN_00280870(3, 1, &fStack_d0, 0, 0, 1);
    fVar3 = 550.0f;
    if (fVar2 < fVar3)
    {
        fVar2 = fVar3;
    }
    FUN_00280050(iVar1, &fStack_110);
    fStack_100 = fStack_110 - fStack_d0;
    fStack_104 = fStack_114 - fStack_d4;
    fStack_108 = fStack_118 - fStack_d8;
    fVar3 = FUN_004c69f0(&fStack_100, &fStack_100);
    fVar4 = 0.25f * fVar3;
    fVar3 = fVar4;
    fStack_f0 = fStack_100 * fVar3;
    fStack_f4 = fStack_104 * fVar3;
    fStack_f8 = fStack_108 * fVar3;
    fStack_e0 = fStack_d0 + fStack_f0;
    fStack_e4 = fStack_d4 + fStack_f4;
    fStack_e8 = fStack_d8 + fStack_f8;
    fVar2 = fVar2 * fGpffff807c;
    fVar3 = FUN_0052e930(gp0xffff8070 * (0.5f * param_1->fovRad));
    fVar3 = fVar2 / fVar3;
    FUN_004c31b0(&matrix, &D_00697870, 32.5f, 0);
    FUN_004c6c60((RwV3d*)&fStack_f0, &D_006978A0, &matrix);
    FUN_004be1e0((RwV3d*)&fStack_100, (const RwV3d*)&fStack_f0, 1,
                 (u8*)iVar1 + 0x1c);
    fStack_110 = fStack_100 * fVar2;
    fStack_114 = fStack_104 * fVar2;
    fStack_118 = fStack_108 * fVar2;
    fStack_110 = fStack_110 + fStack_d0;
    fStack_114 = fStack_114 + fStack_d4;
    fStack_118 = fStack_118 + fStack_d8;
    FUN_002a4690(&quat, &fStack_110, &fStack_e0, &D_00697880);
    FUN_004be1e0((RwV3d*)&fStack_f0, &D_006978A0, 1, &quat);
    fStack_100 = fStack_f0 * fVar3;
    fStack_104 = fStack_f4 * fVar3;
    fStack_108 = fStack_f8 * fVar3;
    fVar2 = fVar3 * FUN_0052e930(gp0xffff8070 * (0.5f * param_1->fovRad));
    fVar2 = fVar2 * 0.21875f;
    fVar2 = fVar2 * fGpffff807c;
    fStack_c8 = fStack_100;
    fStack_cc = fStack_108;
    FUN_004c6b20(&fStack_c8, &fStack_c8);
    fStack_e0 = fStack_e0 + fStack_cc * fVar2;
    fStack_e8 = fStack_e8 - fStack_c8 * fVar2;
    fStack_5c = fStack_e0 + fStack_100;
    fStack_60 = fStack_e4 + fStack_104;
    fStack_64 = fStack_e8 + fStack_108;
    quatX = quat.imag.x;
    quatY = quat.imag.y;
    quatZ = quat.imag.z;
    quatW = quat.real;
    fStack_58 = quatW;
    fStack_54 = quatZ;
    fStack_50 = quatY;
    fStack_4c = quatX;
    fVar3 = fVar3 - 100.0f;
    fStack_100 = fStack_f0 * fVar3;
    fStack_104 = fStack_f4 * fVar3;
    fStack_108 = fStack_f8 * fVar3;
    fStack_40 = fStack_e0 + fStack_100;
    fStack_44 = fStack_e4 + fStack_104;
    fStack_48 = fStack_e8 + fStack_108;
    FUN_002a3e80(0.0f, 0, 0, 0, 0x40);
    FUN_002a3590(&fStack_40, &fStack_40);
    FUN_002a3590(&fStack_5c, &fStack_5c);
    FUN_002a2290((u16*)param_1, (RwV3d*)&fStack_40, (RwV3d*)&fStack_5c, 1);
    FUN_002a3110((u16*)param_1, 3.0f);
    #undef fStack_40
    #undef fStack_44
    #undef fStack_48
    #undef fStack_4c
    #undef fStack_50
    #undef fStack_54
    #undef fStack_58
    #undef fStack_5c
    #undef fStack_60
    #undef fStack_64
    #undef fStack_c8
    #undef fStack_cc
    #undef fStack_d0
    #undef fStack_d4
    #undef fStack_d8
    #undef fStack_e0
    #undef fStack_e4
    #undef fStack_e8
    #undef fStack_f0
    #undef fStack_f4
    #undef fStack_f8
    #undef fStack_100
    #undef fStack_104
    #undef fStack_108
    #undef fStack_110
    #undef fStack_114
    #undef fStack_118
    #undef matrix
    #undef quat
}

// FUN_002b5cd0
void FUN_002b5cd0(BtlCamera* camera)
{
    struct {
        f32 sp40;
        f32 sp44;
        f32 sp48;
        f32 sp4C;
        f32 sp50;
        f32 sp54;
        f32 sp58;
        f32 sp5C;
        f32 sp60;
        f32 sp64;
        RtQuat sp68;
        u8 pad_to_80[8];
        RwMatrix sp80;
        u8 pad_to_C8[8];
        f32 spC8;
        f32 spCC;
        f32 spD0;
        f32 spD4;
        f32 spD8;
        f32 pad_to_E0_2[1];
        f32 spE0;
        f32 spE4;
        f32 spE8;
        f32 pad_to_F0[1];
        f32 spF0;
        f32 spF4;
        f32 spF8;
        f32 pad_to_100[1];
        f32 sp100;
        f32 sp104;
        f32 sp108;
        f32 pad_to_110[1];
        f32 sp110;
        f32 sp114;
        f32 sp118;
        f32 pad_tail;
    } stack;
#define sp40 stack.sp40
#define sp44 stack.sp44
#define sp48 stack.sp48
#define sp4C stack.sp4C
#define sp50 stack.sp50
#define sp54 stack.sp54
#define sp58 stack.sp58
#define sp5C stack.sp5C
#define sp60 stack.sp60
#define sp64 stack.sp64
#define sp68 stack.sp68
#define sp80 stack.sp80
#define spC8 stack.spC8
#define spCC stack.spCC
#define spD0 stack.spD0
#define spD4 stack.spD4
#define spD8 stack.spD8
#define spE0 stack.spE0
#define spE4 stack.spE4
#define spE8 stack.spE8
#define spF0 stack.spF0
#define spF4 stack.spF4
#define spF8 stack.spF8
#define sp100 stack.sp100
#define sp104 stack.sp104
#define sp108 stack.sp108
#define sp110 stack.sp110
#define sp114 stack.sp114
#define sp118 stack.sp118
    f32 var_f21;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f5;
    f32 temp_f6;
    BtlUnit* work;
    f32 temp_e4;

    work = *(BtlUnit**)(*(int *)(DAT_007ce3ec + 0x148) + 0x30);
    var_f21 = FUN_00280870(2, 1, &spD0, 0, 0, 1);
    FUN_00280050(work, &sp110);
    sp100 = sp110 - spD0;
    sp104 = sp114 - spD4;
    sp108 = sp118 - spD8;
    temp_f1 = DAT_007cada4 * RwV3dNormalize((RwV3d*)&sp100, (RwV3d*)&sp100);
    temp_f3 = sp100 * temp_f1;
    spF0 = temp_f3;
    temp_f2 = sp104 * temp_f1;
    spF4 = temp_f2;
    temp_f1_2 = sp108 * temp_f1;
    spF8 = temp_f1_2;
    spE0 = spD0 + temp_f3;
    spE4 = spD4 + temp_f2;
    spE8 = spD8 + temp_f1_2;
    if (var_f21 < 450.0f)
    {
        var_f21 = 450.0f;
    }
    temp_f20 = var_f21 / tanf(DAT_007cad60 * (0.5f * camera->fovRad));
    RwMatrixRotate(&sp80, &D_00697870, 35.0f, rwCOMBINEREPLACE);
    FUN_004c6c60((RwV3d*)&spF0, &D_006978A0, &sp80);
    RtQuatTransformVectors((RwV3d*)&sp100, (RwV3d*)&spF0, 1,
                           &work->rot);
    sp110 = sp100 * var_f21;
    sp114 = sp104 * var_f21;
    sp118 = sp108 * var_f21;
    FUN_002a4690(&sp68, &sp110, &spE0, &D_00697880);
    RtQuatTransformVectors((RwV3d*)&spF0, &D_006978A0, 1, &sp68);
    temp_f1_3 = 50.0f + temp_f20;
    temp_f0 = spF0 * temp_f1_3;
    sp100 = temp_f0;
    sp104 = spF4 * temp_f1_3;
    temp_f0_2 = spF8 * temp_f1_3;
    sp108 = temp_f0_2;
    temp_f1_4 = temp_f20 * tanf(DAT_007cad60 * (0.5f * camera->fovRad));
    temp_f1_4 *= 0.21875f;
    temp_f1_4 *= DAT_007cad6c;
    spC8 = sp100;
    spCC = sp108;
    FUN_004c6b20(&spC8, &spC8);
    temp_f6 = (spE0 + 0.0f) + spCC * temp_f1_4;
    spE0 = temp_f6;
    temp_f5 = (spE8 + 0.0f) - spC8 * temp_f1_4;
    spE8 = temp_f5;
    sp5C = temp_f6 + sp100;
    temp_e4 = spE4;
    sp60 = temp_e4 + sp104;
    sp64 = temp_f5 + sp108;
    *(RtQuat*)&sp4C = sp68;
    temp_f1_5 = temp_f20 - 50.0f;
    temp_f3_2 = spF0 * temp_f1_5;
    sp100 = temp_f3_2;
    temp_f2_2 = spF4 * temp_f1_5;
    sp104 = temp_f2_2;
    temp_f0_2 = spF8 * temp_f1_5;
    sp108 = temp_f0_2;
    sp40 = temp_f6 + temp_f3_2;
    sp44 = temp_e4 + temp_f2_2;
    sp48 = temp_f5 + temp_f0_2;
    FUN_002a3e80(0.0f, 0, 0, 0, 0x40);
    FUN_002a2290((u16*)camera, (RwV3d*)&sp40, (RwV3d*)&sp5C, 1);
    FUN_002a3110((u16*)camera, 3.5f);
}
#undef sp40
#undef sp44
#undef sp48
#undef sp4C
#undef sp50
#undef sp54
#undef sp58
#undef sp5C
#undef sp60
#undef sp64
#undef sp68
#undef sp80
#undef spC8
#undef spCC
#undef spD0
#undef spD4
#undef spD8
#undef spE0
#undef spE4
#undef spE8
#undef spF0
#undef spF4
#undef spF8
#undef sp100
#undef sp104
#undef sp108
#undef sp110
#undef sp114
#undef sp118

// FUN_002b6070 NONMATCHING

void FUN_002b6070(BtlCamera* camera, f32 param_1, f32 param_2)
{
    BtlUnit* unit;
    long random;
    f32 scale1;
    f32 scale2;
    f32 angle;
    f32 temp_f5;
    f32 temp_f1;
    f32 temp_f4;
    struct
    {
        RwV3d target1;
        u8 quat1[16];
        RwV3d target2;
        u8 quat2[24];
        RwMatrix matrix;
        RwV3d base;
        u8 basePad[4];
        RwV3d direction;
        u8 directionPad[4];
        RwV3d scaled;
    } work;

    unit = camera->action->unit;
    random = FUN_00300580_b6070(unit->datUnit, 0x100000);
    FUN_00280130_b6070(unit, &work.base);
    if (random == 0)
    {
        work.base.y = unit->unk_8c * unit->scale * fGpffff806c + work.base.y + 0.0f;
    }
    else
    {
        work.base.y = (work.base.y + 0.0f) -
                      unit->unk_8c * unit->scale * fGpffff806c;
    }
    FUN_004be1e0_b6070(&work.direction, &D_00697890, 1, &unit->rot);
    temp_f5 = 200.0f * work.direction.x;
    work.scaled.x = temp_f5;
    temp_f1 = 200.0f * work.direction.y;
    work.scaled.y = temp_f1;
    temp_f4 = 200.0f * work.direction.z;
    work.scaled.z = temp_f4;
    work.direction.x = (work.base.x + temp_f5) - work.base.x;
    work.direction.y = (work.base.y + temp_f1 + 75.0f) - work.base.y;
    work.direction.z = (work.base.z + temp_f4) - work.base.z;
    FUN_004c69f0_b6070(&work.direction, &work.direction);

    angle = unit->sphereRadius * unit->scale;
    if (angle < 75.0f)
    {
        angle = 75.0f;
    }
    scale1 = angle * param_1;
    scale2 = angle * param_2;

    random = FUN_002ffbc0(2);
    if ((random == 1) || (random != 0))
    {
        angle = -30.0f;
    }
    else
    {
        angle = 30.0f;
    }
    FUN_004c31b0_b6070(&work.matrix, &D_00697880, -angle * 0.5f, 0);
    FUN_004c6c60_b6070(&work.scaled, &work.direction, &work.matrix);
    angle = FUN_0052e930(fGpffff8070 * camera->fovRad * 0.5f);
    scale1 = scale1 / angle;
    work.scaled.x = work.scaled.x * scale1;
    work.scaled.y = work.scaled.y * scale1;
    work.scaled.z = work.scaled.z * scale1;
    work.target1.x = work.base.x + work.scaled.x;
    work.target1.y = work.base.y + work.scaled.y;
    work.target1.z = work.base.z + work.scaled.z;
    FUN_002a4690_b6070(work.quat1, &work.target1, &work.base, &D_00697880);

    FUN_004c31b0_b6070(&work.matrix, &D_00697880, angle * 0.5f, 0);
    FUN_004c6c60_b6070(&work.scaled, &work.direction, &work.matrix);
    angle = FUN_0052e930(fGpffff8070 * camera->fovRad * 0.5f);
    scale2 = scale2 / angle;
    work.scaled.x = work.scaled.x * scale2;
    work.scaled.y = work.scaled.y * scale2;
    work.scaled.z = work.scaled.z * scale2;
    work.target2.x = work.base.x + work.scaled.x;
    work.target2.y = work.base.y + work.scaled.y;
    work.target2.z = work.base.z + work.scaled.z;
    FUN_002a4690_b6070(work.quat2, &work.target2, &work.base, &D_00697880);

    if (work.target1.y < 25.0f)
    {
        work.target1.y = 25.0f;
    }
    if (work.target2.y < 25.0f)
    {
        work.target2.y = 25.0f;
    }
    FUN_002a2290_b6070(camera, &work.target1, &work.target2, 1);
    FUN_002a3110_b6070(camera, 3.0f);
}

// FUN_002b6460

void FUN_002b6460(BtlCamera* camera)
{
  FUN_002b6070(camera, DAT_007cad64, DAT_007cad68);
  return;
}

// FUN_002b6490

void FUN_002b6490(void)

{
  FUN_00521250(DAT_00694c90,DAT_006941d4,0xf4);
  return;
}

typedef struct B64CameraWork {
  BtlAction *firstAction;
  BtlAction *secondAction;
  u16 unk_08;
  s16 index;
  u16 frame;
  u16 flags;
  u16 *entries;
} B64CameraWork;

typedef struct B64CameraEntry {
  s16 duration;
  u16 mode;
  f32 firstX;
  f32 firstY;
  f32 firstZ;
  f32 firstX2;
  f32 firstY2;
  f32 firstZ2;
  u16 targetMode;
  u16 pad_1e;
  f32 secondX;
  f32 secondY;
  f32 secondZ;
  f32 secondX2;
  f32 secondY2;
  f32 secondZ2;
  f32 angle;
} B64CameraEntry;

typedef struct B64CameraScratch {
  RwV3d firstOut;
  RwV3d secondOut;
  u8 pad_18[8];
  RwV3d rotatedFirst;
  RwV3d rotatedSecond;
  u8 pad_38[8];
  RtQuat rotation;
  RwMatrix matrix;
  RwV3d firstPos;
  u8 firstResult[16];
  RwV3d secondPos;
  u8 secondResult[24];
  RwV3d relativeSecond;
  u8 pad_dc[4];
  RwV3d relativeFirst;
  u8 pad_ec[4];
  u64 matrixLow;
  f32 matrixHigh;
  u8 pad_fc[4];
  RwV3d firstVector;
  u8 pad_10c[4];
  RwV3d secondVector;
  u8 pad_11c[4];
  RwV3d sphereBase;
  u8 pad_12c[4];
  RwV3d sphereVector;
  u8 pad_13c[4];
} B64CameraScratch;

#pragma alias FUN_002d1de0_b64d0 FUN_002d1de0
extern void FUN_002d1de0_b64d0(RtQuat *out, const RwV3d *from, const RwV3d *to);
#pragma alias FUN_002802d0_b64d0 FUN_002802d0
extern void FUN_002802d0_b64d0(BtlUnit *first, BtlUnit *second, RwV3d *out);
#pragma alias FUN_004be1e0_b64d0 FUN_004be1e0
extern void FUN_004be1e0_b64d0(RwV3d *out, const RwV3d *in, s32 count, const RtQuat *rotation);
#pragma alias FUN_00280130_b64d0 FUN_00280130
extern void FUN_00280130_b64d0(BtlUnit *unit, RwV3d *out);
#pragma alias FUN_00280200_b64d0 FUN_00280200
extern void FUN_00280200_b64d0(BtlUnit *unit, BtlUnitAnimBounds *bounds, RwV3d *out);
#pragma alias FUN_004c6c60_b64d0 FUN_004c6c60
extern void FUN_004c6c60_b64d0(void *out, const RwV3d *in, const RwMatrix *matrix);
extern BtlUnitAnimBounds *func_002fc520(BtlUnit *unit);

// FUN_002b64d0 NONMATCHING
u32 FUN_002b64d0(int param_1, int param_2)
{
  B64CameraEntry *entry;
  B64CameraScratch scratch;
  BtlUnitAnimBounds *bounds;
  BtlUnit *unit;
  u16 *entries;
  s16 index;
  s16 nextIndex;
  u16 radiusBits;
  f32 radius;
  u16 *camera;
  B64CameraWork *work;

  camera = (u16 *)(uintptr_t)param_1;
  work = (B64CameraWork *)(uintptr_t)param_2;
  if (FUN_002b6bd0(param_2) != 0) {
    goto active;
  }
  goto return_zero;
active:
  entries = work->entries;
  index = work->index;
  if (entries != 0) {
    goto entries_ok;
  }
  goto return_zero;
entries_ok:
  if (index < 4) {
    goto index_ok;
  }
  goto return_zero;
index_ok:
  if (index != -1) {
    if (work->frame < *(s16 *)((u8 *)entries + index * 0x3c + 4)) {
      goto increment_frame;
    }
  }
  nextIndex = index + 1;
  if (nextIndex >= (s16)entries[0]) {
    goto disable;
  }
  if (work->firstAction == 0) {
    goto disable;
  }
  if (btlActionFindByUnit(work->firstAction->unit) == 0) {
    goto disable;
  }
  if (work->secondAction == 0) {
    goto disable;
  }
  if (btlActionFindByUnit(work->secondAction->unit) == 0) {
    goto disable;
  }

  entry = (B64CameraEntry *)((u8 *)entries + nextIndex * 0x3c + 4);
  if ((work->flags & 0x10) == 0) {
    FUN_002d1de0_b64d0(&scratch.rotation, &work->firstAction->unit->pos,
                       &work->secondAction->unit->pos);
  }
  else {
    FUN_002802d0_b64d0(work->firstAction->unit, work->secondAction->unit,
                       &scratch.relativeFirst);
    FUN_002802d0_b64d0(work->secondAction->unit, work->firstAction->unit,
                       &scratch.relativeSecond);
    FUN_002d1de0_b64d0(&scratch.rotation, &scratch.relativeFirst,
                       &scratch.relativeSecond);
  }

  scratch.firstVector.x = entry->firstX;
  scratch.firstVector.y = entry->firstY;
  scratch.firstVector.z = entry->firstZ;
  scratch.secondVector.x = entry->firstX2;
  scratch.secondVector.y = entry->firstY2;
  scratch.secondVector.z = entry->firstZ2;
  if ((work->flags & 2) != 0) {
    scratch.firstVector.x = scratch.firstVector.x * -1.0f;
    scratch.secondVector.x = scratch.secondVector.x * -1.0f;
  }
  if (entry->mode == 1) {
    unit = work->firstAction->unit;
    FUN_004be1e0_b64d0(&scratch.rotatedFirst, &scratch.firstVector, 1,
                       &scratch.rotation);
    FUN_004be1e0_b64d0(&scratch.rotatedSecond, &scratch.secondVector, 1,
                       &scratch.rotation);
    scratch.firstPos.x = unit->pos.x + scratch.rotatedFirst.x;
    scratch.firstPos.y = unit->pos.y + scratch.rotatedFirst.y;
    scratch.firstPos.z = unit->pos.z + scratch.rotatedFirst.z;
    scratch.secondPos.x = unit->pos.x + scratch.rotatedSecond.x;
    scratch.secondPos.y = unit->pos.y + scratch.rotatedSecond.y;
    scratch.secondPos.z = unit->pos.z + scratch.rotatedSecond.z;
  }

  scratch.firstVector.x = entry->secondX;
  scratch.firstVector.y = entry->secondY;
  scratch.firstVector.z = entry->secondZ;
  scratch.secondVector.x = entry->secondX2;
  scratch.secondVector.y = entry->secondY2;
  scratch.secondVector.z = entry->secondZ2;
  if ((work->flags & 2) != 0) {
    scratch.firstVector.x = scratch.firstVector.x * -1.0f;
    scratch.secondVector.x = scratch.secondVector.x * -1.0f;
  }
  switch (entry->targetMode) {
  case 1:
    unit = work->firstAction->unit;
    FUN_004be1e0_b64d0(&scratch.rotatedFirst, &scratch.firstVector, 1,
                       &scratch.rotation);
    FUN_004be1e0_b64d0(&scratch.rotatedSecond, &scratch.secondVector, 1,
                       &scratch.rotation);
    scratch.firstOut.x = unit->pos.x + scratch.rotatedFirst.x;
    scratch.firstOut.y = unit->pos.y + scratch.rotatedFirst.y;
    scratch.firstOut.z = unit->pos.z + scratch.rotatedFirst.z;
    scratch.secondOut.x = unit->pos.x + scratch.rotatedSecond.x;
    scratch.secondOut.y = unit->pos.y + scratch.rotatedSecond.y;
    scratch.secondOut.z = unit->pos.z + scratch.rotatedSecond.z;
    break;
  case 2:
    unit = work->secondAction->unit;
    bounds = func_002fc520(unit);
    if (bounds == 0) {
      FUN_00280130_b64d0(unit, &scratch.sphereBase);
      FUN_004be1e0_b64d0(&scratch.sphereVector, &D_006978A0, 1,
                         &scratch.rotation);
      radius = unit->sphereRadius * unit->scale;
    }
    else {
      FUN_00280200_b64d0(unit, bounds, &scratch.sphereBase);
      FUN_004be1e0_b64d0(&scratch.sphereVector, &D_006978A0, 1,
                         &scratch.rotation);
      radiusBits = bounds->radius;
      if ((s16)radiusBits >= 0) {
        radius = (f32)radiusBits;
      }
      else {
        radius = (f32)((radiusBits >> 1) | (radiusBits & 1));
        radius = radius + radius;
      }
      radius = radius * unit->scale;
    }
    scratch.firstOut.x = scratch.sphereBase.x + scratch.sphereVector.x * radius;
    scratch.firstOut.y = scratch.sphereBase.y + scratch.sphereVector.y * radius;
    scratch.firstOut.z = scratch.sphereBase.z + scratch.sphereVector.z * radius;
    if (scratch.firstOut.y < 100.0f) {
      scratch.firstOut.y = 100.0f;
    }
    else {
      if ((work->flags & 8) != 0) {
        if (250.0f < scratch.firstOut.y) {
          scratch.firstOut.y = 250.0f;
        }
      }
      else if (((work->flags & 4) != 0) && (150.0f < scratch.firstOut.y)) {
        scratch.firstOut.y = 150.0f;
      }
    }
    scratch.secondOut.x = scratch.firstOut.x;
    scratch.secondOut.y = scratch.firstOut.y;
    scratch.secondOut.z = scratch.firstOut.z;
    break;
  }

  FUN_002a4690(&scratch.firstResult, &scratch.firstPos, &scratch.firstOut,
               &D_00697880);
  if (entry->angle == 0.0f) {
    goto no_rotate;
  }
  RwMatrixRotate(&scratch.matrix, &D_00697890, entry->angle, rwCOMBINEREPLACE);
  FUN_004c6c60_b64d0(&scratch.matrixLow, &D_00697880, &scratch.matrix);
  goto rotate_done;
no_rotate:
  scratch.matrixLow = *(u64 *)(uintptr_t)&D_00697880;
  scratch.matrixHigh = DAT_00697888;
rotate_done:
  FUN_002a4690(&scratch.secondResult, &scratch.secondPos, &scratch.secondOut,
               &scratch.matrixLow);
  FUN_002a2290(camera, &scratch.firstPos, &scratch.secondPos, 1);
  FUN_002a3110(camera, (f32)entry->duration / 30.0f);
  work->index = nextIndex;
  work->frame = 0;
  goto increment;

disable:
  work->flags = work->flags & 0xfffe;
  goto increment;
increment_frame:
  work->frame = work->frame + 1;
increment:
  work->unk_08 = work->unk_08 + 1;
  return 1;
return_zero:
  return 0;
}

// FUN_002b6bd0

u32 FUN_002b6bd0(int param_1)

{
  return (*(u16 *)(param_1 + 0xe) & 1) != 0;
}

// FUN_002b6bf0

void FUN_002b6bf0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,u32 param_4,
                 u16 param_5)

{
  u32 uVar1;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[4] = param_4;
  *(undefined2 *)(param_1 + 2) = 0;
  *(short *)((int)param_1 + 10) = -1;
  *(undefined2 *)(param_1 + 3) = 0;
  *(u16 *)((int)param_1 + 0xe) = *(u16 *)((int)param_1 + 0xe) | 1;
  *(u16 *)((int)param_1 + 0xe) = *(u16 *)((int)param_1 + 0xe) & 0xfffd;
  if (((param_5 & 1) != 0) && !(FUN_002ffbc0(100) < 0x32)) {
    *(u16 *)((int)param_1 + 0xe) = *(u16 *)((int)param_1 + 0xe) | 2;
  }
  if ((param_5 & 2) != 0) {
    *(u16 *)((int)param_1 + 0xe) = *(u16 *)((int)param_1 + 0xe) | 4;
  }
  if ((param_5 & 4) != 0) {
    *(u16 *)((int)param_1 + 0xe) = *(u16 *)((int)param_1 + 0xe) | 8;
  }
  if ((param_5 & 8) != 0) {
    *(u16 *)((int)param_1 + 0xe) = *(u16 *)((int)param_1 + 0xe) | 0x10;
  }
  return;
}

// FUN_002b6cd0
u8* FUN_002b6cd0(int param_1)
{
  u16 *puVar1;
  short sVar2;
  u16 counter;
  short frame;

  if ((*(u16 *)(param_1 + 0xe) & 1) == 0) {
    puVar1 = (u16 *)0x0;
  }
  else {
    puVar1 = *(u16 **)(param_1 + 0x10);
    sVar2 = *(short *)(param_1 + 10);
    if (puVar1 == (u16 *)0x0) {
      puVar1 = (u16 *)0x0;
    }
    else {
      if (sVar2 == -1) {
        goto increment_index;
      }
      counter = *(u16 *)(param_1 + 0xc);
      frame = puVar1[sVar2 * 0x1e + 2];
      if (counter < frame) {
        goto after_increment;
      }
increment_index:
      sVar2++;
after_increment:
      if (*puVar1 > sVar2) {
        goto check_index;
      }
      puVar1 = (u16 *)0x0;
      goto done;
check_index:
      if (sVar2 < 4) {
        goto make_pointer;
      }
      puVar1 = (u16 *)0x0;
      goto done;
make_pointer:
      puVar1 = puVar1 + sVar2 * 0x1e + 2;
done:
      ;
    }
  }
  return (u8*)puVar1;
}

// FUN_002b6db0

void FUN_002b6db0(int param_1)

{
  FUN_00521408(param_1,0,0x14);
  return;
}

// FUN_002b6de0

void FUN_002b6de0(unsigned short *param_1)
{
  int iVar1;
  float fVar2;
  float fVar3;

  FUN_00521408(param_1,0,8);
  for (iVar1 = *(int *)(iGpffffb6fc + 0x15c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xa30)) {
    if (FUN_0030b5a0(*(undefined4 *)(iVar1 + 0xa2c),0) != 0) {
      continue;
    }
    fVar3 = *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c);
    fVar2 = *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c);
    if (fVar2 <= 200.0f) {
      if (fVar3 <= 75.0f) {
        param_1[0] = param_1[0] + 1;
      }
      else if (fVar3 <= 125.0f) {
        param_1[1] = param_1[1] + 1;
      }
      else if (fVar3 <= 200.0f) {
        param_1[2] = param_1[2] + 1;
      }
    }
    else if (fVar2 <= 300.0f) {
      if (fVar3 <= 125.0f) {
        param_1[1] = param_1[1] + 1;
      }
      else if (fVar3 <= 200.0f) {
        param_1[2] = param_1[2] + 1;
      }
    }
    else {
      param_1[2] = param_1[2] + 1;
    }
    param_1[3] = param_1[3] + 1;
  }
}

// FUN_002b6f70

u32 FUN_002b6f70(u16 *param_1)
{
  u8 *base;
  u8 *entry;
  u32 i;

  i = 0;
  base = D_00694F10;
  for (; (i & 0xffff) < 0x18U; i = (u16)(i + 1)) {
    entry = base + (u16)i * 0xe0;
    if (param_1[0] > *(u16 *)(entry + 0xd8)) continue;
    if (param_1[1] > *(u16 *)(entry + 0xda)) continue;
    if (param_1[2] > *(u16 *)(entry + 0xdc)) continue;
    return i;
  }
  return 0x17;
}


// FUN_002b7000
void FUN_002b7000(int param_1,u32 param_2,undefined4 param_3)
{
  u8 mode = *(u8 *)(param_1 + 0xa2);
  volatile u8 *table;
  switch (mode) {
  case 0:
    table = DAT_007ce3ec;
    *(undefined4 *)((volatile u8 *)(uintptr_t)((param_2 & 0xffff) * 4) +
                    (uintptr_t)table + 0xa3c) = param_3;
    break;
  case 1:
    table = DAT_007ce3ec;
    *(undefined4 *)((volatile u8 *)(uintptr_t)((param_2 & 0xffff) * 4) +
                    (uintptr_t)table + 0xa4c) = param_3;
    break;
  }
}

// FUN_002b7060 NONMATCHING

#pragma opt_loop_invariants on
s16 FUN_002b7060(void)
{
  u16 vals[3];
  char buf[264];
  u32 t0;
  long t1;
  u8 *entry;

  if (FUN_002fa240() == 1) {
    return -1;
  }
  FUN_002b6de0(vals);
  if (((3 < vals[2]) || ((vals[2] == 3 && ((0 < vals[1] || (0 < vals[0])))))) ||
     ((vals[2] == 2 && ((1 < vals[1] || (2 < vals[0])))))) {
    FUN_00523ac8(buf,D_00696410,*(u16 *)(*(int *)(iGpffffb6fc + 0xbbc) + 8),vals[2]
                 ,vals[1],vals[0]);
    FUN_0019d400(buf,D_00696430,0x16e);
  }
  for (t0 = 0; (u16)t0 < 0x18; t0 = (u16)(t0 + 1)) {
    t1 = (u16)t0;
    entry = D_00694F10 + (u16)t1 * 0xe0;
    if (vals[0] > *(u16 *)(entry + 0xd8)) continue;
    if (vals[1] > *(u16 *)(entry + 0xda)) continue;
    if (vals[2] > *(u16 *)(entry + 0xdc)) continue;
    return (s16)t1;
  }
  t1 = 0x17;
  return (s16)t1;
}
#pragma opt_loop_invariants off


// FUN_002b71e0 NONMATCHING

void FUN_002b71e0(void)
{
    struct
    {
        s8 message[0x100];
        RtQuat quat;
        u32 used[5];
        u8 pad1[4];
        u16 vals[4];
        RwV3d worldA;
        u8 pad2[4];
        RwV3d worldB;
        u8 pad3[4];
        f32 tmp[4];
    } work;
    u16 selected;
    u16 nextSlot;
    BtlUnit* iter;
    u16 slot;
    s64 result;
    u8* table;
    u16 battleId;
    BtlUnit* unit;
    u32 i;
    f32 minX;
    f32 minZ;
    f32 dx;
    f32 dz;
    f32 scale;

    work.tmp[1] = 0.0f;
    *(s16*)(DAT_007ce3ec + 0xa38) = -1;
    if (FUN_002fa240() == 1)
    {
        result = -1;
    }
    else
    {
        FUN_002b6de0(work.vals);
        if (work.vals[2] > 3 ||
            (work.vals[2] == 3 && ((s32)work.vals[1] > 0 || (s32)work.vals[0] > 0)) ||
            (work.vals[2] == 2 && (work.vals[1] > 1 || work.vals[0] > 2)))
        {
            battleId = *(u16*)(*(u8**)(DAT_007ce3ec + 0xbbc) + 8);
            FUN_00523ac8(work.message, D_00696410,
                         battleId, work.vals[2], work.vals[1], work.vals[0]);
            FUN_0019d400_b71e0(work.message, D_00696430, 0x16e);
        }
        result = (s16)FUN_002b6f70(work.vals);
    }
    if ((s16)result != -1)
    {
        FUN_00521408_b71e0(DAT_007ce3ec + 0xa3c, 0, 0x24);
        slot = 1;
        iter = *(BtlUnit**)(DAT_007ce3ec + 0x150);
        table = D_00694F10 + (u16)result * 0xe0;
        for (; iter != NULL; iter = iter->next)
        {
                unit = *(BtlUnit**)(*(u8**)(DAT_007ce3ec + 0x148) + 0x30);
                if (unit == iter)
                {
                    nextSlot = slot;
                    slot = 0;
                }
                else
                {
                    while (*(u8*)(table + (u32)slot * 0x18) == 0 && slot < 4)
                    {
                        slot = (u16)(slot + 1);
                    }
                    nextSlot = (u16)(slot + 1);
                }
                selected = slot;
                work.tmp[0] = *(f32*)(table + (u32)selected * 0x18 + 4);
                work.tmp[2] = *(f32*)(table + (u32)selected * 0x18 + 8);
                FUN_002d2280_b71e0(&iter->unk_94, &iter->unk_96, (RwV3d*)work.tmp);
                work.tmp[0] = (f32)(iter->unk_94 * 0x19 - 0x6d6);
                work.tmp[2] = (f32)(iter->unk_96 * 0x19 - 0x6d6);
                FUN_0027f650_b71e0(iter, (RwV3d*)work.tmp);
                if (iter->genus == 1)
                {
                    *(u32*)(DAT_007ce3ec + (u32)selected * 4 + 0xa4c) = 1;
                }
                else if (iter->genus == 0)
                {
                    *(u32*)(DAT_007ce3ec + (u32)selected * 4 + 0xa3c) = 1;
                }
                iter->unk_9f0 = (s8)slot;
                slot = nextSlot;
            }
        FUN_00521408_b71e0(work.used, 0, 0x14);
        iter = *(BtlUnit**)(DAT_007ce3ec + 0x158);
            for (; iter != NULL; iter = iter->next)
            {
                if (FUN_0030b5a0_b71e0(iter->datUnit, 0) == 0)
                {
                    selected = 5;
                    minX = 100000000.0f;
                    minZ = minX;
                    scale = iter->scale;
                    for (i = 0; i < 5; i = (i + 1) & 0xffff)
                    {
                        if (work.used[i] != 1 &&
                            *(u8*)(table + i * 0x18 + 0x60) != 0)
                        {
                            dx = *(f32*)(table + i * 0x18 + 0x70) -
                                 iter->sphereRadius * scale;
                            dz = *(f32*)(table + i * 0x18 + 0x74) -
                                 iter->unk_8c * scale;
                            if (dx < minX || dz < minZ)
                            {
                                minX = dx;
                                minZ = dz;
                                selected = (u16)i;
                            }
                        }
                    }
                    work.used[selected] = 1;
                    work.tmp[0] = *(f32*)(table + (u32)selected * 0x18 + 0x64);
                    work.tmp[2] = *(f32*)(table + (u32)selected * 0x18 + 0x68);
                    FUN_002d2280_b71e0(&iter->unk_94, &iter->unk_96, (RwV3d*)work.tmp);
                    work.tmp[0] = (f32)(iter->unk_94 * 0x19 - 0x6d6);
                    work.tmp[2] = (f32)(iter->unk_96 * 0x19 - 0x6d6);
                    FUN_0027f650_b71e0(iter, (RwV3d*)work.tmp);
                    if (iter->genus == 1)
                    {
                        *(u32*)(DAT_007ce3ec + (u32)selected * 4 + 0xa4c) = 1;
                    }
                    else if (iter->genus == 0)
                    {
                        *(u32*)(DAT_007ce3ec + (u32)selected * 4 + 0xa3c) = 1;
                    }
                    iter->unk_9f0 = (s8)selected;
                }
            }
        FUN_00280870(2, 1, &work.worldA, 0, 0, 1);
        FUN_0027ffb0_b71e0(*(BtlUnit**)(*(u8**)(DAT_007ce3ec + 0x148) + 0x30),
                     &work.worldB);
        iter = *(BtlUnit**)(DAT_007ce3ec + 0x154);
        for (; iter != NULL; iter = iter->prev)
        {
            FUN_0027ffb0_b71e0(iter, (RwV3d*)work.tmp);
            FUN_002d1de0_b71e0(&work.quat, (RwV3d*)work.tmp, &work.worldA);
            FUN_0027f680_b71e0(iter, &work.quat);
        }
        iter = *(BtlUnit**)(DAT_007ce3ec + 0x15c);
        for (; iter != NULL; iter = iter->prev)
        {
            FUN_0027ffb0_b71e0(iter, (RwV3d*)work.tmp);
            FUN_002d1de0_b71e0(&work.quat, (RwV3d*)work.tmp, &work.worldB);
            FUN_0027f680_b71e0(iter, &work.quat);
        }
        *(s16*)(DAT_007ce3ec + 0xa38) = (s16)result;
        *(s16*)(DAT_007ce3ec + 0xa3a) = FUN_002d4e10_b71e0(2, 0x80000);
    }
}

// FUN_002b77c0 NONMATCHING


void FUN_002b77c0(int param_1)

{
  int iVar1;
  int iVar3;
  u16 uVar3;
  u32 uVar4;
  u32 uVar5;
  u8 uVar6;
  float afStack_10 [3];
  undefined1 auStack_20 [16];
  undefined1 auStack_30 [16];

  if (*(char *)(param_1 + 0x9f0) < '\0') {
    uVar6 = *(u8 *)(param_1 + 0xa2);
    uVar5 = (u32)*(u16 *)((int)DAT_007ce3ec + 0xa38);
    switch (uVar6) {
    case 0:
      uVar3 = 0;
      iVar3 = uVar5 * 0xe0 + 0x694f10;
      goto cond;
inc:
      uVar3 = uVar3 + 1;
cond:
      uVar4 = (u32)uVar3;
      if (*(u8 *)(iVar3 + uVar4 * 0x18) != '\0') {
        switch (uVar6) {
        case 0:
          iVar1 = *(int *)((int)DAT_007ce3ec + uVar4 * 4 + 0xa3c);
          break;
        case 1:
          iVar1 = *(int *)((int)DAT_007ce3ec + uVar4 * 4 + 0xa4c);
          break;
        }
        if (iVar1 != 1) goto found;
      }
      if (uVar3 < 4) goto inc;
found:
      iVar3 = (u32)uVar3 * 0x18;
      iVar1 = (uVar5 & 0xffff) * 0xe0;
      afStack_10[0] = *(float *)(iVar3 + iVar1 + 0x694f14);
      afStack_10[2] = *(float *)(iVar3 + iVar1 + 0x694f18);
      FUN_002d2280_b77c0(param_1 + 0x94,param_1 + 0x96,afStack_10);
      FUN_0027f650(param_1,afStack_10);
      switch (*(u8 *)(param_1 + 0xa2)) {
      case 0:
        *(undefined4 *)(uVar4 * 4 + (int)DAT_007ce3ec + 0xa3c) = 1;
        break;
      case 1:
        *(undefined4 *)(uVar4 * 4 + (int)DAT_007ce3ec + 0xa4c) = 1;
        break;
      }
      *(char *)(param_1 + 0x9f0) = (char)uVar3;
      FUN_00280870(2,1,auStack_20,0,0,1);
      FUN_0027ffb0(param_1,afStack_10);
      FUN_002d1de0(auStack_30,afStack_10,auStack_20);
      FUN_0027f680(param_1,auStack_30);
      break;
    case 1:
      break;
    }
  }
  return;
}

// FUN_002b79e0

undefined4 FUN_002b79e0(int *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  RwV3d diff;
  RwV3d pos;
  f32 out[3];

  iVar1 = *param_1;
  iVar2 = param_1[1];
  FUN_00280390(iVar2,iVar1,out);
  diff.x = *(float *)(iVar1 + 4) - out[0];
  diff.y = 0.0f;
  diff.z = *(float *)(iVar1 + 0xc) - out[2];
  FUN_004c69f0(&diff,&diff);
  if ((diff.x == 0.0f) && (diff.z == 0.0f)) {
    return 1;
  }
  {
    iVar3 = FUN_00288da0(iVar2,9);
    fVar4 = (*(float *)(param_1 + 2) + 0.0f) - (float)(int)*(short *)(iVar3 + 4) * *(float *)(iVar2 + 0x2c);
    diff.x = diff.x * fVar4;
    diff.y = diff.y * fVar4;
    diff.z = diff.z * fVar4;
    if ((*(u16 *)(param_1 + 3) & 1) != 0) {
      pos.x = *(float *)(iVar1 + 4) + diff.x;
      pos.y = *(float *)(iVar1 + 8) + diff.y;
      pos.z = *(float *)(iVar1 + 0xc) + diff.z;
      FUN_0027f650(iVar1,&pos);
      iVar1 = *(int *)(iVar1 + 0xa00);
      if (iVar1 != 0) {
        pos.x = *(float *)(iVar1 + 4) + diff.x;
        pos.y = *(float *)(iVar1 + 8) + diff.y;
        pos.z = *(float *)(iVar1 + 0xc) + diff.z;
        FUN_0027f650(iVar1,&pos);
      }
    }
    if ((*(u16 *)(param_1 + 3) & 2) != 0) {
      pos.x = *(float *)(iVar2 + 4) + diff.x;
      pos.y = *(float *)(iVar2 + 8) + diff.y;
      pos.z = *(float *)(iVar2 + 0xc) + diff.z;
      FUN_0027f650(iVar2,&pos);
    }
  }
  return 1;
}

// FUN_002b7bd0

void FUN_002b7bd0(u32 param_1,u32 param_2,float param_3,u16 param_4)
{
  u32 *work;
  u32 packet;

  packet = FUN_0027ec10(0xb00,0x10);
  *(code **)(packet + 0x6c) = (code *)FUN_002b79e0;
  work = *(u32 **)(packet + 0x78);
  work[0] = param_1;
  work[1] = param_2;
  *(float *)(work + 2) = param_3;
  *(u16 *)(work + 3) = param_4;
}

// FUN_002b7c50 NONMATCHING

u32 FUN_002b7c50(u32 *work)
{
    u32 *work_p = work;
    volatile u8 pad[0x50];
    BtlAction *action;
    BtlAction *targetAction;
    BtlUnit *source;
    BtlUnit *unit;
    BtlUnit *target;
    BtlUnit *persona;
    BtlUnit *iter;
    BtlUnit *next;
    u16 specificId;
    u32 index;
    s32 moved;
    s32 relation;
    s16 tableIndex;
    s16 relation2;
    s32 result;
    f32 radius;
    f32 radius2;
    f32 distance;
    f32 distance2;
    f32 limit;
    f32 scale;
    f32 factor;
    RwV3d center;
    f32 centerZ2;
    f32 centerY;
    s64 centerPair;
    f32 centerZ;
    s64 targetPair;
    RwV3d direction;
    f32 directionZ;
    f32 directionY;
    f32 directionX;
    f32 deltaZ;
    f32 deltaY;
    f32 deltaX;
    RwV3d candidate;
    f32 candidateZ;
    s64 candidatePair;
    f32 candidateY;
    f32 candidateX;
    f32 workZ;
    f32 workY;
    f32 workX;
    f32 workZ2;
    f32 workY2;
    f32 workX2;
    f32 workZ3;
    f32 workY3;
    f32 workX3;
    RtQuat rotation;

    pad[0] = 0;
    action = *(BtlAction **)work_p;
    specificId = action->target.specificId;
    switch (action->unit->genus)
    {
    case 0:
        unit = action->unit;
        FUN_002d6370((s16)specificId);
        if (FUN_002d6290((int)unit) == 1)
        {
            targetAction = action->target.targetedActions[0];
            if (action == targetAction)
            {
                return 1;
            }
            source = action->unit;
            target = targetAction->unit;
            persona = source->personaUnit;
            if (FUN_002fdd40(source, target) != 0)
            {
                *(u32 *)(DAT_007ce3ec + 0xc) |= 0x400000;
                *(u16 *)(DAT_007ce3ec + 0x18) |= 0xe;
            }
            btlUnitGetSphereWorldCenter(source, &center);
            FUN_002802d0(target, source, &centerPair);
            centerY = source->pos.y;
            center.y = centerY;
            if ((work_p[2] == 1) && (target != source) &&
                (FUN_002fdcf0(source, target) != 0))
            {
                if ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x200000) == 0)
                {
                    btlUnitGetSphereWorldCenter(target, &candidate);
                    FUN_002d1de0(&rotation, &candidate, &center);
                    scale = target->scale;
                    workX = target->sphereCenter.x * scale;
                    workY = target->sphereCenter.y * scale;
                    workZ = target->sphereCenter.z * scale;
                    FUN_004be1e0((RwV3d *)&directionX,
                                 (RwV3d *)&workX, 1, &rotation);
                    workX = candidate.x - directionX;
                    workY = candidate.y - directionY;
                    workZ = candidate.z - directionZ;
                    candidateY = target->pos.y;
                    workY = candidateY;
                    candidate.y = candidateY;
                    btlUnitSetPos(target, (RwV3d *)&workX);
                    FUN_002d1de0(&rotation, (RwV3d *)&workX, &source->pos);
                    btlUnitSetRot(target, &rotation);
                    targetPair = *(s64 *)&candidate;
                    centerZ2 = candidate.z;
                }
                else
                {
                    FUN_002d1de0(&rotation, (RwV3d *)&centerPair, &center);
                    btlUnitSetRot(target, &rotation);
                }
                btlUnitStopRotating(target);
                FUN_00288110(target);
            }
            if (work_p[1] == 1)
            {
                direction.x = center.x - *(f32 *)&centerPair;
                direction.z = center.z - centerZ2;
                direction.y = 0.0f;
                radius = RwV3dNormalize(&direction, &direction);
                radius2 = source->sphereRadius * source->scale;
                factor = 0.0f;
                moved = 0;
                if (persona != NULL)
                {
                    tableIndex = (s16)specificId;
                    moved = FUN_002d63b0((int)(uintptr_t)persona,
                                         (s16)tableIndex, 1);
                    relation = (s16)FUN_00284040(persona, source,
                                                 (s64)tableIndex, 1);
                    radius = radius - radius2;
                    if (moved == 0)
                    {
                        relation2 = FUN_00284040(persona, source,
                                                 (s64)(s16)specificId, 1);
                        if ((relation2 == 3) || (relation2 == 1))
                        {
                            FUN_0027f940(persona, source, target,
                                         (s64)(s16)relation,
                                         (RwV3d *)&workX, 0, 1);
                        }
                        else if ((relation2 == 2) || (relation2 == 0))
                        {
                            FUN_0027f940(persona, source, target,
                                         (s64)(s16)relation,
                                         (RwV3d *)&workX, 0, 0);
                        }
                    }
                    else
                    {
                        FUN_0027f940(persona, source, target,
                                     (s64)(s16)relation,
                                     (RwV3d *)&workX, 0, 2);
                    }
                    direction.x = workX - *(f32 *)&centerPair;
                    direction.z = workZ - centerZ2;
                    direction.y = 0.0f;
                    radius2 = persona->sphereRadius * persona->scale;
                    distance = RwV3dNormalize(&direction, &direction) - radius2;
                    if (moved == 0)
                    {
                        if ((distance + radius2) <=
                            source->sphereRadius * source->scale + radius + 0.0f)
                        {
                            deltaX = center.x - workX;
                            deltaY = center.y - workY;
                            deltaZ = center.z - workZ;
                            factor = RwV3dNormalize((RwV3d *)&deltaX,
                                                    (RwV3d *)&deltaX);
                            radius2 = distance;
                            radius = distance;
                        }
                    }
                    else
                    {
                        radius2 = persona->sphereRadius * persona->scale;
                        FUN_0027f940(persona, source, NULL, -1,
                                     (RwV3d *)&workX, 0, 0);
                        workX = center.x;
                        workY = center.y;
                        deltaX = center.x - center.x;
                        deltaY = center.y - center.y;
                        deltaZ = workZ - centerZ2;
                        factor = RwV3dLength((RwV3d *)&deltaX);
                        radius = distance;
                        if ((factor + distance + radius2) <= radius)
                        {
                            factor = 0.0f;
                            radius = radius;
                        }
                        else
                        {
                            radius = distance;
                        }
                    }
                }
                limit = target->sphereRadius * target->scale;
                radius = radius - limit;
                if (radius < 300.0f)
                {
                    radius = 300.0f;
                    moved = 1;
                }
                if (moved != 0)
                {
                    factor = radius + radius2 + limit + factor;
                    direction.x = direction.x * factor;
                    direction.y = direction.y * factor;
                    direction.z = direction.z * factor;
                    workX = *(f32 *)&centerPair + direction.x;
                    workY = centerY + direction.y;
                    workZ = centerZ2 + direction.z;
                    btlUnitSetPos(source, (RwV3d *)&workX);
                }
            }
        }
        else if ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x200000) == 0)
        {
            source = action->unit;
            if (work_p[2] == 1)
            {
                index = 0;
                while ((index & 0xffff) < action->target.targetedCount)
                {
                    targetAction = action->target.targetedActions[index & 0xffff];
                    target = targetAction->unit;
                    if ((target->flags2 & 1) != 0 && targetAction != action)
                    {
                        FUN_002d1de0(&rotation, &target->pos,
                                     &source->pos);
                        btlUnitSetRot(target, &rotation);
                        btlUnitStopRotating(target);
                        FUN_00288110(target);
                    }
                    index = (index + 1) & 0xffff;
                }
            }
            btlUnitGetSphereWorldCenter(source, &center);
            FUN_00280870(2, 0, &centerPair, 0, 0, 1);
            centerY = source->pos.y;
            center.y = centerY;
            targetPair = centerPair;
            centerZ2 = centerZ;
            factor = 0.0f;
            moved = 1;
            candidateX = *(f32 *)&center;
            candidateZ = center.z;
            workX = *(f32 *)&centerPair;
            workY = centerY;
            workZ = centerZ2;
            iter = *(BtlUnit **)(DAT_007ce3ec + 0x15c);
            while (iter != NULL)
            {
                if ((iter->flags3 & 8) != 0)
                {
                    FUN_002802d0(iter, source, &candidatePair);
                    candidateX = *(f32 *)&candidatePair;
                    candidateZ = candidateZ;
                    FUN_002d1fd0(&candidateX, &workX, &candidateX,
                                 &workZ2);
                    candidateX = candidateX - workZ2;
                    candidateZ = candidateZ - workZ3;
                    distance = RwV2dLength((RwV2d *)&candidateX);
                    if ((distance < factor) || (moved != 0))
                    {
                        targetPair = *(s64 *)&workZ2;
                        centerZ2 = workZ3;
                        factor = distance;
                        moved = 0;
                    }
                }
                iter = iter->prev;
            }
            if ((factor + 0.0f) - source->sphereRadius * source->scale <
                300.0f)
            {
                direction.x = center.x - *(f32 *)&targetPair;
                direction.y = center.y - centerZ2;
                direction.z = center.z - centerZ2;
                direction.y = direction.y + 0.0f;
                RwV3dNormalize(&direction, &direction);
                factor = factor + 0.0f;
                limit = factor + source->sphereRadius * source->scale +
                        300.0f;
                direction.x = direction.x * limit;
                direction.y = direction.y * limit;
                direction.z = direction.z * limit;
                workX = *(f32 *)&targetPair + direction.x;
                workY = centerZ2 + direction.y;
                workZ = centerZ2 + direction.z;
                btlUnitSetPos(source, (RwV3d *)&workX);
            }
        }
        else if ((*(u32 *)(DAT_007ce3ec + 0x10) & 0x80) != 0)
        {
            iter = *(BtlUnit **)(DAT_007ce3ec + 0x154);
            while (iter != NULL)
            {
                if ((iter->flags3 & 8) != 0)
                {
                    FUN_0027f7c0(iter, (RwV3d *)&workX, 0, 0);
                    workZ += 200.0f;
                    btlUnitSetPos(iter, (RwV3d *)&workX);
                }
                iter = iter->prev;
            }
            *(u32 *)(DAT_007ce3ec + 0xc) |= 0x400000;
            *(u16 *)(DAT_007ce3ec + 0x18) |= 6;
        }
        break;
    case 1:
        if ((action->target.targetedCount != 1) &&
            ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x200000) == 0) &&
            ((result = FUN_002d1600((int)&action->target)) & 0xffff) == 1)
        {
            moved = 0;
            source = action->unit;
            btlUnitGetSphereWorldCenter(source, &center);
            radius = source->sphereRadius * source->scale;
            if (work_p[2] == 1)
            {
                FUN_00280870(result, 1, &centerPair, 0, 0, 1);
                factor = 0.0f;
                index = 0;
                while ((index & 0xffff) < action->target.targetedCount)
                {
                    targetAction = action->target.targetedActions[index & 0xffff];
                    target = targetAction->unit;
                    if ((target->flags2 & 1) != 0)
                    {
                        FUN_00280050(target, &candidate);
                        direction.x = *(f32 *)&centerPair - candidate.x;
                        direction.y = center.y - candidate.y;
                        direction.z = centerZ2 - candidate.z;
                        distance = RwV3dLength(&direction);
                        if (!(distance <= factor))
                        {
                            targetPair = *(s64 *)&candidate;
                            centerZ2 = candidate.z;
                            factor = distance;
                        }
                    }
                    index = (index + 1) & 0xffff;
                }
                FUN_002d1de0(&rotation, &center,
                             (RwV3d *)&targetPair);
                btlUnitSetRot(source, &rotation);
                btlUnitStopRotating(source);
                FUN_00288110(source);
            }
            iter = *(BtlUnit **)(DAT_007ce3ec + 0x154);
            while (iter != NULL)
            {
                if ((iter->flags3 & 8) != 0)
                {
                    FUN_002802d0(iter, source, &centerPair);
                    direction.x = *(f32 *)&centerPair - center.x;
                    direction.z = centerZ2 - center.z;
                    direction.y = 0.0f;
                    limit = radius + source->sphereRadius * source->scale;
                    if ((limit < RwV3dNormalize(&direction, &direction)) &&
                        !(limit <= 300.0f))
                    {
                        workX = direction.x * limit;
                        workY = direction.y * limit;
                        workZ = direction.z * limit;
                        workX = center.x + workX;
                        workY = center.y + workY;
                        workZ = center.z + workZ;
                        workY = workY + source->sphereRadius * source->scale;
                        btlUnitSetPos(iter, (RwV3d *)&workX);
                        moved = 1;
                    }
                }
                iter = iter->prev;
            }
            if (moved != 0)
            {
                *(u32 *)(DAT_007ce3ec + 0xc) |= 0x400000;
                *(u16 *)(DAT_007ce3ec + 0x18) |= 0x1e;
            }
        }
        break;
    default:
        break;
    }
    return 1;
}

// FUN_002b8900

void FUN_002b8900(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = FUN_0027ec10(0xb01,0xc);
  *(code **)(iVar2 + 0x6c) = (code *)FUN_002b7c50;
  puVar1 = *(undefined4 **)(iVar2 + 0x78);
  *puVar1 = param_1;
  puVar1[1] = param_2;
  puVar1[2] = param_3;
  return;
}

// FUN_002b8970
void LAB_002b8970(u32 *work)
{
  u8 *unit;

  unit = (u8 *)*work;
  (*(u16 *)(unit + 0xa0))++;
}

// FUN_002b8990 NONMATCHING

undefined4 FUN_002b8990(undefined4 *param_1)
{
  undefined4 uVar2;
  undefined4 uVar3;
  s16 uVar1;
  int bVar4;
  s16 uVar5;
  short sVar6;
  u32 lVar7;
  undefined1 auStack_20 [16];
  undefined1 auStack_10 [16];
  
  uVar2 = *param_1;
  uVar3 = *(undefined4 *)(param_1[1] + 0x30);
  uVar1 = *(s16 *)(param_1 + 3);
  bVar4 = param_1[2] != 0;
  uVar5 = FUN_00284040(uVar2,uVar3,uVar1,bVar4);
  lVar7 = FUN_002d63b0(uVar2,uVar1,bVar4);
  if (lVar7 == 0) {
    sVar6 = FUN_00284040(uVar2,uVar3,uVar1,bVar4);
    if ((sVar6 == 3) || (sVar6 == 1)) {
      FUN_0027f940(uVar2,uVar3,0,uVar5,auStack_20,auStack_10,1);
    }
    else if ((sVar6 == 2) || (sVar6 == 0)) {
      FUN_0027f940(uVar2,uVar3,0,uVar5,auStack_20,auStack_10,0);
    }
    FUN_0027f680(uVar2,auStack_10);
    FUN_0027f650(uVar2,auStack_20);
  }
  else {
    FUN_0027f940(uVar2,uVar3,*(undefined4 *)(param_1[2] + 0x30),uVar5,auStack_20,auStack_10,2);
    FUN_0027f680(uVar2,auStack_10);
    FUN_0027f650(uVar2,auStack_20);
  }
  return 1;
}

// FUN_002b8b50
void LAB_002b8b50(u32 *work)
{
  u8 *unit;

  unit = (u8 *)*work;
  (*(u16 *)(unit + 0xa0))--;
}

// FUN_002b8b70

void FUN_002b8b70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = FUN_0027ec10(0xb02,0x10);
  *(undefined1 **)(iVar2 + 0x68) = (undefined1*)LAB_002b8970;
  *(code **)(iVar2 + 0x6c) = (code *)FUN_002b8990;
  *(undefined1 **)(iVar2 + 0x70) = (undefined1*)LAB_002b8b50;
  puVar1 = *(undefined4 **)(iVar2 + 0x78);
  *puVar1 = param_1;
  puVar1[1] = param_2;
  puVar1[2] = param_3;
  *(undefined2 *)(puVar1 + 3) = param_4;
  return;
}

// FUN_002b8c00

undefined4 FUN_002b8c00(u16 *param_1)

{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  u32 m1;
  u32 b1;
  u32 b2;
  u32 uVar5;
  undefined1 auStack_10 [16];
  undefined1 auStack_20 [16];

  uVar1 = *param_1;
  uVar2 = param_1[1];
  uVar5 = 0;
  m1 = uVar2 & 0x8000;
  b1 = uVar2 & 1;
  b2 = uVar2 & 2;

  for (; uVar5 < 4; uVar5 = uVar5 + 1) {
    if ((uVar1 & (1 << uVar5)) != 0) {
      for (iVar3 = *(int *)(iGpffffb6fc + uVar5 * 8 + 0x150); iVar3 != 0;
          iVar3 = *(int *)(iVar3 + 0xa34)) {
        if (((*(u32 *)(iVar3 + 0x9c) & 4) != 0) &&
           ((m1 == 0) || (FUN_00281270(iVar3) == 0))) {
          FUN_0027f7c0((BtlUnit*)(uintptr_t)iVar3,(RwV3d*)auStack_10,(void*)auStack_20,0);
          if (b1 != 0) {
            FUN_0027f650(iVar3,auStack_10);
            FUN_00281290(iVar3);
            FUN_002d4040(iVar3);
          }
          if (b2 != 0) {
            FUN_0027f680(iVar3,auStack_20);
            FUN_002812b0(iVar3);
            FUN_00288110(iVar3);
          }
        }
      }
    }
  }
  return 1;
}

/* Camera-state work records use the retail 64-bit pair layout. */
#ifndef BTLCAMERA_GHIDRA_PAIR
#define BTLCAMERA_GHIDRA_PAIR
typedef u8 u8;
typedef u8 byte;
typedef unsigned short ushort;
typedef union BtlCameraGhidraPair
{
    struct { f32 _0_4_; f32 _4_4_; } f;
    u64 raw;
} BtlCameraGhidraPair;
#define GhidraPair BtlCameraGhidraPair
#define PAIR44(hi, lo) ((GhidraPair){{(lo), (hi)}})
#endif

extern f32 DAT_007cad3c;
extern f32 DAT_007cad54;
extern f32 DAT_007cad98;
extern f32 DAT_007cadb0;
extern f32 DAT_007caddc;
extern f32 DAT_007cade0;
extern f32 DAT_007cade4;
extern f32 DAT_007cade8;
extern f32 DAT_007cadfc;
extern f32 DAT_007cae00;
extern f32 DAT_007cae04;
extern f32 DAT_007cae0c;
extern f32 DAT_007cae10;
extern f32 DAT_007cae14;
extern f32 DAT_007cae18;
extern f32 DAT_007cae24;
extern f32 fGpffff8030;
extern f32 fGpffff807c;
extern f32 fGpffff80a0;
extern f32 fGpffff80a4;
extern f32 fGpffff80a8;
extern f32 fGpffff80b0;
extern f32 fGpffff80b8;
extern f32 fGpffff80bc;
extern u32 uGpffff8074;
extern u32 uGpffff809c;
extern u32 uGpffff80ac;
extern u64 func_00280050();
extern u64 func_00280870();
extern u64 func_002d1de0();
extern u8* iGpffffb6fc;
extern u8* iGpffffb73c;

// FUN_002AA2B0 NONMATCHING

void func_002aa2b0(BtlCamera* camera, int param_2, int param_3)
{
  short sVar1;
  int iVar2;
  int iVar3;
  u8 bVar4;
  u8 bVar5;
  long lVar6;
  long lVar7;
  u32 uVar8;
  int iVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  undefined4 uVar16;
  float fVar17;
  float fStack_118;
  float fStack_114;
  undefined1 auStack_110 [64];
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  GhidraPair uStack_70;
  float fStack_68;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  undefined1 auStack_50 [4];
  float fStack_4c;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar9 = (int)camera;
  iVar2 = *(int *)(*(int *)(iVar9 + 0xe0) + 0x30);
  iVar3 = *(int *)(iVar2 + 0xa00);
  if ((lVar6 == 0) && (lVar6 = FUN_002a3550((u8*)camera), lVar6 == 0)) {
    bVar4 = 0;
  }
  else {
    bVar4 = 1;
  }
  bVar5 = 0;
  btlUnitGetSphereWorldCenter((BtlUnit*)(uintptr_t)(iVar2), (RwV3d*)&fStack_30);
  btlUnitGetSphereWorldCenter((BtlUnit*)(uintptr_t)(iVar3), (RwV3d*)auStack_50);
  fVar15 = *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c) * 0.5 + fStack_2c + 0.0;
  fVar13 = *(float *)(iVar3 + 0x8c) * *(float *)(iVar3 + 0x2c) * 0.5 + fStack_4c + 0.0;
  if ((fVar15 < fVar13) && (!bVar4)) {
    fStack_2c = (fVar15 + fVar13) * 0.25;
    fVar15 = fVar13;
  }
  fVar14 = *(float *)(iVar3 + 0x90) * *(float *)(iVar3 + 0x2c);
  fVar13 = *(float *)(iVar2 + 0x90) * *(float *)(iVar2 + 0x2c) * 1.25;
  if ((fVar13 < fVar14) && (!bVar4)) {
    fVar13 = fVar14;
  }
  if (fVar15 < 275.0) {
    fStack_2c = fGpffff80a0;
    fVar15 = 275.0;
  }
  fVar10 = (float)func_00280870(2,0,&fStack_40,&fStack_4,0,1);
  FUN_004be1e0(&fStack_10,0x697870,1,iVar2 + 0x1c);
  fStack_3c = fStack_4 * 0.5;
  fStack_20 = fStack_30 - fStack_40;
  fStack_1c = fStack_2c - fStack_3c;
  fStack_18 = fStack_28 - fStack_38;
  fVar14 = (float)FUN_004c69f0(&fStack_20,&fStack_20);
  fVar14 = fGpffff8098 * fVar14;
  fStack_60 = fStack_20 * fVar14 + fStack_40;
  fStack_5c = fStack_1c * fVar14 + fStack_3c;
  fStack_68 = fStack_18 * fVar14 + fStack_38;
  uStack_70 = PAIR44(fStack_5c,fStack_60);
  fStack_118 = *(float *)(iVar9 + 0x9c) - fStack_60;
  fStack_114 = *(float *)(iVar9 + 0xa4) - fStack_68;
  fStack_58 = fStack_68;
  FUN_004c6b20(&fStack_118,&fStack_118);
  fVar14 = fStack_18 * fStack_118 + -fStack_20 * fStack_114;
  if ((bVar4) ||
     ((*(ushort *)
        (iGpffffb73c + ((u32)*(ushort *)(iVar3 + 0xa4) * 10 + (u32)*(ushort *)(iVar3 + 0xa4)) * 8)
      & 0x20) == 0)) {
    uVar8 = FUN_00357fd0(0);
    bVar4 = (uVar8 & 1) != 0;
  }
  else {
    bVar4 = 0;
  }
  if ((lVar6 != 0) || (((bVar4 && (lVar6 = FUN_002a3380((u8*)camera), lVar6 != 0)) && (lVar7 == 0)))) {
    btlUnit002880e0((BtlUnit*)(uintptr_t)(iVar3),1);
    *(int *)(iVar9 + 0x120) = iVar3;
    *(undefined2 *)(iVar9 + 0x124) = 0;
    fVar11 = fVar13;
    if (fVar14 < 0.0) {
      fVar11 = -fVar13;
    }
    fStack_8 = fStack_8 * fVar11;
    fStack_10 = fStack_10 * fVar11;
    fStack_80 = fStack_30 + fStack_10;
    fStack_78 = fStack_28 + fStack_8;
    fVar15 = fGpffff80a4 * fVar15;
    fStack_10 = fStack_80 - fStack_60;
    fStack_c = fVar15 - fStack_5c;
    fStack_8 = fStack_78 - fStack_58;
    fStack_7c = fVar15;
    fVar11 = (float)FUN_004c69f0(&fStack_10,&fStack_10);
    fVar17 = fGpffff8070 * *(float *)(iVar9 + 0xb8) * 0.5;
    fVar12 = (float)FUN_0052e930(fVar17);
    fVar13 = fVar13 / fVar12;
    fVar12 = (float)FUN_0052e930(fVar17);
    if (fVar13 <= fVar15 / fVar12) {
      fVar13 = fVar15 / fVar12;
    }
    fVar11 = fVar11 + fVar13;
    fVar15 = (float)FUN_0052e930(fVar17);
    if (fVar11 <= fVar10 / fVar15) {
      fVar11 = fVar10 / fVar15;
    }
    fVar15 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar9 + 0xb8) * 0.5);
    fVar15 = fVar11 * fVar15 * 0.21875;
    fStack_98 = fStack_10;
    fStack_94 = fStack_8;
    FUN_004c6b20(&fStack_98,&fStack_98);
    fStack_60 = fStack_94 * fVar15 + fStack_60 + 0.0;
    fStack_58 = (fStack_58 + 0.0) - fStack_98 * fVar15;
    fStack_b4 = fStack_60 + fStack_10 * fVar11;
    fStack_b0 = fStack_5c + fStack_c * fVar11;
    fStack_ac = fStack_58 + fStack_8 * fVar11;
    btlUnitGetSphereWorldCenter((BtlUnit*)(uintptr_t)(iVar2), (RwV3d*)&fStack_30);
    fStack_2c = fGpffff8094 * *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c) + fStack_2c + 0.0;
    fVar15 = *(float *)(iVar2 + 0x90) * *(float *)(iVar2 + 0x2c) * 2.5;
    FUN_004be1e0(&fStack_10,0x697870,1,iVar2 + 0x1c);
    if (0.0 <= fVar14) {
      fVar15 = -fVar15;
    }
    fStack_8 = fStack_8 * fVar15;
    fStack_c = fStack_c * fVar15;
    fStack_10 = fStack_10 * fVar15;
    fStack_90 = fStack_30 + fStack_10;
    fStack_8c = fStack_2c + fStack_c;
    fStack_88 = fStack_28 + fStack_8;
    fVar14 = *(float *)(iVar2 + 0x90) * *(float *)(iVar2 + 0x2c) * 4.0;
    fStack_10 = fStack_90 - uStack_70.f._0_4_;
    fStack_c = fStack_8c - uStack_70.f._4_4_;
    fStack_8 = fStack_88 - fStack_68;
    fVar15 = (float)FUN_004c69f0(&fStack_10,&fStack_10);
    fVar13 = (float)FUN_0052e930(fVar17);
    fVar15 = fVar15 + fVar14 / fVar13;
    FUN_004be1e0(&fStack_10,0x6978a0,1,&uStack_c4);
    fVar13 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar9 + 0xb8) * 0.5);
    fVar13 = fVar15 * fVar13 * 0.21875;
    fStack_98 = fStack_10;
    fStack_94 = fStack_8;
    FUN_004c6b20(&fStack_98,&fStack_98);
    fStack_d0 = fStack_94 * fVar13 + uStack_70.f._0_4_ + 0.0;
    uStack_70 = PAIR44(uStack_70.f._4_4_,fStack_d0);
    fStack_68 = (fStack_68 + 0.0) - fStack_98 * fVar13;
    fStack_10 = fStack_10 * fVar15;
    fStack_c = fStack_c * fVar15;
    fStack_8 = fStack_8 * fVar15;
    fStack_d0 = fStack_d0 + fStack_10;
    fStack_cc = uStack_70.f._4_4_ + fStack_c;
    fStack_c8 = fStack_68 + fStack_8;
    uVar16 = uGpffff8074;
  }
  else {
    btlUnit002880e0((BtlUnit*)(uintptr_t)(iVar3),0);
    *(int *)(iVar9 + 0x120) = iVar3;
    *(undefined2 *)(iVar9 + 0x124) = 1;
    fStack_78 = fStack_38;
    fStack_7c = fGpffff80a8 * fStack_4;
    fStack_80 = fStack_40;
    if (*(short *)(*(int *)(iVar9 + 0xe0) + 0x6a) == 1) {
      iVar2 = *(int *)(*(int *)(*(int *)(iVar9 + 0xe0) + 0x38) + 0x30);
      if (0.0 <= fVar14) {
        fVar15 = *(float *)(iVar2 + 0x90) * *(float *)(iVar2 + 0x2c);
      }
      else {
        fVar15 = -(*(float *)(iVar2 + 0x90) * *(float *)(iVar2 + 0x2c));
      }
      fStack_8 = fStack_8 * fVar15;
      fStack_c = fStack_c * fVar15;
      fStack_10 = fStack_10 * fVar15;
      fStack_80 = fStack_40 + fStack_10;
      fStack_7c = fStack_7c + fStack_c;
      fStack_78 = fStack_38 + fStack_8;
    }
    if (fStack_7c < 125.0) {
      fStack_7c = 125.0;
    }
    fStack_10 = fStack_80 - fStack_60;
    fStack_c = fStack_7c - fStack_5c;
    fStack_8 = fStack_78 - fStack_58;
    fVar13 = (float)FUN_004c69f0(&fStack_10,&fStack_10);
    fVar15 = 300.0;
    if (300.0 <= fVar10) {
      fVar15 = fVar10;
    }
    fVar10 = (float)FUN_0052e930(*(float *)(iVar9 + 0xb8) * 0.5);
    fVar13 = fVar13 + fVar15 / fVar10;
    fVar15 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar9 + 0xb8) * 0.5);
    fVar15 = fVar13 * fVar15 * 0.21875 * 0.5;
    fStack_98 = fStack_10;
    fStack_94 = fStack_8;
    FUN_004c6b20(&fStack_98,&fStack_98);
    fStack_60 = fStack_94 * fVar15 + fStack_60 + 0.0;
    fStack_58 = (fStack_58 + 0.0) - fStack_98 * fVar15;
    fStack_b4 = fStack_60 + fStack_10 * fVar13;
    fStack_b0 = fStack_5c + fStack_c * fVar13;
    fStack_ac = fStack_58 + fStack_8 * fVar13;
    if (lVar7 == 0) {
      if (0.0 <= fVar14) {
        FUN_004c31b0(0xc1dc0000,auStack_110,0x697880,0);
      }
      else {
        FUN_004c31b0(0x41dc0000,auStack_110,0x697880,0);
      }
      FUN_004c6c60(&fStack_20,&fStack_10,auStack_110);
      fVar13 = fVar13 * fGpffff807c;
      fVar15 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar9 + 0xb8) * 0.5);
      fVar15 = fVar13 * fVar15 * 0.21875 * 0.5;
      fStack_98 = fStack_20;
      fStack_94 = fStack_18;
      FUN_004c6b20(&fStack_98,&fStack_98);
      fStack_60 = fStack_94 * fVar15 + fStack_60 + 0.0;
      fStack_58 = (fStack_58 + 0.0) - fStack_98 * fVar15;
      fStack_d0 = fStack_60 + fStack_20 * fVar13;
      fStack_c8 = fStack_58 + fStack_18 * fVar13;
      fStack_cc = fGpffff80a4 * fStack_4;
      fStack_20 = fStack_30 - fStack_40;
      fStack_1c = fStack_2c - fStack_3c;
      fStack_18 = fStack_28 - fStack_38;
      fVar15 = (float)FUN_004c69f0(&fStack_20,&fStack_20);
      fVar15 = fVar15 * 0.25;
      fStack_60 = fStack_20 * fVar15 + fStack_40;
      fStack_5c = fStack_1c * fVar15 + fStack_3c;
      fStack_58 = fStack_18 * fVar15 + fStack_38;
      uVar16 = 0x40700000;
    }
    else {
      sVar1 = *(short *)(*(int *)(iVar9 + 0xe0) + 0x6e);
      if (sVar1 == 0x38) {
        fStack_5c = 1000.0;
        fStack_cc = 500.0;
        uVar16 = 0x3fc00000;
        bVar5 = 0;
        *(undefined4 *)(iVar9 + 0xdc) = 4;
      }
      else if (sVar1 == 0x2c) {
        fStack_5c = 800.0;
        fStack_cc = 500.0;
        uVar16 = 0x40000000;
        bVar5 = 1;
        *(undefined4 *)(iVar9 + 0xdc) = 0xc;
      }
      else if (sVar1 == 0x27) {
        fStack_5c = 600.0;
        fStack_cc = 200.0;
        bVar5 = 0;
        *(undefined4 *)(iVar9 + 0xdc) = 8;
        uVar16 = uGpffff80ac;
      }
      else if (sVar1 == 0x26) {
        fStack_5c = 500.0;
        fStack_cc = 200.0;
        uVar16 = 0x3fa00000;
        bVar5 = 1;
        *(undefined4 *)(iVar9 + 0xdc) = 0xc;
      }
      else {
        fStack_5c = 500.0;
        fStack_cc = 200.0;
        bVar5 = 1;
        *(undefined4 *)(iVar9 + 0xdc) = 0;
        uVar16 = uGpffff809c;
      }
      param_2 = 0;
      fStack_d0 = fStack_b4;
      fStack_c8 = fStack_ac;
    }
  }
  if ((param_3 == 0) && (lVar7 == 0)) {
    uStack_c4 = uStack_a8;
    uStack_c0 = uStack_a4;
    uStack_bc = uStack_a0;
    uStack_b8 = uStack_9c;
    FUN_004be1e0(&fStack_10,0x697890,1,&uStack_c4);
    fStack_10 = fStack_10 * 100.0;
    fStack_c = fStack_c * 100.0;
    fStack_8 = fStack_8 * 100.0;
    fStack_d0 = fStack_b4 + fStack_10;
    fStack_cc = fStack_b0 + fStack_c;
    fStack_c8 = fStack_ac + fStack_8;
  }
  if (0 < *(int *)(iVar9 + 0xdc)) {
  }
  if (bVar5) {
    FUN_002a3160(uVar16,camera);
  }
  else {
  }
  if (param_2 != 0) {
    FUN_00351bb0(0xc);
  }
  return;
}

// FUN_002AB2A0

void func_002ab2a0(BtlCamera* camera)
{
  int iVar1;
  long lVar2;
  int iVar3;
  
  iVar3 = (int)camera;
  iVar1 = *(int *)(iVar3 + 0xe0);
  if ((iVar1 != 0) && ((*(ushort *)(iVar1 + 0x1a) & 1) != 0)) {
    if (*(int *)(iVar3 + 0xdc) == 0) {
      FUN_002a3e80(0.0f,(u8 *)(uintptr_t)iVar1,0,0,3);
    }
    if (FUN_002a3750(camera,*(undefined4 *)(iVar3 + 0x120)) != 0) {
      btlUnit002880e0((BtlUnit*)(uintptr_t)(*(undefined4 *)(iVar3 + 0x120)),*(undefined2 *)(iVar3 + 0x124));
    }
  }
  return;
}

// FUN_002AB330 NONMATCHING

void func_002ab330(BtlCamera* camera, int param_2, int param_3)
{
  int iVar1;
  int iVar2;
  u8 bVar3;
  u32 uVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  undefined4 uVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  float fStack_e4;
  float fStack_e0;
  float fStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  GhidraPair uStack_80;
  float fStack_78;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar6 = (int)camera;
  iVar7 = *(int *)(*(int *)(iVar6 + 0xe0) + 0x30);
  iVar1 = *(int *)(*(int *)(*(int *)(iVar6 + 0xe0) + 0x38) + 0x30);
  iVar2 = *(int *)(iVar7 + 0xa00);
  btlUnitGetSphereWorldCenter((BtlUnit*)(uintptr_t)(iVar7), (RwV3d*)&fStack_10);
  btlUnitGetSphereWorldCenter((BtlUnit*)(uintptr_t)(iVar1), (RwV3d*)&fStack_20);
  btlUnitGetSphereWorldCenter((BtlUnit*)(uintptr_t)(iVar2), (RwV3d*)&fStack_30);
  fVar15 = *(float *)(iVar7 + 0x8c) * *(float *)(iVar7 + 0x2c) * 0.5 + fStack_c + 0.0;
  fVar12 = *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) * 0.5 + fStack_1c + 0.0;
  fVar13 = *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c) * 0.5 + fStack_2c + 0.0;
  fVar14 = *(float *)(iVar7 + 0x90) * *(float *)(iVar7 + 0x2c);
  fVar10 = *(float *)(iVar2 + 0x90) * *(float *)(iVar2 + 0x2c);
  *(float *)(iVar6 + 0x104) = fStack_20;
  *(float *)(iVar6 + 0x108) = fStack_1c;
  *(float *)(iVar6 + 0x10c) = fStack_18;
  *(undefined4 *)(iVar6 + 0x100) = *(undefined4 *)(*(int *)(iVar6 + 0xe0) + 0x38);
  if (fVar13 < 135.0) {
    fStack_2c = 67.5;
    fVar13 = 135.0;
  }
  if ((*(u32 *)(iGpffffb6fc + 0xc) & 0x200000) == 0) {
    if (125.0 <= fVar13 - fVar12) {
      bVar3 = 0;
    }
    else {
      bVar3 = lVar5 != 0;
      if (!bVar3) {
        uVar4 = FUN_00357fd0(0);
        bVar3 = 0;
        if ((uVar4 & 1) != 0) {
          bVar3 = lVar5 != 0;
        }
      }
    }
  }
  else {
    bVar3 = 1;
  }
  if (bVar3) {
    fStack_60 = fStack_30 - fStack_20;
    fStack_5c = fStack_2c - fStack_1c;
    fStack_58 = fStack_28 - fStack_18;
    fVar8 = (float)FUN_004c69f0(&fStack_60,&fStack_60);
    fStack_48 = fGpffff8098 * fVar8;
    fStack_50 = fStack_60 * fStack_48;
    fStack_4c = fStack_5c * fStack_48;
    fStack_48 = fStack_58 * fStack_48;
  }
  else {
    fStack_60 = (fStack_30 + fStack_10) * 0.5;
    fStack_5c = (fStack_2c + fStack_c) * 0.5;
    fStack_38 = (fStack_28 + fStack_8) * 0.5;
    fStack_60 = fStack_60 - fStack_20;
    fStack_5c = fStack_5c - fStack_1c;
    fStack_58 = fStack_38 - fStack_18;
    fVar8 = (float)FUN_004c69f0(&fStack_60,&fStack_60);
    fStack_48 = fGpffff8098 * fVar8;
    fStack_50 = fStack_60 * fStack_48;
    fStack_4c = fStack_5c * fStack_48;
    fStack_48 = fStack_58 * fStack_48;
  }
  fStack_50 = fStack_50 + fStack_20;
  fStack_4c = fStack_4c + fStack_1c;
  fStack_48 = fStack_48 + fStack_18;
  fStack_b8 = *(float *)(iVar6 + 0x9c) - fStack_50;
  fStack_b4 = *(float *)(iVar6 + 0xa4) - fStack_48;
  FUN_004c6b20(&fStack_b8,&fStack_b8);
  if (bVar3) {
    btlUnit002880e0((BtlUnit*)(uintptr_t)(iVar2),1);
    *(int *)(iVar6 + 0x120) = iVar2;
    *(undefined2 *)(iVar6 + 0x124) = 0;
    fStack_40 = fStack_30;
    fStack_3c = fStack_2c;
    fStack_38 = fStack_28;
    fVar9 = fVar10 * 1.5;
    fStack_c0 = fStack_58;
    fStack_bc = -fStack_60;
    fVar16 = fStack_58 * fStack_b8 + fStack_bc * fStack_b4;
    if (0.0 <= fVar16) {
      fStack_70 = fStack_58 * fVar9 + fStack_30 + 0.0;
      fStack_68 = (fStack_28 + 0.0) - fStack_60 * fVar9;
    }
    else {
      fStack_70 = (fStack_30 + 0.0) - fStack_58 * fVar9;
      fStack_68 = fStack_60 * fVar9 + fStack_28 + 0.0;
      fVar8 = fVar8 * 0.5;
      fStack_50 = fStack_60 * fVar8 + fStack_20;
      fStack_4c = fStack_5c * fVar8 + fStack_1c;
      fStack_48 = fStack_58 * fVar8 + fStack_18;
    }
    if (fVar12 <= fVar13) {
      fStack_4c = fGpffff8094 * *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) +
                  fStack_4c + 0.0;
      if (fStack_4c < fVar13) {
        fStack_6c = fGpffff8030 * *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c) +
                    fStack_4c + 0.0;
      }
      else {
        fStack_6c = fStack_2c;
      }
    }
    else if (((*(u32 *)(iGpffffb6fc + 0xc) & 0x200000) == 0) || (fVar12 < 500.0)) {
      fStack_4c = (fStack_4c + 0.0) -
                  fGpffff80b0 * *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c);
      fStack_6c = fVar13 * 0.25 + fStack_2c + 0.0;
    }
    else {
      fStack_4c = fGpffff8030 * *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) +
                  fStack_4c + 0.0;
      fStack_6c = fVar13 * 0.25 + fStack_2c + 0.0;
    }
    FUN_004be1e0(&fStack_60,0x6978a0,1,&uStack_d8);
    fStack_b0 = fStack_50;
    fStack_ac = fStack_48;
    fStack_a8 = fStack_70;
    fStack_a4 = fStack_68;
    fStack_88 = fStack_40;
    fStack_84 = fStack_38;
    fVar8 = (float)FUN_002d1fd0((f32*)&fStack_b0,(f32*)&fStack_a8,(f32*)&fStack_88,(f32*)&fStack_90);
    fVar8 = fVar10 * fGpffff809c + fVar8 + 0.0;
    fVar10 = 275.0;
    if (275.0 <= fVar8) {
      fVar10 = fVar8;
    }
    fStack_70 = fStack_90;
    if (fVar12 <= fVar13) {
      if (fStack_4c < fVar13) {
        fStack_6c = fGpffff80b4 * *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c) +
                    fStack_4c + 0.0;
      }
      else {
        fStack_6c = *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c) * 0.25 + fStack_3c + 0.0;
      }
    }
    else {
      fStack_6c = fVar13 * 0.25 + fStack_3c + 0.0;
    }
    fStack_68 = fStack_8c;
    fVar13 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar6 + 0xb8) * 0.5);
    fVar10 = fVar10 / fVar13;
    fStack_60 = fStack_60 * fVar10;
    fStack_5c = fStack_5c * fVar10;
    fStack_58 = fStack_58 * fVar10;
    if (fVar16 < 0.0) {
      fVar13 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar6 + 0xb8) * 0.5);
      fVar10 = fVar10 * fVar13 * 0.21875 * 1.25;
      fStack_98 = fStack_60;
      fStack_94 = fStack_58;
      FUN_004c6b20(&fStack_98,&fStack_98);
      fStack_70 = fStack_94 * fVar10 + fStack_70 + 0.0;
      fStack_68 = (fStack_68 + 0.0) - fStack_98 * fVar10;
    }
    fStack_e4 = fStack_70 + fStack_60;
    fStack_e0 = fStack_6c + fStack_5c;
    fStack_dc = fStack_68 + fStack_58;
    if (fStack_e0 < 25.0) {
      fStack_e0 = 25.0;
    }
    fStack_60 = fStack_10 - fStack_20;
    fStack_5c = fStack_c - fStack_1c;
    fStack_58 = fStack_8 - fStack_18;
    fVar13 = (float)FUN_004c69f0(&fStack_60,&fStack_60);
    fVar10 = fGpffff8098 * fVar13;
    fStack_50 = fStack_60 * fVar10 + fStack_20;
    fStack_4c = fStack_5c * fVar10 + fStack_1c;
    fStack_48 = fStack_58 * fVar10 + fStack_18;
    fStack_40 = fStack_10;
    fStack_3c = fStack_c;
    fStack_38 = fStack_8;
    fVar10 = fVar14 * 2.0;
    lVar5 = FUN_0017d800();
    if ((lVar5 != 0) && (450.0 < fStack_1c)) {
      fVar10 = fVar10 + 150.0;
      fVar15 = fVar15 + 350.0;
    }
    fStack_6c = fVar15 * 0.5 + fStack_3c + 0.0;
    if (0.0 <= fVar16) {
      fStack_70 = fStack_58 * fVar10 + fStack_40 + 0.0;
      fStack_68 = (fStack_38 + 0.0) - fStack_60 * fVar10;
    }
    else {
      fStack_70 = (fStack_40 + 0.0) - fStack_58 * fVar10;
      fStack_68 = fStack_60 * fVar10 + fStack_38 + 0.0;
      fVar13 = fVar13 * 0.5;
      fStack_50 = fStack_60 * fVar13 + fStack_20;
      fStack_4c = fStack_5c * fVar13 + fStack_1c;
      fStack_48 = fStack_58 * fVar13 + fStack_18;
    }
    fStack_4c = fGpffff8030 * *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) + fStack_4c + 0.0;
    FUN_004be1e0(&fStack_60,0x6978a0,1,&uStack_f4);
    fStack_b0 = fStack_50;
    fStack_ac = fStack_48;
    fStack_a8 = fStack_70;
    fStack_a4 = fStack_68;
    fStack_88 = fStack_40;
    fStack_84 = fStack_38;
    fVar10 = (float)FUN_002d1fd0((f32*)&fStack_b0,(f32*)&fStack_a8,(f32*)&fStack_88,(f32*)&fStack_90);
    fStack_70 = fStack_90;
    fStack_6c = fVar15 * 0.25 + fStack_3c + 0.0;
    fStack_68 = fStack_8c;
    fVar13 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar6 + 0xb8) * 0.5);
    fVar13 = (fVar14 * 3.0 + fVar10 + 0.0) / fVar13;
    fStack_60 = fStack_60 * fVar13;
    fStack_5c = fStack_5c * fVar13;
    fStack_58 = fStack_58 * fVar13;
    if (fVar16 < 0.0) {
      fVar10 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar6 + 0xb8) * 0.5);
      fVar10 = fVar13 * fVar10 * 0.21875 * 1.25;
      fStack_98 = fStack_60;
      fStack_94 = fStack_58;
      FUN_004c6b20(&fStack_98,&fStack_98);
      fStack_70 = fStack_94 * fVar10 + fStack_70 + 0.0;
      fStack_68 = (fStack_68 + 0.0) - fStack_98 * fVar10;
    }
    fStack_100 = fStack_70 + fStack_60;
    fStack_fc = fStack_6c + fStack_5c;
    fStack_f8 = fStack_68 + fStack_58;
    if (fStack_fc < 25.0) {
      fStack_fc = 25.0;
    }
    uVar11 = 0x40200000;
    iVar7 = iVar1;
  }
  else {
    btlUnit002880e0((BtlUnit*)(uintptr_t)(iVar2),0);
    *(int *)(iVar6 + 0x120) = iVar2;
    *(undefined2 *)(iVar6 + 0x124) = 1;
    fStack_3c = fStack_1c;
    fStack_38 = fStack_18;
    fVar14 = fGpffff80b8 * *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c);
    fVar10 = fVar10 * 0.75;
    if (fVar10 <= fVar14) {
      fVar10 = fVar14;
    }
    if (fStack_1c < 125.0) {
      fStack_3c = 125.0;
    }
    fStack_40 = fStack_20;
    fStack_c0 = fStack_58;
    fStack_bc = -fStack_60;
    fVar14 = fStack_58 * fStack_b8 + fStack_bc * fStack_b4;
    fStack_6c = fStack_3c;
    if (0.0 <= fVar14) {
      fStack_70 = fStack_58 * fVar10 + fStack_20 + 0.0;
      fStack_68 = (fStack_18 + 0.0) - fStack_60 * fVar10;
      uStack_80 = PAIR44(fStack_5c,fStack_60);
      fStack_78 = fStack_58;
    }
    else {
      fStack_70 = (fStack_20 + 0.0) - fStack_58 * fVar10;
      fStack_68 = fStack_60 * fVar10 + fStack_18 + 0.0;
    }
    if (fVar12 <= fVar13) {
      fStack_4c = fGpffff8030 * *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c) +
                  fStack_4c + 0.0;
    }
    else {
      fStack_4c = fGpffff80bc * *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c) +
                  fStack_4c + 0.0;
    }
    FUN_004be1e0(&fStack_60,0x6978a0,1,&uStack_f4);
    fStack_b0 = fStack_50;
    fStack_ac = fStack_48;
    fStack_a8 = fStack_70;
    fStack_a4 = fStack_68;
    fStack_88 = fStack_40;
    fStack_84 = fStack_38;
    fVar13 = (float)FUN_002d1fd0((f32*)&fStack_b0,(f32*)&fStack_a8,(f32*)&fStack_88,(f32*)&fStack_90);
    fVar15 = *(float *)(iVar1 + 0x90);
    fVar10 = *(float *)(iVar1 + 0x2c);
    fStack_70 = fStack_90;
    fStack_6c = fStack_3c;
    fStack_68 = fStack_8c;
    fVar12 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar6 + 0xb8) * 0.5);
    fVar12 = (fVar15 * fVar10 * 1.5 + fVar13 + 0.0) / fVar12;
    fVar10 = 550.0;
    if (550.0 <= fVar12) {
      fVar10 = fVar12;
    }
    fStack_60 = fStack_60 * fVar10;
    fStack_5c = fStack_5c * fVar10;
    fStack_58 = fStack_58 * fVar10;
    if (0.0 <= fVar14) {
      fVar13 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar6 + 0xb8) * 0.5);
      fVar10 = fVar10 * fVar13 * 0.21875 * 2.0;
      fStack_98 = uStack_80.f._0_4_;
      fStack_94 = fStack_78;
      FUN_004c6b20(&fStack_98,&fStack_98);
      fStack_70 = (fStack_70 + 0.0) - fStack_94 * fVar10;
      fStack_68 = fStack_98 * fVar10 + fStack_68 + 0.0;
    }
    fStack_100 = fStack_70 + fStack_60;
    fStack_fc = fStack_6c + fStack_5c;
    fStack_f8 = fStack_68 + fStack_58;
    uStack_d8 = uStack_f4;
    uStack_d4 = uStack_f0;
    uStack_d0 = uStack_ec;
    uStack_cc = uStack_e8;
    fStack_60 = fStack_10 - fStack_100;
    fStack_5c = fStack_c - fStack_fc;
    fStack_58 = fStack_8 - fStack_f8;
    fStack_e4 = fStack_100;
    fStack_e0 = fStack_fc;
    fStack_dc = fStack_f8;
    fVar10 = (float)FUN_004c69f0(&fStack_60,&fStack_60);
    btlUnitGetSphereWorldCenter((BtlUnit*)(uintptr_t)(iVar7), (RwV3d*)&fStack_40);
    fStack_3c = fGpffff8030 * *(float *)(iVar7 + 0x8c) * *(float *)(iVar7 + 0x2c) + fStack_3c + 0.0;
    fVar10 = fGpffff8098 * fVar10;
    fStack_60 = fStack_60 * fVar10;
    fStack_5c = fStack_5c * fVar10;
    fStack_58 = fStack_58 * fVar10;
    fStack_100 = fStack_e4 + fStack_60;
    fStack_fc = fStack_e0 + fStack_5c;
    fStack_f8 = fStack_dc + fStack_58;
    if (fStack_fc < 25.0) {
      fStack_fc = 25.0;
    }
    if (fStack_e0 < 25.0) {
      fStack_e0 = 25.0;
    }
    uVar11 = 0x40100000;
  }
  if (param_3 == 0) {
    fStack_100 = fStack_e4;
    fStack_fc = fStack_e0;
    fStack_f8 = fStack_dc;
    uStack_f4 = uStack_d8;
    uStack_f0 = uStack_d4;
    uStack_ec = uStack_d0;
    uStack_e8 = uStack_cc;
  }
  FUN_002a3e80_ab330(
      camera->action, &((BtlUnit*)(uintptr_t)iVar7)->pos,
      (f32*)&fStack_100, 3, 50.0f);
  FUN_002a2290((u16*)camera, (RwV3d*)&fStack_100, (RwV3d*)&fStack_e4, 1);
  FUN_002a3110((u16*)camera, *(f32*)&uVar11);
  if (param_2 != 0) {
    FUN_00351bb0(0xc);
  }
  return;
}

// FUN_002AC540

void func_002ac540(BtlCamera* camera)
{
  int iVar2;
  u32 flag1;
  u32 flag2;
  u32 lVar4;
  int iVar5;

  iVar5 = (int)camera;
  iVar2 = *(int *)(*(int *)(*(int *)(iVar5 + 0xe0) + 0x30) + 0xa00);
  flag1 = 1;
  flag2 = flag1;
  *(undefined2 *)(iVar5 + 0x110) = FUN_002a7830(camera);
  if (*(u16 *)(iVar5 + 0xe4) == 0x19) {
    flag1 = 0;
    flag2 = 0;
  }
  if ((iVar2 != 0) && (lVar4 = FUN_002fdbb0(*(undefined4 *)(iVar5 + 0xe0),iVar2), lVar4 != 0)) {
    *(undefined4 *)(iVar5 + 0x114) = 1;
  }
  else {
    *(undefined4 *)(iVar5 + 0x114) = 0;
  }
  switch(*(undefined2 *)(iVar5 + 0x110)) {
  case 1:
    FUN_002a8150(camera,flag1,flag2);
    break;
  case 2:
    FUN_002a95d0(camera,flag1,flag2);
    break;
  case 3:
    func_002aa2b0(camera,flag1,flag2);
    break;
  case 4:
    if (*(int *)(iVar5 + 0x114) == 0) {
      func_002ab330(camera,flag1,flag2);
    }
    else {
      FUN_002a95d0(camera,flag1,flag2);
    }
    break;
  case 5:
    func_002aa2b0(camera,flag1,flag2);
    break;
  case 6:
    FUN_002a79f0(camera,1);
  }
  return;
}

// FUN_002AC6E0

void func_002ac6e0(BtlCamera* camera)
{
    u8* cameraBytes;
    BtlAction* action;
    u16 state;

    cameraBytes = (u8*)camera;
    state = *(u16*)(cameraBytes + 0x110);

    switch (state)
    {
    case 0:
    case 1:
        break;
    case 2:
        action = *(BtlAction**)(cameraBytes + 0xe0);
        if (action != NULL && (action->unk_1a & 1) != 0)
        {
            if (FUN_002a3750(camera, *(u32*)(cameraBytes + 0x120)) != 0)
            {
                btlUnit002880e0((BtlUnit*)(uintptr_t)*(u32*)(cameraBytes + 0x120),
                                *(u16*)(cameraBytes + 0x124));
            }
        }
        break;
    case 3:
        action = *(BtlAction**)(cameraBytes + 0xe0);
        if (action != NULL && (action->unk_1a & 1) != 0)
        {
            if (*(s32*)(cameraBytes + 0xdc) == 0)
            {
                FUN_002a3e80(0.0f, (u8*)action, (u8*)0, (u8*)0, 3);
            }
            if (FUN_002a3750(camera, *(u32*)(cameraBytes + 0x120)) != 0)
            {
                btlUnit002880e0((BtlUnit*)(uintptr_t)*(u32*)(cameraBytes + 0x120),
                                *(u16*)(cameraBytes + 0x124));
            }
        }
        break;
    case 4:
        if (*(s32*)(cameraBytes + 0x114) == 0)
        {
            int actionAddress;

            actionAddress = *(int*)(cameraBytes + 0xe0);
            if (((actionAddress != 0) &&
                 (*(u16*)((u8*)actionAddress + 0x6a) == 1)) &&
                (*(s32*)(cameraBytes + 0x100) == *(s32*)((u8*)actionAddress + 0x38) &&
                 ((*(u16*)((u8*)actionAddress + 0x1a) & 1) != 0)))
            {
                if (FUN_002a3750(camera, *(u32*)(cameraBytes + 0x120)) != 0)
                {
                    btlUnit002880e0((BtlUnit*)(uintptr_t)*(u32*)(cameraBytes + 0x120),
                                    *(u16*)(cameraBytes + 0x124));
                }
                FUN_002a3e80(10.0f, *(u8**)(cameraBytes + 0xe0),
                             cameraBytes + 0x9c, cameraBytes + 0x104, 0x33);
            }
        }
        else
        {
            action = *(BtlAction**)(cameraBytes + 0xe0);
            if (action != NULL && (action->unk_1a & 1) != 0)
            {
                if (FUN_002a3750(camera, *(u32*)(cameraBytes + 0x120)) != 0)
                {
                    btlUnit002880e0((BtlUnit*)(uintptr_t)*(u32*)(cameraBytes + 0x120),
                                    *(u16*)(cameraBytes + 0x124));
                }
            }
        }
        break;
    case 5:
        func_002ab2a0(camera);
        break;
    case 6:
        action = *(BtlAction**)(cameraBytes + 0xe0);
        if (action != NULL && (action->unk_1a & 1) != 0)
        {
            if (FUN_002a3750(camera, *(u32*)(cameraBytes + 0x120)) != 0)
            {
                btlUnit002880e0((BtlUnit*)(uintptr_t)*(u32*)(cameraBytes + 0x120),
                                *(u16*)(cameraBytes + 0x124));
            }
        }
        break;
    }
}

// FUN_002AC920 NONMATCHING

void func_002ac920(BtlCamera* camera, long unused)
{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  undefined4 uVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  undefined1 auStack_e0 [4];
  float fStack_dc;
  undefined1 auStack_d4 [16];
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  undefined1 auStack_b8 [24];
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  GhidraPair uStack_70;
  float fStack_68;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  RwV3d targetCenter;
  RwV3d sourceCenter;
  RtQuat quaternion;
  BtlCameraKeyFrame frame;
  RwV3d firstPoint;
  RwV3d secondPoint;
  
  iVar3 = (int)camera;
  iVar1 = *(int *)(*(int *)(iVar3 + 0xe0) + 0x30);
  iVar6 = *(int *)(*(int *)(*(int *)(iVar3 + 0xe0) + 0x38) + 0x30);
  btlUnitGetSphereWorldCenter((BtlUnit*)(uintptr_t)(iVar1), &sourceCenter);
  btlUnitGetSphereWorldCenter((BtlUnit*)(uintptr_t)(iVar6), &targetCenter);
  fStack_50 = sourceCenter.x - targetCenter.x;
  fStack_4c = sourceCenter.y - targetCenter.y;
  fStack_48 = sourceCenter.z - targetCenter.z;
  fVar7 = (float)FUN_004c69f0(&fStack_50,&fStack_50);
  fStack_98 = *(float *)(iVar3 + 0x9c) - sourceCenter.x;
  fStack_94 = *(float *)(iVar3 + 0xa4) - sourceCenter.z;
  FUN_004c6b20(&fStack_98,&fStack_98);
  fVar7 = DAT_007cad88 * fVar7;
  fStack_40 = fStack_50 * fVar7 + targetCenter.x;
  fStack_3c = fStack_4c * fVar7 + targetCenter.y;
  fStack_38 = fStack_48 * fVar7 + targetCenter.z;
  fVar7 = 0.0;
  fVar13 = fStack_50 * fStack_98 + fStack_48 * fStack_94;
  if (0.0 <= fVar13) {
    fStack_30 = sourceCenter.x;
    fStack_2c = sourceCenter.y;
    fStack_28 = sourceCenter.z;
    fVar8 = 1.5;
    fVar9 = *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c) * 1.5;
    fVar11 = DAT_007cad84;
    iVar4 = iVar1;
    if (sourceCenter.y < 125.0) {
      fStack_2c = 125.0;
      fVar8 = 1.5;
    }
  }
  else {
    fStack_30 = targetCenter.x;
    fStack_2c = targetCenter.y;
    fStack_28 = targetCenter.z;
    if (*(char *)(iVar6 + 0xa2) == '\0') {
      fVar9 = *(float *)(iVar6 + 0x90) * *(float *)(iVar6 + 0x2c) * 1.5;
      fVar8 = 3.5;
    }
    else {
      fVar9 = *(float *)(iVar6 + 0x90) * *(float *)(iVar6 + 0x2c) * 1.25;
      fVar8 = 1.75;
    }
    fVar7 = 0.25;
    fVar11 = fVar7;
    iVar4 = iVar6;
    iVar6 = iVar1;
  }
  fVar2 = fStack_2c;
  fStack_a0 = fStack_48;
  fStack_9c = -fStack_50;
  fVar12 = fStack_48 * fStack_98 + fStack_9c * fStack_94;
  fStack_5c = fVar7 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c) + fStack_2c + 0.0;
  if (0.0 <= fVar12) {
    fStack_60 = fStack_48 * fVar9 + fStack_30 + 0.0;
    fStack_58 = (fStack_28 + 0.0) - fStack_50 * fVar9;
  }
  else {
    fStack_60 = (fStack_30 + 0.0) - fStack_48 * fVar9;
    fStack_58 = fStack_50 * fVar9 + fStack_28 + 0.0;
  }
  uStack_70 = PAIR44(fStack_4c,fStack_50);
  fStack_68 = fStack_48;
  fVar7 = fStack_28;
  firstPoint.x = fStack_60;
  firstPoint.y = fStack_5c;
  firstPoint.z = fStack_58;
  secondPoint.x = fStack_40;
  secondPoint.y = fStack_3c;
  secondPoint.z = fStack_38;
  FUN_002a4690(&quaternion, &firstPoint, &secondPoint, &D_00697880);
  RtQuatTransformVectors((RwV3d*)&fStack_50, &D_006978A0, 1, &quaternion);
  fStack_90 = fStack_40;
  fStack_8c = fStack_38;
  fStack_88 = fStack_60;
  fStack_84 = fStack_58;
  fStack_78 = fStack_30;
  fStack_74 = fVar7;
  fVar7 = (float)FUN_002d1fd0((f32*)&fStack_90,(f32*)&fStack_88,(f32*)&fStack_78,(f32*)&fStack_80);
  fVar9 = fVar8 * *(float *)(iVar4 + 0x90) * *(float *)(iVar4 + 0x2c) + fVar7 + 0.0;
  fStack_60 = fStack_80;
  fStack_5c = fVar2;
  fStack_58 = fStack_7c;
  fVar8 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar3 + 0xb8) * 0.5);
  fVar7 = 500.0;
  if (500.0 <= fVar9 / fVar8) {
    fVar7 = fVar9 / fVar8;
  }
  fStack_50 = fStack_50 * fVar7;
  fStack_4c = fStack_4c * fVar7;
  fStack_48 = fStack_48 * fVar7;
  if (0.0 <= fVar13) {
    if (fVar12 < 0.0) {
      fVar7 = *(float *)(iVar4 + 0x90) * *(float *)(iVar4 + 0x2c);
      fStack_60 = fStack_68 * fVar7 + fStack_60 + 0.0;
      fStack_58 = (fStack_58 + 0.0) - uStack_70.f._0_4_ * fVar7;
    }
  }
  else if (0.0 <= fVar12) {
    fVar7 = *(float *)(iVar4 + 0x90) * *(float *)(iVar4 + 0x2c);
    fStack_60 = (fStack_60 + 0.0) - fStack_68 * fVar7;
    fStack_58 = uStack_70.f._0_4_ * fVar7 + fStack_58 + 0.0;
  }
  fStack_5c = fVar11 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c) + fVar2 + 0.0;
  fStack_c4 = fStack_60 + fStack_50;
  fStack_c0 = fStack_5c + fStack_4c;
  fStack_bc = fStack_58 + fStack_48;
  fVar7 = (float)FUN_002d1f30(auStack_d4,auStack_b8);
  if (DAT_007cae24 < fVar7) {
    FUN_004be1e0(&fStack_50,0x6978a0,1,auStack_d4);
    fStack_50 = fStack_50 * 150.0;
    fStack_4c = fStack_4c * 150.0;
    fStack_48 = fStack_48 * 150.0;
    fStack_c4 = fStack_c4 + fStack_50;
    fStack_c0 = fStack_c0 + fStack_4c;
    fStack_bc = fStack_bc + fStack_48;
    uVar5 = 3;
    FUN_00351bb0(0xc);
    uVar10 = 0x3fc00000;
  }
  else {
    uVar5 = 0x33;
    uVar10 = DAT_007cad98;
  }
  if (fStack_dc < 25.0) {
    fStack_dc = 25.0;
  }
  if (fStack_c0 < 25.0) {
    fStack_c0 = 25.0;
  }
  return;
}

// FUN_002ACF90 NONMATCHING

void func_002acf90(BtlCamera* camera, long unused)
{
    u32 temp;
    u32 mode;
    u32 i;
    u32 rand;
    u16 targetId;
    f32 radius;
    f32 distance;
    f32 maxDistance;
    f32 sideDistance;
    f32 angle;
    f32 scale;
    f32 speed;
    f32 centerX;
    f32 centerZ;
    struct {
        RwV3d v50;
        u8 result2[0x10];
        RwV3d v6c;
        u8 result[0x18];
        RwMatrix matrix;
        u8 gap1[8];
        f32 d8;
        f32 dc;
        GhidraPair pair;
        f32 e8;
        u8 gap2[4];
        RwV3d vf0;
        u8 gap3[4];
        RwV3d v100;
        u8 gap4[4];
        RwV3d v110;
        u8 gap5[4];
        RwV3d v120;
        u8 gap6[4];
        RwV3d v130;
        u8 gap7[4];
        f32 f140;
        f32 f144;
        f32 f148;
        f32 f14c;

    } scratch;

    temp = FUN_002a3820_u32((int)camera);
    FUN_002a4470((f32*)&scratch.v50, (f32*)&camera->pos);
    if (camera->action->target.targetedCount >= 2) {
        mode = FUN_002d1600((int)&camera->action->target);
    } else {
        mode = 3;
    }
    mode &= 0xffff;
    distance = FUN_00280870(mode, 1, (void*)&scratch.f140, (void*)&scratch.f14c, 0, 0);
    scratch.f144 = scratch.f14c * 0.75f;
    maxDistance = distance /
                  FUN_0052e930(DAT_007cad60 * camera->fovRad * 0.5f);
    if (maxDistance < 1000.0f) {
        maxDistance = 1000.0f;
    }
    FUN_00280870(mode, 1, (void*)&scratch.v130, 0, 0, 1);
    sideDistance = 0.0f;
    i = 0;
    while (i < camera->action->target.targetedCount) {
        BtlAction* action = camera->action->target.targetedActions[i & 0xffff];
        if ((action->unk_1a & 1) != 0) {
            FUN_00280050(action->unit, &scratch.vf0);
            scratch.v120.x = scratch.v130.x - scratch.vf0.x;
            scratch.v120.y = scratch.v130.y - scratch.vf0.y;
            scratch.v120.z = scratch.v130.z - scratch.vf0.z;
            scale = RwV3dLength((const RwV3d*)&scratch.v120);
            if (scale > sideDistance) {
                *(u64*)&scratch.pair = *(u64*)&scratch.vf0;
                scratch.e8 = scratch.vf0.z;
                sideDistance = scale;
            }
        }
        i = (i + 1) & 0xffff;
    }
    if (sideDistance == 0.0f) {
        FUN_00280050(gBtl->actionList.head->unit, (f32*)&scratch.pair);
    }
    scratch.pair.f._4_4_ = scratch.f144;
    scratch.v120.x = scratch.pair.f._0_4_ - scratch.f140;
    scratch.v120.y = scratch.pair.f._4_4_ - scratch.pair.f._4_4_;
    scratch.v120.z = scratch.e8 - scratch.f148;
    FUN_004c69f0((RwV3d*)&scratch.v120, (RwV3d*)&scratch.v120);
    scratch.v120.x = scratch.v120.x * distance;
    scratch.v120.y = scratch.v120.y * distance;
    scratch.v120.z = scratch.v120.z * distance;
    centerX = scratch.f140 + scratch.v120.x;
    centerZ = scratch.f148 + scratch.v120.z;
    speed = scratch.f14c * 1.5f;
    scratch.v110.x = centerX - scratch.f140;
    scratch.v110.y = 0.0f;
    scratch.v110.z = centerZ - scratch.f148;
    scale = FUN_004c69f0((RwV3d*)&scratch.v110, (RwV3d*)&scratch.v110);
    scale = DAT_007cad84 * scale;
    scratch.v110.x = scratch.v110.x * scale;
    scratch.v110.y = scratch.v110.y * scale;
    scratch.v110.z = scratch.v110.z * scale;
    scratch.v100.x = scratch.f140 + scratch.v110.x;
    scratch.v100.y = scratch.f144 + scratch.v110.y;
    scratch.v100.z = scratch.f148 + scratch.v110.z;
    scratch.v100.y = scratch.f144;
    if (speed < 250.0f) {
        speed = 250.0f;
    }
    scratch.v120.x = scratch.v100.x - scratch.f140;
    scratch.v120.y = speed - scratch.v100.y;
    scratch.v120.z = scratch.v100.z - scratch.f148;
    FUN_004c69f0((RwV3d*)&scratch.v120, (RwV3d*)&scratch.v120);
    scale = FUN_0052e930(DAT_007cad60 * camera->fovRad * 0.5f);
    scale = maxDistance * scale * 0.21875f;
    scratch.d8 = scratch.v120.x;
    scratch.dc = scratch.v120.z;
    FUN_004c6b20((f32*)&scratch.d8, (f32*)&scratch.d8);
    scratch.v100.x = scratch.dc * scale + scratch.v100.x + 0.0f;
    scratch.v100.z = (scratch.v100.z + 0.0f) - scratch.d8 * scale;
    rand = FUN_00357fd0(0);
    if ((rand & 1) != 0) {
        angle = 7.5f;
    } else {
        angle = -7.5f;
    }
    FUN_004c31b0_typed((RwMatrix*)&scratch.matrix, &D_00697880, angle, 0);
    FUN_004c6c60(&scratch.v110, &scratch.v120, &scratch.matrix);
    scratch.v110.x = scratch.v110.x * maxDistance;
    scratch.v110.y = scratch.v110.y * maxDistance;
    scratch.v110.z = scratch.v110.z * maxDistance;
    scratch.v6c.x = scratch.v100.x + scratch.v110.x;
    scratch.v6c.y = scratch.v100.y + scratch.v110.y;
    scratch.v6c.z = scratch.v100.z + scratch.v110.z;
    FUN_002a4690((void*)scratch.result, (const void*)&scratch.v6c, (const void*)&scratch.v100, &D_00697880);
    if (temp == 0) {
        FUN_004c31b0_typed((RwMatrix*)&scratch.matrix, &D_00697880, -angle, 0);
        FUN_004c6c60(&scratch.v110, &scratch.v120, &scratch.matrix);
        scratch.v110.x = scratch.v110.x * maxDistance;
        scratch.v110.y = scratch.v110.y * maxDistance;
        scratch.v110.z = scratch.v110.z * maxDistance;
        scratch.v50.x = scratch.v100.x + scratch.v110.x;
        scratch.v50.y = scratch.v100.y + scratch.v110.y;
        scratch.v50.z = scratch.v100.z + scratch.v110.z;
        FUN_002a4690((void*)scratch.result2, (const void*)&scratch.v50, (const void*)&scratch.v100, &D_00697880);
        FUN_00351bb0(0xc);
        speed = 8.0f;
    } else {
        scratch.v50 = scratch.v6c;
        targetId = camera->action->target.specificId;
        switch (targetId) {
        case 0x26:
            scratch.v50.y = 500.0f;
            scratch.v100.y = 450.0f;
            speed = 2.75f;
            break;
        case 0x27:
            scratch.v50.y = 600.0f;
            scratch.v100.y = 550.0f;
            speed = 3.0f;
            break;
        case 0x2c:
            scratch.v50.y = 800.0f;
            scratch.v100.y = 700.0f;
            speed = 3.75f;
            break;
        case 0x38:
            scratch.v50.y = 1000.0f;
            scratch.v100.y = 750.0f;
            speed = 2.5f;
            break;
        default:
            scratch.v50.y = 500.0f;
            scratch.v100.y = 450.0f;
            speed = 2.75f;
            break;
        }
        FUN_002a4690((void*)scratch.result2, (const void*)&scratch.v50, (const void*)&scratch.v100, &D_00697880);
        FUN_00351bb0(0xc);
    }
    FUN_002a3590((f32*)&scratch.v50, (f32*)&scratch.v50);
    FUN_002a3590((f32*)&scratch.v6c, (f32*)&scratch.v6c);
    FUN_002a2290((u16*)camera, (RwV3d*)&scratch.v50, (RwV3d*)&scratch.v6c, 1);
    FUN_002a3110((u16*)camera, speed);
}

// FUN_002AD680

void func_002ad680(BtlCamera* camera)
{
  undefined2 uVar1;
  
  uVar1 = btlCameraSelectMode(camera);
  *(undefined2 *)((int)camera + 0x110) = uVar1;
  switch(*(undefined2 *)((int)camera + 0x110)) {
  case 1:
    FUN_002a4c70(45.0f,200.0f,camera);
    break;
  case 2:
    func_002ac920(camera,1);
    break;
  case 3:
    func_002acf90(camera,1);
    break;
  case 4:
    func_002ac920(camera,1);
    break;
  case 5:
    func_002acf90(camera,1);
    break;
  case 6:
    FUN_002a79f0(camera,1);
  }
  return;
}

// FUN_002AD770

void func_002ad770(BtlCamera* camera)
{
  int iVar1;
  long lVar2;
  int iVar3;
  undefined1 auStack_10 [16];
  
  iVar3 = (int)camera;
  switch(*(undefined2 *)(iVar3 + 0x110)) {
  case 2:
  case 3:
  case 4:
  case 5:
    break;
  case 1:
    iVar1 = *(int *)(iVar3 + 0xe0);
    if ((iVar1 != 0) && ((*(ushort *)(iVar1 + 0x1a) & 1) != 0)) {
      iVar1 = *(int *)(iVar1 + 0x30);
      btlUnitGetSphereWorldCenter((BtlUnit*)(uintptr_t)(iVar1), (RwV3d*)auStack_10);
      FUN_002a3e80(*(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c) * 0.5f,
                   (u8*)(uintptr_t)*(undefined4 *)(iVar3 + 0xe0),(u8*)(uintptr_t)(iVar3 + 0x9c),
                   (u8*)auStack_10,0x31);
    }
    break;
  case 6:
    if (((*(int *)(iVar3 + 0xe0) != 0) && ((*(ushort *)(*(int *)(iVar3 + 0xe0) + 0x1a) & 1) != 0))
       && (FUN_002a3750(camera,*(undefined4 *)(iVar3 + 0x120)) != 0)) {
      btlUnit002880e0((BtlUnit*)(uintptr_t)(*(undefined4 *)(iVar3 + 0x120)),*(undefined2 *)(iVar3 + 0x124));
    }
  }
  return;
}


// FUN_002ad880
void func_002ad880(BtlCamera *camera, float angle, float distanceScale, float heightScale, float minimumDistance)
{
  extern void FUN_004c31b0(RwMatrix *matrix, const RwV3d *axis, f32 angle, s32 mode);
  extern void FUN_004be1e0(RwV3d *out, const RwV3d *basis, s32 mode, void *source);
  extern RwV3d D_00697890;
  typedef struct CameraVectorSlot {
    RwV3d value;
    u32 padding;
  } CameraVectorSlot;
  struct CameraOrbitScratch {
    RwMatrix rotation;
    RwV3d firstPosition;
    u8 firstView[16];
    RwV3d secondPosition;
    u8 secondView[24];
    CameraVectorSlot scaledOffset;
    CameraVectorSlot candidate;
    CameraVectorSlot direction;
    CameraVectorSlot forward;
    CameraVectorSlot center;
    CameraVectorSlot sphereCenter;
  } scratch;
  u8 *unitBytes;
  int cameraAddress;
  float radius;
  float halfHeight;
  float requiredDistance;
  u64 centerXY;
  float centerZ;

  cameraAddress = (int)camera;
  unitBytes = (u8 *)(uintptr_t)*(int *)(*(int *)(cameraAddress + 0xe0) + 0x30);
  btlUnitGetSphereWorldCenter((BtlUnit *)unitBytes, &scratch.sphereCenter.value);
  radius = *(float *)(unitBytes + 0x90) * *(float *)(unitBytes + 0x2c);
  halfHeight = *(float *)(unitBytes + 0x8c) * *(float *)(unitBytes + 0x2c) * 0.5f;
  centerXY = *(volatile u64 *)&scratch.sphereCenter.value;
  centerZ = *(volatile f32 *)&scratch.sphereCenter.value.z;
  *(u64 *)&scratch.center.value = centerXY;
  scratch.center.value.z = centerZ;
  scratch.center.value.y = halfHeight * heightScale + scratch.center.value.y + 0.0f;
  if (radius > halfHeight) {
    requiredDistance = (radius * distanceScale) /
      FUN_0052e930(DAT_007cad60 * (*(float *)(cameraAddress + 0xb8) * 0.5f));
  } else {
    requiredDistance = (halfHeight * distanceScale) /
      FUN_0052e930(*(float *)(cameraAddress + 0xb8) * 0.5f);
  }
  if (requiredDistance < minimumDistance) {
    requiredDistance = minimumDistance;
  }
  FUN_004be1e0(&scratch.forward.value, &D_00697890, 1, (void *)(unitBytes + 0x1c));
  scratch.scaledOffset.value.x = scratch.forward.value.x * radius;
  scratch.scaledOffset.value.y = scratch.forward.value.y * radius;
  scratch.scaledOffset.value.z = scratch.forward.value.z * radius;
  scratch.candidate.value.x = scratch.center.value.x + scratch.scaledOffset.value.x;
  scratch.candidate.value.y = scratch.center.value.y + scratch.scaledOffset.value.y;
  scratch.candidate.value.z = scratch.center.value.z + scratch.scaledOffset.value.z;
  scratch.candidate.value.y = DAT_007cada4 * halfHeight + scratch.candidate.value.y + 0.0f;
  scratch.direction.value.x = scratch.candidate.value.x - scratch.center.value.x;
  scratch.direction.value.y = scratch.candidate.value.y - scratch.center.value.y;
  scratch.direction.value.z = scratch.candidate.value.z - scratch.center.value.z;
  FUN_004c69f0(&scratch.direction.value, &scratch.direction.value);
  scratch.scaledOffset.value.x = scratch.direction.value.x * requiredDistance;
  scratch.scaledOffset.value.y = scratch.direction.value.y * requiredDistance;
  scratch.scaledOffset.value.z = scratch.direction.value.z * requiredDistance;
  FUN_004c31b0(&scratch.rotation, &D_00697880, angle, 0);
  FUN_004c6c60(&scratch.direction.value, &scratch.scaledOffset.value, &scratch.rotation);
  scratch.candidate.value.x = scratch.center.value.x + scratch.direction.value.x;
  scratch.candidate.value.y = scratch.center.value.y + scratch.direction.value.y;
  scratch.candidate.value.z = scratch.center.value.z + scratch.direction.value.z;
  FUN_002a4690(scratch.firstView, &scratch.candidate.value, &scratch.center.value, &D_00697880);
  scratch.firstPosition.x = scratch.center.value.x + scratch.direction.value.x;
  scratch.firstPosition.y = scratch.center.value.y + scratch.direction.value.y;
  scratch.firstPosition.z = scratch.center.value.z + scratch.direction.value.z;
  FUN_004c31b0(&scratch.rotation, &D_00697880, -angle, 0);
  FUN_004c6c60(&scratch.direction.value, &scratch.scaledOffset.value, &scratch.rotation);
  scratch.candidate.value.x = scratch.center.value.x + scratch.direction.value.x;
  scratch.candidate.value.y = scratch.center.value.y + scratch.direction.value.y;
  scratch.candidate.value.z = scratch.center.value.z + scratch.direction.value.z;
  FUN_002a4690(scratch.secondView, &scratch.candidate.value, &scratch.center.value, &D_00697880);
  scratch.secondPosition.x = scratch.center.value.x + scratch.direction.value.x;
  scratch.secondPosition.y = scratch.center.value.y + scratch.direction.value.y;
  scratch.secondPosition.z = scratch.center.value.z + scratch.direction.value.z;
  FUN_002a3e80(0.0f, *(u8 **)(cameraAddress + 0xe0), NULL, NULL, 1);
  FUN_002a2290((u16 *)camera, &scratch.firstPosition, &scratch.secondPosition, 1);
  FUN_002a3110((u16 *)camera, 3.5f);
}

// FUN_002ADC30

void func_002adc30(BtlCamera* camera)
{
  func_002ad880(camera,10.0f,2.0f,0.0f,250.0f);
  return;
}

// FUN_002ADC70
void btlCameraNoop002adc70(void)
{
}

// FUN_002ADC80
void func_002adc80(BtlCamera* camera)

{
  func_002ad880(camera,15.0f,2.0f,0.25f,400.0f);
  return;
}

// FUN_002ADCC0
void btlCameraNoop002adcc0(void)
{
}

// FUN_002ADCD0

void func_002adcd0(BtlCamera* camera)
{
  FUN_002a8d20(camera,1);
  return;
}

// FUN_002ADD00

void func_002ADD00(void)
{
  return;
}

// FUN_002ADD10 NONMATCHING

u32 func_002add10(BtlCamera* camera, u32 param_2, float* param_3, float* param_4)
{
    extern u64 FUN_002d1de0(RtQuat* out, RwV3d* first, RwV3d* second);
    extern f32 FUN_002d1f30(f32* first, f32* second);
    extern f32 FUN_004c69f0(f32* out, f32* in);
    extern void FUN_004be1e0(RwV3d* out, const RwV3d* basis, s32 mode, void* source);
    struct Work
    {
        RtQuat quaternion;
        BtlCameraKeyFrame first;
        BtlCameraKeyFrame second;
        f32 pad48[2];
        RwV3d generated;
        f32 pad5c;
        RwV3d center;
        f32 pad6c;
        f32 spe0;
        f32 spe4;
        f32 spe8;
        f32 pad7c;
        f32 spf0;
        f32 spf4;
        f32 spf8;
        f32 pad8c;
        RwV3d transformed;
        f32 sp10c;
    } work;
    BtlCamera* cam;
    volatile f32 lowPad[4];
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f22;
    f32 var_f20;
    u32* src;
    int count;
    u32 value;

    cam = camera;
    lowPad[0] = 0.0f;
    FUN_002a4470((f32*)&work.first, (f32*)&cam->pos);
    temp_f21 = FUN_00280870(2, 0, &work.generated, &work.sp10c, 0, 1);
    work.generated.y = DAT_007cadb4 * work.sp10c;
    temp_f22 = cam->action->unit->sphereRadius *
               cam->action->unit->scale;
    temp_f20 = temp_f22 * DAT_007cadfc;
    btlUnitGetSphereWorldCenter(cam->action->unit, &work.center);
    FUN_002d1de0(&work.quaternion, &work.center, &work.generated);
    work.center.y = DAT_007cad54 * temp_f22 + work.center.y + 0.0f;
    FUN_004be1e0(&work.transformed, &D_00697870, 1, &work.quaternion);
    temp_f3 = work.transformed.x * temp_f20;
    work.transformed.x = temp_f3;
    temp_f2 = work.transformed.y * temp_f20;
    work.transformed.y = temp_f2;
    temp_f1 = work.transformed.z * temp_f20;
    work.transformed.z = temp_f1;
    work.center.x = work.center.x + temp_f3;
    work.center.y = work.center.y + temp_f2;
    work.center.z = work.center.z + temp_f1;
    work.spf0 = work.center.x - work.generated.x;
    work.spf4 = work.center.y - work.generated.y;
    work.spf8 = work.center.z - work.generated.z;
    temp_f0 = FUN_004c69f0(&work.spf0, &work.spf0);
    temp_f1 = DAT_007cae00 * temp_f0;
    work.spe0 = work.spf0 * temp_f1;
    work.spe4 = work.spf4 * temp_f1;
    work.spe8 = work.spf8 * temp_f1;
    work.spe0 = work.spe0 + work.generated.x;
    work.spe4 = work.spe4 + work.generated.y;
    work.spe8 = work.spe8 + work.generated.z;
    work.transformed = work.center;
    work.transformed.z = work.center.z;
    FUN_002a4690(&work.second.rot, &work.transformed, &work.spe0,
                 &D_00697880);
    if (FUN_002d1f30((f32*)&work.first.rot, (f32*)&work.second.rot) >
        DAT_007cae00) {
        param_2 = 1;
    }
    temp_f22 = cam->action->unit->unk_8c *
               cam->action->unit->scale;
    var_f20 = temp_f22 / tanf(0.5f * cam->fovRad) + temp_f0;
    temp_f0 = (0.875f * temp_f21) / tanf(0.5f * cam->fovRad);
    if (var_f20 <= temp_f0) {
        var_f20 = temp_f0;
    }
    FUN_004be1e0(&work.transformed, &D_006978A0, 1, &work.second.rot);
    temp_f0 = tanf(DAT_007cad60 * (0.5f * cam->fovRad));
    temp_f5 = work.transformed.z *
                  (var_f20 * temp_f0 * 0.109375f * 1.25f) +
              work.generated.x + 0.0f;
    work.generated.x = temp_f5;
    temp_f4 = (work.generated.z + 0.0f) -
              work.transformed.x *
                  (var_f20 * temp_f0 * 0.109375f * 1.25f);
    work.generated.z = temp_f4;
    work.transformed.x = work.transformed.x * var_f20;
    work.transformed.y = work.transformed.y * var_f20;
    work.transformed.z = work.transformed.z * var_f20;
    work.second.pos.x = temp_f5 + work.transformed.x;
    work.second.pos.y = work.generated.y + work.transformed.y;
    work.second.pos.z = temp_f4 + work.transformed.z;
    if (work.first.pos.y < 25.0f) {
        work.first.pos.y = 25.0f;
    }
    if (work.second.pos.y < 25.0f) {
        work.second.pos.y = 25.0f;
    }
    if (param_3 != NULL) {
        src = (u32*)&work.first;
        count = 7;
        do {
            value = *src;
            src = src + 1;
            count = count - 1;
            *(u32*)param_3 = value;
            param_3 = (float*)((u32*)param_3 + 1);
        } while (count > 0);
    }
    if (param_4 != NULL) {
        src = (u32*)&work.second;
        count = 7;
        do {
            value = *src;
            src = src + 1;
            count = count - 1;
            *(u32*)param_4 = value;
            param_4 = (float*)((u32*)param_4 + 1);
        } while (count > 0);
    }
    return param_2;
}

// FUN_002AE150

void func_002ae150(BtlCamera* camera)
{
  u16 st;
  int flag;
  f32 buf[16];

  st = *(u16 *)(iGpffffb6fc + 0x104);
  switch (st) {
  case 0x1d:
  case 0x22:
  case 2:
  case 0x23:
    flag = 0;
    break;
  default:
    flag = 1;
    break;
  }
  if (func_002add10(camera, flag, buf, buf + 7) != 0) {
    FUN_00351bb0(8);
    FUN_002a3e80(0.0f, *(u8 **)((u8 *)camera + 0xe0), 0, 0, 0x40);
    FUN_002a2170(camera, buf + 7);
  }
  else {
    FUN_002a2290((u16 *)camera, (RwV3d *)buf, (RwV3d *)(buf + 7), 1);
    FUN_002a3110((u16 *)camera, 1.25f);
  }
}

// FUN_002ae250
void func_002ae250(void)
{
}

// FUN_002AE260

void func_002ae260(BtlCamera* camera)
{
  BtlUnit* unit;
  f32 buf[28];
  f32 fVar0;
  f32 fVar1;
  f32 fVar2;
  f32 fVar3;
  f32 fVar4;
  f32 fVar5;
  f32 fVar6;
  f32 fVar7;
  f32 fVar8;
  f32 fVar9;
  f32 fVar20;
  f32 fVar23;
  f32 fVar22;
  f32 fVar21;

  unit = camera->action->unit;
  btlUnitGetSphereWorldCenter(unit, (RwV3d *)(buf + 24));
  fVar20 = unit->sphereRadius * unit->scale;
  fVar21 = unit->unk_8c * unit->scale * 0.5f;
  buf[25] = fVar21 * 0.25f + buf[25] + 0.0f;
  if (fVar20 > fVar21) {
    fVar20 = (1.25f * fVar20) /
      FUN_0052e930(gp0xffff8070 * (camera->fovRad * 0.5f));
  }
  else {
    fVar20 = (1.25f * fVar21) /
      FUN_0052e930(camera->fovRad * 0.5f);
  }
  FUN_004be1e0((RwV3d *)(buf + 20), &D_00697890, 1, &unit->rot);
  fVar4 = fVar20 + 125.0f;
  fVar23 = buf[20] * fVar4;
  fVar22 = buf[21] * fVar4;
  fVar21 = buf[22] * fVar4;
  buf[16] = buf[24] + fVar23;
  buf[17] = buf[25] + fVar22;
  buf[18] = buf[26] + fVar21;
  FUN_002a4690(&buf[3], &buf[16], (RwV3d *)(buf + 24), &D_00697880);
  fVar9 = buf[24];
  buf[0] = fVar9 + fVar23;
  fVar8 = buf[25];
  buf[1] = fVar8 + fVar22;
  fVar7 = buf[26];
  buf[2] = fVar7 + fVar21;
  *(F32Vec4 *)(buf + 10) = *(F32Vec4 *)(buf + 3);
  buf[7] = buf[20] * fVar20 + fVar9 + 0.0f;
  buf[8] = buf[21] * fVar20 + fVar8 + 0.0f;
  buf[9] = buf[22] * fVar20 + fVar7 + 0.0f;
  FUN_002a3e80(0.0f, (u8 *)camera->action, 0, 0, 1);
  FUN_002a2290((u16 *)camera, (RwV3d *)buf, (RwV3d *)(buf + 7), 1);
  FUN_002a3110((u16 *)camera, 2.5f);
}

// FUN_002AE4D0

void func_002ae4d0(BtlCamera* camera)
{
  BtlUnit* unit;
  f32 buf[28];
  f32 fVar0;
  f32 fVar1;
  f32 fVar2;
  f32 fVar3;
  f32 fVar4;
  f32 fVar5;
  f32 fVar6;
  f32 fVar7;
  f32 fVar8;
  f32 fVar9;
  f32 fVar20;
  f32 fVar23;
  f32 fVar22;
  f32 fVar21;

  unit = camera->action->unit;
  btlUnitGetSphereWorldCenter(unit, (RwV3d *)(buf + 24));
  fVar20 = unit->sphereRadius * unit->scale;
  fVar21 = unit->unk_8c * unit->scale * 0.5f;
  buf[25] = fVar21 * 0.25f + buf[25] + 0.0f;
  if (fVar20 > fVar21) {
    fVar20 = (1.5f * fVar20) /
      FUN_0052e930(gp0xffff8070 * (camera->fovRad * 0.5f));
  }
  else {
    fVar20 = (1.5f * fVar21) /
      FUN_0052e930(camera->fovRad * 0.5f);
  }
  FUN_004be1e0((RwV3d *)(buf + 20), &D_00697890, 1, &unit->rot);
  fVar4 = fVar20 + 125.0f;
  fVar23 = buf[20] * fVar4;
  fVar22 = buf[21] * fVar4;
  fVar21 = buf[22] * fVar4;
  buf[16] = buf[24] + fVar23;
  buf[17] = buf[25] + fVar22;
  buf[18] = buf[26] + fVar21;
  FUN_002a4690(&buf[3], &buf[16], (RwV3d *)(buf + 24), &D_00697880);
  fVar9 = buf[24];
  buf[0] = fVar9 + fVar23;
  fVar8 = buf[25];
  buf[1] = fVar8 + fVar22;
  fVar7 = buf[26];
  buf[2] = fVar7 + fVar21;
  *(F32Vec4 *)(buf + 10) = *(F32Vec4 *)(buf + 3);
  buf[7] = buf[20] * fVar20 + fVar9 + 0.0f;
  buf[8] = buf[21] * fVar20 + fVar8 + 0.0f;
  buf[9] = buf[22] * fVar20 + fVar7 + 0.0f;
  FUN_002a3e80(0.0f, (u8 *)camera->action, 0, 0, 1);
  FUN_002a2290((u16 *)camera, (RwV3d *)(buf + 7), (RwV3d *)buf, 1);
  FUN_002a3110((u16 *)camera, 2.5f);
}

// FUN_002AE4C0
void func_002ae4c0(void)
{
}

// FUN_002AE730
void func_002ae730(void)
{
}

// FUN_002AE740 NONMATCHING

void func_002ae740(BtlCamera* camera, int param_2)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fStack_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  int iStack_ec;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  undefined1 auStack_d4 [16];
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  undefined1 auStack_b8 [24];
  undefined1 auStack_a0 [28];
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float afStack_60 [2];
  float fStack_58;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar5 = (int)camera;
  iVar1 = *(int *)(iVar5 + 0xe0);
  uVar2 = *(undefined4 *)(iVar1 + 0x30);
  iVar3 = FUN_002c0880(iVar1 + 0x88);
  fVar6 = (float)func_00280870(3,lVar4 == 0,&fStack_30,&fStack_4,&fStack_8,1);
  fStack_2c = (fStack_4 - fStack_8) * 0.5 + fStack_8 + 0.0;
  fVar7 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar5 + 0xb8) * 0.5);
  fVar7 = (DAT_007cae18 * fVar6) / fVar7;
  func_00280050(uVar2,afStack_60);
  fStack_40 = afStack_60[0];
  fStack_3c = fStack_2c;
  fStack_38 = fStack_58;
  fStack_50 = afStack_60[0] - fStack_30;
  fStack_4c = fStack_2c - fStack_2c;
  fStack_48 = fStack_58 - fStack_28;
  fVar6 = (float)FUN_004c69f0(&fStack_50,&fStack_50);
  fVar6 = fVar6 * 0.5;
  fStack_50 = fStack_50 * fVar6;
  fStack_4c = fStack_4c * fVar6;
  fStack_48 = fStack_48 * fVar6;
  fStack_20 = fStack_30 + fStack_50;
  fStack_1c = fStack_2c + fStack_4c;
  fStack_18 = fStack_28 + fStack_48;
  fStack_40 = afStack_60[0];
  fStack_3c = fStack_4 * 2.0;
  fStack_38 = fStack_58;
  FUN_004be1e0(&fStack_50,0x6978a0,1,auStack_d4);
  fStack_50 = fStack_50 * fVar7;
  fStack_4c = fStack_4c * fVar7;
  fStack_48 = fStack_48 * fVar7;
  fVar6 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar5 + 0xb8) * 0.5);
  fVar6 = fVar7 * fVar6 * 0.21875;
  fStack_10 = fStack_50;
  fStack_c = fStack_48;
  FUN_004c6b20(&fStack_10,&fStack_10);
  fStack_20 = fStack_c * fVar6 + fStack_20 + 0.0;
  fStack_18 = (fStack_18 + 0.0) - fStack_10 * fVar6;
  fStack_e0 = fStack_20 + fStack_50;
  fStack_dc = fStack_1c + fStack_4c;
  fStack_d8 = fStack_18 + fStack_48;
  if (iVar1 == iVar3) {
    if (*(short *)(iVar5 + 0x106) == 0) {
      fStack_40 = afStack_60[0];
      fStack_3c = fStack_2c;
      fStack_38 = fStack_58;
      fStack_50 = afStack_60[0] - fStack_30;
      fStack_4c = fStack_2c - fStack_2c;
      fStack_48 = fStack_58 - fStack_28;
      fVar8 = (float)FUN_004c69f0(&fStack_50,&fStack_50);
      fVar6 = DAT_007cae18 * fVar8;
      fStack_20 = fStack_30 + fStack_50 * fVar6;
      fStack_1c = fStack_2c + fStack_4c * fVar6;
      fStack_18 = fStack_28 + fStack_48 * fVar6;
      fStack_40 = fStack_50 * fVar8 * 0.5 + afStack_60[0];
      fStack_3c = fStack_4 * 1.5;
      fStack_38 = fStack_48 * fVar8 * 0.5 + fStack_58;
      FUN_004be1e0(&fStack_50,0x6978a0,1,&fStack_78);
      fStack_50 = fStack_50 * fVar7;
      fStack_4c = fStack_4c * fVar7;
      fStack_48 = fStack_48 * fVar7;
      fVar6 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar5 + 0xb8) * 0.5);
      fVar6 = fVar7 * fVar6 * 0.21875;
      fStack_10 = fStack_50;
      fStack_c = fStack_48;
      FUN_004c6b20(&fStack_10,&fStack_10);
      fStack_20 = fStack_c * fVar6 + fStack_20 + 0.0;
      fStack_18 = (fStack_18 + 0.0) - fStack_10 * fVar6;
      fStack_84 = fStack_20 + fStack_50;
      fStack_80 = fStack_1c + fStack_4c;
      fStack_7c = fStack_18 + fStack_48;
    }
    else {
    }
  }
  else {
    func_00280050(*(undefined4 *)(iVar3 + 0x30),&fStack_20);
    FUN_004be1e0(&fStack_50,0x6978a0,1,auStack_b8);
    fStack_50 = fStack_50 * fVar7;
    fStack_4c = fStack_4c * fVar7;
    fStack_48 = fStack_48 * fVar7;
    fVar6 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar5 + 0xb8) * 0.5);
    fVar6 = fVar7 * fVar6 * 0.21875;
    fStack_10 = fStack_50;
    fStack_c = fStack_48;
    FUN_004c6b20(&fStack_10,&fStack_10);
    fStack_20 = fStack_c * fVar6 + fStack_20 + 0.0;
    fStack_18 = (fStack_18 + 0.0) - fStack_10 * fVar6;
    fStack_c4 = fStack_20 + fStack_50;
    fStack_c0 = fStack_1c + fStack_4c;
    fStack_bc = fStack_18 + fStack_48;
    if (*(short *)(iVar5 + 0x106) == 0) {
      FUN_004be310(auStack_d4,auStack_b8,&fStack_110);
      fVar6 = DAT_007cad94;
      fVar7 = DAT_007cad84;
      if (iStack_ec == 0) {
        fVar7 = DAT_007cad94 * fStack_f0;
        fVar6 = fVar7 * fVar7;
        fVar6 = fVar6 * fVar7 *
                (fVar6 * (fVar6 * (fVar6 * (fVar6 * (DAT_007cae04 * fVar6 + DAT_007cad38 + 0.0) +
                                           DAT_007cae08 + 0.0) + DAT_007cad40 + 0.0) +
                         DAT_007cad44 + 0.0) + DAT_007cad48 + 0.0) + fVar7 + 0.0;
        fStack_f0 = DAT_007cad84 * fStack_f0;
        fVar7 = fStack_f0 * fStack_f0;
        fVar7 = fVar7 * fStack_f0 *
                (fVar7 * (fVar7 * (fVar7 * (fVar7 * (DAT_007cae04 * fVar7 + DAT_007cad38 + 0.0) +
                                           DAT_007cae08 + 0.0) + DAT_007cad40 + 0.0) +
                         DAT_007cad44 + 0.0) + DAT_007cad48 + 0.0) + fStack_f0 + 0.0;
      }
      fStack_78 = fStack_100 * fVar7 + fStack_110 * fVar6 + 0.0;
      fStack_74 = fStack_fc * fVar7 + fStack_10c * fVar6 + 0.0;
      fStack_70 = fStack_f8 * fVar7 + fStack_108 * fVar6 + 0.0;
      fStack_6c = fStack_104 * fVar6 + fStack_f4 * fVar7;
      fStack_e0 = fStack_e0 * DAT_007cad94;
      fStack_dc = fStack_dc * DAT_007cad94;
      fStack_d8 = fStack_d8 * DAT_007cad94;
      fStack_c4 = fStack_c4 * DAT_007cad84;
      fStack_c0 = fStack_c0 * DAT_007cad84;
      fStack_bc = fStack_bc * DAT_007cad84;
      fStack_84 = fStack_e0 + fStack_c4;
      fStack_80 = fStack_dc + fStack_c0;
      fStack_7c = fStack_d8 + fStack_bc;
    }
    else {
    }
  }
  if (param_2 == 0) {
  }
  else {
  }
  return;
}

// FUN_002AEF80 NONMATCHING

void func_002aef80(BtlCamera* camera, int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fStack_140;
  float fStack_13c;
  float fStack_138;
  float fStack_134;
  float fStack_130;
  float fStack_12c;
  float fStack_128;
  float fStack_124;
  float fStack_120;
  int iStack_11c;
  float fStack_110;
  float fStack_10c;
  float fStack_108;
  undefined1 auStack_104 [16];
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  undefined1 auStack_e8 [24];
  undefined1 auStack_d0 [28];
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  undefined1 auStack_8 [4];
  float fStack_4;
  volatile u8 stackPad[0xa0];
  volatile u8 framePad[0x10];
  
  stackPad[0] = 0;
  framePad[0] = 0;
  iVar3 = (int)camera;
  iVar1 = *(int *)(iVar3 + 0xe0);
  iVar2 = FUN_002c0880(iVar1 + 0x88);
  iVar1 = *(int *)(iVar1 + 0x30);
  fVar5 = (float)func_00280870(1 << (*(byte *)(*(int *)(iVar2 + 0x30) + 0xa2) & 0x1f) & 0xffff,1,
                              &fStack_18,&fStack_4,auStack_8,1);
  func_00280050(iVar1,&fStack_58);
  fVar4 = *(float *)(iVar1 + 0x2c);
  fVar6 = *(float *)(iVar1 + 0x8c);
  fVar7 = *(float *)(iVar1 + 0x90) * fVar4;
  func_00280050(*(undefined4 *)(iVar2 + 0x30),&fStack_68);
  fStack_54 = fStack_54 + fVar6 * fVar4 * 0.5;
  if (fStack_14 < fStack_54) {
    fStack_14 = fStack_54 * 0.5;
  }
  if (fStack_54 <= fStack_4) {
    fStack_54 = fStack_4;
  }
  fStack_4 = fStack_54;
  fStack_20 = fStack_50;
  fStack_38 = fStack_58 - fStack_18;
  fStack_34 = fStack_14 - fStack_14;
  fStack_30 = fStack_50 - fStack_10;
  FUN_004c69f0(&fStack_38,&fStack_38);
  fVar4 = fStack_50;
  fVar6 = DAT_007cad7c * fVar5;
  fStack_18 = fStack_18 + fStack_38 * fVar6;
  fStack_14 = fStack_14 + fStack_34 * fVar6;
  fStack_10 = fStack_10 + fStack_30 * fVar6;
  fStack_88 = fStack_50;
  fStack_38 = fStack_58 - fStack_18;
  fStack_34 = fStack_14 - fStack_14;
  fStack_30 = fStack_50 - fStack_10;
  FUN_004c69f0(&fStack_38,&fStack_38);
  fVar6 = (float)FUN_0052e930(*(float *)(iVar3 + 0xb8) * 0.5);
  fVar6 = fVar7 + fStack_14 / fVar6;
  fStack_38 = fStack_38 * fVar6;
  fStack_34 = fStack_34 * fVar6;
  fStack_30 = fStack_30 * fVar6;
  fStack_48 = fStack_58 + fStack_38;
  fStack_40 = fVar4 + fStack_30;
  fStack_44 = DAT_007cae0c * fStack_4;
  fVar4 = (float)FUN_002d1e70(&fStack_48,&fStack_18);
  fVar6 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar3 + 0xb8) * 0.5);
  fVar6 = (DAT_007cadf0 * fVar5) / fVar6;
  FUN_004be1e0(&fStack_38,0x6978a0,1,auStack_104);
  if (fVar4 <= fVar6) {
    fVar4 = fVar6;
  }
  fVar6 = 1100.0;
  if (1100.0 <= fVar4) {
    fVar6 = fVar4;
  }
  fStack_38 = fStack_38 * fVar6;
  fStack_34 = fStack_34 * fVar6;
  fStack_30 = fStack_30 * fVar6;
  fVar4 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar3 + 0xb8) * 0.5);
  fVar4 = fVar6 * fVar4 * 0.21875;
  fStack_70 = fStack_38;
  fStack_6c = fStack_30;
  FUN_004c6b20(&fStack_70,&fStack_70);
  fStack_18 = fStack_6c * fVar4 + fStack_18 + 0.0;
  fStack_10 = (fStack_10 + 0.0) - fStack_70 * fVar4;
  fStack_110 = fStack_18 + fStack_38;
  fStack_10c = fStack_14 + fStack_34;
  fStack_108 = fStack_10 + fStack_30;
  fStack_78 = fStack_50;
  fStack_38 = fStack_58 - fStack_68;
  fStack_34 = fStack_14 - fStack_64;
  fStack_30 = fStack_50 - fStack_60;
  FUN_004c69f0(&fStack_38,&fStack_38);
  fVar4 = (float)FUN_0052e930(*(float *)(iVar3 + 0xb8) * 0.5);
  fVar7 = fVar7 + fStack_14 / fVar4;
  fStack_38 = fStack_38 * fVar7;
  fStack_34 = fStack_34 * fVar7;
  fStack_30 = fStack_30 * fVar7;
  fStack_48 = fStack_58 + fStack_38;
  fStack_40 = fStack_50 + fStack_30;
  fStack_44 = DAT_007cae0c * fStack_4;
  fVar4 = (float)FUN_002d1e70(&fStack_48,&fStack_68);
  fVar7 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar3 + 0xb8) * 0.5);
  fVar7 = (DAT_007cadb0 * fVar5) / fVar7;
  FUN_004be1e0(&fStack_38,0x6978a0,1,auStack_e8);
  if (fVar4 <= fVar7) {
    fVar4 = fVar7;
  }
  fVar7 = 1100.0;
  if (1100.0 <= fVar4) {
    fVar7 = fVar4;
  }
  fStack_38 = fStack_38 * fVar7;
  fStack_34 = fStack_34 * fVar7;
  fStack_30 = fStack_30 * fVar7;
  fVar4 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar3 + 0xb8) * 0.5);
  fVar4 = fVar7 * fVar4 * 0.21875;
  fStack_70 = fStack_38;
  fStack_6c = fStack_30;
  FUN_004c6b20(&fStack_70,&fStack_70);
  fStack_18 = fStack_6c * fVar4 + fStack_18 + 0.0;
  fStack_10 = (fStack_10 + 0.0) - fStack_70 * fVar4;
  fStack_f4 = fStack_68 + fStack_38;
  fStack_f0 = fStack_64 + fStack_34;
  fStack_ec = fStack_60 + fStack_30;
  if (*(short *)(iVar3 + 0x106) == 0) {
    FUN_004be310(auStack_104,auStack_e8,&fStack_140);
    fVar4 = DAT_007cae10;
    fVar7 = DAT_007cae14;
    if (iStack_11c == 0) {
      fVar7 = DAT_007cae10 * fStack_120;
      fVar4 = fVar7 * fVar7;
      fVar4 = fVar4 * fVar7 *
              (fVar4 * (fVar4 * (fVar4 * (fVar4 * (DAT_007cae04 * fVar4 + DAT_007cad38 + 0.0) +
                                         DAT_007cae08 + 0.0) + DAT_007cad40 + 0.0) +
                       DAT_007cad44 + 0.0) + DAT_007cad48 + 0.0) + fVar7 + 0.0;
      fStack_120 = DAT_007cae14 * fStack_120;
      fVar7 = fStack_120 * fStack_120;
      fVar7 = fVar7 * fStack_120 *
              (fVar7 * (fVar7 * (fVar7 * (fVar7 * (DAT_007cae04 * fVar7 + DAT_007cad38 + 0.0) +
                                         DAT_007cae08 + 0.0) + DAT_007cad40 + 0.0) +
                       DAT_007cad44 + 0.0) + DAT_007cad48 + 0.0) + fStack_120 + 0.0;
    }
    fStack_a8 = fStack_130 * fVar7 + fStack_140 * fVar4 + 0.0;
    fStack_a4 = fStack_12c * fVar7 + fStack_13c * fVar4 + 0.0;
    fStack_a0 = fStack_128 * fVar7 + fStack_138 * fVar4 + 0.0;
    fStack_9c = fStack_134 * fVar4 + fStack_124 * fVar7;
    fStack_110 = fStack_110 * DAT_007cae10;
    fStack_10c = fStack_10c * DAT_007cae10;
    fStack_108 = fStack_108 * DAT_007cae10;
    fStack_f4 = fStack_f4 * DAT_007cae14;
    fStack_f0 = fStack_f0 * DAT_007cae14;
    fStack_ec = fStack_ec * DAT_007cae14;
    fStack_b4 = fStack_110 + fStack_f4;
    fStack_b0 = fStack_10c + fStack_f0;
    fStack_ac = fStack_108 + fStack_ec;
  }
  else {
    FUN_002a44f0(&fStack_b4,&fStack_110);
  }
  if (param_2 != 0) {
    FUN_002a2170(camera,&fStack_b4);
    return;
  }
  FUN_002a2290((u16*)camera,(RwV3d*)&auStack_d0,(RwV3d*)&fStack_b4,1);
  FUN_002a3110((u16*)camera,1.25f);
}

extern u16 FUN_002bff60(int action, int target, u16 commandId, u32 param_4);
extern u16 FUN_002c09f0(int target);

// FUN_002AF7F0

void func_002af7f0(BtlCamera* camera)
{
  int iVar1;
  u16 id;
  undefined2 uVar2;

  iVar1 = *(int *)((u8 *)camera + 0xe0);
  id = *(u16 *)(iVar1 + 0x6e);
  uVar2 = FUN_002bff60(iVar1,0,id,0);
  *(undefined2 *)((u8 *)camera + 0x106) = uVar2;
  uVar2 = FUN_002c09f0(iVar1 + 0x88);
  *(undefined2 *)((u8 *)camera + 0x104) = uVar2;
  *(undefined4 *)((u8 *)camera + 0x100) = 0;
  return;
}

// FUN_002AF850

void func_002af850(BtlCamera* camera)
{
  int iVar2;
  int iVar3;
  int a1;

  iVar3 = FUN_002c0880(*(int *)((u8 *)camera + 0xe0) + 0x88);
  if (iVar3 == 0) {
    goto no_update;
  }
  iVar2 = *(int *)((int)camera + 0x100);
  if (iVar2 == iVar3) {
    goto no_update;
  }
  if (iVar2 == 0) {
    goto update;
  }
  if (*(u16 *)((u8 *)camera + 0x106) == 0) {
    goto update;
  }

no_update:
  return;

update:
  if (iVar2 == 0) {
    switch (*(u16 *)(iGpffffb6fc + 0x104)) {
    case 0x1c:
    case 0x22:
    case 2:
    case 0x23:
      a1 = 0;
      break;
    default:
      a1 = 1;
      break;
    }
  }
  else {
    a1 = 0;
  }
  *(int *)((u8 *)camera + 0x100) = iVar3;
  switch (*(u16 *)((u8 *)camera + 0x104)) {
  case 2:
    func_002aef80(camera, a1);
    break;
  case 1:
  default:
    func_002ae740(camera, a1);
    break;
  }
}


// FUN_002AF960 NONMATCHING

void func_002af960(BtlCamera* camera)
{
    f32 range;
    f32 radius;
    f32 distance;
    f32 factor;
    f32 blend;
    f32 complement;
    f32 radiusScale;
    f32 dot;
    f32 dot2;
    f32 height;
    int interpolationMode;
    f32 clampRadius;
    BtlUnit* unit;
    BtlUnit* target;
    struct Af960Work
    {
        BtlCameraKeyFrame frame;
        RwV3d finalPos;
        RtQuat rotation;
        u8 pad88[8];
        RtQuat firstRotation;
        RtQuat secondRotation;
        f32 modeData[4];
        RtQuat candidate1;
        RtQuat candidate2;
        RtQuat blendedRotation;
        u8 padF8[8];
        RwV3d generated;
        u8 padGen[4];
        RwV3d unitPoint;
        u8 padUnit[4];
        RwV3d anchor;
        u8 padAnchor[4];
        RwV3d offset;
        u8 padOffset[4];
        RwV3d difference;
        u8 padDifference[4];
        RwV3d direction;
        RwV3d transformed;
        u8 padTransformed[4];
        RwV3d endpoint;
        u8 padEndpoint[4];
        RwV2d planar;
    } work;

    #define frame work.frame
    #define finalPos work.finalPos
    #define rotation work.rotation
    #define firstRotation work.firstRotation
    #define secondRotation work.secondRotation
    #define blendedRotation work.blendedRotation
    #define candidate1 work.candidate1
    #define candidate2 work.candidate2
    #define unitPoint work.unitPoint
    #define anchor work.anchor
    #define generated work.generated
    #define offset work.offset
    #define direction work.direction
    #define endpoint work.endpoint
    #define difference work.difference
    #define transformed work.transformed
    #define planar work.planar
    unit = camera->action->unit;
    target = camera->action->target.targetedActions[0]->unit;
    *(BtlAction**)((u8*)camera + 0x118) =
        camera->action->target.targetedActions[0];

    FUN_002a4470((f32*)&frame, (f32*)&camera->pos);
    unitPoint.x = unit->unk_dc.x;
    unitPoint.y = unit->sphereCenter.y * unit->scale;
    unitPoint.z = unit->unk_dc.z;
    FUN_002802d0(target, unit, (f32*)&generated);

    range = DAT_007cad84 * target->unk_8c * target->scale +
            unitPoint.y + 0.0f +
            DAT_007cad84 * unit->unk_8c * unit->scale +
            generated.y + 0.0f;
    radius = target->sphereRadius * target->scale +
             unit->sphereRadius * unit->scale;

    offset.x = unit->unk_dc.x - generated.x;
    offset.y = unit->unk_dc.y - 0.0f;
    offset.z = unit->unk_dc.z - generated.z;
    RwV3dNormalize(&offset, &offset);
    factor = radius * 0.25f;
    offset.x = offset.x * factor + generated.x;
    offset.y = offset.y * factor + generated.y;
    offset.z = offset.z * factor + generated.z;

    height = range * 0.5f;
    finalPos.x = frame.pos.x;
    finalPos.y = height;
    finalPos.z = frame.pos.z;

    camera->unkData3[0x10] = 0;
    camera->unkData3[0x11] = 0;
    *(f32*)((u8*)camera + 0x10c) = unit->unk_e8 * 0.5f;
    *(f32*)((u8*)camera + 0x100) = offset.x;
    *(f32*)((u8*)camera + 0x104) = offset.y;
    *(f32*)((u8*)camera + 0x108) = offset.z;

    FUN_002a4690((void*)&rotation, (const void*)&finalPos,
                 (const void*)&offset, (const void*)&D_00697880);

    blend = (f32)FUN_002d1f30((f32*)&frame.rot, (f32*)&rotation);
    if (blend > DAT_007cade0)
    {
        blend = DAT_007cade0 / blend;
        FUN_004be310((f32*)&frame.rot, (f32*)&rotation,
                     (f32*)&firstRotation);
        if (blend <= 0.0f)
        {
            blendedRotation = frame.rot;
        }
        else if (1.0f <= blend)
        {
            blendedRotation = rotation;
        }
        else
        {
            complement = 1.0f - blend;
            if (interpolationMode == 0)
            {
                complement = complement * radiusScale;
                factor = complement * complement;
                complement = factor * complement *
                    (factor * (factor * (factor * (factor *
                    (DAT_007caddc * factor + DAT_007cad38 + 0.0f) +
                    DAT_007cad3c + 0.0f) + DAT_007cad40 + 0.0f) +
                    DAT_007cad44 + 0.0f) + DAT_007cad48 + 0.0f) +
                    complement + 0.0f;
                blend = blend * radiusScale;
                factor = blend * blend;
                blend = factor * blend *
                    (factor * (factor * (factor * (factor *
                    (DAT_007caddc * factor + DAT_007cad38 + 0.0f) +
                    DAT_007cad3c + 0.0f) + DAT_007cad40 + 0.0f) +
                    DAT_007cad44 + 0.0f) + DAT_007cad48 + 0.0f) +
                    blend + 0.0f;
            }
            blendedRotation.imag.x = firstRotation.imag.x * blend +
                                      rotation.imag.x * complement + 0.0f;
            blendedRotation.imag.y = firstRotation.imag.y * blend +
                                      rotation.imag.y * complement + 0.0f;
            blendedRotation.imag.z = firstRotation.imag.z * blend +
                                      rotation.imag.z * complement + 0.0f;
            blendedRotation.real = firstRotation.real * complement +
                                   rotation.real * blend;
        }
        FUN_004be1e0(&transformed, &D_006978A0, 1, &blendedRotation);
        finalPos.x = transformed.x + offset.x;
        finalPos.y = transformed.y + offset.y;
        finalPos.z = transformed.z + offset.z;
        FUN_002a4690((void*)&rotation, (const void*)&finalPos,
                     (const void*)&offset, (const void*)&D_00697880);
    }
    else if (blend < DAT_007cade4)
    {
        FUN_004bdde0((f32*)&rotation, (const f32*)&D_00697880,
                     DAT_007cade8, 2);
    }

    clampRadius = radius;
    if (clampRadius < 450.0f)
    {
        clampRadius = 450.0f;
    }
    distance = (clampRadius * 0.5f) /
               FUN_0052e930(DAT_007cad60 * camera->fovRad * 0.5f);
    FUN_004be1e0(&transformed, &D_006978A0, 1, &rotation);
    direction.y = transformed.y;
    RwV3dNormalize(&direction, &direction);
    dot = transformed.y * direction.y + transformed.x * direction.x +
          transformed.z * direction.z;
    if (!(dot < 0.0f))
    {
        radiusScale = unit->sphereRadius * unit->scale;
        anchor.x = unitPoint.x;
        anchor.y = unitPoint.y;
        anchor.z = unitPoint.z;
    }
    else
    {
        radiusScale = target->sphereRadius * target->scale;
        anchor.x = generated.x;
        anchor.y = generated.y;
        anchor.z = generated.z;
    }

    endpoint.x = anchor.x + direction.z * radiusScale + 0.0f;
    endpoint.y = offset.y;
    endpoint.z = anchor.z - direction.x * radiusScale;
    difference.x = endpoint.x - offset.x;
    difference.y = endpoint.y - offset.y;
    difference.z = endpoint.z - offset.z;
    RwV3dNormalize(&difference, &difference);
    dot2 = difference.y * offset.y + difference.x * offset.x +
           difference.z * offset.z;
    if (((ABS(dot2) < ABS(dot)) && (dot2 != 0.0f)) && (dot != 0.0f))
    {
        planar.x = offset.x - finalPos.x;
        planar.y = offset.z - finalPos.z;
        factor = RwV2dLength(&planar);
        offset.y = offset.y + (height * factor) / distance;

        endpoint.x = anchor.x + direction.z * radiusScale + 0.0f;
        endpoint.y = offset.y;
        endpoint.z = anchor.z - direction.x * radiusScale + 0.0f;
        FUN_002a4690((void*)&candidate1, (const void*)&endpoint,
                     (const void*)&offset, (const void*)&D_00697880);

        endpoint.x = anchor.x - direction.z * radiusScale;
        endpoint.y = offset.y;
        endpoint.z = anchor.z + direction.x * radiusScale + 0.0f;
        FUN_002a4690((void*)&candidate2, (const void*)&endpoint,
                     (const void*)&offset, (const void*)&D_00697880);
        if (FUN_002d1f30((f32*)&frame.rot, (f32*)&candidate1) <
            FUN_002d1f30((f32*)&frame.rot, (f32*)&candidate2))
        {
            rotation = candidate1;
        }
        else
        {
            rotation = candidate2;
        }
        FUN_004be1e0(&transformed, &D_006978A0, 1, &rotation);
    }

    transformed.x = transformed.x * distance;
    transformed.y = transformed.y * distance;
    transformed.z = transformed.z * distance;
    factor = FUN_0052e930(DAT_007cad60 * camera->fovRad * 0.5f);
    factor = distance * factor * 0.21875f;
    planar.x = transformed.x;
    planar.y = transformed.z;
    FUN_004c6b20((f32*)&planar, (f32*)&planar);
    offset.x = planar.y * factor + offset.x + 0.0f;
    offset.z = offset.z - planar.x * factor;
    finalPos.x = offset.x + transformed.x;
    finalPos.y = offset.y + transformed.y;
    finalPos.z = offset.z + transformed.z;
    FUN_002a2290((u16*)camera, &frame.pos, &finalPos, 1);
    FUN_002a3110((u16*)camera, 1.0f);
    #undef frame
    #undef finalPos
    #undef rotation
    #undef firstRotation
    #undef secondRotation
    #undef blendedRotation
    #undef candidate1
    #undef candidate2
    #undef unitPoint
    #undef anchor
    #undef generated
    #undef offset
    #undef direction
    #undef endpoint
    #undef difference
    #undef transformed
    #undef planar
    #undef range
    #undef radius
    #undef distance
    #undef factor
    #undef blend
    #undef complement
    #undef dot
    #undef dot2
    #undef height
    #undef radiusScale
    #undef clampRadius
    #undef interpolationMode
}

/* Recovered battle-misc harvest: 0x002A3A80-0x002A4C20 */
// FUN_002A3A80


u16 FUN_002a3a80(void)



{

  return *(u16 *)(iGpffffb6fc + 0xf0);

}

// FUN_002A3A90


void FUN_002a3a90(int param_1)



{

  if (*(int *)(iGpffffb6fc + 0x100) != 0) {

    if (*(int *)(*(int *)(iGpffffb6fc + 0x100) + 8) == *(int *)(param_1 + 8)) {

      *(u32 *)(iGpffffb6fc + 0x100) = 0;

    }

    switch (*(u16 *)(iGpffffb6fc + 0xf0)) {
      case 0xc:
        if ((*(int *)(iGpffffb6fc + 0x120) != 0) &&
            (*(int *)(*(int *)(iGpffffb6fc + 0x120) + 8) == *(int *)(param_1 + 8))) {
          *(u32 *)(iGpffffb6fc + 0x120) = 0;
        }
        break;
      default:
        break;
    }

  }

  return;

}

// FUN_002A42A0


void FUN_002a42a0(void)
{
  s32 node;
  s32 index;

  index = 0;
  for (; (index & 0xffff) < 2; index = (u16)(index + 1)) {
    node = *(s32 *)(DAT_007ce3ec + (u16)index * 8 + 0x150);
    while (node != 0) {
      FUN_0027f790(node, 7);
      node = *(s32 *)(node + 0xa34);
    }
  }
}

// FUN_002A4530


void FUN_002a4530(float *param_1,float *param_2,float *param_3,float *param_4)
{
  RwV3d diff;
  RwV3d cross1;
  RwV3d cross2;

  *(RwV3d*)(param_1 + 0xc) = *(RwV3d*)param_3;
  diff.x = *param_2 - *param_3;
  diff.y = param_2[1] - param_3[1];
  diff.z = param_2[2] - param_3[2];
  FUN_004c69f0(&diff,&diff);
  *(RwV3d*)(param_1 + 8) = diff;
  cross1.x = param_4[1] * diff.z - param_4[2] * diff.y;
  cross1.y = param_4[2] * diff.x - *param_4 * diff.z;
  cross1.z = *param_4 * diff.y - param_4[1] * diff.x;
  FUN_004c69f0(&cross1,&cross1);
  *(RwV3d*)param_1 = cross1;
  cross2.x = diff.y * cross1.z - diff.z * cross1.y;
  cross2.y = diff.z * cross1.x - diff.x * cross1.z;
  cross2.z = diff.x * cross1.y - diff.y * cross1.x;
  *(RwV3d*)(param_1 + 4) = cross2;
  return;
}

// FUN_002A4A70 NONMATCHING


void FUN_002a4a70(void)
{
  u8 *gp;
  u8 *cam;
  u32 work;
  u32 uVar4;
  u16 idx;

  FUN_004c9d70(FUN_00198590(),35.0f);
  FUN_001a4580(FUN_00198590(),40.0f);
  gp = iGpffffb6fc;
  cam = gp + 0x20;
  *(u16 *)(gp + 0x20) = 1;
  *(u16 *)(gp + 0x94) = 0;
  *(u16 *)(gp + 0x96) = 0;
  *(u16 *)(gp + 0x98) = 0;
  *(u32 *)(gp + 0xa0) = 0;
  *(u32 *)(gp + 0x9c) = 0;
  work = (*DAT_00960178)(0x30,0x40000);
  FUN_00521408(work,0,0x30);
  *(u32 *)(cam + 0x98) = FUN_0048dab0(4,1,work);
  (*DAT_0096017c)(work);
  FUN_00198590();
  *(f32 *)(iGpffffb6fc + 0xd4) = DAT_007caf3c;
  *(f32 *)(iGpffffb6fc + 0xc8) = DAT_007caf40;
  *(f32 *)(iGpffffb6fc + 0xcc) = DAT_007caf44;
  *(f32 *)(iGpffffb6fc + 0xd0) = DAT_007caf48;
  *(f32 *)(iGpffffb6fc + 0xbc) = DAT_007caf4c;
  *(f32 *)(iGpffffb6fc + 0xc0) = DAT_007caf50;
  *(f32 *)(iGpffffb6fc + 0xc4) = DAT_007caf54;
  *(f32 *)(iGpffffb6fc + 0xd8) = DAT_007cae38;
  *(u16 *)(iGpffffb6fc + 0xf0) = 0;
  *(u16 *)(iGpffffb6fc + 0x10a) = 0;
  for (uVar4 = 0; (u16)uVar4 < 3; uVar4 = (u16)(uVar4 + 1)) {
    idx = (u16)uVar4;
    *(u16 *)(iGpffffb6fc + idx * 2 + 0x104) = 0;
  }
  *(u32 *)(iGpffffb6fc + 0xf4) = *(u32 *)(iGpffffb6fc + 0xf4) | 2;
  FUN_002b6db0((int)(uintptr_t)(iGpffffb6fc + 0x10c));
  return;
}

// FUN_002A4C20


void FUN_002a4c20(void)



{

  if (*(int *)(DAT_007ce3ec + 0xb8) != 0) {

    FUN_0048da30(*(int *)(DAT_007ce3ec + 0xb8));

  }

  return;

}

/* Recovered battle-misc harvest: 0x002A32F0-0x002A4690 */
// FUN_002A32F0


u32 FUN_002a32f0(int param_1)
{
    int unit;

    unit = *(int*)(param_1 + 0xe0);
    if (unit == 0)
        return 0;
    if (FUN_002fdfe0(param_1) != 0)
        return 1;
    if (FUN_00300580(*(u32*)(*(int*)(unit + 0x30) + 0xa2c), 0x80) != 0)
        return 1;
    return FUN_002d5f50(unit) != 0;
}

// FUN_002A3380



u32 FUN_002a3380(u8* param_1)
{
  int action;
  int x;
  u16 id;
  u16 n;

  action = *(int *)(param_1 + 0xe0);
  x = *(int *)(*(int *)(action + 0x30) + 0xa00);
  id = *(u16 *)(action + 0x6e);
  if (x != 0) {
    n = *(u16 *)(x + 0xa4);
    if ((*(u16 *)(iGpffffb73c + ((u32)n * 10 + (u32)n) * 8) & 1) != 0) {
      return 0;
    }
  }
  if ((gp0xffffb710[id][1] & 0x10) != 0) {
    return 0;
  }
  return 1;
}


// FUN_002A3420


u32 FUN_002a3420(int param_1)
{
  int action;
  int x;
  u16 id;
  u16 n;
  u32 flag;

  if ((*(u32 *)(iGpffffb6fc + 0xc) & 0x200000) != 0) {
    return 1;
  }
  action = *(int *)(param_1 + 0xe0);
  id = *(u16 *)(action + 0x6e);
  x = *(int *)(*(int *)(action + 0x30) + 0xa00);
  if ((x != 0) && (n = *(u16 *)(x + 0xa4),
      (*(u16 *)(iGpffffb73c + ((u32)n * 10 + (u32)n) * 8) & 1) != 0)) {
    flag = 0;
  }
  else if ((gp0xffffb710[id][1] & 0x10) != 0) {
    flag = 0;
  }
  else {
    flag = 1;
  }
  if (flag != 0) {
    if ((gp0xffffb710[id][1] & 0x20) != 0) {
      return 1;
    }
  }
  return 0;
}



// FUN_002A3520
u8 FUN_002a3520(int param_1)



{

  u8 bVar1;

  

  if (*(int *)(param_1 + 0xe0) == 0) {

    bVar1 = 0;

  }

  else {

    bVar1 = *(u16 *)(*(int *)(param_1 + 0xe0) + 0x6c) == 3;

  }

  return bVar1;

}

// FUN_002A3550


u64 FUN_002a3550(u8* param_1)



{

  u64 uVar1;

  

  if (*(int *)(param_1 + 0xe0) == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = FUN_00308a50(*(u16 *)(*(int *)(param_1 + 0xe0) + 0x72));

  }

  return uVar1;

}

// FUN_002A3590


u32 FUN_002a3590(float *param_1,float *param_2)
{
  f32 tmp[3];
  f32 t;
  f32 a;
  u32 ret;

  ret = 0;
  a = fabsf(param_1[0]);
  if (a > 1500) {
    if (param_2 != 0) {
      t = a - 1500;
      RtQuatTransformVectors((RwV3d*)tmp,&D_00697890,1,(RtQuat*)(param_1 + 3));
      if (tmp[0] != 0.0f) {
        a = fabsf(tmp[0]);
        t = t / a;
        tmp[0] = tmp[0] * t;
        tmp[1] = tmp[1] * t;
        tmp[2] = tmp[2] * t;
        param_2[0] = param_1[0] + tmp[0];
        param_2[1] = param_1[1] + tmp[1];
        param_2[2] = param_1[2] + tmp[2];
      }
    }
    ret = 1;
  }
  a = fabsf(param_1[2]);
  if (a > 1500) {
    if (param_2 != 0) {
      t = a - 1500;
      RtQuatTransformVectors((RwV3d*)tmp,&D_00697890,1,(RtQuat*)(param_1 + 3));
      if (tmp[2] != 0.0f) {
        a = fabsf(tmp[2]);
        t = t / a;
        tmp[0] = tmp[0] * t;
        tmp[1] = tmp[1] * t;
        tmp[2] = tmp[2] * t;
        param_2[0] = param_1[0] + tmp[0];
        param_2[1] = param_1[1] + tmp[1];
        param_2[2] = param_1[2] + tmp[2];
      }
    }
    ret = 1;
  }
  return ret;
}

// FUN_002A3750


s32 FUN_002a3750(BtlCamera* camera,u32 unit)
{
  BtlUnit *unitPtr;
  s32 result;
  s16 frameCount;
  s16 animFrame;
  
  unitPtr = (BtlUnit *)(uintptr_t)unit;
  if (unitPtr == 0) {
    result = 0;
  }
  else if (((u8 *)unitPtr)[0x33] == '\0') {
    result = 0;
  }
  else if ((*(u32 *)((u8 *)unitPtr + 0x98) & 2) == 0) {
    result = 0;
  }
  else {
    frameCount = func_002835e0(
      unitPtr, (u16)(s32)btlUnit00282c30(unitPtr), 1.0f);
    animFrame = btlUnitGetAnimFrame(unitPtr);
    result = animFrame < frameCount;
    result = result ^ 1;
  }
  return result;
}

// FUN_002A3820


u8 FUN_002a3820(int param_1)



{
  u32 offset;

  offset = (u32)*(u16 *)(*(int *)(param_1 + 0xe0) + 0x6e) * 0x1c;
  offset += iGpffffb710;

  return (*(u16 *)(offset + 2) &

         0x4000) != 0;

}

// FUN_002A3850


u32 FUN_002a3850(int param_1)
{
  s32 index;
  s32 owner;
  s32 object;
  s32 work;

  work = *(s32 *)(param_1 + 0xe0);
  index = 0;
  for (; (index & 0xffff) < *(u16 *)(work + 0x6a);
       index = (u16)(index + 1)) {
    owner = *(s32 *)(work + (u16)index * 4 + 0x38);
    if (owner != 0) {
      object = *(s32 *)(owner + 0x30);
      if (object != 0 &&
          FUN_0030b5a0(*(u32 *)(object + 0xa2c), 0) != 0) {
        return 1;
      }
    }
  }
  return 0;
}

// FUN_002A3E80 NONMATCHING


void FUN_002a3e80(float param_1,u8* param_2,u8* param_3,u8* param_4,u32 param_5)
{
  LocalCameraPacket packet;
  u8* list;
  BtlUnit* unit;
  f32 distance;
  s32 index;
  s32 index_value;
  s32 flag40;
  s32 flag10;
  s32 flag4;
  s32 work;

  if ((*(u32 *)(iGpffffb6fc + 0x10) & 4) == 0) {
    if ((param_3 != 0) && (param_4 != 0)) {
      packet.f100 = *(f32 *)param_3;
      packet.f104 = ((f32 *)param_3)[2];
      packet.f108 = *(f32 *)param_4;
      packet.f10c = ((f32 *)param_4)[2];
    }
    else {
      param_1 = 0.0f;
    }

    list = *(u8 **)(iGpffffb6fc + 0x14c);
    work = param_5 & 0xffff;
    flag40 = work & 0x40;
    flag10 = work & 0x10;
    flag4 = work & 4;
    packet.flag1.w[0] = work & 1;
    packet.flag2.w[0] = work & 2;
    packet.flag8.w[0] = work & 8;
    packet.flag20.w[0] = work & 0x20;
    packet.flag80.w[0] = work & 0x80;

    while (list != 0) {
      if ((*(u16 *)(list + 0x1a) & 1) != 0) {
        unit = (BtlUnit *)(uintptr_t)*(u8 **)(list + 0x30);
        if ((*(u32 *)((u8 *)unit + 0x9c) & 8) != 0) {
          if (flag40 != 0) {
            FUN_0027f790(unit, 2);
            FUN_0027f770(unit, 4);
            if (flag10 == 0) *(u8 *)((u8 *)unit + 0x37) = 0xff;
          }
          else if ((list == *(u8 **)(iGpffffb6fc + 0x148)) && (flag4 != 0)) {
            FUN_0027f790(unit, 2);
            FUN_0027f770(unit, 4);
            if (flag10 == 0) *(u8 *)((u8 *)unit + 0x37) = 0xff;
          }
          else if (param_2 != 0) {
            if ((list == param_2) && (packet.flag1.w[0] != 0)) {
              FUN_0027f790(unit, 2);
              FUN_0027f770(unit, 4);
              if (flag10 == 0) *(u8 *)((u8 *)unit + 0x37) = 0xff;
            }
            else if (packet.flag2.w[0] != 0) {
              index = 0;
              while ((index & 0xffff) < *(u16 *)(param_2 + 0x6a)) {
                index_value = index & 0xffff;
                if (list == *(u8 **)(param_2 + index_value * 4 + 0x38)) {
                  FUN_0027f790(unit, 2);
                  FUN_0027f770(unit, 4);
                  if (flag10 == 0) *(u8 *)((u8 *)unit + 0x37) = 0xff;
                  break;
                }
                index = (index + 1) & 0xffff;
              }
              if (index_value == *(u16 *)(param_2 + 0x6a)) goto next_unit;
            }

            if ((*(s8 *)((u8 *)unit + 0xa2) !=
                 *(s8 *)(*(u8 **)(param_2 + 0x30) + 0xa2)) ||
                (packet.flag8.w[0] == 0)) goto geometry;

            FUN_0027f790(unit, 2);
            if (flag10 == 0) *(u8 *)((u8 *)unit + 0x37) = 0xff;
          }
          else {
geometry:
            if ((param_3 == 0) || (param_4 == 0)) {
              distance = 0.0f;
            }
            else {
              FUN_0027ffb0(unit, &packet.center);
              packet.f110 = packet.center.x;
              packet.f114 = packet.center.z;
              distance = FUN_002d1fd0(&packet.f100, &packet.f108,
                                      &packet.f110, &packet.f118);
              distance = (distance + 0.0f) -
                         *(f32 *)((u8 *)unit + 0x90) *
                         *(f32 *)((u8 *)unit + 0x2c);
              if (((packet.f100 < packet.f118 || packet.f118 < packet.f108) &&
                   (packet.f118 < packet.f100 || packet.f108 < packet.f118)) ||
                  ((packet.f104 < packet.f114 || packet.f114 < packet.f10c) &&
                   (packet.f114 < packet.f104 || packet.f10c < packet.f114))) {
                goto next_unit;
              }
            }

            if (distance <= param_1) {
              FUN_0027f770(unit, 2);
              if (packet.flag20.w[0] == 0) *(u8 *)((u8 *)unit + 0x37) = 0;
              if (packet.flag80.w[0] != 0) FUN_0027f790(unit, 4);
            }
          }
        }
      }
next_unit:
      list = *(u8 **)(list + 0x4a8);
    }
  }
}

// FUN_002A4470


void FUN_002a4470(f32* dst, f32* src)
{
  *(RwV3d*)dst = *(RwV3d*)src;
  *(RtQuat*)(dst + 3) = *(RtQuat*)(src + 3);
}

// FUN_002A44B0


void FUN_002a44b0(f32* dst, f32* src)
{
  *(RwV3d*)dst = *(RwV3d*)src;
  *(RtQuat*)(dst + 3) = *(RtQuat*)(src + 3);
}

// FUN_002A44F0


void FUN_002a44f0(f32* dst, f32* src)
{
  *(RwV3d*)dst = *(RwV3d*)src;
  *(RtQuat*)(dst + 3) = *(RtQuat*)(src + 3);
}

// FUN_002A4690


void FUN_002a4690(void* out, const void* first, const void* second, const void* config)
{
  u8 auStack_40[64];

  FUN_002a4530((float*)auStack_40, (float*)second, (float*)first,
               (float*)config);
  FUN_004bdcb0(out, auStack_40);
}
