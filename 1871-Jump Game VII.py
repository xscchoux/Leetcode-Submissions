class Solution(object):
    def canReach(self, s, minJump, maxJump):
        """
        :type s: str
        :type minJump: int
        :type maxJump: int
        :rtype: bool
        """
        if s[-1] == "1":
            return False
        
        dp = [0]*(len(s)+1)
        dp[minJump] += 1
        dp[maxJump+1] -= 1
        running = 0
        
        for i in range(1, len(s)):
            running += dp[i]
            if s[i] == "0" and running != 0:
                if i + minJump < len(dp):
                    dp[i+minJump] += 1
                if i + maxJump + 1 < len(dp):
                    dp[i+maxJump+1] -= 1
                
        return running