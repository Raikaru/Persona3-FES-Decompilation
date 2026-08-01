#include "mw_harvest_compat.h"
#include "libm.h"
/*
 * Vendor libm functions are split into their upstream translation units.
 * The measured ee-gcc provenance and wrapper-floor analysis lives in
 * src/lib/sce/libm/sf_tan.c, which owns the wrapper run.
 */

