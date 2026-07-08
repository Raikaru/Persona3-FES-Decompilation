#!/usr/bin/env python3
"""AST-level permuter: upstream decomp-permuter's randomizer, wired to this
repo's mwccps2 compile + verify.py reloc-masked scoring.

Where tools/permute.py mutates function *text*, this drives the full
decomp-permuter randomizer (https://github.com/simonlindholm/decomp-permuter):
~30 AST-level passes including temporary-for-expression, type randomization,
statement reordering, and reassociation -- strictly more powerful, and the tool
to reach for on register-allocation / scheduling walls that text mutation can't.

Pipeline (mirrors decomp-permuter's Candidate, minus its objdump scorer):
  1. Preprocess the TU with WSL `cpp -nostdinc` (the repo is self-contained).
  2. Parse with decomp-permuter's pycparser; extract + normalize the function.
  3. Hill-climb: deep-copy the best function, apply one randomizer mutation,
     unparse the whole TU, compile with mwccps2, and score the function's bytes
     against retail exactly as verify.py does (reloc-masked, tail-padding check).

decomp-permuter is cloned into tools/decomp-permuter on first run (gitignored).
Requires WSL Debian with `cpp` (build-essential) and system Python with
`pycparser`, `attrs`, `toml`.

IMPORTANT: a hit's source is usually heavily mutated (dead temps, `if (1)`,
reassociations). It compiles byte-exact, but you MUST read it, extract the one
change that matters, and write clean C -- then confirm with tools/verify.py.
This is the normal decomp-permuter workflow, not a drop-in patch.

Usage:
  python tools/permute_ast.py src/Battle/btlMain.c btlMainUpdateStateLose --time 120
  python tools/permute_ast.py <file.c> <func> [--time S] [--iters N] [--seed S] [--out F]
"""
import argparse
import copy
import json
import os
import shlex
import subprocess
import sys
import tempfile
import time
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
REPO = TOOLS.parent
DP_URL = "https://github.com/simonlindholm/decomp-permuter"


def find_dp():
    for cand in (TOOLS / "decomp-permuter", REPO / "build" / "dp"):
        if (cand / "src" / "randomizer.py").is_file():
            return cand
    dest = TOOLS / "decomp-permuter"
    print(f"cloning decomp-permuter into {dest} ...", flush=True)
    r = subprocess.run(["git", "clone", "--depth", "1", DP_URL, str(dest)])
    if r.returncode or not (dest / "src" / "randomizer.py").is_file():
        sys.exit("failed to clone decomp-permuter; clone it manually to "
                 f"{dest} (git clone {DP_URL})")
    return dest


DP = find_dp()
sys.path.insert(0, str(DP))
sys.path.insert(0, str(TOOLS))
from src import ast_util
import perm_pycparser.c_ast as ca
from src.randomizer import Randomizer
from src.helpers import get_default_randomization_weights
from verify import (ObjectFile, RetailElf, compare, load_config, scan_markers,
                    window_for)


def wslpath(p):
    s = str(p).replace("\\", "/")
    return "/mnt/" + s[0].lower() + s[2:]


def preprocess(rel):
    # Repo is self-contained, so -nostdinc is safe and keeps output pycparser-clean.
    flags = ["-Iinclude", "-nostdinc", "-undef", "-D__MWERKS__=1", rel]
    if os.name == "nt":
        # Windows: cpp lives in WSL Debian; run there against the /mnt path.
        inner = f"cd {shlex.quote(wslpath(REPO))} && cpp " + " ".join(shlex.quote(f) for f in flags)
        r = subprocess.run(["wsl", "-d", "Debian", "--", "bash", "-lc", inner],
                           capture_output=True, text=True)
    else:
        r = subprocess.run(["cpp"] + flags, cwd=str(REPO), capture_output=True, text=True)
    if r.returncode or len(r.stdout) < 100:
        sys.exit(f"cpp preprocessing failed: {r.stderr[:600]}")
    return r.stdout


