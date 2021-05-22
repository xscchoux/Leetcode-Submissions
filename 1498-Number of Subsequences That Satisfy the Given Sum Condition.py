class Solution(object):
    def numSubseq(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        n = len(nums)
        j = n-1
        res = 0
        kMod = 10**9 + 7
        
        
        for i in range(n):
            if 2*nums[i] > target:
                break
            while nums[i] + nums[j] > target:
                j-=1
                
            res += pow(2, j - i, kMod)
        
        return res%kMod