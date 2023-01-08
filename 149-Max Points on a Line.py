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

# another (better?) solution
        points.sort(key = lambda x:(x[0], x[1]))
        dp = [collections.defaultdict(int) for _ in range(len(points))]
        res = 0
        
        for i in range(1, len(points)):
            for j in range(i):
                arc = math.atan2(points[j][1] - points[i][1], points[j][0] - points[i][0])
                dp[i][arc] = dp[j][arc] + 1
                res = max(res, dp[i][arc])
        return res+1