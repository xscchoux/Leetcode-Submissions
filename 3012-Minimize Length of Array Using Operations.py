class Solution:
    def minimumArrayLength(self, nums: List[int]) -> int:
        mn = min(nums)
        for i in range(len(nums)):
            if nums[i]%mn != 0:  # can create a number smaller than current minimum
                return 1
        
        return ceil(nums.count(mn)/2)