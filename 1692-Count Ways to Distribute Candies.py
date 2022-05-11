class Solution(object):
    def waysToDistribute(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        dp = [[0]*(n+1) for _ in range(k+1)]
        kMod = 1000000007
        
        for i in range(1, k+1):
            dp[i][i] = 1
            
        for i in range(1, k+1):
            for j in range(i+1, n+1):
                dp[i][j] = (i*dp[i][j-1] + dp[i-1][j-1])%kMod
                
        return dp[k][n]