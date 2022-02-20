class Solution:
    def closestCost(self, baseCosts: List[int], toppingCosts: List[int], target: int) -> int:
        toppingCosts *= 2
        res = float('inf')
        
        @cache
        def dfs(idx, remain):
            if idx == len(toppingCosts) or remain < 0:
                return 0
            
            subsequentSum = min(dfs(idx+1, remain), toppingCosts[idx]+dfs(idx+1,remain-toppingCosts[idx]), key=lambda x:(abs(remain-x), x))
            return subsequentSum
        
        
        for base in baseCosts:
            res = min(res, base + dfs(0, target-base), key = lambda x: (abs(target-x), x))
            
        return res