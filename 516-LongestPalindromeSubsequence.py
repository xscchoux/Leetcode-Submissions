class Solution(object):
    def longestPalindromeSubseq(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        
        if s == s[::-1]:    # this line improves time complexity substantially
            return n
        
        dp = [[0]*n for _ in range(n)]
        for i in range(n):
            dp[i][i] = 1
        for length in range(2,n+1):
            for i in range(0,n-length+1):
                j = i + length - 1
                if s[i] == s[j]:
                    dp[i][j] = dp[i+1][j-1] + 2
                else:
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j])
                
        return dp[0][-1]