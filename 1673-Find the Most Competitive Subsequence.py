class Solution(object):
    def mostCompetitive(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        stack = []
        
        for i in range(len(nums)):
            minStackLen = max(0, k-(len(nums)-i) )
            while len(stack) > minStackLen and nums[i] < stack[-1]:
                stack.pop()
            stack.append(nums[i])
            
        return stack[:k]