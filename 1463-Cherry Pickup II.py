class Solution(object):
    def cherryPickup(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        row, col = len(grid), len(grid[0])
        # x = [[[0 for k in range(p)] for j in range(n)] for i in range(m)]
        
        dp = [[[-1]*col for c1 in range(col)] for r in range(row)]
        
        def dfs(c1, c2, r):
            if r == row:
                return 0
            
            if dp[r][c2][c1] != -1:
                return dp[r][c2][c1]
            
            maxVal = 0
            for dc1 in range(-1, 2, 1):
                if 0 <= c1 + dc1 < col:
                    for dc2 in range(-1, 2, 1):
                        if 0 <= c2 + dc2 < col:
                            maxVal = max(maxVal, dfs(c1+dc1, c2+dc2, r+1))
            if c1 == c2:
                dp[r][c2][c1] = grid[r][c1] + maxVal
            else:
                dp[r][c2][c1] = grid[r][c1] + grid[r][c2] + maxVal
            return dp[r][c2][c1]
        
        return dfs(0, col-1, 0)