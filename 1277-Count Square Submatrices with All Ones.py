class Solution(object):
    def countSquares(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        row = len(matrix)
        col = len(matrix[0])
        
        for r in range(1, row):
            for c in range(1, col):
                matrix[r][c] *= 1 + min(matrix[r-1][c-1], matrix[r-1][c], matrix[r][c-1])
        
        return sum(map(sum, matrix))