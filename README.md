# XCPCpractice

## `.vscode` 和预编译的巧思

### 文件输入输入

在 `.vscode` 中，编辑 `launch.json` 的 `"args"` 一项：

```json
"args": [
    "<", 
    "${workspaceFolder}/input.txt", 
    ">", 
    "${workspaceFolder}/output.txt"
],
```

### 预编译 `bits/stdc++.h`


使用命令 `g++ -std=c++20 -v -x c++ -E /dev/null` 查看 `bits/stdc++.h` 具体在哪个路径下。

然后可以使用 `g++ <-std=c++ 标准> -x c++-header <stdc++.h 路径> -o <输出路径/stdc++.gch>` 预编译头文件，我的命令为：

```bash
g++ -std=c++20 -x c++-header /usr/include/aarch64-linux-gnu/c++/13/bits/stdc++.h -o ~/XCPCpractice/.pch/stdc++.gch
```

然后再修改 `tasks.json`，插入使用预编译头文件的命令：

```json
"args": [
    // ...
    "${workspaceFolder}/.pch/stdc++.gch",
    // ...
]
```

以上是错误的，未完待续，暂时不折腾了……

## WSL on Win Arm 使用笔记

### 安装

[_Get started with Windows Subsystem for Linux (WSL) on Arm_](https://learn.arm.com/learning-paths/laptops-and-desktops/wsl2/)

### 代理

并不用编辑代理脚本，参照：https://blog.csdn.net/iftodayhappy/article/details/137236279、

在 Windows 主机上编辑 `~\.wslconfig`：

```cpp
[wsl2]
memory=12GB
processors=8
[experimental]
autoMemoryReclaim=gradual
networkingMode=mirrored
dnsTunneling=true
firewall=true
autoProxy=true
sparseVhd=true
```