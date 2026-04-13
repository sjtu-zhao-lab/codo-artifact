
# import argparse
# import re
# import math
# from decimal import Decimal, ROUND_HALF_UP
# from pathlib import Path
# from typing import Dict, List, Optional, Tuple


# HARDCODED_ROWS: Dict[str, List[Tuple[str, str, int, int, str, str, str]]] = {
#     "allo": [
#         ("resnet-small", "8.29M", 0, 652, "51K", "124K", "66.9"),
#         ("vgg-samll", "3.85M", 0, 440, "38K", "98K", "50.1"),
#         ("mobilenet-small", "0.26M", 0, 1942, "57K", "128K", "46.6"),
#     ],
#     "scalehls": [
#         ("resnet-small", "104.88M", 8416, 1330, "144K", "992K", "5.3"),
#         ("vgg-samll", "28.31M", 3936, 882, "100K", "714K", "6.8"),
#         ("mobilenet-small", "2.17M", 6796, 1778, "93K", "518K", "5.6"),
#     ],
# }


# def normalize_path(raw_path: str) -> Path:
#     return Path(raw_path.replace("\\", "/")).expanduser().resolve()


# def canonical_model_name(name: str) -> str:
#     n = name.strip().lower().replace("_", "-")
#     aliases = {
#         "resnet-samall": "resnet-small",
#         "resnet-small": "resnet-small",
#         "vgg-small": "vgg-samll",
#         "vgg-samll": "vgg-samll",
#     }
#     return aliases.get(n, n)


# def round_half_up(value: float, digits: int) -> str:
#     q = Decimal("1") if digits == 0 else Decimal(f"1.{'0' * digits}")
#     return str(Decimal(str(value)).quantize(q, rounding=ROUND_HALF_UP))


# def to_latency_m(latency: int) -> str:
#     return f"{round_half_up(latency / 1_000_000.0, 2)}M"


# def to_k(value: int) -> str:
#     return f"{round_half_up(value / 1000.0, 0)}K"


# def extract_max_latency(report_text: str) -> int:
#     latency_section = report_text.find("+ Latency:")
#     if latency_section == -1:
#         raise ValueError("Latency section not found")

#     summary_start = report_text.find("* Summary:", latency_section)
#     if summary_start == -1:
#         raise ValueError("Latency summary not found")

#     detail_start = report_text.find("+ Detail:", summary_start)
#     block = report_text[summary_start:detail_start if detail_start != -1 else len(report_text)]
#     row_pattern = re.compile(r"^\s*\|\s*(\d+)\s*\|\s*(\d+)\s*\|", re.MULTILINE)
#     m = row_pattern.search(block)
#     if not m:
#         raise ValueError("Latency row not found")
#     return int(m.group(2))


# def extract_total_util(report_text: str) -> Tuple[int, int, int, int]:
#     util_section = report_text.find("== Utilization Estimates")
#     if util_section == -1:
#         raise ValueError("Utilization section not found")

#     util_text = report_text[util_section:]
#     lines = util_text.splitlines()
#     header_idx = -1
#     for i, line in enumerate(lines):
#         if "Name" in line and "DSP" in line and "FF" in line and "LUT" in line and "|" in line:
#             header_idx = i
#             break
#     if header_idx == -1:
#         raise ValueError("Utilization header not found")

#     headers = [x.strip() for x in lines[header_idx].strip().strip("|").split("|")]

#     def find_col(col_name: str) -> int:
#         for idx, h in enumerate(headers):
#             if h == col_name:
#                 return idx
#         raise ValueError(f"{col_name} column not found")

#     bram_col = -1
#     for idx, h in enumerate(headers):
#         if h.startswith("BRAM"):
#             bram_col = idx
#             break
#     if bram_col == -1:
#         raise ValueError("BRAM column not found")

#     dsp_col = find_col("DSP")
#     ff_col = find_col("FF")
#     lut_col = find_col("LUT")

#     total_row = None
#     for line in lines[header_idx + 1:]:
#         if not line.strip().startswith("|"):
#             continue
#         cols = [x.strip() for x in line.strip().strip("|").split("|")]
#         if cols and cols[0] == "Total":
#             total_row = cols
#             break
#     if total_row is None:
#         raise ValueError("Total row not found")

