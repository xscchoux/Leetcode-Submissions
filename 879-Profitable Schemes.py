class Solution:
    def profitableSchemes(self, n: int, minProfit: int, group: List[int], profit: List[int]) -> int:
        
        @cache
        def dfs(idx, totP, people):
            if idx == len(group):
                if totP == minProfit:
                    return 1
                return 0
            
            skip = dfs(idx+1, totP, people)
            
            keep = 0
            if people + group[idx] <= n:
                keep = dfs(idx+1, min(minProfit, totP+profit[idx]), people+group[idx])
                
            return (skip + keep)%(10**9+7)
        
        return dfs(0, 0, 0)