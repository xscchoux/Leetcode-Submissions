class Solution(object):
    def minInsertions(self, s):
        """
        :type s: str
        :rtype: int
        """
        
# DFS + memoization
        memo = dict()
        
        def dp(l, r):
            if l >= r:
                return 0
            if (l, r) in memo:
                return memo[(l,r)]
            
            if s[l] == s[r]:
                memo[(l, r)] = dp(l+1, r-1)
            else:
                memo[(l, r)] = min(dp(l, r-1), dp(l+1,r)) + 1
            return memo[(l, r)]
        
        return dp(0, len(s)-1)
    
# DP
        if len(s) <= 1:
            return 0
        dp = [[0]*len(s) for _ in range(len(s))]
        for l in range(2, len(s)+1):
            for i in range(len(s)):
                j = i+l-1
                if j >= len(s):
                    break
                    
                if s[i] == s[j]:
                    dp[i][j] = dp[i+1][j-1]
                else:
                    dp[i][j] = min(dp[i][j-1], dp[i+1][j]) + 1
        return dp[0][len(s)-1]




# more solutions...

class Solution:
    def minInsertions(self, s: str) -> int:
# Top-Down DP        
        @cache
        def dfs(left, right):
            if left == right:
                return 1
            if left > right:
                return 0
            
            if s[left] == s[right]:
                return 2 + dfs(left+1, right-1)
            else:
                return max(dfs(left+1, right), dfs(left, right-1))
        
        return len(s) - dfs(0, len(s)-1)
        
        
# Bottom-Up DP
        N = len(s)
        dp = [[0]*N for _ in range(N)]
        for i in range(N):
            dp[i][i] = 1
        
        for i in range(N-1, -1, -1):
            for j in range(i+1, N):
                if s[i] == s[j]:
                    dp[i][j] = 2 + dp[i+1][j-1]
                else:
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1])
        
        return N - dp[0][len(s)-1]


# Bottom-Up DP with reduced space complexity, very hard to come up with
        N = len(s)
        dp = [1]*N
        
        for i in range(N-1, -1, -1):
            pre = 0
            for j in range(i+1, N):
                tmp = dp[j]  # store dp[i+1][j-1] in tmp
                if s[i] == s[j]:
                    dp[j] = 2 + pre
                else:
                    dp[j] = max(dp[j], dp[j-1])
                pre = tmp

        return N - dp[-1]