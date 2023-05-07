class Solution:
    def minIncrements(self, n: int, cost: List[int]) -> int:
        
# bottom up
        n = len(cost)
        diff = 0
        
        for i in range(n//2-1, -1, -1):
            left = 2*i + 1
            right = 2*i + 2
            cost[i] += max(cost[left], cost[right])
            diff += abs(cost[left]-cost[right])

        return diff
    
# DFS
        n = len(cost)
        self.diff = 0
        
        def dfs(ind):
            if ind*2 > n:
                return cost[ind-1]
            
            left = dfs(2*ind)
            right = dfs(2*ind+1)
            self.diff += abs(left-right)
            return cost[ind-1] + max(left, right)
        
        dfs(1)
        
        return self.diff