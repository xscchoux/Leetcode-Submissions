class Solution(object):
    def minCost(self, s, cost):
        """
        :type s: str
        :type cost: List[int]
        :rtype: int
        """
        last = 'A'
        res = 0
        prevLargeCost = 0
        
        for i in range(len(s)):
            if s[i] == last:
                res += min(cost[i], prevLargeCost)
                prevLargeCost = max(cost[i], prevLargeCost)
            else:
                prevLargeCost = cost[i]
            last = s[i]
        
        return res