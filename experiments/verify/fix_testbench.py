import os
import re
import sys



def convert_large_vars_to_static(content, threshold_bytes=512*1024):
    def replacer(match):
        indent = match.group(1)    
        dtype = match.group(2)      
        var_name = match.group(3)   
        shape_str = match.group(4)  
        
        dims = re.findall(r'\d+', shape_str)
        elements = 1
        for d in dims:
            elements *= int(d)
        
        total_bytes = elements * 4
        
        if total_bytes >= threshold_bytes:
            return f"{indent}static {dtype} {var_name}{shape_str};"
        return match.group(0)

    pattern = r'^(\s*)(float|int32_t|int|double)\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*((?:\[\d+\])+)\s*;'
    return re.sub(pattern, replacer, content, flags=re.MULTILINE)

def extract_signature_from_a(file_a_path):
    """从 A 文件中提取 main_graph 的参数类型列表"""
    with open(file_a_path, 'r', encoding='utf-8') as f:
        content = f.read()
    
    match = re.search(r'void\s+main_graph\s*\((.*?)\)\s*\{', content, re.DOTALL)
    if not match:
        print("Error: Could not find main_graph definition in File A")
        return []

    params_str = match.group(1)
    params = []
    for p in params_str.split(','):
        p = p.strip()
        type_only = re.sub(r'\s+[a-zA-Z_][a-zA-Z0-9_]*\s*', ' ', p).strip()
        type_only = re.sub(r'\s+', ' ', type_only)
        params.append(type_only)
    return params

def extract_vars_from_b(file_b_path):
    """从 B 文件中提取传给 main_graph 的变量名"""
    if not os.path.exists(file_b_path):
        return []

    with open(file_b_path, 'r', encoding='utf-8') as f:
        content = f.read()
    
    main_start = re.search(r'int\d*_t\s+main\s*\(', content)
    if not main_start: return []
    
    call_match = re.search(r'(?<!void\s)main_graph\s*\((.*?)\);', content[main_start.start():])
    if not call_match: return []

    args_str = call_match.group(1)
    args = [a.strip() for a in args_str.split(',')]
    return args

def delpackage(file_path):
    if not os.path.exists(file_path): return
    packages = ["ap_axi_sdata.h", "ap_fixed.h", "ap_int.h", "hls_math.h", "hls_stream.h", "hls_vector.h", "hls_half.h"]
    with open(file_path, 'r', encoding='utf-8') as f:
        content = f.read()
    header_pattern = r'#include\s*<(' + '|'.join(map(re.escape, packages)) + r')>.*\n?'
    content = re.sub(header_pattern, '', content)
    content = re.sub(r'\bap_int\s*<\s*64\s*>', 'int', content)
    with open(file_path, 'w', encoding='utf-8') as f:
        f.write(content)

def process_files(file_a_path, file_b_path):
    with open(file_a_path, 'r', encoding='utf-8') as f:
        a_content = f.read()
    
    print(f"Processing internal variables in {file_a_path}...")
    a_content = convert_large_vars_to_static(a_content)
    
    with open(file_a_path, 'w', encoding='utf-8') as f:
        f.write(a_content)

    params_a = extract_signature_from_a(file_a_path)
    with open(file_b_path, 'r', encoding='utf-8') as f:
        b_content = f.read()

    print(f"Processing variables in {file_b_path}...")
    b_content = convert_large_vars_to_static(b_content)

    decl_pattern = r'void\s+main_graph\s*\((.*?)\);'
    new_decl_str = "void main_graph(\n  " + ",\n  ".join(params_a) + "\n);"
    b_content = re.sub(decl_pattern, new_decl_str, b_content, flags=re.DOTALL)

    vars_in_b = extract_vars_from_b(file_b_path)
    if vars_in_b:
        diff = len(params_a) - len(vars_in_b)
        if diff >= 0:
            new_call_args = [vars_in_b[0]] * (diff + 1) + vars_in_b[1:]
            new_call_args_str = ", ".join(new_call_args)
            call_pattern = r'(?<!void\s)main_graph\s*\((.*?)\);'
            b_content = re.sub(call_pattern, f"main_graph({new_call_args_str});", b_content, count=1)

    with open(file_b_path, 'w', encoding='utf-8') as f:
        f.write(b_content)
    
    delpackage(file_a_path)
    delpackage(file_b_path)

    print(f"Successfully processed both files.")
    print(f"All local arrays > 512KB have been moved to static storage.")

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python fix_resnet.py <ResNet18.cpp> <ResNet18_tb.cpp>")
    else:
        process_files(sys.argv[1], sys.argv[2])