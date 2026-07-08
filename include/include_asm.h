#ifndef P3FES_INCLUDE_ASM_H
#define P3FES_INCLUDE_ASM_H

/* mwccgap consumes these markers before invoking mwcc.  They are empty for
 * plain C compilation so source files can keep INCLUDE_ASM placeholders in the
 * traditional splat/mwcc workflow. */
#define INCLUDE_ASM(FOLDER, NAME)
#define INCLUDE_RODATA(FOLDER, NAME)

#endif /* P3FES_INCLUDE_ASM_H */
