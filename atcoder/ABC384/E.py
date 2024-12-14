import heapq

# 上、下、左、右
DIRECTIONS = [(-1, 0), (1, 0), (0, -1), (0, 1)]

def max_strength_with_priority_queue(H, W, X, P, Q, grid):
    # 将 P, Q 转换为 0-indexed
    P -= 1
    Q -= 1
    
    # 初始化优先队列 (最小堆)，存储 (史莱姆强度, x, y)
    pq = []
    
    # 记录已访问的单元格
    visited = [[False] * W for _ in range(H)]
    visited[P][Q] = True
    
    # Takahashi 初始的强度
    current_strength = grid[P][Q]
    
    # 将初始位置的邻居加入堆中
    for dx, dy in DIRECTIONS:
        nx, ny = P + dx, Q + dy
        if 0 <= nx < H and 0 <= ny < W and not visited[nx][ny]:
            # 加入堆
            heapq.heappush(pq, (grid[nx][ny], nx, ny))
            visited[nx][ny] = True
    
    while pq:
        strength, x, y = heapq.heappop(pq)
        
        # 是否可吸收
        if strength < current_strength / X:
            # 吸收
            current_strength += strength
            
            # 相邻格子
            for dx, dy in DIRECTIONS:
                nx, ny = x + dx, y + dy
                # 是否合法、未访问
                if 0 <= nx < H and 0 <= ny < W and not visited[nx][ny]:
                    visited[nx][ny] = True
                    # 将新吸收的史莱姆加入堆中
                    heapq.heappush(pq, (grid[nx][ny], nx, ny))
    
    return current_strength

H, W, X = map(int, input().split())
P, Q = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(H)]

result = max_strength_with_priority_queue(H, W, X, P, Q, grid)
print(result)