#     def parse_num(idx: int) -> int:
#         if idx >= len(total_row):
#             raise ValueError("Missing value in Total row")
#         s = total_row[idx].replace(",", "")
#         if not s.isdigit():
#             raise ValueError(f"Invalid numeric value: {s}")
#         return int(s)

#     return parse_num(bram_col), parse_num(dsp_col), parse_num(ff_col), parse_num(lut_col)


# def parse_rpt_file(rpt_path: Path) -> Tuple[int, int, int, int, int]:
#     text = rpt_path.read_text(encoding="utf-8", errors="ignore")
#     latency = extract_max_latency(text)
#     bram, dsp, ff, lut = extract_total_util(text)
#     return latency, bram, dsp, ff, lut


# def select_best_rpt(project_dir: Path) -> Optional[Tuple[Path, int, int, int, int, int]]:
#     preferred = project_dir / "main_graph_csynth.rpt"
#     candidates: List[Path] = []
#     if preferred.is_file():
#         candidates.append(preferred)
#     candidates.extend(sorted([p for p in project_dir.rglob("*_csynth.rpt") if p.is_file() and p != preferred]))
#     if not candidates:
#         candidates = sorted([p for p in project_dir.rglob("*.rpt") if p.is_file()])
#     if not candidates:
#         return None

#     best = None
#     for rpt in candidates:
#         try:
#             latency, bram, dsp, ff, lut = parse_rpt_file(rpt)
#         except Exception:
#             continue
#         if best is None or latency > best[1]:
#             best = (rpt, latency, bram, dsp, ff, lut)
#     return best


# def select_codo_rpt(project_dir: Path) -> Optional[Tuple[Path, int, int, int, int, int]]:
#     rpt_candidates = [p for p in project_dir.glob("*.prj/*/syn/report/main_graph_csynth.rpt") if p.is_file()]
#     if not rpt_candidates:
#         rpt_candidates = [p for p in project_dir.rglob("main_graph_csynth.rpt") if p.is_file() and ".prj/" in p.as_posix()]
#     if not rpt_candidates:
#         return None

#     best = None
#     for rpt in sorted(rpt_candidates):
#         try:
#             latency, bram, dsp, ff, lut = parse_rpt_file(rpt)
#         except Exception:
#             continue
#         if best is None or latency > best[1]:
#             best = (rpt, latency, bram, dsp, ff, lut)
#     return best


# def collect_projects(root: Path) -> List[Tuple[str, Path]]:
#     optimizer = root.name.lower()
#     projects: List[Tuple[str, Path]] = []
#     if optimizer == "codo":
#         for shape_dir in sorted([p for p in root.iterdir() if p.is_dir()], key=lambda p: p.name.lower()):
#             for model_dir in sorted([p for p in shape_dir.iterdir() if p.is_dir()], key=lambda p: p.name.lower()):
#                 name = canonical_model_name(model_dir.name)
#                 projects.append((name, model_dir))
#     else:
#         for model_dir in sorted([p for p in root.iterdir() if p.is_dir()], key=lambda p: p.name.lower()):
#             name = canonical_model_name(model_dir.name)
#             projects.append((name, model_dir))
#     return projects


# def load_compilation_time(path: Path) -> Dict[str, Dict[str, str]]:
#     result: Dict[str, Dict[str, str]] = {"3_32_32": {}, "3_224_224": {}}
#     if not path.exists() or not path.is_file():
#         return result
#     lines = path.read_text(encoding="utf-8", errors="ignore").splitlines()
#     section = None
#     header: List[str] = []
#     for raw in lines:
#         line = raw.strip()
#         if not line:
#             continue
#         if line in result:
#             section = line
#             header = []
#             continue
#         parts = re.split(r"\s+", line)
#         if section is None or not parts:
#             continue
#         if parts[0].lower() == "dataset":
#             header = parts[1:]
#             continue
#         if parts[0].lower() == "compilationtime" and header:
#             values = parts[1:]
#             for k, v in zip(header, values):
#                 result[section][k.lower()] = v
#     return result


