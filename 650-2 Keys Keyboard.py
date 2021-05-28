class Solution(object):
    def minSteps(self, n):
        """
        :type n: int
        :rtype: int
        """


# dp solution, Time:O(n^2), Space:O(n)

        dp = [i for i in range(n+1)]
        dp[1] = 0
        
        for i in range(2, n+1):
            for j in range(2, i//2+1):
                if i%j == 0:
                    dp[i] = min(dp[i], i//j + dp[j])
        
        return dp[n]
              
# Prime factorization, Time:O(n), Space:O(1)
        
        res = 0
        d = 2
        
        while n > 1:
            while n%d == 0:
                res += d
                n = n//d
            d+=1
            
        return res