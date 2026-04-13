# #!/usr/bin/env python3
# import argparse
# import math
# import re
# from pathlib import Path
# from typing import Dict, List, Optional, Tuple


# def normalize_path(raw_path: str) -> Path:
#     return Path(raw_path.replace("\\", "/")).expanduser().resolve()


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


# def extract_total_dsp(report_text: str) -> int:
#     util_section = report_text.find("== Utilization Estimates")
#     if util_section == -1:
#         raise ValueError("Utilization section not found")

#     util_text = report_text[util_section:]
#     lines = util_text.splitlines()
#     header_idx = -1
#     for i, line in enumerate(lines):
#         if "Name" in line and "DSP" in line and "|" in line:
#             header_idx = i
#             break
#     if header_idx == -1:
#         raise ValueError("Utilization header not found")

#     headers = [x.strip() for x in lines[header_idx].strip().strip("|").split("|")]
#     if "DSP" not in headers:
#         raise ValueError("DSP column not found")
#     dsp_col = headers.index("DSP")

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

#     if dsp_col >= len(total_row):
#         raise ValueError("DSP value missing on Total row")
#     dsp_str = total_row[dsp_col].replace(",", "")
#     if not dsp_str.isdigit():
#         raise ValueError(f"Invalid DSP value: {dsp_str}")
#     return int(dsp_str)


# def parse_rpt_file(rpt_path: Path) -> Tuple[int, int]:
#     text = rpt_path.read_text(encoding="utf-8", errors="ignore")
#     return extract_max_latency(text), extract_total_dsp(text)


# def select_best_rpt(project_dir: Path) -> Optional[Tuple[Path, int, int]]:
#     rpt_files = sorted(project_dir.rglob("*.rpt"))
#     best = None
#     for rpt in rpt_files:
#         try:
#             latency, dsp = parse_rpt_file(rpt)
#         except Exception:
#             continue
#         if best is None or latency > best[1]:
#             best = (rpt, latency, dsp)
#     return best


# def select_codo_rpt(project_dir: Path) -> Optional[Tuple[Path, int, int]]:
#     prj_dirs = [p for p in project_dir.glob("*.prj") if p.is_dir()]
#     if not prj_dirs:
#         return None

#     rpt_candidates = []
#     for prj in prj_dirs:
#         rpt_candidates.extend(prj.glob("*/syn/report/*_csynth.rpt"))

#     rpt_candidates = [p for p in rpt_candidates if p.is_file()]
#     if not rpt_candidates:
#         return None

#     preferred = [p for p in rpt_candidates if p.name == "main_graph_csynth.rpt"]
#     scan_list = preferred if preferred else rpt_candidates

#     best = None
#     for rpt in sorted(scan_list):
#         try:
#             latency, dsp = parse_rpt_file(rpt)
#         except Exception:
#             continue
#         if best is None or latency > best[1]:
#             best = (rpt, latency, dsp)
#     return best


# def main() -> None:
#     parser = argparse.ArgumentParser(description="Generate table-2 result.csv")
#     parser.add_argument("--root", default="", help="Table-2 root path")
#     parser.add_argument("--output", default="", help="Output csv path")
#     parser.add_argument("--dsetime", default="", help="dsetime file path")
#     args = parser.parse_args()

#     script_dir = Path(__file__).resolve().parent
#     root = normalize_path(args.root) if args.root else script_dir
#     if not root.exists() or not root.is_dir():
#         raise SystemExit(f"Root folder not found: {root}")

#     if args.output:
#         raw_output = Path(args.output.replace("\\", "/")).expanduser()
#         output_path = raw_output.resolve() if raw_output.is_absolute() else (root / raw_output).resolve()
#     else:
#         output_path = (root / "result.csv").resolve()
#     if args.dsetime:
#         raw_dsetime = Path(args.dsetime.replace("\\", "/")).expanduser()
#         dsetime_path = raw_dsetime.resolve() if raw_dsetime.is_absolute() else (root / raw_dsetime).resolve()
#     else:
#         dsetime_path = (root / "dsetime.csv").resolve()

#     benchmark_order = [
#         "atax",
#         "gesummv",
#         "gemm",
#         "mvt",
#         "3mm",
#         "residualmlp",
#         "autoencoder",
#         "residualblock",
#         "dwsconv",
#         "3conv",
#         "feedforward",
#         "attention",
#     ]
#     benchmark_display = {
#         "atax": "Atax",
#         "gesummv": "Gesummv",
#         "gemm": "Gemm",
#         "mvt": "Mvt",
#         "3mm": "3mm",
#         "residualmlp": "Residual MLP",
#         "autoencoder": "Autoencoder",
#         "residualblock": "Residual Block",
#         "dwsconv": "DWSConv. Block",
#         "3conv": "3-Layer Conv. Block",
#         "feedforward": "Fed Forward",
#         "attention": "Multi-Head Attention",
#     }
#     methods = [
#         ("CODO", "codo"),
#         ("StreamHLS", "streamhls"),
#         ("Allo", "allo"),
#         ("HIDA", "hida"),
#     ]

