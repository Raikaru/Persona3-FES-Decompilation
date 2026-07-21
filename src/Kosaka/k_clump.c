#include "Kosaka/k_clump.h"
#include "Graphics/Model/mdlManager.h"
#include "Graphics/primitive.h"
#include "Kernel/Kwln/kwln.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/Field/k_dungeon.h"
#include "Kosaka/Field/k_field.h"
#include "Main/g_data.h"
#include "Scene/mt_scene.h"
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

/* The retail code uses these engine entry points through the split executable. */
extern void* func_004916d0(void* object, KClumpCallback callback, void* data);
extern void* func_004932c0(void* object, KClumpCallback callback, void* data);
extern void* func_004cb6e0(void* object, KClumpCallback callback, void* data);
extern void* func_0048ee30(void* object, s32 index);
extern s32 func_0048ede0(void* object);
extern s32 func_0048ef30(void* object);
extern s32 func_0048a2c0(void* object);
extern s32 func_0048a480(void* object);
extern void func_0048a3f0(void* object);
extern void func_0048a2a0(void* object, void* data);
extern void func_00466640(void* data);
extern void func_001b5a30(void* material);
extern RwSphere* func_004912b0(void* object);
extern RwMatrix* func_004cb2f0(void* frame);
extern void* func_0034fcd0(void* data);
extern void* func_0034fd10(void* data);
extern void* func_0034fd30(void* data);
extern void* func_0034fd50(void* data);
extern void* func_0034fd70(void* data, s16 value);
extern void* func_0034fcf0(void* data);
extern void* func_0034fdf0(void* data, void* value);
extern void* func_0034fe80(void* data, void* value);
extern void* func_001021c0(void* path, u8* mode);
extern u32 func_001c7130(f32 value, u32 state);
extern void FUN_001099d0(u32 value, ...);
extern void FUN_00108fd0(u32 value, ...);
extern u32 FUN_0016ef30(void);
extern u32 FUN_0016f190(u32 flag);
extern u32 FUN_0017e480(u32 a, u32 b, u32 c, u32 d);
extern void K_Assert(const char* message, s32 line);
extern void (*D_00960090)(u32 state, ...);
extern u32 D_007CC1E4;
extern u32 D_007CC1F4;
extern u32 D_007CC1F8;
extern u32 D_007CC1C0;
extern void (*jtbl_0096017C)(void* memory);
extern void* D_007D2D60;
#pragma alias D_00960090_abs D_00960090
extern u8 D_00960090_abs[];
#pragma alias D_007D2D60_abs D_007D2D60
extern u8 D_007D2D60_abs[];
extern u32 D_00960184[];
extern const char D_00678BD8[];
extern const char D_00678BE8[];
extern const char D_00678C88[];
extern const char D_00678CA0[];
extern const char D_00678CB8[];

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

static void* kclump_alloc(u32 count, u32 size, u32 flags)
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

    sphere = func_004912b0(item->object);
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
        D_00960090(0xe);
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

