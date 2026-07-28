#!/usr/bin/env python3
"""Rigorous decompilation linter for the P3FES source tree.

`verify.py` answers "do these bytes match retail?".  This answers the other
half: "is this source an honest decompilation, and is the tree structurally
sound?".  A function can be byte-perfect and still be a bad artifact -- built
out of compiler-steering tricks, hand-written expansions of things the
compiler emits itself, or Ghidra residue nobody ever read.  Those are exactly
the defects this catches.

Rules are grouped by prefix:

  H  source honesty     constructs that steer codegen instead of expressing
                        the program: no-op arithmetic, zero-width barriers,
                        `volatile` on ordinary data, banned pragmas,
                        hand-written unsigned float conversion, dead stores
  M  marker hygiene     the `// FUN_xxxxxxxx` contract verify.py relies on
  P  pragma balance     push/pop and on/off brackets, including EOF leaks
  S  decomp quality     scalarized aggregates, raw offsets, Ghidra residue,
                        old-style declarations that hide argument errors
  C  corruption         damage from bad edits: mangled identifiers, mixed
                        line endings, duplicated blocks, unbalanced braces

Severities are `error` (fails the run), `warn`, and `info`.

WAIVERS.  A finding is waived by a comment within three lines above the site
(marker lines are skipped when looking up) that either says `lint: allow CODE`
or contains the word `measured`.  The second form is deliberate: this tree
already annotates every deliberately retained `volatile`, barrier and pragma
with its measured removal cost, e.g.

    /* Removing this loses btlUpdateRemoveFlagsPacket (MATCH nd0 -> MISMATCH nd13) - measured W161. */

Those annotations *are* the justification, so they are honoured as-is.  An
unannotated instance of the same construct is a finding, which is the point:
the rule is not "never use this", it is "never use this without paying for it
in measurement".

Usage:
    python tools/decomp_lint.py                     # lint src/ and include/
    python tools/decomp_lint.py src/Battle          # lint a subtree
    python tools/decomp_lint.py src/foo.c --json r.json
    python tools/decomp_lint.py --select H,C        # only honesty+corruption
    python tools/decomp_lint.py --ignore S001       # drop the noisy one
    python tools/decomp_lint.py --list              # describe every rule

Exit status is 1 if any `error` finding survives filtering, else 0.
"""

import argparse
import json
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

# Directories that are vendored, generated, or otherwise not ours to police.
DEFAULT_EXCLUDES = (
    "src/rw/", "src/cri/", "src/sce/",
    "include/rw/", "include/cri/", "include/sce/", "include/sdk/",
    "src/crt0.c", "src/libc_core.c", "src/libcdvd.c", "src/libm.c",
)

# PS2 hardware register windows.  `volatile` is legitimate here and nowhere
# else: EE core/peripheral MMIO, GS privileged registers, and scratchpad.
HARDWARE_RANGES = (
    (0x10000000, 0x10010000),   # EE peripherals: timers, DMAC, GIF, VIF, IPU
    (0x11000000, 0x11010000),   # VU0/VU1 micro and data memory
    (0x12000000, 0x12002000),   # GS privileged registers
    (0x1F800000, 0x1F810000),   # scratchpad / misc
    (0x1FC00000, 0x20000000),   # BIOS
    (0x70000000, 0x70004000),   # scratchpad mirror
)

RULES = {
    # ---- H: source honesty -------------------------------------------------
    "H001": ("error", "`volatile` on non-hardware data (compiler-steering, not a device access)"),
    "H002": ("error", "zero-width asm barrier used as a scheduling hint"),
    "H003": ("error", "banned optimization pragma (optimization_level 0/1, schedule off, opt_common_subs off)"),
    "H004": ("error", "no-op arithmetic identity used to steer codegen (x + 0, x * 1)"),
    "H005": ("error", "hand-written unsigned float-to-int bias expansion; the compiler emits this from a plain cast"),
    "H006": ("warn",  "if(1) / do{}while(0) layout wrapper outside a macro definition"),
    "H007": ("error", "dead store: local is assigned once and never read"),
    "H008": ("error", "`register` storage class on an ordinary local"),
    # ---- M: marker hygiene -------------------------------------------------
    "M001": ("error", "duplicate // FUN_ marker address within one file"),
    # verify.py itself tolerates this -- it blanks comments before reading the
    # header -- but a comment here defeats the "marker line is immediately
    # followed by its definition" assumption that byte-splice edits rely on,
    # and it is how a marker and its function get separated by accident.
    "M002": ("warn", "comment between a marker and its definition; annotations belong ABOVE the marker"),
    "M003": ("error", "marker has no resolvable function definition beneath it"),
    "M004": ("warn",  "NONMATCHING tag is misspelled or mis-cased; verify.py will not see it"),
    # ---- P: pragma balance -------------------------------------------------
    "P001": ("error", "unbalanced #pragma push / #pragma pop"),
    "P002": ("error", "unbalanced on/off pragma bracket"),
    "P003": ("error", "pragma scope still open at end of file (leaks into every later translation unit include)"),
    # ---- S: decompilation quality -----------------------------------------
    "S001": ("info",  "raw-offset struct access; should be a named struct field"),
    "S002": ("warn",  "Ghidra residue identifier or type left un-renamed"),
    "S003": ("warn",  "scalarized aggregate: consecutive member-wise stores that should be one aggregate copy"),
    "S004": ("warn",  "old-style/empty-parameter extern declaration; hides argument-count errors"),
    "S005": ("error", "symbol declared twice with different signatures in one file"),
    "S006": ("info",  "un-suffixed floating literal in float context (promotes to software double)"),
    # ---- C: corruption -----------------------------------------------------
    "C001": ("error", "mangled FUN_/DAT_ identifier (stray suffix from a bad regex edit)"),
    "C002": ("error", "mixed line endings in one file"),
    "C003": ("error", "unbalanced braces in file"),
}