#     def select_for_optimizer(optimizer_name: str, project_dir: Path) -> Optional[Tuple[Path, int, int]]:
#         if optimizer_name.lower() == "codo":
#             return select_codo_rpt(project_dir)
#         return select_best_rpt(project_dir)

#     def collect_metrics(method_root: Path, method_name: str) -> Dict[str, Tuple[Optional[int], Optional[int]]]:
#         result: Dict[str, Tuple[Optional[int], Optional[int]]] = {}
#         if not method_root.exists() or not method_root.is_dir():
#             return result
#         for p in method_root.iterdir():
#             if not p.is_dir():
#                 continue
#             best = select_for_optimizer(method_name, p)
#             if best is None:
#                 result[p.name.lower()] = (None, None)
#                 continue
#             _, latency, dsp = best
#             result[p.name.lower()] = (latency, dsp)
#         return result

#     def parse_dsetime_range(path: Path) -> str:
#         if not path.exists() or not path.is_file():
#             return "-"
#         text = path.read_text(encoding="utf-8", errors="ignore")
#         for raw_line in text.splitlines():
#             line = raw_line.strip()
#             if not line:
#                 continue
#             if "," in line:
#                 parts = [x.strip() for x in line.split(",") if x.strip()]
#             else:
#                 parts = re.split(r"\s+", line)
#             if not parts or parts[0].lower() != "dsetime":
#                 continue
#             values: List[float] = []
#             for token in parts[1:]:
#                 try:
#                     values.append(float(token))
#                 except Exception:
#                     continue
#             if not values:
#                 return "-"
#             mn = min(values)
#             mx = max(values)

#             def fmt(v: float) -> str:
#                 if abs(v - int(v)) < 1e-9:
#                     return str(int(v))
#                 return f"{v:.3f}".rstrip("0").rstrip(".")

#             return f"{fmt(mn)}s-{fmt(mx)}s"
#         return "-"

#     method_data: Dict[str, Dict[str, Tuple[Optional[int], Optional[int]]]] = {}
#     for _, folder in methods:
#         method_data[folder] = collect_metrics(root / folder, folder)
#     baseline_data = collect_metrics(root / "baseline", "baseline")

#     table_rows: List[List[str]] = []
#     geo_values: Dict[str, List[float]] = {folder: [] for _, folder in methods}

#     for key in benchmark_order:
#         dsp_value = method_data["codo"].get(key, (None, None))[1]
#         dsp_str = "-" if dsp_value is None else str(dsp_value)
#         row = [benchmark_display[key], dsp_str]
#         baseline_latency = baseline_data.get(key, (None, None))[0]

#         for _, folder in methods:
#             method_latency = method_data[folder].get(key, (None, None))[0]
#             if baseline_latency is None or baseline_latency == 0 or method_latency is None or method_latency == 0:
#                 row.append("-")
#                 continue
#             ratio = baseline_latency / float(method_latency)
#             geo_values[folder].append(ratio)
#             row.append(f"{ratio:.1f}x")
#         table_rows.append(row)

#     dsetime_range = parse_dsetime_range(dsetime_path)

#     geo_row = ["Geo. Mean", "-"]
#     for _, folder in methods:
#         vals = geo_values[folder]
#         if not vals:
#             geo_row.append("-")
#         else:
#             geo = math.exp(sum(math.log(v) for v in vals) / len(vals))
#             geo_row.append(f"{geo:.1f}x")

#     header = ["Benchmark", "DSP", "CODO", "StreamHLS", "Allo", "HIDA"]
#     dse_row = ["DSE time", "-", dsetime_range, "-", "-", "-"]
#     all_rows = [header] + table_rows + [dse_row, geo_row]
#     col_widths = []
#     for col in range(len(header)):
#         w = max(len(row[col]) for row in all_rows) + 2
#         col_widths.append(w)

#     def format_row(row: List[str]) -> str:
#         cells = []
#         for i, cell in enumerate(row):
#             if i == 0:
#                 cells.append(f"{cell:<{col_widths[i]}}")
#             else:
#                 cells.append(f"{cell:>{col_widths[i]}}")
#         return "".join(cells).rstrip()

#     with output_path.open("w", encoding="utf-8") as f:
#         f.write(format_row(header) + "\n")
#         f.write(format_row(["-" * len(h) for h in header]) + "\n")
#         for row in table_rows:
#             f.write(format_row(row) + "\n")
#         f.write(format_row(["-" * len(h) for h in header]) + "\n")
#         f.write(format_row(dse_row) + "\n")
#         f.write(format_row(geo_row) + "\n")


