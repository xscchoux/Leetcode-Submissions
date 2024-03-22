class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        points.sort(key = lambda x:(x[0], -x[1]))
        res = 0
        for i in range(len(points)):
            x, y = points[i]
            yDiff = float('inf')
            for xx, yy in points[i+1:]:
                if yy > y:
                    continue
                if abs(yy-y) < yDiff:
                    res += 1
                    yDiff = abs(yy-y)
        
        return res