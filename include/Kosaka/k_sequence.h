#ifndef K_SEQUENCE_H
#define K_SEQUENCE_H

#include "Utils.h"

// 8 bytes
typedef struct DungeonSeq
{
    u32 floor;  // 0x00
    u32 unk_04; // 0x04
} SeqDungeon;

s32 K_Seq_ExitField(void);
u8 K_Seq_CheckField(void);

void K_Seq_CallField2(u8 isRestored, void* seqData);
s32 K_Seq_ExitField2(void);
u8 K_Seq_CheckField2(void);

void K_Seq_CallDungeon(u8 isRestored, void* seqData);
s32 K_Seq_ExitDungeon(void);
u8 K_Seq_CheckDungeon(void);

#endif