static void* kclump_alpha_callback(void* material, void* data)
{
    if (*(u8*)((u8*)material + 7) == 0xff)
    {
        *(u32*)data = 1;
    }
    return material;
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

// FUN_001a6400
s32 K_Clump_MatUsrDataGetInt(const RpMaterial* material, const char* name)
{
    s32 i;
    s32 value;
    RpUserDataArray* userData;

    value = 0;
    for (i = 0; i < RpMaterialGetUserDataArrayCount(material); i++)
    {
        userData = RpMaterialGetUserDataArray(material, i);
        if (strcmp(RpUserDataArrayGetName(userData), name) == 0 &&
            RpUserDataArrayGetFormat(userData) == rpINTUSERDATA)
        {
            value = RpUserDataArrayGetInt(userData, 0);
            break;
        }
    }
    return value;
}

// FUN_001a64f0 NONMATCHING
u32 K_Clump_MatUsrDataHasData(const RpMaterial* material, const char* name)
{
    s32 i;
    RpUserDataArray* userData;

    for (i = 0; i < RpMaterialGetUserDataArrayCount(material); i++)
    {
        userData = RpMaterialGetUserDataArray(material, i);
        /* The retail function performs the accessor twice. */
        RpUserDataArrayGetName(userData);
        if (strcmp(RpUserDataArrayGetName(userData), name) == 0)
        {
            return true;
        }
    }
    return false;
}

// FUN_001a65c0 NONMATCHING
void* func_001a65c0(void* geometry, const char** name)
{
    s32 materialIndex;
    s32 resourceIndex;
    void* resourceList;
    RpUserDataArray* userData;

    resourceList = *(void**)((u8*)geometry + 0x18);
    for (resourceIndex = 0; resourceIndex < (s32)kclump_word(resourceList, 0x24); resourceIndex++)
    {
        void* material = *(void**)((u8*)kclump_word(resourceList, 0x20) + resourceIndex * 4);
        for (materialIndex = 0; materialIndex < RpMaterialGetUserDataArrayCount((RpMaterial*)material); materialIndex++)
        {
            userData = RpMaterialGetUserDataArray((RpMaterial*)material, materialIndex);
            if (strcmp(RpUserDataArrayGetName(userData), name[1]) == 0)
            {
                *(u32*)name = 1;
                return NULL;
            }
        }
    }
    return geometry;
}

// FUN_001a66f0
u32 func_001a66f0(void* clump, const char* name)
{
    struct
    {
        u32 found;
        char copiedName[72];
    } context;

    context.found = 0;
    strcpy(context.copiedName, name);
    func_004916d0(clump, (KClumpCallback)func_001a65c0, &context);
    return context.found;
}

// FUN_001a6740 NONMATCHING
u32 func_001a6740(void* geometry, const char* name)
{
    s32 resourceIndex;
    s32 materialIndex;
    void* resourceList;
    RpUserDataArray* userData;

    resourceList = *(void**)((u8*)geometry + 0x10);
    for (resourceIndex = 0; resourceIndex < (s32)kclump_word(geometry, 0x14); resourceIndex++)
    {
        void* material = *(void**)((u8*)resourceList + resourceIndex * 4);
        for (materialIndex = 0; materialIndex < RpMaterialGetUserDataArrayCount((RpMaterial*)material); materialIndex++)
        {
            userData = RpMaterialGetUserDataArray((RpMaterial*)material, materialIndex);
            if (strcmp(RpUserDataArrayGetName(userData), name) == 0)
            {
                return true;
            }
        }
    }
    return false;
}

// FUN_001a6860
void* func_001a6860(void* object, u32* context)
{
    s32 resourceIndex;
    s32 materialIndex;
    s32 elementIndex;
    void* material;
    RpUserDataArray* userData;

    for (resourceIndex = 0; resourceIndex < func_0048ede0(object); resourceIndex++)
    {
        material = func_0048ee30(object, resourceIndex);
        if (strcmp(RpUserDataArrayGetName((RpUserDataArray*)material), (const char*)context) == 0)
        {
            for (elementIndex = 0; elementIndex < func_0048ef30(material); elementIndex++)
            {
                userData = (RpUserDataArray*)material;
                if (RpUserDataArrayGetFormat(userData) == rpINTUSERDATA &&
                    RpUserDataArrayGetInt(userData, elementIndex) == (s32)context[0x11])
                {
                    context[0x10] = (u32)object;
                    return NULL;
                }
            }
        }
    }
    func_004cb6e0(object, (KClumpCallback)func_001a6860, context);
    return object;
}

// FUN_001a69a0 NONMATCHING
void* func_001a69a0(void* object, const char* name, s32 value)
{
    void* geometry;
    s32 elementIndex;
    s32 resourceIndex;
    void* material;
    struct
    {
        char nameCopy[0x40];
        void* result;
        s32 inputValue;
    } context;

    geometry = *(void**)((u8*)object + 4);
    strcpy(context.nameCopy, name);
    context.result = NULL;
    context.inputValue = value;
    for (resourceIndex = 0; resourceIndex < func_0048ede0(geometry); resourceIndex++)
    {
        material = func_0048ee30(geometry, resourceIndex);
        if (strcmp(RpUserDataArrayGetName((RpUserDataArray*)material), context.nameCopy) == 0)
        {
            for (elementIndex = 0; elementIndex < func_0048ef30(material); elementIndex++)
            {
                if (RpUserDataArrayGetFormat((RpUserDataArray*)material) == rpINTUSERDATA &&
                    RpUserDataArrayGetInt((RpUserDataArray*)material, elementIndex) == context.inputValue)
                {
                    context.result = geometry;
                    return context.result;
                }
            }
        }
    }
    func_004cb6e0(geometry, (KClumpCallback)func_001a6860, context.nameCopy);
    return context.result;
}

// FUN_001a6af0
void* func_001a6af0(void* object, u32* context)
{
    s32 resourceIndex;
    s32 elementIndex;
    void* material;

    for (resourceIndex = 0; resourceIndex < func_0048ede0(object); resourceIndex++)
    {
        material = func_0048ee30(object, resourceIndex);
        if (strcmp(RpUserDataArrayGetName((RpUserDataArray*)material), (const char*)context) == 0)
        {
            for (elementIndex = 0; elementIndex < func_0048ef30(material); elementIndex++)
            {
                if (RpUserDataArrayGetFormat((RpUserDataArray*)material) == rpINTUSERDATA)
                {
                    context[0x10]++;
                }
            }
        }
    }
    func_004cb6e0(object, (KClumpCallback)func_001a6af0, context);
    return object;
}

// FUN_001a6c00 NONMATCHING
s32 func_001a6c00(void* object, const char* name)
{
    u32 context[0x15];
    s32 resourceIndex;
    s32 elementIndex;
    void* material;

    memset(context, 0, sizeof(context));
    for (resourceIndex = 0; resourceIndex < func_0048ede0(*(void**)((u8*)object + 4)); resourceIndex++)
    {
        material = func_0048ee30(*(void**)((u8*)object + 4), resourceIndex);
        if (strcmp(RpUserDataArrayGetName((RpUserDataArray*)material), name) == 0)
        {
            for (elementIndex = 0; elementIndex < func_0048ef30(material); elementIndex++)
            {
                if (RpUserDataArrayGetFormat((RpUserDataArray*)material) == rpINTUSERDATA)
                {
                    context[0x24]++;
                }
            }
        }
    }
    func_004cb6e0(*(void**)((u8*)object + 4), (KClumpCallback)func_001a6af0, context);
    return (s32)context[0x24];
}

// FUN_001a6d20
void* func_001a6d20(void* object, u32* context)
{
    s32 resourceIndex;
    s32 elementIndex;
    void* material;

    if (context[0x12] == 1)
    {
        return NULL;
    }
    for (resourceIndex = 0; resourceIndex < func_0048ede0(object); resourceIndex++)
    {
        material = func_0048ee30(object, resourceIndex);
        if (strcmp(RpUserDataArrayGetName((RpUserDataArray*)material), (const char*)context) == 0)
        {
            for (elementIndex = 0; elementIndex < func_0048ef30(material); elementIndex++)
            {
                if (RpUserDataArrayGetFormat((RpUserDataArray*)material) == rpINTUSERDATA)
                {
                    if (context[0x10] == context[0x11])
                    {
                        context[0x13] = RpUserDataArrayGetInt((RpUserDataArray*)material, elementIndex);
                        context[0x14] = (u32)object;
                        context[0x12] = 1;
                        return NULL;
                    }
                    context[0x11]++;
                }
            }
        }
    }
    func_004cb6e0(object, (KClumpCallback)func_001a6d20, context);
    return object;
}

// FUN_001a6e90 NONMATCHING
void func_001a6e90(f32* result, void* object, const char* name, s32 index)
{
    struct
    {
        char nameCopy[0x40];
        s32 targetIndex;
        s32 currentIndex;
        s32 unused0;
        s32 resultValue;
        void* resultMaterial;
    } context;
    void* geometry;
    s32 resourceIndex;
    s32 elementIndex;
    void* material;

    geometry = *(void**)((u8*)object + 4);
    memset(&context, 0, 0x54);
    strcpy(context.nameCopy, name);
    context.targetIndex = index;
    for (resourceIndex = 0; resourceIndex < func_0048ede0(geometry); resourceIndex++)
    {
        material = func_0048ee30(geometry, resourceIndex);
        if (strcmp(RpUserDataArrayGetName((RpUserDataArray*)material), context.nameCopy) == 0)
        {
            for (elementIndex = 0; elementIndex < func_0048ef30(material); elementIndex++)
            {
                if (RpUserDataArrayGetFormat((RpUserDataArray*)material) == rpINTUSERDATA)
                {
                    if (context.targetIndex == context.currentIndex)
                    {
                        context.resultValue = RpUserDataArrayGetInt((RpUserDataArray*)material, elementIndex);
                        context.resultMaterial = material;
                        *(f32*)result = *(f32*)&context.resultValue;
                        *(f32*)((u8*)result + 4) = *(f32*)&context.resultMaterial;
                        return;
                    }
                    context.currentIndex++;
                }
            }
        }
    }
    func_004cb6e0(geometry, (KClumpCallback)func_001a6d20, &context);
    *(f32*)result = *(f32*)&context.resultValue;
    *(f32*)((u8*)result + 4) = *(f32*)&context.resultMaterial;
}

// FUN_001a7020
void* func_001a7020(void)
{
    return NULL;
}

// FUN_001a7030
s32 func_001a7030(void)
{
    kwlnTaskDestroyWithHierarchyByName(D_00678BD8);
    return -1;
}

// FUN_001a7060
void func_001a7060(void)
{
    kwlnTaskCreateWithAutoPriority(NULL, 10,
                                   D_00678BE8,
                                   (KwlnTaskUpdateFunc)func_001a7030,
                                   NULL, NULL);
}

// FUN_001a70a0 NONMATCHING
void* func_001a70a0(void* object, void* data)
{
    s32 state;

    if (func_0048a2c0((void*)kclump_word(object, 0x18)) == 0)
    {
        func_00466640(data);
    }
    else
    {
        state = func_0048a480(object);
        if (state != 0 && state != 3)
        {
            if (state == 2 || state != 1)
            {
                func_0048a3f0(object);
            }
        }
        func_0048a2a0(object, data);
    }
    return object;
}

// FUN_001a7170
void func_001a7170(void* object, void* data)
{
    func_004916d0(object, (KClumpCallback)func_001a70a0, data);
}

// FUN_001a71a0 NONMATCHING
void func_001a71a0(u32* state, u32 kind, void* object, u32 enabled, u32 flags)
{
    KClumpMaterialNode* node;

    node = (KClumpMaterialNode*)kclump_alloc(1, sizeof(KClumpMaterialNode), 0x40000);
    if (node == NULL)
    {
        return;
    }
    node->object = object;
    if (enabled == 1)
    {
        state[1]++;
        node->enabled = 1;
    }
    node->flags = flags;
    node->colorScale[0] = 1.0f;
    node->colorScale[1] = 1.0f;
    node->colorScale[2] = 1.0f;
    node->colorScale[3] = 1.0f;
    switch (kind)
    {
    case 0:
    case 1:
        node->kind = 1;
        node->next = *(KClumpMaterialNode**)&state[2];
        *(KClumpMaterialNode**)&state[2] = node;
        break;
    case 2:
        node->kind = 2;
        node->next = *(KClumpMaterialNode**)&state[5];
        *(KClumpMaterialNode**)&state[5] = node;
        break;
    case 3:
        node->kind = 3;
        node->next = *(KClumpMaterialNode**)&state[9];
        *(KClumpMaterialNode**)&state[9] = node;
        break;
    case 4:
        node->kind = 4;
        node->next = *(KClumpMaterialNode**)&state[10];
        *(KClumpMaterialNode**)&state[10] = node;
        break;
    case 5:
        node->kind = 5;
        node->next = *(KClumpMaterialNode**)&state[3];
        *(KClumpMaterialNode**)&state[3] = node;
        break;
    case 6:
        node->kind = 6;
        node->next = *(KClumpMaterialNode**)&state[4];
        *(KClumpMaterialNode**)&state[4] = node;
        break;
    case 7:
        node->kind = 7;
        node->next = *(KClumpMaterialNode**)&state[6];
        *(KClumpMaterialNode**)&state[6] = node;
        break;
    case 8:
        node->kind = 8;
        node->next = *(KClumpMaterialNode**)&state[7];
        *(KClumpMaterialNode**)&state[7] = node;
        break;
    case 9:
        node->kind = 9;
        node->next = *(KClumpMaterialNode**)&state[8];
        *(KClumpMaterialNode**)&state[8] = node;
        break;
    default:
        break;
    }
    state[0]++;
}

// FUN_001a7370 NONMATCHING
void* func_001a7370(void* material, u32* state)
{
    s32 candidate;
    s32 current;
    s32 selected;
    s32 value;

    value = K_Clump_MatUsrDataGetInt((RpMaterial*)material, (const char*)0x00678c28);
    if (K_Clump_MatUsrDataHasData((RpMaterial*)material, (const char*)0x00678c38))
    {
        if (value < 2)
        {
            value = 2;
        }
        state[2] = 1;
    }
    for (candidate = 0; candidate < 10 && state[0] != kclump_word((void*)0x00678c00, candidate * 4); candidate++)
    {
    }
    for (current = 0; current < 10 && value != kclump_word((void*)0x00678c00, current * 4); current++)
    {
    }
    if (candidate < current)
    {
        state[0] = kclump_word((void*)0x00678c00, current * 4);
    }
    selected = K_Clump_MatUsrDataHasData((RpMaterial*)material, (const char*)0x00678c48);
    if (selected == 1)
    {
        state[1] = 1;
    }
    return material;
}

// FUN_001a74e0 NONMATCHING
void* func_001a74e0(void* object, u32* state)
{
    u32 callbackState[3];
    void* resources;

    memset(callbackState, 0, sizeof(callbackState));
    resources = (void*)kclump_word(object, 0x18);
    if (resources != NULL)
    {
        func_004932c0(resources, (KClumpCallback)func_001a7370, callbackState);
        func_001a71a0(state, callbackState[0], object, callbackState[1], callbackState[2]);
    }
    return object;
}

// FUN_001a7570 NONMATCHING
void* func_001a7570(void* clump)
{
    u32* state;

    state = (u32*)kclump_alloc(1, 0x2c, 0x40000);
    if (state == NULL)
    {
        return NULL;
    }
    func_004916d0(clump, (KClumpCallback)func_001a74e0, state);
    if (state[1] == 0 && state[0] == 0 && state[3] == 0 && state[4] == 0 && state[5] == 0 &&
        state[6] == 0 && state[7] == 0 && state[8] == 0 && state[9] == 0 && state[10] == 0)
    {
        func_001a7710(state);
        state = NULL;
    }
    return state;
}

// FUN_001a7660
u32 func_001a7660(const u32* state)
{
    if (state == NULL)
    {
        return 0;
    }
    if (state[0] == 0 ||
        (state[4] == 0 && state[3] == 0 && state[5] == 0 &&
         state[9] == 0 && state[10] == 0))
    {
        return 0;
    }
    return 1;
}

// FUN_001a76e0
u32 func_001a76e0(const u32* state)
{
    if (state == NULL)
    {
        return 0;
    }
    return state[8] != 0;
}

// FUN_001a7710 NONMATCHING
void func_001a7710(u32* state)
{
    static const u32 listOffsets[] = {8, 0x18, 0x1c, 0x0c, 0x10, 0x20, 0x14, 0x24, 0x28};
    s32 i;
    KClumpMaterialNode* node;
    KClumpMaterialNode* next;

    if (state == NULL)
    {
        return;
    }
    for (i = 0; i < (s32)(sizeof(listOffsets) / sizeof(listOffsets[0])); i++)
    {
        node = *(KClumpMaterialNode**)((u8*)state + listOffsets[i]);
        while (node != NULL)
        {
            next = node->next;
            kclump_free(node);
            node = next;
        }
        *(KClumpMaterialNode**)((u8*)state + listOffsets[i]) = NULL;
    }
    kclump_free(state);
}

// FUN_001a7910 NONMATCHING
void func_001a7910(void* object, f32* scale)
{
    void* resources;
    s32 i;
    u32 color;
    u32 red;
    u32 green;
    u32 blue;
    u32 alpha;
    void* material;

    resources = (void*)kclump_word(object, 0x18);
    for (i = 0; i < (s32)kclump_word(resources, 0x24); i++)
    {
        material = *(void**)((u8*)kclump_word(resources, 0x20) + i * 4);
        func_001b5a30(material);
        color = (u32)K_Clump_MatUsrDataGetInt((RpMaterial*)material, (const char*)0x00678c60);
        red = kclump_scale_color((color >> 16) & 0xff, scale[0]);
        green = kclump_scale_color((color >> 8) & 0xff, scale[1]);
        blue = kclump_scale_color(color & 0xff, scale[2]);
        alpha = kclump_scale_color((color >> 24) & 0xff, scale[3]);
        *(u8*)((u8*)material + 4) = (u8)red;
        *(u8*)((u8*)material + 5) = (u8)green;
        *(u8*)((u8*)material + 6) = (u8)blue;
        *(u8*)((u8*)material + 7) = (u8)alpha;
    }
}

// FUN_001a7b50 NONMATCHING
void func_001a7b50(void* state, u32 mode)
{
    KClumpMaterialNode* item;
    RwSphere* sphere;
    void* resources;
    u32 found;

    if (state == NULL)
    {
        return;
    }
    if (mode == 1)
    {
        void (**renderState)(u32, ...);

        renderState = (void (**)(u32, ...))D_00960090_abs;
        (*renderState)(6);
        (*renderState)(8, 1);
    }
    RpSkyRenderStateSet(2, (void*)0x44);
    RpSkyRenderStateSet(3, (void*)0x717fb);
    item = *(KClumpMaterialNode**)((u8*)state + 8);
    while (item != NULL)
    {
        sphere = func_004912b0(item->object);
        if (RwCameraFrustumTestSphere((RwCamera*)*(void**)(u8*)0x00960070, sphere) != rwSPHEREOUTSIDE)
        {
            if (item->enabled == 1)
            {
                (*(void (**)(u32, ...))(u8*)0x00960090)(0xe, 0);
            }
            if ((&D_007CC1C0)[9] == 1)
            {
                (*(void (**)(void))((u8*)item->object + 0x48))();
            }
            if (item->enabled == 1)
            {
                (*(void (**)(u32, ...))(u8*)0x00960090)(0xe);
            }
        }
        item = item->next;
    }
    item = *(KClumpMaterialNode**)((u8*)state + 0x14);
    while (item != NULL)
    {
        found = 0;
        resources = *(void**)((u8*)item->object + 0x18);
        if (resources != NULL)
        {
            func_001a7910(item->object, (f32*)((u8*)item + 0xc));
            func_004932c0(resources, (KClumpCallback)kclump_alpha_callback, &found);
            if (item->colorScale[3] >= 1.0f && found == 1)
            {
                sphere = func_004912b0(item->object);
                if (RwCameraFrustumTestSphere((RwCamera*)*(void**)(u8*)0x00960070, sphere) != rwSPHEREOUTSIDE)
                {
                    if (item->enabled == 1)
                    {
                        (*(void (**)(u32, ...))(u8*)0x00960090)(0xe, 0);
                    }
                    if ((&D_007CC1C0)[9] == 1)
                    {
                        (*(void (**)(void))((u8*)item->object + 0x48))();
                    }
                    if (item->enabled == 1)
                    {
                        (*(void (**)(u32, ...))(u8*)0x00960090)(0xe);
                    }
                }
            }
        }
        item = item->next;
    }
    if (mode == 1)
    {
        void (**renderState)(u32, ...);

        renderState = (void (**)(u32, ...))D_00960090_abs;
        (*renderState)(6);
        (*renderState)(8, 0);
    }
    RpSkyRenderStateSet(2, (void*)0x44);
    RpSkyRenderStateSet(3, (void*)0x717fb);
    item = *(KClumpMaterialNode**)((u8*)state + 0x18);
    while (item != NULL)
    {
        sphere = func_004912b0(item->object);
        if (RwCameraFrustumTestSphere((RwCamera*)*(void**)(u8*)0x00960070, sphere) != rwSPHEREOUTSIDE)
        {
            if (item->enabled == 1)
            {
                (*(void (**)(u32, ...))(u8*)0x00960090)(0xe, 0);
            }
            if ((&D_007CC1C0)[13] == 1)
            {
                (*(void (**)(void))((u8*)item->object + 0x48))();
            }
            if (item->enabled == 1)
            {
                (*(void (**)(u32, ...))(u8*)0x00960090)(0xe);
            }
        }
        item = item->next;
    }
    if (mode == 1)
    {
        void (**renderState)(u32, ...);

        renderState = (void (**)(u32, ...))D_00960090_abs;
        (*renderState)(6);
        (*renderState)(8, 1);
    }
    RpSkyRenderStateSet(2, (void*)0x44);
    RpSkyRenderStateSet(3, (void*)0x715fb);
    item = *(KClumpMaterialNode**)((u8*)state + 0x1c);
    while (item != NULL)
    {
        sphere = func_004912b0(item->object);
        if (RwCameraFrustumTestSphere((RwCamera*)*(void**)(u8*)0x00960070, sphere) != rwSPHEREOUTSIDE)
        {
            if (item->enabled == 1)
            {
                (*(void (**)(u32, ...))(u8*)0x00960090)(0xe, 0);
            }
            if ((&D_007CC1C0)[14] == 1)
            {
                (*(void (**)(void))((u8*)item->object + 0x48))();
            }
            if (item->enabled == 1)
            {
                (*(void (**)(u32, ...))(u8*)0x00960090)(0xe);
            }
        }
        item = item->next;
    }
}

// FUN_001a7fc0 NONMATCHING
void func_001a7fc0(void* state, u32 mode)
{
    KClumpMaterialNode* item;
    u32 found;

    if (state == NULL)
    {
        return;
    }
    if (mode == 1)
    {
        D_00960090(6, 1);
        D_00960090(8, 0);
    }
    RpSkyRenderStateSet(2, (void*)0x44);
    RpSkyRenderStateSet(3, (void*)0x717fb);
    item = *(KClumpMaterialNode**)((u8*)state + 0x20);
    while (item != NULL)
    {
        found = 0;
        if (item->object != NULL)
        {
            func_004932c0((void*)kclump_word(item->object, 0x18), (KClumpCallback)kclump_alpha_callback, &found);
            if (found == 0)
            {
                /* Keep the retail callback ordering even when alpha is absent. */
                item = item->next;
                continue;
            }
            kclump_render_item(item, 0x007cc1fc);
        }
        item = item->next;
    }
}

// FUN_001a8140 NONMATCHING
void func_001a8140(void* state, u32 mode)
{
    KClumpMaterialNode* item;
    u32 found;

    if (state == NULL)
    {
        return;
    }
    if (mode == 1)
    {
        D_00960090(6);
        D_00960090(8, 1);
    }
    RpSkyRenderStateSet(2, (void*)0x44);
    RpSkyRenderStateSet(3, (void*)0x715fb);
    kclump_render_list((void*)((u8*)state + 0x0c), 0x007cc1e8);

    if (*(u32*)0x007ce158 == 1)
    {
        RpSkyRenderStateSet(2, (void*)0x44);
        RpSkyRenderStateSet(3, (void*)0x707fd);
    }
    else
    {
        RpSkyRenderStateSet(2, (void*)0x44);
        RpSkyRenderStateSet(3, (void*)0x735fb);
    }
    kclump_render_list((void*)((u8*)state + 0x10), 0x007cc1ec);

    if (mode == 1)
    {
        D_00960090(6);
        D_00960090(8, 0);
    }
    RpSkyRenderStateSet(2, (void*)0x42);
    RpSkyRenderStateSet(3, (void*)0x71801);
    item = *(KClumpMaterialNode**)((u8*)state + 0x14);
    while (item != NULL)
    {
        found = 0;
        if (item->object != NULL)
        {
            func_004932c0((void*)kclump_word(item->object, 0x18), (KClumpCallback)kclump_alpha_callback, &found);
            if ((item->flags == 0 || item->colorScale[0] == 1.0f) && found != 0)
            {
                kclump_render_item(item, 0x007cc1f0);
            }
        }
        item = item->next;
    }

    RpSkyRenderStateSet(2, (void*)0x48);
    RpSkyRenderStateSet(3, (void*)0x71801);
    item = *(KClumpMaterialNode**)((u8*)state + 0x28);
    while (item != NULL)
    {
        if (item->object != NULL)
        {
            if (item->flags != 1 || item->colorScale[0] >= 1.0f || item->colorScale[0] <= 0.0f)
            {
                kclump_render_item(item, 0x007cc204);
            }
            else if (*(u32*)0x007cc204 == 1)
            {
                func_001a8920((u32*)0x008668f0, (const u32*)item);
            }
        }
        item = item->next;
    }

    RpSkyRenderStateSet(2, (void*)0x48);
    RpSkyRenderStateSet(3, (void*)0x71801);
    item = *(KClumpMaterialNode**)((u8*)state + 0x24);
    while (item != NULL)
    {
        if (item->object != NULL)
        {
            if (item->flags != 1 || item->colorScale[0] >= 1.0f || item->colorScale[0] <= 0.0f)
            {
                kclump_render_item(item, 0x007cc200);
            }
            else if (*(u32*)0x007cc200 == 1)
            {
                func_001a8920((u32*)0x008668f0, (const u32*)item);
            }
        }
        item = item->next;
    }

    item = *(KClumpMaterialNode**)((u8*)state + 0x14);
    while (item != NULL)
    {
        if (item->flags == 1 && item->colorScale[0] < 1.0f && item->colorScale[0] > 0.0f &&
            *(u32*)0x007cc1f0 == 1)
        {
            func_001a8920((u32*)0x008668f0, (const u32*)item);
        }
        item = item->next;
    }
}

// FUN_001a8820 NONMATCHING
void* func_001a8820(void* item)
{
    if ((*(u8*)((u8*)item + 2) & 4) != 0 && kclump_word(item, 0x18) != 0)
    {
        RwSphere* sphere = func_004912b0(item);
        if (sphere != NULL && RwCameraFrustumTestSphere((RwCamera*)D_007D2D60, sphere) != rwSPHEREOUTSIDE)
        {
            kclump_call_resource(item);
            if (*(u32*)0x007ce154 == 1)
            {
                RwV3d line;
                RwV3d* position;
                position = (RwV3d*)((u8*)func_004912b0(item) + 0x0c);
                line.x = position->x;
                line.y = position->y;
                line.z = position->z;
                primSphereLine3D(position, *(f32*)0x007ce154, NULL, 0);
            }
        }
    }
    return item;
}

// FUN_001a88e0
void func_001a88e0(void* object)
{
    func_004916d0(object, (KClumpCallback)func_001a8820, NULL);
}

// FUN_001a8910
void func_001a8910(u32* count)
{
    *count = 0;
}

// FUN_001a8920 NONMATCHING
void func_001a8920(u32* entries, const u32* source)
{
    u32* destination;
    s32 i;

    if (entries[0] >= 0x80)
    {
        K_Assert((const char*)0x00678c78, 0x3eb);
    }
    destination = entries + entries[0] * 11 + 1;
    for (i = 0; i < 11; i++)
    {
        destination[i] = source[i];
    }
    entries[0]++;
}

// FUN_001a89c0 NONMATCHING
s32 func_001a89c0(const u32* left, const u32* right)
{
    RwCamera* camera;
    RwMatrix* cameraMatrix;
    RwMatrix* leftMatrix;
    RwMatrix* rightMatrix;
    RwV3d cameraPosition;
    RwV3d leftDelta;
    RwV3d rightDelta;
    f32 leftDistance;
    f32 rightDistance;

    camera = kwlnGetMainCamera();
    cameraMatrix = func_004cb2f0(*(void**)((u8*)camera + 4));
    cameraPosition = cameraMatrix->pos;
    leftMatrix = func_004cb2f0(*(void**)(*left + 4));
    rightMatrix = func_004cb2f0(*(void**)(*right + 4));
    leftDelta.x = leftMatrix->pos.x - cameraPosition.x;
    leftDelta.y = leftMatrix->pos.y - cameraPosition.y;
    leftDelta.z = leftMatrix->pos.z - cameraPosition.z;
    rightDelta.x = rightMatrix->pos.x - cameraPosition.x;
    rightDelta.y = rightMatrix->pos.y - cameraPosition.y;
    rightDelta.z = rightMatrix->pos.z - cameraPosition.z;
    leftDistance = RwV3dLength(&leftDelta);
    rightDistance = RwV3dLength(&rightDelta);
    return (s32)(leftDistance - rightDistance);
}

// FUN_001a8b10 NONMATCHING
void func_001a8b10(u32* entries)
{
    s32 i;
    KClumpMaterialNode* item;

    qsort(entries + 1, entries[0], 0x2c, (int (*)(const void*, const void*))func_001a89c0);
    for (i = (s32)entries[0] - 1; i >= 0; i--)
    {
        item = (KClumpMaterialNode*)(entries + i * 11 + 1);
        if (func_004912b0(item->object) != NULL &&
            RwCameraFrustumTestSphere((RwCamera*)D_007D2D60, func_004912b0(item->object)) != rwSPHEREOUTSIDE)
        {
            if (item->enabled == 1)
            {
                D_00960090(0xe, 0);
            }
            func_001a7910(item->object, (f32*)((u8*)item + 0x0c));
            if (item->colorScale[0] < 1.0f && item->colorScale[0] > 0.0f)
            {
                D_00960090(6, 1);
                D_00960090(8, 1);
                RpSkyRenderStateSet(2, (void*)0x44);
                RpSkyRenderStateSet(3, (void*)0x72001);
                if (item->kind == 2)
                {
                    kclump_call_resource(item->object);
                }
                D_00960090(6, 1);
                D_00960090(8, 0);
                if (item->kind == 3)
                {
                    RpSkyRenderStateSet(2, (void*)0x48);
                    RpSkyRenderStateSet(3, (void*)0x71801);
                }
                else if (item->kind == 4)
                {
                    RpSkyRenderStateSet(2, (void*)0x42);
                    RpSkyRenderStateSet(3, (void*)0x71801);
                }
                else if (item->kind == 2)
                {
                    RpSkyRenderStateSet(2, (void*)0x44);
                    RpSkyRenderStateSet(3, (void*)0x717fb);
                }
                kclump_call_resource(item->object);
            }
            if (item->enabled == 1)
            {
                D_00960090(0xe);
            }
        }
    }
}

// FUN_001a8db0 NONMATCHING
s32 func_001a8db0(KwlnTask* task)
{
    u32* work;
    s32 i;
    u8 mode;
    void* handle;

    work = (u32*)task->workData;
    if (work[0] == 3)
    {
        return -1;
    }
    if (work[0] == 2)
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
                    func_0034fd70((void*)work[5], (s16)work[7]);
                    work[6]++;
                }
                else
                {
                    work[4] = 0;
                }
            }
            for (i = 0; i < 8; i++)
            {
                if (work[9 + i] != 0)
                {
                    if (work[0x11 + i] < work[2])
                    {
                        func_0034fd30(NULL);
                        func_0034fd70((void*)work[9 + i], *(s16*)((u8*)work + 100 + i * 2));
                        work[0x11 + i]++;
                    }
                    else
                    {
                        func_0034fcf0(NULL);
                        work[9 + i] = 0;
                        work[8]--;
                    }
                }
            }
        }
    }
    else if (work[0] == 0)
    {
        if (work[3] == 0)
        {
            handle = (void*)work[1];
            if (handle == NULL || H_Cdvd_IsFileLoaded((HCdvd*)handle) == 0)
            {
                return 0;
            }
            if (handle != NULL)
            {
                work[5] = (u32)func_0034fcd0(*(void**)((u8*)handle + 0x110));
                H_Cdvd_Destroy((HCdvd*)handle);
                work[1] = 0;
            }
        }
        else
        {
            work[5] = (u32)func_0034fcd0(func_001021c0(work + 0x1d, &mode));
        }
        work[0]++;
    }
    return 0;
}

