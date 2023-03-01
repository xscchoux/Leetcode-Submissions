class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
    
# top down
        @cache
        def dp(l1, l2):
            if l1 < 0 or l2 < 0:
                if l1 < 0:
                    return l2 + 1
                else:
                    return l1 + 1
            if word1[l1] == word2[l2]:
                return dp(l1-1, l2-1)
            else:
                return 1 + min(dp(l1-1, l2-1), dp(l1-1, l2), dp(l1, l2-1))
        
        return dp(len(word1)-1, len(word2)-1)
    
# bottom up    
        l1, l2 = len(word1), len(word2)
        dp = [[0]*(l2+1) for _ in range(l1+1)]
        
        for j in range(l2+1):
            dp[0][j] = j
            
        for i in range(l1+1):
            dp[i][0] = i
            
        for i in range(1, l1+1):
            for j in range(1, l2+1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = 1 + min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) # replace, delete, insert
        
        return dp[-1][-1]
