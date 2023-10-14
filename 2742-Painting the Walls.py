class Solution:
    def paintWalls(self, cost: List[int], time: List[int]) -> int:
        # if cost[i] == a, time[i] = b, can paint 1 + b walls with cost a
        # variation of knapsack
        
        N = len(cost)
            
        @cache
        def dfs(currIdx, remain):
            if remain <= 0:
                return 0
            
            if currIdx == N:
                return float('inf')
            
            # Did not pick current painter
            costAfter = dfs(currIdx+1, remain)
            # Pick
            costAfter = min(costAfter, cost[currIdx] + dfs(currIdx+1, remain - 1 - time[currIdx]))
            
            return costAfter
        
        return dfs(0, N)