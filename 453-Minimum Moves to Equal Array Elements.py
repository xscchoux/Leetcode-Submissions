class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
# Incrementing n-1 elements is equivalent to incrementing all n elements and decrementing 1 element
        
        return sum(nums) - min(nums)*len(nums)