class Solution:
    def waysToReachTarget(self, target: int, types: List[List[int]]) -> int:

# top-down DP
        kMod = 1000000007
        N = len(types)
        
        @cache
        def dfs(remain, ind):
            if ind == N:
                if remain == 0:
                    return 1
                else:
                    return 0
            
            res = 0
            for k in range(types[ind][0]+1):
                if remain - k*types[ind][1] < 0:
                    break
                res += dfs(remain-k*types[ind][1], ind+1)
                res %= kMod
            
            return res        
        
        return dfs(target, 0)

    
# bottom-up DP
        kMod = 1000000007
        N = len(types)

        # dp[i][j] : the number of ways to earn exactly j points using the first i types
        dp = [[0]*(target+1) for _ in range(N+1)]
        dp[0][0] = 1

        for i in range(1, N+1):
            count, mark = types[i-1]
            for t in range(target+1):
                for c in range(count+1):
                    if t - c*mark < 0:
                        break
                    dp[i][t] = (dp[i][t] + dp[i-1][t-c*mark])%kMod
        
        return dp[N][t]