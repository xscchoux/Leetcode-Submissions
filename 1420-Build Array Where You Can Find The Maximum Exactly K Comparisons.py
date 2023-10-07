class Solution:
    def numOfArrays(self, n: int, m: int, k: int) -> int:
        # O(n*m*m*k)
        kMod = 10**9+7
        
        @cache
        def dfs(idx, maxSoFar, remainCost):
            if idx == n:
                if remainCost == 0:
                    return 1
                return 0

            if maxSoFar == 0:
                res = 0
            else:
                res = maxSoFar*dfs(idx+1, maxSoFar, remainCost)

            if remainCost >= 1:
                for nxt in range(maxSoFar+1, m+1):
                    res = (res + dfs(idx+1, nxt, remainCost-1))%kMod
            return res
        
        return dfs(0, 0, k)