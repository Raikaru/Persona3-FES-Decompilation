# Persona 3 FES (SLUS_216.21) matching decompilation.
#
# Quick start:
#   1. copy your retail SLUS_216.21 somewhere and point tools/verify_config.local.json
#      ("mwcc" -> mwccps2.exe, "retail_elf" -> SLUS_216.21) at it
#   2. make setup      # extract the loadable image from the ELF
#   3. make split      # splat -> asm/ (only needed once, or after a config change)
#   4. make            # build byte-identical SLUS_216.21 + verify
#
# Toolchain: mwccps2/mwldps2 plus GNU mipsel binutils (`mipsel-linux-gnu-as`,
# `mipsel-linux-gnu-objcopy`; Debian/WSL package binutils-mipsel-linux-gnu).

PYTHON ?= python
SPLAT_CONFIG = config/slus21621.yaml
C_SRCS := $(shell find src -name '*.c' 2>/dev/null)

.PHONY: all build setup split verify check test symbols objdiff ctx m2c-setup m2c progress format clean distclean

all: build verify

# Assemble asm + compile decompiled C objects, link the loadable image with
# mwldps2, splice into the retail ELF wrapper -> build/SLUS_216.21, verify.
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

test:
	$(PYTHON) -m unittest discover -s tests -v

# Regenerate the recovered symbol table (data-symbol addresses + _gp).
symbols:
	$(PYTHON) tools/recover_symbols.py

# Regenerate objdiff target/base objects + objdiff.json.
objdiff:
	$(PYTHON) tools/gen_objdiff.py

# Decomp.me context for a file:  make ctx FILE=src/Battle/btlFade.c
ctx:
	$(PYTHON) tools/m2ctx.py $(FILE)

# Install the pinned m2c revision, then decompile one function with project context:
#   make m2c-setup
#   make m2c FILE=src/Battle/btlVoice.c FUNC=func_002e3d50
m2c-setup:
	$(PYTHON) tools/setup_m2c.py

m2c:
	@test -n "$(FILE)" -a -n "$(FUNC)" || (echo "usage: make m2c FILE=src/path.c FUNC=function_name" && exit 2)
	$(PYTHON) tools/m2c_decompile.py "$(FILE)" "$(FUNC)" $(if $(STACK),--stack-structs,)

# Decompilation progress report.
progress:
	$(PYTHON) tools/progress.py

# Format decompiled C in place.
format:
	clang-format -i $(C_SRCS)

clean:
	-rm -rf build/obj build/objdiff asm/chunks
	-rm -f asm/*.o build/slus21621.elf build/slus21621.lcf build/slus21621.map build/SLUS_216.21

distclean: clean
	-rm -f image.bin
	-rm -rf asm/code1.s asm/code2.s asm/data
