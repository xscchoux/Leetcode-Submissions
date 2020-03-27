# DFS + memoization
        wordSet = set(wordDict)
        n = len(s)
        memo = {}
        
        def dfs(start):
            if start == n:
                return True
            
            if start in memo:
                return memo[start]
            
            for i in range(start,n):
                if s[start:i+1] in wordSet:
                    if dfs(i+1):
                        memo[start] = True
                        return True
                    
            memo[start] = False
            return False
        return dfs(0)
    
# DP
        n = len(s)
        dp = [False]*(n+1)
        dp[0] = True
        wordSet = set(wordDict)
        for i in range(n):
            for word in wordSet:
                if word == s[i:i+len(word)] and dp[i] is True:
                    dp[i+len(word)] = True
        return dp[-1]