class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        p0 = 0
        p2 = len(nums)-1
        moving = 0
        
        while moving <= p2:
            if nums[moving] == 0:
                nums[moving], nums[p0] = nums[p0], nums[moving]
                p0 += 1
                moving += 1
            elif nums[moving] == 1:
                moving += 1
            else:
                nums[moving], nums[p2] = nums[p2], nums[moving]
                p2 -= 1