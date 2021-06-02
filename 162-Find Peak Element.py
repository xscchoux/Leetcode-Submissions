class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = [float('-inf')] + nums + [float('-inf')]
        left, right = 1, len(nums)-2
        
        while left + 1 < right:
            mid = left + right >> 1
            if nums[mid] < nums[mid + 1]:
                left = mid
            elif nums[mid] < nums[mid-1]:
                right = mid
            else:
                return mid - 1
        
        if nums[left] < nums[right]:
            return right-1
        else:
            return left - 1