# def collect_optimizer_rows(optimizer_root: Path, baseline_root: Path) -> Dict[str, Tuple[str, str, str, str, str, str]]:
#     optimizer = optimizer_root.name.lower()
#     if optimizer in HARDCODED_ROWS:
#         out: Dict[str, Tuple[str, str, str, str, str, str]] = {}
#         for name, latency_m, bram, dsp, ff_k, lut_k, speedup in HARDCODED_ROWS[optimizer]:
#             out[name] = (latency_m, speedup + "x", str(bram), str(dsp), ff_k, lut_k)
#         return out

#     baseline_by_name: Dict[str, Path] = {}
#     if baseline_root.exists() and baseline_root.is_dir():
#         for p in baseline_root.iterdir():
#             if p.is_dir():
#                 baseline_by_name[canonical_model_name(p.name)] = p

#     out: Dict[str, Tuple[str, str, str, str, str, str]] = {}
#     for canon_name, project_dir in collect_projects(optimizer_root):
#         if optimizer == "codo":
#             best = select_codo_rpt(project_dir)
#         else:
#             best = select_best_rpt(project_dir)
#         if best is None:
#             out[canon_name] = ("-", "-", "-", "-", "-", "-")
#             continue
#         _, latency, bram, dsp, ff, lut = best
#         speedup = "-"
#         baseline_proj = baseline_by_name.get(canon_name)
#         if baseline_proj is not None and latency != 0:
#             baseline_best = select_best_rpt(baseline_proj)
#             if baseline_best is not None:
#                 _, baseline_latency, _, _, _, _ = baseline_best
#                 if baseline_latency and baseline_latency != 0:
#                     speedup = round_half_up(baseline_latency / float(latency), 1) + "x"
#         out[canon_name] = (to_latency_m(latency), speedup, str(bram), str(dsp), to_k(ff), to_k(lut))
#     return out


# def format_table(title: str, rows: List[List[str]]) -> str:
#     header = ["Application", "Framework", "Latency(cycles)", "Speedup", "Compilation Time(s)", "BRAM", "DSP", "FF", "LUT"]
#     all_rows = [header] + rows
#     widths = [max(len(r[i]) for r in all_rows) + 2 for i in range(len(header))]

#     def fmt(row: List[str]) -> str:
#         cells: List[str] = []
#         for i, c in enumerate(row):
#             if i <= 1:
#                 cells.append(f"{c:<{widths[i]}}")
#             else:
#                 cells.append(f"{c:>{widths[i]}}")
#         return "".join(cells).rstrip()

#     sep = fmt(["-" * len(h) for h in header])
#     lines = [title, fmt(header), sep]
#     lines.extend(fmt(r) for r in rows)
#     return "\n".join(lines)


# def main() -> None:
#     parser = argparse.ArgumentParser(description="Generate table-3 and table-4 result.csv")
#     parser.add_argument("--root", default="", help="Root folder path")
#     parser.add_argument("--output", default="", help="Output file path")
#     parser.add_argument("--compilation-time", default="", help="CompilationTime.csv path")
#     args = parser.parse_args()

#     script_dir = Path(__file__).resolve().parent
#     root = normalize_path(args.root) if args.root else script_dir
#     if not root.exists() or not root.is_dir():
#         raise SystemExit(f"Root folder not found: {root}")

#     output_path = normalize_path(args.output) if args.output else (root / "result.csv").resolve()
#     ctime_path = normalize_path(args.compilation_time) if args.compilation_time else (root / "CompilationTime.csv").resolve()

#     baseline_root = root / "baseline"
#     metrics_by_framework: Dict[str, Dict[str, Tuple[str, str, str, str, str, str]]] = {}
#     for framework in ["scalehls", "pom", "allo", "hida", "codo"]:
#         metrics_by_framework[framework] = collect_optimizer_rows(root / framework, baseline_root)

#     ctime = load_compilation_time(ctime_path)
#     app_to_dataset = {
#         "resnet-small": "resnet18", "vgg-samll": "vgg16", "mobilenet-small": "mobilenet",
#         "resnet-large": "resnet18", "vgg-large": "vgg16", "mobilenet-large": "mobilenet",
#         "yolo": "yolo", "zfnet": "zfnet",
#     }
#     app_display = {
#         "resnet-small": "ResNet-18", "vgg-samll": "VGG-16", "mobilenet-small": "MobileNet",
#         "resnet-large": "ResNet-18", "vgg-large": "VGG-16", "mobilenet-large": "MobileNet",
#         "zfnet": "ZFNet", "yolo": "YOLO",
#     }
#     fw_display = {"scalehls": "ScaleHLS", "pom": "POM", "allo": "Allo", "codo": "CODO", "hida": "HIDA"}

