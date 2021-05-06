class Solution(object):
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) == 1:
            return True
        
        count = 0
        
        for i in range(1, len(nums)):
            if nums[i] < nums[i-1]:
                count += 1
                if count >= 2:
                    return False
                if i >= 2 and nums[i] < nums[i-2]:
                    nums[i] = nums[i-1]
                elif i >= 2 and nums[i] >= nums[i-2]:
                    nums[i-1] = nums[i]
                else:
                    nums[i-1] = nums[i]
            
        return True