// FUN_001a8fe0 NONMATCHING
void func_001a8fe0(KwlnTask* task)
{
    u32* work;
    s32 i;

    work = (u32*)task->workData;
    for (i = 0; i < 8; i++)
    {
        if (work[9 + i] != 0)
        {
            func_0034fcf0((void*)work[9 + i]);
        }
    }
    if (work[5] != 0)
    {
        func_0034fcf0((void*)work[5]);
    }
    kclump_free(work);
}

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

// FUN_001a91b0 NONMATCHING
s32 func_001a91b0(KwlnTask* task, void* data)
{
    u32* work;
    s32 index;
    void* stream;

    work = (u32*)task->workData;
    index = -1;
    if (work[4] == 1)
    {
        for (index = 0; index < 8 && work[9 + index] != 0; index++)
        {
        }
        stream = func_0034fd50((void*)work[5]);
        work[9 + index] = (u32)stream;
        func_0034fdf0(stream, data);
        work[0x11 + index] = 0;
        *(u16*)((u8*)work + 100 + index * 2) = 2;
        work[8]++;
    }
    else
    {
        func_0034fd10((void*)work[5]);
        func_0034fdf0((void*)work[5], data);
        work[6] = 0;
        work[4] = 1;
        *(u16*)&work[7] = 2;
    }
    work[0] = 2;
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

// FUN_001a9500 NONMATCHING
s32 func_001a9500(KwlnTask* task)
{
    u32* work;
    s32 i;
    s32 fieldIndex;
    KwlnTask** fieldTasks;

    work = (u32*)task->workData;
    if (work[0] == 3)
    {
        return -1;
    }
    if (work[0] == 2)
    {
        if (work[2] < work[1])
        {
            work[2]++;
        }
        else
        {
            work[0] = 1;
        }
    }
    else
    {
        if (work[0] != 0 && work[0] != 1)
        {
            return 0;
        }
        if (work[0] == 0)
        {
            work[0] = 1;
        }
        if (work[3] > 0)
        {
            fieldTasks = (KwlnTask**)((u8*)K_Field_Get() + 0x11f4);
            fieldIndex = (s32)work[4];
            func_001a91b0(fieldTasks[fieldIndex], &work[0x0c]);
            if ((s32)work[0x24] >= 0)
            {
                func_0010a4e0(1, 8, (u16)work[0x24], (u16)work[0x2c]);
            }
            work[3]--;
            for (i = 1; i < 8; i++)
            {
                work[i + 3] = work[i + 4];
                work[i * 3 + 9] = work[i * 3 + 12];
                work[i * 3 + 10] = work[i * 3 + 13];
                work[i * 3 + 11] = work[i * 3 + 14];
                work[i + 0x23] = work[i + 0x24];
                work[i + 0x2b] = work[i + 0x2c];
            }
            work[2] = 0;
            work[0]++;
        }
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

// FUN_001a9760 NONMATCHING
void func_001a9760(KwlnTask* task, u32 value, const RwV3d* position, u32 sound, u32 flags)
{
    u32* work;
    u32 index;
    f32* dst;

    if (task == NULL)
    {
        return;
    }
    work = (u32*)task->workData;
    index = work[3];
    if (index >= 8)
    {
        K_Assert((const char*)0x007c8620, 0x260);
        return;
    }
    work[4 + index] = value;
    dst = (f32*)((u8*)work + 0x30 + index * 0x0c);
    dst[0] = position->x;
    dst[1] = position->y;
    dst[2] = position->z;
    work[0x24 + index] = sound;
    work[0x2c + index] = flags;
    work[3] = index + 1;
}

// FUN_001a9850 NONMATCHING
void func_001a9850(void)
{
    s32 floor;
    s32 major;
    s32 minor;
    u32 time;
    u32 scenario;
    u32 state;

    if (*(u32*)0x007ce204 == 1)
    {
        return;
    }
    floor = (s32)K_FldDungeon_GetCurrentFloor();
    if (floor > 0)
    {
        if (floor >= 2 && FUN_0016f380(1) > 0)
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
            else H_Snd_PlayBgm(0x47, 1);
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
        return;
    }

    major = gMtScene->fldMajorId;
    minor = gMtScene->fldMinorId;
    time = FUN_0016ef30();
    if (((major == 7 && minor == 6) || (major == 8 && minor == 1) || (major == 9 && minor == 1)) &&
        time == 8)
    {
        FUN_001099d0(0x47, 1);
        return;
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
    if (major == 0x1f || datGetFlag(0xeef) == 1)
    {
        FUN_001099d0(0x14);
        return;
    }
    if (major == 0x21) FUN_00108fd0(0x14);
    else if (major == 0x22) FUN_001099d0(0x16);
    else if (major == 0x23) FUN_001099d0(0x15);
    else if (major == 0x25) FUN_001099d0(0x47);
    else if (major == 0x0e && minor == 5) FUN_00108fd0(0x14);
    else if ((major == 8 || major == 5) && minor == 3) FUN_001099d0(0x36, 1);
    else if (major == 8 && minor == 9) FUN_00108fd0(0x14);
    else if (major == 7 && minor == 1 && (time < 2 || time > 6)) FUN_00108fd0(0x14);
    else if ((major == 8 || major == 9 || major == 10 || major == 0xc || (major == 7 && minor == 9)) &&
             (FUN_0017e480(4, 5, 0xc, 0x1f) == 1 || FUN_0017e480(3, 1, 3, 5) == 1))
    {
        FUN_001099d0(0x19, 1);
    }
    else if ((major == 8 || major == 9 || major == 10 || major == 0xc || (major == 7 && minor == 9)) &&
             FUN_0017e480(1, 1, 2, 0x1c) == 1)
    {
        FUN_001099d0(0x50);
    }
    else if (major == 5 && minor == 1) FUN_001099d0(0x19);
    else if (major == 0x0e) FUN_001099d0(0x20, 1);
    else if (major == 6)
    {
        if (FUN_0017e480(4, 5, 8, 0x1f) == 1 || FUN_0017e480(3, 1, 3, 5) == 1) FUN_001099d0(0x32, 1);
        else if (FUN_0017e480(9, 1, 0xc, 0x1f) == 1) FUN_001099d0(0x33);
        else if (FUN_0017e480(1, 1, 2, 0x1c) == 1) FUN_001099d0(0x34);
    }
    else if (major == 7)
    {
        if (FUN_0017e480(4, 5, 0xc, 0x1f) == 1) FUN_001099d0(0x35);
        else if (FUN_0017e480(1, 1, 2, 0x1c) == 1) FUN_001099d0(0x4d);
        else if (FUN_0017e480(3, 1, 3, 5) == 1) FUN_001099d0(0x5c);
    }
    else if (major == 4) FUN_001099d0(0x4d, 1);
    else if (major == 0x27 && minor == 1) FUN_001099d0(0x65);
}

// FUN_001aa1b0 NONMATCHING
void func_001aa1b0(void)
{
    s32 major = gMtScene->fldMajorId;
    s32 minor = gMtScene->fldMinorId;
    u32 time = FUN_0016ef30();

    if (major == 6 && (minor == 1 || minor == 3 || minor == 4 || minor == 7 || minor == 0xb || minor == 0x14) &&
        (time == 1 || time == 3 || time == 5))
    {
        func_0010a410(4, (const void*)0x67f080);
    }
    else if (major == 6 && (minor == 2 || minor == 5 || minor == 0x10) &&
             (time == 5 || time == 3) && FUN_0017e480(7, 0x12, 9, 0x14) == 1)
    {
        func_0010a410(4, (const void*)0x67f100);
    }
    else if (major == 7 && minor == 1 && time >= 4 && time <= 7 && FUN_0017e480(9, 0x12, 9, 0x12) == 1)
    {
        func_0010a410(4, (const void*)0x67f200);
    }
    else if (major == 7 && minor == 1 && time == 7)
    {
        func_0010a410(4, (const void*)0x67f240);
    }
    else if (major == 7 && minor == 1 && time == 1)
    {
        func_0010a410(4, (const void*)0x67f180);
    }
    else if (((major == 7 && minor == 9) || (major == 9 && (minor == 1 || minor == 2 || minor == 7)) ||
              (major == 0xc && minor == 1)) &&
             (time == 5 || time == 4) && FUN_0017e480(7, 0x12, 9, 0x14) == 1)
    {
        func_0010a410(4, (const void*)0x67f100);
    }
    else if (((major == 6 && (minor == 2 || minor == 0x10)) || (major == 7 && minor == 9) ||
              (major == 0xc && minor == 1)) &&
             (time == 5 || time == 4 || time == 6 || time == 7) && FUN_0017e480(10, 0x10, 0xb, 0x19) == 1)
    {
        func_0010a410(4, (const void*)0x67f140);
    }
    else if (major == 6 && FUN_0016f190(0xe60) == 1)
    {
        func_0010a410(4, (const void*)0x67f240);
    }
    else if (major == 0x0e && minor == 1)
    {
        func_0010a410(4, (const void*)0x67f340);
    }
    else if (major == 0x0e && minor == 5)
    {
        func_0010a410(4, (const void*)0x67f300);
    }
    else if (major == 0x21 && minor == 1)
    {
        func_0010a410(4, (const void*)0x67f2c0);
    }
    else if (major == 0x21)
    {
        func_0010a410(4, (const void*)0x67f380);
    }
    else
    {
        func_00109f60(4, 0);
    }
}

// FUN_001aa8f0 NONMATCHING
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
    else if (func_001c7130(0x45228000, work[0]) == 1)
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
