class Solution:
    def validSubarraySplit(self, nums: List[int]) -> int:
# bottom-up
        dp = [float('inf')]*len(nums)
        dp.append(0)
        for s in range(len(nums)-1, -1, -1):
            for e in range(s, len(nums)):
                if math.gcd(nums[s], nums[e]) > 1:
                    dp[s] = min(dp[s], 1 + dp[e+1])
        
        return dp[0] if dp[0] != float('inf') else -1
    
# top-down
        @cache
        def dp(currIdx):
            if currIdx >= len(nums):
                return 0
            res = float('inf')
            for end in range(currIdx, len(nums)):
                if math.gcd(nums[currIdx], nums[end]) > 1:
                    res = min(res, 1 + dp(end+1))    
            return res
        
        return ans if (ans:=dp(0)) < float('inf') else -1