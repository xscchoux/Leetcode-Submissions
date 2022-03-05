class Solution(object):
    def largestSumOfAverages(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        preSum = [0]
        for i in range(len(nums)):
            preSum.append(preSum[-1] + nums[i])
        
        dp = [[float('-inf')]*(k+1) for _ in range(len(nums)+1)]
        
        dp[0][0] = 0
        
        for i in range(1, len(nums)+1):
            for part in range(1, k+1):
                for j in range(i):
                    dp[i][part] = max(dp[i][part], dp[j][part-1] + (preSum[i]-preSum[j])/float(i-j) )

        return dp[len(nums)][k]