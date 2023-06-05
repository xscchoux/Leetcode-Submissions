class Solution:
    def count(self, num1: str, num2: str, min_sum: int, max_sum: int) -> int:
        
        # dfs(s, d) = dfs(s[1:], d + int(s[0])) + (all combinations that pick previous number smaller than int(s[0]))
        
        kMod = 10**9+7
        @cache
        def dfs2(left, d):
            if d > max_sum:
                return 0
            if left == 0:
                if min_sum <= d <= max_sum:
                    return 1
                return 0
            tot = 0
            for c in range(10):
                tot = (tot + dfs2(left-1, d+c))%kMod
            
            return tot
        
        
        @cache
        def dfs(s, d):  # remaining string (prefix is fixed), digit sum so far
            if not s:
                if min_sum <= d <= max_sum:
                    return 1
                return 0
            
            N = len(s)
            curr = int(s[0])
            res = 0
            for c in range(curr):
                res = (res + dfs2(N-1, d+c))%kMod
            if d + curr <= max_sum:
                res = (res + dfs(s[1:], d + curr))%kMod
            
            return res
        
        return (dfs(num2, 0) - dfs(str(int(num1) - 1), 0))%kMod