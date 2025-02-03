import argparse
import os
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import re
from collections import defaultdict
import numpy as np

def parse_arguments():
    """解析命令行参数"""
    parser = argparse.ArgumentParser(
        description='Memory Trace Analysis Tool',
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument('logfile', 
                        type=str,
                        help='Path to memory trace log file')
    return parser.parse_args()

def main():
    # 解析命令行参数
    args = parse_arguments()
    
    # 校验文件是否存在
    if not os.path.isfile(args.logfile):
        print(f"Error: Log file '{args.logfile}' not found")
        exit(1)

    # 配置参数
    OPERATIONS = ['flash_read', 'sdram_read', 'sdram_write', 'paddr_read', 'paddr_write']

    # 正则表达式模式
    access_pattern = re.compile(
        r'(?P<op>{}) ---.*?addr: (?P<addr>0x[0-9a-f]+).*?pc: (?P<pc>0x[0-9a-f]+)'.format('|'.join(OPERATIONS)),
        re.IGNORECASE
    )

    # 数据结构存储访问记录
    memory_access = {
        'timestamps': [],
        'operations': [],
        'addresses': [],
        'pcs': []
    }

    # 解析日志文件
    with open(args.logfile) as f:
        for line_num, line in enumerate(f, 1):
            match = access_pattern.search(line)
            if match:
                try:
                    addr = int(match.group('addr'), 16)
                    pc = int(match.group('pc'), 16)
                    if addr <= 0 or pc <= 0:
                        continue
                    memory_access['operations'].append(match.group('op'))
                    memory_access['addresses'].append(addr)
                    memory_access['pcs'].append(pc)
                    memory_access['timestamps'].append(len(memory_access['timestamps']))
                except ValueError as e:
                    print(f"Line {line_num}: Invalid data format - {line.strip()} ({str(e)})")

    # 时空局部性分析函数
    def analyze_locality(sequence, name):
        analysis = {
            'name': name,
            'time_locality': defaultdict(int),
            'spatial_deltas': [],
            'sequence': sequence
        }
        
        prev = None
        for val in sequence:
            analysis['time_locality'][val] += 1
            if prev is not None:
                analysis['spatial_deltas'].append(abs(val - prev))
            prev = val
        return analysis

    # 执行分析
    addr_analysis = analyze_locality(memory_access['addresses'], 'Address')
    pc_analysis = analyze_locality(memory_access['pcs'], 'PC')

    # 可视化设置
    plt.figure(figsize=(18, 12))
    plt.rcParams.update({'font.size': 10, 'figure.dpi': 150})

    # 绘图函数
    def plot_analysis(analysis, pos):
        # 时间局部性
        plt.subplot(3, 2, pos)
        plt.hist(analysis['time_locality'].values(), bins=50, 
                 color='teal', alpha=0.7, edgecolor='black')
        plt.title(f'{analysis["name"]} Time Locality')
        plt.xlabel('Access Count')
        plt.ylabel('Frequency')
        plt.grid(True, linestyle=':', alpha=0.6)

        # 空间局部性
        plt.subplot(3, 2, pos+1)
        plt.hist(analysis['spatial_deltas'], bins=100, 
                 color='darkorange', alpha=0.7, edgecolor='black')
        plt.title(f'{analysis["name"]} Spatial Locality')
        plt.xlabel('Address Delta')
        plt.ylabel('Frequency')
        plt.yscale('log')
        plt.grid(True, linestyle=':', alpha=0.6)

    # 绘制分析结果
    plot_analysis(addr_analysis, 1)
    plot_analysis(pc_analysis, 3)

    # 地址-PC关联分析
    plt.subplot(3, 2, 5)
    valid_indices = np.where((np.array(memory_access['addresses']) > 0) & 
                            (np.array(memory_access['pcs']) > 0))[0]
    valid_addresses = np.array(memory_access['addresses'])[valid_indices]
    valid_pcs = np.array(memory_access['pcs'])[valid_indices]

    hexbin = plt.hexbin(valid_addresses, valid_pcs,
                       gridsize=50, cmap='viridis', bins='log', 
                       xscale='log', yscale='log')
    plt.colorbar(hexbin, label='Access Count')
    plt.title('Address-PC Correlation')
    plt.xlabel('Memory Address (log)')
    plt.ylabel('Program Counter (log)')

    # 操作类型分布
    plt.subplot(3, 2, 6)
    op_count = defaultdict(int)
    for op in memory_access['operations']:
        op_count[op] += 1
    plt.pie(op_count.values(), labels=op_count.keys(),
            autopct=lambda p: f'{p:.1f}%' if p > 5 else '',
            startangle=90,
            colors=['#ff9999','#66b3ff','#99ff99','#ffcc99'])
    plt.title('Operation Type Distribution')

    # 保存结果
    output_file = f"{os.path.splitext(args.logfile)[0]}_analysis.png"
    plt.tight_layout()
    plt.savefig(output_file)
    print(f"\nAnalysis completed. Result saved to: {output_file}")

if __name__ == "__main__":
    main()