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
    n = int(oi.next())
    s = int(oi.next())
    
    a = [0] * n * 2
    prefix_sum = [0] * n
    
    for i in range(n):
        a[i] = int(oi.next())
        if i > 0:
            prefix_sum[i] = prefix_sum[i - 1] + a[i]
        else:
            prefix_sum[i] = a[i]
    
    if s % prefix_sum[n - 1] == 0:
        print("Yes")
        exit(0)
    
    for i in range(n):
        a[i + n] = a[i]
    
    lack = prefix_sum[n - 1] * (1 + s // prefix_sum[n - 1]) - s
    ans = "No"
    su = 0
    left = 0
    for right in range(n + n):
        su += a[right]
        # print(left, right, su, lack, a[right])
        while left <= right and su > lack:
            su -= a[left]
            left += 1
        if su == lack:
            ans = "Yes"
            break
    
    print(ans)
