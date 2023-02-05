class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        left, right = 1, max(nums)
        
        def count(mx):
            tot = 0
            picked = False
            for i in range(len(nums)):
                if nums[i] <= mx and not picked:
                    picked = True
                    tot += 1
                elif picked:
                    picked = False
            return tot >= k
            
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if count(mid):
                right = mid
            else:
                left = mid
        
        if count(left):
            return left
        else:
            return right