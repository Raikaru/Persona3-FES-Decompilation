# Persona 3 FES (SLUS_216.21) matching decompilation.
#
# Quick start:
#   1. copy your retail SLUS_216.21 somewhere and point tools/verify_config.local.json
#      ("mwcc" -> mwccps2.exe, "retail_elf" -> SLUS_216.21) at it
#   2. make setup      # extract the loadable image from the ELF
#   3. make split      # splat -> asm/ (only needed once, or after a config change)
#   4. make            # assemble + link -> build/slus21621.elf, verify byte-match
#
# Toolchain: the original CodeWarrior PS2 suite (mwccps2 / asm_r5900_elf / mwldps2).

PYTHON ?= python
SPLAT_CONFIG = config/slus21621.yaml

.PHONY: all build setup split verify check clean distclean

all: build

# Assemble every segment, link, and verify the loadable image is byte-identical.
build:
	$(PYTHON) tools/build.py

# Extract image.bin (the loadable PT_LOAD payload) from the retail ELF.
setup:
	$(PYTHON) tools/build.py --setup-only

# Disassemble/split the image into asm/ + data via splat.
split:
	$(PYTHON) -m splat split $(SPLAT_CONFIG)

# Per-function C match report (compiles src/ and byte-compares each // FUN_ marker).
verify check:
	$(PYTHON) tools/verify.py

clean:
	-rm -f asm/*.o asm/*_raw.s build/slus21621.elf build/slus21621.lcf

distclean: clean
	-rm -f image.bin
	-rm -rf asm/code1.s asm/code2.s asm/data