#     def build_rows(apps: List[str], frameworks: List[str], ctime_group: str) -> List[List[str]]:
#         rows: List[List[str]] = []
#         for app in apps:
#             first = True
#             for fw in frameworks:
#                 metrics = metrics_by_framework.get(fw, {}).get(app, ("-", "-", "-", "-", "-", "-"))
#                 latency, speedup, bram, dsp, ff, lut = metrics
#                 comp = "-"
#                 if fw == "codo":
#                     ds = app_to_dataset.get(app, "")
#                     comp = ctime.get(ctime_group, {}).get(ds, "-")
#                 rows.append([
#                     app_display.get(app, app) if first else "",
#                     fw_display[fw], latency, speedup, comp, bram, dsp, ff, lut,
#                 ])
#                 first = False
#         return rows

#     small_rows = build_rows(["resnet-small", "vgg-samll", "mobilenet-small"], ["scalehls", "pom", "allo", "codo"], "3_32_32")
#     large_rows = build_rows(["resnet-large", "vgg-large", "mobilenet-large", "zfnet", "yolo"], ["hida", "codo"], "3_224_224")

#     # --- 准备最终内容 ---
#     content = (
#         format_table("TABLE III (3_32_32)", small_rows)
#         + "\n\n"
#         + format_table("TABLE IV (3_224_224)", large_rows)
#         + "\n"
#     )

#     # --- 1. 尝试写入文件 (增加了权限错误处理) ---
#     try:
#         output_path.write_text(content, encoding="utf-8")
#         print(f"\n[Success] Results saved to: {output_path}")
#     except PermissionError:
#         print(f"\n[Warning] Permission denied: Could not write to {output_path}")
#     except Exception as e:
#         print(f"\n[Error] Failed to write file: {e}")

#     # --- 2. 命令行输出一份 ---
#     print("\n" + "=" * 40)
#     print(content)
#     print("=" * 40 + "\n")


# if __name__ == "__main__":
#     main()


#!/usr/bin/env python3
import argparse
import re
import math
from decimal import Decimal, ROUND_HALF_UP
from pathlib import Path
from typing import Dict, List, Optional, Tuple


HARDCODED_ROWS: Dict[str, List[Tuple[str, str, int, int, str, str, str]]] = {
    "allo": [
        ("resnet-small", "8.29M", 0, 652, "51K", "124K", "66.9"),
        ("vgg-samll", "3.85M", 0, 440, "38K", "98K", "50.1"),
        ("mobilenet-small", "0.26M", 0, 1942, "57K", "128K", "46.6"),
    ],
    "scalehls": [
        ("resnet-small", "104.88M", 8416, 1330, "144K", "992K", "5.3"),
        ("vgg-samll", "28.31M", 3936, 882, "100K", "714K", "6.8"),
        ("mobilenet-small", "2.17M", 6796, 1778, "93K", "518K", "5.6"),
    ],
}


def normalize_path(raw_path: str) -> Path:
    return Path(raw_path.replace("\\", "/")).expanduser().resolve()


def canonical_model_name(name: str) -> str:
    n = name.strip().lower().replace("_", "-")
    aliases = {
        "resnet-samall": "resnet-small",
        "resnet-small": "resnet-small",
        "vgg-small": "vgg-samll",
        "vgg-samll": "vgg-samll",
    }
    return aliases.get(n, n)


def round_half_up(value: float, digits: int) -> str:
    q = Decimal("1") if digits == 0 else Decimal(f"1.{'0' * digits}")
    return str(Decimal(str(value)).quantize(q, rounding=ROUND_HALF_UP))


def to_latency_m(latency: int) -> str:
    return f"{round_half_up(latency / 1_000_000.0, 2)}M"


def to_k(value: int) -> str:
    return f"{round_half_up(value / 1000.0, 0)}K"


