class Solution:
    def isValidPalindrome(self, s: str, k: int) -> bool:

# top-down 
        @cache
        def dfs(i, j):
            if i == j:
                return 0
            if i == j+1:
                return 0
            
            if s[i] == s[j]:
                return dfs(i+1, j-1)
            else:
                return 1 + min(dfs(i+1, j), dfs(i, j-1))
        
        return dfs(0, len(s)-1) <= k

# bottom-up
        N = len(s)
        dp = [[0]*N for _ in range(N)]
    
        for i in range(N):
            for j in range(i-1, -1, -1):
                if s[i] == s[j]:
                    dp[i][j] = dp[i-1][j+1]
                else:
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j+1])
        return dp[N-1][0] <= k