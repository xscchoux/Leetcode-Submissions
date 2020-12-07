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
            else:
                right = mid
                
        return min(nums[left], nums[right])


class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def DivideAndConquer(left, right):
            if left >= right:
                return nums[left]
            if nums[left] < nums[right]:
                return nums[left]
            else:
                mid = left + (right-left)//2
                return min(DivideAndConquer(left, mid), DivideAndConquer(mid+1, right))
        
        return DivideAndConquer(0, len(nums)-1)