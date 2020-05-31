class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
# bidirectional DP
# Time complexity: O(n)
# Space complexity: O(n)
        if len(prices) <= 1:
            return 0
        
        N = len(prices)
        
        left = [0]*N
        _min = prices[0]
        for i in range(1,N):
            left[i] = max(prices[i]-_min, left[i-1])
            _min = min(prices[i], _min)
            
        right = [0]*N
        _max = prices[-1]
        for j in range(N-2, -1, -1):
            right[j] = max(_max - prices[j], right[j+1])
            _max = max(prices[j], _max)

        res = 0
        for i in range(len(prices)):
            res = max(res, left[i]+right[i]) 
        return res

# One pass
# Time complexity: O(n)
# Space complexity: O(1)

        t1Remain, t2Remain = float('-inf'), float('-inf')
        t1Profit, t2Profit = 0, 0
        
        for price in prices:
            t1Remain = max(t1Remain, (-1)*price)
            t1Profit = max(t1Profit, price + t1Remain)
            t2Remain = max(t2Remain, t1Profit-price)
            t2Profit = max(t2Profit, price + t2Remain)
        
        return t2Profit