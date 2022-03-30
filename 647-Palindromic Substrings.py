class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        N = len(s)
        dp = [[False]*(N+1) for _ in range(N+1)]
        
        for i in range(N):
            dp[i][i] = True
        
        res = N
        
        for L in range(2, N+1):
            for start in range(0, N):
                end = start + L-1
                if end >= N: break
                if s[start] == s[end]:
                    if start + 1 == end or dp[start+1][end-1]:
                        res += 1
                        dp[start][end] = True
        return res