SEVERITY_ORDER = {"info": 0, "warn": 1, "error": 2}

MARKER_RE = re.compile(r"^\s*//\s*(FUN_([0-9a-fA-F]{8}))(.*)$")
IDENT_RE = re.compile(r"[A-Za-z_][A-Za-z0-9_]*")


# --------------------------------------------------------------- source prep

def sanitize(lines):
    """Blank out comments and string/char literals, preserving line layout.

    Every rule below matches against the sanitized text so that a banned
    construct quoted inside a comment or a string is not a finding.
    """
    out_lines = []
    state = "code"
    for line in lines:
        out = []
        i = 0
        while i < len(line):
            ch = line[i]
            nxt = line[i + 1] if i + 1 < len(line) else ""
            if state == "block":
                if ch == "*" and nxt == "/":
                    out.extend("  ")
                    i += 2
                    state = "code"
                else:
                    out.append(" ")
                    i += 1
            elif state in ("str", "chr"):
                quote = '"' if state == "str" else "'"
                if ch == "\\":
                    out.extend("  ")
                    i += 2
                    continue
                out.append(" ")
                i += 1
                if ch == quote:
                    state = "code"
            else:
                if ch == "/" and nxt == "*":
                    out.extend("  ")
                    i += 2
                    state = "block"
                elif ch == "/" and nxt == "/":
                    out.extend(" " * (len(line) - i))
                    break
                elif ch == '"':
                    out.append(" ")
                    i += 1
                    state = "str"
                elif ch == "'":
                    out.append(" ")
                    i += 1
                    state = "chr"
                else:
                    out.append(ch)
                    i += 1
        out_lines.append("".join(out))
    return out_lines


class Source:
    """One .c/.h file, with the derived views every rule needs."""

    def __init__(self, path, raw):
        self.path = path
        self.raw = raw
        text = raw.decode("utf-8", errors="replace")
        self.crlf = raw.count(b"\r\n")
        self.lf = raw.count(b"\n") - self.crlf
        self.lines = text.replace("\r\n", "\n").split("\n")
        self.code = sanitize(self.lines)

    def rel(self):
        try:
            return self.path.relative_to(ROOT).as_posix()
        except ValueError:
            return self.path.as_posix()


class Finding:
    __slots__ = ("code", "severity", "file", "line", "message", "text")

    def __init__(self, code, file, line, message, text=""):
        self.code = code
        self.severity = RULES[code][0]
        self.file = file
        self.line = line
        self.message = message
        self.text = text

    def as_dict(self):
        return dict(code=self.code, severity=self.severity, file=self.file,
                    line=self.line, message=self.message, text=self.text)


# ------------------------------------------------------------------- waivers

WAIVER_ALLOW_RE = re.compile(r"lint:\s*allow\s+([A-Z]\d{3})")


