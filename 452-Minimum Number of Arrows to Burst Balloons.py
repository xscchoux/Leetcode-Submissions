class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        points.sort(key = lambda x: x[1])
        res = 0
        prevEnd = float('-inf')
        
        for start, end in points:
            if start > prevEnd:
                res += 1
                prevEnd = end
        
        return res