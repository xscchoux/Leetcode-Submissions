class Solution(object):
    def change(self, amount, coins):
        """
        :type amount: int
        :type coins: List[int]
        :rtype: int
        """
        
# 2-dimensional dp
        n = len(coins)
        dp = [ [1]+[0]*amount for _ in range(n+1)]

        for i in range(1,n+1):
            for j in range(amount+1):
                if j < coins[i-1]:
                    dp[i][j] = dp[i-1][j]
                else:
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]]  
        return dp[-1][-1]
    
# 1-dimensional dp

        dp = [0]*(amount+1)
        dp[0] = 1
        for coin in coins:
            for j in range(coin, amount+1):
                dp[j] += dp[j-coin]
        
        return dp[-1]