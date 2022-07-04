class Solution(object):
    def maxSumTwoNoOverlap(self, nums, firstLen, secondLen):
        """
        :type nums: List[int]
        :type firstLen: int
        :type secondLen: int
        :rtype: int
        """
        for i in range(1, len(nums)):
            nums[i] = nums[i-1] + nums[i]
        
        maxFirst = nums[firstLen-1]
        maxSecond = nums[secondLen-1]
        res = 0
        
        # first | second
        for i in range(firstLen+secondLen-1, len(nums)):
            maxFirst = max(maxFirst, nums[i-secondLen] - nums[i-secondLen-firstLen])
            res = max(res, maxFirst + nums[i] - nums[i-secondLen])
        
        # second | first
        for i in range(firstLen+secondLen-1, len(nums)):
            maxSecond = max(maxSecond, nums[i-firstLen] - nums[i-secondLen-firstLen])
            res = max(res, maxSecond + nums[i] - nums[i-firstLen])
            
        return res