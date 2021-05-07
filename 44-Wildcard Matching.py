class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
# DP, Time: O(SP), Space: O(SP) 
# if s[i-1] == p[j-1] or p[j-1] == "?" :   dp[i][j] = dp[i-1][j-1]
# elif p[j-1] == '*':   dp[i][j] = dp[i-1][j] (add a new word) or dp[i][j-1] (when '*' is not used)

        dp = [[False]*(len(p)+1) for _ in range(len(s)+1)]
        dp[0][0] = True
        for i in range(1, len(p)+1):
            if p[i-1] == '*':
                dp[0][i] = dp[0][i-1]
        
        for i in range(1, len(s)+1):
            for j in range(1, len(p)+1):
                if p[j-1] == '*':
                    dp[i][j] = dp[i-1][j] or dp[i][j-1]
                else:
                    dp[i][j] = (s[i-1] == p[j-1] or p[j-1] == '?') and dp[i-1][j-1]
        return dp[-1][-1]
    
# DP, Time: O(SP), Space: O(P) (rolling array)
# if s[i-1] == p[j-1] or p[j-1] == "?" :   dp[i][j] = dp[i-1][j-1]
# elif p[j-1] == '*':   dp[i][j] = dp[i-1][j] (add a new word) or dp[i][j-1] (when '*' is not used)

        dp = [[False]*(len(p)+1) for _ in range(2)]    
        dp[0][0] = True
        for i in range(1, len(p)+1):
            if p[i-1] == '*':
                dp[0][i] = dp[0][i-1]
        
        for i in range(1, len(s)+1):
            for j in range(0, len(p)+1):
                if j == 0:
                    dp[i%2][j] = False
                    continue
                if s[i-1] == p[j-1] or p[j-1] == '?':
                    dp[i%2][j] = dp[(i-1)%2][j-1]
                elif p[j-1] == '*':
                    dp[i%2][j] = dp[(i-1)%2][j] or dp[i%2][j-1]
                else:
                    dp[i%2][j] = False
        return dp[len(s)%2][-1]


# fastest way (backtracking)


        star = -1
        i = j = 0
        while i < len(s):
            if j >= len(p) or (p[j] not in ('?','*') and s[i] != p[j]):
                if star == -1:
                    return False
                j = star + 1
                i = istar + 1
                istar+=1
            elif p[j] == '*':
                star = j
                istar = i
                j = star + 1
            else:
                i += 1
                j += 1
        
        while j < len(p):
            if p[j] != '*':
                return False
            j += 1
        
        return True
                
            
    

        