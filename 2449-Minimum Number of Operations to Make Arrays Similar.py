class Solution(object):
    def makeSimilar(self, nums, target):
        """
        :type nums: List[int]
        :type target: List[int]
        :rtype: int
        """
        nums.sort(key = lambda x:(x&1, x))
        target.sort(key = lambda x:(x&1, x))
        res = 0
        
        for i in range(len(nums)):
            res += abs(nums[i]-target[i])//2
            
        return res//2