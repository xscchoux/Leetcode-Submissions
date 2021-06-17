class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        dp = [0]*(n+1)
        dp[0] = 1
        
        for i in range(len(s)):
            if 1 <= int(s[i]) <= 9:
                dp[i+1] += dp[i]
            if i > 0:
                if 10 <= int(s[i-1:i+1]) <= 26:
                    dp[i+1] += dp[i-1]
            if dp[i+1] == 0:
                return 0

        return dp[-1]