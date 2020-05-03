class Solution(object):
    def cherryPickup(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        N = len(grid)
        dp = [[[None]*N for _1 in range(N)] for _2 in range(N)]
        
        def dfs(r1, c1, r2):
            c2 = r1+c1-r2
            if r1 == N or c1 == N or r2 == N or c2 == N or grid[r1][c1] == -1 or grid[r2][c2] == -1:
                return float('-inf')
            elif r1 == c1 == N-1:
                return grid[r1][c1]
            elif dp[r1][c1][r2] is not None:
                return dp[r1][c1][r2]
            else:
                ans = grid[r1][c1] + (r1!=r2)*grid[r2][c2]
                ans += max(dfs(r1,c1+1,r2), dfs(r1+1,c1,r2), dfs(r1,c1+1,r2+1), dfs(r1+1,c1,r2+1))
            dp[r1][c1][r2] = ans
            return ans
            
        return max(0, dfs(0,0,0))