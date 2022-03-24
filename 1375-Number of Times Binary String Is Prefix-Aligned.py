class Solution(object):
    def numTimesAllBlue(self, flips):
        """
        :type flips: List[int]
        :rtype: int
        """
        rightMost = 0
        res = 0
        
        for step, index in enumerate(flips, 1):
            rightMost = max(rightMost, index)
            res += rightMost == step
        
        return res