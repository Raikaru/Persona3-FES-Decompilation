#include "h_cdvd.h"
#include "h_dbprt.h"
#include "sce/libcdvd.h"
#include "rw/rwplcore.h"
#include "temporary.h"

typedef struct HCdvdStreamContext HCdvdStreamContext;
typedef struct HCdvdStreamSlot HCdvdStreamSlot;
typedef struct HCdvdStreamPosition HCdvdStreamPosition;

/*
 * The CDVD callbacks are also used by the ADX/CRI streaming backends.  These
 * records are intentionally described by their retail offsets: the backend
 * hands us opaque records, but the callbacks below operate on the fields
 * shown here (rather than relying on untyped address arithmetic).
 */
struct HCdvdStreamContext
{
    u32 reserved00;
    u32 count; // 0x04
    u8 reserved08[0x0c];
    void* callback14;
    void* callback18;
    u8 reserved1c[0x0c];
    void* callback28;
    void* callback2c;
    void* callback30;
    void* callback34;
    void* callback38;
    u8 reserved3c[8];
    void* callback44;
    u8 reserved48[4];
    void* callback4c;
    u8 reserved50[8];
    HCdvdStreamSlot* slots; // 0x58
};

struct HCdvdStreamSlot
{
    u8 reserved00[0x50];
    HCdvdStreamContext* context; // 0x50
    u8 reserved54[0x14];
    u8* source; // 0x68
    u32 sourceStride; // 0x6c
    u8 reserved70[0x1c];
    u32 capacity; // 0x8c
    u32 cursor; // 0x90
    u8 reserved94[0x64];
    u8* fileMemory; // 0xf8
    u32 fileSize; // 0xfc
    u32 fileOffset; // 0x100
    u8 reserved104[0x0c];
};

struct HCdvdStreamPosition
{
    s64 position;
    u32 unused0;
    u32 unused1;
};

extern u32 D_00960184[];
extern u32 jtbl_0096017C[];
extern u32 D_0096013C[];
extern const char* D_005CDD80[];
extern const char* D_005CDDF0[];
extern const char* D_005CE590[];
extern const char* D_005CE780[];
extern const char D_005CE970[];
extern const char D_005CE988[];

extern void* func_004bfd50(void* key);
extern s32 func_004bf6e0(void* context, s32 count, void* key, void* callbackData);
extern void func_004bfbb0(s64 key);
extern void* func_004c0fd0(s32 count, void* source, s32 stride, void* key0, void* key1);
extern void func_004c0230(void* context);
extern void* func_0054d390(void);
extern void func_0054b2e8(void* handle, const char* name);
extern void func_0054d0a0(void* handle, const char* name);
extern void* func_0053b868(void* source, const char* name, const char* table, void* callback);
extern s32 func_00508670(const char* path, u32 mode, u32 flags);
#pragma alias func_00508670_2 func_00508670
extern s32 func_00508670_2(const char* path, u32 mode);
extern s32 func_00508a78(s32 fd, s32 value, s32 origin);
extern void func_00508900(s32 fd);
extern s32 func_00508cb8(s32 fd, const void* dst, u32 size);
extern s32 func_00508f28(s32 fd, void* dst, u32 size);
extern void func_0050a888(const char* path, void* unused);
extern void func_00505e48(const char* message, ...);
extern s32 func_00566b08(void* output, const void* source);
extern s32 func_0053c268(void* source);
extern void func_00580378(void* handle, const char* name);
extern void func_00584290(void* handle, const char* name);

#define HCDVD_ALLOC(count, size, flags) \
    (*(void* (**)(u32, u32, u32))D_00960184)((count), (size), (flags))
#define HCDVD_FREE(ptr) (*(void (**)(void*))jtbl_0096017C)((ptr))
extern void* func_004bfc80(void* context);
extern void func_00102030(void* requestData, void* fileMemory, u32 fileSize,
                          const char* path);

extern void func_00101100(const char* path, char* fileNameDst, char* dirDst);
extern void func_00101520(const char* dir);
extern void func_00101e30(void* requestData);
extern ADXF func_0053c910(const char* path, s32 mode);
extern void func_0053cdd0(ADXF adxf);
extern u32 func_0053d380(ADXF adxf, u32 sectorCount, void* buffer);
extern u32 func_0053d968(ADXF adxf);
extern u32 func_0053db90(ADXF adxf);

#define HCDVD_CACHE_MAX 256

static HCdvd sCdvdListHead;                    // 007e0380. Dummy head
static HCdvdCache sCdvdCache[HCDVD_CACHE_MAX]; // 007d6f80

static const char* sCdvdBtlDirectories[] = {
    "\\",
    "\\BATTLE\\",
    "\\BATTLE\\CUTIN\\",
    "\\BATTLE\\CUTIN\\C71_C80_L_L_1\\",
    "\\BATTLE\\CUTIN\\C82_L_L_1\\",
    "\\BATTLE\\CUTIN\\C90_L_L_1\\",
    "\\BATTLE\\CUTIN\\C93_L_L_1\\",
    "\\BATTLE\\CUTIN\\EPL\\",
    "\\BATTLE\\CUTIN\\MIXRAID\\",
    "\\BATTLE\\EFFECT\\",
    "\\BATTLE\\PANEL\\",
    "\\BATTLE\\RESULT\\",
    "\\BATTLE\\SHUFFLE\\",
    "\\MODEL\\",
    "\\MODEL\\FACILITYP\\",
    "\\MODEL\\FIELD\\",
    "\\MODEL\\NPC\\",
    "\\MODEL\\PACK\\",
    "\\MODEL\\PERSONA\\",
    "\\MODEL\\SYMBOL\\",
    "\\MODEL\\WEAPON\\",
    "\\SKILL\\",
    "\\SND_BENC\\",
    "\\SND_BENC\\BOSS\\",
    "\\SND_BENC\\PANEL\\",
    ""
};


// FUN_001007f0
void H_Cdvd_001007f0()
{
}

// FUN_00100800
void H_Cdvd_Init()
{
    s32 i;
    HCdvdCache* cache;

    sceCdInit(SCECdINIT);
    sceCdMmode(SCECdDVD);
    sceCdDiskReady(0);

    sCdvdListHead.prev = NULL;
    sCdvdListHead.next = NULL;
    sCdvdListHead.fileMemory = NULL;
    sCdvdListHead.fileSize = 0;
    sCdvdListHead.hasExternalMemory = false;

    i = 0;
    cache = sCdvdCache;
    for (; i < HCDVD_CACHE_MAX; i++)
    {
        cache[i].isValid = false;
    }

    sCdvdListHead.adxf = NULL;
}

