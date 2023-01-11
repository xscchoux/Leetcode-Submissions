class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        
        left, right = 1, max(nums)
        k = maxOperations
        
        def achieve(target):
            limit = k
            for num in nums:
                if num > target:
                    limit -= (num+target-1)//target-1
                    if limit < 0:
                        return False
            return True
        
        while left + 1 < right:
            mid = left + (right - left)//2
            if achieve(mid):
                right = mid
            else:
                left = mid
                
        if achieve(right):
            return right
        else:
            return left