def waived(src, idx, code):
    """True if the site on line `idx` (0-based) carries a justification.

    Three scopes are honoured, matching how this tree actually annotates:

    * INLINE scope -- a comment on the site line itself.  The W170 volatile
      convention embeds the justification directly in the cast:
      `*(volatile /* Removing this ... - measured W170. */ f32*)&x`.
    * SITE scope -- a comment within three lines above the site.
    * FUNCTION scope -- a comment in the six lines above the nearest enclosing
      `// FUN_xxxxxxxx` marker.  This is the important one: the measurement
      behind an annotation is always "removing this loses FUNCTION X", so one
      annotation covers every occurrence of the construct in that function.
      Without it a multi-line construct would need the same note repeated on
      each line, which is noise, not evidence.

    A justification is either an explicit `lint: allow CODE` or a comment
    containing `measured`, which is the tree's existing convention for
    recording a retained construct's measured removal cost.
    """
    line = src.lines[idx]
    m = WAIVER_ALLOW_RE.search(line)
    if m and m.group(1) == code and WAIVER_ALLOW_RE.search(src.code[idx]) is None:
        return True
    # `measured` counts only inside a comment: present in the raw line but
    # blanked out of the sanitized view.
    if "measured" in line and "measured" not in src.code[idx]:
        return True
    if _scan_waiver(src, idx, code, 3):
        return True
    marker = _enclosing_marker(src, idx)
    return marker is not None and _scan_waiver(src, marker, code, 6)


def _scan_waiver(src, idx, code, depth):
    checked = 0
    j = idx
    while j > 0 and checked < depth:
        j -= 1
        line = src.lines[j]
        stripped = line.strip()
        if not stripped:
            continue
        if MARKER_RE.match(line):
            continue  # annotations sit above the marker, the site below it
        m = WAIVER_ALLOW_RE.search(line)
        if m:
            return m.group(1) == code
        # `measured` counts only inside a comment.  The sanitized view blanks
        # comment text, so presence in `lines` but absence in `code` proves it.
        if "measured" in line and "measured" not in src.code[j]:
            return True
        checked += 1
        is_comment = (stripped.startswith("/*") or stripped.startswith("//")
                      or stripped.startswith("*") or stripped.endswith("*/")
                      or not src.code[j].strip())
        if not (is_comment or stripped.startswith("#")):
            break
    return False


def _enclosing_marker(src, idx):
    """Index of the nearest `// FUN_` marker at or above `idx`, else None."""
    for j in range(idx, max(-1, idx - 600), -1):
        if MARKER_RE.match(src.lines[j]):
            return j
    return None


# --------------------------------------------------------------------- rules
# Each rule is `def check_xxx(src) -> iterable[Finding]`.

VOLATILE_RE = re.compile(r"\bvolatile\b")
HEX_RE = re.compile(r"0[xX]([0-9a-fA-F]{6,8})")


def _is_hardware_line(line):
    for m in HEX_RE.finditer(line):
        v = int(m.group(1), 16)
        for lo, hi in HARDWARE_RANGES:
            if lo <= v < hi:
                return True
    return False


def check_volatile(src):
    for i, line in enumerate(src.code):
        if not VOLATILE_RE.search(line):
            continue
        if "__asm__" in line or re.search(r"\basm\b", line):
            continue  # asm volatile is rule H002's business
        if _is_hardware_line(line):
            continue
        if waived(src, i, "H001"):
            continue
        yield Finding("H001", src.rel(), i + 1,
                      "volatile on data with no hardware address in scope",
                      src.lines[i].strip())


ASM_BARRIER_RE = re.compile(r"(?:__asm__|\basm\b)\s*(?:__volatile__|volatile)?\s*\(\s*\"\"")


def check_asm_barrier(src):
    for i, line in enumerate(src.lines):
        if not ASM_BARRIER_RE.search(line):
            continue
        if waived(src, i, "H002"):
            continue
        yield Finding("H002", src.rel(), i + 1,
                      "zero-width asm barrier with no measured justification",
                      line.strip())


BANNED_PRAGMA_RE = re.compile(
    r"#\s*pragma\s+(optimization_level\s+[01]\b"
    r"|schedule\s+off\b"
    r"|opt_common_subs\s+off\b"
    r"|opt_rebuildconditionals\s+(?:on|off)\b)")


def check_banned_pragma(src):
    for i, line in enumerate(src.code):
        m = BANNED_PRAGMA_RE.search(line)
        if not m:
            continue
        if waived(src, i, "H003"):
            continue
        yield Finding("H003", src.rel(), i + 1,
                      f"banned pragma `{m.group(1).strip()}` with no measured justification",
                      src.lines[i].strip())


# `x = x + 0.0f;`  `x = x * 1.0f;`  `x += 0;`  `x *= 1;`
# The lvalue may be a name, a field path, or an index: `c.a`, `p->a`, `v[2]`.
# A statement starts at line start or just after `{`, `}` or `;`.
_STMT = r"(?:^|[{};])\s*"
_LV = r"[A-Za-z_][A-Za-z0-9_.\[\]>-]*"
NOOP_ASSIGN_RE = re.compile(
    _STMT + r"(" + _LV + r")\s*=\s*\1\s*[+\-]\s*0(?:\.0*)?[fF]?\s*;")
