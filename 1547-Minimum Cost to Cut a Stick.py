class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:

# Cannot greedily pick the shortest span, for example
# n = 36
# cuts = [13,22,27] -> span = [13, 9, 5, 9]
# pick [9, 5] and pick [5, 9] first will give different results

# DFS + memoization
        cuts = [0] + sorted(cuts) + [n]
        
        @cache
        def dfs(start, end):
            if start + 1 >= end:
                return 0
            
            mn = float('inf')
            for i in range(start+1, end):
                mn = min(mn, dfs(start, i) + dfs(i, end) + cuts[end] - cuts[start])  
            return mn
        
        return dfs(0, len(cuts)-1)
    
# bottom-up DP
        cuts = [0] + sorted(cuts) + [n]
        N = len(cuts)
        dp = [[0]*N for _ in range(N)]
        
        for idxDiff in range(2, N):
            for start in range(N-1):
                end = start + idxDiff
                if end > N-1:
                    break
                dp[start][end] = float('inf')
                for k in range(start+1, end):
                    dp[start][end] = min(dp[start][end], dp[start][k] + dp[k][end] + cuts[end] - cuts[start])
        
        return dp[0][N-1]