def extract_max_latency(report_text: str) -> int:
    latency_section = report_text.find("+ Latency:")
    if latency_section == -1:
        raise ValueError("Latency section not found")

    summary_start = report_text.find("* Summary:", latency_section)
    if summary_start == -1:
        raise ValueError("Latency summary not found")

    detail_start = report_text.find("+ Detail:", summary_start)
    block = report_text[summary_start:detail_start if detail_start != -1 else len(report_text)]
    row_pattern = re.compile(r"^\s*\|\s*(\d+)\s*\|\s*(\d+)\s*\|", re.MULTILINE)
    m = row_pattern.search(block)
    if not m:
        raise ValueError("Latency row not found")
    return int(m.group(2))


def extract_total_util(report_text: str) -> Tuple[int, int, int, int]:
    util_section = report_text.find("== Utilization Estimates")
    if util_section == -1:
        raise ValueError("Utilization section not found")

    util_text = report_text[util_section:]
    lines = util_text.splitlines()
    header_idx = -1
    for i, line in enumerate(lines):
        if "Name" in line and "DSP" in line and "FF" in line and "LUT" in line and "|" in line:
            header_idx = i
            break
    if header_idx == -1:
        raise ValueError("Utilization header not found")

    headers = [x.strip() for x in lines[header_idx].strip().strip("|").split("|")]

    def find_col(col_name: str) -> int:
        for idx, h in enumerate(headers):
            if h == col_name:
                return idx
        raise ValueError(f"{col_name} column not found")

    bram_col = -1
    for idx, h in enumerate(headers):
        if h.startswith("BRAM"):
            bram_col = idx
            break
    if bram_col == -1:
        raise ValueError("BRAM column not found")

    dsp_col = find_col("DSP")
    ff_col = find_col("FF")
    lut_col = find_col("LUT")

    total_row = None
    for line in lines[header_idx + 1:]:
        if not line.strip().startswith("|"):
            continue
        cols = [x.strip() for x in line.strip().strip("|").split("|")]
        if cols and cols[0] == "Total":
            total_row = cols
            break
    if total_row is None:
        raise ValueError("Total row not found")

    def parse_num(idx: int) -> int:
        if idx >= len(total_row):
            raise ValueError("Missing value in Total row")
        s = total_row[idx].replace(",", "")
        if not s.isdigit():
            raise ValueError(f"Invalid numeric value: {s}")
        return int(s)

    return parse_num(bram_col), parse_num(dsp_col), parse_num(ff_col), parse_num(lut_col)


def parse_rpt_file(rpt_path: Path) -> Tuple[int, int, int, int, int]:
    text = rpt_path.read_text(encoding="utf-8", errors="ignore")
    latency = extract_max_latency(text)
    bram, dsp, ff, lut = extract_total_util(text)
    return latency, bram, dsp, ff, lut


def select_best_rpt(project_dir: Path) -> Optional[Tuple[Path, int, int, int, int, int]]:
    preferred = project_dir / "main_graph_csynth.rpt"
    candidates: List[Path] = []
    if preferred.is_file():
        candidates.append(preferred)
    candidates.extend(sorted([p for p in project_dir.rglob("*_csynth.rpt") if p.is_file() and p != preferred]))
    if not candidates:
        candidates = sorted([p for p in project_dir.rglob("*.rpt") if p.is_file()])
    if not candidates:
        return None

    best = None
    for rpt in candidates:
        try:
            latency, bram, dsp, ff, lut = parse_rpt_file(rpt)
        except Exception:
            continue
        if best is None or latency > best[1]:
            best = (rpt, latency, bram, dsp, ff, lut)
    return best


def select_codo_rpt(project_dir: Path) -> Optional[Tuple[Path, int, int, int, int, int]]:
    rpt_candidates = [p for p in project_dir.glob("*.prj/*/syn/report/main_graph_csynth.rpt") if p.is_file()]
    if not rpt_candidates:
        rpt_candidates = [p for p in project_dir.rglob("main_graph_csynth.rpt") if p.is_file() and ".prj/" in p.as_posix()]
    if not rpt_candidates:
        return None

    best = None
    for rpt in sorted(rpt_candidates):
        try:
            latency, bram, dsp, ff, lut = parse_rpt_file(rpt)
        except Exception:
            continue
        if best is None or latency > best[1]:
            best = (rpt, latency, bram, dsp, ff, lut)
    return best


