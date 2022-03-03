class Solution:
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> int:
        
        @cache
        def dfs(idx, state):
            if idx == len(workers):
                return 0
            
            res = float('inf')
            for i in range(len(bikes)):
                if (state >> i) & 1:
                    continue
                res = min(res, abs(workers[idx][0] - bikes[i][0]) + abs(workers[idx][1]-bikes[i][1]) + dfs(idx+1, state^(1<<i)) )
                    
            return res
        
        return dfs(0, 0)