class Solution(object):
    def singleNonDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = 0, len(nums)-1
        
        while left + 1 < right:
            mid = left + (right-left)//2
            isOdd = mid%2
            if isOdd:
                if nums[mid] == nums[mid-1]:
                    left = mid
                else:
                    right = mid
            else:
                if nums[mid] == nums[mid+1]:
                    left = mid
                else:
                    right = mid
        
        if left%2:
            return nums[right]
        else:
            return nums[left]
        