class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        left, right = 0, len(nums)-1
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if nums[mid] < nums[right]:   # sorted
                if nums[mid] <= target and nums[right] >= target:
                    left = mid
                else:
                    right = mid
            elif nums[mid] > nums[right]:
                if nums[left] <= target and nums[mid] >= target:
                    right = mid
                else:
                    left = mid
            else:
                while mid != right and nums[mid] == nums[right]:
                    right -= 1
                    
        if nums[left] == target:
            return True
        elif nums[right] == target:
            return True
        else:
            return False