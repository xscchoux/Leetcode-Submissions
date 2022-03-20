class Solution:
    def minimumWhiteTiles(self, floor: str, numCarpets: int, carpetLen: int) -> int:
        
# Top-down DP
        @lru_cache(None)
        def dp(i, t):
            if t < 0:
                return float('inf')
            if i < 0:
                return 0

            return min( dp(i-carpetLen, t-1), int(floor[i]) + dp(i-1, t) )
        
        return dp(len(floor)-1, numCarpets)
    
# Bottom-up DP, barely pass
        N = len(floor)
        dp = [[float('inf')]*(numCarpets+1) for _ in range(N+1)]    
        
        for k in range(numCarpets+1):
            dp[0][k] = 0 
        
        for i in range(1, N+1):
            dp[i][0] = dp[i-1][0] + int(floor[i-1])
        
        for k in range(1, numCarpets+1):
            for i in range(1, N+1):
                if i - carpetLen >= 0:
                    dp[i][k] = min( dp[max(0, i-carpetLen)][k-1], dp[i-1][k] + int(floor[i-1]) )        
                else:
                    dp[i][k] = dp[0][k-1]
                    
        return dp[N][numCarpets]