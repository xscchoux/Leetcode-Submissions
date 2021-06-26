class Solution(object):
    def maxAlternatingSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
# dfs + memoization
        N = len(nums)
        memo = dict()
        def dp(index, isEven):
            
            if (index, isEven) in memo:
                return memo[(index, isEven)]
            
            if index == N:
                return 0
            
            curr = nums[index] if isEven else -nums[index]
            
            res = max( curr + dp(index+1, not isEven), dp(index+1, isEven) )
            memo[(index, isEven)] = res
            return res
        
        return dp(0, True)
    
    
# DP (much faster)

        maxEven, maxOdd = nums[0], 0
    
        for i in range(1, len(nums)):
            maxEven, maxOdd = max(maxEven, maxOdd + nums[i]), max(maxOdd, maxEven-nums[i])
            
        return max(maxEven, maxOdd)