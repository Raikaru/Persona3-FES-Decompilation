#ifndef BCM_MAIN_H
#define BCM_MAIN_H

#include "Utils.h"

/* Battle command work area shared by the command and panel callbacks. */
extern u8* gBcmWork;

u32 bcm00207930(u16 param_1);
void bcm00207a10(void);
void bcm00207bf0(void);
void bcm00201ad0(void);
void bcm00203360(void);

#endif
