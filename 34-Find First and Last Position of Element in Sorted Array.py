class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
# https://blog.csdn.net/fuxuemingzhu/article/details/83273084
        # left = bisect.bisect_left(nums, target)
        # right = bisect.bisect_right(nums, target)
        # if left == right:
        #     return [-1,-1]
        # else:
        #     return [left, right-1]
        
        if not nums:
            return [-1,-1]
        
        def bs1(left, right, target):
            while left + 1 < right:
                mid = left + (right-left)//2
                if nums[mid] < target:
                    left = mid
                else:
                    right = mid
            if nums[left] == target:
                return left
            elif nums[right] == target:
                return right
            else:
                return -1
        
        def bs2(left, right, target):
            while left + 1 < right:
                mid = left + (right-left)//2
                if nums[mid] <= target:
                    left = mid
                else:
                    right = mid
            if nums[right] == target:
                return right
            elif nums[left] == target:
                return left
            else:
                return -1
        
        first = bs1(0, len(nums)-1, target)
        second = bs2(0, len(nums)-1, target)
        
        return [first, second]