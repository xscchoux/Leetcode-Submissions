class Solution(object):
    def minimumMoney(self, transactions):
        """
        :type transactions: List[List[int]]
        :rtype: int
        """
# https://www.youtube.com/watch?v=UJ3XKhe0_8M
        
        transactions.sort(key = lambda x:x[1])
        curr = 0
        lowest = 0
        
        mxCost = 0
        
        for cost, cashback in transactions:
            if cost > cashback:
                curr -= cost
                lowest = min(lowest, curr)
                curr += cashback
            else:
                mxCost = max(cost, mxCost)
        
        lowest = min(lowest, curr-mxCost)
        
        return -1*lowest