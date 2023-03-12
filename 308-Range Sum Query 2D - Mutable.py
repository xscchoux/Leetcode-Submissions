class BIT:
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n+1)

    def update(self, i, delta):
        while i <= self.n:
            self.bit[i] += delta
            i += i & (-i)

    def query(self, i):
        result = 0
        while i > 0:
            result += self.bit[i]
            i -= i & (-i)
        return result

class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        row = len(matrix)
        col = len(matrix[0])
        self.BIT = BIT(row*col+1)
        for r in range(row):
            for c in range(col):
                self.BIT.update(r*col+c+1, matrix[r][c])
        self.colLength = col

    def update(self, row: int, col: int, val: int) -> None:
        old_val = self.sumRegion(row, col, row, col)
        self.BIT.update(row*self.colLength+col+1, val-old_val)

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        res = 0
        for r in range(row1, row2+1):
            res += self.BIT.query(r*self.colLength+col2+1) -self.BIT.query(r*self.colLength+col1)
        return res


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# obj.update(row,col,val)
# param_2 = obj.sumRegion(row1,col1,row2,col2)