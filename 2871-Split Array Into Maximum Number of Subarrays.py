class Solution:
    def maxSubarrays(self, nums: List[int]) -> int:
        # If the score of the entire array is not zero, return 1
        # Else we count subarrays with the zero score.
        
        curr = 2**20 - 1
        for i in range(len(nums)):
            curr = curr & nums[i]
        
        if curr != 0:
            return 1
        
        res = 0
        curr = 2**20 - 1
        
        for i in range(len(nums)):
            curr = curr & nums[i]
            if curr == 0:
                res += 1
                curr = 2**20 - 1
        
        return res