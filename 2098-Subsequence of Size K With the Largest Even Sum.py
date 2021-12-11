class Solution(object):
    def largestEvenSum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort(reverse = True)
        lastOdd = lastEven = oddCand = evenCand = -1
        
        tot = 0
        
        for i in range(k):
            if nums[i] % 2:
                lastOdd = i
            else:
                lastEven = i
            tot += nums[i]

        if tot%2 == 0:
            return tot
        
        for i in range(len(nums)-1, k-1, -1):
            if nums[i] % 2:
                oddCand = i
            else:
                evenCand = i

        res = -1
        if lastEven != -1 and oddCand != -1:
            res = max(res, tot - nums[lastEven] + nums[oddCand])
        if lastOdd != -1 and evenCand != -1:
            res = max(res, tot - nums[lastOdd] + nums[evenCand])
        
        return res