from collections import defaultdict
class Solution(object):
    def maxPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        if len(points) <=2:
            return len(points)
        
        res = 2
        for i in range(len(points)-2):
            currX, currY = points[i][0], points[i][1]
            count = collections.defaultdict(int)
            duplicate = 1
            for nxt in points[i+1:]:
                nxtX, nxtY = nxt[0], nxt[1]
                if currX == nxtX:
                    if nxtY == currY:
                        duplicate += 1
                    else:
                        count['inf'] += 1
                else:
                    slope = (nxtY-currY)/float(nxtX-currX)
                    count[slope] += 1
            res = max(res, duplicate + max(count.values()))
        
        return res