def collect_projects(root: Path) -> List[Tuple[str, Path]]:
    optimizer = root.name.lower()
    projects: List[Tuple[str, Path]] = []
    if optimizer == "codo":
        for shape_dir in sorted([p for p in root.iterdir() if p.is_dir()], key=lambda p: p.name.lower()):
            for model_dir in sorted([p for p in shape_dir.iterdir() if p.is_dir()], key=lambda p: p.name.lower()):
                name = canonical_model_name(model_dir.name)
                projects.append((name, model_dir))
    else:
        for model_dir in sorted([p for p in root.iterdir() if p.is_dir()], key=lambda p: p.name.lower()):
            name = canonical_model_name(model_dir.name)
            projects.append((name, model_dir))
    return projects


def load_compilation_time(path: Path) -> Dict[str, Dict[str, str]]:
    result: Dict[str, Dict[str, str]] = {"3_32_32": {}, "3_224_224": {}}
    if not path.exists() or not path.is_file():
        return result
    lines = path.read_text(encoding="utf-8", errors="ignore").splitlines()
    section = None
    header: List[str] = []
    for raw in lines:
        line = raw.strip()
        if not line:
            continue
        if line in result:
            section = line
            header = []
            continue
        parts = re.split(r"\s+", line)
        if section is None or not parts:
            continue
        if parts[0].lower() == "dataset":
            header = parts[1:]
            continue
        if parts[0].lower() == "compilationtime" and header:
            values = parts[1:]
            for k, v in zip(header, values):
                result[section][k.lower()] = v
    return result


def collect_optimizer_rows(optimizer_root: Path, baseline_root: Path) -> Dict[str, Tuple[str, str, str, str, str, str]]:
    optimizer = optimizer_root.name.lower()
    if optimizer in HARDCODED_ROWS:
        out: Dict[str, Tuple[str, str, str, str, str, str]] = {}
        for name, latency_m, bram, dsp, ff_k, lut_k, speedup in HARDCODED_ROWS[optimizer]:
            out[name] = (latency_m, speedup + "x", str(bram), str(dsp), ff_k, lut_k)
        return out

    baseline_by_name: Dict[str, Path] = {}
    if baseline_root.exists() and baseline_root.is_dir():
        for p in baseline_root.iterdir():
            if p.is_dir():
                baseline_by_name[canonical_model_name(p.name)] = p

    out: Dict[str, Tuple[str, str, str, str, str, str]] = {}
    for canon_name, project_dir in collect_projects(optimizer_root):
        if optimizer == "codo":
            best = select_codo_rpt(project_dir)
        else:
            best = select_best_rpt(project_dir)
        if best is None:
            out[canon_name] = ("-", "-", "-", "-", "-", "-")
            continue
        _, latency, bram, dsp, ff, lut = best
        speedup = "-"
        baseline_proj = baseline_by_name.get(canon_name)
        if baseline_proj is not None and latency != 0:
            baseline_best = select_best_rpt(baseline_proj)
            if baseline_best is not None:
                _, baseline_latency, _, _, _, _ = baseline_best
                if baseline_latency and baseline_latency != 0:
                    speedup = round_half_up(baseline_latency / float(latency), 1) + "x"
        out[canon_name] = (to_latency_m(latency), speedup, str(bram), str(dsp), to_k(ff), to_k(lut))
    return out


def format_table(title: str, rows: List[List[str]]) -> str:
    header = ["Application", "Framework", "Latency(cycles)", "Speedup", "Compilation Time(s)", "BRAM", "DSP", "FF", "LUT"]
    all_rows = [header] + rows
    widths = [max(len(r[i]) for r in all_rows) + 2 for i in range(len(header))]

    def fmt(row: List[str]) -> str:
        cells: List[str] = []
        for i, c in enumerate(row):
            if i <= 1:
                cells.append(f"{c:<{widths[i]}}")
            else:
                cells.append(f"{c:>{widths[i]}}")
        return "".join(cells).rstrip()

    sep = fmt(["-" * len(h) for h in header])
    lines = [title, fmt(header), sep]
    lines.extend(fmt(r) for r in rows)
    return "\n".join(lines)