// FUN_001008b0
u32 H_Cdvd_FileExists(const char* path)
{
    char unusedUppercasePath[256];
    char fileName[256];
    char dir[256];
    char uppercasePath[256];
    ADXF adxf;

    H_Dbprt_FmtLog(" Exist %s\n", path);
    H_Cdvd_BuildPathUppercase(path, unusedUppercasePath);
    H_Cdvd_BuildPathUppercase(path, uppercasePath);
    func_00101100(uppercasePath, fileName, dir);
    func_00101520(dir);

    adxf = func_0053c910(fileName, 0);
    if (adxf == NULL)
    {
        H_Dbprt_FmtLog(" FALSE \n");
        return false;
    }

    func_0053cdd0(adxf);
    H_Dbprt_FmtLog(" TRUE \n");
    return true;
}

// FUN_00100980 NONMATCHING
void H_Cdvd_Read()
{
    HCdvd* cdvd;
    HCdvd* next;
    HCdvdCache* cache;
    s32 i;
    u32 readResult;

    cdvd = sCdvdListHead.next;
    while (cdvd != NULL)
    {
        if (cdvd->readState == HCDVD_READ_COMPLETE)
        {
            goto complete;
        }
        if (cdvd->readState == HCDVD_READ_FINALIZING)
        {
            goto finalizing;
        }
        if (cdvd->readState == HCDVD_READ_IN_PROGRESS)
        {
            goto inProgress;
        }
        if (cdvd->readState == HCDVD_READ_OPENED)
        {
            goto opened;
        }
        if (!cdvd->readState)
        {
            goto queued;
        }
        goto complete;

queued:
        cdvd->readPollCount = 0;
        func_00101520(cdvd->dir);
        cdvd->adxf = func_0053c910(cdvd->fileName, 0);
        if (cdvd->adxf == NULL)
        {
            return;
        }

        cdvd->readByteSize = cdvd->adxf->fileSize;
        cdvd->fileSize = cdvd->readByteSize;
        cdvd->readState = HCDVD_READ_OPENED;

opened:
        if (cdvd->fileMemory == NULL)
        {
            if (cdvd->fileMode == HCDVD_FILENORMAL)
            {
                cdvd->unalignedFileMemory =
                    RwMalloc(func_0053d968(cdvd->adxf) * 0x800 + 0x40, rwMEMHINTDUR_GLOBAL);
            }
            else
            {
                cdvd->unalignedFileMemory =
                    RwMalloc(func_0053d968(cdvd->adxf) * 0x800 + 0x140, rwMEMHINTDUR_GLOBAL);
            }

            if (cdvd->unalignedFileMemory == NULL)
            {
                return;
            }

            cdvd->fileMemory =
                (void*)(((uintptr_t)cdvd->unalignedFileMemory + 0x3f) & ~(uintptr_t)0x3f);
        }

        readResult = func_0053d380(cdvd->adxf, func_0053d968(cdvd->adxf), cdvd->fileMemory);
        if (readResult != func_0053d968(cdvd->adxf))
        {
            func_0053cdd0(cdvd->adxf);
            cdvd->adxf = NULL;

            if (cdvd->hasExternalMemory == false)
            {
                RwFree(cdvd->unalignedFileMemory);
                cdvd->fileMemory = NULL;
                cdvd->unalignedFileMemory = NULL;
            }

            cdvd->readState = HCDVD_READ_QUEUED;
            return;
        }

        cdvd->readState = HCDVD_READ_IN_PROGRESS;

inProgress:
        cdvd->readPollCount++;
        readResult = func_0053db90(cdvd->adxf);
        if (readResult == HCDVD_READ_FINALIZING)
        {
            cdvd->readState = HCDVD_READ_FINALIZING;
            if (cdvd->fileMode != HCDVD_FILENORMAL)
            {
                memset((u8*)cdvd->fileMemory + cdvd->readByteSize, 0, 0x100);
            }
        }
        else if (readResult == HCDVD_READ_COMPLETE)
        {
            func_0053cdd0(cdvd->adxf);
            cdvd->adxf = NULL;
            cdvd->readState = HCDVD_READ_QUEUED;

            if (cdvd->hasExternalMemory == false)
            {
                RwFree(cdvd->unalignedFileMemory);
                cdvd->fileMemory = NULL;
                cdvd->unalignedFileMemory = NULL;
            }

            return;
        }

        if (cdvd->readState != HCDVD_READ_FINALIZING)
        {
            goto complete;
        }

finalizing:
        func_00101e30(&cdvd->hasExternalMemory);
        cdvd->readState = HCDVD_READ_COMPLETE;
        func_0053cdd0(cdvd->adxf);
        cdvd->adxf = NULL;

complete:
        if (cdvd->readState != HCDVD_READ_COMPLETE)
        {
            return;
        }

        next = cdvd->next;
        cdvd->refCount -= cdvd->pendingDestroyCount;
        cdvd->pendingDestroyCount = 0;
        if (cdvd->refCount < 1)
        {
            cdvd->prev->next = cdvd->next;
            if (cdvd->next != NULL)
            {
                cdvd->next->prev = cdvd->prev;
            }

            if (cdvd->fileMemory != NULL && cdvd->hasExternalMemory == false)
            {
                RwFree(cdvd->unalignedFileMemory);
                cdvd->fileMemory = NULL;
                cdvd->unalignedFileMemory = NULL;
            }

            for (i = 0, cache = sCdvdCache; i < HCDVD_CACHE_MAX; i++)
            {
                if (cache[i].isValid && cache[i].requestData == &cdvd->hasExternalMemory)
                {
                    cache[i].isValid = false;
                }
            }

            if (cdvd->adxf != NULL)
            {
                func_0053cdd0(cdvd->adxf);
                cdvd->adxf = NULL;
            }

            RwFree(cdvd);
        }

        cdvd = next;
    }
}

