class Solution:
    def goodBinaryStrings(self, minLength: int, maxLength: int, oneGroup: int, zeroGroup: int) -> int:
        kMod = 10**9 + 7
        dp = [0]*(maxLength+1)
        dp[0] = 1
        res = 0
        
        for i in range(1, len(dp)):
            if i >= oneGroup:
                dp[i] = (dp[i] + dp[i-oneGroup])%kMod
            if i >= zeroGroup:
                dp[i] = (dp[i] + dp[i-zeroGroup])%kMod
            if minLength <= i <= maxLength:
                res = (res + dp[i])%kMod
        
        return res