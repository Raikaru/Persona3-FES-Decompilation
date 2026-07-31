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
typedef struct KClumpResourceList
{
    u8 reserved[0x20];
    void** materials;     // 0x20
    u32 count;            // 0x24
} KClumpResourceList;
typedef struct KClumpStreamWork
{
    u32 state;
    u8 pad04[0x0c];
    u32 mode;
    void* stream;
    u32 current;
    u16 currentStatus;
    u16 pad1e;
    u32 count;
    void* queuedStreams[8];
    u32 queuedValues[8];
    u16 queuedStatus[8];
} KClumpStreamWork;
typedef struct KClumpUserDataContext
{
    char name[0x40];
    u32 count;
} KClumpUserDataContext;


/* The retail code uses these engine entry points through the split executable. */
extern void* func_004916d0(void* object, KClumpCallback callback, void* data);
extern void* func_004932c0(void* object, KClumpCallback callback, void* data);
extern void* func_004cb6e0(void* object, KClumpCallback callback, void* data);
extern void* func_0048ee30(void* object, s32 index);
extern s32 func_0048ede0(void* object);
extern s32 func_0048ef30(void* object);
extern s32 func_0048a2c0(void* object);
extern s32 func_0048a480(void* object);
extern void func_0048a3f0(void* object, u32 mode);
extern void func_0048a2a0(void* object, void* data);
extern void func_00466640(void* data);
extern void func_001b5a30(void* material);
extern RwSphere* func_004912b0(void* object);
extern RwMatrix* func_004cb2f0(void* frame);
extern void* func_0034fcd0(void* data);
extern void* func_0034fd10(void* data);
extern void* func_0034fd30(void* data);
extern void* func_0034fd50(void* data);
extern void* func_0034fd70(void* data, u16 value);
extern void* func_0034fcf0(void* data);
extern void* func_0034fdf0(void* data, void* value);
extern void* func_0034fe80(void* data, void* value);
extern void* func_001021c0(void* path, u8* mode);
extern u32 func_001c7130(f32 value, u32 state);
extern void FUN_001099d0(u32 value, ...);
extern void FUN_00108fd0(u32 value, ...);
extern u8 FUN_0016ef30(void);
extern u32 FUN_0016f190(u32 flag);
extern u32 FUN_0017e480(u32 a, u32 b, u32 c, u32 d);
extern void K_Assert(const char* message, s32 line);
extern void (*D_00960090)(u32 state, ...);
extern u32 D_007CE204;
extern u32 D_007CC1E4;
extern u32 D_007CC1F4;
extern u32 D_007CC1F8;
extern u32 D_007CC1C0;
extern u32 D_007CE158;
extern u32 D_008668F0[];
extern void (*jtbl_0096017C)(void* memory);
#pragma alias jtbl_0096017C_abs jtbl_0096017C
extern u32 jtbl_0096017C_abs[];
extern void* D_007D2D60;
#pragma alias D_00960090_abs D_00960090
extern u8 D_00960090_abs[];
#pragma alias D_007D2D60_abs D_007D2D60
extern u8 D_007D2D60_abs[];
extern u32 D_00960184[];
extern char D_00678C78;
#pragma alias D_00678C78_abs D_00678C78
extern char D_00678C78_abs[];
extern u32 D_00678C00[];
extern const char D_00678C28[];
extern const char D_00678C38[];
extern const char D_00678C48[];
extern const char D_00678C60[];
extern f32 D_007CE154;
extern const char D_00678BD8[];
extern const char D_00678BE8[];
extern const char D_00678C88[];
extern const char D_00678CA0[];
extern const char D_00678CB8[];
extern u8 D_0067F080[];
extern u8 D_0067F100[];
extern u8 D_0067F140[];
extern u8 D_0067F180[];
extern u8 D_0067F200[];
extern u8 D_0067F240[];
extern u8 D_0067F2C0[];
extern u8 D_0067F300[];
extern u8 D_0067F340[];
extern u8 D_0067F380[];

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

static inline void* kclump_alloc(u32 count, u32 size, u32 flags)
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
        D_00960090(0xe, 1);
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

// FUN_001a74b0 MATCHING
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

// FUN_001a64f0
u32 K_Clump_MatUsrDataHasData(const RpMaterial* material, const char* name)
{
    s32 i;
    u32 result;
    RpUserDataArray* userData;

    result = 0;
    for (i = 0; i < RpMaterialGetUserDataArrayCount(material); i++)
    {
        userData = RpMaterialGetUserDataArray(material, i);
        /* The retail function performs the accessor twice. */
        RpUserDataArrayGetName(userData);
        if (strcmp(RpUserDataArrayGetName(userData), name) == 0)
        {
            result = 1;
            break;
        }
    }
    return result;
}

