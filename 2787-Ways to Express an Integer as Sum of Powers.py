class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
# O(N*log_x(N))
# Top-Down DP
        kMod = 10**9 + 7
        currN = n
        while pow(currN, x) > n:
            currN -= 1
        
        @cache
        def dfs(remain, base):
            if remain == 0:
                return 1
            if base < 1:
                return 0
            
            res = 0
            curr = pow(base, x)
            if remain >= curr:
                res = (res + dfs(remain-curr, base-1))%kMod
            res = (res + dfs(remain, base-1))%kMod
            
            return res
        
        return dfs(n, currN)
            
# O(N*log_x(N))
# Bottom-Up DP
        kMod = 10**9 + 7
        currN = n
        while pow(currN, x) > n:
            currN -= 1
        
        dp = [1] + [0]*n
        
        for base in range(1, currN+1):
            item = pow(base, x)
            for i in range(n, item-1, -1):
                dp[i] = (dp[i] + dp[i-item])%kMod

        return dp[n]