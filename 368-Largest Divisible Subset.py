class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
# longest increasing divisible subset
        if not nums:
            return []
        n = len(nums)
        nums.sort()
        dp = [1]*n
        pre = [-1]*n
        maxIndex = 0
        maxVal = 0
        for i in range(n):
            for j in range(i):
                if nums[i]%nums[j] == 0 and dp[j] + 1 > dp[i]:
                    dp[i] = dp[j] + 1
                    pre[i] = j
            
            if dp[i] > maxVal:
                maxVal = dp[i]
                maxIndex = i
        
        res = []
        
        for _ in range(maxVal):
            res.append(nums[maxIndex])
            maxIndex = pre[maxIndex]
        
        return res