// FUN_001a65c0
void* func_001a65c0(void* geometry, const char** name)
{
    KClumpResourceList* resourceList;
    s32 resourceIndex;
    void* material;
    s32 materialIndex;
    u32 found;
    RpUserDataArray* userData;

    resourceList = *(KClumpResourceList**)((u8*)geometry + 0x18);
    for (resourceIndex = 0; resourceIndex < (s32)resourceList->count; resourceIndex++)
    {
        material = resourceList->materials[resourceIndex];
        found = 0;
        for (materialIndex = 0; materialIndex < RpMaterialGetUserDataArrayCount((RpMaterial*)material); materialIndex++)
        {
            userData = RpMaterialGetUserDataArray((RpMaterial*)material, materialIndex);
            RpUserDataArrayGetName(userData);
            if (strcmp(RpUserDataArrayGetName(userData), (const char*)(name + 1)) == 0)
            {
                found = 1;
                break;
            }
        }
        if (found == 1)
        {
            *(u32*)name = 1;
            return NULL;
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

// FUN_001a6740
u32 func_001a6740(void* geometry, const char* name)
{
    s32 resourceIndex;
    void* material;
    s32 materialIndex;
    u32 result;
    RpUserDataArray* userData;

    
    for (resourceIndex = 0; resourceIndex < (s32)*(u32*)((u8*)geometry + 0x14); resourceIndex++)
    {
        material = *(void**)(*(u32*)((u8*)geometry + 0x10) + resourceIndex * 4);
        result = 0;
        for (materialIndex = 0; materialIndex < RpMaterialGetUserDataArrayCount((RpMaterial*)material); materialIndex++)
        {
            userData = RpMaterialGetUserDataArray((RpMaterial*)material, materialIndex);
            RpUserDataArrayGetName(userData);
            if (strcmp(RpUserDataArrayGetName(userData), name) == 0)
            {
                result = 1;
                break;
            }
        }
        if (result == 1)
        {
            return 1;
        }
    }
    return 0;
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

// FUN_001a69a0
void* func_001a69a0(void* object, const char* name, s32 value)
{
    s32 resourceIndex;
    s32 elementIndex;
    void* geometry;
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

// FUN_001a6c00
s32 func_001a6c00(void* object, const char* name)
{
    KClumpUserDataContext context;
    s32 resourceIndex;
    s32 elementIndex;
    void* clump;
    void* material;

    clump = *(void**)((u8*)object + 4);
    strcpy(context.name, name);
    context.count = 0;
    for (resourceIndex = 0; resourceIndex < func_0048ede0(clump); resourceIndex++)
    {
        material = func_0048ee30(clump, resourceIndex);
        if (strcmp(RpUserDataArrayGetName((RpUserDataArray*)material), context.name) == 0)
        {
            for (elementIndex = 0; elementIndex < func_0048ef30(material); elementIndex++)
            {
                if (RpUserDataArrayGetFormat((RpUserDataArray*)material) == rpINTUSERDATA)
                {
                    context.count++;
                }
            }
        }
    }
    func_004cb6e0(clump, (KClumpCallback)func_001a6af0, &context);
    return (s32)context.count;
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

// FUN_001a6e90
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
    s32 resourceIndex;
    s32 elementIndex;
    void* geometry;
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
                        context.resultMaterial = geometry;
                        *(RwV2d*)result = *(RwV2d*)&context.resultValue;
                        return;
                    }
                    context.currentIndex++;
                }
            }
        }
    }
    func_004cb6e0(geometry, (KClumpCallback)func_001a6d20, &context);
    *(RwV2d*)result = *(RwV2d*)&context.resultValue;
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

// FUN_001a70a0
void* func_001a70a0(void* object, void* data)
{
    s32 state;

    if (func_0048a2c0(*(void**)((u8*)object + 0x18)) == 0)
    {
        goto fail;
    }
    state = func_0048a480(object);
    if (state == 0)
    {
        goto normal;
    }
    if (state == 3)
    {
        goto normal;
    }
    switch (state)
    {
    case 1:
        goto normal;
    case 2:
        goto state2;
    default:
        goto default_state;
    }
state2:
    func_0048a3f0(object, 2);
    goto normal;
default_state:
    func_0048a3f0(object, 2);
    goto normal;
normal:
    func_0048a2a0(object, data);
    goto done;
fail:
    func_00466640(data);
done:
    return object;
}

// FUN_001a7170
void func_001a7170(void* object, void* data)
{
    func_004916d0(object, (KClumpCallback)func_001a70a0, data);
}

// FUN_001a71a0
void func_001a71a0(u32* state, u32 kind, void* object, u32 enabled, u32 flags)
{
    KClumpMaterialNode* node;

    node = (KClumpMaterialNode*)kclump_alloc(1, sizeof(KClumpMaterialNode), 0x40000);
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

// MWCC floor: retail holds D_00678C00 in $v1 while b210 assigns the equivalent
// pointer lifetime to $a0; direct indexing regresses nd5 to nd34.
// FUN_001a7370 NONMATCHING
void* func_001a7370(void* material, u32* state)
{
    s32 candidate;
    s32 current;
    s32 selected;
    s32 value;
    u32* values;

    value = K_Clump_MatUsrDataGetInt((RpMaterial*)material, D_00678C28);
    if (K_Clump_MatUsrDataHasData((RpMaterial*)material, D_00678C38))
    {
        if (value < 2)
        {
            value = 2;
        }
        state[2] = 1;
    }
    candidate = 0;
    values = D_00678C00;
    for (; candidate < 10; candidate++)
    {
        if (state[0] == values[candidate])
        {
            break;
        }
    }
    current = 0;
    values = D_00678C00;
    for (; current < 10; current++)
    {
        if (value == values[current])
        {
            break;
        }
    }
    if (candidate < current)
    {
        state[0] = D_00678C00[current];
    }
    selected = K_Clump_MatUsrDataHasData((RpMaterial*)material, D_00678C48);
    if (selected == 1)
    {
        state[1] = 1;
    }
    return material;
}

// FUN_001a74e0
void* func_001a74e0(void* object, u32* state)
{
    u32 callbackState[3];
    void* resources;

    memset(callbackState, 0, sizeof(callbackState));
    resources = ((KClumpContainer*)object)->resources;
    if (resources != NULL)
    {
        func_004932c0(resources, (KClumpCallback)func_001a7370, callbackState);
        func_001a71a0(state, callbackState[0], object, callbackState[1], callbackState[2]);
    }
    return object;
}

// FUN_001a7570
void* func_001a7570(void* clump)
{
    u32* state;

    state = (u32*)kclump_alloc(1, 0x2c, 0x40000);
    func_004916d0(clump, (KClumpCallback)func_001a74e0, state);
    if (state[1] == 0 &&
        (state[0] == 0 ||
         (state[4] == 0 && state[3] == 0 && state[5] == 0 &&
          state[9] == 0 && state[10] == 0 && state[6] == 0 &&
          state[7] == 0 && state[8] == 0)))
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

// The retail entry uses the opposite null-state branch layout; MWCC keeps the equivalent beqz form.
// The nine volatile list traversals and final state release are otherwise instruction-identical.
// FUN_001a7710 NONMATCHING
void func_001a7710(u32* state)
{
    typedef struct
    {
        u8 pad[8];
        volatile /* Removing this function's qualifier batch worsens func_001a7710 (NONMATCHING nd3 -> NONMATCHING nd304, size 504 -> 468) - measured W170. */ u32 list8;
        volatile /* Removing this function's qualifier batch worsens func_001a7710 (NONMATCHING nd3 -> NONMATCHING nd304, size 504 -> 468) - measured W170. */ u32 listc;
        volatile /* Removing this function's qualifier batch worsens func_001a7710 (NONMATCHING nd3 -> NONMATCHING nd304, size 504 -> 468) - measured W170. */ u32 list10;
        volatile /* Removing this function's qualifier batch worsens func_001a7710 (NONMATCHING nd3 -> NONMATCHING nd304, size 504 -> 468) - measured W170. */ u32 list14;
        volatile /* Removing this function's qualifier batch worsens func_001a7710 (NONMATCHING nd3 -> NONMATCHING nd304, size 504 -> 468) - measured W170. */ u32 list18;
        volatile /* Removing this function's qualifier batch worsens func_001a7710 (NONMATCHING nd3 -> NONMATCHING nd304, size 504 -> 468) - measured W170. */ u32 list1c;
        volatile /* Removing this function's qualifier batch worsens func_001a7710 (NONMATCHING nd3 -> NONMATCHING nd304, size 504 -> 468) - measured W170. */ u32 list20;
        volatile /* Removing this function's qualifier batch worsens func_001a7710 (NONMATCHING nd3 -> NONMATCHING nd304, size 504 -> 468) - measured W170. */ u32 list24;
        volatile /* Removing this function's qualifier batch worsens func_001a7710 (NONMATCHING nd3 -> NONMATCHING nd304, size 504 -> 468) - measured W170. */ u32 list28;
    } KClumpFreeState;
    KClumpFreeState* work;
    KClumpMaterialNode* node;
    KClumpMaterialNode* next;

    if (state == NULL)
        return;
    work = (KClumpFreeState*)(void*)state;


    while (work->list8 != 0)
    {
        node = (KClumpMaterialNode*)work->list8;
        next = node->next;
        (*(void (**)(void*))jtbl_0096017C_abs)(node);
        work->list8 = (u32)next;
    }

    while (work->list18 != 0)
    {
        node = (KClumpMaterialNode*)work->list18;
        next = node->next;
        (*(void (**)(void*))jtbl_0096017C_abs)(node);
        work->list18 = (u32)next;
    }

    while (work->list1c != 0)
    {
        node = (KClumpMaterialNode*)work->list1c;
        next = node->next;
        (*(void (**)(void*))jtbl_0096017C_abs)(node);
        work->list1c = (u32)next;
    }

    while (work->listc != 0)
    {
        node = (KClumpMaterialNode*)work->listc;
        next = node->next;
        (*(void (**)(void*))jtbl_0096017C_abs)(node);
        work->listc = (u32)next;
    }

    while (work->list10 != 0)
    {
        node = (KClumpMaterialNode*)work->list10;
        next = node->next;
        (*(void (**)(void*))jtbl_0096017C_abs)(node);
        work->list10 = (u32)next;
    }

    while (work->list20 != 0)
    {
        node = (KClumpMaterialNode*)work->list20;
        next = node->next;
        (*(void (**)(void*))jtbl_0096017C_abs)(node);
        work->list20 = (u32)next;
    }

    while (work->list14 != 0)
    {
        node = (KClumpMaterialNode*)work->list14;
        next = node->next;
        (*(void (**)(void*))jtbl_0096017C_abs)(node);
        work->list14 = (u32)next;
    }

    while (work->list24 != 0)
    {
        node = (KClumpMaterialNode*)work->list24;
        next = node->next;
        (*(void (**)(void*))jtbl_0096017C_abs)(node);
        work->list24 = (u32)next;
    }

    while (work->list28 != 0)
    {
        node = (KClumpMaterialNode*)work->list28;
        next = node->next;
        (*(void (**)(void*))jtbl_0096017C_abs)(node);
        work->list28 = (u32)next;
    }

    (*(void (**)(void*))jtbl_0096017C_abs)((void*)state);
}

// FUN_001a7910
void func_001a7910(void* object, f32* scale)
{
    KClumpResourceList* resources;
    u32 i;
    u32 color;
    s32 red;
    s32 green;
    s32 blue;
    s32 alpha;
    void* material;
    RwRGBA materialColor;

    resources = (KClumpResourceList*)((KClumpContainer*)object)->resources;
    for (i = 0; i < resources->count; i++)
    {
        material = resources->materials[i];
        func_001b5a30(material);
        color = (u32)K_Clump_MatUsrDataGetInt((RpMaterial*)material, D_00678C60);
        red = (s32)((f32)((color >> 16) & 0xff) * scale[0]);
        green = (s32)((f32)((color >> 8) & 0xff) * scale[1]);
        blue = (s32)((f32)(color & 0xff) * scale[2]);
        alpha = (s32)((f32)((color >> 24) & 0xff) * scale[3]);
        if ((u32)red > 0xff)
        {
            red = 0xff;
        }
        materialColor.r = (u8)red;
        if ((u32)green > 0xff)
        {
            green = 0xff;
        }
        materialColor.g = (u8)green;
        if ((u32)blue > 0xff)
        {
            blue = 0xff;
        }
        materialColor.b = (u8)blue;
        if ((u32)alpha > 0xff)
        {
            alpha = 0xff;
        }
        materialColor.a = (u8)alpha;
        *(RwRGBA*)((u8*)material + 4) = materialColor;
    }
}

// FUN_001a7b50
void func_001a7b50(void* state, u32 mode)
{
    KClumpMaterialNode* item;
    RwSphere* sphere;
    void* resources;
    u32 found;
    void* object;
    void (**resourceCall)(void*);
    if (state == NULL)
    {
        return;
    }
    if (mode == 1)
    {
        void (**renderState)(u32, ...);

        renderState = (void (**)(u32, ...))D_00960090_abs;
        (*renderState)(6, 1);
        (*renderState)(8, 1);
    }
    RpSkyRenderStateSet(2, (void*)0x44);
    RpSkyRenderStateSet(3, (void*)0x717fb);
    item = *(KClumpMaterialNode**)((u8*)state + 8);
    while (item != NULL)
    {
        object = (void*)*(void**)&item->object;
        sphere = func_004912b0(object);
        if (RwCameraFrustumTestSphere((RwCamera*)*(void**)(u8*)0x00960070, sphere) != rwSPHEREOUTSIDE)
        {
            if (item->enabled == 1)
            {
                (*(void (**)(u32, ...))(u8*)0x00960090)(0xe, 0);
            }
            if (D_007CC1C0 == 1)
            {
                object = item->object;
                resourceCall = (void (**)(void*))((u8*)object + 0x48);
                (*resourceCall)(object);
            }
            if (item->enabled == 1)
            {
                (*(void (**)(u32, ...))(u8*)0x00960090)(0xe, 1);
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
                    if (D_007CC1C0 == 1)
                    {
                        object = item->object;
                        resourceCall = (void (**)(void*))((u8*)object + 0x48);
                        (*resourceCall)(object);
                    }
                    if (item->enabled == 1)
                    {
                        (*(void (**)(u32, ...))(u8*)0x00960090)(0xe, 1);
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
        (*renderState)(6, 1);
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
            if (*(u32*)((u8*)&D_007CC1C0 + 0x10) == 1)
            {
                object = item->object;
                resourceCall = (void (**)(void*))((u8*)object + 0x48);
                (*resourceCall)(object);
            }
            if (item->enabled == 1)
            {
                (*(void (**)(u32, ...))(u8*)0x00960090)(0xe, 1);
            }
        }
        item = item->next;
    }
    if (mode == 1)
    {
        void (**renderState)(u32, ...);

        renderState = (void (**)(u32, ...))D_00960090_abs;
        (*renderState)(6, 1);
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
            if (*(u32*)((u8*)&D_007CC1C0 + 0x14) == 1)
            {
                object = item->object;
                resourceCall = (void (**)(void*))((u8*)object + 0x48);
                (*resourceCall)(object);
            }
            if (item->enabled == 1)
            {
                (*(void (**)(u32, ...))(u8*)0x00960090)(0xe, 1);
            }
        }
        item = item->next;
    }
}

// FUN_001a7fc0
void func_001a7fc0(void* state, u32 mode)
{
    KClumpMaterialNode* item;
    RwSphere* sphere;
    void* resources;
    void (*resourceCall)(void*);
    u32 found;

    if (state == NULL)
    {
        return;
    }
    if (mode == 1)
    {
        void (**renderState)(u32, ...);

        renderState = (void (**)(u32, ...))D_00960090_abs;
        (*renderState)(6, 1);
        (*renderState)(8, 0);
    }
    RpSkyRenderStateSet(2, (void*)0x44);
    RpSkyRenderStateSet(3, (void*)0x717fb);
    item = *(KClumpMaterialNode**)((u8*)state + 0x20);
    while (item != NULL)
    {
        found = 0;
        resources = ((KClumpContainer*)item->object)->resources;
        if (resources != NULL)
        {
            func_004932c0(resources, (KClumpCallback)kclump_alpha_callback,
                          &found);
            if (found == 0)
            {
                sphere = func_004912b0(item->object);
                if (RwCameraFrustumTestSphere(
                        (RwCamera*)*(void**)(u8*)0x00960070, sphere) !=
                    rwSPHEREOUTSIDE)
                {
                    if (item->enabled == 1)
                    {
                        (*(void (**)(u32, ...))(u8*)0x00960090)(0xe, 0);
                    }
                    if (*(u32*)((u8*)&D_007CC1F8 + 4) == 1)
                    {
                        resourceCall =
                            *(void (**)(void*))((u8*)item->object + 0x48);
                        (*resourceCall)(item->object);
                    }
                    if (item->enabled == 1)
                    {
                        (*(void (**)(u32, ...))(u8*)0x00960090)(0xe, 1);
                    }
                }
            }
        }
        item = item->next;
    }
}

// FUN_001a8140 NONMATCHING
void func_001a8140(void* state, u32 mode)
{
    KClumpMaterialNode* item;
    RwSphere* sphere;
    if (state == NULL)
    {
        return;
    }
    if (mode == 1)
    {
        D_00960090(6, 1);
        D_00960090(8, 1);
    }
    RpSkyRenderStateSet(2, (void*)0x44);
    RpSkyRenderStateSet(3, (void*)0x715fb);
    item = *(KClumpMaterialNode**)((u8*)state + 0x0c);
    while (item != NULL)
    {
        sphere = func_004912b0(item->object);
        if (RwCameraFrustumTestSphere((RwCamera*)D_007D2D60, sphere) != rwSPHEREOUTSIDE)
        {
            if (item->enabled == 1)
            {
                D_00960090(0xe, 0);
            }
            if (D_007CC1F8 == 1)
            {
                void* object = item->object;
                void (**resourceCall)(void*) = (void (**)(void*))((u8*)object + 0x48);
                (*resourceCall)(object);
            }
            if (item->enabled == 1)
            {
                D_00960090(0xe, 1);
            }
        }
        item = item->next;
    }

    if (D_007CE158 == 1)
    {
        RpSkyRenderStateSet(2, (void*)0x44);
        RpSkyRenderStateSet(3, (void*)0x707fd);
    }
    else
    {
        RpSkyRenderStateSet(2, (void*)0x44);
        RpSkyRenderStateSet(3, (void*)0x735fb);
    }
    item = *(KClumpMaterialNode**)((u8*)state + 0x10);
    while (item != NULL)
    {
        sphere = func_004912b0(item->object);
        if (RwCameraFrustumTestSphere((RwCamera*)D_007D2D60, sphere) != rwSPHEREOUTSIDE)
        {
            if (item->enabled == 1)
            {
                D_00960090(0xe, 0);
            }
            if (*(u32*)((u8*)&D_007CC1F8 + 4) == 1)
            {
                void* object = item->object;
                void (**resourceCall)(void*) = (void (**)(void*))((u8*)object + 0x48);
                (*resourceCall)(object);
            }
            if (item->enabled == 1)
            {
                D_00960090(0xe, 1);
            }
        }
        item = item->next;
    }

    if (mode == 1)
    {
        D_00960090(6, 1);
        D_00960090(8, 0);
    }
    RpSkyRenderStateSet(2, (void*)0x42);
    RpSkyRenderStateSet(3, (void*)0x71801);
    item = *(KClumpMaterialNode**)((u8*)state + 0x14);
    while (item != NULL)
    {
        u32 found = 0;
        void* object = item->object;
        if (object != NULL)
        {
            void* resources = *(void**)((u8*)object + 0x18);
            if (resources != NULL)
            {
                func_004932c0(resources, (KClumpCallback)kclump_alpha_callback, &found);
                if (found == 0)
                {
                    sphere = func_004912b0(object);
                    if (RwCameraFrustumTestSphere((RwCamera*)D_007D2D60, sphere) != rwSPHEREOUTSIDE)
                    {
                        if (item->enabled == 1)
                        {
                            D_00960090(0xe, 0);
                        }
                        if ((item->flags == 0 || item->colorScale[0] == 1.0f) &&
                            *(u32*)((u8*)&D_007CC1F8 + 8) == 1)
                        {
                            void (**resourceCall)(void*) = (void (**)(void*))((u8*)object + 0x48);
                            (*resourceCall)(object);
                        }
                        if (item->enabled == 1)
                        {
                            D_00960090(0xe, 1);
                        }
                    }
                }
            }
        }
        item = item->next;
    }

    RpSkyRenderStateSet(2, (void*)0x48);
    RpSkyRenderStateSet(3, (void*)0x71801);
    item = *(KClumpMaterialNode**)((u8*)state + 0x28);
    while (item != NULL)
    {
        sphere = func_004912b0(item->object);
        if (RwCameraFrustumTestSphere((RwCamera*)D_007D2D60, sphere) != rwSPHEREOUTSIDE)
        {
            if (item->enabled == 1)
            {
                D_00960090(0xe, 0);
            }
            if (item->flags == 1 && item->colorScale[0] < 1.0f && item->colorScale[0] > 0.0f)
            {
                if (*(u32*)((u8*)&D_007CC1F8 + 0x1c) == 1)
                {
                    func_001a8920(D_008668F0, (const u32*)item);
                }
            }
            else if (*(u32*)((u8*)&D_007CC1F8 + 0x1c) == 1)
            {
                void* object = item->object;
                void (**resourceCall)(void*) = (void (**)(void*))((u8*)object + 0x48);
                (*resourceCall)(object);
            }
            if (item->enabled == 1)
            {
                D_00960090(0xe, 1);
            }
        }
        item = item->next;
    }


    RpSkyRenderStateSet(2, (void*)0x48);
    RpSkyRenderStateSet(3, (void*)0x71801);
    item = *(KClumpMaterialNode**)((u8*)state + 0x24);
    while (item != NULL)
    {
        sphere = func_004912b0(item->object);
        if (RwCameraFrustumTestSphere((RwCamera*)D_007D2D60, sphere) != rwSPHEREOUTSIDE)
        {
            if (item->enabled == 1)
            {
                D_00960090(0xe, 0);
            }
            if (item->flags == 1 && item->colorScale[0] < 1.0f && item->colorScale[0] > 0.0f)
            {
                if (*(u32*)((u8*)&D_007CC1F8 + 0x18) == 1)
                {
                    func_001a8920(D_008668F0, (const u32*)item);
                }
            }
            else if (*(u32*)((u8*)&D_007CC1F8 + 0x18) == 1)
            {
                void* object = item->object;
                void (**resourceCall)(void*) = (void (**)(void*))((u8*)object + 0x48);
                (*resourceCall)(object);
            }
            if (item->enabled == 1)
            {
                D_00960090(0xe, 1);
            }
        }
        item = item->next;
    }

    item = *(KClumpMaterialNode**)((u8*)state + 0x14);
    while (item != NULL)
    {
        if (item->flags == 1 && *(u32*)((u8*)&D_007CC1F8 + 8) == 1)
        {
            if (item->colorScale[0] < 1.0f && item->colorScale[0] > 0.0f)
            {
                func_001a8920(D_008668F0, (const u32*)item);
            }
        }
        item = item->next;
    }
}

// FUN_001a8820
void* func_001a8820(void* item)
{
    void (*render)(void*);
    RwSphere* sphere;

    if ((*(u8*)((u8*)item + 2) & 4) != 0)
    {
        goto process;
    }
    return item;
process:
    if (*(u32*)((u8*)item + 0x18) != 0)
    {
        sphere = func_004912b0(item);
        if (RwCameraFrustumTestSphere(*(RwCamera**)0x00960070, sphere) != rwSPHEREOUTSIDE)
        {
            (*(void (**)(void*))((u8*)item + 0x48))(item);
            if (D_007CE204 == 1)
            {
                f32 debugValue;
                RwSphere* sphere2;
                debugValue = D_007CE154;
                sphere2 = func_004912b0(item);
                primSphereLine3D((RwV3d*)sphere2, sphere2->radius, (const RwRGBA*)&debugValue, 0);
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

// FUN_001a8920
void func_001a8920(u32* entries, const u32* source)
{
    u32* destination;
    s32 i;
    u32 value;

    if ((s32)entries[0] >= 0x80)
    {
        K_Assert(D_00678C78_abs, 0x3eb);
    }
    destination = (u32*)(entries[0] * 11 * 4);
    destination = (u32*)((u8*)destination + (u32)entries);
    destination++;
    i = 11;
    do
    {
        value = *source++;
        i--;
        *destination = value;
        destination++;
    } while (i > 0);
    entries[0]++;
}

// FUN_001a89c0
s32 func_001a89c0(const u32* left, const u32* right)
{
    RwCamera* camera;
    RwMatrix* cameraMatrix;
    RwV3d leftDelta;
    RwV3d rightDelta;
    RwV3d cameraPosition;
    f32 leftDistance;
    f32 rightDistance;

    camera = kwlnGetMainCamera();
    cameraMatrix = func_004cb2f0(*(void**)((u8*)camera + 4));
    cameraPosition = cameraMatrix->pos;
    leftDelta.x = func_004cb2f0(*(void**)(*left + 4))->pos.x - cameraPosition.x;
    leftDelta.y = func_004cb2f0(*(void**)(*left + 4))->pos.y - cameraPosition.y;
    leftDelta.z = func_004cb2f0(*(void**)(*left + 4))->pos.z - cameraPosition.z;
    rightDelta.x = func_004cb2f0(*(void**)(*right + 4))->pos.x - cameraPosition.x;
    rightDelta.y = func_004cb2f0(*(void**)(*right + 4))->pos.y - cameraPosition.y;
    rightDelta.z = func_004cb2f0(*(void**)(*right + 4))->pos.z - cameraPosition.z;
    leftDistance = RwV3dLength(&leftDelta);
    rightDistance = RwV3dLength(&rightDelta);
    return (s32)(leftDistance - rightDistance);
}

/* Remaining differences are qsort argument load order and one commutative item-address add. */
// FUN_001a8b10 NONMATCHING
void func_001a8b10(u32* entries)
{
    s32 i;
    KClumpMaterialNode* item;
    RwSphere* sphere;

    {
        s32 count = (s32)entries[0];
        qsort(entries + 1, count, 0x2c,
              (int (*)(const void*, const void*))func_001a89c0);
    }
    for (i = (s32)entries[0] - 1; i >= 0; i--)
    {
        item = (KClumpMaterialNode*)((u8*)entries + 4 + i * 0x2c);
        sphere = func_004912b0(item->object);
        if (RwCameraFrustumTestSphere(
                (RwCamera*)*(void**)D_007D2D60_abs, sphere) != rwSPHEREOUTSIDE)
        {
            if (item->enabled == 1)
            {
                (*(void (**)(u32, ...))D_00960090_abs)(0xe, 0);
            }
            func_001a7910(item->object, (f32*)((u8*)item + 0x0c));
            if (item->colorScale[3] < 1.0f && item->colorScale[3] > 0.0f)
            {
                void (**renderState)(u32, ...);
                renderState = (void (**)(u32, ...))D_00960090_abs;
                (*renderState)(6, 1);
                (*renderState)(8, 1);
                RpSkyRenderStateSet(2, (void*)0x44);
                RpSkyRenderStateSet(3, (void*)0x72001);
                if (item->kind == 2)
                {
                    (*(void (**)(void*))((u8*)item->object + 0x48))(
                        item->object);
                }
                renderState = (void (**)(u32, ...))D_00960090_abs;
                (*renderState)(6, 1);
                (*renderState)(8, 0);
                switch (item->kind)
                {
                case 2:
                {
                    RpSkyRenderStateSet(2, (void*)0x44);
                    RpSkyRenderStateSet(3, (void*)0x717fb);
                }
                    break;
                case 4:
                {
                    RpSkyRenderStateSet(2, (void*)0x42);
                    RpSkyRenderStateSet(3, (void*)0x71801);
                }
                    break;
                case 3:
                {
                    RpSkyRenderStateSet(2, (void*)0x48);
                    RpSkyRenderStateSet(3, (void*)0x71801);
                }
                    break;
                }
                (*(void (**)(void*))((u8*)item->object + 0x48))(item->object);
            }
            if (item->enabled == 1)
            {
                (*(void (**)(u32, ...))D_00960090_abs)(0xe, 1);
            }
        }
    }
}

/* Remaining differences are one call-argument load order and one commutative address add. */
// FUN_001a8db0 NONMATCHING
s32 func_001a8db0(KwlnTask* task)
{
    u32* work;
    s32 i;
    u32 mode;

    work = (u32*)task->workData;
    switch (work[0])
    {
    case 0:
    {
        if (work[3] == 0)
        {
            if (H_Cdvd_IsFileLoaded((HCdvd*)work[1]) == 0)
            {
                break;
            }
            if (work[1] != 0)
            {
                work[5] = (u32)func_0034fcd0(*(void**)((u8*)work[1] + 0x110));
                H_Cdvd_Destroy((HCdvd*)work[1]);
                work[1] = 0;
            }
        }
        else
        {
            work[5] = (u32)func_0034fcd0(func_001021c0(work + 0x1d, (u8*)&mode));
        }
        work[0]++;
    }
        break;
    case 1:
        break;
    case 2:
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
                    func_0034fd70(
                        (void*)*(volatile u32*)&work[5],
                        (u16)work[7]);
                    work[6]++;
                }
                else
                {
                    work[4] = 0;
                }
            }
            for (i = 0; i < 8; i++)
            {
                if (*(u32*)((u8*)work + (9 + i) * 4) != 0)
                {
                    if (work[0x11 + i] < work[2])
                    {
                        func_0034fd30((void*)work[9 + i]);
                        func_0034fd70((void*)work[9 + i], *(u16*)((u8*)work + 100 + i * 2));
                        work[0x11 + i]++;
                    }
                    else
                    {
                        func_0034fcf0((void*)work[9 + i]);
                        work[9 + i] = 0;
                        work[8]--;
                    }
                }
            }
        }
    }
        break;
    case 3:
    {
        return -1;
    }
    }
    return 0;
}

// FUN_001a8fe0
void func_001a8fe0(KwlnTask* task)
{
    u32* work;
    s32 i;
    KwlnTask* parent;

    parent = task;
    work = (u32*)parent->workData;
    for (i = 0; i < 8; i++)
    {
        if (*(u32*)((u8*)work + (i * 4) + 36) != 0)
        {
            func_0034fcf0((void*)*(u32*)((u8*)work + (i * 4) + 36));
        }
    }
    if (work[5] != 0)
    {
        func_0034fcf0((void*)work[5]);
    }
    (*(void (**)(void*))jtbl_0096017C_abs)(parent->workData);
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

// FUN_001a91b0
s32 func_001a91b0(KwlnTask* task, void* data)
{
    KClumpStreamWork* work;
    KClumpStreamWork* indexedWork;
    s32 index;
    void* stream;
    u32 indexOffset;
    void** streamSlot;

    work = (KClumpStreamWork*)task->workData;
    index = -1;
    if (work->mode == 1)
    {
        index = 0;
        while (index < 8)
        {
            indexedWork = work;
            indexedWork = (KClumpStreamWork*)((s32)indexedWork + index * 4);
            if (indexedWork->queuedStreams[0] == NULL)
            {
                break;
            }
            index++;
        }
        indexOffset = index * 4;
        indexedWork = work;
        indexedWork = (KClumpStreamWork*)(indexOffset + (s32)indexedWork);
        streamSlot = &indexedWork->queuedStreams[0];
        *streamSlot = func_0034fd50(work->stream);
        stream = *streamSlot;
        func_0034fdf0(stream, data);
        *(u32*)((u8*)work->queuedValues + indexOffset) = 0;
        work->queuedStatus[index] = 2;
        work->count++;
    }
    else
    {
        func_0034fd10(work->stream);
        func_0034fdf0(work->stream, data);
        work->current = 0;
        work->mode = 1;
        work->currentStatus = 2;
    }
    work->state = 2;
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

/* Remaining code differences are two commutative address-add operand reversals. */
#pragma push
// FUN_001a9500 NONMATCHING
s32 func_001a9500(KwlnTask* task)
{
    typedef struct KClumpSoundUpdateWork
    {
        s32 state;
        s32 delay;
        s32 timer;
        s32 count;
        u32 values[8];
        RwV3d positions[8];
        u32 sounds[8];
        u32 flags[8];
    } KClumpSoundUpdateWork;
    KClumpSoundUpdateWork* work;
    s32 i;
    s32 fieldIndex;
    u8* fieldBase;

    work = (KClumpSoundUpdateWork*)task->workData;
    switch (work->state)
    {
    case 0:
        work->state++;
    case 1:
        if (work->count > 0)
        {
            fieldBase = (u8*)K_Field_Get();
            fieldIndex = (s32)work->values[0];
            func_001a91b0(
                *(KwlnTask**)(fieldBase + fieldIndex * 4 + 0x11f4),
                &work->positions[0]);
            if (((s32)work->sounds[0] <= -1) != 0)
            {
            }
            else
            {
                func_0010a4e0(1, 8, (s16)work->sounds[0], (s16)work->flags[0]);
            }
            work->count--;
            for (i = 1; i < 8; i++)
            {
                *((u32*)work + 4 + i - 1) = *((u32*)work + 4 + i);
                work->positions[i - 1] = work->positions[i];
                work->sounds[i - 1] = work->sounds[i];
                work->flags[i - 1] = work->flags[i];
            }
            work->timer = 0;
            work->state++;
        }
        break;
    case 2:
        if (work->timer < work->delay)
        {
            work->timer++;
        }
        else
        {
            work->state = 1;
        }
        break;
    case 3:
        return -1;
    }
    return 0;
}
#pragma pop

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

// FUN_001a9760
void func_001a9760(KwlnTask* task, u32 value, const RwV3d* position, u32 sound, u32 flags)
{
    typedef struct KClumpSoundWork
    {
        s32 header[3];
        s32 count;
        u32 values[8];
        RwV3d positions[8];
        u32 sounds[8];
        u32 flags[8];
    } KClumpSoundWork;
    KClumpSoundWork* work;

    if (task == NULL)
    {
        return;
    }
    work = (KClumpSoundWork*)task->workData;
    if (work->count >= 8)
    {
        K_Assert(&D_00678C78, 0x260);
    }
    work->values[work->count] = value;
    work->positions[work->count] = *position;
    work->sounds[work->count] = sound;
    work->flags[work->count] = flags;
    work->count++;
}

// FUN_001a9850 NONMATCHING
void func_001a9850(void)
{
    s32 floor;
    u32 scenario;

    if (D_007CE204 == 1)
    {
        return;
    }
    floor = (s32)K_FldDungeon_GetCurrentFloor();
    if (floor > 0)
    {
        if (floor >= 2 && (s32)FUN_0016f380(1) > 0)
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
            else if (floor > 0) H_Snd_PlayBgm(0x47, 1);
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
    }
    else
    {
    if ((gMtScene->fldMajorId == 7 && gMtScene->fldMinorId == 6) ||
        (gMtScene->fldMajorId == 8 && gMtScene->fldMinorId == 1) ||
        (gMtScene->fldMajorId == 9 && gMtScene->fldMinorId == 1))
    {
        if ((u8)FUN_0016ef30() == 8)
        {
            FUN_001099d0(0x47, 1);
            return;
        }
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
    if (gMtScene->fldMajorId == 0x1f)
    {
        FUN_001099d0(0x14);
        return;
    }
    if (datGetFlag(0xeef) == 1)
    {
        FUN_001099d0(0x14);
        return;
    }
    if (gMtScene->fldMajorId == 0x21) FUN_00108fd0(0x14);
    else if (gMtScene->fldMajorId == 0x22) FUN_001099d0(0x16);
    else if (gMtScene->fldMajorId == 0x23) FUN_001099d0(0x15);
    else if (gMtScene->fldMajorId == 0x25) FUN_001099d0(0x47);
    else if (gMtScene->fldMajorId == 0x0e && gMtScene->fldMinorId == 5) FUN_00108fd0(0x14);
    else if (gMtScene->fldMajorId == 8 && gMtScene->fldMinorId == 3) FUN_001099d0(0x36, 1);
    else if (gMtScene->fldMajorId == 5 && gMtScene->fldMinorId == 3) FUN_001099d0(0x36, 1);
    else if (gMtScene->fldMajorId == 8 && gMtScene->fldMinorId == 9) FUN_00108fd0(0x14);
    else if (gMtScene->fldMajorId == 7 && gMtScene->fldMinorId == 1)
    {
        if ((u8)FUN_0016ef30() < 2 || (u8)FUN_0016ef30() > 6)
            FUN_00108fd0(0x14);
    }
    else if (gMtScene->fldMajorId == 8 || gMtScene->fldMajorId == 9 ||
             gMtScene->fldMajorId == 10 || gMtScene->fldMajorId == 0xc ||
             (gMtScene->fldMajorId == 7 && gMtScene->fldMinorId == 9))
    {
        if (FUN_0017e480(4, 5, 0xc, 0x1f) == 1 ||
            FUN_0017e480(3, 1, 3, 5) == 1)
            FUN_001099d0(0x57, 1);
        else if (FUN_0017e480(1, 1, 2, 0x1c) == 1)
            FUN_001099d0(0x50);
    }
    else if (gMtScene->fldMajorId == 5 && gMtScene->fldMinorId == 1) FUN_001099d0(0x19);
    else if (gMtScene->fldMajorId == 0x0e) FUN_001099d0(0x20, 1);
    else if (gMtScene->fldMajorId == 6)
    {
        if (FUN_0017e480(4, 5, 8, 0x1f) == 1 ||
            FUN_0017e480(3, 1, 3, 5) == 1) FUN_001099d0(0x32, 1);
        else if (FUN_0017e480(9, 1, 0xc, 0x1f) == 1) FUN_001099d0(0x33);
        else if (FUN_0017e480(1, 1, 2, 0x1c) == 1) FUN_001099d0(0x34);
    }
    else if (gMtScene->fldMajorId == 7)
    {
        if (FUN_0017e480(4, 5, 0xc, 0x1f) == 1) FUN_001099d0(0x35);
        else if (FUN_0017e480(1, 1, 2, 0x1c) == 1) FUN_001099d0(0x4d);
        else if (FUN_0017e480(3, 1, 3, 5) == 1) FUN_001099d0(0x5c);
    }
    else if (gMtScene->fldMajorId == 4) FUN_001099d0(0x4d, 1);
    else if (gMtScene->fldMajorId == 0x27 && gMtScene->fldMinorId == 1) FUN_001099d0(0x65);
    }
}

// Retail offsets 0x000-0x730: scene/time/date dispatch and 13 audio-table branches; 0x734-0x73f is tail padding.
// FUN_001aa1b0
void func_001aa1b0(void)
{
    if (((gMtScene->fldMajorId == 6 && gMtScene->fldMinorId == 1) ||
         (gMtScene->fldMajorId == 6 && gMtScene->fldMinorId == 3) ||
         (gMtScene->fldMajorId == 6 && gMtScene->fldMinorId == 4) ||
         (gMtScene->fldMajorId == 6 && gMtScene->fldMinorId == 7) ||
         (gMtScene->fldMajorId == 6 && gMtScene->fldMinorId == 0xb) ||
         (gMtScene->fldMajorId == 6 && gMtScene->fldMinorId == 0x14)) &&
        (FUN_0016ef30() == 1 || FUN_0016ef30() == 3 || FUN_0016ef30() == 5))
    {
        func_0010a410(4, (const char*)D_0067F080);
        return;
    }

    if (((gMtScene->fldMajorId == 6 && gMtScene->fldMinorId == 2) ||
         (gMtScene->fldMajorId == 6 && gMtScene->fldMinorId == 5) ||
         (gMtScene->fldMajorId == 6 && gMtScene->fldMinorId == 0x10)) &&
        (FUN_0016ef30() == 5 || FUN_0016ef30() == 3) &&
        FUN_0017e480(7, 0x12, 9, 0x14) == 1)
    {
        func_0010a410(4, (const char*)D_0067F100);
        return;
    }

    if (gMtScene->fldMajorId == 7 && gMtScene->fldMinorId == 1 &&
        (FUN_0016ef30() == 4 || FUN_0016ef30() == 5 || FUN_0016ef30() == 6 || FUN_0016ef30() == 7) &&
        FUN_0017e480(9, 0x12, 9, 0x12) == 1)
    {
        func_0010a410(4, (const char*)D_0067F200);
        return;
    }

    if (gMtScene->fldMajorId == 7 && gMtScene->fldMinorId == 1 &&
        FUN_0016ef30() == 4 &&
        FUN_0017e480(7, 0x12, 9, 0x14) == 1)
    {
        func_0010a410(4, (const char*)D_0067F100);
        return;
    }

    if (gMtScene->fldMajorId == 7 && gMtScene->fldMinorId == 1 && FUN_0016ef30() == 7)
    {
        func_0010a410(4, (const char*)D_0067F240);
        return;
    }

    if (gMtScene->fldMajorId == 7 && gMtScene->fldMinorId == 1 && FUN_0016ef30() == 1)
    {
        func_0010a410(4, (const char*)D_0067F180);
        return;
    }

    if (((gMtScene->fldMajorId == 7 && gMtScene->fldMinorId == 9) ||
         (gMtScene->fldMajorId == 9 && gMtScene->fldMinorId == 1) ||
         (gMtScene->fldMajorId == 9 && gMtScene->fldMinorId == 2) ||
         (gMtScene->fldMajorId == 9 && gMtScene->fldMinorId == 7) ||
         (gMtScene->fldMajorId == 0xc && gMtScene->fldMinorId == 1)) &&
        (FUN_0016ef30() == 5 || FUN_0016ef30() == 4) &&
        FUN_0017e480(7, 0x12, 9, 0x14) == 1)
    {
        func_0010a410(4, (const char*)D_0067F100);
        return;
    }

    if (((gMtScene->fldMajorId == 6 && gMtScene->fldMinorId == 2) ||
         (gMtScene->fldMajorId == 6 && gMtScene->fldMinorId == 0x10) ||
         (gMtScene->fldMajorId == 7 && gMtScene->fldMinorId == 9) ||
         (gMtScene->fldMajorId == 0xc && gMtScene->fldMinorId == 1)) &&
        (FUN_0016ef30() == 5 || FUN_0016ef30() == 4 || FUN_0016ef30() == 6 || FUN_0016ef30() == 7) &&
        FUN_0017e480(0xa, 0x10, 0xb, 0x19) == 1)
    {
        func_0010a410(4, (const char*)D_0067F140);
        return;
    }

    if (gMtScene->fldMajorId == 6 && FUN_0016f190(0xe60) == 1)
    {
        func_0010a410(4, (const char*)D_0067F240);
        return;
    }

    if (gMtScene->fldMajorId == 0x0e && gMtScene->fldMinorId == 1)
    {
        func_0010a410(4, (const char*)D_0067F340);
        return;
    }

    if (gMtScene->fldMajorId == 0x0e && gMtScene->fldMinorId == 5)
    {
        func_0010a410(4, (const char*)D_0067F300);
        return;
    }

    if (gMtScene->fldMajorId == 0x21 && gMtScene->fldMinorId == 1)
    {
        func_0010a410(4, (const char*)D_0067F2C0);
        return;
    }

    if (gMtScene->fldMajorId == 0x21)
    {
        func_0010a410(4, (const char*)D_0067F380);
        return;
    }

    func_00109f60(4, 0);
}

// FUN_001aa8f0
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
    else if (func_001c7130(2600, work[0]) == 1)
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
