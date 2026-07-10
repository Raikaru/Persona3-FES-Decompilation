#ifndef LIBCDVD_H
#define LIBCDVD_H

#include "sce/eetypes.h"

#define SCECdINIT 0x00
#define SCECdINoD 0x01
#define SCECdEXIT 0x05

#define SCECdCD  1
#define SCECdDVD 2

typedef struct sceCdRMode
{
    u_char trycount;
    u_char spindlctrl;
    u_char datapattern;
    u_char pad;
} sceCdRMode;

#define SCECdNotReady 6

int sceCdInit(int init_mode);
int sceCdDiskReady(int mode);
int sceCdRead(u_int lbn, u_int sectors, void* buffer, sceCdRMode* mode);
int sceCdSeek(u_int lbn);
int sceCdMmode(int media);

#endif