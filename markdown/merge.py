import os
import pypandoc

# 定义MD文件所在路径
md_dir = './'  # 根据需要修改为你的文件夹路径
md_files = [
    "STL.md", "动态规划.md", "基本算法.md", 
    "字符串.md", "对拍.md", "数学.md", "数据结构.md", "树和图论.md"
]

# 合并输出的文件路径
output_path = os.path.join(md_dir, '合并文档.docx')

# 使用 Pandoc 将 Markdown 文件合并为一个 Word 文件
# 主要设置：统一使用 Consolas 字体，并启用代码块语法高亮
pypandoc.convert_file(
    md_files,
    'docx',
    outputfile=output_path,
    extra_args=[
        '--standalone',           # 独立文档
        '--highlight-style=pygments',  # 启用代码块语法高亮（Pygments 样式）
        '--variable', 'monofont=Consolas',  # 统一设置 Consolas 为代码字体
        '--variable', 'mainfont=Consolas',  # 统一设置 Consolas 为正文字体
        '--variable', 'CJKmainfont=Consolas'  # 统一设置 Consolas 为中文字体
    ]
)

print(f'文档已保存为: {output_path}')
