class Solution(object):
    def minCostII(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """
        n = len(costs)
        colors = len(costs[0])
        
        if colors == 1 and n > 1:
            return 2147483647
        
        for house in range(1, n):
            min1Color, min2Color = -1, -1
            for k in range(colors):
                if min1Color == -1 or costs[house-1][k] < costs[house-1][min1Color]:
                    min2Color = min1Color
                    min1Color = k
                elif min2Color == -1 or costs[house-1][k] < costs[house-1][min2Color]:
                    min2Color = k
                    
            for k in range(colors):
                if k == min1Color:
                    costs[house][k] += costs[house-1][min2Color]
                else:
                    costs[house][k] += costs[house-1][min1Color]
        
        return min(costs[-1])