class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = 0, len(nums)-1
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if nums[mid] > nums[right]:
                left = mid
            elif nums[mid] < nums[right]:
                right = mid
            else:
                right -= 1
        return min(nums[left], nums[right])