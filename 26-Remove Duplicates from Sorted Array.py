class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        
        j = 0 
        for i in range(len(nums)-1):
            if nums[i] < nums[i+1]:
                nums[j] = nums[i]
                j+=1
        nums[j] = nums[-1]
        
        return j+1