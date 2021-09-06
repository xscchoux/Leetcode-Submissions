class Solution(object):
    def maxMatrixSum(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        row, col = len(matrix), len(matrix[0])
        res = 0
        bad = 0   # num of negative numbers
        absMin = float('inf')
        
        for r in range(row):
            for c in range(col):
                absNum = abs(matrix[r][c])
                res += absNum
                if matrix[r][c] < 0:
                    bad += 1
                absMin = min(absMin, absNum)
        
        if bad%2:
            res -= 2*absMin
        
        return res