def all_boundaries(sizes):
    bounds = {int(a, 16) for a in sizes["windows"]}
    for c in (REPO / "src").rglob("*.c"):
        for m in scan_markers(c):
            bounds.add(m["addr"])
    return sorted(bounds)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("file")
    ap.add_argument("function")
    ap.add_argument("--iters", type=int, default=10 ** 8)
    ap.add_argument("--time", type=float, default=120.0)
    ap.add_argument("--seed", type=int, default=1)
    ap.add_argument("--out")
    args = ap.parse_args()

    cfg = load_config()
    sizes = json.loads((TOOLS / "slus21621_functions.json").read_text())
    retail = RetailElf(cfg["retail_elf"], expect_sha1=sizes.get("sha1"))
    mk = next((m for m in scan_markers(REPO / args.file)
               if m["name"] == args.function), None)
    if not mk:
        sys.exit(f"no // FUN_ marker for {args.function} in {args.file}")
    addr = mk["addr"]
    window = window_for(addr, all_boundaries(sizes))
    win_bytes = retail.bytes_at(addr, window)

    source = ast_util.process_pragmas(preprocess(args.file))
    base_ast = ast_util.parse_c(source, from_import=True)
    orig_fn, fn_index = ast_util.extract_fn(base_ast, args.function)
    ast_util.normalize_ast(orig_fn, base_ast)

    rnd = Randomizer(get_default_randomization_weights("mwcc"), args.seed)
    tmpdir = Path(tempfile.mkdtemp(prefix="p3ast_"))
    ncompiles = [0]

    def make_ast(fn):
        ast = copy.copy(base_ast)
        ast.ext = copy.copy(base_ast.ext)
        ast.ext[fn_index] = fn
        return ast

    def score(ast):
        ncompiles[0] += 1
        cfile = tmpdir / "cand.c"
        cfile.write_text(ast_util.to_c(ast), newline="\n")
        ofile = tmpdir / "cand.o"
        p = subprocess.run(
            [cfg["mwcc"], "-O2", "-c", str(cfile), "-o", str(ofile)],
            cwd=str(REPO), stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
        if p.returncode or not ofile.is_file():
            return 10 ** 6, False
        try:
            body, rels = ObjectFile(ofile).function(args.function)
        except KeyError:
            return 10 ** 6, False
        ndiff, _ = compare(body, rels, win_bytes)
        tail = win_bytes[len(body):]
        ok = len(body) <= window and not any(tail)
        return ndiff + (0 if ok else 500 + abs(len(body) - window)), (ndiff == 0 and ok)

    base_score, base_match = score(make_ast(orig_fn))
    print(f"[{args.function}] addr={addr:#010x} window={window} "
          f"base_score={base_score} match={base_match}", flush=True)
    if base_score >= 10 ** 6:
        sys.exit("base TU does not compile (check cpp / preprocessing)")

    best_fn, best_score = orig_fn, base_score
    cur_fn, cur_score = orig_fn, base_score
    t0 = time.time()
    stale = 0
    for it in range(args.iters):
        if args.time and time.time() - t0 > args.time:
            break
        fn = copy.deepcopy(cur_fn)
        ast = make_ast(fn)
        try:
            rnd.randomize(ast, args.function)
        except Exception:
            continue
        sc, match = score(ast)
        if match:
            out = args.out or str(REPO / "build" / f"{args.function}.ast.c")
            Path(out).parent.mkdir(parents=True, exist_ok=True)
            Path(out).write_text(ast_util.to_c(fn) + "\n", newline="\n")
            print(f"[{args.function}] MATCH at iter {it} ({ncompiles[0]} compiles). "
                  f"Mutated function -> {out}\n"
                  f"NOTE: extract the essential change and write clean C; "
                  f"re-confirm with tools/verify.py.", flush=True)
            print("--- mutated function ---\n" + ast_util.to_c(fn))
            return
        if sc < cur_score or (sc == cur_score and rnd.random.random() < 0.3):
            cur_fn, cur_score, stale = fn, sc, 0
        else:
            stale += 1
        if sc < best_score:
            best_fn, best_score = fn, sc
            print(f"[{args.function}] iter {it}: best {best_score} "
                  f"({ncompiles[0]} compiles)", flush=True)
        if stale > 80:
            cur_fn, cur_score, stale = best_fn, best_score, 0
    print(f"[{args.function}] no match. best={best_score} after "
          f"{ncompiles[0]} compiles / {time.time()-t0:.0f}s", flush=True)
    sys.exit(1)


if __name__ == "__main__":
    main()
