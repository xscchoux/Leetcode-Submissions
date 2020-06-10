class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        left, right = 0, len(nums)-1
        
        while left+1 < right:
            mid = left + (right-left)//2
            if nums[mid] < target:
                left = mid
            else:
                right = mid
        if nums[left] >= target:
            return left
        if nums[right] >= target:
            return right
        return len(nums)