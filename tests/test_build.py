from __future__ import annotations

import importlib.util
import tempfile
import unittest
from pathlib import Path
from unittest import mock

REPO = Path(__file__).resolve().parents[1]
MODULE_PATH = REPO / "tools" / "build.py"
SPEC = importlib.util.spec_from_file_location("p3_build", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
build = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(build)


class CompileCacheIntegrationTests(unittest.TestCase):
    def test_link_compile_is_restored_without_running_mwccgap(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / "src" / "unit.c"
            output = root / "build" / "obj" / "unit.o"
            compiler = root / "mwcc.exe"
            assembler = root / "as.exe"
            objcopy = root / "objcopy.exe"
            macro = root / "asm" / "macro.inc"
            for path, content in (
                (source, b"int unit(void) { return 1; }\\n"),
                (compiler, b"mwcc"),
                (assembler, b"assembler"),
                (objcopy, b"objcopy"),
                (macro, b".macro dummy\\n.endm\\n"),
            ):
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_bytes(content)
            config = {
                "mwcc": str(compiler),
                "cflags": ["-O2"],
                "compile_flags": ["-O2", "-Iinclude"],
            }
            invocations = []

            def fake_sh(command, **_kwargs):
                invocations.append(command)
                Path(command[3]).write_bytes(b"linked-object")
                return ""

            patches = (
                mock.patch.object(build, "REPO", root),
                mock.patch.object(build, "ASM", root / "asm"),
                mock.patch.object(build, "AS_TOOL", build.A.Tool((str(assembler),))),
                mock.patch.object(build, "OBJCOPY_TOOL", build.A.Tool((str(objcopy),))),
                mock.patch.object(build, "CACHE_TOOL_VERSIONS", {"assembler": "v1", "objcopy": "v1"}),
                mock.patch.object(build, "sh", fake_sh),
                mock.patch.object(build, "progbitsify", lambda _path: None),
            )
            with patches[0], patches[1], patches[2], patches[3], patches[4], patches[5], patches[6]:
                first = build.BC.ObjectCache(root / "build" / "cache" / "c", root)
                build.compile_c(config, source, output, first)
                output.unlink()
                second = build.BC.ObjectCache(root / "build" / "cache" / "c", root)
                build.compile_c(config, source, output, second)

            self.assertEqual(len(invocations), 1)
            self.assertEqual(output.read_bytes(), b"linked-object")
            self.assertEqual(second.stats["link"], {"hits": 1, "misses": 0})


if __name__ == "__main__":
    unittest.main()
