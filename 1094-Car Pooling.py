class Solution(object):
    def carPooling(self, trips, capacity):
        """
        :type trips: List[List[int]]
        :type capacity: int
        :rtype: bool
        """
        
# sweep line
        points = []
        for trip in trips:
            points.append([trip[1], trip[0]])
            points.append([trip[2], -trip[0]])
        
        points.sort()
        v = 0
        for point in points:
            v += point[1]
            if v > capacity:
                return False
        
        return True