NOOP_MUL_RE = re.compile(
    _STMT + r"(" + _LV + r")\s*=\s*\1\s*[*/]\s*1(?:\.0*)?[fF]?\s*;")
NOOP_COMPOUND_RE = re.compile(
    _STMT + _LV + r"\s*(?:\+=|-=)\s*0(?:\.0*)?[fF]?\s*;"
    r"|" + _STMT + _LV + r"\s*(?:\*=|/=)\s*1(?:\.0*)?[fF]?\s*;")


def check_noop_identity(src):
    for i, line in enumerate(src.code):
        if not (NOOP_ASSIGN_RE.search(line) or NOOP_MUL_RE.search(line)
                or NOOP_COMPOUND_RE.search(line)):
            continue
        if waived(src, i, "H004"):
            continue
        yield Finding("H004", src.rel(), i + 1,
                      "no-op arithmetic identity; fold the computation into the "
                      "expression it represents instead",
                      src.lines[i].strip())


# The float->unsigned bias dance MWCC emits itself from `(u32)f`.
BIAS_RE = re.compile(r"2147483648(?:\.0*)?[fF]?|0x4[fF]000000\b|2\.147483[eE]\+?0?9")


def check_handwritten_ufloat(src):
    for i, line in enumerate(src.code):
        if not BIAS_RE.search(line):
            continue
        if waived(src, i, "H005"):
            continue
        yield Finding("H005", src.rel(), i + 1,
                      "hand-written float-to-unsigned bias expansion; use a plain "
                      "(u32) cast and let the compiler emit the sequence",
                      src.lines[i].strip())


IF1_RE = re.compile(r"\bif\s*\(\s*1\s*\)")
DOWHILE0_RE = re.compile(r"\bdo\s*\{.*\}\s*while\s*\(\s*0\s*\)|\bwhile\s*\(\s*0\s*\)\s*;")


def check_layout_wrapper(src):
    for i, line in enumerate(src.code):
        if not (IF1_RE.search(line) or DOWHILE0_RE.search(line)):
            continue
        # A do{}while(0) inside a #define is the standard C macro idiom.
        if _in_macro_definition(src, i):
            continue
        if waived(src, i, "H006"):
            continue
        yield Finding("H006", src.rel(), i + 1,
                      "layout wrapper with no semantic effect", src.lines[i].strip())


def _in_macro_definition(src, idx):
    """True if line `idx` is part of a `#define`, following `\\` continuations.

    `do { ... } while (0)` is the canonical way to make a multi-statement
    macro behave like one statement, so it is only a finding in real code.
    """
    if re.match(r"\s*#\s*define\b", src.code[idx]):
        return True
    j = idx - 1
    while j >= 0:
        prev = src.code[j].rstrip()
        if not prev.endswith("\\"):
            return False
        if re.match(r"\s*#\s*define\b", src.code[j]):
            return True
        j -= 1
    return False


REGISTER_RE = re.compile(r"(?:^|[{};])\s*register\s+[A-Za-z_]")


def check_register_local(src):
    for i, line in enumerate(src.code):
        if not REGISTER_RE.search(line):
            continue
        if waived(src, i, "H008"):
            continue
        yield Finding("H008", src.rel(), i + 1,
                      "`register` on an ordinary local is a codegen hint, not a decompilation",
                      src.lines[i].strip())


# ------------------------------------------------------- function extraction

DECL_RE = re.compile(
    r"^\s*(?:const\s+|static\s+|volatile\s+|unsigned\s+|signed\s+)*"
    r"([A-Za-z_][A-Za-z0-9_]*)\s+(\**)\s*([A-Za-z_][A-Za-z0-9_]*)\s*"
    r"(?:\[[^\]]*\])*\s*;\s*$")

CONTROL_KEYWORDS = {
    "if", "else", "for", "while", "do", "switch", "case", "default", "return",
    "break", "continue", "goto", "sizeof", "struct", "union", "enum", "typedef",
}


def iter_functions(src):
    """Yield (start_idx, end_idx) for each top-level `{...}` function body."""
    depth = 0
    start = None
    for i, line in enumerate(src.code):
        if re.match(r"\s*#", line):
            continue
        opens = line.count("{")
        closes = line.count("}")
        if depth == 0 and opens:
            start = i
        depth += opens - closes
        if start is not None and depth <= 0 and (opens or closes):
            yield start, i
            start = None
            depth = 0


