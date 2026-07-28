from __future__ import annotations

import importlib.util
import tempfile
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
MODULE_PATH = REPO / "tools" / "decomp_lint.py"
SPEC = importlib.util.spec_from_file_location("p3_decomp_lint", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
lint = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(lint)


def check(source: str, name: str = "t.c", newline: str = "\n"):
    """Lint an in-memory translation unit, returning {code: [findings]}."""
    with tempfile.TemporaryDirectory() as directory:
        path = Path(directory) / name
        path.write_bytes(source.replace("\n", newline).encode())
        src = lint.Source(path, path.read_bytes())
        out: dict[str, list] = {}
        for f in lint.lint_source(src):
            out.setdefault(f.code, []).append(f)
        return out


def codes(source: str, **kw):
    return set(check(source, **kw))


class HonestyRuleTests(unittest.TestCase):
    def test_noop_add_zero_is_flagged(self):
        found = check("""
void f(void)
{
    f32 square;
    square = axis[0] * axis[0];
    square = square + 0.0f;
    use(square);
}
""")
        self.assertIn("H004", found)
        self.assertEqual(found["H004"][0].line, 6)

    def test_noop_multiply_one_and_compound_forms(self):
        self.assertIn("H004", codes("void f(void){ x = x * 1.0f; }"))
        self.assertIn("H004", codes("void f(void){ x += 0; }"))
        self.assertIn("H004", codes("void f(void){ y.a[2] = y.a[2] + 0.0f; }"))

    def test_real_arithmetic_is_not_flagged(self):
        self.assertNotIn("H004", codes("void f(void){ x = x + 1.0f; }"))
        self.assertNotIn("H004", codes("void f(void){ x = y + 0.0f; }"))
        self.assertNotIn("H004", codes("void f(void){ x = x * 2; }"))

    def test_noop_in_comment_or_string_is_ignored(self):
        self.assertNotIn("H004", codes('void f(void){ log("x = x + 0.0f;"); }'))
        self.assertNotIn("H004", codes("/* x = x + 0.0f; */\nvoid f(void){}"))

    def test_volatile_on_plain_data_is_flagged_hardware_is_not(self):
        self.assertIn("H001", codes("void f(void){ volatile int spin; }"))
        self.assertNotIn(
            "H001", codes("void f(void){ volatile u32 *gs = (u32 *)0x12001000; }"))

    def test_zero_width_barrier_is_flagged(self):
        self.assertIn("H002", codes(
            'void f(void){ __asm__ volatile ("" : : "r"(x) : "memory"); }'))

    def test_real_asm_is_not_a_barrier(self):
        self.assertNotIn("H002", codes(
            'void f(void){ __asm__ volatile ("sqc2 vf10, 0(%0)" : : "r"(p)); }'))

    def test_banned_pragmas_flagged_and_annotated_ones_waived(self):
        self.assertIn("H003", codes("#pragma optimization_level 1\nvoid f(void){}"))
        self.assertIn("H003", codes("#pragma schedule off\nvoid f(void){}"))
        # optimization_level 2 and 3 are not on the banned list.
        self.assertNotIn("H003", codes("#pragma optimization_level 3\nvoid f(void){}"))

    def test_measured_annotation_waives_a_banned_pragma(self):
        self.assertNotIn("H003", codes(
            "/* Removing this loses fn (MATCH nd0 -> MISMATCH nd13) - measured W161. */\n"
            "#pragma optimization_level 1\nvoid f(void){}"))

    def test_annotation_waives_across_an_intervening_marker(self):
        # The tree annotates above the marker and puts the pragma below it.
        self.assertNotIn("H003", codes(
            "/* Removing this worsens FUN_00320810 (nd8 -> nd19) - measured W161. */\n"
            "// FUN_00320810 NONMATCHING\n"
            "#pragma optimization_level 1\nvoid f(void){}"))

    def test_explicit_allow_waives_only_its_own_code(self):
        self.assertNotIn("H008", codes(
            "void f(void){\n/* lint: allow H008 */\nregister int i;\n}"))
        self.assertIn("H008", codes(
            "void f(void){\n/* lint: allow H001 */\nregister int i;\n}"))

    def test_handwritten_unsigned_float_expansion(self):
        self.assertIn("H005", codes(
            "void f(void){ if (a < 2147483648.0f) { b = (s32)a; } }"))

    def test_register_local_is_flagged(self):
        self.assertIn("H008", codes("void f(void){ register u8 *ctx; }"))

    def test_do_while_zero_in_macro_is_allowed_but_in_code_is_not(self):
        self.assertNotIn("H006", codes(
            "#define ONCE(x) do { x; } while (0)\nvoid f(void){}"))
        self.assertIn("H006", codes("void f(void){ do { g(); } while (0); }"))

    def test_multiline_macro_continuation_is_still_a_macro(self):
        self.assertNotIn("H006", codes(
            "#define TWO(a, b) \\\n"
            "    do { a; b; } while (0)\n"
            "void f(void){}"))


class DeadStoreTests(unittest.TestCase):
    def test_store_never_read_is_flagged(self):
        found = check("""
void f(int base)
{
    u32 keep;
    u32 dropped;
    keep = *(u32 *)(base + 0x18);
    dropped = *(u32 *)(base + 0x1c);
    use(keep);
}
""")
        self.assertIn("H007", found)
        names = [f.message for f in found["H007"]]
        self.assertTrue(any("dropped" in m for m in names))
        self.assertFalse(any("keep" in m for m in names))

    def test_address_taken_local_is_not_dead(self):
        self.assertNotIn("H007", codes("""
void f(int base)
{
    u32 slot;
    slot = *(u32 *)(base + 0x18);
    consume(&slot);
}
"""))

    def test_local_read_later_is_not_dead(self):
        self.assertNotIn("H007", codes("""
void f(int base)
{
    u32 slot;
    slot = *(u32 *)(base + 0x18);
    if (slot != 0) { g(); }
}
"""))

    def test_volatile_local_is_left_to_the_volatile_rule(self):
        found = check("void f(void){ volatile u32 sink; sink = read(); }")
        self.assertNotIn("H007", found)
        self.assertIn("H001", found)


class MarkerTests(unittest.TestCase):
    def test_duplicate_marker_address(self):
        found = check("""// FUN_00100000
void a(void){}
// FUN_00100000
void b(void){}
""")
        self.assertIn("M001", found)

    def test_duplicate_detection_is_case_insensitive(self):
        self.assertIn("M001", codes("// FUN_0010ABCD\nvoid a(void){}\n"
                                    "// FUN_0010abcd\nvoid b(void){}\n"))

    def test_comment_between_marker_and_definition(self):
        found = check("""// FUN_00100000
/* explanatory note that breaks marker binding */
void a(void){}
""")
        self.assertIn("M002", found)
        self.assertEqual(found["M002"][0].line, 2)

    def test_pragma_between_marker_and_definition_is_allowed(self):
        self.assertNotIn("M002", codes("// FUN_00100000\n"
                                       "#pragma optimization_level 3\n"
                                       "void a(void){}\n"))

    def test_miscased_nonmatching_tag(self):
        self.assertIn("M004", codes("// FUN_00100000 NonMatching\nvoid a(void){}"))
        self.assertNotIn("M004", codes("// FUN_00100000 NONMATCHING\nvoid a(void){}"))

    def test_clean_markers_produce_nothing(self):
        found = check("// FUN_00100000 NONMATCHING\nvoid a(void){}\n"
                      "// FUN_00100020\nvoid b(void){}\n")
        for code in ("M001", "M002", "M003", "M004"):
            self.assertNotIn(code, found)


class PragmaBalanceTests(unittest.TestCase):
    def test_unbalanced_push_is_reported_and_flagged_as_leaking(self):
        found = check("#pragma push\n#pragma optimization_level 3\nvoid f(void){}")
        self.assertIn("P001", found)
        self.assertIn("P003", found)

    def test_balanced_push_pop_is_clean(self):
        found = check("#pragma push\n#pragma optimization_level 3\n"
                      "void f(void){}\n#pragma pop\n")
        for code in ("P001", "P002", "P003"):
            self.assertNotIn(code, found)

    def test_onoff_inside_push_pop_is_restored_by_the_pop(self):
        # This is the false positive that a naive counter produces.
        found = check("#pragma push\n#pragma opt_rebuildconditionals off\n"
                      "void f(void){}\n#pragma pop\n")
        self.assertNotIn("P002", found)

    def test_onoff_left_open_at_eof_is_reported(self):
        found = check("#pragma opt_loop_invariants off\nvoid f(void){}\n")
        self.assertIn("P002", found)

    def test_onoff_restored_explicitly_is_clean(self):
        found = check("#pragma opt_loop_invariants off\nvoid f(void){}\n"
                      "#pragma opt_loop_invariants on\n")
        self.assertNotIn("P002", found)


class QualityTests(unittest.TestCase):
    def test_scalarized_aggregate_run_is_flagged(self):
        found = check("""
void f(u8 *colour)
{
    colour[0] = 0xff;
    colour[1] = 0xff;
    colour[2] = 0xff;
    colour[3] = alpha;
}
""")
        self.assertIn("S003", found)

    def test_two_stores_are_not_a_run(self):
        self.assertNotIn("S003", codes("void f(u8 *c){ c[0] = 1; c[1] = 2; }"))

    def test_scattered_offsets_are_not_one_aggregate(self):
        self.assertNotIn("S003", codes("""
void f(u8 *p)
{
    p[0] = 1;
    p[40] = 2;
    p[900] = 3;
}
"""))

    def test_pointer_cast_member_stores_are_a_run(self):
        self.assertIn("S003", codes("""
void f(int o)
{
    *(u8 *)(o + 0x10) = r;
    *(u8 *)(o + 0x11) = g;
    *(u8 *)(o + 0x12) = b;
}
"""))

    def test_old_style_declaration(self):
        self.assertIn("S004", codes("extern u64 FUN_00358a30();"))
        self.assertNotIn("S004", codes("extern u64 FUN_00358a30(float a, void *b);"))

    def test_conflicting_declarations_in_one_file(self):
        found = check("extern u64 FUN_00358a30(int a);\n"
                      "extern void FUN_00358a30(float a, void *b);\n")
        self.assertIn("S005", found)

    def test_identical_redeclaration_is_not_a_conflict(self):
        self.assertNotIn("S005", codes("extern int g(int a);\nextern int g(int a);\n"))

    def test_ghidra_residue(self):
        self.assertIn("S002", codes("void f(int param_1){ int iVar2; }"))
        self.assertNotIn("S002", codes("void f(int index){ int count; }"))

    def test_raw_offset_access(self):
        self.assertIn("S001", codes("void f(int p){ *(u32 *)(p + 0x1c) = 0; }"))

    def test_unsuffixed_float_literal_in_float_context(self):
        self.assertIn("S006", codes("void f(void){ f32 x = 0.5; }"))
        self.assertNotIn("S006", codes("void f(void){ f32 x = 0.5f; }"))
        self.assertNotIn("S006", codes("void f(void){ int n = 5; }"))


class CorruptionTests(unittest.TestCase):
    def test_mangled_identifier_from_a_bad_suffix_edit(self):
        found = check("void f(void){ FUN_00358a30f(4.0f, p, q, 1); }")
        self.assertIn("C001", found)

    def test_legitimate_typed_aliases_are_not_mangled(self):
        for alias in ("DAT_00960178_abs", "FUN_00324160_u32", "FUN_0052ea18_2f",
                      "FUN_00325d60_ptr", "DAT_0069bd50_abs"):
            self.assertNotIn("C001", codes(f"void f(void){{ g({alias}); }}"), alias)

    def test_mixed_line_endings(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "m.c"
            path.write_bytes(b"void a(void){}\r\nvoid b(void){}\n")
            src = lint.Source(path, path.read_bytes())
            found = {f.code for f in lint.lint_source(src)}
        self.assertIn("C002", found)

    def test_consistent_line_endings_are_clean(self):
        self.assertNotIn("C002", codes("void a(void){}\nvoid b(void){}\n"))
        self.assertNotIn("C002", codes("void a(void){}\nvoid b(void){}\n",
                                       newline="\r\n"))

    def test_unbalanced_braces(self):
        self.assertIn("C003", codes("void f(void){\n  g();\n"))

    def test_braces_in_strings_do_not_unbalance(self):
        self.assertNotIn("C003", codes('void f(void){ puts("{"); }\n'))


class RegistryTests(unittest.TestCase):
    def test_every_rule_has_a_severity_and_description(self):
        for code, (sev, desc) in lint.RULES.items():
            self.assertIn(sev, lint.SEVERITY_ORDER, code)
            self.assertTrue(desc.strip(), code)

    def test_every_emitted_code_is_registered(self):
        sample = ("// FUN_00100000\n/* c */\nvoid f(int param_1){\n"
                  "  register int i;\n  x = x + 0.0f;\n}\n")
        for f in check(sample).get("H004", []):
            self.assertIn(f.code, lint.RULES)

    def test_clean_source_produces_no_findings(self):
        self.assertEqual(check("""// FUN_00100000
void modelSetFlag(ModelWork *work, s32 flag)
{
    work->flags = flag;
}
"""), {})


if __name__ == "__main__":
    unittest.main()
