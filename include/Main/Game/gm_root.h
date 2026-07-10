#ifndef GM_ROOT_H
#define GM_ROOT_H

#include "Utils.h"

#define GMROOT_FLAG_ACTIVE (1 << 0) // 0x01
#define GMROOT_FLAG_UNK2   (1 << 1) // 0x02
#define GMROOT_FLAG_UNK4   (1 << 2) // 0x04

typedef struct KwlnTask KwlnTask;

// 44 bytes
typedef struct GmRootWork
{
    u32 flags;                // 0x00
    s32 unk_04;               // 0x04
    KwlnTask* task;           // 0x08
    u32 unk_0c;               // 0x0c
    u32 unk_10;               // 0x10
    u32 unk_14;               // 0x14, opaque task result
    u8 unkData[0x10];         // 0x18
    KwlnTask* chkMemcardTask; // 0x28
} GmRootWork;

KwlnTask* gmRootCreateTask(KwlnTask* parent);

#endif