def check_dead_store(src):
    """A local declared, assigned exactly once, and never read.

    Two very different defects produce this shape, and both matter:

    * WINDOW FILL -- a store added only so the instructions exist.  Banned.
    * A SILENTLY ELIMINATED STORE -- the decompiler emitted separate stack
      scalars where the original had one aggregate whose address was taken.
      Only the addressed member survives; MWCC dead-store-eliminates the
      rest, so the function compiles UNDERSIZED against its retail window
      and no amount of register tuning recovers the missing bytes.  The fix
      is to model the real aggregate.

    Either way the store is not doing what the source claims.  Anything read
    anywhere, or whose address is taken, is left alone.
    """
    for start, end in iter_functions(src):
        body = src.code[start:end + 1]
        decls = {}
        for off, line in enumerate(body):
            m = DECL_RE.match(line)
            if not m:
                continue
            base, stars, name = m.group(1), m.group(2), m.group(3)
            if base in CONTROL_KEYWORDS or name in CONTROL_KEYWORDS:
                continue
            if "volatile" in line:
                continue  # H001 owns that; do not double-report
            decls[name] = off
        if not decls:
            continue
        counts = Counter()
        for line in body:
            for tok in IDENT_RE.findall(line):
                counts[tok] += 1
        for name, off in decls.items():
            if counts[name] != 2:
                continue
            # Locate the single non-declaration mention and require it to be a
            # plain assignment target.
            hits = [k for k, l in enumerate(body)
                    if k != off and re.search(r"\b" + re.escape(name) + r"\b", l)]
            if len(hits) != 1:
                continue
            use = body[hits[0]]
            if not re.match(r"\s*" + re.escape(name) + r"\s*(?:=[^=]|\+=|-=|\*=|/=)", use):
                continue
            if "&" + name in use.replace(" ", ""):
                continue
            idx = start + hits[0]
            if waived(src, idx, "H007"):
                continue
            yield Finding("H007", src.rel(), idx + 1,
                          f"`{name}` is assigned here and never read",
                          src.lines[idx].strip())


# ------------------------------------------------------------ marker hygiene

def scan_markers(src):
    out = []
    for i, line in enumerate(src.lines):
        m = MARKER_RE.match(line)
        if m:
            out.append((i, m.group(1), m.group(2), m.group(3)))
    return out


def check_markers(src):
    markers = scan_markers(src)
    seen = defaultdict(list)
    for i, _full, addr, tail in markers:
        seen[addr.lower()].append(i + 1)

        # M004: the tag verify.py looks for is exactly "NONMATCHING".
        t = tail.strip()
        if t and "NONMATCHING" not in tail and re.search(r"(?i)nonmatching", tail):
            yield Finding("M004", src.rel(), i + 1,
                          "NONMATCHING tag is mis-cased; verify.py matches it case-sensitively",
                          src.lines[i].strip())

        # M002 / M003: walk to the definition, rejecting comments in between.
        j = i + 1
        found = False
        limit = i + 24
        while j < len(src.lines) and j < limit:
            nxt = src.lines[j]
            if MARKER_RE.match(nxt):
                break
            stripped = nxt.strip()
            if not stripped:
                j += 1
                limit += 1          # blank padding must not exhaust the window
                continue
            if stripped.startswith("//") or stripped.startswith("/*") or stripped.startswith("*"):
                yield Finding("M002", src.rel(), j + 1,
                              f"comment between marker {addr} and its definition",
                              stripped)
                j += 1
                continue
            if stripped.startswith("#"):
                j += 1
                continue
            if "(" in src.code[j] or "{" in src.code[j]:
                found = True
            break
        if not found and j < len(src.lines):
            # tolerate a multi-line header
            hdr = " ".join(src.code[i + 1:min(i + 30, len(src.code))])
            found = "(" in hdr
        if not found:
            yield Finding("M003", src.rel(), i + 1,
                          f"marker {addr} has no function definition beneath it",
                          src.lines[i].strip())

    for addr, lines in seen.items():
        if len(lines) > 1:
            yield Finding("M001", src.rel(), lines[0],
                          f"marker FUN_{addr} appears {len(lines)} times "
                          f"(lines {', '.join(map(str, lines))})")


# ------------------------------------------------------------ pragma balance

ONOFF_RE = re.compile(r"#\s*pragma\s+([A-Za-z_][A-Za-z0-9_]*)\s+(on|off)\b")
PUSH_RE = re.compile(r"#\s*pragma\s+push\b")
POP_RE = re.compile(r"#\s*pragma\s+pop\b")

# Pragmas whose on/off is a genuine mode switch, not a bracket.
ONOFF_EXEMPT = {"once"}


