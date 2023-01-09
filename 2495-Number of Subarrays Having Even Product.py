class Solution:
    def evenProduct(self, nums: List[int]) -> int:
        prevEven = -1
        res = 0
        
        for i in range(len(nums)):
            if nums[i]%2 == 0:
                prevEven = i
            if prevEven != -1:
                res += prevEven+1
                
        return res
            