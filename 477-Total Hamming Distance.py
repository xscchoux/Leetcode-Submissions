class Solution(object):
    def totalHammingDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ones = [0]*32
        for num in nums:
            ind = 0
            while num > 0:
                if num & 1:
                    ones[ind] += 1
                num = num >> 1
                ind += 1
                
        res = 0
        for k in ones:
            res += (len(nums)-k)*k
            
        return res