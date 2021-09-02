class Solution(object):
    def rectangleArea(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: int
        """   
# TLE
#         maxX = maxY = 0
        
#         for x1, y1, x2, y2 in rectangles:
#             maxX = max(maxX, x2)
#             maxY = max(maxY, y2)
        
#         grid = [[0]*maxY for _ in range(maxX)]
        
#         for x1, y1, x2, y2 in rectangles:
#             for x in range(x1, x2):
#                 for y in range(y1, y2):
#                     grid[x][y] = 1
#         res = 0
#         for x in range(maxX):
#             for y in range(maxY):
#                 res += grid[x][y]
        
#         return res


# line sweep (N^2logN)
        kMod = 10**9 + 7
        def getArea(width):
            area = 0
            prevTop = 0
            for bottom, top in interval:
                bottom = max(bottom, prevTop)
                if top > bottom:
                    area += (top-bottom)*width
                    prevTop = top
            return area
    
        event = []
        for x1, y1, x2, y2 in rectangles:
            event.append((x1, 0, y1, y2))
            event.append((x2, 1, y1, y2))
        event.sort()
        
        
        xPrev = 0
        res = 0
        interval = []  # store active intervals
        for x, flag, y1, y2 in event:
            if x != xPrev:
                res += getArea(x-xPrev)
            
            if flag == 1:
                print((y1,y2))
                interval.remove((y1, y2))
            else:
                interval.append((y1, y2))
                interval.sort()
            
            xPrev = x
            
        return res%kMod