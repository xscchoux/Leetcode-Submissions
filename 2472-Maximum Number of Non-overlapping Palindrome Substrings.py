class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        
# dynamic programming (slow)
        n = len(s)
        dp = [[False]*n for _ in range(n)]
        
        for i in range(n):
            dp[i][i] = True
        
        for l in range(2, len(s)+1):
            for start in range(len(s)-l+1):
                end = start + l - 1
                if s[start] == s[end]:
                    if start+1 > end-1:
                        dp[start][end] = True
                    else:
                        dp[start][end] = dp[start+1][end-1]
        res = 0
        ind = 0
        while ind < len(s):
            if ind+k-1<len(s) and dp[ind][ind+k-1]:
                res += 1
                ind = ind+k
            elif ind+k<len(s) and dp[ind][ind+k]:
                res += 1
                ind = ind+k+1
            else:
                ind += 1
                continue
        return res

# top down (much faster)
        @cache
        def isPalindrome(i, j):
            while i < j:
                if s[i] != s[j]:
                    return False
                i += 1
                j -= 1
            return True
        
        @cache
        def dfs(ind):
            if ind + k - 1 >= len(s):
                return 0
            
            m = dfs(ind+1)
            if ind+k-1 < len(s) and isPalindrome(ind, ind+k-1):
                m = max(m, 1 + dfs(ind+k))
            if ind+k < len(s) and isPalindrome(ind, ind+k):
                m = max(m, 1 + dfs(ind+k+1))
            return m
            
        return dfs(0)