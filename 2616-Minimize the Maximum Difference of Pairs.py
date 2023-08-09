class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        nums.sort()
        
        def isOK(target):
            count = 0
            i = count = 0
            while i < len(nums):
                if i > 0 and nums[i] - nums[i-1] <= target:
                    i += 1
                    count += 1
                i += 1
                    
            if count >= p:
                return True
            return False
        
        left, right = 0, nums[-1] - nums[0]
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if isOK(mid):
                right = mid
            else:
                left = mid
        
        if isOK(left):
            return left
        return right