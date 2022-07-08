class Solution:
    def minCost(self, houses: List[int], cost: List[List[int]], m: int, n: int, target: int) -> int:
        
        @cache
        def dfs(ind, prev, chunk):
            if chunk > target or chunk + (m-ind) < target:
                return float('inf')
            if ind == m:
                if chunk == target:
                    return 0
                else:
                    return float('inf')
            
            res = float('inf')
            if houses[ind] == 0:
                for nxt in range(1, n+1):
                    res = min(res, cost[ind][nxt-1] + dfs(ind+1, nxt, chunk+(prev!=nxt) ) )
            else:
                res = min(res, dfs(ind+1, houses[ind], chunk + (prev != houses[ind]) ))
                
            return res
        
        ans = dfs(0, -1, 0)
        
        return ans if ans < float('inf') else -1 