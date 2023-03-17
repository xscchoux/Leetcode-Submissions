class Solution:
    def deleteString(self, s: str) -> int:
        
# O(n^3 to n^2)
        if all(x == s[0] for x in s):
            return len(s)
               
        @cache
        def dfs(currIdx):
            length = len(s) - currIdx
            if length == 1:
                return 1
            found = False
            res = 1
            for l in range(1, length//2+1):
                if len(s) - currIdx - l + 1 <= res:
                    break
                if s[currIdx:currIdx+l] == s[currIdx+l:currIdx+2*l]:
                    found = True
                    res = max(res, 1 + dfs(currIdx+l))
            return res
                    
        res = dfs(0)
        return res

# Bottom-Up (Longest Common Prefix)
# https://leetcode.com/problems/maximum-deletions-on-a-string/discuss/2648900/JavaC%2B%2BPython-DP-Solution

        if all(x == s[0] for x in s):
            return len(s)

        N = len(s)
        lcs = [[0]*(N+1) for _ in range(N+1)]
        dp = [1]*N
        
        for i in range(N-1, -1, -1):
            for j in range(i+1, N):
                if s[i] == s[j]:
                    lcs[i][j] = lcs[i+1][j+1] + 1
                if lcs[i][j] >= j-i:
                    dp[i] = max(dp[i], dp[j]+1)
        
        return dp[0]