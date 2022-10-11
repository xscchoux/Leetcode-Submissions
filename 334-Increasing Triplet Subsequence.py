class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        m1, m2 = float('inf'), float('inf')
        
        for n in nums:
            if n <= m1:
                m1 = n
            elif n <= m2:
                m2 = n
            else:
                return True
        return False