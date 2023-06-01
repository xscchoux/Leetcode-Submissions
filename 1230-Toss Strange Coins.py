class Solution:
    def probabilityOfHeads(self, prob: List[float], target: int) -> float:
        N = len(prob)
        
        @cache
        def dfs(ind, k): # k coins are heads-up
            if ind < 0 and k == 0:
                return 1
            elif ind + 1 < k:
                return 0
            
            curr = (1-prob[ind])*dfs(ind-1, k)
            if k - 1 >= 0:
                curr += prob[ind]*dfs(ind-1, k-1)
            return curr
            
        return dfs(N-1, target)


# bottom-up
# dp[i][k] = dp[i-1][k]*(1-p) + (dp[i-1][k-1]*p if k > 0 else 0)

        N = len(prob)
        dp = [[0]*(target+1) for _ in range(N+1)]
        dp[0][0] = 1
        
        for i in range(1, N+1):
            for k in range(target+1):
                if k > i:
                    break
                dp[i][k] += (dp[i-1][k]*(1-prob[i-1]))
                if k > 0:
                    dp[i][k] += dp[i-1][k-1]*prob[i-1]
        
        return dp[-1][target]
    
# smarter bottom-up
# loop k backward because dp[i][k] only depends on the results create when index = i - 1

        N = len(prob)
        dp = [0]*(target+1)
        dp[0] = 1
        
        for i in range(N):
            for k in range(target, -1, -1):
                dp[k] = dp[k]*(1-prob[i]) + (dp[k-1] if k > 0 else 0)*prob[i]
        
        return dp[target]
