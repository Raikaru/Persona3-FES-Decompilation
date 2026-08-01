#include "Kosaka/k_data.h"
#include "Kosaka/Field/k_dungeon.h"
#include "Kosaka/k_assert.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Graphics/Model/mdlManager.h"
#include "Main/g_data.h"
#include "h_cdvd.h"
#include "temporary.h"
#include "Kosaka/Field/k_field.h"
#include "Scene/mt_scene.h"
#include "rw/rwplcore.h"
#include "Kosaka/Field/k_fldrc.h"
#include "Script/scr.h"

static void fieldReplaceBuffer(void** destination, u32* destinationSize,
                               const void* source, u32 sourceSize)
{
    void* buffer;

    if (*destination != NULL)
    {
        RwFree(*destination);
        *destination = NULL;
    }
    if (destinationSize != NULL)
    {
        *destinationSize = sourceSize;
    }
    if (source == NULL || sourceSize == 0)
    {
        return;
    }
    buffer = RwCalloc(1, sourceSize, rwMEMHINTDUR_GLOBAL);
    if (buffer != NULL)
    {
        memcpy(buffer, source, sourceSize);
        *destination = buffer;
    }
}


/*
 * The field data helpers below share the root-field scratch area.  The
 * retail layout keeps these values in the tail of Field; using offsets here
 * avoids inventing a second public work structure while retaining the
 * ownership and lifetime rules observed in the original code.
 */
#define FIELD_DATA_AT(field, offset, type) (*(type*)((u8*)(field) + (offset)))

extern u32 func_0010a720(u32 request);
extern u32 func_0010a770(u32 arg0, u32 arg1, void* buffer,
                         u32 arg3, u32 arg4, u32 arg5);
extern u32 func_0016dba0(s16 value);
extern u32 func_0016ef30(void);
extern u32 func_0016f190(u32 id);
extern u32 func_0017d920(void);
extern u32 func_0017da40(void);
extern u32 func_0017e480(u32 major, u32 minor, u32 mode, u32 limit);
extern void* func_001021c0(void* source, u32* size);
extern u32 func_001023a0(void* request);
extern void* func_001016b0(void* request);
extern void* func_00194b80(KwlnTask* parent, u32 priority, const char* name,
                           void* update, void* destroy, void* work);
extern void* func_001d4360(void);
extern u32 func_001d43e0(void* object);
extern void func_0019d3f0(const char* file, s32 line);
extern void* func_00316bd0(u32 type, u32 priority, void* data, u32 size, u32 mode);
extern u32 func_00316f70(Model* model);
extern u32* PTR_DAT_007cd540;
extern u16* puGpffffa850;
extern void (*D_0096017c)(void* memory);
extern u32 D_00960184[];
#pragma alias D_00960184_abs D_00960184
extern u8 D_00960184_abs[];


void* gFldScrMemory; // 007ce228
u32 gFldScrSize;     // 007ce224
Model* gFldBaseMdl;  // 007ce21c
u32 gTraceCode;      // 007ce208

FldDungeonFloorData gFldDngFloorsData[500]; // 00867f60

/* These symbols are consumed by the field encounter/script modules. */
ScrHeader* D_007CE220;
void* D_007CE218;
s32 D_007CE214;

static void* sFieldMainTable;
static u32 sFieldMainTableCount;
static void* sFieldMainTableCursor;
static void* sFieldMainTableEnd;
static void* sFieldNmScript;
static u32 sFieldNmScriptSize;
static void* sFieldNsScript;
static u32 sFieldNsScriptSize;
static s16* sComuTable;
static u32 sComuTableRecords;
static u32 sComuTableEmptyRecords;
static void* sNpcComuScript;
static u32 sNpcComuScriptSize;

typedef struct FieldLoadWork
{
    u32 state;
    u32 scenarioMode;
    HCdvd* request;
    void* enemyTableRequest;
} FieldLoadWork;

static u32 fieldCurrentMajor(void)
{
    return (u32)gMtScene->fldMajorId;
}

static u32 fieldCurrentMinor(void)
{
    return (u32)gMtScene->fldMinorId;
}

static void fieldSetTableBounds(void* table)
{
    u32 count;

    sFieldMainTable = table;
    if (table == NULL)
    {
        sFieldMainTableCount = 0;
        sFieldMainTableCursor = NULL;
        sFieldMainTableEnd = NULL;
        return;
    }

    count = *(u32*)table;
    sFieldMainTableCount = count;
    sFieldMainTableCursor = (u8*)table + 0x20;
    sFieldMainTableEnd = (u8*)sFieldMainTableCursor + count * 0x20;
}

