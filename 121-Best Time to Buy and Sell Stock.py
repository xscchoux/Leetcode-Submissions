class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        _min = float('inf')
        res = 0
        for i in range(len(prices)):
            _min = min(_min, prices[i])
            res = max(res, prices[i]-_min)
            
        return res