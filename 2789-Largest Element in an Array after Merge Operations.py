class Solution:
    def maxArrayValue(self, nums: List[int]) -> int:
        N = len(nums)        
        running_tot = res = nums[-1]
        
        for i in range(N-2, -1, -1):
            if nums[i] <= running_tot:
                running_tot += nums[i]
            else:
                running_tot = nums[i]
            res = max(res, running_tot)
            
        return res
    