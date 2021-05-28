class Solution(object):
    def maxA(self, N):
        """
        :type N: int
        :rtype: int
        """

        dp = range(N+1)
    
        for i in range(3, N+1):
            for j in range(2, i-2):
                dp[i] = max(dp[i], (i-j-1)*dp[j])
                
        return dp[N]