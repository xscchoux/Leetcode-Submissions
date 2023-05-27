class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        
# bottom-up
        N = len(s)
        dp = [0] * (N+1)
        dictionary = set(dictionary)
        
        for i in range(N):
            for j in range(i+1):
                if s[j:i+1] in dictionary:
                    dp[i+1] = max(dp[i+1], dp[j] + (i - j + 1))
                dp[i+1] = max(dp[i+1], dp[i])
        
        return len(s) - dp[-1]
    
# top-down
        dictionary = set(dictionary)
        N = len(s)
        
        @cache
        def dfs(ind):
            if ind < 0:
                return 0
            res = dfs(ind-1)
            for j in range(ind+1):
                if s[j:ind+1] in dictionary:
                    res = max(res, dfs(j-1) + (ind-j+1))
            return res
        
        return len(s) - dfs(N-1)