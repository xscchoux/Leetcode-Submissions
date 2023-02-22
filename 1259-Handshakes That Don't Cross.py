class Solution:
    def numberOfWays(self, numPeople: int) -> int:
        # Choose one arbitrary person and handshake with each other
        # so there is an even number of people on each sides of the
        # handshake pair
        
        kMod = 1000000007
        dp = [0]*(numPeople//2+1)
        dp[0] = 1
        for i in range(1, numPeople//2+1):
            for j in range(i):
                dp[i] += dp[j]*dp[i-j-1]  # leftside*rightside
                dp[i]%=kMod
        
        return dp[-1]