# if __name__ == "__main__":
#     main()


#!/usr/bin/env python3
import argparse
import math
import re
from pathlib import Path
from typing import Dict, List, Optional, Tuple


def normalize_path(raw_path: str) -> Path:
    return Path(raw_path.replace("\\", "/")).expanduser().resolve()


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


def extract_total_dsp(report_text: str) -> int:
    util_section = report_text.find("== Utilization Estimates")
    if util_section == -1:
        raise ValueError("Utilization section not found")

    util_text = report_text[util_section:]
    lines = util_text.splitlines()
    header_idx = -1
    for i, line in enumerate(lines):
        if "Name" in line and "DSP" in line and "|" in line:
            header_idx = i
            break
    if header_idx == -1:
        raise ValueError("Utilization header not found")

    headers = [x.strip() for x in lines[header_idx].strip().strip("|").split("|")]
    if "DSP" not in headers:
        raise ValueError("DSP column not found")
    dsp_col = headers.index("DSP")

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

    if dsp_col >= len(total_row):
        raise ValueError("DSP value missing on Total row")
    dsp_str = total_row[dsp_col].replace(",", "")
    if not dsp_str.isdigit():
        raise ValueError(f"Invalid DSP value: {dsp_str}")
    return int(dsp_str)


def parse_rpt_file(rpt_path: Path) -> Tuple[int, int]:
    text = rpt_path.read_text(encoding="utf-8", errors="ignore")
    return extract_max_latency(text), extract_total_dsp(text)


def select_best_rpt(project_dir: Path) -> Optional[Tuple[Path, int, int]]:
    rpt_files = sorted(project_dir.rglob("*.rpt"))
    best = None
    for rpt in rpt_files:
        try:
            latency, dsp = parse_rpt_file(rpt)
        except Exception:
            continue
        if best is None or latency > best[1]:
            best = (rpt, latency, dsp)
    return best


def select_codo_rpt(project_dir: Path) -> Optional[Tuple[Path, int, int]]:
    prj_dirs = [p for p in project_dir.glob("*.prj") if p.is_dir()]
    if not prj_dirs:
        return None

    rpt_candidates = []
    for prj in prj_dirs:
        rpt_candidates.extend(prj.glob("*/syn/report/*_csynth.rpt"))

    rpt_candidates = [p for p in rpt_candidates if p.is_file()]
    if not rpt_candidates:
        return None

    preferred = [p for p in rpt_candidates if p.name == "main_graph_csynth.rpt"]
    scan_list = preferred if preferred else rpt_candidates

    best = None
    for rpt in sorted(scan_list):
        try:
            latency, dsp = parse_rpt_file(rpt)
        except Exception:
            continue
        if best is None or latency > best[1]:
            best = (rpt, latency, dsp)
    return best


