class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
# from solution

        if not nums:
            return -1
        
        midloc = self.findpivot(nums)
        def binarySearch(left, right):
            while left +1 < right:
                mid = left + (right-left)//2
                if nums[mid]<=target:
                    left = mid
                else:
                    right = mid
            
            if nums[right] == target:
                return right
            elif nums[left] == target:
                return left
            else:
                return -1
        
        if nums[midloc] <=target <= nums[-1]:
            return binarySearch(midloc, len(nums)-1)
        else:
            return binarySearch(0, midloc-1)
        
    def findpivot(self, nums):     # find the smallest number in the array
        left, right = 0, len(nums)-1
        while left + 1 < right:
            mid = left + (right-left)//2
            if nums[mid] < nums[right]:
                right = mid
            else:
                left = mid
        if nums[right] < nums[left]:
            return right
        return left


# another solution

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        N = len(nums)
        left, right = 0, N-1
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if nums[mid] <= nums[right]:  # RHS in ascending order
                if nums[mid] <= target <= nums[right]:
                    left = mid
                else:
                    right = mid
            else:                         # LHS in ascending order
                if nums[left] <= target <= nums[mid]:
                    right = mid
                else:
                    left = mid
        
        if nums[left] == target:
            return left
        elif nums[right] == target:
            return right
        else:
            return -1