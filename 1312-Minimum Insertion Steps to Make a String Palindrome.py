class Solution(object):
    def minInsertions(self, s):
        """
        :type s: str
        :rtype: int
        """
        
# DFS + memoization
        memo = dict()
        
        def dp(l, r):
            if l >= r:
                return 0
            if (l, r) in memo:
                return memo[(l,r)]
            
            if s[l] == s[r]:
                memo[(l, r)] = dp(l+1, r-1)
            else:
                memo[(l, r)] = min(dp(l, r-1), dp(l+1,r)) + 1
            return memo[(l, r)]
        
        return dp(0, len(s)-1)
    
# DP
        if len(s) <= 1:
            return 0
        dp = [[0]*len(s) for _ in range(len(s))]
        for l in range(2, len(s)+1):
            for i in range(len(s)):
                j = i+l-1
                if j >= len(s):
                    break
                    
                if s[i] == s[j]:
                    dp[i][j] = dp[i+1][j-1]
                else:
                    dp[i][j] = min(dp[i][j-1], dp[i+1][j]) + 1
        return dp[0][len(s)-1]