// FUN_00100d80
HCdvd* H_Cdvd_Request(const char* path, u32 fileMode)
{
    HCdvd* previous;
    HCdvd* next;
    HCdvd* cdvd;
    char uppercasePath[256];

    H_Dbprt_FmtLog("REQ CDVD %s", path);
    previous = &sCdvdListHead;
    H_Cdvd_BuildPathUppercase(path, uppercasePath);

    if (*(HCdvd**)(uintptr_t)0x007e0384 != NULL)
    {
        while (true)
        {
            if (strcmp(uppercasePath, previous->path) == 0)
            {
                previous->refCount++;
                return previous;
            }

            next = previous->next;
            if (next == NULL)
            {
                break;
            }

            previous = next;
        }
    }

    cdvd = (*(void* (**)(u32, u32, u32))(uintptr_t)0x00960184)(
        1, sizeof(HCdvd), rwMEMHINTDUR_GLOBAL);
    H_Cdvd_BuildPathUppercase(path, cdvd->path);
    H_Cdvd_BuildVolumePaths(cdvd->path, cdvd->fileName, cdvd->dir);

    cdvd->readState = HCDVD_READ_QUEUED;
    previous->next = cdvd;
    cdvd->prev = previous;
    cdvd->next = NULL;
    cdvd->fileMemory = NULL;
    cdvd->hasExternalMemory = false;
    cdvd->fileMode = fileMode;
    cdvd->refCount = 1;
    cdvd->adxf = NULL;
    return cdvd;
}


// FUN_00100ec0 NONMATCHING
u32 H_Cdvd_Destroy(HCdvd* cdvd)
{
    HCdvd* prev;
    HCdvd* next;
    HCdvdCache* cache;
    s32 i;

    if (cdvd->readState != HCDVD_READ_QUEUED)
    {
        cdvd->pendingDestroyCount++;
        return true;
    }

    cdvd->refCount--;
    if (cdvd->refCount > 0)
    {
        return true;
    }

    prev = cdvd->prev;
    next = cdvd->next;
    prev->next = next;
    if (next != NULL)
    {
        next->prev = prev;
    }

    if (cdvd->fileMemory != NULL && cdvd->hasExternalMemory == false)
    {
        (*(void (**)(void*))((u8*)&rwGlobals + 0x17c))(cdvd->unalignedFileMemory);
        cdvd->fileMemory = NULL;
        cdvd->unalignedFileMemory = NULL;
    }

    for (i = 0, cache = sCdvdCache; i < HCDVD_CACHE_MAX; i++)
    {
        if (cache[i].isValid && cache[i].requestData == &cdvd->hasExternalMemory)
        {
            cache[i].isValid = false;
        }
    }

    if (cdvd->adxf != NULL)
    {
        func_0053cdd0(cdvd->adxf);
        cdvd->adxf = NULL;
    }

    (*(void (**)(void*))((u8*)&rwGlobals + 0x17c))(cdvd);
    return true;
}


// FUN_00101010 NONMATCHING
void H_Cdvd_BuildPathUppercase(const char* src, char* dst)
{
    char currChar;
    char* pathBase;
    size_t basePathLen;
    u32 i;
    char* dstPtr;
    s32 slash;
    s32 backslash;

    pathBase = "VOL:\\";
    strcpy(dst, pathBase);
    basePathLen = strlen(pathBase);
    i = 0;
    dstPtr = dst + basePathLen;
    slash = 0x2f;
    backslash = 0x5c;

    while (i < 0xff)
    {
        currChar = src[i];
        if (currChar == '\0')
        {
            dst[i + basePathLen] = '\0';
            return;
        }

        if (currChar == slash)
        {
            dstPtr[i] = backslash;
        }
        else if (currChar >= 'a' && currChar <= 'z')
        {
            dstPtr[i] = currChar - 0x20;
        }
        else
        {
            dstPtr[i] = currChar;
        }

        i++;
    }
}

// FUN_00101240 NONMATCHING
void H_Cdvd_BuildVolumePaths(const char* path, char* fileNameDst, char* dirDst)
{
    char reverseFileName[256];
    char normalizedDir[256];
    u32 pathLength;
    u32 fileNameLength;
    u32 i;

    strcpy(dirDst, path);
    pathLength = strlen(dirDst);
    for (i = 1; i < pathLength; i++)
    {
        reverseFileName[i] = dirDst[pathLength - i];
        if (reverseFileName[i] == '\\')
        {
            dirDst[pathLength - i + 1] = '\0';
            reverseFileName[i] = '\0';
            break;
        }
    }

    H_Cdvd_NormalizePath(dirDst, normalizedDir);
    strcpy(fileNameDst, "VOL:");
    for (i = 0; i < 0xc8 && sCdvdBtlDirectories[i][0] != '\0'; i++)
    {
        if (strcmp(sCdvdBtlDirectories[i], &normalizedDir[4]) == 0)
        {
            strcpy(fileNameDst, "BTL:");
        }
    }

    fileNameLength = strlen(&reverseFileName[1]);
    for (i = 0; i < fileNameLength; i++)
    {
        fileNameDst[strlen(fileNameDst) + fileNameLength - i - 1] =
            reverseFileName[i + 1];
    }
    fileNameDst[strlen(fileNameDst) + fileNameLength] = '\0';
}

// FUN_001013f0 NONMATCHING
void H_Cdvd_NormalizePath(const char* src, char* dst)
{
    s32 scanIndex;
    s32 readIndex;
    s32 writeIndex;
    const char* sourcePtr;
    s32 currChar;
    s32 dot;
    s32 backslash;
    s32 slash;

    writeIndex = 0;
    readIndex = 0;
    backslash = 0x5c;
    slash = 0x2f;
    dot = 0x2e;
    while (readIndex < 0xfd)
    {
        sourcePtr = src + readIndex;
        currChar = sourcePtr[0];
        if (currChar == '\0')
        {
            dst[writeIndex] = '\0';
            return;
        }

        if (currChar == dot && sourcePtr[1] == dot &&
            sourcePtr[2] == backslash)
        {
            goto removeParent;
        }
        if (currChar != dot || sourcePtr[1] != dot ||
            sourcePtr[2] != slash)
        {
            goto checkSingle;
        }

removeParent:
        readIndex += 2;
        if (writeIndex >= 3)
        {
            for (scanIndex = writeIndex - 2; scanIndex >= 0; scanIndex--)
            {
                if (dst[scanIndex] == backslash || dst[scanIndex] == slash)
                {
                    writeIndex = scanIndex + 1;
                    break;
                }
            }
        }
        goto advance;

checkSingle:
        if (currChar == dot && sourcePtr[1] == backslash)
        {
            goto incrementRead;
        }
        if (currChar != dot || sourcePtr[1] != slash)
        {
            goto writeCharacter;
        }
incrementRead:
        readIndex++;
        goto advance;

writeCharacter:
        dst[writeIndex] = currChar;
        writeIndex++;

advance:
        readIndex++;
    }
}

