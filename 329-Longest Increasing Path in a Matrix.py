class Solution(object):
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
# O(mn)

        if not matrix or not matrix[0]:
            return 0
        row = len(matrix)
        col = len(matrix[0])
        dp = [[-1]*col for _ in range(row)]

        
        def dfs(r, c):
            if dp[r][c] != -1:
                return dp[r][c]
            
            ans = 1
            for dr, dc in ((1,0),(0,1),(-1,0),(0,-1)):
                newR = r + dr
                newC = c + dc
                if 0<=newR<row and 0<=newC<col and matrix[newR][newC] > matrix[r][c]:
                    ans = max(ans, dfs(newR, newC)+1 )
            dp[r][c] = ans
            return dp[r][c]
        
        res = 0
        for r in range(row):
            for c in range(col):
                res = max(res, dfs(r, c))
        return res