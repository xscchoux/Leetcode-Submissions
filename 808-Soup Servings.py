class Solution:
    def soupServings(self, n: int) -> float:

        @cache
        def dfs(a, b):
            if a <= 0 and b <= 0:
                return 0.5
            elif a > 0 and b <= 0:
                return 0
            elif a <= 0 and b > 0:
                return 1
            else:
                res = 0.25*(dfs(a-4, b) + dfs(a-3, b-1) + dfs(a-2, b-2) + dfs(a-1, b-3))
                if res > 1 - 1e-5:
                    return 1
                return res
        
        for i in range(1, ceil(n/25) + 1):
            if dfs(i, i) > 1 - 1e-5:
                return 1
        
        return dfs(ceil(n/25), ceil(n/25))