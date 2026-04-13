#!/usr/bin/env python3
import argparse
import re
from pathlib import Path


def normalize_input_path(raw_path: str) -> Path:
    return Path(raw_path.replace("\\", "/")).expanduser().resolve()


def extract_max_latency(report_text: str) -> int:
    latency_section = report_text.find("+ Latency:")
    if latency_section == -1:
        raise ValueError("未找到 Latency 区域")

    summary_start = report_text.find("* Summary:", latency_section)
    if summary_start == -1:
        raise ValueError("未找到 Latency Summary")

    detail_start = report_text.find("+ Detail:", summary_start)
    block = report_text[summary_start:detail_start if detail_start != -1 else len(report_text)]
    row_pattern = re.compile(r"^\s*\|\s*(\d+)\s*\|\s*(\d+)\s*\|", re.MULTILINE)
    m = row_pattern.search(block)
    if not m:
        raise ValueError("未找到 Latency min/max 数据行")
    return int(m.group(2))


def extract_total_dsp(report_text: str) -> int:
    util_section = report_text.find("== Utilization Estimates")
    if util_section == -1:
        raise ValueError("未找到 Utilization Estimates 区域")

    util_text = report_text[util_section:]
    lines = util_text.splitlines()
    header_idx = -1
    for i, line in enumerate(lines):
        if "Name" in line and "DSP" in line and "|" in line:
            header_idx = i
            break
    if header_idx == -1:
        raise ValueError("未找到资源表头（包含 DSP 列）")

    headers = [x.strip() for x in lines[header_idx].strip().strip("|").split("|")]
    if "DSP" not in headers:
        raise ValueError("表头中未找到 DSP 列")
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
        raise ValueError("未找到 Total 行")

    if dsp_col >= len(total_row):
        raise ValueError("Total 行缺少 DSP 列")
    dsp_str = total_row[dsp_col].replace(",", "")
    if not dsp_str.isdigit():
        raise ValueError(f"DSP 值格式异常: {dsp_str}")
    return int(dsp_str)


def main() -> None:
    parser = argparse.ArgumentParser(description="从 Vitis HLS .rpt 报告提取 max latency 和总 DSP")
    parser.add_argument("rpt_file", help="输入 .rpt 文件路径")
    args = parser.parse_args()

    rpt_path = normalize_input_path(args.rpt_file)
    if rpt_path.suffix.lower() != ".rpt":
        raise SystemExit("输入文件必须是 .rpt 后缀")
    if not rpt_path.exists():
        raise SystemExit(f"文件不存在: {rpt_path}")

    text = rpt_path.read_text(encoding="utf-8", errors="ignore")
    max_latency = extract_max_latency(text)
    dsp_total = extract_total_dsp(text)
    print(f"max latency = {max_latency}    DSP = {dsp_total}")


if __name__ == "__main__":
    main()
