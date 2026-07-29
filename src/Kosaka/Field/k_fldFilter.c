#include "Kosaka/Field/k_fldFilter.h"
#include "Kosaka/Field/k_fldCamera.h"
#include "Kosaka/Field/k_fldFrame.h"
#include "Kosaka/Field/k_field.h"
#include "Kernel/Kwln/kwln.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Scene/resrcManager.h"
#include "Kosaka/k_draw.h"
#include "Kosaka/k_assert.h"
#include "rw/rwcore.h"
#include "h_cdvd.h"
#include "temporary.h"

#define FLDFILTER_FILE_SIZE 74752 // in bytes

// num of pixels in a single quad
#define FLDFILTER_QUAD_XPIXELS 80
#define FLDFILTER_QUAD_YPIXELS 64
#define FLDFILTER_GRID_WIDTH  (SCREEN_WIDTH / FLDFILTER_QUAD_XPIXELS)  // 8
#define FLDFILTER_GRID_HEIGHT (SCREEN_HEIGHT / FLDFILTER_QUAD_YPIXELS) // 7

// 256 bytes
typedef struct
{
    RwIm2DVertex vert[4]; // 0x00
} FilterQuad;

/* The filter controller keeps the first six words in the small-BSS block. */
extern void* sFilterFile;
extern s32 sFilterColorOffset;
extern s32 sFilterCurrent;
extern f32 sFilterPrevious;
extern f32 sFilterBlend;
extern s32 sFilterBlendDuration;
extern FilterQuad sFilterGrid[FLDFILTER_GRID_HEIGHT][FLDFILTER_GRID_WIDTH];
#pragma alias sFilterGrid_abs sFilterGrid
extern u8 sFilterGrid_abs[];

/* This word belongs to the neighbouring field-resource work block. */
extern u32 gp0xffff95d8;
extern f32 fGpffff8248;
#define FLDFILTER_ALPHA gp0xffff95d8

extern const char D_00683A60[];
extern const char D_00683A78[];
extern void (*D_00960090)(u32 state, u32 value);
extern void (*D_009600A0)(RwPrimitiveType primitiveType, RwIm2DVertex* vertices, s32 vertexCount);
#pragma alias D_00960090_abs D_00960090
extern void (*D_00960090_abs[])(u32 state, u32 value);
#pragma alias D_009600A0_abs D_009600A0
extern void (*D_009600A0_abs[])(RwPrimitiveType primitiveType, RwIm2DVertex* vertices, s32 vertexCount);
extern u32 D_00960184[];
extern void (*D_0096017c)(void* memory);
#pragma alias D_0096017c_abs D_0096017c
extern u32 D_0096017c_abs[];
extern void func_004d7f60(s32 state, u32 value);
extern void func_004c69f0(RwV3d* output, const RwV3d* input);
extern void func_004cb420(RwFrame* parent, RwFrame* child);
extern void func_004cb590(RwFrame* frame);
extern RwFrame* func_004caf10(void);
extern RwFrame* func_004caf80(RwFrame* frame);
extern void func_004cb930(RwFrame* frame);
extern void func_004cb750(RwFrame* frame, const RwV3d* translation, RwOpCombineType combine);
extern void FUN_001a1210(RwCamera* camera, const RwV3d* at, const RwV3d* position, const RwV3d* up);
extern void* FUN_0048d480(f32 frame, void* curve, s32 flags, RwV3d* output, s32 unused);
extern s32 func_00530da0(f32 value);
extern const char D_00683A48[];
extern const char D_007CC2CC[];

/* Work data for the field camera controller (the public header intentionally
 * keeps the post-camera fields opaque). */
