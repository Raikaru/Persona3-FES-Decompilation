#include "Kosaka/k_window.h"
#include "rw/rwcore.h"
#include "h_dbprt.h"
#include "Kosaka/k_assert.h"
#include "Kernel/Kwln/kwlnTask.h"
extern u32 D_00960184[];
extern void (*D_0096017c)(void* memory);
extern u16 DAT_007e094c;
extern u16 DAT_007e094e;
extern u16 DAT_007e0952;
extern u32 uGpffffb450;
extern u32 uGpffffb454;
extern u32 gp0xffff9460;
extern u32 gp0xffff9464;
extern u32 gp0xffff9468;
extern u32 gp0xffff946c;
extern u32 gp0xffff9470;
extern u32 gp0xffff9474;
extern u32 gp0xffff9478;
extern u32 gp0xffff947c;
extern u32 gp0xffff9480;
extern const char gp0xffff9484[];
extern const char gp0xffff9488[];
extern const char gp0xffff9490[];
extern const char gp0xffff9498[];
extern const char gp0xffff94a0[];
extern const char gp0xffff94a8[];
extern const char gp0xffff94b0[];
extern const char gp0xffff94b8[];
extern u32 uGpffff94c4;
extern void func_00524270(void* destination, const void* source);
extern s32 func_00524388(const char* text);
extern f32 func_00530da0(f32 value);
extern void func_0019d3f0(const char* file, s32 line);

extern void func_00494cc0(void* colorData);
extern void func_001e7a60(void* renderData);
extern void* func_001a1550(KwlnTask* task);
extern f32 func_001e7c20(s32 scale);
extern void func_001e7b10(void* quad, f32 scale);
extern void func_004933d0(void* renderLayout);
extern void func_00493370(void* renderLayout, s32 state);
extern void* func_001e78c0(s32 width, s32 height);
extern void func_001e7aa0(void* work, s32 index, void* data);
extern void* func_00494be0(void);
extern f32 func_001a4600(void* camera);
extern u32 func_00195790(void);
extern void func_004d7f60(s32 state, u32 value);
extern void (*D_00960090)(u32 state, u32 value);
extern RwCamera* kwlnGetMainCamera(void);

typedef struct KWindowQuad
{
    RwV3d vertex[4];
} KWindowQuad;

typedef struct KWindowQuadStore
{
    u8 unknown00[0x14];
    KWindowQuad* quad;
} KWindowQuadStore;

typedef struct KWindowRenderLayout
{
    u8 unknown00[0x5c];
    KWindowQuadStore* quadStore;
} KWindowRenderLayout;
// FUN_001a1550 NONMATCHING
void* func_001a1550(KwlnTask* task)
{
    KWindowTaskWork* work;
    RwRGBA* colorA;
    RwRGBA* colorB;
    RwRect frame;
    f32 progress;
    f32 width;
    f32 height;

    work = (KWindowTaskWork*)task->workData;
    switch (work->state)
    {
        case 0:
            work->renderData = func_001e78c0(5, 0x48);
            work->colorDataA = func_00494be0();
            work->colorDataB = func_00494be0();
            if (work->renderData == NULL || work->colorDataA == NULL || work->colorDataB == NULL)
            {
                work->state = 8;
                break;
            }

            colorA = (RwRGBA*)((u8*)work->colorDataA + 4);
            colorA->r = work->colorA.r;
            colorA->g = work->colorA.g;
            colorA->b = work->colorA.b;
            colorA->a = work->colorA.a;
            colorB = (RwRGBA*)((u8*)work->colorDataB + 4);
            colorB->r = work->colorB.r;
            colorB->g = work->colorB.g;
            colorB->b = work->colorB.b;
            colorB->a = work->colorB.a;
            func_001e7aa0(work->renderData, 0, work->colorDataA);
            func_001e7aa0(work->renderData, 1, work->colorDataB);
            work->horizontalOffset = 0.0f;
            work->verticalOffset = 0.0f;
            work->horizontalInset = 0.0f;
            work->verticalInset = 0.0f;
            work->alphaStep = (f32)work->colorB.a / 8.0f;
            work->fieldOfView = func_001a4600(kwlnGetMainCamera());
            work->state = 1;
            break;

        case 1:
            width = (f32)work->rect.w;
            progress = work->horizontalInset + width / 2.0f;
            if (progress >= width)
            {
                progress = width;
                work->state = 2;
            }
            work->horizontalInset = progress;
            frame = work->rect;
            frame.w = (s16)progress;
            func_001a23e0(task, &frame);
            break;

        case 2:
            height = (f32)work->rect.h;
            progress = work->verticalInset + height / 2.0f;
            if (progress >= height)
            {
                progress = height;
                work->state = 3;
            }
            work->verticalInset = progress;
            frame = work->rect;
            frame.y = (s16)((f32)work->rect.y + work->rect.h - progress);
            frame.h = (s16)progress;
            func_001a23e0(task, &frame);
            break;

        case 3:
            width = (f32)work->rect.w;
            progress = work->horizontalOffset + width / 2.0f;
            if (progress >= width)
            {
                progress = width;
                work->state = 4;
            }
            work->horizontalOffset = progress;
            frame = work->rect;
            frame.x = (s16)((f32)work->rect.x + work->rect.w - progress);
            frame.w = (s16)progress;
            func_001a23e0(task, &frame);
            break;

        case 4:
            height = (f32)work->rect.h;
            progress = work->verticalOffset + height / 2.0f;
            if (progress >= height)
            {
                progress = height;
                work->state = 5;
            }
            work->verticalOffset = progress;
            frame = work->rect;
            frame.h = (s16)progress;
            func_001a23e0(task, &frame);
            break;

        case 5:
            colorB = (RwRGBA*)((u8*)work->colorDataB + 4);
            if (work->alphaStep < 1.0f)
            {
                work->alphaStep = 1.0f;
            }
            if (colorB->a < work->colorB.a)
            {
                colorB->a = (u8)((f32)colorB->a + work->alphaStep);
                if (colorB->a >= work->colorB.a)
                {
                    colorB->a = work->colorB.a;
                    work->state = 6;
                }
            }
            else
            {
                work->state = 6;
            }
            func_001a23e0(task, &work->rect);
            break;

        case 6:
            func_001a23e0(task, &work->rect);
            work->state = 7;
            break;

        case 7:
            colorA = (RwRGBA*)((u8*)work->colorDataA + 4);
            colorB = (RwRGBA*)((u8*)work->colorDataB + 4);
            if (colorB->a != 0)
            {
                colorB->a--;
            }
            if (colorA->a != 0)
            {
                colorA->a--;
            }
            if (colorA->a == 0 && colorB->a == 0)
            {
                work->state = 8;
            }
            break;

        case 8:
            return KWLNTASK_STOP;
    }

    if (work->renderData != NULL &&
        work->fieldOfView != func_001a4600(kwlnGetMainCamera()))
    {
        func_001a23e0(task, &work->rect);
    }
    if (func_00195790() == 1 && work->request == 1)
    {
        (*D_00960090)(6, 0);
        (*D_00960090)(8, 0);
        func_004d7f60(2, 0x44);
        func_004d7f60(3, 0x717fb);
    }
    return KWLNTASK_CONTINUE;
}


