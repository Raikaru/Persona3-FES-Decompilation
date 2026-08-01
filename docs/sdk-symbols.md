# SDK symbol tools

To compare a user-supplied SCE Runtime 3.0.2 archive corpus with retail without
copying SDK files into the repository:

```sh
python tools/sdk_match.py --sdk-root "<SDK>/Runtime" --json sdk-report.json
```

Use `--target-root PATH` for a repository outside the default layout and
`--windows PATH` to override boundary-file auto-detection.

`P3_PS2SDK_ROOT` may supply the root instead. The default pass scans
`libcdvd.a`, `libkernl.a`, `libmc.a`, `libmc2.a`, `libpad.a`, and `libpad2.a`;
repeat `--archive NAME` to choose archives explicitly. Results are
relocation-normalized identification evidence, not matching-C proof:
`tools/verify.py` remains the only per-function `MATCH` gate. Keep the
proprietary SDK and generated reports outside version control.

To promote only unambiguous archive matches into a symbol map, first generate
the JSON evidence report, then run the promotion tool against the target
repository:

```sh
python tools/promote_sdk_symbols.py \
  --report sdk-report.json --update-sources --apply
```

The tool promotes only `UNIQUE_NORMALIZED` rows whose address has one SDK
candidate and is still an anonymous `func_XXXXXXXX`/`FUN_XXXXXXXX` symbol.
It writes the names to `config/symbol_addrs.txt`, updates matching source
references when `--update-sources` is supplied, and records archive/member
metadata in the generated-on-demand `config/sdk_symbol_provenance.txt`.
Ambiguous candidates remain anonymous. The provenance file contains names and
hashes only; SDK object bytes are never copied into the repository.
After a promotion, regenerate ignored splat assembly with `make split` before
building so assembly references use the promoted labels.
`objdiff.json`, `diff_settings.py`, `permuter_settings.toml`, the `Dockerfile`,
and CI (`.github/workflows/ci.yml`) follow the standard mwcc/PS2 decomp layout.