typedef struct FldFilterCameraWork
{
    u32 state;                 // 0x00
    u32 flags;                 // 0x04
    u32 type;                  // 0x08
    RwFrame* frame;            // 0x0c
    RwFrame* parentFrame;      // 0x10
    RwV3d posOffset;            // 0x14
    f32 xzDeadZone;            // 0x20
    f32 yDeadZone;             // 0x24
    u8 unknown28[0x1c];         // 0x28
    KwlnTask* pointTask0;       // 0x44
    KwlnTask* pointTask1;       // 0x48
    KwlnTask* pointTask2;       // 0x4c
    u8 unknown50[0x10];         // 0x50
    RwV3d cameraPoints[9];       // 0x60
    ResrcModelChar* playerResrc;// 0xcc
} FldFilterCameraWork;

// FUN_001d4460 NONMATCHING
static void K_FldFilter_InitQuads(RwCamera* camera)
{
    f32* vertex;
    FilterQuad (*grid)[FLDFILTER_GRID_WIDTH];
    FilterQuad* row;
    s32 y;
    s32 x;
    s32 rowOffset;
    s32 rightOffset;
    s32 topOffset;
    s32 bottomOffset;
    f32 z;
    f32 recipZ;
    f32 bottom;
    f32 top;

    z = camera->nearPlane;
    recipZ = 1.0f / z;
    y = 0;
    grid = (FilterQuad (*)[FLDFILTER_GRID_WIDTH])sFilterGrid_abs;
    while (y < FLDFILTER_GRID_HEIGHT)
    {
        x = 0;
        row = grid[y];
        topOffset = y * FLDFILTER_QUAD_YPIXELS;
        bottomOffset = topOffset + FLDFILTER_QUAD_YPIXELS;
        bottom = (f32)bottomOffset;
        top = (f32)topOffset;
        while (x < FLDFILTER_GRID_WIDTH)
        {
            rowOffset = x * FLDFILTER_QUAD_XPIXELS;
            vertex = (f32*)&row[x];
            vertex[0] = (f32)rowOffset;
            vertex[1] = top;
            vertex[2] = z;
            x++;
            rightOffset = x * FLDFILTER_QUAD_XPIXELS;
            vertex[0x10] = (f32)rightOffset;
            vertex[0x11] = top;
            vertex[0x12] = z;
            vertex[0x20] = (f32)rowOffset;
            vertex[0x21] = bottom;
            vertex[0x22] = z;
            vertex[0x30] = (f32)rightOffset;
            vertex[0x31] = bottom;
            vertex[0x32] = z;
            vertex[6] = recipZ;
            vertex[0x16] = recipZ;
            vertex[0x26] = recipZ;
            vertex[0x36] = recipZ;
        }
        y++;
    }
}

// FUN_001d4560
void K_FldFilter_Init()
{
    HCdvd* cdvd;

    if (sFilterFile == NULL)
    {
        sFilterFile = RwCalloc(1, FLDFILTER_FILE_SIZE, rwMEMHINTDUR_GLOBAL);
    }

    cdvd = H_Cdvd_Request("field/FILTER.FLD", HCDVD_FILENORMAL);
    H_Cdvd_ReadSync(cdvd);

    memcpy(sFilterFile, cdvd->fileMemory, FLDFILTER_FILE_SIZE);

    H_Cdvd_Destroy(cdvd);

    K_FldFilter_InitQuads(kwlnGetMainCamera());
}

