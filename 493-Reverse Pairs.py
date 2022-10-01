from sortedcontainers import SortedList
class Solution(object):
    def reversePairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sl = SortedList()
        res = 0
        
        for i in range(len(nums)):
            curr = nums[i]*2
            idx = sl.bisect_right(curr)
            res += len(sl) - idx
            sl.add(nums[i])
        
        return res