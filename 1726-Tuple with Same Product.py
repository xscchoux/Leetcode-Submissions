class Solution(object):
    def tupleSameProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        hmap = collections.defaultdict(int)
        for i in range(len(nums)):
            for j in range(i):
                hmap[nums[i]*nums[j]] += 1
        for key, val in hmap.items():
            if val > 1:
                res += 8*val*(val-1)//2
        
        return res