def check_pragma_balance(src):
    """Model MWCC's pragma state stack.

    `#pragma push` saves the whole pragma state and `#pragma pop` restores it,
    so an `on`/`off` switched inside a push/pop bracket is NOT an imbalance --
    the pop undoes it.  Only state that differs from the file's starting state
    at EOF leaks into whatever includes or follows this translation unit.
    """
    push = pop = 0
    first_unmatched_pop = None
    stack = []
    bal = defaultdict(int)      # +1 per `on`, -1 per `off`; zero == restored
    firstline = {}
    for i, line in enumerate(src.code):
        if PUSH_RE.search(line):
            push += 1
            stack.append(dict(bal))
            continue
        if POP_RE.search(line):
            pop += 1
            if stack:
                bal = defaultdict(int, stack.pop())
            elif first_unmatched_pop is None:
                first_unmatched_pop = i + 1
            continue
        m = ONOFF_RE.search(line)
        if not m:
            continue
        name, mode = m.group(1), m.group(2)
        if name in ONOFF_EXEMPT:
            continue
        bal[name] += 1 if mode == "on" else -1
        firstline.setdefault(name, i + 1)

    if push != pop:
        yield Finding("P001", src.rel(), first_unmatched_pop or 1,
                      f"#pragma push/pop unbalanced: {push} push, {pop} pop")
    if push > pop:
        yield Finding("P003", src.rel(), len(src.lines),
                      f"{push - pop} #pragma push scope(s) still open at end of file")
    for name, n in sorted(bal.items()):
        if n == 0:
            continue
        left = "off" if n < 0 else "on"
        yield Finding("P002", src.rel(), firstline[name],
                      f"pragma `{name}` is left `{left}` at end of file "
                      f"({abs(n)} unmatched); bracket it with #pragma push/pop "
                      f"or restore it explicitly")


# ------------------------------------------------------- decompilation quality

RAW_OFFSET_RE = re.compile(
    r"\*\(\s*[A-Za-z_][A-Za-z0-9_]*\s*\**\s*\*\s*\)\s*\(\s*[A-Za-z_][A-Za-z0-9_]*\s*\+\s*0x[0-9a-fA-F]+\s*\)")


def check_raw_offset(src):
    for i, line in enumerate(src.code):
        for _ in RAW_OFFSET_RE.finditer(line):
            yield Finding("S001", src.rel(), i + 1,
                          "raw-offset access; model the object as a struct",
                          src.lines[i].strip())
            break


GHIDRA_RE = re.compile(
    r"\b(param_\d+|[a-z]Var\d+|local_[0-9a-fA-F]+|[a-z]Stack_[0-9a-fA-F]+"
    r"|undefined[248]?|extraout_[A-Za-z0-9_]+|unaff_[A-Za-z0-9_]+"
    r"|in_[a-z]{1,2}\d?_(?:lo|hi)|uRam[0-9a-fA-F]+)\b")


def check_ghidra_residue(src):
    for i, line in enumerate(src.code):
        names = sorted(set(GHIDRA_RE.findall(line)))
        if not names:
            continue
        yield Finding("S002", src.rel(), i + 1,
                      "un-renamed decompiler output: " + ", ".join(names[:4]),
                      src.lines[i].strip())


# `*(u8 *)(p + 0x10) = a;` / `q->r = a;` / `c[0] = a;`
MEMBER_STORE_RE = re.compile(
    r"^\s*\*\(\s*(u8|s8|char|u16|s16|short)\s*\*\s*\)\s*\(\s*([A-Za-z_][A-Za-z0-9_]*)\s*\+\s*(0x[0-9a-fA-F]+|\d+)\s*\)\s*=")
INDEX_STORE_RE = re.compile(
    r"^\s*([A-Za-z_][A-Za-z0-9_]*)\s*\[\s*(\d+)\s*\]\s*=")


def check_scalarized_aggregate(src):
    """Runs of consecutive byte/halfword stores to one base at adjacent offsets.

    Splitting a packed value into per-member stores lets MWCC common the
    address into a register and reuse an already-live copy; retail addresses
    the slot directly and reloads each byte.  No amount of register or
    lifetime tuning undoes it -- the commoning happens first.  Expressing the
    write as one typed aggregate copy is the fix.
    """
    runs = []
    cur = []

    def flush():
        if len(cur) >= 3:
            runs.append(list(cur))
        cur.clear()

    for i, line in enumerate(src.code):
        if not line.strip():
            continue  # blank lines do not break a run
        m = MEMBER_STORE_RE.match(line)
        key = off = None
        if m:
            key = ("ptr", m.group(2))
            off = int(m.group(3), 0)
        else:
            m2 = INDEX_STORE_RE.match(line)
            if m2:
                key = ("idx", m2.group(1))
                off = int(m2.group(2))
        if key is None:
            flush()
            continue
        if cur and cur[-1][1] != key:
            flush()
        if cur and off in {o for _, _, o in cur}:
            flush()
        cur.append((i, key, off))
    flush()

    for run in runs:
        offs = sorted(o for _, _, o in run)
        span = offs[-1] - offs[0]
        if span > 4 * len(run):
            continue  # scattered, not one packed object
        idx = run[0][0]
        if waived(src, idx, "S003"):
            continue
        yield Finding("S003", src.rel(), idx + 1,
                      f"{len(run)} consecutive member stores to `{run[0][1][1]}` at "
                      f"offsets {offs}; use one typed aggregate copy",
                      src.lines[idx].strip())


