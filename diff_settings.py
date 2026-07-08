#!/usr/bin/env python3
"""Settings for asm-differ (https://github.com/simonlindholm/asm-differ).

The primary per-object diff workflow in this repo is objdiff (`make objdiff`,
then open objdiff.json), which compares the retail-derived target objects to the
compiled C objects symbol by symbol.

asm-differ works over the linked ELF: `make` produces build/slus21621.elf with a
symbol table (mwldps2 -nodeadstrip), so a function can be disassembled by name
with the R5900 objdump. Run e.g.:  ./diff.py -o btlFadeStart
"""


def apply(config, args):
    config["arch"] = "mipsel"
    config["myimg"] = "build/slus21621.elf"
    config["baseimg"] = "build/slus21621.elf"
    config["source_directories"] = ["src", "include"]
    config["objdump_executable"] = "mipsel-linux-gnu-objdump"
    config["make_command"] = ["make"]
    config["makeflags"] = []
