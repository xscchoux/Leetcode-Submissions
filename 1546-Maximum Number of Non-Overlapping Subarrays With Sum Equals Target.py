class Solution(object):
    def maxNonOverlapping(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
# method 1
        index = dict()  # prefix sum : last index
        index[0] = -1
        
        dp = [0]*(len(nums)+1)
        
        summ = 0
        
        for i in range(len(nums)):
            summ += nums[i]
            if summ - target in index:
                dp[i+1] = max(dp[i], dp[index[summ-target] + 1] + 1)
            else:
                dp[i+1] = dp[i]
            index[summ] = i
            
        return dp[-1]
    
# method 2 (without considering index)

        dp = dict()
        dp[0] = 0
        
        summ = 0  # running sum
        res = 0
        
        for i in range(len(nums)):
            summ += nums[i]
            if summ - target in dp:
                res = max(res, dp[summ-target] + 1)
            dp[summ] = res
                
        return res