// FUN_001d4610 NONMATCHING
void K_FldFilter_Main()
{
    s32 current;
    s32 previous;
    s32 x;
    s32 y;
    s32 vertex;
    s32 channel;
    u32 packed0;
    u32 packed1;
    u32 packed2;
    u32 packed3;
    u32 oldPacked0;
    u32 oldPacked1;
    u32 oldPacked2;
    u32 oldPacked3;
    s32 oldRed0;
    s32 oldGreen0;
    s32 oldBlue0;
    s32 oldRed1;
    s32 oldGreen1;
    s32 oldBlue1;
    s32 oldRed2;
    s32 oldGreen2;
    s32 oldBlue2;
    s32 oldRed3;
    s32 oldGreen3;
    s32 oldBlue3;
    void (**stateFunc)(u32 state, u32 value);
    RwIm2DVertex* vertices;
    u8* currentFrame;
    u8* oldFrame;
    s32 currentAlpha0;
    s32 currentAlpha1;
    s32 currentAlpha2;
    s32 currentAlpha3;
    s32 oldAlpha0;
    s32 oldAlpha1;
    s32 oldAlpha2;
    s32 oldAlpha3;
    s32 red0;
    s32 green0;
    s32 blue0;
    s32 red1;
    s32 green1;
    s32 blue1;
    s32 red2;
    s32 green2;
    s32 blue2;
    s32 red3;
    s32 green3;
    s32 blue3;
    u8 color[16];
    f32 blend;
    f32 inverseBlend;
    f32 value;

    current = sFilterCurrent;
    if (current == 0)
    {
        return;
    }

    if (sFilterBlend < 1.0f)
    {
        sFilterBlend += 1.0f / sFilterBlendDuration;
        if (sFilterBlend > 1.0f)
        {
            sFilterBlend = 1.0f;
            sFilterPrevious = current;
        }
    }

    previous = sFilterPrevious;
    blend = sFilterBlend;
    inverseBlend = 1.0f - blend;
    stateFunc = D_00960090_abs;
    (*stateFunc)(6, 0);
    (*stateFunc)(8, 0);
    (*stateFunc)(7, 2);
    (*stateFunc)(1, 0);
    (*stateFunc)(0x0c, 1);
    func_004d7f60(3, 0x71801);
    switch (*(u32*)((u8*)sFilterFile + current * 0x124))
    {
        case 0: func_004d7f60(2, 0x44); break;
        case 1: func_004d7f60(2, 0x48); break;
        case 2: func_004d7f60(2, 0x42); break;
        case 3: func_004d7f60(2, 6); break;
    }

    for (y = 0; y < FLDFILTER_GRID_HEIGHT; y++)
    {
        for (x = 0; x < FLDFILTER_GRID_WIDTH; x++)
        {
            currentFrame = (u8*)sFilterFile + current * 0x124 + y * 0x24 + x * 4;
            packed0 = *(u32*)(currentFrame + 4);
            packed1 = *(u32*)(currentFrame + 8);
            packed2 = *(u32*)(currentFrame + 0x2c);
            packed3 = *(u32*)(currentFrame + 0x28);

            red0 = (s32)(packed0 & 0xff);
            green0 = (s32)((packed0 >> 8) & 0xff);
            blue0 = (s32)((packed0 >> 16) & 0xff);
            currentAlpha0 = (s32)((packed0 >> 24) & 0xff) + sFilterColorOffset;
            red1 = (s32)(packed1 & 0xff);
            green1 = (s32)((packed1 >> 8) & 0xff);
            blue1 = (s32)((packed1 >> 16) & 0xff);
            currentAlpha1 = (s32)((packed1 >> 24) & 0xff) + sFilterColorOffset;
            red2 = (s32)(packed3 & 0xff);
            green2 = (s32)((packed3 >> 8) & 0xff);
            blue2 = (s32)((packed3 >> 16) & 0xff);
            currentAlpha2 = (s32)((packed3 >> 24) & 0xff) + sFilterColorOffset;
            red3 = (s32)(packed2 & 0xff);
            green3 = (s32)((packed2 >> 8) & 0xff);
            blue3 = (s32)((packed2 >> 16) & 0xff);
            currentAlpha3 = (s32)((packed2 >> 24) & 0xff) + sFilterColorOffset;

            if (currentAlpha0 < 0) currentAlpha0 = 0;
            if (currentAlpha0 > 0xff) currentAlpha0 = 0xff;
            if (currentAlpha1 < 0) currentAlpha1 = 0;
            if (currentAlpha1 > 0xff) currentAlpha1 = 0xff;
            if (currentAlpha2 < 0) currentAlpha2 = 0;
            if (currentAlpha2 > 0xff) currentAlpha2 = 0xff;

            if (sFilterBlend < 1.0f)
            {
                oldFrame = (u8*)sFilterFile + previous * 0x124 + y * 0x24 + x * 4;
                oldPacked0 = *(u32*)(oldFrame + 4);
                oldPacked1 = *(u32*)(oldFrame + 8);
                oldPacked2 = *(u32*)(oldFrame + 0x2c);
                oldPacked3 = *(u32*)(oldFrame + 0x28);
                oldRed0 = (s32)(oldPacked0 & 0xff);
                oldGreen0 = (s32)((oldPacked0 >> 8) & 0xff);
                oldBlue0 = (s32)((oldPacked0 >> 16) & 0xff);
                oldRed1 = (s32)(oldPacked1 & 0xff);
                oldGreen1 = (s32)((oldPacked1 >> 8) & 0xff);
                oldBlue1 = (s32)((oldPacked1 >> 16) & 0xff);
                oldRed2 = (s32)(oldPacked3 & 0xff);
                oldGreen2 = (s32)((oldPacked3 >> 8) & 0xff);
                oldBlue2 = (s32)((oldPacked3 >> 16) & 0xff);
                oldRed3 = (s32)(oldPacked2 & 0xff);
                oldGreen3 = (s32)((oldPacked2 >> 8) & 0xff);
                oldBlue3 = (s32)((oldPacked2 >> 16) & 0xff);
                oldAlpha0 = (s32)((oldPacked0 >> 24) & 0xff) + sFilterColorOffset;
                oldAlpha1 = (s32)((oldPacked1 >> 24) & 0xff) + sFilterColorOffset;
                oldAlpha2 = (s32)((oldPacked3 >> 24) & 0xff) + sFilterColorOffset;
                oldAlpha3 = (s32)((oldPacked2 >> 24) & 0xff) + sFilterColorOffset;
                if (oldAlpha0 < 0) oldAlpha0 = 0;
                if (oldAlpha0 > 0xff) oldAlpha0 = 0xff;
                if (oldAlpha1 < 0) oldAlpha1 = 0;
                if (oldAlpha1 > 0xff) oldAlpha1 = 0xff;
                if (oldAlpha2 < 0) oldAlpha2 = 0;
                if (oldAlpha2 > 0xff) oldAlpha2 = 0xff;

#define FLDFILTER_BLEND_CHANNEL(current_, old_) \
                ((s32)((f32)(current_) * blend + (f32)(old_) * inverseBlend))
                red0 = FLDFILTER_BLEND_CHANNEL(red0, oldRed0);
                green0 = FLDFILTER_BLEND_CHANNEL(green0, oldGreen0);
                blue0 = FLDFILTER_BLEND_CHANNEL(blue0, oldBlue0);
                currentAlpha0 = FLDFILTER_BLEND_CHANNEL(currentAlpha0, oldAlpha0);
                red1 = FLDFILTER_BLEND_CHANNEL(red1, oldRed1);
                green1 = FLDFILTER_BLEND_CHANNEL(green1, oldGreen1);
                blue1 = FLDFILTER_BLEND_CHANNEL(blue1, oldBlue1);
                currentAlpha1 = FLDFILTER_BLEND_CHANNEL(currentAlpha1, oldAlpha1);
                red2 = FLDFILTER_BLEND_CHANNEL(red2, oldRed2);
                green2 = FLDFILTER_BLEND_CHANNEL(green2, oldGreen2);
                blue2 = FLDFILTER_BLEND_CHANNEL(blue2, oldBlue2);
                currentAlpha2 = FLDFILTER_BLEND_CHANNEL(currentAlpha2, oldAlpha2);
                red3 = FLDFILTER_BLEND_CHANNEL(red3, oldRed3);
                green3 = FLDFILTER_BLEND_CHANNEL(green3, oldGreen3);
                blue3 = FLDFILTER_BLEND_CHANNEL(blue3, oldBlue3);
                currentAlpha3 = FLDFILTER_BLEND_CHANNEL(currentAlpha3, oldAlpha3);
#undef FLDFILTER_BLEND_CHANNEL
            }

            if (FLDFILTER_ALPHA != 0xff)
            {
                red0 = (red0 * FLDFILTER_ALPHA) / 0xff;
                green0 = (green0 * FLDFILTER_ALPHA) / 0xff;
                blue0 = (blue0 * FLDFILTER_ALPHA) / 0xff;
                currentAlpha0 = (currentAlpha0 * FLDFILTER_ALPHA) / 0xff;
                red1 = (red1 * FLDFILTER_ALPHA) / 0xff;
                green1 = (green1 * FLDFILTER_ALPHA) / 0xff;
                blue1 = (blue1 * FLDFILTER_ALPHA) / 0xff;
                currentAlpha1 = (currentAlpha1 * FLDFILTER_ALPHA) / 0xff;
                red2 = (red2 * FLDFILTER_ALPHA) / 0xff;
                green2 = (green2 * FLDFILTER_ALPHA) / 0xff;
                blue2 = (blue2 * FLDFILTER_ALPHA) / 0xff;
                currentAlpha2 = (currentAlpha2 * FLDFILTER_ALPHA) / 0xff;
                red3 = (red3 * FLDFILTER_ALPHA) / 0xff;
                green3 = (green3 * FLDFILTER_ALPHA) / 0xff;
                blue3 = (blue3 * FLDFILTER_ALPHA) / 0xff;
                currentAlpha3 = (currentAlpha3 * FLDFILTER_ALPHA) / 0xff;
            }

            for (channel = 0; channel < 0x10; channel++)
            {
                color[channel] = 0;
            }
            color[0] = (u8)red0;
            color[1] = (u8)green0;
            color[2] = (u8)blue0;
            color[3] = (u8)currentAlpha0;
            color[4] = (u8)red1;
            color[5] = (u8)green1;
            color[6] = (u8)blue1;
            color[7] = (u8)currentAlpha1;
            color[8] = (u8)red2;
            color[9] = (u8)green2;
            color[10] = (u8)blue2;
            color[11] = (u8)currentAlpha2;
            color[12] = (u8)red3;
            color[13] = (u8)green3;
            color[14] = (u8)blue3;
            color[15] = (u8)currentAlpha3;
            vertices = ((FilterQuad*)sFilterGrid_abs)[y * FLDFILTER_GRID_WIDTH + x].vert;

            for (vertex = 0; vertex < 4; vertex++)
            {
                channel = vertex * 4;
                value = (f32)color[channel];
                vertices[vertex].u.els.color.r = value;
                vertices[vertex].u.els.color.g = (f32)color[channel + 1];
                vertices[vertex].u.els.color.b = (f32)color[channel + 2];
                vertices[vertex].u.els.color.a = (f32)color[channel + 3];
            }
            (*D_009600A0_abs)(4, vertices, 4);
        }
    }

    func_004d7f60(2, 0x44);
    func_004d7f60(3, 0x717fb);
}

