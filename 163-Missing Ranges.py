class Solution:
    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[List[int]]:
        
        nums = [lower-1] + nums + [upper+1]
        
        prev = nums[0]
        res = []
        for i in range(1, len(nums)):
            if nums[i] - prev > 1:
                res.append([prev+1, nums[i]-1])
            prev = nums[i]
        
        return res