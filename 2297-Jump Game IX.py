class Solution(object):
    def minCost(self, nums, costs):
        """
        :type nums: List[int]
        :type costs: List[int]
        :rtype: int
        """
        n = len(nums)
        nextMin, nextMax = [n]*n, [n]*n
        stackNextMin, stackNextMax = [], []
        
        for i in range(len(nums)):
            while stackNextMin and nums[stackNextMin[-1]] > nums[i]:
                nextMin[stackNextMin.pop()] = i
            while stackNextMax and nums[stackNextMax[-1]] <= nums[i]:
                nextMax[stackNextMax.pop()] = i
            
            stackNextMin.append(i)
            stackNextMax.append(i)
        
        dp = [float('inf')]*n
        dp[0] = 0
        
        for i in range(len(nums)):
            for nxt in (nextMin[i], nextMax[i]):
                if nxt < n:
                    dp[nxt] = min(dp[nxt], dp[i] + costs[nxt])
        
        return dp[-1]