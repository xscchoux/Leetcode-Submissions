class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        
# dp(i,j) = min(dp(i−1,j),dp(i−1,j−1),dp(i,j−1))+1.

        row = len(matrix)
        col = len(matrix[0])
        
        res = 0
        
        for r in range(row):
            for c in range(col):
                if matrix[r][c] != "0":
                    if r-1 >= 0 and c-1 >= 0:
                        matrix[r][c] = min(matrix[r-1][c], matrix[r][c-1], matrix[r-1][c-1])+1
                    else:
                        matrix[r][c] = int(matrix[r][c])
                    res = max(res, int(matrix[r][c]) )
                else:
                    matrix[r][c] = 0
                
        return res*res