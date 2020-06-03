class Solution(object):
    def twoCitySchedCost(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """
        
        
        total = 0
        n = len(costs)//2
        
        costs.sort(key = lambda x: x[0] - x[1])
        
        for i in range(n):
            total += costs[i][0] + costs[i+n][1]
        
        return total
            