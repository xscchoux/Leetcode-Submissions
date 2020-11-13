class Solution(object):
    def minFallingPathSum(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        row = len(A)
        col = len(A[0])
        
        if len(A) == 1:
            return min(A[0])
        
        res = float('inf')
        
        for r in range(1, row):
            for c in range(col):
                best = A[r-1][c]
                if c > 0:
                    best = min(A[r-1][c-1], best)
                if c < col-1:
                    best = min(A[r-1][c+1], best)
                A[r][c] += best
                if r == row-1:
                    res = min(res, A[r][c])
        
        return res