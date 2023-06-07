class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        
# DP, O(N*M)
        l1, l2 = len(s1), len(s2)
        dp = [[0]*(l2+1) for _ in range(l1+1)]
        
        for i in range(1, l1+1):
            dp[i][0] = dp[i-1][0] + ord(s1[i-1])

        for j in range(1, l2+1):
            dp[0][j] = dp[0][j-1] + ord(s2[j-1])
        
        for i in range(1, 1+l1):
            for j in range(1, 1+l2):
                if s1[i-1] == s2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j] + ord(s1[i-1]), dp[i][j-1] + ord(s2[j-1]))

        return dp[-1][-1]
    
# Top down DP

        l1, l2 = len(s1), len(s2)
        dp1, dp2 = [0]*(l1+1), [0]*(l2+1)
        
        for i in range(1, l1+1):
            dp1[i] = dp1[i-1]+ ord(s1[i-1])

        for j in range(1, l2+1):
            dp2[j] = dp2[j-1] + ord(s2[j-1])
            
        @cache
        def dfs(idx1, idx2):
            if idx1 < 0 and idx2 < 0:
                return 0
            elif idx1 < 0:
                return dp2[idx2+1]
            elif idx2 < 0:
                return dp1[idx1+1]
            if s1[idx1] == s2[idx2]:
                return dfs(idx1-1, idx2-1)
            else:
                return min(dfs(idx1-1, idx2) + ord(s1[idx1]), dfs(idx1, idx2-1) + ord(s2[idx2]))

        return dfs(l1-1, l2-1)