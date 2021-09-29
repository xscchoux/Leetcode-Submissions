from collections import defaultdict
class DetectSquares(object):

    def __init__(self):
        self.points = defaultdict(lambda: defaultdict(int))
        # Or use self.points = defaultdict(Counter)
        
    def add(self, point):
        """
        :type point: List[int]
        :rtype: None
        """
        x, y = point
        self.points[y][x] += 1
        
    def count(self, point):
        """
        :type point: List[int]
        :rtype: int
        """
        currX, currY = point
        otherX = self.points[currY]
        res = 0
        
        for x in otherX.keys():
            if x != currX:
                diff = abs(currX-x)
                res += self.points[currY][x]*self.points[currY+diff][x]*self.points[currY+diff][currX]
                res += self.points[currY][x]*self.points[currY-diff][x]*self.points[currY-diff][currX]
        return res

# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)