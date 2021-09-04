class Solution(object):
    def maxCount(self, m, n, ops):
        """
        :type m: int
        :type n: int
        :type ops: List[List[int]]
        :rtype: int
        """
        width, height = m, n
        
        for w, h in ops:
            width = min(width, w)
            height = min(height, h)

        return width*height