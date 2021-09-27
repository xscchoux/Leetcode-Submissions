class Solution(object):
    def averageHeightOfBuildings(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """
        points = []
        for x, y, h in buildings:
            points.append([x, 1, h])
            points.append([y, -1, h])
            
        points.sort()
        
        res = []
        count = heightSum = prevX = 0
        
        for i in range(len(points)):
            currX, kind, height = points[i]
            if count != 0 and prevX != currX:
                h = heightSum//count
                if res and res[-1][1] == prevX and res[-1][2] == h:
                    res[-1][1] = currX
                else:
                    res.append([prevX, currX, h])
            prevX = currX
            heightSum += kind*height
            count += kind
            
        return res