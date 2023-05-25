class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        if k == 0 or n >= k + maxPts:
            return 1
        
        dp = [0]*(n+1)
        dp[0] = 1
        s = 1
        
        for i in range(1, n+1):
            dp[i] = s/maxPts
            if i < k:
                s += dp[i]
            if 0 <= i - maxPts < k:
                s -= dp[i-maxPts]
        
        return sum(dp[k:])