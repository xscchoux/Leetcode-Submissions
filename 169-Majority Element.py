class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = float('inf')
        count = 0
        for i in range(len(nums)):
            if res == nums[i]:
                count += 1
            elif count == 0:
                res = nums[i]
                count = 1
            else:
                count-= 1
                
        return res