// FUN_001b7b10. Read 'field.bf' and copy its content in 'gFldScrMemory' and its size in 'gFldScrSize'
void K_Data_LoadFldMainScript()
{
    char buffer[128];
    HCdvd* cdvd;
    u32 scrSize;
    void* scrMemory;


    sprintf(buffer, "field/script/field.bf");

    cdvd = H_Cdvd_Request(buffer, HCDVD_FILENORMAL);
    H_Cdvd_ReadSync(cdvd);

    scrSize = cdvd->fileSize;
    scrMemory = gFldScrMemory = RwCalloc(1, scrSize, rwMEMHINTDUR_GLOBAL);
    gFldScrSize = cdvd->fileSize;
    scrSize = cdvd->fileSize;

    memcpy(scrMemory, cdvd->fileMemory, (s32)scrSize);

    H_Cdvd_Destroy(cdvd);
}

// FUN_001b7bb0
void func_001b7bb0(void)
{
    HCdvd* request;
    u32 fileSize;
    void* memory;

    request = H_Cdvd_Request("field/script/fuka.bf", HCDVD_FILENORMAL);
    H_Cdvd_ReadSync(request);
    fileSize = request->fileSize;
    memory = D_007CE220 = RwCalloc(1, fileSize, rwMEMHINTDUR_GLOBAL);
    fileSize = request->fileSize;
    memcpy(memory, request->fileMemory, (s32)fileSize);
    H_Cdvd_Destroy(request);
}

// FUN_001b7c40. Read 'dungeonAT.bin' or 'dungeonFES.bin' and copy its content in 'gFldDngFloorsData'
void K_Data_LoadDngFloorsData(u32 scenarioMode)
{
    char buffer[128];
    HCdvd* cdvd;
    u32 fileSize;

    if (scenarioMode == SCENARIO_MODE_JOURNEY)
    {
        sprintf(buffer, "field/table/dungeonAT.bin");
    }
    else
    {
        sprintf(buffer, "field/table/dungeonFES.bin");
    }

    cdvd = H_Cdvd_Request(buffer, HCDVD_FILENORMAL);
    H_Cdvd_ReadSync(cdvd);

    fileSize = cdvd->fileSize;

    K_ASSERT(fileSize < 0x2000, 170);

    fileSize = cdvd->fileSize;
    memcpy((u8*)gFldDngFloorsData, (u8*)cdvd->fileMemory, fileSize);

    H_Cdvd_Destroy(cdvd);
}

// FUN_001b7d00
void func_001b7d00(void)
{
    D_007CE218 = RwCalloc(1, 0x34c, rwMEMHINTDUR_GLOBAL);
    D_007CE214 = (s32)func_0010a770(0, 6, D_007CE218, 2, 0x1ea, 1);
}


// FUN_001b7d60
u32 func_001b7d60(void)
{
    if (D_007CE214 == 0)
    {
        return true;
    }
    if (func_0010a720(D_007CE214) == 0)
    {
        return false;
    }
    D_007CE214 = 0;
    return true;
}

// FUN_001b7dc0
void K_Data_CreateFldBaseMdl()
{
    HCdvd* cdvd;

    cdvd = H_Cdvd_Request("field/base.RMD", HCDVD_FILENORMAL);
    H_Cdvd_ReadSync(cdvd);

    gFldBaseMdl = mdlCreateFromRmdMemory(MODEL_TYPE_FLD,
                                         2000,
                                         cdvd->fileMemory,
                                         cdvd->fileSize,
                                         MDL_READASYNC);

    // ??? never destroying the cdvd
}

// FUN_001b7e30
u32 K_Data_ChkFldBaseMdlStream()
{
    return mdlStreamRead(gFldBaseMdl) != false;
}

