import sys

class OI:
    def __init__(self):
        self.buffer = []
        self.current_line = None
        self.line_index = 0
    
    def _read_line(self):
        """读取一行输入并按空格分割成列表"""
        self.current_line = sys.stdin.readline().strip()
        self.buffer = self.current_line.split() if self.current_line else []
        self.line_index = 0
    
    def next(self):
        """返回下一个有效的元素"""
        if self.line_index < len(self.buffer):
            result = self.buffer[self.line_index]
            self.line_index += 1
            return result
        else:
            # 如果当前行没有元素了，读取下一行
            self._read_line()
            if not self.current_line:
                return None  # 如果没有更多的行，返回None
            return self.next()  # 递归调用，返回下一个元素
    
    def has_next(self):
        """检查是否还有下一个元素"""
        return bool(self.current_line or sys.stdin.peek(1))  # 如果有下一行或输入，返回True

oi = OI()

if __name__ == "__main__":
    scores = [0] * 5
    for i in range(5):
        scores[i] = int(oi.next())
    
    ans = []
    names = 'ABCDE'
    
    for i in range(1, 32):
        ii = i
        cnt = 0
        score = 0
        name = []
        while ii != 0:
            if ii % 2 == 1:
                score += scores[cnt]
                name.append(names[cnt]) 
            cnt += 1
            ii //= 2
        ans.append((score, ''.join(name)))
    
    ans = sorted(ans, key=lambda x: (-x[0], x[1]))
    for a in ans:
        print(a[1])
