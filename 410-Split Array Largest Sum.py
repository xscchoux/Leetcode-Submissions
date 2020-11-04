class Solution(object):
    def splitArray(self, nums, m):
        """
        :type nums: List[int]
        :type m: int
        :rtype: int
        """
        _max = 0
        _sum = 0
        for i in range(len(nums)):
            _max = max(nums[i], _max)
            _sum += nums[i]
        
        # edge cases, not nessasary
        # if m==1:
        #     return _sum
        # if m >= len(nums):
        #     return _max
        
        def getCounts(maxValue):
            count = 1
            summ = nums[0]
            for i in range(1, len(nums)):
                if summ + nums[i] > maxValue:
                    count += 1
                    summ = nums[i]
                else:
                    summ += nums[i]
            return count
        
        left, right = _max, _sum
        
        while left +1 < right:
            mid = left + (right-left)//2
            if getCounts(mid) > m:
                left = mid
            else:
                right = mid
        
        if getCounts(left) <= m:
            return left
        else:
            return right