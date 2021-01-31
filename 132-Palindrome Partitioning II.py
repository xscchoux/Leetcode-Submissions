class Solution(object):
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        isPalindrome = [[False]*n for _ in range(n)]
        dp = [i for i in range(n)]

        for end in range(n):
            for start in range(end+1):
                if s[start] == s[end] and (end-start <=1 or isPalindrome[start+1][end-1]):
                    isPalindrome[start][end] = True
                    if start == 0:
                        dp[end] = 0
                        continue
                    dp[end] = min(dp[end], dp[start-1]+1)
        
        return dp[n-1]