def main() -> None:
    parser = argparse.ArgumentParser(description="Generate table-2 result.csv")
    parser.add_argument("--root", default="", help="Table-2 root path")
    parser.add_argument("--output", default="", help="Output csv path")
    parser.add_argument("--dsetime", default="", help="dsetime file path")
    args = parser.parse_args()

    script_dir = Path(__file__).resolve().parent
    root = normalize_path(args.root) if args.root else script_dir
    if not root.exists() or not root.is_dir():
        raise SystemExit(f"Root folder not found: {root}")

    if args.output:
        raw_output = Path(args.output.replace("\\", "/")).expanduser()
        output_path = raw_output.resolve() if raw_output.is_absolute() else (root / raw_output).resolve()
    else:
        output_path = (root / "result.csv").resolve()
    if args.dsetime:
        raw_dsetime = Path(args.dsetime.replace("\\", "/")).expanduser()
        dsetime_path = raw_dsetime.resolve() if raw_dsetime.is_absolute() else (root / raw_dsetime).resolve()
    else:
        dsetime_path = (root / "dsetime.csv").resolve()

    benchmark_order = [
        "atax", "gesummv", "gemm", "mvt", "3mm", "residualmlp",
        "autoencoder", "residualblock", "dwsconv", "3conv",
        "feedforward", "attention",
    ]
    benchmark_display = {
        "atax": "Atax", "gesummv": "Gesummv", "gemm": "Gemm", "mvt": "Mvt",
        "3mm": "3mm", "residualmlp": "Residual MLP", "autoencoder": "Autoencoder",
        "residualblock": "Residual Block", "dwsconv": "DWSConv. Block",
        "3conv": "3-Layer Conv. Block", "feedforward": "Fed Forward",
        "attention": "Multi-Head Attention",
    }
    methods = [
        ("CODO", "codo"), ("StreamHLS", "streamhls"),
        ("Allo", "allo"), ("HIDA", "hida"),
    ]

    def select_for_optimizer(optimizer_name: str, project_dir: Path) -> Optional[Tuple[Path, int, int]]:
        if optimizer_name.lower() == "codo":
            return select_codo_rpt(project_dir)
        return select_best_rpt(project_dir)

    def collect_metrics(method_root: Path, method_name: str) -> Dict[str, Tuple[Optional[int], Optional[int]]]:
        result: Dict[str, Tuple[Optional[int], Optional[int]]] = {}
        if not method_root.exists() or not method_root.is_dir():
            return result
        for p in method_root.iterdir():
            if not p.is_dir():
                continue
            best = select_for_optimizer(method_name, p)
            if best is None:
                result[p.name.lower()] = (None, None)
                continue
            _, latency, dsp = best
            result[p.name.lower()] = (latency, dsp)
        return result

    def parse_dsetime_range(path: Path) -> str:
        if not path.exists() or not path.is_file():
            return "-"
        text = path.read_text(encoding="utf-8", errors="ignore")
        for raw_line in text.splitlines():
            line = raw_line.strip()
            if not line: continue
            parts = [x.strip() for x in line.split(",") if x.strip()] if "," in line else re.split(r"\s+", line)
            if not parts or parts[0].lower() != "dsetime": continue
            values: List[float] = []
            for token in parts[1:]:
                try: values.append(float(token))
                except Exception: continue
            if not values: return "-"
            mn, mx = min(values), max(values)
            def fmt(v: float) -> str:
                return str(int(v)) if abs(v - int(v)) < 1e-9 else f"{v:.3f}".rstrip("0").rstrip(".")
            return f"{fmt(mn)}s-{fmt(mx)}s"
        return "-"

    method_data: Dict[str, Dict[str, Tuple[Optional[int], Optional[int]]]] = {}
    for _, folder in methods:
        method_data[folder] = collect_metrics(root / folder, folder)
    baseline_data = collect_metrics(root / "baseline", "baseline")

    table_rows: List[List[str]] = []
    geo_values: Dict[str, List[float]] = {folder: [] for _, folder in methods}

    for key in benchmark_order:
        dsp_value = method_data["codo"].get(key, (None, None))[1]
        row = [benchmark_display[key], "-" if dsp_value is None else str(dsp_value)]
        baseline_latency = baseline_data.get(key, (None, None))[0]
        for _, folder in methods:
            method_latency = method_data[folder].get(key, (None, None))[0]
            if baseline_latency and method_latency:
                ratio = baseline_latency / float(method_latency)
                geo_values[folder].append(ratio)
                row.append(f"{ratio:.1f}x")
            else:
                row.append("-")
        table_rows.append(row)

    dsetime_range = parse_dsetime_range(dsetime_path)
    geo_row = ["Geo. Mean", "-"]
    for _, folder in methods:
        vals = geo_values[folder]
        if not vals: geo_row.append("-")
        else:
            geo = math.exp(sum(math.log(v) for v in vals) / len(vals))
            geo_row.append(f"{geo:.1f}x")

    header = ["Benchmark", "DSP", "CODO", "StreamHLS", "Allo", "HIDA"]
    dse_row = ["DSE time", "-", dsetime_range, "-", "-", "-"]
    
    # 重新计算列宽
    all_table_data = [header] + table_rows + [dse_row, geo_row]
    col_widths = [max(len(row[i]) for row in all_table_data) + 2 for i in range(len(header))]

    def format_row(row: List[str]) -> str:
        cells = []
        for i, cell in enumerate(row):
            if i == 0: cells.append(f"{cell:<{col_widths[i]}}")
            else: cells.append(f"{cell:>{col_widths[i]}}")
        return "".join(cells).rstrip()

    # --- 准备输出内容 ---
    lines = []
    lines.append(format_row(header))
    lines.append(format_row(["-" * len(h) for h in header]))
    for row in table_rows:
        lines.append(format_row(row))
    lines.append(format_row(["-" * len(h) for h in header]))
    lines.append(format_row(dse_row))
    lines.append(format_row(geo_row))

    # --- 1. 尝试写入文件 ---
    try:
        with output_path.open("w", encoding="utf-8") as f:
            for line in lines:
                f.write(line + "\n")
        print(f"\n[Success] Results saved to: {output_path}")
    except PermissionError:
        print(f"\n[Warning] Permission denied: Could not write to {output_path}")
    except Exception as e:
        print(f"\n[Error] Failed to write file: {e}")

    # --- 2. 命令行输出一份 ---
    print("\n" + "=" * sum(col_widths))
    for line in lines:
        print(line)
    print("=" * sum(col_widths) + "\n")


if __name__ == "__main__":
    main()