// FUN_001016b0
u32 H_Cdvd_IsFileLoaded(HCdvd* cdvd)
{
    return cdvd->readState == 4;
}

// FUN_00102100. Get file memory of a specific file in an archive (.PAC, .PAK or .BIN)
void* H_Cdvd_ArchiveGetFile(HCdvd* cdvd, s32 fileIdx, u32* fileSize)
{
    ArchiveEntryHeader entryHeader;
    uintptr_t fileMemoryAddr;
    s32 alignedSize;
    s32 i;

    fileMemoryAddr = (uintptr_t)cdvd->fileMemory;
    for (i = 0; i < fileIdx; i++)
    {
        memcpy(&entryHeader, (void*)fileMemoryAddr, sizeof(ArchiveEntryHeader));

        fileMemoryAddr += sizeof(ArchiveEntryHeader);

        alignedSize = entryHeader.fileSize + 0x3f;
        alignedSize /= 0x40;
        
        fileMemoryAddr += (alignedSize * 0x40);
    }

    memcpy(&entryHeader, (void*)fileMemoryAddr, sizeof(ArchiveEntryHeader));
    *fileSize = entryHeader.fileSize;

    return (void*)(fileMemoryAddr + sizeof(ArchiveEntryHeader));
}

// FUN_001021c0
void* H_Cdvd_CacheFindFile(const char* path, u32* fileSize)
{
    char uppercasePath[256];
    char normalizedPath[256];
    char cacheNormalizedPath[256];
    s32 i;

    if (path == (char*)1)
    {
        return NULL;
    }

    H_Cdvd_BuildPathUppercase(path, uppercasePath);
    H_Cdvd_NormalizePath(uppercasePath, normalizedPath);

    for (i = 0; i < HCDVD_CACHE_MAX; i++)
    {
        if (sCdvdCache[i].isValid)
        {
            H_Cdvd_NormalizePath(sCdvdCache[i].path, cacheNormalizedPath);

            if (strcmp(cacheNormalizedPath, normalizedPath) == 0)
            {
                *fileSize = sCdvdCache[i].fileSize;
                return sCdvdCache[i].fileMemory;
            }
        }
    }

    return NULL;
}

// FUN_001023a0. Synchronous read
void H_Cdvd_ReadSync(HCdvd* cdvd)
{
    while (true)
    {
        if (!H_Cdvd_IsFileLoaded(cdvd))
        {
            H_Cdvd_Read();
        }
        else
        {
            break;
        }
    }
}

#pragma push
#pragma opt_loop_invariants on
// FUN_00102650
void H_Cdvd_CacheAdd(void* requestData, void* fileMemory, u32 fileSize, const char* path)
{
    s32 i;
    HCdvdCache* curr;
    u32 offset;

    i = 0;
    for (; i < HCDVD_CACHE_MAX; i++)
    {
        offset = i * sizeof(HCdvdCache);
        curr = (HCdvdCache*)((u8*)sCdvdCache + offset);
        if (!curr->isValid)
        {
            curr->isValid = true;
            sCdvdCache[i].requestData = requestData;
            sCdvdCache[i].fileMemory = fileMemory;
            sCdvdCache[i].fileSize = fileSize;
            sCdvdCache[i].unk_110 = 0;
            memcpy(curr->path, path, 128);
            return;
        }
    }
}
#pragma pop

// FUN_00102870
void H_Cdvd_CacheRemove(void* requestData)
{
    s32 i;
    HCdvdCache* cache;
    HCdvdCache* curr;

    i = 0;
    cache = sCdvdCache;
    for (; i < HCDVD_CACHE_MAX; i++)
    {
        curr = &cache[i];

        if (curr->isValid && curr->requestData == requestData)
        {
            curr->isValid = false;
        }
    }
}

// FUN_00101100 NONMATCHING
void func_00101100(const char* path, char* fileNameDst, char* dirDst)
{
    char reversedName[257];
    size_t pathLength;
    size_t nameLength;
    size_t i;
    size_t slashOffset;

    strcpy(fileNameDst, "VOL:");
    strcpy(dirDst, path);
    pathLength = strlen(dirDst);
    slashOffset = pathLength;
    while (slashOffset > 0)
    {
        if (dirDst[slashOffset - 1] == '\\' || dirDst[slashOffset - 1] == '/')
        {
            break;
        }
        slashOffset--;
    }

    if (slashOffset == 0)
    {
        reversedName[0] = '\0';
    }
    else
    {
        strcpy(reversedName, dirDst + slashOffset);
        dirDst[slashOffset] = '\0';
    }


    nameLength = strlen(reversedName);
    for (i = 0; i < nameLength; i++)
    {
        fileNameDst[4 + nameLength - i - 1] = reversedName[i];
    }
    fileNameDst[4 + nameLength] = '\0';
}

// FUN_00101520 NONMATCHING
void func_00101520(const char* dir)
{
    char normalized[256];
    s16 i;
    const char* source;

    H_Cdvd_NormalizePath(dir, normalized);
    i = 0;
    while (i < 300)
    {
        source = D_005CDD80[i];
        if (source[0] == '\0')
        {
            goto secondTable;
        }
        if (strcmp(source, normalized + 4) == 0)
        {
            do
            {
            } while (func_00566b08((void*)0x007d4780, D_005CDDF0[i]) != 0);
            return;
        }
        i++;
    }

secondTable:
    i = 0;
    while (i < 300)
    {
        source = D_005CE590[i];
        if (source[0] == '\0')
        {
            printf(D_005CE970, normalized + 4);
            return;
        }
        if (strcmp(source, normalized + 4) == 0)
        {
            while (true)
            {
                s32 result = func_00566b08((void*)0x007d4784,
                                            D_005CE780[i]);
                if (result == 0)
                {
                    return;
                }
                printf(D_005CE988, result);
            }
        }
        i++;
    }
}
// FUN_001019A0
static HCdvdStreamSlot* H_Cdvd_StreamGetSlot(HCdvdStreamContext* context, u32 index)
{
    HCdvdStreamSlot* result;

    if (index < context->count)
    {
        result = &context->slots[index];
    }
    else
    {
        result = NULL;
    }
    return result;
}