/* W415 census recheck: all nine relocations resolve to the same ordered retail targets; the reported callee discrepancy is an offset shift, not a wrong callee. */
// FUN_001b7e60 NONMATCHING
void* func_001b7e60(KwlnTask* task)
{
    FieldLoadWork* work;
    HCdvd* request;
    char buffer[128];

    work = (FieldLoadWork*)task->workData;
    switch (work->state)
    {
    case 0:
        if (work->scenarioMode == 0)
        {
            sprintf(buffer, "field/table/dungeonAT.bin");
        }
        else
        {
            sprintf(buffer, "field/table/dungeonFES.bin");
        }
        request = H_Cdvd_Request(buffer, HCDVD_FILENORMAL);
        work->request = request;
        work->enemyTableRequest = func_001d4360();
        work->state++;
    case 1:
        request = work->request;
        if (request == NULL || H_Cdvd_IsFileLoaded(request) == 0)
        {
            work->request = NULL;
        }
        else
        {
            if (request->fileSize >= 0x2000)
            {
                K_Assert("k_data.c", 0xcd);
            }
            memcpy(gFldDngFloorsData, request->fileMemory,
                   request->fileSize);
            H_Cdvd_Destroy(request);
            work->request = NULL;
        }
        if (work->enemyTableRequest != NULL)
        {
            if (func_001d43e0(work->enemyTableRequest) != 0)
            {
                work->enemyTableRequest = NULL;
            }
        }
        if (work->request == NULL && work->enemyTableRequest == NULL)
        {
            work->state++;
        }
        return KWLNTASK_CONTINUE;
    case 2:
        return KWLNTASK_STOP;
    default:
        return KWLNTASK_CONTINUE;
    }
}

// FUN_001b8000
void func_001b8000(KwlnTask* task)
{
    ((void (*)(void*))(*(void**)((u8*)&rwGlobals + 0x17c)))(task->workData);
}

