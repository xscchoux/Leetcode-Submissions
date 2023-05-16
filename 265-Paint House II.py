class Solution(object):
    def minCostII(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """

# O(n*colors)
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

# O(n*colors), optimized space

# optimized space
        N = len(costs)
        colors = len(costs[0])
        
        prevMinIdx = -1
        prevFirstMin = prevSecondMin = float('inf')
        
        for color in range(colors):
            if costs[0][color] < prevFirstMin:
                prevSecondMin = prevFirstMin
                prevFirstMin = costs[0][color]
                prevMinIdx = color
            elif costs[0][color] < prevSecondMin:
                prevSecondMin = costs[0][color]
        
        for i in range(1, N):
            firstMin = secondMin = float('inf')
            minIdx = -1
            
            for color in range(colors):
                cost = costs[i][color]
                if color == prevMinIdx:
                    cost += prevSecondMin
                else:
                    cost += prevFirstMin
                
                if cost < firstMin:
                    minIdx = color
                    secondMin = firstMin
                    firstMin = cost
                    
                elif cost < secondMin:
                    secondMin = cost
            
            prevMinIdx = minIdx
            prevFirstMin = firstMin
            prevSecondMin = secondMin
        
        return prevFirstMin