OLDSTYLE_RE = re.compile(
    r"^\s*extern\s+[A-Za-z_][A-Za-z0-9_ \t\*]*\s+([A-Za-z_][A-Za-z0-9_]*)\s*\(\s*\)\s*;")


def check_oldstyle_decl(src):
    for i, line in enumerate(src.code):
        m = OLDSTYLE_RE.match(line)
        if not m:
            continue
        if waived(src, i, "S004"):
            continue
        yield Finding("S004", src.rel(), i + 1,
                      f"`{m.group(1)}` declared with an empty parameter list; "
                      f"argument-count errors will compile silently",
                      src.lines[i].strip())


PROTO_RE = re.compile(
    r"^\s*extern\s+(.+?)\b([A-Za-z_][A-Za-z0-9_]*)\s*\((.*?)\)\s*;")


def check_conflicting_decls(src):
    sigs = defaultdict(list)
    for i, line in enumerate(src.code):
        m = PROTO_RE.match(line)
        if not m:
            continue
        ret = " ".join(m.group(1).split())
        params = " ".join(m.group(3).split())
        sigs[m.group(2)].append((i + 1, ret, params))
    for name, entries in sigs.items():
        shapes = {(r, p) for _, r, p in entries}
        if len(shapes) > 1:
            lines = ", ".join(str(e[0]) for e in entries)
            yield Finding("S005", src.rel(), entries[0][0],
                          f"`{name}` declared with {len(shapes)} different "
                          f"signatures (lines {lines})")


FLOAT_CTX_RE = re.compile(r"\b(f32|float)\b")
UNSUFFIXED_RE = re.compile(r"(?<![A-Za-z0-9_.])(\d+\.\d*|\.\d+)(?![fFeEdD0-9.])")


def check_double_literal(src):
    for i, line in enumerate(src.code):
        if not FLOAT_CTX_RE.search(line):
            continue
        lits = UNSUFFIXED_RE.findall(line)
        if not lits:
            continue
        yield Finding("S006", src.rel(), i + 1,
                      "un-suffixed literal " + ", ".join(sorted(set(lits))[:3])
                      + " in float context promotes the expression to double",
                      src.lines[i].strip())


# ------------------------------------------------------------------ corruption

# A deliberate typed alias is always `FUN_xxxxxxxx_suffix` -- the tree has 129
# distinct ones (`_abs`, `_u32`, `_typed`, `_call`, ...).  A bad search/replace
# instead welds characters straight onto the hex, e.g. a float-suffix regex
# turning `FUN_00358a30` into `FUN_00358a30f`.  The missing underscore is the
# reliable discriminator, so only that shape is a finding.
MANGLED_RE = re.compile(r"\b((?:FUN|DAT)_[0-9a-fA-F]{8})([A-Za-z][A-Za-z0-9_]*)\b")


def check_mangled_identifier(src):
    for i, line in enumerate(src.code):
        for m in MANGLED_RE.finditer(line):
            suffix = m.group(2)
            yield Finding("C001", src.rel(), i + 1,
                          f"`{m.group(0)}` looks like `{m.group(1)}` with a stray "
                          f"`{suffix}` appended by a bad edit",
                          src.lines[i].strip())


def check_line_endings(src):
    if src.crlf and src.lf:
        yield Finding("C002", src.rel(), 1,
                      f"mixed line endings: {src.crlf} CRLF and {src.lf} bare LF; "
                      f"byte splices against the wrong ending silently no-op")


def check_braces(src):
    """Net brace depth over real code.

    Preprocessor lines are excluded, and so are the CONTINUATION lines of a
    multi-line `#define` -- a macro body like `do { ... } while (0)` spread
    over several backslash-continued lines contributes an unmatched `}` to a
    naive count and makes every large file look corrupt.
    """
    depth = 0
    for i, line in enumerate(src.code):
        if re.match(r"\s*#", line) or _in_macro_definition(src, i):
            continue
        depth += line.count("{") - line.count("}")
    if depth != 0:
        yield Finding("C003", src.rel(), len(src.lines),
                      f"brace depth ends at {depth:+d}")