// FUN_001b8030
KwlnTask* func_001b8030(KwlnTask* parent)
{
    FieldLoadWork* work;
    KwlnTask* task;

    work = (FieldLoadWork*)RwCalloc(1, sizeof(FieldLoadWork),
                                    rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreateWithAutoPriority(parent, 10, "read startup data",
                                          func_001b7e60, func_001b8000, work);
    work->scenarioMode = 0;
    return task;
}

// FUN_001b80c0
KwlnTask* func_001b80c0(KwlnTask* parent)
{
    FieldLoadWork* work;
    KwlnTask* task;

    work = (FieldLoadWork*)RwCalloc(1, sizeof(FieldLoadWork),
                                    rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreateWithAutoPriority(parent, 10, "read startup data",
                                          func_001b7e60, func_001b8000, work);
    work->scenarioMode = 1;
    return task;
}

// FUN_001b8160
void* func_001b8160(void)
{
    char path[128];
    void* result;

    if (K_Fldrc_GetFldPacCdvd() == NULL)
    {
        sprintf(path, "field/table/n%03d_%03d.bin", gMtScene->fldMajorId,
                gMtScene->fldMinorId);
        if (H_Cdvd_FileExists(path) == 0)
        {
            result = NULL;
        }
        else
        {
            result = H_Cdvd_Request(path, HCDVD_FILENORMAL);
        }
    }
    else
    {
        result = (void*)1;
    }
    return result;
}

// FUN_001b81f0
u32 func_001b81f0(HCdvd* request)
{
    char path[76];
    void* memory;
    void* source;
    void* data;
    u32 cachedSize;
    if (request == NULL)
    {
        return true;
    }
    if (K_Fldrc_GetFldPacCdvd() == NULL)
    {
        if (H_Cdvd_IsFileLoaded(request) == 0)
        {
            goto failed;
        }
        memory = (*(void* (**)(u32, u32, u32))D_00960184_abs)(
            1, ((volatile /* Removing this function's qualifier batch loses func_001b81f0 (MATCH nd0 -> MISMATCH nd36, size 512 -> 512) - measured W170. */ HCdvd*)request)->fileSize, rwMEMHINTDUR_GLOBAL);
        FIELD_DATA_AT(K_Field_Get(), 0x1158, void*) = memory;
        memcpy(FIELD_DATA_AT(K_Field_Get(), 0x1158, void*),
               request->fileMemory, *(volatile /* Removing this function's qualifier batch loses func_001b81f0 (MATCH nd0 -> MISMATCH nd36, size 512 -> 512) - measured W170. */ u32*)&request->fileSize);
        data = FIELD_DATA_AT(K_Field_Get(), 0x1158, void*);
        FIELD_DATA_AT(K_Field_Get(), 0x115c, u32) =
            *(u32*)data;
        FIELD_DATA_AT(K_Field_Get(), 0x1160, void*) =
            (u8*)data + 0x20;
        FIELD_DATA_AT(K_Field_Get(), 0x1164, void*) =
            (u8*)FIELD_DATA_AT(K_Field_Get(), 0x1160, void*) +
            *(u32*)data * 0x20;
        H_Cdvd_Destroy(request);
        return true;
    }
    else
    {
        sprintf(path, "field/pack/n%03d_%03d.bin",
                PTR_DAT_007cd540[0], PTR_DAT_007cd540[1]);
        source = H_Cdvd_CacheFindFile(path, &cachedSize);
        if (source != NULL)
        {
            memory = (*(void* (**)(u32, u32, u32))D_00960184_abs)(
                1, *(volatile /* Removing this function's qualifier batch loses func_001b81f0 (MATCH nd0 -> MISMATCH nd36, size 512 -> 512) - measured W170. */ u32*)&cachedSize, rwMEMHINTDUR_GLOBAL);
            FIELD_DATA_AT(K_Field_Get(), 0x1158, void*) = memory;
            memcpy(FIELD_DATA_AT(K_Field_Get(), 0x1158, void*),
                   source, *(volatile /* Removing this function's qualifier batch loses func_001b81f0 (MATCH nd0 -> MISMATCH nd36, size 512 -> 512) - measured W170. */ u32*)&cachedSize);
            data = FIELD_DATA_AT(K_Field_Get(), 0x1158, void*);
            FIELD_DATA_AT(K_Field_Get(), 0x115c, u32) =
                *(u32*)data;
            FIELD_DATA_AT(K_Field_Get(), 0x1160, void*) =
                (u8*)data + 0x20;
            FIELD_DATA_AT(K_Field_Get(), 0x1164, void*) =
                (u8*)FIELD_DATA_AT(K_Field_Get(), 0x1160, void*) +
                *(u32*)data * 0x20;
        }
    }
    return true;

failed:
    return false;
}

// FUN_001b83f0
u16* func_001b83f0(void)
{
    u16* record;
    u32 fallbackMajor;
    u32 fallbackMinor;
    u32 fallbackDay;
    u32 i;

    record = (u16*)FIELD_DATA_AT(K_Field_Get(), 0x1160, void*);
    if (record == NULL)
    {
        return NULL;
    }
    record += (FIELD_DATA_AT(K_Field_Get(), 0x115c, u32) - 1) * 0x10;
    fallbackMajor = 3;
    fallbackMinor = 0x1f;
    fallbackDay = 8;
    i = 0;
    while (i < FIELD_DATA_AT(K_Field_Get(), 0x115c, u32))
    {
        if (func_0017e480(record[0], record[1], fallbackMajor, fallbackMinor) == 1)
        {
            if (record[0] == func_0017d920() &&
                record[1] == func_0017da40() &&
                (s32)(func_0016ef30() & 0xff) < (s32)record[2])
            {
                goto nextRecord;
            }
            if (fallbackMajor == func_0017d920() &&
                fallbackMinor == func_0017da40() &&
                (s32)(func_0016ef30() & 0xff) > (s32)fallbackDay)
            {
                goto nextRecord;
            }
            if (*(u32*)&record[4] == (u32)-1 ||
                func_0016f190(*(u32*)&record[4]) == 1)
            {
                break;
            }
        }
        fallbackMajor = record[0];
        fallbackMinor = record[1];
        fallbackDay = record[2];
nextRecord:
        i++;
        record -= 0x10;
    }
    if (i >= FIELD_DATA_AT(K_Field_Get(), 0x115c, u32))
    {
        record = NULL;
    }
    return record;
}

#pragma push
/* Removing this loses FUN_001b85a0 (MATCH nd0 -> MISMATCH nd14) - measured W161. */
#pragma opt_loop_invariants on
// FUN_001b85a0
u16* func_001b85a0(u32 index)
{
    u16* record;
    u32 emptyCount;
    u16 emptyId;
    record = (u16*)FIELD_DATA_AT(K_Field_Get(), 0x1164, void*);
    emptyCount = 0;
    emptyId = 0xffff;
    for (;;)
    {
        if (emptyCount == index)
        {
            break;
        }
        if (*record == emptyId)
        {
            emptyCount++;
        }
        record += 0x10;
    }
    return record;
}
#pragma pop

// FUN_001b8600
void func_001b8600(void)
{
    if (FIELD_DATA_AT(K_Field_Get(), 0x1158, void*) != NULL)
    {
        RwFree(FIELD_DATA_AT(K_Field_Get(), 0x1158, void*));
        FIELD_DATA_AT(K_Field_Get(), 0x1158, void*) = NULL;
        FIELD_DATA_AT(K_Field_Get(), 0x115c, u32) = 0;
        FIELD_DATA_AT(K_Field_Get(), 0x1160, void*) = NULL;
        FIELD_DATA_AT(K_Field_Get(), 0x1164, void*) = NULL;
    }
}

// FUN_001b8680
void* func_001b8680(void)
{
    char path[128];
    void* result;

    if (K_Fldrc_GetFldPacCdvd() == NULL)
    {
        sprintf(path, "field/script/nm%03d_%03d.bmd", gMtScene->fldMajorId,
                gMtScene->fldMinorId);
        if (H_Cdvd_FileExists(path) == 0)
        {
            result = NULL;
        }
        else
        {
            result = H_Cdvd_Request(path, HCDVD_FILENORMAL);
        }
    }
    else
    {
        result = (void*)1;
    }
    return result;
}

// The `volatile` qualifiers below are the same batch annotated on func_001b81f0:
// HCdvd::fileSize and the cache size-out are written by the CD/DVD driver, and
// removing the batch loses this MATCH (nd0 -> nd18) - measured W198.
// FUN_001b8710
u32 func_001b8710(HCdvd* request)
{
    char path[76];
    void* memory;
    void* source;
    u32 cachedSize;
    if (request == NULL)
    {
        return true;
    }
    if (K_Fldrc_GetFldPacCdvd() == NULL)
    {
        if (H_Cdvd_IsFileLoaded(request) == 0)
        {
            goto failed;
        }
        memory = (*(void* (**)(u32, u32, u32))D_00960184_abs)(
            1, ((volatile HCdvd*)request)->fileSize, rwMEMHINTDUR_GLOBAL);
        FIELD_DATA_AT(K_Field_Get(), 0x1154, void*) = memory;
        memcpy(FIELD_DATA_AT(K_Field_Get(), 0x1154, void*),
               request->fileMemory, *(volatile u32*)&request->fileSize);
        H_Cdvd_Destroy(request);
        return true;
    }
    else
    {
        sprintf(path, "field/pack/nm%03d_%03d.bmd",
                PTR_DAT_007cd540[0], PTR_DAT_007cd540[1]);
        source = H_Cdvd_CacheFindFile(path, &cachedSize);
        if (source != NULL)
        {
            memory = (*(void* (**)(u32, u32, u32))D_00960184_abs)(
                1, *(volatile u32*)&cachedSize, rwMEMHINTDUR_GLOBAL);
            FIELD_DATA_AT(K_Field_Get(), 0x1154, void*) = memory;
            memcpy(FIELD_DATA_AT(K_Field_Get(), 0x1154, void*),
                   source, *(volatile u32*)&cachedSize);
        }
    }
    return true;

failed:
    return false;
}

// FUN_001b8870
void func_001b8870(void)
{
    if (FIELD_DATA_AT(K_Field_Get(), 0x1154, void*) != NULL)
    {
        RwFree(FIELD_DATA_AT(K_Field_Get(), 0x1154, void*));
        FIELD_DATA_AT(K_Field_Get(), 0x1154, void*) = NULL;
    }
}

// FUN_001b88d0
void* func_001b88d0(void)
{
    char path[128];
    void* result;

    if (K_Fldrc_GetFldPacCdvd() == NULL)
    {
        sprintf(path, "field/script/ns%03d_%03d.bf", gMtScene->fldMajorId,
                gMtScene->fldMinorId);
        if (H_Cdvd_FileExists(path) == 0)
        {
            result = NULL;
        }
        else
        {
            result = H_Cdvd_Request(path, HCDVD_FILENORMAL);
        }
    }
    else
    {
        result = (void*)1;
    }
    return result;
}

// The `volatile` qualifiers below are the same batch annotated on func_001b81f0:
// HCdvd::fileSize and the cache size-out are written by the CD/DVD driver, and
// removing the batch loses this MATCH (nd0 -> nd18) - measured W198.
// FUN_001b8960
u32 func_001b8960(HCdvd* request)
{
    char path[76];
    void* memory;
    void* source;
    u32 cachedSize;
    if (request == NULL)
    {
        return true;
    }
    if (K_Fldrc_GetFldPacCdvd() == NULL)
    {
        if (H_Cdvd_IsFileLoaded(request) == 0)
        {
            goto failed;
        }
        memory = (*(void* (**)(u32, u32, u32))D_00960184_abs)(
            1, ((volatile HCdvd*)request)->fileSize, rwMEMHINTDUR_GLOBAL);
        FIELD_DATA_AT(K_Field_Get(), 0x114c, void*) = memory;
        FIELD_DATA_AT(K_Field_Get(), 0x1150, u32) = request->fileSize;
        memcpy(FIELD_DATA_AT(K_Field_Get(), 0x114c, void*),
               request->fileMemory, *(volatile u32*)&request->fileSize);
        H_Cdvd_Destroy(request);
        return true;
    }
    else
    {
        sprintf(path, "field/pack/ns%03d_%03d.bf",
                PTR_DAT_007cd540[0], PTR_DAT_007cd540[1]);
        source = H_Cdvd_CacheFindFile(path, &cachedSize);
        if (source != NULL)
        {
            memory = (*(void* (**)(u32, u32, u32))D_00960184_abs)(
                1, *(volatile u32*)&cachedSize, rwMEMHINTDUR_GLOBAL);
            FIELD_DATA_AT(K_Field_Get(), 0x114c, void*) = memory;
            FIELD_DATA_AT(K_Field_Get(), 0x1150, u32) = cachedSize;
            memcpy(FIELD_DATA_AT(K_Field_Get(), 0x114c, void*),
                   source, *(volatile u32*)&cachedSize);
        }
    }
    return true;

failed:
    return false;
}
 

// FUN_001b8ae0
void func_001b8ae0(void)
{
    if (FIELD_DATA_AT(K_Field_Get(), 0x114c, void*) != NULL)
    {
        RwFree(FIELD_DATA_AT(K_Field_Get(), 0x114c, void*));
        FIELD_DATA_AT(K_Field_Get(), 0x114c, void*) = NULL;
    }
}

#pragma push
/* Removing this loses FUN_001b8b40 (MATCH nd0 -> MISMATCH nd14) - measured W161. */
#pragma opt_loop_invariants on
// FUN_001b8b40
void func_001b8b40(void)
{
    char path[128];
    HCdvd* request;
    s16* record;
    s32 recordCount;
    u32 fileSize;
    u32 allocSize;
    const u16 emptyId = 0xffff;
    s32 i;

    sprintf(path, "field/table/comutbl.bin");
    if (H_Cdvd_FileExists(path) == 0)
    {
        return;
    }
    request = H_Cdvd_Request(path, HCDVD_FILENORMAL);
    H_Cdvd_ReadSync(request);
    allocSize = ((volatile /* Removing this qualifier loses func_001b8b40 (MATCH nd0 -> MISMATCH nd8, size 244 -> 244) - measured W170. */ HCdvd*)request)->fileSize;
    sComuTable = (s16*)(*(void* (**)(u32, u32, u32))D_00960184_abs)(
        1, allocSize, rwMEMHINTDUR_GLOBAL);
    fileSize = request->fileSize;
    memcpy(sComuTable, request->fileMemory, (s32)fileSize);
    recordCount = request->fileSize >> 7;
    sComuTableRecords = recordCount;
    record = sComuTable;
    i = 0;
    while (i < recordCount)
    {
        if (*(u16*)record == emptyId)
        {
            sComuTableEmptyRecords++;
        }
        i++;
        record += 0x40;
    }
    H_Cdvd_Destroy(request);
}
#pragma pop

// FUN_001b8c40
void func_001b8c40(void)
{
    char path[128];
    HCdvd* request;
    u32 fileSize;
    void* memory;

    sprintf(path, "field/script/npccomu.bf");
    if (H_Cdvd_FileExists(path) == 0)
    {
        return;
    }
    request = H_Cdvd_Request(path, HCDVD_FILENORMAL);
    H_Cdvd_ReadSync(request);
    fileSize = request->fileSize;
    memory = sNpcComuScript = RwCalloc(1, fileSize, rwMEMHINTDUR_GLOBAL);
    sNpcComuScriptSize = request->fileSize;
    fileSize = request->fileSize;
    memcpy(memory, request->fileMemory, (s32)fileSize);
    H_Cdvd_Destroy(request);
}

// FUN_001b8cf0
void func_001b8cf0(u8* work)
{
    if (*(void**)(work + 0x14) != NULL)
    {
        *(void**)(work + 0x14) = NULL;
        ((void (*)(void*))(*(void**)((u8*)&rwGlobals + 0x17c)))(NULL);
    }
    if (*(void**)(work + 0x1c) != NULL)
    {
        ((void (*)(void*))(*(void**)((u8*)&rwGlobals + 0x17c)))(
            *(void**)(work + 0x1c));
        *(void**)(work + 0x1c) = NULL;
    }
}

#pragma push
/* Removing this loses FUN_001b8d60 (MATCH nd0 -> MISMATCH nd20) - measured W161. */
#pragma opt_loop_invariants on
// FUN_001b8d60
u16* func_001b8d60(u32 index)
{
    u16* record;
    u32 i;
    u32 emptyCount;
    u32 recordCount;
    u16 emptyId;

    record = (u16*)sComuTable;
    emptyCount = 0;
    i = 0;
    recordCount = sComuTableRecords;
    emptyId = 0xffff;
    while (i < recordCount)
    {
        if (emptyCount == index)
        {
            break;
        }
        if (record[0] == emptyId)
        {
            emptyCount++;
        }
        i++;
        record += 0x40;
    }
    return record;
}
#pragma pop

// FUN_001b8db0 NONMATCHING
s16* func_001b8db0(s16* table)
{
    s16* record;
    s16 chosenMajor;
    s16 chosenMinor;
    u16 chosenDay;
    u32 count;
    u32 i;
    u32 slot;
    u32 day;

    if (table == NULL)
    {
        return NULL;
    }
    count = 0;
    record = table;
    while (*record != -1)
    {
        count++;
        record += 0x40;
    }
    chosenMajor = 3;
    chosenMinor = 0x1f;
    chosenDay = 8;
    record = table + count * 0x40;
    i = 0;
    while (i < count)
    {
        record -= 0x40;
        if (puGpffffa850 != NULL &&
            (u16)puGpffffa850[0] == (u16)record[0x30] &&
            (u16)puGpffffa850[1] == (u16)record[0x31] &&
            func_0017e480((u16)record[1], (u16)record[2], 3, 0x1f) != 0)
        {
            if ((u16)record[1] == func_0017d920() &&
                (u16)record[2] == func_0017da40() &&
                (day = func_0016ef30() & 0xff) < chosenDay)
            {
                chosenMajor = record[1];
                chosenMinor = record[2];
                chosenDay = record[3];
            }
            else
            {
                for (slot = 0; slot < 0x0f; slot++)
                {
                    if (record[slot + 9] == -1 ||
                        func_0016f190((u16)record[slot + 9]) != 1)
                    {
                        break;
                    }
                }
                if (slot == 0x0f)
                {
                    for (slot = 0; slot < 7; slot++)
                    {
                        if (record[slot + 2] == -1 ||
                            func_0016f190((u16)record[slot + 2]) != 1)
                        {
                            break;
                        }
                    }
                    if (slot < 7)
                    {
                        return record;
                    }
                }
            }
        }
        chosenMajor = record[1];
        chosenMinor = record[2];
        chosenDay = record[3];
        i++;
    }
    (void)chosenMajor;
    (void)chosenMinor;
    return NULL;
}

// FUN_001b8fd0
u32 func_001b8fd0(const u8* unit, const u8* records, u32 byteSize)
{
    const u8* record;
    u32 count;
    u32 i;
    u32 result;
    count = byteSize / 0x0c;
    record = records + count * 0x0c - 0x0c;
    result = 0;
    i = 0;
    while (i < count)
    {
        if (*(const u32*)(record + 0) == 1)
        {
            result = *(const u32*)(record + 4);
            break;
        }
        else if (*(const u32*)(record + 0) == 2)
        {
            if (func_0016f190(*(const u32*)(record + 8)) == 1)
            {
                result = *(const u32*)(record + 4);
                break;
            }
        }
        else if (*(const u32*)(record + 0) == 3)
        {
            if ((s32)*(const u32*)(record + 8) ==
                (s8)func_0016dba0(*(const s16*)(unit + 0x6c)))
            {
                result = *(const u32*)(record + 4);
                break;
            }
        }
        i++;
    }
    return result;
}
// W419 rejected probes (verify.py; nd/object/window and nd/object rate):
// func_001b7e60 removing the not-loaded request assignment: 96/408/416 (0.2353) -> 128/396/416 (0.3232).