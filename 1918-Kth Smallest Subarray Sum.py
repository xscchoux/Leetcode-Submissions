class Solution(object):
    def kthSmallestSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        minimum = float('inf')
        total = 0
        
        for num in nums:
            minimum = min(minimum, num)
            total += num

        def count(mid):
        # two pointer
            res = 0
            tot = 0
            pointerL = 0
            for pointerR in range(len(nums)):
                tot += nums[pointerR]
                while tot > mid:
                    tot -= nums[pointerL]
                    pointerL+=1
                res += pointerR - pointerL + 1
            return res
        
        left, right = minimum, total
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if count(mid) >= k:
                right = mid
            else:
                left = mid
                     
        if count(left) >= k:
            return left
        else:
            return right