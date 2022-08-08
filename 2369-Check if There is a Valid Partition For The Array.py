class Solution(object):
    def validPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        dp = [False]*(len(nums)+1)
        dp[0] = True
        
        for i in range(len(nums)):
            if i >= 1 and nums[i] == nums[i-1]:
                dp[i+1] |= dp[i-1]
            if i >= 2 and (nums[i] == nums[i-1] and nums[i-1] == nums[i-2]):
                dp[i+1] |= dp[i-2]
            if i >= 2 and (nums[i] == nums[i-1]+1 and nums[i-1] == nums[i-2]+1):
                dp[i+1] |= dp[i-2]
        
        return dp[-1]