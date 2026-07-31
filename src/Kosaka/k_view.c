#include "Kosaka/k_view.h"
#include "Kernel/Kwln/kwln.h"
#include "libm.h"




// FUN_001a4580
void K_View_SetFov(RwCamera* camera, f32 fov)
{
    RwV2d viewWindow;

    viewWindow.y = tanf(DEG_TO_RAD(fov) / 2.0f);
    viewWindow.x = gAspectRatio * viewWindow.y;

    RwCameraSetViewWindow(camera, &viewWindow);
}

// FUN_001a4600
f32 K_View_GetFov(RwCamera* camera)
{
    f32 x;
    RwV2d* viewWindow;

    viewWindow = &camera->viewWindow;

    // Retained unused retail call; removing it changes the matched instruction sequence.
    atanf(viewWindow->x);
    x = atanf(viewWindow->y) * 2.0f;

    return RAD_TO_DEG(x);
}

#include "Kosaka/k_window.h"
#include "rw/rwcore.h"
#include "h_dbprt.h"
#include "Kosaka/k_assert.h"
#pragma alias rwGlobals_abs rwGlobals
extern u8 rwGlobals_abs[];

#include "Kernel/Kwln/kwlnTask.h"
extern u32 D_00960184[];
extern void (*D_0096017c)(void* memory);
#pragma alias D_00960090_abs D_00960090
extern u8 D_00960090_abs[];
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
extern u8 gp0xffff9484;
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
    u8 unknown00[0x30];
    RwRGBA* tileColors;
    u8 unknown34[0x28];
    KWindowQuadStore* quadStore;
} KWindowRenderLayout;

typedef struct KWindowRenderData
{
    u8 unknown00[0x18];
    KWindowRenderLayout* layout;
} KWindowRenderData;


 





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
#pragma alias H_Dbprt_FmtCol3D_f32 H_Dbprt_FmtCol3D
extern void H_Dbprt_FmtCol3D_f32(RwV2d pos, RwRGBA color, const char* fmt, f32 value);
extern s32 strlen(const char* text);
extern void func_00524270(void* destination, const void* source);
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

static inline KWindowManagerWork* KWindow_GetManager(KwlnTask* task)
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

static inline void KWindow_InvokeEntryCallback(KWindowEntry* entry)
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

static inline void KWindow_ApplyValueDelta(KWindowEntry* entry, s32 delta,
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

static inline void KWindow_MoveDown(KWindowManagerWork* manager)
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

static inline void KWindow_MoveUp(KWindowManagerWork* manager)
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

static inline void KWindow_SetManagerRender(KWindowManagerWork* manager)
{
    KWindowRenderData* renderData;
    KWindowRenderLayout* layout;
    KWindowQuad* quad;
    RwRGBA* colorData;
    RwRGBA* tile;
    s32 i;

    colorData = (RwRGBA*)((u8*)manager->colorData + 4);
    *(u8*)&colorData->r = *(u8*)((u8*)&uGpffff94c4 + 0);
    *(u8*)&colorData->g = *(u8*)((u8*)&uGpffff94c4 + 1);
    *(u8*)&colorData->b = *(u8*)((u8*)&uGpffff94c4 + 2);
    *(u8*)&colorData->a = *(u8*)((u8*)&uGpffff94c4 + 3);
    func_001e7aa0(manager->renderData, 0, manager->colorData);

    renderData = (KWindowRenderData*)manager->renderData;
    layout = renderData->layout;
    tile = layout->tileColors;
    for (i = 0; i < 4; i++)
    {
        tile[i] = *(RwRGBA*)&gp0xffff9460;
    }
    quad = layout->quadStore->quad;
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
}

static inline void KWindow_DrawSelection(KWindowManagerWork* manager)
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


 







// FUN_001A3F20
u32 func_001a3f20(KwlnTask* task, const char* name)
{
    KWindowManagerWork* manager;
    KWindowEntry* entry;
    KWindowEntry** link;

    manager = KWindow_GetManager(task);
    entry = (KWindowEntry*)RwCalloc(1, sizeof(KWindowEntry),
                                    rwMEMHINTDUR_GLOBAL);
    if (entry == NULL)
    {
        func_0019d3f0(D_00678B08, 0x31b);
    }

    func_00524270(entry->name, name);
    entry->type = 0;
    entry->id = manager->nextId;
    manager->nextId++;
    link = &manager->entries;
    while (*link != NULL)
    {
        entry->previous = *link;
        link = &(*link)->next;
    }
    *link = entry;
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

// FUN_001A4330
KWindowEntry* func_001a4330(KwlnTask* task, s32 id)
{
    KWindowEntry* entry;

    entry = KWindow_GetManager(task)->entries;
    if (id == -1)
    {
        return NULL;
    }
    while (entry->id != id)
    {
        entry = entry->next;
    }
    return entry;
}

// FUN_001A4380
void func_001a4380(KwlnTask* task, s32 id)
{
    KWindowManagerWork* manager;
    KWindowEntry* entry;
    manager = KWindow_GetManager(task);
    entry = manager->entries;
    if (id == -1)
    {
        entry = NULL;
        goto check_entry;
    }
    while (entry->id != id)
    {
        entry = entry->next;
    }
check_entry:
    if (entry == NULL)
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
    (*(void (**)(void*))D_0096017c_abs)(entry);
    manager->entryCount--;
    if (manager->entryCount == 0)
    {
        manager->entries = NULL;
        manager->firstVisible = 0;
        manager->cursor = 0;
    }
    else if (manager->entryCount < manager->visibleRows)
    {
        if (manager->firstVisible + manager->cursor >=
            manager->entryCount)
        {
            manager->firstVisible = manager->entryCount - 1;
            manager->cursor = 0;
        }
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
    cursor = *(volatile /* Removing this function's qualifier batch loses func_001a4510 (MATCH nd0 -> MISMATCH nd3, size 100 -> 100) - measured W170. */ s32*)&manager->cursor;
    firstVisible = *(volatile /* Removing this function's qualifier batch loses func_001a4510 (MATCH nd0 -> MISMATCH nd3, size 100 -> 100) - measured W170. */ s32*)&manager->firstVisible;
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
