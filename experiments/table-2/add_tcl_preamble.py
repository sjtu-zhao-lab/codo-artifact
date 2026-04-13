#!/usr/bin/env python3
from __future__ import annotations

import argparse
from pathlib import Path


PREAMBLE_LINES = [
    "set script_path [file normalize [info script]]\n",
    "set script_dir [file dirname $script_path]\n",
    "cd $script_dir\n",
]


def normalize_path(raw: str) -> Path:
    return Path(raw.replace("\\", "/")).expanduser().resolve()


def ensure_preamble(path: Path) -> bool:
    text = path.read_text(encoding="utf-8", errors="ignore")
    if text.startswith("".join(PREAMBLE_LINES)):
        return False

    lines = text.splitlines(keepends=True)
    if len(lines) >= 3 and lines[0] == PREAMBLE_LINES[0] and lines[1] == PREAMBLE_LINES[1] and lines[2] == PREAMBLE_LINES[2]:
        return False

    new_text = "".join(PREAMBLE_LINES) + text
    path.write_text(new_text, encoding="utf-8")
    return True


def main() -> None:
    parser = argparse.ArgumentParser(description="Prepend standard preamble lines to all .tcl scripts under folders.")
    parser.add_argument("folders", nargs="+", help="Folders to scan (baseline/hida/streamhls)")
    args = parser.parse_args()

    tcl_files: list[Path] = []
    for folder in args.folders:
        root = normalize_path(folder)
        if not root.exists() or not root.is_dir():
            raise SystemExit(f"Folder not found: {root}")
        tcl_files.extend(sorted(root.rglob("*.tcl")))

    modified = []
    for tcl in tcl_files:
        if ensure_preamble(tcl):
            modified.append(tcl)

    print(f"Found .tcl files: {len(tcl_files)}")
    print(f"Modified files: {len(modified)}")
    for p in modified:
        print(str(p))


if __name__ == "__main__":
    main()
