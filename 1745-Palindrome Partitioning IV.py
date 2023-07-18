class Solution:
    def checkPartitioning(self, s: str) -> bool:
        
        # build DP table
        N = len(s)
        dp = [[False]*N for _ in range(N)]
        for i in range(N):
            dp[i][i] = True
        
        for l in range(2, N+1):
            for start in range(N):
                end = start + l - 1
                if end >= N:
                    break
                if s[start] == s[end] and (end == start+1 or dp[start+1][end-1]):
                    dp[start][end] = True
        
        for i in range(N-2):
            for j in range(i+1, N-1):
                if dp[0][i] and dp[i+1][j] and dp[j+1][N-1]:
                    return True
        
        return False