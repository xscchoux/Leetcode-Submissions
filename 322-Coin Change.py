class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
# DP O(amount * number of coins)
        dp = [amount+1]*(amount+1)
        dp[0] = 0
        
        for coin in coins:
            for i in range(coin, amount+1):
                dp[i] = min(dp[i], dp[i-coin]+1)
                
        return dp[-1] if dp[-1] != amount+1 else -1