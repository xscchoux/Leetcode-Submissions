class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
# https://www.youtube.com/watch?v=MyJvMydR2G4
# time complexity: O(N^2)
# space complexity: O(N^2)
# Bottom-Up DP
        directions = [(2,1),(1,2),(-1,2),(-2,1),(1,-2),(2,-1),(-1,-2),(-2,-1)]
        dp = [[0]*n for _ in range(n)]
        dp[row][column] = 1
        
        for _ in range(k):
            tmp = [[0]*n for _ in range(n)]
            for r in range(n):
                for c in range(n):
                    for dr, dc in directions:
                        nr = r+dr
                        nc = c+dc
                        if 0<=nr<n and 0<=nc<n:
                            tmp[nr][nc] += dp[r][c]/8
            dp = tmp
        
        res = 0
        for r in range(n):
            for c in range(n):
                res += dp[r][c]
        
        return res
                    
        
# Top-Down DP
        directions = [(2,1),(1,2),(-1,2),(-2,1),(1,-2),(2,-1),(-1,-2),(-2,-1)]
    
        @cache
        def dp(r, c, move):
            if move == 0:
                return 1
            res = 0
            for dr, dc in directions:
                if 0<=r+dr<n and 0<=c+dc<n:
                    res += dp(r+dr, c+dc, move-1)/8
            return res
        
        return dp(row, column, k)