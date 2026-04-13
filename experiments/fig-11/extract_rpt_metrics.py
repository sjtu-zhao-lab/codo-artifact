#!/usr/bin/env python3
import re
from pathlib import Path
from typing import List, Tuple


SCALES = ["1", "2", "4", "8", "16", "32"]


def extract_latency(report_text: str) -> int:
    latency_section = report_text.find("+ Latency:")
    if latency_section == -1:
        raise ValueError("Latency section not found")
    summary_start = report_text.find("* Summary:", latency_section)
    if summary_start == -1:
        raise ValueError("Latency summary not found")
    detail_start = report_text.find("+ Detail:", summary_start)
    block = report_text[summary_start:detail_start if detail_start != -1 else len(report_text)]
    m = re.search(r"^\s*\|\s*(\d+)\s*\|\s*(\d+)\s*\|", block, flags=re.MULTILINE)
    if not m:
        raise ValueError("Latency row not found")
    return int(m.group(2))


def extract_utilization_slr(report_text: str) -> List[str]:
    m = re.search(r"^\s*\|\s*Utilization SLR \(%\)\s*\|([^\n]+)\|?\s*$", report_text, flags=re.MULTILINE)
    if not m:
        raise ValueError("Utilization SLR row not found")
    values = [x.strip() for x in m.group(1).split("|")]
    if len(values) < 4:
        raise ValueError("Utilization SLR values not enough")
    return values[:4]


def parse_report(rpt_path: Path) -> Tuple[int, List[str]]:
    text = rpt_path.read_text(encoding="utf-8", errors="ignore")
    latency = extract_latency(text)
    bram, dsp, ff, lut = extract_utilization_slr(text)
    return latency, [bram, dsp, ff, lut]


def main() -> None:
    base_dir = Path(__file__).resolve().parent
    baseline_path = base_dir / "baseline" / "main_graph_csynth.rpt"
    baseline_latency = None
    if baseline_path.is_file():
        try:
            baseline_latency, _ = parse_report(baseline_path)
        except Exception:
            baseline_latency = None

    rows: List[List[str]] = []
    for scale in SCALES:
        prj_dir = base_dir / scale / "resnet18_large.prj"
        candidates = sorted(prj_dir.glob("*/syn/report/main_graph_csynth.rpt"))
        if not candidates:
            rows.append([scale, "-", "-", "-", "-", "-", "-"])
            continue
        preferred = prj_dir / f"large-{scale}" / "syn" / "report" / "main_graph_csynth.rpt"
        rpt_path = preferred if preferred in candidates else candidates[0]
        try:
            latency, util_metrics = parse_report(rpt_path)
            speedup = "-"
            if baseline_latency is not None and latency != 0:
                speedup = f"{(baseline_latency / float(latency)):.1f}x"
            rows.append([scale, str(latency), speedup] + util_metrics)
        except Exception:
            rows.append([scale, "-", "-", "-", "-", "-", "-"])

    header = ["Scale", "Latency", "Speedup", "BRAM", "DSP", "FF", "LUT"]
    table = [header] + rows
    col_widths = [max(len(row[i]) for row in table) + 2 for i in range(len(header))]

    def format_row(row: List[str]) -> str:
        parts = []
        for i, v in enumerate(row):
            if i == 0:
                parts.append(f"{v:<{col_widths[i]}}")
            else:
                parts.append(f"{v:>{col_widths[i]}}")
        return "".join(parts).rstrip()

    output_path = base_dir / "result.csv"
    with output_path.open("w", encoding="utf-8") as f:
        f.write(format_row(header) + "\n")
        f.write(format_row(["-" * len(x) for x in header]) + "\n")
        for row in rows:
            f.write(format_row(row) + "\n")


if __name__ == "__main__":
    main()
#!/usr/bin/env python3
import re
from pathlib import Path
from typing import List, Tuple


SCALES = ["1", "2", "4", "8", "16", "32"]


def extract_latency(report_text: str) -> int:
    latency_section = report_text.find("+ Latency:")
    if latency_section == -1:
        raise ValueError("Latency section not found")
    summary_start = report_text.find("* Summary:", latency_section)
    if summary_start == -1:
        raise ValueError("Latency summary not found")
    detail_start = report_text.find("+ Detail:", summary_start)
    block = report_text[summary_start:detail_start if detail_start != -1 else len(report_text)]
    m = re.search(r"^\s*\|\s*(\d+)\s*\|\s*(\d+)\s*\|", block, flags=re.MULTILINE)
    if not m:
        raise ValueError("Latency row not found")
    return int(m.group(2))


def extract_utilization_slr(report_text: str) -> List[str]:
    m = re.search(r"^\s*\|\s*Utilization SLR \(%\)\s*\|([^\n]+)\|?\s*$", report_text, flags=re.MULTILINE)
    if not m:
        raise ValueError("Utilization SLR row not found")
    values = [x.strip() for x in m.group(1).split("|")]
    if len(values) < 4:
        raise ValueError("Utilization SLR values not enough")
    return values[:4]


def parse_report(rpt_path: Path) -> Tuple[int, List[str]]:
    text = rpt_path.read_text(encoding="utf-8", errors="ignore")
    latency = extract_latency(text)
    bram, dsp, ff, lut = extract_utilization_slr(text)
    return latency, [bram, dsp, ff, lut]


def main() -> None:
    base_dir = Path(__file__).resolve().parent
    baseline_path = base_dir / "baseline" / "main_graph_csynth.rpt"
    baseline_latency = None
    if baseline_path.is_file():
        try:
            baseline_latency, _ = parse_report(baseline_path)
        except Exception:
            baseline_latency = None

    rows: List[List[str]] = []
    for scale in SCALES:
        prj_dir = base_dir / scale / "resnet18_large.prj"
        candidates = sorted(prj_dir.glob("*/syn/report/main_graph_csynth.rpt"))
        if not candidates:
            rows.append([scale, "-", "-", "-", "-", "-", "-"])
            continue
        preferred = prj_dir / f"large-{scale}" / "syn" / "report" / "main_graph_csynth.rpt"
        rpt_path = preferred if preferred in candidates else candidates[0]
        try:
            latency, util_metrics = parse_report(rpt_path)
            speedup = "-"
            if baseline_latency is not None and latency != 0:
                speedup = f"{(baseline_latency / float(latency)):.1f}x"
            rows.append([scale, str(latency), speedup] + util_metrics)
        except Exception:
            rows.append([scale, "-", "-", "-", "-", "-", "-"])

    header = ["Scale", "Latency", "Speedup", "BRAM", "DSP", "FF", "LUT"]
    table = [header] + rows
    col_widths = [max(len(row[i]) for row in table) + 2 for i in range(len(header))]

    def format_row(row: List[str]) -> str:
        parts = []
        for i, v in enumerate(row):
            if i == 0:
                parts.append(f"{v:<{col_widths[i]}}")
            else:
                parts.append(f"{v:>{col_widths[i]}}")
        return "".join(parts).rstrip()

    output_path = base_dir / "result.csv"
    
    output_lines = []
    output_lines.append(format_row(header))
    output_lines.append(format_row(["-" * len(x) for x in header]))
    for row in rows:
        output_lines.append(format_row(row))

    with output_path.open("w", encoding="utf-8") as f:
        for line in output_lines:
            f.write(line + "\n")
    
    print(f"\nResults saved to: {output_path}")
    print("-" * sum(col_widths))
    for line in output_lines:
        print(line)
    print("-" * sum(col_widths))


if __name__ == "__main__":
    main()