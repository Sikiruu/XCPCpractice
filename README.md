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