// FUN_001d50c0
void FUN_001d50c0(s32 index, u32 type, s32 duration)
{
    if (duration == 0)
    {
        sFilterBlend = 1.0f;
        sFilterBlendDuration = index;
        sFilterPrevious = 1.0f;
    }
    else
    {
        sFilterBlend = 0.0f;
        sFilterBlendDuration = sFilterCurrent;
        sFilterPrevious = (f32)duration;
    }
    sFilterCurrent = index;
    *(u32*)((u8*)sFilterFile + index * 0x124) = type;
}

// FUN_001d5130
void FUN_001d5130(u32 alpha)
{
    FLDFILTER_ALPHA = alpha;
}

/* Return the closest camera point to the controlled character. */
// FUN_001d5140
s32 FUN_001d5140(KwlnTask* cameraTask)
{
    s32 bestIndex;
    FldFilterCameraWork* work;
    FldFilterCameraWork* indexedWork;
    struct
    {
        RwV3d playerPos;
        u32 alignment;
        RwV3d pointCopy;
    } scratch;
#define playerPos scratch.playerPos
#define pointCopy scratch.pointCopy
    f32 bestDistance;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 distance;
    f32 pointY;
    f32 pointZ;
    f32 pointX;
    s32 index;

    work = (FldFilterCameraWork*)cameraTask->workData;
    K_FldFrame_CtlCopyPos(&playerPos, work->playerResrc->collisCtlTask);
    pointCopy = playerPos;
    bestDistance = fGpffff8248;
    index = 0;
    pointY = pointCopy.y;
    pointZ = pointCopy.z;
    pointX = pointCopy.x;
    for (; index < 9; index++)
    {
        indexedWork = work;
        indexedWork = (FldFilterCameraWork*)((s32)indexedWork + index * sizeof(RwV3d));
        dx = indexedWork->cameraPoints[0].x - pointX;
        dy = indexedWork->cameraPoints[0].y - pointY;
        dz = indexedWork->cameraPoints[0].z - pointZ;
        distance = sqrtf(dx * dx + dy * dy + dz * dz);
        if (bestDistance > distance)
        {
            bestDistance = distance;
            bestIndex = index;
        }
    }
    return bestIndex;
#undef pointCopy
#undef playerPos
}
// FUN_001d5220 NONMATCHING
#pragma push
#pragma schedule on
void* FUN_001d5220(KwlnTask* cameraTask)
{
    FldFilterCameraWork* work;
    RwV3d target;
    RwV3d cameraPos;
    RwV3d translation;
    RwV3d delta;
    RwV3d projection;
    RwV3d curvePosition;
    RwV3d point0;
    RwV3d point1;
    RwCamera* mainCamera;
    RwFrame* mainFrame;
    void* curve;
    s32 nearest;
    s32 previous;
    s32 next;
    s32 moved;
    f32 horizontalDistance;
    f32 verticalDistance;
    f32 amount;
    f32 denominator;
    f32 fraction;
    f32 dot;
    f32 debugDeltaX;
    f32 debugDeltaY;
    f32 debugDeltaZ;
    f32 debugProjectionX;
    f32 debugProjectionY;
    f32 debugProjectionZ;

    work = (FldFilterCameraWork*)cameraTask->workData;
    if (work->playerResrc == NULL)
    {
        return KWLNTASK_CONTINUE;
    }
    if (work->state != 0)
    {
        return KWLNTASK_CONTINUE;
    }

    switch (work->type)
    {
        case 0:
        case 2:
        case 5:
            K_FldFrame_CtlCopyPos(&target, work->playerResrc->collisCtlTask);
            cameraPos = *K_FldCamera_GetPos(cameraTask);

            if (work->type == 0 || work->type == 5)
            {
                mainCamera = kwlnGetMainCamera();
                mainFrame = mainCamera->object.object.parent;
                if (((RwFrame*)kwlnGetMainCamera()->object.object.parent)->object.parent == work->parentFrame)
                {
                    func_004cb590(mainFrame);
                    func_004cb420(work->parentFrame, work->frame);
                    func_004cb420(work->frame, kwlnGetMainCamera()->object.object.parent);
                }
            }
            else
            {
                mainCamera = kwlnGetMainCamera();
                mainFrame = mainCamera->object.object.parent;
                if (((RwFrame*)kwlnGetMainCamera()->object.object.parent)->object.parent != NULL)
                {
                    func_004cb590(mainFrame);
                }
                if (work->frame->object.parent != NULL)
                {
                    func_004cb590(work->frame);
                }
                func_004cb420(work->parentFrame, kwlnGetMainCamera()->object.object.parent);
            }

            cameraPos.x += work->posOffset.x;
            cameraPos.y += work->posOffset.y;
            cameraPos.z += work->posOffset.z;
            delta.x = target.x - cameraPos.x;
            delta.y = target.y - cameraPos.y;
            delta.z = target.z - cameraPos.z;
            moved = 0;

            horizontalDistance = sqrtf(delta.x * delta.x + delta.z * delta.z);
            if (work->xzDeadZone < horizontalDistance)
            {
                amount = horizontalDistance - work->xzDeadZone;
                translation.x = delta.x;
                translation.y = 0.0f;
                translation.z = delta.z;
                func_004c69f0(&translation, &translation);
                translation.x *= amount;
                translation.y *= amount;
                translation.z *= amount;
                func_004cb750(work->frame, &translation, rwCOMBINEPOSTCONCAT);
                moved = 1;
            }

            verticalDistance = delta.y;
            amount = verticalDistance < 0.0f ? -verticalDistance : verticalDistance;
            if (work->yDeadZone / 2.0f < amount)
            {
                amount -= work->yDeadZone / 2.0f;
                translation.x = 0.0f;
                translation.z = 0.0f;
                translation.y = verticalDistance < 0.0f ? -amount : amount;
                func_004cb750(work->frame, &translation, rwCOMBINEPOSTCONCAT);
                moved = 1;
            }

            if (moved != 0 && work->type == 2)
            {
                mainCamera = kwlnGetMainCamera();
                FUN_001a1210(kwlnGetMainCamera(), &mainCamera->viewMatrix.at,
                             K_FldCamera_GetPos(cameraTask), NULL);
            }
            break;

        case 3:
            K_FldFrame_CtlCopyPos(&target, work->playerResrc->collisCtlTask);
            nearest = FUN_001d5140(cameraTask);
            curve = *(void**)((u8*)K_Field_Get() + 0x116c);
            if (curve != NULL && *(void**)((u8*)K_Field_Get() + 0x116c) != NULL)
            {
                previous = nearest - 1;
                if (previous < 0)
                {
                    previous = 0;
                }
                next = nearest + 1;
                if (next > 8)
                {
                    next = 8;
                }
                point0 = work->cameraPoints[previous];
                point1 = work->cameraPoints[next];
                delta.x = point1.x - point0.x;
                delta.y = point1.y - point0.y;
                delta.z = point1.z - point0.z;
                projection.x = target.x - point0.x;
                projection.y = target.y - point0.y;
                projection.z = target.z - point0.z;
                debugDeltaX = delta.x;
                debugDeltaY = delta.y;
                debugDeltaZ = delta.z;
                debugProjectionX = projection.x;
                debugProjectionY = projection.y;
                debugProjectionZ = projection.z;
                denominator = debugDeltaX * debugDeltaX + debugDeltaY * debugDeltaY + debugDeltaZ * debugDeltaZ;
                if (denominator != 0.0f)
                {
                    fraction = (debugProjectionX * debugDeltaX + debugProjectionY * debugDeltaY +
                                debugProjectionZ * debugDeltaZ) / denominator;
                    debugProjectionX = point0.x + debugDeltaX * fraction - point0.x;
                    debugProjectionY = point0.y + debugDeltaY * fraction - point0.y;
                    debugProjectionZ = point0.z + debugDeltaZ * fraction - point0.z;
                    projection.x = debugProjectionX;
                    projection.y = debugProjectionY;
                    projection.z = debugProjectionZ;
                    amount = sqrtf(debugProjectionX * debugProjectionX +
                                   debugProjectionY * debugProjectionY +
                                   debugProjectionZ * debugProjectionZ);
                    fraction = amount / sqrtf(denominator);
                    dot = debugDeltaX * debugProjectionX + debugDeltaY * debugProjectionY +
                          debugDeltaZ * debugProjectionZ;
                    printf(D_00683A48,
                           func_00530da0(amount),
                           func_00530da0(amount),
                           func_00530da0(fraction),
                           func_00530da0(dot));
                    dot = debugDeltaX * debugProjectionX + debugDeltaY * debugProjectionY +
                          debugDeltaZ * debugProjectionZ;
                    if (dot < 0.0f)
                    {
                        fraction = 0.0f;
                    }
                    if (fraction > 1.0f)
                    {
                        fraction = 1.0f;
                    }
                    fraction *= 0.25f;
                    printf(D_007CC2CC, func_00530da0(fraction));
                    fraction += (f32)previous * 0.125f;
                    printf(D_007CC2CC, func_00530da0(fraction));
                    printf(D_007CC2CC, func_00530da0(fraction));
                    if (fraction > 1.0f)
                    {
                        fraction = 1.0f;
                    }
                    if (fraction < 0.0f)
                    {
                        fraction = 0.0f;
                    }
                    FUN_0048d480(fraction, *(void**)((u8*)curve + 0xa1c), 10, &curvePosition, 0);
                    K_Draw_SetPointCenter(work->pointTask0, &curvePosition);
                    K_Draw_SetPointCenter(work->pointTask1, &point0);
                    K_Draw_SetPointCenter(work->pointTask2, &point1);
                }
            }
            break;
        case 1:
        case 4:
        default:
            break;
    }

    K_Draw_SetCylinderDrawEnabled(cameraTask->child, (work->flags & 0x80000000) != 0);
    cameraPos = *K_FldCamera_GetPos(cameraTask);
    K_Draw_SetCylinderCenter(cameraTask->child, &cameraPos);
    K_Draw_SetCylinderRadius(cameraTask->child, work->xzDeadZone);
    K_Draw_SetCylinderHeight(cameraTask->child, work->yDeadZone);
    return KWLNTASK_CONTINUE;
}
#pragma pop

