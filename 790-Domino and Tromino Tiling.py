class Solution(object):
    def numTilings(self, n):
        """
        :type n: int
        :rtype: int
        """
# https://www.youtube.com/watch?v=S-fUTfqrdq8

        kMod = 1000000007
        dp =[[0]*2 for _ in range(n+1)]
        dp[0][0] = 1
        dp[1][0] = 1
        
        for i in range(2, n+1):
            dp[i][0] = (dp[i-1][0] + dp[i-2][0] + 2*dp[i-1][1])%kMod
            dp[i][1] = (dp[i-2][0] + dp[i-1][1])%kMod
                        
        return dp[n][0]