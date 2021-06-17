class Solution(object):
    def maxSumDivThree(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = [0]*3
        
        for num in nums:
            prev_dp = dp[:]
            for i in range(len(dp)):
                dp[(prev_dp[i]+num)%3] = max(prev_dp[i]+num, dp[(prev_dp[i]+num)%3])
            
        return dp[0]