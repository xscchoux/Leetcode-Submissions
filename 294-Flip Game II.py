class Solution(object):
    def canWin(self, s):
        """
        :type s: str
        :rtype: bool
        """
        memo = dict()
        
        def dfs(s):
            if s in memo:
                return memo[s]
            for i in range(1, len(s)):
                if s[i-1:i+1] == "++" and not dfs(s[:i-1] + "--" + s[i+1:]):
                    memo[s] = True
                    return True
            memo[s] = False
            return False
        
        return dfs(s)