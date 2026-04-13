#!/usr/bin/env python3
""":"
exec python3 "$0" "$@"
":"""
from __future__ import annotations

import argparse
import re
import shutil
import sys
from dataclasses import dataclass
from pathlib import Path


FLOAT_TOKEN_RE = re.compile(r"\bfloat\b")


@dataclass(frozen=True)
class FileUpdateResult:
    path: Path
    replacements: int
    changed: bool


def replace_float_with_int8_t(text: str) -> tuple[str, int]:
    new_text, count = FLOAT_TOKEN_RE.subn("int8_t", text)
    return new_text, count


def process_file(path: Path, *, in_place: bool, backup: bool) -> FileUpdateResult:
    original = path.read_text(encoding="utf-8", errors="surrogateescape")
    updated, replacements = replace_float_with_int8_t(original)
    if updated == original:
        return FileUpdateResult(path=path, replacements=replacements, changed=False)

    if in_place:
        if backup:
            backup_path = path.with_suffix(path.suffix + ".bak")
            shutil.copy2(path, backup_path)
        path.write_text(updated, encoding="utf-8", errors="surrogateescape")
    return FileUpdateResult(path=path, replacements=replacements, changed=True)


def main(argv: list[str]) -> int:
    parser = argparse.ArgumentParser(
        description="Replace all C++ token 'float' with 'int8_t' in a fixed set of DNN source files."
    )
    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="Only report how many replacements would be made; do not write files.",
    )
    parser.add_argument(
        "--backup",
        action="store_true",
        help="When writing in place, create a .bak copy next to each modified file.",
    )
    args = parser.parse_args(argv)

    base_dir = Path(__file__).resolve().parent
    targets = [
        base_dir / "codo" / "3_32_32" / "mobilenet-small" / "mobilenet.cpp",
        base_dir / "codo" / "3_32_32" / "resnet-small" / "resnet18.cpp",
        base_dir / "codo" / "3_32_32" / "vgg-small" / "vgg16.cpp",
        base_dir / "codo" / "3_224_224" / "mobilenet-large" / "mobilenet.cpp",
        base_dir / "codo" / "3_224_224" / "resnet-large" / "resnet18.cpp",
        base_dir / "codo" / "3_224_224" / "vgg-large" / "vgg16.cpp",
        base_dir / "codo" / "3_224_224" / "yolo" / "yolo.cpp",
        base_dir / "codo" / "3_224_224" / "zfnet" / "zfnet.cpp",
    ]

    missing = [p for p in targets if not p.is_file()]
    if missing:
        for p in missing:
            print(f"[missing] {p}", file=sys.stderr)
        return 2

    results: list[FileUpdateResult] = []
    for path in targets:
        result = process_file(path, in_place=not args.dry_run, backup=args.backup)
        results.append(result)

    total_replacements = sum(r.replacements for r in results)
    changed_files = sum(1 for r in results if r.changed)
    mode = "dry-run" if args.dry_run else "in-place"
    print(f"mode={mode} files={len(results)} changed={changed_files} replacements={total_replacements}")
    for r in results:
        if r.replacements == 0:
            continue
        action = "would-change" if args.dry_run else ("changed" if r.changed else "unchanged")
        print(f"[{action}] {r.path} replacements={r.replacements}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
