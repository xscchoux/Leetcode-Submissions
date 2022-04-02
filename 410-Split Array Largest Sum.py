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


# Solution2:
# class Solution:
#     def splitArray(self, nums: List[int], m: int) -> int:
        
#         preSum = [0]
#         for num in nums:
#             preSum.append(preSum[-1] + num)
        
#         @cache
#         def dp(ind, m):
#             if m == 1:
#                 return preSum[ind+1]
            
#             res = preSum[-1]
#             for currLen in range(1, ind+3-m):
#                 right, left = preSum[ind+1]-preSum[ind+1-currLen], dp(ind-currLen, m-1)
#                 res = min(res, max(left, right))
#                 if right > left:
#                     break
#             return res
        
#         return dp(len(nums)-1, m)