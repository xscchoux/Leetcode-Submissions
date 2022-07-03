class Solution(object):
    def peopleAwareOfSecret(self, n, delay, forget):
        """
        :type n: int
        :type delay: int
        :type forget: int
        :rtype: int
        """
# Instead of having dp[i] represent the people that know the secret, we can let dp[i] represent the people that figured out the secret on day i
        dp = [0]*(n+1)
        dp[1] = 1
        kMod = 1000000007
        share = 0
        
        for i in range(2, n+1):
            share += dp[i-delay]
            share -= dp[i-forget]
            dp[i] = share
        
        res = 0
        for j in range(n, n-forget, -1):
            res = (res + dp[j])%kMod
            
        return res