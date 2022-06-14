class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        l1, l2 = len(word1), len(word2)
        
        dp = [[0]*(l1+1) for _ in range(l2+1)]
        
        for i in range(l2):
            for j in range(l1):
                if word1[j] == word2[i]:
                    dp[i+1][j+1] = dp[i][j]+1
                else:
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j])
                    
        return l1 + l2 - 2*dp[-1][-1]