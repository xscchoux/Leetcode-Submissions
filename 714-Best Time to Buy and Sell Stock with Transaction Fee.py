class Solution(object):
    def maxProfit(self, prices, fee):
        """
        :type prices: List[int]
        :type fee: int
        :rtype: int
        """
# 0: without stock, 1: with stock
# dp: money left
# dp[0][i] = max(dp[0][i-1], dp[1][i-1]+A[i])
# dp[1][i] = max(dp[1][i-1], dp[0][i-1]-A[i]-c)

        without, holding = 0, -prices[0]-fee
        
        for i in range(1, len(prices)):
            without, holding = max(without, holding + prices[i]), max(holding, without-prices[i]-fee)
        
        return without