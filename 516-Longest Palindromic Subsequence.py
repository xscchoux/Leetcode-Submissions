class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        
# recursive
        @cache
        def dfs(left, right):
            if right == left:
                return 1
            if right < left:
                return 0
            
            if s[left] == s[right]:
                return 2 + dfs(left+1, right-1)
            else:
                return max(dfs(left+1, right), dfs(left, right-1))
            
        return dfs(0, len(s)-1)
    
# DP
        N = len(s)
        dp = [[0]*N for _ in range(N)]
        
        for i in range(N-1, -1, -1):
            dp[i][i] = 1
            for j in range(i+1, N):
                if s[i] == s[j]:
                    dp[i][j] = 2 + dp[i+1][j-1]
                else:
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1])
        
        return dp[0][N-1]