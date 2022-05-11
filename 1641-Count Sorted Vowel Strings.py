class Solution(object):
    def countVowelStrings(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [1]*5
        
        for i in range(1, n):
            for j in range(1, 6):
                for k in range(j+1, 6):
                    dp[j-1] += dp[k-1]
                    
        return sum(dp)