CHECKS = (
    check_volatile, check_asm_barrier, check_banned_pragma, check_noop_identity,
    check_handwritten_ufloat, check_layout_wrapper, check_dead_store,
    check_register_local,
    check_markers, check_pragma_balance,
    check_raw_offset, check_ghidra_residue, check_scalarized_aggregate,
    check_oldstyle_decl, check_conflicting_decls, check_double_literal,
    check_mangled_identifier, check_line_endings, check_braces,
)


def lint_source(src):
    out = []
    for check in CHECKS:
        out.extend(check(src))
    out.sort(key=lambda f: (f.line, f.code))
    return out


# ----------------------------------------------------------------------- CLI

def gather(paths, excludes):
    files = []
    for p in paths:
        p = Path(p)
        if p.is_dir():
            files.extend(sorted(p.rglob("*.c")) + sorted(p.rglob("*.h")))
        elif p.exists():
            files.append(p)
        else:
            sys.stderr.write(f"decomp_lint: no such path: {p}\n")
    out = []
    for f in files:
        try:
            rel = f.resolve().relative_to(ROOT).as_posix()
        except ValueError:
            rel = f.as_posix()
        if any(rel.startswith(x) or rel == x.rstrip("/") for x in excludes):
            continue
        out.append(f)
    return out


def main():
    ap = argparse.ArgumentParser(
        description=__doc__.splitlines()[0],
        formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("paths", nargs="*", help="files or directories (default: src include)")
    ap.add_argument("--json", metavar="OUT", help="write findings as JSON")
    ap.add_argument("--select", help="comma-separated codes or prefixes to keep")
    ap.add_argument("--ignore", help="comma-separated codes or prefixes to drop")
    ap.add_argument("--severity", choices=("info", "warn", "error"), default="info",
                    help="minimum severity to report (default info)")
    ap.add_argument("--summary", action="store_true", help="counts only, no per-finding lines")
    ap.add_argument("--max", type=int, default=0, metavar="N",
                    help="print at most N findings per rule (0 = all)")
    ap.add_argument("--exclude", action="append", default=[],
                    help="extra path prefix to skip (repeatable)")
    ap.add_argument("--no-default-excludes", action="store_true",
                    help="also lint vendored/runtime sources")
    ap.add_argument("--list", action="store_true", help="describe every rule and exit")
    args = ap.parse_args()

    if args.list:
        for code in sorted(RULES):
            sev, desc = RULES[code]
            print(f"{code}  {sev:<5}  {desc}")
        return 0

    paths = args.paths or [ROOT / "src", ROOT / "include"]
    excludes = list(args.exclude)
    if not args.no_default_excludes:
        excludes += list(DEFAULT_EXCLUDES)

    def keep(code):
        if args.select:
            if not any(code.startswith(s.strip()) for s in args.select.split(",") if s.strip()):
                return False
        if args.ignore:
            if any(code.startswith(s.strip()) for s in args.ignore.split(",") if s.strip()):
                return False
        return SEVERITY_ORDER[RULES[code][0]] >= SEVERITY_ORDER[args.severity]

    files = gather(paths, excludes)
    findings = []
    for f in files:
        try:
            src = Source(f, f.read_bytes())
        except OSError as exc:
            sys.stderr.write(f"decomp_lint: cannot read {f}: {exc}\n")
            continue
        findings.extend(x for x in lint_source(src) if keep(x.code))

    by_code = Counter(f.code for f in findings)
    by_sev = Counter(f.severity for f in findings)

    if not args.summary:
        shown = Counter()
        for f in sorted(findings, key=lambda x: (x.file, x.line, x.code)):
            if args.max and shown[f.code] >= args.max:
                continue
            shown[f.code] += 1
            print(f"{f.file}:{f.line}: {f.severity}: [{f.code}] {f.message}")
            if f.text:
                print(f"    {f.text}")

    print(f"\ndecomp_lint: {len(files)} files, {len(findings)} findings "
          f"({by_sev['error']} error, {by_sev['warn']} warn, {by_sev['info']} info)")
    for code, n in sorted(by_code.items()):
        print(f"  {code}  {RULES[code][0]:<5} {n:>7}  {RULES[code][1]}")

    if args.json:
        Path(args.json).write_text(json.dumps(dict(
            files=len(files),
            summary_by_code={c: n for c, n in sorted(by_code.items())},
            summary_by_severity=dict(by_sev),
            rules={c: dict(severity=s, description=d) for c, (s, d) in RULES.items()},
            findings=[f.as_dict() for f in findings]), indent=1))
        print(f"report: {args.json}")

    return 1 if by_sev["error"] else 0


if __name__ == "__main__":
    sys.exit(main())
