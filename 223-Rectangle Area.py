class Solution(object):
    def computeArea(self, ax1, ay1, ax2, ay2, bx1, by1, bx2, by2):
        """
        :type ax1: int
        :type ay1: int
        :type ax2: int
        :type ay2: int
        :type bx1: int
        :type by1: int
        :type bx2: int
        :type by2: int
        :rtype: int
        """
        area1 = (ay2-ay1)*(ax2-ax1)
        area2 = (by2-by1)*(bx2-bx1)
        
        overlapX = max(0, min(ay2, by2) - max(ay1, by1))
        overlapY = max(0, min(ax2, bx2) - max(ax1, bx1))
        
        return area1+area2-overlapX*overlapY