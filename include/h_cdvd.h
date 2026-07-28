#ifndef H_CDVD_H
#define H_CDVD_H

#include "Utils.h"

#include "cri_adxf.h"

#define HCDVD_FILENORMAL  0
#define HCDVD_FILEARCHIVE 1 // Is a .PAC, .PAK, .BIN or .FPC


typedef enum HCdvdReadState
{
    HCDVD_READ_QUEUED = 0,
    HCDVD_READ_OPENED = 1,
    HCDVD_READ_IN_PROGRESS = 2,
    HCDVD_READ_FINALIZING = 3,
    HCDVD_READ_COMPLETE = 4
} HCdvdReadState;
typedef struct HCdvd HCdvd;

// 868 bytes
struct HCdvd
{
    HCdvd* prev;                    // 0x000
    HCdvd* next;                    // 0x004
    u32 hasExternalMemory;          // 0x008
    u32 readState;                  // 0x00c. See HCdvdReadState
    char path[256];                 // 0x010
    void* fileMemory;               // 0x110. 64-byte aligned loaded file buffer
    void* unalignedFileMemory;      // 0x114. Allocation to pass to RwFree
    u32 fileSize;                   // 0x118. Exact file size in bytes
    u8 unk_11c[8];                  // 0x11c
    u32 readByteSize;               // 0x124. Exact byte size reported by ADXFS
    u8 unk_128[0x28];               // 0x128
    u32 fileMode;                   // 0x150. See HCDVD_FILE*
    ADXF adxf;                      // 0x154
    char fileName[256];             // 0x158
    char dir[256];                  // 0x258
    s16 archiveFileCount;           // 0x358
    s16 refCount;                   // 0x35a
    s16 pendingDestroyCount;        // 0x35c
    s16 readPollCount;              // 0x35e
    u8 unk_360[4];                  // 0x360
};

// 256 bytes. Header for an entry in an archive file (.PAC, .PAK or .BIN)
typedef struct ArchiveEntryHeader
{
    char fileName[252]; // 0x00
    u32 fileSize;       // 0xfc. Size in bytes
} ArchiveEntryHeader;

// 148 bytes
typedef struct HCdvdCache
{
    u32 isValid;      // 0x00
    void* requestData;  // 0x04. Pointer to HCdvd::hasExternalMemory
    char path[128];   // 0x08
    void* fileMemory; // 0x88
    u32 fileSize;     // 0x8c
    u32 unk_110;      // 0x90
} HCdvdCache;

void H_Cdvd_001007f0();
void H_Cdvd_Init();
void H_Cdvd_Read();

u32 H_Cdvd_FileExists(const char* path);
HCdvd* H_Cdvd_Request(const char* path, u32 fileMode);
u32 H_Cdvd_Destroy(HCdvd* cdvd);
void H_Cdvd_BuildPathUppercase(const char* src, char* dst);
s32 H_Cdvd_BuildVolumePaths(const char* path, char* fileNameDst, char* dirDst);
void H_Cdvd_NormalizePath(const char* src, char* dst);
u32 H_Cdvd_IsFileLoaded(HCdvd* cdvd);
void* H_Cdvd_ArchiveGetFile(HCdvd* cdvd, s32 fileIdx, u32* fileSize);
void* H_Cdvd_CacheFindFile(const char* path, u32* fileSize);
void H_Cdvd_ReadSync(HCdvd* cdvd);
void H_Cdvd_CacheAdd(void* requestData, void* fileMemory, u32 fileSize, const char* path);
void H_Cdvd_CacheRemove(void* requestData);
void func_00101100(const char* path, char* fileNameDst, char* dirDst);
void func_00101520(const char* dir);
s32 func_001016d0(void* unused, void* slot, uintptr_t pathOrMode);
u32 func_00101810(void* slot, void* dst, u32 size);
void func_001018c0(void* result, void* slot, u32 amount, s32 mode);
void func_001019e0(void* context);
s32 func_00101a10(void* unused, const char* path);
void* func_00101ad0(s32 count, void* source, s32 stride,
                     void* callbackData, void* key);
void func_00101c70(void);
void func_00101e30(void* requestData);
void func_00102030(void* requestData, void* fileMemory, u32 fileSize,
                   const char* path);
const char* func_001022e0(HCdvd* cdvd, s32 entryIndex);
void func_001023f0(void* handle, const char* path, s32 synchronous);
void func_001024a0(void* source, const char* path, s32 flags, void* callback);
void func_00102530(void* handle, const char* path);
void func_001025c0(void* handle, const char* path);
void func_00102720(const char* path, const void* archive);
void func_001028d0(void);
s32 func_00102900(void* unused, void* slot, const char* path, u32 flags);
void func_00102a70(void* slot);
s32 func_00102ad0(void* slot, void* dst, u32 size);
s32 func_00102b60(void* slot, void* dst, u32 size);
void func_00102bf0(void* result, void* slot, s32 amount, s32 mode);
s32 func_00102d10(void* unused, const char* path);
void* func_00102d90(void* context, u32 index);
void func_00102e00(void* context);
void* func_00102e50(s32 count, void* source, s32 stride,
                    void* callbackData, void* key);

#endif