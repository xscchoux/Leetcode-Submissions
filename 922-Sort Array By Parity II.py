class Solution(object):
    def sortArrayByParityII(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        oddIdx = 1
        
        for i in range(0, len(nums), 2):
            if nums[i]%2:
                while nums[oddIdx]%2:
                    oddIdx += 2
                nums[i], nums[oddIdx] = nums[oddIdx], nums[i]
        
        return nums