// FUN_00101800
static void H_Cdvd_StreamNoop(void)
{
}

// FUN_001018a0
static u32 H_Cdvd_StreamComplete(HCdvdStreamSlot* slot)
{
    u8* data = (u8*)slot + 0x70;
    return -(*(s32*)(data + 0x8c) <= *(s32*)(data + 0x90));
}

// FUN_001016d0
s32 func_001016d0(void* unused, void* slotData, uintptr_t pathOrMode)
{
    char uppercasePath[256];
    char normalizedPath[256];
    char cachePath[256];
    s32 i;
    HCdvdStreamSlot* slot = (HCdvdStreamSlot*)slotData;

    (void)unused;
    if (pathOrMode == 1)
    {
        return 2;
    }

    H_Cdvd_BuildPathUppercase((const char*)pathOrMode, uppercasePath);
    H_Cdvd_NormalizePath(uppercasePath, normalizedPath);
    for (i = 0; i < HCDVD_CACHE_MAX; i++)
    {
        if (!sCdvdCache[i].isValid)
        {
            continue;
        }
        H_Cdvd_NormalizePath(sCdvdCache[i].path, cachePath);
        if (strcmp(cachePath, normalizedPath) == 0)
        {
            memcpy((u8*)slot + 0x70, &sCdvdCache[i], sizeof(HCdvdCache));
            *(u32*)((u8*)slot + 0x100) = 0;
            *(u64*)((u8*)slot + 0x00) = *(s32*)((u8*)slot + 0xfc);
            *(u64*)((u8*)slot + 0x20) = 0;
            *(u64*)((u8*)slot + 0x10) = 0;
            *(u32*)((u8*)slot + 0x30) = 0;
            *(u32*)((u8*)slot + 0x38) = 2;
            *(u32*)((u8*)slot + 0x3c) = 1;
            return 1;
        }
    }
    return 2;
}

// FUN_00101810
u32 func_00101810(void* slotData, void* dst, u32 size)
{
    struct HCdvdStreamData
    {
        u8 reserved[0x88];
        u8* fileMemory;
        s32 fileSize;
        s32 fileOffset;
    } *data;
    u32 available;
    u32 amount;

    data = (struct HCdvdStreamData*)((u8*)slotData + 0x70);
    if (data->fileSize > data->fileOffset)
    {
        goto read_file;
    }
    return 0;

read_file:
    available = data->fileSize - data->fileOffset;
    amount = size;
    if (available < amount)
    {
        amount = available;
    }
    memcpy(dst, data->fileMemory + data->fileOffset, amount);
    data->fileOffset += amount;
    return amount;
}

static void H_Cdvd_StreamSetPosition(HCdvdStreamPosition* result,
                                     HCdvdStreamSlot* slot, u32 amount, s32 mode)
{
    u32 position;

    if (mode == 1)
    {
        position = slot->fileOffset + amount;
        if (position > slot->fileSize)
        {
            position = slot->fileSize;
        }
    }
    else if (mode == 2)
    {
        if (amount > slot->fileSize)
        {
            amount = slot->fileSize;
        }
        position = slot->fileOffset + amount;
    }
    else if (mode == 3)
    {
        position = slot->fileOffset + amount;
        if (position > slot->fileSize)
        {
            position = slot->fileSize - 1;
        }
    }
    else
    {
        position = 1;
    }

    slot->fileOffset = position;
    result->position = position;
    result->unused0 = 0;
    result->unused1 = 0;
}

static void H_Cdvd_StreamSetPositionCallback(HCdvdStreamPosition* result,
                                              HCdvdStreamSlot* slot,
                                              u32 amount, s32 mode)
{
    H_Cdvd_StreamSetPosition(result, slot, amount, mode);
}

// FUN_001018c0
void func_001018c0(void* resultData, void* slotData, u32 amount, s32 mode)
{
    u8* data = (u8*)slotData + 0x70;
    unsigned __int128 position;
    u32 value;

    if (mode == 1)
    {
        value = *(u32*)(data + 0x90) + amount;
        if (value > *(u32*)(data + 0x8c))
        {
            value = *(u32*)(data + 0x8c);
        }
        *(u32*)(data + 0x90) = value;
        __asm__ volatile (
            "sd %0, 0($sp)\n"
            "lq $v1, 0($sp)\n"
            "sq $v1, 0(%1)"
            : : "r"(value), "r"(resultData), "m"(position) : "$v1", "memory");
    }
    else if (mode == 2)
    {
        if (amount > *(u32*)(data + 0x8c))
        {
            amount = *(u32*)(data + 0x8c);
        }
        value = *(u32*)(data + 0x90) + amount;
        *(u32*)(data + 0x90) = value;
        __asm__ volatile (
            "sd %0, 0($sp)\n"
            "lq $v1, 0($sp)\n"
            "sq $v1, 0(%1)"
            : : "r"(value), "r"(resultData), "m"(position) : "$v1", "memory");
    }
    else if (mode == 3)
    {
        value = *(u32*)(data + 0x8c) + amount;
        if (value > *(u32*)(data + 0x8c))
        {
            value = *(u32*)(data + 0x8c) - 1;
        }
        *(u32*)(data + 0x90) = value;
        __asm__ volatile (
            "sd %0, 0($sp)\n"
            "lq $v1, 0($sp)\n"
            "sq $v1, 0(%1)"
            : : "r"(value), "r"(resultData), "m"(position) : "$v1", "memory");
    }
    else
    {
        value = 1;
        __asm__ volatile (
            "sd %0, 0($sp)\n"
            "lq $v1, 0($sp)\n"
            "sq $v1, 0(%1)"
            : : "r"(value), "r"(resultData), "m"(position) : "$v1", "memory");
    }
}

// FUN_001019e0
void func_001019e0(void* contextData)
{
    HCdvdStreamContext* context = (HCdvdStreamContext*)contextData;
    HCDVD_FREE(context->slots);
}