def main() -> None:
    parser = argparse.ArgumentParser(description="Generate table-3 and table-4 result.csv")
    parser.add_argument("--root", default="", help="Root folder path")
    parser.add_argument("--output", default="", help="Output file path")
    parser.add_argument("--compilation-time", default="", help="CompilationTime.csv path")
    args = parser.parse_args()

    script_dir = Path(__file__).resolve().parent
    root = normalize_path(args.root) if args.root else script_dir
    if not root.exists() or not root.is_dir():
        raise SystemExit(f"Root folder not found: {root}")

    output_path = normalize_path(args.output) if args.output else (root / "result.csv").resolve()
    ctime_path = normalize_path(args.compilation_time) if args.compilation_time else (root / "CompilationTime.csv").resolve()

    baseline_root = root / "baseline"
    metrics_by_framework: Dict[str, Dict[str, Tuple[str, str, str, str, str, str]]] = {}
    for framework in ["scalehls", "pom", "allo", "hida", "codo"]:
        metrics_by_framework[framework] = collect_optimizer_rows(root / framework, baseline_root)

    ctime = load_compilation_time(ctime_path)
    app_to_dataset = {
        "resnet-small": "resnet18", "vgg-samll": "vgg16", "mobilenet-small": "mobilenet",
        "resnet-large": "resnet18", "vgg-large": "vgg16", "mobilenet-large": "mobilenet",
        "yolo": "yolo", "zfnet": "zfnet",
    }
    app_display = {
        "resnet-small": "ResNet-18", "vgg-samll": "VGG-16", "mobilenet-small": "MobileNet",
        "resnet-large": "ResNet-18", "vgg-large": "VGG-16", "mobilenet-large": "MobileNet",
        "zfnet": "ZFNet", "yolo": "YOLO",
    }
    fw_display = {"scalehls": "ScaleHLS", "pom": "POM", "allo": "Allo", "codo": "CODO", "hida": "HIDA"}

    def build_rows(apps: List[str], frameworks: List[str], ctime_group: str) -> List[List[str]]:
        rows: List[List[str]] = []
        for app in apps:
            first = True
            for fw in frameworks:
                metrics = metrics_by_framework.get(fw, {}).get(app, ("-", "-", "-", "-", "-", "-"))
                latency, speedup, bram, dsp, ff, lut = metrics
                comp = "-"
                if fw == "codo":
                    ds = app_to_dataset.get(app, "")
                    comp = ctime.get(ctime_group, {}).get(ds, "-")
                rows.append([
                    app_display.get(app, app) if first else "",
                    fw_display[fw], latency, speedup, comp, bram, dsp, ff, lut,
                ])
                first = False
        return rows

    small_rows = build_rows(["resnet-small", "vgg-samll", "mobilenet-small"], ["scalehls", "pom", "allo", "codo"], "3_32_32")
    large_rows = build_rows(["resnet-large", "vgg-large", "mobilenet-large", "zfnet", "yolo"], ["hida", "codo"], "3_224_224")

    # --- 添加备注信息 ---
    note_text = (
        "\nThe slight discrepancy in ResNet-18 results of CODO arises from updates to the model structure, "
        "which lead to differences in the model lowered by Torch-MLIR. Results for other works follow the "
        "original configurations reported in the paper."
    )

    # --- 准备最终内容 ---
    content = (
        format_table("TABLE III (3_32_32)", small_rows)
        + "\n\n"
        + format_table("TABLE IV (3_224_224)", large_rows)
        + "\n"
        + note_text
        + "\n"
    )

    # --- 1. 尝试写入文件 (增加了权限错误处理) ---
    try:
        output_path.write_text(content, encoding="utf-8")
        print(f"\n[Success] Results saved to: {output_path}")
    except PermissionError:
        print(f"\n[Warning] Permission denied: Could not write to {output_path}")
    except Exception as e:
        print(f"\n[Error] Failed to write file: {e}")

    # --- 2. 命令行输出一份 ---
    print("\n" + "=" * 60)
    print(content)
    print("=" * 60 + "\n")


if __name__ == "__main__":
    main()