typedef struct KWindowRenderData
{
    u8 unknown00[0x18];
    KWindowRenderLayout* layout;
} KWindowRenderData;

// FUN_001A2170 NONMATCHING
void func_001a2170(KwlnTask* task)
{
    KWindowTaskWork* work;

    work = (KWindowTaskWork*)task->workData;
    func_00494cc0(work->colorDataA);
    func_00494cc0(work->colorDataB);
    func_001e7a60(work->renderData);
    RwFree(work->buffer);
    RwFree(task->workData);
}

// FUN_001A2200 NONMATCHING
KwlnTask* func_001a2200(KwlnTask* parent, const RwRect* rect, const RwRGBA* colorA, const RwRGBA* colorB)
{
    KWindowTaskWork* work;
    KwlnTask* task;

    work = RwCalloc(1, sizeof(KWindowTaskWork), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreateWithAutoPriority(parent,
                                          0x106F,
                                          "ksk window",
                                          func_001a1550,
                                          func_001a2170,
                                          work);
    work->request = 1;
    work->rect = *rect;
    work->colorA = *colorA;
    work->colorB = *colorB;
    work->bufferSize = (rect->x / 8) * (rect->y / 8) + 0x20;
    work->buffer = RwCalloc(1, work->bufferSize, rwMEMHINTDUR_GLOBAL);
    work->bufferAlias = work->buffer;

    return task;
}

// FUN_001A2390
u32 func_001a2390(const KwlnTask* task)
{
    const KWindowTaskWork* work;

    work = (const KWindowTaskWork*)task->workData;
    if (work->state == 6)
    {
        goto zero;
    }
    if (work->state != 8)
    {
        goto one;
    }
zero:
    return 0;
one:
    return 1;
}

// FUN_001A23D0
void func_001a23d0(KwlnTask* task, u32 request)
{
    KWindowTaskWork* work;

    work = (KWindowTaskWork*)task->workData;
    work->request = request;
}

// FUN_001A23E0 NONMATCHING
void func_001a23e0(KwlnTask* task, const RwRect* rect)
{
    KWindowTaskWork* work;
    KWindowRenderData* renderData;
    KWindowRenderLayout* layout;
    KWindowQuad* quad;
    f32 left;
    f32 top;
    f32 right;
    f32 bottom;

    work = (KWindowTaskWork*)task->workData;
    if (work->state != 6)
    {
        return;
    }

    renderData = (KWindowRenderData*)work->renderData;
    layout = renderData->layout;
    func_00493370(layout, 2);
    quad = layout->quadStore->quad;
    left = (f32)rect->x;
    top = (f32)rect->y;
    right = (f32)(rect->x + rect->w);
    bottom = (f32)(rect->y + rect->h);

    quad[0].vertex[0].x = left;
    quad[0].vertex[0].y = top;
    quad[0].vertex[1].x = right;
    quad[0].vertex[1].y = top;
    quad[0].vertex[2].x = left;
    quad[0].vertex[2].y = top + 2.0f;
    func_001e7b10(&quad[0], func_001e7c20(-16));

    quad[1].vertex[0].x = right - 2.0f;
    quad[1].vertex[0].y = top;
    quad[1].vertex[1].x = right;
    quad[1].vertex[1].y = top;
    quad[1].vertex[2].x = right - 2.0f;
    quad[1].vertex[2].y = top + 2.0f;
    func_001e7b10(&quad[1], func_001e7c20(-16));

    quad[2].vertex[0].x = left;
    quad[2].vertex[0].y = bottom - 2.0f;
    quad[2].vertex[1].x = right;
    quad[2].vertex[1].y = bottom - 2.0f;
    quad[2].vertex[2].x = left;
    quad[2].vertex[2].y = bottom;
    func_001e7b10(&quad[2], func_001e7c20(-16));

    quad[3].vertex[0].x = left;
    quad[3].vertex[0].y = bottom - 2.0f;
    quad[3].vertex[1].x = left + 2.0f;
    quad[3].vertex[1].y = bottom - 2.0f;
    quad[3].vertex[2].x = left;
    quad[3].vertex[2].y = bottom;
    func_001e7b10(&quad[3], func_001e7c20(-16));

    quad[4].vertex[0].x = left;
    quad[4].vertex[0].y = top;
    quad[4].vertex[1].x = left;
    quad[4].vertex[1].y = top + 2.0f;
    quad[4].vertex[2].x = left + 2.0f;
    quad[4].vertex[2].y = top;
    func_001e7b10(&quad[4], func_001e7c20(-32));

    func_004933d0(layout);
}
/*
 * The task below owns the small text/value editor used by the debug window.
 * Its work area is deliberately kept separate from KWindowTaskWork above:
 * the retail task stores the manager at KwlnTask::workData and all offsets
 * below are relative to that manager block.
 */
typedef void (*KWindowEntryCallback)(void* value);

typedef struct KWindowEntry
{
    s32 id;                         /* 0x000 */
    s32 type;                       /* 0x004 */
    char name[0x100];               /* 0x008 */
    char text[0x100];               /* 0x108 */
    s32 intValue;                   /* 0x208 */
    f32 floatValue;                 /* 0x20c */
    s32 minValue;                   /* 0x210 */
    s32 maxValue;                   /* 0x214 */
    s32 flags;                      /* 0x218 */
    KWindowEntryCallback callback;  /* 0x21c */
    void* callbackValue;            /* 0x220 */
    struct KWindowEntry* previous;  /* 0x224 */
    struct KWindowEntry* next;      /* 0x228 */
} KWindowEntry;

typedef struct KWindowManagerWork
{
    s32 state;                      /* 0x00 */
    u32 flags;                      /* 0x04 */
    s32 mode;                       /* 0x08 */
    u32 request;                    /* 0x0c */
    s32 x;                          /* 0x10 */
    s32 y;                          /* 0x14 */
    s32 width;                      /* 0x18 */
    s32 height;                     /* 0x1c */
    void* renderData;               /* 0x20 */
    void* colorData;                /* 0x24 */
    KwlnTask* windowTask;           /* 0x28 */
    s32 firstVisible;               /* 0x2c */
    s32 cursor;                     /* 0x30 */
    s32 visibleRows;                /* 0x34 */
    s32 entryCount;                 /* 0x38 */
    KWindowEntry* entries;          /* 0x3c */
    s32 nextId;                     /* 0x40 */
} KWindowManagerWork;

typedef struct KWindowEntryDescriptor
{
    const char* name;
    s32 type;
    const char* text;
    s32 value0;
    s32 value1;
    s32 value2;
    s32 value3;
    KWindowEntryCallback callback;
} KWindowEntryDescriptor;

extern void H_Dbprt_Fmt3D(RwV2d pos, const char* fmt, ...);
extern void H_Dbprt_FmtCol3D(RwV2d pos, RwRGBA color, const char* fmt, ...);
extern s32 strlen(const char* text);
extern void func_00524270(void* destination, const void* source);
extern void func_0019d3f0(const char* fileName, s32 line);
extern void (*D_0096017c)(void* object);
#pragma alias D_0096017c_abs D_0096017c
extern u32 D_0096017c_abs[];
extern const char D_00678AF8[];
extern const char D_00678B08[];
extern const char D_00678B18[];
extern const char D_00678B30[];

static const char sKWindowValueLabel[] = "%s";
static const char sKWindowType2Label[] = "off";
static const char sKWindowType3Label[] = "%d";
static const char sKWindowType4Label[] = "%.2f";
static const char sKWindowTextLabel[] = "%s";

void* func_001a2a80(KwlnTask* task);
void func_001a3a60(KwlnTask* task);
void func_001a44a0(KwlnTask* task);

KwlnTask* func_001a3b10(KwlnTask* parent, u32 width, u32 height, u32 mode);
void func_001a3c30(KwlnTask* task);
u32 func_001a3f20(KwlnTask* task, const char* name);
char* func_001a4010(KwlnTask* task, s32 id);
void func_001a4050(KwlnTask* task, u32 id, KWindowEntryCallback callback);
void func_001a4090(KwlnTask* task, u32 id, const char* text);
void func_001a4110(KwlnTask* task, u32 id, s32 value, s32 minValue,
                   s32 maxValue, s32 flags);
s32* func_001a41b0(KwlnTask* task, u32 id);
void func_001a41f0(KwlnTask* task, u32 id, s32 value);
void func_001a4260(KwlnTask* task, u32 id, s32 value, s32 minValue,
                   s32 maxValue);
KWindowEntry* func_001a4330(KwlnTask* task, s32 id);
s32 func_001a4510(KwlnTask* task);

static KWindowManagerWork* KWindow_GetManager(KwlnTask* task)
{
    return (KWindowManagerWork*)task->workData;
}

static KWindowEntry* KWindow_GetCurrentEntry(KWindowManagerWork* manager)
{
    KWindowEntry* entry;
    s32 index;

    entry = manager->entries;
    index = manager->firstVisible + manager->cursor;
    if (index < 0 || index >= manager->entryCount)
    {
        return NULL;
    }

    while (index > 0 && entry != NULL)
    {
        entry = entry->next;
        index--;
    }

    return entry;
}

static void KWindow_InvokeEntryCallback(KWindowEntry* entry)
{
    void* value;

    if (entry == NULL || entry->callback == NULL)
    {
        return;
    }

    value = NULL;
    if (entry->type == 4)
    {
        value = &entry->floatValue;
    }
    else if (entry->type == 3 || entry->type == 2)
    {
        value = &entry->intValue;
    }
    else if (entry->type == 1)
    {
        value = entry->text;
    }

    if (entry->callbackValue != NULL)
    {
        entry->callback((void*)&value);
    }
    else
    {
        entry->callback(value);
    }
}

static void KWindow_ApplyValueDelta(KWindowEntry* entry, s32 delta,
                                    f32 floatDelta)
{
    f32 value;

    if (entry == NULL)
    {
        return;
    }

    if (entry->type == 4)
    {
        value = entry->floatValue + floatDelta;
        if (value < (f32)entry->minValue)
        {
            value = (f32)entry->maxValue;
        }
        else if (value > (f32)entry->maxValue)
        {
            value = (f32)entry->minValue;
        }
        entry->floatValue = value;
    }
    else if (entry->type == 3)
    {
        entry->intValue += delta;
        if (entry->intValue < entry->minValue)
        {
            entry->intValue = entry->maxValue;
        }
        else if (entry->intValue > entry->maxValue)
        {
            entry->intValue = entry->minValue;
        }
    }
    else if (entry->type == 2)
    {
        entry->intValue = (entry->intValue == 1) ? 0 : 1;
    }
}

static void KWindow_MoveDown(KWindowManagerWork* manager)
{
    s32 visible;

    if (manager == NULL || manager->entryCount <= 0)
    {
        return;
    }
    visible = manager->visibleRows;
    if (visible > manager->entryCount)
    {
        visible = manager->entryCount;
    }
    manager->cursor++;
    if (manager->cursor >= visible)
    {
        manager->cursor = visible - 1;
        manager->firstVisible++;
        if (manager->entryCount <
            manager->firstVisible + 1 + visible)
        {
            manager->cursor = 0;
            manager->firstVisible = 0;
        }
    }
}

static void KWindow_MoveUp(KWindowManagerWork* manager)
{
    s32 visible;

    if (manager == NULL || manager->entryCount <= 0)
    {
        return;
    }
    visible = manager->visibleRows;
    if (visible > manager->entryCount)
    {
        visible = manager->entryCount;
    }
    manager->cursor--;
    if (manager->cursor < 0)
    {
        manager->cursor = 0;
        manager->firstVisible--;
        if (manager->firstVisible < 0)
        {
            manager->cursor = visible - 1;
            manager->firstVisible = manager->entryCount - visible;
        }
    }
}

static void KWindow_SetManagerRender(KWindowManagerWork* manager)
{
    KWindowRenderData* renderData;
    KWindowRenderLayout* layout;
    KWindowQuad* quad;
    RwRGBA colorA;
    RwRGBA colorB;
    RwRGBA* color;
    RwRGBA* tile;
    s32 i;

    if (manager == NULL)
    {
        return;
    }
    color = (RwRGBA*)&gp0xffff9460;
    colorA = *color;
    color = (RwRGBA*)&gp0xffff9464;
    colorB = *color;
    uGpffff94c4 = 0xff004ae3;
    if (manager->mode == 1)
    {
        colorA = *(RwRGBA*)&gp0xffff9468;
        colorB = *(RwRGBA*)&gp0xffff946c;
        uGpffff94c4 = 0xff000054;
    }
    else if (manager->mode == 2)
    {
        colorA = *(RwRGBA*)&gp0xffff9470;
        colorB = *(RwRGBA*)&gp0xffff9474;
        uGpffff94c4 = 0xff004ae3;
    }
    else if (manager->mode == 3)
    {
        colorA = *(RwRGBA*)&gp0xffff9478;
        colorB = *(RwRGBA*)&gp0xffff947c;
        uGpffff94c4 = 0xff404040;
    }

    if (manager->colorData != NULL)
    {
        RwRGBA* colorData;
        colorData = (RwRGBA*)((u8*)manager->colorData + 4);
        *colorData = colorA;
        func_001e7aa0(manager->renderData, 0, manager->colorData);
    }
    renderData = (KWindowRenderData*)manager->renderData;
    layout = renderData != NULL ? renderData->layout : NULL;
    if (layout == NULL)
    {
        return;
    }
    tile = *(RwRGBA**)((u8*)layout + 0x30);
    if (tile != NULL)
    {
        for (i = 0; i < 4; i++)
        {
            tile[i] = colorA;
        }
    }
    if (layout->quadStore == NULL)
    {
        return;
    }
    quad = layout->quadStore->quad;
    if (quad == NULL)
    {
        return;
    }
    quad[0].vertex[0].x = 0.0f;
    quad[0].vertex[0].y = 0.0f;
    quad[0].vertex[1].x = 0.0f;
    quad[0].vertex[1].y = 0.0f;
    quad[0].vertex[2].x = 0.0f;
    quad[0].vertex[2].y = 0.0f;
    quad[0].vertex[3].x = 0.0f;
    quad[0].vertex[3].y = 0.0f;
    func_001e7b10(quad, func_001e7c20(-16));
    func_004933d0(layout);
    (void)colorB;
}

static void KWindow_DrawSelection(KWindowManagerWork* manager)
{
    KWindowRenderData* renderData;
    KWindowRenderLayout* layout;
    KWindowQuad* quad;
    f32 top;
    f32 bottom;
    void (**renderHook)(void);

    if (manager == NULL || manager->renderData == NULL)
    {
        return;
    }
    renderData = (KWindowRenderData*)manager->renderData;
    layout = renderData->layout;
    if (layout == NULL || layout->quadStore == NULL ||
        layout->quadStore->quad == NULL)
    {
        return;
    }
    func_00493370(layout, 2);
    quad = layout->quadStore->quad;
    top = (f32)(manager->y + 2 + manager->cursor * 12);
    bottom = top + 12.0f;
    quad[0].vertex[0].x = (f32)(manager->x + 2);
    quad[0].vertex[0].y = top;
    quad[0].vertex[1].x = (f32)(manager->x + manager->width - 2);
    quad[0].vertex[1].y = top;
    quad[0].vertex[2].x = (f32)(manager->x + 2);
    quad[0].vertex[2].y = bottom;
    quad[0].vertex[3].x = (f32)(manager->x + manager->width - 2);
    quad[0].vertex[3].y = bottom;
    func_001e7b10(quad, func_001e7c20(0xfff0));
    func_004933d0(layout);
    if (D_00960090 != NULL)
    {
        (*D_00960090)(6, 0);
        (*D_00960090)(8, 0);
    }
    func_004d7f60(2, 0x44);
    func_004d7f60(3, 0x717fb);
    renderHook = (void (**)(void))((u8*)manager->renderData + 0x48);
    if (*renderHook != NULL)
    {
        (**renderHook)();
    }
}

// FUN_001A2720 NONMATCHING
void func_001a2720(KwlnTask* task)
{
    KWindowManagerWork* manager;
    KWindowEntry* entry;
    RwV2d position;
    RwRGBA color;
    s32 index;
    s32 right;
    s32 textWidth;

    manager = KWindow_GetManager(task);
    if (manager == NULL)
    {
        return;
    }

    color = *(RwRGBA*)&gp0xffff9480;
    position.x = (f32)(manager->x + 2);
    position.y = (f32)(manager->y + 2);
    right = manager->x + manager->width;
    entry = manager->entries;
    index = 0;
    while (entry != NULL)
    {
        if (index >= manager->firstVisible &&
            index < manager->firstVisible + manager->visibleRows)
        {
            position.x = (f32)(manager->x + 2);
            H_Dbprt_Fmt3D(position, "%s", entry->name);
            if (entry->type == 1)
            {
                textWidth = strlen(entry->text);
                position.x = (f32)(right - 2 - (textWidth + 1) * 12);
                H_Dbprt_FmtCol3D(position, color, "%s", entry->text);
            }
            else if (entry->type == 2)
            {
                textWidth = strlen(sKWindowType2Label);
                position.x = (f32)(right - 2 - (textWidth + 1) * 12);
                if (entry->intValue == 1)
                {
                    H_Dbprt_FmtCol3D(position, color, "on");
                }
                else
                {
                    H_Dbprt_FmtCol3D(position, color, "off");
                }
            }
            else if (entry->type == 3)
            {
                position.x = (f32)(right - (entry->flags != 0 ? 0x86 : 0x6e));
                H_Dbprt_FmtCol3D(position, color, "%d", entry->intValue);
            }
            else if (entry->type == 4)
            {
                position.x = (f32)(right - 0x62);
                H_Dbprt_FmtCol3D(position, color, "%.2f",
                                 func_00530da0(entry->floatValue));
            }
        }
        position.y += 12.0f;
        entry = entry->next;
        index++;
    }
}

// FUN_001A2A80 NONMATCHING
void* func_001a2a80(KwlnTask* task)
{
    KWindowManagerWork* manager;
    KWindowEntry* entry;
    RwRect rect;
    RwRGBA colorA;
    RwRGBA colorB;
    u16 input;

    manager = KWindow_GetManager(task);
    if (manager == NULL)
    {
        return KWLNTASK_STOP;
    }
    rect.x = (s16)manager->x;
    rect.y = (s16)manager->y;
    rect.w = (s16)manager->width;
    rect.h = (s16)manager->height;

    switch (manager->state)
    {
        case 0:
            if (manager->request == 1)
            {
                manager->state++;
            }
            break;

        case 1:
            colorA = *(RwRGBA*)&gp0xffff9460;
            colorB = *(RwRGBA*)&gp0xffff9464;
            if (manager->mode == 1)
            {
                colorA = *(RwRGBA*)&gp0xffff9468;
                colorB = *(RwRGBA*)&gp0xffff946c;
            }
            else if (manager->mode == 2)
            {
                colorA = *(RwRGBA*)&gp0xffff9470;
                colorB = *(RwRGBA*)&gp0xffff9474;
            }
            else if (manager->mode == 3)
            {
                colorA = *(RwRGBA*)&gp0xffff9478;
                colorB = *(RwRGBA*)&gp0xffff947c;
            }
            manager->windowTask =
                func_001a2200(task, &rect, &colorA, &colorB);
            manager->renderData = func_001e78c0(1, 0x48);
            manager->colorData = func_00494be0();
            if (manager->renderData != NULL && manager->colorData != NULL)
            {
                KWindow_SetManagerRender(manager);
            }
            manager->state++;
            break;

        case 2:
            if (manager->windowTask == NULL ||
                func_001a2390(manager->windowTask) != 1)
            {
                if (manager->windowTask != NULL)
                {
                    func_001a23e0(manager->windowTask, &rect);
                }
                manager->state++;
            }
            break;

        case 3:
            if ((DAT_007e094c & 1) != 0)
            {
                uGpffffb450++;
            }
            else
            {
                uGpffffb450 = 0;
            }
            if ((DAT_007e094c & 2) != 0)
            {
                uGpffffb454++;
            }
            else
            {
                uGpffffb454 = 0;
            }
            if (manager->request != 1 || manager->entryCount == 0)
            {
                break;
            }

            entry = KWindow_GetCurrentEntry(manager);
            input = DAT_007e0952;
            if ((manager->flags & 1) == 0)
            {
                KWindow_DrawSelection(manager);
                if ((input & 0x1000) != 0)
                {
                    KWindow_MoveDown(manager);
                }
                else if ((input & 0x4000) != 0)
                {
                    KWindow_MoveUp(manager);
                }
                else if ((input & 0x2000) != 0)
                {
                    KWindow_ApplyValueDelta(entry, 1, 1.0f);
                }
                else if ((input & 0x8000) != 0)
                {
                    KWindow_ApplyValueDelta(entry, -1, -1.0f);
                }
                else if ((input & 8) != 0)
                {
                    KWindow_ApplyValueDelta(entry, 10, 10.0f);
                }
                else if ((input & 4) != 0)
                {
                    KWindow_ApplyValueDelta(entry, -10, -10.0f);
                }
                else if ((input & 2) != 0)
                {
                    KWindow_ApplyValueDelta(entry,
                                             uGpffffb450 > 0x95 ? 1000 : 100,
                                             uGpffffb450 > 0x95 ? 10.0f : 1.0f);
                }
                else if ((input & 1) != 0)
                {
                    KWindow_ApplyValueDelta(entry,
                                             uGpffffb454 > 0x95 ? -1000 : -100,
                                             uGpffffb454 > 0x95 ? -10.0f : -1.0f);
                }
                else if ((DAT_007e094e & 0x40) != 0)
                {
                    KWindow_InvokeEntryCallback(entry);
                }
            }
            else if ((input & 0x1000) != 0)
            {
                KWindow_MoveDown(manager);
            }
            else if ((input & 0x4000) != 0)
            {
                KWindow_MoveUp(manager);
            }
            func_001a2720(task);
            break;

        case 5:
            return KWLNTASK_STOP;
    }

    return KWLNTASK_CONTINUE;
}
 
// FUN_001A3A60
void func_001a3a60(KwlnTask* task)
{
    KWindowManagerWork* manager;

    manager = (KWindowManagerWork*)task->workData;
    func_001a44a0(task);
    if (manager->colorData != NULL)
    {
        func_00494cc0(manager->colorData);
    }
    if (manager->renderData != NULL)
    {
        func_001e7a60(manager->renderData);
    }
    (*(void (**)(void*))D_0096017c_abs)(task->workData);
}

// FUN_001A3AE0
KwlnTask* func_001a3ae0(KwlnTask* parent, u32 width, u32 height, u32 unused)
{
    (void)unused;
    return func_001a3b10(parent, width, height, 0);
}

// FUN_001A3B10
KwlnTask* func_001a3b10(KwlnTask* parent, u32 width, u32 height, u32 mode)
{
    KWindowManagerWork* manager;
    KwlnTask* task;

    manager = (KWindowManagerWork*)RwCalloc(1, sizeof(KWindowManagerWork),
                                             rwMEMHINTDUR_GLOBAL);
    if (manager == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreateWithAutoPriority(parent,
                                          0x106f,
                                          D_00678AF8,
                                          func_001a2a80,
                                          func_001a3a60,
                                          manager);
    manager->x = (s32)width;
    manager->y = (s32)height;
    manager->width = 0x80;
    manager->height = 0x80;
    manager->visibleRows = 10;
    manager->mode = (s32)mode;
    return task;
}

// FUN_001A3BE0
void func_001a3be0(KwlnTask* task, u32 flags)
{
    ((KWindowManagerWork*)task->workData)->flags = flags;
}

// FUN_001A3BF0
void func_001a3bf0(KwlnTask* task, u32 request)
{
    KWindowManagerWork* manager;

    manager = (KWindowManagerWork*)task->workData;
    manager->request = request;
    if (manager->windowTask != NULL)
    {
        func_001a23d0(manager->windowTask, request);
    }
}

// FUN_001A3C30 NONMATCHING
void func_001a3c30(KwlnTask* task)
{
    KWindowManagerWork* manager;
    KWindowEntry* entry;
    s32 maxWidth;
    s32 width;
    s32 height;
    s32 lineCount;
    RwRect rect;

    manager = KWindow_GetManager(task);
    if (manager == NULL)
    {
        return;
    }

    maxWidth = 0;
    entry = manager->entries;
    while (entry != NULL)
    {
        width = strlen(entry->name);
        switch (entry->type)
        {
            case 4:
                width += 8;
                break;
            case 3:
                width += (entry->flags == 0) ? 9 : 11;
                break;
            case 2:
                width += strlen(sKWindowType2Label) + 1;
                break;
            case 1:
                width += strlen(entry->text) + 1;
                break;
        }
        if (width > maxWidth)
        {
            maxWidth = width;
        }
        entry = entry->next;
    }

    manager->width = maxWidth * 12 + 4;
    lineCount = manager->entryCount * 12 + 4;
    height = manager->visibleRows * 12 + 4;
    if (lineCount < height)
    {
        height = lineCount;
    }
    manager->height = height;
    if (manager->windowTask != NULL)
    {
        rect.x = manager->x;
        rect.y = manager->y;
        rect.w = manager->width;
        rect.h = manager->height;
        func_001a23e0(manager->windowTask, &rect);
    }
}

// FUN_001A3DC0 NONMATCHING
void func_001a3dc0(KwlnTask* task, const KWindowEntryDescriptor* descriptors,
                   u32 count)
{
    u32 i;
    u32 id;
    const KWindowEntryDescriptor* descriptor;

    descriptor = descriptors;
    for (i = 0; i < count; i++)
    {
        id = func_001a3f20(task, descriptor->name);
        switch (descriptor->type)
        {
            case 4:
                func_001a4260(task, id, descriptor->value0,
                              descriptor->value1, descriptor->value2);
                break;
            case 3:
                func_001a4110(task, id, descriptor->value0,
                              descriptor->value1, descriptor->value2,
                              descriptor->value3);
                break;
            case 2:
                func_001a41f0(task, id, descriptor->value0);
                break;
            case 1:
                func_001a4090(task, id, descriptor->text);
                break;
        }
        if (descriptor->callback != NULL)
        {
            func_001a4050(task, id, descriptor->callback);
        }
        descriptor++;
    }
}

// FUN_001A3F20 NONMATCHING
u32 func_001a3f20(KwlnTask* task, const char* name)
{
    KWindowManagerWork* manager;
    KWindowEntry* entry;
    KWindowEntry* tail;

    manager = KWindow_GetManager(task);
    entry = (KWindowEntry*)RwCalloc(1, sizeof(KWindowEntry),
                                    rwMEMHINTDUR_GLOBAL);
    if (manager == NULL || entry == NULL)
    {
        if (entry == NULL)
        {
            func_0019d3f0(D_00678B08, 0x31b);
        }
        return 0;
    }

    func_00524270(entry->name, name);
    entry->id = manager->nextId++;
    if (manager->entries == NULL)
    {
        manager->entries = entry;
    }
    else
    {
        tail = manager->entries;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = entry;
        entry->previous = tail;
    }
    manager->entryCount++;
    func_001a3c30(task);
    return (u32)entry->id;
}
// FUN_001A4010
char* func_001a4010(KwlnTask* task, s32 id)
{
    KWindowEntry* entry;

    entry = func_001a4330(task, id);
    if (entry != NULL)
    {
        goto found;
    }
    return NULL;
found:
    return entry->name;
}

// FUN_001A4050
void func_001a4050(KwlnTask* task, u32 id, KWindowEntryCallback callback)
{
    KWindowEntry* entry;

    entry = (KWindowEntry*)func_001a4330(task, id);
    if (entry != NULL)
    {
        entry->callback = callback;
    }
}

// FUN_001A4090
void func_001a4090(KwlnTask* task, u32 id, const char* text)
{
    KWindowEntry* entry;

    entry = (KWindowEntry*)func_001a4330(task, id);
    if (entry != NULL && entry->type == 0)
    {
        entry->type = 1;
        if (text != NULL)
        {
            func_00524270(entry->text, text);
        }
        func_001a3c30(task);
    }
}

// FUN_001A4110
void func_001a4110(KwlnTask* task, u32 id, s32 value, s32 minValue,
                   s32 maxValue, s32 flags)
{
    KWindowEntry* entry;

    entry = (KWindowEntry*)func_001a4330(task, id);
    if (entry != NULL && entry->type == 0)
    {
        entry->type = 3;
        entry->intValue = value;
        entry->minValue = minValue;
        entry->maxValue = maxValue;
        entry->flags = flags;
        func_001a3c30(task);
    }
}

// FUN_001A41B0
s32* func_001a41b0(KwlnTask* task, u32 id)
{
    KWindowEntry* entry;

    entry = (KWindowEntry*)func_001a4330(task, id);
    if (entry != NULL)
    {
        goto found;
    }
    return NULL;
found:
    return &entry->intValue;
}

// FUN_001A41F0
void func_001a41f0(KwlnTask* task, u32 id, s32 value)
{
    KWindowEntry* entry;

    entry = (KWindowEntry*)func_001a4330(task, id);
    if (entry != NULL && entry->type == 0)
    {
        entry->type = 2;
        entry->intValue = value;
        entry->minValue = 0;
        entry->maxValue = 1;
        func_001a3c30(task);
    }
}

// FUN_001A4260
void func_001a4260(KwlnTask* task, u32 id, s32 value, s32 minValue,
                   s32 maxValue)
{
    KWindowEntry* entry;

    entry = (KWindowEntry*)func_001a4330(task, id);
    if (entry != NULL && entry->type == 0)
    {
        entry->type = 4;
        entry->floatValue = (f32)value;
        entry->minValue = minValue;
        entry->maxValue = maxValue;
        func_001a3c30(task);
    }
}

// FUN_001A42F0
f32* func_001a42f0(KwlnTask* task, u32 id)
{
    KWindowEntry* entry;

    entry = (KWindowEntry*)func_001a4330(task, id);
    if (entry != NULL)
    {
        goto found;
    }
    return NULL;
found:
    return &entry->floatValue;
}

// FUN_001A4330 NONMATCHING
KWindowEntry* func_001a4330(KwlnTask* task, s32 id)
{
    KWindowManagerWork* manager;
    KWindowEntry* entry;

    manager = KWindow_GetManager(task);
    if (manager == NULL || id == -1)
    {
        return NULL;
    }

    entry = manager->entries;
    while (entry != NULL)
    {
        if (entry->id == id)
        {
            return entry;
        }
        entry = entry->next;
    }
    return NULL;
}

// FUN_001A4380 NONMATCHING
void func_001a4380(KwlnTask* task, s32 id)
{
    KWindowManagerWork* manager;
    KWindowEntry* entry;
    s32 oldCount;
    manager = KWindow_GetManager(task);
    entry = func_001a4330(task, id);
    if (manager == NULL || entry == NULL)
    {
        return;
    }

    if (entry->previous != NULL)
    {
        entry->previous->next = entry->next;
    }
    else
    {
        manager->entries = entry->next;
    }
    if (entry->next != NULL)
    {
        entry->next->previous = entry->previous;
    }
    if (D_0096017c != NULL)
    {
        D_0096017c(entry);
    }
    oldCount = manager->entryCount;
    manager->entryCount = oldCount - 1;
    if (manager->entryCount == 0)
    {
        manager->entries = NULL;
        manager->firstVisible = 0;
        manager->cursor = 0;
    }
    else if (manager->entryCount < manager->visibleRows &&
             manager->entryCount <= manager->firstVisible + manager->cursor)
    {
        manager->firstVisible = oldCount - 2;
        manager->cursor = 0;
    }
    func_001a3c30(task);
}

// FUN_001A44A0
void func_001a44a0(KwlnTask* task)
{
    KWindowManagerWork* manager;
    KWindowEntry* entry;
    KWindowEntry* next;

    manager = (KWindowManagerWork*)task->workData;
    entry = manager->entries;
    while (entry != NULL)
    {
        next = entry->next;
        (*(void (**)(void*))D_0096017c_abs)(entry);
        entry = next;
    }
    manager->entryCount = 0;
    manager->firstVisible = 0;
    manager->cursor = 0;
}

// FUN_001A4510
s32 func_001a4510(KwlnTask* task)
{
    KWindowManagerWork* manager;
    KWindowEntry* entry;
    s32 index;
    s32 i;
    s32 cursor;
    s32 firstVisible;

    manager = (KWindowManagerWork*)task->workData;
    entry = manager->entries;
    cursor = *(volatile s32*)&manager->cursor;
    firstVisible = *(volatile s32*)&manager->firstVisible;
    index = firstVisible + cursor;
    if (index >= manager->entryCount)
    {
        return -1;
    }
    for (i = 0; i < index; i++)
    {
        entry = entry->next;
    }
    return entry->id;
}

