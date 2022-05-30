class Solution(object):
    def totalSteps(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        dp = [0]*n
        stack = []
        
        for i in range(n-1, -1, -1):
            while stack and nums[stack[-1]] < nums[i]:
                dp[i] = max(dp[i]+1, dp[stack.pop()])
            stack.append(i)
        
        return max(dp)