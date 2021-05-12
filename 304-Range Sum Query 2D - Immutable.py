class NumMatrix(object):

    def __init__(self, matrix):
        """
        :type matrix: List[List[int]]
        """
        row, col = len(matrix), len(matrix[0])
        self.dp = [[0]*(col+1) for _ in range(row+1)]
        for r in range(1, row+1):
            for c in range(1, col+1):
                self.dp[r][c] = self.dp[r-1][c] + self.dp[r][c-1] + matrix[r-1][c-1] - self.dp[r-1][c-1]

    def sumRegion(self, row1, col1, row2, col2):
        """
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        
        return self.dp[row2+1][col2+1] - self.dp[row1][col2+1] - self.dp[row2+1][col1] + self.dp[row1][col1]


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)