class Solution(object):
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        dup = missing = -1
        
        for num in nums:
            if nums[abs(num)-1] < 0:
                dup = abs(num)
            else:
                nums[abs(num)-1] *= -1
        
        for i in range(len(nums)):
            if nums[i] > 0:
                missing = i+1
                break
        
        return [dup, missing]