class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
# https://www.youtube.com/watch?v=uAGt1QoAoMU
# if nums[i] == 0, sum = sum-1, sum_dict[sum] = i, else sum = sum+1, sum_dict[sum] = i

# time complexity: O(n)
        
        res = 0
        hmap = {0: -1}
        _sum = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                _sum -= 1
            else:
                _sum += 1
            
            if _sum in hmap:
                res = max(res, i-hmap[_sum])
            else:
                hmap[_sum] = i
        
        return res
        