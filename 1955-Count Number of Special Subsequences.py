class Solution(object):
    def countSpecialSubsequences(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
# dp[i]: number of subsequences which end with i
        dp = [0, 0, 0]
        kMod = 10**9+7
        
        for num in nums:
            if num == 0:
                dp[0] = (2*dp[0] + 1)%kMod
            else:
                dp[num] = (dp[num-1] + 2*dp[num])%kMod
        
        return dp[2]%kMod