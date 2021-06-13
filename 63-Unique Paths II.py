class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
# First try
        if obstacleGrid[0][0] == 1:
            return 0
        
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        
        dp = [[0]*n for _ in range(m)]
        dp[0][0] = 1
        
        for j in range(1, n):
            if obstacleGrid[0][j] == 1:
                dp[0][j:] = [0]*(n-j)
                break
            else:
                dp[0][j] = 1

        for i in range(1, m):
            if obstacleGrid[i][0] == 1:
                dp[i][0] = 0
            elif dp[i-1][0] != 0:
                dp[i][0] = 1
        
        for i in range(1, m):
            for j in range(1, n):
                if obstacleGrid[i][j] == 1:
                    continue
                else:
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]
                    
        return dp[-1][-1]
    
# Better 
        if not obstacleGrid:
            return 0
        if obstacleGrid[0][0] or obstacleGrid[-1][-1]:
            return 0
        row = len(obstacleGrid)
        col = len(obstacleGrid[0])
        dp = [[0]*(col+1) for _ in range(row+1)]
        dp[0][1] = 1
        for r in range(1,row+1):
            for c in range(1,col+1):
                if obstacleGrid[r-1][c-1] == 1:
                    dp[r][c] == 0
                else:
                    dp[r][c] = dp[r-1][c]+dp[r][c-1]
        return dp[-1][-1]