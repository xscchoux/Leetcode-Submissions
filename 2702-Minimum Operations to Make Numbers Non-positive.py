import math
class Solution:
    def minOperations(self, nums: List[int], x: int, y: int) -> int:
        delta = x - y
        
        def isOK(step):
            remain = step
            for num in nums:
                required = num - y*step
                if required <= 0:
                    continue
                elif required <= remain*delta:
                    remain -= math.ceil(required/delta)
                else:
                    return False
            return True

        left, right = 0, max(nums)//y + 1

        while left + 1 < right:
            mid = left + (right-left)//2
            if isOK(mid):
                right = mid
            else:
                left = mid

        if isOK(left):
            return left
        else:
            return right