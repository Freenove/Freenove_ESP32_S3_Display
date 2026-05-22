import os

# 配置：偏移地址 和 文件路径
# 注意：Windows下路径分隔符建议使用 / 或 \\
file_config = [
    (0x0,  "bootloader.bin"),
    (0x8000,  "partition-table.bin"),
    (0xd000,  "ota_data_initial.bin"),
    (0x10000, "srmodels.bin"),
    (0x100000,  "xiaozhi.bin"),
]

output_filename = "merged_output.bin"

def merge_files():
    # 1. 计算合并后的总文件大小
    max_address = 0
    for offset, path in file_config:
        if not os.path.exists(path):
            print(f"错误: 找不到文件 {path}")
            return
        
        file_size = os.path.getsize(path)
        end_address = offset + file_size
        if end_address > max_address:
            max_address = end_address
            
    print(f"计算出的固件总大小: {max_address} 字节 ({max_address/1024:.2f} KB)")

    # 2. 创建一个全为 0xFF 的缓冲区
    # 0xFF 是 Flash 的默认擦除状态
    firmware_data = bytearray([0xFF] * max_address)

    # 3. 将每个文件写入缓冲区的对应位置
    for offset, path in file_config:
        print(f"正在写入: {path} -> 偏移量 0x{offset:X}")
        with open(path, 'rb') as f:
            content = f.read()
            # 将内容替换到 bytearray 的指定位置
            firmware_data[offset : offset + len(content)] = content

    # 4. 保存结果
    with open(output_filename, 'wb') as f:
        f.write(firmware_data)
    
    print(f"✅ 合并完成！输出文件: {output_filename}")

if __name__ == "__main__":
    merge_files()