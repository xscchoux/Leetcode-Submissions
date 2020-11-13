class Solution(object):
    def validSquare(self, p1, p2, p3, p4):
        """
        :type p1: List[int]
        :type p2: List[int]
        :type p3: List[int]
        :type p4: List[int]
        :rtype: bool
        """
# use a set. If we 
# 1. Only have two values in the set
# 2. 0 is not in the set

        def dist(point1, point2):
            return (point1[0] - point2[0])**2 + (point1[1] - point2[1])**2
        
        values = set()
        values.add(dist(p1, p2))
        values.add(dist(p1, p3))
        values.add(dist(p1, p4))
        values.add(dist(p2, p3))
        values.add(dist(p2, p4))
        values.add(dist(p3, p4))
        
        return len(values) == 2 and 0 not in values