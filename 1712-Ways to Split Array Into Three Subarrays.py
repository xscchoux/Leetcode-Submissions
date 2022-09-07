class Solution(object):
    def waysToSplit(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        preSum = [nums[0]]
        for i in range(1, len(nums)):
            preSum.append(preSum[-1] + nums[i])
            
        kMod = 1000000007
        j = k = 0
        res = 0
        N = len(nums)
        
        for i in range(N-2):
            j = max(i+1, j)
            while j < N-1 and preSum[j] < 2*preSum[i]:
                j += 1
            k = max(k, j)
            while k < N-1 and preSum[-1] - preSum[k] >= preSum[k] - preSum[i]:
                k += 1
            res = (res + k-j)%kMod
        
        return res%kMod