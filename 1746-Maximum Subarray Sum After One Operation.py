class Solution:
    def maxSumAfterOperation(self, nums: List[int]) -> int:
        running_flip = nums[0]*nums[0]
        running_noflip = max(nums[0], 0)
        max_flip = running_flip
        
        for i in range(1, len(nums)):
            running_flip = max(running_noflip + nums[i]*nums[i], running_flip + nums[i])
            running_noflip = max(running_noflip + nums[i], 0)
            max_flip = max(max_flip, running_flip)
            
        return max_flip