class Solution(object):
    def minCost(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """
        n = len(costs)
        for i in range(1, n):
            for j in range(3):
                costs[i][j] += min(costs[i-1][(j-1)%3], costs[i-1][(j+1)%3])
        
        return min(costs[-1])