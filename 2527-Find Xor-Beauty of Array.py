class Solution:
    def xorBeauty(self, nums: List[int]) -> int:
        
        res = 0
        for i in range(len(nums)):
            res = res^nums[i]
        
        return res