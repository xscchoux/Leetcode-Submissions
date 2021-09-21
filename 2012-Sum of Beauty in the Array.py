class Solution(object):
    def sumOfBeauties(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        N = len(nums)
        
        minFromRight = [0]*N
        minFromRight[N-1] = nums[-1]
        
        for i in range(N-2, 1, -1):
            minFromRight[i] = min(minFromRight[i+1], nums[i])
            
        maxFromLeft = [0]*N
        maxFromLeft[0] = nums[0]
        for i in range(1, N-2):
            maxFromLeft[i] = max(nums[i], maxFromLeft[i-1])
        
        res = 0
        for i in range(1, N-1):
            if nums[i] > maxFromLeft[i-1] and nums[i] < minFromRight[i+1]:
                res += 2
            elif nums[i-1]<nums[i] and nums[i]<nums[i+1]:
                res += 1
                
        return res