// FUN_00101a10
s32 func_00101a10(void* unused, const char* path)
{
    char uppercasePath[256];
    char normalizedPath[256];
    char cachePath[256];
    s32 i;

    (void)unused;
    H_Cdvd_BuildPathUppercase(path, uppercasePath);
    H_Cdvd_NormalizePath(uppercasePath, normalizedPath);
    for (i = 0; i < HCDVD_CACHE_MAX; i++)
    {
        if (sCdvdCache[i].isValid)
        {
            H_Cdvd_NormalizePath(sCdvdCache[i].path, cachePath);
            if (strcmp(cachePath, normalizedPath) == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}

static void H_Cdvd_SetStreamCallback(HCdvdStreamContext* context, u32 offset,
                                     void* callback)
{
    *(void (**)(void))((u8*)context + offset) = (void (*)(void))callback;
}

// FUN_00101ad0 NONMATCHING
void* func_00101ad0(s32 count, void* source, s32 stride,
                                   void* callbackData, void* key)
{
    HCdvdStreamContext* context;
    s32 i;
    void* (**allocator)(u32, u32, u32);

    if (func_004bfd50(key) != NULL)
    {
        return NULL;
    }
    allocator = (void* (**)(u32, u32, u32))D_00960184;

    context = (HCdvdStreamContext*)(*allocator)(1, 0x5c, 0x40000);
    if (context == NULL)
    {
        return NULL;
    }
    context->callback14 = (void*)H_Cdvd_StreamGetSlot;
    context->callback18 = (void*)func_001019e0;
    context->callback28 = (void*)func_001016d0;
    context->callback2c = (void*)H_Cdvd_StreamNoop;
    context->callback30 = (void*)func_00101810;
    context->callback38 = (void*)func_001018c0;
    context->callback44 = (void*)H_Cdvd_StreamComplete;
    context->callback4c = (void*)func_00101a10;
    context->count = count;
    context->slots = (HCdvdStreamSlot*)(*allocator)(count, 0x110, 0x40000);
    if (context->slots == NULL)
    {
        return context;
    }
    for (i = 0; i < count; i++)
    {
        context->slots[i].context = context;
        context->slots[i].source = (u8*)source + i * stride;
        context->slots[i].sourceStride = stride;
    }
    if (func_004bf6e0(context, count, key, callbackData) != 1)
    {
        printf("CDVD stream registration failed: %d\n", count);
    }
    return context;
}

// FUN_00101c70 NONMATCHING
void func_00101c70(void)
{
    static u8 key0[16];
    static u8 key1[16];
    static u8 key2[16];
    static u8 key3[16];
    void* context;

    func_004bfbb0(-1);
    ((void (*)(void*, void*))D_0096013C)(key0, key1);
    ((void (*)(void*, void*))D_0096013C)(key2, key3);
    context = func_004c0fd0(5, (void*)0x007d4780, 0x800, key0, key2);
    if (context == NULL)
    {
        return;
    }
    if (func_004bfc80(context) == NULL)
    {
        printf("CDVD stream group registration failed\n");
        return;
    }
    ((void (*)(void*, void*))D_0096013C)(key0, key1);
    ((void (*)(void*, void*))D_0096013C)(key2, key3);
    context = func_00101ad0(5, (void*)0x007d1f80, 0x800, key0, key2);
    if (context != NULL)
    {
        if (func_004bfc80(context) != NULL)
        {
            func_004c0230(context);
        }
        else
        {
            printf("CDVD stream group 2 registration failed\n");
        }
    }
    ((void (*)(void*, void*))D_0096013C)(key0, key1);
    ((void (*)(void*, void*))D_0096013C)(key2, key3);
    context = func_00102e50(5, (void*)0x007cf780, 0x800, key0, key2);
    if (context != NULL && func_004bfc80(context) == NULL)
    {
        printf("CDVD stream group 3 registration failed\n");
    }
}

static u32 H_Cdvd_Align64(u32 size)
{
    return (size + 0x3f) & ~0x3f;
}

static void H_Cdvd_CopyArchiveEntries(void* requestData, u8* archive,
                                      u32 archiveSize, const char* basePath)
{
    u32 offset = 0;
    char fullPath[256];
    char entryName[256];

    while (offset + sizeof(ArchiveEntryHeader) <= archiveSize)
    {
        ArchiveEntryHeader header;
        memcpy(&header, archive + offset, sizeof(header));
        if (header.fileName[0] == '\0')
        {
            break;
        }
        strcpy(fullPath, basePath);
        strcat(fullPath, header.fileName);
        H_Cdvd_BuildPathUppercase(fullPath, entryName);
        H_Cdvd_CacheAdd(requestData, archive + offset + sizeof(header),
                        header.fileSize, entryName);
        offset += sizeof(header) + H_Cdvd_Align64(header.fileSize);
    }
}

// FUN_00101e30 NONMATCHING
void func_00101e30(void* requestData)
{
    struct
    {
        char directory[256];
        char fileName[256];
        char entryPath[256];
        u32 fileSize;
    } work;
    u32 offset;
    s32 i;
    s32 scan;
    char c;

    if (*(u32*)((u8*)requestData + 0x148) == 0)
    {
        func_00102030(requestData, *(u8**)((u8*)requestData + 0x108),
                      *(u32*)((u8*)requestData + 0x11c),
                      (const char*)requestData + 8);
        *(s16*)((u8*)requestData + 0x350) = 1;
        return;
    }

    for (i = 0; i < 0x100; i++)
    {
        c = ((const char*)requestData)[i + 8];
        if (c == '\0')
        {
            scan = i - 1;
            while (work.entryPath[scan - 1] != '\\')
            {
                scan--;
            }
            work.entryPath[scan] = '\0';
            break;
        }
        work.entryPath[i] = c;
    }

    *(s16*)((u8*)requestData + 0x350) = 0;
    offset = 0;
    while (true)
    {
        memcpy(work.directory, work.entryPath, 0xfc);
        memcpy(work.fileName, *(u8**)((u8*)requestData + 0x108) + offset, 0xfc);
        if (work.fileName[0] == '\0')
        {
            return;
        }
        (*(s16*)((u8*)requestData + 0x350))++;
        memcpy(&work.fileSize,
               *(u8**)((u8*)requestData + 0x108) + offset + 0xfc, 4);
        offset += 0x100;
        strcat(work.directory, work.fileName);
        for (i = 0; i < 0xff; i++)
        {
            c = work.directory[i];
            if (c >= 'a' && c <= 'z')
            {
                work.directory[i] = c - 0x20;
            }
            c = work.directory[i];
            if (c == '\0')
            {
                break;
            }
            if (c == '/')
            {
                work.directory[i] = '\\';
            }
        }
        func_00102030(requestData,
                      *(u8**)((u8*)requestData + 0x108) + offset,
                      work.fileSize, work.directory);
        work.fileSize = ((s32)(work.fileSize + 0x3f) / 0x40) * 0x40;
        offset += work.fileSize;
    }
}

#pragma push
#pragma opt_loop_invariants on
// FUN_00102030
void func_00102030(void* requestData, void* fileMemory, u32 fileSize,
                   const char* path)
{
    s32 i;
    HCdvdCache* curr;
    u32 offset;

    i = 0;
    for (; i < HCDVD_CACHE_MAX; i++)
    {
        offset = i * sizeof(HCdvdCache);
        curr = (HCdvdCache*)((u8*)sCdvdCache + offset);
        if (!curr->isValid)
        {
            curr->isValid = true;
            sCdvdCache[i].requestData = requestData;
            sCdvdCache[i].fileMemory = fileMemory;
            sCdvdCache[i].fileSize = fileSize;
            sCdvdCache[i].unk_110 = 0;
            memcpy(curr->path, path, 128);
            return;
        }
    }
}
#pragma pop

// FUN_001022e0
const char* func_001022e0(HCdvd* cdvd, s32 entryIndex)
{
    s32 i;
    u8* entry;
    ArchiveEntryHeader header;

    entry = (u8*)cdvd->fileMemory;
    for (i = 0; i < entryIndex; i++)
    {
        memcpy(&header, entry, sizeof(header));
        if (header.fileName[0] == '\0')
        {
            return NULL;
        }
        entry += sizeof(header);
        entry += ((((s32)header.fileSize + 0x3f) / 0x40) * 0x40);
    }
    if (*(char*)entry == '\0')
    {
        return NULL;
    }
    return (const char*)entry;
}

// FUN_001023f0
void func_001023f0(void* handle, const char* path, s32 synchronous)
{
    static char uppercasePath[256];
    static char fileName[256];
    static char directory[256];

    H_Cdvd_BuildPathUppercase(path, uppercasePath);
    func_00101100(uppercasePath, fileName, directory);
    func_00101520(directory);
    if (synchronous)
    {
        func_00584290(handle, fileName);
    }
    else
    {
        func_00580378(handle, fileName);
    }
}

// FUN_001024a0
void func_001024a0(void* source, const char* path, s32 flags, void* callback)
{
    static char uppercasePath[256];
    static char fileName[256];
    static char directory[256];
    extern const char D_00638320[];

    H_Cdvd_BuildPathUppercase(path, uppercasePath);
    func_00101100(uppercasePath, fileName, directory);
    func_0053b868(source, fileName, D_00638320, callback);
    (void)flags;
}

// FUN_00102530
void func_00102530(void* handle, const char* path)
{
    static char uppercasePath[256];
    static char fileName[256];
    static char directory[256];
    void* stream;

    stream = func_0054d390();
    H_Cdvd_BuildPathUppercase(path, uppercasePath);
    func_00101100(uppercasePath, fileName, directory);
    func_00101520(directory);
    func_0054b2e8(stream, fileName);
    (void)handle;
}

// FUN_001025c0
void func_001025c0(void* handle, const char* path)
{
    static char uppercasePath[256];
    static char fileName[256];
    static char directory[256];

    func_0054d390();
    H_Cdvd_BuildPathUppercase(path, uppercasePath);
    func_00101100(uppercasePath, fileName, directory);
    func_00101520(directory);
    func_0054d0a0(handle, fileName);
}

// FUN_00102720 NONMATCHING
void func_00102720(const char* path, const void* archive)
{
    char c;
    s32 i;
    char uppercasePath[256];
    char fileName[256];
    char entryPath[256];
    u32 fileSize;
    s32 offset;
    u32 alignedSize;
    s32 backslash;
    s32 slash;

    H_Cdvd_BuildPathUppercase(path, uppercasePath);
    offset = 0;
    while (true)
    {
        memcpy(entryPath, uppercasePath, 0xfc);
        memcpy(fileName, (const u8*)archive + offset, 0xfc);
        if (fileName[0] == '\0')
        {
            return;
        }
        memcpy(&fileSize, (const u8*)archive + (offset + 0xfc), 4);
        offset += 0x100;
        strcat(entryPath, fileName);
        i = 0;
        backslash = '\\';
        slash = '/';
        while (i < 0xff)
        {
            c = entryPath[i];
            if (c >= 'a' && c <= 'z')
            {
                entryPath[i] = c - 0x20;
            }
            c = entryPath[i];
            if (c == '\0')
            {
                break;
            }
            if (c == slash)
            {
                entryPath[i] = backslash;
            }
            i++;
        }
        H_Cdvd_CacheAdd((void*)archive, (u8*)archive + offset, fileSize,
                        entryPath);
        alignedSize = ((s32)(fileSize + 0x3f) / 0x40) * 0x40;
        fileSize = alignedSize;
        offset += alignedSize;
    }
}
// FUN_001028d0
void func_001028d0(void)
{
    func_00505e48("CDVD file context destroyed");
}

typedef struct HCdvdFileContext HCdvdFileContext;

struct HCdvdFileContext
{
    u32 reserved00;
    u32 count;
    u8 reserved08[0x0c];
    void* callback14;
    void* callback18;
    u8 reserved1c[0x0c];
    void* callback28;
    void* callback2c;
    void* callback30;
    void* callback34;
    void* callback38;
    u8 reserved3c[8];
    void* callback44;
    u8 reserved48[4];
    void* callback4c;
    u8 reserved50[8];
    u8* slots;
};
typedef struct
{
    u8 reserved00[0x10];
    s64 position;
    u8 reserved18[0x18];
    u32 state30;
    u8 reserved34[8];
    u32 state3c;
    u8 reserved40[0x34];
    s32 fd;
} HCdvdOpenSlot;


static s64* H_Cdvd_FilePosition(void* slot)
{
    return (s64*)((u8*)slot + 0x10);
}

// FUN_00102900
s32 func_00102900(void* unused, void* slot, const char* path, u32 flags)
{
    char uppercasePath[256];
    u32 openFlags = 0;
    HCdvdOpenSlot* openSlot = (HCdvdOpenSlot*)slot;

    (void)unused;
    func_00505e48("CDVD open %s", path);
    strcpy(uppercasePath, "VOL:\\");
    strcat(uppercasePath, path + 4);
    if (path == NULL)
    {
        return 2;
    }
    if ((flags & 1) != 0 && (flags & 2) != 0)
    {
        openFlags |= 3;
    }
    else
    {
        if ((flags & 1) != 0)
        {
            openFlags |= 1;
        }
        if ((flags & 2) != 0)
        {
            openFlags |= 2;
        }
    }
    if ((flags & 4) != 0)
    {
        openFlags |= 0x200;
    }
    if ((flags & 2) != 0 && (flags & 8) == 0)
    {
        openFlags |= 0x400;
    }

    openSlot->state30 = 0;
    openSlot->position = 0;
    {
        s32 fd = func_00508670(uppercasePath, openFlags, 0x1ff);
        openSlot->fd = fd;
        if (fd < 0)
        {
            return 3;
        }
        *(s64*)openSlot = func_00508a78(fd, 0, 2);
    }
    func_00508a78(openSlot->fd, 0, 0);
    openSlot->state3c = 1;
    return 1;
}

// FUN_00102a70
void func_00102a70(void* slot)
{
    void* unused;

    func_00505e48("CDVD close");
    *(u32*)((u8*)slot + 0x38) = 1;
    func_00508900(*(s32*)((u8*)slot + 0x74));
    func_0050a888("VOL:\\", unused);
}

// FUN_00102ad0
s32 func_00102ad0(void* slot, void* dst, u32 size)
{
    s32 amount;

    func_00505e48("CDVD read");
    amount = func_00508cb8(*(s32*)((u8*)slot + 0x74), dst, size);
    if (amount < 0)
    {
        return 0;
    }
    *(u32*)((u8*)slot + 0x38) = 3;
    *(s64*)((u8*)slot + 0x10) += amount;
    return amount;
}

// FUN_00102b60
s32 func_00102b60(void* slot, void* dst, u32 size)
{
    s32 amount;

    func_00505e48("CDVD read direct");
    amount = func_00508f28(*(s32*)((u8*)slot + 0x74), dst, size);
    if (amount < 0)
    {
        return 0;
    }
    *(s64*)((u8*)slot + 0x10) += amount;
    return amount;
}

// FUN_00102bf0
void func_00102bf0(void* resultData, void* slot,
                   s32 amount, s32 mode)
{
    typedef struct
    {
        u8 reserved00[0x10];
        HCdvdStreamPosition position;
    } HCdvdSeekSlot;
    HCdvdStreamPosition* result = (HCdvdStreamPosition*)resultData;
    HCdvdSeekSlot* seekSlot = (HCdvdSeekSlot*)slot;

    func_00505e48("CDVD seek");
    if (mode == 3)
    {
        goto mode3;
    }
    if (mode == 2)
    {
        goto mode2;
    }
    switch (mode)
    {
    case 1:
        goto mode1;
    default:
        goto invalid;
    }

mode1:
    seekSlot->position.position = amount;
    goto common;
mode2:
    seekSlot->position.position += amount;
    goto common;
mode3:
    seekSlot->position.position -= amount;
    goto common;
invalid:
    seekSlot->position.position = -1;
    *(long128*)resultData = *(long128*)&seekSlot->position;
    return;

common:
    if (seekSlot->position.position < 0)
    {
        seekSlot->position.position = 0;
    }
    {
        s32 offset;
        s32 fd;
        func_00508a78(
            (offset = *(s32*)((u8*)slot + 0x10),
             fd = *(s32*)((u8*)slot + 0x74), fd),
            offset, 0);
    }
    *(long128*)resultData = *(long128*)&seekSlot->position;
}

// FUN_00102d10
s32 func_00102d10(void* unused, const char* path)
{
    char uppercasePath[256];
    s32 fd;

    (void)unused;
    strcpy(uppercasePath, "VOL:\\");
    strcat(uppercasePath, path + 4);
    fd = func_00508670_2(uppercasePath, 1);
    if (fd >= 0)
    {
        func_00508900(fd);
        return 1;
    }
    return 0;
}

// FUN_00102d90
void* func_00102d90(void* contextData, u32 index)
{
    s32 i = index;
    HCdvdFileContext* context = (HCdvdFileContext*)contextData;

    func_00505e48("### hdd fs get file object\t\n");
    if (i < context->count)
    {
        return context->slots + i * 0x90;
    }
    return NULL;
}

// FUN_00102e00
void func_00102e00(void* contextData)
{
    HCdvdFileContext* context = (HCdvdFileContext*)contextData;
    func_00505e48("CDVD file context cleanup");
    HCDVD_FREE(context->slots);
}

// FUN_00102e50 NONMATCHING
void* func_00102e50(s32 count, void* source, s32 stride,
                                 void* callbackData, void* key)
{
    HCdvdFileContext* context;
    s32 i;

    if (func_004bfd50(key) != NULL)
    {
        return NULL;
    }
    context = (HCdvdFileContext*)HCDVD_ALLOC(1, 0x5c, 0x40000);
    if (context == NULL)
    {
        return NULL;
    }
    context->callback14 = (void*)func_00102d90;
    context->callback18 = (void*)func_00102e00;
    context->callback28 = (void*)func_00102900;
    context->callback2c = (void*)func_00102a70;
    context->callback30 = (void*)func_00102ad0;
    context->callback34 = (void*)func_00102b60;
    context->callback38 = (void*)func_00102bf0;
    context->callback44 = (void*)func_001028d0;
    context->callback4c = (void*)func_00102d10;
    context->count = count;
    context->slots = (u8*)HCDVD_ALLOC(count, 0x90, 0x40000);
    if (context->slots == NULL)
    {
        return context;
    }
    for (i = 0; i < count; i++)
    {
        u8* slot = context->slots + i * 0x90;
        *(void**)(slot + 0x50) = context;
        *(u8**)(slot + 0x68) = (u8*)source + i * stride;
        *(u32*)(slot + 0x6c) = stride;
    }
    if (func_004bf6e0(context, count, key, callbackData) != 1)
    {
        printf("CDVD file context registration failed: %d\n", count);
    }
    return context;
}
