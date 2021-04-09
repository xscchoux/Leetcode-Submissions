class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        lenP, lenS = len(p), len(s)
        dp = [[False]*(lenP+1) for _ in range(lenS+1)]
        
        dp[0][0] = True
        
        for j in range(1, lenP+1):
            if p[j-1] == '*' and dp[0][j-2]:
                dp[0][j] = True
        
        for i in range(1, lenS+1):
            for j in range(1, lenP+1):
                if p[j-1] == s[i-1] or p[j-1] == '.':
                    dp[i][j] = dp[i-1][j-1]
                elif p[j-1] == '*':
                    dp[i][j] = dp[i][j-2]
                    if p[j-2] == s[i-1] or p[j-2] == '.':
                        dp[i][j] = dp[i][j] or dp[i-1][j]
                else:
                    dp[i][j] = False
        
        return dp[-1][-1]