class Solution(object):
    def longestPalindromeSubseq(self, s):
        """
        :type s: str
        :rtype: int
        """
# Time: O(n^2)
# Space: O(n^2)
        res = 0
        memo = {}
        n = len(s)
        
        def dp(i, j):
            if (i, j) in memo:
                return memo[(i,j)]
            res = 0
            for start in range(i+1, j):
                for end in range(j-1, start, -1):
                    if s[start] == s[end] and s[i] != s[start]:
                        res = max(res, 2 + dp(start, end))
                        break
            memo[(i, j)] = res
            return res
        
        for start in range(n-1):
            for end in range(n-1, start, -1):
                if s[start] == s[end]:
                    res = max(res, 2 + dp(start, end))
                    break
        return res