// FUN_001d59e0
void FUN_001d59e0(KwlnTask* cameraTask)
{
    FldFilterCameraWork* work;

    work = (FldFilterCameraWork*)cameraTask->workData;
    if (((RwFrame*)kwlnGetMainCamera()->object.object.parent)->object.parent != NULL)
    {
        func_004cb590((RwFrame*)kwlnGetMainCamera()->object.object.parent);
    }
    if (work->frame->object.parent != NULL)
    {
        func_004cb590(work->frame);
    }
    func_004caf80(work->frame);
    func_004cb420(work->parentFrame, kwlnGetMainCamera()->object.object.parent);
    (*(void (**)(void*))D_0096017c_abs)(cameraTask->workData);
}

// FUN_001d5a90 NONMATCHING
KwlnTask* FUN_001d5a90(KwlnTask* parentTask)
{
    RwFrame** slot0;
    RwFrame** slot1;
    KwlnTask* task;
    FldFilterCameraWork* work;

    work = (*(void* (**)(u32, u32, u32))D_00960184)(1, 0xd0, rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreateWithAutoPriority(parentTask,
                                          10,
                                          D_00683A60,
                                          (KwlnTaskUpdateFunc)FUN_001d5220,
                                          (KwlnTaskDestroyFunc)FUN_001d59e0,
                                          work);
    slot1 = &work->frame;
    *slot1 = func_004caf10();
    if (*slot1 == NULL)
    {
        kwlnTaskDestroyWithHierarchy(task);
        return NULL;
    }
    func_004cb930(*slot1);
    slot0 = &work->parentFrame;
    *slot0 = ((RwFrame*)kwlnGetMainCamera()->object.object.parent)->object.parent;
    if (*slot0 != NULL)
    {
        func_004cb590(kwlnGetMainCamera()->object.object.parent);
        func_004cb420(*slot0, work->frame);
        func_004cb420(*slot1, kwlnGetMainCamera()->object.object.parent);
    }
    else
    {
        K_Assert(D_00683A78, 0x1b4);
    }
    K_Draw_CreateCylinderTask(task);
    return task;
}
