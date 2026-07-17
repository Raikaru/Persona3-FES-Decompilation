#ifndef MDLFILE_H
#define MDLFILE_H

#include "Utils.h"

u8 mdlFileIsTypePac(u16 type);
u32 mdlFileResolvePackPath(u16 type, u16 id, char* dst);

#endif